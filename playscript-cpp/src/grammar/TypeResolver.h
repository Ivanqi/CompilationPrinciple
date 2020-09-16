#ifndef TYPERESOLVER_H
#define TYPERESOLVER_H

#pragma
#include "PlayScriptBaseListener.h"
#include "PlayScriptParser.h"
using namespace antlr4;

/**
 * 
 * 类型的消解
 *  1. 把所有出现引用到类型的地方，都消解掉，比如变量声明，函数参数声明，类的继承等等
 *  2. 做完消解后，我们针对Mammal m, 这样语句，就明确的知道了m的类型。这实际上是对I属性的类型的计算
 * 
 * 第二遍扫描。把变量，类继承，函数声明的类型都解析出来
 * 也就是所有用到typeTpe的地方
 * 
 * 实际运行时，把变量添加到符号表，是分两步来做的
 * 
 * 第一步，是把类成员变量和函数的参数加进去
 * 
 * 第二步，是在变量引用消解的时候再添加。这个时候是边Enter符号表，边消解，会避免变量引用到错误的定义
 */

namespace play
{
    class AnnotatedTree;

    class TypeResolver: public PlayScriptBaseListener
    {
        private:
            AnnotatedTree *at_;

            // 是否把本地变量加入符号表
            bool enterLocalVariable_ = false;

        public:
            TypeResolver(AnnotatedTree *at);

            TypeResolver(AnnotatedTree *at, bool enterLocalVariable);

            // 设置所声明的变量的类型 把类成员变量的声明加入符号表
            virtual void exitVariableDeclarators(PlayScriptParser::VariableDeclaratorsContext *ctx);

            // 把类成员变量的声明加入符号表
            virtual void enterVariableDeclaratorId(PlayScriptParser::VariableDeclaratorIdContext *ctx);

            // 设置函数的返回值类型
            virtual void exitFunctionDeclaration(PlayScriptParser::FunctionDeclarationContext *ctx);

            // 设置函数的参数的类型，这些参数已经在enterVariableDeclaratorId中作为变量声明了，现在设置它们的类型
            virtual void exitFormalParameter(PlayScriptParser::FormalParameterContext *ctx);

            // 设置类的父类
            virtual void enterClassDeclaration(PlayScriptParser::ClassDeclarationContext *ctx);

            virtual void exitTypeTypeOrVoid(PlayScriptParser::TypeTypeOrVoidContext *ctx);

            virtual void exitTypeType(PlayScriptParser::TypeTypeContext *ctx);

            virtual void enterClassOrInterfaceType(PlayScriptParser::ClassOrInterfaceTypeContext *ctx);

            virtual void exitFunctionType(PlayScriptParser::FunctionTypeContext *ctx);

            virtual void exitPrimitiveType(PlayScriptParser::PrimitiveTypeContext *ctx);

            virtual void exitLiteral(PlayScriptParser::LiteralContext *ctx);
    };
};

#endif