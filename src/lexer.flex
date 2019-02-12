%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "compiler_bison.tab.hpp"
%}

%%

("/*"[^"*/"]*"*/")|("//".*) {}
[ \t\n\r]       {}
"#".*           {}

\"([^\"]|"\\\"")*\" { 
                        std::string temp = std::string(yytext);
                        temp = temp.substr(1, temp.size()-2);
                        yylval.string = new std::string(temp);
                        return T_STRING;
                    }

"*"             { return '*'; }
"+"             { return '+'; }
"/"             { return '/'; }
"-"             { return '-'; }
"%"             { return '%'; }
"++"            { return T_PLUSPLUS; }
"--"            { return T_MINUSMINUS; }

"=="            { return T_EQUAL_TO; }
"<"             { return '<'; }
">"             { return '>'; }
"!="            { return T_NOT_EQUAL_TO; }
"<="            { return T_LESS_THAN_EQUAL; }
">="            { return T_MORE_THAN_EQUAL; }

"&&"            { return T_AND; }
"||"            { return T_OR; }
"!"             { return '!'; }

"&"             { return '&'; }
"|"             { return '|'; }
"\^"            { return '^'; } 
"~"             { return '~'; }
"<<"            { return T_LEFT_SHIFT; }
">>"            { return T_RIGHT_SHIFT; }

"="             { return '='; }
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

"?"             { return '?'; }
":"             { return ':'; }
","             { return ','; }
"\."            { return '.'; }
"->"            { return T_ARROW; }
";"             { return ';'; }
"\""            { return '\"'; }

"("             { return '('; }
")"             { return ')'; }
"\["            { return '['; }
"\]"            { return ']'; }
"\{"            { return '{'; }
"\}"            { return '}'; }

"break"         { return T_BREAK; }
"bool"          { yylval.string = new std::string("bool"); return T_WORD; }
"case"          { return T_CASE; }
"char"          { yylval.string = new std::string("char"); return T_WORD; }
"const"         { return T_CONST; }
"continue"      { return T_CONTINUE; }
"default"       { return T_DEFAULT; }
"do"            { return T_DO; }
"double"        { yylval.string = new std::string("double"); return T_WORD; }
"else"          { return T_ELSE; }
"enum"          { return T_ENUM; }
"float"         { yylval.string = new std::string("float"); return T_WORD; }
"for"           { return T_FOR; }
"goto"          { return T_GOTO; }
"if"            { return T_IF; }
"int"           { yylval.string = new std::string("int"); return T_WORD; }
"long"          { yylval.string = new std::string("long"); return T_WORD; }
"register"      { yylval.string = new std::string("register"); return T_WORD; }
"return"        { return T_RETURN; }
"short"         { yylval.string = new std::string("short"); return T_WORD; }
"signed"        { yylval.string = new std::string("signed"); return T_WORD; }
"sizeof"        { return T_SIZEOF; }
"static"        { return T_STATIC; }
"struct"        { return T_STRUCT; }
"switch"        { return T_SWITCH; }
"typedef"       { return T_TYPEDEF; }
"union"         { return T_UNION; }
"unsigned"      { yylval.string = new std::string("unsigned"); return T_WORD; }
"void"          { yylval.string = new std::string("void"); return T_WORD; }
"while"         { return T_WHILE; }
 
[0-9]+(\.[0-9]*)? { yylval.number = strtod(yytext, 0); return T_NUMBER; }
[a-zA-Z_][0-9a-zA-Z_]* { yylval.string = new std::string(yytext); return T_WORD; }

.               { fprintf(stderr, "Invalid character: %s\n", yytext); }

%%

void yyerror (char const *s)
{
    fprintf (stderr, "Parse error : %s\n", s);
    exit(1);
}