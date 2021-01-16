#include <iostream>

#include "llvm/IR/Verifier.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "llvm/Transforms/Utils.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"

#include <cctype>
#include <cstdio>
#include <map>
#include <string>
#include <vector>

using namespace llvm;
using namespace std;


static LLVMContext TheContext;
static IRBuilder<> Builder(TheContext);
static std::unique_ptr<Module> TheModule;
static std::map<std::string, Value *> NamedValues;
static std::unique_ptr<legacy::FunctionPassManager> TheFPM;

Function* codegen_const_folding() {
    // 创建mian函数
    FunctionType *funType = FunctionType::get(Type::getInt32Ty(TheContext), false);
    Function *fun = Function::Create(funType, Function::ExternalLinkage, "const_folding", TheModule.get());

    // 创建一个基本块
    BasicBlock *BB = BasicBlock::Create(TheContext, "", fun);
    Builder.SetInsertPoint(BB);

    Value *tmp1 = ConstantInt::get(TheContext, APInt(32, 2, true));

    Value *tmp2 = ConstantInt::get(TheContext, APInt(32, 3, true));

    Value *tmp3 = Builder.CreateAdd(tmp1, tmp2);

    Builder.CreateRet(tmp3);

    return fun;
}

Function* codegen_algebra() {
    // 创建函数
    vector<Type*> argTypes(1, Type::getInt32Ty(TheContext));
    FunctionType *funType = FunctionType::get(Type::getInt32Ty(TheContext), argTypes, false);
    Function *fun = Function::Create(funType, Function::ExternalLinkage, "algebra", TheModule.get());

    // 设置参数名称
    string argNames[1] = {"a"};
    unsigned i = 0;
    for (auto &arg : fun->args()) {
        arg.setName(argNames[i++]);
    }

    NamedValues.clear();
    for (auto &Arg : fun->args()) {
        NamedValues[Arg.getName()] = &Arg;
    }

    // 创建一个基本块
    BasicBlock *BB = BasicBlock::Create(TheContext, "", fun);
    Builder.SetInsertPoint(BB);

    Value *L = NamedValues["a"];
    Value *R = ConstantInt::get(TheContext, APInt(32, 0, true));

    Value *tmp = Builder.CreateMul(L, R);

    Builder.CreateRet(tmp);

    return fun;
}

void InitializeModuleAndPassManager() {
    // 创建一个模块
    TheModule = std::make_unique<Module>("llvmdemo", TheContext);

    // 创建一个PassManager
    TheFPM = std::make_unique<legacy::FunctionPassManager>(TheModule.get());

    // 窥孔优化和一些位计算优化
    TheFPM->add(createInstructionCombiningPass());

    // 表达式重关联
    TheFPM->add(createReassociatePass());

    // 删除公共子表达式
    TheFPM->add(createGVNPass());

    // 简化CFG，比如删除不可达的块
    TheFPM->add(createCFGSimplificationPass());

    TheFPM->doInitialization();
}

int main() {
    InitializeModuleAndPassManager();

    Function *const_folding = codegen_const_folding();
    Function *algebra = codegen_algebra();

    TheFPM->run(*algebra);

    TheModule->print(errs(), nullptr);

    return 0;
}