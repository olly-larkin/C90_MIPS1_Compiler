#ifndef PARSE_HPP

#include <string>

enum TokenType {

    NONE = 0,

    T_TIMES,
    T_PLUS,
    T_DIVIDE,
    T_MINUS,
    T_MOD,
    T_PLUS_PLUS,
    T_MINUS_MINUS,

    T_EQUAL_TO,    
    T_LESS_THAN,
    T_MORE_THAN, 
    T_NOT_EQUAL_TO,
    T_LESS_THAN_EQUAL,
    T_MORE_THAN_EQUAL,

    T_AND,
    T_OR,
    T_NOT,

    T_B_AND,
    T_B_OR,
    T_XOR,
    T_B_NOT,
    T_LEFT_SHIFT,
    T_RIGHT_SHIFT,

    T_EQUAL,
    T_PLUS_EQUAL,
    T_MINUS_EQUAL,
    T_TIMES_EQUAL,
    T_DIVIDE_EQUAL,
    T_MOD_EQUAL,
    T_LEFT_SHIFT_EQUAL,
    T_RIGHT_SHIFT_EQUAL,
    T_B_AND_EQUAL,
    T_XOR_EQUAL,
    T_B_OR_EQUAL,

    T_Q_MARK,
    T_COLON,
    T_COMMA,
    T_PERIOD,
    T_ARROW,
    T_SEMI_COLON,
    T_QUOTE,

    T_L_R_BRACKET,
    T_R_R_BRACKET,
    T_L_S_BRACKET,
    T_R_S_BRACKET,
    T_L_C_BRACKET,
    T_R_C_BRACKET,
    
    T_AUTO,
    T_BREAK,
    T_CASE,
    T_CHAR,
    T_CONST,
    T_CONTINUE,
    T_DEFAULT,
    T_DO,
    T_DOUBLE,
    T_ELSE,
    T_ENUM,
    T_FLOAT,
    T_FOR,
    T_GOTO,
    T_IF,
    T_INT,
    T_LONG,
    T_REGISTER,
    T_RETURN,
    T_SHORT,
    T_SIGNED,
    T_SIZEOF,
    T_STATIC,
    T_STRUCT,
    T_SWITCH,
    T_TYPEDEF,
    T_UNION,
    T_UNSIGNED,
    T_VOID,
    T_WHILE,

    T_NUMBER,
    T_WORD
};

union TokenValue{
    double numberValue;
    std::string *wordValue;
};

extern int yylex();
extern TokenValue yylval;

std::ostream& operator<<(std::ostream& out, TokenType token);

#endif