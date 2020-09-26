#ifndef TYPECHECKER_H
#define TYPECHECKER_H

#pragma once

#include "PlayScriptBaseListener.h"
#include "PlayScriptParser.h"
#include "ParserRuleContext.h"
using namespace antlr4;


namespace play
{
    class AnnotatedTree;
    class Type;

    /**
     * 类型检查，主要检查
     *  1. 赋值表达式
     *  2. 变量初始化
     *  3. 表达式里的一些运算，比如加减乘除，是否类型匹配
     *  4. 返回值的类型
     */
    class TypeChecker: public PlayScriptBaseListener
    {
        private:
            AnnotatedTree *at_;

        private:
            // 检查是否能做赋值操作
            bool checkAssign(Type *type1, Type *type2, ParserRuleContext *ctx, ParserRuleContext *operand1, ParserRuleContext *operand2);

            /**
             * 看一个类型能否赋值成另一个类型，比如：
             *  1. 整型可以转成浮点型
             *  2. 子类的对象可以赋给父类
             *  3. 函数赋值，要求签名是一致的
             */
            bool checkNumericAssign(Type *from, Type *to);

        public:
            TypeChecker(AnnotatedTree *at):at_(at)
            {

            }

            // 对变量初始化部分也做一下类型推断
            virtual void exitVariableInitializer(PlayScriptParser::VariableInitializerContext *ctx);

            virtual void exitVariableDeclarator(PlayScriptParser::VariableDeclaratorContext *ctx);
    };
};

#endif