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
    Global *global;
    TopLevel* toplevel;
    double number;
    std::string* string;
    Type_Specifier typeSpecifier;
    BasicType* basictype;
}

%token STRING
%token PLUSPLUS MINUSMINUS
%token EQUAL_TO NOT_EQUAL_TO LESS_THAN_EQUAL MORE_THAN_EQUAL
%token AND OR
%token LEFT_SHIFT RIGHT_SHIFT
%token PLUS_EQUAL MINUS_EQUAL TIMES_EQUAL DIVIDE_EQUAL MOD_EQUAL
%token LEFT_SHIFT_EQUAL RIGHT_SHIFT_EQUAL B_AND_EQUAL XOR_EQUAL B_OR_EQUAL
%token ARROW
%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE 
%token ENUM FLOAT FOR GOTO IF INT LONG REGISTER RETURN
%token SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION
%token UNSIGNED VOID WHILE EXTERN VOLATILE
%token NUMBER IDENTIFIER TYPEDEF_T

%type <global> GLOBAL
%type <toplevel> DECLARATION
%type <number> NUMBER
%type <string> IDENTIFIER STRING
%type <typeSpecifier> TYPE_SPECIFIER
%type <basictype> TYPE

%start ROOT

%%

ROOT : GLOBAL { g_root = $1; }

GLOBAL  : DECLARATION  { $$ = new Global($1); }
        | GLOBAL DECLARATION { $$ = $1; $$->push_back($2); }

DECLARATION : TYPE IDENTIFIER ';' { $$ = new Declaration(*$1, *$2); }

TYPE : TYPE_SPECIFIER { $$ = new BasicType({},{$1},{}); }

TYPE_SPECIFIER : VOID			{ $$ = Void; }							
		       | CHAR			{ $$ = Char; }							
		       | SHORT			{ $$ = Short; }					
		       | INT			{ $$ = Int; }					
		       | LONG			{ $$ = Long; }						
		       | FLOAT			{ $$ = Float; }						 
		       | DOUBLE			{ $$ = Double; }						 
		       | SIGNED			{ $$ = Signed; }						
		       | UNSIGNED       { $$ = Unsigned; }
               | TYPEDEF_T      { $$ = Typedef_T; }


%%

AST* g_root; // Definition of variable (to match declaration earlier)

AST* parseAST() {
    g_root = 0;
    yyparse();
    return g_root;
}
