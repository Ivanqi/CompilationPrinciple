#include "SQLVisitor.h"
#include "WhereExpr.h"
#include "SelectStmt.h"
#include <iostream>


antlrcpp::Any SQLVisitor::visitSql_stmt(SqlParsingParser::Sql_stmtContext *ctx)
{
    antlrcpp::Any result = nullptr;

    if (ctx->select_stmt() != nullptr && ctx->select_stmt()->select_core().size() > 0) {
        result = visitSelect_core(ctx->select_stmt()->select_core(0));
    }

    return result;
}

antlrcpp::Any SQLVisitor::visitSelect_core(SqlParsingParser::Select_coreContext *ctx)
{
    antlrcpp::Any result = nullptr;

    std::string tableName = "";

    std::list<WhereExpr*> whereExprs;

    antlrcpp::Any tmp = nullptr;

    if (ctx->FROM() != nullptr) {
        if (ctx->table_or_subquery().size() > 0) {
            tmp = visitTable_or_subquery(ctx->table_or_subquery(0));
            if (tmp.is<std::string>()) {
                tableName = tmp.as<std::string>();
            } else {
                std::cout << "visitTable_or_subquery tableName error " << std::endl; 
            }
        }
    }

    if (ctx->WHERE() != nullptr) {
        if (ctx->expr().size() > 0) {
            tmp = visitExpr(ctx->expr(0));
            if (tmp.is<std::list<WhereExpr*>>()) {
                whereExprs = tmp.as<std::list<WhereExpr*>>();
            } else {
                std::cout << "visitTable_or_subquery whereExprs error " << std::endl; 
            }
        }
    }
    std::cout << "xxxx" << std::endl;
    result = new SelectStmt(tableName, whereExprs);

    return result;
}

antlrcpp::Any SQLVisitor::visitTable_or_subquery(SqlParsingParser::Table_or_subqueryContext *ctx)
{
    antlrcpp::Any result = nullptr;

    if (ctx->table_name() != nullptr) {
        result = visitTable_name(ctx->table_name());
    }
    return result;
}

antlrcpp::Any SQLVisitor::visitTable_name(SqlParsingParser::Table_nameContext *ctx)
{
    antlrcpp::Any result = nullptr;

    if (ctx->any_name() != nullptr) {
        result = visitAny_name(ctx->any_name());
    }

    return result;
}

antlrcpp::Any SQLVisitor::visitAny_name(SqlParsingParser::Any_nameContext *ctx)
{
    antlrcpp::Any result = nullptr;
    std::cout << ctx->toString() << std::endl;

    if (ctx->IDENTIFIER() != nullptr) {
        result = ctx->IDENTIFIER()->getText();
    }

    return result;
}

void addWhereExpr(std::list<WhereExpr*> l, antlrcpp::Any obj)
{
    if (obj.is<WhereExpr*>()) {
        WhereExpr *exprTmp = obj.as<WhereExpr*>();
        l.push_back(exprTmp);
    } else if (obj.is<std::list<WhereExpr*>>()) {
        std::list<WhereExpr*> tmp = obj.as<std::list<WhereExpr*>>();
        l.merge(tmp);
    }
}

antlrcpp::Any SQLVisitor::visitExpr(SqlParsingParser::ExprContext *ctx)
{
    antlrcpp::Any result = nullptr;
    
    if (ctx->AND() != nullptr) {
        antlrcpp::Any left =  visitExpr(ctx->expr(0));
        antlrcpp::Any right = visitExpr(ctx->expr(1));

        std::list<WhereExpr*> list;
        addWhereExpr(list, left);
        addWhereExpr(list, right);
        result = list;


    } else if (ctx->ASSIGN() != nullptr) {

        std::string left = visitExpr(ctx->expr(0));
        std::string right = visitExpr(ctx->expr(1));

        result = new WhereExpr(left, "=", right);

    } else if (ctx->literal_value() != nullptr) {
        result = visitLiteral_value(ctx->literal_value());

    } else if (ctx->column_name() != nullptr) {
        result = visitColumn_name(ctx->column_name());
    }

    return result;
}

antlrcpp::Any SQLVisitor::visitLiteral_value(SqlParsingParser::Literal_valueContext *ctx)
{
    antlrcpp::Any result = nullptr;

    if (ctx->STRING_LITERAL() != nullptr) {
        result = ctx->STRING_LITERAL()->getText();
    }

    return result;
}

antlrcpp::Any SQLVisitor::visitColumn_name(SqlParsingParser::Column_nameContext *ctx)
{
    antlrcpp::Any result = nullptr;

    if (ctx->any_name() != nullptr) {
        result = visitAny_name(ctx->any_name());
    }

    return result;
}


