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

// 第一练习
void first_example() {

    // 第一步，生成一个LLVM模块，也就是顶层的IR对象
    TheModule = std::make_unique<Module>("llvmjt.ll", TheContext);

    /**
     * 第二步，在模块中定义函数fun1,因为模块最主要的构成元素就是各个函数
     *  不过定义函数之前，要先定义函数的原型(或者叫函数的类型)
     *  函数的类型：如果两个函数的返回值相同，并且参数也相同，这两个函数的类型是相同的，这样就可以做函数指针或函数型变量的赋值
     */
    // 函数类型
    vector<Type*> argTypes(2, Type::getInt32Ty(TheContext));
    FunctionType *fun1Type = FunctionType::get(Type::getInt32Ty(TheContext),    // 返回
                argTypes,   // 两个整型参数
                false);     // 不是变长参数

    // 函数对象
    Function *fun = Function::Create(fun1Type,
                    Function::ExternalLinkage,  // 链接类型
                    "fun1",                     // 函数名称
                    TheModule.get());           // 所在模块

    // 设置参数名称
    string argNames[2] = {"a", "b"};
    unsigned i = 0;
    for (auto &arg : fun->args()) {
        arg.setName(argNames[i++]);
    }

    /**
     * 第三步，创建一个基本块
     *  可以给它命名为"entry"，也可以不命名
     *  在创建了基本块之后，用了一个辅助类IRBuilder,设置了一个插入点，后序生成指令会插入这个基本块
     *  (IRBuilder是LLVM为了简化IR生成过程所提供的一个辅助类)
     *  
     */
    // 创建一个基本块
    BasicBlock *BB = BasicBlock::Create(TheContext, // 上下文
                "",     // 基本块名称
                fun);   // 所在函数
    Builder.SetInsertPoint(BB); // 设置指令

    /**
     * 第四步，生成"a + b"表达式所对应的IR，插入到基本块中
     *  a 和 b都是函数fun的参数，把它取出来，分别赋值给L和R(L和R是Value)
     *  然后用IRBuilder的CreateAdd()方法，生成一条add指令
     *  这个计算结果存放在addtemp中
     *
     */
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

    /**
     * 第五步，利用刚才获得的addtmp创建一个返回值
     */
    // 返回值
    Builder.CreateRet(addtmp);

    /**
     * 最后一步，检查这个函数的正确性
     *  这相当于做语义检查，比如，基本块的最后一个语句就必须是一个正确的返回指令
     */
    // 验证函数的正确性
    verifyFunction(*fun);

    TheModule->print(errs(), nullptr);  // 在终端输出IR
}

/**
 * 相当于为下面的函数生成代码：
 相当于为下面的函数生成IR：
  int fun_ifstmt(int a){
     if (a > 2)
         return 2;
     else
         return 3;
  }
 * @return
 */
void second_example() {
    TheModule = std::make_unique<Module>("llvmjit", TheContext);

    vector<Type*> argTypes(1, Type::getInt32Ty(TheContext));
    FunctionType *funType = FunctionType::get(Type::getInt32Ty(TheContext), argTypes, false);
    Function *fun = Function::Create(funType, Function::ExternalLinkage, "fun_ifstmt", TheModule.get());

    // 入口基本块
    BasicBlock *entryBB = BasicBlock::Create(TheContext, "", fun);
    Builder.SetInsertPoint(entryBB);

    // 设置参数名称
    string argNames[1] = {"a"};
    unsigned i = 0;
    for (auto &arg: fun->args()) {
        arg.setName(argNames[i++]);
    }

    NamedValues.clear();

    for (auto &Arg: fun->args()) {
        NamedValues[Arg.getName()] = &Arg;
    }

    /**
     * if 语句分为 入口基本块、The基本块、Else基本块和Merge基本块
    */
    
    // 入口基本块. 计算a > 2,并根据这个值，分别跳转到ThenBB和ElseBB
    Value *L = NamedValues["a"];
    Value *R = ConstantInt::get(TheContext, APInt(32, 2, true));
    // CreateICmpUGE (UGE 的意思，是”不大于等于“，也就是小于). 这个指令的返回值是一个1位的整型，也就是int1
    Value *cond = Builder.CreateICmpUGE(L, R, "cmptmp");

    // 创建另外3个基本块
    BasicBlock *ThenBB = BasicBlock::Create(TheContext, "then", fun);
    BasicBlock *ElseBB = BasicBlock::Create(TheContext, "else");
    BasicBlock *MergeBB = BasicBlock::Create(TheContext, "ifcont");
    Builder.CreateCondBr(cond, ThenBB, ElseBB);

    // ThenBB
    Builder.SetInsertPoint(ThenBB);
    Value *ThenV = ConstantInt::get(TheContext, APInt(32, 2, true));
    Builder.CreateBr(MergeBB);

    // ElseBB
    fun->getBasicBlockList().push_back(ElseBB); // 把基本块加入到函数中
    Builder.SetInsertPoint(ElseBB);
    Value *ElseV = ConstantInt::get(TheContext, APInt(32, 3, true));
    Builder.CreateBr(MergeBB);

    // MergeBB
    fun->getBasicBlockList().push_back(MergeBB);
    Builder.SetInsertPoint(MergeBB);

    /**
     * phi指令，它完成了根据控制流来选择合适的值的任务
     * 
     * PHI节点: 整型,两个候选值
     */
    PHINode *PN = Builder.CreatePHI(Type::getInt32Ty(TheContext), 2);
    PN->addIncoming(ThenV, ThenBB); // 前序基本块是ThenBB, 采用ThenV
    PN->addIncoming(ElseV, ElseBB); // 前序基本块是ElseBB，采用ElseV

    // 返回值
    Builder.CreateRet(PN);

    // 验证函数的正确性
    verifyFunction(*fun);

    TheModule->print(errs(), nullptr);  // 在终端输出IR
}

int main() {
    second_example();  

    return 0;
}