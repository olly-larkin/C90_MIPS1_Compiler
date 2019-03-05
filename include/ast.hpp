#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <fstream>

#include "PyContext.hpp"
#include "ast/ast_node.hpp"
#include "ast/ast_expression.hpp"
#include "ast/ast_declaration.hpp"
#include "ast/ast_type_name.hpp"
#include "ast/ast_statement.hpp"
#include "ast/ast_top.hpp"

extern AST* parseAST();
extern AST* parseAST(char* in);

#endif