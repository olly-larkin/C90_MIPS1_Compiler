#ifndef AST_TYPE_NAME_HPP
#define AST_TYPE_NAME_HPP

#include "ast_expression.hpp"
#include "ast_declaration.hpp"

#include <vector>
#include <iostream>

class Type_Name : public Type {
public:
    Type_Name(Type_Specifier_List *_typeList, Abstract_Declarator *_absDec) : typeList(_typeList), absDec(_absDec) {}
    virtual std::string name() { return "Type: "; }
    virtual void print(std::ostream &os, int level) {
        os << indent(level) << typeList->name() << std::endl;
        typeList->print(os, level+1);
        if (absDec != NULL){ 
            os << indent(level) << absDec->name() << std::endl;
            absDec->print(os, level+1);
        }
    }
protected:
    Type_Specifier_List *typeList;
    Abstract_Declarator *absDec;
};

class Unary_SizeOfType : public Expression {
public:
    Unary_SizeOfType(Type_Name *_type) : type(_type) {}
    std::string name() { return "Size of:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << type->name() << std::endl;
        type->print(os, level+1);
    }
protected:
    Type_Name *type;
};

#endif