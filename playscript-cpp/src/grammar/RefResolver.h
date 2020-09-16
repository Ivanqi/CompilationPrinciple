#ifndef REFRESOLVER_H
#define REFRESOLVER_H

#pragma
#include "PlayScriptBaseListener.h"
#include "PlayScriptParser.h"
#include "tree/ParseTreeWalker.h"
#include "TypeResolver.h"

#include <vector>
using namespace antlr4;
using namespace antlr4::tree;

namespace play
{
    class AnnotatedTree;
    class Type;

    /**
     * 语义解析的第三步：引用消解和类型推断
     *  1. 解析所有的本地变量引用，函数调用和类成语引用
     *  2. 类型推断：从下而上推断表达式的类型
     * 
     * 这两件事要放在一起，因为
     *  1. 对于变量，只有做了消解，才能推断类型来
     *  2. 对于FunctionCall，只有把参数(表达式)的类型都推断出来，才能匹配到正确的函数(方法)
     *  3. 表达式里包含FunctionCall，所以要推导表达式的类型，必须知道那个是Function，从而才能得到返回值
     * 
     * 这个时候，对所有变量，函数调用，都会跟它的定义关联起来，并且完成了所有类型计算
     */
    class RefResolver: public PlayScriptBaseListener
    {
        private:
            AnnotatedTree *at_;

            // 用于把本地变量添加到符号表，并计算类型
            ParseTreeWalker typeResolverWalker;

            TypeResolver *localVariableEnter_;


            // this() 和 super()构造函数留到最后去消解，因为它可能引用别的构造函数，必须等到这些构造函数都消解完
            std::vector<PlayScriptParser::FunctionCallContext*> thisConstructorList;
            std::vector<PlayScriptParser::FunctionCallContext*> superConstructorList;

            // 获得函数的参数列表
            std::vector<Type*> getParamTypes(PlayScriptParser::FunctionCallContext* ctx);

            // 消解this()构造函数
            void resolveThisConstructorCall(PlayScriptParser::FunctionCallContext *ctx);

            bool firstStatmentInFunction(PlayScriptParser::FunctionDeclarationContext *fdx, PlayScriptParser::FunctionCallContext *ctx);

            /**
             * 消解Super()构造函数
             * TODO 对于调用super()是有要求的，比如：
             *  1)必须出现在构造函数的第一行，
             *  2)this()和super不能同时出现，等等。
             */
            void resolveSuperConstructorCall(PlayScriptParser::FunctionCallContext *ctx);

        public:
            RefResolver(AnnotatedTree *at):at_(at)
            {
                localVariableEnter_ = new TypeResolver(at, true);
            }

            // 把本地变量加到符号表。本地变量必须边添加，边解析，不然先添加后解析，否则会引起消解的错误
            virtual void enterVariableDeclarators(PlayScriptParser::VariableDeclaratorsContext *ctx);

            virtual void exitPrimary(PlayScriptParser::PrimaryContext *ctx);

            virtual void exitFunctionCall(PlayScriptParser::FunctionCallContext *ctx);

            // 消解处理点符号表达式的层层引用
            virtual void exitExpression(PlayScriptParser::ExpressionContext *ctx);
    };
};
#endif