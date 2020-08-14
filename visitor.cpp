#include <bits/stdc++.h>
#include "ast.h"

using namespace std;

ASTVisitor::ASTVisitor() {};

void ASTVisitor::visit(class Prog* node) {
	cout << "\n\nProgram started\n\n" << endl;
	node->var_list->accept(this);
	node->func_list->accept(this);
	cout << "Program Ended";
}

void ASTVisitor::visit(class Var_List* node){
	int cnt = 1;
	for(int i=0 ; i<node->var_list.size(); i++){
		cout << "	Variable Declaration #" << cnt << ": ";
		node->var_list[i]->accept(this);
		cnt++;
		cout << endl << endl;
	}

}

void ASTVisitor::visit(class Variable_List* node) {
	cout << "DataType: " << *(node->dataType) << " : ";
	
	for (int i=0; i<node->variable_list.size(); i++) {
		node->variable_list[i]->accept(this); cout << ", ";
	}
}

void ASTVisitor::visit(class Variable* node) {
	cout << "Variable:" << node->declType << ": ";
	cout << *(node->name) << ": ";
	if(node->declType != "simple") cout << "array_size: "<<node->size;
	
}

void ASTVisitor::visit(class Func_List* node) {
	int cnt = 1;
	cout << "	Number of Funcs defined: "<< (node->func_list).size() << endl;
	for (int i=0; i<node->func_list.size(); i++) {
		cout << "	Func definition #" << cnt << ": ";
		node->func_list[i]->accept(this);
		cnt++;
		cout << endl << endl;
	}
	
}

void ASTVisitor::visit(class Func* node) {
	cout << "Func name: " << *(node->func_name) << " | ";
	cout << "Return Type: " << *(node->returnType) << " | ";	
	cout << "Parameter list: ";
	node->param_list->accept(this);
	cout << "\n\n Code block starts:\n" ;
	node->block->accept(this);
	cout << " Code block ends\n" ;
}


void ASTVisitor::visit(class Param_List* node) {
	cout << "Param List{ ";

	int cnt = 0;
	for(int i=0; i<node->param_list.size() ; i++){
		cout << *(node->param_list[i].first.first)<< " "<< *(node->param_list[i].first.second)<<":" <<(node->param_list[i].second)<< ", ";
	}
	cout<<"}";
}

void ASTVisitor::visit(class Block* node) {
	node->content->accept(this);
}


void ASTVisitor::visit(class Content* node){
	int statement_num = 1;
	for (int i=0 ;i<node->content.size(); i++) {
		cout << "	Statement #" << statement_num << ":";
		node->content[i]->accept(this);
		cout << endl << endl;
		statement_num++;
	}
}

void ASTVisitor::visit(class Statement* node){
}

void ASTVisitor::visit(class Assign_Stmt* node) {
	cout << " Assign statement: ";
	node->location->accept(this); 
	cout << " value:"; 
	node->expr->accept(this); 
	
}

void ASTVisitor::visit(class Return_Stmt* node){
	cout << " return statement: return ";
	fflush(stdout);
	if(node->return_expr != NULL){
		node->return_expr->accept(this);
	}
}

void ASTVisitor::visit(class Continue_Stmt* node){
	cout << " continue statement";
}

void ASTVisitor::visit(class Break_Stmt* node){
	cout << " break statement" ;
}

void ASTVisitor::visit(class If_Stmt* node) {
	cout << " If-else statement:" << endl;
	cout << "		condition: "; node->condition->accept(this); cout << endl;
	cout << "		if-block: " ; node->if_block->accept(this);
	if(node->else_block != NULL){
		cout << "		else-block: ";
		node->else_block->accept(this);
	}
}

void ASTVisitor::visit(class For_Stmt* node) {
	cout << "\n\t\tfor statement:\n";
	cout << "		iter variable: " << *(node->iter_var); cout<<endl;
	cout << "		initial value: "; node->start->accept(this); cout<<endl;
	cout << "		condition: "; node->condition->accept(this); cout<<endl;
	cout << "		increment by: "; cout<<node->increment<<endl;
	cout << "		block: "; node->block->accept(this);
	
}

void ASTVisitor::visit(class While_Stmt* node){
	cout <<" while statement: ";
	cout << "condition "; node->condition->accept(this); cout<<endl;
	cout << "		block: "; node->block->accept(this); cout<<endl;
}

void ASTVisitor::visit(class Print_Stmt* node){
	cout << " Print statement: " ; 
	cout << "Arguments: ";
	if(node->arg_list != NULL){
		node->arg_list->accept(this);
		cout<<", ";
	}
}

void ASTVisitor::visit(class Scan_Stmt* node){
	cout << " Scan statement: " ; 
	cout << "Arguments: ";
	if(node->arg_list != NULL){
		cout<<", ";
		node->arg_list->accept(this);
	}
}

void ASTVisitor::visit(class Expr* node){
	
}

void ASTVisitor::visit(class Func_Call* node){
	cout << "Func Call: ";
	cout << "function name: " << *(node->func_name);
	cout << " arg list: "; node->arg_list->accept(this);
}

void ASTVisitor::visit(class Arg_List* node){
	int arg_num = 1;
	for (int i=0 ; i<node->arg_list.size(); i++) {
		cout << "Arg #" << arg_num << ": ";
		node->arg_list[i]->accept(this);
		arg_num++;
	}	
}

void ASTVisitor::visit(class Arg* node){
	if(node->expr == NULL)
		cout<<*(node->s);
	else
		node->expr->accept(this);
}



void ASTVisitor::visit(class Location* node){
	cout << "location: " << (node->dataType) <<": " ;
	cout<< *(node->name)<<" ";
	if(node->dataType == "array"){
		cout<<"loc:";
		node->loc_expr->accept(this);
	}
}

void ASTVisitor::visit(class Binary_Expr* node){
	cout << "bin expr: "; node->lhs->accept(this);
	cout << " " << *(node->binop) << " ";
	node->rhs->accept(this); 
}

void ASTVisitor::visit(class Not_Expr* node){
	node->expr->accept(this);
	
}

void ASTVisitor::visit(class Literal* node){
	if(node->lit == NULL){
		cout << "Num Lit: "<< node->num<< " ";
	}
	else{
		cout<<"String Lit: "<< *(node->lit) <<" ";
	}
}