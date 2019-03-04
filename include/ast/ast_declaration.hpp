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
    Declarator(){}
    virtual std::string name() { return "Declarator: "; }
    virtual void print(std::ostream &os, int level){
        // TODO: needs making
    }
protected:
    
};

class Initializer : public Declaration {};

class Init_Declarator : public Declarator {
public:
    Init_Declarator(Declarator *_dec, Initializer *_init) : Declarator(*_dec), init(_init) {
        delete _dec;
    }
    std::string name() { return "Initializer Declarator:"; }
    void print(std::ostream &os, int level) {
        // TODO: needs making
    }
protected:
    Initializer *init;
};

class Init_Dec_List : public Declaration {
public:
    Init_Dec_List(Init_Dec_List *_list, Declarator *_dec) : list(_list), dec(_dec) {}
    std::string name() { return "Declaration List:"; }
    void print(std::ostream &os, int level) {
        if (list != NULL)
            list->print(os, level);
        os << indent(level) << dec->name() << std::endl;
        dec->print(os, level+1);
    }
protected:
    Init_Dec_List *list;
    Declarator *dec;
};

class Decl_initializer_expr : public Initializer {
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

class Decl_init_list : public Initializer {
public:
    Decl_init_list(Decl_init_list *_list, Initializer *_init) : list(_list), init(_init) {}
    Decl_init_list(Initializer *_init) : list(NULL), init(_init) {}

    std::string name() { return "Init List: "; }
    void print(std::ostream &os, int level){
        if(list != NULL)
            list->print(os, level); 
        os << indent(level) << init->name() << std::endl;
        init->print(os, level+1);
    }
protected:
    Decl_init_list *list;
    Initializer *init;
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
    Enum_Specifier(std::string _identifier) : identifier(_identifier) {}
    Enum_Specifier(Enum_Element_List *_list, std::string _identifier) : list(_list), identifier(_identifier) {}

    std::string name() { return "Enum: "; }
    void print(std::ostream &os, int level){
        os << indent(level) << "Identifier: " << identifier << std::endl;
        list->print(os, level);
    }
protected:
    Enum_Element_List *list;
    std::string identifier;
};

class Type_Specifier_Basic : public Type {
public:
    Type_Specifier_Basic(const std::string &_type_name) : type_name(_type_name) {}

    std::string name() { return "Basic Type: "; }
    void print(std::ostream &os, int level){
        os << indent(level) << type_name << std::endl;
    }
protected:
    std::string type_name;
};

class Type_Specifier_Typedef : public Type {
public:
    Type_Specifier_Typedef(const std::string &_name) : type_name(_name) {}

    std::string name() { return "Typedef Type: "; }
    void print(std::ostream &os, int level){
        os << indent(level) << type_name << std::endl;
    }
protected:
    std::string type_name;
};


class Type_Specifier_List : public Type {
public:
    Type_Specifier_List(Type_Specifier_List *_next_elem, Type *_data) : 
        next_elem(_next_elem), data(_data) {}

    std::string name() { return "Type List: "; }
    void print(std::ostream &os, int level){
        os << indent(level) << data->name() << std::endl;
        data->print(os, level+1);
        if(next_elem != NULL)
            next_elem->print(os, level);
    }
protected:
    Type_Specifier_List *next_elem;
    Type *data;
};

class Dec_Spec : public Declaration {};

class Dec_Spec_TypeDef : public Dec_Spec {
public:
    Dec_Spec_TypeDef(Dec_Spec *_decList) : decList(_decList) {}
    std::string name() { return "Declaration Specifier List:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << "Typedef node" << std::endl;
        if (decList != NULL)
            decList->print(os, level);
    }
protected:
    Dec_Spec *decList;
};

class Dec_Spec_TypeSpec : public Dec_Spec {
public:
    Dec_Spec_TypeSpec(Dec_Spec *_decList, Type *_typeSpec) : decList(_decList), typeSpec(_typeSpec) {}
    std::string name() { return "Declaration Specifier List:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << typeSpec->name() << std::endl;
        typeSpec->print(os, level+1);
        if (decList != NULL)
            decList->print(os, level);
    }
protected:
    Dec_Spec *decList;
    Type *typeSpec;
};

class DeclarationNode : public Declaration {
public:
    DeclarationNode(Dec_Spec *_decSpec, Init_Dec_List *_decList) : decSpec(_decSpec), decList(_decList) {}
    std::string name() { return "Declaration:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << decSpec->name() << std::endl;
        decSpec->print(os, level+1);
        if (decList != NULL) {
            os << indent(level) << decList->name() << std::endl;
            decList->print(os, level+1);
        }
    }
protected:
    Dec_Spec *decSpec;
    Init_Dec_List *decList;
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
            next_elem->print(os, level);
        os << indent(level) << data->name() << std::endl;
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
            next_elem->print(os, level);
        os << indent(level) << data->name() << std::endl;
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
        os << indent(level) << list->name() << std::endl;
        list->print(os, level+1);
    }
protected:
    Struct_Declaration_List *list = NULL;
    std::string identifier = "";
};


#endif