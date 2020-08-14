%{
#include <bits/stdc++.h>
#include "ast.h"
#include "parser.tab.h"
#define YY_DECL extern "C" int yylex()
extern union Node yylval;
using namespace std;
int lineno = 0;

void yyerror (char const *s)
{
			
      fprintf (stderr, "%s at line number -> %d\nNot parsed completely\n", s,lineno);
}


%}

char [\x20\x21\x23-\x26\x28-\x5b\x5d-\x7e]|\\[\'\"\\]

%%
"#".*               {}
"func"              {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return FUNC;}

"int"               {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return INT;}
"bool"              {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return BOOL;}
"void"              {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return VOID;}
"uint"              {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return UINT;}
"char"              {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return CHAR;}
"string"            {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return STRING;}
"double"            {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return DOUBLE;}

"True"              {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return TRUE;}
"False"             {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return FALSE;}
"begin"             {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return BEG;}
"end"               {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return END;}
"if"                {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return IF;}
"else"              {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return ELSE;}
"then"              {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return THEN;}
"while"             {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return WHILE;}
"for"               {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return FOR;}
"return"            {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return RETURN;}
"break"		        {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return BREAK;}
"continue"	        {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return CONTINUE;}
"print"            {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return PRINT;}
"scan"             {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return SCAN;}
"\n"		        {printf("%s",yytext); ++lineno; yylval.lit = new string(yytext, yyleng); return END_LINE;}

"?"                 {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return QUES;}
":"                 {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return COLON;}
"["					{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return OPEN_BOX;}
"]"					{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return CLOSE_BOX;}
"("					{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return OPEN_PAR;}
")"					{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return CLOSE_PAR;}
","					{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return COMMA;}
"="					{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return EQUAL;}
"+"					{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return PLUS;}
"-"					{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return MINUS;}
"*"					{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return MULTIPLY;}
"/"					{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return DIVIDE;}
"!"                 {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return NOT;}
"%"					{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return MOD;}
"<"					{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return LESS;}
">"					{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return GREATER;}
"<="				{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return LESS_EQUAL;}
">="				{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return GREATER_EQUAL;}
"=="				{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return EQUALTO;}
"!="				{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return NOTEQUALTO;}
"and"				{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return AND;}
"or"				{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return OR;}

-?[0-9]+		    {printf("%s", yytext);yylval.num = strtol(yytext,0,10); return INT_VAL;}
-?[0-9]+([.][0-9]+)? {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return DOUBLE_VAL;}
\'{char}\'          {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return CHAR_VAL;}
\"{char}*\n*\"         {printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return STRING_VAL;}
&?[A-Za-z][_0-9A-Za-z]* 	{printf("%s",yytext); yylval.lit = new string(yytext, yyleng); return ID;}

"\t"				{printf("%s",yytext);}
" "					{printf(" "); }

.					{printf("Line No %d: Unrecognized Character\n", lineno); }
<<EOF>>				{yyterminate();}

%%

// int main()
// {
//   // open a file handle to a particular file:
//   FILE *myfile = fopen("3.txt", "r");
  
//   // set lex to read from it instead of defaulting to STDIN:
//   yyin = myfile;
  
//   // lex through the input:
//   while(yylex());
// }
