#ifndef AST_DECLARATION_HPP
#define AST_DECLARATION_HPP

#include "ast_base_classes.hpp"

//************************************************************
//--------------------DECLARATION LIST------------------------
//************************************************************

class DeclarationList : public BaseList {
public:
    DeclarationList(BaseList *_list, BaseNode *_declaration) : BaseList(_list), declaration(_declaration) {}
    ~DeclarationList() {
        if (list != NULL) delete list;
        delete declaration;
    }

    void print(std::ostream &os, int level) {
        if (list != NULL) list->print(os, level);
        declaration->print(os, level);
    }

    void printPy(std::ostream &os, PyContext &context) {
        if (list != NULL) list->printPy(os, context);
        declaration->printPy(os, context);
    }

protected:
    BaseNode *declaration;
};

//************************************************************
//-----------------------INITIALIZER--------------------------
//************************************************************

class InitializerListHolder : public BaseExpression {
public:
    InitializerListHolder(BaseExpressionList *_initList) : initList(_initList) {}
    ~InitializerListHolder() { delete initList; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Initializer (List):" << std::endl;
        initList->print(os, level+1);
    }

protected:
    BaseExpressionList *initList;
};

class InitializerList : public BaseExpressionList {
public:
    InitializerList(BaseExpressionList *_list, BaseExpression *_init) : BaseExpressionList(_list), init(_init) {}
    ~InitializerList() {
        if (list != NULL) delete list;
        delete init;
    }

    void print(std::ostream &os, int level) {
        if (list != NULL) list->print(os, level);
        init->print(os, level);
    }

protected:
    BaseExpression *init;
};

//************************************************************
//-------------------ABSTRACT DECLARATION---------------------
//************************************************************

class AbstractArray : public BaseNode {
public:
    AbstractArray(BaseNode *_absDec, BaseExpression *_expr) : absDec(_absDec), expr(_expr) {}
    ~AbstractArray() {
        if (absDec != NULL) delete absDec;
        if (expr != NULL) delete expr;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Abstract Array:" << std::endl;
        if (absDec != NULL) absDec->print(os, level+1);
        if (expr != NULL) {
            os << indent(level+1) << "Size:" << std::endl;
            expr->print(os, level+2);
        }
    }

protected:
    BaseNode *absDec;
    BaseExpression *expr;
};

class AbstractFunc : public BaseNode {
public:
    AbstractFunc(BaseNode *_absDec, BaseList *_params) : absDec(_absDec), params(_params) {}
    ~AbstractFunc() {
        if (absDec != NULL) delete absDec;
        if (params != NULL) delete params;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Abstract Function:" << std::endl;
        if (absDec != NULL) absDec->print(os, level+1);
        if (params != NULL) {
            os << indent(level+1) << "Parameters:" << std::endl;
            params->print(os, level+2);
        }
    }

protected:
    BaseNode *absDec;
    BaseList *params;
};

class AbstractDeclarator : public BaseNode {
public:
    AbstractDeclarator(BaseList *_pointer, BaseNode *_absDec) : pointer(_pointer), absDec(_absDec) {}
    ~AbstractDeclarator() {
        if (pointer != NULL) delete pointer;
        if (absDec != NULL) delete absDec;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Abstract Declarator:" << std::endl;
        if (pointer != NULL) {
            os << indent(level+1) << "Pointer:" << std::endl;
            pointer->print(os, level+2);
        }
        if (absDec != NULL) absDec->print(os, level+1);
    }

protected:
    BaseList *pointer;
    BaseNode *absDec;
};

//************************************************************
//------------------------TYPE NAME---------------------------
//************************************************************

class TypeName : public BaseNode {
public:
    TypeName(BaseList *_specList, BaseNode *_absDec) : specList(_specList), absDec(_absDec) {}
    ~TypeName() {
        delete specList;
        if (absDec != NULL) delete absDec;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Type Name:" << std::endl;
        specList->print(os, level+1);
        if (absDec != NULL) absDec->print(os, level+1);
    }

protected:
    BaseList *specList;
    BaseNode *absDec;
};

//************************************************************
//-----------------------PARAMETERS---------------------------
//************************************************************

class ParamDeclaration : public BaseNode {
public:
    ParamDeclaration(BaseNode *_decSpec, BaseNode *_dec, BaseNode *_absDec) : decSpec(_decSpec), dec(_dec), absDec(_absDec) {}
    ~ParamDeclaration() {
        delete decSpec;
        if (dec != NULL) delete dec;
        if (absDec != NULL) delete absDec;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Parameter Declaration:" << std::endl;
        decSpec->print(os, level+1);
        if (dec != NULL) dec->print(os, level+1);
        if (absDec != NULL) absDec->print(os, level+1);
    }

    void printPy(std::ostream &os, PyContext &context) {
        if (dec != NULL) dec->printPy(os, context);
    }

protected:
    BaseNode *decSpec, *dec, *absDec;
};

class ParamList : public BaseList {
public:
    ParamList(BaseList *_list, BaseNode *_param) : BaseList(_list), param(_param) {}
    ~ParamList() {
        if (list != NULL) delete list;
        delete param;
    }

    void print(std::ostream &os, int level) {
        if (list != NULL) list->print(os, level);
        param->print(os, level);
    }

    void printPy(std::ostream &os, PyContext &context) {
        if (list != NULL) {
            list->printPy(os, context);
            os << ", ";
        }
        param->printPy(os, context);
    }

protected:
    BaseNode *param;
};

//************************************************************
//-------------------------POINTER----------------------------
//************************************************************

class Pointer : public BaseList {
public:
    Pointer(BaseList *_list) : BaseList(_list) {}
    ~Pointer() { if (list != NULL) delete list; }

    void print(std::ostream &os, int level) {
        if (list != NULL) list->print(os, level);
        os << indent(level) << "*" << std::endl;
    }

protected:
};

//************************************************************
//-----------------------DECLARATORS--------------------------
//************************************************************

class DeclaratorIdentifier : public BaseNode {
public:
    DeclaratorIdentifier(const std::string &_iden) : identifier(_iden) {}
    ~DeclaratorIdentifier() {}

    void print(std::ostream &os, int level) {
        os << indent(level) << "Declarator (Identifier): " << identifier << std::endl;
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << identifier;
        if (context.declaration)
            os << " = 0";
        if (context.globalDec)
            context.globals.push_back(identifier);
    }

protected:
    std::string identifier;
};

class DeclaratorArray : public BaseNode {
public:
    DeclaratorArray(BaseNode *_dec, BaseExpression *_expr) : dec(_dec), expr(_expr) {}
    ~DeclaratorArray() {
        delete dec;
        if (expr != NULL) delete expr;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Declarator (Array):" << std::endl;
        dec->print(os, level+1);
        if (expr != NULL) {
            os << indent(level+1) << "Size: " << std::endl;
            expr->print(os, level+2);
        }
    }

protected:
    BaseNode *dec;
    BaseExpression *expr;
};

class DeclaratorFunc : public BaseNode {
public:
    DeclaratorFunc(BaseNode *_dec, BaseList *_params) : dec(_dec), params(_params) {}
    ~DeclaratorFunc() {
        delete dec;
        if (params != NULL) delete params;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Declarator (Function):" << std::endl;
        dec->print(os, level+1);
        if (params != NULL) {
            os << indent(level+1) << "Parameters: " << std::endl;
            params->print(os, level+2);
        }
    }

    void printPy(std::ostream &os, PyContext &context) {
        context.globalDec = false;
        dec->printPy(os, context);
        os << "(";
        if (params != NULL) params->printPy(os, context);
        os << ")";
    }

protected:
    BaseNode *dec;
    BaseList *params;
};

class Declarator : public BaseNode {
public:
    Declarator(BaseList *_pointer, BaseNode *_dec) : pointer(_pointer), dec(_dec) {}
    ~Declarator() {
        delete pointer;
        delete dec;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Declarator:" << std::endl;
        os << indent(level+1) << "Pointer:" << std::endl;
        pointer->print(os, level+2);
        dec->print(os, level+1);
    }

protected:
    BaseList *pointer;
    BaseNode *dec;
};

//************************************************************
//-----------------------ENUMERATORS--------------------------
//************************************************************

class EnumElement : public BaseNode {
public:
    EnumElement(const std::string &_iden, BaseExpression *_expr) : identifier(_iden), expr(_expr) {}
    ~EnumElement() { if (expr != NULL) delete expr; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Enum Element: " << identifier << std::endl;
        if (expr != NULL)
            expr->print(os, level+1);
    }

protected:
    std::string identifier;
    BaseExpression *expr;
};

class EnumElemList : public BaseList {
public:
    EnumElemList(BaseList *_list, BaseNode *_enumElem) : BaseList(_list), enumElem(_enumElem) {}
    ~EnumElemList() {
        if (list != NULL) delete list;
        delete enumElem;
    }

    void print(std::ostream &os, int level) {
        if (list != NULL) list->print(os, level);
        enumElem->print(os, level);
    }

protected:
    BaseNode *enumElem;
};

class EnumSpecifier : public BaseNode {
public:
    EnumSpecifier(const std::string &_iden, BaseList *_elemList) : identifier(_iden), elemList(_elemList) {}
    EnumSpecifier(BaseList *_elemList) : elemList(_elemList) {}
    ~EnumSpecifier() { if (elemList != NULL) delete elemList; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Enumerator:" << std::endl;
        if (identifier != "") os << indent(level+1) << "Identifier: " << identifier << std::endl;
        if (elemList != NULL) {
            os << indent(level+1) << "Contents: " << std::endl;
            elemList->print(os, level+2);
        }
    }

protected:
    std::string identifier = ""; 
    BaseList *elemList;
};

//************************************************************
//-------------------------STRUCTS----------------------------
//************************************************************

class StructDeclarator : public BaseNode {
public:
    StructDeclarator(BaseNode *_dec, BaseExpression *_expr) : dec(_dec), expr(_expr) {}
    ~StructDeclarator() {
        if (dec != NULL) delete dec;
        delete expr;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Struct Declarator:" << std::endl;
        if (dec != NULL) dec->print(os, level+1);
        os << indent(level+1) << "Bit Width:" << std::endl;
        expr->print(os, level+2);
    }

protected:
    BaseNode *dec;
    BaseExpression *expr;
};

class StructDeclaratorList : public BaseList {
public:
    StructDeclaratorList(BaseList *_list, BaseNode *_dec) : BaseList(_list), dec(_dec) {}
    ~StructDeclaratorList() {
        if (list != NULL) delete list;
        delete dec;
    }

    void print(std::ostream &os, int level) {
        if (list != NULL) list->print(os, level);
        dec->print(os, level);
    }

protected:
    BaseNode *dec;
};

class StructDeclaration : public BaseNode {
public:
    StructDeclaration(BaseList *_specList, BaseList *_structDecList) : specList(_specList), structDecList(_structDecList) {}
    ~StructDeclaration() {
        delete specList;
        delete structDecList;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Struct Declaration:" << std::endl;
        os << indent(level+1) << "Specifiers:" << std::endl;
        specList->print(os, level+2);
        os << indent(level+1) << "Declarators:" << std::endl;
        structDecList->print(os, level+2);
    }

protected:
    BaseList *specList, *structDecList;
};

class StructDeclarationList : public BaseList {
public:
    StructDeclarationList(BaseList *_list, BaseNode *_structDec) : BaseList(_list), structDec(_structDec) {}
    ~StructDeclarationList() {
        if (list != NULL) delete list;
        delete structDec;
    }

    void print(std::ostream &os, int level) { 
        if (list != NULL) list->print(os, level);
        structDec->print(os, level);
    }

protected:
    BaseNode *structDec;
};

class StructSpecifier : public BaseNode {
public:
    StructSpecifier(const std::string &_iden, BaseList *_structList) : identifier(_iden), structList(_structList) {}
    StructSpecifier(BaseList *_structList) : structList(_structList) {}
    ~StructSpecifier() { if (structList != NULL) delete structList; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Struct Specifier:" << std::endl;
        if (identifier != "") 
            os << indent(level+1) << "Identifier: " << identifier << std::endl;
        if (structList != NULL) {
            os << indent(level+1) << "Declarations:" << std::endl;
            structList->print(os, level+2);
        }
    }

protected:
    std::string identifier = "";
    BaseList *structList;
};

//************************************************************
//---------------------TYPE SPECIFIERS------------------------
//************************************************************

class BasicTypeSpec : public BaseNode {
public:
    BasicTypeSpec(typeEnum _type) : type(_type) {}
    ~BasicTypeSpec() {}

    void print(std::ostream &os, int level) {
        os << indent(level) << "Type: ";
        switch(type) {
            case VOID_T: os << "void"; break;
            case CHAR_T: os << "char"; break;
            case SHORT_T: os << "short"; break;
            case INT_T: os << "int"; break;
            case LONG_T: os << "long"; break;
            case FLOAT_T: os << "float"; break;
            case DOUBLE_T: os << "double"; break;
            case SIGNED_T: os << "signed"; break;
            case UNSIGNED_T: os << "unsigned"; break;
        }
        os << std::endl;
    }

protected:
    typeEnum type;
};

class TypeDefTypeSpec : public BaseNode {
public:
    TypeDefTypeSpec(const std::string &_type) : type(_type) {}
    ~TypeDefTypeSpec() {}

    void print(std::ostream &os, int level) {
        os << indent(level) << "TypeDef Type: " << type << std::endl;
    }

protected:
    std::string type;
};

class TypeSpecList : public BaseList {
public:
    TypeSpecList(BaseList *_list, BaseNode *_spec) : BaseList(_list), spec(_spec) {}
    ~TypeSpecList() {
        if (list != NULL) delete list;
        delete spec;
    }

    void print(std::ostream &os, int level) {
        spec->print(os, level);
        if (list != NULL) list->print(os, level);
    }

protected:
    BaseNode *spec;
};

//************************************************************
//-----------------------DECLARATIONS-------------------------
//************************************************************

class InitDeclarator : public BaseNode {
public:
    InitDeclarator(BaseNode *_dec, BaseExpression *_init) : dec(_dec), init(_init) {}
    ~InitDeclarator() {
        delete dec;
        delete init;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Initialized Declarator:" << std::endl;
        dec->print(os, level+1);
        os << indent(level+1) << "=" << std::endl;
        init->print(os, level+2);
    }

    void printPy(std::ostream &os, PyContext &context) {
        context.declaration = false;
        dec->printPy(os, context);
        os << " = ";
        init->printPy(os, context);
    }

protected:
    BaseNode *dec;
    BaseExpression *init;
};

class InitDecList : public BaseList {
public:
    InitDecList(BaseList *_list, BaseNode *_dec) : BaseList(_list), dec(_dec) {}
    ~InitDecList() {
        if (list != NULL) delete list;
        delete dec;
    }

    void print(std::ostream &os, int level) {
        if (list != NULL) list->print(os, level);
        dec->print(os, level);
    }

    void printPy(std::ostream &os, PyContext &context) {
        if (list != NULL) list->printPy(os, context);
        context.declaration = true;
        os << context.indentPy();
        dec->printPy(os, context);
        os << std::endl;
        context.declaration = false;
    }

protected:
    BaseNode *dec;
};

class TypeDefDecSpec : public BaseNode {
public:
    TypeDefDecSpec(BaseNode *_decSpec) : decSpec(_decSpec) {}
    ~TypeDefDecSpec() { if (decSpec != NULL) delete decSpec; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "TypeDef Declaration:" << std::endl;
        if (decSpec != NULL) decSpec->print(os, level+1);
    }

protected:
    BaseNode *decSpec;
};

class TypeSpecDecSpec : public BaseNode {
public:
    TypeSpecDecSpec(BaseNode *_typeSpec, BaseNode *_decSpec) : typeSpec(_typeSpec), decSpec(_decSpec) {}
    ~TypeSpecDecSpec() {
        delete typeSpec;
        delete decSpec;
    }

    void print(std::ostream &os, int level) {
        typeSpec->print(os, level);
        decSpec->print(os, level);
    }

protected:
    BaseNode *typeSpec, *decSpec;
};

class Declaration : public BaseNode {
public:
    Declaration(BaseNode *_decSpec, BaseList *_initDecList) : decSpec(_decSpec), initDecList(_initDecList) {}
    ~Declaration() {
        delete decSpec;
        delete initDecList;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Declaration: " << std::endl;
        decSpec->print(os, level+1);
        os << indent(level+1) << "Declarator List:" << std::endl;
        initDecList->print(os, level+2);
    }

    void printPy(std::ostream &os, PyContext &context) {
        initDecList->printPy(os, context);
    }

protected:
    BaseNode *decSpec;
    BaseList *initDecList;
};

#endif