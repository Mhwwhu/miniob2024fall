/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.hpp"
#include "sql/parser/lex_sql.h"
#include "sql/expr/expression.h"
#include "common/type/date_type.h"

using namespace std;

string token_name(const char *sql_string, YYLTYPE *llocp)
{
  return string(sql_string + llocp->first_column, llocp->last_column - llocp->first_column + 1);
}

int yyerror(YYLTYPE *llocp, const char *sql_string, ParsedSqlResult *sql_result, yyscan_t scanner, const char *msg)
{
  std::unique_ptr<ParsedSqlNode> error_sql_node = std::make_unique<ParsedSqlNode>(SCF_ERROR);
  error_sql_node->error.error_msg = msg;
  error_sql_node->error.line = llocp->first_line;
  error_sql_node->error.column = llocp->first_column;
  sql_result->add_sql_node(std::move(error_sql_node));
  return 0;
}

ArithmeticExpr *create_arithmetic_expression(ArithmeticExpr::Type type,
                                             Expression *left,
                                             Expression *right,
                                             const char *sql_string,
                                             YYLTYPE *llocp)
{
  ArithmeticExpr *expr = new ArithmeticExpr(type, left, right);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}

UnboundAggregateExpr *create_aggregate_expression(const char *aggregate_name,
                                           Expression *child,
                                           const char *sql_string,
                                           YYLTYPE *llocp)
{
  UnboundAggregateExpr *expr = new UnboundAggregateExpr(aggregate_name, child);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}


#line 126 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "yacc_sql.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_BY = 4,                         /* BY  */
  YYSYMBOL_CREATE = 5,                     /* CREATE  */
  YYSYMBOL_DROP = 6,                       /* DROP  */
  YYSYMBOL_GROUP = 7,                      /* GROUP  */
  YYSYMBOL_TABLE = 8,                      /* TABLE  */
  YYSYMBOL_TABLES = 9,                     /* TABLES  */
  YYSYMBOL_INDEX = 10,                     /* INDEX  */
  YYSYMBOL_CALC = 11,                      /* CALC  */
  YYSYMBOL_SELECT = 12,                    /* SELECT  */
  YYSYMBOL_DESC = 13,                      /* DESC  */
  YYSYMBOL_SHOW = 14,                      /* SHOW  */
  YYSYMBOL_SYNC = 15,                      /* SYNC  */
  YYSYMBOL_INSERT = 16,                    /* INSERT  */
  YYSYMBOL_DELETE = 17,                    /* DELETE  */
  YYSYMBOL_UPDATE = 18,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 19,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 20,                    /* RBRACE  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 22,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 23,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 24,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 25,                     /* INT_T  */
  YYSYMBOL_STRING_T = 26,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 27,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 28,                    /* DATE_T  */
  YYSYMBOL_HELP = 29,                      /* HELP  */
  YYSYMBOL_EXIT = 30,                      /* EXIT  */
  YYSYMBOL_DOT = 31,                       /* DOT  */
  YYSYMBOL_INTO = 32,                      /* INTO  */
  YYSYMBOL_VALUES = 33,                    /* VALUES  */
  YYSYMBOL_FROM = 34,                      /* FROM  */
  YYSYMBOL_WHERE = 35,                     /* WHERE  */
  YYSYMBOL_AND = 36,                       /* AND  */
  YYSYMBOL_SET = 37,                       /* SET  */
  YYSYMBOL_ON = 38,                        /* ON  */
  YYSYMBOL_LOAD = 39,                      /* LOAD  */
  YYSYMBOL_DATA = 40,                      /* DATA  */
  YYSYMBOL_INFILE = 41,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 42,                   /* EXPLAIN  */
  YYSYMBOL_STORAGE = 43,                   /* STORAGE  */
  YYSYMBOL_FORMAT = 44,                    /* FORMAT  */
  YYSYMBOL_EQ = 45,                        /* EQ  */
  YYSYMBOL_LT = 46,                        /* LT  */
  YYSYMBOL_GT = 47,                        /* GT  */
  YYSYMBOL_LE = 48,                        /* LE  */
  YYSYMBOL_GE = 49,                        /* GE  */
  YYSYMBOL_NE = 50,                        /* NE  */
  YYSYMBOL_INNER = 51,                     /* INNER  */
  YYSYMBOL_JOIN = 52,                      /* JOIN  */
  YYSYMBOL_UNIQUE = 53,                    /* UNIQUE  */
  YYSYMBOL_NUMBER = 54,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 55,                     /* FLOAT  */
  YYSYMBOL_ID = 56,                        /* ID  */
  YYSYMBOL_SSS = 57,                       /* SSS  */
  YYSYMBOL_DATE = 58,                      /* DATE  */
  YYSYMBOL_59_ = 59,                       /* '+'  */
  YYSYMBOL_60_ = 60,                       /* '-'  */
  YYSYMBOL_61_ = 61,                       /* '*'  */
  YYSYMBOL_62_ = 62,                       /* '/'  */
  YYSYMBOL_UMINUS = 63,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_commands = 65,                  /* commands  */
  YYSYMBOL_command_wrapper = 66,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 67,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 68,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 69,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 70,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 71,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 72,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 73,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 74,          /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 75,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 76,         /* create_index_stmt  */
  YYSYMBOL_attr_list = 77,                 /* attr_list  */
  YYSYMBOL_drop_index_stmt = 78,           /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 79,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 80,             /* attr_def_list  */
  YYSYMBOL_attr_def = 81,                  /* attr_def  */
  YYSYMBOL_number = 82,                    /* number  */
  YYSYMBOL_type = 83,                      /* type  */
  YYSYMBOL_insert_stmt = 84,               /* insert_stmt  */
  YYSYMBOL_value_list = 85,                /* value_list  */
  YYSYMBOL_value = 86,                     /* value  */
  YYSYMBOL_storage_format = 87,            /* storage_format  */
  YYSYMBOL_delete_stmt = 88,               /* delete_stmt  */
  YYSYMBOL_update_stmt = 89,               /* update_stmt  */
  YYSYMBOL_select_stmt = 90,               /* select_stmt  */
  YYSYMBOL_join = 91,                      /* join  */
  YYSYMBOL_calc_stmt = 92,                 /* calc_stmt  */
  YYSYMBOL_expression_list = 93,           /* expression_list  */
  YYSYMBOL_expression = 94,                /* expression  */
  YYSYMBOL_rel_attr = 95,                  /* rel_attr  */
  YYSYMBOL_where = 96,                     /* where  */
  YYSYMBOL_condition_list = 97,            /* condition_list  */
  YYSYMBOL_condition = 98,                 /* condition  */
  YYSYMBOL_comp_op = 99,                   /* comp_op  */
  YYSYMBOL_group_by = 100,                 /* group_by  */
  YYSYMBOL_load_data_stmt = 101,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 102,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 103,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 104             /* opt_semicolon  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   170

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    61,    59,     2,    60,     2,    62,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    63
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   210,   210,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   241,   247,   252,   258,   264,   270,   276,
     283,   289,   297,   309,   323,   329,   338,   348,   372,   375,
     388,   396,   406,   409,   410,   411,   412,   415,   432,   435,
     446,   450,   454,   460,   475,   478,   485,   497,   513,   538,
     544,   554,   566,   583,   592,   597,   608,   611,   614,   617,
     620,   624,   627,   632,   638,   645,   650,   684,   687,   693,
     696,   701,   708,   720,   732,   744,   759,   760,   761,   762,
     763,   764,   770,   775,   788,   796,   806,   807
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "BY",
  "CREATE", "DROP", "GROUP", "TABLE", "TABLES", "INDEX", "CALC", "SELECT",
  "DESC", "SHOW", "SYNC", "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE",
  "COMMA", "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T",
  "FLOAT_T", "DATE_T", "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM",
  "WHERE", "AND", "SET", "ON", "LOAD", "DATA", "INFILE", "EXPLAIN",
  "STORAGE", "FORMAT", "EQ", "LT", "GT", "LE", "GE", "NE", "INNER", "JOIN",
  "UNIQUE", "NUMBER", "FLOAT", "ID", "SSS", "DATE", "'+'", "'-'", "'*'",
  "'/'", "UMINUS", "$accept", "commands", "command_wrapper", "exit_stmt",
  "help_stmt", "sync_stmt", "begin_stmt", "commit_stmt", "rollback_stmt",
  "drop_table_stmt", "show_tables_stmt", "desc_table_stmt",
  "create_index_stmt", "attr_list", "drop_index_stmt", "create_table_stmt",
  "attr_def_list", "attr_def", "number", "type", "insert_stmt",
  "value_list", "value", "storage_format", "delete_stmt", "update_stmt",
  "select_stmt", "join", "calc_stmt", "expression_list", "expression",
  "rel_attr", "where", "condition_list", "condition", "comp_op",
  "group_by", "load_data_stmt", "explain_stmt", "set_variable_stmt",
  "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-136)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      78,    -2,     2,     6,     6,   -51,     0,  -136,   -15,    -1,
     -20,  -136,  -136,  -136,  -136,  -136,   -10,     7,    78,    48,
      47,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,     9,    24,    46,    25,    26,     6,  -136,  -136,    54,
    -136,  -136,     6,  -136,  -136,  -136,    17,  -136,    52,  -136,
    -136,    42,    43,    67,    60,    65,  -136,  -136,  -136,  -136,
      95,    80,    63,  -136,    83,    -7,    66,  -136,     6,     6,
       6,     6,     6,    68,    90,    81,    69,    14,    70,    72,
      73,    88,    79,  -136,  -136,  -136,   -47,   -47,  -136,  -136,
      85,   -17,   115,    55,  -136,    92,  -136,   106,     1,   118,
     121,    86,  -136,    89,    68,    91,  -136,    14,   -26,   -26,
    -136,   108,    14,   137,  -136,  -136,  -136,  -136,   127,    72,
     128,    93,   131,    96,   -14,    97,  -136,   126,  -136,  -136,
    -136,  -136,  -136,  -136,    55,    55,    55,    81,    98,   101,
     118,   113,  -136,    11,    93,   119,   120,    14,   139,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,   140,  -136,   107,
    -136,  -136,   105,    21,    55,    55,   126,  -136,  -136,   117,
    -136,  -136,  -136,  -136,  -136,   109,  -136
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,    26,    27,    28,    24,    23,     0,     0,     0,     0,
      96,    22,    21,    14,    15,    16,    17,     9,    10,    11,
      12,    13,     8,     5,     7,     6,     4,     3,    18,    19,
      20,     0,     0,     0,     0,     0,     0,    50,    51,    75,
      52,    53,     0,    74,    72,    63,    64,    73,     0,    31,
      30,     0,     0,     0,     0,     0,    94,     1,    97,     2,
       0,     0,     0,    29,     0,     0,     0,    71,     0,     0,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,    70,    76,    65,    66,    67,    68,    69,
      59,    77,     0,    79,    56,     0,    95,     0,     0,    38,
       0,     0,    36,     0,     0,     0,    92,     0,     0,     0,
      78,    80,     0,     0,    43,    44,    45,    46,    41,     0,
       0,     0,     0,     0,    62,     0,    58,    48,    86,    87,
      88,    89,    90,    91,     0,     0,    79,    77,     0,     0,
      38,    54,    34,     0,     0,     0,     0,     0,     0,    83,
      85,    82,    84,    81,    57,    93,    42,     0,    39,     0,
      37,    32,     0,     0,    79,    79,    48,    47,    40,     0,
      35,    33,    60,    61,    49,     0,    55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,   145,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,    10,  -136,  -136,    16,    38,  -136,  -136,
    -136,    -8,   -87,  -136,  -136,  -136,  -136,    56,  -136,    -3,
      51,  -101,   -98,  -135,  -136,    50,  -136,  -136,  -136,  -136,
    -136
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   153,    31,    32,   130,   109,   167,   128,
      33,   158,    54,   170,    34,    35,    36,   101,    37,    55,
      56,    57,   104,   120,   121,   144,   136,    38,    39,    40,
      69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     106,    58,   119,   116,   114,    59,    41,   114,    42,    60,
      44,   163,    45,    93,    81,    82,   118,    61,   103,   138,
     139,   140,   141,   142,   143,    46,   124,   125,   126,   127,
     137,   171,   172,    62,   115,   147,    63,   115,    78,   182,
     183,   181,   172,   160,   162,   119,    64,    65,    67,   164,
      68,    43,    79,    80,    81,    82,    72,   159,   161,   118,
      47,    48,    49,    50,    51,    70,    52,    53,    47,    48,
     176,    50,    51,   119,   119,    95,    79,    80,    81,    82,
      71,    73,    74,     1,     2,    76,    83,   118,   118,     3,
       4,     5,     6,     7,     8,     9,    10,    75,    84,    85,
      11,    12,    13,    77,    86,    87,    88,    14,    15,    47,
      48,    49,    50,    51,    89,    16,   103,    17,    90,    91,
      18,    92,    94,   102,   100,   105,   111,   107,   108,   110,
      96,    97,    98,    99,   117,   112,   113,   122,   123,   129,
     131,   133,   132,   135,   146,   148,   149,   157,   151,   152,
     154,   179,   155,   156,   165,   166,   169,   174,   175,   177,
     178,   180,   185,    66,   173,   186,   168,   150,   184,   145,
     134
};

static const yytype_uint8 yycheck[] =
{
      87,     4,   103,   101,    21,    56,     8,    21,    10,     9,
       8,   146,    10,    20,    61,    62,   103,    32,    35,    45,
      46,    47,    48,    49,    50,    19,    25,    26,    27,    28,
     117,    20,    21,    34,    51,   122,    56,    51,    21,   174,
     175,    20,    21,   144,   145,   146,    56,    40,     0,   147,
       3,    53,    59,    60,    61,    62,    10,   144,   145,   146,
      54,    55,    56,    57,    58,    56,    60,    61,    54,    55,
     157,    57,    58,   174,   175,    78,    59,    60,    61,    62,
      56,    56,    56,     5,     6,    31,    34,   174,   175,    11,
      12,    13,    14,    15,    16,    17,    18,    46,    56,    56,
      22,    23,    24,    52,    37,    45,    41,    29,    30,    54,
      55,    56,    57,    58,    19,    37,    35,    39,    38,    56,
      42,    38,    56,    33,    56,    56,    38,    57,    56,    56,
      79,    80,    81,    82,    19,    56,    51,    45,    32,    21,
      19,    52,    56,    52,    36,     8,    19,    21,    20,    56,
      19,    44,    56,    56,    56,    54,    43,    38,    38,    20,
      20,    56,    45,    18,   154,    56,   150,   129,   176,   119,
     114
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,    11,    12,    13,    14,    15,    16,    17,
      18,    22,    23,    24,    29,    30,    37,    39,    42,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    78,    79,    84,    88,    89,    90,    92,   101,   102,
     103,     8,    10,    53,     8,    10,    19,    54,    55,    56,
      57,    58,    60,    61,    86,    93,    94,    95,    93,    56,
       9,    32,    34,    56,    56,    40,    66,     0,     3,   104,
      56,    56,    10,    56,    56,    94,    31,    94,    21,    59,
      60,    61,    62,    34,    56,    56,    37,    45,    41,    19,
      38,    56,    38,    20,    56,    93,    94,    94,    94,    94,
      56,    91,    33,    35,    96,    56,    86,    57,    56,    81,
      56,    38,    56,    51,    21,    51,    96,    19,    86,    95,
      97,    98,    45,    32,    25,    26,    27,    28,    83,    21,
      80,    19,    56,    52,    91,    52,   100,    86,    45,    46,
      47,    48,    49,    50,    99,    99,    36,    86,     8,    19,
      81,    20,    56,    77,    19,    56,    56,    21,    85,    86,
      95,    86,    95,    97,    96,    56,    54,    82,    80,    43,
      87,    20,    21,    77,    38,    38,    86,    20,    20,    44,
      56,    20,    97,    97,    85,    45,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    76,    77,    77,    78,    79,    80,    80,
      81,    81,    82,    83,    83,    83,    83,    84,    85,    85,
      86,    86,    86,    86,    87,    87,    88,    89,    90,    91,
      91,    91,    91,    92,    93,    93,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    95,    95,    96,    96,    97,
      97,    97,    98,    98,    98,    98,    99,    99,    99,    99,
      99,    99,   100,   101,   102,   103,   104,   104
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     2,     8,     9,     1,     3,     5,     8,     0,     3,
       5,     2,     1,     1,     1,     1,     1,     8,     0,     3,
       1,     1,     1,     1,     0,     4,     4,     7,     6,     1,
       6,     6,     3,     2,     1,     3,     3,     3,     3,     3,
       3,     2,     1,     1,     1,     1,     3,     0,     2,     0,
       1,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     0,     7,     2,     4,     0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (&yylloc, sql_string, sql_result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, sql_string, sql_result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, sql_string, sql_result, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), sql_string, sql_result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, sql_string, sql_result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_ID: /* ID  */
#line 198 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
            {
	free(((*yyvaluep).string));
}
#line 1455 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
        break;

    case YYSYMBOL_SSS: /* SSS  */
#line 198 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
            {
	free(((*yyvaluep).string));
}
#line 1463 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
        break;

    case YYSYMBOL_DATE: /* DATE  */
#line 198 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
            {
	free(((*yyvaluep).string));
}
#line 1471 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
        break;

    case YYSYMBOL_value: /* value  */
#line 195 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
            {
	delete ((*yyvaluep).value);
}
#line 1479 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
        break;

    case YYSYMBOL_storage_format: /* storage_format  */
#line 198 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
            {
	free(((*yyvaluep).string));
}
#line 1487 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
        break;

    case YYSYMBOL_expression_list: /* expression_list  */
#line 201 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
            {
	delete ((*yyvaluep).expression_list);
}
#line 1495 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
        break;

    case YYSYMBOL_group_by: /* group_by  */
#line 201 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
            {
	delete ((*yyvaluep).expression_list);
}
#line 1503 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* commands: command_wrapper opt_semicolon  */
#line 211 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1812 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 23: /* exit_stmt: EXIT  */
#line 241 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1821 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 24: /* help_stmt: HELP  */
#line 247 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1829 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 25: /* sync_stmt: SYNC  */
#line 252 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1837 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 26: /* begin_stmt: TRX_BEGIN  */
#line 258 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1845 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 27: /* commit_stmt: TRX_COMMIT  */
#line 264 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1853 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 28: /* rollback_stmt: TRX_ROLLBACK  */
#line 270 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1861 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 29: /* drop_table_stmt: DROP TABLE ID  */
#line 276 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1871 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 30: /* show_tables_stmt: SHOW TABLES  */
#line 283 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1879 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 31: /* desc_table_stmt: DESC ID  */
#line 289 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1889 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 32: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE attr_list RBRACE  */
#line 298 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-5].string);
      create_index.relation_name = (yyvsp[-3].string);
      create_index.attribute_names.swap(*(yyvsp[-1].attr_name_list));
	  create_index.unique = false;
      free((yyvsp[-5].string));
      free((yyvsp[-3].string));
	  delete (yyvsp[-1].attr_name_list);
    }
#line 1905 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 33: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE attr_list RBRACE  */
#line 310 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
        {
	  (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-5].string);
      create_index.relation_name = (yyvsp[-3].string);
      create_index.attribute_names.swap(*(yyvsp[-1].attr_name_list));
	  create_index.unique = true;
      free((yyvsp[-5].string));
      free((yyvsp[-3].string));
	  delete (yyvsp[-1].attr_name_list);
	}
#line 1921 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 34: /* attr_list: ID  */
#line 324 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
        {
		(yyval.attr_name_list) = new std::vector<std::string>();
		(yyval.attr_name_list)->push_back((yyvsp[0].string));
		free((yyvsp[0].string));
	}
#line 1931 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 35: /* attr_list: attr_list COMMA ID  */
#line 330 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
        {
		(yyval.attr_name_list) = (yyvsp[-2].attr_name_list);
		(yyval.attr_name_list)->push_back((yyvsp[0].string));
		free((yyvsp[0].string));
	}
#line 1941 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 36: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 339 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 1953 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 37: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE storage_format  */
#line 349 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-5].string);
      free((yyvsp[-5].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-2].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
        delete src_attrs;
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-3].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-3].attr_info);
      if ((yyvsp[0].string) != nullptr) {
        create_table.storage_format = (yyvsp[0].string);
        free((yyvsp[0].string));
      }
    }
#line 1978 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 38: /* attr_def_list: %empty  */
#line 372 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 1986 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 39: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 376 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2000 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 40: /* attr_def: ID type LBRACE number RBRACE  */
#line 389 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-3].number);
      (yyval.attr_info)->name = (yyvsp[-4].string);
      (yyval.attr_info)->length = (yyvsp[-1].number);
      free((yyvsp[-4].string));
    }
#line 2012 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 41: /* attr_def: ID type  */
#line 397 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[0].number);
      (yyval.attr_info)->name = (yyvsp[-1].string);
      (yyval.attr_info)->length = 4;
      free((yyvsp[-1].string));
    }
#line 2024 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 42: /* number: NUMBER  */
#line 406 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2030 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 43: /* type: INT_T  */
#line 409 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::INTS); }
#line 2036 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 44: /* type: STRING_T  */
#line 410 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::CHARS); }
#line 2042 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 45: /* type: FLOAT_T  */
#line 411 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::FLOATS); }
#line 2048 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 46: /* type: DATE_T  */
#line 412 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
                   { (yyval.number) = static_cast<int>(AttrType::DATES); }
#line 2054 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 47: /* insert_stmt: INSERT INTO ID VALUES LBRACE value value_list RBRACE  */
#line 416 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-5].string);
      if ((yyvsp[-1].value_list) != nullptr) {
        (yyval.sql_node)->insertion.values.swap(*(yyvsp[-1].value_list));
        delete (yyvsp[-1].value_list);
      }
      (yyval.sql_node)->insertion.values.emplace_back(*(yyvsp[-2].value));
      std::reverse((yyval.sql_node)->insertion.values.begin(), (yyval.sql_node)->insertion.values.end());
      delete (yyvsp[-2].value);
      free((yyvsp[-5].string));
    }
#line 2071 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 48: /* value_list: %empty  */
#line 432 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2079 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 49: /* value_list: COMMA value value_list  */
#line 435 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2093 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 50: /* value: NUMBER  */
#line 446 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2102 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 51: /* value: FLOAT  */
#line 450 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2111 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 52: /* value: SSS  */
#line 454 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2122 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 53: /* value: DATE  */
#line 460 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
              {
		char* tmp = common::substr((yyvsp[0].string), 1, strlen((yyvsp[0].string)) - 2);
		int date_i;
		if(DateType::str_to_date(tmp, date_i)) {
			(yyval.value) = new Value(AttrType::DATES, (char*)&date_i, 4);
		}
		else {
			(yyval.value) = new Value(tmp);
		}
		free(tmp);
		free((yyvsp[0].string));
	}
#line 2139 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 54: /* storage_format: %empty  */
#line 475 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.string) = nullptr;
    }
#line 2147 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 55: /* storage_format: STORAGE FORMAT EQ ID  */
#line 479 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2155 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 56: /* delete_stmt: DELETE FROM ID where  */
#line 486 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2169 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 57: /* update_stmt: UPDATE ID SET ID EQ value where  */
#line 498 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_UPDATE);
      (yyval.sql_node)->update.relation_name = (yyvsp[-5].string);
      (yyval.sql_node)->update.attribute_name = (yyvsp[-3].string);
      (yyval.sql_node)->update.value = *(yyvsp[-1].value);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->update.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-5].string));
      free((yyvsp[-3].string));
	  delete (yyvsp[-1].value);
    }
#line 2187 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 58: /* select_stmt: SELECT expression_list FROM join where group_by  */
#line 514 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-4].expression_list) != nullptr) {
        (yyval.sql_node)->selection.expressions.swap(*(yyvsp[-4].expression_list));
        delete (yyvsp[-4].expression_list);
      }

      if ((yyvsp[-2].join) != nullptr) {
        (yyval.sql_node)->selection.joinedRelations.reset((yyvsp[-2].join));
		(yyvsp[-2].join) = nullptr;
      }

      if ((yyvsp[-1].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-1].condition_list));
        delete (yyvsp[-1].condition_list);
      }

      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.sql_node)->selection.group_by.swap(*(yyvsp[0].expression_list));
        delete (yyvsp[0].expression_list);
      }
    }
#line 2214 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 59: /* join: ID  */
#line 539 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
        {
		(yyval.join) = new JoinSqlNode;
		(yyval.join)->tableNames.push_back((yyvsp[0].string));
		free((yyvsp[0].string));
	}
#line 2224 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 60: /* join: ID INNER JOIN ID ON condition_list  */
#line 545 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
        {
		(yyval.join) = new JoinSqlNode;
		(yyval.join)->tableNames.push_back((yyvsp[-5].string));
		(yyval.join)->tableNames.push_back((yyvsp[-2].string));
		free((yyvsp[-5].string));
		free((yyvsp[-2].string));
		(yyval.join)->conditions.swap(*(yyvsp[0].condition_list));
		delete (yyvsp[0].condition_list);
	}
#line 2238 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 61: /* join: join INNER JOIN ID ON condition_list  */
#line 555 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
        {
		(yyval.join) = new JoinSqlNode;
		(yyval.join)->tableNames.swap((yyvsp[-5].join)->tableNames);
		(yyval.join)->tableNames.push_back((yyvsp[-2].string));
		free((yyvsp[-2].string));
		(yyval.join)->conditions.reserve((yyvsp[-5].join)->conditions.size() + (yyvsp[0].condition_list)->size());
		std::move((yyvsp[-5].join)->conditions.begin(), (yyvsp[-5].join)->conditions.end(), std::back_inserter((yyval.join)->conditions));
		std::move((yyvsp[0].condition_list)->begin(), (yyvsp[0].condition_list)->end(), std::back_inserter((yyval.join)->conditions));
		delete (yyvsp[0].condition_list);
		delete (yyvsp[-5].join);
	}
#line 2254 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 62: /* join: join COMMA join  */
#line 567 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
        {
		(yyval.join) = new JoinSqlNode;

		(yyval.join)->tableNames.reserve((yyvsp[-2].join)->tableNames.size() + (yyvsp[0].join)->tableNames.size());
		std::move((yyvsp[0].join)->tableNames.begin(), (yyvsp[0].join)->tableNames.end(), std::back_inserter((yyval.join)->tableNames));
		std::move((yyvsp[-2].join)->tableNames.begin(), (yyvsp[-2].join)->tableNames.end(), std::back_inserter((yyval.join)->tableNames));

		(yyval.join)->conditions.reserve((yyvsp[-2].join)->conditions.size() + (yyvsp[0].join)->conditions.size());
		std::move((yyvsp[0].join)->conditions.begin(), (yyvsp[0].join)->conditions.end(), std::back_inserter((yyval.join)->conditions));
		std::move((yyvsp[-2].join)->conditions.begin(), (yyvsp[-2].join)->conditions.end(), std::back_inserter((yyval.join)->conditions));

		delete (yyvsp[-2].join);
		delete (yyvsp[0].join);
	}
#line 2273 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 63: /* calc_stmt: CALC expression_list  */
#line 584 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2283 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 64: /* expression_list: expression  */
#line 593 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2292 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 65: /* expression_list: expression COMMA expression_list  */
#line 598 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      }
      (yyval.expression_list)->emplace((yyval.expression_list)->begin(), (yyvsp[-2].expression));
    }
#line 2305 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 66: /* expression: expression '+' expression  */
#line 608 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2313 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 67: /* expression: expression '-' expression  */
#line 611 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2321 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 68: /* expression: expression '*' expression  */
#line 614 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2329 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 69: /* expression: expression '/' expression  */
#line 617 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2337 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 70: /* expression: LBRACE expression RBRACE  */
#line 620 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
                               {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2346 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 71: /* expression: '-' expression  */
#line 624 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, (yyvsp[0].expression), nullptr, sql_string, &(yyloc));
    }
#line 2354 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 72: /* expression: value  */
#line 627 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2364 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 73: /* expression: rel_attr  */
#line 632 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
               {
      RelAttrSqlNode *node = (yyvsp[0].rel_attr);
      (yyval.expression) = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].rel_attr);
    }
#line 2375 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 74: /* expression: '*'  */
#line 638 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
          {
      (yyval.expression) = new StarExpr();
    }
#line 2383 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 75: /* rel_attr: ID  */
#line 645 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2393 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 76: /* rel_attr: ID DOT ID  */
#line 650 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2405 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 77: /* where: %empty  */
#line 684 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2413 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 78: /* where: WHERE condition_list  */
#line 687 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 2421 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 79: /* condition_list: %empty  */
#line 693 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2429 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 80: /* condition_list: condition  */
#line 696 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(*(yyvsp[0].condition));
      delete (yyvsp[0].condition);
    }
#line 2439 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 81: /* condition_list: condition AND condition_list  */
#line 701 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 2449 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 82: /* condition: rel_attr comp_op value  */
#line 709 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_value = *(yyvsp[0].value);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[0].value);
    }
#line 2465 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 83: /* condition: value comp_op value  */
#line 721 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-2].value);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_value = *(yyvsp[0].value);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].value);
      delete (yyvsp[0].value);
    }
#line 2481 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 84: /* condition: rel_attr comp_op rel_attr  */
#line 733 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
      (yyval.condition)->right_is_attr = 1;
      (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[0].rel_attr);
    }
#line 2497 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 85: /* condition: value comp_op rel_attr  */
#line 745 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-2].value);
      (yyval.condition)->right_is_attr = 1;
      (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].value);
      delete (yyvsp[0].rel_attr);
    }
#line 2513 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 86: /* comp_op: EQ  */
#line 759 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 2519 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 87: /* comp_op: LT  */
#line 760 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 2525 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 88: /* comp_op: GT  */
#line 761 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 2531 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 89: /* comp_op: LE  */
#line 762 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 2537 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 90: /* comp_op: GE  */
#line 763 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 2543 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 91: /* comp_op: NE  */
#line 764 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 2549 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 92: /* group_by: %empty  */
#line 770 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 2557 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 93: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 776 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 2571 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 94: /* explain_stmt: EXPLAIN command_wrapper  */
#line 789 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 2580 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;

  case 95: /* set_variable_stmt: SET ID EQ value  */
#line 797 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 2592 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"
    break;


#line 2596 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, sql_string, sql_result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, sql_string, sql_result, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 809 "/home/haowen/miniob2023/miniob2023fall/src/observer/sql/parser/yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, ParsedSqlResult *sql_result) {
  yyscan_t scanner;
  yylex_init(&scanner);
  scan_string(s, scanner);
  int result = yyparse(s, sql_result, scanner);
  yylex_destroy(scanner);
  return result;
}
