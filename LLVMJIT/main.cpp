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
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"

#include <cctype>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include "llvmjit.h"

/**
 * 使用llvm的示例程序。
 * 能使用IRBuilder，生成一个简单程序的IR，并执行。
 * 示例代码相当于下面的C语言代码：
 *
 */

using namespace llvm;
using namespace llvm::orc;
using namespace std;

static LLVMContext TheContext;
static IRBuilder<> Builder(TheContext);
static std::unique_ptr<Module> TheModule;
static std::map<std::string, Value *> NamedValues;
static std::unique_ptr<legacy::FunctionPassManager> TheFPM;
static std::unique_ptr<LLVMJIT> TheJIT;

/**
相当于为下面的程序生成IR：
int fun1(int a, int b){
    return a + b;
}
**/

Function* codegen_fun1() {
    // 函数类型
    vector<Type*> argTypes(2, Type::getInt32Ty(TheContext));
    FunctionType *fun1Type = FunctionType::get(Type::getInt32Ty(TheContext), argTypes, false);

    // 函数对象
    Function *fun = Function::Create(fun1Type, Function::ExternalLinkage, "fun1", TheModule.get());

    // 设置参数名称
    string argNames[2] = {"a", "b"};
    unsigned i = 0;
    for (auto &arg : fun->args()) {
        arg.setName(argNames[i++]);
    }

    // 创建一个基本块
    BasicBlock *BB = BasicBlock::Create(TheContext, "", fun);
    Builder.SetInsertPoint(BB);

    /**
     * 在基本块里创建语句
     * 把参数变量存到NamedValues里面备用
     */
    NamedValues.clear();
    for (auto &Arg: fun->args()) {
        NamedValues[Arg.getName()] = &Arg;
    }

    // 做加法
    Value *L = NamedValues["a"];
    Value *R = NamedValues["b"];
    Value *addtmp = Builder.CreateAdd(L, R);

    // 返回值
    Builder.CreateRet(addtmp);

    // 验证函数的正确性
    verifyFunction(*fun);

    return fun;
}

int main() {

    codegen_fun1();

    return 0;
}