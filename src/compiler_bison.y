%code requires{
    #include "ast.hpp"

    #include <cassert>
    #include <fstream>

    extern FILE *yyin;
    extern AST* g_root; // A way of getting the AST out

    //! This is to fix problems when generating C++
    // We are declaring the functions provided by Flex, so
    // that Bison generated code can call them.
    int yylex(void);
    void yyerror(const char *);
}
%define parse.error verbose

%union{
    std::string *string;
    double number;

    BaseExpression *BaseExpressionPtr;
    BaseList *BaseListPtr;
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

%type <string> IDENTIFIER STRING_LITERAL ENUM_VAL CONST VOLATILE TYPEDEF_T
%type <number> NUMBER
%type <BaseListPtr> argument_expression_list
%type <BaseExpressionPtr> expression conditional_expression logical_or_expression logical_and_expression inclusive_or_expression exclusive_or_expression and_expression equality_expression relational_expression shift_expression additive_expression multiplicative_expression unary_expression postfix_expression primary_expression

%nonassoc NOELSE
%nonassoc ELSE

%start ROOT

%%

ROOT : expression { g_root = $1; }

/*
//**************************************************************************************
//----------------------------------------- TOP ----------------------------------------
//**************************************************************************************
top_container : translation_unit { $$ = new Top_Container($1); }

translation_unit : external_declaration { $$ = new Translation_Unit(NULL, $1); }
                 | translation_unit external_declaration { $$ = new Translation_Unit($1, $2); }
                 ;

external_declaration : function_definition { $$ = new External_Declaration_Func($1); }
                     | declaration { $$ = new External_Declaration_Dec($1); }
                     ;

function_definition : declaration_specifier declarator compound_statement { $$ = new Function_Definition($1, $2, $3); }
                    | declarator compound_statement { $$ = new Function_Definition(NULL, $1, $2); }
                    ;

//**************************************************************************************
//------------------------------------- DECLARATIONS -----------------------------------
//**************************************************************************************

declaration : declaration_specifier ';' { $$ = new DeclarationNode($1, NULL); }
            | declaration_specifier init_declarator_list ';' { $$ = new DeclarationNode($1, $2); }
            ;

declaration_specifier : TYPEDEF declaration_specifier { $$ = new Dec_Spec_TypeDef($2); }
                      | TYPEDEF { $$ = new Dec_Spec_TypeDef(NULL); }
                      | type_specifier declaration_specifier { $$ = new Dec_Spec_TypeSpec($2, $1); }
                      | type_specifier { $$ = new Dec_Spec_TypeSpec(NULL, $1); }
                      ;

init_declarator_list : init_declarator { $$ = new Init_Dec_List(NULL, $1); }
                     | init_declarator_list ',' init_declarator  { $$ = new Init_Dec_List($1, $3); }
                     ;

init_declarator : declarator { $$ = $1; }
                | declarator '=' initializer  { $$ = new Init_Declarator($1, $3); }
                ;

type_specifier : VOID { $$ = new Type_Specifier_Basic("void"); }
               | CHAR { $$ = new Type_Specifier_Basic("char"); }
               | SHORT { $$ = new Type_Specifier_Basic("short"); }
               | INT { $$ = new Type_Specifier_Basic("int"); }
               | LONG { $$ = new Type_Specifier_Basic("long"); }
               | FLOAT { $$ = new Type_Specifier_Basic("float"); }
               | DOUBLE { $$ = new Type_Specifier_Basic("double"); }
               | SIGNED { $$ = new Type_Specifier_Basic("signed"); }
               | UNSIGNED { $$ = new Type_Specifier_Basic("unsigned"); }
               | struct_spec { $$ = $1; }
               | enum_specifier { $$ = $1; }
               | TYPEDEF_T { $$ = new Type_Specifier_Typedef(*$1); }
               ;

specifier_list : type_specifier specifier_list { $$ = new Type_Specifier_List($2, $1); }
               | type_specifier { $$ = new Type_Specifier_List(NULL, $1); }
               ;

struct_spec : STRUCT IDENTIFIER '{' struct_declaration_list '}' { $$ = new Struct_Specifier($4, *$2); }
            | STRUCT '{' struct_declaration_list '}' { $$ = new Struct_Specifier($3); }
            | STRUCT IDENTIFIER { $$ = new Struct_Specifier(*$2); }
            ;

struct_declaration_list : struct_declaration { $$ = new Struct_Declaration_List(NULL, $1); }
                        | struct_declaration_list struct_declaration { $$ = new Struct_Declaration_List($1, $2); }

struct_declaration : specifier_list struct_declarator_list ';' { $$ = new Struct_Declaration($1, $2); }
	               ;

struct_declarator_list : struct_declarator { $$ = new Struct_Declarator_List(NULL, $1); }
                       | struct_declarator_list ',' struct_declarator { $$ = new Struct_Declarator_List($1, $3); }
                       ;

struct_declarator : declarator { $$ = new Struct_Declarator($1, NULL); }
                  | ':' constant_expression { $$ = new Struct_Declarator(NULL, $2); }
                  | declarator ':' constant_expression { $$ = new Struct_Declarator($1, $3); }
                  ;

enum_specifier : ENUM '{' enum_list '}' { $$ = new Enum_Specifier($3); }
          | ENUM IDENTIFIER '{' enum_list '}' { $$ = new Enum_Specifier($4, *$2); }
          | ENUM IDENTIFIER { $$ = new Enum_Specifier(*$2); }
          ;

enum_list : enumerator { $$ = new Enum_Element_List(NULL, $1); }
          | enum_list ',' enumerator { $$ = new Enum_Element_List($1, $3); }
          ;

enumerator : IDENTIFIER { $$ = new Enum_Element(*$1, NULL); }
           | IDENTIFIER '=' constant_expression { $$ = new Enum_Element(*$1, $3); }
           ;

declarator : pointer direct_declarator { $$ = new Direct_Dec_Pointer($2, $1); }
           | direct_declarator { $$ = $1; }
           ;

direct_declarator : IDENTIFIER { $$ = new Dir_Dec_Iden(*$1); }
                  | '(' declarator ')' { $$ = new Dir_Dec_Dec($2); }
                  | direct_declarator '[' constant_expression ']' { $$ = new Dir_Dec_Arr($1, $3); }
                  | direct_declarator '[' ']' { $$ = new Dir_Dec_Arr($1, NULL); }
                  | direct_declarator '(' parameter_list ')' { $$ = new Dir_Dec_Func($1, $3); }
                  | direct_declarator '(' ')' { $$ = new Dir_Dec_Func($1, NULL); }
                  ;

pointer : '*' { $$ = new Pointer(NULL); }
        | '*' pointer { $$ = new Pointer($2); }
	    ;

parameter_list : parameter_declaration { $$ = new Param_List(NULL, $1); }
               | parameter_list ',' parameter_declaration { $$ = new Param_List($1, $3); }
               ;

parameter_declaration : declaration_specifier declarator { $$ = new Param_Dec($1, $2, NULL); }
                      | declaration_specifier abstract_declarator { $$ = new Param_Dec($1, NULL, $2); }
                      | declaration_specifier { $$ = new Param_Dec($1, NULL, NULL); }
                      ;

type_name : specifier_list { $$ = new Type_Name($1, NULL); }
	      | specifier_list abstract_declarator { $$ = new Type_Name($1, $2); }
	      ;

abstract_declarator : pointer { $$ = new Abstract_Declarator($1, NULL); }
                    | direct_abstract_declarator { $$ = new Abstract_Declarator(NULL, $1); }
                    | pointer direct_abstract_declarator { $$ = new Abstract_Declarator($1, $2); }
                    ;

direct_abstract_declarator : '(' abstract_declarator ')' { $$ = new Dir_Abs_Dec($2); }
                           | '[' ']' { $$ = new Dir_Abs_Arr(NULL, NULL); }
                           | '[' constant_expression ']' { $$ = new Dir_Abs_Arr(NULL, $2); }
                           | direct_abstract_declarator '[' ']' { $$ = new Dir_Abs_Arr($1, NULL); }
                           | direct_abstract_declarator '[' constant_expression ']' { $$ = new Dir_Abs_Arr($1, $3); }
                           | '(' ')' { $$ = new Dir_Abs_Func(NULL, NULL); }
                           | '(' parameter_list ')' { $$ = new Dir_Abs_Func(NULL, $2); }
                           | direct_abstract_declarator '(' ')' { $$ = new Dir_Abs_Func($1, NULL); }
                           | direct_abstract_declarator '(' parameter_list ')' { $$ = new Dir_Abs_Func($1, $3); }
                           ;

initializer : assignment_expression { $$ = new Decl_initializer_expr($1); }
            | '{' initializer_list '}' { $$ = $2; }
            | '{' initializer_list ',' '}' { $$ = $2; }
            ;

initializer_list : initializer { $$ = new Decl_init_list($1); }
                 | initializer_list ',' initializer { $$ = new Decl_init_list($1, $3); }
                 ;

//**************************************************************************************
//-------------------------------------- STATEMENTS ------------------------------------
//**************************************************************************************

statement : labeled_statement       { $$ = $1; }
          | compound_statement      { $$ = $1; }
          | expression_statement    { $$ = $1; }
          | selection_statement     { $$ = $1; }
          | iteration_statement     { $$ = $1; }
          | jump_statement          { $$ = $1; }
          ;

labeled_statement : CASE constant_expression ':' statement   { $$ = new CaseBlock($2, $4); }
                  | DEFAULT ':' statement                    { $$ = new DefaultBlock($3); }
                  ;

compound_statement : '{' '}'                                        { $$ = new CompoundStatement(NULL, NULL); }
                   | '{' declaration_list '}'                       { $$ = new CompoundStatement($2, NULL); }     
                   | '{' statement_list '}'                         { $$ = new CompoundStatement(NULL, $2); }
                   | '{' declaration_list statement_list '}'        { $$ = new CompoundStatement($2, $3); }
                   ;

declaration_list : declaration                    { $$ = new DeclarationList(NULL, $1); }         
                 | declaration_list declaration   { $$ = new DeclarationList($1, $2); }
                 ;

statement_list : statement                  { $$ = new StatementList($1); }
               | statement_list statement   { $$ = new StatementList(reinterpret_cast<StatementList*>($1), $2); }
               ;

expression_statement : ';'              { $$ = new ExpressionStatement(); }
                     | expression ';'   { $$ = new ExpressionStatement($1); }
                     ;

selection_statement : IF '(' expression ')' statement %prec NOELSE      { $$ = new IfStatement($3, $5); }
                    | IF '(' expression ')' statement ELSE statement    { $$ = new IfElseStatement($3, $5, $7); }
                    | SWITCH '(' expression ')' statement               { $$ = new SwitchStatement($3, $5); }
                    ;

iteration_statement : WHILE '(' expression ')' statement                                { $$ = new WhileLoop($3, $5); }
                    | DO statement WHILE '(' expression ')'                             { $$ = new DoWhileLoop($2, $5); }
                    | FOR '(' ';' ';' ')' statement                                     { $$ = new ForLoop(NULL,NULL,NULL,$6); }
                    | FOR '(' expression ';' ';' ')' statement                          { $$ = new ForLoop($3,  NULL,NULL,$7); }
                    | FOR '(' ';' expression ';' ')' statement                          { $$ = new ForLoop(NULL,$4,  NULL,$7); }
                    | FOR '(' ';' ';' expression ')' statement                          { $$ = new ForLoop(NULL,NULL,$5  ,$7); }
                    | FOR '(' expression ';' expression ';' ')' statement               { $$ = new ForLoop($3,  $5,  NULL,$8); }
                    | FOR '(' ';' expression ';' expression ')' statement               { $$ = new ForLoop(NULL,$4,  $6  ,$8); }
                    | FOR '(' expression ';' ';' expression ')' statement               { $$ = new ForLoop($3,  NULL,$6  ,$8); }
                    | FOR '(' expression ';' expression ';' expression ')' statement    { $$ = new ForLoop($3,  $5,  $7  ,$9); }
                    ;

jump_statement : CONTINUE ';'           { $$ = new Continue(); }
               | BREAK ';'              { $$ = new Break(); }
               | RETURN ';'             { $$ = new Return(); }
               | RETURN expression ';'  { $$ = new Return($2); }
               ;
*/
//**************************************************************************************
//------------------------------------- EXPRESSIONS ------------------------------------
//**************************************************************************************

argument_expression_list : expression                                { $$ = new ArgumentExprList(NULL, $1); }
                         | argument_expression_list ',' expression   { $$ = new ArgumentExprList($1, $3); }
                         ;

expression : conditional_expression                         { $$ = $1; }
           | unary_expression '=' expression                { $$ = new Assignment($1, $3); }
           | unary_expression PLUS_EQUAL expression         { $$ = new AddAssignment($1, $3); }
           | unary_expression MINUS_EQUAL expression        { $$ = new SubAssignment($1, $3); }
           | unary_expression TIMES_EQUAL expression        { $$ = new MulAssignment($1, $3); }
           | unary_expression DIVIDE_EQUAL expression       { $$ = new DivAssignment($1, $3); }
           | unary_expression MOD_EQUAL expression          { $$ = new ModAssignment($1, $3); }
           | unary_expression LEFT_SHIFT_EQUAL expression   { $$ = new LeftShiftAssignment($1, $3); }
           | unary_expression RIGHT_SHIFT_EQUAL expression  { $$ = new RightShiftAssignment($1, $3); }
           | unary_expression B_AND_EQUAL expression        { $$ = new BitwiseANDAssignment($1, $3); }
           | unary_expression XOR_EQUAL expression          { $$ = new BitwiseXORAssignment($1, $3); }
           | unary_expression B_OR_EQUAL expression         { $$ = new BitwiseORAssignment($1, $3); }
           ;

conditional_expression : logical_or_expression                                              { $$ = $1; }
                       | logical_or_expression '?' expression ':' conditional_expression    { $$ = new ConditionalOp($1, $3, $5); }
                       ;

logical_or_expression : logical_and_expression                                  { $$ = $1; }
                      | logical_or_expression OR logical_and_expression         { $$ = new LogicalOROp($1, $3); }
                      ;

logical_and_expression : inclusive_or_expression                                { $$ = $1; }
                       | logical_and_expression AND inclusive_or_expression     { $$ = new LogicalANDOp($1, $3); }
                       ;

inclusive_or_expression : exclusive_or_expression                               { $$ = $1; }
                        | inclusive_or_expression '|' exclusive_or_expression   { $$ = new BitwiseInclusiveOROp($1, $3); }
                        ;

exclusive_or_expression : and_expression                                 { $$ = $1; }
                        | exclusive_or_expression '^' and_expression     { $$ = new BitwiseExclusiveOROp($1, $3); }
                        ;

and_expression : equality_expression                        { $$ = $1; }
               | and_expression '&' equality_expression     { $$ = new BitwiseANDOp($1, $3); }
               ;

equality_expression : relational_expression                                     { $$ = $1; }
                    | equality_expression EQUAL_TO relational_expression        { $$ = new EqualToOp($1, $3); }
                    | equality_expression NOT_EQUAL_TO relational_expression    { $$ = new NotEqualToOp($1, $3); }
                    ;

relational_expression : shift_expression                                          { $$ = $1; }
                      | relational_expression '<' shift_expression                { $$ = new LessThanOp($1, $3); }
                      | relational_expression '>' shift_expression                { $$ = new MoreThanOp($1, $3); }
                      | relational_expression LESS_THAN_EQUAL shift_expression    { $$ = new LessThanEqualToOp($1, $3); }
                      | relational_expression MORE_THAN_EQUAL shift_expression    { $$ = new MoreThanEqualToOp($1, $3); }
                      ;

shift_expression : additive_expression                                  { $$ = $1; }
                 | shift_expression LEFT_SHIFT additive_expression      { $$ = new LeftShiftOp($1, $3); }
                 | shift_expression RIGHT_SHIFT additive_expression     { $$ = new RightShiftOp($1, $3); }
                 ;

additive_expression : multiplicative_expression                           { $$ = $1; }
                    | additive_expression '+' multiplicative_expression   { $$ = new AddOp($1, $3); }
                    | additive_expression '-' multiplicative_expression   { $$ = new SubOp($1, $3); }
                    ;

multiplicative_expression : unary_expression                               { $$ = $1; }
                          | multiplicative_expression '*' unary_expression { $$ = new MultiplyOp($1, $3); }
                          | multiplicative_expression '/' unary_expression { $$ = new DivideOp($1, $3); }
                          | multiplicative_expression '%' unary_expression { $$ = new ModOp($1, $3); }
                          ;

unary_expression : postfix_expression                            { $$ = $1;}
                 | PLUSPLUS unary_expression                     { $$ = new PrefixIncOp($2); }
                 | MINUSMINUS unary_expression                   { $$ = new PrefixDecOp($2); }
                 | SIZEOF unary_expression                       { $$ = new SizeOfExpr($2); }
//TODO: come back                 | SIZEOF '(' type_name ')'                      { $$ = new SizeOfType($3); }
                 | '&' unary_expression                          { $$ = new ReferenceOp($2); }
                 | '*' unary_expression                          { $$ = new DereferenceOp($2);}
                 | '+' unary_expression                          { $$ = $2; }
                 | '-' unary_expression                          { $$ = new NegationOp($2); }
                 | '~' unary_expression                          { $$ = new InvertOp($2); }
                 | '!' unary_expression                          { $$ = new NotOp($2); }
                 ;

postfix_expression : primary_expression                                    { $$ = $1;}
                   | postfix_expression '[' expression ']'                 { $$ = new PostfixArrIndex($1, $3); }
                   | postfix_expression '(' ')'                            { $$ = new PostfixFuncCall($1, NULL); }
                   | postfix_expression '(' argument_expression_list ')'   { $$ = new PostfixFuncCall($1, $3); }
                   | postfix_expression '.' IDENTIFIER                     { $$ = new PostfixDotOp($1,*$3); }
                   | postfix_expression ARROW IDENTIFIER                   { $$ = new PostfixArrowOp($1,*$3); }
                   | postfix_expression PLUSPLUS                           { $$ = new PostfixIncOp($1); }
                   | postfix_expression MINUSMINUS                         { $$ = new PostfixDecOp($1); }
                   ;

primary_expression : IDENTIFIER                 { $$ = new PrimaryExprIdentifier(*$1); }
                   | NUMBER                     { $$ = new PrimaryExprConstant($1); }
                   | STRING_LITERAL      	    { $$ = new PrimaryExprStrLiteral(*$1); }
                   | '(' expression ')'         { $$ = $2; }
                   | ENUM_VAL                   { $$ = new PrimaryExprEnumVal(*$1); }
                   ;
%%

AST* g_root; // Definition of variable (to match declaration earlier)

AST* parseAST() {
    g_root = 0;
    yyparse();
    return g_root;
}

AST* parseAST(char* in) {
    g_root = 0;
    yyin = fopen(in, "r");
    if(yyin) { 
	    yyparse();
    }
    fclose(yyin);
    return g_root;
}
