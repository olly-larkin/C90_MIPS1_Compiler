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
    std::vector< std::pair<typeEnum, std::string> > typeSpecifiers;     // this will hold types, string only for typedef types
    std::vector< int > arraySizes;    // each element represents a new dimention
    std::vector< std::pair<Type, std::string> > parameters;     // only for function type
    std::vector< std::pair<Type, std::string> > structBody;     // TODO: need to add bit field to this
    std::vector< std::pair<std::string, int> > enumVals;        // only for enumerated values
};


struct Instruction {
    std::string name;
    std::string arg1, arg2, arg3;
    long unsigned int number;
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
        std::map<std::string, BaseNode*> typeMap;
        bool functionDef = false;
        bool functionDec = false;
    };

    std::vector<stackStruct> stack;         // to keep track of scopes and context

    //******* PASS THROUGHS ************
    std::map<std::string, varStruct>& varMap() { return stack.back().varMap; }
    std::map<std::string, BaseNode*>& typeMap() { return stack.back().typeMap; }
    bool& functionDef() { return stack.back().functionDef; }
    bool& functionDec() { return stack.back().functionDec; }
    //**********************************

    void addScope() {
        if (stack.size() > 0) {             // this will handle function definitions find bc they are only in global scope
            stack.push_back(stack.back());
            functionDef() = false;
            functionDec() = false;
            //TODO: need to offset all the stackOffset fields by the change in frame pointer
        } else {
            stack.push_back({});
        }
    }

    void subScope() {
        stack.pop_back();
    }
};

#endif

