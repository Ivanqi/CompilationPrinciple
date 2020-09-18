#ifndef ASTEVALUATOR_H
#define ASTEVALUATOR_H
// 一个简短的测试程序，只支持整数常量做加减乘除四则运算
#pragma once

#include "PlayScriptBaseVisitor.h"
#include "PlayScriptParser.h"
#include "PlayObject.h"
#include "Stack.h"
#include "StackFrame.h"
#include <iostream>
// using namespace std;

namespace play 
{
    class Scope;
    class LValue;
    class Variable;
    class Function;
    class ClassObject;
    class Class;
    class AnnotatedTree;
    class Type;

    class ASTEvaluator: public PlayScriptBaseVisitor 
    {  
        private:
            Stack<StackFrame*> stacks;

            // 之前的编译结果
            AnnotatedTree *at_;

        protected:
            bool traceStackFrame = false;

            bool traceFunctionCall = false;

        private:

            void dumpStackFrame();

            void popStack();

            /**
             * 为闭包获取环境变量的值
             * @param function 闭包所关联的函数。这个函数会访问一些环境变量
             * @param valueContainer 存放环境变量的值的容器
             */
            void getClosureValues(Function *function, PlayObject *valueContainer);

            // 为从函数中返回的对象设置闭包值。因为多个函数型属性可能共享值，所以要打包到ClassObject中，而不是functionObject中
            void getClosureValues(ClassObject *classObject);

            // 内置函数
            // 自己硬编码的println方法
            void println(PlayScriptParser::FunctionCallContext *ctx);

            // 各种运算
            antlrcpp::Any add(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType);

            antlrcpp::Any minus(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType);

            antlrcpp::Any mul(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType);

            antlrcpp::Any div(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType);

            bool EQ(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType);

            bool GE(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType);

            bool GT(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType);

            bool LE(antlrcpp::Any obj1, antlrcpp::Any obj2, Type *targetType);

        protected:
            // 对象初始化
            // 从父类到子类层层执行缺省的初始化方法，即不带参数的初始化方法
            ClassObject* createAndInitClassObject(Class *theClass);

            // 类的缺省初始化方法
            void defaultObjectInit(Class *theClass, ClassObject *obj);
           
        public:

            // 堆，用于保存对象
            ASTEvaluator(AnnotatedTree *at): at_(at)
            {
            }

            void pushStack(StackFrame *frame);

            LValue* getLValue(Variable *variable);

            // visit每个节点


            virtual antlrcpp::Any visitExpression(PlayScriptParser::ExpressionContext *ctx) override;

            virtual antlrcpp::Any visitPrimary(PlayScriptParser::PrimaryContext *ctx) override;

            virtual antlrcpp::Any visitLiteral(PlayScriptParser::LiteralContext *ctx) override;

            virtual antlrcpp::Any visitIntegerLiteral(PlayScriptParser::IntegerLiteralContext *ctx) override;

            virtual antlrcpp::Any visitFloatLiteral(PlayScriptParser::FloatLiteralContext *ctx) override;

            virtual antlrcpp::Any visitFunctionDeclaration(PlayScriptParser::FunctionDeclarationContext *ctx) override;

            virtual antlrcpp::Any visitFunctionBody(PlayScriptParser::FunctionBodyContext *ctx) override;

            virtual antlrcpp::Any visitClassBody(PlayScriptParser::ClassBodyContext *ctx) override;

            virtual antlrcpp::Any visitClassBodyDeclaration(PlayScriptParser::ClassBodyDeclarationContext *ctx) override;

            virtual antlrcpp::Any visitMemberDeclaration(PlayScriptParser::MemberDeclarationContext *ctx) override;

            virtual antlrcpp::Any visitFieldDeclaration(PlayScriptParser::FieldDeclarationContext *ctx) override;

            virtual antlrcpp::Any visitVariableDeclarators(PlayScriptParser::VariableDeclaratorsContext *ctx) override;

            virtual antlrcpp::Any visitVariableDeclarator(PlayScriptParser::VariableDeclaratorContext *ctx) override;

            virtual antlrcpp::Any visitVariableDeclaratorId(PlayScriptParser::VariableDeclaratorIdContext *ctx) override;

            virtual antlrcpp::Any visitVariableInitializer(PlayScriptParser::VariableInitializerContext *ctx) override;
};

#endif