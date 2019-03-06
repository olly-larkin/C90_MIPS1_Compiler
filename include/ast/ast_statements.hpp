#ifndef AST_STATEMENTS_HPP
#define AST_STATEMENTS_HPP

//************************************************************
//---------------------JUMP STATEMENT-------------------------
//************************************************************

class Continue : public BaseNode {
public:
    Continue() {}
    ~Continue() {}

    void print(std::ostream &os, int level) {
        os << indent(level) << "Continue" << std::endl;
    }

protected:
};

class Break : public BaseNode {
public:
    Break() {}
    ~Break() {}

    void print(std::ostream &os, int level) {
        os << indent(level) << "Break" << std::endl;
    }
    
protected:
};

class Return : public BaseNode {
public:
    Return(BaseExpression *_expr) : expr(_expr) {}
    ~Return() { if (expr != NULL) delete expr; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Return:" << std::endl;
        if (expr != NULL)
            expr->print(os, level+1);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << context.indentPy() << "return ";
        if (expr != NULL)
            expr->printPy(os, context);
        os << std::endl;
    }
    
protected:
    BaseExpression *expr;
};

//************************************************************
//-------------------ITERATION STATEMENT----------------------
//************************************************************

class WhileLoop : public BaseNode {
public:
    WhileLoop(BaseExpression *_expr, BaseNode *_statement) : expr(_expr), statement(_statement) {}
    ~WhileLoop() {
        delete expr;
        delete statement;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "While Loop:" << std::endl;
        os << indent(level+1) << "Condition:" << std::endl;
        expr->print(os, level+2);
        os << indent(level+1) << "Body:" << std::endl;
        statement->print(os, level+2);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << context.indentPy() << "while ";
        expr->printPy(os, context);
        os << ":" << std::endl;
        context.addScope();
        statement->printPy(os, context);
        context.subScope();
    }

protected:
    BaseExpression *expr;
    BaseNode *statement;
};

class DoWhileLoop : public BaseNode {
public:
    DoWhileLoop(BaseNode *_statement, BaseExpression *_expr) : statement(_statement), expr(_expr) {}
    ~DoWhileLoop() {
        delete statement;
        delete expr;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Do While Loop:" << std::endl;
        os << indent(level+1) << "Body:" << std::endl;
        statement->print(os, level+2);
        os << indent(level+1) << "Condition:" << std::endl;
        expr->print(os, level+2);
    }

protected:
    BaseNode *statement;
    BaseExpression *expr;
};

class ForLoop : public BaseNode {
public:
    ForLoop(BaseExpression *_expr1, BaseExpression *_expr2, BaseExpression *_expr3, BaseNode *_statement) : expr1(_expr1), expr2(_expr2), expr3(_expr3), statement(_statement)  {}
    ~ForLoop() {
        if (expr1 != NULL) delete expr1;
        if (expr2 != NULL) delete expr2;
        if (expr3 != NULL) delete expr3;
        delete statement;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "For Loop:" << std::endl;
        if (expr1 != NULL) {
            os << indent(level+1) << "Expression 1:" << std::endl;
            expr1->print(os, level+2);
        }
        if (expr2 != NULL) {
            os << indent(level+1) << "Expression 2:" << std::endl;
            expr2->print(os, level+2);
        }
        if (expr3 != NULL) {
            os << indent(level+1) << "Expression 3:" << std::endl;
            expr3->print(os, level+2);
        }
        os << indent(level+1) << "Body:" << std::endl;
        statement->print(os, level+2);
    }

protected:
    BaseExpression *expr1, *expr2, *expr3;
    BaseNode *statement;
};

//************************************************************
//-------------------SELECTION STATEMENT----------------------
//************************************************************

class IfStatement : public BaseNode {
public:
    IfStatement(BaseExpression *_expr, BaseNode *_statement) : expr(_expr), statement(_statement) {}
    ~IfStatement() {
        delete expr;
        delete statement;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "If Statement:" << std::endl;
        os << indent(level+1) << "Expression: " << std::endl;
        expr->print(os, level+2);
        os << indent(level+1) << "Body: " << std::endl;
        statement->print(os, level+2);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << context.indentPy() << "if ";
        expr->printPy(os, context);
        os << ":" << std::endl;
        context.addScope();
        statement->printPy(os, context);
        context.subScope();
    }

protected:
    BaseExpression *expr;
    BaseNode *statement;
};

class IfElseStatement : public BaseNode {
public:
    IfElseStatement(BaseExpression *_expr, BaseNode *_statementTrue, BaseNode *_statementFalse) : expr(_expr), statementTrue(_statementTrue), statementFalse(_statementFalse) {}
    ~IfElseStatement() {
        delete expr;
        delete statementTrue;
        delete statementFalse;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "If Else Statement:" << std::endl;
        os << indent(level+1) << "Expression: " << std::endl;
        expr->print(os, level+2);
        os << indent(level+1) << "True Body: " << std::endl;
        statementTrue->print(os, level+2);
        os << indent(level+1) << "False Body: " << std::endl;
        statementFalse->print(os, level+2);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << context.indentPy() << "if ";
        expr->printPy(os, context);
        os << ":" << std::endl;
        context.addScope();
        statementTrue->printPy(os, context);
        context.subScope();
        os << context.indentPy() << "else:" << std::endl;
        context.addScope();
        statementFalse->printPy(os, context);
        context.subScope();
    }

protected:
    BaseExpression *expr;
    BaseNode *statementTrue, *statementFalse;
};

class SwitchStatement : public BaseNode {
public:
    SwitchStatement(BaseExpression *_expr, BaseNode *_statement) : expr(_expr), statement(_statement) {}
    ~SwitchStatement() {
        delete expr;
        delete statement;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Switch Statement:" << std::endl;
        os << indent(level+1) << "Expression: " << std::endl;
        expr->print(os, level+2);
        os << indent(level+1) << "Body: " << std::endl;
        statement->print(os, level+2);
    }

protected:
    BaseExpression *expr;
    BaseNode *statement;
};

//************************************************************
//------------------EXPRESSION STATEMENT----------------------
//************************************************************

class ExpressionStatement : public BaseNode {
public:
    ExpressionStatement(BaseExpression *_expr) : expr(_expr) {}
    ~ExpressionStatement() { if (expr != NULL) delete expr; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Expression Statement:" << std::endl;
        if (expr != NULL)
            expr->print(os, level+1);
    }

    void printPy(std::ostream &os, PyContext &context) {
        if (expr != NULL) {
            os << context.indentPy();
            expr->printPy(os, context);
            os << std::endl;
        }
    }

protected:
    BaseExpression *expr;
};

//************************************************************
//---------------------STATEMENT LIST-------------------------
//************************************************************

class StatementList : public BaseList {
public:
    StatementList(BaseList *_list, BaseNode *_statement) : BaseList(_list), statement(_statement) {}
    ~StatementList() {
        if (list != NULL) delete list;
        delete statement;
    }

    void print(std::ostream &os, int level) {
        if (list != NULL)
            list->print(os, level);
        statement->print(os, level);
    }

    void printPy(std::ostream &os, PyContext &context) {
        if (list != NULL)
            list->printPy(os, context);
        statement->printPy(os, context);
    }

protected:
    BaseNode *statement;
};

//************************************************************
//-------------------COMPOUND STATEMENT-----------------------
//************************************************************

class CompoundStatement : public BaseNode {
public:
    CompoundStatement(BaseList *_dec, BaseList *_state) : declarationList(_dec), statementList(_state) {}
    ~CompoundStatement() {
        if (declarationList != NULL) delete declarationList;
        if (statementList != NULL) delete statementList;
    }

    void print(std::ostream &os, int level) {
        if (declarationList != NULL) declarationList->print(os, level);
        if (statementList != NULL) statementList->print(os, level);
    }

    void printPy(std::ostream &os, PyContext &context) {
        if (declarationList != NULL) declarationList->printPy(os, context);
        if (statementList != NULL) statementList->printPy(os, context);
    }

protected:
    BaseList *declarationList, *statementList;
};

//************************************************************
//--------------------LABLED STATEMENT------------------------
//************************************************************

class CaseBlock : public BaseNode {
public:
    CaseBlock(BaseExpression *_expr, BaseNode *_statement) : expr(_expr), statement(_statement) {}
    ~CaseBlock() {
        delete expr;
        delete statement;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Case Block:" << std::endl;
        os << indent(level+1) << "Expression: " << std::endl;
        expr->print(os, level+2);
        os << indent(level+1) << "Body:" << std::endl;
        statement->print(os, level+2);
    }

protected:
    BaseExpression *expr;
    BaseNode *statement;
};

class DefaultCaseBlock : public BaseNode {
public:
    DefaultCaseBlock(BaseNode *_statement) : statement(_statement) {}
    ~DefaultCaseBlock() { delete statement; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Default Case Block:" << std::endl;
        statement->print(os, level+1);
    }

protected:
    BaseNode *statement;
};

#endif