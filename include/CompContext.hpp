#ifndef COMPCONTEXT_HPP
#define COMPCONTEXT_HPP

class BaseNode;         // forward declaration for context

enum typeEnum {
    VOID_T,
    CHAR_T,
    SHORT_T,
    INT_T,
    LONG_T,
    FLOAT_T,
    DOUBLE_T,
    SIGNED_T,
    UNSIGNED_T,
    TYPEDEF_TYPE_T
}; 

const static std::map<typeEnum, std::string> typeStrings = {   // mainly for printing, will also be used in Type below
    {VOID_T, "void"},
    {CHAR_T, "char"},
    {SHORT_T, "short"},
    {INT_T, "int"},
    {LONG_T, "long"},
    {FLOAT_T, "float"},
    {DOUBLE_T, "double"},
    {SIGNED_T, "signed"},
    {UNSIGNED_T, "unsigned"}
};

struct Instruction {
    std::string name;
    std::string arg1, arg2, arg3;
    long int number;
    enum { SSS, SSN, SN, SS, S, N, LS, E, L } printMethod;  
    // LS = load/store
    // E = empty (nop)
    // L = label
};

struct CompContext {
    std::string makeALabel(const std::string &str) {
        static int id = 0;
        return "_" + str + "_" + std::to_string(id++);
    }

    struct Type {
        int pointerNum;
        std::vector< std::pair<typeEnum, std::string> > typeSpecifiers;     // this will hold types, string only for typedef types
        std::vector< int > arraySizes;                              // each element represents a new dimention

        int length() {
            int ret = 1;
            if (pointerNum == 0)
                for (int i = 0; i < (int)arraySizes.size(); ++i)
                    ret *= arraySizes[i];
            return ret;
        }
    };
    
    struct varStruct {
        Type type; 
        int offset;
    };

    struct funcStruct {
        Type retType;
        std::vector< std::pair<std::string, varStruct> > params;
    };

    struct stackStruct {
        std::map<std::string, varStruct> varMap;
        std::map<std::string, Type> typeMap;
        struct decFlagStruct {
            bool functionDef, functionBody, init;
            std::string funcName;
        } decFlags;
    };

    std::map<std::string, funcStruct> funcMap;

    struct {
        bool typeDef;
        std::string identifier;
        Type type;
    } tempDec;                     // as declarations happen, info should be pushed into tempType (will be handled after in declaration node)

    std::vector<stackStruct> stack;         // to keep track of scopes and context

    //******* PASS THROUGHS ************
    std::map<std::string, varStruct>& varMap() { return stack.back().varMap; }
    std::map<std::string, Type>& typeMap() { return stack.back().typeMap; }
    stackStruct::decFlagStruct& decFlags() { return stack.back().decFlags; }
    funcStruct& currentFunc() { return funcMap[decFlags().funcName]; }
    //**********************************

    int memUsed = 0;

    void pushToStack(const std::vector<int> &reg, std::vector<Instruction> &instructions) {
        for(int i = 0; i < (int)reg.size(); ++i) {
            memUsed += 4;                   // increment then store
            instructions.push_back({"addi", regMap[$sp], regMap[$sp], "", -4, Instruction::SSN});
            instructions.push_back({"sw", regMap[reg[i]], regMap[$sp], "", 0, Instruction::LS});
        }
    }

    void pullFromStack(const std::vector<int> &reg, std::vector<Instruction> &instructions) {
        for(int i = 0; i < (int)reg.size(); ++i) {      
            instructions.push_back({"lw", regMap[reg[i]], regMap[$sp], "", 0, Instruction::LS});
            instructions.push_back({"addi", regMap[$sp], regMap[$sp], "", 4, Instruction::SSN});
            memUsed -= 4;           // read then decrement
        }
    }

    void writeStack(int reg, int offset, std::vector<Instruction> &instructions) {
        int spOffset = memUsed - offset;
        instructions.push_back({"sw", regMap[reg], regMap[$sp], "", spOffset, Instruction::LS});
    }

    void readStack(int reg, int offset, std::vector<Instruction> &instructions) {
        int spOffset = memUsed - offset;
        instructions.push_back({"lw", regMap[reg], regMap[$sp], "", spOffset, Instruction::LS});
    }

    void addDeclaration(std::vector<Instruction> &instructions) {
        int length = tempDec.type.length();
        int offset = memUsed + 4;
        for (int i = 0; i < length; ++i) {
            memUsed += 4;
            instructions.push_back({"addi", regMap[$sp], regMap[$sp], "", -4, Instruction::SSN});
        }
        stack.back().varMap[tempDec.identifier] = {tempDec.type, offset};
    }

    void addScope() {                   // will only effect context
        if (stack.size() > 0) {
            //stack.push_back(stackStruct(stack.back()));
            stack.push_back(stack.back());
        } else {
            stack.push_back({});
        }
    }

    void subScope() {                   // will only effect context
        stack.pop_back();
    }

    void addScopeFunc(std::vector<Instruction> &instructions) {
        addScope();

        instructions.push_back({"label", stack.back().decFlags.funcName, "", "", 0, Instruction::L});

        // store up to 4 function args on the prev stack frame
        for (int reg = $4, offset = 0; offset < (int)funcMap[decFlags().funcName].params.size()*4 && offset < 16; ++reg, offset += 4 ) {
            writeStack(reg, memUsed - offset, instructions);
        }

        pushToStack({$ra, $fp}, instructions);           // $ra and $fp need saving
    }

    void subScopeFunc(std::vector<Instruction> &instructions) {
        instructions.push_back({"label", stack.back().decFlags.funcName + "_end", "", "", 0, Instruction::L});

        readStack($fp, 8, instructions);
        readStack($ra, 4, instructions);
        instructions.push_back({"move", regMap[$sp], regMap[$fp], "", 0, Instruction::SS});   // move $sp to $fp
        memUsed = 0;

        subScope();
    }
};

#endif

