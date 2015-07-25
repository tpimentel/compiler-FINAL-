/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "src/sintatica.y"

/*
	Criei algumas funcoes para se trabalhar com o escopó
	pesso que tentem fazer as declaraco dos if/else/else if, e tbm dos comando de repeticao
	lembrando que temos que usar labels e GOTO
*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <stdio.h>
#include <time.h>

#define YYSTYPE atributos

using namespace std;

//Estrutura para atributos do Yacc
typedef struct
{
	string label;
	string traducao;
	string tipo;
	int tam;
} atributos;

//Estrutura para variaveis
typedef struct _variaveis
{
	string nome_temp;
	string tipo;
	int tam;

} inf_variaveis;

//Estrutura para Cast's
typedef struct _cast
{
	string resultOperacao;
	int operando;
}tipo_cast;
map<string, tipo_cast> gera_map_cast();

//Estrutura para Label's
typedef struct _label
{
	string labelIni;
	string labelMeio;
	string labelFim;
} inf_label;

//Contador de linhas
int nLinha = 1;

//Mapa de variaveis, tabela sintatica
//map<string, inf_variaveis> map_variaveis;

//Mapa de cast's
map<string, tipo_cast> map_cast = gera_map_cast();

//Pilha para armazenar os escopos
vector< map<string, inf_variaveis> > vecEscopo;

//Pilha para armazenar as label's
vector< inf_label > vecLabel;

//Declaracao de funcoes no escopo
int yylex(void);
void yyerror(string);
string createvar(void);
inf_label creatLabel(string estrutura);

//Funcao para criacao de escopo
void criaEscopo();

//Funcao para finalizacao do escopo
void finalizaEscopo();

//retorna o escopo atual
map<string, inf_variaveis> getEscopo();

//insere uma funcao no escopo
void insereVarNoEscopo(string nome, inf_variaveis var);

//retorna as informacoes de uma funcao
inf_variaveis retornaVarDoEscopo(string nome);

//verifica se a funcao esta declarada
bool findVar(string nome);

//funcao para criacao de label's


//Incremento para nomeacao das variaveis temporarias e as labels temporarias
int contadorVar = 0;
int contadorLabel = 0;




/* Line 268 of yacc.c  */
#line 176 "bin/y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TK_NUM = 258,
     TK_STRING = 259,
     TK_REAL = 260,
     TK_DOUBLE = 261,
     TK_CHAR = 262,
     TK_LOGICO = 263,
     TK_MAIN = 264,
     TK_ID = 265,
     TK_WRITE = 266,
     TK_READ = 267,
     TK_WHILE = 268,
     TK_FOR = 269,
     TK_FIM = 270,
     TK_ERROR = 271,
     TK_TIPO_INT = 272,
     TK_TIPO_FLOAT = 273,
     TK_TIPO_DOUBLE = 274,
     TK_TIPO_STRING = 275,
     TK_TIPO_CHAR = 276,
     TK_TIPO_BOOLEAN = 277,
     TK_TIPO_LONG = 278,
     TK_SOMA = 279,
     TK_MENOS = 280,
     TK_MULT = 281,
     TK_DIV = 282,
     TK_REST = 283,
     TK_IG = 284,
     TK_PLUS = 285,
     TK_SUB = 286,
     TK_COMP = 287,
     TK_LT = 288,
     TK_GT = 289,
     TK_LTE = 290,
     TK_GTE = 291,
     TK_DIFF = 292,
     TK_OR = 293,
     TK_AND = 294,
     TK_NOT = 295,
     TK_IF = 296,
     TK_ELSE = 297,
     TK_ELSE_IF = 298
   };
#endif
/* Tokens.  */
#define TK_NUM 258
#define TK_STRING 259
#define TK_REAL 260
#define TK_DOUBLE 261
#define TK_CHAR 262
#define TK_LOGICO 263
#define TK_MAIN 264
#define TK_ID 265
#define TK_WRITE 266
#define TK_READ 267
#define TK_WHILE 268
#define TK_FOR 269
#define TK_FIM 270
#define TK_ERROR 271
#define TK_TIPO_INT 272
#define TK_TIPO_FLOAT 273
#define TK_TIPO_DOUBLE 274
#define TK_TIPO_STRING 275
#define TK_TIPO_CHAR 276
#define TK_TIPO_BOOLEAN 277
#define TK_TIPO_LONG 278
#define TK_SOMA 279
#define TK_MENOS 280
#define TK_MULT 281
#define TK_DIV 282
#define TK_REST 283
#define TK_IG 284
#define TK_PLUS 285
#define TK_SUB 286
#define TK_COMP 287
#define TK_LT 288
#define TK_GT 289
#define TK_LTE 290
#define TK_GTE 291
#define TK_DIFF 292
#define TK_OR 293
#define TK_AND 294
#define TK_NOT 295
#define TK_IF 296
#define TK_ELSE 297
#define TK_ELSE_IF 298




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 304 "bin/y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   129

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNRULES -- Number of states.  */
#define YYNSTATES  109

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      45,    46,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    49,
       2,    44,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    14,    18,    21,    24,    25,    31,
      41,    48,    55,    58,    59,    60,    62,    64,    67,    70,
      72,    76,    79,    82,    87,    90,    94,    96,   100,   102,
     106,   108,   112,   114,   118,   120,   123,   125,   129,   131,
     133,   135,   137,   139,   141,   143,   145,   147,   149,   151,
     153,   155,   157,   159,   161,   163,   165,   167,   169,   171,
     173,   175
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    17,     9,    45,    46,    52,    -1,    57,
      47,    53,    48,    -1,    58,    49,    53,    -1,    55,    53,
      -1,    54,    53,    -1,    -1,    13,    45,    61,    46,    52,
      -1,    14,    45,    58,    49,    61,    49,    59,    46,    52,
      -1,    41,    45,    61,    46,    52,    56,    -1,    43,    45,
      61,    46,    52,    56,    -1,    42,    52,    -1,    -1,    -1,
      60,    -1,    59,    -1,    12,    10,    -1,    11,    61,    -1,
      61,    -1,    10,    29,    61,    -1,    10,    30,    -1,    10,
      31,    -1,    71,    10,    29,    61,    -1,    71,    10,    -1,
      61,    38,    62,    -1,    62,    -1,    62,    39,    63,    -1,
      63,    -1,    64,    70,    64,    -1,    64,    -1,    64,    68,
      65,    -1,    65,    -1,    65,    69,    67,    -1,    66,    -1,
      40,    66,    -1,    67,    -1,    45,    61,    46,    -1,     8,
      -1,     3,    -1,    10,    -1,     5,    -1,     6,    -1,     4,
      -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,    28,
      -1,    33,    -1,    34,    -1,    35,    -1,    36,    -1,    32,
      -1,    37,    -1,    17,    -1,    18,    -1,    19,    -1,    20,
      -1,    21,    -1,    22,    -1,    23,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   122,   122,   144,   150,   153,   156,   159,   165,   189,
     212,   224,   233,   236,   242,   248,   252,   256,   267,   275,
     282,   320,   329,   341,   386,   413,   428,   436,   451,   458,
     482,   490,   547,   555,   587,   594,   605,   612,   617,   622,
     627,   640,   645,   650,   657,   662,   669,   674,   679,   685,
     689,   693,   697,   701,   705,   711,   717,   723,   729,   735,
     741,   747
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_NUM", "TK_STRING", "TK_REAL",
  "TK_DOUBLE", "TK_CHAR", "TK_LOGICO", "TK_MAIN", "TK_ID", "TK_WRITE",
  "TK_READ", "TK_WHILE", "TK_FOR", "TK_FIM", "TK_ERROR", "TK_TIPO_INT",
  "TK_TIPO_FLOAT", "TK_TIPO_DOUBLE", "TK_TIPO_STRING", "TK_TIPO_CHAR",
  "TK_TIPO_BOOLEAN", "TK_TIPO_LONG", "TK_SOMA", "TK_MENOS", "TK_MULT",
  "TK_DIV", "TK_REST", "TK_IG", "TK_PLUS", "TK_SUB", "TK_COMP", "TK_LT",
  "TK_GT", "TK_LTE", "TK_GTE", "TK_DIFF", "TK_OR", "TK_AND", "TK_NOT",
  "TK_IF", "TK_ELSE", "TK_ELSE_IF", "'='", "'('", "')'", "'{'", "'}'",
  "';'", "$accept", "S", "BLOCO", "COMANDOS", "LOOP", "CONDICIONAL",
  "BLOCO_ELSE", "INIT_ESCOP", "COMANDO", "ATRIBUICAO", "DECLARACAO",
  "OP_OR", "OP_AND", "REL", "E", "E_TEMP", "NOT", "VAL", "ARIT_SO_SUB",
  "ARIT_MU_DI", "RELACOES_OP", "TIPO", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    61,    40,    41,   123,   125,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    53,    53,    53,    53,    54,    54,
      55,    56,    56,    56,    57,    58,    58,    58,    58,    58,
      59,    59,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    69,    69,    69,    70,
      70,    70,    70,    70,    70,    71,    71,    71,    71,    71,
      71,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     3,     2,     2,     0,     5,     9,
       6,     6,     2,     0,     0,     1,     1,     2,     2,     1,
       3,     2,     2,     4,     2,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     2,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    14,     2,     0,     7,
      39,    43,    41,    42,    38,    40,     0,     0,     0,     0,
      55,    56,    57,    58,    59,    60,    61,     0,     0,     0,
       0,     7,     7,     0,    16,    15,    19,    26,    28,    30,
      32,    34,    36,     0,     0,    21,    22,    40,    18,    17,
       0,     0,    35,     0,     0,     3,     6,     5,     7,     0,
       0,    44,    45,    53,    49,    50,    51,    52,    54,     0,
       0,    46,    47,    48,     0,    24,    20,     0,     0,     0,
      37,     4,    25,    27,    31,    29,    33,     0,    14,     0,
      14,    23,     8,     0,    13,     0,    14,     0,    10,     0,
       0,    12,     0,    14,     0,     9,    14,    13,    11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    30,    31,    32,    98,     8,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    69,    74,
      70,    43
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -17
static const yytype_int8 yypact[] =
{
     -12,     5,     7,    -3,   -17,    12,   -17,   -17,   -14,    -2,
     -17,   -17,   -17,   -17,   -17,    26,    64,    34,     6,    40,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,    64,    53,    64,
      46,    -2,    -2,    48,   -17,   -17,    57,    60,   -17,    78,
      52,   -17,   -17,    90,    64,   -17,   -17,   -17,    57,   -17,
      64,    42,   -17,    64,    -6,   -17,   -17,   -17,    -2,    64,
      64,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,    64,
      64,   -17,   -17,   -17,    21,    72,    57,    38,    56,    43,
     -17,   -17,    60,   -17,    52,    11,   -17,    64,   -17,    64,
     -17,    57,   -17,    -8,    49,    96,   -17,    62,   -17,    26,
      70,   -17,    64,   -17,    50,   -17,   -17,    49,   -17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -17,   -17,   -13,    -9,   -17,   -17,     1,   -17,    66,    23,
     -17,   -16,    61,    59,    51,    54,    95,    55,   -17,   -17,
     -17,   -17
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      48,    10,    11,    12,    13,     1,    14,     4,    15,    16,
      17,    18,    19,    54,     3,    20,    21,    22,    23,    24,
      25,    26,    56,    57,    10,    11,    12,    13,    76,    14,
      59,    47,    59,     9,    77,    61,    62,    79,    27,    28,
      80,    95,     5,    29,    49,    10,    11,    12,    13,    81,
      14,    50,    15,    16,    17,    44,    45,    46,     6,    20,
      21,    22,    23,    24,    25,    26,    29,    10,    11,    12,
      13,    91,    14,    93,    47,    92,    59,    94,    71,    72,
      73,    59,    27,   101,    88,    51,   104,    29,    59,    90,
     105,    96,    97,   107,    55,    59,   106,    58,    53,    60,
      75,    87,    61,    62,    27,    89,    99,   102,   108,    29,
      63,    64,    65,    66,    67,    68,   103,    78,   100,    83,
      82,    85,    52,    84,     0,     0,     0,     0,     0,    86
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-17))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      16,     3,     4,     5,     6,    17,     8,     0,    10,    11,
      12,    13,    14,    29,     9,    17,    18,    19,    20,    21,
      22,    23,    31,    32,     3,     4,     5,     6,    44,     8,
      38,    10,    38,    47,    50,    24,    25,    53,    40,    41,
      46,    49,    45,    45,    10,     3,     4,     5,     6,    58,
       8,    45,    10,    11,    12,    29,    30,    31,    46,    17,
      18,    19,    20,    21,    22,    23,    45,     3,     4,     5,
       6,    87,     8,    89,    10,    88,    38,    90,    26,    27,
      28,    38,    40,    96,    46,    45,   102,    45,    38,    46,
     103,    42,    43,   106,    48,    38,    46,    49,    45,    39,
      10,    29,    24,    25,    40,    49,    10,    45,   107,    45,
      32,    33,    34,    35,    36,    37,    46,    51,    95,    60,
      59,    70,    27,    69,    -1,    -1,    -1,    -1,    -1,    74
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    51,     9,     0,    45,    46,    52,    57,    47,
       3,     4,     5,     6,     8,    10,    11,    12,    13,    14,
      17,    18,    19,    20,    21,    22,    23,    40,    41,    45,
      53,    54,    55,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    71,    29,    30,    31,    10,    61,    10,
      45,    45,    66,    45,    61,    48,    53,    53,    49,    38,
      39,    24,    25,    32,    33,    34,    35,    36,    37,    68,
      70,    26,    27,    28,    69,    10,    61,    61,    58,    61,
      46,    53,    62,    63,    65,    64,    67,    29,    46,    49,
      46,    61,    52,    61,    52,    49,    42,    43,    56,    10,
      59,    52,    45,    46,    61,    52,    46,    52,    56
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1806 of yacc.c  */
#line 122 "src/sintatica.y"
    {
				//armazena a saida do codigo
				stringstream saida;
				saida 	<< "\n/*Compilador FOCA*/\n" 
						<< "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" 
						<< (yyvsp[(5) - (5)]).traducao 
						<< "\n\n\treturn 0;\n}" 
						<< endl; 

				//exibe saida no terminal
				cout << saida.str();

				// criar arquivo de saida
				stringstream fileOUTname; 
				fileOUTname << "saidas/saida(" << __TIME__ << ").c";

				ofstream myfile;
				myfile.open (fileOUTname.str().c_str());
				myfile << saida.str();
				myfile.close();
			}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 144 "src/sintatica.y"
    {	
				(yyval).traducao = (yyvsp[(3) - (4)]).traducao;

				finalizaEscopo();
			}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 150 "src/sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
			}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 153 "src/sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (2)]).traducao + "\n" + (yyvsp[(2) - (2)]).traducao;
			}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 156 "src/sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (2)]).traducao + "\n" + (yyvsp[(2) - (2)]).traducao;
			}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 159 "src/sintatica.y"
    {
				(yyval).label = "";
				(yyval).traducao = "";
			}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 165 "src/sintatica.y"
    {
				inf_label infLabel =  creatLabel((yyvsp[(1) - (5)]).label);

				if((yyvsp[(3) - (5)]).tipo == "boolean"){
					(yyval).traducao = "\n\n" 
								+ vecLabel.back().labelIni
								+ ":\n\t" 
								+ "if(!(" + (yyvsp[(3) - (5)]).traducao + "))\n\t\tgoto " 
								+ vecLabel.back().labelFim
								+ ";\n\t"
								+  (yyvsp[(5) - (5)]).traducao
								+ "\n\tgoto " 
								+ vecLabel.back().labelIni
								+ ":\n"
								+ vecLabel.back().labelFim
								+ ":\n"; 

				} else {
					cout << "\tErro linha " << nLinha
						 << " ----- Condicao para While nao eh booleana ------- Erro producao: TK_WHILE '(' OP_OR  ')' BLOCO" << endl;
					exit(1);
				}

			}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 189 "src/sintatica.y"
    {
				inf_label infLabel =  creatLabel((yyvsp[(1) - (9)]).label);

				(yyval).traducao = "\n\n"
							+ (yyvsp[(3) - (9)]).traducao
							+ "\n" 
							+ vecLabel.back().labelIni
							+ ":\n\t"
							+ "if(!(" + (yyvsp[(5) - (9)]).traducao + "))\n\t\tgoto "
							+ vecLabel.back().labelFim
							+ ";\n\t"
							+ (yyvsp[(7) - (9)]).traducao
							+ "\n\t"
							+ (yyvsp[(9) - (9)]).traducao
							+ "\n\tgoto "
							+ vecLabel.back().labelIni
							+ ":\n"
							+ vecLabel.back().labelFim
							+ ":\n";

			}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 212 "src/sintatica.y"
    {

				inf_label infLabel =  creatLabel((yyvsp[(1) - (6)]).label);

				(yyval).traducao = 
					"\n\n" + vecLabel.back().labelIni + ":\n\t" 
					+ "if(!(" + (yyvsp[(3) - (6)]).traducao + "))\n\t\tgoto " + vecLabel.back().labelMeio + ";\n\t"
					+ (yyvsp[(5) - (6)]).traducao + "\ngoto " + vecLabel.back().labelFim + ":\n" + vecLabel.back().labelMeio
					+ ":\n" + (yyvsp[(6) - (6)]).traducao + "\n" + vecLabel.back().labelFim;
			}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 224 "src/sintatica.y"
    {
				inf_label infLabel =  creatLabel((yyvsp[(1) - (6)]).label);

				(yyval).traducao = 
					"\n\n" + vecLabel.back().labelIni + ":\n\t" 
					+ "if(!(" + (yyvsp[(3) - (6)]).traducao + "))\n\t\tgoto " + vecLabel.back().labelMeio + ";\n\t"
					+ (yyvsp[(5) - (6)]).traducao + "\ngoto " + vecLabel.back().labelFim + ":\n" + vecLabel.back().labelMeio 
					+ ":\n" + (yyvsp[(6) - (6)]).traducao + "\n" + vecLabel.back().labelFim;
			}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 233 "src/sintatica.y"
    {
				(yyval).traducao = "\t" + (yyvsp[(2) - (2)]).traducao;
			}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 236 "src/sintatica.y"
    {
				(yyval).traducao = "";
				(yyval).label = "";
			}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 242 "src/sintatica.y"
    {
				criaEscopo();
				(yyval).traducao = "";
				(yyval).label = "";
			}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 248 "src/sintatica.y"
    {				
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 252 "src/sintatica.y"
    {				
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 256 "src/sintatica.y"
    {
				if(findVar((yyvsp[(2) - (2)]).label)){
					inf_variaveis variavel = retornaVarDoEscopo((yyvsp[(2) - (2)]).label);
					string varTemp = variavel.nome_temp;

					(yyval).traducao = "\n\tcin >> " + varTemp + ";\n\t";
				} else {					
					cout << "\tErro linha " << nLinha << " ----- Variavel nao declarada! ------- Erro producao: TK_READ" << endl;
					exit(1);
				}
			}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 267 "src/sintatica.y"
    {
				if((yyvsp[(2) - (2)]).tipo == "string")
					cout << endl << endl << "string" << endl << endl ;


				(yyval).traducao = "\n\tcout << " + (yyvsp[(2) - (2)]).label + ";\n\t";
				(yyval).tipo = "void"; 
			}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 275 "src/sintatica.y"
    {				
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
			}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 282 "src/sintatica.y"
    {

				//cout << findVar($1.label) << endl << endl;
				
				//if(map_variaveis.find($1.label) != map_variaveis.end()){
				if(findVar((yyvsp[(1) - (3)]).label)){
					//inf_variaveis var = map_variaveis[$1.label];
					inf_variaveis var = retornaVarDoEscopo((yyvsp[(1) - (3)]).label);

					string castChave = var.tipo + "_" + (yyvsp[(2) - (3)]).label + "_" + (yyvsp[(3) - (3)]).tipo;

					(yyval).tipo = var.tipo;

					if(var.tipo == (yyvsp[(3) - (3)]).tipo){						

						(yyval).traducao = "\t" + (yyvsp[(3) - (3)]).traducao + "\n\t" + var.nome_temp + " " + (yyvsp[(2) - (3)]).label + " " + (yyvsp[(3) - (3)]).label + ";";

					} else if(map_cast.find(castChave) != map_cast.end()){

						tipo_cast cast = map_cast[castChave];

						if(cast.operando == 2) {
							(yyval).traducao = "\t" + (yyvsp[(3) - (3)]).traducao + "\n\t" + var.nome_temp + " " + (yyvsp[(2) - (3)]).label + " " + "(" + cast.resultOperacao + ") " + (yyvsp[(3) - (3)]).label + ";";
						} else {
							cout << "Erro na linha " << nLinha <<": Nao foi possivel atribuir o valor a variavels, pois os tipo nao combinan ------- Erro 01 producao: TK_ID TK_IG OP_OR" << endl << endl;
							exit(1);
						}

					} else {
						cout << "Erro na linha " << nLinha <<": Nao foi possivel atribuir o valor a variavels, pois os tipo nao combinan ------- Erro 02 producao: TK_ID TK_IG OP_OR" << endl << endl;
						exit(1);
					}

				}else{
					cout << "\tErro linha " << nLinha << " ----- Variavel nao declarada! ------- Erro producao: TK_ID TK_IG OP_OR" << endl;
					exit(1); 
				}
			}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 320 "src/sintatica.y"
    {
				if(findVar((yyvsp[(1) - (2)]).label)){
					inf_variaveis var = retornaVarDoEscopo((yyvsp[(1) - (2)]).label);

					if((yyvsp[(1) - (2)]).tipo == "int"){
						(yyval).traducao = "\n\t" + var.nome_temp + "++;\n" ;
					}
				}
			}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 329 "src/sintatica.y"
    {
				if(findVar((yyvsp[(1) - (2)]).label)){
					inf_variaveis var = retornaVarDoEscopo((yyvsp[(1) - (2)]).label);

					if((yyvsp[(1) - (2)]).tipo == "int"){
						(yyval).traducao = "\n\t" + var.nome_temp + "--;\n" ;
					}
				}
			}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 341 "src/sintatica.y"
    {
				inf_variaveis novo = {createvar(), (yyvsp[(1) - (4)]).traducao, (yyvsp[(4) - (4)]).tam};

				if(!findVar((yyvsp[(2) - (4)]).label)){
					insereVarNoEscopo((yyvsp[(2) - (4)]).label, novo);

					(yyval).label = novo.nome_temp;
					(yyval).tipo = (yyvsp[(1) - (4)]).tipo;

					string castChave = novo.tipo + "_" + (yyvsp[(3) - (4)]).label + "_" + (yyvsp[(4) - (4)]).tipo;

					if(novo.tipo == (yyvsp[(4) - (4)]).tipo){
						//$1.label == "string"
						if((yyvsp[(1) - (4)]).tipo == "string"){
							stringstream traducao;
							traducao << "\n\t" << (yyvsp[(4) - (4)]).traducao;
							traducao << "\n\t" << "char" << " " << novo.nome_temp << "[" << (novo.tam+1) << "]" << ";";
							traducao << "\n\tstrcpy(" << novo.nome_temp << ", " << (yyvsp[(4) - (4)]).label << ");";
							
							(yyval).traducao = traducao.str();
						} else {
							(yyval).traducao = "\t" + (yyvsp[(4) - (4)]).traducao + "\n\t" + (yyvsp[(1) - (4)]).traducao + " " + novo.nome_temp + " " + (yyvsp[(3) - (4)]).label + " " + (yyvsp[(4) - (4)]).label + ";";
						}

					} else if(map_cast.find(castChave) != map_cast.end()){	
						tipo_cast cast = map_cast[castChave];					

						if(cast.operando == 2) {
							(yyval).traducao = "\t" + (yyvsp[(4) - (4)]).traducao + "\n\t" + (yyvsp[(1) - (4)]).traducao + " " + novo.nome_temp + " " + (yyvsp[(3) - (4)]).label + " " + "(" + cast.resultOperacao + ") " + (yyvsp[(4) - (4)]).label + ";";
						} else {
							cout << "Erro na linha " << nLinha <<": Nao foi possivel atribuir o valor a variavels, pois os tipo nao combinan  ------ Erro 01 producao: TIPO TK_ID TK_IG OP_OR" << endl << endl;
							exit(1);
						}

					} else {
						cout << "Erro na linha " << nLinha <<": Nao foi possivel atribuir o valor a variavels, pois os tipo nao combinan  ------ Erro 02 producao: TIPO TK_ID TK_IG OP_OR" << endl << endl;
						exit(1);
					}

				}else{
					cout << "\tErro linha " << nLinha << " ----- Variavel redeclarada! ------ Erro producao: TIPO TK_ID TK_IG OP_OR" << endl;
					exit(1); 
				}
			}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 386 "src/sintatica.y"
    {
				inf_variaveis novo = {createvar(), (yyvsp[(1) - (2)]).traducao};

				if(!findVar((yyvsp[(2) - (2)]).label)){
					insereVarNoEscopo((yyvsp[(2) - (2)]).label, novo);
					//map_variaveis[$2.label] = novo;


					(yyval).label = novo.nome_temp;
					(yyval).tipo = (yyvsp[(1) - (2)]).tipo;
					(yyval).tam = (yyvsp[(2) - (2)]).tam;

					if((yyvsp[(1) - (2)]).label == "string") {
						(yyval).traducao = "\n\t" + (yyvsp[(1) - (2)]).traducao + " " + novo.nome_temp + "[" + "1" + "]" + ";";
						(yyval).traducao = (yyval).traducao + "\n\tstrcpy(" + novo.nome_temp + ", \"\");";

					} else {
						(yyval).traducao = "\n\t" + (yyvsp[(1) - (2)]).traducao + " " + novo.nome_temp + ";";
					}

				}else{
					cout << "Erro linha " << nLinha << " ----- Variavel redeclarada! ----  Erro producao TIPO TK_ID" << endl;
					exit(1); 

				}
			}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 413 "src/sintatica.y"
    {
				string var_temp;

				string castChave = (yyvsp[(1) - (3)]).tipo + "_" + (yyvsp[(2) - (3)]).label + "_" + (yyvsp[(3) - (3)]).tipo;

				if(((yyvsp[(1) - (3)]).tipo == "boolean") && ((yyvsp[(1) - (3)]).tipo == (yyvsp[(3) - (3)]).tipo)){
					var_temp = createvar();
					(yyval).traducao = (yyvsp[(3) - (3)]).traducao + "\t" + (yyvsp[(1) - (3)]).traducao + "\n\t" + "int" + var_temp + " = " + (yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).traducao + " " + (yyvsp[(3) - (3)]).label + ";";
				
					(yyval).tipo = "boolean";
				} else {
					cout << "Erro na linha " << nLinha <<": Nao foi possivel atribuir o valor a variavels, pois os tipo nao combinan ----  Erro producao OP_OR TK_OR OP_AND" << endl << endl;
					exit(1);
				}
			}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 428 "src/sintatica.y"
    {
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).tipo = (yyvsp[(1) - (1)]).tipo;
				(yyval).tam = (yyvsp[(1) - (1)]).tam;

			}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 436 "src/sintatica.y"
    {
				string var_temp;

				string castChave = (yyvsp[(1) - (3)]).tipo + "_" + (yyvsp[(2) - (3)]).label + "_" + (yyvsp[(3) - (3)]).tipo;

				if(((yyvsp[(1) - (3)]).tipo == "boolean") && ((yyvsp[(1) - (3)]).tipo == (yyvsp[(3) - (3)]).tipo)){
					var_temp = createvar();
					(yyval).traducao = (yyvsp[(3) - (3)]).traducao + "\t" + (yyvsp[(1) - (3)]).traducao + "\n\t" + "int" + var_temp + " = " + (yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).traducao + " " + (yyvsp[(3) - (3)]).label + ";";
				
					(yyval).tipo = "boolean";
				} else {
					cout << "Erro na linha " << nLinha <<": Nao foi possivel atribuir o valor a variavels, pois os tipo nao combinan ------ Erro producao OP_AND TK_AND REL" << endl << endl;
					exit(1);
				}
			}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 451 "src/sintatica.y"
    {
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).tipo = (yyvsp[(1) - (1)]).tipo;
				(yyval).tam = (yyvsp[(1) - (1)]).tam;				
			}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 458 "src/sintatica.y"
    {
				string var_temp;

				string castChave = (yyvsp[(1) - (3)]).tipo + "_" + (yyvsp[(2) - (3)]).label + "_" + (yyvsp[(3) - (3)]).tipo;

				if(map_cast.find(castChave) != map_cast.end()){
					tipo_cast cast = map_cast[castChave];

					var_temp = createvar();

					if(cast.operando == 1){
						(yyval).traducao = (yyvsp[(3) - (3)]).traducao + "\t" + (yyvsp[(1) - (3)]).traducao + "\n\t" + "int" + " " 
						+ var_temp + " = " + "(" + (yyvsp[(3) - (3)]).tipo + ") " + (yyvsp[(1) - (3)]).label + " " 
						+ (yyvsp[(2) - (3)]).label + " " + (yyvsp[(3) - (3)]).label + ";";
					} else if ((cast.operando == 4) && (cast.resultOperacao == "boolean")){
						(yyval).traducao = (yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).label + " " + (yyvsp[(3) - (3)]).label;
						(yyval).tipo = "boolean";
					} else {
						(yyval).traducao = (yyvsp[(3) - (3)]).traducao + "\t" + (yyvsp[(1) - (3)]).traducao + "\n\t" + "int" + " " 
						+ var_temp + " = " + (yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).label + " " 
						+ "(" + (yyvsp[(1) - (3)]).tipo + ") " + (yyvsp[(3) - (3)]).label + ";";
					}
				}
			}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 482 "src/sintatica.y"
    {
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).tipo = (yyvsp[(1) - (1)]).tipo;
				(yyval).tam = (yyvsp[(1) - (1)]).tam;				
			}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 490 "src/sintatica.y"
    {
				string var_temp = createvar();
				(yyval).label = var_temp;

				string castChave = (yyvsp[(1) - (3)]).tipo + "_" + (yyvsp[(2) - (3)]).label + "_" + (yyvsp[(3) - (3)]).tipo;

				if(map_cast.find(castChave) != map_cast.end()){
					tipo_cast cast = map_cast[castChave];

					if(cast.operando == 1){
						(yyval).traducao = (yyvsp[(3) - (3)]).traducao + "\t" + (yyvsp[(1) - (3)]).traducao + "\n\t" + "int" + " " 
						+ var_temp + " = " + "(" + (yyvsp[(3) - (3)]).tipo + ") " + (yyvsp[(1) - (3)]).label + " " 
						+ (yyvsp[(2) - (3)]).label + " " + (yyvsp[(3) - (3)]).label + ";";

					} else if(cast.operando == 2){
						(yyval).traducao = (yyvsp[(3) - (3)]).traducao + "\t" + (yyvsp[(1) - (3)]).traducao + "\n\t" + "int" + " " 
						+ var_temp + " = " + (yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).label + " " 
						+ "(" + (yyvsp[(1) - (3)]).tipo + ") " + (yyvsp[(3) - (3)]).label + ";";

					} else if ((cast.operando == -1) && (cast.resultOperacao == "string")) {
						inf_variaveis novo = {createvar(), "string", (yyvsp[(1) - (3)]).tam + (yyvsp[(3) - (3)]).tam};

						stringstream trad;
						trad << "\n\tchar"
							 << novo.nome_temp
							 << "[" << (novo.tam + 1) << "];"
							 << "\n\tstrcpy("
							 << novo.nome_temp + ", "
							 << (yyvsp[(1) - (3)]).label
							 << ");"
							 << "\n\tstrcat("
							 << novo.nome_temp + ", "
							 << (yyvsp[(3) - (3)]).label
							 << ");";

						(yyval).traducao = trad.str();
						(yyval).tipo = "string";
						(yyval).tam = novo.tam + 1;
						(yyval).label = novo.nome_temp;


					} else {
						cout << "Erro na linha " << nLinha <<": Tipo nao combinan ------ Erro 01 producao: E ARIT_SO_SUB E_TEMP" << endl << endl;
						exit(1);
					}

					(yyval).tipo = cast.resultOperacao;
				} else if((yyvsp[(1) - (3)]).tipo == (yyvsp[(3) - (3)]).tipo){
					(yyval).traducao = (yyvsp[(3) - (3)]).traducao + "\t" + (yyvsp[(1) - (3)]).traducao + 
					"\n\t" + (yyvsp[(1) - (3)]).tipo + " " + var_temp + " = " + 
					(yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).label + " " + (yyvsp[(3) - (3)]).label + ";";

				} else {
					cout << "Erro na linha " << nLinha <<": Tipo nao combinan------ Erro 02 producao:  E ARIT_SO_SUB E_TEMP" << endl << endl;
					exit(1);					
				}
			}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 547 "src/sintatica.y"
    {
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).tipo = (yyvsp[(1) - (1)]).tipo;
				(yyval).tam = (yyvsp[(1) - (1)]).tam;				
			}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 555 "src/sintatica.y"
    {
				string var_temp = createvar();
				(yyval).label = var_temp;

				string castChave = (yyvsp[(1) - (3)]).tipo + "_" + (yyvsp[(2) - (3)]).label + "_" + (yyvsp[(3) - (3)]).tipo;

				if(map_cast.find(castChave) != map_cast.end()){
					tipo_cast cast = map_cast[castChave];

					if(cast.operando == 1){
						(yyval).traducao = (yyvsp[(3) - (3)]).traducao + "\t" + (yyvsp[(1) - (3)]).traducao + "\n\t" + "int" + " " 
							+ var_temp + " = " + "(" + (yyvsp[(3) - (3)]).tipo + ") " + (yyvsp[(1) - (3)]).label + " " 
								+ (yyvsp[(2) - (3)]).label + " " + (yyvsp[(3) - (3)]).label + ";";
					} else if(cast.operando == 2){
						(yyval).traducao = (yyvsp[(3) - (3)]).traducao + "\t" + (yyvsp[(1) - (3)]).traducao + "\n\t" + "int" + " " 
							+ var_temp + " = " + (yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).label + " " 
								+ "(" + (yyvsp[(1) - (3)]).tipo + ") " + (yyvsp[(3) - (3)]).label + ";";
					} else {
						cout << "Erro na linha " << nLinha <<": Tipo nao combinan ----- Erro 01 producao: E_TEMP ARIT_MU_DI VAL" << endl << endl;
						exit(1);
					}

					(yyval).tipo = cast.resultOperacao;
				} else if((yyvsp[(1) - (3)]).tipo == (yyvsp[(3) - (3)]).tipo){
					(yyval).traducao = (yyvsp[(3) - (3)]).traducao + "\t" + (yyvsp[(1) - (3)]).traducao + 
						"\n\t" + (yyvsp[(1) - (3)]).tipo + " " + var_temp + " = " + 
							(yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).label + " " + (yyvsp[(3) - (3)]).label + ";";
				} else {
					cout << "Erro na linha " << nLinha <<": Tipo nao combinan ----- Erro 02 producao: E_TEMP ARIT_MU_DI VAL" << endl << endl;
					exit(1);					
				}
			}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 587 "src/sintatica.y"
    {
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).tipo = (yyvsp[(1) - (1)]).tipo;
				(yyval).tam = (yyvsp[(1) - (1)]).tam;				
			}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 594 "src/sintatica.y"
    {
				string var_temp = createvar();

				if((yyvsp[(2) - (2)]).tipo == "boolean"){
					(yyval).traducao = (yyvsp[(2) - (2)]).traducao + "\n\t" + "int " + 
						var_temp + " = " + (yyvsp[(1) - (2)]).traducao + (yyvsp[(2) - (2)]).label + ";";
				} else {
					cout << "Erro na linha " << nLinha <<": Tipo nao combinan ----- Erro producao: TK_NOT NOT" << endl << endl;
					exit(1);
				}
			}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 605 "src/sintatica.y"
    {
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).tipo = (yyvsp[(1) - (1)]).tipo;
				(yyval).tam = (yyvsp[(1) - (1)]).tam;
			}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 612 "src/sintatica.y"
    {
				(yyval).label = (yyvsp[(2) - (3)]).label;
				(yyval).traducao = (yyvsp[(2) - (3)]).traducao;
				(yyval).tipo = (yyvsp[(2) - (3)]).tipo;
			}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 617 "src/sintatica.y"
    {
				(yyval).label = (yyvsp[(1) - (1)]).traducao;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).tipo = (yyvsp[(1) - (1)]).tipo;
			}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 622 "src/sintatica.y"
    {
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = "";
				(yyval).tipo = (yyvsp[(1) - (1)]).tipo;
			}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 627 "src/sintatica.y"
    {
				if(!findVar((yyvsp[(1) - (1)]).label)){					
					cout << "\tErro linha " << nLinha << " ----- Variavel NAO declarada! ----- Erro producao: val '(' OP_OR ')' " << endl;
					//exit(1); 
				} 

				inf_variaveis var = retornaVarDoEscopo((yyvsp[(1) - (1)]).label);

				(yyval).label = var.nome_temp;
				(yyval).traducao = (yyval).label;
				(yyval).tipo = var.tipo;

			}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 640 "src/sintatica.y"
    {
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = "";
				(yyval).tipo = (yyvsp[(1) - (1)]).tipo;	
			}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 645 "src/sintatica.y"
    {
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = "";
				(yyval).tipo = (yyvsp[(1) - (1)]).tipo;	
			}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 650 "src/sintatica.y"
    {
				(yyval).label = "\"" + (yyvsp[(1) - (1)]).label + "\"";
				(yyval).traducao = "";
				(yyval).tipo = (yyvsp[(1) - (1)]).tipo;
				(yyval).tam = (yyvsp[(1) - (1)]).tam;
			}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 658 "src/sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).label = (yyvsp[(1) - (1)]).label;
			}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 663 "src/sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).label = (yyvsp[(1) - (1)]).label;
			}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 670 "src/sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).label = (yyvsp[(1) - (1)]).label;
			}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 675 "src/sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).label = (yyvsp[(1) - (1)]).label;
			}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 680 "src/sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).label = (yyvsp[(1) - (1)]).label;
			}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 685 "src/sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).label = (yyvsp[(1) - (1)]).label;
			}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 689 "src/sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).label = (yyvsp[(1) - (1)]).label;
			}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 693 "src/sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).label = (yyvsp[(1) - (1)]).label;
			}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 697 "src/sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).label = (yyvsp[(1) - (1)]).label;
			}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 701 "src/sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).label = (yyvsp[(1) - (1)]).label;
			}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 705 "src/sintatica.y"
    {
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).label = (yyvsp[(1) - (1)]).label;
			}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 711 "src/sintatica.y"
    {
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).tipo = "int";
				(yyval).tam = (yyvsp[(1) - (1)]).tam;
			}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 717 "src/sintatica.y"
    {
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).tipo = "float";
				(yyval).tam = (yyvsp[(1) - (1)]).tam;
			}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 723 "src/sintatica.y"
    {
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).tipo = "double";
				(yyval).tam = (yyvsp[(1) - (1)]).tam;
			}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 729 "src/sintatica.y"
    {
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).tipo = "string";
				(yyval).tam = (yyvsp[(1) - (1)]).tam;
			}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 735 "src/sintatica.y"
    {
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).tipo = "char";
				(yyval).tam = (yyvsp[(1) - (1)]).tam;
			}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 741 "src/sintatica.y"
    {
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).tipo = "boolean";
				(yyval).tam = (yyvsp[(1) - (1)]).tam;
			}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 747 "src/sintatica.y"
    {
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).traducao = (yyvsp[(1) - (1)]).traducao;
				(yyval).tipo = "long";
				(yyval).tam = (yyvsp[(1) - (1)]).tam;
			}
    break;



/* Line 1806 of yacc.c  */
#line 2583 "bin/y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 754 "src/sintatica.y"


#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	yyparse();

	return 0;
}

void yyerror( string MSG ){
	cout << MSG << endl;
	exit (0);
}

string createvar(){
	stringstream a;
	contadorVar = contadorVar + 1;
	a << "CompilerVarTemp_" << contadorVar;
	return a.str();
}

void criaEscopo(){	
	map<string, inf_variaveis> mapTemp;

	vecEscopo.push_back(mapTemp);
}

void finalizaEscopo(){
	vecEscopo.pop_back();
}


map<string, inf_variaveis> getEscopo(){
	return vecEscopo.back();
}

void insereVarNoEscopo(string nome, inf_variaveis var){
	vecEscopo.back()[nome] = var;

	//map<string, inf_variaveis> mapTemp;
	//mapTemp = getEscopo();

	//mapTemp[var.nome_temp] = var;

}

bool findVar(string nome){
	//for (int i = vecEscopo.size()-1; i >= 0; i--) {
	for (int i = 0; i < vecEscopo.size(); i++){
		map<string, inf_variaveis> mapTemp;
		mapTemp = vecEscopo[i];

		if(mapTemp.find(nome) != mapTemp.end())
			return true;
	}
	return false;
}

inf_variaveis retornaVarDoEscopo(string nome){
	if(findVar(nome)){
		for(int i = 0; i < vecEscopo.size(); i++){
			map<string, inf_variaveis> mapTemp;
			mapTemp = vecEscopo[i];
			
			if(mapTemp.find(nome) != mapTemp.end())
				return mapTemp[nome];
		}
	} else {
		cout << "Erro na linda: " << nLinha << ", variavel nao encontrada" ;
		exit(1);
	}

}

inf_label creatLabel(string estrutura){	
	contadorLabel = contadorLabel + 1;

	stringstream ini;
	ini << "label_" << estrutura << "_ini_" << contadorLabel;

	stringstream meio;
	meio << "label_" << estrutura << "_meio_" << contadorLabel;

	stringstream fim;
	fim << "label_" << estrutura << "_fim_" << contadorLabel;

	inf_label infLabel = {ini.str(), meio.str(), fim.str()};

	vecLabel.push_back(infLabel);	

	return infLabel;
}


map<string, tipo_cast> gera_map_cast(){
	map<string, tipo_cast> tab;

	tipo_cast cast_1 = {"float", 1};
	tab["int_+_float"] = cast_1;
	tab["int_-_float"] = cast_1;
	tab["int_*_float"] = cast_1;
	tab["int_/_float"] = cast_1;

	tipo_cast cast_2 = {"float", 2};
	tab["float_+_int"] = cast_2;
	tab["float_-_int"] = cast_2;
	tab["float_*_int"] = cast_2;
	tab["float_/_int"] = cast_2;
	tab["float_=_int"] = cast_2;

	tipo_cast cast_3 = {"long", 1};
	tab["int_+_long"] = cast_3;
	tab["int_-_long"] = cast_3;
	tab["int_*_long"] = cast_3;
	tab["int_/_long"] = cast_3;	
	tab["int_%_long"] = cast_3;

	tipo_cast cast_4 = {"long", 2};
	tab["long_+_int"] = cast_4;
	tab["long_-_int"] = cast_4;
	tab["long_*_int"] = cast_4;
	tab["long_/_int"] = cast_4;
	tab["long_%_int"] = cast_4;
	tab["long_=_int"] = cast_4;

	tipo_cast cast_5 = {"double", 1};
	tab["int_+_double"] = cast_5;
	tab["int_-_double"] = cast_5;
	tab["int_*_double"] = cast_5;
	tab["int_/_double"] = cast_5;
	tab["long_+_double"] = cast_5;
	tab["long_-_double"] = cast_5;
	tab["long_*_double"] = cast_5;
	tab["long_/_double"] = cast_5;

	tipo_cast cast_6 = {"double", 2};
	tab["double_+_int"] = cast_6;
	tab["double_-_int"] = cast_6;
	tab["double_*_int"] = cast_6;
	tab["double_/_int"] = cast_6;
	tab["double_=_int"] = cast_6;
	tab["double_+_long"] = cast_6;
	tab["double_-_long"] = cast_6;
	tab["double_*_long"] = cast_6;
	tab["double_/_long"] = cast_6;


	tipo_cast cast_8 = {"boolean", 4};	
	tab["int_<_int"] = cast_8;
	tab["int_<_float"] = cast_8;
	tab["int_<_long"] = cast_8;
	tab["int_<_double"] = cast_8;
	tab["int_>_int"] = cast_8;
	tab["int_>_float"] = cast_8;
	tab["int_>_long"] = cast_8;
	tab["int_>_double"] = cast_8;
	tab["int_<=_int"] = cast_8;
	tab["int_<=_float"] = cast_8;
	tab["int_<=_long"] = cast_8;
	tab["int_<=_double"] = cast_8;
	tab["int_>=_int"] = cast_8;
	tab["int_>=_float"] = cast_8;
	tab["int_>=_long"] = cast_8;
	tab["int_>=_double"] = cast_8;
	tab["int_==_int"] = cast_8;
	tab["int_==_float"] = cast_8;
	tab["int_==_long"] = cast_8;
	tab["int_==_double"] = cast_8;

	tab["float_<_float"] = cast_8;
	tab["float_<_int"] = cast_8;
	tab["float_<_long"] = cast_8;
	tab["float_<_double"] = cast_8;
	tab["float_>_float"] = cast_8;
	tab["float_>_int"] = cast_8;
	tab["float_>_long"] = cast_8;
	tab["float_>_double"] = cast_8;
	tab["float_<=_float"] = cast_8;
	tab["float_<=_int"] = cast_8;
	tab["float_<=_long"] = cast_8;
	tab["float_<=_double"] = cast_8;
	tab["float_>=_float"] = cast_8;
	tab["float_>=_int"] = cast_8;
	tab["float_>=_long"] = cast_8;
	tab["float_>=_double"] = cast_8;
	tab["float_==_float"] = cast_8;
	tab["float_==_int"] = cast_8;
	tab["float_==_long"] = cast_8;
	tab["float_==_double"] = cast_8;

	tab["double_<_double"] = cast_8;
	tab["double_<_int"] = cast_8;
	tab["double_<_float"] = cast_8;
	tab["double_<_long"] = cast_8;
	tab["double_>_double"] = cast_8;
	tab["double_>_int"] = cast_8;
	tab["double_>_float"] = cast_8;
	tab["double_>_long"] = cast_8;
	tab["double_<=_double"] = cast_8;
	tab["double_<=_int"] = cast_8;
	tab["double_<=_float"] = cast_8;
	tab["double_<=_long"] = cast_8;
	tab["double_>=_double"] = cast_8;
	tab["double_>=_int"] = cast_8;
	tab["double_>=_float"] = cast_8;
	tab["double_>=_long"] = cast_8;
	tab["double_==_double"] = cast_8;
	tab["double_==_int"] = cast_8;
	tab["double_==_float"] = cast_8;
	tab["double_==_long"] = cast_8;

	tab["long_<_long"] = cast_8;
	tab["long_<_int"] = cast_8;
	tab["long_<_float"] = cast_8;
	tab["long_<_double"] = cast_8;
	tab["long_>_long"] = cast_8;
	tab["long_>_int"] = cast_8;
	tab["long_>_float"] = cast_8;
	tab["long_>_double"] = cast_8;
	tab["long_<=_long"] = cast_8;
	tab["long_<=_int"] = cast_8;
	tab["long_<=_float"] = cast_8;
	tab["long_<=_double"] = cast_8;
	tab["long_>=_long"] = cast_8;
	tab["long_>=_int"] = cast_8;
	tab["long_>=_float"] = cast_8;
	tab["long_>=_double"] = cast_8;
	tab["long_==_long"] = cast_8;
	tab["long_==_int"] = cast_8;
	tab["long_==_float"] = cast_8;
	tab["long_==_double"] = cast_8;

	tab["string_==_string"] = cast_8;

	tipo_cast cast_9 = {"string", -1};
	tab["string_+_string"] = cast_9;
	tab["string_+_int"] = cast_9;
	tab["string_+_double"] = cast_9;
	tab["string_+_long"] = cast_9;
	tab["string_+_boolean"] = cast_9;
	tab["int_+_string"] = cast_9;
	tab["double_+_string"] = cast_9;
	tab["long_+_string"] = cast_9;
	tab["boolean_+_string"] = cast_9;

	tipo_cast cast_0 = {"null", -1};
	tab["int_%_float"] = cast_0;
	tab["int_%_float"] = cast_0;
	tab["int_%_doubla"] = cast_0;
	tab["int_%_double"] = cast_0;
	tab["float_%_int"] = cast_0;
	tab["float_%_float"] = cast_0;
	tab["boolean_+_boolean"] = cast_0;
	tab["boolean_-_boolean"] = cast_0;
	tab["boolean_*_boolean"] = cast_0;
	tab["boolean_/_boolean"] = cast_0;
	tab["boolean_=_boolean"] = cast_0;
	tab["boolean_%_boolean"] = cast_0;
	tab["long_%_double"] = cast_0;
	tab["double_%_double"] = cast_0;
	tab["int_or_int"] = cast_0;
	tab["float_or_float"] = cast_0;
	tab["double_or_double"] = cast_0;
	tab["long_or_long"] = cast_0;
	tab["int_and_int"] = cast_0;
	tab["float_and_float"] = cast_0;
	tab["double_and_double"] = cast_0;
	tab["long_and_long"] = cast_0;


    return tab; 
}
