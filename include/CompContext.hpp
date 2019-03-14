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

struct Type {
    int pointerNum;
    int length;
    std::vector< std::pair<typeEnum, std::string> > typeSpecifiers;     // this will hold types, string only for typedef types
    std::vector< int > arraySizes;                              // each element represents a new dimention
    std::vector< std::pair<Type, std::string> > parameters;     // only for function type
    std::vector< std::pair<Type, std::string> > structBody;     // TODO: need to add bit field to this..?
    std::vector< std::pair<std::string, int> > enumVals;        // only for enumerated values
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

    struct varStruct {
        Type type; 
        int stackOffset;
    };

    struct stackStruct {
        std::map<std::string, varStruct> varMap;
        std::map<std::string, Type> typeMap;
        bool functionDef = false;
        bool paramDec = false;
    };

    struct tempTypeStruct {
        bool typeDef;
        int stackOffset;
        std::string identifier;
        Type type;
    } tempDec, tempParam;                     // as declarations happen, info should be pushed into tempType (will be handled after in declaration node)

    tempTypeStruct &tempType() {
        if (paramDec())
            return tempParam;
        else
            return tempDec;
    }

    std::vector<stackStruct> stack;         // to keep track of scopes and context

    //******* PASS THROUGHS ************
    std::map<std::string, varStruct>& varMap() { return stack.back().varMap; }
    std::map<std::string, Type>& typeMap() { return stack.back().typeMap; }
    bool& functionDef() { return stack.back().functionDef; }
    bool& paramDec() { return stack.back().paramDec; }
    //**********************************

    int memUsed = 0;

    //TODO: double check this
    int addToStack(const std::vector<int> &reg, std::vector<Instruction> &instructions) {
        // reg array for when size > 1 multiple registers need to be used or can store multiple registers at the same time
        // should return offset from start of stack
        int offset = memUsed;
        for(int i = 0; i < (int)reg.size(); ++i) {
            memUsed += 4;
            instructions.push_back({"sw", regMap[reg[i]], regMap[$sp], "", 0, Instruction::LS});
            instructions.push_back({"addi", regMap[$sp], regMap[$sp], "", -4, Instruction::SSN});
        }
        return offset;
    }

    //TODO: double check this
    void takeFromStack(const std::vector<int> &reg, std::vector<Instruction> &instructions) {
        // reg array for when size > 1 multiple registers need to be used or can load multiple registers at the same time
        for(int i = 0; i < (int)reg.size(); ++i) {
            memUsed -= 4;
            instructions.push_back({"addi", regMap[$sp], regMap[$sp], "", 4, Instruction::SSN});
            instructions.push_back({"lw", regMap[reg[i]], regMap[$sp], "", 0, Instruction::LS});
        }
    }

    void addScope(std::vector<Instruction> &instructions) {
        if (stack.size() > 0) {

            stack.push_back(stack.back());
            functionDef() = false;
            paramDec() = false;
            // Items needed on the stack (first and second redundant for non function but need to be the same):
            //      -> $4 / $a0  (function argument pointer)
            //      -> $31 / $ra  (return address for function)
            //      -> $30 / $fp (record the previous fp value to return to later)
            addToStack({$a0, $ra, $fp}, instructions);
            // need to move the $fp now that it is stored (sp + 4)
            instructions.push_back({"addi", regMap[$fp], regMap[$sp], "", 4, Instruction::SSN});
        } else {
            stack.push_back({});
        }
    }

    void addScopeFuncCall(std::vector<Instruction> &instructions) {           // when a function is called
        stack.push_back(stack[0]);      // only take the global context
        functionDef() = false;
        paramDec() = false;
        // Items needed on the stack:   (TODO: may need to make this save $s registers to be ISA compliant)
        //      -> $4 / $a0  (function argument pointer)
        //      -> $31 / $ra  (return address for function)
        //      -> $30 / $fp (record the previous fp value to return to later)
        addToStack({$a0, $ra, $fp}, instructions);
        // need to move the $fp now that it is stored (sp + 4)
        instructions.push_back({"addi", regMap[$fp], regMap[$sp], "", 4, Instruction::SSN});
    }

    void subScope(std::vector<Instruction> &instructions) {
        stack.pop_back();
        //TODO: retreive from stack
        // $sp = $fp   ->   $fp = read($fp)   ->   take other items off stack
        instructions.push_back({"addi", regMap[$sp], regMap[$fp], "", 0, Instruction::SSN});
        instructions.push_back({"lw", regMap[$fp], regMap[$fp], "", 0, Instruction::LS});
        takeFromStack({$ra, $a0}, instructions);
    }
};

#endif

