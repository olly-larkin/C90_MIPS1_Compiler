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

#endif