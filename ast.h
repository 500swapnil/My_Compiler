#include <bits/stdc++.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Transforms/Utils/FunctionComparator.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/Support/raw_ostream.h>

#ifndef __CLASS_DEF__
#define __CLASS_DEF__

using namespace std;
using namespace llvm;

union Node {

	class Prog *program;
    class Var_List *var_list;
    class Func_List *func_list;
    class Variable *variable;
	class Variable_List *variable_list;
    class Func *func;
    class Param_List *param_list;
    class Content *content;
	class Statement *statement;
    class Assign_Stmt *assign_statement;
    class Block *block;
    class If_Stmt *if_statement;
    class While_Stmt *while_statement;
	class Location *location;
    class For_Stmt *for_statement;
    class Return_Stmt *return_statement;
    class Break_Stmt *break_statement;
    class Continue_Stmt *continue_statement;
	class Expr *expr;
    class Binary_Expr *bin_expression;
    class Not_Expr *not_expression;
    class Literal *literal;
    class Func_Call *func_call;
    class Arg_List *arg_list;
    class Arg *arg;
    class Print_Stmt *print_statement;
    class Scan_Stmt *scan_statement;
	string* lit;
	int num;
Node()
    {
        program = NULL;
		var_list = NULL;
		func_list = NULL;
		variable = NULL;
		variable_list = NULL;
		func = NULL;
		param_list = NULL;
		content = NULL;
		location = NULL;
		assign_statement = NULL;
		block = NULL;
		if_statement = NULL;
		while_statement = NULL;
		for_statement = NULL;
		return_statement = NULL;
		break_statement = NULL;
		continue_statement = NULL;
		expr = NULL;
		bin_expression = NULL;
		not_expression = NULL;
		literal = NULL;
		func_call = NULL;
		arg_list = NULL;
        arg = NULL;
		print_statement = NULL;
		scan_statement = NULL;
		lit = NULL;
        num = 0;
    }
    ~Node(){}
};

class Visitor {
    public:
        virtual void visit(class Prog*) = 0;
        virtual void visit(class Var_List*) = 0;
        virtual void visit(class Func_List*) = 0;
        virtual void visit(class Variable*) = 0;
        virtual void visit(class Variable_List*) = 0;
        virtual void visit(class Func*) = 0;
        virtual void visit(class Param_List*) = 0;
        virtual void visit(class Content*) = 0;
        virtual void visit(class Statement*) = 0;
        virtual void visit(class Assign_Stmt*) = 0;
        virtual void visit(class Block*) = 0;
        virtual void visit(class If_Stmt*) = 0;
        virtual void visit(class While_Stmt*) = 0;
        virtual void visit(class Location*) = 0;
        virtual void visit(class For_Stmt*) = 0;
        virtual void visit(class Return_Stmt*) = 0;
        virtual void visit(class Break_Stmt*) = 0;
        virtual void visit(class Continue_Stmt*) = 0;
        virtual void visit(class Expr*) = 0;
        virtual void visit(class Binary_Expr*) = 0;
        virtual void visit(class Not_Expr*) = 0;
        virtual void visit(class Literal*) = 0;
        virtual void visit(class Func_Call*) = 0;
        virtual void visit(class Arg_List*) = 0;
        virtual void visit(class Arg*) = 0;
        virtual void visit(class Print_Stmt*) = 0;
        virtual void visit(class Scan_Stmt*) = 0;
};

class ASTVisitor: public Visitor {
    public:
        ASTVisitor() ;

        void visit(class Prog*);
        void visit(class Var_List*);
        void visit(class Func_List*);
        void visit(class Variable*);
        void visit(class Variable_List*);
        void visit(class Func*);
        void visit(class Param_List*);
        void visit(class Content*);
        void visit(class Statement*);
        void visit(class Assign_Stmt*);
        void visit(class Block*);
        void visit(class If_Stmt*);
        void visit(class While_Stmt*);
        void visit(class Location*);
        void visit(class For_Stmt*);
        void visit(class Return_Stmt*);
        void visit(class Break_Stmt*);
        void visit(class Continue_Stmt*);
        void visit(class Expr*);
        void visit(class Binary_Expr*);
        void visit(class Not_Expr*);
        void visit(class Literal*);
        void visit(class Func_Call*);
        void visit(class Arg_List*);
        void visit(class Arg*);
        void visit(class Print_Stmt*);
        void visit(class Scan_Stmt*);
};

typedef union Node YYSTYPE; 
#define YYSTYPE_IS_DECLARED 1 

class baseAstNode {
public:
    virtual void accept(ASTVisitor* v) = 0;
    virtual Value *codegen(){};
}; 

class Prog: public baseAstNode {
public:
	class Var_List *var_list;
    class Func_List *func_list;
	Prog(class Var_List*, class Func_List*);
    void output_llvm_ir();
    Value *reportError();
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};

class Var_List: public baseAstNode {
public: 
	vector <class Variable_List* > var_list;
	int cnt;
	Var_List(){cnt=0;} 
	void push_back(class Variable_List*); 
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
}; 

class Statement:public baseAstNode{
public:
    bool has_return;
    bool has_break;
    bool has_continue;
    Statement(){has_return = false;has_break=false;has_continue=false;}
    virtual Value *generateCode(){};
    virtual void accept(ASTVisitor* v) { v->visit(this); };
};

class Variable_List: public Statement {
public:
	vector<class Variable*> variable_list;
  	int cnt;
  	string* dataType;
	Variable_List(){cnt=0;}
	void push_back(class Variable*);
    Value *generateCode();
    Value *generateCode(map<string, llvm::AllocaInst *> &);
    void accept(ASTVisitor* v) { v->visit(this); };
}; 

class Func_List: public baseAstNode {
public:
	vector < class Func*> func_list; 
	int cnt;
	Func_List(){cnt=0;}
	void push_back(class Func*); 
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
}; 

class Func:public baseAstNode{
public:
  	string* func_name;
  	class Param_List* param_list;
  	class Block* block;
  	string* returnType;
  	Func(string*,string*,Param_List*,Block*);
    Function *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};

class Param_List:public baseAstNode{
public:
    vector<pair<pair<string*,string*>,string> > param_list;
    int cnt;
	Param_List(){cnt=0;}
    void push_back(string*,string*,string); 
    void accept(ASTVisitor* v) { v->visit(this); };
};

class Variable: public baseAstNode{
public:
	string declType;
  	string* name;
  	int size;
  	Variable(string,string*);
  	Variable(string,string*,int);
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};

class Block:public baseAstNode{
public:
    class Content* content;
    Block( class Content*); 
    bool has_break();
    bool has_continue();
    bool has_return();
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};

class Content:public baseAstNode{
public:
    vector<class Statement*> content;
    int cnt;
    Content(){cnt=0;}
    void push_back(class Statement*);
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};

class Assign_Stmt:public Statement{
public:
    class Location* location;
    class Expr* expr;
    Assign_Stmt(class Location*, class Expr*);
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};

class If_Stmt: public Statement{
public:
    class Expr* condition;
    class Block* if_block;
    class Block* else_block;
    If_Stmt(class Expr*, class Block*);
    If_Stmt(class Expr*, class Block*, class Block*);
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};


class Arg_List:public baseAstNode{
public:
    vector<class Arg*> arg_list;
    int cnt;
    Arg_List(){cnt=0;}
    void push_back(class Arg*);
    
    void accept(ASTVisitor* v) { v->visit(this); };
};


class Arg: public baseAstNode{
public:
    class Expr *expr;
    string *s;
    Arg(class Expr *);
    Arg(string *);
    Value *generateCode();
    void accept(ASTVisitor *v) { v->visit(this); };
};

class Return_Stmt:public Statement{
public:
    class Expr* return_expr;
    Return_Stmt(){this->has_return = true; this->return_expr = NULL;}
    Return_Stmt(class Expr*);
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};


class For_Stmt:public Statement{
public:
    string* iter_var;
    class Expr* start;
	class Expr* condition;
    int increment;
    class Block* block;
    For_Stmt(string*,class Expr*, class Expr*, int, class Block*);
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};

class While_Stmt:public Statement{
public:
    class Expr* condition;
    class Block* block;
    While_Stmt(class Expr*, class Block*);
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};
 
class Continue_Stmt:public Statement{
public:
    Continue_Stmt(){has_continue = true;}
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};

class Break_Stmt:public Statement{
public:
    Break_Stmt(){has_break=true;}
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};


class Expr:public baseAstNode{
public:
    
    
    virtual Value *generateCode(){};
    virtual void accept(ASTVisitor* v){};
};

class Func_Call:public Statement,public Expr{
public:
    string* func_name;
    class Arg_List* arg_list;
    Func_Call(string*, class Arg_List*);
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};


class Location:public Expr{
public:
    string dataType;
    string* name;
    class Expr* loc_expr;
    Location(string,string*);
    Location(string,string*,class Expr*);
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};

class Binary_Expr:public Expr{
public:
    class Expr* lhs;
    class Expr* rhs;
    string* binop;
    Binary_Expr(class Expr*, string*, class Expr*);    
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};

class Not_Expr:public Expr{
public:
    class Expr* expr;
    Not_Expr(class Expr*);    
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};

class Literal:public Expr{
public:
    int num;
    string* lit;
    Literal(string*);
    Literal(int);       
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};

class Print_Stmt:public Statement{
public:
    class Arg_List* arg_list;
    Print_Stmt(class Arg_List*);
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};

class Scan_Stmt:public Statement{
public:
    class Arg_List* arg_list;
    Scan_Stmt(class Arg_List*);
    Value *generateCode();
    void accept(ASTVisitor* v) { v->visit(this); };
};

class loopInfo
{
    BasicBlock *afterBB, *checkBB, *loop_header;
    llvm::Value *condition;
    std::string loopVariable;
    PHINode *phiVariable;

public:
    loopInfo(BasicBlock *loop_header2, BasicBlock *afterBlock, BasicBlock *checkBlock, Value *cond, string var, PHINode *phiVar)
    {
        loop_header = loop_header2;
        afterBB = afterBlock;
        checkBB = checkBlock;
        condition = cond;
        loopVariable = var;
        phiVariable = phiVar;
    }

    BasicBlock *getLoopHeader()
    {
        return loop_header;
    }

    BasicBlock *getAfterBlock() { return afterBB; }

    BasicBlock *getCheckBlock() { return checkBB; }

    llvm::Value *getCondition() { return condition; }

    PHINode *getPHINode() { return phiVariable; }

    std::string getLoopVariable() { return loopVariable; }
};

#endif //__CLASS_DEF__