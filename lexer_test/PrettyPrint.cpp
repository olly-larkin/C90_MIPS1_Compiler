#include "Parse.hpp"

#include <map>

std::map<TokenType, std::string> tokenStrings = {
    {NONE, "NONE"},

    {T_TIMES, "T_TIMES: *"},
    {T_PLUS, "T_PLUS: +"},
    {T_DIVIDE, "T_DIVIDE: /"},
    {T_MINUS, "T_MINUS: -"},
    {T_MOD, "T_MOD: %"},
    {T_PLUS_PLUS, "T_PLUS_PLUS: ++"},
    {T_MINUS_MINUS, "T_MINUS_MINUS: --"},

    {T_EQUAL_TO, "T_EQUAL_TO: =="},    
    {T_LESS_THAN, "T_LESS_THAN: <"},
    {T_MORE_THAN, "T_MORE_THAN: >"}, 
    {T_NOT_EQUAL_TO, "T_NOT_EQUAL_TO: !="},
    {T_LESS_THAN_EQUAL, "T_LESS_THAN_EQUAL: <="},
    {T_MORE_THAN_EQUAL, "T_MORE_THAN_EQUAL"},

    {T_AND, "T_AND: &&"},
    {T_OR, "T_OR: ||"},
    {T_NOT, "T_NOT: !"},

    {T_B_AND, "T_B_AND: &"},
    {T_B_OR, "T_B_OR: |"},
    {T_XOR, "T_XOR: ^"},
    {T_B_NOT, "T_B_NOT: ~"},
    {T_LEFT_SHIFT, "T_LEFT_SHIFT: <<"},
    {T_RIGHT_SHIFT, "T_RIGHT_SHIFT: >>"},

    {T_EQUAL, "T_EQUAL: ="},
    {T_PLUS_EQUAL, "T_PLUS_EQUAL: +="},
    {T_MINUS_EQUAL, "T_MINUS_EQUAL: -="},
    {T_TIMES_EQUAL, "T_TIMES_EQUAL: *="},
    {T_DIVIDE_EQUAL, "T_DIVIDE_EQUAL: /="},
    {T_MOD_EQUAL, "T_MOD_EQUAL: %="},
    {T_LEFT_SHIFT_EQUAL, "T_LEFT_SHIFT_EQUAL: <<="},
    {T_RIGHT_SHIFT_EQUAL, "T_RIGHT_SHIFT_EQUAL: >>="},
    {T_B_AND_EQUAL, "T_B_AND_EQUAL: &="},
    {T_XOR_EQUAL, "T_XOR_EQUAL: ^="},
    {T_B_OR_EQUAL, "T_B_OR_EQUAL: |="},

    {T_Q_MARK, "T_Q_MARK: ?"},
    {T_COLON, "T_COLON: :"},
    {T_COMMA, "T_COMMA: ,"},
    {T_PERIOD, "T_PERIOD: ."},
    {T_ARROW, "T_ARROW: ->"},
    {T_SEMI_COLON, "T_SEMI_COLON: ;"},
    {T_QUOTE, "T_QUOTE: \""},

    {T_L_R_BRACKET, "T_L_R_BRACKET: ("},
    {T_R_R_BRACKET, "T_R_R_BRACKET: )"},
    {T_L_S_BRACKET, "T_L_S_BRACKET: ["},
    {T_R_S_BRACKET, "T_R_S_BRACKET: ]"},
    {T_L_C_BRACKET, "T_L_C_BRACKET: {"},
    {T_R_C_BRACKET, "T_R_C_BRACKET: }"},
    
    {T_AUTO, "T_AUTO: auto"},
    {T_BREAK, "T_BREAK: break"},
    {T_CASE, "T_CASE: case"},
    {T_CHAR, "T_CHAR: char"},
    {T_CONST, "T_CONST: const"},
    {T_CONTINUE, "T_CONTINUE: continue"},
    {T_DEFAULT, "T_DEFAULT: default"},
    {T_DO, "T_DO: do"},
    {T_DOUBLE, "T_DOUBLE: double"},
    {T_ELSE, "T_ELSE: else"},
    {T_ENUM, "T_ENUM: enum"},
    {T_FLOAT, "T_FLOAT: float"},
    {T_FOR, "T_FOR: for"},
    {T_GOTO, "T_GOTO: goto"},
    {T_IF, "T_IF: if"},
    {T_INT, "T_INT: int"},
    {T_LONG, "T_LONG: long"},
    {T_REGISTER, "T_REGISTER: register"},
    {T_RETURN, "T_RETURN: return"},
    {T_SHORT, "T_SHORT: short"},
    {T_SIGNED, "T_SIGNED: signed"},
    {T_SIZEOF, "T_SIZEOF: sizeof"},
    {T_STATIC, "T_STATIC: static"},
    {T_STRUCT, "T_STRUCT: struct"},
    {T_SWITCH, "T_SWITCH: switch"},
    {T_TYPEDEF, "T_TYPEDEF: typedef"},
    {T_UNION, "T_UNION: union"},
    {T_UNSIGNED, "T_UNSIGNED: unsigned"},
    {T_VOID, "T_VOID: void"},
    {T_WHILE, "T_WHILE: while"},

    {T_NUMBER, "T_NUMBER"},
    {T_WORD, "T_WORD"}
};

std::ostream& operator<<(std::ostream& out, TokenType token) {
    out << tokenStrings[token];
    return out;
}