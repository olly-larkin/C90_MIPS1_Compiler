#include "ast.hpp"

int main()
{
    const AST* ast = parseAST();

    ast->print(std::cout);
    std::cout<<std::endl;

    return 0;
}