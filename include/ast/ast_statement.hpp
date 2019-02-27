#ifndef AST_STATEMENT_HPP
#define AST_STATEMENT_HPP

#include "ast_node.hpp"
#include "ast_expression.hpp"

class Statement : public AST {};

class ExpressionStatement : public Statement {
public:
    ExpressionStatement() : expression(NULL) {}
    ExpressionStatement(Expression *_expression) : expression(_expression) {}
    std::string name() { return "Expression Statement:"; }
    void print(std::ostream &os, int level) {
        if (expression != NULL) {
            os << indent(level) << expression->name() << std::endl;
            expression->print(os, level+1);
        }
    }
protected:
    Expression *expression;
};

class IfStatement : public Statement {
public:
    IfStatement(Expression *_expression, Statement *_statement) : expression(_expression), statement(_statement) {}
    std::string name() { return "If Statement:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << "Condition: " << expression->name() << std::endl;
        expression->print(os, level+1);
        os << indent(level) << "Body: " << statement->name() << std::endl;
        statement->print(os, level+1);
    }
protected:
    Expression *expression;
    Statement *statement;
};

class IfElseStatement : public Statement {
public:
    IfElseStatement(Expression *_expression, Statement *_true_statement, Statement *_false_statement) : expression(_expression), true_statement(_true_statement), false_statement(_false_statement) {}
    std::string name() { return "If / Else Statement:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << "Condition: " << expression->name() << std::endl;
        expression->print(os, level+1);
        os << indent(level) << "True: " << true_statement->name() << std::endl;
        true_statement->print(os, level+1);
        os << indent(level) << "False: " << false_statement->name() << std::endl;
        false_statement->print(os, level+1);
    }
protected:
    Expression *expression;
    Statement *true_statement, *false_statement;
};

class SwitchStatement : public Statement {
public:
    SwitchStatement(Expression *_expression, Statement *_statement) : expression(_expression), statement(_statement) {}
    std::string name() { return "Switch Statement:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << "Evaluating: " << expression->name() << std::endl;
        expression->print(os, level+1);
        os << indent(level) << "Body: " << statement->name() << std::endl;
        statement->print(os, level+1);
    }
protected:
    Expression *expression;
    Statement *statement;
};

class WhileLoop : public Statement {
public:
    WhileLoop(Expression *_expression, Statement *_statement) : expression(_expression), statement(_statement) {}
    std::string name() { return "While Loop:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << "Condition: " << expression->name() << std::endl;
        expression->print(os, level+1);
        os << indent(level) << "Body: " << statement->name() << std::endl;
        statement->print(os, level+1);
    }
protected:
    Expression *expression;
    Statement *statement;
};

class DoWhileLoop : public Statement {
public:
    DoWhileLoop(Statement *_statement, Expression *_expression) : statement(_statement), expression(_expression) {}
    std::string name() { return "Do While Loop:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << "Body: " << statement->name() << std::endl;
        statement->print(os, level+1);
        os << indent(level) << "Condition: " << expression->name() << std::endl;
        expression->print(os, level+1);
    }
protected:
    Statement *statement;
    Expression *expression;
};

class ForLoop : public Statement {
public:
    ForLoop(Expression *_exp1, Expression *_exp2, Expression *_exp3, Statement *_statement) : exp1(_exp1), exp2(_exp2), exp3(_exp3), statement(_statement) {}
    std::string name() { return "For Loop:"; }
    void print(std::ostream& os, int level) {
        if (exp1 != NULL) {
            os << indent(level) << "Expression 1: " << exp1->name() << std::endl;
            exp1->print(os, level+1);
        }
        if (exp2 != NULL) {
            os << indent(level) << "Expression 2: " << exp2->name() << std::endl;
            exp2->print(os, level+1);
        }
        if (exp3 != NULL) {
            os << indent(level) << "Expression 3: " << exp3->name() << std::endl;
            exp3->print(os, level+1);
        }
        os << indent(level) << "Body: " << statement->name() << std::endl;
        statement->print(os, level+1);
    } 
protected:
    Expression *exp1, *exp2, *exp3;
    Statement *statement;
};

class Continue : public Statement {
public:
    Continue() {}
    std::string name() { return "Continue:"; }
    void print(std::ostream &os, int level) {}
protected:
};

class Break : public Statement {
public:
    Break() {}
    std::string name() { return "Break:"; }
    void print(std::ostream &os, int level) {}
protected:
};

class Return : public Statement {
public:
    Return() : expression(NULL) {}
    Return(Expression *_expression) : expression(_expression) {}
    std::string name() { return "Return:"; }
    void print(std::ostream &os, int level) {
        if (expression != NULL) {
            os << indent(level) << expression->name() << std::endl;
            expression->print(os, level+1);
        }
    }
protected:
    Expression *expression;
};

class CaseBlock : public Statement {
public:
    CaseBlock(Expression *_expression, Statement *_statement) : expression(_expression), statement(_statement) {}
    std::string name() { return "Case Block:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << "Match: " << expression->name() << std::endl;
        expression->print(os, level+1);
        os << indent(level) << "Body: " << statement->name() << std::endl;
        statement->print(os, level+1);
    }
protected:
    Expression *expression;
    Statement *statement;
};

class DefaultBlock : public Statement {
public:
    DefaultBlock(Statement *_statement) : statement(_statement) {}
    std::string name() { return "Default Block:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << statement->name() << std::endl;
        statement->print(os, level);
    }
private:
    Statement *statement;
};

class StatementList : public Statement {
public:
    StatementList(Statement *_statement) : statement_list(NULL), statement(_statement) {}
    StatementList(StatementList *_statement_list, Statement *_statement) : statement_list(_statement_list), statement(_statement) {}
    std::string name() { return "Statement List:"; }
    void print(std::ostream &os, int level) {
        if (statement_list != NULL)
            statement_list->print(os, level);
        os << indent(level) << statement->name() << std::endl;
        statement->print(os, level+1);
    }
private:
    StatementList *statement_list;
    Statement *statement;
};

#endif