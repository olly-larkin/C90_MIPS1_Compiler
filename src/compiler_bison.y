%code requires{
    #include "ast.hpp"

    #include <cassert>

    extern const AST* g_root; // A way of getting the AST out

    //! This is to fix problems when generating C++
    // We are declaring the functions provided by Flex, so
    // that Bison generated code can call them.
    int yylex(void);
    void yyerror(const char *);
}

%union{
    AST *ast;
    double number;
    std::string* string;
}

%token T_PLUSPLUS T_MINUSMINUS
%token T_EQUAL_TO T_NOT_EQUAL_TO T_LESS_THAN_EQUAL T_MORE_THAN_EQUAL
%token T_AND T_OR
%token T_LEFT_SHIFT T_RIGHT_SHIFT
%token T_PLUS_EQUAL T_MINUS_EQUAL T_TIMES_EQUAL T_DIVIDE_EQUAL T_MOD_EQUAL
%token T_LEFT_SHIFT_EQUAL T_RIGHT_SHIFT_EQUAL T_B_AND_EQUAL T_XOR_EQUAL T_B_OR_EQUAL
%token T_ARROW
%token T_BREAK T_CASE T_CHAR T_CONST T_CONTINUE T_DEFAULT T_DO T_DOUBLE T_ELSE 
%token T_ENUM T_FLOAT T_FOR T_GOTO T_IF T_INT T_LONG T_REGISTER T_RETURN
%token T_SHORT T_SIGNED T_SIZEOF T_STATIC T_STRUCT T_SWITCH T_TYPEDEF T_UNION
%token T_UNSIGNED T_VOID T_WHILE
%token T_NUMBER T_WORD

%type <ast> TOP 
%type <number> T_NUMBER
%type <string> T_WORD

%start ROOT

%%

ROOT : TOP { g_root = $1; }

TOP  : T_NUMBER { $$ = new Number($1); }

%%

const AST* g_root; // Definition of variable (to match declaration earlier)

const AST* parseAST() {
    g_root = 0;
    yyparse();
    return g_root;
}
