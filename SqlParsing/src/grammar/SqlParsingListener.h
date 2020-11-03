
// Generated from SqlParsing.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "SqlParsingParser.h"


namespace dsql.parser {

/**
 * This interface defines an abstract listener for a parse tree produced by SqlParsingParser.
 */
class  SqlParsingListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterSql_stmt_list(SqlParsingParser::Sql_stmt_listContext *ctx) = 0;
  virtual void exitSql_stmt_list(SqlParsingParser::Sql_stmt_listContext *ctx) = 0;

  virtual void enterSql_stmt(SqlParsingParser::Sql_stmtContext *ctx) = 0;
  virtual void exitSql_stmt(SqlParsingParser::Sql_stmtContext *ctx) = 0;

  virtual void enterAlter_table_stmt(SqlParsingParser::Alter_table_stmtContext *ctx) = 0;
  virtual void exitAlter_table_stmt(SqlParsingParser::Alter_table_stmtContext *ctx) = 0;

  virtual void enterAnalyze_stmt(SqlParsingParser::Analyze_stmtContext *ctx) = 0;
  virtual void exitAnalyze_stmt(SqlParsingParser::Analyze_stmtContext *ctx) = 0;

  virtual void enterAttach_stmt(SqlParsingParser::Attach_stmtContext *ctx) = 0;
  virtual void exitAttach_stmt(SqlParsingParser::Attach_stmtContext *ctx) = 0;

  virtual void enterBegin_stmt(SqlParsingParser::Begin_stmtContext *ctx) = 0;
  virtual void exitBegin_stmt(SqlParsingParser::Begin_stmtContext *ctx) = 0;

  virtual void enterCommit_stmt(SqlParsingParser::Commit_stmtContext *ctx) = 0;
  virtual void exitCommit_stmt(SqlParsingParser::Commit_stmtContext *ctx) = 0;

  virtual void enterRollback_stmt(SqlParsingParser::Rollback_stmtContext *ctx) = 0;
  virtual void exitRollback_stmt(SqlParsingParser::Rollback_stmtContext *ctx) = 0;

  virtual void enterSavepoint_stmt(SqlParsingParser::Savepoint_stmtContext *ctx) = 0;
  virtual void exitSavepoint_stmt(SqlParsingParser::Savepoint_stmtContext *ctx) = 0;

  virtual void enterRelease_stmt(SqlParsingParser::Release_stmtContext *ctx) = 0;
  virtual void exitRelease_stmt(SqlParsingParser::Release_stmtContext *ctx) = 0;

  virtual void enterCreate_index_stmt(SqlParsingParser::Create_index_stmtContext *ctx) = 0;
  virtual void exitCreate_index_stmt(SqlParsingParser::Create_index_stmtContext *ctx) = 0;

  virtual void enterIndexed_column(SqlParsingParser::Indexed_columnContext *ctx) = 0;
  virtual void exitIndexed_column(SqlParsingParser::Indexed_columnContext *ctx) = 0;

  virtual void enterCreate_table_stmt(SqlParsingParser::Create_table_stmtContext *ctx) = 0;
  virtual void exitCreate_table_stmt(SqlParsingParser::Create_table_stmtContext *ctx) = 0;

  virtual void enterColumn_def(SqlParsingParser::Column_defContext *ctx) = 0;
  virtual void exitColumn_def(SqlParsingParser::Column_defContext *ctx) = 0;

  virtual void enterType_name(SqlParsingParser::Type_nameContext *ctx) = 0;
  virtual void exitType_name(SqlParsingParser::Type_nameContext *ctx) = 0;

  virtual void enterColumn_constraint(SqlParsingParser::Column_constraintContext *ctx) = 0;
  virtual void exitColumn_constraint(SqlParsingParser::Column_constraintContext *ctx) = 0;

  virtual void enterSigned_number(SqlParsingParser::Signed_numberContext *ctx) = 0;
  virtual void exitSigned_number(SqlParsingParser::Signed_numberContext *ctx) = 0;

  virtual void enterTable_constraint(SqlParsingParser::Table_constraintContext *ctx) = 0;
  virtual void exitTable_constraint(SqlParsingParser::Table_constraintContext *ctx) = 0;

  virtual void enterForeign_key_clause(SqlParsingParser::Foreign_key_clauseContext *ctx) = 0;
  virtual void exitForeign_key_clause(SqlParsingParser::Foreign_key_clauseContext *ctx) = 0;

  virtual void enterConflict_clause(SqlParsingParser::Conflict_clauseContext *ctx) = 0;
  virtual void exitConflict_clause(SqlParsingParser::Conflict_clauseContext *ctx) = 0;

  virtual void enterCreate_trigger_stmt(SqlParsingParser::Create_trigger_stmtContext *ctx) = 0;
  virtual void exitCreate_trigger_stmt(SqlParsingParser::Create_trigger_stmtContext *ctx) = 0;

  virtual void enterCreate_view_stmt(SqlParsingParser::Create_view_stmtContext *ctx) = 0;
  virtual void exitCreate_view_stmt(SqlParsingParser::Create_view_stmtContext *ctx) = 0;

  virtual void enterCreate_virtual_table_stmt(SqlParsingParser::Create_virtual_table_stmtContext *ctx) = 0;
  virtual void exitCreate_virtual_table_stmt(SqlParsingParser::Create_virtual_table_stmtContext *ctx) = 0;

  virtual void enterWith_clause(SqlParsingParser::With_clauseContext *ctx) = 0;
  virtual void exitWith_clause(SqlParsingParser::With_clauseContext *ctx) = 0;

  virtual void enterCte_table_name(SqlParsingParser::Cte_table_nameContext *ctx) = 0;
  virtual void exitCte_table_name(SqlParsingParser::Cte_table_nameContext *ctx) = 0;

  virtual void enterRecursive_cte(SqlParsingParser::Recursive_cteContext *ctx) = 0;
  virtual void exitRecursive_cte(SqlParsingParser::Recursive_cteContext *ctx) = 0;

  virtual void enterCommon_table_expression(SqlParsingParser::Common_table_expressionContext *ctx) = 0;
  virtual void exitCommon_table_expression(SqlParsingParser::Common_table_expressionContext *ctx) = 0;

  virtual void enterDelete_stmt(SqlParsingParser::Delete_stmtContext *ctx) = 0;
  virtual void exitDelete_stmt(SqlParsingParser::Delete_stmtContext *ctx) = 0;

  virtual void enterDelete_stmt_limited(SqlParsingParser::Delete_stmt_limitedContext *ctx) = 0;
  virtual void exitDelete_stmt_limited(SqlParsingParser::Delete_stmt_limitedContext *ctx) = 0;

  virtual void enterDetach_stmt(SqlParsingParser::Detach_stmtContext *ctx) = 0;
  virtual void exitDetach_stmt(SqlParsingParser::Detach_stmtContext *ctx) = 0;

  virtual void enterDrop_stmt(SqlParsingParser::Drop_stmtContext *ctx) = 0;
  virtual void exitDrop_stmt(SqlParsingParser::Drop_stmtContext *ctx) = 0;

  virtual void enterExpr(SqlParsingParser::ExprContext *ctx) = 0;
  virtual void exitExpr(SqlParsingParser::ExprContext *ctx) = 0;

  virtual void enterRaise_function(SqlParsingParser::Raise_functionContext *ctx) = 0;
  virtual void exitRaise_function(SqlParsingParser::Raise_functionContext *ctx) = 0;

  virtual void enterLiteral_value(SqlParsingParser::Literal_valueContext *ctx) = 0;
  virtual void exitLiteral_value(SqlParsingParser::Literal_valueContext *ctx) = 0;

  virtual void enterInsert_stmt(SqlParsingParser::Insert_stmtContext *ctx) = 0;
  virtual void exitInsert_stmt(SqlParsingParser::Insert_stmtContext *ctx) = 0;

  virtual void enterUpsert_clause(SqlParsingParser::Upsert_clauseContext *ctx) = 0;
  virtual void exitUpsert_clause(SqlParsingParser::Upsert_clauseContext *ctx) = 0;

  virtual void enterPragma_stmt(SqlParsingParser::Pragma_stmtContext *ctx) = 0;
  virtual void exitPragma_stmt(SqlParsingParser::Pragma_stmtContext *ctx) = 0;

  virtual void enterPragma_value(SqlParsingParser::Pragma_valueContext *ctx) = 0;
  virtual void exitPragma_value(SqlParsingParser::Pragma_valueContext *ctx) = 0;

  virtual void enterReindex_stmt(SqlParsingParser::Reindex_stmtContext *ctx) = 0;
  virtual void exitReindex_stmt(SqlParsingParser::Reindex_stmtContext *ctx) = 0;

  virtual void enterSelect_stmt(SqlParsingParser::Select_stmtContext *ctx) = 0;
  virtual void exitSelect_stmt(SqlParsingParser::Select_stmtContext *ctx) = 0;

  virtual void enterJoin_clause(SqlParsingParser::Join_clauseContext *ctx) = 0;
  virtual void exitJoin_clause(SqlParsingParser::Join_clauseContext *ctx) = 0;

  virtual void enterSelect_core(SqlParsingParser::Select_coreContext *ctx) = 0;
  virtual void exitSelect_core(SqlParsingParser::Select_coreContext *ctx) = 0;

  virtual void enterFactored_select_stmt(SqlParsingParser::Factored_select_stmtContext *ctx) = 0;
  virtual void exitFactored_select_stmt(SqlParsingParser::Factored_select_stmtContext *ctx) = 0;

  virtual void enterSimple_select_stmt(SqlParsingParser::Simple_select_stmtContext *ctx) = 0;
  virtual void exitSimple_select_stmt(SqlParsingParser::Simple_select_stmtContext *ctx) = 0;

  virtual void enterCompound_select_stmt(SqlParsingParser::Compound_select_stmtContext *ctx) = 0;
  virtual void exitCompound_select_stmt(SqlParsingParser::Compound_select_stmtContext *ctx) = 0;

  virtual void enterTable_or_subquery(SqlParsingParser::Table_or_subqueryContext *ctx) = 0;
  virtual void exitTable_or_subquery(SqlParsingParser::Table_or_subqueryContext *ctx) = 0;

  virtual void enterResult_column(SqlParsingParser::Result_columnContext *ctx) = 0;
  virtual void exitResult_column(SqlParsingParser::Result_columnContext *ctx) = 0;

  virtual void enterJoin_operator(SqlParsingParser::Join_operatorContext *ctx) = 0;
  virtual void exitJoin_operator(SqlParsingParser::Join_operatorContext *ctx) = 0;

  virtual void enterJoin_constraint(SqlParsingParser::Join_constraintContext *ctx) = 0;
  virtual void exitJoin_constraint(SqlParsingParser::Join_constraintContext *ctx) = 0;

  virtual void enterCompound_operator(SqlParsingParser::Compound_operatorContext *ctx) = 0;
  virtual void exitCompound_operator(SqlParsingParser::Compound_operatorContext *ctx) = 0;

  virtual void enterUpdate_stmt(SqlParsingParser::Update_stmtContext *ctx) = 0;
  virtual void exitUpdate_stmt(SqlParsingParser::Update_stmtContext *ctx) = 0;

  virtual void enterColumn_name_list(SqlParsingParser::Column_name_listContext *ctx) = 0;
  virtual void exitColumn_name_list(SqlParsingParser::Column_name_listContext *ctx) = 0;

  virtual void enterUpdate_stmt_limited(SqlParsingParser::Update_stmt_limitedContext *ctx) = 0;
  virtual void exitUpdate_stmt_limited(SqlParsingParser::Update_stmt_limitedContext *ctx) = 0;

  virtual void enterQualified_table_name(SqlParsingParser::Qualified_table_nameContext *ctx) = 0;
  virtual void exitQualified_table_name(SqlParsingParser::Qualified_table_nameContext *ctx) = 0;

  virtual void enterVacuum_stmt(SqlParsingParser::Vacuum_stmtContext *ctx) = 0;
  virtual void exitVacuum_stmt(SqlParsingParser::Vacuum_stmtContext *ctx) = 0;

  virtual void enterFilter_clause(SqlParsingParser::Filter_clauseContext *ctx) = 0;
  virtual void exitFilter_clause(SqlParsingParser::Filter_clauseContext *ctx) = 0;

  virtual void enterWindow_defn(SqlParsingParser::Window_defnContext *ctx) = 0;
  virtual void exitWindow_defn(SqlParsingParser::Window_defnContext *ctx) = 0;

  virtual void enterOver_clause(SqlParsingParser::Over_clauseContext *ctx) = 0;
  virtual void exitOver_clause(SqlParsingParser::Over_clauseContext *ctx) = 0;

  virtual void enterFrame_spec(SqlParsingParser::Frame_specContext *ctx) = 0;
  virtual void exitFrame_spec(SqlParsingParser::Frame_specContext *ctx) = 0;

  virtual void enterFrame_clause(SqlParsingParser::Frame_clauseContext *ctx) = 0;
  virtual void exitFrame_clause(SqlParsingParser::Frame_clauseContext *ctx) = 0;

  virtual void enterSimple_function_invocation(SqlParsingParser::Simple_function_invocationContext *ctx) = 0;
  virtual void exitSimple_function_invocation(SqlParsingParser::Simple_function_invocationContext *ctx) = 0;

  virtual void enterAggregate_function_invocation(SqlParsingParser::Aggregate_function_invocationContext *ctx) = 0;
  virtual void exitAggregate_function_invocation(SqlParsingParser::Aggregate_function_invocationContext *ctx) = 0;

  virtual void enterWindow_function_invocation(SqlParsingParser::Window_function_invocationContext *ctx) = 0;
  virtual void exitWindow_function_invocation(SqlParsingParser::Window_function_invocationContext *ctx) = 0;

  virtual void enterCommon_table_stmt(SqlParsingParser::Common_table_stmtContext *ctx) = 0;
  virtual void exitCommon_table_stmt(SqlParsingParser::Common_table_stmtContext *ctx) = 0;

  virtual void enterOrder_by_stmt(SqlParsingParser::Order_by_stmtContext *ctx) = 0;
  virtual void exitOrder_by_stmt(SqlParsingParser::Order_by_stmtContext *ctx) = 0;

  virtual void enterLimit_stmt(SqlParsingParser::Limit_stmtContext *ctx) = 0;
  virtual void exitLimit_stmt(SqlParsingParser::Limit_stmtContext *ctx) = 0;

  virtual void enterOrdering_term(SqlParsingParser::Ordering_termContext *ctx) = 0;
  virtual void exitOrdering_term(SqlParsingParser::Ordering_termContext *ctx) = 0;

  virtual void enterAsc_desc(SqlParsingParser::Asc_descContext *ctx) = 0;
  virtual void exitAsc_desc(SqlParsingParser::Asc_descContext *ctx) = 0;

  virtual void enterFrame_left(SqlParsingParser::Frame_leftContext *ctx) = 0;
  virtual void exitFrame_left(SqlParsingParser::Frame_leftContext *ctx) = 0;

  virtual void enterFrame_right(SqlParsingParser::Frame_rightContext *ctx) = 0;
  virtual void exitFrame_right(SqlParsingParser::Frame_rightContext *ctx) = 0;

  virtual void enterFrame_single(SqlParsingParser::Frame_singleContext *ctx) = 0;
  virtual void exitFrame_single(SqlParsingParser::Frame_singleContext *ctx) = 0;

  virtual void enterWindow_function(SqlParsingParser::Window_functionContext *ctx) = 0;
  virtual void exitWindow_function(SqlParsingParser::Window_functionContext *ctx) = 0;

  virtual void enterOffset(SqlParsingParser::OffsetContext *ctx) = 0;
  virtual void exitOffset(SqlParsingParser::OffsetContext *ctx) = 0;

  virtual void enterDefault_value(SqlParsingParser::Default_valueContext *ctx) = 0;
  virtual void exitDefault_value(SqlParsingParser::Default_valueContext *ctx) = 0;

  virtual void enterPartition_by(SqlParsingParser::Partition_byContext *ctx) = 0;
  virtual void exitPartition_by(SqlParsingParser::Partition_byContext *ctx) = 0;

  virtual void enterOrder_by_expr(SqlParsingParser::Order_by_exprContext *ctx) = 0;
  virtual void exitOrder_by_expr(SqlParsingParser::Order_by_exprContext *ctx) = 0;

  virtual void enterOrder_by_expr_asc_desc(SqlParsingParser::Order_by_expr_asc_descContext *ctx) = 0;
  virtual void exitOrder_by_expr_asc_desc(SqlParsingParser::Order_by_expr_asc_descContext *ctx) = 0;

  virtual void enterExpr_asc_desc(SqlParsingParser::Expr_asc_descContext *ctx) = 0;
  virtual void exitExpr_asc_desc(SqlParsingParser::Expr_asc_descContext *ctx) = 0;

  virtual void enterInitial_select(SqlParsingParser::Initial_selectContext *ctx) = 0;
  virtual void exitInitial_select(SqlParsingParser::Initial_selectContext *ctx) = 0;

  virtual void enterRecursive_select(SqlParsingParser::Recursive_selectContext *ctx) = 0;
  virtual void exitRecursive_select(SqlParsingParser::Recursive_selectContext *ctx) = 0;

  virtual void enterUnary_operator(SqlParsingParser::Unary_operatorContext *ctx) = 0;
  virtual void exitUnary_operator(SqlParsingParser::Unary_operatorContext *ctx) = 0;

  virtual void enterError_message(SqlParsingParser::Error_messageContext *ctx) = 0;
  virtual void exitError_message(SqlParsingParser::Error_messageContext *ctx) = 0;

  virtual void enterModule_argument(SqlParsingParser::Module_argumentContext *ctx) = 0;
  virtual void exitModule_argument(SqlParsingParser::Module_argumentContext *ctx) = 0;

  virtual void enterColumn_alias(SqlParsingParser::Column_aliasContext *ctx) = 0;
  virtual void exitColumn_alias(SqlParsingParser::Column_aliasContext *ctx) = 0;

  virtual void enterKeyword(SqlParsingParser::KeywordContext *ctx) = 0;
  virtual void exitKeyword(SqlParsingParser::KeywordContext *ctx) = 0;

  virtual void enterName(SqlParsingParser::NameContext *ctx) = 0;
  virtual void exitName(SqlParsingParser::NameContext *ctx) = 0;

  virtual void enterFunction_name(SqlParsingParser::Function_nameContext *ctx) = 0;
  virtual void exitFunction_name(SqlParsingParser::Function_nameContext *ctx) = 0;

  virtual void enterSchema_name(SqlParsingParser::Schema_nameContext *ctx) = 0;
  virtual void exitSchema_name(SqlParsingParser::Schema_nameContext *ctx) = 0;

  virtual void enterTable_name(SqlParsingParser::Table_nameContext *ctx) = 0;
  virtual void exitTable_name(SqlParsingParser::Table_nameContext *ctx) = 0;

  virtual void enterTable_or_index_name(SqlParsingParser::Table_or_index_nameContext *ctx) = 0;
  virtual void exitTable_or_index_name(SqlParsingParser::Table_or_index_nameContext *ctx) = 0;

  virtual void enterNew_table_name(SqlParsingParser::New_table_nameContext *ctx) = 0;
  virtual void exitNew_table_name(SqlParsingParser::New_table_nameContext *ctx) = 0;

  virtual void enterColumn_name(SqlParsingParser::Column_nameContext *ctx) = 0;
  virtual void exitColumn_name(SqlParsingParser::Column_nameContext *ctx) = 0;

  virtual void enterCollation_name(SqlParsingParser::Collation_nameContext *ctx) = 0;
  virtual void exitCollation_name(SqlParsingParser::Collation_nameContext *ctx) = 0;

  virtual void enterForeign_table(SqlParsingParser::Foreign_tableContext *ctx) = 0;
  virtual void exitForeign_table(SqlParsingParser::Foreign_tableContext *ctx) = 0;

  virtual void enterIndex_name(SqlParsingParser::Index_nameContext *ctx) = 0;
  virtual void exitIndex_name(SqlParsingParser::Index_nameContext *ctx) = 0;

  virtual void enterTrigger_name(SqlParsingParser::Trigger_nameContext *ctx) = 0;
  virtual void exitTrigger_name(SqlParsingParser::Trigger_nameContext *ctx) = 0;

  virtual void enterView_name(SqlParsingParser::View_nameContext *ctx) = 0;
  virtual void exitView_name(SqlParsingParser::View_nameContext *ctx) = 0;

  virtual void enterModule_name(SqlParsingParser::Module_nameContext *ctx) = 0;
  virtual void exitModule_name(SqlParsingParser::Module_nameContext *ctx) = 0;

  virtual void enterPragma_name(SqlParsingParser::Pragma_nameContext *ctx) = 0;
  virtual void exitPragma_name(SqlParsingParser::Pragma_nameContext *ctx) = 0;

  virtual void enterSavepoint_name(SqlParsingParser::Savepoint_nameContext *ctx) = 0;
  virtual void exitSavepoint_name(SqlParsingParser::Savepoint_nameContext *ctx) = 0;

  virtual void enterTable_alias(SqlParsingParser::Table_aliasContext *ctx) = 0;
  virtual void exitTable_alias(SqlParsingParser::Table_aliasContext *ctx) = 0;

  virtual void enterTransaction_name(SqlParsingParser::Transaction_nameContext *ctx) = 0;
  virtual void exitTransaction_name(SqlParsingParser::Transaction_nameContext *ctx) = 0;

  virtual void enterWindow_name(SqlParsingParser::Window_nameContext *ctx) = 0;
  virtual void exitWindow_name(SqlParsingParser::Window_nameContext *ctx) = 0;

  virtual void enterAlias(SqlParsingParser::AliasContext *ctx) = 0;
  virtual void exitAlias(SqlParsingParser::AliasContext *ctx) = 0;

  virtual void enterFilename(SqlParsingParser::FilenameContext *ctx) = 0;
  virtual void exitFilename(SqlParsingParser::FilenameContext *ctx) = 0;

  virtual void enterBase_window_name(SqlParsingParser::Base_window_nameContext *ctx) = 0;
  virtual void exitBase_window_name(SqlParsingParser::Base_window_nameContext *ctx) = 0;

  virtual void enterSimple_func(SqlParsingParser::Simple_funcContext *ctx) = 0;
  virtual void exitSimple_func(SqlParsingParser::Simple_funcContext *ctx) = 0;

  virtual void enterAggregate_func(SqlParsingParser::Aggregate_funcContext *ctx) = 0;
  virtual void exitAggregate_func(SqlParsingParser::Aggregate_funcContext *ctx) = 0;

  virtual void enterTable_function_name(SqlParsingParser::Table_function_nameContext *ctx) = 0;
  virtual void exitTable_function_name(SqlParsingParser::Table_function_nameContext *ctx) = 0;

  virtual void enterAny_name(SqlParsingParser::Any_nameContext *ctx) = 0;
  virtual void exitAny_name(SqlParsingParser::Any_nameContext *ctx) = 0;


};

}  // namespace dsql.parser
