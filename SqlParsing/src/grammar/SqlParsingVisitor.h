
// Generated from SqlParsing.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "SqlParsingParser.h"


namespace dsql.parser {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by SqlParsingParser.
 */
class  SqlParsingVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SqlParsingParser.
   */
    virtual antlrcpp::Any visitSql_stmt_list(SqlParsingParser::Sql_stmt_listContext *context) = 0;

    virtual antlrcpp::Any visitSql_stmt(SqlParsingParser::Sql_stmtContext *context) = 0;

    virtual antlrcpp::Any visitAlter_table_stmt(SqlParsingParser::Alter_table_stmtContext *context) = 0;

    virtual antlrcpp::Any visitAnalyze_stmt(SqlParsingParser::Analyze_stmtContext *context) = 0;

    virtual antlrcpp::Any visitAttach_stmt(SqlParsingParser::Attach_stmtContext *context) = 0;

    virtual antlrcpp::Any visitBegin_stmt(SqlParsingParser::Begin_stmtContext *context) = 0;

    virtual antlrcpp::Any visitCommit_stmt(SqlParsingParser::Commit_stmtContext *context) = 0;

    virtual antlrcpp::Any visitRollback_stmt(SqlParsingParser::Rollback_stmtContext *context) = 0;

    virtual antlrcpp::Any visitSavepoint_stmt(SqlParsingParser::Savepoint_stmtContext *context) = 0;

    virtual antlrcpp::Any visitRelease_stmt(SqlParsingParser::Release_stmtContext *context) = 0;

    virtual antlrcpp::Any visitCreate_index_stmt(SqlParsingParser::Create_index_stmtContext *context) = 0;

    virtual antlrcpp::Any visitIndexed_column(SqlParsingParser::Indexed_columnContext *context) = 0;

    virtual antlrcpp::Any visitCreate_table_stmt(SqlParsingParser::Create_table_stmtContext *context) = 0;

    virtual antlrcpp::Any visitColumn_def(SqlParsingParser::Column_defContext *context) = 0;

    virtual antlrcpp::Any visitType_name(SqlParsingParser::Type_nameContext *context) = 0;

    virtual antlrcpp::Any visitColumn_constraint(SqlParsingParser::Column_constraintContext *context) = 0;

    virtual antlrcpp::Any visitSigned_number(SqlParsingParser::Signed_numberContext *context) = 0;

    virtual antlrcpp::Any visitTable_constraint(SqlParsingParser::Table_constraintContext *context) = 0;

    virtual antlrcpp::Any visitForeign_key_clause(SqlParsingParser::Foreign_key_clauseContext *context) = 0;

    virtual antlrcpp::Any visitConflict_clause(SqlParsingParser::Conflict_clauseContext *context) = 0;

    virtual antlrcpp::Any visitCreate_trigger_stmt(SqlParsingParser::Create_trigger_stmtContext *context) = 0;

    virtual antlrcpp::Any visitCreate_view_stmt(SqlParsingParser::Create_view_stmtContext *context) = 0;

    virtual antlrcpp::Any visitCreate_virtual_table_stmt(SqlParsingParser::Create_virtual_table_stmtContext *context) = 0;

    virtual antlrcpp::Any visitWith_clause(SqlParsingParser::With_clauseContext *context) = 0;

    virtual antlrcpp::Any visitCte_table_name(SqlParsingParser::Cte_table_nameContext *context) = 0;

    virtual antlrcpp::Any visitRecursive_cte(SqlParsingParser::Recursive_cteContext *context) = 0;

    virtual antlrcpp::Any visitCommon_table_expression(SqlParsingParser::Common_table_expressionContext *context) = 0;

    virtual antlrcpp::Any visitDelete_stmt(SqlParsingParser::Delete_stmtContext *context) = 0;

    virtual antlrcpp::Any visitDelete_stmt_limited(SqlParsingParser::Delete_stmt_limitedContext *context) = 0;

    virtual antlrcpp::Any visitDetach_stmt(SqlParsingParser::Detach_stmtContext *context) = 0;

    virtual antlrcpp::Any visitDrop_stmt(SqlParsingParser::Drop_stmtContext *context) = 0;

    virtual antlrcpp::Any visitExpr(SqlParsingParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitRaise_function(SqlParsingParser::Raise_functionContext *context) = 0;

    virtual antlrcpp::Any visitLiteral_value(SqlParsingParser::Literal_valueContext *context) = 0;

    virtual antlrcpp::Any visitInsert_stmt(SqlParsingParser::Insert_stmtContext *context) = 0;

    virtual antlrcpp::Any visitUpsert_clause(SqlParsingParser::Upsert_clauseContext *context) = 0;

    virtual antlrcpp::Any visitPragma_stmt(SqlParsingParser::Pragma_stmtContext *context) = 0;

    virtual antlrcpp::Any visitPragma_value(SqlParsingParser::Pragma_valueContext *context) = 0;

    virtual antlrcpp::Any visitReindex_stmt(SqlParsingParser::Reindex_stmtContext *context) = 0;

    virtual antlrcpp::Any visitSelect_stmt(SqlParsingParser::Select_stmtContext *context) = 0;

    virtual antlrcpp::Any visitJoin_clause(SqlParsingParser::Join_clauseContext *context) = 0;

    virtual antlrcpp::Any visitSelect_core(SqlParsingParser::Select_coreContext *context) = 0;

    virtual antlrcpp::Any visitFactored_select_stmt(SqlParsingParser::Factored_select_stmtContext *context) = 0;

    virtual antlrcpp::Any visitSimple_select_stmt(SqlParsingParser::Simple_select_stmtContext *context) = 0;

    virtual antlrcpp::Any visitCompound_select_stmt(SqlParsingParser::Compound_select_stmtContext *context) = 0;

    virtual antlrcpp::Any visitTable_or_subquery(SqlParsingParser::Table_or_subqueryContext *context) = 0;

    virtual antlrcpp::Any visitResult_column(SqlParsingParser::Result_columnContext *context) = 0;

    virtual antlrcpp::Any visitJoin_operator(SqlParsingParser::Join_operatorContext *context) = 0;

    virtual antlrcpp::Any visitJoin_constraint(SqlParsingParser::Join_constraintContext *context) = 0;

    virtual antlrcpp::Any visitCompound_operator(SqlParsingParser::Compound_operatorContext *context) = 0;

    virtual antlrcpp::Any visitUpdate_stmt(SqlParsingParser::Update_stmtContext *context) = 0;

    virtual antlrcpp::Any visitColumn_name_list(SqlParsingParser::Column_name_listContext *context) = 0;

    virtual antlrcpp::Any visitUpdate_stmt_limited(SqlParsingParser::Update_stmt_limitedContext *context) = 0;

    virtual antlrcpp::Any visitQualified_table_name(SqlParsingParser::Qualified_table_nameContext *context) = 0;

    virtual antlrcpp::Any visitVacuum_stmt(SqlParsingParser::Vacuum_stmtContext *context) = 0;

    virtual antlrcpp::Any visitFilter_clause(SqlParsingParser::Filter_clauseContext *context) = 0;

    virtual antlrcpp::Any visitWindow_defn(SqlParsingParser::Window_defnContext *context) = 0;

    virtual antlrcpp::Any visitOver_clause(SqlParsingParser::Over_clauseContext *context) = 0;

    virtual antlrcpp::Any visitFrame_spec(SqlParsingParser::Frame_specContext *context) = 0;

    virtual antlrcpp::Any visitFrame_clause(SqlParsingParser::Frame_clauseContext *context) = 0;

    virtual antlrcpp::Any visitSimple_function_invocation(SqlParsingParser::Simple_function_invocationContext *context) = 0;

    virtual antlrcpp::Any visitAggregate_function_invocation(SqlParsingParser::Aggregate_function_invocationContext *context) = 0;

    virtual antlrcpp::Any visitWindow_function_invocation(SqlParsingParser::Window_function_invocationContext *context) = 0;

    virtual antlrcpp::Any visitCommon_table_stmt(SqlParsingParser::Common_table_stmtContext *context) = 0;

    virtual antlrcpp::Any visitOrder_by_stmt(SqlParsingParser::Order_by_stmtContext *context) = 0;

    virtual antlrcpp::Any visitLimit_stmt(SqlParsingParser::Limit_stmtContext *context) = 0;

    virtual antlrcpp::Any visitOrdering_term(SqlParsingParser::Ordering_termContext *context) = 0;

    virtual antlrcpp::Any visitAsc_desc(SqlParsingParser::Asc_descContext *context) = 0;

    virtual antlrcpp::Any visitFrame_left(SqlParsingParser::Frame_leftContext *context) = 0;

    virtual antlrcpp::Any visitFrame_right(SqlParsingParser::Frame_rightContext *context) = 0;

    virtual antlrcpp::Any visitFrame_single(SqlParsingParser::Frame_singleContext *context) = 0;

    virtual antlrcpp::Any visitWindow_function(SqlParsingParser::Window_functionContext *context) = 0;

    virtual antlrcpp::Any visitOffset(SqlParsingParser::OffsetContext *context) = 0;

    virtual antlrcpp::Any visitDefault_value(SqlParsingParser::Default_valueContext *context) = 0;

    virtual antlrcpp::Any visitPartition_by(SqlParsingParser::Partition_byContext *context) = 0;

    virtual antlrcpp::Any visitOrder_by_expr(SqlParsingParser::Order_by_exprContext *context) = 0;

    virtual antlrcpp::Any visitOrder_by_expr_asc_desc(SqlParsingParser::Order_by_expr_asc_descContext *context) = 0;

    virtual antlrcpp::Any visitExpr_asc_desc(SqlParsingParser::Expr_asc_descContext *context) = 0;

    virtual antlrcpp::Any visitInitial_select(SqlParsingParser::Initial_selectContext *context) = 0;

    virtual antlrcpp::Any visitRecursive_select(SqlParsingParser::Recursive_selectContext *context) = 0;

    virtual antlrcpp::Any visitUnary_operator(SqlParsingParser::Unary_operatorContext *context) = 0;

    virtual antlrcpp::Any visitError_message(SqlParsingParser::Error_messageContext *context) = 0;

    virtual antlrcpp::Any visitModule_argument(SqlParsingParser::Module_argumentContext *context) = 0;

    virtual antlrcpp::Any visitColumn_alias(SqlParsingParser::Column_aliasContext *context) = 0;

    virtual antlrcpp::Any visitKeyword(SqlParsingParser::KeywordContext *context) = 0;

    virtual antlrcpp::Any visitName(SqlParsingParser::NameContext *context) = 0;

    virtual antlrcpp::Any visitFunction_name(SqlParsingParser::Function_nameContext *context) = 0;

    virtual antlrcpp::Any visitSchema_name(SqlParsingParser::Schema_nameContext *context) = 0;

    virtual antlrcpp::Any visitTable_name(SqlParsingParser::Table_nameContext *context) = 0;

    virtual antlrcpp::Any visitTable_or_index_name(SqlParsingParser::Table_or_index_nameContext *context) = 0;

    virtual antlrcpp::Any visitNew_table_name(SqlParsingParser::New_table_nameContext *context) = 0;

    virtual antlrcpp::Any visitColumn_name(SqlParsingParser::Column_nameContext *context) = 0;

    virtual antlrcpp::Any visitCollation_name(SqlParsingParser::Collation_nameContext *context) = 0;

    virtual antlrcpp::Any visitForeign_table(SqlParsingParser::Foreign_tableContext *context) = 0;

    virtual antlrcpp::Any visitIndex_name(SqlParsingParser::Index_nameContext *context) = 0;

    virtual antlrcpp::Any visitTrigger_name(SqlParsingParser::Trigger_nameContext *context) = 0;

    virtual antlrcpp::Any visitView_name(SqlParsingParser::View_nameContext *context) = 0;

    virtual antlrcpp::Any visitModule_name(SqlParsingParser::Module_nameContext *context) = 0;

    virtual antlrcpp::Any visitPragma_name(SqlParsingParser::Pragma_nameContext *context) = 0;

    virtual antlrcpp::Any visitSavepoint_name(SqlParsingParser::Savepoint_nameContext *context) = 0;

    virtual antlrcpp::Any visitTable_alias(SqlParsingParser::Table_aliasContext *context) = 0;

    virtual antlrcpp::Any visitTransaction_name(SqlParsingParser::Transaction_nameContext *context) = 0;

    virtual antlrcpp::Any visitWindow_name(SqlParsingParser::Window_nameContext *context) = 0;

    virtual antlrcpp::Any visitAlias(SqlParsingParser::AliasContext *context) = 0;

    virtual antlrcpp::Any visitFilename(SqlParsingParser::FilenameContext *context) = 0;

    virtual antlrcpp::Any visitBase_window_name(SqlParsingParser::Base_window_nameContext *context) = 0;

    virtual antlrcpp::Any visitSimple_func(SqlParsingParser::Simple_funcContext *context) = 0;

    virtual antlrcpp::Any visitAggregate_func(SqlParsingParser::Aggregate_funcContext *context) = 0;

    virtual antlrcpp::Any visitTable_function_name(SqlParsingParser::Table_function_nameContext *context) = 0;

    virtual antlrcpp::Any visitAny_name(SqlParsingParser::Any_nameContext *context) = 0;


};

}  // namespace dsql.parser
