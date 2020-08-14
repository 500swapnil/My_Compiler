%{
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
%}

%token <lit> FUNC
%token <lit> OPEN_PAR CLOSE_PAR
%token <lit> OPEN_BOX CLOSE_BOX
%token <lit> INT BOOL VOID UINT DOUBLE
%token <lit> CHAR 
%token <lit> STRING
%token <lit> IF
%token <lit> THEN		
%token <lit> ELSE
%token <lit> FOR
%token <lit> WHILE			
%token <lit> RETURN
%token <lit> TRUE
%token <lit> FALSE
%token <lit> COMMA
%token <lit> END_LINE
%token <lit> BEG
%token <lit> END
%token <lit> BREAK
%token <lit> CONTINUE
%token <lit> ID
%token <num> INT_VAL
%token <lit> DOUBLE_VAL
%token <lit> UINT_VAL
%token <lit> CHAR_VAL
%token <lit> STRING_VAL
%token <lit> QUES
%token <lit> COLON
%token <lit> PRINT
%token <lit> SCAN

%left <lit> AND
%left <lit> OR
%left <lit> NOT
%left <lit> NOTEQUALTO
%left <lit> EQUALTO
%left <lit> LESS
%left <lit> GREATER
%left <lit> LESS_EQUAL
%left <lit> GREATER_EQUAL

%left <lit> PLUS MINUS
%left <lit> MULTIPLY DIVIDE 
%nonassoc <lit> MOD
%left <lit> EQUAL

%type <program> Program;
%type <var_list> VarList;
%type <func_list> FuncList;
%type <variable_list> Var;
%type <variable_list> IDList;
%type <func> Func;
%type <param_list> ParamList;
%type <block> Block;
%type <content> Content;
%type <statement> Statement;
%type <assign_statement> Assign_Statement;
%type <if_statement> If_Statement;
%type <func_call>  FuncCall;

%type <return_statement> Return_Statement;
%type <for_statement> For_Statement;
%type <while_statement> While_Statement;
%type <continue_statement> Continue_Statement;
%type <break_statement> Break_Statement;

%type <expr> Expr;
%type <expr> Term;
%type <expr> Factor;
%type <print_statement> Print_Statement;
%type <scan_statement> Scan_Statement;
%type <arg_list> ArgList;
%type <arg> Arg;
%type <literal> Literal;
%type <location> Loc;

%type <lit> Type;
%type <lit> Binop;
%type <lit> Lit_Literal;
%type <num> Int_Literal;

%%

Program: VarList FuncList								{ $$ = new Prog($1,$2); rootAst = $$; }
	;

VarList: 												{ $$ = new Var_List(); }
	| VarList Var										{ $$=$1 ; $$->push_back($2); }
	| VarList END_LINE									{ $$=$1 ; }
	;

Var: Type IDList END_LINE								{ $$ = $2; $$->dataType = $1; }
	;

IDList:	ID 												{ $$ = new Variable_List(); $$->push_back(new Variable(string("simple"),$1));}
	|	IDList COMMA ID 								{ $$->push_back(new Variable(string("simple"),$3));}
	|	ID OPEN_BOX INT_VAL CLOSE_BOX					{ $$ = new Variable_List(); $$->push_back(new Variable(string("array"),$1,$3));}					
	|	IDList COMMA ID OPEN_BOX INT_VAL CLOSE_BOX		{ $$->push_back(new Variable(string("array"),$3,$5));}
	;


FuncList: 												{ $$ = new Func_List(); }
	| FuncList Func										{ $$=$1 ; $$->push_back($2); }
	| FuncList END_LINE  								{ $$=$1 ;}
	;

Func: FUNC Type ID OPEN_PAR ParamList CLOSE_PAR END_LINE Block		{ $$ = new Func($2,$3,$5,$8); }
	;

ParamList: 												{ $$ = new Param_List();}
	| Type ID											{ $$ = new Param_List(); $$->push_back($1,$2,string("simple")); }
	| ParamList COMMA Type ID							{ $$=$1 ; $$->push_back($3,$4,string("simple")); }
	| Type ID OPEN_BOX CLOSE_BOX						{ $$ = new Param_List(); $$->push_back($1,$2,string("array")); }
	| ParamList COMMA Type ID OPEN_BOX CLOSE_BOX		{ $$=$1 ; $$->push_back($3,$4,string("array")); }						
	;

Content: 												{ $$ = new Content(); }
	| Content Statement 								{ $$=$1 ; $$->push_back($2); };
	| Content END_LINE									{ $$=$1 ; }
	;

Block: BEG END_LINE Content END END_LINE				{ $$ = new Block($3); };
	;

Statement: Var											{ $$ = $1; }
	| FuncCall END_LINE									{ $$ = $1; } 
	| If_Statement										{ $$ = $1; } 
	| While_Statement									{ $$ = $1; } 
	| For_Statement										{ $$ = $1; } 
	| Assign_Statement									{ $$ = $1; } 
	| Return_Statement									{ $$ = $1; } 
	| Break_Statement									{ $$ = $1; } 
	| Continue_Statement								{ $$ = $1; } 
	| Scan_Statement END_LINE							{ $$ = $1; }
	| Print_Statement END_LINE							{ $$ = $1; }
	;

If_Statement: IF Expr THEN END_LINE Block				{ $$ = new If_Stmt($2,$5); }
	| IF Expr THEN END_LINE Block ELSE END_LINE Block	{ $$ = new If_Stmt($2,$5,$8); }
	;

While_Statement: WHILE Expr END_LINE Block				{ $$ = new While_Stmt($2,$4); }
	;

For_Statement: FOR ID EQUAL Expr COMMA Expr COMMA INT_VAL END_LINE Block	{ $$ = new For_Stmt($2,$4,$6,$8,$10); }
	;

Assign_Statement: Loc EQUAL Expr END_LINE				{ $$ = new Assign_Stmt($1,$3); }
	;

Return_Statement:  RETURN Expr END_LINE					{ $$ = new Return_Stmt($2); }
	| RETURN END_LINE									{ $$ = new Return_Stmt(); }
	;

Break_Statement:  BREAK END_LINE						{ $$ = new Break_Stmt(); }
	;

Continue_Statement:  CONTINUE END_LINE					{ $$ = new Continue_Stmt(); }
	;
	
Expr: Expr Binop Term									{ $$ = new Binary_Expr($1,$2,$3); }
	| NOT Expr											{ $$ = new Not_Expr($2); }
	| Term												{ $$ = $1; }
	;

Term: Term MULTIPLY Factor								{ $$ = new Binary_Expr($1,$2,$3); }
	| Term DIVIDE Factor								{ $$ = new Binary_Expr($1,$2,$3); }
	| Factor											{ $$ = $1; }
	;

Factor: Literal											{ $$ = $1; }
	| Loc												{ $$ = $1; }
	| FuncCall											{ $$ = $1; }
	| OPEN_PAR Expr CLOSE_PAR							{ $$ = $2; }
	;

Literal: Int_Literal									{ $$ = new Literal($1); }
	| Lit_Literal										{ $$ = new Literal($1); }
	;

Int_Literal: INT_VAL									{ $$ = $1; }
	;

Lit_Literal: CHAR_VAL									{ $$ = $1; }
	| TRUE												{ $$ = $1; }
	| FALSE												{ $$ = $1; }
	;

Type: INT												{ $$ = $1; }
	| UINT 												{ $$ = $1; }
	| CHAR 												{ $$ = $1; }
	| BOOL 												{ $$ = $1; }
	| VOID 												{ $$ = $1; }
	| STRING 											{ $$ = $1; }
	| DOUBLE											{ $$ = $1; }
	;

Binop: PLUS 											{ $$ = $1; }
	| MINUS 											{ $$ = $1; }
	| AND 												{ $$ = $1; }
	| OR 												{ $$ = $1; }
	| MOD 												{ $$ = $1; }
	| EQUALTO 											{ $$ = $1; }
	| NOTEQUALTO 										{ $$ = $1; }
	| GREATER											{ $$ = $1; }
	| GREATER_EQUAL 									{ $$ = $1; }
	| LESS 												{ $$ = $1; }
	| LESS_EQUAL										{ $$ = $1; }
	;

FuncCall: ID OPEN_PAR ArgList CLOSE_PAR					{ $$ = new Func_Call($1,$3); }
	;

ArgList: Arg										 	{ $$ = new Arg_List(); $$->push_back($1);}
	| ArgList COMMA Arg									{ $$ = $1 ; $$->push_back($3); }
	| 													{ $$ = new Arg_List();}				
	;

Arg: STRING_VAL											{ $$ = new Arg($1); }
	| Expr												{ $$ = new Arg($1); }
	;

Loc:  ID												{ $$ = new Location(string("simple"),$1);}
	| ID OPEN_BOX Expr CLOSE_BOX						{ $$ = new Location(string("array"),$1,$3);}
	;

Print_Statement: PRINT OPEN_PAR ArgList CLOSE_PAR				{ $$ = new Print_Stmt($3); }
	;

Scan_Statement: SCAN OPEN_PAR ArgList CLOSE_PAR					{ $$ = new Scan_Stmt($3); }
	;


%%


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



