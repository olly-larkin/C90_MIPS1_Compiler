/* A Bison parser, made by GNU Bison 3.2.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_SRC_COMPILER_BISON_TAB_HPP_INCLUDED
# define YY_YY_SRC_COMPILER_BISON_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/compiler_bison.y" /* yacc.c:1912  */

    #include "ast.hpp"

    #include <cassert>

    extern AST* g_root; // A way of getting the AST out

    //! This is to fix problems when generating C++
    // We are declaring the functions provided by Flex, so
    // that Bison generated code can call them.
    int yylex(void);
    void yyerror(const char *);

#line 61 "src/compiler_bison.tab.hpp" /* yacc.c:1912  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_STRING = 258,
    T_PLUSPLUS = 259,
    T_MINUSMINUS = 260,
    T_EQUAL_TO = 261,
    T_NOT_EQUAL_TO = 262,
    T_LESS_THAN_EQUAL = 263,
    T_MORE_THAN_EQUAL = 264,
    T_AND = 265,
    T_OR = 266,
    T_LEFT_SHIFT = 267,
    T_RIGHT_SHIFT = 268,
    T_PLUS_EQUAL = 269,
    T_MINUS_EQUAL = 270,
    T_TIMES_EQUAL = 271,
    T_DIVIDE_EQUAL = 272,
    T_MOD_EQUAL = 273,
    T_LEFT_SHIFT_EQUAL = 274,
    T_RIGHT_SHIFT_EQUAL = 275,
    T_B_AND_EQUAL = 276,
    T_XOR_EQUAL = 277,
    T_B_OR_EQUAL = 278,
    T_ARROW = 279,
    T_BREAK = 280,
    T_BOOL = 281,
    T_CASE = 282,
    T_CHAR = 283,
    T_CONST = 284,
    T_CONTINUE = 285,
    T_DEFAULT = 286,
    T_DO = 287,
    T_DOUBLE = 288,
    T_ELSE = 289,
    T_ENUM = 290,
    T_FLOAT = 291,
    T_FOR = 292,
    T_GOTO = 293,
    T_IF = 294,
    T_INT = 295,
    T_LONG = 296,
    T_REGISTER = 297,
    T_RETURN = 298,
    T_SHORT = 299,
    T_SIGNED = 300,
    T_SIZEOF = 301,
    T_STATIC = 302,
    T_STRUCT = 303,
    T_SWITCH = 304,
    T_TYPEDEF = 305,
    T_UNION = 306,
    T_UNSIGNED = 307,
    T_VOID = 308,
    T_WHILE = 309,
    T_NUMBER = 310,
    T_WORD = 311
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "src/compiler_bison.y" /* yacc.c:1912  */

    AST *ast;
    TopLevel* toplevel;
    double number;
    std::string* string;

#line 137 "src/compiler_bison.tab.hpp" /* yacc.c:1912  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_COMPILER_BISON_TAB_HPP_INCLUDED  */
