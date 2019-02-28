#ifndef AST_DECLARATION_HPP
#define AST_DECLARATION_HPP
#include "ast_node.hpp"
#include <vector>
#include <string>

class Declaration : public AST {};

class Declarator : public Declaration {
public:
    Declarator(std::string initializer){}
    std::string name() { return "Declarator: "; }
    void print(std::ostream &os, int level){
        
    }
protected:
    std::string initializer;
};


#endif