#ifndef AST_EXPRESSIONS_HPP
#define AST_EXPRESSIONS_HPP

#include <iostream>

#include "ast_base_classes.hpp"

//************************************************************
//----------------------PRIMARY-------------------------------
//************************************************************

class PrimaryExprIdentifier : public BaseExpression {
public:
    PrimaryExprIdentifier(const std::string &_identifier) : identifier(_identifier) {}
    ~PrimaryExprIdentifier() {}

    void print(std::ostream &os, int level) {
        os << indent(level) << "Primary (Identifier): " << identifier;
    }

    void printPy(std::ostream &os, PyContext& context) {
        os << identifier;
    }

protected:
    std::string identifier;
};

class PrimaryExprConstant : public BaseExpression {
public:
    PrimaryExprConstant(double _constant) : constant(_constant) {}
    ~PrimaryExprConstant() {}

    void print(std::ostream &os, int level) {
        os << indent(level) << "Primary (Constant): " << constant;
    }

    void printPy(std::ostream &os, PyContext& context) {
        os << (int)constant;
    }

protected:
    double constant;
};

class PrimaryExprStrLiteral : public BaseExpression {
public:
    PrimaryExprStrLiteral(const std::string &_literal) : literal(_literal) {}
    ~PrimaryExprStrLiteral() {}

    void print(std::ostream &os, int level) {
        os << indent(level) << "Primary (String Literal): " << literal;
    }

    void printPy(std::ostream &os, PyContext& context) {
        os << literal;
    }

protected:
    std::string literal;
};

class PrimaryExprEnumVal : public BaseExpression {
public:
    PrimaryExprEnumVal(const std::string &_val) : val(_val) {}
    ~PrimaryExprEnumVal() {}

    void print(std::ostream &os, int level) {
        os << indent(level) << "Primary (Enum Val): " << val;
    }

protected:
    std::string val;
};

//************************************************************
//----------------------POSTFIX-------------------------------
//************************************************************

class 

#endif