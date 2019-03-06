#include "ast.hpp"
#include <vector>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    AST* ast;
    if (argc > 2)
        ast = parseAST(argv[2]);
    else
        ast = parseAST();

    PyContext context;

    std::ostream* os = &std::cout;
    std::ofstream tempStrm;
    if (argc > 4) {
        tempStrm.open(argv[4]);
        if (tempStrm.is_open())
            os = &tempStrm;
    }
    ast->printPy(*os, context);

    return 0;
}