#ifndef AST_HPP
#define AST_HPP

#include <iostream>

#include "ast/ast_node.hpp"
#include "ast/ast_expression.hpp"
#include "ast/ast_declaration.hpp"
#include "ast/ast_statement.hpp"

extern AST* parseAST();

#endif