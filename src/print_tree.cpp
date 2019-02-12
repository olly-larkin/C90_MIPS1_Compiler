#include "ast.hpp"
#include <vector>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    AST* ast = parseAST();

    std::ostream& os = std::cout;
    os << ast->name() << std::endl;
    ast->print(os,1);

    return 0;
}