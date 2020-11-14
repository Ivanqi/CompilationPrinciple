#include <iostream>
#include "PlayReport.h"
#include "ReportTemplate.h"
#include "TabularData.h"
#include "FieldEvaluator.h"
#include "CharStr.h"
using namespace antlr4;
using namespace std;

string PlayReport::renderReport(ReportTemplate *temp, TabularData *data)
{
    std::string sb;

    // 输出表格头
    for (std::string columnHeader: temp->columnHeaders) {
        sb.append(columnHeader).append("\t");
    }

    sb.append("\n");

    // 编译报表的每个字段
    vector<PlayReportParser::BracedExpressionContext*> fieldASTs;
    for (string fieldExpr: temp->fields) {
        PlayReportParser::BracedExpressionContext *tree = parse(fieldExpr);
        fieldASTs.push_back(tree);
    }

    // 计算报表字段
    FieldEvaluator *evaluator = new FieldEvaluator(data);
    vector<std::string> fieldNames;

    for (PlayReportParser::BracedExpressionContext *fieldAST : fieldASTs) {
        string fieldName = fieldAST->expression()->getText();
        fieldNames.push_back(fieldName);

        if (!data->hasField(fieldName)) {
            cout << fieldName << endl;
            antlrcpp::Any field = evaluator->visit(fieldAST);
            data->setField(fieldName, field);
        }
    }

    // 现实每一行数据
    string tmp;
    for (int row = 0; row < data->getNumRows(); row++) {
        for (string fieldName : fieldNames) {
            antlrcpp::Any value = data->getFieldValue(fieldName, row);
            tmp.clear();
            if (value.is<string>()) {
                tmp = value.as<string>();
            } else if (value.is<double>()) {
                double tmpD = value.as<double>();
                tmp = to_string(tmpD);
            } else if (value.is<int>()) {
                int tmpI = value.as<int>();
                tmp = to_string(tmpI);
            } else if (value.is<CharStr*>()) {
                CharStr *tmpC = value.as<CharStr*>();
                tmp = tmpC->getCharStr();
            }

            sb.append(tmp).append("\t");            
        }
        sb.append("\n");
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