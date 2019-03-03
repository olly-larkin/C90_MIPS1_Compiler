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
    std::string *string;
    double number;
    char Char;

    AST *ast;
    Expression *ExpressionPtr;
    ArgumentExpressionList *ArgumentExpressionListPtr;
    Statement *StatementPtr;
    StatementList *StatementListPtr;
    Declaration *DeclarationPtr;
    Decl_init_list *DeclInitList;
    Type *TypePtr;
    Pointer *PointerPtr;
    Enum_element_list *EnumElementList;
    Enum_element *EnumElement;
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

%type <string> IDENTIFIER STRING_LITERAL ENUM_VAL CONST VOLATILE
%type <Char> assignment_operator
%type <number> NUMBER
%type <ExpressionPtr> expression assignment_expression unary_expression postfix_expression primary_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression conditional_expression constant_expression
%type <ArgumentExpressionListPtr> argument_expression_list
%type <StatementPtr> statement labeled_statement compound_statement expression_statement selection_statement iteration_statement jump_statement 
%type <StatementListPtr> statement_list
%type <DeclarationPtr> declaration initializer
%type <DeclInitList> initializer_list
%type <PointerPtr> pointer
%type <EnumElement> enumerator 
%type <EnumElementList> enum_list

%nonassoc NOELSE
%nonassoc ELSE

%start ROOT

%%

ROOT : enum_list { g_root = $1; }

//**************************************************************************************
//----------------------------------------- TOP ----------------------------------------
//**************************************************************************************

translation_unit : external_declaration {}
                 | translation_unit external_declaration {}
                 ;

external_declaration : function_definition {}
                     | declaration {}
                     ;

function_definition : //declaration_specifiers declarator declaration_list compound_statement {}
                    //| declaration_specifiers declarator compound_statement {}
                    //| declarator declaration_list compound_statement {}
                     declarator compound_statement {}
                    ;

//**************************************************************************************
//------------------------------------- DECLARATIONS -----------------------------------
//**************************************************************************************

declaration : declaration_specifier ';' {}
            | declaration_specifier init_declarator_list ';' {}
            ;

declaration_specifier : TYPEDEF declaration_specifier {}
                    |   TYPEDEF {}
                    |   type_specifier declaration_specifier {}
                    |   type_specifier {}
                    ;

init_declarator_list : init_declarator {}
                    |  init_declarator_list ',' init_declarator  {}
                    ;

init_declarator : declarator {}
                | declarator '=' initializer  {}
                ;

type_specifier :  VOID {}
                | CHAR {}
                | SHORT {}
                | INT {}
                | LONG {}
                | FLOAT {}
                | DOUBLE {}
                | SIGNED {}
                | UNSIGNED {}
                | struct_spec {}
                | enum_specifier {}
                | TYPEDEF_T {}
                ;

specifier_list : type_specifier specifier_list {}
               | type_specifier {}
               ;

struct_spec : STRUCT IDENTIFIER '{' struct_declaration_list '}' {}
            | STRUCT '{' struct_declaration_list '}' {}
            | STRUCT IDENTIFIER {}
            ;


struct_declaration_list : struct_declaration {}
                        | struct_declaration_list struct_declaration {}

struct_declaration : specifier_list struct_declarator_list ';' {}
	               ;

struct_declarator_list : struct_declarator {}
                       | struct_declarator_list ',' struct_declarator {}
                       ;

struct_declarator : declarator {}
                  | constant_expression {}
                  | declarator ':' constant_expression {}
                  ;



enum_specifier : ENUM '{' enum_list '}' {}
          | ENUM IDENTIFIER '{' enum_list '}' {}
          | ENUM IDENTIFIER {}
          ;

enum_list : enumerator { $$ = new Enum_element_list(NULL, $1); }
          | enum_list ',' enumerator { $$ = new Enum_element_list($1, $3); }
          ;

enumerator : IDENTIFIER { $$ = new Enum_element(*$1, NULL); }
           | IDENTIFIER '=' constant_expression { $$ = new Enum_element(*$1, $3); }
           ;

declarator : pointer direct_declarator {}
           | direct_declarator {}
           ;

direct_declarator : IDENTIFIER {}
                  | '(' declarator ')' {}
                  | direct_declarator '[' constant_expression ']' {}
                  | direct_declarator '[' ']' {}
                  | direct_declarator '(' parameter_list ')' {}
                  | direct_declarator '(' ')' {}
                  ;

pointer : '*' { $$ = new Pointer(NULL); }
        | '*' pointer { $$ = new Pointer($2); }
	    ;

parameter_list : parameter_declaration {}
               | parameter_list ',' parameter_declaration {}
               ;

parameter_declaration : declaration_specifier declarator {}
                      | declaration_specifier abstract_declarator {}
                      | declaration_specifier {}
                      ;

//TODO: abstract declarators=====================================
type_name : specifier_list {}
	        | specifier_list abstract_declarator {}
	        ;

abstract_declarator : pointer {}
                    | direct_abstract_declarator {}
                    | pointer direct_abstract_declarator {}
                    ;

direct_abstract_declarator : '(' abstract_declarator ')' {}
                           | '[' ']' {}
                           | '[' constant_expression ']' {}
                           | direct_abstract_declarator '[' ']' {}
                           | direct_abstract_declarator '[' constant_expression ']' {}
                           | '(' ')' {}
                           | '(' parameter_list ')' {}
                           | direct_abstract_declarator '(' ')' {}
                           | direct_abstract_declarator '(' parameter_list ')' {}
                           ;
//==============================================================

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

statement : labeled_statement        { $$ = $1; }
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
 //                  | '{' declaration_list '}'                       { $$ = new CompoundStatement($2, NULL); }     TODO: need to come back and fix once 
                   | '{' statement_list '}'                         { $$ = new CompoundStatement(NULL, $2); }
 //                  | '{' declaration_list statement_list '}'        { $$ = new CompoundStatement($2, $3); }
                   ;

//declaration_list : declaration                    { $$ = new DeclarationList(NULL, $1); }         // TODO: return once declaration has been made
//                 | declaration_list declaration   { $$ = new DeclarationList($1, $2); }
//                ;

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

//**************************************************************************************
//------------------------------------- EXPRESSIONS ------------------------------------
//**************************************************************************************

constant_expression : expression   { $$ = $1; }
                    ;

expression : assignment_expression { $$ = $1; }
           ;

argument_expression_list : assignment_expression                                { $$ = new ArgumentExpressionList($1); }
                         | argument_expression_list ',' assignment_expression   { $$ = new ArgumentExpressionList($1, $3); }
                         ;

assignment_expression : conditional_expression                                      { $$ = $1; }
                      | unary_expression assignment_operator assignment_expression  { $$ = new Assignment($1, $3, $2); }
                      ;

assignment_operator : '='                   { $$ = '='; }
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
                      | relational_expression LESS_THAN_EQUAL shift_expression    { $$ = new LessThanEqualOp($1, $3); }
                      | relational_expression MORE_THAN_EQUAL shift_expression    { $$ = new MoreThanEqualOp($1, $3); }
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
                 | PLUSPLUS unary_expression                     { $$ = new Unary_PrefixInc($2); }
                 | MINUSMINUS unary_expression                   { $$ = new Unary_PrefixDec($2); }
                 | SIZEOF unary_expression                       { $$ = new Unary_SizeOfExpr($2); }
//                 | SIZEOF '(' type_name ')'                      { /* TODO: return after creating type_name */ }
                 | '&' unary_expression                          { $$ = new Unary_Reference($2); }
                 | '*' unary_expression                          { $$ = new Unary_Dereference($2);}
                 | '+' unary_expression                          { $$ = $2; /* TODO: CHECK */}
                 | '-' unary_expression                          { $$ = new Unary_Negation($2); }
                 | '~' unary_expression                          { $$ = new Unary_InvertOp($2); }
                 | '!' unary_expression                          { $$ = new Unary_NotOp($2); }
                 ;

postfix_expression : primary_expression                                     { $$ = $1;}
                    | postfix_expression '[' expression ']'                 { $$ = new Postfix_ArrIndex($1, $3); }
                    | postfix_expression '(' ')'                            { $$ = new Postfix_FnCall($1); }
                    | postfix_expression '(' argument_expression_list ')'   { $$ = new Postfix_FnCall($1, $3); }
                    | postfix_expression '.' IDENTIFIER                     { $$ = new Postfix_DotIdentifier($1,*$3); }
                    | postfix_expression ARROW IDENTIFIER                   { $$ = new Postfix_ArrowIdentifier($1,*$3); }
                    | postfix_expression PLUSPLUS                           { $$ = new Postfix_IncOp($1); }
                    | postfix_expression MINUSMINUS                         { $$ = new Postfix_DecOp($1); }
                    ;

primary_expression : IDENTIFIER                 { $$ = new PrimaryExp_Identifier(*$1); }
                   | NUMBER                     { $$ = new PrimaryExp_Constant($1); }
                   | STRING_LITERAL      	    { $$ = new PrimaryExp_StrLiteral(*$1); }
                   | '(' expression ')'         { $$ = $2; }
                   | ENUM_VAL                   { $$ = new PrimaryExp_EnumVal(*$1); }
                   ;
%%

AST* g_root; // Definition of variable (to match declaration earlier)

AST* parseAST() {
    g_root = 0;
    yyparse();
    return g_root;
}
