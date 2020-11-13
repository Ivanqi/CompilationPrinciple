#ifndef FIELDEVALUATOR_H
#define FIELDEVALUATOR_H
#include "antlr4-runtime.h"
#include "PlayReportBaseVisitor.h"
#include "PlayReportParser.h"

#include "Add.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include "EQ.h"
#include "GE.h"
#include "GT.h"
#include "LE.h"
#include "LT.h"

class TabularData;
class PrimitiveType;

class FieldEvaluator: public PlayReportBaseVisitor
{

    private:
        // 报表数据
        TabularData *data_ = nullptr;

        Add *add = new Add();
        Minus *minus = new Minus();
        Mul *mul = new Mul();
        Div *div = new Div();
        EQ *eq = new EQ();
        GE *ge =  new GE();
        GT *gt = new GT();
        LE *le = new LE();
        LT *lt = new LT();

    public:
        FieldEvaluator(TabularData *data);

    public:

        antlrcpp::Any visitBracedExpression(PlayReportParser::BracedExpressionContext *ctx);

        antlrcpp::Any visitExpression(PlayReportParser::ExpressionContext *ctx);

        antlrcpp::Any visitPrimary(PlayReportParser::PrimaryContext *ctx);

        antlrcpp::Any visitLiteral(PlayReportParser::LiteralContext *ctx);

        antlrcpp::Any visitFloatLiteral(PlayReportParser::FloatLiteralContext *ctx);

        antlrcpp::Any visitIntegerLiteral(PlayReportParser::IntegerLiteralContext *ctx);

        antlrcpp::Any visitFunctionCall(PlayReportParser::FunctionCallContext *ctx);

        antlrcpp::Any visitExpressionList(PlayReportParser::ExpressionListContext *ctx);

    private:
        // 求排序值(向量)
        antlrcpp::Any rank(PlayReportParser::FunctionCallContext *ctx);

        // 求最大值（标量）
        antlrcpp::Any max(PlayReportParser::FunctionCallContext *ctx);

        // 求汇总值（标量）
        antlrcpp::Any sum(PlayReportParser::FunctionCallContext *ctx);

        // 求累计汇总值（向量）
        antlrcpp::Any runningSum(PlayReportParser::FunctionCallContext *ctx);

        // 根据公式，往数据源里添加一个计算字段
        void addCalculatedField(PlayReportParser::ExpressionContext *ctx);

        // 工具性的方法
        PrimitiveType* calcType(antlrcpp::Any *obj1, antlrcpp::Any *obj2);
};


#endif