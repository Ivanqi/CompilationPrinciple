
// Generated from SqlParsing.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"


namespace dsql.parser {


class  SqlParsingParser : public antlr4::Parser {
public:
  enum {
    SCOL = 1, DOT = 2, OPEN_PAR = 3, CLOSE_PAR = 4, COMMA = 5, ASSIGN = 6, 
    STAR = 7, PLUS = 8, MINUS = 9, TILDE = 10, PIPE2 = 11, DIV = 12, MOD = 13, 
    LT2 = 14, GT2 = 15, AMP = 16, PIPE = 17, LT = 18, LT_EQ = 19, GT = 20, 
    GT_EQ = 21, EQ = 22, NOT_EQ1 = 23, NOT_EQ2 = 24, ABORT = 25, ACTION = 26, 
    ADD = 27, AFTER = 28, ALL = 29, ALTER = 30, ANALYZE = 31, AND = 32, 
    AS = 33, ASC = 34, ATTACH = 35, AUTOINCREMENT = 36, BEFORE = 37, BEGIN = 38, 
    BETWEEN = 39, BY = 40, CASCADE = 41, CASE = 42, CAST = 43, CHECK = 44, 
    COLLATE = 45, COLUMN = 46, COMMIT = 47, CONFLICT = 48, CONSTRAINT = 49, 
    CREATE = 50, CROSS = 51, CURRENT_DATE = 52, CURRENT_TIME = 53, CURRENT_TIMESTAMP = 54, 
    DATABASE = 55, DEFAULT = 56, DEFERRABLE = 57, DEFERRED = 58, DELETE = 59, 
    DESC = 60, DETACH = 61, DISTINCT = 62, DROP = 63, EACH = 64, ELSE = 65, 
    END = 66, ESCAPE = 67, EXCEPT = 68, EXCLUSIVE = 69, EXISTS = 70, EXPLAIN = 71, 
    FAIL = 72, FOR = 73, FOREIGN = 74, FROM = 75, FULL = 76, GLOB = 77, 
    GROUP = 78, HAVING = 79, IF = 80, IGNORE = 81, IMMEDIATE = 82, IN = 83, 
    INDEX = 84, INDEXED = 85, INITIALLY = 86, INNER = 87, INSERT = 88, INSTEAD = 89, 
    INTERSECT = 90, INTO = 91, IS = 92, ISNULL = 93, JOIN = 94, KEY = 95, 
    LEFT = 96, LIKE = 97, LIMIT = 98, MATCH = 99, NATURAL = 100, NO = 101, 
    NOT = 102, NOTNULL = 103, NULL_ = 104, OF = 105, OFFSET = 106, ON = 107, 
    OR = 108, ORDER = 109, OUTER = 110, PLAN = 111, PRAGMA = 112, PRIMARY = 113, 
    QUERY = 114, RAISE = 115, RECURSIVE = 116, REFERENCES = 117, REGEXP = 118, 
    REINDEX = 119, RELEASE = 120, RENAME = 121, REPLACE = 122, RESTRICT = 123, 
    RIGHT = 124, ROLLBACK = 125, ROW = 126, ROWS = 127, SAVEPOINT = 128, 
    SELECT = 129, SET = 130, TABLE = 131, TEMP = 132, TEMPORARY = 133, THEN = 134, 
    TO = 135, TRANSACTION = 136, TRIGGER = 137, UNION = 138, UNIQUE = 139, 
    UPDATE = 140, USING = 141, VACUUM = 142, VALUES = 143, VIEW = 144, VIRTUAL = 145, 
    WHEN = 146, WHERE = 147, WITH = 148, WITHOUT = 149, FIRST_VALUE = 150, 
    OVER = 151, PARTITION = 152, RANGE = 153, PRECEDING = 154, UNBOUNDED = 155, 
    CURRENT = 156, FOLLOWING = 157, CUME_DIST = 158, DENSE_RANK = 159, LAG = 160, 
    LAST_VALUE = 161, LEAD = 162, NTH_VALUE = 163, NTILE = 164, PERCENT_RANK = 165, 
    RANK = 166, ROW_NUMBER = 167, GENERATED = 168, ALWAYS = 169, STORED = 170, 
    TRUE_ = 171, FALSE_ = 172, WINDOW = 173, NULLS = 174, FIRST = 175, LAST = 176, 
    FILTER = 177, GROUPS = 178, EXCLUDE = 179, TIES = 180, OTHERS = 181, 
    DO = 182, NOTHING = 183, IDENTIFIER = 184, NUMERIC_LITERAL = 185, BIND_PARAMETER = 186, 
    STRING_LITERAL = 187, BLOB_LITERAL = 188, SINGLE_LINE_COMMENT = 189, 
    MULTILINE_COMMENT = 190, SPACES = 191, UNEXPECTED_CHAR = 192
  };

  enum {
    RuleSql_stmt_list = 0, RuleSql_stmt = 1, RuleAlter_table_stmt = 2, RuleAnalyze_stmt = 3, 
    RuleAttach_stmt = 4, RuleBegin_stmt = 5, RuleCommit_stmt = 6, RuleRollback_stmt = 7, 
    RuleSavepoint_stmt = 8, RuleRelease_stmt = 9, RuleCreate_index_stmt = 10, 
    RuleIndexed_column = 11, RuleCreate_table_stmt = 12, RuleColumn_def = 13, 
    RuleType_name = 14, RuleColumn_constraint = 15, RuleSigned_number = 16, 
    RuleTable_constraint = 17, RuleForeign_key_clause = 18, RuleConflict_clause = 19, 
    RuleCreate_trigger_stmt = 20, RuleCreate_view_stmt = 21, RuleCreate_virtual_table_stmt = 22, 
    RuleWith_clause = 23, RuleCte_table_name = 24, RuleRecursive_cte = 25, 
    RuleCommon_table_expression = 26, RuleDelete_stmt = 27, RuleDelete_stmt_limited = 28, 
    RuleDetach_stmt = 29, RuleDrop_stmt = 30, RuleExpr = 31, RuleRaise_function = 32, 
    RuleLiteral_value = 33, RuleInsert_stmt = 34, RuleUpsert_clause = 35, 
    RulePragma_stmt = 36, RulePragma_value = 37, RuleReindex_stmt = 38, 
    RuleSelect_stmt = 39, RuleJoin_clause = 40, RuleSelect_core = 41, RuleFactored_select_stmt = 42, 
    RuleSimple_select_stmt = 43, RuleCompound_select_stmt = 44, RuleTable_or_subquery = 45, 
    RuleResult_column = 46, RuleJoin_operator = 47, RuleJoin_constraint = 48, 
    RuleCompound_operator = 49, RuleUpdate_stmt = 50, RuleColumn_name_list = 51, 
    RuleUpdate_stmt_limited = 52, RuleQualified_table_name = 53, RuleVacuum_stmt = 54, 
    RuleFilter_clause = 55, RuleWindow_defn = 56, RuleOver_clause = 57, 
    RuleFrame_spec = 58, RuleFrame_clause = 59, RuleSimple_function_invocation = 60, 
    RuleAggregate_function_invocation = 61, RuleWindow_function_invocation = 62, 
    RuleCommon_table_stmt = 63, RuleOrder_by_stmt = 64, RuleLimit_stmt = 65, 
    RuleOrdering_term = 66, RuleAsc_desc = 67, RuleFrame_left = 68, RuleFrame_right = 69, 
    RuleFrame_single = 70, RuleWindow_function = 71, RuleOffset = 72, RuleDefault_value = 73, 
    RulePartition_by = 74, RuleOrder_by_expr = 75, RuleOrder_by_expr_asc_desc = 76, 
    RuleExpr_asc_desc = 77, RuleInitial_select = 78, RuleRecursive_select = 79, 
    RuleUnary_operator = 80, RuleError_message = 81, RuleModule_argument = 82, 
    RuleColumn_alias = 83, RuleKeyword = 84, RuleName = 85, RuleFunction_name = 86, 
    RuleSchema_name = 87, RuleTable_name = 88, RuleTable_or_index_name = 89, 
    RuleNew_table_name = 90, RuleColumn_name = 91, RuleCollation_name = 92, 
    RuleForeign_table = 93, RuleIndex_name = 94, RuleTrigger_name = 95, 
    RuleView_name = 96, RuleModule_name = 97, RulePragma_name = 98, RuleSavepoint_name = 99, 
    RuleTable_alias = 100, RuleTransaction_name = 101, RuleWindow_name = 102, 
    RuleAlias = 103, RuleFilename = 104, RuleBase_window_name = 105, RuleSimple_func = 106, 
    RuleAggregate_func = 107, RuleTable_function_name = 108, RuleAny_name = 109
  };

  SqlParsingParser(antlr4::TokenStream *input);
  ~SqlParsingParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class Sql_stmt_listContext;
  class Sql_stmtContext;
  class Alter_table_stmtContext;
  class Analyze_stmtContext;
  class Attach_stmtContext;
  class Begin_stmtContext;
  class Commit_stmtContext;
  class Rollback_stmtContext;
  class Savepoint_stmtContext;
  class Release_stmtContext;
  class Create_index_stmtContext;
  class Indexed_columnContext;
  class Create_table_stmtContext;
  class Column_defContext;
  class Type_nameContext;
  class Column_constraintContext;
  class Signed_numberContext;
  class Table_constraintContext;
  class Foreign_key_clauseContext;
  class Conflict_clauseContext;
  class Create_trigger_stmtContext;
  class Create_view_stmtContext;
  class Create_virtual_table_stmtContext;
  class With_clauseContext;
  class Cte_table_nameContext;
  class Recursive_cteContext;
  class Common_table_expressionContext;
  class Delete_stmtContext;
  class Delete_stmt_limitedContext;
  class Detach_stmtContext;
  class Drop_stmtContext;
  class ExprContext;
  class Raise_functionContext;
  class Literal_valueContext;
  class Insert_stmtContext;
  class Upsert_clauseContext;
  class Pragma_stmtContext;
  class Pragma_valueContext;
  class Reindex_stmtContext;
  class Select_stmtContext;
  class Join_clauseContext;
  class Select_coreContext;
  class Factored_select_stmtContext;
  class Simple_select_stmtContext;
  class Compound_select_stmtContext;
  class Table_or_subqueryContext;
  class Result_columnContext;
  class Join_operatorContext;
  class Join_constraintContext;
  class Compound_operatorContext;
  class Update_stmtContext;
  class Column_name_listContext;
  class Update_stmt_limitedContext;
  class Qualified_table_nameContext;
  class Vacuum_stmtContext;
  class Filter_clauseContext;
  class Window_defnContext;
  class Over_clauseContext;
  class Frame_specContext;
  class Frame_clauseContext;
  class Simple_function_invocationContext;
  class Aggregate_function_invocationContext;
  class Window_function_invocationContext;
  class Common_table_stmtContext;
  class Order_by_stmtContext;
  class Limit_stmtContext;
  class Ordering_termContext;
  class Asc_descContext;
  class Frame_leftContext;
  class Frame_rightContext;
  class Frame_singleContext;
  class Window_functionContext;
  class OffsetContext;
  class Default_valueContext;
  class Partition_byContext;
  class Order_by_exprContext;
  class Order_by_expr_asc_descContext;
  class Expr_asc_descContext;
  class Initial_selectContext;
  class Recursive_selectContext;
  class Unary_operatorContext;
  class Error_messageContext;
  class Module_argumentContext;
  class Column_aliasContext;
  class KeywordContext;
  class NameContext;
  class Function_nameContext;
  class Schema_nameContext;
  class Table_nameContext;
  class Table_or_index_nameContext;
  class New_table_nameContext;
  class Column_nameContext;
  class Collation_nameContext;
  class Foreign_tableContext;
  class Index_nameContext;
  class Trigger_nameContext;
  class View_nameContext;
  class Module_nameContext;
  class Pragma_nameContext;
  class Savepoint_nameContext;
  class Table_aliasContext;
  class Transaction_nameContext;
  class Window_nameContext;
  class AliasContext;
  class FilenameContext;
  class Base_window_nameContext;
  class Simple_funcContext;
  class Aggregate_funcContext;
  class Table_function_nameContext;
  class Any_nameContext; 

  class  Sql_stmt_listContext : public antlr4::ParserRuleContext {
  public:
    Sql_stmt_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Sql_stmtContext *> sql_stmt();
    Sql_stmtContext* sql_stmt(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SCOL();
    antlr4::tree::TerminalNode* SCOL(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sql_stmt_listContext* sql_stmt_list();

  class  Sql_stmtContext : public antlr4::ParserRuleContext {
  public:
    Sql_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Alter_table_stmtContext *alter_table_stmt();
    Analyze_stmtContext *analyze_stmt();
    Attach_stmtContext *attach_stmt();
    Begin_stmtContext *begin_stmt();
    Commit_stmtContext *commit_stmt();
    Create_index_stmtContext *create_index_stmt();
    Create_table_stmtContext *create_table_stmt();
    Create_trigger_stmtContext *create_trigger_stmt();
    Create_view_stmtContext *create_view_stmt();
    Create_virtual_table_stmtContext *create_virtual_table_stmt();
    Delete_stmtContext *delete_stmt();
    Delete_stmt_limitedContext *delete_stmt_limited();
    Detach_stmtContext *detach_stmt();
    Drop_stmtContext *drop_stmt();
    Insert_stmtContext *insert_stmt();
    Pragma_stmtContext *pragma_stmt();
    Reindex_stmtContext *reindex_stmt();
    Release_stmtContext *release_stmt();
    Rollback_stmtContext *rollback_stmt();
    Savepoint_stmtContext *savepoint_stmt();
    Select_stmtContext *select_stmt();
    Update_stmtContext *update_stmt();
    Update_stmt_limitedContext *update_stmt_limited();
    Vacuum_stmtContext *vacuum_stmt();
    antlr4::tree::TerminalNode *EXPLAIN();
    antlr4::tree::TerminalNode *QUERY();
    antlr4::tree::TerminalNode *PLAN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sql_stmtContext* sql_stmt();

  class  Alter_table_stmtContext : public antlr4::ParserRuleContext {
  public:
    SqlParsingParser::Column_nameContext *old_column_name = nullptr;;
    SqlParsingParser::Column_nameContext *new_column_name = nullptr;;
    Alter_table_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALTER();
    antlr4::tree::TerminalNode *TABLE();
    Table_nameContext *table_name();
    antlr4::tree::TerminalNode *RENAME();
    antlr4::tree::TerminalNode *ADD();
    Column_defContext *column_def();
    Schema_nameContext *schema_name();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *COLUMN();
    antlr4::tree::TerminalNode *TO();
    New_table_nameContext *new_table_name();
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Alter_table_stmtContext* alter_table_stmt();

  class  Analyze_stmtContext : public antlr4::ParserRuleContext {
  public:
    Analyze_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ANALYZE();
    Schema_nameContext *schema_name();
    Table_or_index_nameContext *table_or_index_name();
    antlr4::tree::TerminalNode *DOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Analyze_stmtContext* analyze_stmt();

  class  Attach_stmtContext : public antlr4::ParserRuleContext {
  public:
    Attach_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ATTACH();
    ExprContext *expr();
    antlr4::tree::TerminalNode *AS();
    Schema_nameContext *schema_name();
    antlr4::tree::TerminalNode *DATABASE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Attach_stmtContext* attach_stmt();

  class  Begin_stmtContext : public antlr4::ParserRuleContext {
  public:
    Begin_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BEGIN();
    antlr4::tree::TerminalNode *TRANSACTION();
    antlr4::tree::TerminalNode *DEFERRED();
    antlr4::tree::TerminalNode *IMMEDIATE();
    antlr4::tree::TerminalNode *EXCLUSIVE();
    Transaction_nameContext *transaction_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Begin_stmtContext* begin_stmt();

  class  Commit_stmtContext : public antlr4::ParserRuleContext {
  public:
    Commit_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMIT();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *TRANSACTION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Commit_stmtContext* commit_stmt();

  class  Rollback_stmtContext : public antlr4::ParserRuleContext {
  public:
    Rollback_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ROLLBACK();
    antlr4::tree::TerminalNode *TRANSACTION();
    antlr4::tree::TerminalNode *TO();
    Savepoint_nameContext *savepoint_name();
    antlr4::tree::TerminalNode *SAVEPOINT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rollback_stmtContext* rollback_stmt();

  class  Savepoint_stmtContext : public antlr4::ParserRuleContext {
  public:
    Savepoint_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SAVEPOINT();
    Savepoint_nameContext *savepoint_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Savepoint_stmtContext* savepoint_stmt();

  class  Release_stmtContext : public antlr4::ParserRuleContext {
  public:
    Release_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RELEASE();
    Savepoint_nameContext *savepoint_name();
    antlr4::tree::TerminalNode *SAVEPOINT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Release_stmtContext* release_stmt();

  class  Create_index_stmtContext : public antlr4::ParserRuleContext {
  public:
    Create_index_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    antlr4::tree::TerminalNode *INDEX();
    Index_nameContext *index_name();
    antlr4::tree::TerminalNode *ON();
    Table_nameContext *table_name();
    antlr4::tree::TerminalNode *OPEN_PAR();
    std::vector<Indexed_columnContext *> indexed_column();
    Indexed_columnContext* indexed_column(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *UNIQUE();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *EXISTS();
    Schema_nameContext *schema_name();
    antlr4::tree::TerminalNode *DOT();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *WHERE();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Create_index_stmtContext* create_index_stmt();

  class  Indexed_columnContext : public antlr4::ParserRuleContext {
  public:
    Indexed_columnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Column_nameContext *column_name();
    ExprContext *expr();
    antlr4::tree::TerminalNode *COLLATE();
    Collation_nameContext *collation_name();
    Asc_descContext *asc_desc();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Indexed_columnContext* indexed_column();

  class  Create_table_stmtContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *rowID = nullptr;;
    Create_table_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    antlr4::tree::TerminalNode *TABLE();
    Table_nameContext *table_name();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *EXISTS();
    Schema_nameContext *schema_name();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *TEMP();
    antlr4::tree::TerminalNode *TEMPORARY();
    antlr4::tree::TerminalNode *OPEN_PAR();
    std::vector<Column_defContext *> column_def();
    Column_defContext* column_def(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *AS();
    Select_stmtContext *select_stmt();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<Table_constraintContext *> table_constraint();
    Table_constraintContext* table_constraint(size_t i);
    antlr4::tree::TerminalNode *WITHOUT();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Create_table_stmtContext* create_table_stmt();

  class  Column_defContext : public antlr4::ParserRuleContext {
  public:
    Column_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Column_nameContext *column_name();
    Type_nameContext *type_name();
    std::vector<Column_constraintContext *> column_constraint();
    Column_constraintContext* column_constraint(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Column_defContext* column_def();

  class  Type_nameContext : public antlr4::ParserRuleContext {
  public:
    Type_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NameContext *> name();
    NameContext* name(size_t i);
    antlr4::tree::TerminalNode *OPEN_PAR();
    std::vector<Signed_numberContext *> signed_number();
    Signed_numberContext* signed_number(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *COMMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_nameContext* type_name();

  class  Column_constraintContext : public antlr4::ParserRuleContext {
  public:
    Column_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHECK();
    antlr4::tree::TerminalNode *OPEN_PAR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *DEFAULT();
    antlr4::tree::TerminalNode *COLLATE();
    Collation_nameContext *collation_name();
    Foreign_key_clauseContext *foreign_key_clause();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *CONSTRAINT();
    NameContext *name();
    antlr4::tree::TerminalNode *PRIMARY();
    antlr4::tree::TerminalNode *KEY();
    antlr4::tree::TerminalNode *UNIQUE();
    Signed_numberContext *signed_number();
    Literal_valueContext *literal_value();
    Conflict_clauseContext *conflict_clause();
    antlr4::tree::TerminalNode *GENERATED();
    antlr4::tree::TerminalNode *ALWAYS();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *NULL_();
    antlr4::tree::TerminalNode *STORED();
    antlr4::tree::TerminalNode *VIRTUAL();
    Asc_descContext *asc_desc();
    antlr4::tree::TerminalNode *AUTOINCREMENT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Column_constraintContext* column_constraint();

  class  Signed_numberContext : public antlr4::ParserRuleContext {
  public:
    Signed_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMERIC_LITERAL();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Signed_numberContext* signed_number();

  class  Table_constraintContext : public antlr4::ParserRuleContext {
  public:
    Table_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONSTRAINT();
    NameContext *name();
    antlr4::tree::TerminalNode *OPEN_PAR();
    std::vector<Indexed_columnContext *> indexed_column();
    Indexed_columnContext* indexed_column(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *CHECK();
    ExprContext *expr();
    antlr4::tree::TerminalNode *FOREIGN();
    antlr4::tree::TerminalNode *KEY();
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    Foreign_key_clauseContext *foreign_key_clause();
    antlr4::tree::TerminalNode *PRIMARY();
    antlr4::tree::TerminalNode *UNIQUE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    Conflict_clauseContext *conflict_clause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_constraintContext* table_constraint();

  class  Foreign_key_clauseContext : public antlr4::ParserRuleContext {
  public:
    Foreign_key_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REFERENCES();
    Foreign_tableContext *foreign_table();
    antlr4::tree::TerminalNode *OPEN_PAR();
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *DEFERRABLE();
    std::vector<antlr4::tree::TerminalNode *> ON();
    antlr4::tree::TerminalNode* ON(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MATCH();
    antlr4::tree::TerminalNode* MATCH(size_t i);
    std::vector<NameContext *> name();
    NameContext* name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DELETE();
    antlr4::tree::TerminalNode* DELETE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UPDATE();
    antlr4::tree::TerminalNode* UPDATE(size_t i);
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *INITIALLY();
    std::vector<antlr4::tree::TerminalNode *> CASCADE();
    antlr4::tree::TerminalNode* CASCADE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RESTRICT();
    antlr4::tree::TerminalNode* RESTRICT(size_t i);
    antlr4::tree::TerminalNode *DEFERRED();
    antlr4::tree::TerminalNode *IMMEDIATE();
    std::vector<antlr4::tree::TerminalNode *> SET();
    antlr4::tree::TerminalNode* SET(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NO();
    antlr4::tree::TerminalNode* NO(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ACTION();
    antlr4::tree::TerminalNode* ACTION(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NULL_();
    antlr4::tree::TerminalNode* NULL_(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DEFAULT();
    antlr4::tree::TerminalNode* DEFAULT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Foreign_key_clauseContext* foreign_key_clause();

  class  Conflict_clauseContext : public antlr4::ParserRuleContext {
  public:
    Conflict_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ON();
    antlr4::tree::TerminalNode *CONFLICT();
    antlr4::tree::TerminalNode *ROLLBACK();
    antlr4::tree::TerminalNode *ABORT();
    antlr4::tree::TerminalNode *FAIL();
    antlr4::tree::TerminalNode *IGNORE();
    antlr4::tree::TerminalNode *REPLACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Conflict_clauseContext* conflict_clause();

  class  Create_trigger_stmtContext : public antlr4::ParserRuleContext {
  public:
    Create_trigger_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    antlr4::tree::TerminalNode *TRIGGER();
    Trigger_nameContext *trigger_name();
    antlr4::tree::TerminalNode *ON();
    Table_nameContext *table_name();
    antlr4::tree::TerminalNode *BEGIN();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *DELETE();
    antlr4::tree::TerminalNode *INSERT();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *EXISTS();
    Schema_nameContext *schema_name();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *BEFORE();
    antlr4::tree::TerminalNode *AFTER();
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *EACH();
    antlr4::tree::TerminalNode *ROW();
    antlr4::tree::TerminalNode *WHEN();
    ExprContext *expr();
    std::vector<antlr4::tree::TerminalNode *> SCOL();
    antlr4::tree::TerminalNode* SCOL(size_t i);
    antlr4::tree::TerminalNode *TEMP();
    antlr4::tree::TerminalNode *TEMPORARY();
    antlr4::tree::TerminalNode *UPDATE();
    antlr4::tree::TerminalNode *INSTEAD();
    std::vector<antlr4::tree::TerminalNode *> OF();
    antlr4::tree::TerminalNode* OF(size_t i);
    std::vector<Update_stmtContext *> update_stmt();
    Update_stmtContext* update_stmt(size_t i);
    std::vector<Insert_stmtContext *> insert_stmt();
    Insert_stmtContext* insert_stmt(size_t i);
    std::vector<Delete_stmtContext *> delete_stmt();
    Delete_stmtContext* delete_stmt(size_t i);
    std::vector<Select_stmtContext *> select_stmt();
    Select_stmtContext* select_stmt(size_t i);
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Create_trigger_stmtContext* create_trigger_stmt();

  class  Create_view_stmtContext : public antlr4::ParserRuleContext {
  public:
    Create_view_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    antlr4::tree::TerminalNode *VIEW();
    View_nameContext *view_name();
    antlr4::tree::TerminalNode *AS();
    Select_stmtContext *select_stmt();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *EXISTS();
    Schema_nameContext *schema_name();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *OPEN_PAR();
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *TEMP();
    antlr4::tree::TerminalNode *TEMPORARY();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Create_view_stmtContext* create_view_stmt();

  class  Create_virtual_table_stmtContext : public antlr4::ParserRuleContext {
  public:
    Create_virtual_table_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    antlr4::tree::TerminalNode *VIRTUAL();
    antlr4::tree::TerminalNode *TABLE();
    Table_nameContext *table_name();
    antlr4::tree::TerminalNode *USING();
    Module_nameContext *module_name();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *EXISTS();
    Schema_nameContext *schema_name();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *OPEN_PAR();
    std::vector<Module_argumentContext *> module_argument();
    Module_argumentContext* module_argument(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAR();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Create_virtual_table_stmtContext* create_virtual_table_stmt();

  class  With_clauseContext : public antlr4::ParserRuleContext {
  public:
    With_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITH();
    std::vector<Cte_table_nameContext *> cte_table_name();
    Cte_table_nameContext* cte_table_name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AS();
    antlr4::tree::TerminalNode* AS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OPEN_PAR();
    antlr4::tree::TerminalNode* OPEN_PAR(size_t i);
    std::vector<Select_stmtContext *> select_stmt();
    Select_stmtContext* select_stmt(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CLOSE_PAR();
    antlr4::tree::TerminalNode* CLOSE_PAR(size_t i);
    antlr4::tree::TerminalNode *RECURSIVE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  With_clauseContext* with_clause();

  class  Cte_table_nameContext : public antlr4::ParserRuleContext {
  public:
    Cte_table_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Table_nameContext *table_name();
    antlr4::tree::TerminalNode *OPEN_PAR();
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAR();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cte_table_nameContext* cte_table_name();

  class  Recursive_cteContext : public antlr4::ParserRuleContext {
  public:
    Recursive_cteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Cte_table_nameContext *cte_table_name();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *OPEN_PAR();
    Initial_selectContext *initial_select();
    antlr4::tree::TerminalNode *UNION();
    Recursive_selectContext *recursive_select();
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *ALL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Recursive_cteContext* recursive_cte();

  class  Common_table_expressionContext : public antlr4::ParserRuleContext {
  public:
    Common_table_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Table_nameContext *table_name();
    antlr4::tree::TerminalNode *AS();
    std::vector<antlr4::tree::TerminalNode *> OPEN_PAR();
    antlr4::tree::TerminalNode* OPEN_PAR(size_t i);
    Select_stmtContext *select_stmt();
    std::vector<antlr4::tree::TerminalNode *> CLOSE_PAR();
    antlr4::tree::TerminalNode* CLOSE_PAR(size_t i);
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Common_table_expressionContext* common_table_expression();

  class  Delete_stmtContext : public antlr4::ParserRuleContext {
  public:
    Delete_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DELETE();
    antlr4::tree::TerminalNode *FROM();
    Qualified_table_nameContext *qualified_table_name();
    With_clauseContext *with_clause();
    antlr4::tree::TerminalNode *WHERE();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Delete_stmtContext* delete_stmt();

  class  Delete_stmt_limitedContext : public antlr4::ParserRuleContext {
  public:
    Delete_stmt_limitedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DELETE();
    antlr4::tree::TerminalNode *FROM();
    Qualified_table_nameContext *qualified_table_name();
    With_clauseContext *with_clause();
    antlr4::tree::TerminalNode *WHERE();
    ExprContext *expr();
    Limit_stmtContext *limit_stmt();
    Order_by_stmtContext *order_by_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Delete_stmt_limitedContext* delete_stmt_limited();

  class  Detach_stmtContext : public antlr4::ParserRuleContext {
  public:
    Detach_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DETACH();
    Schema_nameContext *schema_name();
    antlr4::tree::TerminalNode *DATABASE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Detach_stmtContext* detach_stmt();

  class  Drop_stmtContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *object = nullptr;;
    Drop_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DROP();
    Any_nameContext *any_name();
    antlr4::tree::TerminalNode *INDEX();
    antlr4::tree::TerminalNode *TABLE();
    antlr4::tree::TerminalNode *TRIGGER();
    antlr4::tree::TerminalNode *VIEW();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *EXISTS();
    Schema_nameContext *schema_name();
    antlr4::tree::TerminalNode *DOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Drop_stmtContext* drop_stmt();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Literal_valueContext *literal_value();
    antlr4::tree::TerminalNode *BIND_PARAMETER();
    Column_nameContext *column_name();
    Table_nameContext *table_name();
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    Schema_nameContext *schema_name();
    Unary_operatorContext *unary_operator();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    Function_nameContext *function_name();
    antlr4::tree::TerminalNode *OPEN_PAR();
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *STAR();
    Filter_clauseContext *filter_clause();
    Over_clauseContext *over_clause();
    antlr4::tree::TerminalNode *DISTINCT();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *CAST();
    antlr4::tree::TerminalNode *AS();
    Type_nameContext *type_name();
    Select_stmtContext *select_stmt();
    antlr4::tree::TerminalNode *EXISTS();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *CASE();
    antlr4::tree::TerminalNode *END();
    std::vector<antlr4::tree::TerminalNode *> WHEN();
    antlr4::tree::TerminalNode* WHEN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> THEN();
    antlr4::tree::TerminalNode* THEN(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    Raise_functionContext *raise_function();
    antlr4::tree::TerminalNode *PIPE2();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *LT2();
    antlr4::tree::TerminalNode *GT2();
    antlr4::tree::TerminalNode *AMP();
    antlr4::tree::TerminalNode *PIPE();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *LT_EQ();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *GT_EQ();
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NOT_EQ1();
    antlr4::tree::TerminalNode *NOT_EQ2();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *IN();
    antlr4::tree::TerminalNode *LIKE();
    antlr4::tree::TerminalNode *GLOB();
    antlr4::tree::TerminalNode *MATCH();
    antlr4::tree::TerminalNode *REGEXP();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *BETWEEN();
    antlr4::tree::TerminalNode *COLLATE();
    Collation_nameContext *collation_name();
    antlr4::tree::TerminalNode *ESCAPE();
    antlr4::tree::TerminalNode *ISNULL();
    antlr4::tree::TerminalNode *NOTNULL();
    antlr4::tree::TerminalNode *NULL_();
    Table_function_nameContext *table_function_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  Raise_functionContext : public antlr4::ParserRuleContext {
  public:
    Raise_functionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RAISE();
    antlr4::tree::TerminalNode *OPEN_PAR();
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *IGNORE();
    antlr4::tree::TerminalNode *COMMA();
    Error_messageContext *error_message();
    antlr4::tree::TerminalNode *ROLLBACK();
    antlr4::tree::TerminalNode *ABORT();
    antlr4::tree::TerminalNode *FAIL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Raise_functionContext* raise_function();

  class  Literal_valueContext : public antlr4::ParserRuleContext {
  public:
    Literal_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMERIC_LITERAL();
    antlr4::tree::TerminalNode *STRING_LITERAL();
    antlr4::tree::TerminalNode *BLOB_LITERAL();
    antlr4::tree::TerminalNode *NULL_();
    antlr4::tree::TerminalNode *TRUE_();
    antlr4::tree::TerminalNode *FALSE_();
    antlr4::tree::TerminalNode *CURRENT_TIME();
    antlr4::tree::TerminalNode *CURRENT_DATE();
    antlr4::tree::TerminalNode *CURRENT_TIMESTAMP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Literal_valueContext* literal_value();

  class  Insert_stmtContext : public antlr4::ParserRuleContext {
  public:
    Insert_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTO();
    Table_nameContext *table_name();
    antlr4::tree::TerminalNode *INSERT();
    antlr4::tree::TerminalNode *REPLACE();
    With_clauseContext *with_clause();
    Schema_nameContext *schema_name();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *AS();
    Table_aliasContext *table_alias();
    std::vector<antlr4::tree::TerminalNode *> OPEN_PAR();
    antlr4::tree::TerminalNode* OPEN_PAR(size_t i);
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CLOSE_PAR();
    antlr4::tree::TerminalNode* CLOSE_PAR(size_t i);
    antlr4::tree::TerminalNode *OR();
    Select_stmtContext *select_stmt();
    antlr4::tree::TerminalNode *ROLLBACK();
    antlr4::tree::TerminalNode *ABORT();
    antlr4::tree::TerminalNode *FAIL();
    antlr4::tree::TerminalNode *IGNORE();
    Upsert_clauseContext *upsert_clause();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *VALUES();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *DEFAULT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Insert_stmtContext* insert_stmt();

  class  Upsert_clauseContext : public antlr4::ParserRuleContext {
  public:
    Upsert_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ON();
    antlr4::tree::TerminalNode *CONFLICT();
    antlr4::tree::TerminalNode *DO();
    antlr4::tree::TerminalNode *NOTHING();
    antlr4::tree::TerminalNode *OPEN_PAR();
    std::vector<Indexed_columnContext *> indexed_column();
    Indexed_columnContext* indexed_column(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *UPDATE();
    antlr4::tree::TerminalNode *SET();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> WHERE();
    antlr4::tree::TerminalNode* WHERE(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EQ();
    antlr4::tree::TerminalNode* EQ(size_t i);
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    std::vector<Column_name_listContext *> column_name_list();
    Column_name_listContext* column_name_list(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Upsert_clauseContext* upsert_clause();

  class  Pragma_stmtContext : public antlr4::ParserRuleContext {
  public:
    Pragma_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRAGMA();
    Pragma_nameContext *pragma_name();
    Schema_nameContext *schema_name();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *ASSIGN();
    Pragma_valueContext *pragma_value();
    antlr4::tree::TerminalNode *OPEN_PAR();
    antlr4::tree::TerminalNode *CLOSE_PAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pragma_stmtContext* pragma_stmt();

  class  Pragma_valueContext : public antlr4::ParserRuleContext {
  public:
    Pragma_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Signed_numberContext *signed_number();
    NameContext *name();
    antlr4::tree::TerminalNode *STRING_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pragma_valueContext* pragma_value();

  class  Reindex_stmtContext : public antlr4::ParserRuleContext {
  public:
    Reindex_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REINDEX();
    Collation_nameContext *collation_name();
    Table_nameContext *table_name();
    Index_nameContext *index_name();
    Schema_nameContext *schema_name();
    antlr4::tree::TerminalNode *DOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Reindex_stmtContext* reindex_stmt();

  class  Select_stmtContext : public antlr4::ParserRuleContext {
  public:
    Select_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Select_coreContext *> select_core();
    Select_coreContext* select_core(size_t i);
    Common_table_stmtContext *common_table_stmt();
    std::vector<Compound_operatorContext *> compound_operator();
    Compound_operatorContext* compound_operator(size_t i);
    Order_by_stmtContext *order_by_stmt();
    Limit_stmtContext *limit_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Select_stmtContext* select_stmt();

  class  Join_clauseContext : public antlr4::ParserRuleContext {
  public:
    Join_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Table_or_subqueryContext *> table_or_subquery();
    Table_or_subqueryContext* table_or_subquery(size_t i);
    std::vector<Join_operatorContext *> join_operator();
    Join_operatorContext* join_operator(size_t i);
    std::vector<Join_constraintContext *> join_constraint();
    Join_constraintContext* join_constraint(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Join_clauseContext* join_clause();

  class  Select_coreContext : public antlr4::ParserRuleContext {
  public:
    Select_coreContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SELECT();
    std::vector<Result_columnContext *> result_column();
    Result_columnContext* result_column(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *FROM();
    antlr4::tree::TerminalNode *WHERE();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *GROUP();
    antlr4::tree::TerminalNode *BY();
    antlr4::tree::TerminalNode *WINDOW();
    std::vector<Window_nameContext *> window_name();
    Window_nameContext* window_name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AS();
    antlr4::tree::TerminalNode* AS(size_t i);
    std::vector<Window_defnContext *> window_defn();
    Window_defnContext* window_defn(size_t i);
    antlr4::tree::TerminalNode *DISTINCT();
    antlr4::tree::TerminalNode *ALL();
    std::vector<Table_or_subqueryContext *> table_or_subquery();
    Table_or_subqueryContext* table_or_subquery(size_t i);
    Join_clauseContext *join_clause();
    antlr4::tree::TerminalNode *HAVING();
    antlr4::tree::TerminalNode *VALUES();
    std::vector<antlr4::tree::TerminalNode *> OPEN_PAR();
    antlr4::tree::TerminalNode* OPEN_PAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CLOSE_PAR();
    antlr4::tree::TerminalNode* CLOSE_PAR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Select_coreContext* select_core();

  class  Factored_select_stmtContext : public antlr4::ParserRuleContext {
  public:
    Factored_select_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Select_stmtContext *select_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Factored_select_stmtContext* factored_select_stmt();

  class  Simple_select_stmtContext : public antlr4::ParserRuleContext {
  public:
    Simple_select_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Select_coreContext *select_core();
    Common_table_stmtContext *common_table_stmt();
    Order_by_stmtContext *order_by_stmt();
    Limit_stmtContext *limit_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_select_stmtContext* simple_select_stmt();

  class  Compound_select_stmtContext : public antlr4::ParserRuleContext {
  public:
    Compound_select_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Select_coreContext *> select_core();
    Select_coreContext* select_core(size_t i);
    Common_table_stmtContext *common_table_stmt();
    Order_by_stmtContext *order_by_stmt();
    Limit_stmtContext *limit_stmt();
    std::vector<antlr4::tree::TerminalNode *> INTERSECT();
    antlr4::tree::TerminalNode* INTERSECT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EXCEPT();
    antlr4::tree::TerminalNode* EXCEPT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UNION();
    antlr4::tree::TerminalNode* UNION(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ALL();
    antlr4::tree::TerminalNode* ALL(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Compound_select_stmtContext* compound_select_stmt();

  class  Table_or_subqueryContext : public antlr4::ParserRuleContext {
  public:
    Table_or_subqueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Table_nameContext *table_name();
    Schema_nameContext *schema_name();
    antlr4::tree::TerminalNode *DOT();
    Table_aliasContext *table_alias();
    antlr4::tree::TerminalNode *INDEXED();
    antlr4::tree::TerminalNode *BY();
    Index_nameContext *index_name();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *AS();
    Table_function_nameContext *table_function_name();
    antlr4::tree::TerminalNode *OPEN_PAR();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAR();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<Table_or_subqueryContext *> table_or_subquery();
    Table_or_subqueryContext* table_or_subquery(size_t i);
    Join_clauseContext *join_clause();
    Select_stmtContext *select_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_or_subqueryContext* table_or_subquery();

  class  Result_columnContext : public antlr4::ParserRuleContext {
  public:
    Result_columnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STAR();
    Table_nameContext *table_name();
    antlr4::tree::TerminalNode *DOT();
    ExprContext *expr();
    Column_aliasContext *column_alias();
    antlr4::tree::TerminalNode *AS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Result_columnContext* result_column();

  class  Join_operatorContext : public antlr4::ParserRuleContext {
  public:
    Join_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *JOIN();
    antlr4::tree::TerminalNode *NATURAL();
    antlr4::tree::TerminalNode *INNER();
    antlr4::tree::TerminalNode *CROSS();
    antlr4::tree::TerminalNode *LEFT();
    antlr4::tree::TerminalNode *OUTER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Join_operatorContext* join_operator();

  class  Join_constraintContext : public antlr4::ParserRuleContext {
  public:
    Join_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ON();
    ExprContext *expr();
    antlr4::tree::TerminalNode *USING();
    antlr4::tree::TerminalNode *OPEN_PAR();
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAR();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Join_constraintContext* join_constraint();

  class  Compound_operatorContext : public antlr4::ParserRuleContext {
  public:
    Compound_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNION();
    antlr4::tree::TerminalNode *ALL();
    antlr4::tree::TerminalNode *INTERSECT();
    antlr4::tree::TerminalNode *EXCEPT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Compound_operatorContext* compound_operator();

  class  Update_stmtContext : public antlr4::ParserRuleContext {
  public:
    Update_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UPDATE();
    Qualified_table_nameContext *qualified_table_name();
    antlr4::tree::TerminalNode *SET();
    std::vector<antlr4::tree::TerminalNode *> ASSIGN();
    antlr4::tree::TerminalNode* ASSIGN(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    std::vector<Column_name_listContext *> column_name_list();
    Column_name_listContext* column_name_list(size_t i);
    With_clauseContext *with_clause();
    antlr4::tree::TerminalNode *OR();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *WHERE();
    antlr4::tree::TerminalNode *ROLLBACK();
    antlr4::tree::TerminalNode *ABORT();
    antlr4::tree::TerminalNode *REPLACE();
    antlr4::tree::TerminalNode *FAIL();
    antlr4::tree::TerminalNode *IGNORE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Update_stmtContext* update_stmt();

  class  Column_name_listContext : public antlr4::ParserRuleContext {
  public:
    Column_name_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_PAR();
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAR();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Column_name_listContext* column_name_list();

  class  Update_stmt_limitedContext : public antlr4::ParserRuleContext {
  public:
    Update_stmt_limitedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UPDATE();
    Qualified_table_nameContext *qualified_table_name();
    antlr4::tree::TerminalNode *SET();
    std::vector<antlr4::tree::TerminalNode *> ASSIGN();
    antlr4::tree::TerminalNode* ASSIGN(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);
    std::vector<Column_name_listContext *> column_name_list();
    Column_name_listContext* column_name_list(size_t i);
    With_clauseContext *with_clause();
    antlr4::tree::TerminalNode *OR();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *WHERE();
    Limit_stmtContext *limit_stmt();
    antlr4::tree::TerminalNode *ROLLBACK();
    antlr4::tree::TerminalNode *ABORT();
    antlr4::tree::TerminalNode *REPLACE();
    antlr4::tree::TerminalNode *FAIL();
    antlr4::tree::TerminalNode *IGNORE();
    Order_by_stmtContext *order_by_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Update_stmt_limitedContext* update_stmt_limited();

  class  Qualified_table_nameContext : public antlr4::ParserRuleContext {
  public:
    Qualified_table_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Table_nameContext *table_name();
    Schema_nameContext *schema_name();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *AS();
    AliasContext *alias();
    antlr4::tree::TerminalNode *INDEXED();
    antlr4::tree::TerminalNode *BY();
    Index_nameContext *index_name();
    antlr4::tree::TerminalNode *NOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Qualified_table_nameContext* qualified_table_name();

  class  Vacuum_stmtContext : public antlr4::ParserRuleContext {
  public:
    Vacuum_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VACUUM();
    Schema_nameContext *schema_name();
    antlr4::tree::TerminalNode *INTO();
    FilenameContext *filename();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Vacuum_stmtContext* vacuum_stmt();

  class  Filter_clauseContext : public antlr4::ParserRuleContext {
  public:
    Filter_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FILTER();
    antlr4::tree::TerminalNode *OPEN_PAR();
    antlr4::tree::TerminalNode *WHERE();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CLOSE_PAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Filter_clauseContext* filter_clause();

  class  Window_defnContext : public antlr4::ParserRuleContext {
  public:
    Window_defnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_PAR();
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *ORDER();
    std::vector<antlr4::tree::TerminalNode *> BY();
    antlr4::tree::TerminalNode* BY(size_t i);
    std::vector<Ordering_termContext *> ordering_term();
    Ordering_termContext* ordering_term(size_t i);
    Base_window_nameContext *base_window_name();
    antlr4::tree::TerminalNode *PARTITION();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    Frame_specContext *frame_spec();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Window_defnContext* window_defn();

  class  Over_clauseContext : public antlr4::ParserRuleContext {
  public:
    Over_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OVER();
    Window_nameContext *window_name();
    antlr4::tree::TerminalNode *OPEN_PAR();
    antlr4::tree::TerminalNode *CLOSE_PAR();
    Base_window_nameContext *base_window_name();
    antlr4::tree::TerminalNode *PARTITION();
    std::vector<antlr4::tree::TerminalNode *> BY();
    antlr4::tree::TerminalNode* BY(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *ORDER();
    std::vector<Ordering_termContext *> ordering_term();
    Ordering_termContext* ordering_term(size_t i);
    Frame_specContext *frame_spec();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Over_clauseContext* over_clause();

  class  Frame_specContext : public antlr4::ParserRuleContext {
  public:
    Frame_specContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Frame_clauseContext *frame_clause();
    antlr4::tree::TerminalNode *EXCLUDE();
    antlr4::tree::TerminalNode *GROUP();
    antlr4::tree::TerminalNode *TIES();
    antlr4::tree::TerminalNode *NO();
    antlr4::tree::TerminalNode *OTHERS();
    antlr4::tree::TerminalNode *CURRENT();
    antlr4::tree::TerminalNode *ROW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Frame_specContext* frame_spec();

  class  Frame_clauseContext : public antlr4::ParserRuleContext {
  public:
    Frame_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RANGE();
    antlr4::tree::TerminalNode *ROWS();
    antlr4::tree::TerminalNode *GROUPS();
    Frame_singleContext *frame_single();
    antlr4::tree::TerminalNode *BETWEEN();
    Frame_leftContext *frame_left();
    antlr4::tree::TerminalNode *AND();
    Frame_rightContext *frame_right();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Frame_clauseContext* frame_clause();

  class  Simple_function_invocationContext : public antlr4::ParserRuleContext {
  public:
    Simple_function_invocationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_funcContext *simple_func();
    antlr4::tree::TerminalNode *OPEN_PAR();
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *STAR();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_function_invocationContext* simple_function_invocation();

  class  Aggregate_function_invocationContext : public antlr4::ParserRuleContext {
  public:
    Aggregate_function_invocationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Aggregate_funcContext *aggregate_func();
    antlr4::tree::TerminalNode *OPEN_PAR();
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *STAR();
    Filter_clauseContext *filter_clause();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *DISTINCT();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Aggregate_function_invocationContext* aggregate_function_invocation();

  class  Window_function_invocationContext : public antlr4::ParserRuleContext {
  public:
    Window_function_invocationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Window_functionContext *window_function();
    antlr4::tree::TerminalNode *OPEN_PAR();
    antlr4::tree::TerminalNode *CLOSE_PAR();
    antlr4::tree::TerminalNode *OVER();
    Window_defnContext *window_defn();
    Window_nameContext *window_name();
    antlr4::tree::TerminalNode *STAR();
    Filter_clauseContext *filter_clause();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Window_function_invocationContext* window_function_invocation();

  class  Common_table_stmtContext : public antlr4::ParserRuleContext {
  public:
    Common_table_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITH();
    std::vector<Common_table_expressionContext *> common_table_expression();
    Common_table_expressionContext* common_table_expression(size_t i);
    antlr4::tree::TerminalNode *RECURSIVE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Common_table_stmtContext* common_table_stmt();

  class  Order_by_stmtContext : public antlr4::ParserRuleContext {
  public:
    Order_by_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ORDER();
    antlr4::tree::TerminalNode *BY();
    std::vector<Ordering_termContext *> ordering_term();
    Ordering_termContext* ordering_term(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Order_by_stmtContext* order_by_stmt();

  class  Limit_stmtContext : public antlr4::ParserRuleContext {
  public:
    Limit_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LIMIT();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *OFFSET();
    antlr4::tree::TerminalNode *COMMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Limit_stmtContext* limit_stmt();

  class  Ordering_termContext : public antlr4::ParserRuleContext {
  public:
    Ordering_termContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    antlr4::tree::TerminalNode *COLLATE();
    Collation_nameContext *collation_name();
    Asc_descContext *asc_desc();
    antlr4::tree::TerminalNode *NULLS();
    antlr4::tree::TerminalNode *FIRST();
    antlr4::tree::TerminalNode *LAST();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ordering_termContext* ordering_term();

  class  Asc_descContext : public antlr4::ParserRuleContext {
  public:
    Asc_descContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASC();
    antlr4::tree::TerminalNode *DESC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Asc_descContext* asc_desc();

  class  Frame_leftContext : public antlr4::ParserRuleContext {
  public:
    Frame_leftContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    antlr4::tree::TerminalNode *PRECEDING();
    antlr4::tree::TerminalNode *FOLLOWING();
    antlr4::tree::TerminalNode *CURRENT();
    antlr4::tree::TerminalNode *ROW();
    antlr4::tree::TerminalNode *UNBOUNDED();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Frame_leftContext* frame_left();

  class  Frame_rightContext : public antlr4::ParserRuleContext {
  public:
    Frame_rightContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    antlr4::tree::TerminalNode *PRECEDING();
    antlr4::tree::TerminalNode *FOLLOWING();
    antlr4::tree::TerminalNode *CURRENT();
    antlr4::tree::TerminalNode *ROW();
    antlr4::tree::TerminalNode *UNBOUNDED();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Frame_rightContext* frame_right();

  class  Frame_singleContext : public antlr4::ParserRuleContext {
  public:
    Frame_singleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    antlr4::tree::TerminalNode *PRECEDING();
    antlr4::tree::TerminalNode *UNBOUNDED();
    antlr4::tree::TerminalNode *CURRENT();
    antlr4::tree::TerminalNode *ROW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Frame_singleContext* frame_single();

  class  Window_functionContext : public antlr4::ParserRuleContext {
  public:
    Window_functionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> OPEN_PAR();
    antlr4::tree::TerminalNode* OPEN_PAR(size_t i);
    ExprContext *expr();
    std::vector<antlr4::tree::TerminalNode *> CLOSE_PAR();
    antlr4::tree::TerminalNode* CLOSE_PAR(size_t i);
    antlr4::tree::TerminalNode *OVER();
    Order_by_expr_asc_descContext *order_by_expr_asc_desc();
    antlr4::tree::TerminalNode *FIRST_VALUE();
    antlr4::tree::TerminalNode *LAST_VALUE();
    Partition_byContext *partition_by();
    Frame_clauseContext *frame_clause();
    antlr4::tree::TerminalNode *CUME_DIST();
    antlr4::tree::TerminalNode *PERCENT_RANK();
    Order_by_exprContext *order_by_expr();
    antlr4::tree::TerminalNode *DENSE_RANK();
    antlr4::tree::TerminalNode *RANK();
    antlr4::tree::TerminalNode *ROW_NUMBER();
    antlr4::tree::TerminalNode *LAG();
    antlr4::tree::TerminalNode *LEAD();
    OffsetContext *offset();
    Default_valueContext *default_value();
    antlr4::tree::TerminalNode *NTH_VALUE();
    antlr4::tree::TerminalNode *COMMA();
    Signed_numberContext *signed_number();
    antlr4::tree::TerminalNode *NTILE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Window_functionContext* window_function();

  class  OffsetContext : public antlr4::ParserRuleContext {
  public:
    OffsetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    Signed_numberContext *signed_number();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OffsetContext* offset();

  class  Default_valueContext : public antlr4::ParserRuleContext {
  public:
    Default_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    Signed_numberContext *signed_number();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Default_valueContext* default_value();

  class  Partition_byContext : public antlr4::ParserRuleContext {
  public:
    Partition_byContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PARTITION();
    antlr4::tree::TerminalNode *BY();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Partition_byContext* partition_by();

  class  Order_by_exprContext : public antlr4::ParserRuleContext {
  public:
    Order_by_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ORDER();
    antlr4::tree::TerminalNode *BY();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Order_by_exprContext* order_by_expr();

  class  Order_by_expr_asc_descContext : public antlr4::ParserRuleContext {
  public:
    Order_by_expr_asc_descContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ORDER();
    antlr4::tree::TerminalNode *BY();
    Order_by_expr_asc_descContext *order_by_expr_asc_desc();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Order_by_expr_asc_descContext* order_by_expr_asc_desc();

  class  Expr_asc_descContext : public antlr4::ParserRuleContext {
  public:
    Expr_asc_descContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<Asc_descContext *> asc_desc();
    Asc_descContext* asc_desc(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr_asc_descContext* expr_asc_desc();

  class  Initial_selectContext : public antlr4::ParserRuleContext {
  public:
    Initial_selectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Select_stmtContext *select_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Initial_selectContext* initial_select();

  class  Recursive_selectContext : public antlr4::ParserRuleContext {
  public:
    Recursive_selectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Select_stmtContext *select_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Recursive_selectContext* recursive_select();

  class  Unary_operatorContext : public antlr4::ParserRuleContext {
  public:
    Unary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *TILDE();
    antlr4::tree::TerminalNode *NOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_operatorContext* unary_operator();

  class  Error_messageContext : public antlr4::ParserRuleContext {
  public:
    Error_messageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Error_messageContext* error_message();

  class  Module_argumentContext : public antlr4::ParserRuleContext {
  public:
    Module_argumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    Column_defContext *column_def();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_argumentContext* module_argument();

  class  Column_aliasContext : public antlr4::ParserRuleContext {
  public:
    Column_aliasContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *STRING_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Column_aliasContext* column_alias();

  class  KeywordContext : public antlr4::ParserRuleContext {
  public:
    KeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ABORT();
    antlr4::tree::TerminalNode *ACTION();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *AFTER();
    antlr4::tree::TerminalNode *ALL();
    antlr4::tree::TerminalNode *ALTER();
    antlr4::tree::TerminalNode *ANALYZE();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *ASC();
    antlr4::tree::TerminalNode *ATTACH();
    antlr4::tree::TerminalNode *AUTOINCREMENT();
    antlr4::tree::TerminalNode *BEFORE();
    antlr4::tree::TerminalNode *BEGIN();
    antlr4::tree::TerminalNode *BETWEEN();
    antlr4::tree::TerminalNode *BY();
    antlr4::tree::TerminalNode *CASCADE();
    antlr4::tree::TerminalNode *CASE();
    antlr4::tree::TerminalNode *CAST();
    antlr4::tree::TerminalNode *CHECK();
    antlr4::tree::TerminalNode *COLLATE();
    antlr4::tree::TerminalNode *COLUMN();
    antlr4::tree::TerminalNode *COMMIT();
    antlr4::tree::TerminalNode *CONFLICT();
    antlr4::tree::TerminalNode *CONSTRAINT();
    antlr4::tree::TerminalNode *CREATE();
    antlr4::tree::TerminalNode *CROSS();
    antlr4::tree::TerminalNode *CURRENT_DATE();
    antlr4::tree::TerminalNode *CURRENT_TIME();
    antlr4::tree::TerminalNode *CURRENT_TIMESTAMP();
    antlr4::tree::TerminalNode *DATABASE();
    antlr4::tree::TerminalNode *DEFAULT();
    antlr4::tree::TerminalNode *DEFERRABLE();
    antlr4::tree::TerminalNode *DEFERRED();
    antlr4::tree::TerminalNode *DELETE();
    antlr4::tree::TerminalNode *DESC();
    antlr4::tree::TerminalNode *DETACH();
    antlr4::tree::TerminalNode *DISTINCT();
    antlr4::tree::TerminalNode *DROP();
    antlr4::tree::TerminalNode *EACH();
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *ESCAPE();
    antlr4::tree::TerminalNode *EXCEPT();
    antlr4::tree::TerminalNode *EXCLUSIVE();
    antlr4::tree::TerminalNode *EXISTS();
    antlr4::tree::TerminalNode *EXPLAIN();
    antlr4::tree::TerminalNode *FAIL();
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *FOREIGN();
    antlr4::tree::TerminalNode *FROM();
    antlr4::tree::TerminalNode *FULL();
    antlr4::tree::TerminalNode *GLOB();
    antlr4::tree::TerminalNode *GROUP();
    antlr4::tree::TerminalNode *HAVING();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *IGNORE();
    antlr4::tree::TerminalNode *IMMEDIATE();
    antlr4::tree::TerminalNode *IN();
    antlr4::tree::TerminalNode *INDEX();
    antlr4::tree::TerminalNode *INDEXED();
    antlr4::tree::TerminalNode *INITIALLY();
    antlr4::tree::TerminalNode *INNER();
    antlr4::tree::TerminalNode *INSERT();
    antlr4::tree::TerminalNode *INSTEAD();
    antlr4::tree::TerminalNode *INTERSECT();
    antlr4::tree::TerminalNode *INTO();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *ISNULL();
    antlr4::tree::TerminalNode *JOIN();
    antlr4::tree::TerminalNode *KEY();
    antlr4::tree::TerminalNode *LEFT();
    antlr4::tree::TerminalNode *LIKE();
    antlr4::tree::TerminalNode *LIMIT();
    antlr4::tree::TerminalNode *MATCH();
    antlr4::tree::TerminalNode *NATURAL();
    antlr4::tree::TerminalNode *NO();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *NOTNULL();
    antlr4::tree::TerminalNode *NULL_();
    antlr4::tree::TerminalNode *OF();
    antlr4::tree::TerminalNode *OFFSET();
    antlr4::tree::TerminalNode *ON();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *ORDER();
    antlr4::tree::TerminalNode *OUTER();
    antlr4::tree::TerminalNode *PLAN();
    antlr4::tree::TerminalNode *PRAGMA();
    antlr4::tree::TerminalNode *PRIMARY();
    antlr4::tree::TerminalNode *QUERY();
    antlr4::tree::TerminalNode *RAISE();
    antlr4::tree::TerminalNode *RECURSIVE();
    antlr4::tree::TerminalNode *REFERENCES();
    antlr4::tree::TerminalNode *REGEXP();
    antlr4::tree::TerminalNode *REINDEX();
    antlr4::tree::TerminalNode *RELEASE();
    antlr4::tree::TerminalNode *RENAME();
    antlr4::tree::TerminalNode *REPLACE();
    antlr4::tree::TerminalNode *RESTRICT();
    antlr4::tree::TerminalNode *RIGHT();
    antlr4::tree::TerminalNode *ROLLBACK();
    antlr4::tree::TerminalNode *ROW();
    antlr4::tree::TerminalNode *ROWS();
    antlr4::tree::TerminalNode *SAVEPOINT();
    antlr4::tree::TerminalNode *SELECT();
    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *TABLE();
    antlr4::tree::TerminalNode *TEMP();
    antlr4::tree::TerminalNode *TEMPORARY();
    antlr4::tree::TerminalNode *THEN();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *TRANSACTION();
    antlr4::tree::TerminalNode *TRIGGER();
    antlr4::tree::TerminalNode *UNION();
    antlr4::tree::TerminalNode *UNIQUE();
    antlr4::tree::TerminalNode *UPDATE();
    antlr4::tree::TerminalNode *USING();
    antlr4::tree::TerminalNode *VACUUM();
    antlr4::tree::TerminalNode *VALUES();
    antlr4::tree::TerminalNode *VIEW();
    antlr4::tree::TerminalNode *VIRTUAL();
    antlr4::tree::TerminalNode *WHEN();
    antlr4::tree::TerminalNode *WHERE();
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *WITHOUT();
    antlr4::tree::TerminalNode *FIRST_VALUE();
    antlr4::tree::TerminalNode *OVER();
    antlr4::tree::TerminalNode *PARTITION();
    antlr4::tree::TerminalNode *RANGE();
    antlr4::tree::TerminalNode *PRECEDING();
    antlr4::tree::TerminalNode *UNBOUNDED();
    antlr4::tree::TerminalNode *CURRENT();
    antlr4::tree::TerminalNode *FOLLOWING();
    antlr4::tree::TerminalNode *CUME_DIST();
    antlr4::tree::TerminalNode *DENSE_RANK();
    antlr4::tree::TerminalNode *LAG();
    antlr4::tree::TerminalNode *LAST_VALUE();
    antlr4::tree::TerminalNode *LEAD();
    antlr4::tree::TerminalNode *NTH_VALUE();
    antlr4::tree::TerminalNode *NTILE();
    antlr4::tree::TerminalNode *PERCENT_RANK();
    antlr4::tree::TerminalNode *RANK();
    antlr4::tree::TerminalNode *ROW_NUMBER();
    antlr4::tree::TerminalNode *GENERATED();
    antlr4::tree::TerminalNode *ALWAYS();
    antlr4::tree::TerminalNode *STORED();
    antlr4::tree::TerminalNode *TRUE_();
    antlr4::tree::TerminalNode *FALSE_();
    antlr4::tree::TerminalNode *WINDOW();
    antlr4::tree::TerminalNode *NULLS();
    antlr4::tree::TerminalNode *FIRST();
    antlr4::tree::TerminalNode *LAST();
    antlr4::tree::TerminalNode *FILTER();
    antlr4::tree::TerminalNode *GROUPS();
    antlr4::tree::TerminalNode *EXCLUDE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KeywordContext* keyword();

  class  NameContext : public antlr4::ParserRuleContext {
  public:
    NameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NameContext* name();

  class  Function_nameContext : public antlr4::ParserRuleContext {
  public:
    Function_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_nameContext* function_name();

  class  Schema_nameContext : public antlr4::ParserRuleContext {
  public:
    Schema_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Schema_nameContext* schema_name();

  class  Table_nameContext : public antlr4::ParserRuleContext {
  public:
    Table_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_nameContext* table_name();

  class  Table_or_index_nameContext : public antlr4::ParserRuleContext {
  public:
    Table_or_index_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_or_index_nameContext* table_or_index_name();

  class  New_table_nameContext : public antlr4::ParserRuleContext {
  public:
    New_table_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  New_table_nameContext* new_table_name();

  class  Column_nameContext : public antlr4::ParserRuleContext {
  public:
    Column_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Column_nameContext* column_name();

  class  Collation_nameContext : public antlr4::ParserRuleContext {
  public:
    Collation_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Collation_nameContext* collation_name();

  class  Foreign_tableContext : public antlr4::ParserRuleContext {
  public:
    Foreign_tableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Foreign_tableContext* foreign_table();

  class  Index_nameContext : public antlr4::ParserRuleContext {
  public:
    Index_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Index_nameContext* index_name();

  class  Trigger_nameContext : public antlr4::ParserRuleContext {
  public:
    Trigger_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Trigger_nameContext* trigger_name();

  class  View_nameContext : public antlr4::ParserRuleContext {
  public:
    View_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  View_nameContext* view_name();

  class  Module_nameContext : public antlr4::ParserRuleContext {
  public:
    Module_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_nameContext* module_name();

  class  Pragma_nameContext : public antlr4::ParserRuleContext {
  public:
    Pragma_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pragma_nameContext* pragma_name();

  class  Savepoint_nameContext : public antlr4::ParserRuleContext {
  public:
    Savepoint_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Savepoint_nameContext* savepoint_name();

  class  Table_aliasContext : public antlr4::ParserRuleContext {
  public:
    Table_aliasContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_aliasContext* table_alias();

  class  Transaction_nameContext : public antlr4::ParserRuleContext {
  public:
    Transaction_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Transaction_nameContext* transaction_name();

  class  Window_nameContext : public antlr4::ParserRuleContext {
  public:
    Window_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Window_nameContext* window_name();

  class  AliasContext : public antlr4::ParserRuleContext {
  public:
    AliasContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AliasContext* alias();

  class  FilenameContext : public antlr4::ParserRuleContext {
  public:
    FilenameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FilenameContext* filename();

  class  Base_window_nameContext : public antlr4::ParserRuleContext {
  public:
    Base_window_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Base_window_nameContext* base_window_name();

  class  Simple_funcContext : public antlr4::ParserRuleContext {
  public:
    Simple_funcContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_funcContext* simple_func();

  class  Aggregate_funcContext : public antlr4::ParserRuleContext {
  public:
    Aggregate_funcContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Aggregate_funcContext* aggregate_func();

  class  Table_function_nameContext : public antlr4::ParserRuleContext {
  public:
    Table_function_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_function_nameContext* table_function_name();

  class  Any_nameContext : public antlr4::ParserRuleContext {
  public:
    Any_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    KeywordContext *keyword();
    antlr4::tree::TerminalNode *STRING_LITERAL();
    antlr4::tree::TerminalNode *OPEN_PAR();
    Any_nameContext *any_name();
    antlr4::tree::TerminalNode *CLOSE_PAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Any_nameContext* any_name();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace dsql.parser
