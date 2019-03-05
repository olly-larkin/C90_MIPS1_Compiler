#ifndef AST_TOP_HPP
#define AST_TOP_HPP


#include "ast_node.hpp"
#include "ast_expression.hpp"
#include "ast_declaration.hpp"
#include "ast_statement.hpp"

#include <vector>
#include <iostream>

class Function_Definition : public AST {
public:
    Function_Definition(Dec_Spec *_rettypes, Declarator *_dec, CompoundStatement *_seq) : 
        return_types(_rettypes), 
        dec(_dec),
        sequence(_seq) 
    {}

    std::string name(){ return "Function Definition: "; }
    void print(std::ostream &os, int level){
        if(return_types != NULL){
            os << indent(level) << "Return Types: " << std::endl;
            return_types->print(os, level+1);
        }
        else{
            os << indent(level) << "Return Types: " << std::endl;
            os << indent(level+1) << "Int (Implicit)" << std::endl;
        }
        os << indent(level) << dec->name() << std::endl;
        dec->print(os, level+1);

        os << indent(level) << sequence->name() << std::endl;
        sequence->print(os, level+1);
    }
private:
    Dec_Spec *return_types;
    Declarator *dec;
    CompoundStatement *sequence;
};

class External_Declaration : public AST {};

class External_Declaration_Func : public External_Declaration {
public:
    External_Declaration_Func(Function_Definition *fd) : fn_defn(fd) {}

    std::string name(){ return "External Declaration Function: "; }
    void print(std::ostream &os, int level){
        os << indent(level) << fn_defn->name() << std::endl;
        fn_defn->print(os, level+1);
    }
private:
    Function_Definition *fn_defn;
};

class External_Declaration_Dec : public External_Declaration {
public:
    External_Declaration_Dec(Declaration *decla) : dec(decla) {}

    std::string name(){ return "External Declaration: "; }
    void print(std::ostream &os, int level){
        os << indent(level) << dec->name() << std::endl;
        dec->print(os, level+1);
    }
private:
    Declaration *dec;
};


class Translation_Unit : public AST {
public:
    Translation_Unit(Translation_Unit *_next, External_Declaration *_data) : 
    next(_next),
    data(_data){}

    std::string name(){ return "Translation Unit: "; }
    void print(std::ostream &os, int level){
        if(next != NULL){
            next->print(os, level);
        }
        os << indent(level) << data->name() << std::endl;
        data->print(os, level+1);
    }
private:
    Translation_Unit *next;
    External_Declaration *data;
};
#endif