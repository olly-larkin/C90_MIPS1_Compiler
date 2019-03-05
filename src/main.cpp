#include "ast.hpp"
#include <vector>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    AST* ast = parseAST();

    PyContext context;

    std::ostream& os = std::cout;
    ast->print_py(os, context);

    return 0;
}