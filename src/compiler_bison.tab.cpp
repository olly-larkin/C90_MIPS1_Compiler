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
# define YYERROR_VERBOSE 1
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
    #include <fstream>

    extern FILE *yyin;
    extern AST* g_root; // A way of getting the AST out

    //! This is to fix problems when generating C++
    // We are declaring the functions provided by Flex, so
    // that Bison generated code can call them.
    int yylex(void);
    void yyerror(const char *);

#line 117 "src/compiler_bison.tab.cpp" /* yacc.c:353  */

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
    FLOAT = 291,
    FOR = 292,
    GOTO = 293,
    IF = 294,
    INT = 295,
    LONG = 296,
    REGISTER = 297,
    RETURN = 298,
    SHORT = 299,
    SIGNED = 300,
    SIZEOF = 301,
    STATIC = 302,
    STRUCT = 303,
    SWITCH = 304,
    TYPEDEF = 305,
    UNION = 306,
    UNSIGNED = 307,
    VOID = 308,
    WHILE = 309,
    EXTERN = 310,
    VOLATILE = 311,
    NUMBER = 312,
    IDENTIFIER = 313,
    TYPEDEF_T = 314,
    NOELSE = 315
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "src/compiler_bison.y" /* yacc.c:353  */

    std::string *string;
    double number;

    BaseNode *BaseNodePtr;
    BaseExpression *BaseExpressionPtr;
    BaseList *BaseListPtr;
    BaseExpressionList *BaseExpressionListPtr;

#line 200 "src/compiler_bison.tab.cpp" /* yacc.c:353  */
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
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1372

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  187
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  343

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
       2,     2,     2,    83,     2,     2,     2,    81,    75,     2,
      67,    68,    71,    78,    62,    79,    84,    80,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,    61,
      76,    63,    77,    72,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    69,     2,    70,    74,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,    73,    65,    82,     2,     2,     2,
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
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    61,    64,    65,    68,    69,    72,    73,
      80,    81,    84,    85,    86,    87,    90,    91,    94,    95,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   112,   113,   116,   117,   118,   121,   122,   124,
     127,   128,   131,   132,   133,   136,   137,   138,   141,   142,
     145,   146,   149,   150,   153,   154,   155,   156,   157,   158,
     161,   162,   165,   166,   169,   170,   171,   174,   175,   178,
     179,   180,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   194,   195,   196,   199,   200,   207,   208,   209,   210,
     211,   212,   215,   216,   219,   220,   221,   222,   225,   226,
     229,   230,   233,   234,   237,   238,   239,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   254,   255,   256,
     257,   264,   265,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   282,   283,   286,   287,   290,
     291,   294,   295,   298,   299,   302,   303,   306,   307,   308,
     311,   312,   313,   314,   315,   318,   319,   320,   323,   324,
     325,   328,   329,   330,   331,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   347,   348,   349,   350,
     351,   352,   353,   354,   357,   358,   359,   360
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
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
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "FLOAT", "FOR",
  "GOTO", "IF", "INT", "LONG", "REGISTER", "RETURN", "SHORT", "SIGNED",
  "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDEF", "UNION", "UNSIGNED",
  "VOID", "WHILE", "EXTERN", "VOLATILE", "NUMBER", "IDENTIFIER",
  "TYPEDEF_T", "NOELSE", "';'", "','", "'='", "'{'", "'}'", "':'", "'('",
  "')'", "'['", "']'", "'*'", "'?'", "'|'", "'^'", "'&'", "'<'", "'>'",
  "'+'", "'-'", "'/'", "'%'", "'~'", "'!'", "'.'", "$accept", "ROOT",
  "top_container", "translation_unit", "external_declaration",
  "function_definition", "declaration", "declaration_specifier",
  "init_declarator_list", "init_declarator", "type_specifier",
  "specifier_list", "struct_spec", "struct_declaration_list",
  "struct_declaration", "struct_declarator_list", "struct_declarator",
  "enum_specifier", "enum_list", "enumerator", "declarator",
  "direct_declarator", "pointer", "parameter_list",
  "parameter_declaration", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "statement", "labeled_statement", "compound_statement",
  "declaration_list", "statement_list", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "argument_expression_list", "expression", "conditional_expression",
  "logical_or_expression", "logical_and_expression",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "primary_expression", YY_NULLPTR
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
     315,    59,    44,    61,   123,   125,    58,    40,    41,    91,
      93,    42,    63,   124,    94,    38,    60,    62,    43,    45,
      47,    37,   126,    33,    46
};
# endif

#define YYPACT_NINF -198

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-198)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1178,  -198,  -198,   -40,  -198,  -198,  -198,  -198,  -198,   -39,
    1292,  -198,  -198,  -198,  -198,    -6,   -29,    29,  -198,  1178,
    -198,  -198,  -198,   -23,  1292,  -198,  -198,   -14,    -1,    -3,
      22,   -35,    30,  1313,  -198,     7,  -198,  -198,  -198,  -198,
      74,  -198,   -42,  -198,   273,  -198,  1206,   655,    -1,   -35,
      33,    23,  -198,  1313,  1313,    -9,  1248,  -198,  -198,  -198,
      -6,   682,  -198,  -198,  1025,  1025,    44,  1025,    61,    63,
     533,    -7,    93,   712,  1052,    98,   101,  -198,  -198,  -198,
    -198,  1025,  1025,  1025,  1025,  1025,  1025,  1025,  -198,   -23,
    -198,  -198,  -198,   338,   403,  -198,  -198,  -198,  -198,   108,
    -198,    -2,   165,   104,   105,   107,   143,     4,   144,    80,
      11,   270,   157,  -198,  -198,   -28,   -51,  -198,  -198,   110,
      68,  1025,   -35,  -198,  1270,  -198,  1025,   102,  -198,   117,
    -198,  -198,  -198,   121,   682,  -198,  -198,  -198,  -198,  -198,
     119,  -198,   533,   133,   739,  1025,  -198,   127,   598,  -198,
    1025,  1025,   123,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,   468,  -198,  -198,  -198,  1025,  1025,  1025,  1025,  1025,
    1025,  1025,  1025,  1025,  1025,  1025,  1025,  1025,  1025,  1025,
    1025,  1025,  1025,  1025,  1025,  1025,  1025,  1025,  1025,  1025,
    1025,  1025,  1025,  1025,  1025,  -198,  -198,   131,   773,  1025,
     151,  1104,   800,  -198,   -22,  -198,    46,  1292,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,    -9,  1025,  -198,    69,
     533,  -198,   146,   823,   149,   147,  -198,    47,   148,   152,
     153,  -198,  -198,   165,  -198,   145,   104,   105,   107,   143,
       4,     4,   144,   144,   144,   144,    80,    80,    11,    11,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,     1,  -198,   155,  -198,
    -198,     5,   161,  -198,   166,    46,  1227,   857,  -198,  -198,
    -198,   625,  -198,  -198,  1025,   884,   156,   907,   533,  1141,
      54,  -198,  -198,   533,   533,  1025,  1025,  -198,  -198,  -198,
    -198,  -198,  -198,    16,  -198,   169,  -198,  -198,   163,   533,
     167,   941,   968,   158,   180,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,   533,   533,   174,   533,   176,   991,   533,
    -198,  -198,   533,  -198,   533,   533,   177,  -198,  -198,  -198,
    -198,   533,  -198
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    21,    26,     0,    25,    23,    24,    22,    27,     0,
      13,    28,    20,    54,    31,     0,    60,     0,     2,     3,
       4,     6,     7,     0,    15,    29,    30,     0,    53,     0,
      47,     0,    36,     0,    12,     0,    61,     1,     5,    10,
       0,    16,    18,    14,     0,     9,     0,     0,    52,     0,
      50,     0,    48,     0,    33,     0,     0,    37,    55,    11,
       0,     0,     8,   186,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   185,   184,   102,
      94,     0,     0,     0,     0,     0,     0,     0,    98,     0,
     100,    86,    87,     0,     0,    88,    89,    90,    91,     0,
     123,   135,   137,   139,   141,   143,   145,   147,   150,   155,
     158,   161,   165,   176,    59,    66,     0,    62,    57,     0,
       0,     0,     0,    45,     0,    32,     0,     0,    40,    42,
      35,    38,    17,    18,     0,    19,    81,   166,   167,   118,
       0,   117,     0,     0,     0,     0,   119,     0,     0,   168,
       0,     0,     0,   171,   170,   172,   173,   174,   175,    95,
      99,     0,    96,   101,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,   183,     0,     0,     0,
       0,     0,     0,    64,    69,    65,    70,     0,    58,    56,
      46,    51,    49,    34,    43,    39,     0,     0,    84,     0,
       0,    93,     0,     0,     0,     0,   120,    67,     0,     0,
       0,   187,    97,   138,   161,     0,   140,   142,   144,   146,
     148,   149,   153,   154,   151,   152,   156,   157,   159,   160,
     162,   163,   164,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   124,   181,   178,     0,   121,     0,   180,
      77,     0,     0,    73,     0,    71,     0,     0,    63,    41,
      44,     0,    82,    92,     0,     0,     0,     0,     0,     0,
      69,    68,   169,     0,     0,     0,     0,   179,   177,    78,
      72,    74,    79,     0,    75,     0,    83,    85,     0,     0,
       0,     0,     0,     0,   104,   106,   107,   136,   122,    80,
      76,   108,   109,     0,     0,     0,     0,     0,     0,     0,
     112,   111,     0,   110,     0,     0,     0,   105,   114,   115,
     113,     0,   116
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -198,  -198,  -198,  -198,   204,  -198,   -34,    27,  -198,   186,
       0,   -46,  -198,   194,   -41,  -198,    32,  -198,   201,   129,
      17,   -26,   -15,   -44,    45,  -198,  -110,  -197,  -128,  -198,
     -66,  -198,   -11,  -198,   160,  -198,  -198,  -198,  -198,  -198,
     -47,   -36,  -198,    89,    88,    94,    87,    91,    -5,   -48,
      -4,    -8,    25,  -198,  -198
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    22,   115,    40,    41,
      24,    55,    25,    56,    57,   127,   128,    26,    51,    52,
      27,    28,    29,   271,   117,   228,   272,   206,   135,   219,
      90,    91,    92,    93,    94,    95,    96,    97,    98,   266,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     119,    36,   116,    48,   143,   205,   218,   275,   125,   165,
      88,   207,   173,   174,   136,   131,    45,   208,    30,    32,
     140,    61,    44,    50,    31,    33,   147,    23,   163,    37,
      13,    62,    35,    54,   152,    13,    13,    34,    39,   201,
      42,   202,    16,    16,    15,   201,    23,   202,    16,    13,
      44,    43,    13,    54,    54,    13,    54,   126,    15,   160,
     144,    15,    16,   296,    15,    16,    46,   207,    47,   297,
     166,    89,   129,   299,   211,    58,   221,   133,   207,   214,
     175,   176,   181,   131,   319,   122,    49,   136,   123,   137,
     138,   182,   183,   275,    53,   163,   121,   224,   225,   149,
     204,   152,   227,   229,   230,   139,   133,   153,   154,   155,
     156,   157,   158,   276,   289,   277,   202,   291,    16,   235,
      89,   289,   141,   202,    54,   242,   243,   244,   245,   142,
     122,   281,   203,   210,   282,    59,    60,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    54,   171,
     172,   267,   268,   307,   283,   274,   177,   178,   179,   180,
     145,   195,   196,   215,   216,   150,   240,   241,   151,   164,
     280,   248,   249,   246,   247,   167,   286,   168,    48,   169,
     209,   197,   170,   217,    61,   220,   204,   222,   226,   264,
     234,   231,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   250,   251,   252,   269,
     287,   295,   290,   284,   329,   288,   292,   311,    35,   328,
     293,   294,   314,    38,   198,   298,   199,   315,   316,   300,
     305,   321,   303,   129,   136,   323,   301,   308,   310,   320,
     313,   200,   332,   322,   334,   341,   132,   124,   279,   318,
     120,   212,   278,   161,   233,   236,   238,   330,   331,   317,
     333,   239,   237,   337,   325,   327,   338,     0,   339,   340,
       0,     0,     0,     0,   290,   342,    63,    64,    65,     0,
       0,   336,     0,     0,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     0,     0,     0,     0,     0,    66,
      67,     1,     0,    68,    69,    70,     2,     0,     3,     4,
      71,     0,    72,     5,     6,     0,    73,     7,     8,    74,
     234,     9,    75,    10,     0,    11,    12,    76,     0,     0,
      77,    78,    14,   194,    79,     0,     0,    44,    80,     0,
      81,    63,    64,    65,    82,     0,     0,     0,    83,     0,
       0,    84,    85,     0,     0,    86,    87,     0,     0,     0,
       0,     0,     0,     0,    66,    67,     1,     0,    68,    69,
      70,     2,     0,     3,     4,    71,     0,    72,     5,     6,
       0,    73,     7,     8,    74,     0,     9,    75,    10,     0,
      11,    12,    76,     0,     0,    77,    78,    14,     0,    79,
       0,     0,    44,   159,     0,    81,    63,    64,    65,    82,
       0,     0,     0,    83,     0,     0,    84,    85,     0,     0,
      86,    87,     0,     0,     0,     0,     0,     0,     0,    66,
      67,     0,     0,    68,    69,    70,     0,     0,     0,     0,
      71,     0,    72,     0,     0,     0,    73,     0,     0,    74,
       0,     0,    75,     0,     0,     0,     0,    76,     0,     0,
      77,    78,     0,     0,    79,     0,     0,    44,   162,     0,
      81,    63,    64,    65,    82,     0,     0,     0,    83,     0,
       0,    84,    85,     0,     0,    86,    87,     0,     0,     0,
       0,     0,     0,     0,    66,    67,     0,     0,    68,    69,
      70,     0,     0,     0,     0,    71,     0,    72,     0,     0,
       0,    73,     0,     0,    74,     0,     0,    75,     0,     0,
       0,     0,    76,     0,     0,    77,    78,     0,     0,    79,
       0,     0,    44,   232,     0,    81,    63,    64,    65,    82,
       0,     0,     0,    83,     0,     0,    84,    85,     0,     0,
      86,    87,     0,     0,     0,     0,     0,     0,     0,    66,
      67,     0,     0,    68,    69,    70,     0,     0,     0,     0,
      71,     0,    72,     0,     0,     0,    73,     0,     0,    74,
       0,     0,    75,     0,     0,     0,     0,    76,     0,     0,
      77,    78,     0,     0,    79,     0,     0,    44,     0,     0,
      81,    63,    64,    65,    82,     0,     0,     0,    83,     0,
       0,    84,    85,     0,     0,    86,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,    63,    64,
      65,     2,     0,     3,     4,     0,     0,     0,     5,     6,
       0,     0,     7,     8,    74,     0,     9,     0,     0,     0,
      11,    12,     0,     0,     0,    77,    78,    14,    63,    64,
      65,     0,     0,     0,     0,    81,     0,     0,     0,    82,
       0,    74,     0,    83,     0,     0,    84,    85,     0,     0,
      86,    87,    77,    78,     0,    63,    64,    65,     0,   134,
     306,     0,    81,     0,     0,     0,    82,     0,     0,     0,
      83,    74,     0,    84,    85,     0,     0,    86,    87,     0,
       0,     0,    77,    78,     0,    63,    64,    65,     0,     0,
       0,     0,    81,     0,     0,   118,    82,     0,    74,     0,
      83,     0,     0,    84,    85,     0,     0,    86,    87,    77,
      78,     0,    63,    64,    65,     0,   134,     0,     0,    81,
       0,     0,     0,    82,     0,     0,     0,    83,    74,     0,
      84,    85,     0,     0,    86,    87,     0,     0,     0,    77,
      78,     0,     0,   146,     0,     0,    63,    64,    65,    81,
       0,     0,     0,    82,     0,    74,     0,    83,     0,     0,
      84,    85,     0,     0,    86,    87,    77,    78,     0,     0,
     223,     0,     0,    63,    64,    65,    81,     0,     0,     0,
      82,     0,     0,     0,    83,     0,     0,    84,    85,    74,
       0,    86,    87,     0,     0,     0,    63,    64,    65,     0,
      77,    78,     0,     0,     0,     0,     0,     0,     0,     0,
      81,   265,     0,     0,    82,     0,    74,     0,    83,     0,
       0,    84,    85,     0,     0,    86,    87,    77,    78,     0,
      63,    64,    65,     0,     0,     0,     0,    81,     0,    74,
     273,    82,     0,     0,     0,    83,     0,     0,    84,    85,
      77,    78,    86,    87,   285,     0,     0,    63,    64,    65,
      81,     0,     0,     0,    82,     0,     0,     0,    83,     0,
       0,    84,    85,    74,     0,    86,    87,     0,     0,     0,
      63,    64,    65,     0,    77,    78,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,   304,    82,     0,
      74,     0,    83,     0,     0,    84,    85,     0,     0,    86,
      87,    77,    78,     0,    63,    64,    65,     0,     0,     0,
       0,    81,   309,    74,     0,    82,     0,     0,     0,    83,
       0,     0,    84,    85,    77,    78,    86,    87,   312,     0,
       0,    63,    64,    65,    81,     0,     0,     0,    82,     0,
       0,     0,    83,     0,     0,    84,    85,    74,     0,    86,
      87,     0,     0,     0,    63,    64,    65,     0,    77,    78,
       0,     0,     0,     0,     0,     0,     0,     0,    81,   324,
       0,     0,    82,     0,    74,     0,    83,     0,     0,    84,
      85,     0,     0,    86,    87,    77,    78,     0,    63,    64,
      65,     0,     0,     0,     0,    81,   326,    74,     0,    82,
       0,     0,     0,    83,     0,     0,    84,    85,    77,    78,
      86,    87,     0,     0,     0,    63,    64,    65,    81,   335,
       0,     0,    82,     0,     0,     0,    83,     0,     0,    84,
      85,    74,     0,    86,    87,     0,     0,     0,     0,     0,
       0,     0,    77,    78,     0,     0,     0,     0,     0,     0,
       0,     0,    81,     0,     0,     0,    82,     0,    74,     0,
      83,     0,     0,    84,    85,     0,     0,    86,    87,    77,
      78,     0,     0,     0,     0,     0,     0,     0,     0,   148,
       0,     0,     0,    82,     0,     0,     0,    83,     0,     0,
      84,    85,     1,     0,    86,    87,     0,     2,     0,     3,
       4,     0,     0,     0,     5,     6,     0,     0,     7,     8,
       0,     0,     9,     0,    10,     0,    11,    12,     0,     0,
       0,     0,    13,    14,     0,     0,     0,     0,     0,     1,
       0,   201,   270,   202,     2,    16,     3,     4,     0,     0,
       0,     5,     6,     0,     0,     7,     8,     0,     0,     9,
       0,    10,     0,    11,    12,     0,     0,     0,     0,     0,
      14,     0,     0,     0,     0,     0,     1,     0,   289,   270,
     202,     2,    16,     3,     4,     0,     0,     0,     5,     6,
       0,     0,     7,     8,     0,     0,     9,     0,    10,     0,
      11,    12,     0,     0,     1,     0,    13,    14,     0,     2,
       0,     3,     4,     0,     0,    15,     5,     6,     0,    16,
       7,     8,     0,     0,     9,     1,    10,     0,    11,    12,
       2,     0,     3,     4,     0,    14,     0,     5,     6,     0,
       0,     7,     8,     0,   114,     9,     1,    10,     0,    11,
      12,     2,     0,     3,     4,     0,    14,     0,     5,     6,
       0,     0,     7,     8,     0,   302,     9,     0,     1,     0,
      11,    12,     0,     2,     0,     3,     4,    14,     0,     0,
       5,     6,     0,   130,     7,     8,     0,     0,     9,     0,
       1,     0,    11,    12,     0,     2,     0,     3,     4,    14,
       0,     0,     5,     6,     0,   213,     7,     8,     0,     0,
       9,     1,    10,     0,    11,    12,     2,     0,     3,     4,
       0,    14,     0,     5,     6,     0,     0,     7,     8,     0,
       0,     9,     0,     0,     0,    11,    12,     0,     0,     0,
       0,     0,    14
};

static const yytype_int16 yycheck[] =
{
      47,    16,    46,    29,    70,   115,   134,   204,    54,    11,
      44,    62,     8,     9,    61,    56,    27,    68,    58,    58,
      67,    63,    64,    58,    64,    64,    73,     0,    94,     0,
      58,    42,    15,    33,    81,    58,    58,    10,    61,    67,
      23,    69,    71,    71,    67,    67,    19,    69,    71,    58,
      64,    24,    58,    53,    54,    58,    56,    66,    67,    93,
      67,    67,    71,    62,    67,    71,    67,    62,    69,    68,
      72,    44,    55,    68,   121,    68,   142,    60,    62,   126,
      76,    77,    71,   124,    68,    62,    64,   134,    65,    64,
      65,    80,    81,   290,    64,   161,    63,   144,   145,    74,
     115,   148,   148,   150,   151,    61,    89,    82,    83,    84,
      85,    86,    87,    67,    67,    69,    69,   227,    71,   166,
      93,    67,    61,    69,   124,   173,   174,   175,   176,    66,
      62,    62,   115,    65,    65,    61,    62,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   148,     6,
       7,   198,   199,   281,   220,   202,    12,    13,    78,    79,
      67,     4,     5,    61,    62,    67,   171,   172,    67,    61,
     217,   179,   180,   177,   178,    10,   223,    73,   204,    74,
      70,    24,    75,    66,    63,    66,   201,    54,    61,    58,
     165,    68,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    58,
      61,    66,   227,    67,    34,    68,    68,    61,   201,    61,
      68,    68,   288,    19,    67,    70,    69,   293,   294,    68,
     277,    68,   276,   216,   281,    68,    70,   284,   285,    70,
     287,    84,    68,   309,    68,    68,    60,    53,   216,   296,
      49,   122,   207,    93,   165,   167,   169,   323,   324,   295,
     326,   170,   168,   329,   311,   312,   332,    -1,   334,   335,
      -1,    -1,    -1,    -1,   289,   341,     3,     4,     5,    -1,
      -1,   328,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    -1,    30,    31,    32,    33,    -1,    35,    36,
      37,    -1,    39,    40,    41,    -1,    43,    44,    45,    46,
     295,    48,    49,    50,    -1,    52,    53,    54,    -1,    -1,
      57,    58,    59,    63,    61,    -1,    -1,    64,    65,    -1,
      67,     3,     4,     5,    71,    -1,    -1,    -1,    75,    -1,
      -1,    78,    79,    -1,    -1,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    -1,    30,    31,
      32,    33,    -1,    35,    36,    37,    -1,    39,    40,    41,
      -1,    43,    44,    45,    46,    -1,    48,    49,    50,    -1,
      52,    53,    54,    -1,    -1,    57,    58,    59,    -1,    61,
      -1,    -1,    64,    65,    -1,    67,     3,     4,     5,    71,
      -1,    -1,    -1,    75,    -1,    -1,    78,    79,    -1,    -1,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    -1,    39,    -1,    -1,    -1,    43,    -1,    -1,    46,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      57,    58,    -1,    -1,    61,    -1,    -1,    64,    65,    -1,
      67,     3,     4,     5,    71,    -1,    -1,    -1,    75,    -1,
      -1,    78,    79,    -1,    -1,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,
      32,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,    -1,
      -1,    43,    -1,    -1,    46,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    57,    58,    -1,    -1,    61,
      -1,    -1,    64,    65,    -1,    67,     3,     4,     5,    71,
      -1,    -1,    -1,    75,    -1,    -1,    78,    79,    -1,    -1,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    -1,    39,    -1,    -1,    -1,    43,    -1,    -1,    46,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      57,    58,    -1,    -1,    61,    -1,    -1,    64,    -1,    -1,
      67,     3,     4,     5,    71,    -1,    -1,    -1,    75,    -1,
      -1,    78,    79,    -1,    -1,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,     3,     4,
       5,    33,    -1,    35,    36,    -1,    -1,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    -1,    48,    -1,    -1,    -1,
      52,    53,    -1,    -1,    -1,    57,    58,    59,     3,     4,
       5,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,
      -1,    46,    -1,    75,    -1,    -1,    78,    79,    -1,    -1,
      82,    83,    57,    58,    -1,     3,     4,     5,    -1,    64,
      65,    -1,    67,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      75,    46,    -1,    78,    79,    -1,    -1,    82,    83,    -1,
      -1,    -1,    57,    58,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    70,    71,    -1,    46,    -1,
      75,    -1,    -1,    78,    79,    -1,    -1,    82,    83,    57,
      58,    -1,     3,     4,     5,    -1,    64,    -1,    -1,    67,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    75,    46,    -1,
      78,    79,    -1,    -1,    82,    83,    -1,    -1,    -1,    57,
      58,    -1,    -1,    61,    -1,    -1,     3,     4,     5,    67,
      -1,    -1,    -1,    71,    -1,    46,    -1,    75,    -1,    -1,
      78,    79,    -1,    -1,    82,    83,    57,    58,    -1,    -1,
      61,    -1,    -1,     3,     4,     5,    67,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,    46,
      -1,    82,    83,    -1,    -1,    -1,     3,     4,     5,    -1,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    71,    -1,    46,    -1,    75,    -1,
      -1,    78,    79,    -1,    -1,    82,    83,    57,    58,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,    67,    -1,    46,
      70,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,
      57,    58,    82,    83,    61,    -1,    -1,     3,     4,     5,
      67,    -1,    -1,    -1,    71,    -1,    -1,    -1,    75,    -1,
      -1,    78,    79,    46,    -1,    82,    83,    -1,    -1,    -1,
       3,     4,     5,    -1,    57,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    71,    -1,
      46,    -1,    75,    -1,    -1,    78,    79,    -1,    -1,    82,
      83,    57,    58,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    67,    68,    46,    -1,    71,    -1,    -1,    -1,    75,
      -1,    -1,    78,    79,    57,    58,    82,    83,    61,    -1,
      -1,     3,     4,     5,    67,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    75,    -1,    -1,    78,    79,    46,    -1,    82,
      83,    -1,    -1,    -1,     3,     4,     5,    -1,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      -1,    -1,    71,    -1,    46,    -1,    75,    -1,    -1,    78,
      79,    -1,    -1,    82,    83,    57,    58,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    67,    68,    46,    -1,    71,
      -1,    -1,    -1,    75,    -1,    -1,    78,    79,    57,    58,
      82,    83,    -1,    -1,    -1,     3,     4,     5,    67,    68,
      -1,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,
      79,    46,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    71,    -1,    46,    -1,
      75,    -1,    -1,    78,    79,    -1,    -1,    82,    83,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,
      78,    79,    28,    -1,    82,    83,    -1,    33,    -1,    35,
      36,    -1,    -1,    -1,    40,    41,    -1,    -1,    44,    45,
      -1,    -1,    48,    -1,    50,    -1,    52,    53,    -1,    -1,
      -1,    -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    67,    68,    69,    33,    71,    35,    36,    -1,    -1,
      -1,    40,    41,    -1,    -1,    44,    45,    -1,    -1,    48,
      -1,    50,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    28,    -1,    67,    68,
      69,    33,    71,    35,    36,    -1,    -1,    -1,    40,    41,
      -1,    -1,    44,    45,    -1,    -1,    48,    -1,    50,    -1,
      52,    53,    -1,    -1,    28,    -1,    58,    59,    -1,    33,
      -1,    35,    36,    -1,    -1,    67,    40,    41,    -1,    71,
      44,    45,    -1,    -1,    48,    28,    50,    -1,    52,    53,
      33,    -1,    35,    36,    -1,    59,    -1,    40,    41,    -1,
      -1,    44,    45,    -1,    68,    48,    28,    50,    -1,    52,
      53,    33,    -1,    35,    36,    -1,    59,    -1,    40,    41,
      -1,    -1,    44,    45,    -1,    68,    48,    -1,    28,    -1,
      52,    53,    -1,    33,    -1,    35,    36,    59,    -1,    -1,
      40,    41,    -1,    65,    44,    45,    -1,    -1,    48,    -1,
      28,    -1,    52,    53,    -1,    33,    -1,    35,    36,    59,
      -1,    -1,    40,    41,    -1,    65,    44,    45,    -1,    -1,
      48,    28,    50,    -1,    52,    53,    33,    -1,    35,    36,
      -1,    59,    -1,    40,    41,    -1,    -1,    44,    45,    -1,
      -1,    48,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,
      -1,    -1,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    33,    35,    36,    40,    41,    44,    45,    48,
      50,    52,    53,    58,    59,    67,    71,    86,    87,    88,
      89,    90,    91,    92,    95,    97,   102,   105,   106,   107,
      58,    64,    58,    64,    92,   105,   107,     0,    89,    61,
      93,    94,   105,    92,    64,   117,    67,    69,   106,    64,
      58,   103,   104,    64,    95,    96,    98,    99,    68,    61,
      62,    63,   117,     3,     4,     5,    26,    27,    30,    31,
      32,    37,    39,    43,    46,    49,    54,    57,    58,    61,
      65,    67,    71,    75,    78,    79,    82,    83,    91,    92,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    68,    92,   108,   109,    70,   125,
     103,    63,    62,    65,    98,    96,    66,   100,   101,   105,
      65,    99,    94,   105,    64,   113,   125,   137,   137,    61,
     125,    61,    66,   115,    67,    67,    61,   125,    67,   137,
      67,    67,   125,   137,   137,   137,   137,   137,   137,    65,
      91,   119,    65,   115,    61,    11,    72,    10,    73,    74,
      75,     6,     7,     8,     9,    76,    77,    12,    13,    78,
      79,    71,    80,    81,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    63,     4,     5,    24,    67,    69,
      84,    67,    69,   105,   107,   111,   112,    62,    68,    70,
      65,   125,   104,    65,   125,    61,    62,    66,   113,   114,
      66,   115,    54,    61,   125,   125,    61,    96,   110,   125,
     125,    68,    65,   128,   137,   125,   129,   130,   131,   132,
     133,   133,   134,   134,   134,   134,   135,   135,   136,   136,
     137,   137,   137,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,    58,    68,   124,   125,   125,    58,
      68,   108,   111,    70,   125,   112,    67,    69,   109,   101,
     125,    62,    65,   115,    67,    61,   125,    61,    68,    67,
     107,   111,    68,    68,    68,    66,    62,    68,    70,    68,
      68,    70,    68,   108,    70,   125,    65,   113,   125,    68,
     125,    61,    61,   125,   115,   115,   115,   126,   125,    68,
      70,    68,   115,    68,    68,   125,    68,   125,    61,    34,
     115,   115,    68,   115,    68,    68,   125,   115,   115,   115,
     115,    68,   115
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    87,    88,    88,    89,    89,    90,    90,
      91,    91,    92,    92,    92,    92,    93,    93,    94,    94,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    96,    96,    97,    97,    97,    98,    98,    99,
     100,   100,   101,   101,   101,   102,   102,   102,   103,   103,
     104,   104,   105,   105,   106,   106,   106,   106,   106,   106,
     107,   107,   108,   108,   109,   109,   109,   110,   110,   111,
     111,   111,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   113,   113,   113,   114,   114,   115,   115,   115,   115,
     115,   115,   116,   116,   117,   117,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   121,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   123,   123,   123,
     123,   124,   124,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   126,   126,   127,   127,   128,
     128,   129,   129,   130,   130,   131,   131,   132,   132,   132,
     133,   133,   133,   133,   133,   134,   134,   134,   135,   135,
     135,   136,   136,   136,   136,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   138,   138,   138,   138,
     138,   138,   138,   138,   139,   139,   139,   139
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     1,     1,     3,     2,
       2,     3,     2,     1,     2,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     5,     4,     2,     1,     2,     3,
       1,     3,     1,     2,     3,     4,     5,     2,     1,     3,
       1,     3,     2,     1,     1,     3,     4,     3,     4,     3,
       1,     2,     1,     3,     2,     2,     1,     1,     2,     1,
       1,     2,     3,     2,     3,     3,     4,     2,     3,     3,
       4,     1,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     4,     3,     2,     3,     3,     4,     1,     2,
       1,     2,     1,     2,     5,     7,     5,     5,     6,     6,
       7,     7,     7,     8,     8,     8,     9,     2,     2,     2,
       3,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     5,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     2,     2,     4,
       2,     2,     2,     2,     2,     2,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     1,     1,     3
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
#line 56 "src/compiler_bison.y" /* yacc.c:1660  */
    { g_root = (yyvsp[0].BaseNodePtr); }
#line 1754 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 3:
#line 61 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new TopContainer((yyvsp[0].BaseListPtr)); }
#line 1760 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 4:
#line 64 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new TranslationUnit(NULL, (yyvsp[0].BaseNodePtr)); }
#line 1766 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 5:
#line 65 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new TranslationUnit((yyvsp[-1].BaseListPtr), (yyvsp[0].BaseNodePtr)); }
#line 1772 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 6:
#line 68 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = (yyvsp[0].BaseNodePtr); }
#line 1778 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 7:
#line 69 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = (yyvsp[0].BaseNodePtr); }
#line 1784 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 8:
#line 72 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new FunctionDefinition((yyvsp[-2].BaseNodePtr), (yyvsp[-1].BaseNodePtr), (yyvsp[0].BaseNodePtr)); }
#line 1790 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 9:
#line 73 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new FunctionDefinition((yyvsp[-1].BaseNodePtr), (yyvsp[0].BaseNodePtr)); }
#line 1796 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 10:
#line 80 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = (yyvsp[-1].BaseNodePtr); }
#line 1802 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 11:
#line 81 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new Declaration((yyvsp[-2].BaseNodePtr), (yyvsp[-1].BaseListPtr)); }
#line 1808 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 12:
#line 84 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new TypeDefDecSpec((yyvsp[0].BaseNodePtr)); }
#line 1814 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 13:
#line 85 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new TypeDefDecSpec(NULL); }
#line 1820 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 14:
#line 86 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new TypeSpecDecSpec((yyvsp[0].BaseNodePtr), (yyvsp[-1].BaseNodePtr)); }
#line 1826 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 15:
#line 87 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = (yyvsp[0].BaseNodePtr); }
#line 1832 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 16:
#line 90 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new InitDecList(NULL, (yyvsp[0].BaseNodePtr)); }
#line 1838 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 17:
#line 91 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new InitDecList((yyvsp[-2].BaseListPtr), (yyvsp[0].BaseNodePtr)); }
#line 1844 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 18:
#line 94 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = (yyvsp[0].BaseNodePtr); }
#line 1850 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 19:
#line 95 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new InitDeclarator((yyvsp[-2].BaseNodePtr), (yyvsp[0].BaseExpressionPtr)); }
#line 1856 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 20:
#line 98 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new BasicTypeSpec(VOID_T); }
#line 1862 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 21:
#line 99 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new BasicTypeSpec(CHAR_T); }
#line 1868 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 22:
#line 100 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new BasicTypeSpec(SHORT_T); }
#line 1874 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 23:
#line 101 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new BasicTypeSpec(INT_T); }
#line 1880 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 24:
#line 102 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new BasicTypeSpec(LONG_T); }
#line 1886 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 25:
#line 103 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new BasicTypeSpec(FLOAT_T); }
#line 1892 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 26:
#line 104 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new BasicTypeSpec(DOUBLE_T); }
#line 1898 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 27:
#line 105 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new BasicTypeSpec(SIGNED_T); }
#line 1904 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 28:
#line 106 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new BasicTypeSpec(UNSIGNED_T); }
#line 1910 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 29:
#line 107 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = (yyvsp[0].BaseNodePtr); }
#line 1916 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 30:
#line 108 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = (yyvsp[0].BaseNodePtr); }
#line 1922 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 31:
#line 109 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new TypeDefTypeSpec(*(yyvsp[0].string)); }
#line 1928 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 32:
#line 112 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new TypeSpecList((yyvsp[0].BaseListPtr), (yyvsp[-1].BaseNodePtr)); }
#line 1934 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 33:
#line 113 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new TypeSpecList(NULL, (yyvsp[0].BaseNodePtr)); }
#line 1940 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 34:
#line 116 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new StructSpecifier(*(yyvsp[-3].string), (yyvsp[-1].BaseListPtr)); }
#line 1946 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 35:
#line 117 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new StructSpecifier((yyvsp[-1].BaseListPtr)); }
#line 1952 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 36:
#line 118 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new StructSpecifier(*(yyvsp[0].string), NULL); }
#line 1958 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 37:
#line 121 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new StructDeclarationList(NULL, (yyvsp[0].BaseNodePtr)); }
#line 1964 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 38:
#line 122 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new StructDeclarationList((yyvsp[-1].BaseListPtr), (yyvsp[0].BaseNodePtr)); }
#line 1970 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 39:
#line 124 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new StructDeclaration((yyvsp[-2].BaseListPtr), (yyvsp[-1].BaseListPtr)); }
#line 1976 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 40:
#line 127 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new StructDeclaratorList(NULL, (yyvsp[0].BaseNodePtr)); }
#line 1982 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 41:
#line 128 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new StructDeclaratorList((yyvsp[-2].BaseListPtr), (yyvsp[0].BaseNodePtr)); }
#line 1988 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 42:
#line 131 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = (yyvsp[0].BaseNodePtr); }
#line 1994 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 43:
#line 132 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new StructDeclarator(NULL, (yyvsp[0].BaseExpressionPtr)); }
#line 2000 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 44:
#line 133 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new StructDeclarator((yyvsp[-2].BaseNodePtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2006 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 45:
#line 136 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new EnumSpecifier((yyvsp[-1].BaseListPtr)); }
#line 2012 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 46:
#line 137 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new EnumSpecifier(*(yyvsp[-3].string), (yyvsp[-1].BaseListPtr)); }
#line 2018 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 47:
#line 138 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new EnumSpecifier(*(yyvsp[0].string), NULL); }
#line 2024 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 48:
#line 141 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new EnumElemList(NULL, (yyvsp[0].BaseNodePtr)); }
#line 2030 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 49:
#line 142 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new EnumElemList((yyvsp[-2].BaseListPtr), (yyvsp[0].BaseNodePtr)); }
#line 2036 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 50:
#line 145 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new EnumElement(*(yyvsp[0].string), NULL); }
#line 2042 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 51:
#line 146 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new EnumElement(*(yyvsp[-2].string), (yyvsp[0].BaseExpressionPtr)); }
#line 2048 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 52:
#line 149 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new Declarator((yyvsp[-1].BaseListPtr), (yyvsp[0].BaseNodePtr)); }
#line 2054 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 53:
#line 150 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = (yyvsp[0].BaseNodePtr); }
#line 2060 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 54:
#line 153 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new DeclaratorIdentifier(*(yyvsp[0].string)); }
#line 2066 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 55:
#line 154 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = (yyvsp[-1].BaseNodePtr); }
#line 2072 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 56:
#line 155 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new DeclaratorArray((yyvsp[-3].BaseNodePtr), (yyvsp[-1].BaseExpressionPtr)); }
#line 2078 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 57:
#line 156 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new DeclaratorArray((yyvsp[-2].BaseNodePtr), NULL); }
#line 2084 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 58:
#line 157 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new DeclaratorFunc((yyvsp[-3].BaseNodePtr), (yyvsp[-1].BaseListPtr)); }
#line 2090 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 59:
#line 158 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new DeclaratorFunc((yyvsp[-2].BaseNodePtr), NULL); }
#line 2096 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 60:
#line 161 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new Pointer(NULL); }
#line 2102 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 61:
#line 162 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new Pointer((yyvsp[0].BaseListPtr)); }
#line 2108 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 62:
#line 165 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new ParamList(NULL, (yyvsp[0].BaseNodePtr)); }
#line 2114 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 63:
#line 166 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new ParamList((yyvsp[-2].BaseListPtr), (yyvsp[0].BaseNodePtr)); }
#line 2120 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 64:
#line 169 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new ParamDeclaration((yyvsp[-1].BaseNodePtr), (yyvsp[0].BaseNodePtr), NULL); }
#line 2126 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 65:
#line 170 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new ParamDeclaration((yyvsp[-1].BaseNodePtr), NULL, (yyvsp[0].BaseNodePtr)); }
#line 2132 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 66:
#line 171 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new ParamDeclaration((yyvsp[0].BaseNodePtr), NULL, NULL); }
#line 2138 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 67:
#line 174 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new TypeName((yyvsp[0].BaseListPtr), NULL); }
#line 2144 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 68:
#line 175 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new TypeName((yyvsp[-1].BaseListPtr), (yyvsp[0].BaseNodePtr)); }
#line 2150 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 69:
#line 178 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new AbstractDeclarator((yyvsp[0].BaseListPtr), NULL); }
#line 2156 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 70:
#line 179 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new AbstractDeclarator(NULL, (yyvsp[0].BaseNodePtr)); }
#line 2162 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 71:
#line 180 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new AbstractDeclarator((yyvsp[-1].BaseListPtr), (yyvsp[0].BaseNodePtr)); }
#line 2168 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 72:
#line 183 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = (yyvsp[-1].BaseNodePtr); }
#line 2174 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 73:
#line 184 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new AbstractArray(NULL, NULL); }
#line 2180 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 74:
#line 185 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new AbstractArray(NULL, (yyvsp[-1].BaseExpressionPtr)); }
#line 2186 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 75:
#line 186 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new AbstractArray((yyvsp[-2].BaseNodePtr), NULL); }
#line 2192 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 76:
#line 187 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new AbstractArray((yyvsp[-3].BaseNodePtr), (yyvsp[-1].BaseExpressionPtr)); }
#line 2198 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 77:
#line 188 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new AbstractFunc(NULL, NULL); }
#line 2204 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 78:
#line 189 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new AbstractFunc(NULL, (yyvsp[-1].BaseListPtr)); }
#line 2210 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 79:
#line 190 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new AbstractFunc((yyvsp[-2].BaseNodePtr), NULL); }
#line 2216 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 80:
#line 191 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new AbstractFunc((yyvsp[-3].BaseNodePtr), (yyvsp[-1].BaseListPtr)); }
#line 2222 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 81:
#line 194 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = (yyvsp[0].BaseExpressionPtr); }
#line 2228 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 82:
#line 195 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new InitializerListHolder((yyvsp[-1].BaseExpressionListPtr)); }
#line 2234 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 83:
#line 196 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new InitializerListHolder((yyvsp[-2].BaseExpressionListPtr)); }
#line 2240 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 84:
#line 199 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionListPtr) = new InitializerList(NULL, (yyvsp[0].BaseExpressionPtr)); }
#line 2246 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 85:
#line 200 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionListPtr) = new InitializerList((yyvsp[-2].BaseExpressionListPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2252 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 86:
#line 207 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = (yyvsp[0].BaseNodePtr); }
#line 2258 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 87:
#line 208 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = (yyvsp[0].BaseNodePtr); }
#line 2264 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 88:
#line 209 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = (yyvsp[0].BaseNodePtr); }
#line 2270 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 89:
#line 210 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = (yyvsp[0].BaseNodePtr); }
#line 2276 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 90:
#line 211 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = (yyvsp[0].BaseNodePtr); }
#line 2282 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 91:
#line 212 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = (yyvsp[0].BaseNodePtr); }
#line 2288 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 92:
#line 215 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new CaseBlock((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseNodePtr)); }
#line 2294 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 93:
#line 216 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new DefaultCaseBlock((yyvsp[0].BaseNodePtr)); }
#line 2300 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 94:
#line 219 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new CompoundStatement(NULL, NULL); }
#line 2306 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 95:
#line 220 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new CompoundStatement((yyvsp[-1].BaseListPtr), NULL); }
#line 2312 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 96:
#line 221 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new CompoundStatement(NULL, (yyvsp[-1].BaseListPtr)); }
#line 2318 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 97:
#line 222 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new CompoundStatement((yyvsp[-2].BaseListPtr), (yyvsp[-1].BaseListPtr)); }
#line 2324 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 98:
#line 225 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new DeclarationList(NULL, (yyvsp[0].BaseNodePtr)); }
#line 2330 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 99:
#line 226 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new DeclarationList((yyvsp[-1].BaseListPtr), (yyvsp[0].BaseNodePtr)); }
#line 2336 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 100:
#line 229 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new StatementList(NULL, (yyvsp[0].BaseNodePtr)); }
#line 2342 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 101:
#line 230 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new StatementList(reinterpret_cast<StatementList*>((yyvsp[-1].BaseListPtr)), (yyvsp[0].BaseNodePtr)); }
#line 2348 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 102:
#line 233 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new ExpressionStatement(NULL); }
#line 2354 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 103:
#line 234 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new ExpressionStatement((yyvsp[-1].BaseExpressionPtr)); }
#line 2360 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 104:
#line 237 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new IfStatement((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseNodePtr)); }
#line 2366 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 105:
#line 238 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new IfElseStatement((yyvsp[-4].BaseExpressionPtr), (yyvsp[-2].BaseNodePtr), (yyvsp[0].BaseNodePtr)); }
#line 2372 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 106:
#line 239 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new SwitchStatement((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseNodePtr)); }
#line 2378 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 107:
#line 242 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new WhileLoop((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseNodePtr)); }
#line 2384 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 108:
#line 243 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new DoWhileLoop((yyvsp[-4].BaseNodePtr), (yyvsp[-1].BaseExpressionPtr)); }
#line 2390 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 109:
#line 244 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new ForLoop(NULL,NULL,NULL,(yyvsp[0].BaseNodePtr)); }
#line 2396 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 110:
#line 245 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new ForLoop((yyvsp[-4].BaseExpressionPtr),  NULL,NULL,(yyvsp[0].BaseNodePtr)); }
#line 2402 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 111:
#line 246 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new ForLoop(NULL,(yyvsp[-3].BaseExpressionPtr),  NULL,(yyvsp[0].BaseNodePtr)); }
#line 2408 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 112:
#line 247 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new ForLoop(NULL,NULL,(yyvsp[-2].BaseExpressionPtr)  ,(yyvsp[0].BaseNodePtr)); }
#line 2414 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 113:
#line 248 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new ForLoop((yyvsp[-5].BaseExpressionPtr),  (yyvsp[-3].BaseExpressionPtr),  NULL,(yyvsp[0].BaseNodePtr)); }
#line 2420 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 114:
#line 249 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new ForLoop(NULL,(yyvsp[-4].BaseExpressionPtr),  (yyvsp[-2].BaseExpressionPtr)  ,(yyvsp[0].BaseNodePtr)); }
#line 2426 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 115:
#line 250 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new ForLoop((yyvsp[-5].BaseExpressionPtr),  NULL,(yyvsp[-2].BaseExpressionPtr)  ,(yyvsp[0].BaseNodePtr)); }
#line 2432 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 116:
#line 251 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new ForLoop((yyvsp[-6].BaseExpressionPtr),  (yyvsp[-4].BaseExpressionPtr),  (yyvsp[-2].BaseExpressionPtr)  ,(yyvsp[0].BaseNodePtr)); }
#line 2438 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 117:
#line 254 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new Continue(); }
#line 2444 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 118:
#line 255 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new Break(); }
#line 2450 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 119:
#line 256 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new Return(NULL); }
#line 2456 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 120:
#line 257 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseNodePtr) = new Return((yyvsp[-1].BaseExpressionPtr)); }
#line 2462 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 121:
#line 264 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new ArgumentExprList(NULL, (yyvsp[0].BaseExpressionPtr)); }
#line 2468 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 122:
#line 265 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseListPtr) = new ArgumentExprList((yyvsp[-2].BaseListPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2474 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 123:
#line 268 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = (yyvsp[0].BaseExpressionPtr); }
#line 2480 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 124:
#line 269 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new Assignment((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2486 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 125:
#line 270 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new AddAssignment((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2492 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 126:
#line 271 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new SubAssignment((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2498 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 127:
#line 272 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new MulAssignment((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2504 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 128:
#line 273 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new DivAssignment((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2510 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 129:
#line 274 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new ModAssignment((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2516 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 130:
#line 275 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new LeftShiftAssignment((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2522 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 131:
#line 276 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new RightShiftAssignment((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2528 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 132:
#line 277 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new BitwiseANDAssignment((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2534 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 133:
#line 278 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new BitwiseXORAssignment((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2540 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 134:
#line 279 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new BitwiseORAssignment((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2546 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 135:
#line 282 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = (yyvsp[0].BaseExpressionPtr); }
#line 2552 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 136:
#line 283 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new ConditionalOp((yyvsp[-4].BaseExpressionPtr), (yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2558 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 137:
#line 286 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = (yyvsp[0].BaseExpressionPtr); }
#line 2564 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 138:
#line 287 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new LogicalOROp((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2570 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 139:
#line 290 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = (yyvsp[0].BaseExpressionPtr); }
#line 2576 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 140:
#line 291 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new LogicalANDOp((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2582 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 141:
#line 294 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = (yyvsp[0].BaseExpressionPtr); }
#line 2588 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 142:
#line 295 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new BitwiseInclusiveOROp((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2594 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 143:
#line 298 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = (yyvsp[0].BaseExpressionPtr); }
#line 2600 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 144:
#line 299 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new BitwiseExclusiveOROp((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2606 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 145:
#line 302 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = (yyvsp[0].BaseExpressionPtr); }
#line 2612 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 146:
#line 303 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new BitwiseANDOp((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2618 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 147:
#line 306 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = (yyvsp[0].BaseExpressionPtr); }
#line 2624 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 148:
#line 307 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new EqualToOp((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2630 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 149:
#line 308 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new NotEqualToOp((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2636 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 150:
#line 311 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = (yyvsp[0].BaseExpressionPtr); }
#line 2642 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 151:
#line 312 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new LessThanOp((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2648 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 152:
#line 313 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new MoreThanOp((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2654 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 153:
#line 314 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new LessThanEqualToOp((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2660 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 154:
#line 315 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new MoreThanEqualToOp((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2666 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 155:
#line 318 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = (yyvsp[0].BaseExpressionPtr); }
#line 2672 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 156:
#line 319 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new LeftShiftOp((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2678 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 157:
#line 320 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new RightShiftOp((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2684 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 158:
#line 323 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = (yyvsp[0].BaseExpressionPtr); }
#line 2690 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 159:
#line 324 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new AddOp((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2696 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 160:
#line 325 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new SubOp((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2702 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 161:
#line 328 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = (yyvsp[0].BaseExpressionPtr); }
#line 2708 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 162:
#line 329 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new MultiplyOp((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2714 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 163:
#line 330 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new DivideOp((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2720 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 164:
#line 331 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new ModOp((yyvsp[-2].BaseExpressionPtr), (yyvsp[0].BaseExpressionPtr)); }
#line 2726 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 165:
#line 334 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = (yyvsp[0].BaseExpressionPtr);}
#line 2732 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 166:
#line 335 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new PrefixIncOp((yyvsp[0].BaseExpressionPtr)); }
#line 2738 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 167:
#line 336 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new PrefixDecOp((yyvsp[0].BaseExpressionPtr)); }
#line 2744 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 168:
#line 337 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new SizeOfExpr((yyvsp[0].BaseExpressionPtr)); }
#line 2750 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 169:
#line 338 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new SizeOfType((yyvsp[-1].BaseNodePtr)); }
#line 2756 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 170:
#line 339 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new ReferenceOp((yyvsp[0].BaseExpressionPtr)); }
#line 2762 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 171:
#line 340 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new DereferenceOp((yyvsp[0].BaseExpressionPtr));}
#line 2768 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 172:
#line 341 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = (yyvsp[0].BaseExpressionPtr); }
#line 2774 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 173:
#line 342 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new NegationOp((yyvsp[0].BaseExpressionPtr)); }
#line 2780 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 174:
#line 343 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new InvertOp((yyvsp[0].BaseExpressionPtr)); }
#line 2786 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 175:
#line 344 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new NotOp((yyvsp[0].BaseExpressionPtr)); }
#line 2792 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 176:
#line 347 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = (yyvsp[0].BaseExpressionPtr);}
#line 2798 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 177:
#line 348 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new PostfixArrIndex((yyvsp[-3].BaseExpressionPtr), (yyvsp[-1].BaseExpressionPtr)); }
#line 2804 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 178:
#line 349 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new PostfixFuncCall((yyvsp[-2].BaseExpressionPtr), NULL); }
#line 2810 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 179:
#line 350 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new PostfixFuncCall((yyvsp[-3].BaseExpressionPtr), (yyvsp[-1].BaseListPtr)); }
#line 2816 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 180:
#line 351 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new PostfixDotOp((yyvsp[-2].BaseExpressionPtr),*(yyvsp[0].string)); }
#line 2822 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 181:
#line 352 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new PostfixArrowOp((yyvsp[-2].BaseExpressionPtr),*(yyvsp[0].string)); }
#line 2828 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 182:
#line 353 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new PostfixIncOp((yyvsp[-1].BaseExpressionPtr)); }
#line 2834 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 183:
#line 354 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new PostfixDecOp((yyvsp[-1].BaseExpressionPtr)); }
#line 2840 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 184:
#line 357 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new PrimaryExprIdentifier(*(yyvsp[0].string)); }
#line 2846 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 185:
#line 358 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new PrimaryExprConstant((yyvsp[0].number)); }
#line 2852 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 186:
#line 359 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = new PrimaryExprStrLiteral(*(yyvsp[0].string)); }
#line 2858 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;

  case 187:
#line 360 "src/compiler_bison.y" /* yacc.c:1660  */
    { (yyval.BaseExpressionPtr) = (yyvsp[-1].BaseExpressionPtr); }
#line 2864 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
    break;


#line 2868 "src/compiler_bison.tab.cpp" /* yacc.c:1660  */
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
#line 362 "src/compiler_bison.y" /* yacc.c:1903  */


AST* g_root; // Definition of variable (to match declaration earlier)

AST* parseAST() {
    g_root = 0;
    yyparse();
    return g_root;
}

AST* parseAST(char* in) {
    g_root = 0;
    yyin = fopen(in, "r");
    if(yyin) { 
	    yyparse();
    }
    fclose(yyin);
    return g_root;
}
