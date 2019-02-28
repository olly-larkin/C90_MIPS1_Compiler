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
    //ArgumentExpressionList *ArgumentExpressionListPtr;
    Statement *StatementPtr;
    Declaration *DeclarationPtr;
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
%type <Char> assignment_operator
%type <number> NUMBER
%type <ExpressionPtr> expression assignment_expression unary_expression cast_expression postfix_expression primary_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression conditional_expression constant_expression
%type <ExpressionPtr> argument_expression_list
//%type <ArgumentExpressionListPtr> argument_expression_list
%type <StatementPtr> statement labeled_statement compound_statement expression_statement selection_statement iteration_statement jump_statement statement_list
%type <DeclarationPtr> declaration

%nonassoc NOELSE
%nonassoc ELSE

%start ROOT

%%

ROOT : statement { g_root = $1; }

//TYPE_NAME : IDENTIFIER {$$ = $1;  /* TODO: Fill in later */}
//          ;


//**************************************************************************************
//----------------------------------------- TOP ----------------------------------------
//**************************************************************************************
translation_unit : external_declaration {}
                 | translation_unit external_declaration {}
                 ;

external_declaration : function_definition {}
                     | declaration {}
                     ;

function_definition : declaration_specifiers declarator declaration_list compound_statement {}
                    | declaration_specifiers declarator compound_statement {}
                    | declarator declaration_list compound_statement {}
                    | declarator compound_statement {}
                    ;

//**************************************************************************************
//------------------------------------- DECLARATIONS -----------------------------------
//**************************************************************************************
declaration : declaration_specifier ';' {}
            | declaration_specifier init_declarator_list ';' {}
            ;

declaration_specifier : storage_class_specifier declaration_specifier {}
                    |   storage_class_specifier {}
                    |   type_specifier declaration_specifier {}
                    |   type_specifier {}
                    |   type_qualifier declaration_specifier {}
                    |   type_qualifier {}
                    ;

init_declarator_list : init_declarator {}
                    |  init_declarator_list ',' init_declarator  {}
                    ;

init_declarator : declarator {}
                | declarator '=' initializer  {}
                ;

storage_class_specifier : TYPEDEF {}
                        | EXTERN {}
                        | STATIC {}
                        | AUTO {}
                        | REGISTER {}
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
                | struct_union_spec {}
                | enum_specifier {}
                | TYPEDEF_T {}
                ;

struct_union_spec : struct_or_union IDENTIFIER '{' struct_declaration_list '}' {}
                  | struct_or_union '{' struct_declaration_list '}' {}
                  | struct_or_union IDENTIFIER {}
                  ;

struct_or_union : STRUCT {}
                | UNION {}
                ;

struct_declaration_list : struct_declaration {}
                        | struct_declaration_list struct_declaration {}

struct_declaration : specifier_qualifier_list struct_declarator_list ';'
	               ;

specifier_qualifier_list : type_specifier specifier_qualifier_list {}
                         | type_specifier {}
                         | type_qualifier specifier_qualifier_list {}
                         | type_qualifier {}
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
          | ENUM IDENTIFIER
          ;

enum_list : enumerator
          | enum_list ',' enumerator {}
          ;

enumerator : IDENTIFIER {}
           | IDENTIFIER '=' constant_expression {}
           ;

type_qualifier : CONST {}
                | VOLATILE {}

declarator : pointer direct_declarator {}
           | direct_declarator {}
           ;

direct_declarator : IDENTIFIER {}
                  | '(' declarator ')' {}
                  | direct_declarator '[' constant_expression ']' {}
                  | direct_declarator '[' ']' {}
                  | direct_declarator '(' parameter_type_list ')' {}
                  | direct_declarator '(' ')' {}
                  ;

pointer : '*' {}
        | '*' pointer {}
	    | '*' type_qualifier_list {}
	    | '*' type_qualifier_list pointer {}
	    ;

type_qualifier_list : type_qualifier
                    | type_qualifier_list type_qualifier {}
                    ;

parameter_type_list : parameter_list {} //TODO: CHECK THAT WE DONT NEED ELLIPSIS
                    ;

parameter_list : parameter_declaration {}
               | parameter_list ',' parameter_declaration {}
               ;

parameter_declaration : declaration_specifier declarator {}
                      | declaration_specifier abstract_declarator {}
                      | declaration_specifier {}
                      ;

//TODO: abstract declarators=====================================
type_name : specifier_qualifier_list {}
	        | specifier_qualifier_list abstract_declarator
	        ;

abstract_declarator : pointer
                    | direct_abstract_declarator
                    | pointer direct_abstract_declarator
                    ;

direct_abstract_declarator : '(' abstract_declarator ')'
                           | '[' ']'
                           | '[' constant_expression ']'
                           | direct_abstract_declarator '[' ']'
                           | direct_abstract_declarator '[' constant_expression ']'
                           | '(' ')'
                           | '(' parameter_type_list ')'
                           | direct_abstract_declarator '(' ')'
                           | direct_abstract_declarator '(' parameter_type_list ')'
                           ;
//==============================================================

initializer : assignment_expression {}
            | '{' initializer_list '}'
            | '{' initializer_list ',' '}'
            ;

initializer_list : initializer {}
                 | initializer_list ',' initializer {}
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

compound_statement : '{' '}'                                        { $$ = new ExpressionStatement(); }
                   | '{' declaration_list '}'
                   | '{' statement_list '}'                         { $$ = $2; }
                   | '{' declaration_list statement_list '}'
                   ;

declaration_list : declaration
                 | declaration_list declaration
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

//**************************************************************************************
//------------------------------------- EXPRESSIONS ------------------------------------
//**************************************************************************************

constant_expression : expression   { $$ = $1; }
                    ;

expression : assignment_expression { $$ = $1; }
           ;

//argument_expression_list : assignment_expression                                { $$ = new ArgumentExpressionList($1); }
//                         | argument_expression_list ',' assignment_expression   { $$ = $1; $$->addArg($3); }
//                         ;

argument_expression_list : assignment_expression                                { $$ = new ArgumentExpressionList($1); }
                         | argument_expression_list ',' assignment_expression   { $$ = new ArgumentExpressionList(reinterpret_cast<ArgumentExpressionList*>($1), $3); }
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

multiplicative_expression : cast_expression                               { $$ = $1; }
                          | multiplicative_expression '*' cast_expression { $$ = new MultiplyOp($1, $3); }
                          | multiplicative_expression '/' cast_expression { $$ = new DivideOp($1, $3); }
                          | multiplicative_expression '%' cast_expression { $$ = new ModOp($1, $3); }
                          ;

cast_expression : unary_expression                              { $$ = $1; }
//                | '(' TYPE_NAME ')' cast_expression             { $$ = new Cast_ToType($4, *$2); }
                ;

unary_expression : postfix_expression                           { $$ = $1;}
                 | PLUSPLUS unary_expression                    { $$ = new Unary_PrefixInc($2); }
                 | MINUSMINUS unary_expression                  { $$ = new Unary_PrefixDec($2); }
                 | SIZEOF unary_expression                      { $$ = new Unary_SizeOfExpr($2); }
//                 | SIZEOF '(' TYPE_NAME ')'                     { /* TODO: return after creating type_name */ }
                 | '&' cast_expression                          { $$ = new Unary_Reference($2); }
                 | '*' cast_expression                          { $$ = new Unary_Dereference($2);}
                 | '+' cast_expression                          { $$ = $2; /* TODO: CHECK */}
                 | '-' cast_expression                          { $$ = new Unary_Negation($2); }
                 | '~' cast_expression                          { $$ = new Unary_InvertOp($2); }
                 | '!' cast_expression                          { $$ = new Unary_NotOp($2); }
                 ;

postfix_expression : primary_expression                                     { $$ = $1;}
                    | postfix_expression '[' expression ']'                 { $$ = new Postfix_ArrIndex($1, $3); }
                    | postfix_expression '(' ')'                            { $$ = new Postfix_FnCall($1); }
                    | postfix_expression '(' argument_expression_list ')'   { $$ = new Postfix_FnCall($1, reinterpret_cast<ArgumentExpressionList*>($3)); }
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
