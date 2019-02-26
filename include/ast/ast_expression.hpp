#ifndef AST_EXPRESSION_HPP
#define AST_EXPRESSION_HPP

#include "ast_node.hpp"

enum postTypes{
    E,
    AL,
    D,
    A,
    PP,
    MM
};

enum primTypes{
    I,
    C,
    S,
    E,
    EV
};

class Expression : public AST {};
class ArgList : public AST {}; //TODO: make class

class PostfixExpression : public Expression {
public:
    std::string name() { return "postfix_expression"; }
    void print(std::ostream& os, int level){ //TODO: printing
        switch(type) {
            case E:
                os << indent(level) <<  <<"[ "<<  <<" ]"<< std::endl;
                break;
            case AL:
                break;
            case D:
                break;
            case A:
                os << indent(level) << expression->name() << std::endl;
                expression->print(os, level+1);
                break;
            case PP:
                break;
            case MM:
                break;
        }
    }
protected:
    Expression* expression;
    Arglist* arglist;   
    std::string identifier; //TODO: make class or handle internally
    Arrow* arrow;       //TODO: make class
    Plusplus* pp;       //TODO: make class
    MinusMinus* mm;     //TODO: make class

    postTypes type;
};


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
            case EV:
                os << indent(level) << "Enum Value: " << enum_value << std::endl;
                break;
        }
    }
    PrimaryExpression(const std::string& str, primTypes type_) : type(type_) {
        if (type == I)
            identifier = str;
        else if (type == S)
            string_literal = str;
        else if (type == EV)
            enum_value = str;
    }
    PrimaryExpression(double num) : constant(num), type(C) {}
    PrimaryExpression(Expression* e) : expression(e), type(E) {}
protected:
    std::string identifier;
    double constant;
    std::string string_literal;
    Expression* expression;
    primTypes type;
    std::string enum_value;
};

#endif