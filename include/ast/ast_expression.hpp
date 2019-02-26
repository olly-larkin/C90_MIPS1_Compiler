#ifndef AST_EXPRESSION_HPP
#define AST_EXPRESSION_HPP

#include "ast_node.hpp"

class Expression : public AST {};
class ArgList : public AST {}; //TODO: make class

class PrimaryExp_Identifier : public Expression {
public:
    PrimaryExp_Identifier(const std::string &_identifier) : identifier(_identifier){}
    std::string name() { return "Identifier"; }
    void print(std::ostream& os, int level){
        os << indent(level) << identifier << std::endl;
    }
protected:
    std::string identifier;
};


class PrimaryExp_Constant : public Expression {
public:
    PrimaryExp_Constant(double _constant) : constant(_constant){}
    std::string name() { return "Constant"; }
    void print(std::ostream& os, int level){
        os << indent(level) << constant << std::endl;
    }
protected:
    double constant;
};


class PrimaryExp_StrLiteral : public Expression {
    public:
    PrimaryExp_StrLiteral(const std::string &_string) : string(_string){}
    std::string name() { return "String Literal"; }
    void print(std::ostream& os, int level){
        os << indent(level) << string << std::endl;
    }
protected:
    std::string string;
};


class PrimaryExp_EnumVal : public Expression {
public:
    PrimaryExp_EnumVal(const std::string &_val) : val(_val){}
    std::string name() { return "Enum Value"; }
    void print(std::ostream& os, int level){
        os << indent(level) << val << std::endl;
    }
protected:
    std::string val;
};


#endif