
// Generated from SqlParsing.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "SqlParsingListener.h"


/**
 * This class provides an empty implementation of SqlParsingListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SqlParsingBaseListener : public SqlParsingListener {
public:

  virtual void enterSql_stmt_list(SqlParsingParser::Sql_stmt_listContext * /*ctx*/) override { }
  virtual void exitSql_stmt_list(SqlParsingParser::Sql_stmt_listContext * /*ctx*/) override { }

  virtual void enterSql_stmt(SqlParsingParser::Sql_stmtContext * /*ctx*/) override { }
  virtual void exitSql_stmt(SqlParsingParser::Sql_stmtContext * /*ctx*/) override { }

  virtual void enterAlter_table_stmt(SqlParsingParser::Alter_table_stmtContext * /*ctx*/) override { }
  virtual void exitAlter_table_stmt(SqlParsingParser::Alter_table_stmtContext * /*ctx*/) override { }

  virtual void enterAnalyze_stmt(SqlParsingParser::Analyze_stmtContext * /*ctx*/) override { }
  virtual void exitAnalyze_stmt(SqlParsingParser::Analyze_stmtContext * /*ctx*/) override { }

  virtual void enterAttach_stmt(SqlParsingParser::Attach_stmtContext * /*ctx*/) override { }
  virtual void exitAttach_stmt(SqlParsingParser::Attach_stmtContext * /*ctx*/) override { }

  virtual void enterBegin_stmt(SqlParsingParser::Begin_stmtContext * /*ctx*/) override { }
  virtual void exitBegin_stmt(SqlParsingParser::Begin_stmtContext * /*ctx*/) override { }

  virtual void enterCommit_stmt(SqlParsingParser::Commit_stmtContext * /*ctx*/) override { }
  virtual void exitCommit_stmt(SqlParsingParser::Commit_stmtContext * /*ctx*/) override { }

  virtual void enterRollback_stmt(SqlParsingParser::Rollback_stmtContext * /*ctx*/) override { }
  virtual void exitRollback_stmt(SqlParsingParser::Rollback_stmtContext * /*ctx*/) override { }

  virtual void enterSavepoint_stmt(SqlParsingParser::Savepoint_stmtContext * /*ctx*/) override { }
  virtual void exitSavepoint_stmt(SqlParsingParser::Savepoint_stmtContext * /*ctx*/) override { }

  virtual void enterRelease_stmt(SqlParsingParser::Release_stmtContext * /*ctx*/) override { }
  virtual void exitRelease_stmt(SqlParsingParser::Release_stmtContext * /*ctx*/) override { }

  virtual void enterCreate_index_stmt(SqlParsingParser::Create_index_stmtContext * /*ctx*/) override { }
  virtual void exitCreate_index_stmt(SqlParsingParser::Create_index_stmtContext * /*ctx*/) override { }

  virtual void enterIndexed_column(SqlParsingParser::Indexed_columnContext * /*ctx*/) override { }
  virtual void exitIndexed_column(SqlParsingParser::Indexed_columnContext * /*ctx*/) override { }

  virtual void enterCreate_table_stmt(SqlParsingParser::Create_table_stmtContext * /*ctx*/) override { }
  virtual void exitCreate_table_stmt(SqlParsingParser::Create_table_stmtContext * /*ctx*/) override { }

  virtual void enterColumn_def(SqlParsingParser::Column_defContext * /*ctx*/) override { }
  virtual void exitColumn_def(SqlParsingParser::Column_defContext * /*ctx*/) override { }

  virtual void enterType_name(SqlParsingParser::Type_nameContext * /*ctx*/) override { }
  virtual void exitType_name(SqlParsingParser::Type_nameContext * /*ctx*/) override { }

  virtual void enterColumn_constraint(SqlParsingParser::Column_constraintContext * /*ctx*/) override { }
  virtual void exitColumn_constraint(SqlParsingParser::Column_constraintContext * /*ctx*/) override { }

  virtual void enterSigned_number(SqlParsingParser::Signed_numberContext * /*ctx*/) override { }
  virtual void exitSigned_number(SqlParsingParser::Signed_numberContext * /*ctx*/) override { }

  virtual void enterTable_constraint(SqlParsingParser::Table_constraintContext * /*ctx*/) override { }
  virtual void exitTable_constraint(SqlParsingParser::Table_constraintContext * /*ctx*/) override { }

  virtual void enterForeign_key_clause(SqlParsingParser::Foreign_key_clauseContext * /*ctx*/) override { }
  virtual void exitForeign_key_clause(SqlParsingParser::Foreign_key_clauseContext * /*ctx*/) override { }

  virtual void enterConflict_clause(SqlParsingParser::Conflict_clauseContext * /*ctx*/) override { }
  virtual void exitConflict_clause(SqlParsingParser::Conflict_clauseContext * /*ctx*/) override { }

  virtual void enterCreate_trigger_stmt(SqlParsingParser::Create_trigger_stmtContext * /*ctx*/) override { }
  virtual void exitCreate_trigger_stmt(SqlParsingParser::Create_trigger_stmtContext * /*ctx*/) override { }

  virtual void enterCreate_view_stmt(SqlParsingParser::Create_view_stmtContext * /*ctx*/) override { }
  virtual void exitCreate_view_stmt(SqlParsingParser::Create_view_stmtContext * /*ctx*/) override { }

  virtual void enterCreate_virtual_table_stmt(SqlParsingParser::Create_virtual_table_stmtContext * /*ctx*/) override { }
  virtual void exitCreate_virtual_table_stmt(SqlParsingParser::Create_virtual_table_stmtContext * /*ctx*/) override { }

  virtual void enterWith_clause(SqlParsingParser::With_clauseContext * /*ctx*/) override { }
  virtual void exitWith_clause(SqlParsingParser::With_clauseContext * /*ctx*/) override { }

  virtual void enterCte_table_name(SqlParsingParser::Cte_table_nameContext * /*ctx*/) override { }
  virtual void exitCte_table_name(SqlParsingParser::Cte_table_nameContext * /*ctx*/) override { }

  virtual void enterRecursive_cte(SqlParsingParser::Recursive_cteContext * /*ctx*/) override { }
  virtual void exitRecursive_cte(SqlParsingParser::Recursive_cteContext * /*ctx*/) override { }

  virtual void enterCommon_table_expression(SqlParsingParser::Common_table_expressionContext * /*ctx*/) override { }
  virtual void exitCommon_table_expression(SqlParsingParser::Common_table_expressionContext * /*ctx*/) override { }

  virtual void enterDelete_stmt(SqlParsingParser::Delete_stmtContext * /*ctx*/) override { }
  virtual void exitDelete_stmt(SqlParsingParser::Delete_stmtContext * /*ctx*/) override { }

  virtual void enterDelete_stmt_limited(SqlParsingParser::Delete_stmt_limitedContext * /*ctx*/) override { }
  virtual void exitDelete_stmt_limited(SqlParsingParser::Delete_stmt_limitedContext * /*ctx*/) override { }

  virtual void enterDetach_stmt(SqlParsingParser::Detach_stmtContext * /*ctx*/) override { }
  virtual void exitDetach_stmt(SqlParsingParser::Detach_stmtContext * /*ctx*/) override { }

  virtual void enterDrop_stmt(SqlParsingParser::Drop_stmtContext * /*ctx*/) override { }
  virtual void exitDrop_stmt(SqlParsingParser::Drop_stmtContext * /*ctx*/) override { }

  virtual void enterExpr(SqlParsingParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(SqlParsingParser::ExprContext * /*ctx*/) override { }

  virtual void enterRaise_function(SqlParsingParser::Raise_functionContext * /*ctx*/) override { }
  virtual void exitRaise_function(SqlParsingParser::Raise_functionContext * /*ctx*/) override { }

  virtual void enterLiteral_value(SqlParsingParser::Literal_valueContext * /*ctx*/) override { }
  virtual void exitLiteral_value(SqlParsingParser::Literal_valueContext * /*ctx*/) override { }

  virtual void enterInsert_stmt(SqlParsingParser::Insert_stmtContext * /*ctx*/) override { }
  virtual void exitInsert_stmt(SqlParsingParser::Insert_stmtContext * /*ctx*/) override { }

  virtual void enterUpsert_clause(SqlParsingParser::Upsert_clauseContext * /*ctx*/) override { }
  virtual void exitUpsert_clause(SqlParsingParser::Upsert_clauseContext * /*ctx*/) override { }

  virtual void enterPragma_stmt(SqlParsingParser::Pragma_stmtContext * /*ctx*/) override { }
  virtual void exitPragma_stmt(SqlParsingParser::Pragma_stmtContext * /*ctx*/) override { }

  virtual void enterPragma_value(SqlParsingParser::Pragma_valueContext * /*ctx*/) override { }
  virtual void exitPragma_value(SqlParsingParser::Pragma_valueContext * /*ctx*/) override { }

  virtual void enterReindex_stmt(SqlParsingParser::Reindex_stmtContext * /*ctx*/) override { }
  virtual void exitReindex_stmt(SqlParsingParser::Reindex_stmtContext * /*ctx*/) override { }

  virtual void enterSelect_stmt(SqlParsingParser::Select_stmtContext * /*ctx*/) override { }
  virtual void exitSelect_stmt(SqlParsingParser::Select_stmtContext * /*ctx*/) override { }

  virtual void enterJoin_clause(SqlParsingParser::Join_clauseContext * /*ctx*/) override { }
  virtual void exitJoin_clause(SqlParsingParser::Join_clauseContext * /*ctx*/) override { }

  virtual void enterSelect_core(SqlParsingParser::Select_coreContext * /*ctx*/) override { }
  virtual void exitSelect_core(SqlParsingParser::Select_coreContext * /*ctx*/) override { }

  virtual void enterFactored_select_stmt(SqlParsingParser::Factored_select_stmtContext * /*ctx*/) override { }
  virtual void exitFactored_select_stmt(SqlParsingParser::Factored_select_stmtContext * /*ctx*/) override { }

  virtual void enterSimple_select_stmt(SqlParsingParser::Simple_select_stmtContext * /*ctx*/) override { }
  virtual void exitSimple_select_stmt(SqlParsingParser::Simple_select_stmtContext * /*ctx*/) override { }

  virtual void enterCompound_select_stmt(SqlParsingParser::Compound_select_stmtContext * /*ctx*/) override { }
  virtual void exitCompound_select_stmt(SqlParsingParser::Compound_select_stmtContext * /*ctx*/) override { }

  virtual void enterTable_or_subquery(SqlParsingParser::Table_or_subqueryContext * /*ctx*/) override { }
  virtual void exitTable_or_subquery(SqlParsingParser::Table_or_subqueryContext * /*ctx*/) override { }

  virtual void enterResult_column(SqlParsingParser::Result_columnContext * /*ctx*/) override { }
  virtual void exitResult_column(SqlParsingParser::Result_columnContext * /*ctx*/) override { }

  virtual void enterJoin_operator(SqlParsingParser::Join_operatorContext * /*ctx*/) override { }
  virtual void exitJoin_operator(SqlParsingParser::Join_operatorContext * /*ctx*/) override { }

  virtual void enterJoin_constraint(SqlParsingParser::Join_constraintContext * /*ctx*/) override { }
  virtual void exitJoin_constraint(SqlParsingParser::Join_constraintContext * /*ctx*/) override { }

  virtual void enterCompound_operator(SqlParsingParser::Compound_operatorContext * /*ctx*/) override { }
  virtual void exitCompound_operator(SqlParsingParser::Compound_operatorContext * /*ctx*/) override { }

  virtual void enterUpdate_stmt(SqlParsingParser::Update_stmtContext * /*ctx*/) override { }
  virtual void exitUpdate_stmt(SqlParsingParser::Update_stmtContext * /*ctx*/) override { }

  virtual void enterColumn_name_list(SqlParsingParser::Column_name_listContext * /*ctx*/) override { }
  virtual void exitColumn_name_list(SqlParsingParser::Column_name_listContext * /*ctx*/) override { }

  virtual void enterUpdate_stmt_limited(SqlParsingParser::Update_stmt_limitedContext * /*ctx*/) override { }
  virtual void exitUpdate_stmt_limited(SqlParsingParser::Update_stmt_limitedContext * /*ctx*/) override { }

  virtual void enterQualified_table_name(SqlParsingParser::Qualified_table_nameContext * /*ctx*/) override { }
  virtual void exitQualified_table_name(SqlParsingParser::Qualified_table_nameContext * /*ctx*/) override { }

  virtual void enterVacuum_stmt(SqlParsingParser::Vacuum_stmtContext * /*ctx*/) override { }
  virtual void exitVacuum_stmt(SqlParsingParser::Vacuum_stmtContext * /*ctx*/) override { }

  virtual void enterFilter_clause(SqlParsingParser::Filter_clauseContext * /*ctx*/) override { }
  virtual void exitFilter_clause(SqlParsingParser::Filter_clauseContext * /*ctx*/) override { }

  virtual void enterWindow_defn(SqlParsingParser::Window_defnContext * /*ctx*/) override { }
  virtual void exitWindow_defn(SqlParsingParser::Window_defnContext * /*ctx*/) override { }

  virtual void enterOver_clause(SqlParsingParser::Over_clauseContext * /*ctx*/) override { }
  virtual void exitOver_clause(SqlParsingParser::Over_clauseContext * /*ctx*/) override { }

  virtual void enterFrame_spec(SqlParsingParser::Frame_specContext * /*ctx*/) override { }
  virtual void exitFrame_spec(SqlParsingParser::Frame_specContext * /*ctx*/) override { }

  virtual void enterFrame_clause(SqlParsingParser::Frame_clauseContext * /*ctx*/) override { }
  virtual void exitFrame_clause(SqlParsingParser::Frame_clauseContext * /*ctx*/) override { }

  virtual void enterSimple_function_invocation(SqlParsingParser::Simple_function_invocationContext * /*ctx*/) override { }
  virtual void exitSimple_function_invocation(SqlParsingParser::Simple_function_invocationContext * /*ctx*/) override { }

  virtual void enterAggregate_function_invocation(SqlParsingParser::Aggregate_function_invocationContext * /*ctx*/) override { }
  virtual void exitAggregate_function_invocation(SqlParsingParser::Aggregate_function_invocationContext * /*ctx*/) override { }

  virtual void enterWindow_function_invocation(SqlParsingParser::Window_function_invocationContext * /*ctx*/) override { }
  virtual void exitWindow_function_invocation(SqlParsingParser::Window_function_invocationContext * /*ctx*/) override { }

  virtual void enterCommon_table_stmt(SqlParsingParser::Common_table_stmtContext * /*ctx*/) override { }
  virtual void exitCommon_table_stmt(SqlParsingParser::Common_table_stmtContext * /*ctx*/) override { }

  virtual void enterOrder_by_stmt(SqlParsingParser::Order_by_stmtContext * /*ctx*/) override { }
  virtual void exitOrder_by_stmt(SqlParsingParser::Order_by_stmtContext * /*ctx*/) override { }

  virtual void enterLimit_stmt(SqlParsingParser::Limit_stmtContext * /*ctx*/) override { }
  virtual void exitLimit_stmt(SqlParsingParser::Limit_stmtContext * /*ctx*/) override { }

  virtual void enterOrdering_term(SqlParsingParser::Ordering_termContext * /*ctx*/) override { }
  virtual void exitOrdering_term(SqlParsingParser::Ordering_termContext * /*ctx*/) override { }

  virtual void enterAsc_desc(SqlParsingParser::Asc_descContext * /*ctx*/) override { }
  virtual void exitAsc_desc(SqlParsingParser::Asc_descContext * /*ctx*/) override { }

  virtual void enterFrame_left(SqlParsingParser::Frame_leftContext * /*ctx*/) override { }
  virtual void exitFrame_left(SqlParsingParser::Frame_leftContext * /*ctx*/) override { }

  virtual void enterFrame_right(SqlParsingParser::Frame_rightContext * /*ctx*/) override { }
  virtual void exitFrame_right(SqlParsingParser::Frame_rightContext * /*ctx*/) override { }

  virtual void enterFrame_single(SqlParsingParser::Frame_singleContext * /*ctx*/) override { }
  virtual void exitFrame_single(SqlParsingParser::Frame_singleContext * /*ctx*/) override { }

  virtual void enterWindow_function(SqlParsingParser::Window_functionContext * /*ctx*/) override { }
  virtual void exitWindow_function(SqlParsingParser::Window_functionContext * /*ctx*/) override { }

  virtual void enterOffset(SqlParsingParser::OffsetContext * /*ctx*/) override { }
  virtual void exitOffset(SqlParsingParser::OffsetContext * /*ctx*/) override { }

  virtual void enterDefault_value(SqlParsingParser::Default_valueContext * /*ctx*/) override { }
  virtual void exitDefault_value(SqlParsingParser::Default_valueContext * /*ctx*/) override { }

  virtual void enterPartition_by(SqlParsingParser::Partition_byContext * /*ctx*/) override { }
  virtual void exitPartition_by(SqlParsingParser::Partition_byContext * /*ctx*/) override { }

  virtual void enterOrder_by_expr(SqlParsingParser::Order_by_exprContext * /*ctx*/) override { }
  virtual void exitOrder_by_expr(SqlParsingParser::Order_by_exprContext * /*ctx*/) override { }

  virtual void enterOrder_by_expr_asc_desc(SqlParsingParser::Order_by_expr_asc_descContext * /*ctx*/) override { }
  virtual void exitOrder_by_expr_asc_desc(SqlParsingParser::Order_by_expr_asc_descContext * /*ctx*/) override { }

  virtual void enterExpr_asc_desc(SqlParsingParser::Expr_asc_descContext * /*ctx*/) override { }
  virtual void exitExpr_asc_desc(SqlParsingParser::Expr_asc_descContext * /*ctx*/) override { }

  virtual void enterInitial_select(SqlParsingParser::Initial_selectContext * /*ctx*/) override { }
  virtual void exitInitial_select(SqlParsingParser::Initial_selectContext * /*ctx*/) override { }

  virtual void enterRecursive_select(SqlParsingParser::Recursive_selectContext * /*ctx*/) override { }
  virtual void exitRecursive_select(SqlParsingParser::Recursive_selectContext * /*ctx*/) override { }

  virtual void enterUnary_operator(SqlParsingParser::Unary_operatorContext * /*ctx*/) override { }
  virtual void exitUnary_operator(SqlParsingParser::Unary_operatorContext * /*ctx*/) override { }

  virtual void enterError_message(SqlParsingParser::Error_messageContext * /*ctx*/) override { }
  virtual void exitError_message(SqlParsingParser::Error_messageContext * /*ctx*/) override { }

  virtual void enterModule_argument(SqlParsingParser::Module_argumentContext * /*ctx*/) override { }
  virtual void exitModule_argument(SqlParsingParser::Module_argumentContext * /*ctx*/) override { }

  virtual void enterColumn_alias(SqlParsingParser::Column_aliasContext * /*ctx*/) override { }
  virtual void exitColumn_alias(SqlParsingParser::Column_aliasContext * /*ctx*/) override { }

  virtual void enterKeyword(SqlParsingParser::KeywordContext * /*ctx*/) override { }
  virtual void exitKeyword(SqlParsingParser::KeywordContext * /*ctx*/) override { }

  virtual void enterName(SqlParsingParser::NameContext * /*ctx*/) override { }
  virtual void exitName(SqlParsingParser::NameContext * /*ctx*/) override { }

  virtual void enterFunction_name(SqlParsingParser::Function_nameContext * /*ctx*/) override { }
  virtual void exitFunction_name(SqlParsingParser::Function_nameContext * /*ctx*/) override { }

  virtual void enterSchema_name(SqlParsingParser::Schema_nameContext * /*ctx*/) override { }
  virtual void exitSchema_name(SqlParsingParser::Schema_nameContext * /*ctx*/) override { }

  virtual void enterTable_name(SqlParsingParser::Table_nameContext * /*ctx*/) override { }
  virtual void exitTable_name(SqlParsingParser::Table_nameContext * /*ctx*/) override { }

  virtual void enterTable_or_index_name(SqlParsingParser::Table_or_index_nameContext * /*ctx*/) override { }
  virtual void exitTable_or_index_name(SqlParsingParser::Table_or_index_nameContext * /*ctx*/) override { }

  virtual void enterNew_table_name(SqlParsingParser::New_table_nameContext * /*ctx*/) override { }
  virtual void exitNew_table_name(SqlParsingParser::New_table_nameContext * /*ctx*/) override { }

  virtual void enterColumn_name(SqlParsingParser::Column_nameContext * /*ctx*/) override { }
  virtual void exitColumn_name(SqlParsingParser::Column_nameContext * /*ctx*/) override { }

  virtual void enterCollation_name(SqlParsingParser::Collation_nameContext * /*ctx*/) override { }
  virtual void exitCollation_name(SqlParsingParser::Collation_nameContext * /*ctx*/) override { }

  virtual void enterForeign_table(SqlParsingParser::Foreign_tableContext * /*ctx*/) override { }
  virtual void exitForeign_table(SqlParsingParser::Foreign_tableContext * /*ctx*/) override { }

  virtual void enterIndex_name(SqlParsingParser::Index_nameContext * /*ctx*/) override { }
  virtual void exitIndex_name(SqlParsingParser::Index_nameContext * /*ctx*/) override { }

  virtual void enterTrigger_name(SqlParsingParser::Trigger_nameContext * /*ctx*/) override { }
  virtual void exitTrigger_name(SqlParsingParser::Trigger_nameContext * /*ctx*/) override { }

  virtual void enterView_name(SqlParsingParser::View_nameContext * /*ctx*/) override { }
  virtual void exitView_name(SqlParsingParser::View_nameContext * /*ctx*/) override { }

  virtual void enterModule_name(SqlParsingParser::Module_nameContext * /*ctx*/) override { }
  virtual void exitModule_name(SqlParsingParser::Module_nameContext * /*ctx*/) override { }

  virtual void enterPragma_name(SqlParsingParser::Pragma_nameContext * /*ctx*/) override { }
  virtual void exitPragma_name(SqlParsingParser::Pragma_nameContext * /*ctx*/) override { }

  virtual void enterSavepoint_name(SqlParsingParser::Savepoint_nameContext * /*ctx*/) override { }
  virtual void exitSavepoint_name(SqlParsingParser::Savepoint_nameContext * /*ctx*/) override { }

  virtual void enterTable_alias(SqlParsingParser::Table_aliasContext * /*ctx*/) override { }
  virtual void exitTable_alias(SqlParsingParser::Table_aliasContext * /*ctx*/) override { }

  virtual void enterTransaction_name(SqlParsingParser::Transaction_nameContext * /*ctx*/) override { }
  virtual void exitTransaction_name(SqlParsingParser::Transaction_nameContext * /*ctx*/) override { }

  virtual void enterWindow_name(SqlParsingParser::Window_nameContext * /*ctx*/) override { }
  virtual void exitWindow_name(SqlParsingParser::Window_nameContext * /*ctx*/) override { }

  virtual void enterAlias(SqlParsingParser::AliasContext * /*ctx*/) override { }
  virtual void exitAlias(SqlParsingParser::AliasContext * /*ctx*/) override { }

  virtual void enterFilename(SqlParsingParser::FilenameContext * /*ctx*/) override { }
  virtual void exitFilename(SqlParsingParser::FilenameContext * /*ctx*/) override { }

  virtual void enterBase_window_name(SqlParsingParser::Base_window_nameContext * /*ctx*/) override { }
  virtual void exitBase_window_name(SqlParsingParser::Base_window_nameContext * /*ctx*/) override { }

  virtual void enterSimple_func(SqlParsingParser::Simple_funcContext * /*ctx*/) override { }
  virtual void exitSimple_func(SqlParsingParser::Simple_funcContext * /*ctx*/) override { }

  virtual void enterAggregate_func(SqlParsingParser::Aggregate_funcContext * /*ctx*/) override { }
  virtual void exitAggregate_func(SqlParsingParser::Aggregate_funcContext * /*ctx*/) override { }

  virtual void enterTable_function_name(SqlParsingParser::Table_function_nameContext * /*ctx*/) override { }
  virtual void exitTable_function_name(SqlParsingParser::Table_function_nameContext * /*ctx*/) override { }

  virtual void enterAny_name(SqlParsingParser::Any_nameContext * /*ctx*/) override { }
  virtual void exitAny_name(SqlParsingParser::Any_nameContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

