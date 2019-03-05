#ifndef AST_DECLARATION_HPP
#define AST_DECLARATION_HPP

#include "ast_node.hpp"
#include "ast_expression.hpp"
#include <vector>
#include <string>

class Declaration : public AST {};
class Type : public AST {};

//********************************************************
class DeclarationList : public Declaration {
public:
    DeclarationList(DeclarationList *_list, Declaration *_declaration) : list(_list), declaration(_declaration) {}
    virtual std::string name() { return "Declaration List: "; }
    virtual void print(std::ostream &os, int level) {
        if (list != NULL)
            list->print(os, level);
        os << indent(level) << declaration->name() << std::endl;
        declaration->print(os, level+1);
    }

    virtual void print_py(std::ostream &os, PyContext &context) {
        if (list != NULL)
            list->print_py(os, context);
        declaration->print_py(os, context);
    }

protected:
    DeclarationList *list;
    Declaration *declaration;
};
//********************************************************

class Declarator : public Declaration {};

class Initializer : public Declaration {};

class Init_Declarator : public Declarator {
public:
    Init_Declarator(Declarator *_dec, Initializer *_init) : dec(_dec), init(_init) {}
    virtual std::string name() { return "Initializer Declarator:"; }
    virtual void print(std::ostream &os, int level) {
        os << indent(level) << dec->name() << std::endl;
        dec->print(os, level+1);
        os << indent(level) << init->name() << std::endl;
        init->print(os, level+1);
    }

    virtual void print_py(std::ostream &os, PyContext &context) {
        context.declaration = false;
        dec->print_py(os, context);
        os << " = ";
        init->print_py(os, context);
    }

protected:
    Declarator *dec;
    Initializer *init;
};

class Init_Dec_List : public Declaration {
public:
    Init_Dec_List(Init_Dec_List *_list, Declarator *_dec) : list(_list), dec(_dec) {}
    virtual std::string name() { return "Declaration List:"; }
    virtual void print(std::ostream &os, int level) {
        if (list != NULL)
            list->print(os, level);
        os << indent(level) << dec->name() << std::endl;
        dec->print(os, level+1);
    }

    virtual void print_py(std::ostream &os, PyContext &context) {
        if (list != NULL)
            list->print_py(os, context);
        context.declaration = true;
        os << context.indentPy();
        dec->print_py(os, context);
        os << std::endl;
        context.declaration = false;
    }

protected:
    Init_Dec_List *list;
    Declarator *dec;
};

class Direct_Declarator : public Declarator {};

class Dir_Dec_Iden : public Direct_Declarator {
public:
    Dir_Dec_Iden(const std::string &_identifier) : identifier(_identifier) {}
    virtual std::string name() { return "Identifier:"; }
    virtual void print(std::ostream &os, int level) {
        os << indent(level) << identifier << std::endl;
    }

    virtual void print_py(std::ostream &os, PyContext &context) {
        os << identifier;
        if (context.declaration)
            os << " = 0";
    } 

protected:
    std::string identifier;
};

class Dir_Dec_Dec : public Direct_Declarator {
public:
    Dir_Dec_Dec(Declarator *_dec) : dec(_dec) {}
    virtual std::string name() { return "Declarator:"; }
    virtual void print(std::ostream &os, int level) {
        os << indent(level) << dec->name() << std::endl;
        dec->print(os, level+1);
    }

    virtual void print_py(std::ostream &os, PyContext &context) {
        //TODO: Might have to do
    } 

protected:
    Declarator *dec;
};

class Dir_Dec_Arr : public Direct_Declarator {
public:
    Dir_Dec_Arr(Direct_Declarator *_dec, Expression *_expression) : dec(_dec), expression(_expression) {}
    virtual std::string name() { return "Array:"; }
    virtual void print(std::ostream &os, int level) {
        os << indent(level) << dec->name() << std::endl;
        dec->print(os, level+1);
        if (expression != NULL) {
            os << indent(level) << "Index: " << expression->name() << std::endl;
            expression->print(os, level+1);
        }
    }
protected:
    Direct_Declarator *dec;
    Expression *expression;
};

class Decl_initializer_expr : public Initializer {
public:
    Decl_initializer_expr(Expression *_assignment_expr) : assignment_expr(_assignment_expr) {}

    virtual std::string name() { return "Initializer: "; }
    virtual void print(std::ostream &os, int level){
        os << indent(level) << assignment_expr->name() << std::endl;
        assignment_expr->print(os, level+1);
    }

    virtual void print_py(std::ostream &os, PyContext &context) {
        assignment_expr->print_py(os, context);
    } 
    
protected:
    Expression *assignment_expr;
};

class Decl_init_list : public Initializer {
public:
    Decl_init_list(Decl_init_list *_list, Initializer *_init) : list(_list), init(_init) {}
    Decl_init_list(Initializer *_init) : list(NULL), init(_init) {}

    virtual std::string name() { return "Init List: "; }
    virtual void print(std::ostream &os, int level){
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

    virtual std::string name() { return "Pointer"; }
    virtual void print(std::ostream &os, int level){
        os << indent(level) << "*" << std::endl;
        if(next_elem != NULL) {
            next_elem->print(os, level);
        }
    }
protected:
    Pointer *next_elem;
};

class Direct_Dec_Pointer : public Declarator {
public:
    Direct_Dec_Pointer(Direct_Declarator *_dirDec, Pointer *_pointer) : dirDec(_dirDec), pointer(_pointer) {}
    virtual std::string name() { return "Direct Declarator Pointer:"; }
    virtual void print(std::ostream &os, int level) {
        os << indent(level) << pointer->name() << std::endl;
        pointer->print(os, level+1);
        os << indent(level) << dirDec->name() << std::endl;
        dirDec->print(os, level+1);
    }
protected:
    Direct_Declarator *dirDec;
    Pointer *pointer;
};

class Enum_Element : public Type{
public:
    Enum_Element(std::string elem, Expression *_const_expr) : enum_elem(elem), const_expr(_const_expr) {}
    virtual std::string name() { return "Enum_element "; }
    virtual void print(std::ostream &os, int level){
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

    virtual std::string name() { return "Enum list: "; }
    virtual void print(std::ostream &os, int level){
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

    virtual std::string name() { return "Enum: "; }
    virtual void print(std::ostream &os, int level){
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

    virtual std::string name() { return "Basic Type: "; }
    virtual void print(std::ostream &os, int level){
        os << indent(level) << type_name << std::endl;
    }
protected:
    std::string type_name;
};

class Type_Specifier_Typedef : public Type {
public:
    Type_Specifier_Typedef(const std::string &_name) : type_name(_name) {}

    virtual std::string name() { return "Typedef Type: "; }
    virtual void print(std::ostream &os, int level){
        os << indent(level) << type_name << std::endl;
    }
protected:
    std::string type_name;
};


class Type_Specifier_List : public Type {
public:
    Type_Specifier_List(Type_Specifier_List *_next_elem, Type *_data) : 
        next_elem(_next_elem), data(_data) {}

    virtual std::string name() { return "Type List: "; }
    virtual void print(std::ostream &os, int level){
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
    virtual std::string name() { return "Declaration Specifier List:"; }
    virtual void print(std::ostream &os, int level) {
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
    virtual std::string name() { return "Declaration Specifier List:"; }
    virtual void print(std::ostream &os, int level) {
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
    virtual std::string name() { return "Declaration:"; }
    virtual void print(std::ostream &os, int level) {
        os << indent(level) << decSpec->name() << std::endl;
        decSpec->print(os, level+1);
        if (decList != NULL) {
            os << indent(level) << decList->name() << std::endl;
            decList->print(os, level+1);
        }
    }

    virtual void print_py(std::ostream &os, PyContext &context) {
        if (decList != NULL)
            decList->print_py(os, context);
    }

protected:
    Dec_Spec *decSpec;
    Init_Dec_List *decList;
};

class Struct_Declarator : public Declaration {
public:
    Struct_Declarator(Declarator *_decl, Expression* _constant_expr) : 
    decl(_decl), constant_expr(_constant_expr) {}

    virtual std::string name() { return "Struct Declarator: "; }
    virtual void print(std::ostream &os, int level){
        if(decl != NULL)
            decl->print(os, level+1);
        if(constant_expr != NULL) {
            os << indent(level) << constant_expr->name() << std::endl;
            constant_expr->print(os, level+1);
        }
    }
protected:
    Declarator *decl;
    Expression* constant_expr;
};


class Struct_Declarator_List : public Type {
public:
    Struct_Declarator_List(Struct_Declarator_List *_next_elem, Struct_Declarator *_data) : 
        next_elem(_next_elem), data(_data) {}

    virtual std::string name() { return "Struct Declarator List: "; }
    virtual void print(std::ostream &os, int level){
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

    virtual std::string name() { return "Struct Declaration: "; }
    virtual void print(std::ostream &os, int level){
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

    virtual std::string name() { return "Struct Declaration List: "; }
    virtual void print(std::ostream &os, int level){
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

    virtual std::string name() { return "Struct: "; }
    virtual void print(std::ostream &os, int level){
        os << indent(level) << "Identifier: " << identifier << std::endl;
        os << indent(level) << list->name() << std::endl;
        list->print(os, level+1);
    }
protected:
    Struct_Declaration_List *list = NULL;
    std::string identifier = "";
};

class Dir_Abs_Declarator : public Declaration {};

class Abstract_Declarator : public Declaration {
public:
    Abstract_Declarator(Pointer *_pointer, Dir_Abs_Declarator *_dirAbs) : pointer(_pointer), dirAbs(_dirAbs) {}
    virtual std::string name() { return "Abstract Declarator:"; }
    virtual void print(std::ostream &os, int level) {
        if (pointer != NULL) {
            os << indent(level) << pointer->name() << std::endl;
            pointer->print(os, level+1);
        }
        if (dirAbs != NULL) {
            os << indent(level) << dirAbs->name() << std::endl;
            dirAbs->print(os, level+1);
        }
    }
protected:
    Pointer *pointer;
    Dir_Abs_Declarator *dirAbs;
};

class Param_Dec : public Declaration {
public:
    Param_Dec(Dec_Spec *_decSpec, Declarator *_dec, Abstract_Declarator *_abs) : decSpec(_decSpec), dec(_dec), abs(_abs) {}
    virtual std::string name() { return "Parameter Declaration:"; }
    virtual void print(std::ostream &os, int level) {
        os << indent(level) << decSpec->name() << std::endl;
        decSpec->print(os, level+1);
        if (dec != NULL) {
            os << indent(level) << dec->name() << std::endl;
            dec->print(os, level+1);
        }
        if (abs != NULL) {
            os << indent(level) << abs->name() << std::endl;
            abs->print(os, level+1);
        }
    }

    virtual void print_py(std::ostream &os, PyContext &context) {
        dec->print_py(os, context);
    } 

protected:
    Dec_Spec *decSpec;
    Declarator *dec;
    Abstract_Declarator *abs;
};

class Param_List : public Declaration {
public:
    Param_List(Param_List *_list, Param_Dec *_dec) : list(_list), dec(_dec) {}
    virtual std::string name() { return "Parameter List:"; }
    virtual void print(std::ostream &os, int level) {
        if (list != NULL)
            list->print(os, level);
        os << indent(level) << dec->name() << std::endl;
        dec->print(os, level+1);
    }

    virtual void print_py(std::ostream &os, PyContext &context) {
        if (list != NULL) {
            list->print_py(os, context);
            os << ", ";
        }
        dec->print_py(os, context);
    } 

protected:
    Param_List *list;
    Param_Dec *dec;
};


class Dir_Dec_Func : public Direct_Declarator {
public:
    Dir_Dec_Func(Direct_Declarator *_dec, Param_List *_paramList) : dec(_dec), paramList(_paramList) {}
    virtual std::string name() { return "Function:"; }
    virtual void print(std::ostream &os, int level) {
        os << indent(level) << dec->name() << std::endl;
        dec->print(os, level+1);
        if (paramList != NULL) {
            os << indent(level) << paramList->name() << std::endl;
            paramList->print(os, level+1);
        }
    }

    virtual void print_py(std::ostream &os, PyContext &context) {
        dec->print_py(os, context);
        os << "(";
        if (paramList != NULL)
            paramList->print_py(os, context);
        os << ")";
    } 

protected:
    Direct_Declarator *dec;
    Param_List *paramList;
};


class Dir_Abs_Dec : public Dir_Abs_Declarator {
public:
    Dir_Abs_Dec(Abstract_Declarator *_abs) : abs(_abs) {}
    virtual std::string name() { return "( Abstract Declarator ):"; }
    virtual void print(std::ostream &os, int level) {
        abs->print(os, level);
    }
protected:
    Abstract_Declarator *abs;
};

class Dir_Abs_Arr : public Dir_Abs_Declarator {
public:
    Dir_Abs_Arr(Dir_Abs_Declarator *_dec, Expression *_expr) : dec(_dec), expr(_expr) {}
    virtual std::string name() { return "Direct Abstract Declarator Array:"; }
    virtual void print(std::ostream &os, int level) {
        if (dec != NULL) {
            os << indent(level) << dec->name() << std::endl;
            dec->print(os, level);
        }
        if (expr != NULL) {
            os << indent(level) << expr->name() << std::endl;
            expr->print(os, level+1);
        }
    }
protected:
    Dir_Abs_Declarator *dec;
    Expression *expr;
};

class Dir_Abs_Func : public Dir_Abs_Declarator {
public:
    Dir_Abs_Func(Dir_Abs_Declarator *_dec, Param_List *_params) : dec(_dec), params(_params) {}
    virtual std::string name() { return "Direct Abstract Declarator Function:"; }
    virtual void print(std::ostream &os, int level) {
        if (dec != NULL) {
            os << indent(level) << dec->name() << std::endl;
            dec->print(os, level);
        }
        if (params != NULL) {
            os << indent(level) << params->name() << std::endl;
            params->print(os, level+1);
        }
    }
protected:
    Dir_Abs_Declarator *dec;
    Param_List *params;
};

#endif