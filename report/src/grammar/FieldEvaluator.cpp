#include "FieldEvaluator.h"
#include "Add.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include "EQ.h"
#include "GE.h"
#include "GT.h"
#include "LE.h"
#include "LT.h"
#include "PrimitiveType.h"

#include <string>
#include <algorithm>

FieldEvaluator::FieldEvaluator()
{
    Add *add = new Add();
    Minus *minus = new Minus();
    Mul *mul = new Mul();
    Div *div = new Div();
    EQ *eq = new EQ();
    GE *ge = new GE();
    GT *gt = new GT();
    LE *le = new LE();
    LT *lt = new LT;
}

FieldEvaluator::FieldEvaluator(TabularData *data): data_(data)
{

}

antlrcpp::Any FieldEvaluator::visitBracedExpression(PlayReportParser::BracedExpressionContext *ctx)
{
    return visitExpression(ctx->expression());
}

antlrcpp::Any FieldEvaluator::visitExpression(PlayReportParser::ExpressionContext *ctx)
{
    antlrcpp::Any rtn = nullptr;

    if (ctx->bop != nullptr && ctx->expression().size() >= 2) {
        antlrcpp::Any left = visitExpression(ctx->expression(0));
        antlrcpp::Any right = visitExpression(ctx->expression(1));

        PrimitiveType *type = calcType(left, right);

        switch (ctx->bop->getType()) {
            case PlayReportParser::ADD:
                rtn = add->vectorOp(left, right, type);
                break;
            
            case PlayReportParser::SUB:
                rtn = minus->vectorOp(left, right, type);
                break;
            
            case PlayReportParser::MUL:
                rtn = mul->vectorOp(left, right, type);
                break;
            
            case PlayReportParser::DIV:
                rtn = div->vectorOp(left, right, type);
                break;
            
            case PlayReportParser::EQUAL:
                rtn = eq->vectorOp(left, right, type);
                break;
            
            case PlayReportParser::LE:
                rtn = le->vectorOp(left, right, type);
                break;
            
            case PlayReportParser::LT:
                rtn = lt->vectorOp(left, right, type);
                break;
            
            case PlayReportParser::GE:
                rtn = ge->vectorOp(left, right, type);
                break;
            
            case PlayReportParser::GT:
                rtn = gt->vectorOp(left, right, type);
                break;
            
            default:
                break;
        }

    } else if (ctx->primary() != nullptr) {
        rtn = visitPrimary(ctx->primary());

    } else if (ctx->functionCall() != nullptr) {
        rtn = visitFunctionCall(ctx->functionCall());
    }
}

antlrcpp::Any FieldEvaluator::visitPrimary(PlayReportParser::PrimaryContext *ctx)
{
    antlrcpp::Any rtn = nullptr;

    if (ctx->literal() != nullptr) {
        rtn = visitLiteral(ctx->literal());

    } else if (ctx->IDENTIFIER() != nullptr) {
        std::string fieldName = ctx->IDENTIFIER()->getText();
        rtn = data_->getField(fieldName);
    }

    return rtn;
}

antlrcpp::Any FieldEvaluator::visitLiteral(PlayReportParser::LiteralContext *ctx)
{
    antlrcpp::Any rtn = nullptr;

    if (ctx->integerLiteral() != nullptr) {
        rtn = visitIntegerLiteral(ctx->integerLiteral());

    } else if (ctx->floatLiteral() != nullptr) {
        rtn = visitFloatLiteral(ctx->floatLiteral());

    } else if (ctx->BOOL_LITERAL() != nullptr) {
        if (ctx->BOOL_LITERAL()->getText().compare("true")) {
            rtn = true;
        } else {
            rtn = false;
        }

    } else if (ctx->STRING_LITERAL() != nullptr) {
        std::string withQuotationMark = ctx->STRING_LITERAL()->getText();
        rtn = withQuotationMark.substr(1, withQuotationMark.length() - 1);

    } else if (ctx->CHAR_LITERAL() != nullptr) {
        rtn = ctx->CHAR_LITERAL()->getText()[0];
    }
}

antlrcpp::Any FieldEvaluator::visitFloatLiteral(PlayReportParser::FloatLiteralContext *ctx)
{
    return (float)atof(ctx->getText().c_str());
}

antlrcpp::Any FieldEvaluator::visitIntegerLiteral(PlayReportParser::IntegerLiteralContext *ctx)
{
    antlrcpp::Any rtn = nullptr;
    if (ctx->DECIMAL_LITERAL() != nullptr) {
        int tmp = atoi(ctx->DECIMAL_LITERAL()->getText().c_str());
        rtn = tmp;
    }
    return rtn;
}

antlrcpp::Any FieldEvaluator::visitFunctionCall(PlayReportParser::FunctionCallContext *ctx)
{
    antlrcpp::Any rtn = nullptr;

    std::string functionName = ctx->IDENTIFIER()->getText();
    functionName = std::transform(functionName.begin(), functionName.end(), functionName.begin(), std::tolower);

    if (functionName.compare("rank")) {
        rtn = rank(ctx);

    } else if (functionName.compare("max")) {
        rtn = max(ctx);

    } else if (functionName.compare("sum")) {
        rtn = sum(ctx);

    } else if (functionName.compare("runningsum")) {
        rtn = runningSum(ctx);
    }

    return rtn;
}

antlrcpp::Any FieldEvaluator::visitExpressionList(PlayReportParser::ExpressionListContext *ctx)
{
    antlrcpp::Any rtn = nullptr;

    for (PlayReportParser::ExpressionContext *child: ctx->expression()) {
        rtn = visitExpression(child);
    }

    return rtn;
}

// 求排序值(向量)
antlrcpp::Any FieldEvaluator::rank(PlayReportParser::FunctionCallContext *ctx)
{
    antlrcpp::Any rtn = nullptr;

    std::string functionFieldName = ctx->getText();

    if (!data_->hasField(functionFieldName)) {
        // 计算参数列
        std::string fieldName = ctx->expressionList()->expression(0)->getText();
        if (!data_->hasField(fieldName)) {
            addCalculatedField(ctx->expressionList()->expression(0));
        }

        antlrcpp::Any rank = nullptr;

        // 计算rank
        antlrcpp::Any tmp = data_->getField(fieldName);

        if (tmp.is<std::vector<antlrcpp::Any>>()) {
            std::vector<antlrcpp::Any> paramCol = tmp.as<std::vector<antlrcpp::Any>>();
            std::vector<antlrcpp::Any> sorted;
            sorted.assign(paramCol.begin(), paramCol.end());
            std::sort(sorted.begin(), sorted.end());

            std::vector<antlrcpp::Any> rankList(paramCol.size());
            rank = rankList;

            int numRows = data_->getNumRows();
            // todo 这里有点问题
            for (antlrcpp::Any obj: paramCol) {
                auto iter = std::find(sorted.begin(), sorted.end(), obj);
                int index = std::distance(sorted.begin(), iter);

                rankList.push_back(numRows - index);
            }
        } else {    //  标量
            rank = 1;
        }

        // 增加一个字段
        data_->getField(functionFieldName);

        return rtn;
    }
}

// 求最大值（标量）
antlrcpp::Any FieldEvaluator::max(PlayReportParser::FunctionCallContext *ctx)
{
    antlrcpp::Any rtn = nullptr;
    std::string functionFieldName = ctx->getText();

    if (!data_->hasField(functionFieldName)) {
        // 计算参数列 
        std::string fieldName = ctx->expressionList()->expression(0)->getText();
        if (!data_->hasField(functionFieldName)) {
            addCalculatedField(ctx->expressionList()->expression(0));
        }

        // 计算 max
        antlrcpp::Any rtn = nullptr;
        antlrcpp::Any field = data_->getField(fieldName);

        if (field.is<std::vector<antlrcpp::Any>>()) {
            std::vector<antlrcpp::Any> paramCol = field.as<std::vector<antlrcpp::Any>>();
            if (paramCol.size() > 0) {
                antlrcpp::Any firstTmp = paramCol[0];
                if (firstTmp.is<int>()) {
                    max = paramCol
                }
            }
        }
    }
}

// 求汇总值（标量）
antlrcpp::Any FieldEvaluator::sum(PlayReportParser::FunctionCallContext *ctx);

// 求累计汇总值（向量）
antlrcpp::Any FieldEvaluator::runningSum(PlayReportParser::FunctionCallContext *ctx);

// 根据公式，往数据源里添加一个计算字段
void FieldEvaluator::addCalculatedField(PlayReportParser::ExpressionContext *ctx);

// 工具性的方法
PrimitiveType* FieldEvaluator::calcType(antlrcpp::Any obj1, antlrcpp::Any obj2);