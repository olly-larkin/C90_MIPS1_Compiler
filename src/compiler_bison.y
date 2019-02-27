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
    Expression *ExpressionPtr;
    ArgumentExpressionList *ArgumentExpressionListPtr;
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

%type <string> IDENTIFIER STRING_LITERAL ENUM_VAL TYPE_NAME
%type <number> NUMBER
%type <ExpressionPtr> EXPRESSION ASSIGNMENT_EXPRESSION UNARY_EXPRESSION CAST_EXPRESSION POSTFIX_EXPRESSION PRIMARY_EXPRESSION MULTIPLICATIVE_EXPRESSION ADDITIVE_EXPRESSION
%type <ArgumentExpressionListPtr> ARGUMENT_EXPRESSION_LIST

%start ROOT

%%

ROOT: EXPRESSION { g_root = $1; }

EXPRESSION : ASSIGNMENT_EXPRESSION { $$ = $1;      /* TODO: FILL OUT EXPRESSION*/ }
           ;

TYPE_NAME : IDENTIFIER {$$ = $1;  /* TODO: Fill in later */}
          ;

ARGUMENT_EXPRESSION_LIST : ASSIGNMENT_EXPRESSION { $$ = new ArgumentExpressionList(); /* TODO: FIX THIS */ }
                         | ARGUMENT_EXPRESSION_LIST ',' ASSIGNMENT_EXPRESSION { $$ = $1; /* TODO: FIX THIS */ }
                         ;

ASSIGNMENT_EXPRESSION : ADDITIVE_EXPRESSION { $$ = $1; /* TODO: FIX THIS */ }
                      ;

//**************************************************************************************

ADDITIVE_EXPRESSION : MULTIPLICATIVE_EXPRESSION                           { $$ = $1; }
                    | ADDITIVE_EXPRESSION '+' MULTIPLICATIVE_EXPRESSION   { $$ = new AddOp($1, $3); }
                    | ADDITIVE_EXPRESSION '-' MULTIPLICATIVE_EXPRESSION   { $$ = new SubOp($1, $3); }

MULTIPLICATIVE_EXPRESSION : CAST_EXPRESSION                               { $$ = $1; }
                          | MULTIPLICATIVE_EXPRESSION '*' CAST_EXPRESSION { $$ = new MultiplyOp($1, $3); }
                          | MULTIPLICATIVE_EXPRESSION '/' CAST_EXPRESSION { $$ = new DivideOp($1, $3); }
                          | MULTIPLICATIVE_EXPRESSION '%' CAST_EXPRESSION { $$ = new ModOp($1, $3); }
                          ;

CAST_EXPRESSION : UNARY_EXPRESSION                              { $$ = $1; }
                | '(' TYPE_NAME ')' CAST_EXPRESSION             { $$ = new Cast_ToType($4, *$2); }
                ;

UNARY_EXPRESSION : POSTFIX_EXPRESSION                           { $$ = $1;}
                 | PLUSPLUS UNARY_EXPRESSION                    { $$ = new Unary_PrefixInc($2); }
                 | MINUSMINUS UNARY_EXPRESSION                  { $$ = new Unary_PrefixDec($2); }
                 | SIZEOF UNARY_EXPRESSION                      { $$ = new Unary_SizeOfExpr($2); }
                 | SIZEOF '(' TYPE_NAME ')'                     { /* TODO: return after creating type_name */ }
                 | '&' CAST_EXPRESSION                          { $$ = new Unary_Reference($2); }
                 | '*' CAST_EXPRESSION                          { $$ = new Unary_Dereference($2);}
                 | '+' CAST_EXPRESSION                          { $$ = $2; /* TODO: CHECK */}
                 | '-' CAST_EXPRESSION                          { $$ = new Unary_Negation($2); }
                 | '~' CAST_EXPRESSION                          { $$ = new Unary_InvertOp($2); }
                 | '!' CAST_EXPRESSION                          { $$ = new Unary_NotOp($2); }
                 ;

POSTFIX_EXPRESSION : PRIMARY_EXPRESSION                         { $$ = $1;}
                    | POSTFIX_EXPRESSION '[' EXPRESSION ']'     { $$ = new Postfix_ArrIndex($1, $3); }
                    | POSTFIX_EXPRESSION '(' ')'                { $$ = new Postfix_FnCall($1); }
                    | POSTFIX_EXPRESSION '(' ARGUMENT_EXPRESSION_LIST ')' { $$ = new Postfix_FnCall($1, $3); } 
                    | POSTFIX_EXPRESSION '.' IDENTIFIER         { $$ = new Postfix_DotIdentifier($1,*$3); }
                    | POSTFIX_EXPRESSION ARROW IDENTIFIER       { $$ = new Postfix_ArrowIdentifier($1,*$3); }
                    | POSTFIX_EXPRESSION PLUSPLUS               { $$ = new Postfix_IncOp($1); }
                    | POSTFIX_EXPRESSION MINUSMINUS             { $$ = new Postfix_DecOp($1); }
                    ;

PRIMARY_EXPRESSION : IDENTIFIER                 { $$ = new PrimaryExp_Identifier(*$1); }
                   | NUMBER                     { $$ = new PrimaryExp_Constant($1); }
                   | STRING_LITERAL      	    { $$ = new PrimaryExp_StrLiteral(*$1); }
                   | '(' EXPRESSION ')'         { $$ = $2; }
                   | ENUM_VAL                   { $$ = new PrimaryExp_EnumVal(*$1); }
                   ;
%%

AST* g_root; // Definition of variable (to match declaration earlier)

AST* parseAST() {
    g_root = 0;
    yyparse();
    return g_root;
}
