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
