/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#line 1 "src/compiler_bison.y" /* yacc.c:1909  */

    #include "ast.hpp"

    #include <cassert>

    extern AST* g_root; // A way of getting the AST out

    //! This is to fix problems when generating C++
    // We are declaring the functions provided by Flex, so
    // that Bison generated code can call them.
    int yylex(void);
    void yyerror(const char *);

#line 58 "src/compiler_bison.tab.hpp" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRING_LITERAL = 258,
    PLUSPLUS = 259,
    MINUSMINUS = 260,
    EQUAL_TO = 261,
    NOT_EQUAL_TO = 262,
    LESS_THAN_EQUAL = 263,
    MORE_THAN_EQUAL = 264,
    AND = 265,
    OR = 266,
    LEFT_SHIFT = 267,
    RIGHT_SHIFT = 268,
    PLUS_EQUAL = 269,
    MINUS_EQUAL = 270,
    TIMES_EQUAL = 271,
    DIVIDE_EQUAL = 272,
    MOD_EQUAL = 273,
    LEFT_SHIFT_EQUAL = 274,
    RIGHT_SHIFT_EQUAL = 275,
    B_AND_EQUAL = 276,
    XOR_EQUAL = 277,
    B_OR_EQUAL = 278,
    ARROW = 279,
    AUTO = 280,
    BREAK = 281,
    CASE = 282,
    CHAR = 283,
    CONST = 284,
    CONTINUE = 285,
    DEFAULT = 286,
    DO = 287,
    DOUBLE = 288,
    ELSE = 289,
    ENUM = 290,
    ENUM_VAL = 291,
    FLOAT = 292,
    FOR = 293,
    GOTO = 294,
    IF = 295,
    INT = 296,
    LONG = 297,
    REGISTER = 298,
    RETURN = 299,
    SHORT = 300,
    SIGNED = 301,
    SIZEOF = 302,
    STATIC = 303,
    STRUCT = 304,
    SWITCH = 305,
    TYPEDEF = 306,
    UNION = 307,
    UNSIGNED = 308,
    VOID = 309,
    WHILE = 310,
    EXTERN = 311,
    VOLATILE = 312,
    NUMBER = 313,
    IDENTIFIER = 314,
    TYPEDEF_T = 315
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "src/compiler_bison.y" /* yacc.c:1909  */

    AST *ast;
    std::string *string;
    double number;
    Expression *ExpressionPtr;

#line 138 "src/compiler_bison.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_COMPILER_BISON_TAB_HPP_INCLUDED  */
