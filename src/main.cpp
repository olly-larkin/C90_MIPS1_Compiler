#include <vector>
#include <iostream>
#include <fstream>

#include "ast.hpp"

void translate(AST *tree, std::ostream &os) {
    PyContext context;
    tree->printPy(os, context);
}

void compile(AST *tree, std::ostream &os) {
    CompContext context;
    std::vector<Instruction> instructions;
    tree->generateMIPS(os, context, instructions);
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "Not enough arguments passed." << std::endl;
        exit(10);
    }

    AST* ast;
    if (argc < 3) {
        std::cerr << "No input file specified. Using stdin." << std::endl;
        ast = parseAST();
    } else {
        ast = parseAST(argv[2]);
    }

    std::ostream* os = &std::cout;
    std::ofstream tempStrm;
    if (argc > 4) {
        tempStrm.open(argv[4]);
        if (tempStrm.is_open())
            os = &tempStrm;
        else
            std::cerr << "Cannot open output file... Printing to stdout." << std::endl;
    }

    if (std::string(argv[1]) == "-S")
        compile(ast, *os);
    else if (std::string(argv[1]) == "--translate")
        translate(ast, *os);

    tempStrm.close();

    return 0;
}