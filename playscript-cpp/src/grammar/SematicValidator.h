#ifndef SEMATICVALIDATOR_H
#define SEMATICVALIDATOR_H

#include "PlayScriptBaseListener.h"
#include "PlayScriptParser.h"
#include "ParserRuleContext.h"
#include "tree/ParseTree.h"
using namespace antlr4;
using namespace antlr4::tree;

namespace play
{
    class AnnotatedTree;
    /**
     * 进行一些语义检查，包括：
     *  01.break 只能出现在循环语句中，或case语句中；
     *  
     *  02.return语句
     *      02-01 函数声明了返回值，就一定要有return语句。除非返回值类型是void。
     *      02-02 类的构造函数里如果用到return，不能带返回值。
     *      02-03 return语句只能出现在函数里。
     *      02-04 返回值类型检查 -> (在TypeChecker里做）
     * 
     * 03.左值
     *      03-01 标注左值（不标注就是右值)；
     *      03-02 检查表达式能否生成合格的左值
     * 
     * 04.类的声明不能在函数里（TODO 未来应该也可以，只不过对生存期有要求）
     * 
     * 05.super()和this()，只能是构造函数中的第一句。  这个在RefResolver中实现了。
     */
    class SematicValidator: public PlayScriptBaseListener
    {
        private:
            AnnotatedTree *at_;

        private:
            // 检查一个函数里有没有return语句
            bool hasReturnStatement(ParseTree *ctx);

            // break只能出现在循环语句或switch-case语句里
            bool checkBreak(RuleContext *ctx);

        public:
            SematicValidator(AnnotatedTree *at): at_(at)
            {

            }

            virtual void exitPrimary(PlayScriptParser::PrimaryContext *ctx);

            virtual void exitFunctionCall(PlayScriptParser::FunctionCallContext *ctx);

            virtual void exitExpression(PlayScriptParser::ExpressionContext *ctx);

            virtual void exitClassDeclaration(PlayScriptParser::ClassDeclarationContext *ctx);

            virtual void exitFunctionDeclaration(PlayScriptParser::FunctionDeclarationContext *ctx);

            virtual void exitVariableDeclarators(PlayScriptParser::VariableDeclaratorsContext *ctx);

            virtual void exitVariableDeclarator(PlayScriptParser::VariableDeclaratorContext *ctx);

            virtual void exitVariableDeclaratorId(PlayScriptParser::VariableDeclaratorIdContext *ctx);

            // 对变量初始化部分也做一下类型推断
            virtual void exitVariableInitializer(PlayScriptParser::VariableInitializerContext *ctx);

            // 根据字面量来推断类型
            virtual void exitLiteral(PlayScriptParser::LiteralContext *ctx);

            virtual void exitStatement(PlayScriptParser::StatementContext *ctx);
    };
};

#endif