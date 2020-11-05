#include <iostream>
#include "PlayReport.h"
#include "ReportTemplate.h"
#include "TabularData.h"
#include "FieldEvaluator.h"
using namespace antlr4;

std::string PlayReport::renderReport(ReportTemplate *temp, TabularData *data)
{
    std::string sb;

    // 输出表格头
    for (std::string columnHeader: temp->columnHeaders) {
        sb.append(columnHeader).append("\t");
    }

    sb.append("\n");

    // 编译报表的每个字段
    std::vector<PlayReportParser::BracedExpressionContext*> fieldASTs;
    for (std::string fieldExpr: temp->fields) {
        PlayReportParser::BracedExpressionContext *tree = parse(fieldExpr);
        fieldASTs.push_back(tree);
    }

    // 计算报表字段
    FieldEvaluator *evaluator = new FieldEvaluator(data);
    std::vector<std::string> fieldNames;

    for (PlayReportParser::BracedExpressionContext *fieldAST : fieldASTs) {
        std::string fieldName = fieldAST->expression()->getText();
        fieldNames.push_back(fieldName);

        if (!data->hasField(fieldName)) {
            antlrcpp::Any field = evaluator->visit(fieldAST);
            data->setField(fieldName, field);
        }
    }

    // 现实每一行数据
    for (int row = 0; row < data->getNumRows(); row++) {
        for (std::string fieldName : fieldNames) {
            antlrcpp::Any value = data->getFieldValue(fieldName, row);
            if (value.is<std::string>()) {
                std::string tmp = value.as<std::string>();
                sb.append(tmp).append("\t");
            } else {
                std::cout << "data->getFieldValue isn't string" << std::endl;
            }
        }
    }

    return sb;
}

PlayReportParser::BracedExpressionContext* PlayReport::parse(std::string exp)
{
    // 词法解析
    PlayReportLexer *lexer = new PlayReportLexer(new ANTLRInputStream(exp));
    CommonTokenStream *tokens = new CommonTokenStream(lexer);

    // 语法解析
    PlayReportParser *parser = new PlayReportParser(tokens);

    PlayReportParser::BracedExpressionContext *tree = parser->bracedExpression();

    // 以lisp格式打印AST
    std::cout << tree->toStringTree() << std::endl;

    return tree;
}