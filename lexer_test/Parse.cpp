#include "lexer.hpp"

#include <iostream>

TokenValue yylval;

int main(int argc, char* argv[]) {
    while(1) {
        TokenType token = (TokenType)yylex();
        if (token == NONE)
            break;
        std::cout << token;
        if (token == T_NUMBER)
            std::cout << ": " << yylval.numberValue;
        else if (token == T_WORD) {
            std::cout << ": " << *yylval.wordValue;
            delete yylval.wordValue;
        }
        std::cout << std::endl;
    }
}