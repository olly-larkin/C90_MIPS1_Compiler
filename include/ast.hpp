#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <fstream>

#include "PyContext.hpp"
#include "ast/ast_root.hpp"
#include "ast/ast_base_classes.hpp"
#include "ast/ast_expressions.hpp"
#include "ast/ast_declarations.hpp"
#include "ast/ast_statements.hpp"

extern AST* parseAST();
extern AST* parseAST(char* in);

#endif