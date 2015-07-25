/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

extern YYSTYPE yylval;


