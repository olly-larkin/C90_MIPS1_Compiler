#include "ast.hpp"
#include <vector>
#include <iostream>

int main()
{
    AST* ast = parseAST();

    std::vector<AST*> astVec;
    astVec.push_back(ast);

    std::ostream& os = std::cout;

    for(int i = 0; i < (int)astVec.size(); ++i) {
        os << astVec[i]->name() << std::endl;
    }
    astVec.back()->print(os,1);

    return 0;
}