// 一个简短的测试程序，只支持整数常量做加减乘除四则运算
#pragma once

#include "PlayScriptBaseVisitor.h"
#include <stack>
#include "StackFrame.h"

class ASTEvaluator: public PlayScriptBaseVisitor 
{  
    private:
        stack<StackFrame*> stacks;

    public:
        void pushStack(StackFrame *frame);

        virtual antlrcpp::Any visitExpression(PlayScriptParser::ExpressionContext *ctx) override;

        virtual antlrcpp::Any visitPrimary(PlayScriptParser::PrimaryContext *ctx) override;

        virtual antlrcpp::Any visitLiteral(PlayScriptParser::LiteralContext *ctx) override;

        virtual antlrcpp::Any visitIntegerLiteral(PlayScriptParser::IntegerLiteralContext *ctx) override;

        virtual antlrcpp::Any visitFloatLiteral(PlayScriptParser::FloatLiteralContext *ctx) override;
};