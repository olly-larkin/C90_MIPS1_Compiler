%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "Parse.hpp"
%}

%%

("/*"[^"*/"]*"*/")|("//".*) {}
[ \t\n\r]       {}
"#".*           {}

"*"             { return T_TIMES; }
"+"             { return T_PLUS; }
"/"             { return T_DIVIDE; }
"-"             { return T_MINUS; }
"%"             { return T_MOD; }
"++"            { return T_PLUS_PLUS; }
"--"            { return T_MINUS_MINUS; }

"=="            { return T_EQUAL_TO; }
"<"             { return T_LESS_THAN; }
">"             { return T_MORE_THAN; }
"!="            { return T_NOT_EQUAL_TO; }
"<="            { return T_LESS_THAN_EQUAL; }
">="            { return T_MORE_THAN_EQUAL; }

"&&"            { return T_AND; }
"||"            { return T_OR; }
"!"             { return T_NOT; }

"&"             { return T_B_AND; }
"|"             { return T_B_OR; }
"\^"            { return T_XOR; } 
"~"             { return T_B_NOT; }
"<<"            { return T_LEFT_SHIFT; }
">>"            { return T_RIGHT_SHIFT; }

"="             { return T_EQUAL; }
"+="            { return T_PLUS_EQUAL; }
"-="            { return T_MINUS_EQUAL; }
"*="            { return T_TIMES_EQUAL; }
"/="            { return T_DIVIDE_EQUAL; }
"%="            { return T_MOD_EQUAL; }
"<<="           { return T_LEFT_SHIFT_EQUAL; }
">>="           { return T_RIGHT_SHIFT_EQUAL; }
"&="            { return T_B_AND_EQUAL; }
"\^="           { return T_XOR_EQUAL; }
"|="            { return T_B_OR_EQUAL; }

"?"             { return T_Q_MARK; }
":"             { return T_COLON; }
","             { return T_COMMA; }
"\."            { return T_PERIOD; }
"->"            { return T_ARROW; }
";"             { return T_SEMI_COLON; }
"\""            { return T_QUOTE; }

"("             { return T_L_R_BRACKET; }
")"             { return T_R_R_BRACKET; }
"\["            { return T_L_S_BRACKET; }
"\]"            { return T_R_S_BRACKET; }
"\{"            { return T_L_C_BRACKET; }
"\}"            { return T_R_C_BRACKET; }

"auto"          { return T_AUTO; }
"break"         { return T_BREAK; }
"case"          { return T_CASE; }
"char"          { return T_CHAR; }
"const"         { return T_CONST; }
"continue"      { return T_CONTINUE; }
"default"       { return T_DEFAULT; }
"do"            { return T_DO; }
"double"        { return T_DOUBLE; }
"else"          { return T_ELSE; }
"enum"          { return T_ENUM; }
"float"         { return T_FLAT; }
"for"           { return T_FOR; }
"goto"          { return T_GOTO; }
"if"            { return T_IF; }
"int"           { return T_INT; }
"long"          { return T_LONG; }
"register"      { return T_REGISTER; }
"return"        { return T_RETURN; }
"short"         { return T_SHORT; }
"signed"        { return T_SIGNED; }
"sizeof"        { return T_SIZEOF; }
"static"        { return T_STATIC; }
"struct"        { return T_STRUCT; }
"switch"        { return T_SWITCH; }
"typedef"       { return T_TYPEDEF; }
"union"         { return T_UNION; }
"unsigned"      { return T_UNSIGNED; }
"void"          { return T_VOID; }
"while"         { return T_WHILE; }
 
-?[0-9]+("\."[0-9]*)? { yylval.numberValue = strtod(yytext, 0); return T_NUMBER; }
[a-zA-Z_]+[0-9a-zA-Z_]* { yylval.wordValue = new std::string(yytext); return T_WORD; }

.               { fprintf(stderr, "Invalid character: %s\n", yytext); }

%%

void yyerror (char const *s)
{
    fprintf (stderr, "Parse error : %s\n", s);
    exit(1);
}