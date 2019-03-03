#ifndef AST_DECLARATION_HPP
#define AST_DECLARATION_HPP
#include "ast_node.hpp"
#include <vector>
#include <string>

class Declaration : public AST {};
class Type : public AST {};

//********************************************************
class DeclarationList : public Declaration {
public:
    DeclarationList(DeclarationList *_list, Declaration *_declaration) : list(_list), declaration(_declaration) {}
    std::string name() { return "Declaration List: "; }
    void print(std::ostream &os, int level) {
        if (list != NULL)
            list->print(os, level);
        os << indent(level) << declaration->name() << std::endl;
        declaration->print(os, level+1);
    }
protected:
    DeclarationList *list;
    Declaration *declaration;
};
//********************************************************

class Declarator : public Declaration {
public:
    Declarator(std::string initializer){}
    std::string name() { return "Declarator: "; }
    void print(std::ostream &os, int level){
        
    }
protected:
    std::string initializer;
};

class Decl_initializer_expr : public Declaration {
public:
    Decl_initializer_expr(Expression *_assignment_expr) : assignment_expr(_assignment_expr) {}

    std::string name() { return "Initializer (expr): "; }
    void print(std::ostream &os, int level){
        os << indent(level) << assignment_expr->name() << std::endl;
        assignment_expr->print(os, level+1);
    }
protected:
    Expression *assignment_expr;
};

class Decl_init_list : public Declaration {
public:
    Decl_init_list(Decl_init_list *_list, Declaration *_init) : list(_list), init(_init) {}
    Decl_init_list(Declaration *_init) : list(NULL), init(_init) {}

    std::string name() { return "Init List: "; }
    void print(std::ostream &os, int level){
        if(list != NULL)
            list->print(os, level); 
        os << indent(level) << init->name() << std::endl;
        init->print(os, level+1);
    }
protected:
    Decl_init_list *list;
    Declaration *init;
};



class Type_Specifier : public Type {
public:
    Type_Specifier(std::string _qualifier) : qualifier(_qualifier) {}

    std::string name() { return "Type Specifier: "; }
    void print(std::ostream &os, int level){
        
    }
protected:
    std::string qualifier;
};



class Pointer : public Type {
public:
    Pointer(Pointer *_elem) : next_elem(_elem) {}

    std::string name() { return "Pointer"; }
    void print(std::ostream &os, int level){
        os << indent(level) << "*" << std::endl;
        if(next_elem != NULL) {
            next_elem->print(os, level);
        }
    }
protected:
    Pointer *next_elem;
};



class Enum_element : public Type{
public:
    Enum_element(std::string elem,Expression *_const_expr) : enum_elem(elem), const_expr(_const_expr) {}
    std::string name() { return "Enum_element "; }
    void print(std::ostream &os, int level){
        os << indent(level) << enum_elem;
        if(const_expr != NULL){
            os << " = " << const_expr->name() << std::endl;
            const_expr->print(os, level+1);
        }
        else
            os << std::endl;
    }
protected:
    std::string enum_elem;
    Expression *const_expr;
};

class Enum_element_list : public Type{
public:
    Enum_element_list(Enum_element_list *_next_elem, Enum_element *_data) : 
        next_elem(_next_elem), data(_data) {}

    std::string name() { return "Enum list: "; }
    void print(std::ostream &os, int level){
        if(next_elem != NULL){
            next_elem->print(os, level);
        }
        os << indent(level) << data->name() << std::endl;
        data->print(os, level+1);
    }
protected:
    Enum_element_list *next_elem;
    Enum_element *data;
};




#endif