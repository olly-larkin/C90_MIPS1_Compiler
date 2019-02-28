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
    char Char;
    Statement *StatementPtr;
    ExpressionStatement *ExpressionStatementPtr;
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

%type <string> IDENTIFIER STRING_LITERAL ENUM_VAL //TYPE_NAME TODO: bring back once being used
%type <Char> ASSIGNMENT_OPERATOR
%type <number> NUMBER
%type <ExpressionPtr> EXPRESSION ASSIGNMENT_EXPRESSION UNARY_EXPRESSION CAST_EXPRESSION POSTFIX_EXPRESSION PRIMARY_EXPRESSION MULTIPLICATIVE_EXPRESSION ADDITIVE_EXPRESSION SHIFT_EXPRESSION RELATIONAL_EXPRESSION EQUALITY_EXPRESSION AND_EXPRESSION EXCLUSIVE_OR_EXPRESSION INCLUSIVE_OR_EXPRESSION LOGICAL_AND_EXPRESSION LOGICAL_OR_EXPRESSION CONDITIONAL_EXPRESSION CONSTANT_EXPRESSION
%type <ArgumentExpressionListPtr> ARGUMENT_EXPRESSION_LIST
%type <StatementPtr> STATEMENT LABELED_STATEMENT COMPOUND_STATEMENT EXPRESSION_STATEMENT SELECTION_STATEMENT ITERATION_STATEMENT JUMP_STATEMENT STATEMENT_LIST

%nonassoc NOELSE
%nonassoc ELSE

%start ROOT

%%

ROOT : STATEMENT { g_root = $1; }

//TYPE_NAME : IDENTIFIER {$$ = $1;  /* TODO: Fill in later */}
//          ;


//**************************************************************************************
//------------------------------------- DECLARATIONS -----------------------------------
//**************************************************************************************
DECLARATION : DECLARATION_SPECIFIER {}
            | DECLARATION_SPECIFIER INIT_DECLARATOR_LIST {}
            ;

DECLARATION_SPECIFIER : STORAGE_CLASS_SPECIFIER DECLARATION_SPECIFIER {}
                    |   STORAGE_CLASS_SPECIFIER {}
                    |   TYPE_SPECIFIER DECLARATION_SPECIFIER {}
                    |   TYPE_SPECIFIER {}
                    |   TYPE_QUALIFIER DECLARATION_SPECIFIER {}
                    |   TYPE_QUALIFIER {}
                    ;

INIT_DECLARATOR_LIST : INIT_DECLARATOR {}
                    |  INIT_DECLARATOR_LIST ',' INIT_DECLARATOR  {}
                    ;

INIT_DECLARATOR : DECLARATOR {}
                | DECLARATOR '=' INITIALIZER  {}
                ;





STORAGE_CLASS_SPECIFIER : TYPEDEF {} 
                        | EXTERN {}
                        | STATIC {}
                        | AUTO {}
                        | REGISTER {}
                        ;

TYPE_SPECIFIER :  VOID {} 
                | CHAR {}
                | SHORT {}
                | INT {}
                | LONG {}
                | FLOAT {}
                | DOUBLE {}
                | SIGNED {}
                | UNSIGNED {}
                | STRUCT_UNION_SPEC {}
                | ENUM_SPEC {}
                | TYPEDEF_NAME {} 
                ;

STRUCT_UNION_SPEC : STRUCT_OR_UNION IDENTIFIER '{' STRUCT_DECLARATION_LIST '}' {}
                  | STRUCT_OR_UNION '{' STRUCT_DECLARATION_LIST '}' {}
                  | STRUCT_OR_UNION IDENTIFIER {}
                  ;

STRUCT_OR_UNION : STRUCT {}
                | UNION {}
                ;

STRUCT_DECLARATION_LIST : STRUCT_DECLARATION {}
                        | STRUCT_DECLARATION_LIST STRUCT_DECLARATION {}

STRUCT_DECLARATION : SPECIFIER_QUALIFIER_LIST STRUCT_DECLARATOR_LIST ';'
	               ;

//TODO:FILL IN GRAMMARS

SPECIFIER_QUALIFIER_LIST : 

STRUCT_DECLARATOR_LIST : 

ENUM_SPEC : 

TYPEDEF_NAME : 

TYPE_QUALIFIER : CONST {}
                | VOLATILE {}


//**************************************************************************************
//-------------------------------------- STATEMENTS ------------------------------------
//**************************************************************************************

STATEMENT : LABELED_STATEMENT        { $$ = $1; }
          | COMPOUND_STATEMENT      { $$ = $1; }
          | EXPRESSION_STATEMENT    { $$ = $1; }
          | SELECTION_STATEMENT     { $$ = $1; }
          | ITERATION_STATEMENT     { $$ = $1; }
          | JUMP_STATEMENT          { $$ = $1; }
          ;

LABELED_STATEMENT : CASE CONSTANT_EXPRESSION ':' STATEMENT   { $$ = new CaseBlock($2, $4); }
                 | DEFAULT ':' STATEMENT                    { $$ = new DefaultBlock($3); }  
                 ;

COMPOUND_STATEMENT : '{' '}'                                        { $$ = new ExpressionStatement(); }
//                   | '{' DECLARATION_LIST '}'  TODO: return when declarations done
                   | '{' STATEMENT_LIST '}'                         { $$ = $2; }
//                   | '{' DECLARATION_LIST STATEMENT_LIST '}'
                   ;

//DECLARATION_LIST : DECLARATION
//                 | DECLARATION_LIST DECLARATION
//                 ;

STATEMENT_LIST : STATEMENT                  { $$ = new StatementList($1); }
               | STATEMENT_LIST STATEMENT   { $$ = new StatementList(reinterpret_cast<StatementList*>($1), $2); }
               ;

EXPRESSION_STATEMENT : ';'              { $$ = new ExpressionStatement(); }
                     | EXPRESSION ';'   { $$ = new ExpressionStatement($1); }
                     ;

SELECTION_STATEMENT : IF '(' EXPRESSION ')' STATEMENT %prec NOELSE      { $$ = new IfStatement($3, $5); }
                    | IF '(' EXPRESSION ')' STATEMENT ELSE STATEMENT    { $$ = new IfElseStatement($3, $5, $7); }
                    | SWITCH '(' EXPRESSION ')' STATEMENT               { $$ = new SwitchStatement($3, $5); }
                    ;

ITERATION_STATEMENT : WHILE '(' EXPRESSION ')' STATEMENT                                { $$ = new WhileLoop($3, $5); }
                    | DO STATEMENT WHILE '(' EXPRESSION ')'                             { $$ = new DoWhileLoop($2, $5); }
                    | FOR '(' ';' ';' ')' STATEMENT                                     { $$ = new ForLoop(NULL,NULL,NULL,$6); }
                    | FOR '(' EXPRESSION ';' ';' ')' STATEMENT                          { $$ = new ForLoop($3,  NULL,NULL,$7); }
                    | FOR '(' ';' EXPRESSION ';' ')' STATEMENT                          { $$ = new ForLoop(NULL,$4,  NULL,$7); }
                    | FOR '(' ';' ';' EXPRESSION ')' STATEMENT                          { $$ = new ForLoop(NULL,NULL,$5  ,$7); }
                    | FOR '(' EXPRESSION ';' EXPRESSION ';' ')' STATEMENT               { $$ = new ForLoop($3,  $5,  NULL,$8); }
                    | FOR '(' ';' EXPRESSION ';' EXPRESSION ')' STATEMENT               { $$ = new ForLoop(NULL,$4,  $6  ,$8); }
                    | FOR '(' EXPRESSION ';' ';' EXPRESSION ')' STATEMENT               { $$ = new ForLoop($3,  NULL,$6  ,$8); }
                    | FOR '(' EXPRESSION ';' EXPRESSION ';' EXPRESSION ')' STATEMENT    { $$ = new ForLoop($3,  $5,  $7  ,$9); }
                    ;    

JUMP_STATEMENT : CONTINUE ';'           { $$ = new Continue(); }
               | BREAK ';'              { $$ = new Break(); }
               | RETURN ';'             { $$ = new Return(); }
               | RETURN EXPRESSION ';'  { $$ = new Return($2); }
               ;

//**************************************************************************************
//------------------------------------- EXPRESSIONS ------------------------------------
//**************************************************************************************

CONSTANT_EXPRESSION : EXPRESSION   { $$ = $1; }
                    ;

EXPRESSION : ASSIGNMENT_EXPRESSION { $$ = $1; }
           ;

ARGUMENT_EXPRESSION_LIST : ASSIGNMENT_EXPRESSION                                { $$ = new ArgumentExpressionList($1); }
                         | ARGUMENT_EXPRESSION_LIST ',' ASSIGNMENT_EXPRESSION   { $$ = $1; $$->addArg($3); }
                         ;

ASSIGNMENT_EXPRESSION : CONDITIONAL_EXPRESSION                                      { $$ = $1; }
                      | UNARY_EXPRESSION ASSIGNMENT_OPERATOR ASSIGNMENT_EXPRESSION  { $$ = new Assignment($1, $3, $2); }
                      ;

ASSIGNMENT_OPERATOR : '='                   { $$ = '='; }
                    | PLUS_EQUAL            { $$ = '+'; }
                    | MINUS_EQUAL           { $$ = '-'; }
                    | TIMES_EQUAL           { $$ = '*'; }
                    | DIVIDE_EQUAL          { $$ = '/'; }
                    | MOD_EQUAL             { $$ = '%'; }
                    | LEFT_SHIFT_EQUAL      { $$ = '<'; }
                    | RIGHT_SHIFT_EQUAL     { $$ = '>'; }
                    | B_AND_EQUAL           { $$ = '&'; }
                    | XOR_EQUAL             { $$ = '^'; }
                    | B_OR_EQUAL            { $$ = '|'; }
                    ;

CONDITIONAL_EXPRESSION : LOGICAL_OR_EXPRESSION                                              { $$ = $1; }
                       | LOGICAL_OR_EXPRESSION '?' EXPRESSION ':' CONDITIONAL_EXPRESSION    { $$ = new ConditionalOp($1, $3, $5); }
                       ;

LOGICAL_OR_EXPRESSION : LOGICAL_AND_EXPRESSION                                  { $$ = $1; }
                      | LOGICAL_OR_EXPRESSION OR LOGICAL_AND_EXPRESSION         { $$ = new LogicalOROp($1, $3); }
                      ;

LOGICAL_AND_EXPRESSION : INCLUSIVE_OR_EXPRESSION                                { $$ = $1; }
                       | LOGICAL_AND_EXPRESSION AND INCLUSIVE_OR_EXPRESSION     { $$ = new LogicalANDOp($1, $3); }
                       ;    

INCLUSIVE_OR_EXPRESSION : EXCLUSIVE_OR_EXPRESSION                               { $$ = $1; }
                        | INCLUSIVE_OR_EXPRESSION '|' EXCLUSIVE_OR_EXPRESSION   { $$ = new BitwiseInclusiveOROp($1, $3); }
                        ;

EXCLUSIVE_OR_EXPRESSION : AND_EXPRESSION                                 { $$ = $1; }
                        | EXCLUSIVE_OR_EXPRESSION '^' AND_EXPRESSION     { $$ = new BitwiseExclusiveOROp($1, $3); }
                        ;

AND_EXPRESSION : EQUALITY_EXPRESSION                        { $$ = $1; }
               | AND_EXPRESSION '&' EQUALITY_EXPRESSION     { $$ = new BitwiseANDOp($1, $3); }
               ;

EQUALITY_EXPRESSION : RELATIONAL_EXPRESSION                                     { $$ = $1; }
                    | EQUALITY_EXPRESSION EQUAL_TO RELATIONAL_EXPRESSION        { $$ = new EqualToOp($1, $3); }
                    | EQUALITY_EXPRESSION NOT_EQUAL_TO RELATIONAL_EXPRESSION    { $$ = new NotEqualToOp($1, $3); }
                    ;

RELATIONAL_EXPRESSION : SHIFT_EXPRESSION                                          { $$ = $1; }
                      | RELATIONAL_EXPRESSION '<' SHIFT_EXPRESSION                { $$ = new LessThanOp($1, $3); }
                      | RELATIONAL_EXPRESSION '>' SHIFT_EXPRESSION                { $$ = new MoreThanOp($1, $3); }
                      | RELATIONAL_EXPRESSION LESS_THAN_EQUAL SHIFT_EXPRESSION    { $$ = new LessThanEqualOp($1, $3); }
                      | RELATIONAL_EXPRESSION MORE_THAN_EQUAL SHIFT_EXPRESSION    { $$ = new MoreThanEqualOp($1, $3); }
                      ;

SHIFT_EXPRESSION : ADDITIVE_EXPRESSION                                  { $$ = $1; }
                 | SHIFT_EXPRESSION LEFT_SHIFT ADDITIVE_EXPRESSION      { $$ = new LeftShiftOp($1, $3); }
                 | SHIFT_EXPRESSION RIGHT_SHIFT ADDITIVE_EXPRESSION     { $$ = new RightShiftOp($1, $3); }
                 ;

ADDITIVE_EXPRESSION : MULTIPLICATIVE_EXPRESSION                           { $$ = $1; }
                    | ADDITIVE_EXPRESSION '+' MULTIPLICATIVE_EXPRESSION   { $$ = new AddOp($1, $3); }
                    | ADDITIVE_EXPRESSION '-' MULTIPLICATIVE_EXPRESSION   { $$ = new SubOp($1, $3); }
                    ;

MULTIPLICATIVE_EXPRESSION : CAST_EXPRESSION                               { $$ = $1; }
                          | MULTIPLICATIVE_EXPRESSION '*' CAST_EXPRESSION { $$ = new MultiplyOp($1, $3); }
                          | MULTIPLICATIVE_EXPRESSION '/' CAST_EXPRESSION { $$ = new DivideOp($1, $3); }
                          | MULTIPLICATIVE_EXPRESSION '%' CAST_EXPRESSION { $$ = new ModOp($1, $3); }
                          ;

CAST_EXPRESSION : UNARY_EXPRESSION                              { $$ = $1; }
//                | '(' TYPE_NAME ')' CAST_EXPRESSION             { $$ = new Cast_ToType($4, *$2); }
                ;

UNARY_EXPRESSION : POSTFIX_EXPRESSION                           { $$ = $1;}
                 | PLUSPLUS UNARY_EXPRESSION                    { $$ = new Unary_PrefixInc($2); }
                 | MINUSMINUS UNARY_EXPRESSION                  { $$ = new Unary_PrefixDec($2); }
                 | SIZEOF UNARY_EXPRESSION                      { $$ = new Unary_SizeOfExpr($2); }
//                 | SIZEOF '(' TYPE_NAME ')'                     { /* TODO: return after creating type_name */ }
                 | '&' CAST_EXPRESSION                          { $$ = new Unary_Reference($2); }
                 | '*' CAST_EXPRESSION                          { $$ = new Unary_Dereference($2);}
                 | '+' CAST_EXPRESSION                          { $$ = $2; /* TODO: CHECK */}
                 | '-' CAST_EXPRESSION                          { $$ = new Unary_Negation($2); }
                 | '~' CAST_EXPRESSION                          { $$ = new Unary_InvertOp($2); }
                 | '!' CAST_EXPRESSION                          { $$ = new Unary_NotOp($2); }
                 ;

POSTFIX_EXPRESSION : PRIMARY_EXPRESSION                                     { $$ = $1;}
                    | POSTFIX_EXPRESSION '[' EXPRESSION ']'                 { $$ = new Postfix_ArrIndex($1, $3); }
                    | POSTFIX_EXPRESSION '(' ')'                            { $$ = new Postfix_FnCall($1); }
                    | POSTFIX_EXPRESSION '(' ARGUMENT_EXPRESSION_LIST ')'   { $$ = new Postfix_FnCall($1, $3); } 
                    | POSTFIX_EXPRESSION '.' IDENTIFIER                     { $$ = new Postfix_DotIdentifier($1,*$3); }
                    | POSTFIX_EXPRESSION ARROW IDENTIFIER                   { $$ = new Postfix_ArrowIdentifier($1,*$3); }
                    | POSTFIX_EXPRESSION PLUSPLUS                           { $$ = new Postfix_IncOp($1); }
                    | POSTFIX_EXPRESSION MINUSMINUS                         { $$ = new Postfix_DecOp($1); }
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
