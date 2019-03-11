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
    UNSIGNED_T
}; 

struct CompContext {
    std::map<std::string, std::string> funcToLabel = { {"main", "_main_"} };
    std::string makeALabel(const std::string &str) {
        static int id = 0;
        return "_" + str + "_" + std::to_string(id++);
    }

    struct varStruct {
        BaseNode *type;
        int stackOffset;
    };

    struct stackStruct {
        std::map<std::string, varStruct> varMap;
        std::map<std::string, BaseNode*> typeMap;
        bool functionDef = false;
    };

    std::string funcDefName;

    std::vector<stackStruct> stack;         // to keep track of scopes and context

    //******* PASS THROUGHS ************
    std::map<std::string, varStruct>& varMap() { return stack.back().varMap; }
    std::map<std::string, BaseNode*>& typeMap() { return stack.back().typeMap; }
    bool& functionDef() { return stack.back().functionDef; }
    //**********************************

    void addScope() {
        if (stack.size() > 0) {             // this will handle function definitions find bc they are only in global scope
            stack.push_back(stack.back());
            functionDef() = false;
            //TODO: need to offset all the stackOffset fields by the change in frame pointer
        } else {
            stack.push_back({});
        }
    }

    void subScope() {
        stack.pop_back();
    }
};

struct Instruction {
    std::string name;
    std::string arg1, arg2, arg3;
    long unsigned int number;
    enum { SSS, SSN, SN, SS, S, N, LS, E, L } printMethod;
};

#endif

