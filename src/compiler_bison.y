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
    std::string *string;
    double number;
    PrimaryExpression *PrimaryExpressionPtr;
    Expression *ExpressionPtr;
}

%token STRING_LITERAL
%token PLUSPLUS MINUSMINUS
%token EQUAL_TO NOT_EQUAL_TO LESS_THAN_EQUAL MORE_THAN_EQUAL
%token AND OR
%token LEFT_SHIFT RIGHT_SHIFT
%token PLUS_EQUAL MINUS_EQUAL TIMES_EQUAL DIVIDE_EQUAL MOD_EQUAL
%token LEFT_SHIFT_EQUAL RIGHT_SHIFT_EQUAL B_AND_EQUAL XOR_EQUAL B_OR_EQUAL
%token ARROW
%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE 
%token ENUM ENUM_VAL FLOAT FOR GOTO IF INT LONG REGISTER RETURN
%token SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION
%token UNSIGNED VOID WHILE EXTERN VOLATILE
%token NUMBER IDENTIFIER TYPEDEF_T

%type <string> IDENTIFIER STRING_LITERAL ENUM_VAL
%type <number> NUMBER
%type <PrimaryExpressionPtr> PRIMARY_EXPRESSION
%type <ExpressionPtr> EXPRESSION ASSIGNMENT_EXPRESSION ARGUMENT_EXPRESSION_LIST POSTFIX_EXPRESSION UNARY_EXPRESSION CAST_EXPRESSION // TODO: Should be updated to specific types

%start ROOT

%%

ROOT: EXPRESSION { g_root = $1; }

EXPRESSION : ASSIGNMENT_EXPRESSION { $$ = $1;      /* TODO: FILL OUT EXPRESSION*/ }
           ;

ARGUMENT_EXPRESSION_LIST : ASSIGNMENT_EXPRESSION { $$ = $1; /* TODO: FIX THIS */ }
                         | ARGUMENT_EXPRESSION_LIST ',' ASSIGNMENT_EXPRESSION { $$ = $1; /* TODO: FIX THIS */ }
                         ;

ASSIGNMENT_EXPRESSION : POSTFIX_EXPRESSION { $$ = $1; /* TODO: FIX THIS */ }

CAST_EXPRESSION : UNARY_EXPRESSION                              {$$=$1;}
                | '(' TYPE_NAME ')' CAST_EXPRESSION             {$$=$1;}

UNARY_EXPRESSION : POSTFIX_EXPRESSION                           {$$=$1;}
                 | PLUSPLUS UNARY_EXPRESSION                    {$$=$2;}
                 | MINUSMINUS UNARY_EXPRESSION                  {$$=$2;}
                 | SIZEOF UNARY_EXPRESSION                      {$$=$2;}
                 | SIZEOF '(' TYPE_NAME ')'                     {$$ = new PrimaryExpression(1);}
                 | '&' CAST_EXPRESSION                          {$$=$2;}
                 | '*' CAST_EXPRESSION                          {$$=$2;}
                 | '+' CAST_EXPRESSION                          {$$=$2;}
                 | '-' CAST_EXPRESSION                          {$$=$2;}
                 | '~' CAST_EXPRESSION                          {$$=$2;}
                 | '!' CAST_EXPRESSION                          {$$=$2;}
                 ;

POSTFIX_EXPRESSION : PRIMARY_EXPRESSION                         {$$ = $1;}
                    | POSTFIX_EXPRESSION '[' EXPRESSION ']'     {$$ = $1;}
                    | POSTFIX_EXPRESSION '(' ')'                {$$ = $1;}
                    | POSTFIX_EXPRESSION '(' ARGUMENT_EXPRESSION_LIST ')' {$$=$1;} 
                    | POSTFIX_EXPRESSION '.' IDENTIFIER         {$$ = $1;}
                    | POSTFIX_EXPRESSION ARROW IDENTIFIER       {$$ = $1;}
                    | POSTFIX_EXPRESSION PLUSPLUS               {$$ = $1;}
                    | POSTFIX_EXPRESSION MINUSMINUS             {$$ = $1;}
                    ;

PRIMARY_EXPRESSION : IDENTIFIER                 { $$ = new PrimaryExpression(*$1, I); }
                   | NUMBER                     { $$ = new PrimaryExpression($1); }
                   | STRING_LITERAL      	    { $$ = new PrimaryExpression(*$1, S); }
                   | '(' EXPRESSION ')'         { $$ = new PrimaryExpression($2); }
                   | ENUM_VAL                   { $$ = new PrimaryExpression(*$1, EV); }
                   ;
%%

AST* g_root; // Definition of variable (to match declaration earlier)

AST* parseAST() {
    g_root = 0;
    yyparse();
    return g_root;
}
