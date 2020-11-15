#include "FieldEvaluator.h"

#include "PrimitiveType.h"
#include "TabularData.h"
#include "DyArray.h"

#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

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

    return rtn;
}

antlrcpp::Any FieldEvaluator::visitPrimary(PlayReportParser::PrimaryContext *ctx)
{
    antlrcpp::Any rtn = nullptr;

    if (ctx->IDENTIFIER() != nullptr) {
        string fieldName = ctx->IDENTIFIER()->getText();
        rtn = data_->getField(fieldName);

    } else if (ctx->literal() != nullptr) {
        rtn = visitLiteral(ctx->literal());
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

    return rtn;
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

    string functionName = ctx->IDENTIFIER()->getText();
    transform(functionName.begin(), functionName.end(), functionName.begin(), 
        [](unsigned char c) -> unsigned char { return tolower(c); });

    if (functionName.compare("rank") == 0) {
        rtn = rank(ctx);

    } else if (functionName.compare("max") == 0) {
        rtn = max(ctx);

    } else if (functionName.compare("sum") == 0) {
        rtn = sum(ctx);

    } else if (functionName.compare("runningsum") == 0) {
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

static bool max_compare(antlrcpp::Any a, antlrcpp::Any b)
{
    if (a.is<int>() && b.is<int>()) {
        return (a.as<int>() > b.as<int>());

    } else if (a.is<long>() && b.is<long>()) {
        return (a.as<long>() > b.as<long>());

    } else if (a.is<float>() && b.is<float>()) {
        return (a.as<float>() > b.as<float>());

    } else if (a.is<double>() && b.is<double>()) {
        return (a.as<double>() > b.as<double>());

    } else {
        return false;
    }
}

// 求排序值(向量)
antlrcpp::Any FieldEvaluator::rank(PlayReportParser::FunctionCallContext *ctx)
{
    antlrcpp::Any rtn = nullptr;

    string functionFieldName = ctx->getText();

    if (!data_->hasField(functionFieldName)) {
        // 计算参数列
        string fieldName = ctx->expressionList()->expression(0)->getText();
        if (!data_->hasField(fieldName)) {
            addCalculatedField(ctx->expressionList()->expression(0));
        }

        antlrcpp::Any rank = nullptr;

        // 计算rank
        antlrcpp::Any tmp = data_->getField(fieldName);

        if (tmp.is<std::vector<antlrcpp::Any>>()) {
            vector<antlrcpp::Any> paramCol = tmp.as<std::vector<antlrcpp::Any>>();
            vector<antlrcpp::Any> sorted;
            sorted.assign(paramCol.begin(), paramCol.end());
            sort(sorted.begin(), sorted.end(), max_compare);

            vector<antlrcpp::Any> rankList(paramCol.size());
            rank = rankList;

            int numRows = data_->getNumRows();
   
            // O(n^2)
            for (antlrcpp::Any obj: paramCol) {
                int index = 0;
                for (antlrcpp::Any o: sorted) {
                    if (o.equals(obj)){
                        break;
                    }
                    index++;
                }
                rankList.emplace_back(numRows - index);
            }

        } else {    //  标量
            rank = 1;
        }

        // 增加一个字段
        data_->setField(functionFieldName, rank);
    }

    data_->getField(functionFieldName);
    return rtn;

}

// 求最大值（标量）
antlrcpp::Any FieldEvaluator::max(PlayReportParser::FunctionCallContext *ctx)
{
    antlrcpp::Any rtn = nullptr;
    string functionFieldName = ctx->getText();

    if (!data_->hasField(functionFieldName)) {
        // 计算参数列 
        string fieldName = ctx->expressionList()->expression(0)->getText();
        if (!data_->hasField(fieldName)) {
            addCalculatedField(ctx->expressionList()->expression(0));
        }

        // 计算 max
        antlrcpp::Any max = nullptr;
        antlrcpp::Any field = data_->getField(fieldName);
        // todo 这里有点问题
        if (field.is<DyArray<antlrcpp::Any>*>()) {
            DyArray<antlrcpp::Any> *paramCol = field.as<DyArray<antlrcpp::Any>*>();
            // if (paramCol->size() > 0) {
            //     antlrcpp::Any result = std::max_element(paramCol.begin(), paramCol.end(), max_compare);

            //     if (result.is<int>()) {
            //         max = result.as<int>();

            //     } else if (result.is<long>()) {
            //         max = result.as<long>();

            //     } else if (result.is<float>()) {
            //         max = result.as<float>();

            //     } else if (result.is<double>()) {
            //         max = result.as<double>();
            //     }
            // }
        } else {    // 标量
            max = field;
        }

        // 增加一个field
        data_->setField(functionFieldName, max);
    }

    rtn = data_->getField(functionFieldName);
    return rtn;
}

// 求汇总值（标量）
antlrcpp::Any FieldEvaluator::sum(PlayReportParser::FunctionCallContext *ctx)
{
    antlrcpp::Any rtn = nullptr;
    string functionFieldName = ctx->getText();

    if (!data_->hasField(functionFieldName)) {
        // 计算参数列 
        string fieldName = ctx->expressionList()->expression(0)->getText();
        if (!data_->hasField(functionFieldName)) {
            addCalculatedField(ctx->expressionList()->expression(0));
        }

        // 计算 max
        antlrcpp::Any sum = nullptr;
        antlrcpp::Any field = data_->getField(fieldName);

        if (field.is<vector<antlrcpp::Any>>()) {
            vector<antlrcpp::Any> paramCol = field.as<vector<antlrcpp::Any>>();
            if (paramCol.size() > 0) {
                auto tmp = 0;
                for (antlrcpp::Any obj: paramCol) {
                    if (obj.is<int>()) {
                        tmp += obj.as<int>();

                    } else if (obj.is<long>()) {
                        tmp += obj.as<long>();

                    } else if (obj.is<float>()) {
                        tmp += obj.as<float>();

                    } else if (obj.is<double>()) {
                        tmp += obj.as<double>();
                    }
                }
                sum = tmp;
            }
        } else {    // 标量
            sum = field;
        }

        // 增加一个field
        data_->setField(functionFieldName, sum);
    }

    rtn = data_->getField(functionFieldName);
    return rtn;
}

// 求累计汇总值（向量）
antlrcpp::Any FieldEvaluator::runningSum(PlayReportParser::FunctionCallContext *ctx)
{
    antlrcpp::Any rtn = nullptr;
    string functionFieldName = ctx->getText();

    if (!data_->hasField(functionFieldName)) {
        // 计算参数列 
        string fieldName = ctx->expressionList()->expression(0)->getText();
        if (!data_->hasField(functionFieldName)) {
            addCalculatedField(ctx->expressionList()->expression(0));
        }

        antlrcpp::Any runningSum = nullptr;

        // 计算rank
        antlrcpp::Any field = data_->getField(fieldName);

        if (field.is<vector<antlrcpp::Any>>()) {
            vector<antlrcpp::Any> paramCol = field.as<vector<antlrcpp::Any>>();
            if (paramCol.size() > 0) {
                antlrcpp::Any first = paramCol[0];                
                if (first.is<int>()) {
                    vector<int> runningSumTmp;
                    int iSum = 0;
                    for (antlrcpp::Any o: paramCol) {
                        iSum += o.as<int>();
                        runningSumTmp.emplace_back(iSum);
                    }

                } else if (first.is<long>()) {
                    long lSum = 0l;
                    vector<long> runningSumTmp;
                    for (antlrcpp::Any o: paramCol) {
                        lSum += o.as<long>();
                        runningSumTmp.emplace_back(lSum);
                    }

                } else if (first.is<double>()) {
                    double dSum = 0.0;
                    vector<double> runningSumTmp;
                    for (antlrcpp::Any o: paramCol) {
                        dSum += o.as<double>();
                        runningSumTmp.emplace_back(dSum);
                    }

                }
            }

        } else {    // 标量
            runningSum = data_->getField(fieldName);
        }

        // 增加一个字段
        data_->setField(functionFieldName, runningSum);
    }

    rtn = data_->getField(functionFieldName);

    return rtn;
}

// 根据公式，往数据源里添加一个计算字段
void FieldEvaluator::addCalculatedField(PlayReportParser::ExpressionContext *ctx)
{
    antlrcpp::Any value = nullptr;
    string fieldName = ctx->getText();
    data_->setField(fieldName, value);
}

// 工具性的方法
PrimitiveType* FieldEvaluator::calcType(antlrcpp::Any obj1, antlrcpp::Any obj2)
{
    PrimitiveType *type = PrimitiveType::String;

    // 处理向量的情况
    bool obj1Status = obj1.is<DyArray<antlrcpp::Any>*>();
    if (obj1Status) {
        DyArray<antlrcpp::Any> *tmp1 = obj1.as<DyArray<antlrcpp::Any>*>();
        if (tmp1->size() > 0) {
            obj1 = tmp1->get(0);
        }
    }

    bool obj2Status = obj2.is<DyArray<antlrcpp::Any>*>();
    if (obj2Status) {
        DyArray<antlrcpp::Any> *tmp2 = obj2.as<DyArray<antlrcpp::Any>*>();
        if (tmp2->size() > 0) {
            obj2 = tmp2->get(0);
        }
    }

    if (obj1.is<string>() || obj2.is<string>()) {
        type = PrimitiveType::String;

    } else if (obj1.is<double>() || obj2.is<double>()) {
        type = PrimitiveType::Double;

    } else if (obj1.is<float>() || obj2.is<float>()) {
        type = PrimitiveType::Float;

    } else if (obj1.is<long>() || obj2.is<long>()) {
        type = PrimitiveType::Long;

    } else if (obj1.is<int>() || obj2.is<int>()) {
        type = PrimitiveType::Integer;
    }

    return type;
}