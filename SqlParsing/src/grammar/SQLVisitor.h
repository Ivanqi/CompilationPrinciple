#ifndef SQLVISITOR_H
#define SQLVISITOR_H

#include "antlr4-runtime.h"
#include "SqlParsingBaseVisitor.h"

class SQLVisitor: public SqlParsingBaseVisitor
{
    antlrcpp::Any visitSql_stmt(SqlParsingParser::Sql_stmtContext *context);

    antlrcpp::Any visitSelect_core(SqlParsingParser::Select_coreContext *context);

    antlrcpp::Any visitTable_or_subquery(SqlParsingParser::Table_or_subqueryContext *context);

    antlrcpp::Any visitTable_name(SqlParsingParser::Table_nameContext *context);

    antlrcpp::Any visitAny_name(SqlParsingParser::Any_nameContext *context);

    antlrcpp::Any visitExpr(SqlParsingParser::ExprContext *context);

    antlrcpp::Any visitLiteral_value(SqlParsingParser::Literal_valueContext *context);

    antlrcpp::Any visitColumn_name(SqlParsingParser::Column_nameContext *context);
};

#endif