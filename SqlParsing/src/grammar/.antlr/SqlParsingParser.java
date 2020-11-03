// Generated from /data/web/log_service/CompilationPrinciple/SqlParsing/src/grammar/SqlParsing.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class SqlParsingParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.7.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, T__23=24, 
		EXPLAIN=25, QUERY=26, PLAN=27, ALTER=28, TABLE=29, RENAME=30, TO=31, COLUMN=32, 
		ADD=33, ANALYZE=34, ATTACH=35, DATABASE=36, AS=37, BEGIN=38, DEFERRED=39, 
		IMMEDIATE=40, EXCLUSIVE=41, TRANSACTION=42, COMMIT=43, END=44, ROLLBACK=45, 
		SAVEPOINT=46, RELEASE=47, CREATE=48, UNIQUE=49, INDEX=50, IF=51, NOT=52, 
		EXISTS=53, ON=54, WHERE=55, COLLATE=56, TEMP=57, TEMPORARY=58, WITHOUT=59, 
		IDENTIFIER=60, CONSTRAINT=61, PRIMARY=62, KEY=63, AUTOINCREMENT=64, NULL_=65, 
		CHECK=66, DEFAULT=67, GENERATED=68, ALWAYS=69, STORED=70, VIRTUAL=71, 
		NUMERIC_LITERAL=72, FOREIGN=73, REFERENCES=74, DELETE=75, UPDATE=76, SET=77, 
		CASCADE=78, RESTRICT=79, NO=80, ACTION=81, MATCH=82, DEFERRABLE=83, INITIALLY=84, 
		CONFLICT=85, ABORT=86, FAIL=87, IGNORE=88, REPLACE=89, TRIGGER=90, BEFORE=91, 
		AFTER=92, INSTEAD=93, OF=94, INSERT=95, FOR=96, EACH=97, ROW=98, WHEN=99, 
		VIEW=100, USING=101, WITH=102, RECURSIVE=103, UNION=104, ALL=105, FROM=106, 
		DETACH=107, DROP=108, BIND_PARAMETER=109, DISTINCT=110, CAST=111, CASE=112, 
		THEN=113, ELSE=114, IS=115, IN=116, LIKE=117, GLOB=118, REGEXP=119, AND=120, 
		OR=121, BETWEEN=122, ESCAPE=123, ISNULL=124, NOTNULL=125, RAISE=126, STRING_LITERAL=127, 
		BLOB_LITERAL=128, TRUE_=129, FALSE_=130, CURRENT_TIME=131, CURRENT_DATE=132, 
		CURRENT_TIMESTAMP=133, INTO=134, VALUES=135, DO=136, NOTHING=137, EQ=138, 
		PRAGMA=139, REINDEX=140, SELECT=141, GROUP=142, BY=143, HAVING=144, WINDOW=145, 
		INTERSECT=146, EXCEPT=147, INDEXED=148, NATURAL=149, LEFT=150, OUTER=151, 
		INNER=152, CROSS=153, JOIN=154, VACUUM=155, FILTER=156, PARTITION=157, 
		ORDER=158, OVER=159, EXCLUDE=160, OTHERS=161, CURRENT=162, TIES=163, RANGE=164, 
		ROWS=165, GROUPS=166, LIMIT=167, OFFSET=168, NULLS=169, FIRST=170, LAST=171, 
		ASC=172, DESC=173, PRECEDING=174, FOLLOWING=175, UNBOUNDED=176, FIRST_VALUE=177, 
		LAST_VALUE=178, CUME_DIST=179, PERCENT_RANK=180, DENSE_RANK=181, RANK=182, 
		ROW_NUMBER=183, LAG=184, LEAD=185, NTH_VALUE=186, NTILE=187, FULL=188, 
		RIGHT=189;
	public static final int
		RULE_sql_stmt_list = 0, RULE_sql_stmt = 1, RULE_alter_table_stmt = 2, 
		RULE_analyze_stmt = 3, RULE_attach_stmt = 4, RULE_begin_stmt = 5, RULE_commit_stmt = 6, 
		RULE_rollback_stmt = 7, RULE_savepoint_stmt = 8, RULE_release_stmt = 9, 
		RULE_create_index_stmt = 10, RULE_indexed_column = 11, RULE_create_table_stmt = 12, 
		RULE_column_def = 13, RULE_type_name = 14, RULE_column_constraint = 15, 
		RULE_signed_number = 16, RULE_table_constraint = 17, RULE_foreign_key_clause = 18, 
		RULE_conflict_clause = 19, RULE_create_trigger_stmt = 20, RULE_create_view_stmt = 21, 
		RULE_create_virtual_table_stmt = 22, RULE_with_clause = 23, RULE_cte_table_name = 24, 
		RULE_recursive_cte = 25, RULE_common_table_expression = 26, RULE_delete_stmt = 27, 
		RULE_delete_stmt_limited = 28, RULE_detach_stmt = 29, RULE_drop_stmt = 30, 
		RULE_expr = 31, RULE_raise_function = 32, RULE_literal_value = 33, RULE_insert_stmt = 34, 
		RULE_upsert_clause = 35, RULE_pragma_stmt = 36, RULE_pragma_value = 37, 
		RULE_reindex_stmt = 38, RULE_select_stmt = 39, RULE_join_clause = 40, 
		RULE_select_core = 41, RULE_factored_select_stmt = 42, RULE_simple_select_stmt = 43, 
		RULE_compound_select_stmt = 44, RULE_table_or_subquery = 45, RULE_result_column = 46, 
		RULE_join_operator = 47, RULE_join_constraint = 48, RULE_compound_operator = 49, 
		RULE_update_stmt = 50, RULE_column_name_list = 51, RULE_update_stmt_limited = 52, 
		RULE_qualified_table_name = 53, RULE_vacuum_stmt = 54, RULE_filter_clause = 55, 
		RULE_window_defn = 56, RULE_over_clause = 57, RULE_frame_spec = 58, RULE_frame_clause = 59, 
		RULE_simple_function_invocation = 60, RULE_aggregate_function_invocation = 61, 
		RULE_window_function_invocation = 62, RULE_common_table_stmt = 63, RULE_order_by_stmt = 64, 
		RULE_limit_stmt = 65, RULE_ordering_term = 66, RULE_asc_desc = 67, RULE_frame_left = 68, 
		RULE_frame_right = 69, RULE_frame_single = 70, RULE_window_function = 71, 
		RULE_offset = 72, RULE_default_value = 73, RULE_partition_by = 74, RULE_order_by_expr = 75, 
		RULE_order_by_expr_asc_desc = 76, RULE_expr_asc_desc = 77, RULE_initial_select = 78, 
		RULE_recursive_select = 79, RULE_unary_operator = 80, RULE_error_message = 81, 
		RULE_module_argument = 82, RULE_column_alias = 83, RULE_keyword = 84, 
		RULE_name = 85, RULE_function_name = 86, RULE_schema_name = 87, RULE_table_name = 88, 
		RULE_table_or_index_name = 89, RULE_new_table_name = 90, RULE_column_name = 91, 
		RULE_collation_name = 92, RULE_foreign_table = 93, RULE_index_name = 94, 
		RULE_trigger_name = 95, RULE_view_name = 96, RULE_module_name = 97, RULE_pragma_name = 98, 
		RULE_savepoint_name = 99, RULE_table_alias = 100, RULE_transaction_name = 101, 
		RULE_window_name = 102, RULE_alias = 103, RULE_filename = 104, RULE_base_window_name = 105, 
		RULE_simple_func = 106, RULE_aggregate_func = 107, RULE_table_function_name = 108, 
		RULE_any_name = 109;
	public static final String[] ruleNames = {
		"sql_stmt_list", "sql_stmt", "alter_table_stmt", "analyze_stmt", "attach_stmt", 
		"begin_stmt", "commit_stmt", "rollback_stmt", "savepoint_stmt", "release_stmt", 
		"create_index_stmt", "indexed_column", "create_table_stmt", "column_def", 
		"type_name", "column_constraint", "signed_number", "table_constraint", 
		"foreign_key_clause", "conflict_clause", "create_trigger_stmt", "create_view_stmt", 
		"create_virtual_table_stmt", "with_clause", "cte_table_name", "recursive_cte", 
		"common_table_expression", "delete_stmt", "delete_stmt_limited", "detach_stmt", 
		"drop_stmt", "expr", "raise_function", "literal_value", "insert_stmt", 
		"upsert_clause", "pragma_stmt", "pragma_value", "reindex_stmt", "select_stmt", 
		"join_clause", "select_core", "factored_select_stmt", "simple_select_stmt", 
		"compound_select_stmt", "table_or_subquery", "result_column", "join_operator", 
		"join_constraint", "compound_operator", "update_stmt", "column_name_list", 
		"update_stmt_limited", "qualified_table_name", "vacuum_stmt", "filter_clause", 
		"window_defn", "over_clause", "frame_spec", "frame_clause", "simple_function_invocation", 
		"aggregate_function_invocation", "window_function_invocation", "common_table_stmt", 
		"order_by_stmt", "limit_stmt", "ordering_term", "asc_desc", "frame_left", 
		"frame_right", "frame_single", "window_function", "offset", "default_value", 
		"partition_by", "order_by_expr", "order_by_expr_asc_desc", "expr_asc_desc", 
		"initial_select", "recursive_select", "unary_operator", "error_message", 
		"module_argument", "column_alias", "keyword", "name", "function_name", 
		"schema_name", "table_name", "table_or_index_name", "new_table_name", 
		"column_name", "collation_name", "foreign_table", "index_name", "trigger_name", 
		"view_name", "module_name", "pragma_name", "savepoint_name", "table_alias", 
		"transaction_name", "window_name", "alias", "filename", "base_window_name", 
		"simple_func", "aggregate_func", "table_function_name", "any_name"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "';'", "'.'", "'('", "','", "')'", "'+'", "'-'", "'||'", "'*'", 
		"'/'", "'%'", "'<<'", "'>>'", "'&'", "'|'", "'<'", "'<='", "'>'", "'>='", 
		"'='", "'=='", "'!='", "'<>'", "'~'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, null, null, null, null, null, null, null, null, 
		null, null, null, null, null, null, null, null, null, null, null, null, 
		null, "EXPLAIN", "QUERY", "PLAN", "ALTER", "TABLE", "RENAME", "TO", "COLUMN", 
		"ADD", "ANALYZE", "ATTACH", "DATABASE", "AS", "BEGIN", "DEFERRED", "IMMEDIATE", 
		"EXCLUSIVE", "TRANSACTION", "COMMIT", "END", "ROLLBACK", "SAVEPOINT", 
		"RELEASE", "CREATE", "UNIQUE", "INDEX", "IF", "NOT", "EXISTS", "ON", "WHERE", 
		"COLLATE", "TEMP", "TEMPORARY", "WITHOUT", "IDENTIFIER", "CONSTRAINT", 
		"PRIMARY", "KEY", "AUTOINCREMENT", "NULL_", "CHECK", "DEFAULT", "GENERATED", 
		"ALWAYS", "STORED", "VIRTUAL", "NUMERIC_LITERAL", "FOREIGN", "REFERENCES", 
		"DELETE", "UPDATE", "SET", "CASCADE", "RESTRICT", "NO", "ACTION", "MATCH", 
		"DEFERRABLE", "INITIALLY", "CONFLICT", "ABORT", "FAIL", "IGNORE", "REPLACE", 
		"TRIGGER", "BEFORE", "AFTER", "INSTEAD", "OF", "INSERT", "FOR", "EACH", 
		"ROW", "WHEN", "VIEW", "USING", "WITH", "RECURSIVE", "UNION", "ALL", "FROM", 
		"DETACH", "DROP", "BIND_PARAMETER", "DISTINCT", "CAST", "CASE", "THEN", 
		"ELSE", "IS", "IN", "LIKE", "GLOB", "REGEXP", "AND", "OR", "BETWEEN", 
		"ESCAPE", "ISNULL", "NOTNULL", "RAISE", "STRING_LITERAL", "BLOB_LITERAL", 
		"TRUE_", "FALSE_", "CURRENT_TIME", "CURRENT_DATE", "CURRENT_TIMESTAMP", 
		"INTO", "VALUES", "DO", "NOTHING", "EQ", "PRAGMA", "REINDEX", "SELECT", 
		"GROUP", "BY", "HAVING", "WINDOW", "INTERSECT", "EXCEPT", "INDEXED", "NATURAL", 
		"LEFT", "OUTER", "INNER", "CROSS", "JOIN", "VACUUM", "FILTER", "PARTITION", 
		"ORDER", "OVER", "EXCLUDE", "OTHERS", "CURRENT", "TIES", "RANGE", "ROWS", 
		"GROUPS", "LIMIT", "OFFSET", "NULLS", "FIRST", "LAST", "ASC", "DESC", 
		"PRECEDING", "FOLLOWING", "UNBOUNDED", "FIRST_VALUE", "LAST_VALUE", "CUME_DIST", 
		"PERCENT_RANK", "DENSE_RANK", "RANK", "ROW_NUMBER", "LAG", "LEAD", "NTH_VALUE", 
		"NTILE", "FULL", "RIGHT"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "SqlParsing.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public SqlParsingParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class Sql_stmt_listContext extends ParserRuleContext {
		public List<Sql_stmtContext> sql_stmt() {
			return getRuleContexts(Sql_stmtContext.class);
		}
		public Sql_stmtContext sql_stmt(int i) {
			return getRuleContext(Sql_stmtContext.class,i);
		}
		public Sql_stmt_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sql_stmt_list; }
	}

	public final Sql_stmt_listContext sql_stmt_list() throws RecognitionException {
		Sql_stmt_listContext _localctx = new Sql_stmt_listContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_sql_stmt_list);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(223);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__0) {
				{
				{
				setState(220);
				match(T__0);
				}
				}
				setState(225);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(226);
			sql_stmt();
			setState(235);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(228); 
					_errHandler.sync(this);
					_la = _input.LA(1);
					do {
						{
						{
						setState(227);
						match(T__0);
						}
						}
						setState(230); 
						_errHandler.sync(this);
						_la = _input.LA(1);
					} while ( _la==T__0 );
					setState(232);
					sql_stmt();
					}
					} 
				}
				setState(237);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			}
			setState(241);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__0) {
				{
				{
				setState(238);
				match(T__0);
				}
				}
				setState(243);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Sql_stmtContext extends ParserRuleContext {
		public Alter_table_stmtContext alter_table_stmt() {
			return getRuleContext(Alter_table_stmtContext.class,0);
		}
		public Analyze_stmtContext analyze_stmt() {
			return getRuleContext(Analyze_stmtContext.class,0);
		}
		public Attach_stmtContext attach_stmt() {
			return getRuleContext(Attach_stmtContext.class,0);
		}
		public Begin_stmtContext begin_stmt() {
			return getRuleContext(Begin_stmtContext.class,0);
		}
		public Commit_stmtContext commit_stmt() {
			return getRuleContext(Commit_stmtContext.class,0);
		}
		public Create_index_stmtContext create_index_stmt() {
			return getRuleContext(Create_index_stmtContext.class,0);
		}
		public Create_table_stmtContext create_table_stmt() {
			return getRuleContext(Create_table_stmtContext.class,0);
		}
		public Create_trigger_stmtContext create_trigger_stmt() {
			return getRuleContext(Create_trigger_stmtContext.class,0);
		}
		public Create_view_stmtContext create_view_stmt() {
			return getRuleContext(Create_view_stmtContext.class,0);
		}
		public Create_virtual_table_stmtContext create_virtual_table_stmt() {
			return getRuleContext(Create_virtual_table_stmtContext.class,0);
		}
		public Delete_stmtContext delete_stmt() {
			return getRuleContext(Delete_stmtContext.class,0);
		}
		public Delete_stmt_limitedContext delete_stmt_limited() {
			return getRuleContext(Delete_stmt_limitedContext.class,0);
		}
		public Detach_stmtContext detach_stmt() {
			return getRuleContext(Detach_stmtContext.class,0);
		}
		public Drop_stmtContext drop_stmt() {
			return getRuleContext(Drop_stmtContext.class,0);
		}
		public Insert_stmtContext insert_stmt() {
			return getRuleContext(Insert_stmtContext.class,0);
		}
		public Pragma_stmtContext pragma_stmt() {
			return getRuleContext(Pragma_stmtContext.class,0);
		}
		public Reindex_stmtContext reindex_stmt() {
			return getRuleContext(Reindex_stmtContext.class,0);
		}
		public Release_stmtContext release_stmt() {
			return getRuleContext(Release_stmtContext.class,0);
		}
		public Rollback_stmtContext rollback_stmt() {
			return getRuleContext(Rollback_stmtContext.class,0);
		}
		public Savepoint_stmtContext savepoint_stmt() {
			return getRuleContext(Savepoint_stmtContext.class,0);
		}
		public Select_stmtContext select_stmt() {
			return getRuleContext(Select_stmtContext.class,0);
		}
		public Update_stmtContext update_stmt() {
			return getRuleContext(Update_stmtContext.class,0);
		}
		public Update_stmt_limitedContext update_stmt_limited() {
			return getRuleContext(Update_stmt_limitedContext.class,0);
		}
		public Vacuum_stmtContext vacuum_stmt() {
			return getRuleContext(Vacuum_stmtContext.class,0);
		}
		public TerminalNode EXPLAIN() { return getToken(SqlParsingParser.EXPLAIN, 0); }
		public TerminalNode QUERY() { return getToken(SqlParsingParser.QUERY, 0); }
		public TerminalNode PLAN() { return getToken(SqlParsingParser.PLAN, 0); }
		public Sql_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sql_stmt; }
	}

	public final Sql_stmtContext sql_stmt() throws RecognitionException {
		Sql_stmtContext _localctx = new Sql_stmtContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_sql_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(249);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==EXPLAIN) {
				{
				setState(244);
				match(EXPLAIN);
				setState(247);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==QUERY) {
					{
					setState(245);
					match(QUERY);
					setState(246);
					match(PLAN);
					}
				}

				}
			}

			setState(275);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				{
				setState(251);
				alter_table_stmt();
				}
				break;
			case 2:
				{
				setState(252);
				analyze_stmt();
				}
				break;
			case 3:
				{
				setState(253);
				attach_stmt();
				}
				break;
			case 4:
				{
				setState(254);
				begin_stmt();
				}
				break;
			case 5:
				{
				setState(255);
				commit_stmt();
				}
				break;
			case 6:
				{
				setState(256);
				create_index_stmt();
				}
				break;
			case 7:
				{
				setState(257);
				create_table_stmt();
				}
				break;
			case 8:
				{
				setState(258);
				create_trigger_stmt();
				}
				break;
			case 9:
				{
				setState(259);
				create_view_stmt();
				}
				break;
			case 10:
				{
				setState(260);
				create_virtual_table_stmt();
				}
				break;
			case 11:
				{
				setState(261);
				delete_stmt();
				}
				break;
			case 12:
				{
				setState(262);
				delete_stmt_limited();
				}
				break;
			case 13:
				{
				setState(263);
				detach_stmt();
				}
				break;
			case 14:
				{
				setState(264);
				drop_stmt();
				}
				break;
			case 15:
				{
				setState(265);
				insert_stmt();
				}
				break;
			case 16:
				{
				setState(266);
				pragma_stmt();
				}
				break;
			case 17:
				{
				setState(267);
				reindex_stmt();
				}
				break;
			case 18:
				{
				setState(268);
				release_stmt();
				}
				break;
			case 19:
				{
				setState(269);
				rollback_stmt();
				}
				break;
			case 20:
				{
				setState(270);
				savepoint_stmt();
				}
				break;
			case 21:
				{
				setState(271);
				select_stmt();
				}
				break;
			case 22:
				{
				setState(272);
				update_stmt();
				}
				break;
			case 23:
				{
				setState(273);
				update_stmt_limited();
				}
				break;
			case 24:
				{
				setState(274);
				vacuum_stmt();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Alter_table_stmtContext extends ParserRuleContext {
		public Column_nameContext old_column_name;
		public Column_nameContext new_column_name;
		public TerminalNode ALTER() { return getToken(SqlParsingParser.ALTER, 0); }
		public TerminalNode TABLE() { return getToken(SqlParsingParser.TABLE, 0); }
		public Table_nameContext table_name() {
			return getRuleContext(Table_nameContext.class,0);
		}
		public TerminalNode RENAME() { return getToken(SqlParsingParser.RENAME, 0); }
		public TerminalNode ADD() { return getToken(SqlParsingParser.ADD, 0); }
		public Column_defContext column_def() {
			return getRuleContext(Column_defContext.class,0);
		}
		public Schema_nameContext schema_name() {
			return getRuleContext(Schema_nameContext.class,0);
		}
		public TerminalNode COLUMN() { return getToken(SqlParsingParser.COLUMN, 0); }
		public TerminalNode TO() { return getToken(SqlParsingParser.TO, 0); }
		public New_table_nameContext new_table_name() {
			return getRuleContext(New_table_nameContext.class,0);
		}
		public List<Column_nameContext> column_name() {
			return getRuleContexts(Column_nameContext.class);
		}
		public Column_nameContext column_name(int i) {
			return getRuleContext(Column_nameContext.class,i);
		}
		public Alter_table_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_alter_table_stmt; }
	}

	public final Alter_table_stmtContext alter_table_stmt() throws RecognitionException {
		Alter_table_stmtContext _localctx = new Alter_table_stmtContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_alter_table_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(277);
			match(ALTER);
			setState(278);
			match(TABLE);
			setState(282);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				{
				setState(279);
				schema_name();
				setState(280);
				match(T__1);
				}
				break;
			}
			setState(284);
			table_name();
			setState(302);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case RENAME:
				{
				setState(285);
				match(RENAME);
				setState(295);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
				case 1:
					{
					{
					setState(286);
					match(TO);
					setState(287);
					new_table_name();
					}
					}
					break;
				case 2:
					{
					{
					setState(289);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
					case 1:
						{
						setState(288);
						match(COLUMN);
						}
						break;
					}
					setState(291);
					((Alter_table_stmtContext)_localctx).old_column_name = column_name();
					setState(292);
					match(TO);
					setState(293);
					((Alter_table_stmtContext)_localctx).new_column_name = column_name();
					}
					}
					break;
				}
				}
				break;
			case ADD:
				{
				setState(297);
				match(ADD);
				setState(299);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
				case 1:
					{
					setState(298);
					match(COLUMN);
					}
					break;
				}
				setState(301);
				column_def();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Analyze_stmtContext extends ParserRuleContext {
		public TerminalNode ANALYZE() { return getToken(SqlParsingParser.ANALYZE, 0); }
		public Schema_nameContext schema_name() {
			return getRuleContext(Schema_nameContext.class,0);
		}
		public Table_or_index_nameContext table_or_index_name() {
			return getRuleContext(Table_or_index_nameContext.class,0);
		}
		public Analyze_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_analyze_stmt; }
	}

	public final Analyze_stmtContext analyze_stmt() throws RecognitionException {
		Analyze_stmtContext _localctx = new Analyze_stmtContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_analyze_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(304);
			match(ANALYZE);
			setState(312);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				{
				setState(305);
				schema_name();
				}
				break;
			case 2:
				{
				setState(309);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
				case 1:
					{
					setState(306);
					schema_name();
					setState(307);
					match(T__1);
					}
					break;
				}
				setState(311);
				table_or_index_name();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Attach_stmtContext extends ParserRuleContext {
		public TerminalNode ATTACH() { return getToken(SqlParsingParser.ATTACH, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode AS() { return getToken(SqlParsingParser.AS, 0); }
		public Schema_nameContext schema_name() {
			return getRuleContext(Schema_nameContext.class,0);
		}
		public TerminalNode DATABASE() { return getToken(SqlParsingParser.DATABASE, 0); }
		public Attach_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_attach_stmt; }
	}

	public final Attach_stmtContext attach_stmt() throws RecognitionException {
		Attach_stmtContext _localctx = new Attach_stmtContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_attach_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(314);
			match(ATTACH);
			setState(316);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				{
				setState(315);
				match(DATABASE);
				}
				break;
			}
			setState(318);
			expr(0);
			setState(319);
			match(AS);
			setState(320);
			schema_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Begin_stmtContext extends ParserRuleContext {
		public TerminalNode BEGIN() { return getToken(SqlParsingParser.BEGIN, 0); }
		public TerminalNode TRANSACTION() { return getToken(SqlParsingParser.TRANSACTION, 0); }
		public TerminalNode DEFERRED() { return getToken(SqlParsingParser.DEFERRED, 0); }
		public TerminalNode IMMEDIATE() { return getToken(SqlParsingParser.IMMEDIATE, 0); }
		public TerminalNode EXCLUSIVE() { return getToken(SqlParsingParser.EXCLUSIVE, 0); }
		public Transaction_nameContext transaction_name() {
			return getRuleContext(Transaction_nameContext.class,0);
		}
		public Begin_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_begin_stmt; }
	}

	public final Begin_stmtContext begin_stmt() throws RecognitionException {
		Begin_stmtContext _localctx = new Begin_stmtContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_begin_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(322);
			match(BEGIN);
			setState(324);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << DEFERRED) | (1L << IMMEDIATE) | (1L << EXCLUSIVE))) != 0)) {
				{
				setState(323);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << DEFERRED) | (1L << IMMEDIATE) | (1L << EXCLUSIVE))) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
			}

			setState(330);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==TRANSACTION) {
				{
				setState(326);
				match(TRANSACTION);
				setState(328);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__2) | (1L << EXPLAIN) | (1L << QUERY) | (1L << PLAN) | (1L << ALTER) | (1L << TABLE) | (1L << RENAME) | (1L << TO) | (1L << COLUMN) | (1L << ADD) | (1L << ANALYZE) | (1L << ATTACH) | (1L << DATABASE) | (1L << AS) | (1L << BEGIN) | (1L << DEFERRED) | (1L << IMMEDIATE) | (1L << EXCLUSIVE) | (1L << TRANSACTION) | (1L << COMMIT) | (1L << END) | (1L << ROLLBACK) | (1L << SAVEPOINT) | (1L << RELEASE) | (1L << CREATE) | (1L << UNIQUE) | (1L << INDEX) | (1L << IF) | (1L << NOT) | (1L << EXISTS) | (1L << ON) | (1L << WHERE) | (1L << COLLATE) | (1L << TEMP) | (1L << TEMPORARY) | (1L << WITHOUT) | (1L << IDENTIFIER) | (1L << CONSTRAINT) | (1L << PRIMARY) | (1L << KEY))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (AUTOINCREMENT - 64)) | (1L << (NULL_ - 64)) | (1L << (CHECK - 64)) | (1L << (DEFAULT - 64)) | (1L << (GENERATED - 64)) | (1L << (ALWAYS - 64)) | (1L << (STORED - 64)) | (1L << (VIRTUAL - 64)) | (1L << (FOREIGN - 64)) | (1L << (REFERENCES - 64)) | (1L << (DELETE - 64)) | (1L << (UPDATE - 64)) | (1L << (SET - 64)) | (1L << (CASCADE - 64)) | (1L << (RESTRICT - 64)) | (1L << (NO - 64)) | (1L << (ACTION - 64)) | (1L << (MATCH - 64)) | (1L << (DEFERRABLE - 64)) | (1L << (INITIALLY - 64)) | (1L << (CONFLICT - 64)) | (1L << (ABORT - 64)) | (1L << (FAIL - 64)) | (1L << (IGNORE - 64)) | (1L << (REPLACE - 64)) | (1L << (TRIGGER - 64)) | (1L << (BEFORE - 64)) | (1L << (AFTER - 64)) | (1L << (INSTEAD - 64)) | (1L << (OF - 64)) | (1L << (INSERT - 64)) | (1L << (FOR - 64)) | (1L << (EACH - 64)) | (1L << (ROW - 64)) | (1L << (WHEN - 64)) | (1L << (VIEW - 64)) | (1L << (USING - 64)) | (1L << (WITH - 64)) | (1L << (RECURSIVE - 64)) | (1L << (UNION - 64)) | (1L << (ALL - 64)) | (1L << (FROM - 64)) | (1L << (DETACH - 64)) | (1L << (DROP - 64)) | (1L << (DISTINCT - 64)) | (1L << (CAST - 64)) | (1L << (CASE - 64)) | (1L << (THEN - 64)) | (1L << (ELSE - 64)) | (1L << (IS - 64)) | (1L << (IN - 64)) | (1L << (LIKE - 64)) | (1L << (GLOB - 64)) | (1L << (REGEXP - 64)) | (1L << (AND - 64)) | (1L << (OR - 64)) | (1L << (BETWEEN - 64)) | (1L << (ESCAPE - 64)) | (1L << (ISNULL - 64)) | (1L << (NOTNULL - 64)) | (1L << (RAISE - 64)) | (1L << (STRING_LITERAL - 64)))) != 0) || ((((_la - 129)) & ~0x3f) == 0 && ((1L << (_la - 129)) & ((1L << (TRUE_ - 129)) | (1L << (FALSE_ - 129)) | (1L << (CURRENT_TIME - 129)) | (1L << (CURRENT_DATE - 129)) | (1L << (CURRENT_TIMESTAMP - 129)) | (1L << (INTO - 129)) | (1L << (VALUES - 129)) | (1L << (PRAGMA - 129)) | (1L << (REINDEX - 129)) | (1L << (SELECT - 129)) | (1L << (GROUP - 129)) | (1L << (BY - 129)) | (1L << (HAVING - 129)) | (1L << (WINDOW - 129)) | (1L << (INTERSECT - 129)) | (1L << (EXCEPT - 129)) | (1L << (INDEXED - 129)) | (1L << (NATURAL - 129)) | (1L << (LEFT - 129)) | (1L << (OUTER - 129)) | (1L << (INNER - 129)) | (1L << (CROSS - 129)) | (1L << (JOIN - 129)) | (1L << (VACUUM - 129)) | (1L << (FILTER - 129)) | (1L << (PARTITION - 129)) | (1L << (ORDER - 129)) | (1L << (OVER - 129)) | (1L << (EXCLUDE - 129)) | (1L << (CURRENT - 129)) | (1L << (RANGE - 129)) | (1L << (ROWS - 129)) | (1L << (GROUPS - 129)) | (1L << (LIMIT - 129)) | (1L << (OFFSET - 129)) | (1L << (NULLS - 129)) | (1L << (FIRST - 129)) | (1L << (LAST - 129)) | (1L << (ASC - 129)) | (1L << (DESC - 129)) | (1L << (PRECEDING - 129)) | (1L << (FOLLOWING - 129)) | (1L << (UNBOUNDED - 129)) | (1L << (FIRST_VALUE - 129)) | (1L << (LAST_VALUE - 129)) | (1L << (CUME_DIST - 129)) | (1L << (PERCENT_RANK - 129)) | (1L << (DENSE_RANK - 129)) | (1L << (RANK - 129)) | (1L << (ROW_NUMBER - 129)) | (1L << (LAG - 129)) | (1L << (LEAD - 129)) | (1L << (NTH_VALUE - 129)) | (1L << (NTILE - 129)) | (1L << (FULL - 129)) | (1L << (RIGHT - 129)))) != 0)) {
					{
					setState(327);
					transaction_name();
					}
				}

				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Commit_stmtContext extends ParserRuleContext {
		public TerminalNode COMMIT() { return getToken(SqlParsingParser.COMMIT, 0); }
		public TerminalNode END() { return getToken(SqlParsingParser.END, 0); }
		public TerminalNode TRANSACTION() { return getToken(SqlParsingParser.TRANSACTION, 0); }
		public Commit_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_commit_stmt; }
	}

	public final Commit_stmtContext commit_stmt() throws RecognitionException {
		Commit_stmtContext _localctx = new Commit_stmtContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_commit_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(332);
			_la = _input.LA(1);
			if ( !(_la==COMMIT || _la==END) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			setState(334);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==TRANSACTION) {
				{
				setState(333);
				match(TRANSACTION);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Rollback_stmtContext extends ParserRuleContext {
		public TerminalNode ROLLBACK() { return getToken(SqlParsingParser.ROLLBACK, 0); }
		public TerminalNode TRANSACTION() { return getToken(SqlParsingParser.TRANSACTION, 0); }
		public TerminalNode TO() { return getToken(SqlParsingParser.TO, 0); }
		public Savepoint_nameContext savepoint_name() {
			return getRuleContext(Savepoint_nameContext.class,0);
		}
		public TerminalNode SAVEPOINT() { return getToken(SqlParsingParser.SAVEPOINT, 0); }
		public Rollback_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rollback_stmt; }
	}

	public final Rollback_stmtContext rollback_stmt() throws RecognitionException {
		Rollback_stmtContext _localctx = new Rollback_stmtContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_rollback_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(336);
			match(ROLLBACK);
			setState(338);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==TRANSACTION) {
				{
				setState(337);
				match(TRANSACTION);
				}
			}

			setState(345);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==TO) {
				{
				setState(340);
				match(TO);
				setState(342);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
				case 1:
					{
					setState(341);
					match(SAVEPOINT);
					}
					break;
				}
				setState(344);
				savepoint_name();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Savepoint_stmtContext extends ParserRuleContext {
		public TerminalNode SAVEPOINT() { return getToken(SqlParsingParser.SAVEPOINT, 0); }
		public Savepoint_nameContext savepoint_name() {
			return getRuleContext(Savepoint_nameContext.class,0);
		}
		public Savepoint_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_savepoint_stmt; }
	}

	public final Savepoint_stmtContext savepoint_stmt() throws RecognitionException {
		Savepoint_stmtContext _localctx = new Savepoint_stmtContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_savepoint_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(347);
			match(SAVEPOINT);
			setState(348);
			savepoint_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Release_stmtContext extends ParserRuleContext {
		public TerminalNode RELEASE() { return getToken(SqlParsingParser.RELEASE, 0); }
		public Savepoint_nameContext savepoint_name() {
			return getRuleContext(Savepoint_nameContext.class,0);
		}
		public TerminalNode SAVEPOINT() { return getToken(SqlParsingParser.SAVEPOINT, 0); }
		public Release_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_release_stmt; }
	}

	public final Release_stmtContext release_stmt() throws RecognitionException {
		Release_stmtContext _localctx = new Release_stmtContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_release_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(350);
			match(RELEASE);
			setState(352);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
			case 1:
				{
				setState(351);
				match(SAVEPOINT);
				}
				break;
			}
			setState(354);
			savepoint_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Create_index_stmtContext extends ParserRuleContext {
		public TerminalNode CREATE() { return getToken(SqlParsingParser.CREATE, 0); }
		public TerminalNode INDEX() { return getToken(SqlParsingParser.INDEX, 0); }
		public Index_nameContext index_name() {
			return getRuleContext(Index_nameContext.class,0);
		}
		public TerminalNode ON() { return getToken(SqlParsingParser.ON, 0); }
		public Table_nameContext table_name() {
			return getRuleContext(Table_nameContext.class,0);
		}
		public List<Indexed_columnContext> indexed_column() {
			return getRuleContexts(Indexed_columnContext.class);
		}
		public Indexed_columnContext indexed_column(int i) {
			return getRuleContext(Indexed_columnContext.class,i);
		}
		public TerminalNode UNIQUE() { return getToken(SqlParsingParser.UNIQUE, 0); }
		public TerminalNode IF() { return getToken(SqlParsingParser.IF, 0); }
		public TerminalNode NOT() { return getToken(SqlParsingParser.NOT, 0); }
		public TerminalNode EXISTS() { return getToken(SqlParsingParser.EXISTS, 0); }
		public Schema_nameContext schema_name() {
			return getRuleContext(Schema_nameContext.class,0);
		}
		public TerminalNode WHERE() { return getToken(SqlParsingParser.WHERE, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public Create_index_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_create_index_stmt; }
	}

	public final Create_index_stmtContext create_index_stmt() throws RecognitionException {
		Create_index_stmtContext _localctx = new Create_index_stmtContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_create_index_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(356);
			match(CREATE);
			setState(358);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==UNIQUE) {
				{
				setState(357);
				match(UNIQUE);
				}
			}

			setState(360);
			match(INDEX);
			setState(364);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,24,_ctx) ) {
			case 1:
				{
				setState(361);
				match(IF);
				setState(362);
				match(NOT);
				setState(363);
				match(EXISTS);
				}
				break;
			}
			setState(369);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,25,_ctx) ) {
			case 1:
				{
				setState(366);
				schema_name();
				setState(367);
				match(T__1);
				}
				break;
			}
			setState(371);
			index_name();
			setState(372);
			match(ON);
			setState(373);
			table_name();
			setState(374);
			match(T__2);
			setState(375);
			indexed_column();
			setState(380);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__3) {
				{
				{
				setState(376);
				match(T__3);
				setState(377);
				indexed_column();
				}
				}
				setState(382);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(383);
			match(T__4);
			setState(386);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WHERE) {
				{
				setState(384);
				match(WHERE);
				setState(385);
				expr(0);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Indexed_columnContext extends ParserRuleContext {
		public Column_nameContext column_name() {
			return getRuleContext(Column_nameContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode COLLATE() { return getToken(SqlParsingParser.COLLATE, 0); }
		public Collation_nameContext collation_name() {
			return getRuleContext(Collation_nameContext.class,0);
		}
		public Asc_descContext asc_desc() {
			return getRuleContext(Asc_descContext.class,0);
		}
		public Indexed_columnContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_indexed_column; }
	}

	public final Indexed_columnContext indexed_column() throws RecognitionException {
		Indexed_columnContext _localctx = new Indexed_columnContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_indexed_column);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(390);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,28,_ctx) ) {
			case 1:
				{
				setState(388);
				column_name();
				}
				break;
			case 2:
				{
				setState(389);
				expr(0);
				}
				break;
			}
			setState(394);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COLLATE) {
				{
				setState(392);
				match(COLLATE);
				setState(393);
				collation_name();
				}
			}

			setState(397);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ASC || _la==DESC) {
				{
				setState(396);
				asc_desc();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Create_table_stmtContext extends ParserRuleContext {
		public Token rowID;
		public TerminalNode CREATE() { return getToken(SqlParsingParser.CREATE, 0); }
		public TerminalNode TABLE() { return getToken(SqlParsingParser.TABLE, 0); }
		public Table_nameContext table_name() {
			return getRuleContext(Table_nameContext.class,0);
		}
		public TerminalNode IF() { return getToken(SqlParsingParser.IF, 0); }
		public TerminalNode NOT() { return getToken(SqlParsingParser.NOT, 0); }
		public TerminalNode EXISTS() { return getToken(SqlParsingParser.EXISTS, 0); }
		public Schema_nameContext schema_name() {
			return getRuleContext(Schema_nameContext.class,0);
		}
		public TerminalNode TEMP() { return getToken(SqlParsingParser.TEMP, 0); }
		public TerminalNode TEMPORARY() { return getToken(SqlParsingParser.TEMPORARY, 0); }
		public List<Column_defContext> column_def() {
			return getRuleContexts(Column_defContext.class);
		}
		public Column_defContext column_def(int i) {
			return getRuleContext(Column_defContext.class,i);
		}
		public TerminalNode AS() { return getToken(SqlParsingParser.AS, 0); }
		public Select_stmtContext select_stmt() {
			return getRuleContext(Select_stmtContext.class,0);
		}
		public List<Table_constraintContext> table_constraint() {
			return getRuleContexts(Table_constraintContext.class);
		}
		public Table_constraintContext table_constraint(int i) {
			return getRuleContext(Table_constraintContext.class,i);
		}
		public TerminalNode WITHOUT() { return getToken(SqlParsingParser.WITHOUT, 0); }
		public TerminalNode IDENTIFIER() { return getToken(SqlParsingParser.IDENTIFIER, 0); }
		public Create_table_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_create_table_stmt; }
	}

	public final Create_table_stmtContext create_table_stmt() throws RecognitionException {
		Create_table_stmtContext _localctx = new Create_table_stmtContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_create_table_stmt);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(399);
			match(CREATE);
			setState(401);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==TEMP || _la==TEMPORARY) {
				{
				setState(400);
				_la = _input.LA(1);
				if ( !(_la==TEMP || _la==TEMPORARY) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
			}

			setState(403);
			match(TABLE);
			setState(407);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,32,_ctx) ) {
			case 1:
				{
				setState(404);
				match(IF);
				setState(405);
				match(NOT);
				setState(406);
				match(EXISTS);
				}
				break;
			}
			setState(412);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,33,_ctx) ) {
			case 1:
				{
				setState(409);
				schema_name();
				setState(410);
				match(T__1);
				}
				break;
			}
			setState(414);
			table_name();
			setState(438);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__2:
				{
				{
				setState(415);
				match(T__2);
				setState(416);
				column_def();
				setState(421);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,34,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(417);
						match(T__3);
						setState(418);
						column_def();
						}
						} 
					}
					setState(423);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,34,_ctx);
				}
				setState(428);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(424);
					match(T__3);
					setState(425);
					table_constraint();
					}
					}
					setState(430);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(431);
				match(T__4);
				setState(434);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WITHOUT) {
					{
					setState(432);
					match(WITHOUT);
					setState(433);
					((Create_table_stmtContext)_localctx).rowID = match(IDENTIFIER);
					}
				}

				}
				}
				break;
			case AS:
				{
				{
				setState(436);
				match(AS);
				setState(437);
				select_stmt();
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Column_defContext extends ParserRuleContext {
		public Column_nameContext column_name() {
			return getRuleContext(Column_nameContext.class,0);
		}
		public Type_nameContext type_name() {
			return getRuleContext(Type_nameContext.class,0);
		}
		public List<Column_constraintContext> column_constraint() {
			return getRuleContexts(Column_constraintContext.class);
		}
		public Column_constraintContext column_constraint(int i) {
			return getRuleContext(Column_constraintContext.class,i);
		}
		public Column_defContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_column_def; }
	}

	public final Column_defContext column_def() throws RecognitionException {
		Column_defContext _localctx = new Column_defContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_column_def);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(440);
			column_name();
			setState(442);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,38,_ctx) ) {
			case 1:
				{
				setState(441);
				type_name();
				}
				break;
			}
			setState(447);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 37)) & ~0x3f) == 0 && ((1L << (_la - 37)) & ((1L << (AS - 37)) | (1L << (UNIQUE - 37)) | (1L << (NOT - 37)) | (1L << (COLLATE - 37)) | (1L << (CONSTRAINT - 37)) | (1L << (PRIMARY - 37)) | (1L << (CHECK - 37)) | (1L << (DEFAULT - 37)) | (1L << (GENERATED - 37)) | (1L << (REFERENCES - 37)))) != 0)) {
				{
				{
				setState(444);
				column_constraint();
				}
				}
				setState(449);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Type_nameContext extends ParserRuleContext {
		public List<NameContext> name() {
			return getRuleContexts(NameContext.class);
		}
		public NameContext name(int i) {
			return getRuleContext(NameContext.class,i);
		}
		public List<Signed_numberContext> signed_number() {
			return getRuleContexts(Signed_numberContext.class);
		}
		public Signed_numberContext signed_number(int i) {
			return getRuleContext(Signed_numberContext.class,i);
		}
		public Type_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_name; }
	}

	public final Type_nameContext type_name() throws RecognitionException {
		Type_nameContext _localctx = new Type_nameContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_type_name);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(451); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(450);
					name();
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(453); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,40,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			setState(465);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,41,_ctx) ) {
			case 1:
				{
				setState(455);
				match(T__2);
				setState(456);
				signed_number();
				setState(457);
				match(T__4);
				}
				break;
			case 2:
				{
				setState(459);
				match(T__2);
				setState(460);
				signed_number();
				setState(461);
				match(T__3);
				setState(462);
				signed_number();
				setState(463);
				match(T__4);
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Column_constraintContext extends ParserRuleContext {
		public TerminalNode CHECK() { return getToken(SqlParsingParser.CHECK, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode DEFAULT() { return getToken(SqlParsingParser.DEFAULT, 0); }
		public TerminalNode COLLATE() { return getToken(SqlParsingParser.COLLATE, 0); }
		public Collation_nameContext collation_name() {
			return getRuleContext(Collation_nameContext.class,0);
		}
		public Foreign_key_clauseContext foreign_key_clause() {
			return getRuleContext(Foreign_key_clauseContext.class,0);
		}
		public TerminalNode AS() { return getToken(SqlParsingParser.AS, 0); }
		public TerminalNode CONSTRAINT() { return getToken(SqlParsingParser.CONSTRAINT, 0); }
		public NameContext name() {
			return getRuleContext(NameContext.class,0);
		}
		public TerminalNode PRIMARY() { return getToken(SqlParsingParser.PRIMARY, 0); }
		public TerminalNode KEY() { return getToken(SqlParsingParser.KEY, 0); }
		public TerminalNode UNIQUE() { return getToken(SqlParsingParser.UNIQUE, 0); }
		public Signed_numberContext signed_number() {
			return getRuleContext(Signed_numberContext.class,0);
		}
		public Literal_valueContext literal_value() {
			return getRuleContext(Literal_valueContext.class,0);
		}
		public Conflict_clauseContext conflict_clause() {
			return getRuleContext(Conflict_clauseContext.class,0);
		}
		public TerminalNode GENERATED() { return getToken(SqlParsingParser.GENERATED, 0); }
		public TerminalNode ALWAYS() { return getToken(SqlParsingParser.ALWAYS, 0); }
		public TerminalNode NOT() { return getToken(SqlParsingParser.NOT, 0); }
		public TerminalNode NULL_() { return getToken(SqlParsingParser.NULL_, 0); }
		public TerminalNode STORED() { return getToken(SqlParsingParser.STORED, 0); }
		public TerminalNode VIRTUAL() { return getToken(SqlParsingParser.VIRTUAL, 0); }
		public Asc_descContext asc_desc() {
			return getRuleContext(Asc_descContext.class,0);
		}
		public TerminalNode AUTOINCREMENT() { return getToken(SqlParsingParser.AUTOINCREMENT, 0); }
		public Column_constraintContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_column_constraint; }
	}

	public final Column_constraintContext column_constraint() throws RecognitionException {
		Column_constraintContext _localctx = new Column_constraintContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_column_constraint);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(469);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==CONSTRAINT) {
				{
				setState(467);
				match(CONSTRAINT);
				setState(468);
				name();
				}
			}

			setState(518);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case PRIMARY:
				{
				{
				setState(471);
				match(PRIMARY);
				setState(472);
				match(KEY);
				setState(474);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ASC || _la==DESC) {
					{
					setState(473);
					asc_desc();
					}
				}

				setState(477);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ON) {
					{
					setState(476);
					conflict_clause();
					}
				}

				setState(480);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==AUTOINCREMENT) {
					{
					setState(479);
					match(AUTOINCREMENT);
					}
				}

				}
				}
				break;
			case UNIQUE:
			case NOT:
				{
				setState(485);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case NOT:
					{
					{
					setState(482);
					match(NOT);
					setState(483);
					match(NULL_);
					}
					}
					break;
				case UNIQUE:
					{
					setState(484);
					match(UNIQUE);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(488);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ON) {
					{
					setState(487);
					conflict_clause();
					}
				}

				}
				break;
			case CHECK:
				{
				setState(490);
				match(CHECK);
				setState(491);
				match(T__2);
				setState(492);
				expr(0);
				setState(493);
				match(T__4);
				}
				break;
			case DEFAULT:
				{
				setState(495);
				match(DEFAULT);
				setState(502);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,48,_ctx) ) {
				case 1:
					{
					setState(496);
					signed_number();
					}
					break;
				case 2:
					{
					setState(497);
					literal_value();
					}
					break;
				case 3:
					{
					{
					setState(498);
					match(T__2);
					setState(499);
					expr(0);
					setState(500);
					match(T__4);
					}
					}
					break;
				}
				}
				break;
			case COLLATE:
				{
				setState(504);
				match(COLLATE);
				setState(505);
				collation_name();
				}
				break;
			case REFERENCES:
				{
				setState(506);
				foreign_key_clause();
				}
				break;
			case AS:
			case GENERATED:
				{
				setState(509);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==GENERATED) {
					{
					setState(507);
					match(GENERATED);
					setState(508);
					match(ALWAYS);
					}
				}

				setState(511);
				match(AS);
				setState(512);
				match(T__2);
				setState(513);
				expr(0);
				setState(514);
				match(T__4);
				setState(516);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==STORED || _la==VIRTUAL) {
					{
					setState(515);
					_la = _input.LA(1);
					if ( !(_la==STORED || _la==VIRTUAL) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
				}

				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Signed_numberContext extends ParserRuleContext {
		public TerminalNode NUMERIC_LITERAL() { return getToken(SqlParsingParser.NUMERIC_LITERAL, 0); }
		public Signed_numberContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_signed_number; }
	}

	public final Signed_numberContext signed_number() throws RecognitionException {
		Signed_numberContext _localctx = new Signed_numberContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_signed_number);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(521);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__5 || _la==T__6) {
				{
				setState(520);
				_la = _input.LA(1);
				if ( !(_la==T__5 || _la==T__6) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
			}

			setState(523);
			match(NUMERIC_LITERAL);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Table_constraintContext extends ParserRuleContext {
		public TerminalNode CONSTRAINT() { return getToken(SqlParsingParser.CONSTRAINT, 0); }
		public NameContext name() {
			return getRuleContext(NameContext.class,0);
		}
		public List<Indexed_columnContext> indexed_column() {
			return getRuleContexts(Indexed_columnContext.class);
		}
		public Indexed_columnContext indexed_column(int i) {
			return getRuleContext(Indexed_columnContext.class,i);
		}
		public TerminalNode CHECK() { return getToken(SqlParsingParser.CHECK, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode FOREIGN() { return getToken(SqlParsingParser.FOREIGN, 0); }
		public TerminalNode KEY() { return getToken(SqlParsingParser.KEY, 0); }
		public List<Column_nameContext> column_name() {
			return getRuleContexts(Column_nameContext.class);
		}
		public Column_nameContext column_name(int i) {
			return getRuleContext(Column_nameContext.class,i);
		}
		public Foreign_key_clauseContext foreign_key_clause() {
			return getRuleContext(Foreign_key_clauseContext.class,0);
		}
		public TerminalNode PRIMARY() { return getToken(SqlParsingParser.PRIMARY, 0); }
		public TerminalNode UNIQUE() { return getToken(SqlParsingParser.UNIQUE, 0); }
		public Conflict_clauseContext conflict_clause() {
			return getRuleContext(Conflict_clauseContext.class,0);
		}
		public Table_constraintContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_table_constraint; }
	}

	public final Table_constraintContext table_constraint() throws RecognitionException {
		Table_constraintContext _localctx = new Table_constraintContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_table_constraint);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(527);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==CONSTRAINT) {
				{
				setState(525);
				match(CONSTRAINT);
				setState(526);
				name();
				}
			}

			setState(566);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case UNIQUE:
			case PRIMARY:
				{
				{
				setState(532);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case PRIMARY:
					{
					setState(529);
					match(PRIMARY);
					setState(530);
					match(KEY);
					}
					break;
				case UNIQUE:
					{
					setState(531);
					match(UNIQUE);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(534);
				match(T__2);
				setState(535);
				indexed_column();
				setState(540);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(536);
					match(T__3);
					setState(537);
					indexed_column();
					}
					}
					setState(542);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(543);
				match(T__4);
				setState(545);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ON) {
					{
					setState(544);
					conflict_clause();
					}
				}

				}
				}
				break;
			case CHECK:
				{
				{
				setState(547);
				match(CHECK);
				setState(548);
				match(T__2);
				setState(549);
				expr(0);
				setState(550);
				match(T__4);
				}
				}
				break;
			case FOREIGN:
				{
				{
				setState(552);
				match(FOREIGN);
				setState(553);
				match(KEY);
				setState(554);
				match(T__2);
				setState(555);
				column_name();
				setState(560);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(556);
					match(T__3);
					setState(557);
					column_name();
					}
					}
					setState(562);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(563);
				match(T__4);
				setState(564);
				foreign_key_clause();
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Foreign_key_clauseContext extends ParserRuleContext {
		public TerminalNode REFERENCES() { return getToken(SqlParsingParser.REFERENCES, 0); }
		public Foreign_tableContext foreign_table() {
			return getRuleContext(Foreign_tableContext.class,0);
		}
		public List<Column_nameContext> column_name() {
			return getRuleContexts(Column_nameContext.class);
		}
		public Column_nameContext column_name(int i) {
			return getRuleContext(Column_nameContext.class,i);
		}
		public TerminalNode DEFERRABLE() { return getToken(SqlParsingParser.DEFERRABLE, 0); }
		public List<TerminalNode> ON() { return getTokens(SqlParsingParser.ON); }
		public TerminalNode ON(int i) {
			return getToken(SqlParsingParser.ON, i);
		}
		public List<TerminalNode> MATCH() { return getTokens(SqlParsingParser.MATCH); }
		public TerminalNode MATCH(int i) {
			return getToken(SqlParsingParser.MATCH, i);
		}
		public List<NameContext> name() {
			return getRuleContexts(NameContext.class);
		}
		public NameContext name(int i) {
			return getRuleContext(NameContext.class,i);
		}
		public List<TerminalNode> DELETE() { return getTokens(SqlParsingParser.DELETE); }
		public TerminalNode DELETE(int i) {
			return getToken(SqlParsingParser.DELETE, i);
		}
		public List<TerminalNode> UPDATE() { return getTokens(SqlParsingParser.UPDATE); }
		public TerminalNode UPDATE(int i) {
			return getToken(SqlParsingParser.UPDATE, i);
		}
		public TerminalNode NOT() { return getToken(SqlParsingParser.NOT, 0); }
		public TerminalNode INITIALLY() { return getToken(SqlParsingParser.INITIALLY, 0); }
		public List<TerminalNode> CASCADE() { return getTokens(SqlParsingParser.CASCADE); }
		public TerminalNode CASCADE(int i) {
			return getToken(SqlParsingParser.CASCADE, i);
		}
		public List<TerminalNode> RESTRICT() { return getTokens(SqlParsingParser.RESTRICT); }
		public TerminalNode RESTRICT(int i) {
			return getToken(SqlParsingParser.RESTRICT, i);
		}
		public TerminalNode DEFERRED() { return getToken(SqlParsingParser.DEFERRED, 0); }
		public TerminalNode IMMEDIATE() { return getToken(SqlParsingParser.IMMEDIATE, 0); }
		public List<TerminalNode> SET() { return getTokens(SqlParsingParser.SET); }
		public TerminalNode SET(int i) {
			return getToken(SqlParsingParser.SET, i);
		}
		public List<TerminalNode> NO() { return getTokens(SqlParsingParser.NO); }
		public TerminalNode NO(int i) {
			return getToken(SqlParsingParser.NO, i);
		}
		public List<TerminalNode> ACTION() { return getTokens(SqlParsingParser.ACTION); }
		public TerminalNode ACTION(int i) {
			return getToken(SqlParsingParser.ACTION, i);
		}
		public List<TerminalNode> NULL_() { return getTokens(SqlParsingParser.NULL_); }
		public TerminalNode NULL_(int i) {
			return getToken(SqlParsingParser.NULL_, i);
		}
		public List<TerminalNode> DEFAULT() { return getTokens(SqlParsingParser.DEFAULT); }
		public TerminalNode DEFAULT(int i) {
			return getToken(SqlParsingParser.DEFAULT, i);
		}
		public Foreign_key_clauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_foreign_key_clause; }
	}

	public final Foreign_key_clauseContext foreign_key_clause() throws RecognitionException {
		Foreign_key_clauseContext _localctx = new Foreign_key_clauseContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_foreign_key_clause);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(568);
			match(REFERENCES);
			setState(569);
			foreign_table();
			setState(581);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__2) {
				{
				setState(570);
				match(T__2);
				setState(571);
				column_name();
				setState(576);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(572);
					match(T__3);
					setState(573);
					column_name();
					}
					}
					setState(578);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(579);
				match(T__4);
				}
			}

			setState(597);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==ON || _la==MATCH) {
				{
				setState(595);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case ON:
					{
					{
					setState(583);
					match(ON);
					setState(584);
					_la = _input.LA(1);
					if ( !(_la==DELETE || _la==UPDATE) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					setState(591);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case SET:
						{
						{
						setState(585);
						match(SET);
						setState(586);
						_la = _input.LA(1);
						if ( !(_la==NULL_ || _la==DEFAULT) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						}
						}
						break;
					case CASCADE:
						{
						setState(587);
						match(CASCADE);
						}
						break;
					case RESTRICT:
						{
						setState(588);
						match(RESTRICT);
						}
						break;
					case NO:
						{
						{
						setState(589);
						match(NO);
						setState(590);
						match(ACTION);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					}
					}
					break;
				case MATCH:
					{
					{
					setState(593);
					match(MATCH);
					setState(594);
					name();
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(599);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(608);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,66,_ctx) ) {
			case 1:
				{
				setState(601);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==NOT) {
					{
					setState(600);
					match(NOT);
					}
				}

				setState(603);
				match(DEFERRABLE);
				setState(606);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==INITIALLY) {
					{
					setState(604);
					match(INITIALLY);
					setState(605);
					_la = _input.LA(1);
					if ( !(_la==DEFERRED || _la==IMMEDIATE) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
				}

				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Conflict_clauseContext extends ParserRuleContext {
		public TerminalNode ON() { return getToken(SqlParsingParser.ON, 0); }
		public TerminalNode CONFLICT() { return getToken(SqlParsingParser.CONFLICT, 0); }
		public TerminalNode ROLLBACK() { return getToken(SqlParsingParser.ROLLBACK, 0); }
		public TerminalNode ABORT() { return getToken(SqlParsingParser.ABORT, 0); }
		public TerminalNode FAIL() { return getToken(SqlParsingParser.FAIL, 0); }
		public TerminalNode IGNORE() { return getToken(SqlParsingParser.IGNORE, 0); }
		public TerminalNode REPLACE() { return getToken(SqlParsingParser.REPLACE, 0); }
		public Conflict_clauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_conflict_clause; }
	}

	public final Conflict_clauseContext conflict_clause() throws RecognitionException {
		Conflict_clauseContext _localctx = new Conflict_clauseContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_conflict_clause);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(610);
			match(ON);
			setState(611);
			match(CONFLICT);
			setState(612);
			_la = _input.LA(1);
			if ( !(((((_la - 45)) & ~0x3f) == 0 && ((1L << (_la - 45)) & ((1L << (ROLLBACK - 45)) | (1L << (ABORT - 45)) | (1L << (FAIL - 45)) | (1L << (IGNORE - 45)) | (1L << (REPLACE - 45)))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Create_trigger_stmtContext extends ParserRuleContext {
		public TerminalNode CREATE() { return getToken(SqlParsingParser.CREATE, 0); }
		public TerminalNode TRIGGER() { return getToken(SqlParsingParser.TRIGGER, 0); }
		public Trigger_nameContext trigger_name() {
			return getRuleContext(Trigger_nameContext.class,0);
		}
		public TerminalNode ON() { return getToken(SqlParsingParser.ON, 0); }
		public Table_nameContext table_name() {
			return getRuleContext(Table_nameContext.class,0);
		}
		public TerminalNode BEGIN() { return getToken(SqlParsingParser.BEGIN, 0); }
		public TerminalNode END() { return getToken(SqlParsingParser.END, 0); }
		public TerminalNode DELETE() { return getToken(SqlParsingParser.DELETE, 0); }
		public TerminalNode INSERT() { return getToken(SqlParsingParser.INSERT, 0); }
		public TerminalNode IF() { return getToken(SqlParsingParser.IF, 0); }
		public TerminalNode NOT() { return getToken(SqlParsingParser.NOT, 0); }
		public TerminalNode EXISTS() { return getToken(SqlParsingParser.EXISTS, 0); }
		public Schema_nameContext schema_name() {
			return getRuleContext(Schema_nameContext.class,0);
		}
		public TerminalNode BEFORE() { return getToken(SqlParsingParser.BEFORE, 0); }
		public TerminalNode AFTER() { return getToken(SqlParsingParser.AFTER, 0); }
		public TerminalNode FOR() { return getToken(SqlParsingParser.FOR, 0); }
		public TerminalNode EACH() { return getToken(SqlParsingParser.EACH, 0); }
		public TerminalNode ROW() { return getToken(SqlParsingParser.ROW, 0); }
		public TerminalNode WHEN() { return getToken(SqlParsingParser.WHEN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode TEMP() { return getToken(SqlParsingParser.TEMP, 0); }
		public TerminalNode TEMPORARY() { return getToken(SqlParsingParser.TEMPORARY, 0); }
		public TerminalNode UPDATE() { return getToken(SqlParsingParser.UPDATE, 0); }
		public TerminalNode INSTEAD() { return getToken(SqlParsingParser.INSTEAD, 0); }
		public List<TerminalNode> OF() { return getTokens(SqlParsingParser.OF); }
		public TerminalNode OF(int i) {
			return getToken(SqlParsingParser.OF, i);
		}
		public List<Update_stmtContext> update_stmt() {
			return getRuleContexts(Update_stmtContext.class);
		}
		public Update_stmtContext update_stmt(int i) {
			return getRuleContext(Update_stmtContext.class,i);
		}
		public List<Insert_stmtContext> insert_stmt() {
			return getRuleContexts(Insert_stmtContext.class);
		}
		public Insert_stmtContext insert_stmt(int i) {
			return getRuleContext(Insert_stmtContext.class,i);
		}
		public List<Delete_stmtContext> delete_stmt() {
			return getRuleContexts(Delete_stmtContext.class);
		}
		public Delete_stmtContext delete_stmt(int i) {
			return getRuleContext(Delete_stmtContext.class,i);
		}
		public List<Select_stmtContext> select_stmt() {
			return getRuleContexts(Select_stmtContext.class);
		}
		public Select_stmtContext select_stmt(int i) {
			return getRuleContext(Select_stmtContext.class,i);
		}
		public List<Column_nameContext> column_name() {
			return getRuleContexts(Column_nameContext.class);
		}
		public Column_nameContext column_name(int i) {
			return getRuleContext(Column_nameContext.class,i);
		}
		public Create_trigger_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_create_trigger_stmt; }
	}

	public final Create_trigger_stmtContext create_trigger_stmt() throws RecognitionException {
		Create_trigger_stmtContext _localctx = new Create_trigger_stmtContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_create_trigger_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(614);
			match(CREATE);
			setState(616);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==TEMP || _la==TEMPORARY) {
				{
				setState(615);
				_la = _input.LA(1);
				if ( !(_la==TEMP || _la==TEMPORARY) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
			}

			setState(618);
			match(TRIGGER);
			setState(622);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,68,_ctx) ) {
			case 1:
				{
				setState(619);
				match(IF);
				setState(620);
				match(NOT);
				setState(621);
				match(EXISTS);
				}
				break;
			}
			setState(627);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,69,_ctx) ) {
			case 1:
				{
				setState(624);
				schema_name();
				setState(625);
				match(T__1);
				}
				break;
			}
			setState(629);
			trigger_name();
			setState(634);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BEFORE:
				{
				setState(630);
				match(BEFORE);
				}
				break;
			case AFTER:
				{
				setState(631);
				match(AFTER);
				}
				break;
			case INSTEAD:
				{
				{
				setState(632);
				match(INSTEAD);
				setState(633);
				match(OF);
				}
				}
				break;
			case DELETE:
			case UPDATE:
			case INSERT:
				break;
			default:
				break;
			}
			setState(650);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case DELETE:
				{
				setState(636);
				match(DELETE);
				}
				break;
			case INSERT:
				{
				setState(637);
				match(INSERT);
				}
				break;
			case UPDATE:
				{
				{
				setState(638);
				match(UPDATE);
				setState(648);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==OF) {
					{
					setState(639);
					match(OF);
					setState(640);
					column_name();
					setState(645);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==T__3) {
						{
						{
						setState(641);
						match(T__3);
						setState(642);
						column_name();
						}
						}
						setState(647);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
				}

				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(652);
			match(ON);
			setState(653);
			table_name();
			setState(657);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==FOR) {
				{
				setState(654);
				match(FOR);
				setState(655);
				match(EACH);
				setState(656);
				match(ROW);
				}
			}

			setState(661);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WHEN) {
				{
				setState(659);
				match(WHEN);
				setState(660);
				expr(0);
				}
			}

			setState(663);
			match(BEGIN);
			setState(672); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(668);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,76,_ctx) ) {
				case 1:
					{
					setState(664);
					update_stmt();
					}
					break;
				case 2:
					{
					setState(665);
					insert_stmt();
					}
					break;
				case 3:
					{
					setState(666);
					delete_stmt();
					}
					break;
				case 4:
					{
					setState(667);
					select_stmt();
					}
					break;
				}
				setState(670);
				match(T__0);
				}
				}
				setState(674); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( ((((_la - 67)) & ~0x3f) == 0 && ((1L << (_la - 67)) & ((1L << (DEFAULT - 67)) | (1L << (DELETE - 67)) | (1L << (UPDATE - 67)) | (1L << (REPLACE - 67)) | (1L << (INSERT - 67)) | (1L << (WITH - 67)))) != 0) || _la==VALUES || _la==SELECT );
			setState(676);
			match(END);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Create_view_stmtContext extends ParserRuleContext {
		public TerminalNode CREATE() { return getToken(SqlParsingParser.CREATE, 0); }
		public TerminalNode VIEW() { return getToken(SqlParsingParser.VIEW, 0); }
		public View_nameContext view_name() {
			return getRuleContext(View_nameContext.class,0);
		}
		public TerminalNode AS() { return getToken(SqlParsingParser.AS, 0); }
		public Select_stmtContext select_stmt() {
			return getRuleContext(Select_stmtContext.class,0);
		}
		public TerminalNode IF() { return getToken(SqlParsingParser.IF, 0); }
		public TerminalNode NOT() { return getToken(SqlParsingParser.NOT, 0); }
		public TerminalNode EXISTS() { return getToken(SqlParsingParser.EXISTS, 0); }
		public Schema_nameContext schema_name() {
			return getRuleContext(Schema_nameContext.class,0);
		}
		public List<Column_nameContext> column_name() {
			return getRuleContexts(Column_nameContext.class);
		}
		public Column_nameContext column_name(int i) {
			return getRuleContext(Column_nameContext.class,i);
		}
		public TerminalNode TEMP() { return getToken(SqlParsingParser.TEMP, 0); }
		public TerminalNode TEMPORARY() { return getToken(SqlParsingParser.TEMPORARY, 0); }
		public Create_view_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_create_view_stmt; }
	}

	public final Create_view_stmtContext create_view_stmt() throws RecognitionException {
		Create_view_stmtContext _localctx = new Create_view_stmtContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_create_view_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(678);
			match(CREATE);
			setState(680);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==TEMP || _la==TEMPORARY) {
				{
				setState(679);
				_la = _input.LA(1);
				if ( !(_la==TEMP || _la==TEMPORARY) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
			}

			setState(682);
			match(VIEW);
			setState(686);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,79,_ctx) ) {
			case 1:
				{
				setState(683);
				match(IF);
				setState(684);
				match(NOT);
				setState(685);
				match(EXISTS);
				}
				break;
			}
			setState(691);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,80,_ctx) ) {
			case 1:
				{
				setState(688);
				schema_name();
				setState(689);
				match(T__1);
				}
				break;
			}
			setState(693);
			view_name();
			setState(705);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__2) {
				{
				setState(694);
				match(T__2);
				setState(695);
				column_name();
				setState(700);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(696);
					match(T__3);
					setState(697);
					column_name();
					}
					}
					setState(702);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(703);
				match(T__4);
				}
			}

			setState(707);
			match(AS);
			setState(708);
			select_stmt();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Create_virtual_table_stmtContext extends ParserRuleContext {
		public TerminalNode CREATE() { return getToken(SqlParsingParser.CREATE, 0); }
		public TerminalNode VIRTUAL() { return getToken(SqlParsingParser.VIRTUAL, 0); }
		public TerminalNode TABLE() { return getToken(SqlParsingParser.TABLE, 0); }
		public Table_nameContext table_name() {
			return getRuleContext(Table_nameContext.class,0);
		}
		public TerminalNode USING() { return getToken(SqlParsingParser.USING, 0); }
		public Module_nameContext module_name() {
			return getRuleContext(Module_nameContext.class,0);
		}
		public TerminalNode IF() { return getToken(SqlParsingParser.IF, 0); }
		public TerminalNode NOT() { return getToken(SqlParsingParser.NOT, 0); }
		public TerminalNode EXISTS() { return getToken(SqlParsingParser.EXISTS, 0); }
		public Schema_nameContext schema_name() {
			return getRuleContext(Schema_nameContext.class,0);
		}
		public List<Module_argumentContext> module_argument() {
			return getRuleContexts(Module_argumentContext.class);
		}
		public Module_argumentContext module_argument(int i) {
			return getRuleContext(Module_argumentContext.class,i);
		}
		public Create_virtual_table_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_create_virtual_table_stmt; }
	}

	public final Create_virtual_table_stmtContext create_virtual_table_stmt() throws RecognitionException {
		Create_virtual_table_stmtContext _localctx = new Create_virtual_table_stmtContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_create_virtual_table_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(710);
			match(CREATE);
			setState(711);
			match(VIRTUAL);
			setState(712);
			match(TABLE);
			setState(716);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,83,_ctx) ) {
			case 1:
				{
				setState(713);
				match(IF);
				setState(714);
				match(NOT);
				setState(715);
				match(EXISTS);
				}
				break;
			}
			setState(721);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,84,_ctx) ) {
			case 1:
				{
				setState(718);
				schema_name();
				setState(719);
				match(T__1);
				}
				break;
			}
			setState(723);
			table_name();
			setState(724);
			match(USING);
			setState(725);
			module_name();
			setState(737);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__2) {
				{
				setState(726);
				match(T__2);
				setState(727);
				module_argument();
				setState(732);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(728);
					match(T__3);
					setState(729);
					module_argument();
					}
					}
					setState(734);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(735);
				match(T__4);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class With_clauseContext extends ParserRuleContext {
		public TerminalNode WITH() { return getToken(SqlParsingParser.WITH, 0); }
		public List<Cte_table_nameContext> cte_table_name() {
			return getRuleContexts(Cte_table_nameContext.class);
		}
		public Cte_table_nameContext cte_table_name(int i) {
			return getRuleContext(Cte_table_nameContext.class,i);
		}
		public List<TerminalNode> AS() { return getTokens(SqlParsingParser.AS); }
		public TerminalNode AS(int i) {
			return getToken(SqlParsingParser.AS, i);
		}
		public List<Select_stmtContext> select_stmt() {
			return getRuleContexts(Select_stmtContext.class);
		}
		public Select_stmtContext select_stmt(int i) {
			return getRuleContext(Select_stmtContext.class,i);
		}
		public TerminalNode RECURSIVE() { return getToken(SqlParsingParser.RECURSIVE, 0); }
		public With_clauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_with_clause; }
	}

	public final With_clauseContext with_clause() throws RecognitionException {
		With_clauseContext _localctx = new With_clauseContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_with_clause);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(739);
			match(WITH);
			setState(741);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,87,_ctx) ) {
			case 1:
				{
				setState(740);
				match(RECURSIVE);
				}
				break;
			}
			setState(743);
			cte_table_name();
			setState(744);
			match(AS);
			setState(745);
			match(T__2);
			setState(746);
			select_stmt();
			setState(747);
			match(T__4);
			setState(757);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__3) {
				{
				{
				setState(748);
				match(T__3);
				setState(749);
				cte_table_name();
				setState(750);
				match(AS);
				setState(751);
				match(T__2);
				setState(752);
				select_stmt();
				setState(753);
				match(T__4);
				}
				}
				setState(759);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Cte_table_nameContext extends ParserRuleContext {
		public Table_nameContext table_name() {
			return getRuleContext(Table_nameContext.class,0);
		}
		public List<Column_nameContext> column_name() {
			return getRuleContexts(Column_nameContext.class);
		}
		public Column_nameContext column_name(int i) {
			return getRuleContext(Column_nameContext.class,i);
		}
		public Cte_table_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_cte_table_name; }
	}

	public final Cte_table_nameContext cte_table_name() throws RecognitionException {
		Cte_table_nameContext _localctx = new Cte_table_nameContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_cte_table_name);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(760);
			table_name();
			setState(772);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__2) {
				{
				setState(761);
				match(T__2);
				setState(762);
				column_name();
				setState(767);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(763);
					match(T__3);
					setState(764);
					column_name();
					}
					}
					setState(769);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(770);
				match(T__4);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Recursive_cteContext extends ParserRuleContext {
		public Cte_table_nameContext cte_table_name() {
			return getRuleContext(Cte_table_nameContext.class,0);
		}
		public TerminalNode AS() { return getToken(SqlParsingParser.AS, 0); }
		public Initial_selectContext initial_select() {
			return getRuleContext(Initial_selectContext.class,0);
		}
		public TerminalNode UNION() { return getToken(SqlParsingParser.UNION, 0); }
		public Recursive_selectContext recursive_select() {
			return getRuleContext(Recursive_selectContext.class,0);
		}
		public TerminalNode ALL() { return getToken(SqlParsingParser.ALL, 0); }
		public Recursive_cteContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_recursive_cte; }
	}

	public final Recursive_cteContext recursive_cte() throws RecognitionException {
		Recursive_cteContext _localctx = new Recursive_cteContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_recursive_cte);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(774);
			cte_table_name();
			setState(775);
			match(AS);
			setState(776);
			match(T__2);
			setState(777);
			initial_select();
			setState(778);
			match(UNION);
			setState(780);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ALL) {
				{
				setState(779);
				match(ALL);
				}
			}

			setState(782);
			recursive_select();
			setState(783);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Common_table_expressionContext extends ParserRuleContext {
		public Table_nameContext table_name() {
			return getRuleContext(Table_nameContext.class,0);
		}
		public TerminalNode AS() { return getToken(SqlParsingParser.AS, 0); }
		public Select_stmtContext select_stmt() {
			return getRuleContext(Select_stmtContext.class,0);
		}
		public List<Column_nameContext> column_name() {
			return getRuleContexts(Column_nameContext.class);
		}
		public Column_nameContext column_name(int i) {
			return getRuleContext(Column_nameContext.class,i);
		}
		public Common_table_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_common_table_expression; }
	}

	public final Common_table_expressionContext common_table_expression() throws RecognitionException {
		Common_table_expressionContext _localctx = new Common_table_expressionContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_common_table_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(785);
			table_name();
			setState(797);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__2) {
				{
				setState(786);
				match(T__2);
				setState(787);
				column_name();
				setState(792);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(788);
					match(T__3);
					setState(789);
					column_name();
					}
					}
					setState(794);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(795);
				match(T__4);
				}
			}

			setState(799);
			match(AS);
			setState(800);
			match(T__2);
			setState(801);
			select_stmt();
			setState(802);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Delete_stmtContext extends ParserRuleContext {
		public TerminalNode DELETE() { return getToken(SqlParsingParser.DELETE, 0); }
		public TerminalNode FROM() { return getToken(SqlParsingParser.FROM, 0); }
		public Qualified_table_nameContext qualified_table_name() {
			return getRuleContext(Qualified_table_nameContext.class,0);
		}
		public With_clauseContext with_clause() {
			return getRuleContext(With_clauseContext.class,0);
		}
		public TerminalNode WHERE() { return getToken(SqlParsingParser.WHERE, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public Delete_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_delete_stmt; }
	}

	public final Delete_stmtContext delete_stmt() throws RecognitionException {
		Delete_stmtContext _localctx = new Delete_stmtContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_delete_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(805);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WITH) {
				{
				setState(804);
				with_clause();
				}
			}

			setState(807);
			match(DELETE);
			setState(808);
			match(FROM);
			setState(809);
			qualified_table_name();
			setState(812);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WHERE) {
				{
				setState(810);
				match(WHERE);
				setState(811);
				expr(0);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Delete_stmt_limitedContext extends ParserRuleContext {
		public TerminalNode DELETE() { return getToken(SqlParsingParser.DELETE, 0); }
		public TerminalNode FROM() { return getToken(SqlParsingParser.FROM, 0); }
		public Qualified_table_nameContext qualified_table_name() {
			return getRuleContext(Qualified_table_nameContext.class,0);
		}
		public With_clauseContext with_clause() {
			return getRuleContext(With_clauseContext.class,0);
		}
		public TerminalNode WHERE() { return getToken(SqlParsingParser.WHERE, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public Limit_stmtContext limit_stmt() {
			return getRuleContext(Limit_stmtContext.class,0);
		}
		public Order_by_stmtContext order_by_stmt() {
			return getRuleContext(Order_by_stmtContext.class,0);
		}
		public Delete_stmt_limitedContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_delete_stmt_limited; }
	}

	public final Delete_stmt_limitedContext delete_stmt_limited() throws RecognitionException {
		Delete_stmt_limitedContext _localctx = new Delete_stmt_limitedContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_delete_stmt_limited);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(815);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WITH) {
				{
				setState(814);
				with_clause();
				}
			}

			setState(817);
			match(DELETE);
			setState(818);
			match(FROM);
			setState(819);
			qualified_table_name();
			setState(822);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WHERE) {
				{
				setState(820);
				match(WHERE);
				setState(821);
				expr(0);
				}
			}

			setState(828);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ORDER || _la==LIMIT) {
				{
				setState(825);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ORDER) {
					{
					setState(824);
					order_by_stmt();
					}
				}

				setState(827);
				limit_stmt();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Detach_stmtContext extends ParserRuleContext {
		public TerminalNode DETACH() { return getToken(SqlParsingParser.DETACH, 0); }
		public Schema_nameContext schema_name() {
			return getRuleContext(Schema_nameContext.class,0);
		}
		public TerminalNode DATABASE() { return getToken(SqlParsingParser.DATABASE, 0); }
		public Detach_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_detach_stmt; }
	}

	public final Detach_stmtContext detach_stmt() throws RecognitionException {
		Detach_stmtContext _localctx = new Detach_stmtContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_detach_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(830);
			match(DETACH);
			setState(832);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,100,_ctx) ) {
			case 1:
				{
				setState(831);
				match(DATABASE);
				}
				break;
			}
			setState(834);
			schema_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Drop_stmtContext extends ParserRuleContext {
		public Token object;
		public TerminalNode DROP() { return getToken(SqlParsingParser.DROP, 0); }
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public TerminalNode INDEX() { return getToken(SqlParsingParser.INDEX, 0); }
		public TerminalNode TABLE() { return getToken(SqlParsingParser.TABLE, 0); }
		public TerminalNode TRIGGER() { return getToken(SqlParsingParser.TRIGGER, 0); }
		public TerminalNode VIEW() { return getToken(SqlParsingParser.VIEW, 0); }
		public TerminalNode IF() { return getToken(SqlParsingParser.IF, 0); }
		public TerminalNode EXISTS() { return getToken(SqlParsingParser.EXISTS, 0); }
		public Schema_nameContext schema_name() {
			return getRuleContext(Schema_nameContext.class,0);
		}
		public Drop_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_drop_stmt; }
	}

	public final Drop_stmtContext drop_stmt() throws RecognitionException {
		Drop_stmtContext _localctx = new Drop_stmtContext(_ctx, getState());
		enterRule(_localctx, 60, RULE_drop_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(836);
			match(DROP);
			setState(837);
			((Drop_stmtContext)_localctx).object = _input.LT(1);
			_la = _input.LA(1);
			if ( !(_la==TABLE || _la==INDEX || _la==TRIGGER || _la==VIEW) ) {
				((Drop_stmtContext)_localctx).object = (Token)_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			setState(840);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,101,_ctx) ) {
			case 1:
				{
				setState(838);
				match(IF);
				setState(839);
				match(EXISTS);
				}
				break;
			}
			setState(845);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,102,_ctx) ) {
			case 1:
				{
				setState(842);
				schema_name();
				setState(843);
				match(T__1);
				}
				break;
			}
			setState(847);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprContext extends ParserRuleContext {
		public Literal_valueContext literal_value() {
			return getRuleContext(Literal_valueContext.class,0);
		}
		public TerminalNode BIND_PARAMETER() { return getToken(SqlParsingParser.BIND_PARAMETER, 0); }
		public Column_nameContext column_name() {
			return getRuleContext(Column_nameContext.class,0);
		}
		public Table_nameContext table_name() {
			return getRuleContext(Table_nameContext.class,0);
		}
		public Schema_nameContext schema_name() {
			return getRuleContext(Schema_nameContext.class,0);
		}
		public Unary_operatorContext unary_operator() {
			return getRuleContext(Unary_operatorContext.class,0);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public Function_nameContext function_name() {
			return getRuleContext(Function_nameContext.class,0);
		}
		public Filter_clauseContext filter_clause() {
			return getRuleContext(Filter_clauseContext.class,0);
		}
		public Over_clauseContext over_clause() {
			return getRuleContext(Over_clauseContext.class,0);
		}
		public TerminalNode DISTINCT() { return getToken(SqlParsingParser.DISTINCT, 0); }
		public TerminalNode CAST() { return getToken(SqlParsingParser.CAST, 0); }
		public TerminalNode AS() { return getToken(SqlParsingParser.AS, 0); }
		public Type_nameContext type_name() {
			return getRuleContext(Type_nameContext.class,0);
		}
		public Select_stmtContext select_stmt() {
			return getRuleContext(Select_stmtContext.class,0);
		}
		public TerminalNode EXISTS() { return getToken(SqlParsingParser.EXISTS, 0); }
		public TerminalNode NOT() { return getToken(SqlParsingParser.NOT, 0); }
		public TerminalNode CASE() { return getToken(SqlParsingParser.CASE, 0); }
		public TerminalNode END() { return getToken(SqlParsingParser.END, 0); }
		public List<TerminalNode> WHEN() { return getTokens(SqlParsingParser.WHEN); }
		public TerminalNode WHEN(int i) {
			return getToken(SqlParsingParser.WHEN, i);
		}
		public List<TerminalNode> THEN() { return getTokens(SqlParsingParser.THEN); }
		public TerminalNode THEN(int i) {
			return getToken(SqlParsingParser.THEN, i);
		}
		public TerminalNode ELSE() { return getToken(SqlParsingParser.ELSE, 0); }
		public Raise_functionContext raise_function() {
			return getRuleContext(Raise_functionContext.class,0);
		}
		public TerminalNode IS() { return getToken(SqlParsingParser.IS, 0); }
		public TerminalNode IN() { return getToken(SqlParsingParser.IN, 0); }
		public TerminalNode LIKE() { return getToken(SqlParsingParser.LIKE, 0); }
		public TerminalNode GLOB() { return getToken(SqlParsingParser.GLOB, 0); }
		public TerminalNode MATCH() { return getToken(SqlParsingParser.MATCH, 0); }
		public TerminalNode REGEXP() { return getToken(SqlParsingParser.REGEXP, 0); }
		public TerminalNode AND() { return getToken(SqlParsingParser.AND, 0); }
		public TerminalNode OR() { return getToken(SqlParsingParser.OR, 0); }
		public TerminalNode BETWEEN() { return getToken(SqlParsingParser.BETWEEN, 0); }
		public TerminalNode COLLATE() { return getToken(SqlParsingParser.COLLATE, 0); }
		public Collation_nameContext collation_name() {
			return getRuleContext(Collation_nameContext.class,0);
		}
		public TerminalNode ESCAPE() { return getToken(SqlParsingParser.ESCAPE, 0); }
		public TerminalNode ISNULL() { return getToken(SqlParsingParser.ISNULL, 0); }
		public TerminalNode NOTNULL() { return getToken(SqlParsingParser.NOTNULL, 0); }
		public TerminalNode NULL_() { return getToken(SqlParsingParser.NULL_, 0); }
		public Table_function_nameContext table_function_name() {
			return getRuleContext(Table_function_nameContext.class,0);
		}
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 62;
		enterRecursionRule(_localctx, 62, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(937);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,116,_ctx) ) {
			case 1:
				{
				setState(850);
				literal_value();
				}
				break;
			case 2:
				{
				setState(851);
				match(BIND_PARAMETER);
				}
				break;
			case 3:
				{
				setState(860);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,104,_ctx) ) {
				case 1:
					{
					setState(855);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,103,_ctx) ) {
					case 1:
						{
						setState(852);
						schema_name();
						setState(853);
						match(T__1);
						}
						break;
					}
					setState(857);
					table_name();
					setState(858);
					match(T__1);
					}
					break;
				}
				setState(862);
				column_name();
				}
				break;
			case 4:
				{
				setState(863);
				unary_operator();
				setState(864);
				expr(21);
				}
				break;
			case 5:
				{
				setState(866);
				function_name();
				setState(867);
				match(T__2);
				setState(880);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case T__2:
				case T__5:
				case T__6:
				case T__23:
				case EXPLAIN:
				case QUERY:
				case PLAN:
				case ALTER:
				case TABLE:
				case RENAME:
				case TO:
				case COLUMN:
				case ADD:
				case ANALYZE:
				case ATTACH:
				case DATABASE:
				case AS:
				case BEGIN:
				case DEFERRED:
				case IMMEDIATE:
				case EXCLUSIVE:
				case TRANSACTION:
				case COMMIT:
				case END:
				case ROLLBACK:
				case SAVEPOINT:
				case RELEASE:
				case CREATE:
				case UNIQUE:
				case INDEX:
				case IF:
				case NOT:
				case EXISTS:
				case ON:
				case WHERE:
				case COLLATE:
				case TEMP:
				case TEMPORARY:
				case WITHOUT:
				case IDENTIFIER:
				case CONSTRAINT:
				case PRIMARY:
				case KEY:
				case AUTOINCREMENT:
				case NULL_:
				case CHECK:
				case DEFAULT:
				case GENERATED:
				case ALWAYS:
				case STORED:
				case VIRTUAL:
				case NUMERIC_LITERAL:
				case FOREIGN:
				case REFERENCES:
				case DELETE:
				case UPDATE:
				case SET:
				case CASCADE:
				case RESTRICT:
				case NO:
				case ACTION:
				case MATCH:
				case DEFERRABLE:
				case INITIALLY:
				case CONFLICT:
				case ABORT:
				case FAIL:
				case IGNORE:
				case REPLACE:
				case TRIGGER:
				case BEFORE:
				case AFTER:
				case INSTEAD:
				case OF:
				case INSERT:
				case FOR:
				case EACH:
				case ROW:
				case WHEN:
				case VIEW:
				case USING:
				case WITH:
				case RECURSIVE:
				case UNION:
				case ALL:
				case FROM:
				case DETACH:
				case DROP:
				case BIND_PARAMETER:
				case DISTINCT:
				case CAST:
				case CASE:
				case THEN:
				case ELSE:
				case IS:
				case IN:
				case LIKE:
				case GLOB:
				case REGEXP:
				case AND:
				case OR:
				case BETWEEN:
				case ESCAPE:
				case ISNULL:
				case NOTNULL:
				case RAISE:
				case STRING_LITERAL:
				case BLOB_LITERAL:
				case TRUE_:
				case FALSE_:
				case CURRENT_TIME:
				case CURRENT_DATE:
				case CURRENT_TIMESTAMP:
				case INTO:
				case VALUES:
				case PRAGMA:
				case REINDEX:
				case SELECT:
				case GROUP:
				case BY:
				case HAVING:
				case WINDOW:
				case INTERSECT:
				case EXCEPT:
				case INDEXED:
				case NATURAL:
				case LEFT:
				case OUTER:
				case INNER:
				case CROSS:
				case JOIN:
				case VACUUM:
				case FILTER:
				case PARTITION:
				case ORDER:
				case OVER:
				case EXCLUDE:
				case CURRENT:
				case RANGE:
				case ROWS:
				case GROUPS:
				case LIMIT:
				case OFFSET:
				case NULLS:
				case FIRST:
				case LAST:
				case ASC:
				case DESC:
				case PRECEDING:
				case FOLLOWING:
				case UNBOUNDED:
				case FIRST_VALUE:
				case LAST_VALUE:
				case CUME_DIST:
				case PERCENT_RANK:
				case DENSE_RANK:
				case RANK:
				case ROW_NUMBER:
				case LAG:
				case LEAD:
				case NTH_VALUE:
				case NTILE:
				case FULL:
				case RIGHT:
					{
					{
					setState(869);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,105,_ctx) ) {
					case 1:
						{
						setState(868);
						match(DISTINCT);
						}
						break;
					}
					setState(871);
					expr(0);
					setState(876);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==T__3) {
						{
						{
						setState(872);
						match(T__3);
						setState(873);
						expr(0);
						}
						}
						setState(878);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
					}
					break;
				case T__8:
					{
					setState(879);
					match(T__8);
					}
					break;
				case T__4:
					break;
				default:
					break;
				}
				setState(882);
				match(T__4);
				setState(884);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,108,_ctx) ) {
				case 1:
					{
					setState(883);
					filter_clause();
					}
					break;
				}
				setState(887);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,109,_ctx) ) {
				case 1:
					{
					setState(886);
					over_clause();
					}
					break;
				}
				}
				break;
			case 6:
				{
				setState(889);
				match(T__2);
				setState(890);
				expr(0);
				setState(895);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(891);
					match(T__3);
					setState(892);
					expr(0);
					}
					}
					setState(897);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(898);
				match(T__4);
				}
				break;
			case 7:
				{
				setState(900);
				match(CAST);
				setState(901);
				match(T__2);
				setState(902);
				expr(0);
				setState(903);
				match(AS);
				setState(904);
				type_name();
				setState(905);
				match(T__4);
				}
				break;
			case 8:
				{
				setState(911);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==NOT || _la==EXISTS) {
					{
					setState(908);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==NOT) {
						{
						setState(907);
						match(NOT);
						}
					}

					setState(910);
					match(EXISTS);
					}
				}

				setState(913);
				match(T__2);
				setState(914);
				select_stmt();
				setState(915);
				match(T__4);
				}
				break;
			case 9:
				{
				setState(917);
				match(CASE);
				setState(919);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,113,_ctx) ) {
				case 1:
					{
					setState(918);
					expr(0);
					}
					break;
				}
				setState(926); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(921);
					match(WHEN);
					setState(922);
					expr(0);
					setState(923);
					match(THEN);
					setState(924);
					expr(0);
					}
					}
					setState(928); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHEN );
				setState(932);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ELSE) {
					{
					setState(930);
					match(ELSE);
					setState(931);
					expr(0);
					}
				}

				setState(934);
				match(END);
				}
				break;
			case 10:
				{
				setState(936);
				raise_function();
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(1058);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,132,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(1056);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,131,_ctx) ) {
					case 1:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(939);
						if (!(precpred(_ctx, 20))) throw new FailedPredicateException(this, "precpred(_ctx, 20)");
						setState(940);
						match(T__7);
						setState(941);
						expr(21);
						}
						break;
					case 2:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(942);
						if (!(precpred(_ctx, 19))) throw new FailedPredicateException(this, "precpred(_ctx, 19)");
						setState(943);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__8) | (1L << T__9) | (1L << T__10))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(944);
						expr(20);
						}
						break;
					case 3:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(945);
						if (!(precpred(_ctx, 18))) throw new FailedPredicateException(this, "precpred(_ctx, 18)");
						setState(946);
						_la = _input.LA(1);
						if ( !(_la==T__5 || _la==T__6) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(947);
						expr(19);
						}
						break;
					case 4:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(948);
						if (!(precpred(_ctx, 17))) throw new FailedPredicateException(this, "precpred(_ctx, 17)");
						setState(949);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__11) | (1L << T__12) | (1L << T__13) | (1L << T__14))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(950);
						expr(18);
						}
						break;
					case 5:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(951);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(952);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__15) | (1L << T__16) | (1L << T__17) | (1L << T__18))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(953);
						expr(17);
						}
						break;
					case 6:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(954);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(967);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,117,_ctx) ) {
						case 1:
							{
							setState(955);
							match(T__19);
							}
							break;
						case 2:
							{
							setState(956);
							match(T__20);
							}
							break;
						case 3:
							{
							setState(957);
							match(T__21);
							}
							break;
						case 4:
							{
							setState(958);
							match(T__22);
							}
							break;
						case 5:
							{
							setState(959);
							match(IS);
							}
							break;
						case 6:
							{
							setState(960);
							match(IS);
							setState(961);
							match(NOT);
							}
							break;
						case 7:
							{
							setState(962);
							match(IN);
							}
							break;
						case 8:
							{
							setState(963);
							match(LIKE);
							}
							break;
						case 9:
							{
							setState(964);
							match(GLOB);
							}
							break;
						case 10:
							{
							setState(965);
							match(MATCH);
							}
							break;
						case 11:
							{
							setState(966);
							match(REGEXP);
							}
							break;
						}
						setState(969);
						expr(16);
						}
						break;
					case 7:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(970);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(971);
						match(AND);
						setState(972);
						expr(15);
						}
						break;
					case 8:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(973);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(974);
						match(OR);
						setState(975);
						expr(14);
						}
						break;
					case 9:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(976);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(977);
						match(IS);
						setState(979);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,118,_ctx) ) {
						case 1:
							{
							setState(978);
							match(NOT);
							}
							break;
						}
						setState(981);
						expr(7);
						}
						break;
					case 10:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(982);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(984);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==NOT) {
							{
							setState(983);
							match(NOT);
							}
						}

						setState(986);
						match(BETWEEN);
						setState(987);
						expr(0);
						setState(988);
						match(AND);
						setState(989);
						expr(6);
						}
						break;
					case 11:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(991);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(992);
						match(COLLATE);
						setState(993);
						collation_name();
						}
						break;
					case 12:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(994);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(996);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==NOT) {
							{
							setState(995);
							match(NOT);
							}
						}

						setState(998);
						_la = _input.LA(1);
						if ( !(((((_la - 82)) & ~0x3f) == 0 && ((1L << (_la - 82)) & ((1L << (MATCH - 82)) | (1L << (LIKE - 82)) | (1L << (GLOB - 82)) | (1L << (REGEXP - 82)))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(999);
						expr(0);
						setState(1002);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,121,_ctx) ) {
						case 1:
							{
							setState(1000);
							match(ESCAPE);
							setState(1001);
							expr(0);
							}
							break;
						}
						}
						break;
					case 13:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(1004);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(1009);
						_errHandler.sync(this);
						switch (_input.LA(1)) {
						case ISNULL:
							{
							setState(1005);
							match(ISNULL);
							}
							break;
						case NOTNULL:
							{
							setState(1006);
							match(NOTNULL);
							}
							break;
						case NOT:
							{
							{
							setState(1007);
							match(NOT);
							setState(1008);
							match(NULL_);
							}
							}
							break;
						default:
							throw new NoViableAltException(this);
						}
						}
						break;
					case 14:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(1011);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(1013);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==NOT) {
							{
							setState(1012);
							match(NOT);
							}
						}

						setState(1015);
						match(IN);
						setState(1054);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,130,_ctx) ) {
						case 1:
							{
							{
							setState(1016);
							match(T__2);
							setState(1026);
							_errHandler.sync(this);
							switch ( getInterpreter().adaptivePredict(_input,125,_ctx) ) {
							case 1:
								{
								setState(1017);
								select_stmt();
								}
								break;
							case 2:
								{
								setState(1018);
								expr(0);
								setState(1023);
								_errHandler.sync(this);
								_la = _input.LA(1);
								while (_la==T__3) {
									{
									{
									setState(1019);
									match(T__3);
									setState(1020);
									expr(0);
									}
									}
									setState(1025);
									_errHandler.sync(this);
									_la = _input.LA(1);
								}
								}
								break;
							}
							setState(1028);
							match(T__4);
							}
							}
							break;
						case 2:
							{
							{
							setState(1032);
							_errHandler.sync(this);
							switch ( getInterpreter().adaptivePredict(_input,126,_ctx) ) {
							case 1:
								{
								setState(1029);
								schema_name();
								setState(1030);
								match(T__1);
								}
								break;
							}
							setState(1034);
							table_name();
							}
							}
							break;
						case 3:
							{
							{
							setState(1038);
							_errHandler.sync(this);
							switch ( getInterpreter().adaptivePredict(_input,127,_ctx) ) {
							case 1:
								{
								setState(1035);
								schema_name();
								setState(1036);
								match(T__1);
								}
								break;
							}
							setState(1040);
							table_function_name();
							setState(1041);
							match(T__2);
							setState(1050);
							_errHandler.sync(this);
							_la = _input.LA(1);
							if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__2) | (1L << T__5) | (1L << T__6) | (1L << T__23) | (1L << EXPLAIN) | (1L << QUERY) | (1L << PLAN) | (1L << ALTER) | (1L << TABLE) | (1L << RENAME) | (1L << TO) | (1L << COLUMN) | (1L << ADD) | (1L << ANALYZE) | (1L << ATTACH) | (1L << DATABASE) | (1L << AS) | (1L << BEGIN) | (1L << DEFERRED) | (1L << IMMEDIATE) | (1L << EXCLUSIVE) | (1L << TRANSACTION) | (1L << COMMIT) | (1L << END) | (1L << ROLLBACK) | (1L << SAVEPOINT) | (1L << RELEASE) | (1L << CREATE) | (1L << UNIQUE) | (1L << INDEX) | (1L << IF) | (1L << NOT) | (1L << EXISTS) | (1L << ON) | (1L << WHERE) | (1L << COLLATE) | (1L << TEMP) | (1L << TEMPORARY) | (1L << WITHOUT) | (1L << IDENTIFIER) | (1L << CONSTRAINT) | (1L << PRIMARY) | (1L << KEY))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (AUTOINCREMENT - 64)) | (1L << (NULL_ - 64)) | (1L << (CHECK - 64)) | (1L << (DEFAULT - 64)) | (1L << (GENERATED - 64)) | (1L << (ALWAYS - 64)) | (1L << (STORED - 64)) | (1L << (VIRTUAL - 64)) | (1L << (NUMERIC_LITERAL - 64)) | (1L << (FOREIGN - 64)) | (1L << (REFERENCES - 64)) | (1L << (DELETE - 64)) | (1L << (UPDATE - 64)) | (1L << (SET - 64)) | (1L << (CASCADE - 64)) | (1L << (RESTRICT - 64)) | (1L << (NO - 64)) | (1L << (ACTION - 64)) | (1L << (MATCH - 64)) | (1L << (DEFERRABLE - 64)) | (1L << (INITIALLY - 64)) | (1L << (CONFLICT - 64)) | (1L << (ABORT - 64)) | (1L << (FAIL - 64)) | (1L << (IGNORE - 64)) | (1L << (REPLACE - 64)) | (1L << (TRIGGER - 64)) | (1L << (BEFORE - 64)) | (1L << (AFTER - 64)) | (1L << (INSTEAD - 64)) | (1L << (OF - 64)) | (1L << (INSERT - 64)) | (1L << (FOR - 64)) | (1L << (EACH - 64)) | (1L << (ROW - 64)) | (1L << (WHEN - 64)) | (1L << (VIEW - 64)) | (1L << (USING - 64)) | (1L << (WITH - 64)) | (1L << (RECURSIVE - 64)) | (1L << (UNION - 64)) | (1L << (ALL - 64)) | (1L << (FROM - 64)) | (1L << (DETACH - 64)) | (1L << (DROP - 64)) | (1L << (BIND_PARAMETER - 64)) | (1L << (DISTINCT - 64)) | (1L << (CAST - 64)) | (1L << (CASE - 64)) | (1L << (THEN - 64)) | (1L << (ELSE - 64)) | (1L << (IS - 64)) | (1L << (IN - 64)) | (1L << (LIKE - 64)) | (1L << (GLOB - 64)) | (1L << (REGEXP - 64)) | (1L << (AND - 64)) | (1L << (OR - 64)) | (1L << (BETWEEN - 64)) | (1L << (ESCAPE - 64)) | (1L << (ISNULL - 64)) | (1L << (NOTNULL - 64)) | (1L << (RAISE - 64)) | (1L << (STRING_LITERAL - 64)))) != 0) || ((((_la - 128)) & ~0x3f) == 0 && ((1L << (_la - 128)) & ((1L << (BLOB_LITERAL - 128)) | (1L << (TRUE_ - 128)) | (1L << (FALSE_ - 128)) | (1L << (CURRENT_TIME - 128)) | (1L << (CURRENT_DATE - 128)) | (1L << (CURRENT_TIMESTAMP - 128)) | (1L << (INTO - 128)) | (1L << (VALUES - 128)) | (1L << (PRAGMA - 128)) | (1L << (REINDEX - 128)) | (1L << (SELECT - 128)) | (1L << (GROUP - 128)) | (1L << (BY - 128)) | (1L << (HAVING - 128)) | (1L << (WINDOW - 128)) | (1L << (INTERSECT - 128)) | (1L << (EXCEPT - 128)) | (1L << (INDEXED - 128)) | (1L << (NATURAL - 128)) | (1L << (LEFT - 128)) | (1L << (OUTER - 128)) | (1L << (INNER - 128)) | (1L << (CROSS - 128)) | (1L << (JOIN - 128)) | (1L << (VACUUM - 128)) | (1L << (FILTER - 128)) | (1L << (PARTITION - 128)) | (1L << (ORDER - 128)) | (1L << (OVER - 128)) | (1L << (EXCLUDE - 128)) | (1L << (CURRENT - 128)) | (1L << (RANGE - 128)) | (1L << (ROWS - 128)) | (1L << (GROUPS - 128)) | (1L << (LIMIT - 128)) | (1L << (OFFSET - 128)) | (1L << (NULLS - 128)) | (1L << (FIRST - 128)) | (1L << (LAST - 128)) | (1L << (ASC - 128)) | (1L << (DESC - 128)) | (1L << (PRECEDING - 128)) | (1L << (FOLLOWING - 128)) | (1L << (UNBOUNDED - 128)) | (1L << (FIRST_VALUE - 128)) | (1L << (LAST_VALUE - 128)) | (1L << (CUME_DIST - 128)) | (1L << (PERCENT_RANK - 128)) | (1L << (DENSE_RANK - 128)) | (1L << (RANK - 128)) | (1L << (ROW_NUMBER - 128)) | (1L << (LAG - 128)) | (1L << (LEAD - 128)) | (1L << (NTH_VALUE - 128)) | (1L << (NTILE - 128)) | (1L << (FULL - 128)) | (1L << (RIGHT - 128)))) != 0)) {
								{
								setState(1042);
								expr(0);
								setState(1047);
								_errHandler.sync(this);
								_la = _input.LA(1);
								while (_la==T__3) {
									{
									{
									setState(1043);
									match(T__3);
									setState(1044);
									expr(0);
									}
									}
									setState(1049);
									_errHandler.sync(this);
									_la = _input.LA(1);
								}
								}
							}

							setState(1052);
							match(T__4);
							}
							}
							break;
						}
						}
						break;
					}
					} 
				}
				setState(1060);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,132,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class Raise_functionContext extends ParserRuleContext {
		public TerminalNode RAISE() { return getToken(SqlParsingParser.RAISE, 0); }
		public TerminalNode IGNORE() { return getToken(SqlParsingParser.IGNORE, 0); }
		public Error_messageContext error_message() {
			return getRuleContext(Error_messageContext.class,0);
		}
		public TerminalNode ROLLBACK() { return getToken(SqlParsingParser.ROLLBACK, 0); }
		public TerminalNode ABORT() { return getToken(SqlParsingParser.ABORT, 0); }
		public TerminalNode FAIL() { return getToken(SqlParsingParser.FAIL, 0); }
		public Raise_functionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_raise_function; }
	}

	public final Raise_functionContext raise_function() throws RecognitionException {
		Raise_functionContext _localctx = new Raise_functionContext(_ctx, getState());
		enterRule(_localctx, 64, RULE_raise_function);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1061);
			match(RAISE);
			setState(1062);
			match(T__2);
			setState(1067);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IGNORE:
				{
				setState(1063);
				match(IGNORE);
				}
				break;
			case ROLLBACK:
			case ABORT:
			case FAIL:
				{
				{
				setState(1064);
				_la = _input.LA(1);
				if ( !(((((_la - 45)) & ~0x3f) == 0 && ((1L << (_la - 45)) & ((1L << (ROLLBACK - 45)) | (1L << (ABORT - 45)) | (1L << (FAIL - 45)))) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(1065);
				match(T__3);
				setState(1066);
				error_message();
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(1069);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Literal_valueContext extends ParserRuleContext {
		public TerminalNode NUMERIC_LITERAL() { return getToken(SqlParsingParser.NUMERIC_LITERAL, 0); }
		public TerminalNode STRING_LITERAL() { return getToken(SqlParsingParser.STRING_LITERAL, 0); }
		public TerminalNode BLOB_LITERAL() { return getToken(SqlParsingParser.BLOB_LITERAL, 0); }
		public TerminalNode NULL_() { return getToken(SqlParsingParser.NULL_, 0); }
		public TerminalNode TRUE_() { return getToken(SqlParsingParser.TRUE_, 0); }
		public TerminalNode FALSE_() { return getToken(SqlParsingParser.FALSE_, 0); }
		public TerminalNode CURRENT_TIME() { return getToken(SqlParsingParser.CURRENT_TIME, 0); }
		public TerminalNode CURRENT_DATE() { return getToken(SqlParsingParser.CURRENT_DATE, 0); }
		public TerminalNode CURRENT_TIMESTAMP() { return getToken(SqlParsingParser.CURRENT_TIMESTAMP, 0); }
		public Literal_valueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal_value; }
	}

	public final Literal_valueContext literal_value() throws RecognitionException {
		Literal_valueContext _localctx = new Literal_valueContext(_ctx, getState());
		enterRule(_localctx, 66, RULE_literal_value);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1071);
			_la = _input.LA(1);
			if ( !(((((_la - 65)) & ~0x3f) == 0 && ((1L << (_la - 65)) & ((1L << (NULL_ - 65)) | (1L << (NUMERIC_LITERAL - 65)) | (1L << (STRING_LITERAL - 65)) | (1L << (BLOB_LITERAL - 65)))) != 0) || ((((_la - 129)) & ~0x3f) == 0 && ((1L << (_la - 129)) & ((1L << (TRUE_ - 129)) | (1L << (FALSE_ - 129)) | (1L << (CURRENT_TIME - 129)) | (1L << (CURRENT_DATE - 129)) | (1L << (CURRENT_TIMESTAMP - 129)))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Insert_stmtContext extends ParserRuleContext {
		public TerminalNode INTO() { return getToken(SqlParsingParser.INTO, 0); }
		public Table_nameContext table_name() {
			return getRuleContext(Table_nameContext.class,0);
		}
		public TerminalNode INSERT() { return getToken(SqlParsingParser.INSERT, 0); }
		public TerminalNode REPLACE() { return getToken(SqlParsingParser.REPLACE, 0); }
		public With_clauseContext with_clause() {
			return getRuleContext(With_clauseContext.class,0);
		}
		public Schema_nameContext schema_name() {
			return getRuleContext(Schema_nameContext.class,0);
		}
		public TerminalNode AS() { return getToken(SqlParsingParser.AS, 0); }
		public Table_aliasContext table_alias() {
			return getRuleContext(Table_aliasContext.class,0);
		}
		public List<Column_nameContext> column_name() {
			return getRuleContexts(Column_nameContext.class);
		}
		public Column_nameContext column_name(int i) {
			return getRuleContext(Column_nameContext.class,i);
		}
		public TerminalNode OR() { return getToken(SqlParsingParser.OR, 0); }
		public Select_stmtContext select_stmt() {
			return getRuleContext(Select_stmtContext.class,0);
		}
		public TerminalNode ROLLBACK() { return getToken(SqlParsingParser.ROLLBACK, 0); }
		public TerminalNode ABORT() { return getToken(SqlParsingParser.ABORT, 0); }
		public TerminalNode FAIL() { return getToken(SqlParsingParser.FAIL, 0); }
		public TerminalNode IGNORE() { return getToken(SqlParsingParser.IGNORE, 0); }
		public Upsert_clauseContext upsert_clause() {
			return getRuleContext(Upsert_clauseContext.class,0);
		}
		public TerminalNode VALUES() { return getToken(SqlParsingParser.VALUES, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode DEFAULT() { return getToken(SqlParsingParser.DEFAULT, 0); }
		public Insert_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_insert_stmt; }
	}

	public final Insert_stmtContext insert_stmt() throws RecognitionException {
		Insert_stmtContext _localctx = new Insert_stmtContext(_ctx, getState());
		enterRule(_localctx, 68, RULE_insert_stmt);
		int _la;
		try {
			setState(1143);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case REPLACE:
			case INSERT:
			case WITH:
				enterOuterAlt(_localctx, 1);
				{
				setState(1074);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WITH) {
					{
					setState(1073);
					with_clause();
					}
				}

				setState(1081);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,135,_ctx) ) {
				case 1:
					{
					setState(1076);
					match(INSERT);
					}
					break;
				case 2:
					{
					setState(1077);
					match(REPLACE);
					}
					break;
				case 3:
					{
					{
					setState(1078);
					match(INSERT);
					setState(1079);
					match(OR);
					setState(1080);
					_la = _input.LA(1);
					if ( !(((((_la - 45)) & ~0x3f) == 0 && ((1L << (_la - 45)) & ((1L << (ROLLBACK - 45)) | (1L << (ABORT - 45)) | (1L << (FAIL - 45)) | (1L << (IGNORE - 45)) | (1L << (REPLACE - 45)))) != 0)) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
					}
					break;
				}
				setState(1083);
				match(INTO);
				setState(1087);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,136,_ctx) ) {
				case 1:
					{
					setState(1084);
					schema_name();
					setState(1085);
					match(T__1);
					}
					break;
				}
				setState(1089);
				table_name();
				setState(1092);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==AS) {
					{
					setState(1090);
					match(AS);
					setState(1091);
					table_alias();
					}
				}

				setState(1105);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==T__2) {
					{
					setState(1094);
					match(T__2);
					setState(1095);
					column_name();
					setState(1100);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==T__3) {
						{
						{
						setState(1096);
						match(T__3);
						setState(1097);
						column_name();
						}
						}
						setState(1102);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					setState(1103);
					match(T__4);
					}
				}

				{
				setState(1136);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,143,_ctx) ) {
				case 1:
					{
					{
					setState(1107);
					match(VALUES);
					setState(1108);
					match(T__2);
					setState(1109);
					expr(0);
					setState(1114);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==T__3) {
						{
						{
						setState(1110);
						match(T__3);
						setState(1111);
						expr(0);
						}
						}
						setState(1116);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					setState(1117);
					match(T__4);
					setState(1132);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==T__3) {
						{
						{
						setState(1118);
						match(T__3);
						setState(1119);
						match(T__2);
						setState(1120);
						expr(0);
						setState(1125);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==T__3) {
							{
							{
							setState(1121);
							match(T__3);
							setState(1122);
							expr(0);
							}
							}
							setState(1127);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						setState(1128);
						match(T__4);
						}
						}
						setState(1134);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
					}
					break;
				case 2:
					{
					setState(1135);
					select_stmt();
					}
					break;
				}
				setState(1139);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ON) {
					{
					setState(1138);
					upsert_clause();
					}
				}

				}
				}
				break;
			case DEFAULT:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(1141);
				match(DEFAULT);
				setState(1142);
				match(VALUES);
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Upsert_clauseContext extends ParserRuleContext {
		public TerminalNode ON() { return getToken(SqlParsingParser.ON, 0); }
		public TerminalNode CONFLICT() { return getToken(SqlParsingParser.CONFLICT, 0); }
		public TerminalNode DO() { return getToken(SqlParsingParser.DO, 0); }
		public TerminalNode NOTHING() { return getToken(SqlParsingParser.NOTHING, 0); }
		public List<Indexed_columnContext> indexed_column() {
			return getRuleContexts(Indexed_columnContext.class);
		}
		public Indexed_columnContext indexed_column(int i) {
			return getRuleContext(Indexed_columnContext.class,i);
		}
		public TerminalNode UPDATE() { return getToken(SqlParsingParser.UPDATE, 0); }
		public TerminalNode SET() { return getToken(SqlParsingParser.SET, 0); }
		public List<TerminalNode> WHERE() { return getTokens(SqlParsingParser.WHERE); }
		public TerminalNode WHERE(int i) {
			return getToken(SqlParsingParser.WHERE, i);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public List<TerminalNode> EQ() { return getTokens(SqlParsingParser.EQ); }
		public TerminalNode EQ(int i) {
			return getToken(SqlParsingParser.EQ, i);
		}
		public List<Column_nameContext> column_name() {
			return getRuleContexts(Column_nameContext.class);
		}
		public Column_nameContext column_name(int i) {
			return getRuleContext(Column_nameContext.class,i);
		}
		public List<Column_name_listContext> column_name_list() {
			return getRuleContexts(Column_name_listContext.class);
		}
		public Column_name_listContext column_name_list(int i) {
			return getRuleContext(Column_name_listContext.class,i);
		}
		public Upsert_clauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_upsert_clause; }
	}

	public final Upsert_clauseContext upsert_clause() throws RecognitionException {
		Upsert_clauseContext _localctx = new Upsert_clauseContext(_ctx, getState());
		enterRule(_localctx, 70, RULE_upsert_clause);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1145);
			match(ON);
			setState(1146);
			match(CONFLICT);
			setState(1161);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__2) {
				{
				setState(1147);
				match(T__2);
				setState(1148);
				indexed_column();
				setState(1153);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(1149);
					match(T__3);
					setState(1150);
					indexed_column();
					}
					}
					setState(1155);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(1156);
				match(T__4);
				setState(1159);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WHERE) {
					{
					setState(1157);
					match(WHERE);
					setState(1158);
					expr(0);
					}
				}

				}
			}

			setState(1163);
			match(DO);
			setState(1190);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NOTHING:
				{
				setState(1164);
				match(NOTHING);
				}
				break;
			case UPDATE:
				{
				{
				setState(1165);
				match(UPDATE);
				setState(1166);
				match(SET);
				{
				setState(1169);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,149,_ctx) ) {
				case 1:
					{
					setState(1167);
					column_name();
					}
					break;
				case 2:
					{
					setState(1168);
					column_name_list();
					}
					break;
				}
				setState(1171);
				match(EQ);
				setState(1172);
				expr(0);
				setState(1183);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(1173);
					match(T__3);
					setState(1176);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,150,_ctx) ) {
					case 1:
						{
						setState(1174);
						column_name();
						}
						break;
					case 2:
						{
						setState(1175);
						column_name_list();
						}
						break;
					}
					setState(1178);
					match(EQ);
					setState(1179);
					expr(0);
					}
					}
					setState(1185);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(1188);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WHERE) {
					{
					setState(1186);
					match(WHERE);
					setState(1187);
					expr(0);
					}
				}

				}
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Pragma_stmtContext extends ParserRuleContext {
		public TerminalNode PRAGMA() { return getToken(SqlParsingParser.PRAGMA, 0); }
		public Pragma_nameContext pragma_name() {
			return getRuleContext(Pragma_nameContext.class,0);
		}
		public Schema_nameContext schema_name() {
			return getRuleContext(Schema_nameContext.class,0);
		}
		public Pragma_valueContext pragma_value() {
			return getRuleContext(Pragma_valueContext.class,0);
		}
		public Pragma_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_pragma_stmt; }
	}

	public final Pragma_stmtContext pragma_stmt() throws RecognitionException {
		Pragma_stmtContext _localctx = new Pragma_stmtContext(_ctx, getState());
		enterRule(_localctx, 72, RULE_pragma_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1192);
			match(PRAGMA);
			setState(1196);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,154,_ctx) ) {
			case 1:
				{
				setState(1193);
				schema_name();
				setState(1194);
				match(T__1);
				}
				break;
			}
			setState(1198);
			pragma_name();
			setState(1205);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__19:
				{
				setState(1199);
				match(T__19);
				setState(1200);
				pragma_value();
				}
				break;
			case T__2:
				{
				setState(1201);
				match(T__2);
				setState(1202);
				pragma_value();
				setState(1203);
				match(T__4);
				}
				break;
			case EOF:
			case T__0:
				break;
			default:
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Pragma_valueContext extends ParserRuleContext {
		public Signed_numberContext signed_number() {
			return getRuleContext(Signed_numberContext.class,0);
		}
		public NameContext name() {
			return getRuleContext(NameContext.class,0);
		}
		public TerminalNode STRING_LITERAL() { return getToken(SqlParsingParser.STRING_LITERAL, 0); }
		public Pragma_valueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_pragma_value; }
	}

	public final Pragma_valueContext pragma_value() throws RecognitionException {
		Pragma_valueContext _localctx = new Pragma_valueContext(_ctx, getState());
		enterRule(_localctx, 74, RULE_pragma_value);
		try {
			setState(1210);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,156,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1207);
				signed_number();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1208);
				name();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(1209);
				match(STRING_LITERAL);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Reindex_stmtContext extends ParserRuleContext {
		public TerminalNode REINDEX() { return getToken(SqlParsingParser.REINDEX, 0); }
		public Collation_nameContext collation_name() {
			return getRuleContext(Collation_nameContext.class,0);
		}
		public Table_nameContext table_name() {
			return getRuleContext(Table_nameContext.class,0);
		}
		public Index_nameContext index_name() {
			return getRuleContext(Index_nameContext.class,0);
		}
		public Schema_nameContext schema_name() {
			return getRuleContext(Schema_nameContext.class,0);
		}
		public Reindex_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_reindex_stmt; }
	}

	public final Reindex_stmtContext reindex_stmt() throws RecognitionException {
		Reindex_stmtContext _localctx = new Reindex_stmtContext(_ctx, getState());
		enterRule(_localctx, 76, RULE_reindex_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1212);
			match(REINDEX);
			setState(1223);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,159,_ctx) ) {
			case 1:
				{
				setState(1213);
				collation_name();
				}
				break;
			case 2:
				{
				{
				setState(1217);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,157,_ctx) ) {
				case 1:
					{
					setState(1214);
					schema_name();
					setState(1215);
					match(T__1);
					}
					break;
				}
				setState(1221);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,158,_ctx) ) {
				case 1:
					{
					setState(1219);
					table_name();
					}
					break;
				case 2:
					{
					setState(1220);
					index_name();
					}
					break;
				}
				}
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Select_stmtContext extends ParserRuleContext {
		public List<Select_coreContext> select_core() {
			return getRuleContexts(Select_coreContext.class);
		}
		public Select_coreContext select_core(int i) {
			return getRuleContext(Select_coreContext.class,i);
		}
		public Common_table_stmtContext common_table_stmt() {
			return getRuleContext(Common_table_stmtContext.class,0);
		}
		public List<Compound_operatorContext> compound_operator() {
			return getRuleContexts(Compound_operatorContext.class);
		}
		public Compound_operatorContext compound_operator(int i) {
			return getRuleContext(Compound_operatorContext.class,i);
		}
		public Order_by_stmtContext order_by_stmt() {
			return getRuleContext(Order_by_stmtContext.class,0);
		}
		public Limit_stmtContext limit_stmt() {
			return getRuleContext(Limit_stmtContext.class,0);
		}
		public Select_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_select_stmt; }
	}

	public final Select_stmtContext select_stmt() throws RecognitionException {
		Select_stmtContext _localctx = new Select_stmtContext(_ctx, getState());
		enterRule(_localctx, 78, RULE_select_stmt);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1226);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WITH) {
				{
				setState(1225);
				common_table_stmt();
				}
			}

			setState(1228);
			select_core();
			setState(1234);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,161,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(1229);
					compound_operator();
					setState(1230);
					select_core();
					}
					} 
				}
				setState(1236);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,161,_ctx);
			}
			setState(1238);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ORDER) {
				{
				setState(1237);
				order_by_stmt();
				}
			}

			setState(1241);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LIMIT) {
				{
				setState(1240);
				limit_stmt();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Join_clauseContext extends ParserRuleContext {
		public List<Table_or_subqueryContext> table_or_subquery() {
			return getRuleContexts(Table_or_subqueryContext.class);
		}
		public Table_or_subqueryContext table_or_subquery(int i) {
			return getRuleContext(Table_or_subqueryContext.class,i);
		}
		public List<Join_operatorContext> join_operator() {
			return getRuleContexts(Join_operatorContext.class);
		}
		public Join_operatorContext join_operator(int i) {
			return getRuleContext(Join_operatorContext.class,i);
		}
		public List<Join_constraintContext> join_constraint() {
			return getRuleContexts(Join_constraintContext.class);
		}
		public Join_constraintContext join_constraint(int i) {
			return getRuleContext(Join_constraintContext.class,i);
		}
		public Join_clauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_join_clause; }
	}

	public final Join_clauseContext join_clause() throws RecognitionException {
		Join_clauseContext _localctx = new Join_clauseContext(_ctx, getState());
		enterRule(_localctx, 80, RULE_join_clause);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1243);
			table_or_subquery();
			setState(1251);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__3 || ((((_la - 149)) & ~0x3f) == 0 && ((1L << (_la - 149)) & ((1L << (NATURAL - 149)) | (1L << (LEFT - 149)) | (1L << (INNER - 149)) | (1L << (CROSS - 149)) | (1L << (JOIN - 149)))) != 0)) {
				{
				{
				setState(1244);
				join_operator();
				setState(1245);
				table_or_subquery();
				setState(1247);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,164,_ctx) ) {
				case 1:
					{
					setState(1246);
					join_constraint();
					}
					break;
				}
				}
				}
				setState(1253);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Select_coreContext extends ParserRuleContext {
		public TerminalNode SELECT() { return getToken(SqlParsingParser.SELECT, 0); }
		public List<Result_columnContext> result_column() {
			return getRuleContexts(Result_columnContext.class);
		}
		public Result_columnContext result_column(int i) {
			return getRuleContext(Result_columnContext.class,i);
		}
		public TerminalNode FROM() { return getToken(SqlParsingParser.FROM, 0); }
		public TerminalNode WHERE() { return getToken(SqlParsingParser.WHERE, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode GROUP() { return getToken(SqlParsingParser.GROUP, 0); }
		public TerminalNode BY() { return getToken(SqlParsingParser.BY, 0); }
		public TerminalNode WINDOW() { return getToken(SqlParsingParser.WINDOW, 0); }
		public List<Window_nameContext> window_name() {
			return getRuleContexts(Window_nameContext.class);
		}
		public Window_nameContext window_name(int i) {
			return getRuleContext(Window_nameContext.class,i);
		}
		public List<TerminalNode> AS() { return getTokens(SqlParsingParser.AS); }
		public TerminalNode AS(int i) {
			return getToken(SqlParsingParser.AS, i);
		}
		public List<Window_defnContext> window_defn() {
			return getRuleContexts(Window_defnContext.class);
		}
		public Window_defnContext window_defn(int i) {
			return getRuleContext(Window_defnContext.class,i);
		}
		public TerminalNode DISTINCT() { return getToken(SqlParsingParser.DISTINCT, 0); }
		public TerminalNode ALL() { return getToken(SqlParsingParser.ALL, 0); }
		public List<Table_or_subqueryContext> table_or_subquery() {
			return getRuleContexts(Table_or_subqueryContext.class);
		}
		public Table_or_subqueryContext table_or_subquery(int i) {
			return getRuleContext(Table_or_subqueryContext.class,i);
		}
		public Join_clauseContext join_clause() {
			return getRuleContext(Join_clauseContext.class,0);
		}
		public TerminalNode HAVING() { return getToken(SqlParsingParser.HAVING, 0); }
		public TerminalNode VALUES() { return getToken(SqlParsingParser.VALUES, 0); }
		public Select_coreContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_select_core; }
	}

	public final Select_coreContext select_core() throws RecognitionException {
		Select_coreContext _localctx = new Select_coreContext(_ctx, getState());
		enterRule(_localctx, 82, RULE_select_core);
		int _la;
		try {
			setState(1344);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case SELECT:
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(1254);
				match(SELECT);
				setState(1256);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,166,_ctx) ) {
				case 1:
					{
					setState(1255);
					_la = _input.LA(1);
					if ( !(_la==ALL || _la==DISTINCT) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
					break;
				}
				setState(1258);
				result_column();
				setState(1263);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(1259);
					match(T__3);
					setState(1260);
					result_column();
					}
					}
					setState(1265);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(1278);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==FROM) {
					{
					setState(1266);
					match(FROM);
					setState(1276);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,169,_ctx) ) {
					case 1:
						{
						setState(1267);
						table_or_subquery();
						setState(1272);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==T__3) {
							{
							{
							setState(1268);
							match(T__3);
							setState(1269);
							table_or_subquery();
							}
							}
							setState(1274);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						}
						break;
					case 2:
						{
						setState(1275);
						join_clause();
						}
						break;
					}
					}
				}

				setState(1282);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WHERE) {
					{
					setState(1280);
					match(WHERE);
					setState(1281);
					expr(0);
					}
				}

				setState(1298);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==GROUP) {
					{
					setState(1284);
					match(GROUP);
					setState(1285);
					match(BY);
					setState(1286);
					expr(0);
					setState(1291);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==T__3) {
						{
						{
						setState(1287);
						match(T__3);
						setState(1288);
						expr(0);
						}
						}
						setState(1293);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					setState(1296);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==HAVING) {
						{
						setState(1294);
						match(HAVING);
						setState(1295);
						expr(0);
						}
					}

					}
				}

				setState(1314);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WINDOW) {
					{
					setState(1300);
					match(WINDOW);
					setState(1301);
					window_name();
					setState(1302);
					match(AS);
					setState(1303);
					window_defn();
					setState(1311);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==T__3) {
						{
						{
						setState(1304);
						match(T__3);
						setState(1305);
						window_name();
						setState(1306);
						match(AS);
						setState(1307);
						window_defn();
						}
						}
						setState(1313);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
				}

				}
				}
				break;
			case VALUES:
				enterOuterAlt(_localctx, 2);
				{
				setState(1316);
				match(VALUES);
				setState(1317);
				match(T__2);
				setState(1318);
				expr(0);
				setState(1323);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(1319);
					match(T__3);
					setState(1320);
					expr(0);
					}
					}
					setState(1325);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(1326);
				match(T__4);
				setState(1341);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(1327);
					match(T__3);
					setState(1328);
					match(T__2);
					setState(1329);
					expr(0);
					setState(1334);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==T__3) {
						{
						{
						setState(1330);
						match(T__3);
						setState(1331);
						expr(0);
						}
						}
						setState(1336);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					setState(1337);
					match(T__4);
					}
					}
					setState(1343);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Factored_select_stmtContext extends ParserRuleContext {
		public Select_stmtContext select_stmt() {
			return getRuleContext(Select_stmtContext.class,0);
		}
		public Factored_select_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_factored_select_stmt; }
	}

	public final Factored_select_stmtContext factored_select_stmt() throws RecognitionException {
		Factored_select_stmtContext _localctx = new Factored_select_stmtContext(_ctx, getState());
		enterRule(_localctx, 84, RULE_factored_select_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1346);
			select_stmt();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Simple_select_stmtContext extends ParserRuleContext {
		public Select_coreContext select_core() {
			return getRuleContext(Select_coreContext.class,0);
		}
		public Common_table_stmtContext common_table_stmt() {
			return getRuleContext(Common_table_stmtContext.class,0);
		}
		public Order_by_stmtContext order_by_stmt() {
			return getRuleContext(Order_by_stmtContext.class,0);
		}
		public Limit_stmtContext limit_stmt() {
			return getRuleContext(Limit_stmtContext.class,0);
		}
		public Simple_select_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_select_stmt; }
	}

	public final Simple_select_stmtContext simple_select_stmt() throws RecognitionException {
		Simple_select_stmtContext _localctx = new Simple_select_stmtContext(_ctx, getState());
		enterRule(_localctx, 86, RULE_simple_select_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1349);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WITH) {
				{
				setState(1348);
				common_table_stmt();
				}
			}

			setState(1351);
			select_core();
			setState(1353);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ORDER) {
				{
				setState(1352);
				order_by_stmt();
				}
			}

			setState(1356);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LIMIT) {
				{
				setState(1355);
				limit_stmt();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Compound_select_stmtContext extends ParserRuleContext {
		public List<Select_coreContext> select_core() {
			return getRuleContexts(Select_coreContext.class);
		}
		public Select_coreContext select_core(int i) {
			return getRuleContext(Select_coreContext.class,i);
		}
		public Common_table_stmtContext common_table_stmt() {
			return getRuleContext(Common_table_stmtContext.class,0);
		}
		public Order_by_stmtContext order_by_stmt() {
			return getRuleContext(Order_by_stmtContext.class,0);
		}
		public Limit_stmtContext limit_stmt() {
			return getRuleContext(Limit_stmtContext.class,0);
		}
		public List<TerminalNode> INTERSECT() { return getTokens(SqlParsingParser.INTERSECT); }
		public TerminalNode INTERSECT(int i) {
			return getToken(SqlParsingParser.INTERSECT, i);
		}
		public List<TerminalNode> EXCEPT() { return getTokens(SqlParsingParser.EXCEPT); }
		public TerminalNode EXCEPT(int i) {
			return getToken(SqlParsingParser.EXCEPT, i);
		}
		public List<TerminalNode> UNION() { return getTokens(SqlParsingParser.UNION); }
		public TerminalNode UNION(int i) {
			return getToken(SqlParsingParser.UNION, i);
		}
		public List<TerminalNode> ALL() { return getTokens(SqlParsingParser.ALL); }
		public TerminalNode ALL(int i) {
			return getToken(SqlParsingParser.ALL, i);
		}
		public Compound_select_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compound_select_stmt; }
	}

	public final Compound_select_stmtContext compound_select_stmt() throws RecognitionException {
		Compound_select_stmtContext _localctx = new Compound_select_stmtContext(_ctx, getState());
		enterRule(_localctx, 88, RULE_compound_select_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1359);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WITH) {
				{
				setState(1358);
				common_table_stmt();
				}
			}

			setState(1361);
			select_core();
			setState(1371); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(1368);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case UNION:
					{
					{
					setState(1362);
					match(UNION);
					setState(1364);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==ALL) {
						{
						setState(1363);
						match(ALL);
						}
					}

					}
					}
					break;
				case INTERSECT:
					{
					setState(1366);
					match(INTERSECT);
					}
					break;
				case EXCEPT:
					{
					setState(1367);
					match(EXCEPT);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(1370);
				select_core();
				}
				}
				setState(1373); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( ((((_la - 104)) & ~0x3f) == 0 && ((1L << (_la - 104)) & ((1L << (UNION - 104)) | (1L << (INTERSECT - 104)) | (1L << (EXCEPT - 104)))) != 0) );
			setState(1376);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ORDER) {
				{
				setState(1375);
				order_by_stmt();
				}
			}

			setState(1379);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LIMIT) {
				{
				setState(1378);
				limit_stmt();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Table_or_subqueryContext extends ParserRuleContext {
		public Table_nameContext table_name() {
			return getRuleContext(Table_nameContext.class,0);
		}
		public Schema_nameContext schema_name() {
			return getRuleContext(Schema_nameContext.class,0);
		}
		public Table_aliasContext table_alias() {
			return getRuleContext(Table_aliasContext.class,0);
		}
		public TerminalNode INDEXED() { return getToken(SqlParsingParser.INDEXED, 0); }
		public TerminalNode BY() { return getToken(SqlParsingParser.BY, 0); }
		public Index_nameContext index_name() {
			return getRuleContext(Index_nameContext.class,0);
		}
		public TerminalNode NOT() { return getToken(SqlParsingParser.NOT, 0); }
		public TerminalNode AS() { return getToken(SqlParsingParser.AS, 0); }
		public Table_function_nameContext table_function_name() {
			return getRuleContext(Table_function_nameContext.class,0);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public List<Table_or_subqueryContext> table_or_subquery() {
			return getRuleContexts(Table_or_subqueryContext.class);
		}
		public Table_or_subqueryContext table_or_subquery(int i) {
			return getRuleContext(Table_or_subqueryContext.class,i);
		}
		public Join_clauseContext join_clause() {
			return getRuleContext(Join_clauseContext.class,0);
		}
		public Select_stmtContext select_stmt() {
			return getRuleContext(Select_stmtContext.class,0);
		}
		public Table_or_subqueryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_table_or_subquery; }
	}

	public final Table_or_subqueryContext table_or_subquery() throws RecognitionException {
		Table_or_subqueryContext _localctx = new Table_or_subqueryContext(_ctx, getState());
		enterRule(_localctx, 90, RULE_table_or_subquery);
		int _la;
		try {
			setState(1445);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,202,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(1384);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,190,_ctx) ) {
				case 1:
					{
					setState(1381);
					schema_name();
					setState(1382);
					match(T__1);
					}
					break;
				}
				setState(1386);
				table_name();
				setState(1391);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,192,_ctx) ) {
				case 1:
					{
					setState(1388);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,191,_ctx) ) {
					case 1:
						{
						setState(1387);
						match(AS);
						}
						break;
					}
					setState(1390);
					table_alias();
					}
					break;
				}
				setState(1398);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case INDEXED:
					{
					{
					setState(1393);
					match(INDEXED);
					setState(1394);
					match(BY);
					setState(1395);
					index_name();
					}
					}
					break;
				case NOT:
					{
					{
					setState(1396);
					match(NOT);
					setState(1397);
					match(INDEXED);
					}
					}
					break;
				case EOF:
				case T__0:
				case T__3:
				case T__4:
				case ON:
				case WHERE:
				case USING:
				case UNION:
				case GROUP:
				case WINDOW:
				case INTERSECT:
				case EXCEPT:
				case NATURAL:
				case LEFT:
				case INNER:
				case CROSS:
				case JOIN:
				case ORDER:
				case LIMIT:
					break;
				default:
					break;
				}
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(1403);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,194,_ctx) ) {
				case 1:
					{
					setState(1400);
					schema_name();
					setState(1401);
					match(T__1);
					}
					break;
				}
				setState(1405);
				table_function_name();
				setState(1406);
				match(T__2);
				setState(1407);
				expr(0);
				setState(1412);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(1408);
					match(T__3);
					setState(1409);
					expr(0);
					}
					}
					setState(1414);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(1415);
				match(T__4);
				setState(1420);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,197,_ctx) ) {
				case 1:
					{
					setState(1417);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,196,_ctx) ) {
					case 1:
						{
						setState(1416);
						match(AS);
						}
						break;
					}
					setState(1419);
					table_alias();
					}
					break;
				}
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(1422);
				match(T__2);
				setState(1432);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,199,_ctx) ) {
				case 1:
					{
					setState(1423);
					table_or_subquery();
					setState(1428);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==T__3) {
						{
						{
						setState(1424);
						match(T__3);
						setState(1425);
						table_or_subquery();
						}
						}
						setState(1430);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
					break;
				case 2:
					{
					setState(1431);
					join_clause();
					}
					break;
				}
				setState(1434);
				match(T__4);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				{
				setState(1436);
				match(T__2);
				setState(1437);
				select_stmt();
				setState(1438);
				match(T__4);
				setState(1443);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,201,_ctx) ) {
				case 1:
					{
					setState(1440);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,200,_ctx) ) {
					case 1:
						{
						setState(1439);
						match(AS);
						}
						break;
					}
					setState(1442);
					table_alias();
					}
					break;
				}
				}
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Result_columnContext extends ParserRuleContext {
		public Table_nameContext table_name() {
			return getRuleContext(Table_nameContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public Column_aliasContext column_alias() {
			return getRuleContext(Column_aliasContext.class,0);
		}
		public TerminalNode AS() { return getToken(SqlParsingParser.AS, 0); }
		public Result_columnContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_result_column; }
	}

	public final Result_columnContext result_column() throws RecognitionException {
		Result_columnContext _localctx = new Result_columnContext(_ctx, getState());
		enterRule(_localctx, 92, RULE_result_column);
		int _la;
		try {
			setState(1459);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,205,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1447);
				match(T__8);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1448);
				table_name();
				setState(1449);
				match(T__1);
				setState(1450);
				match(T__8);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(1452);
				expr(0);
				setState(1457);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==AS || _la==IDENTIFIER || _la==STRING_LITERAL) {
					{
					setState(1454);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==AS) {
						{
						setState(1453);
						match(AS);
						}
					}

					setState(1456);
					column_alias();
					}
				}

				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Join_operatorContext extends ParserRuleContext {
		public TerminalNode JOIN() { return getToken(SqlParsingParser.JOIN, 0); }
		public TerminalNode NATURAL() { return getToken(SqlParsingParser.NATURAL, 0); }
		public TerminalNode INNER() { return getToken(SqlParsingParser.INNER, 0); }
		public TerminalNode CROSS() { return getToken(SqlParsingParser.CROSS, 0); }
		public TerminalNode LEFT() { return getToken(SqlParsingParser.LEFT, 0); }
		public TerminalNode OUTER() { return getToken(SqlParsingParser.OUTER, 0); }
		public Join_operatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_join_operator; }
	}

	public final Join_operatorContext join_operator() throws RecognitionException {
		Join_operatorContext _localctx = new Join_operatorContext(_ctx, getState());
		enterRule(_localctx, 94, RULE_join_operator);
		int _la;
		try {
			setState(1474);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__3:
				enterOuterAlt(_localctx, 1);
				{
				setState(1461);
				match(T__3);
				}
				break;
			case NATURAL:
			case LEFT:
			case INNER:
			case CROSS:
			case JOIN:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(1463);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==NATURAL) {
					{
					setState(1462);
					match(NATURAL);
					}
				}

				setState(1471);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case LEFT:
					{
					{
					setState(1465);
					match(LEFT);
					setState(1467);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==OUTER) {
						{
						setState(1466);
						match(OUTER);
						}
					}

					}
					}
					break;
				case INNER:
					{
					setState(1469);
					match(INNER);
					}
					break;
				case CROSS:
					{
					setState(1470);
					match(CROSS);
					}
					break;
				case JOIN:
					break;
				default:
					break;
				}
				setState(1473);
				match(JOIN);
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Join_constraintContext extends ParserRuleContext {
		public TerminalNode ON() { return getToken(SqlParsingParser.ON, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode USING() { return getToken(SqlParsingParser.USING, 0); }
		public List<Column_nameContext> column_name() {
			return getRuleContexts(Column_nameContext.class);
		}
		public Column_nameContext column_name(int i) {
			return getRuleContext(Column_nameContext.class,i);
		}
		public Join_constraintContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_join_constraint; }
	}

	public final Join_constraintContext join_constraint() throws RecognitionException {
		Join_constraintContext _localctx = new Join_constraintContext(_ctx, getState());
		enterRule(_localctx, 96, RULE_join_constraint);
		int _la;
		try {
			setState(1490);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ON:
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(1476);
				match(ON);
				setState(1477);
				expr(0);
				}
				}
				break;
			case USING:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(1478);
				match(USING);
				setState(1479);
				match(T__2);
				setState(1480);
				column_name();
				setState(1485);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(1481);
					match(T__3);
					setState(1482);
					column_name();
					}
					}
					setState(1487);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(1488);
				match(T__4);
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Compound_operatorContext extends ParserRuleContext {
		public TerminalNode UNION() { return getToken(SqlParsingParser.UNION, 0); }
		public TerminalNode ALL() { return getToken(SqlParsingParser.ALL, 0); }
		public TerminalNode INTERSECT() { return getToken(SqlParsingParser.INTERSECT, 0); }
		public TerminalNode EXCEPT() { return getToken(SqlParsingParser.EXCEPT, 0); }
		public Compound_operatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compound_operator; }
	}

	public final Compound_operatorContext compound_operator() throws RecognitionException {
		Compound_operatorContext _localctx = new Compound_operatorContext(_ctx, getState());
		enterRule(_localctx, 98, RULE_compound_operator);
		int _la;
		try {
			setState(1498);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case UNION:
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(1492);
				match(UNION);
				setState(1494);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ALL) {
					{
					setState(1493);
					match(ALL);
					}
				}

				}
				}
				break;
			case INTERSECT:
				enterOuterAlt(_localctx, 2);
				{
				setState(1496);
				match(INTERSECT);
				}
				break;
			case EXCEPT:
				enterOuterAlt(_localctx, 3);
				{
				setState(1497);
				match(EXCEPT);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Update_stmtContext extends ParserRuleContext {
		public TerminalNode UPDATE() { return getToken(SqlParsingParser.UPDATE, 0); }
		public Qualified_table_nameContext qualified_table_name() {
			return getRuleContext(Qualified_table_nameContext.class,0);
		}
		public TerminalNode SET() { return getToken(SqlParsingParser.SET, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public List<Column_nameContext> column_name() {
			return getRuleContexts(Column_nameContext.class);
		}
		public Column_nameContext column_name(int i) {
			return getRuleContext(Column_nameContext.class,i);
		}
		public List<Column_name_listContext> column_name_list() {
			return getRuleContexts(Column_name_listContext.class);
		}
		public Column_name_listContext column_name_list(int i) {
			return getRuleContext(Column_name_listContext.class,i);
		}
		public With_clauseContext with_clause() {
			return getRuleContext(With_clauseContext.class,0);
		}
		public TerminalNode OR() { return getToken(SqlParsingParser.OR, 0); }
		public TerminalNode WHERE() { return getToken(SqlParsingParser.WHERE, 0); }
		public TerminalNode ROLLBACK() { return getToken(SqlParsingParser.ROLLBACK, 0); }
		public TerminalNode ABORT() { return getToken(SqlParsingParser.ABORT, 0); }
		public TerminalNode REPLACE() { return getToken(SqlParsingParser.REPLACE, 0); }
		public TerminalNode FAIL() { return getToken(SqlParsingParser.FAIL, 0); }
		public TerminalNode IGNORE() { return getToken(SqlParsingParser.IGNORE, 0); }
		public Update_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_update_stmt; }
	}

	public final Update_stmtContext update_stmt() throws RecognitionException {
		Update_stmtContext _localctx = new Update_stmtContext(_ctx, getState());
		enterRule(_localctx, 100, RULE_update_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1501);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WITH) {
				{
				setState(1500);
				with_clause();
				}
			}

			setState(1503);
			match(UPDATE);
			setState(1506);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,215,_ctx) ) {
			case 1:
				{
				setState(1504);
				match(OR);
				setState(1505);
				_la = _input.LA(1);
				if ( !(((((_la - 45)) & ~0x3f) == 0 && ((1L << (_la - 45)) & ((1L << (ROLLBACK - 45)) | (1L << (ABORT - 45)) | (1L << (FAIL - 45)) | (1L << (IGNORE - 45)) | (1L << (REPLACE - 45)))) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
				break;
			}
			setState(1508);
			qualified_table_name();
			setState(1509);
			match(SET);
			setState(1512);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,216,_ctx) ) {
			case 1:
				{
				setState(1510);
				column_name();
				}
				break;
			case 2:
				{
				setState(1511);
				column_name_list();
				}
				break;
			}
			setState(1514);
			match(T__19);
			setState(1515);
			expr(0);
			setState(1526);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__3) {
				{
				{
				setState(1516);
				match(T__3);
				setState(1519);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,217,_ctx) ) {
				case 1:
					{
					setState(1517);
					column_name();
					}
					break;
				case 2:
					{
					setState(1518);
					column_name_list();
					}
					break;
				}
				setState(1521);
				match(T__19);
				setState(1522);
				expr(0);
				}
				}
				setState(1528);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(1531);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WHERE) {
				{
				setState(1529);
				match(WHERE);
				setState(1530);
				expr(0);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Column_name_listContext extends ParserRuleContext {
		public List<Column_nameContext> column_name() {
			return getRuleContexts(Column_nameContext.class);
		}
		public Column_nameContext column_name(int i) {
			return getRuleContext(Column_nameContext.class,i);
		}
		public Column_name_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_column_name_list; }
	}

	public final Column_name_listContext column_name_list() throws RecognitionException {
		Column_name_listContext _localctx = new Column_name_listContext(_ctx, getState());
		enterRule(_localctx, 102, RULE_column_name_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1533);
			match(T__2);
			setState(1534);
			column_name();
			setState(1539);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__3) {
				{
				{
				setState(1535);
				match(T__3);
				setState(1536);
				column_name();
				}
				}
				setState(1541);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(1542);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Update_stmt_limitedContext extends ParserRuleContext {
		public TerminalNode UPDATE() { return getToken(SqlParsingParser.UPDATE, 0); }
		public Qualified_table_nameContext qualified_table_name() {
			return getRuleContext(Qualified_table_nameContext.class,0);
		}
		public TerminalNode SET() { return getToken(SqlParsingParser.SET, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public List<Column_nameContext> column_name() {
			return getRuleContexts(Column_nameContext.class);
		}
		public Column_nameContext column_name(int i) {
			return getRuleContext(Column_nameContext.class,i);
		}
		public List<Column_name_listContext> column_name_list() {
			return getRuleContexts(Column_name_listContext.class);
		}
		public Column_name_listContext column_name_list(int i) {
			return getRuleContext(Column_name_listContext.class,i);
		}
		public With_clauseContext with_clause() {
			return getRuleContext(With_clauseContext.class,0);
		}
		public TerminalNode OR() { return getToken(SqlParsingParser.OR, 0); }
		public TerminalNode WHERE() { return getToken(SqlParsingParser.WHERE, 0); }
		public Limit_stmtContext limit_stmt() {
			return getRuleContext(Limit_stmtContext.class,0);
		}
		public TerminalNode ROLLBACK() { return getToken(SqlParsingParser.ROLLBACK, 0); }
		public TerminalNode ABORT() { return getToken(SqlParsingParser.ABORT, 0); }
		public TerminalNode REPLACE() { return getToken(SqlParsingParser.REPLACE, 0); }
		public TerminalNode FAIL() { return getToken(SqlParsingParser.FAIL, 0); }
		public TerminalNode IGNORE() { return getToken(SqlParsingParser.IGNORE, 0); }
		public Order_by_stmtContext order_by_stmt() {
			return getRuleContext(Order_by_stmtContext.class,0);
		}
		public Update_stmt_limitedContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_update_stmt_limited; }
	}

	public final Update_stmt_limitedContext update_stmt_limited() throws RecognitionException {
		Update_stmt_limitedContext _localctx = new Update_stmt_limitedContext(_ctx, getState());
		enterRule(_localctx, 104, RULE_update_stmt_limited);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1545);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WITH) {
				{
				setState(1544);
				with_clause();
				}
			}

			setState(1547);
			match(UPDATE);
			setState(1550);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,222,_ctx) ) {
			case 1:
				{
				setState(1548);
				match(OR);
				setState(1549);
				_la = _input.LA(1);
				if ( !(((((_la - 45)) & ~0x3f) == 0 && ((1L << (_la - 45)) & ((1L << (ROLLBACK - 45)) | (1L << (ABORT - 45)) | (1L << (FAIL - 45)) | (1L << (IGNORE - 45)) | (1L << (REPLACE - 45)))) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
				break;
			}
			setState(1552);
			qualified_table_name();
			setState(1553);
			match(SET);
			setState(1556);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,223,_ctx) ) {
			case 1:
				{
				setState(1554);
				column_name();
				}
				break;
			case 2:
				{
				setState(1555);
				column_name_list();
				}
				break;
			}
			setState(1558);
			match(T__19);
			setState(1559);
			expr(0);
			setState(1570);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__3) {
				{
				{
				setState(1560);
				match(T__3);
				setState(1563);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,224,_ctx) ) {
				case 1:
					{
					setState(1561);
					column_name();
					}
					break;
				case 2:
					{
					setState(1562);
					column_name_list();
					}
					break;
				}
				setState(1565);
				match(T__19);
				setState(1566);
				expr(0);
				}
				}
				setState(1572);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(1575);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WHERE) {
				{
				setState(1573);
				match(WHERE);
				setState(1574);
				expr(0);
				}
			}

			setState(1581);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ORDER || _la==LIMIT) {
				{
				setState(1578);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ORDER) {
					{
					setState(1577);
					order_by_stmt();
					}
				}

				setState(1580);
				limit_stmt();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Qualified_table_nameContext extends ParserRuleContext {
		public Table_nameContext table_name() {
			return getRuleContext(Table_nameContext.class,0);
		}
		public Schema_nameContext schema_name() {
			return getRuleContext(Schema_nameContext.class,0);
		}
		public TerminalNode AS() { return getToken(SqlParsingParser.AS, 0); }
		public AliasContext alias() {
			return getRuleContext(AliasContext.class,0);
		}
		public TerminalNode INDEXED() { return getToken(SqlParsingParser.INDEXED, 0); }
		public TerminalNode BY() { return getToken(SqlParsingParser.BY, 0); }
		public Index_nameContext index_name() {
			return getRuleContext(Index_nameContext.class,0);
		}
		public TerminalNode NOT() { return getToken(SqlParsingParser.NOT, 0); }
		public Qualified_table_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_qualified_table_name; }
	}

	public final Qualified_table_nameContext qualified_table_name() throws RecognitionException {
		Qualified_table_nameContext _localctx = new Qualified_table_nameContext(_ctx, getState());
		enterRule(_localctx, 106, RULE_qualified_table_name);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1586);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,229,_ctx) ) {
			case 1:
				{
				setState(1583);
				schema_name();
				setState(1584);
				match(T__1);
				}
				break;
			}
			setState(1588);
			table_name();
			setState(1591);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==AS) {
				{
				setState(1589);
				match(AS);
				setState(1590);
				alias();
				}
			}

			setState(1598);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INDEXED:
				{
				{
				setState(1593);
				match(INDEXED);
				setState(1594);
				match(BY);
				setState(1595);
				index_name();
				}
				}
				break;
			case NOT:
				{
				{
				setState(1596);
				match(NOT);
				setState(1597);
				match(INDEXED);
				}
				}
				break;
			case EOF:
			case T__0:
			case WHERE:
			case SET:
			case ORDER:
			case LIMIT:
				break;
			default:
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Vacuum_stmtContext extends ParserRuleContext {
		public TerminalNode VACUUM() { return getToken(SqlParsingParser.VACUUM, 0); }
		public Schema_nameContext schema_name() {
			return getRuleContext(Schema_nameContext.class,0);
		}
		public TerminalNode INTO() { return getToken(SqlParsingParser.INTO, 0); }
		public FilenameContext filename() {
			return getRuleContext(FilenameContext.class,0);
		}
		public Vacuum_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vacuum_stmt; }
	}

	public final Vacuum_stmtContext vacuum_stmt() throws RecognitionException {
		Vacuum_stmtContext _localctx = new Vacuum_stmtContext(_ctx, getState());
		enterRule(_localctx, 108, RULE_vacuum_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1600);
			match(VACUUM);
			setState(1602);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,232,_ctx) ) {
			case 1:
				{
				setState(1601);
				schema_name();
				}
				break;
			}
			setState(1606);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==INTO) {
				{
				setState(1604);
				match(INTO);
				setState(1605);
				filename();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Filter_clauseContext extends ParserRuleContext {
		public TerminalNode FILTER() { return getToken(SqlParsingParser.FILTER, 0); }
		public TerminalNode WHERE() { return getToken(SqlParsingParser.WHERE, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public Filter_clauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_filter_clause; }
	}

	public final Filter_clauseContext filter_clause() throws RecognitionException {
		Filter_clauseContext _localctx = new Filter_clauseContext(_ctx, getState());
		enterRule(_localctx, 110, RULE_filter_clause);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1608);
			match(FILTER);
			setState(1609);
			match(T__2);
			setState(1610);
			match(WHERE);
			setState(1611);
			expr(0);
			setState(1612);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Window_defnContext extends ParserRuleContext {
		public TerminalNode ORDER() { return getToken(SqlParsingParser.ORDER, 0); }
		public List<TerminalNode> BY() { return getTokens(SqlParsingParser.BY); }
		public TerminalNode BY(int i) {
			return getToken(SqlParsingParser.BY, i);
		}
		public List<Ordering_termContext> ordering_term() {
			return getRuleContexts(Ordering_termContext.class);
		}
		public Ordering_termContext ordering_term(int i) {
			return getRuleContext(Ordering_termContext.class,i);
		}
		public Base_window_nameContext base_window_name() {
			return getRuleContext(Base_window_nameContext.class,0);
		}
		public TerminalNode PARTITION() { return getToken(SqlParsingParser.PARTITION, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public Frame_specContext frame_spec() {
			return getRuleContext(Frame_specContext.class,0);
		}
		public Window_defnContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_window_defn; }
	}

	public final Window_defnContext window_defn() throws RecognitionException {
		Window_defnContext _localctx = new Window_defnContext(_ctx, getState());
		enterRule(_localctx, 112, RULE_window_defn);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1614);
			match(T__2);
			setState(1616);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,234,_ctx) ) {
			case 1:
				{
				setState(1615);
				base_window_name();
				}
				break;
			}
			setState(1628);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==PARTITION) {
				{
				setState(1618);
				match(PARTITION);
				setState(1619);
				match(BY);
				setState(1620);
				expr(0);
				setState(1625);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(1621);
					match(T__3);
					setState(1622);
					expr(0);
					}
					}
					setState(1627);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			{
			setState(1630);
			match(ORDER);
			setState(1631);
			match(BY);
			setState(1632);
			ordering_term();
			setState(1637);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__3) {
				{
				{
				setState(1633);
				match(T__3);
				setState(1634);
				ordering_term();
				}
				}
				setState(1639);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
			setState(1641);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 164)) & ~0x3f) == 0 && ((1L << (_la - 164)) & ((1L << (RANGE - 164)) | (1L << (ROWS - 164)) | (1L << (GROUPS - 164)))) != 0)) {
				{
				setState(1640);
				frame_spec();
				}
			}

			setState(1643);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Over_clauseContext extends ParserRuleContext {
		public TerminalNode OVER() { return getToken(SqlParsingParser.OVER, 0); }
		public Window_nameContext window_name() {
			return getRuleContext(Window_nameContext.class,0);
		}
		public Base_window_nameContext base_window_name() {
			return getRuleContext(Base_window_nameContext.class,0);
		}
		public TerminalNode PARTITION() { return getToken(SqlParsingParser.PARTITION, 0); }
		public List<TerminalNode> BY() { return getTokens(SqlParsingParser.BY); }
		public TerminalNode BY(int i) {
			return getToken(SqlParsingParser.BY, i);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode ORDER() { return getToken(SqlParsingParser.ORDER, 0); }
		public List<Ordering_termContext> ordering_term() {
			return getRuleContexts(Ordering_termContext.class);
		}
		public Ordering_termContext ordering_term(int i) {
			return getRuleContext(Ordering_termContext.class,i);
		}
		public Frame_specContext frame_spec() {
			return getRuleContext(Frame_specContext.class,0);
		}
		public Over_clauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_over_clause; }
	}

	public final Over_clauseContext over_clause() throws RecognitionException {
		Over_clauseContext _localctx = new Over_clauseContext(_ctx, getState());
		enterRule(_localctx, 114, RULE_over_clause);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1645);
			match(OVER);
			setState(1679);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,245,_ctx) ) {
			case 1:
				{
				setState(1646);
				window_name();
				}
				break;
			case 2:
				{
				{
				setState(1647);
				match(T__2);
				setState(1649);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,239,_ctx) ) {
				case 1:
					{
					setState(1648);
					base_window_name();
					}
					break;
				}
				setState(1661);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==PARTITION) {
					{
					setState(1651);
					match(PARTITION);
					setState(1652);
					match(BY);
					setState(1653);
					expr(0);
					setState(1658);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==T__3) {
						{
						{
						setState(1654);
						match(T__3);
						setState(1655);
						expr(0);
						}
						}
						setState(1660);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
				}

				setState(1673);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ORDER) {
					{
					setState(1663);
					match(ORDER);
					setState(1664);
					match(BY);
					setState(1665);
					ordering_term();
					setState(1670);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==T__3) {
						{
						{
						setState(1666);
						match(T__3);
						setState(1667);
						ordering_term();
						}
						}
						setState(1672);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
				}

				setState(1676);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (((((_la - 164)) & ~0x3f) == 0 && ((1L << (_la - 164)) & ((1L << (RANGE - 164)) | (1L << (ROWS - 164)) | (1L << (GROUPS - 164)))) != 0)) {
					{
					setState(1675);
					frame_spec();
					}
				}

				setState(1678);
				match(T__4);
				}
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Frame_specContext extends ParserRuleContext {
		public Frame_clauseContext frame_clause() {
			return getRuleContext(Frame_clauseContext.class,0);
		}
		public TerminalNode EXCLUDE() { return getToken(SqlParsingParser.EXCLUDE, 0); }
		public TerminalNode GROUP() { return getToken(SqlParsingParser.GROUP, 0); }
		public TerminalNode TIES() { return getToken(SqlParsingParser.TIES, 0); }
		public TerminalNode NO() { return getToken(SqlParsingParser.NO, 0); }
		public TerminalNode OTHERS() { return getToken(SqlParsingParser.OTHERS, 0); }
		public TerminalNode CURRENT() { return getToken(SqlParsingParser.CURRENT, 0); }
		public TerminalNode ROW() { return getToken(SqlParsingParser.ROW, 0); }
		public Frame_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_frame_spec; }
	}

	public final Frame_specContext frame_spec() throws RecognitionException {
		Frame_specContext _localctx = new Frame_specContext(_ctx, getState());
		enterRule(_localctx, 116, RULE_frame_spec);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1681);
			frame_clause();
			setState(1689);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case EXCLUDE:
				{
				setState(1682);
				match(EXCLUDE);
				{
				setState(1683);
				match(NO);
				setState(1684);
				match(OTHERS);
				}
				}
				break;
			case CURRENT:
				{
				{
				setState(1685);
				match(CURRENT);
				setState(1686);
				match(ROW);
				}
				}
				break;
			case GROUP:
				{
				setState(1687);
				match(GROUP);
				}
				break;
			case TIES:
				{
				setState(1688);
				match(TIES);
				}
				break;
			case T__4:
				break;
			default:
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Frame_clauseContext extends ParserRuleContext {
		public TerminalNode RANGE() { return getToken(SqlParsingParser.RANGE, 0); }
		public TerminalNode ROWS() { return getToken(SqlParsingParser.ROWS, 0); }
		public TerminalNode GROUPS() { return getToken(SqlParsingParser.GROUPS, 0); }
		public Frame_singleContext frame_single() {
			return getRuleContext(Frame_singleContext.class,0);
		}
		public TerminalNode BETWEEN() { return getToken(SqlParsingParser.BETWEEN, 0); }
		public Frame_leftContext frame_left() {
			return getRuleContext(Frame_leftContext.class,0);
		}
		public TerminalNode AND() { return getToken(SqlParsingParser.AND, 0); }
		public Frame_rightContext frame_right() {
			return getRuleContext(Frame_rightContext.class,0);
		}
		public Frame_clauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_frame_clause; }
	}

	public final Frame_clauseContext frame_clause() throws RecognitionException {
		Frame_clauseContext _localctx = new Frame_clauseContext(_ctx, getState());
		enterRule(_localctx, 118, RULE_frame_clause);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1691);
			_la = _input.LA(1);
			if ( !(((((_la - 164)) & ~0x3f) == 0 && ((1L << (_la - 164)) & ((1L << (RANGE - 164)) | (1L << (ROWS - 164)) | (1L << (GROUPS - 164)))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			setState(1698);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,247,_ctx) ) {
			case 1:
				{
				setState(1692);
				frame_single();
				}
				break;
			case 2:
				{
				setState(1693);
				match(BETWEEN);
				setState(1694);
				frame_left();
				setState(1695);
				match(AND);
				setState(1696);
				frame_right();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Simple_function_invocationContext extends ParserRuleContext {
		public Simple_funcContext simple_func() {
			return getRuleContext(Simple_funcContext.class,0);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public Simple_function_invocationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_function_invocation; }
	}

	public final Simple_function_invocationContext simple_function_invocation() throws RecognitionException {
		Simple_function_invocationContext _localctx = new Simple_function_invocationContext(_ctx, getState());
		enterRule(_localctx, 120, RULE_simple_function_invocation);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1700);
			simple_func();
			setState(1701);
			match(T__2);
			setState(1711);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__2:
			case T__5:
			case T__6:
			case T__23:
			case EXPLAIN:
			case QUERY:
			case PLAN:
			case ALTER:
			case TABLE:
			case RENAME:
			case TO:
			case COLUMN:
			case ADD:
			case ANALYZE:
			case ATTACH:
			case DATABASE:
			case AS:
			case BEGIN:
			case DEFERRED:
			case IMMEDIATE:
			case EXCLUSIVE:
			case TRANSACTION:
			case COMMIT:
			case END:
			case ROLLBACK:
			case SAVEPOINT:
			case RELEASE:
			case CREATE:
			case UNIQUE:
			case INDEX:
			case IF:
			case NOT:
			case EXISTS:
			case ON:
			case WHERE:
			case COLLATE:
			case TEMP:
			case TEMPORARY:
			case WITHOUT:
			case IDENTIFIER:
			case CONSTRAINT:
			case PRIMARY:
			case KEY:
			case AUTOINCREMENT:
			case NULL_:
			case CHECK:
			case DEFAULT:
			case GENERATED:
			case ALWAYS:
			case STORED:
			case VIRTUAL:
			case NUMERIC_LITERAL:
			case FOREIGN:
			case REFERENCES:
			case DELETE:
			case UPDATE:
			case SET:
			case CASCADE:
			case RESTRICT:
			case NO:
			case ACTION:
			case MATCH:
			case DEFERRABLE:
			case INITIALLY:
			case CONFLICT:
			case ABORT:
			case FAIL:
			case IGNORE:
			case REPLACE:
			case TRIGGER:
			case BEFORE:
			case AFTER:
			case INSTEAD:
			case OF:
			case INSERT:
			case FOR:
			case EACH:
			case ROW:
			case WHEN:
			case VIEW:
			case USING:
			case WITH:
			case RECURSIVE:
			case UNION:
			case ALL:
			case FROM:
			case DETACH:
			case DROP:
			case BIND_PARAMETER:
			case DISTINCT:
			case CAST:
			case CASE:
			case THEN:
			case ELSE:
			case IS:
			case IN:
			case LIKE:
			case GLOB:
			case REGEXP:
			case AND:
			case OR:
			case BETWEEN:
			case ESCAPE:
			case ISNULL:
			case NOTNULL:
			case RAISE:
			case STRING_LITERAL:
			case BLOB_LITERAL:
			case TRUE_:
			case FALSE_:
			case CURRENT_TIME:
			case CURRENT_DATE:
			case CURRENT_TIMESTAMP:
			case INTO:
			case VALUES:
			case PRAGMA:
			case REINDEX:
			case SELECT:
			case GROUP:
			case BY:
			case HAVING:
			case WINDOW:
			case INTERSECT:
			case EXCEPT:
			case INDEXED:
			case NATURAL:
			case LEFT:
			case OUTER:
			case INNER:
			case CROSS:
			case JOIN:
			case VACUUM:
			case FILTER:
			case PARTITION:
			case ORDER:
			case OVER:
			case EXCLUDE:
			case CURRENT:
			case RANGE:
			case ROWS:
			case GROUPS:
			case LIMIT:
			case OFFSET:
			case NULLS:
			case FIRST:
			case LAST:
			case ASC:
			case DESC:
			case PRECEDING:
			case FOLLOWING:
			case UNBOUNDED:
			case FIRST_VALUE:
			case LAST_VALUE:
			case CUME_DIST:
			case PERCENT_RANK:
			case DENSE_RANK:
			case RANK:
			case ROW_NUMBER:
			case LAG:
			case LEAD:
			case NTH_VALUE:
			case NTILE:
			case FULL:
			case RIGHT:
				{
				{
				setState(1702);
				expr(0);
				setState(1707);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(1703);
					match(T__3);
					setState(1704);
					expr(0);
					}
					}
					setState(1709);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				}
				break;
			case T__8:
				{
				setState(1710);
				match(T__8);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(1713);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Aggregate_function_invocationContext extends ParserRuleContext {
		public Aggregate_funcContext aggregate_func() {
			return getRuleContext(Aggregate_funcContext.class,0);
		}
		public Filter_clauseContext filter_clause() {
			return getRuleContext(Filter_clauseContext.class,0);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode DISTINCT() { return getToken(SqlParsingParser.DISTINCT, 0); }
		public Aggregate_function_invocationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_aggregate_function_invocation; }
	}

	public final Aggregate_function_invocationContext aggregate_function_invocation() throws RecognitionException {
		Aggregate_function_invocationContext _localctx = new Aggregate_function_invocationContext(_ctx, getState());
		enterRule(_localctx, 122, RULE_aggregate_function_invocation);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1715);
			aggregate_func();
			setState(1716);
			match(T__2);
			setState(1729);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__2:
			case T__5:
			case T__6:
			case T__23:
			case EXPLAIN:
			case QUERY:
			case PLAN:
			case ALTER:
			case TABLE:
			case RENAME:
			case TO:
			case COLUMN:
			case ADD:
			case ANALYZE:
			case ATTACH:
			case DATABASE:
			case AS:
			case BEGIN:
			case DEFERRED:
			case IMMEDIATE:
			case EXCLUSIVE:
			case TRANSACTION:
			case COMMIT:
			case END:
			case ROLLBACK:
			case SAVEPOINT:
			case RELEASE:
			case CREATE:
			case UNIQUE:
			case INDEX:
			case IF:
			case NOT:
			case EXISTS:
			case ON:
			case WHERE:
			case COLLATE:
			case TEMP:
			case TEMPORARY:
			case WITHOUT:
			case IDENTIFIER:
			case CONSTRAINT:
			case PRIMARY:
			case KEY:
			case AUTOINCREMENT:
			case NULL_:
			case CHECK:
			case DEFAULT:
			case GENERATED:
			case ALWAYS:
			case STORED:
			case VIRTUAL:
			case NUMERIC_LITERAL:
			case FOREIGN:
			case REFERENCES:
			case DELETE:
			case UPDATE:
			case SET:
			case CASCADE:
			case RESTRICT:
			case NO:
			case ACTION:
			case MATCH:
			case DEFERRABLE:
			case INITIALLY:
			case CONFLICT:
			case ABORT:
			case FAIL:
			case IGNORE:
			case REPLACE:
			case TRIGGER:
			case BEFORE:
			case AFTER:
			case INSTEAD:
			case OF:
			case INSERT:
			case FOR:
			case EACH:
			case ROW:
			case WHEN:
			case VIEW:
			case USING:
			case WITH:
			case RECURSIVE:
			case UNION:
			case ALL:
			case FROM:
			case DETACH:
			case DROP:
			case BIND_PARAMETER:
			case DISTINCT:
			case CAST:
			case CASE:
			case THEN:
			case ELSE:
			case IS:
			case IN:
			case LIKE:
			case GLOB:
			case REGEXP:
			case AND:
			case OR:
			case BETWEEN:
			case ESCAPE:
			case ISNULL:
			case NOTNULL:
			case RAISE:
			case STRING_LITERAL:
			case BLOB_LITERAL:
			case TRUE_:
			case FALSE_:
			case CURRENT_TIME:
			case CURRENT_DATE:
			case CURRENT_TIMESTAMP:
			case INTO:
			case VALUES:
			case PRAGMA:
			case REINDEX:
			case SELECT:
			case GROUP:
			case BY:
			case HAVING:
			case WINDOW:
			case INTERSECT:
			case EXCEPT:
			case INDEXED:
			case NATURAL:
			case LEFT:
			case OUTER:
			case INNER:
			case CROSS:
			case JOIN:
			case VACUUM:
			case FILTER:
			case PARTITION:
			case ORDER:
			case OVER:
			case EXCLUDE:
			case CURRENT:
			case RANGE:
			case ROWS:
			case GROUPS:
			case LIMIT:
			case OFFSET:
			case NULLS:
			case FIRST:
			case LAST:
			case ASC:
			case DESC:
			case PRECEDING:
			case FOLLOWING:
			case UNBOUNDED:
			case FIRST_VALUE:
			case LAST_VALUE:
			case CUME_DIST:
			case PERCENT_RANK:
			case DENSE_RANK:
			case RANK:
			case ROW_NUMBER:
			case LAG:
			case LEAD:
			case NTH_VALUE:
			case NTILE:
			case FULL:
			case RIGHT:
				{
				{
				setState(1718);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,250,_ctx) ) {
				case 1:
					{
					setState(1717);
					match(DISTINCT);
					}
					break;
				}
				setState(1720);
				expr(0);
				setState(1725);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(1721);
					match(T__3);
					setState(1722);
					expr(0);
					}
					}
					setState(1727);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				}
				break;
			case T__8:
				{
				setState(1728);
				match(T__8);
				}
				break;
			case T__4:
				break;
			default:
				break;
			}
			setState(1731);
			match(T__4);
			setState(1733);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==FILTER) {
				{
				setState(1732);
				filter_clause();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Window_function_invocationContext extends ParserRuleContext {
		public Window_functionContext window_function() {
			return getRuleContext(Window_functionContext.class,0);
		}
		public TerminalNode OVER() { return getToken(SqlParsingParser.OVER, 0); }
		public Window_defnContext window_defn() {
			return getRuleContext(Window_defnContext.class,0);
		}
		public Window_nameContext window_name() {
			return getRuleContext(Window_nameContext.class,0);
		}
		public Filter_clauseContext filter_clause() {
			return getRuleContext(Filter_clauseContext.class,0);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public Window_function_invocationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_window_function_invocation; }
	}

	public final Window_function_invocationContext window_function_invocation() throws RecognitionException {
		Window_function_invocationContext _localctx = new Window_function_invocationContext(_ctx, getState());
		enterRule(_localctx, 124, RULE_window_function_invocation);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1735);
			window_function();
			setState(1736);
			match(T__2);
			setState(1746);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__2:
			case T__5:
			case T__6:
			case T__23:
			case EXPLAIN:
			case QUERY:
			case PLAN:
			case ALTER:
			case TABLE:
			case RENAME:
			case TO:
			case COLUMN:
			case ADD:
			case ANALYZE:
			case ATTACH:
			case DATABASE:
			case AS:
			case BEGIN:
			case DEFERRED:
			case IMMEDIATE:
			case EXCLUSIVE:
			case TRANSACTION:
			case COMMIT:
			case END:
			case ROLLBACK:
			case SAVEPOINT:
			case RELEASE:
			case CREATE:
			case UNIQUE:
			case INDEX:
			case IF:
			case NOT:
			case EXISTS:
			case ON:
			case WHERE:
			case COLLATE:
			case TEMP:
			case TEMPORARY:
			case WITHOUT:
			case IDENTIFIER:
			case CONSTRAINT:
			case PRIMARY:
			case KEY:
			case AUTOINCREMENT:
			case NULL_:
			case CHECK:
			case DEFAULT:
			case GENERATED:
			case ALWAYS:
			case STORED:
			case VIRTUAL:
			case NUMERIC_LITERAL:
			case FOREIGN:
			case REFERENCES:
			case DELETE:
			case UPDATE:
			case SET:
			case CASCADE:
			case RESTRICT:
			case NO:
			case ACTION:
			case MATCH:
			case DEFERRABLE:
			case INITIALLY:
			case CONFLICT:
			case ABORT:
			case FAIL:
			case IGNORE:
			case REPLACE:
			case TRIGGER:
			case BEFORE:
			case AFTER:
			case INSTEAD:
			case OF:
			case INSERT:
			case FOR:
			case EACH:
			case ROW:
			case WHEN:
			case VIEW:
			case USING:
			case WITH:
			case RECURSIVE:
			case UNION:
			case ALL:
			case FROM:
			case DETACH:
			case DROP:
			case BIND_PARAMETER:
			case DISTINCT:
			case CAST:
			case CASE:
			case THEN:
			case ELSE:
			case IS:
			case IN:
			case LIKE:
			case GLOB:
			case REGEXP:
			case AND:
			case OR:
			case BETWEEN:
			case ESCAPE:
			case ISNULL:
			case NOTNULL:
			case RAISE:
			case STRING_LITERAL:
			case BLOB_LITERAL:
			case TRUE_:
			case FALSE_:
			case CURRENT_TIME:
			case CURRENT_DATE:
			case CURRENT_TIMESTAMP:
			case INTO:
			case VALUES:
			case PRAGMA:
			case REINDEX:
			case SELECT:
			case GROUP:
			case BY:
			case HAVING:
			case WINDOW:
			case INTERSECT:
			case EXCEPT:
			case INDEXED:
			case NATURAL:
			case LEFT:
			case OUTER:
			case INNER:
			case CROSS:
			case JOIN:
			case VACUUM:
			case FILTER:
			case PARTITION:
			case ORDER:
			case OVER:
			case EXCLUDE:
			case CURRENT:
			case RANGE:
			case ROWS:
			case GROUPS:
			case LIMIT:
			case OFFSET:
			case NULLS:
			case FIRST:
			case LAST:
			case ASC:
			case DESC:
			case PRECEDING:
			case FOLLOWING:
			case UNBOUNDED:
			case FIRST_VALUE:
			case LAST_VALUE:
			case CUME_DIST:
			case PERCENT_RANK:
			case DENSE_RANK:
			case RANK:
			case ROW_NUMBER:
			case LAG:
			case LEAD:
			case NTH_VALUE:
			case NTILE:
			case FULL:
			case RIGHT:
				{
				{
				setState(1737);
				expr(0);
				setState(1742);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(1738);
					match(T__3);
					setState(1739);
					expr(0);
					}
					}
					setState(1744);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				}
				break;
			case T__8:
				{
				setState(1745);
				match(T__8);
				}
				break;
			case T__4:
				break;
			default:
				break;
			}
			setState(1748);
			match(T__4);
			setState(1750);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==FILTER) {
				{
				setState(1749);
				filter_clause();
				}
			}

			setState(1752);
			match(OVER);
			setState(1755);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,257,_ctx) ) {
			case 1:
				{
				setState(1753);
				window_defn();
				}
				break;
			case 2:
				{
				setState(1754);
				window_name();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Common_table_stmtContext extends ParserRuleContext {
		public TerminalNode WITH() { return getToken(SqlParsingParser.WITH, 0); }
		public List<Common_table_expressionContext> common_table_expression() {
			return getRuleContexts(Common_table_expressionContext.class);
		}
		public Common_table_expressionContext common_table_expression(int i) {
			return getRuleContext(Common_table_expressionContext.class,i);
		}
		public TerminalNode RECURSIVE() { return getToken(SqlParsingParser.RECURSIVE, 0); }
		public Common_table_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_common_table_stmt; }
	}

	public final Common_table_stmtContext common_table_stmt() throws RecognitionException {
		Common_table_stmtContext _localctx = new Common_table_stmtContext(_ctx, getState());
		enterRule(_localctx, 126, RULE_common_table_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1757);
			match(WITH);
			setState(1759);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,258,_ctx) ) {
			case 1:
				{
				setState(1758);
				match(RECURSIVE);
				}
				break;
			}
			setState(1761);
			common_table_expression();
			setState(1766);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__3) {
				{
				{
				setState(1762);
				match(T__3);
				setState(1763);
				common_table_expression();
				}
				}
				setState(1768);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Order_by_stmtContext extends ParserRuleContext {
		public TerminalNode ORDER() { return getToken(SqlParsingParser.ORDER, 0); }
		public TerminalNode BY() { return getToken(SqlParsingParser.BY, 0); }
		public List<Ordering_termContext> ordering_term() {
			return getRuleContexts(Ordering_termContext.class);
		}
		public Ordering_termContext ordering_term(int i) {
			return getRuleContext(Ordering_termContext.class,i);
		}
		public Order_by_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_order_by_stmt; }
	}

	public final Order_by_stmtContext order_by_stmt() throws RecognitionException {
		Order_by_stmtContext _localctx = new Order_by_stmtContext(_ctx, getState());
		enterRule(_localctx, 128, RULE_order_by_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1769);
			match(ORDER);
			setState(1770);
			match(BY);
			setState(1771);
			ordering_term();
			setState(1776);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__3) {
				{
				{
				setState(1772);
				match(T__3);
				setState(1773);
				ordering_term();
				}
				}
				setState(1778);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Limit_stmtContext extends ParserRuleContext {
		public TerminalNode LIMIT() { return getToken(SqlParsingParser.LIMIT, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode OFFSET() { return getToken(SqlParsingParser.OFFSET, 0); }
		public Limit_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_limit_stmt; }
	}

	public final Limit_stmtContext limit_stmt() throws RecognitionException {
		Limit_stmtContext _localctx = new Limit_stmtContext(_ctx, getState());
		enterRule(_localctx, 130, RULE_limit_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1779);
			match(LIMIT);
			setState(1780);
			expr(0);
			setState(1783);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__3 || _la==OFFSET) {
				{
				setState(1781);
				_la = _input.LA(1);
				if ( !(_la==T__3 || _la==OFFSET) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(1782);
				expr(0);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Ordering_termContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode COLLATE() { return getToken(SqlParsingParser.COLLATE, 0); }
		public Collation_nameContext collation_name() {
			return getRuleContext(Collation_nameContext.class,0);
		}
		public Asc_descContext asc_desc() {
			return getRuleContext(Asc_descContext.class,0);
		}
		public TerminalNode NULLS() { return getToken(SqlParsingParser.NULLS, 0); }
		public TerminalNode FIRST() { return getToken(SqlParsingParser.FIRST, 0); }
		public TerminalNode LAST() { return getToken(SqlParsingParser.LAST, 0); }
		public Ordering_termContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ordering_term; }
	}

	public final Ordering_termContext ordering_term() throws RecognitionException {
		Ordering_termContext _localctx = new Ordering_termContext(_ctx, getState());
		enterRule(_localctx, 132, RULE_ordering_term);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1785);
			expr(0);
			setState(1788);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COLLATE) {
				{
				setState(1786);
				match(COLLATE);
				setState(1787);
				collation_name();
				}
			}

			setState(1791);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ASC || _la==DESC) {
				{
				setState(1790);
				asc_desc();
				}
			}

			setState(1795);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==NULLS) {
				{
				setState(1793);
				match(NULLS);
				setState(1794);
				_la = _input.LA(1);
				if ( !(_la==FIRST || _la==LAST) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Asc_descContext extends ParserRuleContext {
		public TerminalNode ASC() { return getToken(SqlParsingParser.ASC, 0); }
		public TerminalNode DESC() { return getToken(SqlParsingParser.DESC, 0); }
		public Asc_descContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_asc_desc; }
	}

	public final Asc_descContext asc_desc() throws RecognitionException {
		Asc_descContext _localctx = new Asc_descContext(_ctx, getState());
		enterRule(_localctx, 134, RULE_asc_desc);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1797);
			_la = _input.LA(1);
			if ( !(_la==ASC || _la==DESC) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Frame_leftContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode PRECEDING() { return getToken(SqlParsingParser.PRECEDING, 0); }
		public TerminalNode FOLLOWING() { return getToken(SqlParsingParser.FOLLOWING, 0); }
		public TerminalNode CURRENT() { return getToken(SqlParsingParser.CURRENT, 0); }
		public TerminalNode ROW() { return getToken(SqlParsingParser.ROW, 0); }
		public TerminalNode UNBOUNDED() { return getToken(SqlParsingParser.UNBOUNDED, 0); }
		public Frame_leftContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_frame_left; }
	}

	public final Frame_leftContext frame_left() throws RecognitionException {
		Frame_leftContext _localctx = new Frame_leftContext(_ctx, getState());
		enterRule(_localctx, 136, RULE_frame_left);
		try {
			setState(1809);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,265,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(1799);
				expr(0);
				setState(1800);
				match(PRECEDING);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(1802);
				expr(0);
				setState(1803);
				match(FOLLOWING);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				{
				setState(1805);
				match(CURRENT);
				setState(1806);
				match(ROW);
				}
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				{
				setState(1807);
				match(UNBOUNDED);
				setState(1808);
				match(PRECEDING);
				}
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Frame_rightContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode PRECEDING() { return getToken(SqlParsingParser.PRECEDING, 0); }
		public TerminalNode FOLLOWING() { return getToken(SqlParsingParser.FOLLOWING, 0); }
		public TerminalNode CURRENT() { return getToken(SqlParsingParser.CURRENT, 0); }
		public TerminalNode ROW() { return getToken(SqlParsingParser.ROW, 0); }
		public TerminalNode UNBOUNDED() { return getToken(SqlParsingParser.UNBOUNDED, 0); }
		public Frame_rightContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_frame_right; }
	}

	public final Frame_rightContext frame_right() throws RecognitionException {
		Frame_rightContext _localctx = new Frame_rightContext(_ctx, getState());
		enterRule(_localctx, 138, RULE_frame_right);
		try {
			setState(1821);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,266,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(1811);
				expr(0);
				setState(1812);
				match(PRECEDING);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(1814);
				expr(0);
				setState(1815);
				match(FOLLOWING);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				{
				setState(1817);
				match(CURRENT);
				setState(1818);
				match(ROW);
				}
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				{
				setState(1819);
				match(UNBOUNDED);
				setState(1820);
				match(FOLLOWING);
				}
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Frame_singleContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode PRECEDING() { return getToken(SqlParsingParser.PRECEDING, 0); }
		public TerminalNode UNBOUNDED() { return getToken(SqlParsingParser.UNBOUNDED, 0); }
		public TerminalNode CURRENT() { return getToken(SqlParsingParser.CURRENT, 0); }
		public TerminalNode ROW() { return getToken(SqlParsingParser.ROW, 0); }
		public Frame_singleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_frame_single; }
	}

	public final Frame_singleContext frame_single() throws RecognitionException {
		Frame_singleContext _localctx = new Frame_singleContext(_ctx, getState());
		enterRule(_localctx, 140, RULE_frame_single);
		try {
			setState(1830);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,267,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				{
				setState(1823);
				expr(0);
				setState(1824);
				match(PRECEDING);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				{
				setState(1826);
				match(UNBOUNDED);
				setState(1827);
				match(PRECEDING);
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				{
				setState(1828);
				match(CURRENT);
				setState(1829);
				match(ROW);
				}
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Window_functionContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode OVER() { return getToken(SqlParsingParser.OVER, 0); }
		public Order_by_expr_asc_descContext order_by_expr_asc_desc() {
			return getRuleContext(Order_by_expr_asc_descContext.class,0);
		}
		public TerminalNode FIRST_VALUE() { return getToken(SqlParsingParser.FIRST_VALUE, 0); }
		public TerminalNode LAST_VALUE() { return getToken(SqlParsingParser.LAST_VALUE, 0); }
		public Partition_byContext partition_by() {
			return getRuleContext(Partition_byContext.class,0);
		}
		public Frame_clauseContext frame_clause() {
			return getRuleContext(Frame_clauseContext.class,0);
		}
		public TerminalNode CUME_DIST() { return getToken(SqlParsingParser.CUME_DIST, 0); }
		public TerminalNode PERCENT_RANK() { return getToken(SqlParsingParser.PERCENT_RANK, 0); }
		public Order_by_exprContext order_by_expr() {
			return getRuleContext(Order_by_exprContext.class,0);
		}
		public TerminalNode DENSE_RANK() { return getToken(SqlParsingParser.DENSE_RANK, 0); }
		public TerminalNode RANK() { return getToken(SqlParsingParser.RANK, 0); }
		public TerminalNode ROW_NUMBER() { return getToken(SqlParsingParser.ROW_NUMBER, 0); }
		public TerminalNode LAG() { return getToken(SqlParsingParser.LAG, 0); }
		public TerminalNode LEAD() { return getToken(SqlParsingParser.LEAD, 0); }
		public OffsetContext offset() {
			return getRuleContext(OffsetContext.class,0);
		}
		public Default_valueContext default_value() {
			return getRuleContext(Default_valueContext.class,0);
		}
		public TerminalNode NTH_VALUE() { return getToken(SqlParsingParser.NTH_VALUE, 0); }
		public Signed_numberContext signed_number() {
			return getRuleContext(Signed_numberContext.class,0);
		}
		public TerminalNode NTILE() { return getToken(SqlParsingParser.NTILE, 0); }
		public Window_functionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_window_function; }
	}

	public final Window_functionContext window_function() throws RecognitionException {
		Window_functionContext _localctx = new Window_functionContext(_ctx, getState());
		enterRule(_localctx, 142, RULE_window_function);
		int _la;
		try {
			setState(1917);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case FIRST_VALUE:
			case LAST_VALUE:
				enterOuterAlt(_localctx, 1);
				{
				setState(1832);
				_la = _input.LA(1);
				if ( !(_la==FIRST_VALUE || _la==LAST_VALUE) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(1833);
				match(T__2);
				setState(1834);
				expr(0);
				setState(1835);
				match(T__4);
				setState(1836);
				match(OVER);
				setState(1837);
				match(T__2);
				setState(1839);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==PARTITION) {
					{
					setState(1838);
					partition_by();
					}
				}

				setState(1841);
				order_by_expr_asc_desc();
				setState(1843);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (((((_la - 164)) & ~0x3f) == 0 && ((1L << (_la - 164)) & ((1L << (RANGE - 164)) | (1L << (ROWS - 164)) | (1L << (GROUPS - 164)))) != 0)) {
					{
					setState(1842);
					frame_clause();
					}
				}

				setState(1845);
				match(T__4);
				}
				break;
			case CUME_DIST:
			case PERCENT_RANK:
				enterOuterAlt(_localctx, 2);
				{
				setState(1847);
				_la = _input.LA(1);
				if ( !(_la==CUME_DIST || _la==PERCENT_RANK) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(1848);
				match(T__2);
				setState(1849);
				match(T__4);
				setState(1850);
				match(OVER);
				setState(1851);
				match(T__2);
				setState(1853);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==PARTITION) {
					{
					setState(1852);
					partition_by();
					}
				}

				setState(1856);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ORDER) {
					{
					setState(1855);
					order_by_expr();
					}
				}

				setState(1858);
				match(T__4);
				}
				break;
			case DENSE_RANK:
			case RANK:
			case ROW_NUMBER:
				enterOuterAlt(_localctx, 3);
				{
				setState(1859);
				_la = _input.LA(1);
				if ( !(((((_la - 181)) & ~0x3f) == 0 && ((1L << (_la - 181)) & ((1L << (DENSE_RANK - 181)) | (1L << (RANK - 181)) | (1L << (ROW_NUMBER - 181)))) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(1860);
				match(T__2);
				setState(1861);
				match(T__4);
				setState(1862);
				match(OVER);
				setState(1863);
				match(T__2);
				setState(1865);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==PARTITION) {
					{
					setState(1864);
					partition_by();
					}
				}

				setState(1867);
				order_by_expr_asc_desc();
				setState(1868);
				match(T__4);
				}
				break;
			case LAG:
			case LEAD:
				enterOuterAlt(_localctx, 4);
				{
				setState(1870);
				_la = _input.LA(1);
				if ( !(_la==LAG || _la==LEAD) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(1871);
				match(T__2);
				setState(1872);
				expr(0);
				setState(1874);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,273,_ctx) ) {
				case 1:
					{
					setState(1873);
					offset();
					}
					break;
				}
				setState(1877);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==T__3) {
					{
					setState(1876);
					default_value();
					}
				}

				setState(1879);
				match(T__4);
				setState(1880);
				match(OVER);
				setState(1881);
				match(T__2);
				setState(1883);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==PARTITION) {
					{
					setState(1882);
					partition_by();
					}
				}

				setState(1885);
				order_by_expr_asc_desc();
				setState(1886);
				match(T__4);
				}
				break;
			case NTH_VALUE:
				enterOuterAlt(_localctx, 5);
				{
				setState(1888);
				match(NTH_VALUE);
				setState(1889);
				match(T__2);
				setState(1890);
				expr(0);
				setState(1891);
				match(T__3);
				setState(1892);
				signed_number();
				setState(1893);
				match(T__4);
				setState(1894);
				match(OVER);
				setState(1895);
				match(T__2);
				setState(1897);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==PARTITION) {
					{
					setState(1896);
					partition_by();
					}
				}

				setState(1899);
				order_by_expr_asc_desc();
				setState(1901);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (((((_la - 164)) & ~0x3f) == 0 && ((1L << (_la - 164)) & ((1L << (RANGE - 164)) | (1L << (ROWS - 164)) | (1L << (GROUPS - 164)))) != 0)) {
					{
					setState(1900);
					frame_clause();
					}
				}

				setState(1903);
				match(T__4);
				}
				break;
			case NTILE:
				enterOuterAlt(_localctx, 6);
				{
				setState(1905);
				match(NTILE);
				setState(1906);
				match(T__2);
				setState(1907);
				expr(0);
				setState(1908);
				match(T__4);
				setState(1909);
				match(OVER);
				setState(1910);
				match(T__2);
				setState(1912);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==PARTITION) {
					{
					setState(1911);
					partition_by();
					}
				}

				setState(1914);
				order_by_expr_asc_desc();
				setState(1915);
				match(T__4);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class OffsetContext extends ParserRuleContext {
		public Signed_numberContext signed_number() {
			return getRuleContext(Signed_numberContext.class,0);
		}
		public OffsetContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_offset; }
	}

	public final OffsetContext offset() throws RecognitionException {
		OffsetContext _localctx = new OffsetContext(_ctx, getState());
		enterRule(_localctx, 144, RULE_offset);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1919);
			match(T__3);
			setState(1920);
			signed_number();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Default_valueContext extends ParserRuleContext {
		public Signed_numberContext signed_number() {
			return getRuleContext(Signed_numberContext.class,0);
		}
		public Default_valueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_default_value; }
	}

	public final Default_valueContext default_value() throws RecognitionException {
		Default_valueContext _localctx = new Default_valueContext(_ctx, getState());
		enterRule(_localctx, 146, RULE_default_value);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1922);
			match(T__3);
			setState(1923);
			signed_number();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Partition_byContext extends ParserRuleContext {
		public TerminalNode PARTITION() { return getToken(SqlParsingParser.PARTITION, 0); }
		public TerminalNode BY() { return getToken(SqlParsingParser.BY, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public Partition_byContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_partition_by; }
	}

	public final Partition_byContext partition_by() throws RecognitionException {
		Partition_byContext _localctx = new Partition_byContext(_ctx, getState());
		enterRule(_localctx, 148, RULE_partition_by);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1925);
			match(PARTITION);
			setState(1926);
			match(BY);
			setState(1928); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(1927);
					expr(0);
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(1930); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,280,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Order_by_exprContext extends ParserRuleContext {
		public TerminalNode ORDER() { return getToken(SqlParsingParser.ORDER, 0); }
		public TerminalNode BY() { return getToken(SqlParsingParser.BY, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public Order_by_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_order_by_expr; }
	}

	public final Order_by_exprContext order_by_expr() throws RecognitionException {
		Order_by_exprContext _localctx = new Order_by_exprContext(_ctx, getState());
		enterRule(_localctx, 150, RULE_order_by_expr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1932);
			match(ORDER);
			setState(1933);
			match(BY);
			setState(1935); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(1934);
				expr(0);
				}
				}
				setState(1937); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__2) | (1L << T__5) | (1L << T__6) | (1L << T__23) | (1L << EXPLAIN) | (1L << QUERY) | (1L << PLAN) | (1L << ALTER) | (1L << TABLE) | (1L << RENAME) | (1L << TO) | (1L << COLUMN) | (1L << ADD) | (1L << ANALYZE) | (1L << ATTACH) | (1L << DATABASE) | (1L << AS) | (1L << BEGIN) | (1L << DEFERRED) | (1L << IMMEDIATE) | (1L << EXCLUSIVE) | (1L << TRANSACTION) | (1L << COMMIT) | (1L << END) | (1L << ROLLBACK) | (1L << SAVEPOINT) | (1L << RELEASE) | (1L << CREATE) | (1L << UNIQUE) | (1L << INDEX) | (1L << IF) | (1L << NOT) | (1L << EXISTS) | (1L << ON) | (1L << WHERE) | (1L << COLLATE) | (1L << TEMP) | (1L << TEMPORARY) | (1L << WITHOUT) | (1L << IDENTIFIER) | (1L << CONSTRAINT) | (1L << PRIMARY) | (1L << KEY))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (AUTOINCREMENT - 64)) | (1L << (NULL_ - 64)) | (1L << (CHECK - 64)) | (1L << (DEFAULT - 64)) | (1L << (GENERATED - 64)) | (1L << (ALWAYS - 64)) | (1L << (STORED - 64)) | (1L << (VIRTUAL - 64)) | (1L << (NUMERIC_LITERAL - 64)) | (1L << (FOREIGN - 64)) | (1L << (REFERENCES - 64)) | (1L << (DELETE - 64)) | (1L << (UPDATE - 64)) | (1L << (SET - 64)) | (1L << (CASCADE - 64)) | (1L << (RESTRICT - 64)) | (1L << (NO - 64)) | (1L << (ACTION - 64)) | (1L << (MATCH - 64)) | (1L << (DEFERRABLE - 64)) | (1L << (INITIALLY - 64)) | (1L << (CONFLICT - 64)) | (1L << (ABORT - 64)) | (1L << (FAIL - 64)) | (1L << (IGNORE - 64)) | (1L << (REPLACE - 64)) | (1L << (TRIGGER - 64)) | (1L << (BEFORE - 64)) | (1L << (AFTER - 64)) | (1L << (INSTEAD - 64)) | (1L << (OF - 64)) | (1L << (INSERT - 64)) | (1L << (FOR - 64)) | (1L << (EACH - 64)) | (1L << (ROW - 64)) | (1L << (WHEN - 64)) | (1L << (VIEW - 64)) | (1L << (USING - 64)) | (1L << (WITH - 64)) | (1L << (RECURSIVE - 64)) | (1L << (UNION - 64)) | (1L << (ALL - 64)) | (1L << (FROM - 64)) | (1L << (DETACH - 64)) | (1L << (DROP - 64)) | (1L << (BIND_PARAMETER - 64)) | (1L << (DISTINCT - 64)) | (1L << (CAST - 64)) | (1L << (CASE - 64)) | (1L << (THEN - 64)) | (1L << (ELSE - 64)) | (1L << (IS - 64)) | (1L << (IN - 64)) | (1L << (LIKE - 64)) | (1L << (GLOB - 64)) | (1L << (REGEXP - 64)) | (1L << (AND - 64)) | (1L << (OR - 64)) | (1L << (BETWEEN - 64)) | (1L << (ESCAPE - 64)) | (1L << (ISNULL - 64)) | (1L << (NOTNULL - 64)) | (1L << (RAISE - 64)) | (1L << (STRING_LITERAL - 64)))) != 0) || ((((_la - 128)) & ~0x3f) == 0 && ((1L << (_la - 128)) & ((1L << (BLOB_LITERAL - 128)) | (1L << (TRUE_ - 128)) | (1L << (FALSE_ - 128)) | (1L << (CURRENT_TIME - 128)) | (1L << (CURRENT_DATE - 128)) | (1L << (CURRENT_TIMESTAMP - 128)) | (1L << (INTO - 128)) | (1L << (VALUES - 128)) | (1L << (PRAGMA - 128)) | (1L << (REINDEX - 128)) | (1L << (SELECT - 128)) | (1L << (GROUP - 128)) | (1L << (BY - 128)) | (1L << (HAVING - 128)) | (1L << (WINDOW - 128)) | (1L << (INTERSECT - 128)) | (1L << (EXCEPT - 128)) | (1L << (INDEXED - 128)) | (1L << (NATURAL - 128)) | (1L << (LEFT - 128)) | (1L << (OUTER - 128)) | (1L << (INNER - 128)) | (1L << (CROSS - 128)) | (1L << (JOIN - 128)) | (1L << (VACUUM - 128)) | (1L << (FILTER - 128)) | (1L << (PARTITION - 128)) | (1L << (ORDER - 128)) | (1L << (OVER - 128)) | (1L << (EXCLUDE - 128)) | (1L << (CURRENT - 128)) | (1L << (RANGE - 128)) | (1L << (ROWS - 128)) | (1L << (GROUPS - 128)) | (1L << (LIMIT - 128)) | (1L << (OFFSET - 128)) | (1L << (NULLS - 128)) | (1L << (FIRST - 128)) | (1L << (LAST - 128)) | (1L << (ASC - 128)) | (1L << (DESC - 128)) | (1L << (PRECEDING - 128)) | (1L << (FOLLOWING - 128)) | (1L << (UNBOUNDED - 128)) | (1L << (FIRST_VALUE - 128)) | (1L << (LAST_VALUE - 128)) | (1L << (CUME_DIST - 128)) | (1L << (PERCENT_RANK - 128)) | (1L << (DENSE_RANK - 128)) | (1L << (RANK - 128)) | (1L << (ROW_NUMBER - 128)) | (1L << (LAG - 128)) | (1L << (LEAD - 128)) | (1L << (NTH_VALUE - 128)) | (1L << (NTILE - 128)) | (1L << (FULL - 128)) | (1L << (RIGHT - 128)))) != 0) );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Order_by_expr_asc_descContext extends ParserRuleContext {
		public TerminalNode ORDER() { return getToken(SqlParsingParser.ORDER, 0); }
		public TerminalNode BY() { return getToken(SqlParsingParser.BY, 0); }
		public Order_by_expr_asc_descContext order_by_expr_asc_desc() {
			return getRuleContext(Order_by_expr_asc_descContext.class,0);
		}
		public Order_by_expr_asc_descContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_order_by_expr_asc_desc; }
	}

	public final Order_by_expr_asc_descContext order_by_expr_asc_desc() throws RecognitionException {
		Order_by_expr_asc_descContext _localctx = new Order_by_expr_asc_descContext(_ctx, getState());
		enterRule(_localctx, 152, RULE_order_by_expr_asc_desc);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1939);
			match(ORDER);
			setState(1940);
			match(BY);
			setState(1941);
			order_by_expr_asc_desc();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Expr_asc_descContext extends ParserRuleContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public List<Asc_descContext> asc_desc() {
			return getRuleContexts(Asc_descContext.class);
		}
		public Asc_descContext asc_desc(int i) {
			return getRuleContext(Asc_descContext.class,i);
		}
		public Expr_asc_descContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr_asc_desc; }
	}

	public final Expr_asc_descContext expr_asc_desc() throws RecognitionException {
		Expr_asc_descContext _localctx = new Expr_asc_descContext(_ctx, getState());
		enterRule(_localctx, 154, RULE_expr_asc_desc);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1943);
			expr(0);
			setState(1945);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ASC || _la==DESC) {
				{
				setState(1944);
				asc_desc();
				}
			}

			setState(1954);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__3) {
				{
				{
				setState(1947);
				match(T__3);
				setState(1948);
				expr(0);
				setState(1950);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ASC || _la==DESC) {
					{
					setState(1949);
					asc_desc();
					}
				}

				}
				}
				setState(1956);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Initial_selectContext extends ParserRuleContext {
		public Select_stmtContext select_stmt() {
			return getRuleContext(Select_stmtContext.class,0);
		}
		public Initial_selectContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_initial_select; }
	}

	public final Initial_selectContext initial_select() throws RecognitionException {
		Initial_selectContext _localctx = new Initial_selectContext(_ctx, getState());
		enterRule(_localctx, 156, RULE_initial_select);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1957);
			select_stmt();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Recursive_selectContext extends ParserRuleContext {
		public Select_stmtContext select_stmt() {
			return getRuleContext(Select_stmtContext.class,0);
		}
		public Recursive_selectContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_recursive_select; }
	}

	public final Recursive_selectContext recursive_select() throws RecognitionException {
		Recursive_selectContext _localctx = new Recursive_selectContext(_ctx, getState());
		enterRule(_localctx, 158, RULE_recursive_select);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1959);
			select_stmt();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Unary_operatorContext extends ParserRuleContext {
		public TerminalNode NOT() { return getToken(SqlParsingParser.NOT, 0); }
		public Unary_operatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unary_operator; }
	}

	public final Unary_operatorContext unary_operator() throws RecognitionException {
		Unary_operatorContext _localctx = new Unary_operatorContext(_ctx, getState());
		enterRule(_localctx, 160, RULE_unary_operator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1961);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__5) | (1L << T__6) | (1L << T__23) | (1L << NOT))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Error_messageContext extends ParserRuleContext {
		public TerminalNode STRING_LITERAL() { return getToken(SqlParsingParser.STRING_LITERAL, 0); }
		public Error_messageContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_error_message; }
	}

	public final Error_messageContext error_message() throws RecognitionException {
		Error_messageContext _localctx = new Error_messageContext(_ctx, getState());
		enterRule(_localctx, 162, RULE_error_message);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1963);
			match(STRING_LITERAL);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Module_argumentContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public Column_defContext column_def() {
			return getRuleContext(Column_defContext.class,0);
		}
		public Module_argumentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_module_argument; }
	}

	public final Module_argumentContext module_argument() throws RecognitionException {
		Module_argumentContext _localctx = new Module_argumentContext(_ctx, getState());
		enterRule(_localctx, 164, RULE_module_argument);
		try {
			setState(1967);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,285,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1965);
				expr(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1966);
				column_def();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Column_aliasContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(SqlParsingParser.IDENTIFIER, 0); }
		public TerminalNode STRING_LITERAL() { return getToken(SqlParsingParser.STRING_LITERAL, 0); }
		public Column_aliasContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_column_alias; }
	}

	public final Column_aliasContext column_alias() throws RecognitionException {
		Column_aliasContext _localctx = new Column_aliasContext(_ctx, getState());
		enterRule(_localctx, 166, RULE_column_alias);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1969);
			_la = _input.LA(1);
			if ( !(_la==IDENTIFIER || _la==STRING_LITERAL) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class KeywordContext extends ParserRuleContext {
		public TerminalNode ABORT() { return getToken(SqlParsingParser.ABORT, 0); }
		public TerminalNode ACTION() { return getToken(SqlParsingParser.ACTION, 0); }
		public TerminalNode ADD() { return getToken(SqlParsingParser.ADD, 0); }
		public TerminalNode AFTER() { return getToken(SqlParsingParser.AFTER, 0); }
		public TerminalNode ALL() { return getToken(SqlParsingParser.ALL, 0); }
		public TerminalNode ALTER() { return getToken(SqlParsingParser.ALTER, 0); }
		public TerminalNode ANALYZE() { return getToken(SqlParsingParser.ANALYZE, 0); }
		public TerminalNode AND() { return getToken(SqlParsingParser.AND, 0); }
		public TerminalNode AS() { return getToken(SqlParsingParser.AS, 0); }
		public TerminalNode ASC() { return getToken(SqlParsingParser.ASC, 0); }
		public TerminalNode ATTACH() { return getToken(SqlParsingParser.ATTACH, 0); }
		public TerminalNode AUTOINCREMENT() { return getToken(SqlParsingParser.AUTOINCREMENT, 0); }
		public TerminalNode BEFORE() { return getToken(SqlParsingParser.BEFORE, 0); }
		public TerminalNode BEGIN() { return getToken(SqlParsingParser.BEGIN, 0); }
		public TerminalNode BETWEEN() { return getToken(SqlParsingParser.BETWEEN, 0); }
		public TerminalNode BY() { return getToken(SqlParsingParser.BY, 0); }
		public TerminalNode CASCADE() { return getToken(SqlParsingParser.CASCADE, 0); }
		public TerminalNode CASE() { return getToken(SqlParsingParser.CASE, 0); }
		public TerminalNode CAST() { return getToken(SqlParsingParser.CAST, 0); }
		public TerminalNode CHECK() { return getToken(SqlParsingParser.CHECK, 0); }
		public TerminalNode COLLATE() { return getToken(SqlParsingParser.COLLATE, 0); }
		public TerminalNode COLUMN() { return getToken(SqlParsingParser.COLUMN, 0); }
		public TerminalNode COMMIT() { return getToken(SqlParsingParser.COMMIT, 0); }
		public TerminalNode CONFLICT() { return getToken(SqlParsingParser.CONFLICT, 0); }
		public TerminalNode CONSTRAINT() { return getToken(SqlParsingParser.CONSTRAINT, 0); }
		public TerminalNode CREATE() { return getToken(SqlParsingParser.CREATE, 0); }
		public TerminalNode CROSS() { return getToken(SqlParsingParser.CROSS, 0); }
		public TerminalNode CURRENT_DATE() { return getToken(SqlParsingParser.CURRENT_DATE, 0); }
		public TerminalNode CURRENT_TIME() { return getToken(SqlParsingParser.CURRENT_TIME, 0); }
		public TerminalNode CURRENT_TIMESTAMP() { return getToken(SqlParsingParser.CURRENT_TIMESTAMP, 0); }
		public TerminalNode DATABASE() { return getToken(SqlParsingParser.DATABASE, 0); }
		public TerminalNode DEFAULT() { return getToken(SqlParsingParser.DEFAULT, 0); }
		public TerminalNode DEFERRABLE() { return getToken(SqlParsingParser.DEFERRABLE, 0); }
		public TerminalNode DEFERRED() { return getToken(SqlParsingParser.DEFERRED, 0); }
		public TerminalNode DELETE() { return getToken(SqlParsingParser.DELETE, 0); }
		public TerminalNode DESC() { return getToken(SqlParsingParser.DESC, 0); }
		public TerminalNode DETACH() { return getToken(SqlParsingParser.DETACH, 0); }
		public TerminalNode DISTINCT() { return getToken(SqlParsingParser.DISTINCT, 0); }
		public TerminalNode DROP() { return getToken(SqlParsingParser.DROP, 0); }
		public TerminalNode EACH() { return getToken(SqlParsingParser.EACH, 0); }
		public TerminalNode ELSE() { return getToken(SqlParsingParser.ELSE, 0); }
		public TerminalNode END() { return getToken(SqlParsingParser.END, 0); }
		public TerminalNode ESCAPE() { return getToken(SqlParsingParser.ESCAPE, 0); }
		public TerminalNode EXCEPT() { return getToken(SqlParsingParser.EXCEPT, 0); }
		public TerminalNode EXCLUSIVE() { return getToken(SqlParsingParser.EXCLUSIVE, 0); }
		public TerminalNode EXISTS() { return getToken(SqlParsingParser.EXISTS, 0); }
		public TerminalNode EXPLAIN() { return getToken(SqlParsingParser.EXPLAIN, 0); }
		public TerminalNode FAIL() { return getToken(SqlParsingParser.FAIL, 0); }
		public TerminalNode FOR() { return getToken(SqlParsingParser.FOR, 0); }
		public TerminalNode FOREIGN() { return getToken(SqlParsingParser.FOREIGN, 0); }
		public TerminalNode FROM() { return getToken(SqlParsingParser.FROM, 0); }
		public TerminalNode FULL() { return getToken(SqlParsingParser.FULL, 0); }
		public TerminalNode GLOB() { return getToken(SqlParsingParser.GLOB, 0); }
		public TerminalNode GROUP() { return getToken(SqlParsingParser.GROUP, 0); }
		public TerminalNode HAVING() { return getToken(SqlParsingParser.HAVING, 0); }
		public TerminalNode IF() { return getToken(SqlParsingParser.IF, 0); }
		public TerminalNode IGNORE() { return getToken(SqlParsingParser.IGNORE, 0); }
		public TerminalNode IMMEDIATE() { return getToken(SqlParsingParser.IMMEDIATE, 0); }
		public TerminalNode IN() { return getToken(SqlParsingParser.IN, 0); }
		public TerminalNode INDEX() { return getToken(SqlParsingParser.INDEX, 0); }
		public TerminalNode INDEXED() { return getToken(SqlParsingParser.INDEXED, 0); }
		public TerminalNode INITIALLY() { return getToken(SqlParsingParser.INITIALLY, 0); }
		public TerminalNode INNER() { return getToken(SqlParsingParser.INNER, 0); }
		public TerminalNode INSERT() { return getToken(SqlParsingParser.INSERT, 0); }
		public TerminalNode INSTEAD() { return getToken(SqlParsingParser.INSTEAD, 0); }
		public TerminalNode INTERSECT() { return getToken(SqlParsingParser.INTERSECT, 0); }
		public TerminalNode INTO() { return getToken(SqlParsingParser.INTO, 0); }
		public TerminalNode IS() { return getToken(SqlParsingParser.IS, 0); }
		public TerminalNode ISNULL() { return getToken(SqlParsingParser.ISNULL, 0); }
		public TerminalNode JOIN() { return getToken(SqlParsingParser.JOIN, 0); }
		public TerminalNode KEY() { return getToken(SqlParsingParser.KEY, 0); }
		public TerminalNode LEFT() { return getToken(SqlParsingParser.LEFT, 0); }
		public TerminalNode LIKE() { return getToken(SqlParsingParser.LIKE, 0); }
		public TerminalNode LIMIT() { return getToken(SqlParsingParser.LIMIT, 0); }
		public TerminalNode MATCH() { return getToken(SqlParsingParser.MATCH, 0); }
		public TerminalNode NATURAL() { return getToken(SqlParsingParser.NATURAL, 0); }
		public TerminalNode NO() { return getToken(SqlParsingParser.NO, 0); }
		public TerminalNode NOT() { return getToken(SqlParsingParser.NOT, 0); }
		public TerminalNode NOTNULL() { return getToken(SqlParsingParser.NOTNULL, 0); }
		public TerminalNode NULL_() { return getToken(SqlParsingParser.NULL_, 0); }
		public TerminalNode OF() { return getToken(SqlParsingParser.OF, 0); }
		public TerminalNode OFFSET() { return getToken(SqlParsingParser.OFFSET, 0); }
		public TerminalNode ON() { return getToken(SqlParsingParser.ON, 0); }
		public TerminalNode OR() { return getToken(SqlParsingParser.OR, 0); }
		public TerminalNode ORDER() { return getToken(SqlParsingParser.ORDER, 0); }
		public TerminalNode OUTER() { return getToken(SqlParsingParser.OUTER, 0); }
		public TerminalNode PLAN() { return getToken(SqlParsingParser.PLAN, 0); }
		public TerminalNode PRAGMA() { return getToken(SqlParsingParser.PRAGMA, 0); }
		public TerminalNode PRIMARY() { return getToken(SqlParsingParser.PRIMARY, 0); }
		public TerminalNode QUERY() { return getToken(SqlParsingParser.QUERY, 0); }
		public TerminalNode RAISE() { return getToken(SqlParsingParser.RAISE, 0); }
		public TerminalNode RECURSIVE() { return getToken(SqlParsingParser.RECURSIVE, 0); }
		public TerminalNode REFERENCES() { return getToken(SqlParsingParser.REFERENCES, 0); }
		public TerminalNode REGEXP() { return getToken(SqlParsingParser.REGEXP, 0); }
		public TerminalNode REINDEX() { return getToken(SqlParsingParser.REINDEX, 0); }
		public TerminalNode RELEASE() { return getToken(SqlParsingParser.RELEASE, 0); }
		public TerminalNode RENAME() { return getToken(SqlParsingParser.RENAME, 0); }
		public TerminalNode REPLACE() { return getToken(SqlParsingParser.REPLACE, 0); }
		public TerminalNode RESTRICT() { return getToken(SqlParsingParser.RESTRICT, 0); }
		public TerminalNode RIGHT() { return getToken(SqlParsingParser.RIGHT, 0); }
		public TerminalNode ROLLBACK() { return getToken(SqlParsingParser.ROLLBACK, 0); }
		public TerminalNode ROW() { return getToken(SqlParsingParser.ROW, 0); }
		public TerminalNode ROWS() { return getToken(SqlParsingParser.ROWS, 0); }
		public TerminalNode SAVEPOINT() { return getToken(SqlParsingParser.SAVEPOINT, 0); }
		public TerminalNode SELECT() { return getToken(SqlParsingParser.SELECT, 0); }
		public TerminalNode SET() { return getToken(SqlParsingParser.SET, 0); }
		public TerminalNode TABLE() { return getToken(SqlParsingParser.TABLE, 0); }
		public TerminalNode TEMP() { return getToken(SqlParsingParser.TEMP, 0); }
		public TerminalNode TEMPORARY() { return getToken(SqlParsingParser.TEMPORARY, 0); }
		public TerminalNode THEN() { return getToken(SqlParsingParser.THEN, 0); }
		public TerminalNode TO() { return getToken(SqlParsingParser.TO, 0); }
		public TerminalNode TRANSACTION() { return getToken(SqlParsingParser.TRANSACTION, 0); }
		public TerminalNode TRIGGER() { return getToken(SqlParsingParser.TRIGGER, 0); }
		public TerminalNode UNION() { return getToken(SqlParsingParser.UNION, 0); }
		public TerminalNode UNIQUE() { return getToken(SqlParsingParser.UNIQUE, 0); }
		public TerminalNode UPDATE() { return getToken(SqlParsingParser.UPDATE, 0); }
		public TerminalNode USING() { return getToken(SqlParsingParser.USING, 0); }
		public TerminalNode VACUUM() { return getToken(SqlParsingParser.VACUUM, 0); }
		public TerminalNode VALUES() { return getToken(SqlParsingParser.VALUES, 0); }
		public TerminalNode VIEW() { return getToken(SqlParsingParser.VIEW, 0); }
		public TerminalNode VIRTUAL() { return getToken(SqlParsingParser.VIRTUAL, 0); }
		public TerminalNode WHEN() { return getToken(SqlParsingParser.WHEN, 0); }
		public TerminalNode WHERE() { return getToken(SqlParsingParser.WHERE, 0); }
		public TerminalNode WITH() { return getToken(SqlParsingParser.WITH, 0); }
		public TerminalNode WITHOUT() { return getToken(SqlParsingParser.WITHOUT, 0); }
		public TerminalNode FIRST_VALUE() { return getToken(SqlParsingParser.FIRST_VALUE, 0); }
		public TerminalNode OVER() { return getToken(SqlParsingParser.OVER, 0); }
		public TerminalNode PARTITION() { return getToken(SqlParsingParser.PARTITION, 0); }
		public TerminalNode RANGE() { return getToken(SqlParsingParser.RANGE, 0); }
		public TerminalNode PRECEDING() { return getToken(SqlParsingParser.PRECEDING, 0); }
		public TerminalNode UNBOUNDED() { return getToken(SqlParsingParser.UNBOUNDED, 0); }
		public TerminalNode CURRENT() { return getToken(SqlParsingParser.CURRENT, 0); }
		public TerminalNode FOLLOWING() { return getToken(SqlParsingParser.FOLLOWING, 0); }
		public TerminalNode CUME_DIST() { return getToken(SqlParsingParser.CUME_DIST, 0); }
		public TerminalNode DENSE_RANK() { return getToken(SqlParsingParser.DENSE_RANK, 0); }
		public TerminalNode LAG() { return getToken(SqlParsingParser.LAG, 0); }
		public TerminalNode LAST_VALUE() { return getToken(SqlParsingParser.LAST_VALUE, 0); }
		public TerminalNode LEAD() { return getToken(SqlParsingParser.LEAD, 0); }
		public TerminalNode NTH_VALUE() { return getToken(SqlParsingParser.NTH_VALUE, 0); }
		public TerminalNode NTILE() { return getToken(SqlParsingParser.NTILE, 0); }
		public TerminalNode PERCENT_RANK() { return getToken(SqlParsingParser.PERCENT_RANK, 0); }
		public TerminalNode RANK() { return getToken(SqlParsingParser.RANK, 0); }
		public TerminalNode ROW_NUMBER() { return getToken(SqlParsingParser.ROW_NUMBER, 0); }
		public TerminalNode GENERATED() { return getToken(SqlParsingParser.GENERATED, 0); }
		public TerminalNode ALWAYS() { return getToken(SqlParsingParser.ALWAYS, 0); }
		public TerminalNode STORED() { return getToken(SqlParsingParser.STORED, 0); }
		public TerminalNode TRUE_() { return getToken(SqlParsingParser.TRUE_, 0); }
		public TerminalNode FALSE_() { return getToken(SqlParsingParser.FALSE_, 0); }
		public TerminalNode WINDOW() { return getToken(SqlParsingParser.WINDOW, 0); }
		public TerminalNode NULLS() { return getToken(SqlParsingParser.NULLS, 0); }
		public TerminalNode FIRST() { return getToken(SqlParsingParser.FIRST, 0); }
		public TerminalNode LAST() { return getToken(SqlParsingParser.LAST, 0); }
		public TerminalNode FILTER() { return getToken(SqlParsingParser.FILTER, 0); }
		public TerminalNode GROUPS() { return getToken(SqlParsingParser.GROUPS, 0); }
		public TerminalNode EXCLUDE() { return getToken(SqlParsingParser.EXCLUDE, 0); }
		public KeywordContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_keyword; }
	}

	public final KeywordContext keyword() throws RecognitionException {
		KeywordContext _localctx = new KeywordContext(_ctx, getState());
		enterRule(_localctx, 168, RULE_keyword);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1971);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << EXPLAIN) | (1L << QUERY) | (1L << PLAN) | (1L << ALTER) | (1L << TABLE) | (1L << RENAME) | (1L << TO) | (1L << COLUMN) | (1L << ADD) | (1L << ANALYZE) | (1L << ATTACH) | (1L << DATABASE) | (1L << AS) | (1L << BEGIN) | (1L << DEFERRED) | (1L << IMMEDIATE) | (1L << EXCLUSIVE) | (1L << TRANSACTION) | (1L << COMMIT) | (1L << END) | (1L << ROLLBACK) | (1L << SAVEPOINT) | (1L << RELEASE) | (1L << CREATE) | (1L << UNIQUE) | (1L << INDEX) | (1L << IF) | (1L << NOT) | (1L << EXISTS) | (1L << ON) | (1L << WHERE) | (1L << COLLATE) | (1L << TEMP) | (1L << TEMPORARY) | (1L << WITHOUT) | (1L << CONSTRAINT) | (1L << PRIMARY) | (1L << KEY))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (AUTOINCREMENT - 64)) | (1L << (NULL_ - 64)) | (1L << (CHECK - 64)) | (1L << (DEFAULT - 64)) | (1L << (GENERATED - 64)) | (1L << (ALWAYS - 64)) | (1L << (STORED - 64)) | (1L << (VIRTUAL - 64)) | (1L << (FOREIGN - 64)) | (1L << (REFERENCES - 64)) | (1L << (DELETE - 64)) | (1L << (UPDATE - 64)) | (1L << (SET - 64)) | (1L << (CASCADE - 64)) | (1L << (RESTRICT - 64)) | (1L << (NO - 64)) | (1L << (ACTION - 64)) | (1L << (MATCH - 64)) | (1L << (DEFERRABLE - 64)) | (1L << (INITIALLY - 64)) | (1L << (CONFLICT - 64)) | (1L << (ABORT - 64)) | (1L << (FAIL - 64)) | (1L << (IGNORE - 64)) | (1L << (REPLACE - 64)) | (1L << (TRIGGER - 64)) | (1L << (BEFORE - 64)) | (1L << (AFTER - 64)) | (1L << (INSTEAD - 64)) | (1L << (OF - 64)) | (1L << (INSERT - 64)) | (1L << (FOR - 64)) | (1L << (EACH - 64)) | (1L << (ROW - 64)) | (1L << (WHEN - 64)) | (1L << (VIEW - 64)) | (1L << (USING - 64)) | (1L << (WITH - 64)) | (1L << (RECURSIVE - 64)) | (1L << (UNION - 64)) | (1L << (ALL - 64)) | (1L << (FROM - 64)) | (1L << (DETACH - 64)) | (1L << (DROP - 64)) | (1L << (DISTINCT - 64)) | (1L << (CAST - 64)) | (1L << (CASE - 64)) | (1L << (THEN - 64)) | (1L << (ELSE - 64)) | (1L << (IS - 64)) | (1L << (IN - 64)) | (1L << (LIKE - 64)) | (1L << (GLOB - 64)) | (1L << (REGEXP - 64)) | (1L << (AND - 64)) | (1L << (OR - 64)) | (1L << (BETWEEN - 64)) | (1L << (ESCAPE - 64)) | (1L << (ISNULL - 64)) | (1L << (NOTNULL - 64)) | (1L << (RAISE - 64)))) != 0) || ((((_la - 129)) & ~0x3f) == 0 && ((1L << (_la - 129)) & ((1L << (TRUE_ - 129)) | (1L << (FALSE_ - 129)) | (1L << (CURRENT_TIME - 129)) | (1L << (CURRENT_DATE - 129)) | (1L << (CURRENT_TIMESTAMP - 129)) | (1L << (INTO - 129)) | (1L << (VALUES - 129)) | (1L << (PRAGMA - 129)) | (1L << (REINDEX - 129)) | (1L << (SELECT - 129)) | (1L << (GROUP - 129)) | (1L << (BY - 129)) | (1L << (HAVING - 129)) | (1L << (WINDOW - 129)) | (1L << (INTERSECT - 129)) | (1L << (EXCEPT - 129)) | (1L << (INDEXED - 129)) | (1L << (NATURAL - 129)) | (1L << (LEFT - 129)) | (1L << (OUTER - 129)) | (1L << (INNER - 129)) | (1L << (CROSS - 129)) | (1L << (JOIN - 129)) | (1L << (VACUUM - 129)) | (1L << (FILTER - 129)) | (1L << (PARTITION - 129)) | (1L << (ORDER - 129)) | (1L << (OVER - 129)) | (1L << (EXCLUDE - 129)) | (1L << (CURRENT - 129)) | (1L << (RANGE - 129)) | (1L << (ROWS - 129)) | (1L << (GROUPS - 129)) | (1L << (LIMIT - 129)) | (1L << (OFFSET - 129)) | (1L << (NULLS - 129)) | (1L << (FIRST - 129)) | (1L << (LAST - 129)) | (1L << (ASC - 129)) | (1L << (DESC - 129)) | (1L << (PRECEDING - 129)) | (1L << (FOLLOWING - 129)) | (1L << (UNBOUNDED - 129)) | (1L << (FIRST_VALUE - 129)) | (1L << (LAST_VALUE - 129)) | (1L << (CUME_DIST - 129)) | (1L << (PERCENT_RANK - 129)) | (1L << (DENSE_RANK - 129)) | (1L << (RANK - 129)) | (1L << (ROW_NUMBER - 129)) | (1L << (LAG - 129)) | (1L << (LEAD - 129)) | (1L << (NTH_VALUE - 129)) | (1L << (NTILE - 129)) | (1L << (FULL - 129)) | (1L << (RIGHT - 129)))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public NameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_name; }
	}

	public final NameContext name() throws RecognitionException {
		NameContext _localctx = new NameContext(_ctx, getState());
		enterRule(_localctx, 170, RULE_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1973);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Function_nameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Function_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_function_name; }
	}

	public final Function_nameContext function_name() throws RecognitionException {
		Function_nameContext _localctx = new Function_nameContext(_ctx, getState());
		enterRule(_localctx, 172, RULE_function_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1975);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Schema_nameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Schema_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_schema_name; }
	}

	public final Schema_nameContext schema_name() throws RecognitionException {
		Schema_nameContext _localctx = new Schema_nameContext(_ctx, getState());
		enterRule(_localctx, 174, RULE_schema_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1977);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Table_nameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Table_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_table_name; }
	}

	public final Table_nameContext table_name() throws RecognitionException {
		Table_nameContext _localctx = new Table_nameContext(_ctx, getState());
		enterRule(_localctx, 176, RULE_table_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1979);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Table_or_index_nameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Table_or_index_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_table_or_index_name; }
	}

	public final Table_or_index_nameContext table_or_index_name() throws RecognitionException {
		Table_or_index_nameContext _localctx = new Table_or_index_nameContext(_ctx, getState());
		enterRule(_localctx, 178, RULE_table_or_index_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1981);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class New_table_nameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public New_table_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_new_table_name; }
	}

	public final New_table_nameContext new_table_name() throws RecognitionException {
		New_table_nameContext _localctx = new New_table_nameContext(_ctx, getState());
		enterRule(_localctx, 180, RULE_new_table_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1983);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Column_nameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Column_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_column_name; }
	}

	public final Column_nameContext column_name() throws RecognitionException {
		Column_nameContext _localctx = new Column_nameContext(_ctx, getState());
		enterRule(_localctx, 182, RULE_column_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1985);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Collation_nameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Collation_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_collation_name; }
	}

	public final Collation_nameContext collation_name() throws RecognitionException {
		Collation_nameContext _localctx = new Collation_nameContext(_ctx, getState());
		enterRule(_localctx, 184, RULE_collation_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1987);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Foreign_tableContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Foreign_tableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_foreign_table; }
	}

	public final Foreign_tableContext foreign_table() throws RecognitionException {
		Foreign_tableContext _localctx = new Foreign_tableContext(_ctx, getState());
		enterRule(_localctx, 186, RULE_foreign_table);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1989);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Index_nameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Index_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_index_name; }
	}

	public final Index_nameContext index_name() throws RecognitionException {
		Index_nameContext _localctx = new Index_nameContext(_ctx, getState());
		enterRule(_localctx, 188, RULE_index_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1991);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Trigger_nameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Trigger_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_trigger_name; }
	}

	public final Trigger_nameContext trigger_name() throws RecognitionException {
		Trigger_nameContext _localctx = new Trigger_nameContext(_ctx, getState());
		enterRule(_localctx, 190, RULE_trigger_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1993);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class View_nameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public View_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_view_name; }
	}

	public final View_nameContext view_name() throws RecognitionException {
		View_nameContext _localctx = new View_nameContext(_ctx, getState());
		enterRule(_localctx, 192, RULE_view_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1995);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Module_nameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Module_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_module_name; }
	}

	public final Module_nameContext module_name() throws RecognitionException {
		Module_nameContext _localctx = new Module_nameContext(_ctx, getState());
		enterRule(_localctx, 194, RULE_module_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1997);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Pragma_nameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Pragma_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_pragma_name; }
	}

	public final Pragma_nameContext pragma_name() throws RecognitionException {
		Pragma_nameContext _localctx = new Pragma_nameContext(_ctx, getState());
		enterRule(_localctx, 196, RULE_pragma_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1999);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Savepoint_nameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Savepoint_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_savepoint_name; }
	}

	public final Savepoint_nameContext savepoint_name() throws RecognitionException {
		Savepoint_nameContext _localctx = new Savepoint_nameContext(_ctx, getState());
		enterRule(_localctx, 198, RULE_savepoint_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(2001);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Table_aliasContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Table_aliasContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_table_alias; }
	}

	public final Table_aliasContext table_alias() throws RecognitionException {
		Table_aliasContext _localctx = new Table_aliasContext(_ctx, getState());
		enterRule(_localctx, 200, RULE_table_alias);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(2003);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Transaction_nameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Transaction_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_transaction_name; }
	}

	public final Transaction_nameContext transaction_name() throws RecognitionException {
		Transaction_nameContext _localctx = new Transaction_nameContext(_ctx, getState());
		enterRule(_localctx, 202, RULE_transaction_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(2005);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Window_nameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Window_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_window_name; }
	}

	public final Window_nameContext window_name() throws RecognitionException {
		Window_nameContext _localctx = new Window_nameContext(_ctx, getState());
		enterRule(_localctx, 204, RULE_window_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(2007);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AliasContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public AliasContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_alias; }
	}

	public final AliasContext alias() throws RecognitionException {
		AliasContext _localctx = new AliasContext(_ctx, getState());
		enterRule(_localctx, 206, RULE_alias);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(2009);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FilenameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public FilenameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_filename; }
	}

	public final FilenameContext filename() throws RecognitionException {
		FilenameContext _localctx = new FilenameContext(_ctx, getState());
		enterRule(_localctx, 208, RULE_filename);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(2011);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Base_window_nameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Base_window_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_base_window_name; }
	}

	public final Base_window_nameContext base_window_name() throws RecognitionException {
		Base_window_nameContext _localctx = new Base_window_nameContext(_ctx, getState());
		enterRule(_localctx, 210, RULE_base_window_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(2013);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Simple_funcContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Simple_funcContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_func; }
	}

	public final Simple_funcContext simple_func() throws RecognitionException {
		Simple_funcContext _localctx = new Simple_funcContext(_ctx, getState());
		enterRule(_localctx, 212, RULE_simple_func);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(2015);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Aggregate_funcContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Aggregate_funcContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_aggregate_func; }
	}

	public final Aggregate_funcContext aggregate_func() throws RecognitionException {
		Aggregate_funcContext _localctx = new Aggregate_funcContext(_ctx, getState());
		enterRule(_localctx, 214, RULE_aggregate_func);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(2017);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Table_function_nameContext extends ParserRuleContext {
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Table_function_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_table_function_name; }
	}

	public final Table_function_nameContext table_function_name() throws RecognitionException {
		Table_function_nameContext _localctx = new Table_function_nameContext(_ctx, getState());
		enterRule(_localctx, 216, RULE_table_function_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(2019);
			any_name();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Any_nameContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(SqlParsingParser.IDENTIFIER, 0); }
		public KeywordContext keyword() {
			return getRuleContext(KeywordContext.class,0);
		}
		public TerminalNode STRING_LITERAL() { return getToken(SqlParsingParser.STRING_LITERAL, 0); }
		public Any_nameContext any_name() {
			return getRuleContext(Any_nameContext.class,0);
		}
		public Any_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_any_name; }
	}

	public final Any_nameContext any_name() throws RecognitionException {
		Any_nameContext _localctx = new Any_nameContext(_ctx, getState());
		enterRule(_localctx, 218, RULE_any_name);
		try {
			setState(2028);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENTIFIER:
				enterOuterAlt(_localctx, 1);
				{
				setState(2021);
				match(IDENTIFIER);
				}
				break;
			case EXPLAIN:
			case QUERY:
			case PLAN:
			case ALTER:
			case TABLE:
			case RENAME:
			case TO:
			case COLUMN:
			case ADD:
			case ANALYZE:
			case ATTACH:
			case DATABASE:
			case AS:
			case BEGIN:
			case DEFERRED:
			case IMMEDIATE:
			case EXCLUSIVE:
			case TRANSACTION:
			case COMMIT:
			case END:
			case ROLLBACK:
			case SAVEPOINT:
			case RELEASE:
			case CREATE:
			case UNIQUE:
			case INDEX:
			case IF:
			case NOT:
			case EXISTS:
			case ON:
			case WHERE:
			case COLLATE:
			case TEMP:
			case TEMPORARY:
			case WITHOUT:
			case CONSTRAINT:
			case PRIMARY:
			case KEY:
			case AUTOINCREMENT:
			case NULL_:
			case CHECK:
			case DEFAULT:
			case GENERATED:
			case ALWAYS:
			case STORED:
			case VIRTUAL:
			case FOREIGN:
			case REFERENCES:
			case DELETE:
			case UPDATE:
			case SET:
			case CASCADE:
			case RESTRICT:
			case NO:
			case ACTION:
			case MATCH:
			case DEFERRABLE:
			case INITIALLY:
			case CONFLICT:
			case ABORT:
			case FAIL:
			case IGNORE:
			case REPLACE:
			case TRIGGER:
			case BEFORE:
			case AFTER:
			case INSTEAD:
			case OF:
			case INSERT:
			case FOR:
			case EACH:
			case ROW:
			case WHEN:
			case VIEW:
			case USING:
			case WITH:
			case RECURSIVE:
			case UNION:
			case ALL:
			case FROM:
			case DETACH:
			case DROP:
			case DISTINCT:
			case CAST:
			case CASE:
			case THEN:
			case ELSE:
			case IS:
			case IN:
			case LIKE:
			case GLOB:
			case REGEXP:
			case AND:
			case OR:
			case BETWEEN:
			case ESCAPE:
			case ISNULL:
			case NOTNULL:
			case RAISE:
			case TRUE_:
			case FALSE_:
			case CURRENT_TIME:
			case CURRENT_DATE:
			case CURRENT_TIMESTAMP:
			case INTO:
			case VALUES:
			case PRAGMA:
			case REINDEX:
			case SELECT:
			case GROUP:
			case BY:
			case HAVING:
			case WINDOW:
			case INTERSECT:
			case EXCEPT:
			case INDEXED:
			case NATURAL:
			case LEFT:
			case OUTER:
			case INNER:
			case CROSS:
			case JOIN:
			case VACUUM:
			case FILTER:
			case PARTITION:
			case ORDER:
			case OVER:
			case EXCLUDE:
			case CURRENT:
			case RANGE:
			case ROWS:
			case GROUPS:
			case LIMIT:
			case OFFSET:
			case NULLS:
			case FIRST:
			case LAST:
			case ASC:
			case DESC:
			case PRECEDING:
			case FOLLOWING:
			case UNBOUNDED:
			case FIRST_VALUE:
			case LAST_VALUE:
			case CUME_DIST:
			case PERCENT_RANK:
			case DENSE_RANK:
			case RANK:
			case ROW_NUMBER:
			case LAG:
			case LEAD:
			case NTH_VALUE:
			case NTILE:
			case FULL:
			case RIGHT:
				enterOuterAlt(_localctx, 2);
				{
				setState(2022);
				keyword();
				}
				break;
			case STRING_LITERAL:
				enterOuterAlt(_localctx, 3);
				{
				setState(2023);
				match(STRING_LITERAL);
				}
				break;
			case T__2:
				enterOuterAlt(_localctx, 4);
				{
				setState(2024);
				match(T__2);
				setState(2025);
				any_name();
				setState(2026);
				match(T__4);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 31:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 20);
		case 1:
			return precpred(_ctx, 19);
		case 2:
			return precpred(_ctx, 18);
		case 3:
			return precpred(_ctx, 17);
		case 4:
			return precpred(_ctx, 16);
		case 5:
			return precpred(_ctx, 15);
		case 6:
			return precpred(_ctx, 14);
		case 7:
			return precpred(_ctx, 13);
		case 8:
			return precpred(_ctx, 6);
		case 9:
			return precpred(_ctx, 5);
		case 10:
			return precpred(_ctx, 9);
		case 11:
			return precpred(_ctx, 8);
		case 12:
			return precpred(_ctx, 7);
		case 13:
			return precpred(_ctx, 4);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\u00bf\u07f1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\4\64\t"+
		"\64\4\65\t\65\4\66\t\66\4\67\t\67\48\t8\49\t9\4:\t:\4;\t;\4<\t<\4=\t="+
		"\4>\t>\4?\t?\4@\t@\4A\tA\4B\tB\4C\tC\4D\tD\4E\tE\4F\tF\4G\tG\4H\tH\4I"+
		"\tI\4J\tJ\4K\tK\4L\tL\4M\tM\4N\tN\4O\tO\4P\tP\4Q\tQ\4R\tR\4S\tS\4T\tT"+
		"\4U\tU\4V\tV\4W\tW\4X\tX\4Y\tY\4Z\tZ\4[\t[\4\\\t\\\4]\t]\4^\t^\4_\t_\4"+
		"`\t`\4a\ta\4b\tb\4c\tc\4d\td\4e\te\4f\tf\4g\tg\4h\th\4i\ti\4j\tj\4k\t"+
		"k\4l\tl\4m\tm\4n\tn\4o\to\3\2\7\2\u00e0\n\2\f\2\16\2\u00e3\13\2\3\2\3"+
		"\2\6\2\u00e7\n\2\r\2\16\2\u00e8\3\2\7\2\u00ec\n\2\f\2\16\2\u00ef\13\2"+
		"\3\2\7\2\u00f2\n\2\f\2\16\2\u00f5\13\2\3\3\3\3\3\3\5\3\u00fa\n\3\5\3\u00fc"+
		"\n\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\5\3\u0116\n\3\3\4\3\4\3\4\3\4\3\4\5\4\u011d"+
		"\n\4\3\4\3\4\3\4\3\4\3\4\5\4\u0124\n\4\3\4\3\4\3\4\3\4\5\4\u012a\n\4\3"+
		"\4\3\4\5\4\u012e\n\4\3\4\5\4\u0131\n\4\3\5\3\5\3\5\3\5\3\5\5\5\u0138\n"+
		"\5\3\5\5\5\u013b\n\5\3\6\3\6\5\6\u013f\n\6\3\6\3\6\3\6\3\6\3\7\3\7\5\7"+
		"\u0147\n\7\3\7\3\7\5\7\u014b\n\7\5\7\u014d\n\7\3\b\3\b\5\b\u0151\n\b\3"+
		"\t\3\t\5\t\u0155\n\t\3\t\3\t\5\t\u0159\n\t\3\t\5\t\u015c\n\t\3\n\3\n\3"+
		"\n\3\13\3\13\5\13\u0163\n\13\3\13\3\13\3\f\3\f\5\f\u0169\n\f\3\f\3\f\3"+
		"\f\3\f\5\f\u016f\n\f\3\f\3\f\3\f\5\f\u0174\n\f\3\f\3\f\3\f\3\f\3\f\3\f"+
		"\3\f\7\f\u017d\n\f\f\f\16\f\u0180\13\f\3\f\3\f\3\f\5\f\u0185\n\f\3\r\3"+
		"\r\5\r\u0189\n\r\3\r\3\r\5\r\u018d\n\r\3\r\5\r\u0190\n\r\3\16\3\16\5\16"+
		"\u0194\n\16\3\16\3\16\3\16\3\16\5\16\u019a\n\16\3\16\3\16\3\16\5\16\u019f"+
		"\n\16\3\16\3\16\3\16\3\16\3\16\7\16\u01a6\n\16\f\16\16\16\u01a9\13\16"+
		"\3\16\3\16\7\16\u01ad\n\16\f\16\16\16\u01b0\13\16\3\16\3\16\3\16\5\16"+
		"\u01b5\n\16\3\16\3\16\5\16\u01b9\n\16\3\17\3\17\5\17\u01bd\n\17\3\17\7"+
		"\17\u01c0\n\17\f\17\16\17\u01c3\13\17\3\20\6\20\u01c6\n\20\r\20\16\20"+
		"\u01c7\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\20\5\20\u01d4\n"+
		"\20\3\21\3\21\5\21\u01d8\n\21\3\21\3\21\3\21\5\21\u01dd\n\21\3\21\5\21"+
		"\u01e0\n\21\3\21\5\21\u01e3\n\21\3\21\3\21\3\21\5\21\u01e8\n\21\3\21\5"+
		"\21\u01eb\n\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21"+
		"\3\21\5\21\u01f9\n\21\3\21\3\21\3\21\3\21\3\21\5\21\u0200\n\21\3\21\3"+
		"\21\3\21\3\21\3\21\5\21\u0207\n\21\5\21\u0209\n\21\3\22\5\22\u020c\n\22"+
		"\3\22\3\22\3\23\3\23\5\23\u0212\n\23\3\23\3\23\3\23\5\23\u0217\n\23\3"+
		"\23\3\23\3\23\3\23\7\23\u021d\n\23\f\23\16\23\u0220\13\23\3\23\3\23\5"+
		"\23\u0224\n\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23"+
		"\7\23\u0231\n\23\f\23\16\23\u0234\13\23\3\23\3\23\3\23\5\23\u0239\n\23"+
		"\3\24\3\24\3\24\3\24\3\24\3\24\7\24\u0241\n\24\f\24\16\24\u0244\13\24"+
		"\3\24\3\24\5\24\u0248\n\24\3\24\3\24\3\24\3\24\3\24\3\24\3\24\3\24\5\24"+
		"\u0252\n\24\3\24\3\24\7\24\u0256\n\24\f\24\16\24\u0259\13\24\3\24\5\24"+
		"\u025c\n\24\3\24\3\24\3\24\5\24\u0261\n\24\5\24\u0263\n\24\3\25\3\25\3"+
		"\25\3\25\3\26\3\26\5\26\u026b\n\26\3\26\3\26\3\26\3\26\5\26\u0271\n\26"+
		"\3\26\3\26\3\26\5\26\u0276\n\26\3\26\3\26\3\26\3\26\3\26\5\26\u027d\n"+
		"\26\3\26\3\26\3\26\3\26\3\26\3\26\3\26\7\26\u0286\n\26\f\26\16\26\u0289"+
		"\13\26\5\26\u028b\n\26\5\26\u028d\n\26\3\26\3\26\3\26\3\26\3\26\5\26\u0294"+
		"\n\26\3\26\3\26\5\26\u0298\n\26\3\26\3\26\3\26\3\26\3\26\5\26\u029f\n"+
		"\26\3\26\3\26\6\26\u02a3\n\26\r\26\16\26\u02a4\3\26\3\26\3\27\3\27\5\27"+
		"\u02ab\n\27\3\27\3\27\3\27\3\27\5\27\u02b1\n\27\3\27\3\27\3\27\5\27\u02b6"+
		"\n\27\3\27\3\27\3\27\3\27\3\27\7\27\u02bd\n\27\f\27\16\27\u02c0\13\27"+
		"\3\27\3\27\5\27\u02c4\n\27\3\27\3\27\3\27\3\30\3\30\3\30\3\30\3\30\3\30"+
		"\5\30\u02cf\n\30\3\30\3\30\3\30\5\30\u02d4\n\30\3\30\3\30\3\30\3\30\3"+
		"\30\3\30\3\30\7\30\u02dd\n\30\f\30\16\30\u02e0\13\30\3\30\3\30\5\30\u02e4"+
		"\n\30\3\31\3\31\5\31\u02e8\n\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31\3\31"+
		"\3\31\3\31\3\31\3\31\7\31\u02f6\n\31\f\31\16\31\u02f9\13\31\3\32\3\32"+
		"\3\32\3\32\3\32\7\32\u0300\n\32\f\32\16\32\u0303\13\32\3\32\3\32\5\32"+
		"\u0307\n\32\3\33\3\33\3\33\3\33\3\33\3\33\5\33\u030f\n\33\3\33\3\33\3"+
		"\33\3\34\3\34\3\34\3\34\3\34\7\34\u0319\n\34\f\34\16\34\u031c\13\34\3"+
		"\34\3\34\5\34\u0320\n\34\3\34\3\34\3\34\3\34\3\34\3\35\5\35\u0328\n\35"+
		"\3\35\3\35\3\35\3\35\3\35\5\35\u032f\n\35\3\36\5\36\u0332\n\36\3\36\3"+
		"\36\3\36\3\36\3\36\5\36\u0339\n\36\3\36\5\36\u033c\n\36\3\36\5\36\u033f"+
		"\n\36\3\37\3\37\5\37\u0343\n\37\3\37\3\37\3 \3 \3 \3 \5 \u034b\n \3 \3"+
		" \3 \5 \u0350\n \3 \3 \3!\3!\3!\3!\3!\3!\5!\u035a\n!\3!\3!\3!\5!\u035f"+
		"\n!\3!\3!\3!\3!\3!\3!\3!\5!\u0368\n!\3!\3!\3!\7!\u036d\n!\f!\16!\u0370"+
		"\13!\3!\5!\u0373\n!\3!\3!\5!\u0377\n!\3!\5!\u037a\n!\3!\3!\3!\3!\7!\u0380"+
		"\n!\f!\16!\u0383\13!\3!\3!\3!\3!\3!\3!\3!\3!\3!\3!\5!\u038f\n!\3!\5!\u0392"+
		"\n!\3!\3!\3!\3!\3!\3!\5!\u039a\n!\3!\3!\3!\3!\3!\6!\u03a1\n!\r!\16!\u03a2"+
		"\3!\3!\5!\u03a7\n!\3!\3!\3!\5!\u03ac\n!\3!\3!\3!\3!\3!\3!\3!\3!\3!\3!"+
		"\3!\3!\3!\3!\3!\3!\3!\3!\3!\3!\3!\3!\3!\3!\3!\3!\3!\3!\5!\u03ca\n!\3!"+
		"\3!\3!\3!\3!\3!\3!\3!\3!\3!\5!\u03d6\n!\3!\3!\3!\5!\u03db\n!\3!\3!\3!"+
		"\3!\3!\3!\3!\3!\3!\3!\5!\u03e7\n!\3!\3!\3!\3!\5!\u03ed\n!\3!\3!\3!\3!"+
		"\3!\5!\u03f4\n!\3!\3!\5!\u03f8\n!\3!\3!\3!\3!\3!\3!\7!\u0400\n!\f!\16"+
		"!\u0403\13!\5!\u0405\n!\3!\3!\3!\3!\5!\u040b\n!\3!\3!\3!\3!\5!\u0411\n"+
		"!\3!\3!\3!\3!\3!\7!\u0418\n!\f!\16!\u041b\13!\5!\u041d\n!\3!\3!\5!\u0421"+
		"\n!\7!\u0423\n!\f!\16!\u0426\13!\3\"\3\"\3\"\3\"\3\"\3\"\5\"\u042e\n\""+
		"\3\"\3\"\3#\3#\3$\5$\u0435\n$\3$\3$\3$\3$\3$\5$\u043c\n$\3$\3$\3$\3$\5"+
		"$\u0442\n$\3$\3$\3$\5$\u0447\n$\3$\3$\3$\3$\7$\u044d\n$\f$\16$\u0450\13"+
		"$\3$\3$\5$\u0454\n$\3$\3$\3$\3$\3$\7$\u045b\n$\f$\16$\u045e\13$\3$\3$"+
		"\3$\3$\3$\3$\7$\u0466\n$\f$\16$\u0469\13$\3$\3$\7$\u046d\n$\f$\16$\u0470"+
		"\13$\3$\5$\u0473\n$\3$\5$\u0476\n$\3$\3$\5$\u047a\n$\3%\3%\3%\3%\3%\3"+
		"%\7%\u0482\n%\f%\16%\u0485\13%\3%\3%\3%\5%\u048a\n%\5%\u048c\n%\3%\3%"+
		"\3%\3%\3%\3%\5%\u0494\n%\3%\3%\3%\3%\3%\5%\u049b\n%\3%\3%\3%\7%\u04a0"+
		"\n%\f%\16%\u04a3\13%\3%\3%\5%\u04a7\n%\5%\u04a9\n%\3&\3&\3&\3&\5&\u04af"+
		"\n&\3&\3&\3&\3&\3&\3&\3&\5&\u04b8\n&\3\'\3\'\3\'\5\'\u04bd\n\'\3(\3(\3"+
		"(\3(\3(\5(\u04c4\n(\3(\3(\5(\u04c8\n(\5(\u04ca\n(\3)\5)\u04cd\n)\3)\3"+
		")\3)\3)\7)\u04d3\n)\f)\16)\u04d6\13)\3)\5)\u04d9\n)\3)\5)\u04dc\n)\3*"+
		"\3*\3*\3*\5*\u04e2\n*\7*\u04e4\n*\f*\16*\u04e7\13*\3+\3+\5+\u04eb\n+\3"+
		"+\3+\3+\7+\u04f0\n+\f+\16+\u04f3\13+\3+\3+\3+\3+\7+\u04f9\n+\f+\16+\u04fc"+
		"\13+\3+\5+\u04ff\n+\5+\u0501\n+\3+\3+\5+\u0505\n+\3+\3+\3+\3+\3+\7+\u050c"+
		"\n+\f+\16+\u050f\13+\3+\3+\5+\u0513\n+\5+\u0515\n+\3+\3+\3+\3+\3+\3+\3"+
		"+\3+\3+\7+\u0520\n+\f+\16+\u0523\13+\5+\u0525\n+\3+\3+\3+\3+\3+\7+\u052c"+
		"\n+\f+\16+\u052f\13+\3+\3+\3+\3+\3+\3+\7+\u0537\n+\f+\16+\u053a\13+\3"+
		"+\3+\7+\u053e\n+\f+\16+\u0541\13+\5+\u0543\n+\3,\3,\3-\5-\u0548\n-\3-"+
		"\3-\5-\u054c\n-\3-\5-\u054f\n-\3.\5.\u0552\n.\3.\3.\3.\5.\u0557\n.\3."+
		"\3.\5.\u055b\n.\3.\6.\u055e\n.\r.\16.\u055f\3.\5.\u0563\n.\3.\5.\u0566"+
		"\n.\3/\3/\3/\5/\u056b\n/\3/\3/\5/\u056f\n/\3/\5/\u0572\n/\3/\3/\3/\3/"+
		"\3/\5/\u0579\n/\3/\3/\3/\5/\u057e\n/\3/\3/\3/\3/\3/\7/\u0585\n/\f/\16"+
		"/\u0588\13/\3/\3/\5/\u058c\n/\3/\5/\u058f\n/\3/\3/\3/\3/\7/\u0595\n/\f"+
		"/\16/\u0598\13/\3/\5/\u059b\n/\3/\3/\3/\3/\3/\3/\5/\u05a3\n/\3/\5/\u05a6"+
		"\n/\5/\u05a8\n/\3\60\3\60\3\60\3\60\3\60\3\60\3\60\5\60\u05b1\n\60\3\60"+
		"\5\60\u05b4\n\60\5\60\u05b6\n\60\3\61\3\61\5\61\u05ba\n\61\3\61\3\61\5"+
		"\61\u05be\n\61\3\61\3\61\5\61\u05c2\n\61\3\61\5\61\u05c5\n\61\3\62\3\62"+
		"\3\62\3\62\3\62\3\62\3\62\7\62\u05ce\n\62\f\62\16\62\u05d1\13\62\3\62"+
		"\3\62\5\62\u05d5\n\62\3\63\3\63\5\63\u05d9\n\63\3\63\3\63\5\63\u05dd\n"+
		"\63\3\64\5\64\u05e0\n\64\3\64\3\64\3\64\5\64\u05e5\n\64\3\64\3\64\3\64"+
		"\3\64\5\64\u05eb\n\64\3\64\3\64\3\64\3\64\3\64\5\64\u05f2\n\64\3\64\3"+
		"\64\3\64\7\64\u05f7\n\64\f\64\16\64\u05fa\13\64\3\64\3\64\5\64\u05fe\n"+
		"\64\3\65\3\65\3\65\3\65\7\65\u0604\n\65\f\65\16\65\u0607\13\65\3\65\3"+
		"\65\3\66\5\66\u060c\n\66\3\66\3\66\3\66\5\66\u0611\n\66\3\66\3\66\3\66"+
		"\3\66\5\66\u0617\n\66\3\66\3\66\3\66\3\66\3\66\5\66\u061e\n\66\3\66\3"+
		"\66\3\66\7\66\u0623\n\66\f\66\16\66\u0626\13\66\3\66\3\66\5\66\u062a\n"+
		"\66\3\66\5\66\u062d\n\66\3\66\5\66\u0630\n\66\3\67\3\67\3\67\5\67\u0635"+
		"\n\67\3\67\3\67\3\67\5\67\u063a\n\67\3\67\3\67\3\67\3\67\3\67\5\67\u0641"+
		"\n\67\38\38\58\u0645\n8\38\38\58\u0649\n8\39\39\39\39\39\39\3:\3:\5:\u0653"+
		"\n:\3:\3:\3:\3:\3:\7:\u065a\n:\f:\16:\u065d\13:\5:\u065f\n:\3:\3:\3:\3"+
		":\3:\7:\u0666\n:\f:\16:\u0669\13:\3:\5:\u066c\n:\3:\3:\3;\3;\3;\3;\5;"+
		"\u0674\n;\3;\3;\3;\3;\3;\7;\u067b\n;\f;\16;\u067e\13;\5;\u0680\n;\3;\3"+
		";\3;\3;\3;\7;\u0687\n;\f;\16;\u068a\13;\5;\u068c\n;\3;\5;\u068f\n;\3;"+
		"\5;\u0692\n;\3<\3<\3<\3<\3<\3<\3<\3<\5<\u069c\n<\3=\3=\3=\3=\3=\3=\3="+
		"\5=\u06a5\n=\3>\3>\3>\3>\3>\7>\u06ac\n>\f>\16>\u06af\13>\3>\5>\u06b2\n"+
		">\3>\3>\3?\3?\3?\5?\u06b9\n?\3?\3?\3?\7?\u06be\n?\f?\16?\u06c1\13?\3?"+
		"\5?\u06c4\n?\3?\3?\5?\u06c8\n?\3@\3@\3@\3@\3@\7@\u06cf\n@\f@\16@\u06d2"+
		"\13@\3@\5@\u06d5\n@\3@\3@\5@\u06d9\n@\3@\3@\3@\5@\u06de\n@\3A\3A\5A\u06e2"+
		"\nA\3A\3A\3A\7A\u06e7\nA\fA\16A\u06ea\13A\3B\3B\3B\3B\3B\7B\u06f1\nB\f"+
		"B\16B\u06f4\13B\3C\3C\3C\3C\5C\u06fa\nC\3D\3D\3D\5D\u06ff\nD\3D\5D\u0702"+
		"\nD\3D\3D\5D\u0706\nD\3E\3E\3F\3F\3F\3F\3F\3F\3F\3F\3F\3F\5F\u0714\nF"+
		"\3G\3G\3G\3G\3G\3G\3G\3G\3G\3G\5G\u0720\nG\3H\3H\3H\3H\3H\3H\3H\5H\u0729"+
		"\nH\3I\3I\3I\3I\3I\3I\3I\5I\u0732\nI\3I\3I\5I\u0736\nI\3I\3I\3I\3I\3I"+
		"\3I\3I\3I\5I\u0740\nI\3I\5I\u0743\nI\3I\3I\3I\3I\3I\3I\3I\5I\u074c\nI"+
		"\3I\3I\3I\3I\3I\3I\3I\5I\u0755\nI\3I\5I\u0758\nI\3I\3I\3I\3I\5I\u075e"+
		"\nI\3I\3I\3I\3I\3I\3I\3I\3I\3I\3I\3I\3I\5I\u076c\nI\3I\3I\5I\u0770\nI"+
		"\3I\3I\3I\3I\3I\3I\3I\3I\3I\5I\u077b\nI\3I\3I\3I\5I\u0780\nI\3J\3J\3J"+
		"\3K\3K\3K\3L\3L\3L\6L\u078b\nL\rL\16L\u078c\3M\3M\3M\6M\u0792\nM\rM\16"+
		"M\u0793\3N\3N\3N\3N\3O\3O\5O\u079c\nO\3O\3O\3O\5O\u07a1\nO\7O\u07a3\n"+
		"O\fO\16O\u07a6\13O\3P\3P\3Q\3Q\3R\3R\3S\3S\3T\3T\5T\u07b2\nT\3U\3U\3V"+
		"\3V\3W\3W\3X\3X\3Y\3Y\3Z\3Z\3[\3[\3\\\3\\\3]\3]\3^\3^\3_\3_\3`\3`\3a\3"+
		"a\3b\3b\3c\3c\3d\3d\3e\3e\3f\3f\3g\3g\3h\3h\3i\3i\3j\3j\3k\3k\3l\3l\3"+
		"m\3m\3n\3n\3o\3o\3o\3o\3o\3o\3o\5o\u07ef\no\3o\2\3@p\2\4\6\b\n\f\16\20"+
		"\22\24\26\30\32\34\36 \"$&(*,.\60\62\64\668:<>@BDFHJLNPRTVXZ\\^`bdfhj"+
		"lnprtvxz|~\u0080\u0082\u0084\u0086\u0088\u008a\u008c\u008e\u0090\u0092"+
		"\u0094\u0096\u0098\u009a\u009c\u009e\u00a0\u00a2\u00a4\u00a6\u00a8\u00aa"+
		"\u00ac\u00ae\u00b0\u00b2\u00b4\u00b6\u00b8\u00ba\u00bc\u00be\u00c0\u00c2"+
		"\u00c4\u00c6\u00c8\u00ca\u00cc\u00ce\u00d0\u00d2\u00d4\u00d6\u00d8\u00da"+
		"\u00dc\2\36\3\2)+\3\2-.\3\2;<\3\2HI\3\2\b\t\3\2MN\4\2CCEE\3\2)*\4\2//"+
		"X[\6\2\37\37\64\64\\\\ff\3\2\13\r\3\2\16\21\3\2\22\25\4\2TTwy\4\2//XY"+
		"\5\2CCJJ\u0081\u0087\4\2kkpp\3\2\u00a6\u00a8\4\2\6\6\u00aa\u00aa\3\2\u00ac"+
		"\u00ad\3\2\u00ae\u00af\3\2\u00b3\u00b4\3\2\u00b5\u00b6\3\2\u00b7\u00b9"+
		"\3\2\u00ba\u00bb\5\2\b\t\32\32\66\66\4\2>>\u0081\u0081\n\2\33=?IKnp\u0080"+
		"\u0083\u0089\u008d\u00a2\u00a4\u00a4\u00a6\u00bf\2\u0905\2\u00e1\3\2\2"+
		"\2\4\u00fb\3\2\2\2\6\u0117\3\2\2\2\b\u0132\3\2\2\2\n\u013c\3\2\2\2\f\u0144"+
		"\3\2\2\2\16\u014e\3\2\2\2\20\u0152\3\2\2\2\22\u015d\3\2\2\2\24\u0160\3"+
		"\2\2\2\26\u0166\3\2\2\2\30\u0188\3\2\2\2\32\u0191\3\2\2\2\34\u01ba\3\2"+
		"\2\2\36\u01c5\3\2\2\2 \u01d7\3\2\2\2\"\u020b\3\2\2\2$\u0211\3\2\2\2&\u023a"+
		"\3\2\2\2(\u0264\3\2\2\2*\u0268\3\2\2\2,\u02a8\3\2\2\2.\u02c8\3\2\2\2\60"+
		"\u02e5\3\2\2\2\62\u02fa\3\2\2\2\64\u0308\3\2\2\2\66\u0313\3\2\2\28\u0327"+
		"\3\2\2\2:\u0331\3\2\2\2<\u0340\3\2\2\2>\u0346\3\2\2\2@\u03ab\3\2\2\2B"+
		"\u0427\3\2\2\2D\u0431\3\2\2\2F\u0479\3\2\2\2H\u047b\3\2\2\2J\u04aa\3\2"+
		"\2\2L\u04bc\3\2\2\2N\u04be\3\2\2\2P\u04cc\3\2\2\2R\u04dd\3\2\2\2T\u0542"+
		"\3\2\2\2V\u0544\3\2\2\2X\u0547\3\2\2\2Z\u0551\3\2\2\2\\\u05a7\3\2\2\2"+
		"^\u05b5\3\2\2\2`\u05c4\3\2\2\2b\u05d4\3\2\2\2d\u05dc\3\2\2\2f\u05df\3"+
		"\2\2\2h\u05ff\3\2\2\2j\u060b\3\2\2\2l\u0634\3\2\2\2n\u0642\3\2\2\2p\u064a"+
		"\3\2\2\2r\u0650\3\2\2\2t\u066f\3\2\2\2v\u0693\3\2\2\2x\u069d\3\2\2\2z"+
		"\u06a6\3\2\2\2|\u06b5\3\2\2\2~\u06c9\3\2\2\2\u0080\u06df\3\2\2\2\u0082"+
		"\u06eb\3\2\2\2\u0084\u06f5\3\2\2\2\u0086\u06fb\3\2\2\2\u0088\u0707\3\2"+
		"\2\2\u008a\u0713\3\2\2\2\u008c\u071f\3\2\2\2\u008e\u0728\3\2\2\2\u0090"+
		"\u077f\3\2\2\2\u0092\u0781\3\2\2\2\u0094\u0784\3\2\2\2\u0096\u0787\3\2"+
		"\2\2\u0098\u078e\3\2\2\2\u009a\u0795\3\2\2\2\u009c\u0799\3\2\2\2\u009e"+
		"\u07a7\3\2\2\2\u00a0\u07a9\3\2\2\2\u00a2\u07ab\3\2\2\2\u00a4\u07ad\3\2"+
		"\2\2\u00a6\u07b1\3\2\2\2\u00a8\u07b3\3\2\2\2\u00aa\u07b5\3\2\2\2\u00ac"+
		"\u07b7\3\2\2\2\u00ae\u07b9\3\2\2\2\u00b0\u07bb\3\2\2\2\u00b2\u07bd\3\2"+
		"\2\2\u00b4\u07bf\3\2\2\2\u00b6\u07c1\3\2\2\2\u00b8\u07c3\3\2\2\2\u00ba"+
		"\u07c5\3\2\2\2\u00bc\u07c7\3\2\2\2\u00be\u07c9\3\2\2\2\u00c0\u07cb\3\2"+
		"\2\2\u00c2\u07cd\3\2\2\2\u00c4\u07cf\3\2\2\2\u00c6\u07d1\3\2\2\2\u00c8"+
		"\u07d3\3\2\2\2\u00ca\u07d5\3\2\2\2\u00cc\u07d7\3\2\2\2\u00ce\u07d9\3\2"+
		"\2\2\u00d0\u07db\3\2\2\2\u00d2\u07dd\3\2\2\2\u00d4\u07df\3\2\2\2\u00d6"+
		"\u07e1\3\2\2\2\u00d8\u07e3\3\2\2\2\u00da\u07e5\3\2\2\2\u00dc\u07ee\3\2"+
		"\2\2\u00de\u00e0\7\3\2\2\u00df\u00de\3\2\2\2\u00e0\u00e3\3\2\2\2\u00e1"+
		"\u00df\3\2\2\2\u00e1\u00e2\3\2\2\2\u00e2\u00e4\3\2\2\2\u00e3\u00e1\3\2"+
		"\2\2\u00e4\u00ed\5\4\3\2\u00e5\u00e7\7\3\2\2\u00e6\u00e5\3\2\2\2\u00e7"+
		"\u00e8\3\2\2\2\u00e8\u00e6\3\2\2\2\u00e8\u00e9\3\2\2\2\u00e9\u00ea\3\2"+
		"\2\2\u00ea\u00ec\5\4\3\2\u00eb\u00e6\3\2\2\2\u00ec\u00ef\3\2\2\2\u00ed"+
		"\u00eb\3\2\2\2\u00ed\u00ee\3\2\2\2\u00ee\u00f3\3\2\2\2\u00ef\u00ed\3\2"+
		"\2\2\u00f0\u00f2\7\3\2\2\u00f1\u00f0\3\2\2\2\u00f2\u00f5\3\2\2\2\u00f3"+
		"\u00f1\3\2\2\2\u00f3\u00f4\3\2\2\2\u00f4\3\3\2\2\2\u00f5\u00f3\3\2\2\2"+
		"\u00f6\u00f9\7\33\2\2\u00f7\u00f8\7\34\2\2\u00f8\u00fa\7\35\2\2\u00f9"+
		"\u00f7\3\2\2\2\u00f9\u00fa\3\2\2\2\u00fa\u00fc\3\2\2\2\u00fb\u00f6\3\2"+
		"\2\2\u00fb\u00fc\3\2\2\2\u00fc\u0115\3\2\2\2\u00fd\u0116\5\6\4\2\u00fe"+
		"\u0116\5\b\5\2\u00ff\u0116\5\n\6\2\u0100\u0116\5\f\7\2\u0101\u0116\5\16"+
		"\b\2\u0102\u0116\5\26\f\2\u0103\u0116\5\32\16\2\u0104\u0116\5*\26\2\u0105"+
		"\u0116\5,\27\2\u0106\u0116\5.\30\2\u0107\u0116\58\35\2\u0108\u0116\5:"+
		"\36\2\u0109\u0116\5<\37\2\u010a\u0116\5> \2\u010b\u0116\5F$\2\u010c\u0116"+
		"\5J&\2\u010d\u0116\5N(\2\u010e\u0116\5\24\13\2\u010f\u0116\5\20\t\2\u0110"+
		"\u0116\5\22\n\2\u0111\u0116\5P)\2\u0112\u0116\5f\64\2\u0113\u0116\5j\66"+
		"\2\u0114\u0116\5n8\2\u0115\u00fd\3\2\2\2\u0115\u00fe\3\2\2\2\u0115\u00ff"+
		"\3\2\2\2\u0115\u0100\3\2\2\2\u0115\u0101\3\2\2\2\u0115\u0102\3\2\2\2\u0115"+
		"\u0103\3\2\2\2\u0115\u0104\3\2\2\2\u0115\u0105\3\2\2\2\u0115\u0106\3\2"+
		"\2\2\u0115\u0107\3\2\2\2\u0115\u0108\3\2\2\2\u0115\u0109\3\2\2\2\u0115"+
		"\u010a\3\2\2\2\u0115\u010b\3\2\2\2\u0115\u010c\3\2\2\2\u0115\u010d\3\2"+
		"\2\2\u0115\u010e\3\2\2\2\u0115\u010f\3\2\2\2\u0115\u0110\3\2\2\2\u0115"+
		"\u0111\3\2\2\2\u0115\u0112\3\2\2\2\u0115\u0113\3\2\2\2\u0115\u0114\3\2"+
		"\2\2\u0116\5\3\2\2\2\u0117\u0118\7\36\2\2\u0118\u011c\7\37\2\2\u0119\u011a"+
		"\5\u00b0Y\2\u011a\u011b\7\4\2\2\u011b\u011d\3\2\2\2\u011c\u0119\3\2\2"+
		"\2\u011c\u011d\3\2\2\2\u011d\u011e\3\2\2\2\u011e\u0130\5\u00b2Z\2\u011f"+
		"\u0129\7 \2\2\u0120\u0121\7!\2\2\u0121\u012a\5\u00b6\\\2\u0122\u0124\7"+
		"\"\2\2\u0123\u0122\3\2\2\2\u0123\u0124\3\2\2\2\u0124\u0125\3\2\2\2\u0125"+
		"\u0126\5\u00b8]\2\u0126\u0127\7!\2\2\u0127\u0128\5\u00b8]\2\u0128\u012a"+
		"\3\2\2\2\u0129\u0120\3\2\2\2\u0129\u0123\3\2\2\2\u012a\u0131\3\2\2\2\u012b"+
		"\u012d\7#\2\2\u012c\u012e\7\"\2\2\u012d\u012c\3\2\2\2\u012d\u012e\3\2"+
		"\2\2\u012e\u012f\3\2\2\2\u012f\u0131\5\34\17\2\u0130\u011f\3\2\2\2\u0130"+
		"\u012b\3\2\2\2\u0131\7\3\2\2\2\u0132\u013a\7$\2\2\u0133\u013b\5\u00b0"+
		"Y\2\u0134\u0135\5\u00b0Y\2\u0135\u0136\7\4\2\2\u0136\u0138\3\2\2\2\u0137"+
		"\u0134\3\2\2\2\u0137\u0138\3\2\2\2\u0138\u0139\3\2\2\2\u0139\u013b\5\u00b4"+
		"[\2\u013a\u0133\3\2\2\2\u013a\u0137\3\2\2\2\u013a\u013b\3\2\2\2\u013b"+
		"\t\3\2\2\2\u013c\u013e\7%\2\2\u013d\u013f\7&\2\2\u013e\u013d\3\2\2\2\u013e"+
		"\u013f\3\2\2\2\u013f\u0140\3\2\2\2\u0140\u0141\5@!\2\u0141\u0142\7\'\2"+
		"\2\u0142\u0143\5\u00b0Y\2\u0143\13\3\2\2\2\u0144\u0146\7(\2\2\u0145\u0147"+
		"\t\2\2\2\u0146\u0145\3\2\2\2\u0146\u0147\3\2\2\2\u0147\u014c\3\2\2\2\u0148"+
		"\u014a\7,\2\2\u0149\u014b\5\u00ccg\2\u014a\u0149\3\2\2\2\u014a\u014b\3"+
		"\2\2\2\u014b\u014d\3\2\2\2\u014c\u0148\3\2\2\2\u014c\u014d\3\2\2\2\u014d"+
		"\r\3\2\2\2\u014e\u0150\t\3\2\2\u014f\u0151\7,\2\2\u0150\u014f\3\2\2\2"+
		"\u0150\u0151\3\2\2\2\u0151\17\3\2\2\2\u0152\u0154\7/\2\2\u0153\u0155\7"+
		",\2\2\u0154\u0153\3\2\2\2\u0154\u0155\3\2\2\2\u0155\u015b\3\2\2\2\u0156"+
		"\u0158\7!\2\2\u0157\u0159\7\60\2\2\u0158\u0157\3\2\2\2\u0158\u0159\3\2"+
		"\2\2\u0159\u015a\3\2\2\2\u015a\u015c\5\u00c8e\2\u015b\u0156\3\2\2\2\u015b"+
		"\u015c\3\2\2\2\u015c\21\3\2\2\2\u015d\u015e\7\60\2\2\u015e\u015f\5\u00c8"+
		"e\2\u015f\23\3\2\2\2\u0160\u0162\7\61\2\2\u0161\u0163\7\60\2\2\u0162\u0161"+
		"\3\2\2\2\u0162\u0163\3\2\2\2\u0163\u0164\3\2\2\2\u0164\u0165\5\u00c8e"+
		"\2\u0165\25\3\2\2\2\u0166\u0168\7\62\2\2\u0167\u0169\7\63\2\2\u0168\u0167"+
		"\3\2\2\2\u0168\u0169\3\2\2\2\u0169\u016a\3\2\2\2\u016a\u016e\7\64\2\2"+
		"\u016b\u016c\7\65\2\2\u016c\u016d\7\66\2\2\u016d\u016f\7\67\2\2\u016e"+
		"\u016b\3\2\2\2\u016e\u016f\3\2\2\2\u016f\u0173\3\2\2\2\u0170\u0171\5\u00b0"+
		"Y\2\u0171\u0172\7\4\2\2\u0172\u0174\3\2\2\2\u0173\u0170\3\2\2\2\u0173"+
		"\u0174\3\2\2\2\u0174\u0175\3\2\2\2\u0175\u0176\5\u00be`\2\u0176\u0177"+
		"\78\2\2\u0177\u0178\5\u00b2Z\2\u0178\u0179\7\5\2\2\u0179\u017e\5\30\r"+
		"\2\u017a\u017b\7\6\2\2\u017b\u017d\5\30\r\2\u017c\u017a\3\2\2\2\u017d"+
		"\u0180\3\2\2\2\u017e\u017c\3\2\2\2\u017e\u017f\3\2\2\2\u017f\u0181\3\2"+
		"\2\2\u0180\u017e\3\2\2\2\u0181\u0184\7\7\2\2\u0182\u0183\79\2\2\u0183"+
		"\u0185\5@!\2\u0184\u0182\3\2\2\2\u0184\u0185\3\2\2\2\u0185\27\3\2\2\2"+
		"\u0186\u0189\5\u00b8]\2\u0187\u0189\5@!\2\u0188\u0186\3\2\2\2\u0188\u0187"+
		"\3\2\2\2\u0189\u018c\3\2\2\2\u018a\u018b\7:\2\2\u018b\u018d\5\u00ba^\2"+
		"\u018c\u018a\3\2\2\2\u018c\u018d\3\2\2\2\u018d\u018f\3\2\2\2\u018e\u0190"+
		"\5\u0088E\2\u018f\u018e\3\2\2\2\u018f\u0190\3\2\2\2\u0190\31\3\2\2\2\u0191"+
		"\u0193\7\62\2\2\u0192\u0194\t\4\2\2\u0193\u0192\3\2\2\2\u0193\u0194\3"+
		"\2\2\2\u0194\u0195\3\2\2\2\u0195\u0199\7\37\2\2\u0196\u0197\7\65\2\2\u0197"+
		"\u0198\7\66\2\2\u0198\u019a\7\67\2\2\u0199\u0196\3\2\2\2\u0199\u019a\3"+
		"\2\2\2\u019a\u019e\3\2\2\2\u019b\u019c\5\u00b0Y\2\u019c\u019d\7\4\2\2"+
		"\u019d\u019f\3\2\2\2\u019e\u019b\3\2\2\2\u019e\u019f\3\2\2\2\u019f\u01a0"+
		"\3\2\2\2\u01a0\u01b8\5\u00b2Z\2\u01a1\u01a2\7\5\2\2\u01a2\u01a7\5\34\17"+
		"\2\u01a3\u01a4\7\6\2\2\u01a4\u01a6\5\34\17\2\u01a5\u01a3\3\2\2\2\u01a6"+
		"\u01a9\3\2\2\2\u01a7\u01a5\3\2\2\2\u01a7\u01a8\3\2\2\2\u01a8\u01ae\3\2"+
		"\2\2\u01a9\u01a7\3\2\2\2\u01aa\u01ab\7\6\2\2\u01ab\u01ad\5$\23\2\u01ac"+
		"\u01aa\3\2\2\2\u01ad\u01b0\3\2\2\2\u01ae\u01ac\3\2\2\2\u01ae\u01af\3\2"+
		"\2\2\u01af\u01b1\3\2\2\2\u01b0\u01ae\3\2\2\2\u01b1\u01b4\7\7\2\2\u01b2"+
		"\u01b3\7=\2\2\u01b3\u01b5\7>\2\2\u01b4\u01b2\3\2\2\2\u01b4\u01b5\3\2\2"+
		"\2\u01b5\u01b9\3\2\2\2\u01b6\u01b7\7\'\2\2\u01b7\u01b9\5P)\2\u01b8\u01a1"+
		"\3\2\2\2\u01b8\u01b6\3\2\2\2\u01b9\33\3\2\2\2\u01ba\u01bc\5\u00b8]\2\u01bb"+
		"\u01bd\5\36\20\2\u01bc\u01bb\3\2\2\2\u01bc\u01bd\3\2\2\2\u01bd\u01c1\3"+
		"\2\2\2\u01be\u01c0\5 \21\2\u01bf\u01be\3\2\2\2\u01c0\u01c3\3\2\2\2\u01c1"+
		"\u01bf\3\2\2\2\u01c1\u01c2\3\2\2\2\u01c2\35\3\2\2\2\u01c3\u01c1\3\2\2"+
		"\2\u01c4\u01c6\5\u00acW\2\u01c5\u01c4\3\2\2\2\u01c6\u01c7\3\2\2\2\u01c7"+
		"\u01c5\3\2\2\2\u01c7\u01c8\3\2\2\2\u01c8\u01d3\3\2\2\2\u01c9\u01ca\7\5"+
		"\2\2\u01ca\u01cb\5\"\22\2\u01cb\u01cc\7\7\2\2\u01cc\u01d4\3\2\2\2\u01cd"+
		"\u01ce\7\5\2\2\u01ce\u01cf\5\"\22\2\u01cf\u01d0\7\6\2\2\u01d0\u01d1\5"+
		"\"\22\2\u01d1\u01d2\7\7\2\2\u01d2\u01d4\3\2\2\2\u01d3\u01c9\3\2\2\2\u01d3"+
		"\u01cd\3\2\2\2\u01d3\u01d4\3\2\2\2\u01d4\37\3\2\2\2\u01d5\u01d6\7?\2\2"+
		"\u01d6\u01d8\5\u00acW\2\u01d7\u01d5\3\2\2\2\u01d7\u01d8\3\2\2\2\u01d8"+
		"\u0208\3\2\2\2\u01d9\u01da\7@\2\2\u01da\u01dc\7A\2\2\u01db\u01dd\5\u0088"+
		"E\2\u01dc\u01db\3\2\2\2\u01dc\u01dd\3\2\2\2\u01dd\u01df\3\2\2\2\u01de"+
		"\u01e0\5(\25\2\u01df\u01de\3\2\2\2\u01df\u01e0\3\2\2\2\u01e0\u01e2\3\2"+
		"\2\2\u01e1\u01e3\7B\2\2\u01e2\u01e1\3\2\2\2\u01e2\u01e3\3\2\2\2\u01e3"+
		"\u0209\3\2\2\2\u01e4\u01e5\7\66\2\2\u01e5\u01e8\7C\2\2\u01e6\u01e8\7\63"+
		"\2\2\u01e7\u01e4\3\2\2\2\u01e7\u01e6\3\2\2\2\u01e8\u01ea\3\2\2\2\u01e9"+
		"\u01eb\5(\25\2\u01ea\u01e9\3\2\2\2\u01ea\u01eb\3\2\2\2\u01eb\u0209\3\2"+
		"\2\2\u01ec\u01ed\7D\2\2\u01ed\u01ee\7\5\2\2\u01ee\u01ef\5@!\2\u01ef\u01f0"+
		"\7\7\2\2\u01f0\u0209\3\2\2\2\u01f1\u01f8\7E\2\2\u01f2\u01f9\5\"\22\2\u01f3"+
		"\u01f9\5D#\2\u01f4\u01f5\7\5\2\2\u01f5\u01f6\5@!\2\u01f6\u01f7\7\7\2\2"+
		"\u01f7\u01f9\3\2\2\2\u01f8\u01f2\3\2\2\2\u01f8\u01f3\3\2\2\2\u01f8\u01f4"+
		"\3\2\2\2\u01f9\u0209\3\2\2\2\u01fa\u01fb\7:\2\2\u01fb\u0209\5\u00ba^\2"+
		"\u01fc\u0209\5&\24\2\u01fd\u01fe\7F\2\2\u01fe\u0200\7G\2\2\u01ff\u01fd"+
		"\3\2\2\2\u01ff\u0200\3\2\2\2\u0200\u0201\3\2\2\2\u0201\u0202\7\'\2\2\u0202"+
		"\u0203\7\5\2\2\u0203\u0204\5@!\2\u0204\u0206\7\7\2\2\u0205\u0207\t\5\2"+
		"\2\u0206\u0205\3\2\2\2\u0206\u0207\3\2\2\2\u0207\u0209\3\2\2\2\u0208\u01d9"+
		"\3\2\2\2\u0208\u01e7\3\2\2\2\u0208\u01ec\3\2\2\2\u0208\u01f1\3\2\2\2\u0208"+
		"\u01fa\3\2\2\2\u0208\u01fc\3\2\2\2\u0208\u01ff\3\2\2\2\u0209!\3\2\2\2"+
		"\u020a\u020c\t\6\2\2\u020b\u020a\3\2\2\2\u020b\u020c\3\2\2\2\u020c\u020d"+
		"\3\2\2\2\u020d\u020e\7J\2\2\u020e#\3\2\2\2\u020f\u0210\7?\2\2\u0210\u0212"+
		"\5\u00acW\2\u0211\u020f\3\2\2\2\u0211\u0212\3\2\2\2\u0212\u0238\3\2\2"+
		"\2\u0213\u0214\7@\2\2\u0214\u0217\7A\2\2\u0215\u0217\7\63\2\2\u0216\u0213"+
		"\3\2\2\2\u0216\u0215\3\2\2\2\u0217\u0218\3\2\2\2\u0218\u0219\7\5\2\2\u0219"+
		"\u021e\5\30\r\2\u021a\u021b\7\6\2\2\u021b\u021d\5\30\r\2\u021c\u021a\3"+
		"\2\2\2\u021d\u0220\3\2\2\2\u021e\u021c\3\2\2\2\u021e\u021f\3\2\2\2\u021f"+
		"\u0221\3\2\2\2\u0220\u021e\3\2\2\2\u0221\u0223\7\7\2\2\u0222\u0224\5("+
		"\25\2\u0223\u0222\3\2\2\2\u0223\u0224\3\2\2\2\u0224\u0239\3\2\2\2\u0225"+
		"\u0226\7D\2\2\u0226\u0227\7\5\2\2\u0227\u0228\5@!\2\u0228\u0229\7\7\2"+
		"\2\u0229\u0239\3\2\2\2\u022a\u022b\7K\2\2\u022b\u022c\7A\2\2\u022c\u022d"+
		"\7\5\2\2\u022d\u0232\5\u00b8]\2\u022e\u022f\7\6\2\2\u022f\u0231\5\u00b8"+
		"]\2\u0230\u022e\3\2\2\2\u0231\u0234\3\2\2\2\u0232\u0230\3\2\2\2\u0232"+
		"\u0233\3\2\2\2\u0233\u0235\3\2\2\2\u0234\u0232\3\2\2\2\u0235\u0236\7\7"+
		"\2\2\u0236\u0237\5&\24\2\u0237\u0239\3\2\2\2\u0238\u0216\3\2\2\2\u0238"+
		"\u0225\3\2\2\2\u0238\u022a\3\2\2\2\u0239%\3\2\2\2\u023a\u023b\7L\2\2\u023b"+
		"\u0247\5\u00bc_\2\u023c\u023d\7\5\2\2\u023d\u0242\5\u00b8]\2\u023e\u023f"+
		"\7\6\2\2\u023f\u0241\5\u00b8]\2\u0240\u023e\3\2\2\2\u0241\u0244\3\2\2"+
		"\2\u0242\u0240\3\2\2\2\u0242\u0243\3\2\2\2\u0243\u0245\3\2\2\2\u0244\u0242"+
		"\3\2\2\2\u0245\u0246\7\7\2\2\u0246\u0248\3\2\2\2\u0247\u023c\3\2\2\2\u0247"+
		"\u0248\3\2\2\2\u0248\u0257\3\2\2\2\u0249\u024a\78\2\2\u024a\u0251\t\7"+
		"\2\2\u024b\u024c\7O\2\2\u024c\u0252\t\b\2\2\u024d\u0252\7P\2\2\u024e\u0252"+
		"\7Q\2\2\u024f\u0250\7R\2\2\u0250\u0252\7S\2\2\u0251\u024b\3\2\2\2\u0251"+
		"\u024d\3\2\2\2\u0251\u024e\3\2\2\2\u0251\u024f\3\2\2\2\u0252\u0256\3\2"+
		"\2\2\u0253\u0254\7T\2\2\u0254\u0256\5\u00acW\2\u0255\u0249\3\2\2\2\u0255"+
		"\u0253\3\2\2\2\u0256\u0259\3\2\2\2\u0257\u0255\3\2\2\2\u0257\u0258\3\2"+
		"\2\2\u0258\u0262\3\2\2\2\u0259\u0257\3\2\2\2\u025a\u025c\7\66\2\2\u025b"+
		"\u025a\3\2\2\2\u025b\u025c\3\2\2\2\u025c\u025d\3\2\2\2\u025d\u0260\7U"+
		"\2\2\u025e\u025f\7V\2\2\u025f\u0261\t\t\2\2\u0260\u025e\3\2\2\2\u0260"+
		"\u0261\3\2\2\2\u0261\u0263\3\2\2\2\u0262\u025b\3\2\2\2\u0262\u0263\3\2"+
		"\2\2\u0263\'\3\2\2\2\u0264\u0265\78\2\2\u0265\u0266\7W\2\2\u0266\u0267"+
		"\t\n\2\2\u0267)\3\2\2\2\u0268\u026a\7\62\2\2\u0269\u026b\t\4\2\2\u026a"+
		"\u0269\3\2\2\2\u026a\u026b\3\2\2\2\u026b\u026c\3\2\2\2\u026c\u0270\7\\"+
		"\2\2\u026d\u026e\7\65\2\2\u026e\u026f\7\66\2\2\u026f\u0271\7\67\2\2\u0270"+
		"\u026d\3\2\2\2\u0270\u0271\3\2\2\2\u0271\u0275\3\2\2\2\u0272\u0273\5\u00b0"+
		"Y\2\u0273\u0274\7\4\2\2\u0274\u0276\3\2\2\2\u0275\u0272\3\2\2\2\u0275"+
		"\u0276\3\2\2\2\u0276\u0277\3\2\2\2\u0277\u027c\5\u00c0a\2\u0278\u027d"+
		"\7]\2\2\u0279\u027d\7^\2\2\u027a\u027b\7_\2\2\u027b\u027d\7`\2\2\u027c"+
		"\u0278\3\2\2\2\u027c\u0279\3\2\2\2\u027c\u027a\3\2\2\2\u027c\u027d\3\2"+
		"\2\2\u027d\u028c\3\2\2\2\u027e\u028d\7M\2\2\u027f\u028d\7a\2\2\u0280\u028a"+
		"\7N\2\2\u0281\u0282\7`\2\2\u0282\u0287\5\u00b8]\2\u0283\u0284\7\6\2\2"+
		"\u0284\u0286\5\u00b8]\2\u0285\u0283\3\2\2\2\u0286\u0289\3\2\2\2\u0287"+
		"\u0285\3\2\2\2\u0287\u0288\3\2\2\2\u0288\u028b\3\2\2\2\u0289\u0287\3\2"+
		"\2\2\u028a\u0281\3\2\2\2\u028a\u028b\3\2\2\2\u028b\u028d\3\2\2\2\u028c"+
		"\u027e\3\2\2\2\u028c\u027f\3\2\2\2\u028c\u0280\3\2\2\2\u028d\u028e\3\2"+
		"\2\2\u028e\u028f\78\2\2\u028f\u0293\5\u00b2Z\2\u0290\u0291\7b\2\2\u0291"+
		"\u0292\7c\2\2\u0292\u0294\7d\2\2\u0293\u0290\3\2\2\2\u0293\u0294\3\2\2"+
		"\2\u0294\u0297\3\2\2\2\u0295\u0296\7e\2\2\u0296\u0298\5@!\2\u0297\u0295"+
		"\3\2\2\2\u0297\u0298\3\2\2\2\u0298\u0299\3\2\2\2\u0299\u02a2\7(\2\2\u029a"+
		"\u029f\5f\64\2\u029b\u029f\5F$\2\u029c\u029f\58\35\2\u029d\u029f\5P)\2"+
		"\u029e\u029a\3\2\2\2\u029e\u029b\3\2\2\2\u029e\u029c\3\2\2\2\u029e\u029d"+
		"\3\2\2\2\u029f\u02a0\3\2\2\2\u02a0\u02a1\7\3\2\2\u02a1\u02a3\3\2\2\2\u02a2"+
		"\u029e\3\2\2\2\u02a3\u02a4\3\2\2\2\u02a4\u02a2\3\2\2\2\u02a4\u02a5\3\2"+
		"\2\2\u02a5\u02a6\3\2\2\2\u02a6\u02a7\7.\2\2\u02a7+\3\2\2\2\u02a8\u02aa"+
		"\7\62\2\2\u02a9\u02ab\t\4\2\2\u02aa\u02a9\3\2\2\2\u02aa\u02ab\3\2\2\2"+
		"\u02ab\u02ac\3\2\2\2\u02ac\u02b0\7f\2\2\u02ad\u02ae\7\65\2\2\u02ae\u02af"+
		"\7\66\2\2\u02af\u02b1\7\67\2\2\u02b0\u02ad\3\2\2\2\u02b0\u02b1\3\2\2\2"+
		"\u02b1\u02b5\3\2\2\2\u02b2\u02b3\5\u00b0Y\2\u02b3\u02b4\7\4\2\2\u02b4"+
		"\u02b6\3\2\2\2\u02b5\u02b2\3\2\2\2\u02b5\u02b6\3\2\2\2\u02b6\u02b7\3\2"+
		"\2\2\u02b7\u02c3\5\u00c2b\2\u02b8\u02b9\7\5\2\2\u02b9\u02be\5\u00b8]\2"+
		"\u02ba\u02bb\7\6\2\2\u02bb\u02bd\5\u00b8]\2\u02bc\u02ba\3\2\2\2\u02bd"+
		"\u02c0\3\2\2\2\u02be\u02bc\3\2\2\2\u02be\u02bf\3\2\2\2\u02bf\u02c1\3\2"+
		"\2\2\u02c0\u02be\3\2\2\2\u02c1\u02c2\7\7\2\2\u02c2\u02c4\3\2\2\2\u02c3"+
		"\u02b8\3\2\2\2\u02c3\u02c4\3\2\2\2\u02c4\u02c5\3\2\2\2\u02c5\u02c6\7\'"+
		"\2\2\u02c6\u02c7\5P)\2\u02c7-\3\2\2\2\u02c8\u02c9\7\62\2\2\u02c9\u02ca"+
		"\7I\2\2\u02ca\u02ce\7\37\2\2\u02cb\u02cc\7\65\2\2\u02cc\u02cd\7\66\2\2"+
		"\u02cd\u02cf\7\67\2\2\u02ce\u02cb\3\2\2\2\u02ce\u02cf\3\2\2\2\u02cf\u02d3"+
		"\3\2\2\2\u02d0\u02d1\5\u00b0Y\2\u02d1\u02d2\7\4\2\2\u02d2\u02d4\3\2\2"+
		"\2\u02d3\u02d0\3\2\2\2\u02d3\u02d4\3\2\2\2\u02d4\u02d5\3\2\2\2\u02d5\u02d6"+
		"\5\u00b2Z\2\u02d6\u02d7\7g\2\2\u02d7\u02e3\5\u00c4c\2\u02d8\u02d9\7\5"+
		"\2\2\u02d9\u02de\5\u00a6T\2\u02da\u02db\7\6\2\2\u02db\u02dd\5\u00a6T\2"+
		"\u02dc\u02da\3\2\2\2\u02dd\u02e0\3\2\2\2\u02de\u02dc\3\2\2\2\u02de\u02df"+
		"\3\2\2\2\u02df\u02e1\3\2\2\2\u02e0\u02de\3\2\2\2\u02e1\u02e2\7\7\2\2\u02e2"+
		"\u02e4\3\2\2\2\u02e3\u02d8\3\2\2\2\u02e3\u02e4\3\2\2\2\u02e4/\3\2\2\2"+
		"\u02e5\u02e7\7h\2\2\u02e6\u02e8\7i\2\2\u02e7\u02e6\3\2\2\2\u02e7\u02e8"+
		"\3\2\2\2\u02e8\u02e9\3\2\2\2\u02e9\u02ea\5\62\32\2\u02ea\u02eb\7\'\2\2"+
		"\u02eb\u02ec\7\5\2\2\u02ec\u02ed\5P)\2\u02ed\u02f7\7\7\2\2\u02ee\u02ef"+
		"\7\6\2\2\u02ef\u02f0\5\62\32\2\u02f0\u02f1\7\'\2\2\u02f1\u02f2\7\5\2\2"+
		"\u02f2\u02f3\5P)\2\u02f3\u02f4\7\7\2\2\u02f4\u02f6\3\2\2\2\u02f5\u02ee"+
		"\3\2\2\2\u02f6\u02f9\3\2\2\2\u02f7\u02f5\3\2\2\2\u02f7\u02f8\3\2\2\2\u02f8"+
		"\61\3\2\2\2\u02f9\u02f7\3\2\2\2\u02fa\u0306\5\u00b2Z\2\u02fb\u02fc\7\5"+
		"\2\2\u02fc\u0301\5\u00b8]\2\u02fd\u02fe\7\6\2\2\u02fe\u0300\5\u00b8]\2"+
		"\u02ff\u02fd\3\2\2\2\u0300\u0303\3\2\2\2\u0301\u02ff\3\2\2\2\u0301\u0302"+
		"\3\2\2\2\u0302\u0304\3\2\2\2\u0303\u0301\3\2\2\2\u0304\u0305\7\7\2\2\u0305"+
		"\u0307\3\2\2\2\u0306\u02fb\3\2\2\2\u0306\u0307\3\2\2\2\u0307\63\3\2\2"+
		"\2\u0308\u0309\5\62\32\2\u0309\u030a\7\'\2\2\u030a\u030b\7\5\2\2\u030b"+
		"\u030c\5\u009eP\2\u030c\u030e\7j\2\2\u030d\u030f\7k\2\2\u030e\u030d\3"+
		"\2\2\2\u030e\u030f\3\2\2\2\u030f\u0310\3\2\2\2\u0310\u0311\5\u00a0Q\2"+
		"\u0311\u0312\7\7\2\2\u0312\65\3\2\2\2\u0313\u031f\5\u00b2Z\2\u0314\u0315"+
		"\7\5\2\2\u0315\u031a\5\u00b8]\2\u0316\u0317\7\6\2\2\u0317\u0319\5\u00b8"+
		"]\2\u0318\u0316\3\2\2\2\u0319\u031c\3\2\2\2\u031a\u0318\3\2\2\2\u031a"+
		"\u031b\3\2\2\2\u031b\u031d\3\2\2\2\u031c\u031a\3\2\2\2\u031d\u031e\7\7"+
		"\2\2\u031e\u0320\3\2\2\2\u031f\u0314\3\2\2\2\u031f\u0320\3\2\2\2\u0320"+
		"\u0321\3\2\2\2\u0321\u0322\7\'\2\2\u0322\u0323\7\5\2\2\u0323\u0324\5P"+
		")\2\u0324\u0325\7\7\2\2\u0325\67\3\2\2\2\u0326\u0328\5\60\31\2\u0327\u0326"+
		"\3\2\2\2\u0327\u0328\3\2\2\2\u0328\u0329\3\2\2\2\u0329\u032a\7M\2\2\u032a"+
		"\u032b\7l\2\2\u032b\u032e\5l\67\2\u032c\u032d\79\2\2\u032d\u032f\5@!\2"+
		"\u032e\u032c\3\2\2\2\u032e\u032f\3\2\2\2\u032f9\3\2\2\2\u0330\u0332\5"+
		"\60\31\2\u0331\u0330\3\2\2\2\u0331\u0332\3\2\2\2\u0332\u0333\3\2\2\2\u0333"+
		"\u0334\7M\2\2\u0334\u0335\7l\2\2\u0335\u0338\5l\67\2\u0336\u0337\79\2"+
		"\2\u0337\u0339\5@!\2\u0338\u0336\3\2\2\2\u0338\u0339\3\2\2\2\u0339\u033e"+
		"\3\2\2\2\u033a\u033c\5\u0082B\2\u033b\u033a\3\2\2\2\u033b\u033c\3\2\2"+
		"\2\u033c\u033d\3\2\2\2\u033d\u033f\5\u0084C\2\u033e\u033b\3\2\2\2\u033e"+
		"\u033f\3\2\2\2\u033f;\3\2\2\2\u0340\u0342\7m\2\2\u0341\u0343\7&\2\2\u0342"+
		"\u0341\3\2\2\2\u0342\u0343\3\2\2\2\u0343\u0344\3\2\2\2\u0344\u0345\5\u00b0"+
		"Y\2\u0345=\3\2\2\2\u0346\u0347\7n\2\2\u0347\u034a\t\13\2\2\u0348\u0349"+
		"\7\65\2\2\u0349\u034b\7\67\2\2\u034a\u0348\3\2\2\2\u034a\u034b\3\2\2\2"+
		"\u034b\u034f\3\2\2\2\u034c\u034d\5\u00b0Y\2\u034d\u034e\7\4\2\2\u034e"+
		"\u0350\3\2\2\2\u034f\u034c\3\2\2\2\u034f\u0350\3\2\2\2\u0350\u0351\3\2"+
		"\2\2\u0351\u0352\5\u00dco\2\u0352?\3\2\2\2\u0353\u0354\b!\1\2\u0354\u03ac"+
		"\5D#\2\u0355\u03ac\7o\2\2\u0356\u0357\5\u00b0Y\2\u0357\u0358\7\4\2\2\u0358"+
		"\u035a\3\2\2\2\u0359\u0356\3\2\2\2\u0359\u035a\3\2\2\2\u035a\u035b\3\2"+
		"\2\2\u035b\u035c\5\u00b2Z\2\u035c\u035d\7\4\2\2\u035d\u035f\3\2\2\2\u035e"+
		"\u0359\3\2\2\2\u035e\u035f\3\2\2\2\u035f\u0360\3\2\2\2\u0360\u03ac\5\u00b8"+
		"]\2\u0361\u0362\5\u00a2R\2\u0362\u0363\5@!\27\u0363\u03ac\3\2\2\2\u0364"+
		"\u0365\5\u00aeX\2\u0365\u0372\7\5\2\2\u0366\u0368\7p\2\2\u0367\u0366\3"+
		"\2\2\2\u0367\u0368\3\2\2\2\u0368\u0369\3\2\2\2\u0369\u036e\5@!\2\u036a"+
		"\u036b\7\6\2\2\u036b\u036d\5@!\2\u036c\u036a\3\2\2\2\u036d\u0370\3\2\2"+
		"\2\u036e\u036c\3\2\2\2\u036e\u036f\3\2\2\2\u036f\u0373\3\2\2\2\u0370\u036e"+
		"\3\2\2\2\u0371\u0373\7\13\2\2\u0372\u0367\3\2\2\2\u0372\u0371\3\2\2\2"+
		"\u0372\u0373\3\2\2\2\u0373\u0374\3\2\2\2\u0374\u0376\7\7\2\2\u0375\u0377"+
		"\5p9\2\u0376\u0375\3\2\2\2\u0376\u0377\3\2\2\2\u0377\u0379\3\2\2\2\u0378"+
		"\u037a\5t;\2\u0379\u0378\3\2\2\2\u0379\u037a\3\2\2\2\u037a\u03ac\3\2\2"+
		"\2\u037b\u037c\7\5\2\2\u037c\u0381\5@!\2\u037d\u037e\7\6\2\2\u037e\u0380"+
		"\5@!\2\u037f\u037d\3\2\2\2\u0380\u0383\3\2\2\2\u0381\u037f\3\2\2\2\u0381"+
		"\u0382\3\2\2\2\u0382\u0384\3\2\2\2\u0383\u0381\3\2\2\2\u0384\u0385\7\7"+
		"\2\2\u0385\u03ac\3\2\2\2\u0386\u0387\7q\2\2\u0387\u0388\7\5\2\2\u0388"+
		"\u0389\5@!\2\u0389\u038a\7\'\2\2\u038a\u038b\5\36\20\2\u038b\u038c\7\7"+
		"\2\2\u038c\u03ac\3\2\2\2\u038d\u038f\7\66\2\2\u038e\u038d\3\2\2\2\u038e"+
		"\u038f\3\2\2\2\u038f\u0390\3\2\2\2\u0390\u0392\7\67\2\2\u0391\u038e\3"+
		"\2\2\2\u0391\u0392\3\2\2\2\u0392\u0393\3\2\2\2\u0393\u0394\7\5\2\2\u0394"+
		"\u0395\5P)\2\u0395\u0396\7\7\2\2\u0396\u03ac\3\2\2\2\u0397\u0399\7r\2"+
		"\2\u0398\u039a\5@!\2\u0399\u0398\3\2\2\2\u0399\u039a\3\2\2\2\u039a\u03a0"+
		"\3\2\2\2\u039b\u039c\7e\2\2\u039c\u039d\5@!\2\u039d\u039e\7s\2\2\u039e"+
		"\u039f\5@!\2\u039f\u03a1\3\2\2\2\u03a0\u039b\3\2\2\2\u03a1\u03a2\3\2\2"+
		"\2\u03a2\u03a0\3\2\2\2\u03a2\u03a3\3\2\2\2\u03a3\u03a6\3\2\2\2\u03a4\u03a5"+
		"\7t\2\2\u03a5\u03a7\5@!\2\u03a6\u03a4\3\2\2\2\u03a6\u03a7\3\2\2\2\u03a7"+
		"\u03a8\3\2\2\2\u03a8\u03a9\7.\2\2\u03a9\u03ac\3\2\2\2\u03aa\u03ac\5B\""+
		"\2\u03ab\u0353\3\2\2\2\u03ab\u0355\3\2\2\2\u03ab\u035e\3\2\2\2\u03ab\u0361"+
		"\3\2\2\2\u03ab\u0364\3\2\2\2\u03ab\u037b\3\2\2\2\u03ab\u0386\3\2\2\2\u03ab"+
		"\u0391\3\2\2\2\u03ab\u0397\3\2\2\2\u03ab\u03aa\3\2\2\2\u03ac\u0424\3\2"+
		"\2\2\u03ad\u03ae\f\26\2\2\u03ae\u03af\7\n\2\2\u03af\u0423\5@!\27\u03b0"+
		"\u03b1\f\25\2\2\u03b1\u03b2\t\f\2\2\u03b2\u0423\5@!\26\u03b3\u03b4\f\24"+
		"\2\2\u03b4\u03b5\t\6\2\2\u03b5\u0423\5@!\25\u03b6\u03b7\f\23\2\2\u03b7"+
		"\u03b8\t\r\2\2\u03b8\u0423\5@!\24\u03b9\u03ba\f\22\2\2\u03ba\u03bb\t\16"+
		"\2\2\u03bb\u0423\5@!\23\u03bc\u03c9\f\21\2\2\u03bd\u03ca\7\26\2\2\u03be"+
		"\u03ca\7\27\2\2\u03bf\u03ca\7\30\2\2\u03c0\u03ca\7\31\2\2\u03c1\u03ca"+
		"\7u\2\2\u03c2\u03c3\7u\2\2\u03c3\u03ca\7\66\2\2\u03c4\u03ca\7v\2\2\u03c5"+
		"\u03ca\7w\2\2\u03c6\u03ca\7x\2\2\u03c7\u03ca\7T\2\2\u03c8\u03ca\7y\2\2"+
		"\u03c9\u03bd\3\2\2\2\u03c9\u03be\3\2\2\2\u03c9\u03bf\3\2\2\2\u03c9\u03c0"+
		"\3\2\2\2\u03c9\u03c1\3\2\2\2\u03c9\u03c2\3\2\2\2\u03c9\u03c4\3\2\2\2\u03c9"+
		"\u03c5\3\2\2\2\u03c9\u03c6\3\2\2\2\u03c9\u03c7\3\2\2\2\u03c9\u03c8\3\2"+
		"\2\2\u03ca\u03cb\3\2\2\2\u03cb\u0423\5@!\22\u03cc\u03cd\f\20\2\2\u03cd"+
		"\u03ce\7z\2\2\u03ce\u0423\5@!\21\u03cf\u03d0\f\17\2\2\u03d0\u03d1\7{\2"+
		"\2\u03d1\u0423\5@!\20\u03d2\u03d3\f\b\2\2\u03d3\u03d5\7u\2\2\u03d4\u03d6"+
		"\7\66\2\2\u03d5\u03d4\3\2\2\2\u03d5\u03d6\3\2\2\2\u03d6\u03d7\3\2\2\2"+
		"\u03d7\u0423\5@!\t\u03d8\u03da\f\7\2\2\u03d9\u03db\7\66\2\2\u03da\u03d9"+
		"\3\2\2\2\u03da\u03db\3\2\2\2\u03db\u03dc\3\2\2\2\u03dc\u03dd\7|\2\2\u03dd"+
		"\u03de\5@!\2\u03de\u03df\7z\2\2\u03df\u03e0\5@!\b\u03e0\u0423\3\2\2\2"+
		"\u03e1\u03e2\f\13\2\2\u03e2\u03e3\7:\2\2\u03e3\u0423\5\u00ba^\2\u03e4"+
		"\u03e6\f\n\2\2\u03e5\u03e7\7\66\2\2\u03e6\u03e5\3\2\2\2\u03e6\u03e7\3"+
		"\2\2\2\u03e7\u03e8\3\2\2\2\u03e8\u03e9\t\17\2\2\u03e9\u03ec\5@!\2\u03ea"+
		"\u03eb\7}\2\2\u03eb\u03ed\5@!\2\u03ec\u03ea\3\2\2\2\u03ec\u03ed\3\2\2"+
		"\2\u03ed\u0423\3\2\2\2\u03ee\u03f3\f\t\2\2\u03ef\u03f4\7~\2\2\u03f0\u03f4"+
		"\7\177\2\2\u03f1\u03f2\7\66\2\2\u03f2\u03f4\7C\2\2\u03f3\u03ef\3\2\2\2"+
		"\u03f3\u03f0\3\2\2\2\u03f3\u03f1\3\2\2\2\u03f4\u0423\3\2\2\2\u03f5\u03f7"+
		"\f\6\2\2\u03f6\u03f8\7\66\2\2\u03f7\u03f6\3\2\2\2\u03f7\u03f8\3\2\2\2"+
		"\u03f8\u03f9\3\2\2\2\u03f9\u0420\7v\2\2\u03fa\u0404\7\5\2\2\u03fb\u0405"+
		"\5P)\2\u03fc\u0401\5@!\2\u03fd\u03fe\7\6\2\2\u03fe\u0400\5@!\2\u03ff\u03fd"+
		"\3\2\2\2\u0400\u0403\3\2\2\2\u0401\u03ff\3\2\2\2\u0401\u0402\3\2\2\2\u0402"+
		"\u0405\3\2\2\2\u0403\u0401\3\2\2\2\u0404\u03fb\3\2\2\2\u0404\u03fc\3\2"+
		"\2\2\u0404\u0405\3\2\2\2\u0405\u0406\3\2\2\2\u0406\u0421\7\7\2\2\u0407"+
		"\u0408\5\u00b0Y\2\u0408\u0409\7\4\2\2\u0409\u040b\3\2\2\2\u040a\u0407"+
		"\3\2\2\2\u040a\u040b\3\2\2\2\u040b\u040c\3\2\2\2\u040c\u0421\5\u00b2Z"+
		"\2\u040d\u040e\5\u00b0Y\2\u040e\u040f\7\4\2\2\u040f\u0411\3\2\2\2\u0410"+
		"\u040d\3\2\2\2\u0410\u0411\3\2\2\2\u0411\u0412\3\2\2\2\u0412\u0413\5\u00da"+
		"n\2\u0413\u041c\7\5\2\2\u0414\u0419\5@!\2\u0415\u0416\7\6\2\2\u0416\u0418"+
		"\5@!\2\u0417\u0415\3\2\2\2\u0418\u041b\3\2\2\2\u0419\u0417\3\2\2\2\u0419"+
		"\u041a\3\2\2\2\u041a\u041d\3\2\2\2\u041b\u0419\3\2\2\2\u041c\u0414\3\2"+
		"\2\2\u041c\u041d\3\2\2\2\u041d\u041e\3\2\2\2\u041e\u041f\7\7\2\2\u041f"+
		"\u0421\3\2\2\2\u0420\u03fa\3\2\2\2\u0420\u040a\3\2\2\2\u0420\u0410\3\2"+
		"\2\2\u0421\u0423\3\2\2\2\u0422\u03ad\3\2\2\2\u0422\u03b0\3\2\2\2\u0422"+
		"\u03b3\3\2\2\2\u0422\u03b6\3\2\2\2\u0422\u03b9\3\2\2\2\u0422\u03bc\3\2"+
		"\2\2\u0422\u03cc\3\2\2\2\u0422\u03cf\3\2\2\2\u0422\u03d2\3\2\2\2\u0422"+
		"\u03d8\3\2\2\2\u0422\u03e1\3\2\2\2\u0422\u03e4\3\2\2\2\u0422\u03ee\3\2"+
		"\2\2\u0422\u03f5\3\2\2\2\u0423\u0426\3\2\2\2\u0424\u0422\3\2\2\2\u0424"+
		"\u0425\3\2\2\2\u0425A\3\2\2\2\u0426\u0424\3\2\2\2\u0427\u0428\7\u0080"+
		"\2\2\u0428\u042d\7\5\2\2\u0429\u042e\7Z\2\2\u042a\u042b\t\20\2\2\u042b"+
		"\u042c\7\6\2\2\u042c\u042e\5\u00a4S\2\u042d\u0429\3\2\2\2\u042d\u042a"+
		"\3\2\2\2\u042e\u042f\3\2\2\2\u042f\u0430\7\7\2\2\u0430C\3\2\2\2\u0431"+
		"\u0432\t\21\2\2\u0432E\3\2\2\2\u0433\u0435\5\60\31\2\u0434\u0433\3\2\2"+
		"\2\u0434\u0435\3\2\2\2\u0435\u043b\3\2\2\2\u0436\u043c\7a\2\2\u0437\u043c"+
		"\7[\2\2\u0438\u0439\7a\2\2\u0439\u043a\7{\2\2\u043a\u043c\t\n\2\2\u043b"+
		"\u0436\3\2\2\2\u043b\u0437\3\2\2\2\u043b\u0438\3\2\2\2\u043c\u043d\3\2"+
		"\2\2\u043d\u0441\7\u0088\2\2\u043e\u043f\5\u00b0Y\2\u043f\u0440\7\4\2"+
		"\2\u0440\u0442\3\2\2\2\u0441\u043e\3\2\2\2\u0441\u0442\3\2\2\2\u0442\u0443"+
		"\3\2\2\2\u0443\u0446\5\u00b2Z\2\u0444\u0445\7\'\2\2\u0445\u0447\5\u00ca"+
		"f\2\u0446\u0444\3\2\2\2\u0446\u0447\3\2\2\2\u0447\u0453\3\2\2\2\u0448"+
		"\u0449\7\5\2\2\u0449\u044e\5\u00b8]\2\u044a\u044b\7\6\2\2\u044b\u044d"+
		"\5\u00b8]\2\u044c\u044a\3\2\2\2\u044d\u0450\3\2\2\2\u044e\u044c\3\2\2"+
		"\2\u044e\u044f\3\2\2\2\u044f\u0451\3\2\2\2\u0450\u044e\3\2\2\2\u0451\u0452"+
		"\7\7\2\2\u0452\u0454\3\2\2\2\u0453\u0448\3\2\2\2\u0453\u0454\3\2\2\2\u0454"+
		"\u0472\3\2\2\2\u0455\u0456\7\u0089\2\2\u0456\u0457\7\5\2\2\u0457\u045c"+
		"\5@!\2\u0458\u0459\7\6\2\2\u0459\u045b\5@!\2\u045a\u0458\3\2\2\2\u045b"+
		"\u045e\3\2\2\2\u045c\u045a\3\2\2\2\u045c\u045d\3\2\2\2\u045d\u045f\3\2"+
		"\2\2\u045e\u045c\3\2\2\2\u045f\u046e\7\7\2\2\u0460\u0461\7\6\2\2\u0461"+
		"\u0462\7\5\2\2\u0462\u0467\5@!\2\u0463\u0464\7\6\2\2\u0464\u0466\5@!\2"+
		"\u0465\u0463\3\2\2\2\u0466\u0469\3\2\2\2\u0467\u0465\3\2\2\2\u0467\u0468"+
		"\3\2\2\2\u0468\u046a\3\2\2\2\u0469\u0467\3\2\2\2\u046a\u046b\7\7\2\2\u046b"+
		"\u046d\3\2\2\2\u046c\u0460\3\2\2\2\u046d\u0470\3\2\2\2\u046e\u046c\3\2"+
		"\2\2\u046e\u046f\3\2\2\2\u046f\u0473\3\2\2\2\u0470\u046e\3\2\2\2\u0471"+
		"\u0473\5P)\2\u0472\u0455\3\2\2\2\u0472\u0471\3\2\2\2\u0473\u0475\3\2\2"+
		"\2\u0474\u0476\5H%\2\u0475\u0474\3\2\2\2\u0475\u0476\3\2\2\2\u0476\u047a"+
		"\3\2\2\2\u0477\u0478\7E\2\2\u0478\u047a\7\u0089\2\2\u0479\u0434\3\2\2"+
		"\2\u0479\u0477\3\2\2\2\u047aG\3\2\2\2\u047b\u047c\78\2\2\u047c\u048b\7"+
		"W\2\2\u047d\u047e\7\5\2\2\u047e\u0483\5\30\r\2\u047f\u0480\7\6\2\2\u0480"+
		"\u0482\5\30\r\2\u0481\u047f\3\2\2\2\u0482\u0485\3\2\2\2\u0483\u0481\3"+
		"\2\2\2\u0483\u0484\3\2\2\2\u0484\u0486\3\2\2\2\u0485\u0483\3\2\2\2\u0486"+
		"\u0489\7\7\2\2\u0487\u0488\79\2\2\u0488\u048a\5@!\2\u0489\u0487\3\2\2"+
		"\2\u0489\u048a\3\2\2\2\u048a\u048c\3\2\2\2\u048b\u047d\3\2\2\2\u048b\u048c"+
		"\3\2\2\2\u048c\u048d\3\2\2\2\u048d\u04a8\7\u008a\2\2\u048e\u04a9\7\u008b"+
		"\2\2\u048f\u0490\7N\2\2\u0490\u0493\7O\2\2\u0491\u0494\5\u00b8]\2\u0492"+
		"\u0494\5h\65\2\u0493\u0491\3\2\2\2\u0493\u0492\3\2\2\2\u0494\u0495\3\2"+
		"\2\2\u0495\u0496\7\u008c\2\2\u0496\u04a1\5@!\2\u0497\u049a\7\6\2\2\u0498"+
		"\u049b\5\u00b8]\2\u0499\u049b\5h\65\2\u049a\u0498\3\2\2\2\u049a\u0499"+
		"\3\2\2\2\u049b\u049c\3\2\2\2\u049c\u049d\7\u008c\2\2\u049d\u049e\5@!\2"+
		"\u049e\u04a0\3\2\2\2\u049f\u0497\3\2\2\2\u04a0\u04a3\3\2\2\2\u04a1\u049f"+
		"\3\2\2\2\u04a1\u04a2\3\2\2\2\u04a2\u04a6\3\2\2\2\u04a3\u04a1\3\2\2\2\u04a4"+
		"\u04a5\79\2\2\u04a5\u04a7\5@!\2\u04a6\u04a4\3\2\2\2\u04a6\u04a7\3\2\2"+
		"\2\u04a7\u04a9\3\2\2\2\u04a8\u048e\3\2\2\2\u04a8\u048f\3\2\2\2\u04a9I"+
		"\3\2\2\2\u04aa\u04ae\7\u008d\2\2\u04ab\u04ac\5\u00b0Y\2\u04ac\u04ad\7"+
		"\4\2\2\u04ad\u04af\3\2\2\2\u04ae\u04ab\3\2\2\2\u04ae\u04af\3\2\2\2\u04af"+
		"\u04b0\3\2\2\2\u04b0\u04b7\5\u00c6d\2\u04b1\u04b2\7\26\2\2\u04b2\u04b8"+
		"\5L\'\2\u04b3\u04b4\7\5\2\2\u04b4\u04b5\5L\'\2\u04b5\u04b6\7\7\2\2\u04b6"+
		"\u04b8\3\2\2\2\u04b7\u04b1\3\2\2\2\u04b7\u04b3\3\2\2\2\u04b7\u04b8\3\2"+
		"\2\2\u04b8K\3\2\2\2\u04b9\u04bd\5\"\22\2\u04ba\u04bd\5\u00acW\2\u04bb"+
		"\u04bd\7\u0081\2\2\u04bc\u04b9\3\2\2\2\u04bc\u04ba\3\2\2\2\u04bc\u04bb"+
		"\3\2\2\2\u04bdM\3\2\2\2\u04be\u04c9\7\u008e\2\2\u04bf\u04ca\5\u00ba^\2"+
		"\u04c0\u04c1\5\u00b0Y\2\u04c1\u04c2\7\4\2\2\u04c2\u04c4\3\2\2\2\u04c3"+
		"\u04c0\3\2\2\2\u04c3\u04c4\3\2\2\2\u04c4\u04c7\3\2\2\2\u04c5\u04c8\5\u00b2"+
		"Z\2\u04c6\u04c8\5\u00be`\2\u04c7\u04c5\3\2\2\2\u04c7\u04c6\3\2\2\2\u04c8"+
		"\u04ca\3\2\2\2\u04c9\u04bf\3\2\2\2\u04c9\u04c3\3\2\2\2\u04c9\u04ca\3\2"+
		"\2\2\u04caO\3\2\2\2\u04cb\u04cd\5\u0080A\2\u04cc\u04cb\3\2\2\2\u04cc\u04cd"+
		"\3\2\2\2\u04cd\u04ce\3\2\2\2\u04ce\u04d4\5T+\2\u04cf\u04d0\5d\63\2\u04d0"+
		"\u04d1\5T+\2\u04d1\u04d3\3\2\2\2\u04d2\u04cf\3\2\2\2\u04d3\u04d6\3\2\2"+
		"\2\u04d4\u04d2\3\2\2\2\u04d4\u04d5\3\2\2\2\u04d5\u04d8\3\2\2\2\u04d6\u04d4"+
		"\3\2\2\2\u04d7\u04d9\5\u0082B\2\u04d8\u04d7\3\2\2\2\u04d8\u04d9\3\2\2"+
		"\2\u04d9\u04db\3\2\2\2\u04da\u04dc\5\u0084C\2\u04db\u04da\3\2\2\2\u04db"+
		"\u04dc\3\2\2\2\u04dcQ\3\2\2\2\u04dd\u04e5\5\\/\2\u04de\u04df\5`\61\2\u04df"+
		"\u04e1\5\\/\2\u04e0\u04e2\5b\62\2\u04e1\u04e0\3\2\2\2\u04e1\u04e2\3\2"+
		"\2\2\u04e2\u04e4\3\2\2\2\u04e3\u04de\3\2\2\2\u04e4\u04e7\3\2\2\2\u04e5"+
		"\u04e3\3\2\2\2\u04e5\u04e6\3\2\2\2\u04e6S\3\2\2\2\u04e7\u04e5\3\2\2\2"+
		"\u04e8\u04ea\7\u008f\2\2\u04e9\u04eb\t\22\2\2\u04ea\u04e9\3\2\2\2\u04ea"+
		"\u04eb\3\2\2\2\u04eb\u04ec\3\2\2\2\u04ec\u04f1\5^\60\2\u04ed\u04ee\7\6"+
		"\2\2\u04ee\u04f0\5^\60\2\u04ef\u04ed\3\2\2\2\u04f0\u04f3\3\2\2\2\u04f1"+
		"\u04ef\3\2\2\2\u04f1\u04f2\3\2\2\2\u04f2\u0500\3\2\2\2\u04f3\u04f1\3\2"+
		"\2\2\u04f4\u04fe\7l\2\2\u04f5\u04fa\5\\/\2\u04f6\u04f7\7\6\2\2\u04f7\u04f9"+
		"\5\\/\2\u04f8\u04f6\3\2\2\2\u04f9\u04fc\3\2\2\2\u04fa\u04f8\3\2\2\2\u04fa"+
		"\u04fb\3\2\2\2\u04fb\u04ff\3\2\2\2\u04fc\u04fa\3\2\2\2\u04fd\u04ff\5R"+
		"*\2\u04fe\u04f5\3\2\2\2\u04fe\u04fd\3\2\2\2\u04ff\u0501\3\2\2\2\u0500"+
		"\u04f4\3\2\2\2\u0500\u0501\3\2\2\2\u0501\u0504\3\2\2\2\u0502\u0503\79"+
		"\2\2\u0503\u0505\5@!\2\u0504\u0502\3\2\2\2\u0504\u0505\3\2\2\2\u0505\u0514"+
		"\3\2\2\2\u0506\u0507\7\u0090\2\2\u0507\u0508\7\u0091\2\2\u0508\u050d\5"+
		"@!\2\u0509\u050a\7\6\2\2\u050a\u050c\5@!\2\u050b\u0509\3\2\2\2\u050c\u050f"+
		"\3\2\2\2\u050d\u050b\3\2\2\2\u050d\u050e\3\2\2\2\u050e\u0512\3\2\2\2\u050f"+
		"\u050d\3\2\2\2\u0510\u0511\7\u0092\2\2\u0511\u0513\5@!\2\u0512\u0510\3"+
		"\2\2\2\u0512\u0513\3\2\2\2\u0513\u0515\3\2\2\2\u0514\u0506\3\2\2\2\u0514"+
		"\u0515\3\2\2\2\u0515\u0524\3\2\2\2\u0516\u0517\7\u0093\2\2\u0517\u0518"+
		"\5\u00ceh\2\u0518\u0519\7\'\2\2\u0519\u0521\5r:\2\u051a\u051b\7\6\2\2"+
		"\u051b\u051c\5\u00ceh\2\u051c\u051d\7\'\2\2\u051d\u051e\5r:\2\u051e\u0520"+
		"\3\2\2\2\u051f\u051a\3\2\2\2\u0520\u0523\3\2\2\2\u0521\u051f\3\2\2\2\u0521"+
		"\u0522\3\2\2\2\u0522\u0525\3\2\2\2\u0523\u0521\3\2\2\2\u0524\u0516\3\2"+
		"\2\2\u0524\u0525\3\2\2\2\u0525\u0543\3\2\2\2\u0526\u0527\7\u0089\2\2\u0527"+
		"\u0528\7\5\2\2\u0528\u052d\5@!\2\u0529\u052a\7\6\2\2\u052a\u052c\5@!\2"+
		"\u052b\u0529\3\2\2\2\u052c\u052f\3\2\2\2\u052d\u052b\3\2\2\2\u052d\u052e"+
		"\3\2\2\2\u052e\u0530\3\2\2\2\u052f\u052d\3\2\2\2\u0530\u053f\7\7\2\2\u0531"+
		"\u0532\7\6\2\2\u0532\u0533\7\5\2\2\u0533\u0538\5@!\2\u0534\u0535\7\6\2"+
		"\2\u0535\u0537\5@!\2\u0536\u0534\3\2\2\2\u0537\u053a\3\2\2\2\u0538\u0536"+
		"\3\2\2\2\u0538\u0539\3\2\2\2\u0539\u053b\3\2\2\2\u053a\u0538\3\2\2\2\u053b"+
		"\u053c\7\7\2\2\u053c\u053e\3\2\2\2\u053d\u0531\3\2\2\2\u053e\u0541\3\2"+
		"\2\2\u053f\u053d\3\2\2\2\u053f\u0540\3\2\2\2\u0540\u0543\3\2\2\2\u0541"+
		"\u053f\3\2\2\2\u0542\u04e8\3\2\2\2\u0542\u0526\3\2\2\2\u0543U\3\2\2\2"+
		"\u0544\u0545\5P)\2\u0545W\3\2\2\2\u0546\u0548\5\u0080A\2\u0547\u0546\3"+
		"\2\2\2\u0547\u0548\3\2\2\2\u0548\u0549\3\2\2\2\u0549\u054b\5T+\2\u054a"+
		"\u054c\5\u0082B\2\u054b\u054a\3\2\2\2\u054b\u054c\3\2\2\2\u054c\u054e"+
		"\3\2\2\2\u054d\u054f\5\u0084C\2\u054e\u054d\3\2\2\2\u054e\u054f\3\2\2"+
		"\2\u054fY\3\2\2\2\u0550\u0552\5\u0080A\2\u0551\u0550\3\2\2\2\u0551\u0552"+
		"\3\2\2\2\u0552\u0553\3\2\2\2\u0553\u055d\5T+\2\u0554\u0556\7j\2\2\u0555"+
		"\u0557\7k\2\2\u0556\u0555\3\2\2\2\u0556\u0557\3\2\2\2\u0557\u055b\3\2"+
		"\2\2\u0558\u055b\7\u0094\2\2\u0559\u055b\7\u0095\2\2\u055a\u0554\3\2\2"+
		"\2\u055a\u0558\3\2\2\2\u055a\u0559\3\2\2\2\u055b\u055c\3\2\2\2\u055c\u055e"+
		"\5T+\2\u055d\u055a\3\2\2\2\u055e\u055f\3\2\2\2\u055f\u055d\3\2\2\2\u055f"+
		"\u0560\3\2\2\2\u0560\u0562\3\2\2\2\u0561\u0563\5\u0082B\2\u0562\u0561"+
		"\3\2\2\2\u0562\u0563\3\2\2\2\u0563\u0565\3\2\2\2\u0564\u0566\5\u0084C"+
		"\2\u0565\u0564\3\2\2\2\u0565\u0566\3\2\2\2\u0566[\3\2\2\2\u0567\u0568"+
		"\5\u00b0Y\2\u0568\u0569\7\4\2\2\u0569\u056b\3\2\2\2\u056a\u0567\3\2\2"+
		"\2\u056a\u056b\3\2\2\2\u056b\u056c\3\2\2\2\u056c\u0571\5\u00b2Z\2\u056d"+
		"\u056f\7\'\2\2\u056e\u056d\3\2\2\2\u056e\u056f\3\2\2\2\u056f\u0570\3\2"+
		"\2\2\u0570\u0572\5\u00caf\2\u0571\u056e\3\2\2\2\u0571\u0572\3\2\2\2\u0572"+
		"\u0578\3\2\2\2\u0573\u0574\7\u0096\2\2\u0574\u0575\7\u0091\2\2\u0575\u0579"+
		"\5\u00be`\2\u0576\u0577\7\66\2\2\u0577\u0579\7\u0096\2\2\u0578\u0573\3"+
		"\2\2\2\u0578\u0576\3\2\2\2\u0578\u0579\3\2\2\2\u0579\u05a8\3\2\2\2\u057a"+
		"\u057b\5\u00b0Y\2\u057b\u057c\7\4\2\2\u057c\u057e\3\2\2\2\u057d\u057a"+
		"\3\2\2\2\u057d\u057e\3\2\2\2\u057e\u057f\3\2\2\2\u057f\u0580\5\u00dan"+
		"\2\u0580\u0581\7\5\2\2\u0581\u0586\5@!\2\u0582\u0583\7\6\2\2\u0583\u0585"+
		"\5@!\2\u0584\u0582\3\2\2\2\u0585\u0588\3\2\2\2\u0586\u0584\3\2\2\2\u0586"+
		"\u0587\3\2\2\2\u0587\u0589\3\2\2\2\u0588\u0586\3\2\2\2\u0589\u058e\7\7"+
		"\2\2\u058a\u058c\7\'\2\2\u058b\u058a\3\2\2\2\u058b\u058c\3\2\2\2\u058c"+
		"\u058d\3\2\2\2\u058d\u058f\5\u00caf\2\u058e\u058b\3\2\2\2\u058e\u058f"+
		"\3\2\2\2\u058f\u05a8\3\2\2\2\u0590\u059a\7\5\2\2\u0591\u0596\5\\/\2\u0592"+
		"\u0593\7\6\2\2\u0593\u0595\5\\/\2\u0594\u0592\3\2\2\2\u0595\u0598\3\2"+
		"\2\2\u0596\u0594\3\2\2\2\u0596\u0597\3\2\2\2\u0597\u059b\3\2\2\2\u0598"+
		"\u0596\3\2\2\2\u0599\u059b\5R*\2\u059a\u0591\3\2\2\2\u059a\u0599\3\2\2"+
		"\2\u059b\u059c\3\2\2\2\u059c\u059d\7\7\2\2\u059d\u05a8\3\2\2\2\u059e\u059f"+
		"\7\5\2\2\u059f\u05a0\5P)\2\u05a0\u05a5\7\7\2\2\u05a1\u05a3\7\'\2\2\u05a2"+
		"\u05a1\3\2\2\2\u05a2\u05a3\3\2\2\2\u05a3\u05a4\3\2\2\2\u05a4\u05a6\5\u00ca"+
		"f\2\u05a5\u05a2\3\2\2\2\u05a5\u05a6\3\2\2\2\u05a6\u05a8\3\2\2\2\u05a7"+
		"\u056a\3\2\2\2\u05a7\u057d\3\2\2\2\u05a7\u0590\3\2\2\2\u05a7\u059e\3\2"+
		"\2\2\u05a8]\3\2\2\2\u05a9\u05b6\7\13\2\2\u05aa\u05ab\5\u00b2Z\2\u05ab"+
		"\u05ac\7\4\2\2\u05ac\u05ad\7\13\2\2\u05ad\u05b6\3\2\2\2\u05ae\u05b3\5"+
		"@!\2\u05af\u05b1\7\'\2\2\u05b0\u05af\3\2\2\2\u05b0\u05b1\3\2\2\2\u05b1"+
		"\u05b2\3\2\2\2\u05b2\u05b4\5\u00a8U\2\u05b3\u05b0\3\2\2\2\u05b3\u05b4"+
		"\3\2\2\2\u05b4\u05b6\3\2\2\2\u05b5\u05a9\3\2\2\2\u05b5\u05aa\3\2\2\2\u05b5"+
		"\u05ae\3\2\2\2\u05b6_\3\2\2\2\u05b7\u05c5\7\6\2\2\u05b8\u05ba\7\u0097"+
		"\2\2\u05b9\u05b8\3\2\2\2\u05b9\u05ba\3\2\2\2\u05ba\u05c1\3\2\2\2\u05bb"+
		"\u05bd\7\u0098\2\2\u05bc\u05be\7\u0099\2\2\u05bd\u05bc\3\2\2\2\u05bd\u05be"+
		"\3\2\2\2\u05be\u05c2\3\2\2\2\u05bf\u05c2\7\u009a\2\2\u05c0\u05c2\7\u009b"+
		"\2\2\u05c1\u05bb\3\2\2\2\u05c1\u05bf\3\2\2\2\u05c1\u05c0\3\2\2\2\u05c1"+
		"\u05c2\3\2\2\2\u05c2\u05c3\3\2\2\2\u05c3\u05c5\7\u009c\2\2\u05c4\u05b7"+
		"\3\2\2\2\u05c4\u05b9\3\2\2\2\u05c5a\3\2\2\2\u05c6\u05c7\78\2\2\u05c7\u05d5"+
		"\5@!\2\u05c8\u05c9\7g\2\2\u05c9\u05ca\7\5\2\2\u05ca\u05cf\5\u00b8]\2\u05cb"+
		"\u05cc\7\6\2\2\u05cc\u05ce\5\u00b8]\2\u05cd\u05cb\3\2\2\2\u05ce\u05d1"+
		"\3\2\2\2\u05cf\u05cd\3\2\2\2\u05cf\u05d0\3\2\2\2\u05d0\u05d2\3\2\2\2\u05d1"+
		"\u05cf\3\2\2\2\u05d2\u05d3\7\7\2\2\u05d3\u05d5\3\2\2\2\u05d4\u05c6\3\2"+
		"\2\2\u05d4\u05c8\3\2\2\2\u05d5c\3\2\2\2\u05d6\u05d8\7j\2\2\u05d7\u05d9"+
		"\7k\2\2\u05d8\u05d7\3\2\2\2\u05d8\u05d9\3\2\2\2\u05d9\u05dd\3\2\2\2\u05da"+
		"\u05dd\7\u0094\2\2\u05db\u05dd\7\u0095\2\2\u05dc\u05d6\3\2\2\2\u05dc\u05da"+
		"\3\2\2\2\u05dc\u05db\3\2\2\2\u05dde\3\2\2\2\u05de\u05e0\5\60\31\2\u05df"+
		"\u05de\3\2\2\2\u05df\u05e0\3\2\2\2\u05e0\u05e1\3\2\2\2\u05e1\u05e4\7N"+
		"\2\2\u05e2\u05e3\7{\2\2\u05e3\u05e5\t\n\2\2\u05e4\u05e2\3\2\2\2\u05e4"+
		"\u05e5\3\2\2\2\u05e5\u05e6\3\2\2\2\u05e6\u05e7\5l\67\2\u05e7\u05ea\7O"+
		"\2\2\u05e8\u05eb\5\u00b8]\2\u05e9\u05eb\5h\65\2\u05ea\u05e8\3\2\2\2\u05ea"+
		"\u05e9\3\2\2\2\u05eb\u05ec\3\2\2\2\u05ec\u05ed\7\26\2\2\u05ed\u05f8\5"+
		"@!\2\u05ee\u05f1\7\6\2\2\u05ef\u05f2\5\u00b8]\2\u05f0\u05f2\5h\65\2\u05f1"+
		"\u05ef\3\2\2\2\u05f1\u05f0\3\2\2\2\u05f2\u05f3\3\2\2\2\u05f3\u05f4\7\26"+
		"\2\2\u05f4\u05f5\5@!\2\u05f5\u05f7\3\2\2\2\u05f6\u05ee\3\2\2\2\u05f7\u05fa"+
		"\3\2\2\2\u05f8\u05f6\3\2\2\2\u05f8\u05f9\3\2\2\2\u05f9\u05fd\3\2\2\2\u05fa"+
		"\u05f8\3\2\2\2\u05fb\u05fc\79\2\2\u05fc\u05fe\5@!\2\u05fd\u05fb\3\2\2"+
		"\2\u05fd\u05fe\3\2\2\2\u05feg\3\2\2\2\u05ff\u0600\7\5\2\2\u0600\u0605"+
		"\5\u00b8]\2\u0601\u0602\7\6\2\2\u0602\u0604\5\u00b8]\2\u0603\u0601\3\2"+
		"\2\2\u0604\u0607\3\2\2\2\u0605\u0603\3\2\2\2\u0605\u0606\3\2\2\2\u0606"+
		"\u0608\3\2\2\2\u0607\u0605\3\2\2\2\u0608\u0609\7\7\2\2\u0609i\3\2\2\2"+
		"\u060a\u060c\5\60\31\2\u060b\u060a\3\2\2\2\u060b\u060c\3\2\2\2\u060c\u060d"+
		"\3\2\2\2\u060d\u0610\7N\2\2\u060e\u060f\7{\2\2\u060f\u0611\t\n\2\2\u0610"+
		"\u060e\3\2\2\2\u0610\u0611\3\2\2\2\u0611\u0612\3\2\2\2\u0612\u0613\5l"+
		"\67\2\u0613\u0616\7O\2\2\u0614\u0617\5\u00b8]\2\u0615\u0617\5h\65\2\u0616"+
		"\u0614\3\2\2\2\u0616\u0615\3\2\2\2\u0617\u0618\3\2\2\2\u0618\u0619\7\26"+
		"\2\2\u0619\u0624\5@!\2\u061a\u061d\7\6\2\2\u061b\u061e\5\u00b8]\2\u061c"+
		"\u061e\5h\65\2\u061d\u061b\3\2\2\2\u061d\u061c\3\2\2\2\u061e\u061f\3\2"+
		"\2\2\u061f\u0620\7\26\2\2\u0620\u0621\5@!\2\u0621\u0623\3\2\2\2\u0622"+
		"\u061a\3\2\2\2\u0623\u0626\3\2\2\2\u0624\u0622\3\2\2\2\u0624\u0625\3\2"+
		"\2\2\u0625\u0629\3\2\2\2\u0626\u0624\3\2\2\2\u0627\u0628\79\2\2\u0628"+
		"\u062a\5@!\2\u0629\u0627\3\2\2\2\u0629\u062a\3\2\2\2\u062a\u062f\3\2\2"+
		"\2\u062b\u062d\5\u0082B\2\u062c\u062b\3\2\2\2\u062c\u062d\3\2\2\2\u062d"+
		"\u062e\3\2\2\2\u062e\u0630\5\u0084C\2\u062f\u062c\3\2\2\2\u062f\u0630"+
		"\3\2\2\2\u0630k\3\2\2\2\u0631\u0632\5\u00b0Y\2\u0632\u0633\7\4\2\2\u0633"+
		"\u0635\3\2\2\2\u0634\u0631\3\2\2\2\u0634\u0635\3\2\2\2\u0635\u0636\3\2"+
		"\2\2\u0636\u0639\5\u00b2Z\2\u0637\u0638\7\'\2\2\u0638\u063a\5\u00d0i\2"+
		"\u0639\u0637\3\2\2\2\u0639\u063a\3\2\2\2\u063a\u0640\3\2\2\2\u063b\u063c"+
		"\7\u0096\2\2\u063c\u063d\7\u0091\2\2\u063d\u0641\5\u00be`\2\u063e\u063f"+
		"\7\66\2\2\u063f\u0641\7\u0096\2\2\u0640\u063b\3\2\2\2\u0640\u063e\3\2"+
		"\2\2\u0640\u0641\3\2\2\2\u0641m\3\2\2\2\u0642\u0644\7\u009d\2\2\u0643"+
		"\u0645\5\u00b0Y\2\u0644\u0643\3\2\2\2\u0644\u0645\3\2\2\2\u0645\u0648"+
		"\3\2\2\2\u0646\u0647\7\u0088\2\2\u0647\u0649\5\u00d2j\2\u0648\u0646\3"+
		"\2\2\2\u0648\u0649\3\2\2\2\u0649o\3\2\2\2\u064a\u064b\7\u009e\2\2\u064b"+
		"\u064c\7\5\2\2\u064c\u064d\79\2\2\u064d\u064e\5@!\2\u064e\u064f\7\7\2"+
		"\2\u064fq\3\2\2\2\u0650\u0652\7\5\2\2\u0651\u0653\5\u00d4k\2\u0652\u0651"+
		"\3\2\2\2\u0652\u0653\3\2\2\2\u0653\u065e\3\2\2\2\u0654\u0655\7\u009f\2"+
		"\2\u0655\u0656\7\u0091\2\2\u0656\u065b\5@!\2\u0657\u0658\7\6\2\2\u0658"+
		"\u065a\5@!\2\u0659\u0657\3\2\2\2\u065a\u065d\3\2\2\2\u065b\u0659\3\2\2"+
		"\2\u065b\u065c\3\2\2\2\u065c\u065f\3\2\2\2\u065d\u065b\3\2\2\2\u065e\u0654"+
		"\3\2\2\2\u065e\u065f\3\2\2\2\u065f\u0660\3\2\2\2\u0660\u0661\7\u00a0\2"+
		"\2\u0661\u0662\7\u0091\2\2\u0662\u0667\5\u0086D\2\u0663\u0664\7\6\2\2"+
		"\u0664\u0666\5\u0086D\2\u0665\u0663\3\2\2\2\u0666\u0669\3\2\2\2\u0667"+
		"\u0665\3\2\2\2\u0667\u0668\3\2\2\2\u0668\u066b\3\2\2\2\u0669\u0667\3\2"+
		"\2\2\u066a\u066c\5v<\2\u066b\u066a\3\2\2\2\u066b\u066c\3\2\2\2\u066c\u066d"+
		"\3\2\2\2\u066d\u066e\7\7\2\2\u066es\3\2\2\2\u066f\u0691\7\u00a1\2\2\u0670"+
		"\u0692\5\u00ceh\2\u0671\u0673\7\5\2\2\u0672\u0674\5\u00d4k\2\u0673\u0672"+
		"\3\2\2\2\u0673\u0674\3\2\2\2\u0674\u067f\3\2\2\2\u0675\u0676\7\u009f\2"+
		"\2\u0676\u0677\7\u0091\2\2\u0677\u067c\5@!\2\u0678\u0679\7\6\2\2\u0679"+
		"\u067b\5@!\2\u067a\u0678\3\2\2\2\u067b\u067e\3\2\2\2\u067c\u067a\3\2\2"+
		"\2\u067c\u067d\3\2\2\2\u067d\u0680\3\2\2\2\u067e\u067c\3\2\2\2\u067f\u0675"+
		"\3\2\2\2\u067f\u0680\3\2\2\2\u0680\u068b\3\2\2\2\u0681\u0682\7\u00a0\2"+
		"\2\u0682\u0683\7\u0091\2\2\u0683\u0688\5\u0086D\2\u0684\u0685\7\6\2\2"+
		"\u0685\u0687\5\u0086D\2\u0686\u0684\3\2\2\2\u0687\u068a\3\2\2\2\u0688"+
		"\u0686\3\2\2\2\u0688\u0689\3\2\2\2\u0689\u068c\3\2\2\2\u068a\u0688\3\2"+
		"\2\2\u068b\u0681\3\2\2\2\u068b\u068c\3\2\2\2\u068c\u068e\3\2\2\2\u068d"+
		"\u068f\5v<\2\u068e\u068d\3\2\2\2\u068e\u068f\3\2\2\2\u068f\u0690\3\2\2"+
		"\2\u0690\u0692\7\7\2\2\u0691\u0670\3\2\2\2\u0691\u0671\3\2\2\2\u0692u"+
		"\3\2\2\2\u0693\u069b\5x=\2\u0694\u0695\7\u00a2\2\2\u0695\u0696\7R\2\2"+
		"\u0696\u069c\7\u00a3\2\2\u0697\u0698\7\u00a4\2\2\u0698\u069c\7d\2\2\u0699"+
		"\u069c\7\u0090\2\2\u069a\u069c\7\u00a5\2\2\u069b\u0694\3\2\2\2\u069b\u0697"+
		"\3\2\2\2\u069b\u0699\3\2\2\2\u069b\u069a\3\2\2\2\u069b\u069c\3\2\2\2\u069c"+
		"w\3\2\2\2\u069d\u06a4\t\23\2\2\u069e\u06a5\5\u008eH\2\u069f\u06a0\7|\2"+
		"\2\u06a0\u06a1\5\u008aF\2\u06a1\u06a2\7z\2\2\u06a2\u06a3\5\u008cG\2\u06a3"+
		"\u06a5\3\2\2\2\u06a4\u069e\3\2\2\2\u06a4\u069f\3\2\2\2\u06a5y\3\2\2\2"+
		"\u06a6\u06a7\5\u00d6l\2\u06a7\u06b1\7\5\2\2\u06a8\u06ad\5@!\2\u06a9\u06aa"+
		"\7\6\2\2\u06aa\u06ac\5@!\2\u06ab\u06a9\3\2\2\2\u06ac\u06af\3\2\2\2\u06ad"+
		"\u06ab\3\2\2\2\u06ad\u06ae\3\2\2\2\u06ae\u06b2\3\2\2\2\u06af\u06ad\3\2"+
		"\2\2\u06b0\u06b2\7\13\2\2\u06b1\u06a8\3\2\2\2\u06b1\u06b0\3\2\2\2\u06b2"+
		"\u06b3\3\2\2\2\u06b3\u06b4\7\7\2\2\u06b4{\3\2\2\2\u06b5\u06b6\5\u00d8"+
		"m\2\u06b6\u06c3\7\5\2\2\u06b7\u06b9\7p\2\2\u06b8\u06b7\3\2\2\2\u06b8\u06b9"+
		"\3\2\2\2\u06b9\u06ba\3\2\2\2\u06ba\u06bf\5@!\2\u06bb\u06bc\7\6\2\2\u06bc"+
		"\u06be\5@!\2\u06bd\u06bb\3\2\2\2\u06be\u06c1\3\2\2\2\u06bf\u06bd\3\2\2"+
		"\2\u06bf\u06c0\3\2\2\2\u06c0\u06c4\3\2\2\2\u06c1\u06bf\3\2\2\2\u06c2\u06c4"+
		"\7\13\2\2\u06c3\u06b8\3\2\2\2\u06c3\u06c2\3\2\2\2\u06c3\u06c4\3\2\2\2"+
		"\u06c4\u06c5\3\2\2\2\u06c5\u06c7\7\7\2\2\u06c6\u06c8\5p9\2\u06c7\u06c6"+
		"\3\2\2\2\u06c7\u06c8\3\2\2\2\u06c8}\3\2\2\2\u06c9\u06ca\5\u0090I\2\u06ca"+
		"\u06d4\7\5\2\2\u06cb\u06d0\5@!\2\u06cc\u06cd\7\6\2\2\u06cd\u06cf\5@!\2"+
		"\u06ce\u06cc\3\2\2\2\u06cf\u06d2\3\2\2\2\u06d0\u06ce\3\2\2\2\u06d0\u06d1"+
		"\3\2\2\2\u06d1\u06d5\3\2\2\2\u06d2\u06d0\3\2\2\2\u06d3\u06d5\7\13\2\2"+
		"\u06d4\u06cb\3\2\2\2\u06d4\u06d3\3\2\2\2\u06d4\u06d5\3\2\2\2\u06d5\u06d6"+
		"\3\2\2\2\u06d6\u06d8\7\7\2\2\u06d7\u06d9\5p9\2\u06d8\u06d7\3\2\2\2\u06d8"+
		"\u06d9\3\2\2\2\u06d9\u06da\3\2\2\2\u06da\u06dd\7\u00a1\2\2\u06db\u06de"+
		"\5r:\2\u06dc\u06de\5\u00ceh\2\u06dd\u06db\3\2\2\2\u06dd\u06dc\3\2\2\2"+
		"\u06de\177\3\2\2\2\u06df\u06e1\7h\2\2\u06e0\u06e2\7i\2\2\u06e1\u06e0\3"+
		"\2\2\2\u06e1\u06e2\3\2\2\2\u06e2\u06e3\3\2\2\2\u06e3\u06e8\5\66\34\2\u06e4"+
		"\u06e5\7\6\2\2\u06e5\u06e7\5\66\34\2\u06e6\u06e4\3\2\2\2\u06e7\u06ea\3"+
		"\2\2\2\u06e8\u06e6\3\2\2\2\u06e8\u06e9\3\2\2\2\u06e9\u0081\3\2\2\2\u06ea"+
		"\u06e8\3\2\2\2\u06eb\u06ec\7\u00a0\2\2\u06ec\u06ed\7\u0091\2\2\u06ed\u06f2"+
		"\5\u0086D\2\u06ee\u06ef\7\6\2\2\u06ef\u06f1\5\u0086D\2\u06f0\u06ee\3\2"+
		"\2\2\u06f1\u06f4\3\2\2\2\u06f2\u06f0\3\2\2\2\u06f2\u06f3\3\2\2\2\u06f3"+
		"\u0083\3\2\2\2\u06f4\u06f2\3\2\2\2\u06f5\u06f6\7\u00a9\2\2\u06f6\u06f9"+
		"\5@!\2\u06f7\u06f8\t\24\2\2\u06f8\u06fa\5@!\2\u06f9\u06f7\3\2\2\2\u06f9"+
		"\u06fa\3\2\2\2\u06fa\u0085\3\2\2\2\u06fb\u06fe\5@!\2\u06fc\u06fd\7:\2"+
		"\2\u06fd\u06ff\5\u00ba^\2\u06fe\u06fc\3\2\2\2\u06fe\u06ff\3\2\2\2\u06ff"+
		"\u0701\3\2\2\2\u0700\u0702\5\u0088E\2\u0701\u0700\3\2\2\2\u0701\u0702"+
		"\3\2\2\2\u0702\u0705\3\2\2\2\u0703\u0704\7\u00ab\2\2\u0704\u0706\t\25"+
		"\2\2\u0705\u0703\3\2\2\2\u0705\u0706\3\2\2\2\u0706\u0087\3\2\2\2\u0707"+
		"\u0708\t\26\2\2\u0708\u0089\3\2\2\2\u0709\u070a\5@!\2\u070a\u070b\7\u00b0"+
		"\2\2\u070b\u0714\3\2\2\2\u070c\u070d\5@!\2\u070d\u070e\7\u00b1\2\2\u070e"+
		"\u0714\3\2\2\2\u070f\u0710\7\u00a4\2\2\u0710\u0714\7d\2\2\u0711\u0712"+
		"\7\u00b2\2\2\u0712\u0714\7\u00b0\2\2\u0713\u0709\3\2\2\2\u0713\u070c\3"+
		"\2\2\2\u0713\u070f\3\2\2\2\u0713\u0711\3\2\2\2\u0714\u008b\3\2\2\2\u0715"+
		"\u0716\5@!\2\u0716\u0717\7\u00b0\2\2\u0717\u0720\3\2\2\2\u0718\u0719\5"+
		"@!\2\u0719\u071a\7\u00b1\2\2\u071a\u0720\3\2\2\2\u071b\u071c\7\u00a4\2"+
		"\2\u071c\u0720\7d\2\2\u071d\u071e\7\u00b2\2\2\u071e\u0720\7\u00b1\2\2"+
		"\u071f\u0715\3\2\2\2\u071f\u0718\3\2\2\2\u071f\u071b\3\2\2\2\u071f\u071d"+
		"\3\2\2\2\u0720\u008d\3\2\2\2\u0721\u0722\5@!\2\u0722\u0723\7\u00b0\2\2"+
		"\u0723\u0729\3\2\2\2\u0724\u0725\7\u00b2\2\2\u0725\u0729\7\u00b0\2\2\u0726"+
		"\u0727\7\u00a4\2\2\u0727\u0729\7d\2\2\u0728\u0721\3\2\2\2\u0728\u0724"+
		"\3\2\2\2\u0728\u0726\3\2\2\2\u0729\u008f\3\2\2\2\u072a\u072b\t\27\2\2"+
		"\u072b\u072c\7\5\2\2\u072c\u072d\5@!\2\u072d\u072e\7\7\2\2\u072e\u072f"+
		"\7\u00a1\2\2\u072f\u0731\7\5\2\2\u0730\u0732\5\u0096L\2\u0731\u0730\3"+
		"\2\2\2\u0731\u0732\3\2\2\2\u0732\u0733\3\2\2\2\u0733\u0735\5\u009aN\2"+
		"\u0734\u0736\5x=\2\u0735\u0734\3\2\2\2\u0735\u0736\3\2\2\2\u0736\u0737"+
		"\3\2\2\2\u0737\u0738\7\7\2\2\u0738\u0780\3\2\2\2\u0739\u073a\t\30\2\2"+
		"\u073a\u073b\7\5\2\2\u073b\u073c\7\7\2\2\u073c\u073d\7\u00a1\2\2\u073d"+
		"\u073f\7\5\2\2\u073e\u0740\5\u0096L\2\u073f\u073e\3\2\2\2\u073f\u0740"+
		"\3\2\2\2\u0740\u0742\3\2\2\2\u0741\u0743\5\u0098M\2\u0742\u0741\3\2\2"+
		"\2\u0742\u0743\3\2\2\2\u0743\u0744\3\2\2\2\u0744\u0780\7\7\2\2\u0745\u0746"+
		"\t\31\2\2\u0746\u0747\7\5\2\2\u0747\u0748\7\7\2\2\u0748\u0749\7\u00a1"+
		"\2\2\u0749\u074b\7\5\2\2\u074a\u074c\5\u0096L\2\u074b\u074a\3\2\2\2\u074b"+
		"\u074c\3\2\2\2\u074c\u074d\3\2\2\2\u074d\u074e\5\u009aN\2\u074e\u074f"+
		"\7\7\2\2\u074f\u0780\3\2\2\2\u0750\u0751\t\32\2\2\u0751\u0752\7\5\2\2"+
		"\u0752\u0754\5@!\2\u0753\u0755\5\u0092J\2\u0754\u0753\3\2\2\2\u0754\u0755"+
		"\3\2\2\2\u0755\u0757\3\2\2\2\u0756\u0758\5\u0094K\2\u0757\u0756\3\2\2"+
		"\2\u0757\u0758\3\2\2\2\u0758\u0759\3\2\2\2\u0759\u075a\7\7\2\2\u075a\u075b"+
		"\7\u00a1\2\2\u075b\u075d\7\5\2\2\u075c\u075e\5\u0096L\2\u075d\u075c\3"+
		"\2\2\2\u075d\u075e\3\2\2\2\u075e\u075f\3\2\2\2\u075f\u0760\5\u009aN\2"+
		"\u0760\u0761\7\7\2\2\u0761\u0780\3\2\2\2\u0762\u0763\7\u00bc\2\2\u0763"+
		"\u0764\7\5\2\2\u0764\u0765\5@!\2\u0765\u0766\7\6\2\2\u0766\u0767\5\"\22"+
		"\2\u0767\u0768\7\7\2\2\u0768\u0769\7\u00a1\2\2\u0769\u076b\7\5\2\2\u076a"+
		"\u076c\5\u0096L\2\u076b\u076a\3\2\2\2\u076b\u076c\3\2\2\2\u076c\u076d"+
		"\3\2\2\2\u076d\u076f\5\u009aN\2\u076e\u0770\5x=\2\u076f\u076e\3\2\2\2"+
		"\u076f\u0770\3\2\2\2\u0770\u0771\3\2\2\2\u0771\u0772\7\7\2\2\u0772\u0780"+
		"\3\2\2\2\u0773\u0774\7\u00bd\2\2\u0774\u0775\7\5\2\2\u0775\u0776\5@!\2"+
		"\u0776\u0777\7\7\2\2\u0777\u0778\7\u00a1\2\2\u0778\u077a\7\5\2\2\u0779"+
		"\u077b\5\u0096L\2\u077a\u0779\3\2\2\2\u077a\u077b\3\2\2\2\u077b\u077c"+
		"\3\2\2\2\u077c\u077d\5\u009aN\2\u077d\u077e\7\7\2\2\u077e\u0780\3\2\2"+
		"\2\u077f\u072a\3\2\2\2\u077f\u0739\3\2\2\2\u077f\u0745\3\2\2\2\u077f\u0750"+
		"\3\2\2\2\u077f\u0762\3\2\2\2\u077f\u0773\3\2\2\2\u0780\u0091\3\2\2\2\u0781"+
		"\u0782\7\6\2\2\u0782\u0783\5\"\22\2\u0783\u0093\3\2\2\2\u0784\u0785\7"+
		"\6\2\2\u0785\u0786\5\"\22\2\u0786\u0095\3\2\2\2\u0787\u0788\7\u009f\2"+
		"\2\u0788\u078a\7\u0091\2\2\u0789\u078b\5@!\2\u078a\u0789\3\2\2\2\u078b"+
		"\u078c\3\2\2\2\u078c\u078a\3\2\2\2\u078c\u078d\3\2\2\2\u078d\u0097\3\2"+
		"\2\2\u078e\u078f\7\u00a0\2\2\u078f\u0791\7\u0091\2\2\u0790\u0792\5@!\2"+
		"\u0791\u0790\3\2\2\2\u0792\u0793\3\2\2\2\u0793\u0791\3\2\2\2\u0793\u0794"+
		"\3\2\2\2\u0794\u0099\3\2\2\2\u0795\u0796\7\u00a0\2\2\u0796\u0797\7\u0091"+
		"\2\2\u0797\u0798\5\u009aN\2\u0798\u009b\3\2\2\2\u0799\u079b\5@!\2\u079a"+
		"\u079c\5\u0088E\2\u079b\u079a\3\2\2\2\u079b\u079c\3\2\2\2\u079c\u07a4"+
		"\3\2\2\2\u079d\u079e\7\6\2\2\u079e\u07a0\5@!\2\u079f\u07a1\5\u0088E\2"+
		"\u07a0\u079f\3\2\2\2\u07a0\u07a1\3\2\2\2\u07a1\u07a3\3\2\2\2\u07a2\u079d"+
		"\3\2\2\2\u07a3\u07a6\3\2\2\2\u07a4\u07a2\3\2\2\2\u07a4\u07a5\3\2\2\2\u07a5"+
		"\u009d\3\2\2\2\u07a6\u07a4\3\2\2\2\u07a7\u07a8\5P)\2\u07a8\u009f\3\2\2"+
		"\2\u07a9\u07aa\5P)\2\u07aa\u00a1\3\2\2\2\u07ab\u07ac\t\33\2\2\u07ac\u00a3"+
		"\3\2\2\2\u07ad\u07ae\7\u0081\2\2\u07ae\u00a5\3\2\2\2\u07af\u07b2\5@!\2"+
		"\u07b0\u07b2\5\34\17\2\u07b1\u07af\3\2\2\2\u07b1\u07b0\3\2\2\2\u07b2\u00a7"+
		"\3\2\2\2\u07b3\u07b4\t\34\2\2\u07b4\u00a9\3\2\2\2\u07b5\u07b6\t\35\2\2"+
		"\u07b6\u00ab\3\2\2\2\u07b7\u07b8\5\u00dco\2\u07b8\u00ad\3\2\2\2\u07b9"+
		"\u07ba\5\u00dco\2\u07ba\u00af\3\2\2\2\u07bb\u07bc\5\u00dco\2\u07bc\u00b1"+
		"\3\2\2\2\u07bd\u07be\5\u00dco\2\u07be\u00b3\3\2\2\2\u07bf\u07c0\5\u00dc"+
		"o\2\u07c0\u00b5\3\2\2\2\u07c1\u07c2\5\u00dco\2\u07c2\u00b7\3\2\2\2\u07c3"+
		"\u07c4\5\u00dco\2\u07c4\u00b9\3\2\2\2\u07c5\u07c6\5\u00dco\2\u07c6\u00bb"+
		"\3\2\2\2\u07c7\u07c8\5\u00dco\2\u07c8\u00bd\3\2\2\2\u07c9\u07ca\5\u00dc"+
		"o\2\u07ca\u00bf\3\2\2\2\u07cb\u07cc\5\u00dco\2\u07cc\u00c1\3\2\2\2\u07cd"+
		"\u07ce\5\u00dco\2\u07ce\u00c3\3\2\2\2\u07cf\u07d0\5\u00dco\2\u07d0\u00c5"+
		"\3\2\2\2\u07d1\u07d2\5\u00dco\2\u07d2\u00c7\3\2\2\2\u07d3\u07d4\5\u00dc"+
		"o\2\u07d4\u00c9\3\2\2\2\u07d5\u07d6\5\u00dco\2\u07d6\u00cb\3\2\2\2\u07d7"+
		"\u07d8\5\u00dco\2\u07d8\u00cd\3\2\2\2\u07d9\u07da\5\u00dco\2\u07da\u00cf"+
		"\3\2\2\2\u07db\u07dc\5\u00dco\2\u07dc\u00d1\3\2\2\2\u07dd\u07de\5\u00dc"+
		"o\2\u07de\u00d3\3\2\2\2\u07df\u07e0\5\u00dco\2\u07e0\u00d5\3\2\2\2\u07e1"+
		"\u07e2\5\u00dco\2\u07e2\u00d7\3\2\2\2\u07e3\u07e4\5\u00dco\2\u07e4\u00d9"+
		"\3\2\2\2\u07e5\u07e6\5\u00dco\2\u07e6\u00db\3\2\2\2\u07e7\u07ef\7>\2\2"+
		"\u07e8\u07ef\5\u00aaV\2\u07e9\u07ef\7\u0081\2\2\u07ea\u07eb\7\5\2\2\u07eb"+
		"\u07ec\5\u00dco\2\u07ec\u07ed\7\7\2\2\u07ed\u07ef\3\2\2\2\u07ee\u07e7"+
		"\3\2\2\2\u07ee\u07e8\3\2\2\2\u07ee\u07e9\3\2\2\2\u07ee\u07ea\3\2\2\2\u07ef"+
		"\u00dd\3\2\2\2\u0121\u00e1\u00e8\u00ed\u00f3\u00f9\u00fb\u0115\u011c\u0123"+
		"\u0129\u012d\u0130\u0137\u013a\u013e\u0146\u014a\u014c\u0150\u0154\u0158"+
		"\u015b\u0162\u0168\u016e\u0173\u017e\u0184\u0188\u018c\u018f\u0193\u0199"+
		"\u019e\u01a7\u01ae\u01b4\u01b8\u01bc\u01c1\u01c7\u01d3\u01d7\u01dc\u01df"+
		"\u01e2\u01e7\u01ea\u01f8\u01ff\u0206\u0208\u020b\u0211\u0216\u021e\u0223"+
		"\u0232\u0238\u0242\u0247\u0251\u0255\u0257\u025b\u0260\u0262\u026a\u0270"+
		"\u0275\u027c\u0287\u028a\u028c\u0293\u0297\u029e\u02a4\u02aa\u02b0\u02b5"+
		"\u02be\u02c3\u02ce\u02d3\u02de\u02e3\u02e7\u02f7\u0301\u0306\u030e\u031a"+
		"\u031f\u0327\u032e\u0331\u0338\u033b\u033e\u0342\u034a\u034f\u0359\u035e"+
		"\u0367\u036e\u0372\u0376\u0379\u0381\u038e\u0391\u0399\u03a2\u03a6\u03ab"+
		"\u03c9\u03d5\u03da\u03e6\u03ec\u03f3\u03f7\u0401\u0404\u040a\u0410\u0419"+
		"\u041c\u0420\u0422\u0424\u042d\u0434\u043b\u0441\u0446\u044e\u0453\u045c"+
		"\u0467\u046e\u0472\u0475\u0479\u0483\u0489\u048b\u0493\u049a\u04a1\u04a6"+
		"\u04a8\u04ae\u04b7\u04bc\u04c3\u04c7\u04c9\u04cc\u04d4\u04d8\u04db\u04e1"+
		"\u04e5\u04ea\u04f1\u04fa\u04fe\u0500\u0504\u050d\u0512\u0514\u0521\u0524"+
		"\u052d\u0538\u053f\u0542\u0547\u054b\u054e\u0551\u0556\u055a\u055f\u0562"+
		"\u0565\u056a\u056e\u0571\u0578\u057d\u0586\u058b\u058e\u0596\u059a\u05a2"+
		"\u05a5\u05a7\u05b0\u05b3\u05b5\u05b9\u05bd\u05c1\u05c4\u05cf\u05d4\u05d8"+
		"\u05dc\u05df\u05e4\u05ea\u05f1\u05f8\u05fd\u0605\u060b\u0610\u0616\u061d"+
		"\u0624\u0629\u062c\u062f\u0634\u0639\u0640\u0644\u0648\u0652\u065b\u065e"+
		"\u0667\u066b\u0673\u067c\u067f\u0688\u068b\u068e\u0691\u069b\u06a4\u06ad"+
		"\u06b1\u06b8\u06bf\u06c3\u06c7\u06d0\u06d4\u06d8\u06dd\u06e1\u06e8\u06f2"+
		"\u06f9\u06fe\u0701\u0705\u0713\u071f\u0728\u0731\u0735\u073f\u0742\u074b"+
		"\u0754\u0757\u075d\u076b\u076f\u077a\u077f\u078c\u0793\u079b\u07a0\u07a4"+
		"\u07b1\u07ee";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}