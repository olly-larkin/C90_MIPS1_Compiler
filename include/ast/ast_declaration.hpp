#ifndef AST_DECLARATION_HPP
#define AST_DECLARATION_HPP
#include "ast_node.hpp"
#include <vector>
#include <string>

class Declaration : public AST {};
class Type : public AST {};


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


class Decl_init_list_element : public Declaration {
public:
    Decl_init_list_element(Decl_init_list_element *_list, Declaration *_init) : 
        list(_list),
        init(_init)
        {}

    Decl_init_list_element(Declaration *_init) : 
        list(NULL),
        init(_init)
        {}

    std::string name() { return "Init List: "; }
    void print(std::ostream &os, int level){
        if(list != NULL)
            list->print(os, level); 
        os << indent(level) << init->name() << std::endl;
        init->print(os, level+1);
    }
protected:
    Decl_init_list_element *list;
    Declaration *init;
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


class Enum_Element : public Type{
public:
    Enum_Element(std::string elem, Expression *_const_expr) : enum_elem(elem), const_expr(_const_expr) {}
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


class Enum_Element_List : public Type{
public:
    Enum_Element_List(Enum_Element_List *_next_elem, Enum_Element *_data) : 
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
    Enum_Element_List *next_elem;
    Enum_Element *data;
};


class Enum_Specifier : public Type {
public:
    Enum_Specifier(Enum_Element_List *_list) : list(_list) {}
    Enum_Specifier(std::string _identifier) : 
        identifier(_identifier) {}
    Enum_Specifier(Enum_Element_List *_list, std::string _identifier) : 
        list(_list), identifier(_identifier) {}

    std::string name() { return "Enum: "; }
    void print(std::ostream &os, int level){
        os << indent(level) << "Identifier: " << identifier << std::endl;
        list->print(os, level+1);
    }
protected:
    Enum_Element_List *list;
    std::string identifier;
};

class Struct_Specifier;
class Type_Specifier : public Type {
public:
    Type_Specifier(std::string _type_name, Struct_Specifier *_struct_spec, Enum_Specifier* _enum_spec) : 
    type_name(_type_name), enum_spec(_enum_spec) {}

    std::string name() { return "Type: "; }
    void print(std::ostream &os, int level){
        if(struct_spec != NULL)
            struct_spec->print(os, level+1);
        else if(enum_spec != NULL)
            enum_spec->print(os, level+1);
        else
            os << indent(level) << type_name << std::endl;
        
    }
protected:
    std::string type_name;
    Struct_Specifier *struct_spec;
    Enum_Specifier *enum_spec;
};


class Type_Specifier_List : public Type {
public:
    Type_Specifier_List(Type_Specifier_List *_next_elem, Type_Specifier *_data) : 
    next_elem(_next_elem), data(_data) {}

    std::string name() { return "Type List: "; }
    void print(std::ostream &os, int level){
        if(next_elem != NULL)
            next_elem->print(os, level+1);
        data->print(os, level+1);
    }
protected:
    Type_Specifier_List *next_elem;
    Type_Specifier *data;
};


class Struct_Declarator : public Declaration {
public:
    Struct_Declarator(Declarator *_decl, Expression* _constant_expr) : 
    decl(_decl), constant_expr(_constant_expr) {}

    std::string name() { return "Struct Declarator: "; }
    void print(std::ostream &os, int level){
        if(decl != NULL)
            decl->print(os, level+1);
        if(decl != NULL)
            constant_expr->print(os, level+1);
    }
protected:
    Declarator *decl;
    Expression* constant_expr;
};


class Struct_Declarator_List : public Type {
public:
    Struct_Declarator_List(Struct_Declarator_List *_next_elem, Struct_Declarator *_data) : 
    next_elem(_next_elem), data(_data) {}

    std::string name() { return "Struct Declarator List: "; }
    void print(std::ostream &os, int level){
        if(next_elem != NULL)
            next_elem->print(os, level+1);

        data->print(os, level+1);
    }
protected:
    Struct_Declarator_List *next_elem;
    Struct_Declarator *data;
};


class Struct_Declaration : public Type {
public:
    Struct_Declaration(Type_Specifier_List *_types, Struct_Declarator_List *_data) : 
    types(_types), data(_data) {}

    std::string name() { return "Struct Declaration: "; }
    void print(std::ostream &os, int level){
        os << indent(level) << types->name() << std::endl;
        types->print(os, level+1);
        os << indent(level) << data->name() << std::endl;
        data->print(os, level+1);
    }
protected:
    Type_Specifier_List *types;
    Struct_Declarator_List *data;
};


class Struct_Declaration_List : public Type {
public:
    Struct_Declaration_List(Struct_Declaration_List *_next_elem, Struct_Declaration *_data) : 
    next_elem(_next_elem), data(_data) {}

    std::string name() { return "Struct Declaration List: "; }
    void print(std::ostream &os, int level){
        if(next_elem != NULL)
            next_elem->print(os, level+1);

        data->print(os, level+1);
    }
protected:
    Struct_Declaration_List *next_elem;
    Struct_Declaration *data;
};


class Struct_Specifier : public Type {
public:
    Struct_Specifier(Struct_Declaration_List *_list) : list(_list) {}
    Struct_Specifier(std::string _identifier) : identifier(_identifier) {}
    Struct_Specifier(Struct_Declaration_List *_list, std::string _identifier) : 
        list(_list), identifier(_identifier) {}

    std::string name() { return "Struct: "; }
    void print(std::ostream &os, int level){
        os << indent(level) << "Identifier: " << identifier << std::endl;
        list->print(os, level+1);
    }
protected:
    Struct_Declaration_List *list;
    std::string identifier;
};


#endif