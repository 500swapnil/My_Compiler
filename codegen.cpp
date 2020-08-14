#include <bits/stdc++.h>
#include "ast.h"

using namespace std;
using namespace llvm;


static LLVMContext Context;
static IRBuilder<> Builder(Context);
static Module *TheModule = new Module("Compiler for Kauta", Context);

vector<string> errors;
map<string, AllocaInst *> global_vars;
stack<loopInfo *> loops;

Value *Prog::reportError()
{
    cout<<"\n\n-----------------Errors (if any) listed below------------------"<<endl;
    for (int i = 0; i<errors.size(); i++)
    {
        cout<<errors[i]<<endl;
    }
    fflush(stdout);
    return nullptr;
}

AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, string name, string type)
{
    AllocaInst *alloca_instruction = nullptr;
    IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());

    if (type == "boolean")
        return TmpB.CreateAlloca(Type::getInt1Ty(Context), 0, name);
    else if (type == "int")
        return TmpB.CreateAlloca(Type::getInt32Ty(Context), 0, name);
}

Value *Prog::generateCode()
{

    Value *V;
    V = var_list->generateCode();
    if (V == nullptr)
    {
        errors.push_back("Invalid variable Declarations");
        
    }

    V = func_list->generateCode();
    if (V == nullptr)
    {
        errors.push_back("Invalid Function Declarations");
        
    }
    Function *callee = TheModule->getFunction("main");
    if (callee == nullptr)
    {
        errors.push_back("main not defined");
        
    }
    if (callee->arg_size() != 0)
    {
        errors.push_back("In main: number of parameters should be zero");
        
    }
    return V;
}

void Prog::output_llvm_ir()
{
    TheModule->print(errs(), nullptr);
}

Value *Var_List::generateCode()
{
    for (int i = 0 ; i < var_list.size() ; i++)
    {
        var_list[i]->generateCode();
    }
    Value *v = ConstantInt::get(Context, APInt(32, 1));
    return v;
}

Value *Variable_List::generateCode()
{
    Type *ty = nullptr;

    if (*dataType == "int")
        ty = Type::getInt32Ty(Context);
    else if (*dataType == "boolean")
        ty = Type::getInt1Ty(Context);
    else    return nullptr;

    for (int i = 0 ; i < variable_list.size() ; i++)
    {
        GlobalVariable *check_gv = TheModule->getNamedGlobal(*(variable_list[i]->name));
        if (check_gv != nullptr)
        {
            errors.push_back("Variable redeclared" + *(variable_list[i]->name));
            return nullptr;
        }

        if (variable_list[i]->declType == "array")
        {
            if (variable_list[i]->size <= 0)
            {
                errors.push_back("Array size cannot be 0: " + *(variable_list[i]->name));
            }
            ArrayType *arrType = ArrayType::get(ty, variable_list[i]->size);
            GlobalVariable *gv = new GlobalVariable(*(TheModule), arrType, false,
                                                    GlobalValue::ExternalLinkage, nullptr,
                                                    *(variable_list[i]->name));
            gv->setInitializer(ConstantAggregateZero::get(arrType));
        }
        else
        {
            GlobalVariable *gv = new GlobalVariable(*(TheModule), ty, false,
                                                    GlobalValue::ExternalLinkage, nullptr,
                                                    *(variable_list[i]->name));
            gv->setInitializer(Constant::getNullValue(ty));
        }
    }
    Value *v = ConstantInt::get(Context, APInt(32, 1));
    return v;
}

Value *Variable_List::generateCode(map<string, llvm::AllocaInst *> &old_vars)
{

    llvm::Function *TheFunction = Builder.GetInsertBlock()->getParent();
    for (int i = 0 ; i < variable_list.size() ; i++)
    {
        Value *initval = nullptr;
        AllocaInst *Alloca = nullptr;
        if (global_vars[*(variable_list[i]->name)] != nullptr)
        {
            errors.push_back("Redeclared Variable: " + *(variable_list[i]->name));
            return nullptr;
        }
        if (*(dataType) == "int")
        {
            initval = ConstantInt::get(Context, APInt(32, 0));
            Alloca = CreateEntryBlockAlloca(TheFunction, *(variable_list[i]->name), "int");
        }
        else if (*(dataType) == "boolean")
        {
            initval = ConstantInt::get(Context, APInt(1, 0));
            Alloca = CreateEntryBlockAlloca(TheFunction, *(variable_list[i]->name), "boolean");
        }

        Builder.CreateStore(initval, Alloca);
        old_vars[*(variable_list[i]->name)] = global_vars[*(variable_list[i]->name)];
        global_vars[*(variable_list[i]->name)] = Alloca;
    }
    Value *v = ConstantInt::get(Context, APInt(32, 1));
    return v;
}

Value *Func_List::generateCode()
{
    Value *V = ConstantInt::get(Context, APInt(32, 0));
    for (int i = 0; i<func_list.size() ; i++)
    {
        V = func_list[i]->generateCode();
        if (V == nullptr)
            return nullptr;
    }
    return V;
}

Function *Func::generateCode()
{
    vector<pair<string,string>> arg;
    vector<string> argTypes;
    class Param_List *arg_l = param_list;
    vector<Type *> arguments;
    int arg_size = arg_l->param_list.size();

    for (int i=0 ; i<arg_size ; i++)
    {
        string arg_type = *(arg_l->param_list[i].first.first);
        string arg_name = *(arg_l->param_list[i].first.second);

        if (arg_type == "int")
            arguments.push_back(Type::getInt32Ty(Context));
        else if (arg_type == "boolean")
            arguments.push_back(Type::getInt1Ty(Context));
        else
        {
            errors.push_back("Arguments can only be int or boolean");
            return nullptr;
        }

        arg.push_back(make_pair(arg_name,arg_type));
    }

    Type *return_type;
    string data_type = *returnType;

    if (data_type == "int")
        return_type = Type::getInt32Ty(Context);
    else if (data_type == "boolean")
        return_type = Type::getInt1Ty(Context);
    else if (data_type == "void")
        return_type = Type::getVoidTy(Context);
    else
    {
        errors.push_back("Invalid Return Type for " + *(func_name) + ". Return Type can only be int or boolean or bool");
        return nullptr;
    }

    FunctionType *FT = llvm::FunctionType::get(return_type, arguments, false);
    Function *F = llvm::Function::Create(FT, Function::ExternalLinkage, *(func_name), TheModule);

    unsigned idx = 0;
    for (Function::arg_iterator AI = F->arg_begin(); idx != arg_size; ++AI, ++idx)
    {
        AI->setName(arg[idx].first);
    }
    idx = 0;
    BasicBlock *BB = BasicBlock::Create(Context, "entry", F);
    Builder.SetInsertPoint(BB);
    for (auto &Arg : F->args())
    {
        AllocaInst *Alloca = CreateEntryBlockAlloca(F, arg[idx].first, arg[idx].second);
        Builder.CreateStore(&Arg, Alloca);
        global_vars[arg[idx].first] = Alloca;
        idx++;
    }

    Value *RetVal = block->generateCode();
    if (!RetVal)
    {
        F->eraseFromParent();
        return nullptr;
    }
    verifyFunction(*F);
    return F;
 
}

Value *If_Stmt::generateCode()
{

    Value *cond = condition->generateCode();
    if (cond == nullptr)
    {
        errors.push_back("Invalid Expression in the IF");
        return nullptr;
    }

    Value *temp = ConstantInt::get(Context, APInt(1, 0));
    if (temp->getType() == cond->getType())
    {
        Function *TheFunction = Builder.GetInsertBlock()->getParent();
        BasicBlock *elseBlock = BasicBlock::Create(Context, "else");
        BasicBlock *otherBlock = elseBlock;

        BasicBlock *ifBlock = BasicBlock::Create(Context, "if", TheFunction);
        
        BasicBlock *nextBlock = BasicBlock::Create(Context, "after if");
        if (else_block == nullptr)
            otherBlock = nextBlock;
        bool break_if = if_block->has_break(), break_else = false;
        bool cont_if = if_block->has_continue(), cont_else = false;
        bool ret_if = if_block->has_return(), ret_else = false;
        


        Builder.CreateCondBr(cond, ifBlock, otherBlock);
        Builder.SetInsertPoint(ifBlock);

        Value *if_val = if_block->generateCode();
        if (if_val == nullptr)
            return nullptr;

        if (ret_if || break_if || cont_if){}
        else
            Builder.CreateBr(nextBlock);

        ifBlock = Builder.GetInsertBlock();

        Value *else_val = nullptr;

        if (else_block != nullptr)
        {
            TheFunction->getBasicBlockList().push_back(elseBlock);
            Builder.SetInsertPoint(elseBlock);
            else_val = else_block->generateCode();

            if (else_val == nullptr)
                return nullptr;
            break_else = else_block->has_break();
            cont_else = else_block->has_continue();
            ret_else = else_block->has_return();

            if (ret_else || break_else || cont_else){}
            else
                Builder.CreateBr(nextBlock);
        }
        if (!cont_if)
        {
            TheFunction->getBasicBlockList().push_back(nextBlock);
            Builder.SetInsertPoint(nextBlock);
            if (ret_else && ret_if)
            {
                Type *retType = Builder.GetInsertBlock()->getParent()->getReturnType();
                if (retType != Type::getVoidTy(Context))
                    Builder.CreateRet(ConstantInt::get(Context, APInt(32, 0)));
                else
                    Builder.CreateRetVoid();
            }
        }
        Value *V = ConstantInt::get(Context, APInt(32, 0));
        return V;
    }
    else
    {
        errors.push_back("Condition in If statement can only be bool");
        return nullptr;
    }

}

Value *Not_Expr::generateCode()
{

    Value *v = expr->generateCode();

    if (dynamic_cast<class Location *>(expr) != nullptr)
        v = Builder.CreateLoad(v);

    return Builder.CreateNot(v, "nottmp");

    return nullptr;
}

Value *For_Stmt::generateCode()
{

    Value *start_node = start->generateCode();
    if (start_node == nullptr)
        return nullptr;
    if (dynamic_cast<class Location *>(start) != nullptr)
        start_node = Builder.CreateLoad(start_node);
    Function *TheFunction = Builder.GetInsertBlock()->getParent();

    llvm::AllocaInst *Alloca = CreateEntryBlockAlloca(TheFunction, *(iter_var), string("int"));

    AllocaInst *OldVal = global_vars[*iter_var];
    global_vars[*iter_var] = Alloca;
    Value *step_val = ConstantInt::get(Context, APInt(32, increment));
    Value *a = Builder.CreateStore(start_node, Alloca);
    BasicBlock *pre_header_basic_block = Builder.GetInsertBlock();
    BasicBlock *loop_body = BasicBlock::Create(Context, "LoopStart", TheFunction);
    BasicBlock *afterBB = BasicBlock::Create(Context, "LoopEnd", TheFunction);
    BasicBlock *loop_header = BasicBlock::Create(Context, "Start Condition", TheFunction);
    Builder.CreateBr(loop_header);
    Builder.SetInsertPoint(loop_header);

    PHINode *Variable = Builder.CreatePHI(Type::getInt32Ty(Context), 2, *iter_var);
    Variable->addIncoming(start_node, pre_header_basic_block);

    Value *cond = condition->generateCode();
    
    if (dynamic_cast<class Location *>(condition) != nullptr)
        cond = Builder.CreateLoad(cond);
    
    if (cond == nullptr)
    {
        errors.push_back("Invalid Condition in for loop with iter var: " + *iter_var);
        return nullptr;
    }

    Value *sec = Variable;
    
    if (block->generateCode() == nullptr)
        return nullptr;

    Builder.CreateCondBr(cond, loop_body, afterBB);

    Builder.SetInsertPoint(loop_body);

    loops.push(new loopInfo(loop_header, afterBB, loop_body, cond, *iter_var, Variable));

    if (block->has_break() || block->has_continue()){}
    else
    {
        Value *cur = Variable;
        Value *next_val = Builder.CreateAdd(cur, step_val, "NextVal");
        Builder.CreateStore(next_val, global_vars[*iter_var]);

        Builder.CreateBr(loop_header);
        BasicBlock *loopEndBlock = Builder.GetInsertBlock();

        Variable->addIncoming(next_val, loopEndBlock);
    }
    Builder.SetInsertPoint(afterBB);

    if (!OldVal)
        global_vars.erase(*iter_var);
    else
        global_vars[*iter_var] = OldVal;

    llvm::Value *V = ConstantInt::get(Context, APInt(32, 1));
    loops.pop();
    return V;
}

Value *While_Stmt::generateCode()
{
    Function *TheFunction = Builder.GetInsertBlock()->getParent();

    BasicBlock *pre_header_basic_block = Builder.GetInsertBlock();

    BasicBlock *loop_header = BasicBlock::Create(Context, "Start Condition", TheFunction);
    BasicBlock *loop_body = BasicBlock::Create(Context, "LoopStart", TheFunction);
    BasicBlock *afterBB = BasicBlock::Create(Context, "LoopEnd", TheFunction);
    Builder.CreateBr(loop_header);
    Builder.SetInsertPoint(loop_header);


    Value *cond = condition->generateCode();
    if (cond == nullptr)
    {
        errors.push_back("Invalid Condition in for loop" );
        return nullptr;
    }

    if (dynamic_cast<class Location *>(condition) != nullptr)
        cond = Builder.CreateLoad(cond);

    PHINode *sec;

    Builder.CreateCondBr(cond, loop_body, afterBB);

    Builder.SetInsertPoint(loop_body);

    loops.push(new loopInfo(loop_header, afterBB, loop_body, cond, string("unused"), sec));

    if (block->generateCode() == nullptr)
        return nullptr;

    if (!block->has_break() && !block->has_continue())
    {

        Builder.CreateBr(loop_header);
        BasicBlock *loopEndBlock = Builder.GetInsertBlock();

    }
    Builder.SetInsertPoint(afterBB);

    llvm::Value *V = ConstantInt::get(Context, APInt(32, 1));
    loops.pop();
    return V;
}

Value *Break_Stmt::generateCode()
{
    if (loops.size() == 0)
    {
        errors.push_back("Break cannot be without a for loop.");
        return nullptr;
    }
    Value *V = ConstantInt::get(Context, llvm::APInt(32, 1));
    loopInfo *currentLoop = loops.top();
    Builder.CreateBr(currentLoop->getAfterBlock());
    return V;
}

Value *Return_Stmt::generateCode()
{

    Value *V = ConstantInt::get(Context, APInt(32, 1));

    if (return_expr != nullptr)
    {
        V = return_expr->generateCode();

        if (dynamic_cast<class Location *>(return_expr) != nullptr)
            V = Builder.CreateLoad(V);

        Builder.CreateRet(V);
        return V;
    }
    Builder.CreateRetVoid();

    return V;
}

Value *Continue_Stmt::generateCode()
{
    loopInfo *currentLoop = loops.top();
    string var = currentLoop->getLoopVariable();
    AllocaInst *Alloca = global_vars[var];
    if (loops.size() == 0)
    {
        errors.push_back("Continue cannot be without a for loop.");
        return nullptr;
    }
    Value *V = ConstantInt::get(Context, APInt(32, 1));
    Value *step_val = ConstantInt::get(Context, APInt(32, 1));
    Value *cur = Builder.CreateLoad(Alloca, var);
    Value *next_val = Builder.CreateAdd(cur, step_val, "NextVal");
    Builder.CreateStore(next_val, Alloca);

 
    Builder.CreateBr(currentLoop->getLoopHeader());

    currentLoop->getPHINode()->addIncoming(next_val, currentLoop->getCheckBlock());

    return V;
}

Value *Print_Stmt::generateCode()
{

    vector<Type *> argTypes;
    vector<Value *> Args;
    vector<class Arg *> args_list = arg_list->arg_list;

    for (int i= 0; i<args_list.size() ;i++)
    {
        Value *tmp = args_list[i]->generateCode();
        if (tmp == nullptr)
            return nullptr;
        Args.push_back(tmp);
        argTypes.push_back(tmp->getType());
    }
    ArrayRef<llvm::Type *> argsRef(argTypes);
    ArrayRef<llvm::Value *> funcargs(Args);
    FunctionType *FType = FunctionType::get(Type::getInt32Ty(Context), argsRef, false);
    Constant *func = TheModule->getOrInsertFunction("printf", FType);
    Value *v = Builder.CreateCall(func, funcargs);
    return v;
}

Value *Scan_Stmt::generateCode()
{

    vector<Type *> argTypes;
    vector<Value *> Args;
    vector<class Arg *> args_list = arg_list->arg_list;

    for (int i=0 ; i<args_list.size(); i++)
    {
        Value *tmp = args_list[i]->generateCode();
        if (tmp == nullptr)
            return nullptr;

        Args.push_back(tmp);
        argTypes.push_back(tmp->getType());
    }

    ArrayRef<llvm::Type *> argsRef(argTypes);
    ArrayRef<llvm::Value *> funcargs(Args);
    FunctionType *FType = FunctionType::get(Type::getInt32Ty(Context), argsRef, false);
    Constant *func = TheModule->getOrInsertFunction("scanf", FType);
    Value *v = Builder.CreateCall(func, funcargs);
    return v;
}
Value *Binary_Expr::generateCode()
{
    Value *right = rhs->generateCode();
    Value *left = lhs->generateCode();

    Value *temp = ConstantInt::get(Context, APInt(32, 0));
    if (dynamic_cast<class Location *>(rhs) != nullptr)
        right = Builder.CreateLoad(right);

    if (right != 0) {}
    else
    {
        errors.push_back("Error in right operand of " + *(binop));
        return nullptr;
    }

    if (dynamic_cast<class Location *>(lhs) != nullptr)
        left = Builder.CreateLoad(left);

    if (left != 0) {}
    else
    {
        errors.push_back("Error in left operand of " + *(binop));
        return nullptr;
    }

    Value *temp1 = ConstantInt::get(Context, APInt(1, 0));
    if (*binop == "==" || *binop == "!=")
    {
        Type *l = left->getType();
        Type *r = right->getType();
        if (l->isPointerTy())
            l = left->getType()->getContainedType(0);
        if (r->isPointerTy())
            r = right->getType()->getContainedType(0);
        if (l == r && (l == temp1->getType() || r == temp->getType()))
        {
        }
        else
        {
            errors.push_back("Invalid Operand for Equal operation: " + *binop);
            return nullptr;
        }
    }

    if ( *binop == "-" || *binop == "+" || *binop == "*" || *binop == "/" || *binop == "%" || *binop == "<" || *binop == ">" || *binop == ">=" || *binop == "<=")
    {
        Type *r = right->getType();
        Type *l = left->getType();
        if (r->isPointerTy())
            r = right->getType()->getContainedType(0);
        if (l->isPointerTy())
            l = left->getType()->getContainedType(0);
        if (l != temp->getType() || r != temp->getType())
        {
            errors.push_back("Invalid Operand for binary operation: " + *binop);
            return nullptr;
        }
    }

    if (*binop == "and" || *binop == "or")
    {
        Type *l = left->getType();
        if (l->isPointerTy())
            l = left->getType()->getContainedType(0);
        Type *r = right->getType();
        if (r->isPointerTy())
            r = right->getType()->getContainedType(0);
        if (l != r && l != temp1->getType())
        {
            errors.push_back("Invalid Operand for Conditional operation: " + *binop);
            return nullptr;
        }
    }

    Value *v = nullptr;
    if (*binop == "+")
        v = Builder.CreateAdd(left, right, "add");
    else if (*binop == "-")
        v = Builder.CreateSub(left, right, "sub");
    else if (*binop == "*")
        v = Builder.CreateMul(left, right, "mul");
    else if (*binop == "/")
        v = Builder.CreateSDiv(left, right, "div");
    else if (*binop == "%")
        v = Builder.CreateSRem(left, right, "mod");
    else if (*binop == "and")
        v = Builder.CreateAnd(left, right, "andcompare");
    else if (*binop == "or")
        v = Builder.CreateOr(left, right, "orcompare");
    else if (*binop == "<")
        v = Builder.CreateICmpSLT(left, right, "ltcompare");
    else if (*binop == ">")
        v = Builder.CreateICmpSGT(left, right, "gtcompare");
    else if (*binop == "<=")
        v = Builder.CreateICmpSLE(left, right, "lecompare");
    else if (*binop == ">=")
        v = Builder.CreateICmpSGE(left, right, "gecompare");
    else if (*binop == "==")
        v = Builder.CreateICmpEQ(left, right, "equalcompare");
    else if (*binop == "!=")
        v = Builder.CreateICmpNE(left, right, "notequalcompare");

    return v;
}

Value *Block::generateCode()
{
    Value *V;
    map<string, AllocaInst *> old_vars;
    V = content->generateCode();
    for (auto it = old_vars.begin(); it != old_vars.end(); it++)
    {
        global_vars[it->first] = old_vars[it->first];
    }
    return V;
}

Value *Content::generateCode()
{
    Value *v = ConstantInt::get(Context, llvm::APInt(32, 1));
    for (int i = 0 ; i<content.size() ; i++)
    {
        v = content[i]->generateCode();
        fflush(stdout);
        if (content[i]->has_break || content[i]->has_continue   )
        {
            return v;
        }
    }
    return v;
}

Value *Assign_Stmt::generateCode()
{
    Value *cur = global_vars[*(location->name)];
    if (cur == nullptr)
        cur = TheModule->getGlobalVariable(*(location->name));

    if (cur == nullptr)
    {
        errors.push_back("Unknown Variable" + *(location->name));
        return nullptr;
    }
    
    Value *lhs = location->generateCode();
    cur = Builder.CreateLoad(lhs);

    Value *val = expr->generateCode();
    if (val == nullptr)
    {
        errors.push_back("Error in right hand side of the Assignment");
        return nullptr;
    }
    if (dynamic_cast<class Location *>(expr) != nullptr)
        val = Builder.CreateLoad(val);

    Type *l = lhs->getType();
    Type *r = val->getType();
    if (r->isPointerTy())
        r = val->getType()->getContainedType(0);
    if (l->isPointerTy())
        l = lhs->getType()->getContainedType(0);
    if (l != r)
    {
        errors.push_back("Invalid Operand for Assignment operation: ");
        return nullptr;
    }

    return Builder.CreateStore(val, lhs);
}

Value *Location::generateCode()
{
    fflush(stdout);
    Value *V = global_vars[*name];
    if (V == nullptr)
        V = TheModule->getNamedGlobal(*name);

    if (V == nullptr)
    {
        errors.push_back("Unknown Variable name " + *name);
        return nullptr;
    }

    if (dataType == "array")
    {

        Value *index = loc_expr->generateCode();

        if (dynamic_cast<class Location *>(loc_expr) != nullptr)
            index = Builder.CreateLoad(index);

        if (index == nullptr)
        {
            errors.push_back("Invalid Array Index for:" + *name);
            return nullptr;
        }

        vector<Value *> array_index;
        array_index.push_back(Builder.getInt32(0));
        array_index.push_back(index);
        V = Builder.CreateGEP(V, array_index, *name + "_Index");
    }
    return V;
}


Value *Literal::generateCode()
{
    if (lit != nullptr){
        if (*lit == "false" || *lit == "true")
        {
            bool val;

            if (*lit == "false")
                val = false;
            else if (*lit == "true")
                val = true;
            else
            {
                errors.push_back("Invalid Boolean Literal " + *lit);
                return nullptr;
            }

            Value *v = ConstantInt::get(Context, llvm::APInt(1, val));
            return v;
        }
        else
        {
            Value *v = ConstantInt::get(Context, llvm::APInt(32, static_cast<uint64_t>(stoi(*lit))));
            return v;
        }
    }
    else
    {
        Value *v = ConstantInt::get(Context, llvm::APInt(32, static_cast<uint64_t>(num)));
        return v;
    }
    
}

Value *Func_Call::generateCode()
{
    Function *callee = TheModule->getFunction(*func_name);
    if (callee == nullptr)
    {
        errors.push_back("Unknown Function name: " + *func_name);
        return nullptr;
    }

    vector<class Arg *> args_list = arg_list->arg_list;
    if (callee->arg_size() != args_list.size())
    {
        errors.push_back("Incorrect Number of Parameters Passed");
        return nullptr;
    }

    vector<Value *> Args;
    int cur_ind = 0;
    for (int i=0 ; i<args_list.size(); i++)
    {
        Value *argVal = args_list[i]->generateCode();
        if (argVal != nullptr) {}
        else
        {
            errors.push_back("Argument is not valid");
            return nullptr;
        }
        int ind = 0;
        auto arg_rn = callee->arg_begin();
        for (int i=0 ; i<callee->arg_size(); i++)
        {
            if (cur_ind != ind)
                continue;
            ind++;
        }
        
        int ind_type = argVal->getType()->getPrimitiveSizeInBits();
        int cur_type = arg_rn->getType()->getPrimitiveSizeInBits();
        if (ind_type == 0)
        {
            ind_type = argVal->getType()->getContainedType(0)->getPrimitiveSizeInBits();
        }

        if (ind_type == cur_type){}
        else
        {
            errors.push_back("Method call doesn't match the function signature: " + *func_name);
            return nullptr;
        }

        cur_ind++;

        if (dynamic_cast<class Location *>(args_list[i]) != nullptr)
            argVal = Builder.CreateLoad(argVal);

        Args.push_back(argVal);
    }

    Value *v = Builder.CreateCall(callee, Args);
    return v;
}

Value *Arg::generateCode()
{
    if (expr == nullptr)
        return Builder.CreateGlobalStringPtr(*s);

    else
    {
        Value *v = expr->generateCode();
        if (dynamic_cast<class Location *>(expr) != nullptr)
        {
            v = Builder.CreateLoad(v);
        }
        return v;
    }
}