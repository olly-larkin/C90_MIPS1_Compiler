#ifndef AST_EXPRESSION_HPP
#define AST_EXPRESSION_HPP

#include "ast_node.hpp"

enum primTypes{
    I,
    C,
    S,
    E
};

class Expression : public AST {};

class PrimaryExpression : public Expression {  // TODO: primary expression inheritance
public:
    std::string name() { return "primary_expression"; }
    void print(std::ostream& os, int level) {
        switch(type) {
            case I:
                os << indent(level) << "Identifier: " << identifier << std::endl;
                break;
            case C:
                os << indent(level) << "Constant: " << constant << std::endl;
                break;
            case S:
                os << indent(level) << "String Literal: " << string_literal << std::endl;
                break;
            case E:
                os << indent(level) << expression->name() << std::endl;
                expression->print(os, level+1);
                break;
        }
    }
    PrimaryExpression(const std::string& str, primTypes type_) : type(type_) {
        if (type == I)
            identifier = str;
        else if (type == S)
            string_literal = str;
    }
    PrimaryExpression(double num) : constant(num), type(C) {}
    PrimaryExpression(Expression* e) : expression(e), type(E) {}
protected:
    std::string identifier;
    double constant;
    std::string string_literal;
    Expression* expression;
    primTypes type;
};

#endif