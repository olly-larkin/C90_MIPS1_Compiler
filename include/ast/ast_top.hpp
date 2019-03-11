#ifndef AST_TOP_HPP
#define AST_TOP_HPP

class FunctionDefinition : public BaseNode {
public:
    FunctionDefinition(BaseNode *_decSpec, BaseNode *_dec, BaseNode *_statement) : decSpec(_decSpec), dec(_dec), statement(_statement) {}
    FunctionDefinition(BaseNode *_dec, BaseNode *_statement) : dec(_dec), statement(_statement) {
        decSpec = new BasicTypeSpec(INT_T);
    }
    ~FunctionDefinition() {
        delete decSpec;
        delete dec;
        delete statement;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Function Definition:" << std::endl;
        os << indent(level+1) << "Return Type:" << std::endl;
        decSpec->print(os, level+2);
        os << indent(level+1) << "Declarator:" << std::endl;
        dec->print(os, level+2);
        os << indent(level+1) << "Body:" << std::endl;
        statement->print(os, level+2);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << std::endl << "def ";
        dec->printPy(os, context);
        os << ":" << std::endl;
        context.addScopeFunc(os);
        statement->printPy(os, context);
        context.subScope();
        os << std::endl;
    }

    void generateMIPS(std::ostream &os, CompContext &context, std::vector<Instruction> &instructions) {
        context.addScope();     // increase the scope before processing function parameters
        dec->generateMIPS(os, context, instructions);
        context.subScope();
    }

protected:
    BaseNode *decSpec, *dec, *statement;
};

class TranslationUnit : public BaseList {
public:
    TranslationUnit(BaseList *_list, BaseNode *_dec) : BaseList(_list), dec(_dec) {}
    ~TranslationUnit() {
        if (list != NULL) delete list;
        delete dec;
    }

    void print(std::ostream &os, int level) {
        if (list != NULL) list->print(os, level);
        dec->print(os, level);
    }

    void printPy(std::ostream &os, PyContext &context) {
        if (list != NULL) list->printPy(os, context);
        context.globalDec = true;
        dec->printPy(os, context);
        context.globalDec = false;
    }

    void generateMIPS(std::ostream &os, CompContext &context, std::vector<Instruction> &instructions) {
        context.addScope();
        if (list != NULL) list->generateMIPS(os, context, instructions);
        dec->generateMIPS(os, context, instructions);
    }

protected:
    BaseNode *dec;
};

class TopContainer : public BaseNode {
public:
    TopContainer(BaseList *_topList) : topList(_topList) {}
    ~TopContainer() { delete topList; }

    void print(std::ostream &os, int level) {
        os << "Root:" << std::endl;
        topList->print(os, level+1);
    }

    void printPy(std::ostream &os, PyContext &context) {
        topList->printPy(os, context);
        os << "# Invoke main as the starting point" << std::endl
           << "if __name__ == \"__main__\": " << std::endl
           << "\timport sys" << std::endl
           << "\tret=main()" << std::endl
           << "\tsys.exit(ret)" << std::endl;
    }

    void generateMIPS(std::ostream &os, CompContext &context, std::vector<Instruction> &instructions) {
        instructions.push_back({"j",context.funcToLabel["main"],"","",0,Instruction::S});
        topList->generateMIPS(os, context, instructions);
    }

protected:
    BaseList *topList;
};

#endif