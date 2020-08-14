#include <bits/stdc++.h>
#include "ast.h"
using namespace std;


Prog::Prog(Var_List* var_list, Func_List* func_list){
  	this->var_list = var_list;
  	this->func_list = func_list;
}


void Var_List::push_back(class Variable_List* var){
	var_list.push_back(var);
	cnt++;
}

void Func_List::push_back(class Func* func){
	func_list.push_back(func);
	cnt++;
}

void Variable_List::push_back(class Variable* var){
	variable_list.push_back(var);
	cnt++;
}


Func::Func(string* returnType, string* func_name,Param_List* param_list,Block* block){
	
	this->func_name = func_name;
	this->param_list = param_list;
	this->block = block;
	this->returnType = returnType;
}

void Param_List::push_back(string* type,string* name, string isarray){
	param_list.push_back(make_pair(make_pair(type,name),isarray));
	cnt++;
}

Block::Block(class Content* content){
	this->content = content;
}

void Content::push_back(class Statement* stmt){
	content.push_back(stmt);
	cnt++;
}

Assign_Stmt::Assign_Stmt(class Location* location, class Expr* expr){
	this->location=location;
    this->expr=expr;
}

Return_Stmt::Return_Stmt(class Expr* expr){
	this->has_return = true;
	this->return_expr = expr;
}

Print_Stmt::Print_Stmt(class Arg_List* arg_list){
	this->arg_list = arg_list;
}

Scan_Stmt::Scan_Stmt(class Arg_List* arg_list){
	this->arg_list = arg_list;
}


If_Stmt::If_Stmt(class Expr* condition, class Block* if_block){
	this->condition = condition;
	this->if_block = if_block;
}


If_Stmt::If_Stmt(class Expr* condition, class Block* if_block, class Block* else_block){
	this->condition = condition;
	this->if_block = if_block;
	this->else_block = else_block;
}

For_Stmt::For_Stmt(string* var,class Expr* start, class Expr* condition, int increment, class Block* block){
	this->iter_var = var;
    this->start = start;
    this->condition = condition;
	this->increment = increment;
    this->block = block;
}

While_Stmt::While_Stmt(class Expr* condition, class Block* block){
	this->condition = condition;
	this->block = block;
}


Location::Location(string dataType,string* name){
	this->dataType = dataType;
	this->name = name;
}

Location::Location(string dataType,string* name, class Expr* loc_expr){
	this->dataType = dataType;
	this->name = name;
	this->loc_expr = loc_expr;
}

Func_Call::Func_Call(string* func_name, class Arg_List* arg_list){
	this->func_name = func_name;
	this->arg_list = arg_list;
}

void Arg_List::push_back(class Arg* expr){
	arg_list.push_back(expr);
	cnt++;
}

Arg::Arg(class Expr* expr){
    this->expr = expr;
}

Arg::Arg(string* s){
    this->s = s;
}

Binary_Expr::Binary_Expr(class Expr* lhs, string* binop, class Expr* rhs){
    this->lhs = lhs;
    this->rhs = rhs;
    this->binop = binop;
}

Not_Expr::Not_Expr(class Expr* expr){
    this->expr = expr;
}

Literal::Literal(string* lit){
    this->lit = lit;
}

Literal::Literal(int num){
    this->num = num;
}

Variable::Variable(string declType, string* name,int size){
	this->declType = declType;
	this->name = name;
	this->size = size;
}


Variable::Variable(string declType, string* name){
	this->declType = declType;
	this->name = name;
}


bool Block::has_break(){
	vector<class Statement* > block = content->content;
	for (auto statement: block) {
        if (statement->has_break) {
            return true;
        }
    }
	return false;
}

bool Block::has_continue(){
	vector<class Statement* > block = content->content;
	for (auto statement: block) {
        if (statement->has_continue) {
            return true;
        }
    }
	return false;
}


bool Block::has_return(){
	vector<class Statement* > block = content->content;
	for (auto statement: block) {
        if (statement->has_return) {
            return true;
        }
    }
	return false;
}

