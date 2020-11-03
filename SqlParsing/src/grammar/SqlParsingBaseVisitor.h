
// Generated from SqlParsing.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "SqlParsingVisitor.h"


/**
 * This class provides an empty implementation of SqlParsingVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SqlParsingBaseVisitor : public SqlParsingVisitor {
public:

  virtual antlrcpp::Any visitSql_stmt_list(SqlParsingParser::Sql_stmt_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSql_stmt(SqlParsingParser::Sql_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlter_table_stmt(SqlParsingParser::Alter_table_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnalyze_stmt(SqlParsingParser::Analyze_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttach_stmt(SqlParsingParser::Attach_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBegin_stmt(SqlParsingParser::Begin_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommit_stmt(SqlParsingParser::Commit_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRollback_stmt(SqlParsingParser::Rollback_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSavepoint_stmt(SqlParsingParser::Savepoint_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelease_stmt(SqlParsingParser::Release_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreate_index_stmt(SqlParsingParser::Create_index_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexed_column(SqlParsingParser::Indexed_columnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreate_table_stmt(SqlParsingParser::Create_table_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumn_def(SqlParsingParser::Column_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_name(SqlParsingParser::Type_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumn_constraint(SqlParsingParser::Column_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSigned_number(SqlParsingParser::Signed_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_constraint(SqlParsingParser::Table_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForeign_key_clause(SqlParsingParser::Foreign_key_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConflict_clause(SqlParsingParser::Conflict_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreate_trigger_stmt(SqlParsingParser::Create_trigger_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreate_view_stmt(SqlParsingParser::Create_view_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreate_virtual_table_stmt(SqlParsingParser::Create_virtual_table_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWith_clause(SqlParsingParser::With_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCte_table_name(SqlParsingParser::Cte_table_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecursive_cte(SqlParsingParser::Recursive_cteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommon_table_expression(SqlParsingParser::Common_table_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelete_stmt(SqlParsingParser::Delete_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelete_stmt_limited(SqlParsingParser::Delete_stmt_limitedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDetach_stmt(SqlParsingParser::Detach_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDrop_stmt(SqlParsingParser::Drop_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(SqlParsingParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRaise_function(SqlParsingParser::Raise_functionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral_value(SqlParsingParser::Literal_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInsert_stmt(SqlParsingParser::Insert_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUpsert_clause(SqlParsingParser::Upsert_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPragma_stmt(SqlParsingParser::Pragma_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPragma_value(SqlParsingParser::Pragma_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReindex_stmt(SqlParsingParser::Reindex_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelect_stmt(SqlParsingParser::Select_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJoin_clause(SqlParsingParser::Join_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelect_core(SqlParsingParser::Select_coreContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFactored_select_stmt(SqlParsingParser::Factored_select_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_select_stmt(SqlParsingParser::Simple_select_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompound_select_stmt(SqlParsingParser::Compound_select_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_or_subquery(SqlParsingParser::Table_or_subqueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResult_column(SqlParsingParser::Result_columnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJoin_operator(SqlParsingParser::Join_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJoin_constraint(SqlParsingParser::Join_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompound_operator(SqlParsingParser::Compound_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUpdate_stmt(SqlParsingParser::Update_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumn_name_list(SqlParsingParser::Column_name_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUpdate_stmt_limited(SqlParsingParser::Update_stmt_limitedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQualified_table_name(SqlParsingParser::Qualified_table_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVacuum_stmt(SqlParsingParser::Vacuum_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFilter_clause(SqlParsingParser::Filter_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWindow_defn(SqlParsingParser::Window_defnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOver_clause(SqlParsingParser::Over_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFrame_spec(SqlParsingParser::Frame_specContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFrame_clause(SqlParsingParser::Frame_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_function_invocation(SqlParsingParser::Simple_function_invocationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAggregate_function_invocation(SqlParsingParser::Aggregate_function_invocationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWindow_function_invocation(SqlParsingParser::Window_function_invocationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommon_table_stmt(SqlParsingParser::Common_table_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrder_by_stmt(SqlParsingParser::Order_by_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLimit_stmt(SqlParsingParser::Limit_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrdering_term(SqlParsingParser::Ordering_termContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAsc_desc(SqlParsingParser::Asc_descContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFrame_left(SqlParsingParser::Frame_leftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFrame_right(SqlParsingParser::Frame_rightContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFrame_single(SqlParsingParser::Frame_singleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWindow_function(SqlParsingParser::Window_functionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOffset(SqlParsingParser::OffsetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefault_value(SqlParsingParser::Default_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPartition_by(SqlParsingParser::Partition_byContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrder_by_expr(SqlParsingParser::Order_by_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrder_by_expr_asc_desc(SqlParsingParser::Order_by_expr_asc_descContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr_asc_desc(SqlParsingParser::Expr_asc_descContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitial_select(SqlParsingParser::Initial_selectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecursive_select(SqlParsingParser::Recursive_selectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary_operator(SqlParsingParser::Unary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitError_message(SqlParsingParser::Error_messageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_argument(SqlParsingParser::Module_argumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumn_alias(SqlParsingParser::Column_aliasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKeyword(SqlParsingParser::KeywordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitName(SqlParsingParser::NameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_name(SqlParsingParser::Function_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSchema_name(SqlParsingParser::Schema_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_name(SqlParsingParser::Table_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_or_index_name(SqlParsingParser::Table_or_index_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNew_table_name(SqlParsingParser::New_table_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumn_name(SqlParsingParser::Column_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCollation_name(SqlParsingParser::Collation_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForeign_table(SqlParsingParser::Foreign_tableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndex_name(SqlParsingParser::Index_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrigger_name(SqlParsingParser::Trigger_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitView_name(SqlParsingParser::View_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_name(SqlParsingParser::Module_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPragma_name(SqlParsingParser::Pragma_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSavepoint_name(SqlParsingParser::Savepoint_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_alias(SqlParsingParser::Table_aliasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTransaction_name(SqlParsingParser::Transaction_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWindow_name(SqlParsingParser::Window_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlias(SqlParsingParser::AliasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFilename(SqlParsingParser::FilenameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBase_window_name(SqlParsingParser::Base_window_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_func(SqlParsingParser::Simple_funcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAggregate_func(SqlParsingParser::Aggregate_funcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_function_name(SqlParsingParser::Table_function_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAny_name(SqlParsingParser::Any_nameContext *ctx) override {
    return visitChildren(ctx);
  }


};

