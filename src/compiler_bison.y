%code requires{
    #include "ast.hpp"

    #include <cassert>

    extern AST* g_root; // A way of getting the AST out

    //! This is to fix problems when generating C++
    // We are declaring the functions provided by Flex, so
    // that Bison generated code can call them.
    int yylex(void);
    void yyerror(const char *);
}

%union{
    AST *ast;
    TopLevel* toplevel;
    double number;
    std::string* string;
}

%token STRING
%token PLUSPLUS MINUSMINUS
%token EQUAL_TO NOT_EQUAL_TO LESS_THAN_EQUAL MORE_THAN_EQUAL
%token AND OR
%token LEFT_SHIFT RIGHT_SHIFT
%token PLUS_EQUAL MINUS_EQUAL TIMES_EQUAL DIVIDE_EQUAL MOD_EQUAL
%token LEFT_SHIFT_EQUAL RIGHT_SHIFT_EQUAL B_AND_EQUAL XOR_EQUAL B_OR_EQUAL
%token ARROW
%token AUTO BREAK BOOL CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE 
%token ENUM FLOAT FOR GOTO IF INT LONG REGISTER RETURN
%token SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION
%token UNSIGNED VOID WHILE EXTERN VOLATILE
%token NUMBER IDENTIFIER TYPEDEF_T

%type <ast> TOP
%type <toplevel> DECLARATION
%type <number> NUMBER
%type <string> IDENTIFIER STRING

%start ROOT

%%

ROOT : TOP { g_root = $1; }

TOP  : DECLARATION  { $$ = new Global($1); }
     | TOP DECLARATION  { $$ = $1; $$->push_back($2); }

DECLARATION : IDENTIFIER IDENTIFIER ';' { $$ = new Declaration(*$1, *$2); }

%%

AST* g_root; // Definition of variable (to match declaration earlier)

AST* parseAST() {
    g_root = 0;
    yyparse();
    return g_root;
}
