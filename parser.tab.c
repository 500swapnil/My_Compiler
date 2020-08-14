/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

  #include <bits/stdc++.h>
  #include "ast.h"

  using namespace std;
  extern "C" int yylex();
  extern "C" int yyparse();
//   extern "C" FILE *yyin;
  extern "C" int lineno;
  extern union Node yylval;
  extern "C" int errors;
  void yyerror(const char *s);
  class Prog* rootAst = NULL;
  int errors=0;

#line 82 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FUNC = 258,
    OPEN_PAR = 259,
    CLOSE_PAR = 260,
    OPEN_BOX = 261,
    CLOSE_BOX = 262,
    INT = 263,
    BOOL = 264,
    VOID = 265,
    UINT = 266,
    DOUBLE = 267,
    CHAR = 268,
    STRING = 269,
    IF = 270,
    THEN = 271,
    ELSE = 272,
    FOR = 273,
    WHILE = 274,
    RETURN = 275,
    TRUE = 276,
    FALSE = 277,
    COMMA = 278,
    END_LINE = 279,
    BEG = 280,
    END = 281,
    BREAK = 282,
    CONTINUE = 283,
    ID = 284,
    INT_VAL = 285,
    DOUBLE_VAL = 286,
    UINT_VAL = 287,
    CHAR_VAL = 288,
    STRING_VAL = 289,
    QUES = 290,
    COLON = 291,
    PRINT = 292,
    SCAN = 293,
    AND = 294,
    OR = 295,
    NOT = 296,
    NOTEQUALTO = 297,
    EQUALTO = 298,
    LESS = 299,
    GREATER = 300,
    LESS_EQUAL = 301,
    GREATER_EQUAL = 302,
    PLUS = 303,
    MINUS = 304,
    MULTIPLY = 305,
    DIVIDE = 306,
    MOD = 307,
    EQUAL = 308
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 182 "parser.tab.c" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   267

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   100,   100,   103,   104,   105,   108,   111,   112,   113,
     114,   118,   119,   120,   123,   126,   127,   128,   129,   130,
     133,   134,   135,   138,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   154,   155,   158,   161,   164,
     167,   168,   171,   174,   177,   178,   179,   182,   183,   184,
     187,   188,   189,   190,   193,   194,   197,   200,   201,   202,
     205,   206,   207,   208,   209,   210,   211,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   227,   230,
     231,   232,   235,   236,   239,   240,   243,   246
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNC", "OPEN_PAR", "CLOSE_PAR",
  "OPEN_BOX", "CLOSE_BOX", "INT", "BOOL", "VOID", "UINT", "DOUBLE", "CHAR",
  "STRING", "IF", "THEN", "ELSE", "FOR", "WHILE", "RETURN", "TRUE",
  "FALSE", "COMMA", "END_LINE", "BEG", "END", "BREAK", "CONTINUE", "ID",
  "INT_VAL", "DOUBLE_VAL", "UINT_VAL", "CHAR_VAL", "STRING_VAL", "QUES",
  "COLON", "PRINT", "SCAN", "AND", "OR", "NOT", "NOTEQUALTO", "EQUALTO",
  "LESS", "GREATER", "LESS_EQUAL", "GREATER_EQUAL", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "MOD", "EQUAL", "$accept", "Program", "VarList",
  "Var", "IDList", "FuncList", "Func", "ParamList", "Content", "Block",
  "Statement", "If_Statement", "While_Statement", "For_Statement",
  "Assign_Statement", "Return_Statement", "Break_Statement",
  "Continue_Statement", "Expr", "Term", "Factor", "Literal", "Int_Literal",
  "Lit_Literal", "Type", "Binop", "FuncCall", "ArgList", "Arg", "Loc",
  "Print_Statement", "Scan_Statement", YY_NULLPTR
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
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF -115

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-115)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -115,     6,   243,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,     1,   -18,   250,  -115,  -115,    17,    -6,
      -3,   -15,    18,  -115,    30,    46,    57,   250,  -115,    35,
       5,    39,    64,    49,   250,    78,  -115,    69,    54,    89,
      76,  -115,    98,  -115,  -115,    99,   122,  -115,    68,    79,
      68,    45,  -115,    83,    88,    91,     3,   101,   109,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,    94,    74,
     104,   114,    68,  -115,  -115,  -115,  -115,    68,    77,   -29,
    -115,  -115,  -115,  -115,  -115,  -115,    86,   161,  -115,   172,
    -115,  -115,  -115,    58,    68,    58,    58,  -115,    68,  -115,
    -115,    -4,   146,   119,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,    81,    81,    81,    68,    69,
    -115,  -115,   187,     7,  -115,    12,     8,     9,   198,  -115,
      69,   -29,  -115,  -115,   124,  -115,  -115,    58,  -115,  -115,
    -115,  -115,   127,    68,  -115,   121,   135,    69,   123,  -115,
     128,    69,  -115
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,    11,     1,    60,    63,    64,    61,    66,    62,
      65,     5,     4,     2,     0,     0,    13,    12,     7,     0,
       0,     0,     0,     6,     0,     0,     8,    15,     9,     0,
       0,     0,     0,     0,     0,    16,    10,     0,     0,     0,
       0,    14,    17,    18,    20,     0,     0,    19,     0,     0,
       0,     0,    22,     0,     0,     0,    84,     0,     0,    24,
      21,    26,    27,    28,    29,    30,    31,    32,     0,     0,
       0,     0,     0,    58,    59,    56,    57,     0,     0,    46,
      49,    50,    54,    55,    52,    51,     0,     0,    41,     0,
      23,    42,    43,    81,     0,    81,    81,    25,     0,    34,
      33,     0,    45,     0,    69,    70,    73,    72,    76,    74,
      77,    75,    67,    68,    71,     0,     0,     0,     0,     0,
      40,    82,    83,     0,    79,     0,     0,     0,     0,    53,
       0,    44,    47,    48,     0,    37,    78,     0,    85,    86,
      87,    39,    35,     0,    80,     0,     0,     0,     0,    36,
       0,     0,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -115,  -115,  -115,   108,  -115,  -115,  -115,  -115,  -115,  -114,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,   -48,    40,
     -40,  -115,  -115,  -115,    -7,  -115,   110,   -14,    20,   115,
    -115,  -115
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    12,    19,    13,    17,    30,    46,    41,
      60,    61,    62,    63,    64,    65,    66,    67,   122,    79,
      80,    81,    82,    83,    14,   115,    84,   123,   124,    85,
      70,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      78,   129,    87,    89,    15,   135,     3,    93,    20,    94,
      33,    18,   136,   139,   140,    25,   142,    22,    23,   138,
      31,   116,   117,    21,   101,    16,    24,    38,    34,   102,
     137,   137,   137,   149,    27,   104,   105,   152,   106,   107,
     108,   109,   110,   111,   112,   113,   125,    26,   114,    72,
     128,   104,   105,    28,   106,   107,   108,   109,   110,   111,
     112,   113,    72,    29,   114,    32,    73,    74,    35,    88,
     134,    36,    72,    37,    56,    75,   132,   133,    76,    73,
      74,   126,   127,    42,    39,    72,    77,    56,    75,    73,
      74,    76,   121,   103,    40,   146,    43,    56,    75,    77,
      44,    76,    73,    74,    45,    95,    47,    90,    86,    77,
      56,    75,    91,    96,    76,    92,   104,   105,    97,   106,
     107,   108,   109,   110,   111,   112,   113,    98,    99,   114,
       4,     5,     6,     7,     8,     9,    10,    48,   100,   118,
      49,    50,    51,   130,   145,   147,    52,   143,    53,    54,
      55,    56,   151,   150,    59,   131,    68,   144,   148,    57,
      58,    69,     0,   104,   105,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   104,   105,   114,   106,   107,   108,
     109,   110,   111,   112,   113,   119,     0,   114,   106,   107,
     108,   109,   110,   111,   112,   113,   120,     0,   114,     0,
     104,   105,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   104,   105,   114,   106,   107,   108,   109,   110,   111,
     112,   113,   141,     0,   114,     0,   104,   105,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   104,   105,   114,
     106,   107,   108,   109,   110,   111,   112,   113,     0,     0,
     114,     4,     5,     6,     7,     8,     9,    10,     4,     5,
       6,     7,     8,     9,    10,     0,     0,    11
};

static const yytype_int16 yycheck[] =
{
      48,     5,    50,    51,     3,   119,     0,     4,    15,     6,
       5,    29,     5,     5,     5,    30,   130,    23,    24,     7,
      27,    50,    51,     6,    72,    24,    29,    34,    23,    77,
      23,    23,    23,   147,     4,    39,    40,   151,    42,    43,
      44,    45,    46,    47,    48,    49,    94,    29,    52,     4,
      98,    39,    40,     7,    42,    43,    44,    45,    46,    47,
      48,    49,     4,     6,    52,    30,    21,    22,    29,    24,
     118,     7,     4,    24,    29,    30,   116,   117,    33,    21,
      22,    95,    96,    29,     6,     4,    41,    29,    30,    21,
      22,    33,    34,    16,    25,   143,     7,    29,    30,    41,
      24,    33,    21,    22,     6,     4,     7,    24,    29,    41,
      29,    30,    24,     4,    33,    24,    39,    40,    24,    42,
      43,    44,    45,    46,    47,    48,    49,    53,    24,    52,
       8,     9,    10,    11,    12,    13,    14,    15,    24,    53,
      18,    19,    20,    24,    17,    24,    24,    23,    26,    27,
      28,    29,    24,    30,    46,   115,    46,   137,    23,    37,
      38,    46,    -1,    39,    40,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    39,    40,    52,    42,    43,    44,
      45,    46,    47,    48,    49,    24,    -1,    52,    42,    43,
      44,    45,    46,    47,    48,    49,    24,    -1,    52,    -1,
      39,    40,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    39,    40,    52,    42,    43,    44,    45,    46,    47,
      48,    49,    24,    -1,    52,    -1,    39,    40,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    39,    40,    52,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      52,     8,     9,    10,    11,    12,    13,    14,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,    56,     0,     8,     9,    10,    11,    12,    13,
      14,    24,    57,    59,    78,     3,    24,    60,    29,    58,
      78,     6,    23,    24,    29,    30,    29,     4,     7,     6,
      61,    78,    30,     5,    23,    29,     7,    24,    78,     6,
      25,    63,    29,     7,    24,     6,    62,     7,    15,    18,
      19,    20,    24,    26,    27,    28,    29,    37,    38,    57,
      64,    65,    66,    67,    68,    69,    70,    71,    80,    83,
      84,    85,     4,    21,    22,    30,    33,    41,    72,    73,
      74,    75,    76,    77,    80,    83,    29,    72,    24,    72,
      24,    24,    24,     4,     6,     4,     4,    24,    53,    24,
      24,    72,    72,    16,    39,    40,    42,    43,    44,    45,
      46,    47,    48,    49,    52,    79,    50,    51,    53,    24,
      24,    34,    72,    81,    82,    72,    81,    81,    72,     5,
      24,    73,    74,    74,    72,    63,     5,    23,     7,     5,
       5,    24,    63,    23,    82,    17,    72,    24,    23,    63,
      30,    24,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    57,    58,    58,    58,
      58,    59,    59,    59,    60,    61,    61,    61,    61,    61,
      62,    62,    62,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    65,    65,    66,    67,    68,
      69,    69,    70,    71,    72,    72,    72,    73,    73,    73,
      74,    74,    74,    74,    75,    75,    76,    77,    77,    77,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    80,    81,
      81,    81,    82,    82,    83,    83,    84,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     3,     1,     3,     4,
       6,     0,     2,     2,     8,     0,     2,     4,     4,     6,
       0,     2,     2,     5,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     5,     8,     4,    10,     4,
       3,     2,     2,     2,     3,     2,     1,     3,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     0,     1,     1,     1,     4,     4,     4
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
  unsigned long int yylno = yyrline[yyrule];
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

  return yystpcpy (yyres, yystr) - yyres;
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
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

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
                  (unsigned long int) yystacksize));

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
#line 100 "parser.y" /* yacc.c:1646  */
    { (yyval.program) = new Prog((yyvsp[-1].var_list),(yyvsp[0].func_list)); rootAst = (yyval.program); }
#line 1396 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 103 "parser.y" /* yacc.c:1646  */
    { (yyval.var_list) = new Var_List(); }
#line 1402 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 104 "parser.y" /* yacc.c:1646  */
    { (yyval.var_list)=(yyvsp[-1].var_list) ; (yyval.var_list)->push_back((yyvsp[0].variable_list)); }
#line 1408 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 105 "parser.y" /* yacc.c:1646  */
    { (yyval.var_list)=(yyvsp[-1].var_list) ; }
#line 1414 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 108 "parser.y" /* yacc.c:1646  */
    { (yyval.variable_list) = (yyvsp[-1].variable_list); (yyval.variable_list)->dataType = (yyvsp[-2].lit); }
#line 1420 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 111 "parser.y" /* yacc.c:1646  */
    { (yyval.variable_list) = new Variable_List(); (yyval.variable_list)->push_back(new Variable(string("simple"),(yyvsp[0].lit)));}
#line 1426 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 112 "parser.y" /* yacc.c:1646  */
    { (yyval.variable_list)->push_back(new Variable(string("simple"),(yyvsp[0].lit)));}
#line 1432 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 113 "parser.y" /* yacc.c:1646  */
    { (yyval.variable_list) = new Variable_List(); (yyval.variable_list)->push_back(new Variable(string("array"),(yyvsp[-3].lit),(yyvsp[-1].num)));}
#line 1438 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval.variable_list)->push_back(new Variable(string("array"),(yyvsp[-3].lit),(yyvsp[-1].num)));}
#line 1444 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 118 "parser.y" /* yacc.c:1646  */
    { (yyval.func_list) = new Func_List(); }
#line 1450 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.func_list)=(yyvsp[-1].func_list) ; (yyval.func_list)->push_back((yyvsp[0].func)); }
#line 1456 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.func_list)=(yyvsp[-1].func_list) ;}
#line 1462 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval.func) = new Func((yyvsp[-6].lit),(yyvsp[-5].lit),(yyvsp[-3].param_list),(yyvsp[0].block)); }
#line 1468 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 126 "parser.y" /* yacc.c:1646  */
    { (yyval.param_list) = new Param_List();}
#line 1474 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 127 "parser.y" /* yacc.c:1646  */
    { (yyval.param_list) = new Param_List(); (yyval.param_list)->push_back((yyvsp[-1].lit),(yyvsp[0].lit),string("simple")); }
#line 1480 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval.param_list)=(yyvsp[-3].param_list) ; (yyval.param_list)->push_back((yyvsp[-1].lit),(yyvsp[0].lit),string("simple")); }
#line 1486 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval.param_list) = new Param_List(); (yyval.param_list)->push_back((yyvsp[-3].lit),(yyvsp[-2].lit),string("array")); }
#line 1492 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 130 "parser.y" /* yacc.c:1646  */
    { (yyval.param_list)=(yyvsp[-5].param_list) ; (yyval.param_list)->push_back((yyvsp[-3].lit),(yyvsp[-2].lit),string("array")); }
#line 1498 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 133 "parser.y" /* yacc.c:1646  */
    { (yyval.content) = new Content(); }
#line 1504 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 134 "parser.y" /* yacc.c:1646  */
    { (yyval.content)=(yyvsp[-1].content) ; (yyval.content)->push_back((yyvsp[0].statement)); }
#line 1510 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.content)=(yyvsp[-1].content) ; }
#line 1516 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.block) = new Block((yyvsp[-2].content)); }
#line 1522 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].variable_list); }
#line 1528 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[-1].func_call); }
#line 1534 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].if_statement); }
#line 1540 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].while_statement); }
#line 1546 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].for_statement); }
#line 1552 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].assign_statement); }
#line 1558 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].return_statement); }
#line 1564 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].break_statement); }
#line 1570 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 149 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].continue_statement); }
#line 1576 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[-1].scan_statement); }
#line 1582 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[-1].print_statement); }
#line 1588 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 154 "parser.y" /* yacc.c:1646  */
    { (yyval.if_statement) = new If_Stmt((yyvsp[-3].expr),(yyvsp[0].block)); }
#line 1594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.if_statement) = new If_Stmt((yyvsp[-6].expr),(yyvsp[-3].block),(yyvsp[0].block)); }
#line 1600 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.while_statement) = new While_Stmt((yyvsp[-2].expr),(yyvsp[0].block)); }
#line 1606 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.for_statement) = new For_Stmt((yyvsp[-8].lit),(yyvsp[-6].expr),(yyvsp[-4].expr),(yyvsp[-2].num),(yyvsp[0].block)); }
#line 1612 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.assign_statement) = new Assign_Stmt((yyvsp[-3].location),(yyvsp[-1].expr)); }
#line 1618 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval.return_statement) = new Return_Stmt((yyvsp[-1].expr)); }
#line 1624 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval.return_statement) = new Return_Stmt(); }
#line 1630 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.break_statement) = new Break_Stmt(); }
#line 1636 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.continue_statement) = new Continue_Stmt(); }
#line 1642 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binary_Expr((yyvsp[-2].expr),(yyvsp[-1].lit),(yyvsp[0].expr)); }
#line 1648 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Not_Expr((yyvsp[0].expr)); }
#line 1654 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1660 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binary_Expr((yyvsp[-2].expr),(yyvsp[-1].lit),(yyvsp[0].expr)); }
#line 1666 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 183 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binary_Expr((yyvsp[-2].expr),(yyvsp[-1].lit),(yyvsp[0].expr)); }
#line 1672 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 184 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1678 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 187 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].literal); }
#line 1684 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 188 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].location); }
#line 1690 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].func_call); }
#line 1696 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 190 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 1702 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyval.literal) = new Literal((yyvsp[0].num)); }
#line 1708 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyval.literal) = new Literal((yyvsp[0].lit)); }
#line 1714 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval.num) = (yyvsp[0].num); }
#line 1720 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1726 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1732 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 202 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1738 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 205 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1744 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1750 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 207 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1756 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 208 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1762 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1768 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1774 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1780 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1786 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 215 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1792 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 216 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1798 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1804 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 218 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1810 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 219 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1816 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 220 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1822 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1828 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1834 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1840 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 224 "parser.y" /* yacc.c:1646  */
    { (yyval.lit) = (yyvsp[0].lit); }
#line 1846 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 227 "parser.y" /* yacc.c:1646  */
    { (yyval.func_call) = new Func_Call((yyvsp[-3].lit),(yyvsp[-1].arg_list)); }
#line 1852 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 230 "parser.y" /* yacc.c:1646  */
    { (yyval.arg_list) = new Arg_List(); (yyval.arg_list)->push_back((yyvsp[0].arg));}
#line 1858 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 231 "parser.y" /* yacc.c:1646  */
    { (yyval.arg_list) = (yyvsp[-2].arg_list) ; (yyval.arg_list)->push_back((yyvsp[0].arg)); }
#line 1864 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 232 "parser.y" /* yacc.c:1646  */
    { (yyval.arg_list) = new Arg_List();}
#line 1870 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 235 "parser.y" /* yacc.c:1646  */
    { (yyval.arg) = new Arg((yyvsp[0].lit)); }
#line 1876 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 236 "parser.y" /* yacc.c:1646  */
    { (yyval.arg) = new Arg((yyvsp[0].expr)); }
#line 1882 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 239 "parser.y" /* yacc.c:1646  */
    { (yyval.location) = new Location(string("simple"),(yyvsp[0].lit));}
#line 1888 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 240 "parser.y" /* yacc.c:1646  */
    { (yyval.location) = new Location(string("array"),(yyvsp[-3].lit),(yyvsp[-1].expr));}
#line 1894 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 243 "parser.y" /* yacc.c:1646  */
    { (yyval.print_statement) = new Print_Stmt((yyvsp[-1].arg_list)); }
#line 1900 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 246 "parser.y" /* yacc.c:1646  */
    { (yyval.scan_statement) = new Scan_Stmt((yyvsp[-1].arg_list)); }
#line 1906 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1910 "parser.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
#line 250 "parser.y" /* yacc.c:1906  */



int main(int argc, char **argv)
{
    cout<<"\n\n*******************************************************************************************\n"<<endl;
	cout<<"                                   Parsing Started                                         \n"<<endl;
	cout<<"*******************************************************************************************\n\n";
	yyparse();
	cout<<"\n\nParsing Over\n";

	cout<<"\n\n\n*******************************************************************************************\n"<<endl;
	cout<<"                                   AST Construction                                         \n"<<endl;
	cout<<"*******************************************************************************************\n";
	class ASTVisitor *visitor = new ASTVisitor();
	visitor->visit(rootAst);
	rootAst->generateCode();
	rootAst->output_llvm_ir();
	rootAst->reportError();
}

void yyerror(char *s)
{
        fprintf(stderr, "Error: %s\n", s);
}



