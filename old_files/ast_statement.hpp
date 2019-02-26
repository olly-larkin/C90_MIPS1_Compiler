#ifndef AST_STATEMENT_HPP
#define AST_STATEMENT_HPP

#include "root.hpp"
#include "ast_global.hpp"
#include "types.hpp"

class Statement : public AST {};

class Declaration : public Statement, public TopLevel {
public:
    virtual void print(std::ostream& dst, int level) const {
        dst << multiStr(level, "\t") << type.printStr() << std::endl
            << multiStr(level, "\t") << iden << std::endl;
    }
    virtual std::string name() { return "Declaration"; }
    Declaration(const BasicType& type_, const std::string& iden_) : type(type_), iden(iden_) {} 
    Declaration() {};
protected:
    BasicType type;
    std::string iden;
};

/*class PrimaryExpression : public Expression {  // TODO: primary expression inheritance
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
};*/

#endif