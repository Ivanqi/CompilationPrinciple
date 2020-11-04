#include <iostream>
#include "PlayReport.h"
#include "ReportTemplate.h"
#include "TabularData.h"

std::string PlayReport::renderReport(ReportTemplate *temp, TabularData *data)
{
    std::string sb;

    // 输出表格头
    for (std::string columnHeader: temp->columnHeaders) {
        sb.append(columnHeader).append("\t");
    }

    sb.append("\n");

    // 编译报表的每个字段
    std::vector<BracedExpressionContext*> fieldASTs;
    for (std::string fieldExpr: temp->fields) {
        BracedExpressionContext *tree = parse(fieldExpr);
        fieldASTs.push_back(tree);
    }

    // 计算报表字段
    
}

PlayReportParser::BracedExpressionContext* PlayReport::parse(std::string exp)
{
    // 词法解析
    PlayReportLexer *lexer = new PlayReportLexer(CharStream(exp));
    CommonTokenStream *tokens = new CommonTokenStream(lexer);

    // 语法解析
    PlayReportParser *parser = new PlayReportParser(tokens);

    PlayReportParser::BracedExpressionContext *tree = parser->bracedExpression();

    // 以lisp格式打印AST
    std::cout << tree->toStringTree() << std::endl;

    return tree;
}