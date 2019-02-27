/* A Bison parser, made by GNU Bison 3.2.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.2.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "compiler_bison.tab.hpp".  */
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
#line 1 "src/compiler_bison.y" /* yacc.c:353  */

    #include "ast.hpp"

    #include <cassert>

    extern AST* g_root; // A way of getting the AST out

    //! This is to fix problems when generating C++
    // We are declaring the functions provided by Flex, so
    // that Bison generated code can call them.
    int yylex(void);
    void yyerror(const char *);

#line 115 "src/compiler_bison.tab.cpp" /* yacc.c:353  */

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
#line 15 "src/compiler_bison.y" /* yacc.c:353  */

    AST *ast;
    std::string *string;
    double number;
    Expression *ExpressionPtr;
    ArgumentExpressionList *ArgumentExpressionListPtr;
    char Char;

#line 197 "src/compiler_bison.tab.cpp" /* yacc.c:353  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_COMPILER_BISON_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,     2,     2,     2,    74,    67,     2,
      75,    76,    72,    70,    61,    71,    81,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,     2,
      68,    62,    69,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    79,     2,    80,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    65,     2,    77,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    48,    48,    50,    55,    58,    61,    62,    65,    66,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    82,    83,    86,    87,    90,    91,    94,    95,    98,
      99,   102,   103,   106,   107,   108,   111,   112,   113,   114,
     115,   118,   119,   120,   123,   124,   125,   128,   129,   130,
     131,   134,   135,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   151,   152,   153,   154,   155,   156,
     157,   158,   161,   162,   163,   164,   165
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING_LITERAL", "PLUSPLUS",
  "MINUSMINUS", "EQUAL_TO", "NOT_EQUAL_TO", "LESS_THAN_EQUAL",
  "MORE_THAN_EQUAL", "AND", "OR", "LEFT_SHIFT", "RIGHT_SHIFT",
  "PLUS_EQUAL", "MINUS_EQUAL", "TIMES_EQUAL", "DIVIDE_EQUAL", "MOD_EQUAL",
  "LEFT_SHIFT_EQUAL", "RIGHT_SHIFT_EQUAL", "B_AND_EQUAL", "XOR_EQUAL",
  "B_OR_EQUAL", "ARROW", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "ENUM_VAL",
  "FLOAT", "FOR", "GOTO", "IF", "INT", "LONG", "REGISTER", "RETURN",
  "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDEF",
  "UNION", "UNSIGNED", "VOID", "WHILE", "EXTERN", "VOLATILE", "NUMBER",
  "IDENTIFIER", "TYPEDEF_T", "','", "'='", "'?'", "':'", "'|'", "'^'",
  "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'",
  "'~'", "'!'", "'['", "']'", "'.'", "$accept", "ROOT", "TYPE_NAME",
  "CONSTANT_EXPRESSION", "EXPRESSION", "ARGUMENT_EXPRESSION_LIST",
  "ASSIGNMENT_EXPRESSION", "ASSIGNMENT_OPERATOR", "CONDITIONAL_EXPRESSION",
  "LOGICAL_OR_EXPRESSION", "LOGICAL_AND_EXPRESSION",
  "INCLUSIVE_OR_EXPRESSION", "EXCLUSIVE_OR_EXPRESSION", "AND_EXPRESSION",
  "EQUALITY_EXPRESSION", "RELATIONAL_EXPRESSION", "SHIFT_EXPRESSION",
  "ADDITIVE_EXPRESSION", "MULTIPLICATIVE_EXPRESSION", "CAST_EXPRESSION",
  "UNARY_EXPRESSION", "POSTFIX_EXPRESSION", "PRIMARY_EXPRESSION", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    44,    61,    63,    58,   124,    94,    38,    60,    62,
      43,    45,    42,    47,    37,    40,    41,   126,    33,    91,
      93,    46
};
# endif

#define YYPACT_NINF -64

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-64)))

#define YYTABLE_NINF -4

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      58,   -64,    96,    96,   -64,   117,   -64,   -64,    58,    58,
      58,    58,   143,    58,    58,     4,   -64,   -64,   -64,   -64,
      -3,    12,   -32,   -36,   -19,    14,    34,    16,   -35,   -63,
     -64,   208,     2,   -64,    58,   -64,   -64,   143,   -64,   -64,
     -64,   -64,   -64,   -64,   -23,   -22,   -21,   -64,   -64,   -64,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
      58,   -64,   -64,    -2,    20,    58,    -1,   -17,    58,   -64,
      12,     6,   -32,   -36,   -19,    14,    34,    34,    16,    16,
      16,    16,   -35,   -35,   -63,   -63,   -64,   -64,   -64,   -64,
     -64,   -64,   -44,   -64,   -11,   -64,   -64,   -64,    58,    58,
     -64,   -64,   -64,   -64
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    74,     0,     0,    76,     0,    73,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     4,     5,     8,
      21,    23,    25,    27,    29,    31,    33,    36,    41,    44,
      47,    51,    53,    64,     0,    54,    55,     0,    56,    58,
      51,    60,    61,    59,    72,     0,     0,    62,    63,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    10,
       0,    70,    71,     0,     0,     0,     0,     0,     0,    75,
      24,     0,    26,    28,    30,    32,    34,    35,    39,    40,
      37,    38,    42,    43,    45,    46,    48,    49,    50,     9,
      69,    66,     0,     6,     0,    68,    57,    52,     0,     0,
      67,    65,    22,     7
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,   -64,    27,   -64,     1,   -64,   -53,   -64,   -50,   -64,
      15,    22,    23,    21,    33,   -12,   -20,   -16,   -15,     5,
       0,   -64,   -64
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    15,    45,    16,    46,   112,    18,    80,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      40,    32,    33
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      31,    17,    35,    36,    49,    38,    81,    82,    50,    66,
      67,    68,    31,    39,    41,    42,    43,   119,    47,    48,
      56,    57,    52,     1,     2,     3,    83,   109,    62,    63,
      54,   113,   120,    53,    31,    64,    65,    31,    98,    99,
     100,   101,    58,    59,    96,    97,   102,   103,    55,   104,
     105,    31,    91,    -3,    88,    89,     4,   110,   115,   116,
      51,     1,     2,     3,    87,    90,   123,     5,   122,   121,
     118,   106,   107,   108,    92,    94,    93,    84,     6,     7,
      31,    85,     0,    86,    31,    31,   114,     8,    95,     0,
       9,    10,    11,   117,     4,    12,   111,    13,    14,     1,
       2,     3,    60,    61,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     0,    31,
       1,     2,     3,     0,     0,     8,     0,     0,     9,    10,
      11,     0,     4,    12,     0,    13,    14,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     1,     2,     3,     0,
       0,     0,     0,     4,     6,     7,     0,     0,     0,     0,
       0,     0,     0,     8,     5,     0,     9,    10,    11,     0,
       0,    34,     0,    13,    14,     6,     7,     0,     0,     4,
       0,     0,     0,     0,     8,     0,     0,     9,    10,    11,
       5,     0,    37,     0,    13,    14,     0,     0,     0,     0,
       0,     6,    44,     0,     0,     0,     0,     0,     0,     0,
       8,     0,     0,     9,    10,    11,     0,     0,    12,     0,
      13,    14,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79
};

static const yytype_int8 yycheck[] =
{
       0,     0,     2,     3,     0,     5,     4,     5,    11,    72,
      73,    74,    12,     8,     9,    10,    11,    61,    13,    14,
       6,     7,    10,     3,     4,     5,    24,    80,    12,    13,
      66,    84,    76,    65,    34,    70,    71,    37,    58,    59,
      60,    61,     8,     9,    56,    57,    62,    63,    67,    64,
      65,    51,    51,    76,    76,    76,    36,    59,    59,    76,
      63,     3,     4,     5,    37,    50,   119,    47,   118,    80,
      64,    66,    67,    68,    52,    54,    53,    75,    58,    59,
      80,    79,    -1,    81,    84,    85,    85,    67,    55,    -1,
      70,    71,    72,    88,    36,    75,    76,    77,    78,     3,
       4,     5,    68,    69,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    -1,   119,
       3,     4,     5,    -1,    -1,    67,    -1,    -1,    70,    71,
      72,    -1,    36,    75,    -1,    77,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    36,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    47,    -1,    70,    71,    72,    -1,
      -1,    75,    -1,    77,    78,    58,    59,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    71,    72,
      47,    -1,    75,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    70,    71,    72,    -1,    -1,    75,    -1,
      77,    78,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    36,    47,    58,    59,    67,    70,
      71,    72,    75,    77,    78,    83,    85,    86,    88,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    75,   102,   102,    75,   102,   101,
     102,   101,   101,   101,    59,    84,    86,   101,   101,     0,
      11,    63,    10,    65,    66,    67,     6,     7,     8,     9,
      68,    69,    12,    13,    70,    71,    72,    73,    74,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    62,
      89,     4,     5,    24,    75,    79,    81,    84,    76,    76,
      92,    86,    93,    94,    95,    96,    97,    97,    98,    98,
      98,    98,    99,    99,   100,   100,   101,   101,   101,    88,
      59,    76,    87,    88,    86,    59,    76,   101,    64,    61,
      76,    80,    90,    88
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    85,    86,    87,    87,    88,    88,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    90,    90,    91,    91,    92,    92,    93,    93,    94,
      94,    95,    95,    96,    96,    96,    97,    97,    97,    97,
      97,    98,    98,    98,    99,    99,    99,   100,   100,   100,
     100,   101,   101,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   103,   104,   104,   104,   104,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     4,     1,     2,     2,     2,     4,     2,     2,
       2,     2,     2,     2,     1,     4,     3,     4,     3,     3,
       2,     2,     1,     1,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 48 "src/compiler_bison.y" /* yacc.c:1660  */
    { g_root = (yyvsp[0].ExpressionPtr); }
#line 1415 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 3:
#line 50 "src/compiler_bison.y" /* yacc.c:1660  */
    {(yyval.string) = (yyvsp[0].string);  /* TODO: Fill in later */}
#line 1421 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 4:
#line 55 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[0].ExpressionPtr); }
#line 1427 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 5:
#line 58 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[0].ExpressionPtr); }
#line 1433 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 6:
#line 61 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ArgumentExpressionListPtr) = new ArgumentExpressionList((yyvsp[0].ExpressionPtr)); }
#line 1439 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 7:
#line 62 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ArgumentExpressionListPtr) = (yyvsp[-2].ArgumentExpressionListPtr); (yyval.ArgumentExpressionListPtr)->addArg((yyvsp[0].ExpressionPtr)); }
#line 1445 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 8:
#line 65 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[0].ExpressionPtr); }
#line 1451 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 9:
#line 66 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new Assignment((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr), (yyvsp[-1].Char)); }
#line 1457 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 10:
#line 69 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.Char) = '='; }
#line 1463 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 11:
#line 70 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.Char) = '+'; }
#line 1469 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 12:
#line 71 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.Char) = '-'; }
#line 1475 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 13:
#line 72 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.Char) = '*'; }
#line 1481 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 14:
#line 73 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.Char) = '/'; }
#line 1487 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 15:
#line 74 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.Char) = '%'; }
#line 1493 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 16:
#line 75 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.Char) = '<'; }
#line 1499 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 17:
#line 76 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.Char) = '>'; }
#line 1505 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 18:
#line 77 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.Char) = '&'; }
#line 1511 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 19:
#line 78 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.Char) = '^'; }
#line 1517 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 20:
#line 79 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.Char) = '|'; }
#line 1523 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 21:
#line 82 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[0].ExpressionPtr); }
#line 1529 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 22:
#line 83 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new ConditionalOp((yyvsp[-4].ExpressionPtr), (yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1535 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 23:
#line 86 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[0].ExpressionPtr); }
#line 1541 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 24:
#line 87 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new LogicalOROp((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1547 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 25:
#line 90 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[0].ExpressionPtr); }
#line 1553 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 26:
#line 91 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new LogicalANDOp((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1559 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 27:
#line 94 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[0].ExpressionPtr); }
#line 1565 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 28:
#line 95 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new BitwiseInclusiveOROp((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1571 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 29:
#line 98 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[0].ExpressionPtr); }
#line 1577 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 30:
#line 99 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new BitwiseExclusiveOROp((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1583 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 31:
#line 102 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[0].ExpressionPtr); }
#line 1589 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 32:
#line 103 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new BitwiseANDOp((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1595 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 33:
#line 106 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[0].ExpressionPtr); }
#line 1601 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 34:
#line 107 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new EqualToOp((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1607 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 35:
#line 108 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new NotEqualToOp((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1613 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 36:
#line 111 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[0].ExpressionPtr); }
#line 1619 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 37:
#line 112 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new LessThanOp((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1625 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 38:
#line 113 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new MoreThanOp((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1631 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 39:
#line 114 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new LessThanEqualOp((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1637 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 40:
#line 115 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new MoreThanEqualOp((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1643 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 41:
#line 118 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[0].ExpressionPtr); }
#line 1649 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 42:
#line 119 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new LeftShiftOp((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1655 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 43:
#line 120 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new RightShiftOp((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1661 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 44:
#line 123 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[0].ExpressionPtr); }
#line 1667 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 45:
#line 124 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new AddOp((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1673 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 46:
#line 125 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new SubOp((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1679 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 47:
#line 128 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[0].ExpressionPtr); }
#line 1685 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 48:
#line 129 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new MultiplyOp((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1691 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 49:
#line 130 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new DivideOp((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1697 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 50:
#line 131 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new ModOp((yyvsp[-2].ExpressionPtr), (yyvsp[0].ExpressionPtr)); }
#line 1703 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 51:
#line 134 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[0].ExpressionPtr); }
#line 1709 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 52:
#line 135 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new Cast_ToType((yyvsp[0].ExpressionPtr), *(yyvsp[-2].string)); }
#line 1715 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 53:
#line 138 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[0].ExpressionPtr);}
#line 1721 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 54:
#line 139 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new Unary_PrefixInc((yyvsp[0].ExpressionPtr)); }
#line 1727 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 55:
#line 140 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new Unary_PrefixDec((yyvsp[0].ExpressionPtr)); }
#line 1733 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 56:
#line 141 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new Unary_SizeOfExpr((yyvsp[0].ExpressionPtr)); }
#line 1739 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 57:
#line 142 "src/compiler_bison.y" /* yacc.c:1660  */
    { /* TODO: return after creating type_name */ }
#line 1745 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 58:
#line 143 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new Unary_Reference((yyvsp[0].ExpressionPtr)); }
#line 1751 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 59:
#line 144 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new Unary_Dereference((yyvsp[0].ExpressionPtr));}
#line 1757 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 60:
#line 145 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[0].ExpressionPtr); /* TODO: CHECK */}
#line 1763 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 61:
#line 146 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new Unary_Negation((yyvsp[0].ExpressionPtr)); }
#line 1769 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 62:
#line 147 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new Unary_InvertOp((yyvsp[0].ExpressionPtr)); }
#line 1775 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 63:
#line 148 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new Unary_NotOp((yyvsp[0].ExpressionPtr)); }
#line 1781 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 64:
#line 151 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[0].ExpressionPtr);}
#line 1787 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 65:
#line 152 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new Postfix_ArrIndex((yyvsp[-3].ExpressionPtr), (yyvsp[-1].ExpressionPtr)); }
#line 1793 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 66:
#line 153 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new Postfix_FnCall((yyvsp[-2].ExpressionPtr)); }
#line 1799 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 67:
#line 154 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new Postfix_FnCall((yyvsp[-3].ExpressionPtr), (yyvsp[-1].ArgumentExpressionListPtr)); }
#line 1805 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 68:
#line 155 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new Postfix_DotIdentifier((yyvsp[-2].ExpressionPtr),*(yyvsp[0].string)); }
#line 1811 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 69:
#line 156 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new Postfix_ArrowIdentifier((yyvsp[-2].ExpressionPtr),*(yyvsp[0].string)); }
#line 1817 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 70:
#line 157 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new Postfix_IncOp((yyvsp[-1].ExpressionPtr)); }
#line 1823 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 71:
#line 158 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new Postfix_DecOp((yyvsp[-1].ExpressionPtr)); }
#line 1829 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 72:
#line 161 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new PrimaryExp_Identifier(*(yyvsp[0].string)); }
#line 1835 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 73:
#line 162 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new PrimaryExp_Constant((yyvsp[0].number)); }
#line 1841 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 74:
#line 163 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new PrimaryExp_StrLiteral(*(yyvsp[0].string)); }
#line 1847 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 75:
#line 164 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = (yyvsp[-1].ExpressionPtr); }
#line 1853 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 76:
#line 165 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.ExpressionPtr) = new PrimaryExp_EnumVal(*(yyvsp[0].string)); }
#line 1859 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;


#line 1863 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 167 "src/compiler_bison.y" /* yacc.c:1903  */


AST* g_root; // Definition of variable (to match declaration earlier)

AST* parseAST() {
    g_root = 0;
    yyparse();
    return g_root;
}
