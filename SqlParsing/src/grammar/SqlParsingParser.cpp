
// Generated from SqlParsing.g4 by ANTLR 4.8


#include "SqlParsingListener.h"
#include "SqlParsingVisitor.h"

#include "SqlParsingParser.h"


using namespace antlrcpp;
using namespace dsql.parser;
using namespace antlr4;

SqlParsingParser::SqlParsingParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SqlParsingParser::~SqlParsingParser() {
  delete _interpreter;
}

std::string SqlParsingParser::getGrammarFileName() const {
  return "SqlParsing.g4";
}

const std::vector<std::string>& SqlParsingParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SqlParsingParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- Sql_stmt_listContext ------------------------------------------------------------------

SqlParsingParser::Sql_stmt_listContext::Sql_stmt_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SqlParsingParser::Sql_stmtContext *> SqlParsingParser::Sql_stmt_listContext::sql_stmt() {
  return getRuleContexts<SqlParsingParser::Sql_stmtContext>();
}

SqlParsingParser::Sql_stmtContext* SqlParsingParser::Sql_stmt_listContext::sql_stmt(size_t i) {
  return getRuleContext<SqlParsingParser::Sql_stmtContext>(i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Sql_stmt_listContext::SCOL() {
  return getTokens(SqlParsingParser::SCOL);
}

tree::TerminalNode* SqlParsingParser::Sql_stmt_listContext::SCOL(size_t i) {
  return getToken(SqlParsingParser::SCOL, i);
}


size_t SqlParsingParser::Sql_stmt_listContext::getRuleIndex() const {
  return SqlParsingParser::RuleSql_stmt_list;
}

void SqlParsingParser::Sql_stmt_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSql_stmt_list(this);
}

void SqlParsingParser::Sql_stmt_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSql_stmt_list(this);
}


antlrcpp::Any SqlParsingParser::Sql_stmt_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitSql_stmt_list(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Sql_stmt_listContext* SqlParsingParser::sql_stmt_list() {
  Sql_stmt_listContext *_localctx = _tracker.createInstance<Sql_stmt_listContext>(_ctx, getState());
  enterRule(_localctx, 0, SqlParsingParser::RuleSql_stmt_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(223);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SqlParsingParser::SCOL) {
      setState(220);
      match(SqlParsingParser::SCOL);
      setState(225);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(226);
    sql_stmt();
    setState(235);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(228); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(227);
          match(SqlParsingParser::SCOL);
          setState(230); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == SqlParsingParser::SCOL);
        setState(232);
        sql_stmt(); 
      }
      setState(237);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(241);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SqlParsingParser::SCOL) {
      setState(238);
      match(SqlParsingParser::SCOL);
      setState(243);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sql_stmtContext ------------------------------------------------------------------

SqlParsingParser::Sql_stmtContext::Sql_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Alter_table_stmtContext* SqlParsingParser::Sql_stmtContext::alter_table_stmt() {
  return getRuleContext<SqlParsingParser::Alter_table_stmtContext>(0);
}

SqlParsingParser::Analyze_stmtContext* SqlParsingParser::Sql_stmtContext::analyze_stmt() {
  return getRuleContext<SqlParsingParser::Analyze_stmtContext>(0);
}

SqlParsingParser::Attach_stmtContext* SqlParsingParser::Sql_stmtContext::attach_stmt() {
  return getRuleContext<SqlParsingParser::Attach_stmtContext>(0);
}

SqlParsingParser::Begin_stmtContext* SqlParsingParser::Sql_stmtContext::begin_stmt() {
  return getRuleContext<SqlParsingParser::Begin_stmtContext>(0);
}

SqlParsingParser::Commit_stmtContext* SqlParsingParser::Sql_stmtContext::commit_stmt() {
  return getRuleContext<SqlParsingParser::Commit_stmtContext>(0);
}

SqlParsingParser::Create_index_stmtContext* SqlParsingParser::Sql_stmtContext::create_index_stmt() {
  return getRuleContext<SqlParsingParser::Create_index_stmtContext>(0);
}

SqlParsingParser::Create_table_stmtContext* SqlParsingParser::Sql_stmtContext::create_table_stmt() {
  return getRuleContext<SqlParsingParser::Create_table_stmtContext>(0);
}

SqlParsingParser::Create_trigger_stmtContext* SqlParsingParser::Sql_stmtContext::create_trigger_stmt() {
  return getRuleContext<SqlParsingParser::Create_trigger_stmtContext>(0);
}

SqlParsingParser::Create_view_stmtContext* SqlParsingParser::Sql_stmtContext::create_view_stmt() {
  return getRuleContext<SqlParsingParser::Create_view_stmtContext>(0);
}

SqlParsingParser::Create_virtual_table_stmtContext* SqlParsingParser::Sql_stmtContext::create_virtual_table_stmt() {
  return getRuleContext<SqlParsingParser::Create_virtual_table_stmtContext>(0);
}

SqlParsingParser::Delete_stmtContext* SqlParsingParser::Sql_stmtContext::delete_stmt() {
  return getRuleContext<SqlParsingParser::Delete_stmtContext>(0);
}

SqlParsingParser::Delete_stmt_limitedContext* SqlParsingParser::Sql_stmtContext::delete_stmt_limited() {
  return getRuleContext<SqlParsingParser::Delete_stmt_limitedContext>(0);
}

SqlParsingParser::Detach_stmtContext* SqlParsingParser::Sql_stmtContext::detach_stmt() {
  return getRuleContext<SqlParsingParser::Detach_stmtContext>(0);
}

SqlParsingParser::Drop_stmtContext* SqlParsingParser::Sql_stmtContext::drop_stmt() {
  return getRuleContext<SqlParsingParser::Drop_stmtContext>(0);
}

SqlParsingParser::Insert_stmtContext* SqlParsingParser::Sql_stmtContext::insert_stmt() {
  return getRuleContext<SqlParsingParser::Insert_stmtContext>(0);
}

SqlParsingParser::Pragma_stmtContext* SqlParsingParser::Sql_stmtContext::pragma_stmt() {
  return getRuleContext<SqlParsingParser::Pragma_stmtContext>(0);
}

SqlParsingParser::Reindex_stmtContext* SqlParsingParser::Sql_stmtContext::reindex_stmt() {
  return getRuleContext<SqlParsingParser::Reindex_stmtContext>(0);
}

SqlParsingParser::Release_stmtContext* SqlParsingParser::Sql_stmtContext::release_stmt() {
  return getRuleContext<SqlParsingParser::Release_stmtContext>(0);
}

SqlParsingParser::Rollback_stmtContext* SqlParsingParser::Sql_stmtContext::rollback_stmt() {
  return getRuleContext<SqlParsingParser::Rollback_stmtContext>(0);
}

SqlParsingParser::Savepoint_stmtContext* SqlParsingParser::Sql_stmtContext::savepoint_stmt() {
  return getRuleContext<SqlParsingParser::Savepoint_stmtContext>(0);
}

SqlParsingParser::Select_stmtContext* SqlParsingParser::Sql_stmtContext::select_stmt() {
  return getRuleContext<SqlParsingParser::Select_stmtContext>(0);
}

SqlParsingParser::Update_stmtContext* SqlParsingParser::Sql_stmtContext::update_stmt() {
  return getRuleContext<SqlParsingParser::Update_stmtContext>(0);
}

SqlParsingParser::Update_stmt_limitedContext* SqlParsingParser::Sql_stmtContext::update_stmt_limited() {
  return getRuleContext<SqlParsingParser::Update_stmt_limitedContext>(0);
}

SqlParsingParser::Vacuum_stmtContext* SqlParsingParser::Sql_stmtContext::vacuum_stmt() {
  return getRuleContext<SqlParsingParser::Vacuum_stmtContext>(0);
}

tree::TerminalNode* SqlParsingParser::Sql_stmtContext::EXPLAIN() {
  return getToken(SqlParsingParser::EXPLAIN, 0);
}

tree::TerminalNode* SqlParsingParser::Sql_stmtContext::QUERY() {
  return getToken(SqlParsingParser::QUERY, 0);
}

tree::TerminalNode* SqlParsingParser::Sql_stmtContext::PLAN() {
  return getToken(SqlParsingParser::PLAN, 0);
}


size_t SqlParsingParser::Sql_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleSql_stmt;
}

void SqlParsingParser::Sql_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSql_stmt(this);
}

void SqlParsingParser::Sql_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSql_stmt(this);
}


antlrcpp::Any SqlParsingParser::Sql_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitSql_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Sql_stmtContext* SqlParsingParser::sql_stmt() {
  Sql_stmtContext *_localctx = _tracker.createInstance<Sql_stmtContext>(_ctx, getState());
  enterRule(_localctx, 2, SqlParsingParser::RuleSql_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::EXPLAIN) {
      setState(244);
      match(SqlParsingParser::EXPLAIN);
      setState(247);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SqlParsingParser::QUERY) {
        setState(245);
        match(SqlParsingParser::QUERY);
        setState(246);
        match(SqlParsingParser::PLAN);
      }
    }
    setState(275);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(251);
      alter_table_stmt();
      break;
    }

    case 2: {
      setState(252);
      analyze_stmt();
      break;
    }

    case 3: {
      setState(253);
      attach_stmt();
      break;
    }

    case 4: {
      setState(254);
      begin_stmt();
      break;
    }

    case 5: {
      setState(255);
      commit_stmt();
      break;
    }

    case 6: {
      setState(256);
      create_index_stmt();
      break;
    }

    case 7: {
      setState(257);
      create_table_stmt();
      break;
    }

    case 8: {
      setState(258);
      create_trigger_stmt();
      break;
    }

    case 9: {
      setState(259);
      create_view_stmt();
      break;
    }

    case 10: {
      setState(260);
      create_virtual_table_stmt();
      break;
    }

    case 11: {
      setState(261);
      delete_stmt();
      break;
    }

    case 12: {
      setState(262);
      delete_stmt_limited();
      break;
    }

    case 13: {
      setState(263);
      detach_stmt();
      break;
    }

    case 14: {
      setState(264);
      drop_stmt();
      break;
    }

    case 15: {
      setState(265);
      insert_stmt();
      break;
    }

    case 16: {
      setState(266);
      pragma_stmt();
      break;
    }

    case 17: {
      setState(267);
      reindex_stmt();
      break;
    }

    case 18: {
      setState(268);
      release_stmt();
      break;
    }

    case 19: {
      setState(269);
      rollback_stmt();
      break;
    }

    case 20: {
      setState(270);
      savepoint_stmt();
      break;
    }

    case 21: {
      setState(271);
      select_stmt();
      break;
    }

    case 22: {
      setState(272);
      update_stmt();
      break;
    }

    case 23: {
      setState(273);
      update_stmt_limited();
      break;
    }

    case 24: {
      setState(274);
      vacuum_stmt();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Alter_table_stmtContext ------------------------------------------------------------------

SqlParsingParser::Alter_table_stmtContext::Alter_table_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Alter_table_stmtContext::ALTER() {
  return getToken(SqlParsingParser::ALTER, 0);
}

tree::TerminalNode* SqlParsingParser::Alter_table_stmtContext::TABLE() {
  return getToken(SqlParsingParser::TABLE, 0);
}

SqlParsingParser::Table_nameContext* SqlParsingParser::Alter_table_stmtContext::table_name() {
  return getRuleContext<SqlParsingParser::Table_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Alter_table_stmtContext::RENAME() {
  return getToken(SqlParsingParser::RENAME, 0);
}

tree::TerminalNode* SqlParsingParser::Alter_table_stmtContext::ADD() {
  return getToken(SqlParsingParser::ADD, 0);
}

SqlParsingParser::Column_defContext* SqlParsingParser::Alter_table_stmtContext::column_def() {
  return getRuleContext<SqlParsingParser::Column_defContext>(0);
}

SqlParsingParser::Schema_nameContext* SqlParsingParser::Alter_table_stmtContext::schema_name() {
  return getRuleContext<SqlParsingParser::Schema_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Alter_table_stmtContext::DOT() {
  return getToken(SqlParsingParser::DOT, 0);
}

tree::TerminalNode* SqlParsingParser::Alter_table_stmtContext::COLUMN() {
  return getToken(SqlParsingParser::COLUMN, 0);
}

tree::TerminalNode* SqlParsingParser::Alter_table_stmtContext::TO() {
  return getToken(SqlParsingParser::TO, 0);
}

SqlParsingParser::New_table_nameContext* SqlParsingParser::Alter_table_stmtContext::new_table_name() {
  return getRuleContext<SqlParsingParser::New_table_nameContext>(0);
}

std::vector<SqlParsingParser::Column_nameContext *> SqlParsingParser::Alter_table_stmtContext::column_name() {
  return getRuleContexts<SqlParsingParser::Column_nameContext>();
}

SqlParsingParser::Column_nameContext* SqlParsingParser::Alter_table_stmtContext::column_name(size_t i) {
  return getRuleContext<SqlParsingParser::Column_nameContext>(i);
}


size_t SqlParsingParser::Alter_table_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleAlter_table_stmt;
}

void SqlParsingParser::Alter_table_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlter_table_stmt(this);
}

void SqlParsingParser::Alter_table_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlter_table_stmt(this);
}


antlrcpp::Any SqlParsingParser::Alter_table_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitAlter_table_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Alter_table_stmtContext* SqlParsingParser::alter_table_stmt() {
  Alter_table_stmtContext *_localctx = _tracker.createInstance<Alter_table_stmtContext>(_ctx, getState());
  enterRule(_localctx, 4, SqlParsingParser::RuleAlter_table_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(277);
    match(SqlParsingParser::ALTER);
    setState(278);
    match(SqlParsingParser::TABLE);
    setState(282);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(279);
      schema_name();
      setState(280);
      match(SqlParsingParser::DOT);
      break;
    }

    }
    setState(284);
    table_name();
    setState(302);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::RENAME: {
        setState(285);
        match(SqlParsingParser::RENAME);
        setState(295);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          setState(286);
          match(SqlParsingParser::TO);
          setState(287);
          new_table_name();
          break;
        }

        case 2: {
          setState(289);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
          case 1: {
            setState(288);
            match(SqlParsingParser::COLUMN);
            break;
          }

          }
          setState(291);
          dynamic_cast<Alter_table_stmtContext *>(_localctx)->old_column_name = column_name();
          setState(292);
          match(SqlParsingParser::TO);
          setState(293);
          dynamic_cast<Alter_table_stmtContext *>(_localctx)->new_column_name = column_name();
          break;
        }

        }
        break;
      }

      case SqlParsingParser::ADD: {
        setState(297);
        match(SqlParsingParser::ADD);
        setState(299);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          setState(298);
          match(SqlParsingParser::COLUMN);
          break;
        }

        }
        setState(301);
        column_def();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Analyze_stmtContext ------------------------------------------------------------------

SqlParsingParser::Analyze_stmtContext::Analyze_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Analyze_stmtContext::ANALYZE() {
  return getToken(SqlParsingParser::ANALYZE, 0);
}

SqlParsingParser::Schema_nameContext* SqlParsingParser::Analyze_stmtContext::schema_name() {
  return getRuleContext<SqlParsingParser::Schema_nameContext>(0);
}

SqlParsingParser::Table_or_index_nameContext* SqlParsingParser::Analyze_stmtContext::table_or_index_name() {
  return getRuleContext<SqlParsingParser::Table_or_index_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Analyze_stmtContext::DOT() {
  return getToken(SqlParsingParser::DOT, 0);
}


size_t SqlParsingParser::Analyze_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleAnalyze_stmt;
}

void SqlParsingParser::Analyze_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnalyze_stmt(this);
}

void SqlParsingParser::Analyze_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnalyze_stmt(this);
}


antlrcpp::Any SqlParsingParser::Analyze_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitAnalyze_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Analyze_stmtContext* SqlParsingParser::analyze_stmt() {
  Analyze_stmtContext *_localctx = _tracker.createInstance<Analyze_stmtContext>(_ctx, getState());
  enterRule(_localctx, 6, SqlParsingParser::RuleAnalyze_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    match(SqlParsingParser::ANALYZE);
    setState(312);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(305);
      schema_name();
      break;
    }

    case 2: {
      setState(309);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
      case 1: {
        setState(306);
        schema_name();
        setState(307);
        match(SqlParsingParser::DOT);
        break;
      }

      }
      setState(311);
      table_or_index_name();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Attach_stmtContext ------------------------------------------------------------------

SqlParsingParser::Attach_stmtContext::Attach_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Attach_stmtContext::ATTACH() {
  return getToken(SqlParsingParser::ATTACH, 0);
}

SqlParsingParser::ExprContext* SqlParsingParser::Attach_stmtContext::expr() {
  return getRuleContext<SqlParsingParser::ExprContext>(0);
}

tree::TerminalNode* SqlParsingParser::Attach_stmtContext::AS() {
  return getToken(SqlParsingParser::AS, 0);
}

SqlParsingParser::Schema_nameContext* SqlParsingParser::Attach_stmtContext::schema_name() {
  return getRuleContext<SqlParsingParser::Schema_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Attach_stmtContext::DATABASE() {
  return getToken(SqlParsingParser::DATABASE, 0);
}


size_t SqlParsingParser::Attach_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleAttach_stmt;
}

void SqlParsingParser::Attach_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttach_stmt(this);
}

void SqlParsingParser::Attach_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttach_stmt(this);
}


antlrcpp::Any SqlParsingParser::Attach_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitAttach_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Attach_stmtContext* SqlParsingParser::attach_stmt() {
  Attach_stmtContext *_localctx = _tracker.createInstance<Attach_stmtContext>(_ctx, getState());
  enterRule(_localctx, 8, SqlParsingParser::RuleAttach_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(314);
    match(SqlParsingParser::ATTACH);
    setState(316);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(315);
      match(SqlParsingParser::DATABASE);
      break;
    }

    }
    setState(318);
    expr(0);
    setState(319);
    match(SqlParsingParser::AS);
    setState(320);
    schema_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Begin_stmtContext ------------------------------------------------------------------

SqlParsingParser::Begin_stmtContext::Begin_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Begin_stmtContext::BEGIN() {
  return getToken(SqlParsingParser::BEGIN, 0);
}

tree::TerminalNode* SqlParsingParser::Begin_stmtContext::TRANSACTION() {
  return getToken(SqlParsingParser::TRANSACTION, 0);
}

tree::TerminalNode* SqlParsingParser::Begin_stmtContext::DEFERRED() {
  return getToken(SqlParsingParser::DEFERRED, 0);
}

tree::TerminalNode* SqlParsingParser::Begin_stmtContext::IMMEDIATE() {
  return getToken(SqlParsingParser::IMMEDIATE, 0);
}

tree::TerminalNode* SqlParsingParser::Begin_stmtContext::EXCLUSIVE() {
  return getToken(SqlParsingParser::EXCLUSIVE, 0);
}

SqlParsingParser::Transaction_nameContext* SqlParsingParser::Begin_stmtContext::transaction_name() {
  return getRuleContext<SqlParsingParser::Transaction_nameContext>(0);
}


size_t SqlParsingParser::Begin_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleBegin_stmt;
}

void SqlParsingParser::Begin_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBegin_stmt(this);
}

void SqlParsingParser::Begin_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBegin_stmt(this);
}


antlrcpp::Any SqlParsingParser::Begin_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitBegin_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Begin_stmtContext* SqlParsingParser::begin_stmt() {
  Begin_stmtContext *_localctx = _tracker.createInstance<Begin_stmtContext>(_ctx, getState());
  enterRule(_localctx, 10, SqlParsingParser::RuleBegin_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(322);
    match(SqlParsingParser::BEGIN);
    setState(324);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 58) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 58)) & ((1ULL << (SqlParsingParser::DEFERRED - 58))
      | (1ULL << (SqlParsingParser::EXCLUSIVE - 58))
      | (1ULL << (SqlParsingParser::IMMEDIATE - 58)))) != 0)) {
      setState(323);
      _la = _input->LA(1);
      if (!(((((_la - 58) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 58)) & ((1ULL << (SqlParsingParser::DEFERRED - 58))
        | (1ULL << (SqlParsingParser::EXCLUSIVE - 58))
        | (1ULL << (SqlParsingParser::IMMEDIATE - 58)))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(330);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::TRANSACTION) {
      setState(326);
      match(SqlParsingParser::TRANSACTION);
      setState(328);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SqlParsingParser::OPEN_PAR)
        | (1ULL << SqlParsingParser::ABORT)
        | (1ULL << SqlParsingParser::ACTION)
        | (1ULL << SqlParsingParser::ADD)
        | (1ULL << SqlParsingParser::AFTER)
        | (1ULL << SqlParsingParser::ALL)
        | (1ULL << SqlParsingParser::ALTER)
        | (1ULL << SqlParsingParser::ANALYZE)
        | (1ULL << SqlParsingParser::AND)
        | (1ULL << SqlParsingParser::AS)
        | (1ULL << SqlParsingParser::ASC)
        | (1ULL << SqlParsingParser::ATTACH)
        | (1ULL << SqlParsingParser::AUTOINCREMENT)
        | (1ULL << SqlParsingParser::BEFORE)
        | (1ULL << SqlParsingParser::BEGIN)
        | (1ULL << SqlParsingParser::BETWEEN)
        | (1ULL << SqlParsingParser::BY)
        | (1ULL << SqlParsingParser::CASCADE)
        | (1ULL << SqlParsingParser::CASE)
        | (1ULL << SqlParsingParser::CAST)
        | (1ULL << SqlParsingParser::CHECK)
        | (1ULL << SqlParsingParser::COLLATE)
        | (1ULL << SqlParsingParser::COLUMN)
        | (1ULL << SqlParsingParser::COMMIT)
        | (1ULL << SqlParsingParser::CONFLICT)
        | (1ULL << SqlParsingParser::CONSTRAINT)
        | (1ULL << SqlParsingParser::CREATE)
        | (1ULL << SqlParsingParser::CROSS)
        | (1ULL << SqlParsingParser::CURRENT_DATE)
        | (1ULL << SqlParsingParser::CURRENT_TIME)
        | (1ULL << SqlParsingParser::CURRENT_TIMESTAMP)
        | (1ULL << SqlParsingParser::DATABASE)
        | (1ULL << SqlParsingParser::DEFAULT)
        | (1ULL << SqlParsingParser::DEFERRABLE)
        | (1ULL << SqlParsingParser::DEFERRED)
        | (1ULL << SqlParsingParser::DELETE)
        | (1ULL << SqlParsingParser::DESC)
        | (1ULL << SqlParsingParser::DETACH)
        | (1ULL << SqlParsingParser::DISTINCT)
        | (1ULL << SqlParsingParser::DROP))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (SqlParsingParser::EACH - 64))
        | (1ULL << (SqlParsingParser::ELSE - 64))
        | (1ULL << (SqlParsingParser::END - 64))
        | (1ULL << (SqlParsingParser::ESCAPE - 64))
        | (1ULL << (SqlParsingParser::EXCEPT - 64))
        | (1ULL << (SqlParsingParser::EXCLUSIVE - 64))
        | (1ULL << (SqlParsingParser::EXISTS - 64))
        | (1ULL << (SqlParsingParser::EXPLAIN - 64))
        | (1ULL << (SqlParsingParser::FAIL - 64))
        | (1ULL << (SqlParsingParser::FOR - 64))
        | (1ULL << (SqlParsingParser::FOREIGN - 64))
        | (1ULL << (SqlParsingParser::FROM - 64))
        | (1ULL << (SqlParsingParser::FULL - 64))
        | (1ULL << (SqlParsingParser::GLOB - 64))
        | (1ULL << (SqlParsingParser::GROUP - 64))
        | (1ULL << (SqlParsingParser::HAVING - 64))
        | (1ULL << (SqlParsingParser::IF - 64))
        | (1ULL << (SqlParsingParser::IGNORE - 64))
        | (1ULL << (SqlParsingParser::IMMEDIATE - 64))
        | (1ULL << (SqlParsingParser::IN - 64))
        | (1ULL << (SqlParsingParser::INDEX - 64))
        | (1ULL << (SqlParsingParser::INDEXED - 64))
        | (1ULL << (SqlParsingParser::INITIALLY - 64))
        | (1ULL << (SqlParsingParser::INNER - 64))
        | (1ULL << (SqlParsingParser::INSERT - 64))
        | (1ULL << (SqlParsingParser::INSTEAD - 64))
        | (1ULL << (SqlParsingParser::INTERSECT - 64))
        | (1ULL << (SqlParsingParser::INTO - 64))
        | (1ULL << (SqlParsingParser::IS - 64))
        | (1ULL << (SqlParsingParser::ISNULL - 64))
        | (1ULL << (SqlParsingParser::JOIN - 64))
        | (1ULL << (SqlParsingParser::KEY - 64))
        | (1ULL << (SqlParsingParser::LEFT - 64))
        | (1ULL << (SqlParsingParser::LIKE - 64))
        | (1ULL << (SqlParsingParser::LIMIT - 64))
        | (1ULL << (SqlParsingParser::MATCH - 64))
        | (1ULL << (SqlParsingParser::NATURAL - 64))
        | (1ULL << (SqlParsingParser::NO - 64))
        | (1ULL << (SqlParsingParser::NOT - 64))
        | (1ULL << (SqlParsingParser::NOTNULL - 64))
        | (1ULL << (SqlParsingParser::NULL_ - 64))
        | (1ULL << (SqlParsingParser::OF - 64))
        | (1ULL << (SqlParsingParser::OFFSET - 64))
        | (1ULL << (SqlParsingParser::ON - 64))
        | (1ULL << (SqlParsingParser::OR - 64))
        | (1ULL << (SqlParsingParser::ORDER - 64))
        | (1ULL << (SqlParsingParser::OUTER - 64))
        | (1ULL << (SqlParsingParser::PLAN - 64))
        | (1ULL << (SqlParsingParser::PRAGMA - 64))
        | (1ULL << (SqlParsingParser::PRIMARY - 64))
        | (1ULL << (SqlParsingParser::QUERY - 64))
        | (1ULL << (SqlParsingParser::RAISE - 64))
        | (1ULL << (SqlParsingParser::RECURSIVE - 64))
        | (1ULL << (SqlParsingParser::REFERENCES - 64))
        | (1ULL << (SqlParsingParser::REGEXP - 64))
        | (1ULL << (SqlParsingParser::REINDEX - 64))
        | (1ULL << (SqlParsingParser::RELEASE - 64))
        | (1ULL << (SqlParsingParser::RENAME - 64))
        | (1ULL << (SqlParsingParser::REPLACE - 64))
        | (1ULL << (SqlParsingParser::RESTRICT - 64))
        | (1ULL << (SqlParsingParser::RIGHT - 64))
        | (1ULL << (SqlParsingParser::ROLLBACK - 64))
        | (1ULL << (SqlParsingParser::ROW - 64))
        | (1ULL << (SqlParsingParser::ROWS - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 128)) & ((1ULL << (SqlParsingParser::SAVEPOINT - 128))
        | (1ULL << (SqlParsingParser::SELECT - 128))
        | (1ULL << (SqlParsingParser::SET - 128))
        | (1ULL << (SqlParsingParser::TABLE - 128))
        | (1ULL << (SqlParsingParser::TEMP - 128))
        | (1ULL << (SqlParsingParser::TEMPORARY - 128))
        | (1ULL << (SqlParsingParser::THEN - 128))
        | (1ULL << (SqlParsingParser::TO - 128))
        | (1ULL << (SqlParsingParser::TRANSACTION - 128))
        | (1ULL << (SqlParsingParser::TRIGGER - 128))
        | (1ULL << (SqlParsingParser::UNION - 128))
        | (1ULL << (SqlParsingParser::UNIQUE - 128))
        | (1ULL << (SqlParsingParser::UPDATE - 128))
        | (1ULL << (SqlParsingParser::USING - 128))
        | (1ULL << (SqlParsingParser::VACUUM - 128))
        | (1ULL << (SqlParsingParser::VALUES - 128))
        | (1ULL << (SqlParsingParser::VIEW - 128))
        | (1ULL << (SqlParsingParser::VIRTUAL - 128))
        | (1ULL << (SqlParsingParser::WHEN - 128))
        | (1ULL << (SqlParsingParser::WHERE - 128))
        | (1ULL << (SqlParsingParser::WITH - 128))
        | (1ULL << (SqlParsingParser::WITHOUT - 128))
        | (1ULL << (SqlParsingParser::FIRST_VALUE - 128))
        | (1ULL << (SqlParsingParser::OVER - 128))
        | (1ULL << (SqlParsingParser::PARTITION - 128))
        | (1ULL << (SqlParsingParser::RANGE - 128))
        | (1ULL << (SqlParsingParser::PRECEDING - 128))
        | (1ULL << (SqlParsingParser::UNBOUNDED - 128))
        | (1ULL << (SqlParsingParser::CURRENT - 128))
        | (1ULL << (SqlParsingParser::FOLLOWING - 128))
        | (1ULL << (SqlParsingParser::CUME_DIST - 128))
        | (1ULL << (SqlParsingParser::DENSE_RANK - 128))
        | (1ULL << (SqlParsingParser::LAG - 128))
        | (1ULL << (SqlParsingParser::LAST_VALUE - 128))
        | (1ULL << (SqlParsingParser::LEAD - 128))
        | (1ULL << (SqlParsingParser::NTH_VALUE - 128))
        | (1ULL << (SqlParsingParser::NTILE - 128))
        | (1ULL << (SqlParsingParser::PERCENT_RANK - 128))
        | (1ULL << (SqlParsingParser::RANK - 128))
        | (1ULL << (SqlParsingParser::ROW_NUMBER - 128))
        | (1ULL << (SqlParsingParser::GENERATED - 128))
        | (1ULL << (SqlParsingParser::ALWAYS - 128))
        | (1ULL << (SqlParsingParser::STORED - 128))
        | (1ULL << (SqlParsingParser::TRUE_ - 128))
        | (1ULL << (SqlParsingParser::FALSE_ - 128))
        | (1ULL << (SqlParsingParser::WINDOW - 128))
        | (1ULL << (SqlParsingParser::NULLS - 128))
        | (1ULL << (SqlParsingParser::FIRST - 128))
        | (1ULL << (SqlParsingParser::LAST - 128))
        | (1ULL << (SqlParsingParser::FILTER - 128))
        | (1ULL << (SqlParsingParser::GROUPS - 128))
        | (1ULL << (SqlParsingParser::EXCLUDE - 128))
        | (1ULL << (SqlParsingParser::IDENTIFIER - 128))
        | (1ULL << (SqlParsingParser::STRING_LITERAL - 128)))) != 0)) {
        setState(327);
        transaction_name();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Commit_stmtContext ------------------------------------------------------------------

SqlParsingParser::Commit_stmtContext::Commit_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Commit_stmtContext::COMMIT() {
  return getToken(SqlParsingParser::COMMIT, 0);
}

tree::TerminalNode* SqlParsingParser::Commit_stmtContext::END() {
  return getToken(SqlParsingParser::END, 0);
}

tree::TerminalNode* SqlParsingParser::Commit_stmtContext::TRANSACTION() {
  return getToken(SqlParsingParser::TRANSACTION, 0);
}


size_t SqlParsingParser::Commit_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleCommit_stmt;
}

void SqlParsingParser::Commit_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommit_stmt(this);
}

void SqlParsingParser::Commit_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommit_stmt(this);
}


antlrcpp::Any SqlParsingParser::Commit_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitCommit_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Commit_stmtContext* SqlParsingParser::commit_stmt() {
  Commit_stmtContext *_localctx = _tracker.createInstance<Commit_stmtContext>(_ctx, getState());
  enterRule(_localctx, 12, SqlParsingParser::RuleCommit_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    _la = _input->LA(1);
    if (!(_la == SqlParsingParser::COMMIT

    || _la == SqlParsingParser::END)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(334);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::TRANSACTION) {
      setState(333);
      match(SqlParsingParser::TRANSACTION);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rollback_stmtContext ------------------------------------------------------------------

SqlParsingParser::Rollback_stmtContext::Rollback_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Rollback_stmtContext::ROLLBACK() {
  return getToken(SqlParsingParser::ROLLBACK, 0);
}

tree::TerminalNode* SqlParsingParser::Rollback_stmtContext::TRANSACTION() {
  return getToken(SqlParsingParser::TRANSACTION, 0);
}

tree::TerminalNode* SqlParsingParser::Rollback_stmtContext::TO() {
  return getToken(SqlParsingParser::TO, 0);
}

SqlParsingParser::Savepoint_nameContext* SqlParsingParser::Rollback_stmtContext::savepoint_name() {
  return getRuleContext<SqlParsingParser::Savepoint_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Rollback_stmtContext::SAVEPOINT() {
  return getToken(SqlParsingParser::SAVEPOINT, 0);
}


size_t SqlParsingParser::Rollback_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleRollback_stmt;
}

void SqlParsingParser::Rollback_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRollback_stmt(this);
}

void SqlParsingParser::Rollback_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRollback_stmt(this);
}


antlrcpp::Any SqlParsingParser::Rollback_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitRollback_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Rollback_stmtContext* SqlParsingParser::rollback_stmt() {
  Rollback_stmtContext *_localctx = _tracker.createInstance<Rollback_stmtContext>(_ctx, getState());
  enterRule(_localctx, 14, SqlParsingParser::RuleRollback_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(336);
    match(SqlParsingParser::ROLLBACK);
    setState(338);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::TRANSACTION) {
      setState(337);
      match(SqlParsingParser::TRANSACTION);
    }
    setState(345);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::TO) {
      setState(340);
      match(SqlParsingParser::TO);
      setState(342);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
      case 1: {
        setState(341);
        match(SqlParsingParser::SAVEPOINT);
        break;
      }

      }
      setState(344);
      savepoint_name();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Savepoint_stmtContext ------------------------------------------------------------------

SqlParsingParser::Savepoint_stmtContext::Savepoint_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Savepoint_stmtContext::SAVEPOINT() {
  return getToken(SqlParsingParser::SAVEPOINT, 0);
}

SqlParsingParser::Savepoint_nameContext* SqlParsingParser::Savepoint_stmtContext::savepoint_name() {
  return getRuleContext<SqlParsingParser::Savepoint_nameContext>(0);
}


size_t SqlParsingParser::Savepoint_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleSavepoint_stmt;
}

void SqlParsingParser::Savepoint_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSavepoint_stmt(this);
}

void SqlParsingParser::Savepoint_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSavepoint_stmt(this);
}


antlrcpp::Any SqlParsingParser::Savepoint_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitSavepoint_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Savepoint_stmtContext* SqlParsingParser::savepoint_stmt() {
  Savepoint_stmtContext *_localctx = _tracker.createInstance<Savepoint_stmtContext>(_ctx, getState());
  enterRule(_localctx, 16, SqlParsingParser::RuleSavepoint_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(347);
    match(SqlParsingParser::SAVEPOINT);
    setState(348);
    savepoint_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Release_stmtContext ------------------------------------------------------------------

SqlParsingParser::Release_stmtContext::Release_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Release_stmtContext::RELEASE() {
  return getToken(SqlParsingParser::RELEASE, 0);
}

SqlParsingParser::Savepoint_nameContext* SqlParsingParser::Release_stmtContext::savepoint_name() {
  return getRuleContext<SqlParsingParser::Savepoint_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Release_stmtContext::SAVEPOINT() {
  return getToken(SqlParsingParser::SAVEPOINT, 0);
}


size_t SqlParsingParser::Release_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleRelease_stmt;
}

void SqlParsingParser::Release_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelease_stmt(this);
}

void SqlParsingParser::Release_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelease_stmt(this);
}


antlrcpp::Any SqlParsingParser::Release_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitRelease_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Release_stmtContext* SqlParsingParser::release_stmt() {
  Release_stmtContext *_localctx = _tracker.createInstance<Release_stmtContext>(_ctx, getState());
  enterRule(_localctx, 18, SqlParsingParser::RuleRelease_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    match(SqlParsingParser::RELEASE);
    setState(352);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      setState(351);
      match(SqlParsingParser::SAVEPOINT);
      break;
    }

    }
    setState(354);
    savepoint_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Create_index_stmtContext ------------------------------------------------------------------

SqlParsingParser::Create_index_stmtContext::Create_index_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Create_index_stmtContext::CREATE() {
  return getToken(SqlParsingParser::CREATE, 0);
}

tree::TerminalNode* SqlParsingParser::Create_index_stmtContext::INDEX() {
  return getToken(SqlParsingParser::INDEX, 0);
}

SqlParsingParser::Index_nameContext* SqlParsingParser::Create_index_stmtContext::index_name() {
  return getRuleContext<SqlParsingParser::Index_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Create_index_stmtContext::ON() {
  return getToken(SqlParsingParser::ON, 0);
}

SqlParsingParser::Table_nameContext* SqlParsingParser::Create_index_stmtContext::table_name() {
  return getRuleContext<SqlParsingParser::Table_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Create_index_stmtContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

std::vector<SqlParsingParser::Indexed_columnContext *> SqlParsingParser::Create_index_stmtContext::indexed_column() {
  return getRuleContexts<SqlParsingParser::Indexed_columnContext>();
}

SqlParsingParser::Indexed_columnContext* SqlParsingParser::Create_index_stmtContext::indexed_column(size_t i) {
  return getRuleContext<SqlParsingParser::Indexed_columnContext>(i);
}

tree::TerminalNode* SqlParsingParser::Create_index_stmtContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Create_index_stmtContext::UNIQUE() {
  return getToken(SqlParsingParser::UNIQUE, 0);
}

tree::TerminalNode* SqlParsingParser::Create_index_stmtContext::IF() {
  return getToken(SqlParsingParser::IF, 0);
}

tree::TerminalNode* SqlParsingParser::Create_index_stmtContext::NOT() {
  return getToken(SqlParsingParser::NOT, 0);
}

tree::TerminalNode* SqlParsingParser::Create_index_stmtContext::EXISTS() {
  return getToken(SqlParsingParser::EXISTS, 0);
}

SqlParsingParser::Schema_nameContext* SqlParsingParser::Create_index_stmtContext::schema_name() {
  return getRuleContext<SqlParsingParser::Schema_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Create_index_stmtContext::DOT() {
  return getToken(SqlParsingParser::DOT, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Create_index_stmtContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Create_index_stmtContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}

tree::TerminalNode* SqlParsingParser::Create_index_stmtContext::WHERE() {
  return getToken(SqlParsingParser::WHERE, 0);
}

SqlParsingParser::ExprContext* SqlParsingParser::Create_index_stmtContext::expr() {
  return getRuleContext<SqlParsingParser::ExprContext>(0);
}


size_t SqlParsingParser::Create_index_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleCreate_index_stmt;
}

void SqlParsingParser::Create_index_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreate_index_stmt(this);
}

void SqlParsingParser::Create_index_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreate_index_stmt(this);
}


antlrcpp::Any SqlParsingParser::Create_index_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitCreate_index_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Create_index_stmtContext* SqlParsingParser::create_index_stmt() {
  Create_index_stmtContext *_localctx = _tracker.createInstance<Create_index_stmtContext>(_ctx, getState());
  enterRule(_localctx, 20, SqlParsingParser::RuleCreate_index_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(356);
    match(SqlParsingParser::CREATE);
    setState(358);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::UNIQUE) {
      setState(357);
      match(SqlParsingParser::UNIQUE);
    }
    setState(360);
    match(SqlParsingParser::INDEX);
    setState(364);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(361);
      match(SqlParsingParser::IF);
      setState(362);
      match(SqlParsingParser::NOT);
      setState(363);
      match(SqlParsingParser::EXISTS);
      break;
    }

    }
    setState(369);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      setState(366);
      schema_name();
      setState(367);
      match(SqlParsingParser::DOT);
      break;
    }

    }
    setState(371);
    index_name();
    setState(372);
    match(SqlParsingParser::ON);
    setState(373);
    table_name();
    setState(374);
    match(SqlParsingParser::OPEN_PAR);
    setState(375);
    indexed_column();
    setState(380);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SqlParsingParser::COMMA) {
      setState(376);
      match(SqlParsingParser::COMMA);
      setState(377);
      indexed_column();
      setState(382);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(383);
    match(SqlParsingParser::CLOSE_PAR);
    setState(386);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::WHERE) {
      setState(384);
      match(SqlParsingParser::WHERE);
      setState(385);
      expr(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Indexed_columnContext ------------------------------------------------------------------

SqlParsingParser::Indexed_columnContext::Indexed_columnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Column_nameContext* SqlParsingParser::Indexed_columnContext::column_name() {
  return getRuleContext<SqlParsingParser::Column_nameContext>(0);
}

SqlParsingParser::ExprContext* SqlParsingParser::Indexed_columnContext::expr() {
  return getRuleContext<SqlParsingParser::ExprContext>(0);
}

tree::TerminalNode* SqlParsingParser::Indexed_columnContext::COLLATE() {
  return getToken(SqlParsingParser::COLLATE, 0);
}

SqlParsingParser::Collation_nameContext* SqlParsingParser::Indexed_columnContext::collation_name() {
  return getRuleContext<SqlParsingParser::Collation_nameContext>(0);
}

SqlParsingParser::Asc_descContext* SqlParsingParser::Indexed_columnContext::asc_desc() {
  return getRuleContext<SqlParsingParser::Asc_descContext>(0);
}


size_t SqlParsingParser::Indexed_columnContext::getRuleIndex() const {
  return SqlParsingParser::RuleIndexed_column;
}

void SqlParsingParser::Indexed_columnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndexed_column(this);
}

void SqlParsingParser::Indexed_columnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndexed_column(this);
}


antlrcpp::Any SqlParsingParser::Indexed_columnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitIndexed_column(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Indexed_columnContext* SqlParsingParser::indexed_column() {
  Indexed_columnContext *_localctx = _tracker.createInstance<Indexed_columnContext>(_ctx, getState());
  enterRule(_localctx, 22, SqlParsingParser::RuleIndexed_column);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(390);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      setState(388);
      column_name();
      break;
    }

    case 2: {
      setState(389);
      expr(0);
      break;
    }

    }
    setState(394);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::COLLATE) {
      setState(392);
      match(SqlParsingParser::COLLATE);
      setState(393);
      collation_name();
    }
    setState(397);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::ASC

    || _la == SqlParsingParser::DESC) {
      setState(396);
      asc_desc();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Create_table_stmtContext ------------------------------------------------------------------

SqlParsingParser::Create_table_stmtContext::Create_table_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Create_table_stmtContext::CREATE() {
  return getToken(SqlParsingParser::CREATE, 0);
}

tree::TerminalNode* SqlParsingParser::Create_table_stmtContext::TABLE() {
  return getToken(SqlParsingParser::TABLE, 0);
}

SqlParsingParser::Table_nameContext* SqlParsingParser::Create_table_stmtContext::table_name() {
  return getRuleContext<SqlParsingParser::Table_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Create_table_stmtContext::IF() {
  return getToken(SqlParsingParser::IF, 0);
}

tree::TerminalNode* SqlParsingParser::Create_table_stmtContext::NOT() {
  return getToken(SqlParsingParser::NOT, 0);
}

tree::TerminalNode* SqlParsingParser::Create_table_stmtContext::EXISTS() {
  return getToken(SqlParsingParser::EXISTS, 0);
}

SqlParsingParser::Schema_nameContext* SqlParsingParser::Create_table_stmtContext::schema_name() {
  return getRuleContext<SqlParsingParser::Schema_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Create_table_stmtContext::DOT() {
  return getToken(SqlParsingParser::DOT, 0);
}

tree::TerminalNode* SqlParsingParser::Create_table_stmtContext::TEMP() {
  return getToken(SqlParsingParser::TEMP, 0);
}

tree::TerminalNode* SqlParsingParser::Create_table_stmtContext::TEMPORARY() {
  return getToken(SqlParsingParser::TEMPORARY, 0);
}

tree::TerminalNode* SqlParsingParser::Create_table_stmtContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

std::vector<SqlParsingParser::Column_defContext *> SqlParsingParser::Create_table_stmtContext::column_def() {
  return getRuleContexts<SqlParsingParser::Column_defContext>();
}

SqlParsingParser::Column_defContext* SqlParsingParser::Create_table_stmtContext::column_def(size_t i) {
  return getRuleContext<SqlParsingParser::Column_defContext>(i);
}

tree::TerminalNode* SqlParsingParser::Create_table_stmtContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Create_table_stmtContext::AS() {
  return getToken(SqlParsingParser::AS, 0);
}

SqlParsingParser::Select_stmtContext* SqlParsingParser::Create_table_stmtContext::select_stmt() {
  return getRuleContext<SqlParsingParser::Select_stmtContext>(0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Create_table_stmtContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Create_table_stmtContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}

std::vector<SqlParsingParser::Table_constraintContext *> SqlParsingParser::Create_table_stmtContext::table_constraint() {
  return getRuleContexts<SqlParsingParser::Table_constraintContext>();
}

SqlParsingParser::Table_constraintContext* SqlParsingParser::Create_table_stmtContext::table_constraint(size_t i) {
  return getRuleContext<SqlParsingParser::Table_constraintContext>(i);
}

tree::TerminalNode* SqlParsingParser::Create_table_stmtContext::WITHOUT() {
  return getToken(SqlParsingParser::WITHOUT, 0);
}

tree::TerminalNode* SqlParsingParser::Create_table_stmtContext::IDENTIFIER() {
  return getToken(SqlParsingParser::IDENTIFIER, 0);
}


size_t SqlParsingParser::Create_table_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleCreate_table_stmt;
}

void SqlParsingParser::Create_table_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreate_table_stmt(this);
}

void SqlParsingParser::Create_table_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreate_table_stmt(this);
}


antlrcpp::Any SqlParsingParser::Create_table_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitCreate_table_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Create_table_stmtContext* SqlParsingParser::create_table_stmt() {
  Create_table_stmtContext *_localctx = _tracker.createInstance<Create_table_stmtContext>(_ctx, getState());
  enterRule(_localctx, 24, SqlParsingParser::RuleCreate_table_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(399);
    match(SqlParsingParser::CREATE);
    setState(401);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::TEMP

    || _la == SqlParsingParser::TEMPORARY) {
      setState(400);
      _la = _input->LA(1);
      if (!(_la == SqlParsingParser::TEMP

      || _la == SqlParsingParser::TEMPORARY)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(403);
    match(SqlParsingParser::TABLE);
    setState(407);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(404);
      match(SqlParsingParser::IF);
      setState(405);
      match(SqlParsingParser::NOT);
      setState(406);
      match(SqlParsingParser::EXISTS);
      break;
    }

    }
    setState(412);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      setState(409);
      schema_name();
      setState(410);
      match(SqlParsingParser::DOT);
      break;
    }

    }
    setState(414);
    table_name();
    setState(438);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::OPEN_PAR: {
        setState(415);
        match(SqlParsingParser::OPEN_PAR);
        setState(416);
        column_def();
        setState(421);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(417);
            match(SqlParsingParser::COMMA);
            setState(418);
            column_def(); 
          }
          setState(423);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
        }
        setState(428);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParsingParser::COMMA) {
          setState(424);
          match(SqlParsingParser::COMMA);
          setState(425);
          table_constraint();
          setState(430);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(431);
        match(SqlParsingParser::CLOSE_PAR);
        setState(434);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::WITHOUT) {
          setState(432);
          match(SqlParsingParser::WITHOUT);
          setState(433);
          dynamic_cast<Create_table_stmtContext *>(_localctx)->rowID = match(SqlParsingParser::IDENTIFIER);
        }
        break;
      }

      case SqlParsingParser::AS: {
        setState(436);
        match(SqlParsingParser::AS);
        setState(437);
        select_stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_defContext ------------------------------------------------------------------

SqlParsingParser::Column_defContext::Column_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Column_nameContext* SqlParsingParser::Column_defContext::column_name() {
  return getRuleContext<SqlParsingParser::Column_nameContext>(0);
}

SqlParsingParser::Type_nameContext* SqlParsingParser::Column_defContext::type_name() {
  return getRuleContext<SqlParsingParser::Type_nameContext>(0);
}

std::vector<SqlParsingParser::Column_constraintContext *> SqlParsingParser::Column_defContext::column_constraint() {
  return getRuleContexts<SqlParsingParser::Column_constraintContext>();
}

SqlParsingParser::Column_constraintContext* SqlParsingParser::Column_defContext::column_constraint(size_t i) {
  return getRuleContext<SqlParsingParser::Column_constraintContext>(i);
}


size_t SqlParsingParser::Column_defContext::getRuleIndex() const {
  return SqlParsingParser::RuleColumn_def;
}

void SqlParsingParser::Column_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn_def(this);
}

void SqlParsingParser::Column_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn_def(this);
}


antlrcpp::Any SqlParsingParser::Column_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitColumn_def(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Column_defContext* SqlParsingParser::column_def() {
  Column_defContext *_localctx = _tracker.createInstance<Column_defContext>(_ctx, getState());
  enterRule(_localctx, 26, SqlParsingParser::RuleColumn_def);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(440);
    column_name();
    setState(442);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      setState(441);
      type_name();
      break;
    }

    }
    setState(447);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SqlParsingParser::AS)
      | (1ULL << SqlParsingParser::CHECK)
      | (1ULL << SqlParsingParser::COLLATE)
      | (1ULL << SqlParsingParser::CONSTRAINT)
      | (1ULL << SqlParsingParser::DEFAULT))) != 0) || ((((_la - 102) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 102)) & ((1ULL << (SqlParsingParser::NOT - 102))
      | (1ULL << (SqlParsingParser::PRIMARY - 102))
      | (1ULL << (SqlParsingParser::REFERENCES - 102))
      | (1ULL << (SqlParsingParser::UNIQUE - 102)))) != 0) || _la == SqlParsingParser::GENERATED) {
      setState(444);
      column_constraint();
      setState(449);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_nameContext ------------------------------------------------------------------

SqlParsingParser::Type_nameContext::Type_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SqlParsingParser::NameContext *> SqlParsingParser::Type_nameContext::name() {
  return getRuleContexts<SqlParsingParser::NameContext>();
}

SqlParsingParser::NameContext* SqlParsingParser::Type_nameContext::name(size_t i) {
  return getRuleContext<SqlParsingParser::NameContext>(i);
}

tree::TerminalNode* SqlParsingParser::Type_nameContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

std::vector<SqlParsingParser::Signed_numberContext *> SqlParsingParser::Type_nameContext::signed_number() {
  return getRuleContexts<SqlParsingParser::Signed_numberContext>();
}

SqlParsingParser::Signed_numberContext* SqlParsingParser::Type_nameContext::signed_number(size_t i) {
  return getRuleContext<SqlParsingParser::Signed_numberContext>(i);
}

tree::TerminalNode* SqlParsingParser::Type_nameContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Type_nameContext::COMMA() {
  return getToken(SqlParsingParser::COMMA, 0);
}


size_t SqlParsingParser::Type_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleType_name;
}

void SqlParsingParser::Type_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_name(this);
}

void SqlParsingParser::Type_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_name(this);
}


antlrcpp::Any SqlParsingParser::Type_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitType_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Type_nameContext* SqlParsingParser::type_name() {
  Type_nameContext *_localctx = _tracker.createInstance<Type_nameContext>(_ctx, getState());
  enterRule(_localctx, 28, SqlParsingParser::RuleType_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(451); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(450);
              name();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(453); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(465);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      setState(455);
      match(SqlParsingParser::OPEN_PAR);
      setState(456);
      signed_number();
      setState(457);
      match(SqlParsingParser::CLOSE_PAR);
      break;
    }

    case 2: {
      setState(459);
      match(SqlParsingParser::OPEN_PAR);
      setState(460);
      signed_number();
      setState(461);
      match(SqlParsingParser::COMMA);
      setState(462);
      signed_number();
      setState(463);
      match(SqlParsingParser::CLOSE_PAR);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_constraintContext ------------------------------------------------------------------

SqlParsingParser::Column_constraintContext::Column_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Column_constraintContext::CHECK() {
  return getToken(SqlParsingParser::CHECK, 0);
}

tree::TerminalNode* SqlParsingParser::Column_constraintContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

SqlParsingParser::ExprContext* SqlParsingParser::Column_constraintContext::expr() {
  return getRuleContext<SqlParsingParser::ExprContext>(0);
}

tree::TerminalNode* SqlParsingParser::Column_constraintContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Column_constraintContext::DEFAULT() {
  return getToken(SqlParsingParser::DEFAULT, 0);
}

tree::TerminalNode* SqlParsingParser::Column_constraintContext::COLLATE() {
  return getToken(SqlParsingParser::COLLATE, 0);
}

SqlParsingParser::Collation_nameContext* SqlParsingParser::Column_constraintContext::collation_name() {
  return getRuleContext<SqlParsingParser::Collation_nameContext>(0);
}

SqlParsingParser::Foreign_key_clauseContext* SqlParsingParser::Column_constraintContext::foreign_key_clause() {
  return getRuleContext<SqlParsingParser::Foreign_key_clauseContext>(0);
}

tree::TerminalNode* SqlParsingParser::Column_constraintContext::AS() {
  return getToken(SqlParsingParser::AS, 0);
}

tree::TerminalNode* SqlParsingParser::Column_constraintContext::CONSTRAINT() {
  return getToken(SqlParsingParser::CONSTRAINT, 0);
}

SqlParsingParser::NameContext* SqlParsingParser::Column_constraintContext::name() {
  return getRuleContext<SqlParsingParser::NameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Column_constraintContext::PRIMARY() {
  return getToken(SqlParsingParser::PRIMARY, 0);
}

tree::TerminalNode* SqlParsingParser::Column_constraintContext::KEY() {
  return getToken(SqlParsingParser::KEY, 0);
}

tree::TerminalNode* SqlParsingParser::Column_constraintContext::UNIQUE() {
  return getToken(SqlParsingParser::UNIQUE, 0);
}

SqlParsingParser::Signed_numberContext* SqlParsingParser::Column_constraintContext::signed_number() {
  return getRuleContext<SqlParsingParser::Signed_numberContext>(0);
}

SqlParsingParser::Literal_valueContext* SqlParsingParser::Column_constraintContext::literal_value() {
  return getRuleContext<SqlParsingParser::Literal_valueContext>(0);
}

SqlParsingParser::Conflict_clauseContext* SqlParsingParser::Column_constraintContext::conflict_clause() {
  return getRuleContext<SqlParsingParser::Conflict_clauseContext>(0);
}

tree::TerminalNode* SqlParsingParser::Column_constraintContext::GENERATED() {
  return getToken(SqlParsingParser::GENERATED, 0);
}

tree::TerminalNode* SqlParsingParser::Column_constraintContext::ALWAYS() {
  return getToken(SqlParsingParser::ALWAYS, 0);
}

tree::TerminalNode* SqlParsingParser::Column_constraintContext::NOT() {
  return getToken(SqlParsingParser::NOT, 0);
}

tree::TerminalNode* SqlParsingParser::Column_constraintContext::NULL_() {
  return getToken(SqlParsingParser::NULL_, 0);
}

tree::TerminalNode* SqlParsingParser::Column_constraintContext::STORED() {
  return getToken(SqlParsingParser::STORED, 0);
}

tree::TerminalNode* SqlParsingParser::Column_constraintContext::VIRTUAL() {
  return getToken(SqlParsingParser::VIRTUAL, 0);
}

SqlParsingParser::Asc_descContext* SqlParsingParser::Column_constraintContext::asc_desc() {
  return getRuleContext<SqlParsingParser::Asc_descContext>(0);
}

tree::TerminalNode* SqlParsingParser::Column_constraintContext::AUTOINCREMENT() {
  return getToken(SqlParsingParser::AUTOINCREMENT, 0);
}


size_t SqlParsingParser::Column_constraintContext::getRuleIndex() const {
  return SqlParsingParser::RuleColumn_constraint;
}

void SqlParsingParser::Column_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn_constraint(this);
}

void SqlParsingParser::Column_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn_constraint(this);
}


antlrcpp::Any SqlParsingParser::Column_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitColumn_constraint(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Column_constraintContext* SqlParsingParser::column_constraint() {
  Column_constraintContext *_localctx = _tracker.createInstance<Column_constraintContext>(_ctx, getState());
  enterRule(_localctx, 30, SqlParsingParser::RuleColumn_constraint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(469);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::CONSTRAINT) {
      setState(467);
      match(SqlParsingParser::CONSTRAINT);
      setState(468);
      name();
    }
    setState(518);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::PRIMARY: {
        setState(471);
        match(SqlParsingParser::PRIMARY);
        setState(472);
        match(SqlParsingParser::KEY);
        setState(474);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::ASC

        || _la == SqlParsingParser::DESC) {
          setState(473);
          asc_desc();
        }
        setState(477);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::ON) {
          setState(476);
          conflict_clause();
        }
        setState(480);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::AUTOINCREMENT) {
          setState(479);
          match(SqlParsingParser::AUTOINCREMENT);
        }
        break;
      }

      case SqlParsingParser::NOT:
      case SqlParsingParser::UNIQUE: {
        setState(485);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case SqlParsingParser::NOT: {
            setState(482);
            match(SqlParsingParser::NOT);
            setState(483);
            match(SqlParsingParser::NULL_);
            break;
          }

          case SqlParsingParser::UNIQUE: {
            setState(484);
            match(SqlParsingParser::UNIQUE);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(488);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::ON) {
          setState(487);
          conflict_clause();
        }
        break;
      }

      case SqlParsingParser::CHECK: {
        setState(490);
        match(SqlParsingParser::CHECK);
        setState(491);
        match(SqlParsingParser::OPEN_PAR);
        setState(492);
        expr(0);
        setState(493);
        match(SqlParsingParser::CLOSE_PAR);
        break;
      }

      case SqlParsingParser::DEFAULT: {
        setState(495);
        match(SqlParsingParser::DEFAULT);
        setState(502);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
        case 1: {
          setState(496);
          signed_number();
          break;
        }

        case 2: {
          setState(497);
          literal_value();
          break;
        }

        case 3: {
          setState(498);
          match(SqlParsingParser::OPEN_PAR);
          setState(499);
          expr(0);
          setState(500);
          match(SqlParsingParser::CLOSE_PAR);
          break;
        }

        }
        break;
      }

      case SqlParsingParser::COLLATE: {
        setState(504);
        match(SqlParsingParser::COLLATE);
        setState(505);
        collation_name();
        break;
      }

      case SqlParsingParser::REFERENCES: {
        setState(506);
        foreign_key_clause();
        break;
      }

      case SqlParsingParser::AS:
      case SqlParsingParser::GENERATED: {
        setState(509);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::GENERATED) {
          setState(507);
          match(SqlParsingParser::GENERATED);
          setState(508);
          match(SqlParsingParser::ALWAYS);
        }
        setState(511);
        match(SqlParsingParser::AS);
        setState(512);
        match(SqlParsingParser::OPEN_PAR);
        setState(513);
        expr(0);
        setState(514);
        match(SqlParsingParser::CLOSE_PAR);
        setState(516);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::VIRTUAL

        || _la == SqlParsingParser::STORED) {
          setState(515);
          _la = _input->LA(1);
          if (!(_la == SqlParsingParser::VIRTUAL

          || _la == SqlParsingParser::STORED)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Signed_numberContext ------------------------------------------------------------------

SqlParsingParser::Signed_numberContext::Signed_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Signed_numberContext::NUMERIC_LITERAL() {
  return getToken(SqlParsingParser::NUMERIC_LITERAL, 0);
}

tree::TerminalNode* SqlParsingParser::Signed_numberContext::PLUS() {
  return getToken(SqlParsingParser::PLUS, 0);
}

tree::TerminalNode* SqlParsingParser::Signed_numberContext::MINUS() {
  return getToken(SqlParsingParser::MINUS, 0);
}


size_t SqlParsingParser::Signed_numberContext::getRuleIndex() const {
  return SqlParsingParser::RuleSigned_number;
}

void SqlParsingParser::Signed_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSigned_number(this);
}

void SqlParsingParser::Signed_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSigned_number(this);
}


antlrcpp::Any SqlParsingParser::Signed_numberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitSigned_number(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Signed_numberContext* SqlParsingParser::signed_number() {
  Signed_numberContext *_localctx = _tracker.createInstance<Signed_numberContext>(_ctx, getState());
  enterRule(_localctx, 32, SqlParsingParser::RuleSigned_number);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(521);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::PLUS

    || _la == SqlParsingParser::MINUS) {
      setState(520);
      _la = _input->LA(1);
      if (!(_la == SqlParsingParser::PLUS

      || _la == SqlParsingParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(523);
    match(SqlParsingParser::NUMERIC_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_constraintContext ------------------------------------------------------------------

SqlParsingParser::Table_constraintContext::Table_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Table_constraintContext::CONSTRAINT() {
  return getToken(SqlParsingParser::CONSTRAINT, 0);
}

SqlParsingParser::NameContext* SqlParsingParser::Table_constraintContext::name() {
  return getRuleContext<SqlParsingParser::NameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Table_constraintContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

std::vector<SqlParsingParser::Indexed_columnContext *> SqlParsingParser::Table_constraintContext::indexed_column() {
  return getRuleContexts<SqlParsingParser::Indexed_columnContext>();
}

SqlParsingParser::Indexed_columnContext* SqlParsingParser::Table_constraintContext::indexed_column(size_t i) {
  return getRuleContext<SqlParsingParser::Indexed_columnContext>(i);
}

tree::TerminalNode* SqlParsingParser::Table_constraintContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Table_constraintContext::CHECK() {
  return getToken(SqlParsingParser::CHECK, 0);
}

SqlParsingParser::ExprContext* SqlParsingParser::Table_constraintContext::expr() {
  return getRuleContext<SqlParsingParser::ExprContext>(0);
}

tree::TerminalNode* SqlParsingParser::Table_constraintContext::FOREIGN() {
  return getToken(SqlParsingParser::FOREIGN, 0);
}

tree::TerminalNode* SqlParsingParser::Table_constraintContext::KEY() {
  return getToken(SqlParsingParser::KEY, 0);
}

std::vector<SqlParsingParser::Column_nameContext *> SqlParsingParser::Table_constraintContext::column_name() {
  return getRuleContexts<SqlParsingParser::Column_nameContext>();
}

SqlParsingParser::Column_nameContext* SqlParsingParser::Table_constraintContext::column_name(size_t i) {
  return getRuleContext<SqlParsingParser::Column_nameContext>(i);
}

SqlParsingParser::Foreign_key_clauseContext* SqlParsingParser::Table_constraintContext::foreign_key_clause() {
  return getRuleContext<SqlParsingParser::Foreign_key_clauseContext>(0);
}

tree::TerminalNode* SqlParsingParser::Table_constraintContext::PRIMARY() {
  return getToken(SqlParsingParser::PRIMARY, 0);
}

tree::TerminalNode* SqlParsingParser::Table_constraintContext::UNIQUE() {
  return getToken(SqlParsingParser::UNIQUE, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Table_constraintContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Table_constraintContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}

SqlParsingParser::Conflict_clauseContext* SqlParsingParser::Table_constraintContext::conflict_clause() {
  return getRuleContext<SqlParsingParser::Conflict_clauseContext>(0);
}


size_t SqlParsingParser::Table_constraintContext::getRuleIndex() const {
  return SqlParsingParser::RuleTable_constraint;
}

void SqlParsingParser::Table_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_constraint(this);
}

void SqlParsingParser::Table_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_constraint(this);
}


antlrcpp::Any SqlParsingParser::Table_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitTable_constraint(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Table_constraintContext* SqlParsingParser::table_constraint() {
  Table_constraintContext *_localctx = _tracker.createInstance<Table_constraintContext>(_ctx, getState());
  enterRule(_localctx, 34, SqlParsingParser::RuleTable_constraint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(527);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::CONSTRAINT) {
      setState(525);
      match(SqlParsingParser::CONSTRAINT);
      setState(526);
      name();
    }
    setState(566);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::PRIMARY:
      case SqlParsingParser::UNIQUE: {
        setState(532);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case SqlParsingParser::PRIMARY: {
            setState(529);
            match(SqlParsingParser::PRIMARY);
            setState(530);
            match(SqlParsingParser::KEY);
            break;
          }

          case SqlParsingParser::UNIQUE: {
            setState(531);
            match(SqlParsingParser::UNIQUE);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(534);
        match(SqlParsingParser::OPEN_PAR);
        setState(535);
        indexed_column();
        setState(540);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParsingParser::COMMA) {
          setState(536);
          match(SqlParsingParser::COMMA);
          setState(537);
          indexed_column();
          setState(542);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(543);
        match(SqlParsingParser::CLOSE_PAR);
        setState(545);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::ON) {
          setState(544);
          conflict_clause();
        }
        break;
      }

      case SqlParsingParser::CHECK: {
        setState(547);
        match(SqlParsingParser::CHECK);
        setState(548);
        match(SqlParsingParser::OPEN_PAR);
        setState(549);
        expr(0);
        setState(550);
        match(SqlParsingParser::CLOSE_PAR);
        break;
      }

      case SqlParsingParser::FOREIGN: {
        setState(552);
        match(SqlParsingParser::FOREIGN);
        setState(553);
        match(SqlParsingParser::KEY);
        setState(554);
        match(SqlParsingParser::OPEN_PAR);
        setState(555);
        column_name();
        setState(560);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParsingParser::COMMA) {
          setState(556);
          match(SqlParsingParser::COMMA);
          setState(557);
          column_name();
          setState(562);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(563);
        match(SqlParsingParser::CLOSE_PAR);
        setState(564);
        foreign_key_clause();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Foreign_key_clauseContext ------------------------------------------------------------------

SqlParsingParser::Foreign_key_clauseContext::Foreign_key_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::REFERENCES() {
  return getToken(SqlParsingParser::REFERENCES, 0);
}

SqlParsingParser::Foreign_tableContext* SqlParsingParser::Foreign_key_clauseContext::foreign_table() {
  return getRuleContext<SqlParsingParser::Foreign_tableContext>(0);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

std::vector<SqlParsingParser::Column_nameContext *> SqlParsingParser::Foreign_key_clauseContext::column_name() {
  return getRuleContexts<SqlParsingParser::Column_nameContext>();
}

SqlParsingParser::Column_nameContext* SqlParsingParser::Foreign_key_clauseContext::column_name(size_t i) {
  return getRuleContext<SqlParsingParser::Column_nameContext>(i);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::DEFERRABLE() {
  return getToken(SqlParsingParser::DEFERRABLE, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Foreign_key_clauseContext::ON() {
  return getTokens(SqlParsingParser::ON);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::ON(size_t i) {
  return getToken(SqlParsingParser::ON, i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Foreign_key_clauseContext::MATCH() {
  return getTokens(SqlParsingParser::MATCH);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::MATCH(size_t i) {
  return getToken(SqlParsingParser::MATCH, i);
}

std::vector<SqlParsingParser::NameContext *> SqlParsingParser::Foreign_key_clauseContext::name() {
  return getRuleContexts<SqlParsingParser::NameContext>();
}

SqlParsingParser::NameContext* SqlParsingParser::Foreign_key_clauseContext::name(size_t i) {
  return getRuleContext<SqlParsingParser::NameContext>(i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Foreign_key_clauseContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Foreign_key_clauseContext::DELETE() {
  return getTokens(SqlParsingParser::DELETE);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::DELETE(size_t i) {
  return getToken(SqlParsingParser::DELETE, i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Foreign_key_clauseContext::UPDATE() {
  return getTokens(SqlParsingParser::UPDATE);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::UPDATE(size_t i) {
  return getToken(SqlParsingParser::UPDATE, i);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::NOT() {
  return getToken(SqlParsingParser::NOT, 0);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::INITIALLY() {
  return getToken(SqlParsingParser::INITIALLY, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Foreign_key_clauseContext::CASCADE() {
  return getTokens(SqlParsingParser::CASCADE);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::CASCADE(size_t i) {
  return getToken(SqlParsingParser::CASCADE, i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Foreign_key_clauseContext::RESTRICT() {
  return getTokens(SqlParsingParser::RESTRICT);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::RESTRICT(size_t i) {
  return getToken(SqlParsingParser::RESTRICT, i);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::DEFERRED() {
  return getToken(SqlParsingParser::DEFERRED, 0);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::IMMEDIATE() {
  return getToken(SqlParsingParser::IMMEDIATE, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Foreign_key_clauseContext::SET() {
  return getTokens(SqlParsingParser::SET);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::SET(size_t i) {
  return getToken(SqlParsingParser::SET, i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Foreign_key_clauseContext::NO() {
  return getTokens(SqlParsingParser::NO);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::NO(size_t i) {
  return getToken(SqlParsingParser::NO, i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Foreign_key_clauseContext::ACTION() {
  return getTokens(SqlParsingParser::ACTION);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::ACTION(size_t i) {
  return getToken(SqlParsingParser::ACTION, i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Foreign_key_clauseContext::NULL_() {
  return getTokens(SqlParsingParser::NULL_);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::NULL_(size_t i) {
  return getToken(SqlParsingParser::NULL_, i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Foreign_key_clauseContext::DEFAULT() {
  return getTokens(SqlParsingParser::DEFAULT);
}

tree::TerminalNode* SqlParsingParser::Foreign_key_clauseContext::DEFAULT(size_t i) {
  return getToken(SqlParsingParser::DEFAULT, i);
}


size_t SqlParsingParser::Foreign_key_clauseContext::getRuleIndex() const {
  return SqlParsingParser::RuleForeign_key_clause;
}

void SqlParsingParser::Foreign_key_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForeign_key_clause(this);
}

void SqlParsingParser::Foreign_key_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForeign_key_clause(this);
}


antlrcpp::Any SqlParsingParser::Foreign_key_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitForeign_key_clause(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Foreign_key_clauseContext* SqlParsingParser::foreign_key_clause() {
  Foreign_key_clauseContext *_localctx = _tracker.createInstance<Foreign_key_clauseContext>(_ctx, getState());
  enterRule(_localctx, 36, SqlParsingParser::RuleForeign_key_clause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(568);
    match(SqlParsingParser::REFERENCES);
    setState(569);
    foreign_table();
    setState(581);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::OPEN_PAR) {
      setState(570);
      match(SqlParsingParser::OPEN_PAR);
      setState(571);
      column_name();
      setState(576);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SqlParsingParser::COMMA) {
        setState(572);
        match(SqlParsingParser::COMMA);
        setState(573);
        column_name();
        setState(578);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(579);
      match(SqlParsingParser::CLOSE_PAR);
    }
    setState(597);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SqlParsingParser::MATCH

    || _la == SqlParsingParser::ON) {
      setState(595);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SqlParsingParser::ON: {
          setState(583);
          match(SqlParsingParser::ON);
          setState(584);
          _la = _input->LA(1);
          if (!(_la == SqlParsingParser::DELETE || _la == SqlParsingParser::UPDATE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(591);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case SqlParsingParser::SET: {
              setState(585);
              match(SqlParsingParser::SET);
              setState(586);
              _la = _input->LA(1);
              if (!(_la == SqlParsingParser::DEFAULT

              || _la == SqlParsingParser::NULL_)) {
              _errHandler->recoverInline(this);
              }
              else {
                _errHandler->reportMatch(this);
                consume();
              }
              break;
            }

            case SqlParsingParser::CASCADE: {
              setState(587);
              match(SqlParsingParser::CASCADE);
              break;
            }

            case SqlParsingParser::RESTRICT: {
              setState(588);
              match(SqlParsingParser::RESTRICT);
              break;
            }

            case SqlParsingParser::NO: {
              setState(589);
              match(SqlParsingParser::NO);
              setState(590);
              match(SqlParsingParser::ACTION);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          break;
        }

        case SqlParsingParser::MATCH: {
          setState(593);
          match(SqlParsingParser::MATCH);
          setState(594);
          name();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(599);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(608);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx)) {
    case 1: {
      setState(601);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SqlParsingParser::NOT) {
        setState(600);
        match(SqlParsingParser::NOT);
      }
      setState(603);
      match(SqlParsingParser::DEFERRABLE);
      setState(606);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SqlParsingParser::INITIALLY) {
        setState(604);
        match(SqlParsingParser::INITIALLY);
        setState(605);
        _la = _input->LA(1);
        if (!(_la == SqlParsingParser::DEFERRED

        || _la == SqlParsingParser::IMMEDIATE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Conflict_clauseContext ------------------------------------------------------------------

SqlParsingParser::Conflict_clauseContext::Conflict_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Conflict_clauseContext::ON() {
  return getToken(SqlParsingParser::ON, 0);
}

tree::TerminalNode* SqlParsingParser::Conflict_clauseContext::CONFLICT() {
  return getToken(SqlParsingParser::CONFLICT, 0);
}

tree::TerminalNode* SqlParsingParser::Conflict_clauseContext::ROLLBACK() {
  return getToken(SqlParsingParser::ROLLBACK, 0);
}

tree::TerminalNode* SqlParsingParser::Conflict_clauseContext::ABORT() {
  return getToken(SqlParsingParser::ABORT, 0);
}

tree::TerminalNode* SqlParsingParser::Conflict_clauseContext::FAIL() {
  return getToken(SqlParsingParser::FAIL, 0);
}

tree::TerminalNode* SqlParsingParser::Conflict_clauseContext::IGNORE() {
  return getToken(SqlParsingParser::IGNORE, 0);
}

tree::TerminalNode* SqlParsingParser::Conflict_clauseContext::REPLACE() {
  return getToken(SqlParsingParser::REPLACE, 0);
}


size_t SqlParsingParser::Conflict_clauseContext::getRuleIndex() const {
  return SqlParsingParser::RuleConflict_clause;
}

void SqlParsingParser::Conflict_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConflict_clause(this);
}

void SqlParsingParser::Conflict_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConflict_clause(this);
}


antlrcpp::Any SqlParsingParser::Conflict_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitConflict_clause(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Conflict_clauseContext* SqlParsingParser::conflict_clause() {
  Conflict_clauseContext *_localctx = _tracker.createInstance<Conflict_clauseContext>(_ctx, getState());
  enterRule(_localctx, 38, SqlParsingParser::RuleConflict_clause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(610);
    match(SqlParsingParser::ON);
    setState(611);
    match(SqlParsingParser::CONFLICT);
    setState(612);
    _la = _input->LA(1);
    if (!(_la == SqlParsingParser::ABORT || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (SqlParsingParser::FAIL - 72))
      | (1ULL << (SqlParsingParser::IGNORE - 72))
      | (1ULL << (SqlParsingParser::REPLACE - 72))
      | (1ULL << (SqlParsingParser::ROLLBACK - 72)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Create_trigger_stmtContext ------------------------------------------------------------------

SqlParsingParser::Create_trigger_stmtContext::Create_trigger_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::CREATE() {
  return getToken(SqlParsingParser::CREATE, 0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::TRIGGER() {
  return getToken(SqlParsingParser::TRIGGER, 0);
}

SqlParsingParser::Trigger_nameContext* SqlParsingParser::Create_trigger_stmtContext::trigger_name() {
  return getRuleContext<SqlParsingParser::Trigger_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::ON() {
  return getToken(SqlParsingParser::ON, 0);
}

SqlParsingParser::Table_nameContext* SqlParsingParser::Create_trigger_stmtContext::table_name() {
  return getRuleContext<SqlParsingParser::Table_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::BEGIN() {
  return getToken(SqlParsingParser::BEGIN, 0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::END() {
  return getToken(SqlParsingParser::END, 0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::DELETE() {
  return getToken(SqlParsingParser::DELETE, 0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::INSERT() {
  return getToken(SqlParsingParser::INSERT, 0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::IF() {
  return getToken(SqlParsingParser::IF, 0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::NOT() {
  return getToken(SqlParsingParser::NOT, 0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::EXISTS() {
  return getToken(SqlParsingParser::EXISTS, 0);
}

SqlParsingParser::Schema_nameContext* SqlParsingParser::Create_trigger_stmtContext::schema_name() {
  return getRuleContext<SqlParsingParser::Schema_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::DOT() {
  return getToken(SqlParsingParser::DOT, 0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::BEFORE() {
  return getToken(SqlParsingParser::BEFORE, 0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::AFTER() {
  return getToken(SqlParsingParser::AFTER, 0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::FOR() {
  return getToken(SqlParsingParser::FOR, 0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::EACH() {
  return getToken(SqlParsingParser::EACH, 0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::ROW() {
  return getToken(SqlParsingParser::ROW, 0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::WHEN() {
  return getToken(SqlParsingParser::WHEN, 0);
}

SqlParsingParser::ExprContext* SqlParsingParser::Create_trigger_stmtContext::expr() {
  return getRuleContext<SqlParsingParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Create_trigger_stmtContext::SCOL() {
  return getTokens(SqlParsingParser::SCOL);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::SCOL(size_t i) {
  return getToken(SqlParsingParser::SCOL, i);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::TEMP() {
  return getToken(SqlParsingParser::TEMP, 0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::TEMPORARY() {
  return getToken(SqlParsingParser::TEMPORARY, 0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::UPDATE() {
  return getToken(SqlParsingParser::UPDATE, 0);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::INSTEAD() {
  return getToken(SqlParsingParser::INSTEAD, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Create_trigger_stmtContext::OF() {
  return getTokens(SqlParsingParser::OF);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::OF(size_t i) {
  return getToken(SqlParsingParser::OF, i);
}

std::vector<SqlParsingParser::Update_stmtContext *> SqlParsingParser::Create_trigger_stmtContext::update_stmt() {
  return getRuleContexts<SqlParsingParser::Update_stmtContext>();
}

SqlParsingParser::Update_stmtContext* SqlParsingParser::Create_trigger_stmtContext::update_stmt(size_t i) {
  return getRuleContext<SqlParsingParser::Update_stmtContext>(i);
}

std::vector<SqlParsingParser::Insert_stmtContext *> SqlParsingParser::Create_trigger_stmtContext::insert_stmt() {
  return getRuleContexts<SqlParsingParser::Insert_stmtContext>();
}

SqlParsingParser::Insert_stmtContext* SqlParsingParser::Create_trigger_stmtContext::insert_stmt(size_t i) {
  return getRuleContext<SqlParsingParser::Insert_stmtContext>(i);
}

std::vector<SqlParsingParser::Delete_stmtContext *> SqlParsingParser::Create_trigger_stmtContext::delete_stmt() {
  return getRuleContexts<SqlParsingParser::Delete_stmtContext>();
}

SqlParsingParser::Delete_stmtContext* SqlParsingParser::Create_trigger_stmtContext::delete_stmt(size_t i) {
  return getRuleContext<SqlParsingParser::Delete_stmtContext>(i);
}

std::vector<SqlParsingParser::Select_stmtContext *> SqlParsingParser::Create_trigger_stmtContext::select_stmt() {
  return getRuleContexts<SqlParsingParser::Select_stmtContext>();
}

SqlParsingParser::Select_stmtContext* SqlParsingParser::Create_trigger_stmtContext::select_stmt(size_t i) {
  return getRuleContext<SqlParsingParser::Select_stmtContext>(i);
}

std::vector<SqlParsingParser::Column_nameContext *> SqlParsingParser::Create_trigger_stmtContext::column_name() {
  return getRuleContexts<SqlParsingParser::Column_nameContext>();
}

SqlParsingParser::Column_nameContext* SqlParsingParser::Create_trigger_stmtContext::column_name(size_t i) {
  return getRuleContext<SqlParsingParser::Column_nameContext>(i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Create_trigger_stmtContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Create_trigger_stmtContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}


size_t SqlParsingParser::Create_trigger_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleCreate_trigger_stmt;
}

void SqlParsingParser::Create_trigger_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreate_trigger_stmt(this);
}

void SqlParsingParser::Create_trigger_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreate_trigger_stmt(this);
}


antlrcpp::Any SqlParsingParser::Create_trigger_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitCreate_trigger_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Create_trigger_stmtContext* SqlParsingParser::create_trigger_stmt() {
  Create_trigger_stmtContext *_localctx = _tracker.createInstance<Create_trigger_stmtContext>(_ctx, getState());
  enterRule(_localctx, 40, SqlParsingParser::RuleCreate_trigger_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(614);
    match(SqlParsingParser::CREATE);
    setState(616);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::TEMP

    || _la == SqlParsingParser::TEMPORARY) {
      setState(615);
      _la = _input->LA(1);
      if (!(_la == SqlParsingParser::TEMP

      || _la == SqlParsingParser::TEMPORARY)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(618);
    match(SqlParsingParser::TRIGGER);
    setState(622);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx)) {
    case 1: {
      setState(619);
      match(SqlParsingParser::IF);
      setState(620);
      match(SqlParsingParser::NOT);
      setState(621);
      match(SqlParsingParser::EXISTS);
      break;
    }

    }
    setState(627);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx)) {
    case 1: {
      setState(624);
      schema_name();
      setState(625);
      match(SqlParsingParser::DOT);
      break;
    }

    }
    setState(629);
    trigger_name();
    setState(634);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::BEFORE: {
        setState(630);
        match(SqlParsingParser::BEFORE);
        break;
      }

      case SqlParsingParser::AFTER: {
        setState(631);
        match(SqlParsingParser::AFTER);
        break;
      }

      case SqlParsingParser::INSTEAD: {
        setState(632);
        match(SqlParsingParser::INSTEAD);
        setState(633);
        match(SqlParsingParser::OF);
        break;
      }

      case SqlParsingParser::DELETE:
      case SqlParsingParser::INSERT:
      case SqlParsingParser::UPDATE: {
        break;
      }

    default:
      break;
    }
    setState(650);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::DELETE: {
        setState(636);
        match(SqlParsingParser::DELETE);
        break;
      }

      case SqlParsingParser::INSERT: {
        setState(637);
        match(SqlParsingParser::INSERT);
        break;
      }

      case SqlParsingParser::UPDATE: {
        setState(638);
        match(SqlParsingParser::UPDATE);
        setState(648);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::OF) {
          setState(639);
          match(SqlParsingParser::OF);
          setState(640);
          column_name();
          setState(645);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SqlParsingParser::COMMA) {
            setState(641);
            match(SqlParsingParser::COMMA);
            setState(642);
            column_name();
            setState(647);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(652);
    match(SqlParsingParser::ON);
    setState(653);
    table_name();
    setState(657);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::FOR) {
      setState(654);
      match(SqlParsingParser::FOR);
      setState(655);
      match(SqlParsingParser::EACH);
      setState(656);
      match(SqlParsingParser::ROW);
    }
    setState(661);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::WHEN) {
      setState(659);
      match(SqlParsingParser::WHEN);
      setState(660);
      expr(0);
    }
    setState(663);
    match(SqlParsingParser::BEGIN);
    setState(672); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(668);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx)) {
      case 1: {
        setState(664);
        update_stmt();
        break;
      }

      case 2: {
        setState(665);
        insert_stmt();
        break;
      }

      case 3: {
        setState(666);
        delete_stmt();
        break;
      }

      case 4: {
        setState(667);
        select_stmt();
        break;
      }

      }
      setState(670);
      match(SqlParsingParser::SCOL);
      setState(674); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SqlParsingParser::DEFAULT

    || _la == SqlParsingParser::DELETE || ((((_la - 88) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 88)) & ((1ULL << (SqlParsingParser::INSERT - 88))
      | (1ULL << (SqlParsingParser::REPLACE - 88))
      | (1ULL << (SqlParsingParser::SELECT - 88))
      | (1ULL << (SqlParsingParser::UPDATE - 88))
      | (1ULL << (SqlParsingParser::VALUES - 88))
      | (1ULL << (SqlParsingParser::WITH - 88)))) != 0));
    setState(676);
    match(SqlParsingParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Create_view_stmtContext ------------------------------------------------------------------

SqlParsingParser::Create_view_stmtContext::Create_view_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Create_view_stmtContext::CREATE() {
  return getToken(SqlParsingParser::CREATE, 0);
}

tree::TerminalNode* SqlParsingParser::Create_view_stmtContext::VIEW() {
  return getToken(SqlParsingParser::VIEW, 0);
}

SqlParsingParser::View_nameContext* SqlParsingParser::Create_view_stmtContext::view_name() {
  return getRuleContext<SqlParsingParser::View_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Create_view_stmtContext::AS() {
  return getToken(SqlParsingParser::AS, 0);
}

SqlParsingParser::Select_stmtContext* SqlParsingParser::Create_view_stmtContext::select_stmt() {
  return getRuleContext<SqlParsingParser::Select_stmtContext>(0);
}

tree::TerminalNode* SqlParsingParser::Create_view_stmtContext::IF() {
  return getToken(SqlParsingParser::IF, 0);
}

tree::TerminalNode* SqlParsingParser::Create_view_stmtContext::NOT() {
  return getToken(SqlParsingParser::NOT, 0);
}

tree::TerminalNode* SqlParsingParser::Create_view_stmtContext::EXISTS() {
  return getToken(SqlParsingParser::EXISTS, 0);
}

SqlParsingParser::Schema_nameContext* SqlParsingParser::Create_view_stmtContext::schema_name() {
  return getRuleContext<SqlParsingParser::Schema_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Create_view_stmtContext::DOT() {
  return getToken(SqlParsingParser::DOT, 0);
}

tree::TerminalNode* SqlParsingParser::Create_view_stmtContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

std::vector<SqlParsingParser::Column_nameContext *> SqlParsingParser::Create_view_stmtContext::column_name() {
  return getRuleContexts<SqlParsingParser::Column_nameContext>();
}

SqlParsingParser::Column_nameContext* SqlParsingParser::Create_view_stmtContext::column_name(size_t i) {
  return getRuleContext<SqlParsingParser::Column_nameContext>(i);
}

tree::TerminalNode* SqlParsingParser::Create_view_stmtContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Create_view_stmtContext::TEMP() {
  return getToken(SqlParsingParser::TEMP, 0);
}

tree::TerminalNode* SqlParsingParser::Create_view_stmtContext::TEMPORARY() {
  return getToken(SqlParsingParser::TEMPORARY, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Create_view_stmtContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Create_view_stmtContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}


size_t SqlParsingParser::Create_view_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleCreate_view_stmt;
}

void SqlParsingParser::Create_view_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreate_view_stmt(this);
}

void SqlParsingParser::Create_view_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreate_view_stmt(this);
}


antlrcpp::Any SqlParsingParser::Create_view_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitCreate_view_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Create_view_stmtContext* SqlParsingParser::create_view_stmt() {
  Create_view_stmtContext *_localctx = _tracker.createInstance<Create_view_stmtContext>(_ctx, getState());
  enterRule(_localctx, 42, SqlParsingParser::RuleCreate_view_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(678);
    match(SqlParsingParser::CREATE);
    setState(680);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::TEMP

    || _la == SqlParsingParser::TEMPORARY) {
      setState(679);
      _la = _input->LA(1);
      if (!(_la == SqlParsingParser::TEMP

      || _la == SqlParsingParser::TEMPORARY)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(682);
    match(SqlParsingParser::VIEW);
    setState(686);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx)) {
    case 1: {
      setState(683);
      match(SqlParsingParser::IF);
      setState(684);
      match(SqlParsingParser::NOT);
      setState(685);
      match(SqlParsingParser::EXISTS);
      break;
    }

    }
    setState(691);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx)) {
    case 1: {
      setState(688);
      schema_name();
      setState(689);
      match(SqlParsingParser::DOT);
      break;
    }

    }
    setState(693);
    view_name();
    setState(705);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::OPEN_PAR) {
      setState(694);
      match(SqlParsingParser::OPEN_PAR);
      setState(695);
      column_name();
      setState(700);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SqlParsingParser::COMMA) {
        setState(696);
        match(SqlParsingParser::COMMA);
        setState(697);
        column_name();
        setState(702);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(703);
      match(SqlParsingParser::CLOSE_PAR);
    }
    setState(707);
    match(SqlParsingParser::AS);
    setState(708);
    select_stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Create_virtual_table_stmtContext ------------------------------------------------------------------

SqlParsingParser::Create_virtual_table_stmtContext::Create_virtual_table_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Create_virtual_table_stmtContext::CREATE() {
  return getToken(SqlParsingParser::CREATE, 0);
}

tree::TerminalNode* SqlParsingParser::Create_virtual_table_stmtContext::VIRTUAL() {
  return getToken(SqlParsingParser::VIRTUAL, 0);
}

tree::TerminalNode* SqlParsingParser::Create_virtual_table_stmtContext::TABLE() {
  return getToken(SqlParsingParser::TABLE, 0);
}

SqlParsingParser::Table_nameContext* SqlParsingParser::Create_virtual_table_stmtContext::table_name() {
  return getRuleContext<SqlParsingParser::Table_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Create_virtual_table_stmtContext::USING() {
  return getToken(SqlParsingParser::USING, 0);
}

SqlParsingParser::Module_nameContext* SqlParsingParser::Create_virtual_table_stmtContext::module_name() {
  return getRuleContext<SqlParsingParser::Module_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Create_virtual_table_stmtContext::IF() {
  return getToken(SqlParsingParser::IF, 0);
}

tree::TerminalNode* SqlParsingParser::Create_virtual_table_stmtContext::NOT() {
  return getToken(SqlParsingParser::NOT, 0);
}

tree::TerminalNode* SqlParsingParser::Create_virtual_table_stmtContext::EXISTS() {
  return getToken(SqlParsingParser::EXISTS, 0);
}

SqlParsingParser::Schema_nameContext* SqlParsingParser::Create_virtual_table_stmtContext::schema_name() {
  return getRuleContext<SqlParsingParser::Schema_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Create_virtual_table_stmtContext::DOT() {
  return getToken(SqlParsingParser::DOT, 0);
}

tree::TerminalNode* SqlParsingParser::Create_virtual_table_stmtContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

std::vector<SqlParsingParser::Module_argumentContext *> SqlParsingParser::Create_virtual_table_stmtContext::module_argument() {
  return getRuleContexts<SqlParsingParser::Module_argumentContext>();
}

SqlParsingParser::Module_argumentContext* SqlParsingParser::Create_virtual_table_stmtContext::module_argument(size_t i) {
  return getRuleContext<SqlParsingParser::Module_argumentContext>(i);
}

tree::TerminalNode* SqlParsingParser::Create_virtual_table_stmtContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Create_virtual_table_stmtContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Create_virtual_table_stmtContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}


size_t SqlParsingParser::Create_virtual_table_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleCreate_virtual_table_stmt;
}

void SqlParsingParser::Create_virtual_table_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreate_virtual_table_stmt(this);
}

void SqlParsingParser::Create_virtual_table_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreate_virtual_table_stmt(this);
}


antlrcpp::Any SqlParsingParser::Create_virtual_table_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitCreate_virtual_table_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Create_virtual_table_stmtContext* SqlParsingParser::create_virtual_table_stmt() {
  Create_virtual_table_stmtContext *_localctx = _tracker.createInstance<Create_virtual_table_stmtContext>(_ctx, getState());
  enterRule(_localctx, 44, SqlParsingParser::RuleCreate_virtual_table_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(710);
    match(SqlParsingParser::CREATE);
    setState(711);
    match(SqlParsingParser::VIRTUAL);
    setState(712);
    match(SqlParsingParser::TABLE);
    setState(716);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx)) {
    case 1: {
      setState(713);
      match(SqlParsingParser::IF);
      setState(714);
      match(SqlParsingParser::NOT);
      setState(715);
      match(SqlParsingParser::EXISTS);
      break;
    }

    }
    setState(721);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx)) {
    case 1: {
      setState(718);
      schema_name();
      setState(719);
      match(SqlParsingParser::DOT);
      break;
    }

    }
    setState(723);
    table_name();
    setState(724);
    match(SqlParsingParser::USING);
    setState(725);
    module_name();
    setState(737);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::OPEN_PAR) {
      setState(726);
      match(SqlParsingParser::OPEN_PAR);
      setState(727);
      module_argument();
      setState(732);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SqlParsingParser::COMMA) {
        setState(728);
        match(SqlParsingParser::COMMA);
        setState(729);
        module_argument();
        setState(734);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(735);
      match(SqlParsingParser::CLOSE_PAR);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- With_clauseContext ------------------------------------------------------------------

SqlParsingParser::With_clauseContext::With_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::With_clauseContext::WITH() {
  return getToken(SqlParsingParser::WITH, 0);
}

std::vector<SqlParsingParser::Cte_table_nameContext *> SqlParsingParser::With_clauseContext::cte_table_name() {
  return getRuleContexts<SqlParsingParser::Cte_table_nameContext>();
}

SqlParsingParser::Cte_table_nameContext* SqlParsingParser::With_clauseContext::cte_table_name(size_t i) {
  return getRuleContext<SqlParsingParser::Cte_table_nameContext>(i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::With_clauseContext::AS() {
  return getTokens(SqlParsingParser::AS);
}

tree::TerminalNode* SqlParsingParser::With_clauseContext::AS(size_t i) {
  return getToken(SqlParsingParser::AS, i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::With_clauseContext::OPEN_PAR() {
  return getTokens(SqlParsingParser::OPEN_PAR);
}

tree::TerminalNode* SqlParsingParser::With_clauseContext::OPEN_PAR(size_t i) {
  return getToken(SqlParsingParser::OPEN_PAR, i);
}

std::vector<SqlParsingParser::Select_stmtContext *> SqlParsingParser::With_clauseContext::select_stmt() {
  return getRuleContexts<SqlParsingParser::Select_stmtContext>();
}

SqlParsingParser::Select_stmtContext* SqlParsingParser::With_clauseContext::select_stmt(size_t i) {
  return getRuleContext<SqlParsingParser::Select_stmtContext>(i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::With_clauseContext::CLOSE_PAR() {
  return getTokens(SqlParsingParser::CLOSE_PAR);
}

tree::TerminalNode* SqlParsingParser::With_clauseContext::CLOSE_PAR(size_t i) {
  return getToken(SqlParsingParser::CLOSE_PAR, i);
}

tree::TerminalNode* SqlParsingParser::With_clauseContext::RECURSIVE() {
  return getToken(SqlParsingParser::RECURSIVE, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::With_clauseContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::With_clauseContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}


size_t SqlParsingParser::With_clauseContext::getRuleIndex() const {
  return SqlParsingParser::RuleWith_clause;
}

void SqlParsingParser::With_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWith_clause(this);
}

void SqlParsingParser::With_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWith_clause(this);
}


antlrcpp::Any SqlParsingParser::With_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitWith_clause(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::With_clauseContext* SqlParsingParser::with_clause() {
  With_clauseContext *_localctx = _tracker.createInstance<With_clauseContext>(_ctx, getState());
  enterRule(_localctx, 46, SqlParsingParser::RuleWith_clause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(739);
    match(SqlParsingParser::WITH);
    setState(741);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx)) {
    case 1: {
      setState(740);
      match(SqlParsingParser::RECURSIVE);
      break;
    }

    }
    setState(743);
    cte_table_name();
    setState(744);
    match(SqlParsingParser::AS);
    setState(745);
    match(SqlParsingParser::OPEN_PAR);
    setState(746);
    select_stmt();
    setState(747);
    match(SqlParsingParser::CLOSE_PAR);
    setState(757);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SqlParsingParser::COMMA) {
      setState(748);
      match(SqlParsingParser::COMMA);
      setState(749);
      cte_table_name();
      setState(750);
      match(SqlParsingParser::AS);
      setState(751);
      match(SqlParsingParser::OPEN_PAR);
      setState(752);
      select_stmt();
      setState(753);
      match(SqlParsingParser::CLOSE_PAR);
      setState(759);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cte_table_nameContext ------------------------------------------------------------------

SqlParsingParser::Cte_table_nameContext::Cte_table_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Table_nameContext* SqlParsingParser::Cte_table_nameContext::table_name() {
  return getRuleContext<SqlParsingParser::Table_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Cte_table_nameContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

std::vector<SqlParsingParser::Column_nameContext *> SqlParsingParser::Cte_table_nameContext::column_name() {
  return getRuleContexts<SqlParsingParser::Column_nameContext>();
}

SqlParsingParser::Column_nameContext* SqlParsingParser::Cte_table_nameContext::column_name(size_t i) {
  return getRuleContext<SqlParsingParser::Column_nameContext>(i);
}

tree::TerminalNode* SqlParsingParser::Cte_table_nameContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Cte_table_nameContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Cte_table_nameContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}


size_t SqlParsingParser::Cte_table_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleCte_table_name;
}

void SqlParsingParser::Cte_table_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCte_table_name(this);
}

void SqlParsingParser::Cte_table_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCte_table_name(this);
}


antlrcpp::Any SqlParsingParser::Cte_table_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitCte_table_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Cte_table_nameContext* SqlParsingParser::cte_table_name() {
  Cte_table_nameContext *_localctx = _tracker.createInstance<Cte_table_nameContext>(_ctx, getState());
  enterRule(_localctx, 48, SqlParsingParser::RuleCte_table_name);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(760);
    table_name();
    setState(772);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::OPEN_PAR) {
      setState(761);
      match(SqlParsingParser::OPEN_PAR);
      setState(762);
      column_name();
      setState(767);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SqlParsingParser::COMMA) {
        setState(763);
        match(SqlParsingParser::COMMA);
        setState(764);
        column_name();
        setState(769);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(770);
      match(SqlParsingParser::CLOSE_PAR);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Recursive_cteContext ------------------------------------------------------------------

SqlParsingParser::Recursive_cteContext::Recursive_cteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Cte_table_nameContext* SqlParsingParser::Recursive_cteContext::cte_table_name() {
  return getRuleContext<SqlParsingParser::Cte_table_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Recursive_cteContext::AS() {
  return getToken(SqlParsingParser::AS, 0);
}

tree::TerminalNode* SqlParsingParser::Recursive_cteContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

SqlParsingParser::Initial_selectContext* SqlParsingParser::Recursive_cteContext::initial_select() {
  return getRuleContext<SqlParsingParser::Initial_selectContext>(0);
}

tree::TerminalNode* SqlParsingParser::Recursive_cteContext::UNION() {
  return getToken(SqlParsingParser::UNION, 0);
}

SqlParsingParser::Recursive_selectContext* SqlParsingParser::Recursive_cteContext::recursive_select() {
  return getRuleContext<SqlParsingParser::Recursive_selectContext>(0);
}

tree::TerminalNode* SqlParsingParser::Recursive_cteContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Recursive_cteContext::ALL() {
  return getToken(SqlParsingParser::ALL, 0);
}


size_t SqlParsingParser::Recursive_cteContext::getRuleIndex() const {
  return SqlParsingParser::RuleRecursive_cte;
}

void SqlParsingParser::Recursive_cteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRecursive_cte(this);
}

void SqlParsingParser::Recursive_cteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRecursive_cte(this);
}


antlrcpp::Any SqlParsingParser::Recursive_cteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitRecursive_cte(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Recursive_cteContext* SqlParsingParser::recursive_cte() {
  Recursive_cteContext *_localctx = _tracker.createInstance<Recursive_cteContext>(_ctx, getState());
  enterRule(_localctx, 50, SqlParsingParser::RuleRecursive_cte);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(774);
    cte_table_name();
    setState(775);
    match(SqlParsingParser::AS);
    setState(776);
    match(SqlParsingParser::OPEN_PAR);
    setState(777);
    initial_select();
    setState(778);
    match(SqlParsingParser::UNION);
    setState(780);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::ALL) {
      setState(779);
      match(SqlParsingParser::ALL);
    }
    setState(782);
    recursive_select();
    setState(783);
    match(SqlParsingParser::CLOSE_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Common_table_expressionContext ------------------------------------------------------------------

SqlParsingParser::Common_table_expressionContext::Common_table_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Table_nameContext* SqlParsingParser::Common_table_expressionContext::table_name() {
  return getRuleContext<SqlParsingParser::Table_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Common_table_expressionContext::AS() {
  return getToken(SqlParsingParser::AS, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Common_table_expressionContext::OPEN_PAR() {
  return getTokens(SqlParsingParser::OPEN_PAR);
}

tree::TerminalNode* SqlParsingParser::Common_table_expressionContext::OPEN_PAR(size_t i) {
  return getToken(SqlParsingParser::OPEN_PAR, i);
}

SqlParsingParser::Select_stmtContext* SqlParsingParser::Common_table_expressionContext::select_stmt() {
  return getRuleContext<SqlParsingParser::Select_stmtContext>(0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Common_table_expressionContext::CLOSE_PAR() {
  return getTokens(SqlParsingParser::CLOSE_PAR);
}

tree::TerminalNode* SqlParsingParser::Common_table_expressionContext::CLOSE_PAR(size_t i) {
  return getToken(SqlParsingParser::CLOSE_PAR, i);
}

std::vector<SqlParsingParser::Column_nameContext *> SqlParsingParser::Common_table_expressionContext::column_name() {
  return getRuleContexts<SqlParsingParser::Column_nameContext>();
}

SqlParsingParser::Column_nameContext* SqlParsingParser::Common_table_expressionContext::column_name(size_t i) {
  return getRuleContext<SqlParsingParser::Column_nameContext>(i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Common_table_expressionContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Common_table_expressionContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}


size_t SqlParsingParser::Common_table_expressionContext::getRuleIndex() const {
  return SqlParsingParser::RuleCommon_table_expression;
}

void SqlParsingParser::Common_table_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommon_table_expression(this);
}

void SqlParsingParser::Common_table_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommon_table_expression(this);
}


antlrcpp::Any SqlParsingParser::Common_table_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitCommon_table_expression(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Common_table_expressionContext* SqlParsingParser::common_table_expression() {
  Common_table_expressionContext *_localctx = _tracker.createInstance<Common_table_expressionContext>(_ctx, getState());
  enterRule(_localctx, 52, SqlParsingParser::RuleCommon_table_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(785);
    table_name();
    setState(797);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::OPEN_PAR) {
      setState(786);
      match(SqlParsingParser::OPEN_PAR);
      setState(787);
      column_name();
      setState(792);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SqlParsingParser::COMMA) {
        setState(788);
        match(SqlParsingParser::COMMA);
        setState(789);
        column_name();
        setState(794);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(795);
      match(SqlParsingParser::CLOSE_PAR);
    }
    setState(799);
    match(SqlParsingParser::AS);
    setState(800);
    match(SqlParsingParser::OPEN_PAR);
    setState(801);
    select_stmt();
    setState(802);
    match(SqlParsingParser::CLOSE_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Delete_stmtContext ------------------------------------------------------------------

SqlParsingParser::Delete_stmtContext::Delete_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Delete_stmtContext::DELETE() {
  return getToken(SqlParsingParser::DELETE, 0);
}

tree::TerminalNode* SqlParsingParser::Delete_stmtContext::FROM() {
  return getToken(SqlParsingParser::FROM, 0);
}

SqlParsingParser::Qualified_table_nameContext* SqlParsingParser::Delete_stmtContext::qualified_table_name() {
  return getRuleContext<SqlParsingParser::Qualified_table_nameContext>(0);
}

SqlParsingParser::With_clauseContext* SqlParsingParser::Delete_stmtContext::with_clause() {
  return getRuleContext<SqlParsingParser::With_clauseContext>(0);
}

tree::TerminalNode* SqlParsingParser::Delete_stmtContext::WHERE() {
  return getToken(SqlParsingParser::WHERE, 0);
}

SqlParsingParser::ExprContext* SqlParsingParser::Delete_stmtContext::expr() {
  return getRuleContext<SqlParsingParser::ExprContext>(0);
}


size_t SqlParsingParser::Delete_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleDelete_stmt;
}

void SqlParsingParser::Delete_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDelete_stmt(this);
}

void SqlParsingParser::Delete_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDelete_stmt(this);
}


antlrcpp::Any SqlParsingParser::Delete_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitDelete_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Delete_stmtContext* SqlParsingParser::delete_stmt() {
  Delete_stmtContext *_localctx = _tracker.createInstance<Delete_stmtContext>(_ctx, getState());
  enterRule(_localctx, 54, SqlParsingParser::RuleDelete_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(805);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::WITH) {
      setState(804);
      with_clause();
    }
    setState(807);
    match(SqlParsingParser::DELETE);
    setState(808);
    match(SqlParsingParser::FROM);
    setState(809);
    qualified_table_name();
    setState(812);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::WHERE) {
      setState(810);
      match(SqlParsingParser::WHERE);
      setState(811);
      expr(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Delete_stmt_limitedContext ------------------------------------------------------------------

SqlParsingParser::Delete_stmt_limitedContext::Delete_stmt_limitedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Delete_stmt_limitedContext::DELETE() {
  return getToken(SqlParsingParser::DELETE, 0);
}

tree::TerminalNode* SqlParsingParser::Delete_stmt_limitedContext::FROM() {
  return getToken(SqlParsingParser::FROM, 0);
}

SqlParsingParser::Qualified_table_nameContext* SqlParsingParser::Delete_stmt_limitedContext::qualified_table_name() {
  return getRuleContext<SqlParsingParser::Qualified_table_nameContext>(0);
}

SqlParsingParser::With_clauseContext* SqlParsingParser::Delete_stmt_limitedContext::with_clause() {
  return getRuleContext<SqlParsingParser::With_clauseContext>(0);
}

tree::TerminalNode* SqlParsingParser::Delete_stmt_limitedContext::WHERE() {
  return getToken(SqlParsingParser::WHERE, 0);
}

SqlParsingParser::ExprContext* SqlParsingParser::Delete_stmt_limitedContext::expr() {
  return getRuleContext<SqlParsingParser::ExprContext>(0);
}

SqlParsingParser::Limit_stmtContext* SqlParsingParser::Delete_stmt_limitedContext::limit_stmt() {
  return getRuleContext<SqlParsingParser::Limit_stmtContext>(0);
}

SqlParsingParser::Order_by_stmtContext* SqlParsingParser::Delete_stmt_limitedContext::order_by_stmt() {
  return getRuleContext<SqlParsingParser::Order_by_stmtContext>(0);
}


size_t SqlParsingParser::Delete_stmt_limitedContext::getRuleIndex() const {
  return SqlParsingParser::RuleDelete_stmt_limited;
}

void SqlParsingParser::Delete_stmt_limitedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDelete_stmt_limited(this);
}

void SqlParsingParser::Delete_stmt_limitedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDelete_stmt_limited(this);
}


antlrcpp::Any SqlParsingParser::Delete_stmt_limitedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitDelete_stmt_limited(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Delete_stmt_limitedContext* SqlParsingParser::delete_stmt_limited() {
  Delete_stmt_limitedContext *_localctx = _tracker.createInstance<Delete_stmt_limitedContext>(_ctx, getState());
  enterRule(_localctx, 56, SqlParsingParser::RuleDelete_stmt_limited);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(815);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::WITH) {
      setState(814);
      with_clause();
    }
    setState(817);
    match(SqlParsingParser::DELETE);
    setState(818);
    match(SqlParsingParser::FROM);
    setState(819);
    qualified_table_name();
    setState(822);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::WHERE) {
      setState(820);
      match(SqlParsingParser::WHERE);
      setState(821);
      expr(0);
    }
    setState(828);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::LIMIT

    || _la == SqlParsingParser::ORDER) {
      setState(825);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SqlParsingParser::ORDER) {
        setState(824);
        order_by_stmt();
      }
      setState(827);
      limit_stmt();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Detach_stmtContext ------------------------------------------------------------------

SqlParsingParser::Detach_stmtContext::Detach_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Detach_stmtContext::DETACH() {
  return getToken(SqlParsingParser::DETACH, 0);
}

SqlParsingParser::Schema_nameContext* SqlParsingParser::Detach_stmtContext::schema_name() {
  return getRuleContext<SqlParsingParser::Schema_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Detach_stmtContext::DATABASE() {
  return getToken(SqlParsingParser::DATABASE, 0);
}


size_t SqlParsingParser::Detach_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleDetach_stmt;
}

void SqlParsingParser::Detach_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDetach_stmt(this);
}

void SqlParsingParser::Detach_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDetach_stmt(this);
}


antlrcpp::Any SqlParsingParser::Detach_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitDetach_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Detach_stmtContext* SqlParsingParser::detach_stmt() {
  Detach_stmtContext *_localctx = _tracker.createInstance<Detach_stmtContext>(_ctx, getState());
  enterRule(_localctx, 58, SqlParsingParser::RuleDetach_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(830);
    match(SqlParsingParser::DETACH);
    setState(832);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 100, _ctx)) {
    case 1: {
      setState(831);
      match(SqlParsingParser::DATABASE);
      break;
    }

    }
    setState(834);
    schema_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Drop_stmtContext ------------------------------------------------------------------

SqlParsingParser::Drop_stmtContext::Drop_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Drop_stmtContext::DROP() {
  return getToken(SqlParsingParser::DROP, 0);
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Drop_stmtContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Drop_stmtContext::INDEX() {
  return getToken(SqlParsingParser::INDEX, 0);
}

tree::TerminalNode* SqlParsingParser::Drop_stmtContext::TABLE() {
  return getToken(SqlParsingParser::TABLE, 0);
}

tree::TerminalNode* SqlParsingParser::Drop_stmtContext::TRIGGER() {
  return getToken(SqlParsingParser::TRIGGER, 0);
}

tree::TerminalNode* SqlParsingParser::Drop_stmtContext::VIEW() {
  return getToken(SqlParsingParser::VIEW, 0);
}

tree::TerminalNode* SqlParsingParser::Drop_stmtContext::IF() {
  return getToken(SqlParsingParser::IF, 0);
}

tree::TerminalNode* SqlParsingParser::Drop_stmtContext::EXISTS() {
  return getToken(SqlParsingParser::EXISTS, 0);
}

SqlParsingParser::Schema_nameContext* SqlParsingParser::Drop_stmtContext::schema_name() {
  return getRuleContext<SqlParsingParser::Schema_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Drop_stmtContext::DOT() {
  return getToken(SqlParsingParser::DOT, 0);
}


size_t SqlParsingParser::Drop_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleDrop_stmt;
}

void SqlParsingParser::Drop_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDrop_stmt(this);
}

void SqlParsingParser::Drop_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDrop_stmt(this);
}


antlrcpp::Any SqlParsingParser::Drop_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitDrop_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Drop_stmtContext* SqlParsingParser::drop_stmt() {
  Drop_stmtContext *_localctx = _tracker.createInstance<Drop_stmtContext>(_ctx, getState());
  enterRule(_localctx, 60, SqlParsingParser::RuleDrop_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(836);
    match(SqlParsingParser::DROP);
    setState(837);
    dynamic_cast<Drop_stmtContext *>(_localctx)->object = _input->LT(1);
    _la = _input->LA(1);
    if (!(((((_la - 84) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 84)) & ((1ULL << (SqlParsingParser::INDEX - 84))
      | (1ULL << (SqlParsingParser::TABLE - 84))
      | (1ULL << (SqlParsingParser::TRIGGER - 84))
      | (1ULL << (SqlParsingParser::VIEW - 84)))) != 0))) {
      dynamic_cast<Drop_stmtContext *>(_localctx)->object = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(840);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 101, _ctx)) {
    case 1: {
      setState(838);
      match(SqlParsingParser::IF);
      setState(839);
      match(SqlParsingParser::EXISTS);
      break;
    }

    }
    setState(845);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx)) {
    case 1: {
      setState(842);
      schema_name();
      setState(843);
      match(SqlParsingParser::DOT);
      break;
    }

    }
    setState(847);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

SqlParsingParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Literal_valueContext* SqlParsingParser::ExprContext::literal_value() {
  return getRuleContext<SqlParsingParser::Literal_valueContext>(0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::BIND_PARAMETER() {
  return getToken(SqlParsingParser::BIND_PARAMETER, 0);
}

SqlParsingParser::Column_nameContext* SqlParsingParser::ExprContext::column_name() {
  return getRuleContext<SqlParsingParser::Column_nameContext>(0);
}

SqlParsingParser::Table_nameContext* SqlParsingParser::ExprContext::table_name() {
  return getRuleContext<SqlParsingParser::Table_nameContext>(0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::ExprContext::DOT() {
  return getTokens(SqlParsingParser::DOT);
}

tree::TerminalNode* SqlParsingParser::ExprContext::DOT(size_t i) {
  return getToken(SqlParsingParser::DOT, i);
}

SqlParsingParser::Schema_nameContext* SqlParsingParser::ExprContext::schema_name() {
  return getRuleContext<SqlParsingParser::Schema_nameContext>(0);
}

SqlParsingParser::Unary_operatorContext* SqlParsingParser::ExprContext::unary_operator() {
  return getRuleContext<SqlParsingParser::Unary_operatorContext>(0);
}

std::vector<SqlParsingParser::ExprContext *> SqlParsingParser::ExprContext::expr() {
  return getRuleContexts<SqlParsingParser::ExprContext>();
}

SqlParsingParser::ExprContext* SqlParsingParser::ExprContext::expr(size_t i) {
  return getRuleContext<SqlParsingParser::ExprContext>(i);
}

SqlParsingParser::Function_nameContext* SqlParsingParser::ExprContext::function_name() {
  return getRuleContext<SqlParsingParser::Function_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::STAR() {
  return getToken(SqlParsingParser::STAR, 0);
}

SqlParsingParser::Filter_clauseContext* SqlParsingParser::ExprContext::filter_clause() {
  return getRuleContext<SqlParsingParser::Filter_clauseContext>(0);
}

SqlParsingParser::Over_clauseContext* SqlParsingParser::ExprContext::over_clause() {
  return getRuleContext<SqlParsingParser::Over_clauseContext>(0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::DISTINCT() {
  return getToken(SqlParsingParser::DISTINCT, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::ExprContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::ExprContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}

tree::TerminalNode* SqlParsingParser::ExprContext::CAST() {
  return getToken(SqlParsingParser::CAST, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::AS() {
  return getToken(SqlParsingParser::AS, 0);
}

SqlParsingParser::Type_nameContext* SqlParsingParser::ExprContext::type_name() {
  return getRuleContext<SqlParsingParser::Type_nameContext>(0);
}

SqlParsingParser::Select_stmtContext* SqlParsingParser::ExprContext::select_stmt() {
  return getRuleContext<SqlParsingParser::Select_stmtContext>(0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::EXISTS() {
  return getToken(SqlParsingParser::EXISTS, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::NOT() {
  return getToken(SqlParsingParser::NOT, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::CASE() {
  return getToken(SqlParsingParser::CASE, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::END() {
  return getToken(SqlParsingParser::END, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::ExprContext::WHEN() {
  return getTokens(SqlParsingParser::WHEN);
}

tree::TerminalNode* SqlParsingParser::ExprContext::WHEN(size_t i) {
  return getToken(SqlParsingParser::WHEN, i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::ExprContext::THEN() {
  return getTokens(SqlParsingParser::THEN);
}

tree::TerminalNode* SqlParsingParser::ExprContext::THEN(size_t i) {
  return getToken(SqlParsingParser::THEN, i);
}

tree::TerminalNode* SqlParsingParser::ExprContext::ELSE() {
  return getToken(SqlParsingParser::ELSE, 0);
}

SqlParsingParser::Raise_functionContext* SqlParsingParser::ExprContext::raise_function() {
  return getRuleContext<SqlParsingParser::Raise_functionContext>(0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::PIPE2() {
  return getToken(SqlParsingParser::PIPE2, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::DIV() {
  return getToken(SqlParsingParser::DIV, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::MOD() {
  return getToken(SqlParsingParser::MOD, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::PLUS() {
  return getToken(SqlParsingParser::PLUS, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::MINUS() {
  return getToken(SqlParsingParser::MINUS, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::LT2() {
  return getToken(SqlParsingParser::LT2, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::GT2() {
  return getToken(SqlParsingParser::GT2, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::AMP() {
  return getToken(SqlParsingParser::AMP, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::PIPE() {
  return getToken(SqlParsingParser::PIPE, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::LT() {
  return getToken(SqlParsingParser::LT, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::LT_EQ() {
  return getToken(SqlParsingParser::LT_EQ, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::GT() {
  return getToken(SqlParsingParser::GT, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::GT_EQ() {
  return getToken(SqlParsingParser::GT_EQ, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::ASSIGN() {
  return getToken(SqlParsingParser::ASSIGN, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::EQ() {
  return getToken(SqlParsingParser::EQ, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::NOT_EQ1() {
  return getToken(SqlParsingParser::NOT_EQ1, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::NOT_EQ2() {
  return getToken(SqlParsingParser::NOT_EQ2, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::IS() {
  return getToken(SqlParsingParser::IS, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::IN() {
  return getToken(SqlParsingParser::IN, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::LIKE() {
  return getToken(SqlParsingParser::LIKE, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::GLOB() {
  return getToken(SqlParsingParser::GLOB, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::MATCH() {
  return getToken(SqlParsingParser::MATCH, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::REGEXP() {
  return getToken(SqlParsingParser::REGEXP, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::AND() {
  return getToken(SqlParsingParser::AND, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::OR() {
  return getToken(SqlParsingParser::OR, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::BETWEEN() {
  return getToken(SqlParsingParser::BETWEEN, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::COLLATE() {
  return getToken(SqlParsingParser::COLLATE, 0);
}

SqlParsingParser::Collation_nameContext* SqlParsingParser::ExprContext::collation_name() {
  return getRuleContext<SqlParsingParser::Collation_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::ESCAPE() {
  return getToken(SqlParsingParser::ESCAPE, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::ISNULL() {
  return getToken(SqlParsingParser::ISNULL, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::NOTNULL() {
  return getToken(SqlParsingParser::NOTNULL, 0);
}

tree::TerminalNode* SqlParsingParser::ExprContext::NULL_() {
  return getToken(SqlParsingParser::NULL_, 0);
}

SqlParsingParser::Table_function_nameContext* SqlParsingParser::ExprContext::table_function_name() {
  return getRuleContext<SqlParsingParser::Table_function_nameContext>(0);
}


size_t SqlParsingParser::ExprContext::getRuleIndex() const {
  return SqlParsingParser::RuleExpr;
}

void SqlParsingParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void SqlParsingParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


antlrcpp::Any SqlParsingParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


SqlParsingParser::ExprContext* SqlParsingParser::expr() {
   return expr(0);
}

SqlParsingParser::ExprContext* SqlParsingParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SqlParsingParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  SqlParsingParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 62;
  enterRecursionRule(_localctx, 62, SqlParsingParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(937);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 116, _ctx)) {
    case 1: {
      setState(850);
      literal_value();
      break;
    }

    case 2: {
      setState(851);
      match(SqlParsingParser::BIND_PARAMETER);
      break;
    }

    case 3: {
      setState(860);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 104, _ctx)) {
      case 1: {
        setState(855);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx)) {
        case 1: {
          setState(852);
          schema_name();
          setState(853);
          match(SqlParsingParser::DOT);
          break;
        }

        }
        setState(857);
        table_name();
        setState(858);
        match(SqlParsingParser::DOT);
        break;
      }

      }
      setState(862);
      column_name();
      break;
    }

    case 4: {
      setState(863);
      unary_operator();
      setState(864);
      expr(21);
      break;
    }

    case 5: {
      setState(866);
      function_name();
      setState(867);
      match(SqlParsingParser::OPEN_PAR);
      setState(880);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SqlParsingParser::OPEN_PAR:
        case SqlParsingParser::PLUS:
        case SqlParsingParser::MINUS:
        case SqlParsingParser::TILDE:
        case SqlParsingParser::ABORT:
        case SqlParsingParser::ACTION:
        case SqlParsingParser::ADD:
        case SqlParsingParser::AFTER:
        case SqlParsingParser::ALL:
        case SqlParsingParser::ALTER:
        case SqlParsingParser::ANALYZE:
        case SqlParsingParser::AND:
        case SqlParsingParser::AS:
        case SqlParsingParser::ASC:
        case SqlParsingParser::ATTACH:
        case SqlParsingParser::AUTOINCREMENT:
        case SqlParsingParser::BEFORE:
        case SqlParsingParser::BEGIN:
        case SqlParsingParser::BETWEEN:
        case SqlParsingParser::BY:
        case SqlParsingParser::CASCADE:
        case SqlParsingParser::CASE:
        case SqlParsingParser::CAST:
        case SqlParsingParser::CHECK:
        case SqlParsingParser::COLLATE:
        case SqlParsingParser::COLUMN:
        case SqlParsingParser::COMMIT:
        case SqlParsingParser::CONFLICT:
        case SqlParsingParser::CONSTRAINT:
        case SqlParsingParser::CREATE:
        case SqlParsingParser::CROSS:
        case SqlParsingParser::CURRENT_DATE:
        case SqlParsingParser::CURRENT_TIME:
        case SqlParsingParser::CURRENT_TIMESTAMP:
        case SqlParsingParser::DATABASE:
        case SqlParsingParser::DEFAULT:
        case SqlParsingParser::DEFERRABLE:
        case SqlParsingParser::DEFERRED:
        case SqlParsingParser::DELETE:
        case SqlParsingParser::DESC:
        case SqlParsingParser::DETACH:
        case SqlParsingParser::DISTINCT:
        case SqlParsingParser::DROP:
        case SqlParsingParser::EACH:
        case SqlParsingParser::ELSE:
        case SqlParsingParser::END:
        case SqlParsingParser::ESCAPE:
        case SqlParsingParser::EXCEPT:
        case SqlParsingParser::EXCLUSIVE:
        case SqlParsingParser::EXISTS:
        case SqlParsingParser::EXPLAIN:
        case SqlParsingParser::FAIL:
        case SqlParsingParser::FOR:
        case SqlParsingParser::FOREIGN:
        case SqlParsingParser::FROM:
        case SqlParsingParser::FULL:
        case SqlParsingParser::GLOB:
        case SqlParsingParser::GROUP:
        case SqlParsingParser::HAVING:
        case SqlParsingParser::IF:
        case SqlParsingParser::IGNORE:
        case SqlParsingParser::IMMEDIATE:
        case SqlParsingParser::IN:
        case SqlParsingParser::INDEX:
        case SqlParsingParser::INDEXED:
        case SqlParsingParser::INITIALLY:
        case SqlParsingParser::INNER:
        case SqlParsingParser::INSERT:
        case SqlParsingParser::INSTEAD:
        case SqlParsingParser::INTERSECT:
        case SqlParsingParser::INTO:
        case SqlParsingParser::IS:
        case SqlParsingParser::ISNULL:
        case SqlParsingParser::JOIN:
        case SqlParsingParser::KEY:
        case SqlParsingParser::LEFT:
        case SqlParsingParser::LIKE:
        case SqlParsingParser::LIMIT:
        case SqlParsingParser::MATCH:
        case SqlParsingParser::NATURAL:
        case SqlParsingParser::NO:
        case SqlParsingParser::NOT:
        case SqlParsingParser::NOTNULL:
        case SqlParsingParser::NULL_:
        case SqlParsingParser::OF:
        case SqlParsingParser::OFFSET:
        case SqlParsingParser::ON:
        case SqlParsingParser::OR:
        case SqlParsingParser::ORDER:
        case SqlParsingParser::OUTER:
        case SqlParsingParser::PLAN:
        case SqlParsingParser::PRAGMA:
        case SqlParsingParser::PRIMARY:
        case SqlParsingParser::QUERY:
        case SqlParsingParser::RAISE:
        case SqlParsingParser::RECURSIVE:
        case SqlParsingParser::REFERENCES:
        case SqlParsingParser::REGEXP:
        case SqlParsingParser::REINDEX:
        case SqlParsingParser::RELEASE:
        case SqlParsingParser::RENAME:
        case SqlParsingParser::REPLACE:
        case SqlParsingParser::RESTRICT:
        case SqlParsingParser::RIGHT:
        case SqlParsingParser::ROLLBACK:
        case SqlParsingParser::ROW:
        case SqlParsingParser::ROWS:
        case SqlParsingParser::SAVEPOINT:
        case SqlParsingParser::SELECT:
        case SqlParsingParser::SET:
        case SqlParsingParser::TABLE:
        case SqlParsingParser::TEMP:
        case SqlParsingParser::TEMPORARY:
        case SqlParsingParser::THEN:
        case SqlParsingParser::TO:
        case SqlParsingParser::TRANSACTION:
        case SqlParsingParser::TRIGGER:
        case SqlParsingParser::UNION:
        case SqlParsingParser::UNIQUE:
        case SqlParsingParser::UPDATE:
        case SqlParsingParser::USING:
        case SqlParsingParser::VACUUM:
        case SqlParsingParser::VALUES:
        case SqlParsingParser::VIEW:
        case SqlParsingParser::VIRTUAL:
        case SqlParsingParser::WHEN:
        case SqlParsingParser::WHERE:
        case SqlParsingParser::WITH:
        case SqlParsingParser::WITHOUT:
        case SqlParsingParser::FIRST_VALUE:
        case SqlParsingParser::OVER:
        case SqlParsingParser::PARTITION:
        case SqlParsingParser::RANGE:
        case SqlParsingParser::PRECEDING:
        case SqlParsingParser::UNBOUNDED:
        case SqlParsingParser::CURRENT:
        case SqlParsingParser::FOLLOWING:
        case SqlParsingParser::CUME_DIST:
        case SqlParsingParser::DENSE_RANK:
        case SqlParsingParser::LAG:
        case SqlParsingParser::LAST_VALUE:
        case SqlParsingParser::LEAD:
        case SqlParsingParser::NTH_VALUE:
        case SqlParsingParser::NTILE:
        case SqlParsingParser::PERCENT_RANK:
        case SqlParsingParser::RANK:
        case SqlParsingParser::ROW_NUMBER:
        case SqlParsingParser::GENERATED:
        case SqlParsingParser::ALWAYS:
        case SqlParsingParser::STORED:
        case SqlParsingParser::TRUE_:
        case SqlParsingParser::FALSE_:
        case SqlParsingParser::WINDOW:
        case SqlParsingParser::NULLS:
        case SqlParsingParser::FIRST:
        case SqlParsingParser::LAST:
        case SqlParsingParser::FILTER:
        case SqlParsingParser::GROUPS:
        case SqlParsingParser::EXCLUDE:
        case SqlParsingParser::IDENTIFIER:
        case SqlParsingParser::NUMERIC_LITERAL:
        case SqlParsingParser::BIND_PARAMETER:
        case SqlParsingParser::STRING_LITERAL:
        case SqlParsingParser::BLOB_LITERAL: {
          setState(869);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx)) {
          case 1: {
            setState(868);
            match(SqlParsingParser::DISTINCT);
            break;
          }

          }
          setState(871);
          expr(0);
          setState(876);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SqlParsingParser::COMMA) {
            setState(872);
            match(SqlParsingParser::COMMA);
            setState(873);
            expr(0);
            setState(878);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case SqlParsingParser::STAR: {
          setState(879);
          match(SqlParsingParser::STAR);
          break;
        }

        case SqlParsingParser::CLOSE_PAR: {
          break;
        }

      default:
        break;
      }
      setState(882);
      match(SqlParsingParser::CLOSE_PAR);
      setState(884);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 108, _ctx)) {
      case 1: {
        setState(883);
        filter_clause();
        break;
      }

      }
      setState(887);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx)) {
      case 1: {
        setState(886);
        over_clause();
        break;
      }

      }
      break;
    }

    case 6: {
      setState(889);
      match(SqlParsingParser::OPEN_PAR);
      setState(890);
      expr(0);
      setState(895);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SqlParsingParser::COMMA) {
        setState(891);
        match(SqlParsingParser::COMMA);
        setState(892);
        expr(0);
        setState(897);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(898);
      match(SqlParsingParser::CLOSE_PAR);
      break;
    }

    case 7: {
      setState(900);
      match(SqlParsingParser::CAST);
      setState(901);
      match(SqlParsingParser::OPEN_PAR);
      setState(902);
      expr(0);
      setState(903);
      match(SqlParsingParser::AS);
      setState(904);
      type_name();
      setState(905);
      match(SqlParsingParser::CLOSE_PAR);
      break;
    }

    case 8: {
      setState(911);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SqlParsingParser::EXISTS

      || _la == SqlParsingParser::NOT) {
        setState(908);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::NOT) {
          setState(907);
          match(SqlParsingParser::NOT);
        }
        setState(910);
        match(SqlParsingParser::EXISTS);
      }
      setState(913);
      match(SqlParsingParser::OPEN_PAR);
      setState(914);
      select_stmt();
      setState(915);
      match(SqlParsingParser::CLOSE_PAR);
      break;
    }

    case 9: {
      setState(917);
      match(SqlParsingParser::CASE);
      setState(919);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 113, _ctx)) {
      case 1: {
        setState(918);
        expr(0);
        break;
      }

      }
      setState(926); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(921);
        match(SqlParsingParser::WHEN);
        setState(922);
        expr(0);
        setState(923);
        match(SqlParsingParser::THEN);
        setState(924);
        expr(0);
        setState(928); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == SqlParsingParser::WHEN);
      setState(932);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SqlParsingParser::ELSE) {
        setState(930);
        match(SqlParsingParser::ELSE);
        setState(931);
        expr(0);
      }
      setState(934);
      match(SqlParsingParser::END);
      break;
    }

    case 10: {
      setState(936);
      raise_function();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(1058);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 132, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1056);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 131, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(939);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(940);
          match(SqlParsingParser::PIPE2);
          setState(941);
          expr(21);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(942);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(943);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SqlParsingParser::STAR)
            | (1ULL << SqlParsingParser::DIV)
            | (1ULL << SqlParsingParser::MOD))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(944);
          expr(20);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(945);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(946);
          _la = _input->LA(1);
          if (!(_la == SqlParsingParser::PLUS

          || _la == SqlParsingParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(947);
          expr(19);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(948);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(949);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SqlParsingParser::LT2)
            | (1ULL << SqlParsingParser::GT2)
            | (1ULL << SqlParsingParser::AMP)
            | (1ULL << SqlParsingParser::PIPE))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(950);
          expr(18);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(951);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(952);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SqlParsingParser::LT)
            | (1ULL << SqlParsingParser::LT_EQ)
            | (1ULL << SqlParsingParser::GT)
            | (1ULL << SqlParsingParser::GT_EQ))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(953);
          expr(17);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(954);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(967);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 117, _ctx)) {
          case 1: {
            setState(955);
            match(SqlParsingParser::ASSIGN);
            break;
          }

          case 2: {
            setState(956);
            match(SqlParsingParser::EQ);
            break;
          }

          case 3: {
            setState(957);
            match(SqlParsingParser::NOT_EQ1);
            break;
          }

          case 4: {
            setState(958);
            match(SqlParsingParser::NOT_EQ2);
            break;
          }

          case 5: {
            setState(959);
            match(SqlParsingParser::IS);
            break;
          }

          case 6: {
            setState(960);
            match(SqlParsingParser::IS);
            setState(961);
            match(SqlParsingParser::NOT);
            break;
          }

          case 7: {
            setState(962);
            match(SqlParsingParser::IN);
            break;
          }

          case 8: {
            setState(963);
            match(SqlParsingParser::LIKE);
            break;
          }

          case 9: {
            setState(964);
            match(SqlParsingParser::GLOB);
            break;
          }

          case 10: {
            setState(965);
            match(SqlParsingParser::MATCH);
            break;
          }

          case 11: {
            setState(966);
            match(SqlParsingParser::REGEXP);
            break;
          }

          }
          setState(969);
          expr(16);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(970);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(971);
          match(SqlParsingParser::AND);
          setState(972);
          expr(15);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(973);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(974);
          match(SqlParsingParser::OR);
          setState(975);
          expr(14);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(976);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(977);
          match(SqlParsingParser::IS);
          setState(979);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 118, _ctx)) {
          case 1: {
            setState(978);
            match(SqlParsingParser::NOT);
            break;
          }

          }
          setState(981);
          expr(7);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(982);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(984);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == SqlParsingParser::NOT) {
            setState(983);
            match(SqlParsingParser::NOT);
          }
          setState(986);
          match(SqlParsingParser::BETWEEN);
          setState(987);
          expr(0);
          setState(988);
          match(SqlParsingParser::AND);
          setState(989);
          expr(6);
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(991);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(992);
          match(SqlParsingParser::COLLATE);
          setState(993);
          collation_name();
          break;
        }

        case 12: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(994);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(996);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == SqlParsingParser::NOT) {
            setState(995);
            match(SqlParsingParser::NOT);
          }
          setState(998);
          _la = _input->LA(1);
          if (!(((((_la - 77) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 77)) & ((1ULL << (SqlParsingParser::GLOB - 77))
            | (1ULL << (SqlParsingParser::LIKE - 77))
            | (1ULL << (SqlParsingParser::MATCH - 77))
            | (1ULL << (SqlParsingParser::REGEXP - 77)))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(999);
          expr(0);
          setState(1002);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 121, _ctx)) {
          case 1: {
            setState(1000);
            match(SqlParsingParser::ESCAPE);
            setState(1001);
            expr(0);
            break;
          }

          }
          break;
        }

        case 13: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1004);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(1009);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case SqlParsingParser::ISNULL: {
              setState(1005);
              match(SqlParsingParser::ISNULL);
              break;
            }

            case SqlParsingParser::NOTNULL: {
              setState(1006);
              match(SqlParsingParser::NOTNULL);
              break;
            }

            case SqlParsingParser::NOT: {
              setState(1007);
              match(SqlParsingParser::NOT);
              setState(1008);
              match(SqlParsingParser::NULL_);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          break;
        }

        case 14: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1011);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(1013);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == SqlParsingParser::NOT) {
            setState(1012);
            match(SqlParsingParser::NOT);
          }
          setState(1015);
          match(SqlParsingParser::IN);
          setState(1054);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 130, _ctx)) {
          case 1: {
            setState(1016);
            match(SqlParsingParser::OPEN_PAR);
            setState(1026);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 125, _ctx)) {
            case 1: {
              setState(1017);
              select_stmt();
              break;
            }

            case 2: {
              setState(1018);
              expr(0);
              setState(1023);
              _errHandler->sync(this);
              _la = _input->LA(1);
              while (_la == SqlParsingParser::COMMA) {
                setState(1019);
                match(SqlParsingParser::COMMA);
                setState(1020);
                expr(0);
                setState(1025);
                _errHandler->sync(this);
                _la = _input->LA(1);
              }
              break;
            }

            }
            setState(1028);
            match(SqlParsingParser::CLOSE_PAR);
            break;
          }

          case 2: {
            setState(1032);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 126, _ctx)) {
            case 1: {
              setState(1029);
              schema_name();
              setState(1030);
              match(SqlParsingParser::DOT);
              break;
            }

            }
            setState(1034);
            table_name();
            break;
          }

          case 3: {
            setState(1038);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 127, _ctx)) {
            case 1: {
              setState(1035);
              schema_name();
              setState(1036);
              match(SqlParsingParser::DOT);
              break;
            }

            }
            setState(1040);
            table_function_name();
            setState(1041);
            match(SqlParsingParser::OPEN_PAR);
            setState(1050);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if ((((_la & ~ 0x3fULL) == 0) &&
              ((1ULL << _la) & ((1ULL << SqlParsingParser::OPEN_PAR)
              | (1ULL << SqlParsingParser::PLUS)
              | (1ULL << SqlParsingParser::MINUS)
              | (1ULL << SqlParsingParser::TILDE)
              | (1ULL << SqlParsingParser::ABORT)
              | (1ULL << SqlParsingParser::ACTION)
              | (1ULL << SqlParsingParser::ADD)
              | (1ULL << SqlParsingParser::AFTER)
              | (1ULL << SqlParsingParser::ALL)
              | (1ULL << SqlParsingParser::ALTER)
              | (1ULL << SqlParsingParser::ANALYZE)
              | (1ULL << SqlParsingParser::AND)
              | (1ULL << SqlParsingParser::AS)
              | (1ULL << SqlParsingParser::ASC)
              | (1ULL << SqlParsingParser::ATTACH)
              | (1ULL << SqlParsingParser::AUTOINCREMENT)
              | (1ULL << SqlParsingParser::BEFORE)
              | (1ULL << SqlParsingParser::BEGIN)
              | (1ULL << SqlParsingParser::BETWEEN)
              | (1ULL << SqlParsingParser::BY)
              | (1ULL << SqlParsingParser::CASCADE)
              | (1ULL << SqlParsingParser::CASE)
              | (1ULL << SqlParsingParser::CAST)
              | (1ULL << SqlParsingParser::CHECK)
              | (1ULL << SqlParsingParser::COLLATE)
              | (1ULL << SqlParsingParser::COLUMN)
              | (1ULL << SqlParsingParser::COMMIT)
              | (1ULL << SqlParsingParser::CONFLICT)
              | (1ULL << SqlParsingParser::CONSTRAINT)
              | (1ULL << SqlParsingParser::CREATE)
              | (1ULL << SqlParsingParser::CROSS)
              | (1ULL << SqlParsingParser::CURRENT_DATE)
              | (1ULL << SqlParsingParser::CURRENT_TIME)
              | (1ULL << SqlParsingParser::CURRENT_TIMESTAMP)
              | (1ULL << SqlParsingParser::DATABASE)
              | (1ULL << SqlParsingParser::DEFAULT)
              | (1ULL << SqlParsingParser::DEFERRABLE)
              | (1ULL << SqlParsingParser::DEFERRED)
              | (1ULL << SqlParsingParser::DELETE)
              | (1ULL << SqlParsingParser::DESC)
              | (1ULL << SqlParsingParser::DETACH)
              | (1ULL << SqlParsingParser::DISTINCT)
              | (1ULL << SqlParsingParser::DROP))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
              ((1ULL << (_la - 64)) & ((1ULL << (SqlParsingParser::EACH - 64))
              | (1ULL << (SqlParsingParser::ELSE - 64))
              | (1ULL << (SqlParsingParser::END - 64))
              | (1ULL << (SqlParsingParser::ESCAPE - 64))
              | (1ULL << (SqlParsingParser::EXCEPT - 64))
              | (1ULL << (SqlParsingParser::EXCLUSIVE - 64))
              | (1ULL << (SqlParsingParser::EXISTS - 64))
              | (1ULL << (SqlParsingParser::EXPLAIN - 64))
              | (1ULL << (SqlParsingParser::FAIL - 64))
              | (1ULL << (SqlParsingParser::FOR - 64))
              | (1ULL << (SqlParsingParser::FOREIGN - 64))
              | (1ULL << (SqlParsingParser::FROM - 64))
              | (1ULL << (SqlParsingParser::FULL - 64))
              | (1ULL << (SqlParsingParser::GLOB - 64))
              | (1ULL << (SqlParsingParser::GROUP - 64))
              | (1ULL << (SqlParsingParser::HAVING - 64))
              | (1ULL << (SqlParsingParser::IF - 64))
              | (1ULL << (SqlParsingParser::IGNORE - 64))
              | (1ULL << (SqlParsingParser::IMMEDIATE - 64))
              | (1ULL << (SqlParsingParser::IN - 64))
              | (1ULL << (SqlParsingParser::INDEX - 64))
              | (1ULL << (SqlParsingParser::INDEXED - 64))
              | (1ULL << (SqlParsingParser::INITIALLY - 64))
              | (1ULL << (SqlParsingParser::INNER - 64))
              | (1ULL << (SqlParsingParser::INSERT - 64))
              | (1ULL << (SqlParsingParser::INSTEAD - 64))
              | (1ULL << (SqlParsingParser::INTERSECT - 64))
              | (1ULL << (SqlParsingParser::INTO - 64))
              | (1ULL << (SqlParsingParser::IS - 64))
              | (1ULL << (SqlParsingParser::ISNULL - 64))
              | (1ULL << (SqlParsingParser::JOIN - 64))
              | (1ULL << (SqlParsingParser::KEY - 64))
              | (1ULL << (SqlParsingParser::LEFT - 64))
              | (1ULL << (SqlParsingParser::LIKE - 64))
              | (1ULL << (SqlParsingParser::LIMIT - 64))
              | (1ULL << (SqlParsingParser::MATCH - 64))
              | (1ULL << (SqlParsingParser::NATURAL - 64))
              | (1ULL << (SqlParsingParser::NO - 64))
              | (1ULL << (SqlParsingParser::NOT - 64))
              | (1ULL << (SqlParsingParser::NOTNULL - 64))
              | (1ULL << (SqlParsingParser::NULL_ - 64))
              | (1ULL << (SqlParsingParser::OF - 64))
              | (1ULL << (SqlParsingParser::OFFSET - 64))
              | (1ULL << (SqlParsingParser::ON - 64))
              | (1ULL << (SqlParsingParser::OR - 64))
              | (1ULL << (SqlParsingParser::ORDER - 64))
              | (1ULL << (SqlParsingParser::OUTER - 64))
              | (1ULL << (SqlParsingParser::PLAN - 64))
              | (1ULL << (SqlParsingParser::PRAGMA - 64))
              | (1ULL << (SqlParsingParser::PRIMARY - 64))
              | (1ULL << (SqlParsingParser::QUERY - 64))
              | (1ULL << (SqlParsingParser::RAISE - 64))
              | (1ULL << (SqlParsingParser::RECURSIVE - 64))
              | (1ULL << (SqlParsingParser::REFERENCES - 64))
              | (1ULL << (SqlParsingParser::REGEXP - 64))
              | (1ULL << (SqlParsingParser::REINDEX - 64))
              | (1ULL << (SqlParsingParser::RELEASE - 64))
              | (1ULL << (SqlParsingParser::RENAME - 64))
              | (1ULL << (SqlParsingParser::REPLACE - 64))
              | (1ULL << (SqlParsingParser::RESTRICT - 64))
              | (1ULL << (SqlParsingParser::RIGHT - 64))
              | (1ULL << (SqlParsingParser::ROLLBACK - 64))
              | (1ULL << (SqlParsingParser::ROW - 64))
              | (1ULL << (SqlParsingParser::ROWS - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
              ((1ULL << (_la - 128)) & ((1ULL << (SqlParsingParser::SAVEPOINT - 128))
              | (1ULL << (SqlParsingParser::SELECT - 128))
              | (1ULL << (SqlParsingParser::SET - 128))
              | (1ULL << (SqlParsingParser::TABLE - 128))
              | (1ULL << (SqlParsingParser::TEMP - 128))
              | (1ULL << (SqlParsingParser::TEMPORARY - 128))
              | (1ULL << (SqlParsingParser::THEN - 128))
              | (1ULL << (SqlParsingParser::TO - 128))
              | (1ULL << (SqlParsingParser::TRANSACTION - 128))
              | (1ULL << (SqlParsingParser::TRIGGER - 128))
              | (1ULL << (SqlParsingParser::UNION - 128))
              | (1ULL << (SqlParsingParser::UNIQUE - 128))
              | (1ULL << (SqlParsingParser::UPDATE - 128))
              | (1ULL << (SqlParsingParser::USING - 128))
              | (1ULL << (SqlParsingParser::VACUUM - 128))
              | (1ULL << (SqlParsingParser::VALUES - 128))
              | (1ULL << (SqlParsingParser::VIEW - 128))
              | (1ULL << (SqlParsingParser::VIRTUAL - 128))
              | (1ULL << (SqlParsingParser::WHEN - 128))
              | (1ULL << (SqlParsingParser::WHERE - 128))
              | (1ULL << (SqlParsingParser::WITH - 128))
              | (1ULL << (SqlParsingParser::WITHOUT - 128))
              | (1ULL << (SqlParsingParser::FIRST_VALUE - 128))
              | (1ULL << (SqlParsingParser::OVER - 128))
              | (1ULL << (SqlParsingParser::PARTITION - 128))
              | (1ULL << (SqlParsingParser::RANGE - 128))
              | (1ULL << (SqlParsingParser::PRECEDING - 128))
              | (1ULL << (SqlParsingParser::UNBOUNDED - 128))
              | (1ULL << (SqlParsingParser::CURRENT - 128))
              | (1ULL << (SqlParsingParser::FOLLOWING - 128))
              | (1ULL << (SqlParsingParser::CUME_DIST - 128))
              | (1ULL << (SqlParsingParser::DENSE_RANK - 128))
              | (1ULL << (SqlParsingParser::LAG - 128))
              | (1ULL << (SqlParsingParser::LAST_VALUE - 128))
              | (1ULL << (SqlParsingParser::LEAD - 128))
              | (1ULL << (SqlParsingParser::NTH_VALUE - 128))
              | (1ULL << (SqlParsingParser::NTILE - 128))
              | (1ULL << (SqlParsingParser::PERCENT_RANK - 128))
              | (1ULL << (SqlParsingParser::RANK - 128))
              | (1ULL << (SqlParsingParser::ROW_NUMBER - 128))
              | (1ULL << (SqlParsingParser::GENERATED - 128))
              | (1ULL << (SqlParsingParser::ALWAYS - 128))
              | (1ULL << (SqlParsingParser::STORED - 128))
              | (1ULL << (SqlParsingParser::TRUE_ - 128))
              | (1ULL << (SqlParsingParser::FALSE_ - 128))
              | (1ULL << (SqlParsingParser::WINDOW - 128))
              | (1ULL << (SqlParsingParser::NULLS - 128))
              | (1ULL << (SqlParsingParser::FIRST - 128))
              | (1ULL << (SqlParsingParser::LAST - 128))
              | (1ULL << (SqlParsingParser::FILTER - 128))
              | (1ULL << (SqlParsingParser::GROUPS - 128))
              | (1ULL << (SqlParsingParser::EXCLUDE - 128))
              | (1ULL << (SqlParsingParser::IDENTIFIER - 128))
              | (1ULL << (SqlParsingParser::NUMERIC_LITERAL - 128))
              | (1ULL << (SqlParsingParser::BIND_PARAMETER - 128))
              | (1ULL << (SqlParsingParser::STRING_LITERAL - 128))
              | (1ULL << (SqlParsingParser::BLOB_LITERAL - 128)))) != 0)) {
              setState(1042);
              expr(0);
              setState(1047);
              _errHandler->sync(this);
              _la = _input->LA(1);
              while (_la == SqlParsingParser::COMMA) {
                setState(1043);
                match(SqlParsingParser::COMMA);
                setState(1044);
                expr(0);
                setState(1049);
                _errHandler->sync(this);
                _la = _input->LA(1);
              }
            }
            setState(1052);
            match(SqlParsingParser::CLOSE_PAR);
            break;
          }

          }
          break;
        }

        } 
      }
      setState(1060);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 132, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Raise_functionContext ------------------------------------------------------------------

SqlParsingParser::Raise_functionContext::Raise_functionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Raise_functionContext::RAISE() {
  return getToken(SqlParsingParser::RAISE, 0);
}

tree::TerminalNode* SqlParsingParser::Raise_functionContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Raise_functionContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Raise_functionContext::IGNORE() {
  return getToken(SqlParsingParser::IGNORE, 0);
}

tree::TerminalNode* SqlParsingParser::Raise_functionContext::COMMA() {
  return getToken(SqlParsingParser::COMMA, 0);
}

SqlParsingParser::Error_messageContext* SqlParsingParser::Raise_functionContext::error_message() {
  return getRuleContext<SqlParsingParser::Error_messageContext>(0);
}

tree::TerminalNode* SqlParsingParser::Raise_functionContext::ROLLBACK() {
  return getToken(SqlParsingParser::ROLLBACK, 0);
}

tree::TerminalNode* SqlParsingParser::Raise_functionContext::ABORT() {
  return getToken(SqlParsingParser::ABORT, 0);
}

tree::TerminalNode* SqlParsingParser::Raise_functionContext::FAIL() {
  return getToken(SqlParsingParser::FAIL, 0);
}


size_t SqlParsingParser::Raise_functionContext::getRuleIndex() const {
  return SqlParsingParser::RuleRaise_function;
}

void SqlParsingParser::Raise_functionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRaise_function(this);
}

void SqlParsingParser::Raise_functionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRaise_function(this);
}


antlrcpp::Any SqlParsingParser::Raise_functionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitRaise_function(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Raise_functionContext* SqlParsingParser::raise_function() {
  Raise_functionContext *_localctx = _tracker.createInstance<Raise_functionContext>(_ctx, getState());
  enterRule(_localctx, 64, SqlParsingParser::RuleRaise_function);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1061);
    match(SqlParsingParser::RAISE);
    setState(1062);
    match(SqlParsingParser::OPEN_PAR);
    setState(1067);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::IGNORE: {
        setState(1063);
        match(SqlParsingParser::IGNORE);
        break;
      }

      case SqlParsingParser::ABORT:
      case SqlParsingParser::FAIL:
      case SqlParsingParser::ROLLBACK: {
        setState(1064);
        _la = _input->LA(1);
        if (!(_la == SqlParsingParser::ABORT || _la == SqlParsingParser::FAIL

        || _la == SqlParsingParser::ROLLBACK)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(1065);
        match(SqlParsingParser::COMMA);
        setState(1066);
        error_message();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(1069);
    match(SqlParsingParser::CLOSE_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Literal_valueContext ------------------------------------------------------------------

SqlParsingParser::Literal_valueContext::Literal_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Literal_valueContext::NUMERIC_LITERAL() {
  return getToken(SqlParsingParser::NUMERIC_LITERAL, 0);
}

tree::TerminalNode* SqlParsingParser::Literal_valueContext::STRING_LITERAL() {
  return getToken(SqlParsingParser::STRING_LITERAL, 0);
}

tree::TerminalNode* SqlParsingParser::Literal_valueContext::BLOB_LITERAL() {
  return getToken(SqlParsingParser::BLOB_LITERAL, 0);
}

tree::TerminalNode* SqlParsingParser::Literal_valueContext::NULL_() {
  return getToken(SqlParsingParser::NULL_, 0);
}

tree::TerminalNode* SqlParsingParser::Literal_valueContext::TRUE_() {
  return getToken(SqlParsingParser::TRUE_, 0);
}

tree::TerminalNode* SqlParsingParser::Literal_valueContext::FALSE_() {
  return getToken(SqlParsingParser::FALSE_, 0);
}

tree::TerminalNode* SqlParsingParser::Literal_valueContext::CURRENT_TIME() {
  return getToken(SqlParsingParser::CURRENT_TIME, 0);
}

tree::TerminalNode* SqlParsingParser::Literal_valueContext::CURRENT_DATE() {
  return getToken(SqlParsingParser::CURRENT_DATE, 0);
}

tree::TerminalNode* SqlParsingParser::Literal_valueContext::CURRENT_TIMESTAMP() {
  return getToken(SqlParsingParser::CURRENT_TIMESTAMP, 0);
}


size_t SqlParsingParser::Literal_valueContext::getRuleIndex() const {
  return SqlParsingParser::RuleLiteral_value;
}

void SqlParsingParser::Literal_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral_value(this);
}

void SqlParsingParser::Literal_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral_value(this);
}


antlrcpp::Any SqlParsingParser::Literal_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitLiteral_value(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Literal_valueContext* SqlParsingParser::literal_value() {
  Literal_valueContext *_localctx = _tracker.createInstance<Literal_valueContext>(_ctx, getState());
  enterRule(_localctx, 66, SqlParsingParser::RuleLiteral_value);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1071);
    _la = _input->LA(1);
    if (!(((((_la - 52) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 52)) & ((1ULL << (SqlParsingParser::CURRENT_DATE - 52))
      | (1ULL << (SqlParsingParser::CURRENT_TIME - 52))
      | (1ULL << (SqlParsingParser::CURRENT_TIMESTAMP - 52))
      | (1ULL << (SqlParsingParser::NULL_ - 52)))) != 0) || ((((_la - 171) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 171)) & ((1ULL << (SqlParsingParser::TRUE_ - 171))
      | (1ULL << (SqlParsingParser::FALSE_ - 171))
      | (1ULL << (SqlParsingParser::NUMERIC_LITERAL - 171))
      | (1ULL << (SqlParsingParser::STRING_LITERAL - 171))
      | (1ULL << (SqlParsingParser::BLOB_LITERAL - 171)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Insert_stmtContext ------------------------------------------------------------------

SqlParsingParser::Insert_stmtContext::Insert_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Insert_stmtContext::INTO() {
  return getToken(SqlParsingParser::INTO, 0);
}

SqlParsingParser::Table_nameContext* SqlParsingParser::Insert_stmtContext::table_name() {
  return getRuleContext<SqlParsingParser::Table_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Insert_stmtContext::INSERT() {
  return getToken(SqlParsingParser::INSERT, 0);
}

tree::TerminalNode* SqlParsingParser::Insert_stmtContext::REPLACE() {
  return getToken(SqlParsingParser::REPLACE, 0);
}

SqlParsingParser::With_clauseContext* SqlParsingParser::Insert_stmtContext::with_clause() {
  return getRuleContext<SqlParsingParser::With_clauseContext>(0);
}

SqlParsingParser::Schema_nameContext* SqlParsingParser::Insert_stmtContext::schema_name() {
  return getRuleContext<SqlParsingParser::Schema_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Insert_stmtContext::DOT() {
  return getToken(SqlParsingParser::DOT, 0);
}

tree::TerminalNode* SqlParsingParser::Insert_stmtContext::AS() {
  return getToken(SqlParsingParser::AS, 0);
}

SqlParsingParser::Table_aliasContext* SqlParsingParser::Insert_stmtContext::table_alias() {
  return getRuleContext<SqlParsingParser::Table_aliasContext>(0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Insert_stmtContext::OPEN_PAR() {
  return getTokens(SqlParsingParser::OPEN_PAR);
}

tree::TerminalNode* SqlParsingParser::Insert_stmtContext::OPEN_PAR(size_t i) {
  return getToken(SqlParsingParser::OPEN_PAR, i);
}

std::vector<SqlParsingParser::Column_nameContext *> SqlParsingParser::Insert_stmtContext::column_name() {
  return getRuleContexts<SqlParsingParser::Column_nameContext>();
}

SqlParsingParser::Column_nameContext* SqlParsingParser::Insert_stmtContext::column_name(size_t i) {
  return getRuleContext<SqlParsingParser::Column_nameContext>(i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Insert_stmtContext::CLOSE_PAR() {
  return getTokens(SqlParsingParser::CLOSE_PAR);
}

tree::TerminalNode* SqlParsingParser::Insert_stmtContext::CLOSE_PAR(size_t i) {
  return getToken(SqlParsingParser::CLOSE_PAR, i);
}

tree::TerminalNode* SqlParsingParser::Insert_stmtContext::OR() {
  return getToken(SqlParsingParser::OR, 0);
}

SqlParsingParser::Select_stmtContext* SqlParsingParser::Insert_stmtContext::select_stmt() {
  return getRuleContext<SqlParsingParser::Select_stmtContext>(0);
}

tree::TerminalNode* SqlParsingParser::Insert_stmtContext::ROLLBACK() {
  return getToken(SqlParsingParser::ROLLBACK, 0);
}

tree::TerminalNode* SqlParsingParser::Insert_stmtContext::ABORT() {
  return getToken(SqlParsingParser::ABORT, 0);
}

tree::TerminalNode* SqlParsingParser::Insert_stmtContext::FAIL() {
  return getToken(SqlParsingParser::FAIL, 0);
}

tree::TerminalNode* SqlParsingParser::Insert_stmtContext::IGNORE() {
  return getToken(SqlParsingParser::IGNORE, 0);
}

SqlParsingParser::Upsert_clauseContext* SqlParsingParser::Insert_stmtContext::upsert_clause() {
  return getRuleContext<SqlParsingParser::Upsert_clauseContext>(0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Insert_stmtContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Insert_stmtContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}

tree::TerminalNode* SqlParsingParser::Insert_stmtContext::VALUES() {
  return getToken(SqlParsingParser::VALUES, 0);
}

std::vector<SqlParsingParser::ExprContext *> SqlParsingParser::Insert_stmtContext::expr() {
  return getRuleContexts<SqlParsingParser::ExprContext>();
}

SqlParsingParser::ExprContext* SqlParsingParser::Insert_stmtContext::expr(size_t i) {
  return getRuleContext<SqlParsingParser::ExprContext>(i);
}

tree::TerminalNode* SqlParsingParser::Insert_stmtContext::DEFAULT() {
  return getToken(SqlParsingParser::DEFAULT, 0);
}


size_t SqlParsingParser::Insert_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleInsert_stmt;
}

void SqlParsingParser::Insert_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInsert_stmt(this);
}

void SqlParsingParser::Insert_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInsert_stmt(this);
}


antlrcpp::Any SqlParsingParser::Insert_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitInsert_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Insert_stmtContext* SqlParsingParser::insert_stmt() {
  Insert_stmtContext *_localctx = _tracker.createInstance<Insert_stmtContext>(_ctx, getState());
  enterRule(_localctx, 68, SqlParsingParser::RuleInsert_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1143);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::INSERT:
      case SqlParsingParser::REPLACE:
      case SqlParsingParser::WITH: {
        enterOuterAlt(_localctx, 1);
        setState(1074);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::WITH) {
          setState(1073);
          with_clause();
        }
        setState(1081);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 135, _ctx)) {
        case 1: {
          setState(1076);
          match(SqlParsingParser::INSERT);
          break;
        }

        case 2: {
          setState(1077);
          match(SqlParsingParser::REPLACE);
          break;
        }

        case 3: {
          setState(1078);
          match(SqlParsingParser::INSERT);
          setState(1079);
          match(SqlParsingParser::OR);
          setState(1080);
          _la = _input->LA(1);
          if (!(_la == SqlParsingParser::ABORT || ((((_la - 72) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 72)) & ((1ULL << (SqlParsingParser::FAIL - 72))
            | (1ULL << (SqlParsingParser::IGNORE - 72))
            | (1ULL << (SqlParsingParser::REPLACE - 72))
            | (1ULL << (SqlParsingParser::ROLLBACK - 72)))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        }
        setState(1083);
        match(SqlParsingParser::INTO);
        setState(1087);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 136, _ctx)) {
        case 1: {
          setState(1084);
          schema_name();
          setState(1085);
          match(SqlParsingParser::DOT);
          break;
        }

        }
        setState(1089);
        table_name();
        setState(1092);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::AS) {
          setState(1090);
          match(SqlParsingParser::AS);
          setState(1091);
          table_alias();
        }
        setState(1105);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::OPEN_PAR) {
          setState(1094);
          match(SqlParsingParser::OPEN_PAR);
          setState(1095);
          column_name();
          setState(1100);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SqlParsingParser::COMMA) {
            setState(1096);
            match(SqlParsingParser::COMMA);
            setState(1097);
            column_name();
            setState(1102);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(1103);
          match(SqlParsingParser::CLOSE_PAR);
        }

        setState(1136);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 143, _ctx)) {
        case 1: {
          setState(1107);
          match(SqlParsingParser::VALUES);
          setState(1108);
          match(SqlParsingParser::OPEN_PAR);
          setState(1109);
          expr(0);
          setState(1114);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SqlParsingParser::COMMA) {
            setState(1110);
            match(SqlParsingParser::COMMA);
            setState(1111);
            expr(0);
            setState(1116);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(1117);
          match(SqlParsingParser::CLOSE_PAR);
          setState(1132);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SqlParsingParser::COMMA) {
            setState(1118);
            match(SqlParsingParser::COMMA);
            setState(1119);
            match(SqlParsingParser::OPEN_PAR);
            setState(1120);
            expr(0);
            setState(1125);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == SqlParsingParser::COMMA) {
              setState(1121);
              match(SqlParsingParser::COMMA);
              setState(1122);
              expr(0);
              setState(1127);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            setState(1128);
            match(SqlParsingParser::CLOSE_PAR);
            setState(1134);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case 2: {
          setState(1135);
          select_stmt();
          break;
        }

        }
        setState(1139);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::ON) {
          setState(1138);
          upsert_clause();
        }
        break;
      }

      case SqlParsingParser::DEFAULT: {
        enterOuterAlt(_localctx, 2);
        setState(1141);
        match(SqlParsingParser::DEFAULT);
        setState(1142);
        match(SqlParsingParser::VALUES);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Upsert_clauseContext ------------------------------------------------------------------

SqlParsingParser::Upsert_clauseContext::Upsert_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Upsert_clauseContext::ON() {
  return getToken(SqlParsingParser::ON, 0);
}

tree::TerminalNode* SqlParsingParser::Upsert_clauseContext::CONFLICT() {
  return getToken(SqlParsingParser::CONFLICT, 0);
}

tree::TerminalNode* SqlParsingParser::Upsert_clauseContext::DO() {
  return getToken(SqlParsingParser::DO, 0);
}

tree::TerminalNode* SqlParsingParser::Upsert_clauseContext::NOTHING() {
  return getToken(SqlParsingParser::NOTHING, 0);
}

tree::TerminalNode* SqlParsingParser::Upsert_clauseContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

std::vector<SqlParsingParser::Indexed_columnContext *> SqlParsingParser::Upsert_clauseContext::indexed_column() {
  return getRuleContexts<SqlParsingParser::Indexed_columnContext>();
}

SqlParsingParser::Indexed_columnContext* SqlParsingParser::Upsert_clauseContext::indexed_column(size_t i) {
  return getRuleContext<SqlParsingParser::Indexed_columnContext>(i);
}

tree::TerminalNode* SqlParsingParser::Upsert_clauseContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Upsert_clauseContext::UPDATE() {
  return getToken(SqlParsingParser::UPDATE, 0);
}

tree::TerminalNode* SqlParsingParser::Upsert_clauseContext::SET() {
  return getToken(SqlParsingParser::SET, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Upsert_clauseContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Upsert_clauseContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Upsert_clauseContext::WHERE() {
  return getTokens(SqlParsingParser::WHERE);
}

tree::TerminalNode* SqlParsingParser::Upsert_clauseContext::WHERE(size_t i) {
  return getToken(SqlParsingParser::WHERE, i);
}

std::vector<SqlParsingParser::ExprContext *> SqlParsingParser::Upsert_clauseContext::expr() {
  return getRuleContexts<SqlParsingParser::ExprContext>();
}

SqlParsingParser::ExprContext* SqlParsingParser::Upsert_clauseContext::expr(size_t i) {
  return getRuleContext<SqlParsingParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Upsert_clauseContext::EQ() {
  return getTokens(SqlParsingParser::EQ);
}

tree::TerminalNode* SqlParsingParser::Upsert_clauseContext::EQ(size_t i) {
  return getToken(SqlParsingParser::EQ, i);
}

std::vector<SqlParsingParser::Column_nameContext *> SqlParsingParser::Upsert_clauseContext::column_name() {
  return getRuleContexts<SqlParsingParser::Column_nameContext>();
}

SqlParsingParser::Column_nameContext* SqlParsingParser::Upsert_clauseContext::column_name(size_t i) {
  return getRuleContext<SqlParsingParser::Column_nameContext>(i);
}

std::vector<SqlParsingParser::Column_name_listContext *> SqlParsingParser::Upsert_clauseContext::column_name_list() {
  return getRuleContexts<SqlParsingParser::Column_name_listContext>();
}

SqlParsingParser::Column_name_listContext* SqlParsingParser::Upsert_clauseContext::column_name_list(size_t i) {
  return getRuleContext<SqlParsingParser::Column_name_listContext>(i);
}


size_t SqlParsingParser::Upsert_clauseContext::getRuleIndex() const {
  return SqlParsingParser::RuleUpsert_clause;
}

void SqlParsingParser::Upsert_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUpsert_clause(this);
}

void SqlParsingParser::Upsert_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUpsert_clause(this);
}


antlrcpp::Any SqlParsingParser::Upsert_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitUpsert_clause(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Upsert_clauseContext* SqlParsingParser::upsert_clause() {
  Upsert_clauseContext *_localctx = _tracker.createInstance<Upsert_clauseContext>(_ctx, getState());
  enterRule(_localctx, 70, SqlParsingParser::RuleUpsert_clause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1145);
    match(SqlParsingParser::ON);
    setState(1146);
    match(SqlParsingParser::CONFLICT);
    setState(1161);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::OPEN_PAR) {
      setState(1147);
      match(SqlParsingParser::OPEN_PAR);
      setState(1148);
      indexed_column();
      setState(1153);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SqlParsingParser::COMMA) {
        setState(1149);
        match(SqlParsingParser::COMMA);
        setState(1150);
        indexed_column();
        setState(1155);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1156);
      match(SqlParsingParser::CLOSE_PAR);
      setState(1159);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SqlParsingParser::WHERE) {
        setState(1157);
        match(SqlParsingParser::WHERE);
        setState(1158);
        expr(0);
      }
    }
    setState(1163);
    match(SqlParsingParser::DO);
    setState(1190);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::NOTHING: {
        setState(1164);
        match(SqlParsingParser::NOTHING);
        break;
      }

      case SqlParsingParser::UPDATE: {
        setState(1165);
        match(SqlParsingParser::UPDATE);
        setState(1166);
        match(SqlParsingParser::SET);

        setState(1169);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 149, _ctx)) {
        case 1: {
          setState(1167);
          column_name();
          break;
        }

        case 2: {
          setState(1168);
          column_name_list();
          break;
        }

        }
        setState(1171);
        match(SqlParsingParser::EQ);
        setState(1172);
        expr(0);
        setState(1183);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParsingParser::COMMA) {
          setState(1173);
          match(SqlParsingParser::COMMA);
          setState(1176);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 150, _ctx)) {
          case 1: {
            setState(1174);
            column_name();
            break;
          }

          case 2: {
            setState(1175);
            column_name_list();
            break;
          }

          }
          setState(1178);
          match(SqlParsingParser::EQ);
          setState(1179);
          expr(0);
          setState(1185);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1188);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::WHERE) {
          setState(1186);
          match(SqlParsingParser::WHERE);
          setState(1187);
          expr(0);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pragma_stmtContext ------------------------------------------------------------------

SqlParsingParser::Pragma_stmtContext::Pragma_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Pragma_stmtContext::PRAGMA() {
  return getToken(SqlParsingParser::PRAGMA, 0);
}

SqlParsingParser::Pragma_nameContext* SqlParsingParser::Pragma_stmtContext::pragma_name() {
  return getRuleContext<SqlParsingParser::Pragma_nameContext>(0);
}

SqlParsingParser::Schema_nameContext* SqlParsingParser::Pragma_stmtContext::schema_name() {
  return getRuleContext<SqlParsingParser::Schema_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Pragma_stmtContext::DOT() {
  return getToken(SqlParsingParser::DOT, 0);
}

tree::TerminalNode* SqlParsingParser::Pragma_stmtContext::ASSIGN() {
  return getToken(SqlParsingParser::ASSIGN, 0);
}

SqlParsingParser::Pragma_valueContext* SqlParsingParser::Pragma_stmtContext::pragma_value() {
  return getRuleContext<SqlParsingParser::Pragma_valueContext>(0);
}

tree::TerminalNode* SqlParsingParser::Pragma_stmtContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Pragma_stmtContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}


size_t SqlParsingParser::Pragma_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RulePragma_stmt;
}

void SqlParsingParser::Pragma_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPragma_stmt(this);
}

void SqlParsingParser::Pragma_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPragma_stmt(this);
}


antlrcpp::Any SqlParsingParser::Pragma_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitPragma_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Pragma_stmtContext* SqlParsingParser::pragma_stmt() {
  Pragma_stmtContext *_localctx = _tracker.createInstance<Pragma_stmtContext>(_ctx, getState());
  enterRule(_localctx, 72, SqlParsingParser::RulePragma_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1192);
    match(SqlParsingParser::PRAGMA);
    setState(1196);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 154, _ctx)) {
    case 1: {
      setState(1193);
      schema_name();
      setState(1194);
      match(SqlParsingParser::DOT);
      break;
    }

    }
    setState(1198);
    pragma_name();
    setState(1205);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::ASSIGN: {
        setState(1199);
        match(SqlParsingParser::ASSIGN);
        setState(1200);
        pragma_value();
        break;
      }

      case SqlParsingParser::OPEN_PAR: {
        setState(1201);
        match(SqlParsingParser::OPEN_PAR);
        setState(1202);
        pragma_value();
        setState(1203);
        match(SqlParsingParser::CLOSE_PAR);
        break;
      }

      case SqlParsingParser::EOF:
      case SqlParsingParser::SCOL: {
        break;
      }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pragma_valueContext ------------------------------------------------------------------

SqlParsingParser::Pragma_valueContext::Pragma_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Signed_numberContext* SqlParsingParser::Pragma_valueContext::signed_number() {
  return getRuleContext<SqlParsingParser::Signed_numberContext>(0);
}

SqlParsingParser::NameContext* SqlParsingParser::Pragma_valueContext::name() {
  return getRuleContext<SqlParsingParser::NameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Pragma_valueContext::STRING_LITERAL() {
  return getToken(SqlParsingParser::STRING_LITERAL, 0);
}


size_t SqlParsingParser::Pragma_valueContext::getRuleIndex() const {
  return SqlParsingParser::RulePragma_value;
}

void SqlParsingParser::Pragma_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPragma_value(this);
}

void SqlParsingParser::Pragma_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPragma_value(this);
}


antlrcpp::Any SqlParsingParser::Pragma_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitPragma_value(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Pragma_valueContext* SqlParsingParser::pragma_value() {
  Pragma_valueContext *_localctx = _tracker.createInstance<Pragma_valueContext>(_ctx, getState());
  enterRule(_localctx, 74, SqlParsingParser::RulePragma_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1210);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 156, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1207);
      signed_number();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1208);
      name();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1209);
      match(SqlParsingParser::STRING_LITERAL);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Reindex_stmtContext ------------------------------------------------------------------

SqlParsingParser::Reindex_stmtContext::Reindex_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Reindex_stmtContext::REINDEX() {
  return getToken(SqlParsingParser::REINDEX, 0);
}

SqlParsingParser::Collation_nameContext* SqlParsingParser::Reindex_stmtContext::collation_name() {
  return getRuleContext<SqlParsingParser::Collation_nameContext>(0);
}

SqlParsingParser::Table_nameContext* SqlParsingParser::Reindex_stmtContext::table_name() {
  return getRuleContext<SqlParsingParser::Table_nameContext>(0);
}

SqlParsingParser::Index_nameContext* SqlParsingParser::Reindex_stmtContext::index_name() {
  return getRuleContext<SqlParsingParser::Index_nameContext>(0);
}

SqlParsingParser::Schema_nameContext* SqlParsingParser::Reindex_stmtContext::schema_name() {
  return getRuleContext<SqlParsingParser::Schema_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Reindex_stmtContext::DOT() {
  return getToken(SqlParsingParser::DOT, 0);
}


size_t SqlParsingParser::Reindex_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleReindex_stmt;
}

void SqlParsingParser::Reindex_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReindex_stmt(this);
}

void SqlParsingParser::Reindex_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReindex_stmt(this);
}


antlrcpp::Any SqlParsingParser::Reindex_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitReindex_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Reindex_stmtContext* SqlParsingParser::reindex_stmt() {
  Reindex_stmtContext *_localctx = _tracker.createInstance<Reindex_stmtContext>(_ctx, getState());
  enterRule(_localctx, 76, SqlParsingParser::RuleReindex_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1212);
    match(SqlParsingParser::REINDEX);
    setState(1223);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 159, _ctx)) {
    case 1: {
      setState(1213);
      collation_name();
      break;
    }

    case 2: {
      setState(1217);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 157, _ctx)) {
      case 1: {
        setState(1214);
        schema_name();
        setState(1215);
        match(SqlParsingParser::DOT);
        break;
      }

      }
      setState(1221);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 158, _ctx)) {
      case 1: {
        setState(1219);
        table_name();
        break;
      }

      case 2: {
        setState(1220);
        index_name();
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Select_stmtContext ------------------------------------------------------------------

SqlParsingParser::Select_stmtContext::Select_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SqlParsingParser::Select_coreContext *> SqlParsingParser::Select_stmtContext::select_core() {
  return getRuleContexts<SqlParsingParser::Select_coreContext>();
}

SqlParsingParser::Select_coreContext* SqlParsingParser::Select_stmtContext::select_core(size_t i) {
  return getRuleContext<SqlParsingParser::Select_coreContext>(i);
}

SqlParsingParser::Common_table_stmtContext* SqlParsingParser::Select_stmtContext::common_table_stmt() {
  return getRuleContext<SqlParsingParser::Common_table_stmtContext>(0);
}

std::vector<SqlParsingParser::Compound_operatorContext *> SqlParsingParser::Select_stmtContext::compound_operator() {
  return getRuleContexts<SqlParsingParser::Compound_operatorContext>();
}

SqlParsingParser::Compound_operatorContext* SqlParsingParser::Select_stmtContext::compound_operator(size_t i) {
  return getRuleContext<SqlParsingParser::Compound_operatorContext>(i);
}

SqlParsingParser::Order_by_stmtContext* SqlParsingParser::Select_stmtContext::order_by_stmt() {
  return getRuleContext<SqlParsingParser::Order_by_stmtContext>(0);
}

SqlParsingParser::Limit_stmtContext* SqlParsingParser::Select_stmtContext::limit_stmt() {
  return getRuleContext<SqlParsingParser::Limit_stmtContext>(0);
}


size_t SqlParsingParser::Select_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleSelect_stmt;
}

void SqlParsingParser::Select_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelect_stmt(this);
}

void SqlParsingParser::Select_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelect_stmt(this);
}


antlrcpp::Any SqlParsingParser::Select_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitSelect_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Select_stmtContext* SqlParsingParser::select_stmt() {
  Select_stmtContext *_localctx = _tracker.createInstance<Select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 78, SqlParsingParser::RuleSelect_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1226);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::WITH) {
      setState(1225);
      common_table_stmt();
    }
    setState(1228);
    select_core();
    setState(1234);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 161, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1229);
        compound_operator();
        setState(1230);
        select_core(); 
      }
      setState(1236);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 161, _ctx);
    }
    setState(1238);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::ORDER) {
      setState(1237);
      order_by_stmt();
    }
    setState(1241);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::LIMIT) {
      setState(1240);
      limit_stmt();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Join_clauseContext ------------------------------------------------------------------

SqlParsingParser::Join_clauseContext::Join_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SqlParsingParser::Table_or_subqueryContext *> SqlParsingParser::Join_clauseContext::table_or_subquery() {
  return getRuleContexts<SqlParsingParser::Table_or_subqueryContext>();
}

SqlParsingParser::Table_or_subqueryContext* SqlParsingParser::Join_clauseContext::table_or_subquery(size_t i) {
  return getRuleContext<SqlParsingParser::Table_or_subqueryContext>(i);
}

std::vector<SqlParsingParser::Join_operatorContext *> SqlParsingParser::Join_clauseContext::join_operator() {
  return getRuleContexts<SqlParsingParser::Join_operatorContext>();
}

SqlParsingParser::Join_operatorContext* SqlParsingParser::Join_clauseContext::join_operator(size_t i) {
  return getRuleContext<SqlParsingParser::Join_operatorContext>(i);
}

std::vector<SqlParsingParser::Join_constraintContext *> SqlParsingParser::Join_clauseContext::join_constraint() {
  return getRuleContexts<SqlParsingParser::Join_constraintContext>();
}

SqlParsingParser::Join_constraintContext* SqlParsingParser::Join_clauseContext::join_constraint(size_t i) {
  return getRuleContext<SqlParsingParser::Join_constraintContext>(i);
}


size_t SqlParsingParser::Join_clauseContext::getRuleIndex() const {
  return SqlParsingParser::RuleJoin_clause;
}

void SqlParsingParser::Join_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJoin_clause(this);
}

void SqlParsingParser::Join_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJoin_clause(this);
}


antlrcpp::Any SqlParsingParser::Join_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitJoin_clause(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Join_clauseContext* SqlParsingParser::join_clause() {
  Join_clauseContext *_localctx = _tracker.createInstance<Join_clauseContext>(_ctx, getState());
  enterRule(_localctx, 80, SqlParsingParser::RuleJoin_clause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1243);
    table_or_subquery();
    setState(1251);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SqlParsingParser::COMMA

    || _la == SqlParsingParser::CROSS || ((((_la - 87) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 87)) & ((1ULL << (SqlParsingParser::INNER - 87))
      | (1ULL << (SqlParsingParser::JOIN - 87))
      | (1ULL << (SqlParsingParser::LEFT - 87))
      | (1ULL << (SqlParsingParser::NATURAL - 87)))) != 0)) {
      setState(1244);
      join_operator();
      setState(1245);
      table_or_subquery();
      setState(1247);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 164, _ctx)) {
      case 1: {
        setState(1246);
        join_constraint();
        break;
      }

      }
      setState(1253);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Select_coreContext ------------------------------------------------------------------

SqlParsingParser::Select_coreContext::Select_coreContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Select_coreContext::SELECT() {
  return getToken(SqlParsingParser::SELECT, 0);
}

std::vector<SqlParsingParser::Result_columnContext *> SqlParsingParser::Select_coreContext::result_column() {
  return getRuleContexts<SqlParsingParser::Result_columnContext>();
}

SqlParsingParser::Result_columnContext* SqlParsingParser::Select_coreContext::result_column(size_t i) {
  return getRuleContext<SqlParsingParser::Result_columnContext>(i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Select_coreContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Select_coreContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}

tree::TerminalNode* SqlParsingParser::Select_coreContext::FROM() {
  return getToken(SqlParsingParser::FROM, 0);
}

tree::TerminalNode* SqlParsingParser::Select_coreContext::WHERE() {
  return getToken(SqlParsingParser::WHERE, 0);
}

std::vector<SqlParsingParser::ExprContext *> SqlParsingParser::Select_coreContext::expr() {
  return getRuleContexts<SqlParsingParser::ExprContext>();
}

SqlParsingParser::ExprContext* SqlParsingParser::Select_coreContext::expr(size_t i) {
  return getRuleContext<SqlParsingParser::ExprContext>(i);
}

tree::TerminalNode* SqlParsingParser::Select_coreContext::GROUP() {
  return getToken(SqlParsingParser::GROUP, 0);
}

tree::TerminalNode* SqlParsingParser::Select_coreContext::BY() {
  return getToken(SqlParsingParser::BY, 0);
}

tree::TerminalNode* SqlParsingParser::Select_coreContext::WINDOW() {
  return getToken(SqlParsingParser::WINDOW, 0);
}

std::vector<SqlParsingParser::Window_nameContext *> SqlParsingParser::Select_coreContext::window_name() {
  return getRuleContexts<SqlParsingParser::Window_nameContext>();
}

SqlParsingParser::Window_nameContext* SqlParsingParser::Select_coreContext::window_name(size_t i) {
  return getRuleContext<SqlParsingParser::Window_nameContext>(i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Select_coreContext::AS() {
  return getTokens(SqlParsingParser::AS);
}

tree::TerminalNode* SqlParsingParser::Select_coreContext::AS(size_t i) {
  return getToken(SqlParsingParser::AS, i);
}

std::vector<SqlParsingParser::Window_defnContext *> SqlParsingParser::Select_coreContext::window_defn() {
  return getRuleContexts<SqlParsingParser::Window_defnContext>();
}

SqlParsingParser::Window_defnContext* SqlParsingParser::Select_coreContext::window_defn(size_t i) {
  return getRuleContext<SqlParsingParser::Window_defnContext>(i);
}

tree::TerminalNode* SqlParsingParser::Select_coreContext::DISTINCT() {
  return getToken(SqlParsingParser::DISTINCT, 0);
}

tree::TerminalNode* SqlParsingParser::Select_coreContext::ALL() {
  return getToken(SqlParsingParser::ALL, 0);
}

std::vector<SqlParsingParser::Table_or_subqueryContext *> SqlParsingParser::Select_coreContext::table_or_subquery() {
  return getRuleContexts<SqlParsingParser::Table_or_subqueryContext>();
}

SqlParsingParser::Table_or_subqueryContext* SqlParsingParser::Select_coreContext::table_or_subquery(size_t i) {
  return getRuleContext<SqlParsingParser::Table_or_subqueryContext>(i);
}

SqlParsingParser::Join_clauseContext* SqlParsingParser::Select_coreContext::join_clause() {
  return getRuleContext<SqlParsingParser::Join_clauseContext>(0);
}

tree::TerminalNode* SqlParsingParser::Select_coreContext::HAVING() {
  return getToken(SqlParsingParser::HAVING, 0);
}

tree::TerminalNode* SqlParsingParser::Select_coreContext::VALUES() {
  return getToken(SqlParsingParser::VALUES, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Select_coreContext::OPEN_PAR() {
  return getTokens(SqlParsingParser::OPEN_PAR);
}

tree::TerminalNode* SqlParsingParser::Select_coreContext::OPEN_PAR(size_t i) {
  return getToken(SqlParsingParser::OPEN_PAR, i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Select_coreContext::CLOSE_PAR() {
  return getTokens(SqlParsingParser::CLOSE_PAR);
}

tree::TerminalNode* SqlParsingParser::Select_coreContext::CLOSE_PAR(size_t i) {
  return getToken(SqlParsingParser::CLOSE_PAR, i);
}


size_t SqlParsingParser::Select_coreContext::getRuleIndex() const {
  return SqlParsingParser::RuleSelect_core;
}

void SqlParsingParser::Select_coreContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelect_core(this);
}

void SqlParsingParser::Select_coreContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelect_core(this);
}


antlrcpp::Any SqlParsingParser::Select_coreContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitSelect_core(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Select_coreContext* SqlParsingParser::select_core() {
  Select_coreContext *_localctx = _tracker.createInstance<Select_coreContext>(_ctx, getState());
  enterRule(_localctx, 82, SqlParsingParser::RuleSelect_core);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1344);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::SELECT: {
        enterOuterAlt(_localctx, 1);
        setState(1254);
        match(SqlParsingParser::SELECT);
        setState(1256);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 166, _ctx)) {
        case 1: {
          setState(1255);
          _la = _input->LA(1);
          if (!(_la == SqlParsingParser::ALL

          || _la == SqlParsingParser::DISTINCT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        }
        setState(1258);
        result_column();
        setState(1263);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParsingParser::COMMA) {
          setState(1259);
          match(SqlParsingParser::COMMA);
          setState(1260);
          result_column();
          setState(1265);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1278);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::FROM) {
          setState(1266);
          match(SqlParsingParser::FROM);
          setState(1276);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 169, _ctx)) {
          case 1: {
            setState(1267);
            table_or_subquery();
            setState(1272);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == SqlParsingParser::COMMA) {
              setState(1268);
              match(SqlParsingParser::COMMA);
              setState(1269);
              table_or_subquery();
              setState(1274);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case 2: {
            setState(1275);
            join_clause();
            break;
          }

          }
        }
        setState(1282);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::WHERE) {
          setState(1280);
          match(SqlParsingParser::WHERE);
          setState(1281);
          expr(0);
        }
        setState(1298);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::GROUP) {
          setState(1284);
          match(SqlParsingParser::GROUP);
          setState(1285);
          match(SqlParsingParser::BY);
          setState(1286);
          expr(0);
          setState(1291);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SqlParsingParser::COMMA) {
            setState(1287);
            match(SqlParsingParser::COMMA);
            setState(1288);
            expr(0);
            setState(1293);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(1296);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == SqlParsingParser::HAVING) {
            setState(1294);
            match(SqlParsingParser::HAVING);
            setState(1295);
            expr(0);
          }
        }
        setState(1314);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::WINDOW) {
          setState(1300);
          match(SqlParsingParser::WINDOW);
          setState(1301);
          window_name();
          setState(1302);
          match(SqlParsingParser::AS);
          setState(1303);
          window_defn();
          setState(1311);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SqlParsingParser::COMMA) {
            setState(1304);
            match(SqlParsingParser::COMMA);
            setState(1305);
            window_name();
            setState(1306);
            match(SqlParsingParser::AS);
            setState(1307);
            window_defn();
            setState(1313);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        break;
      }

      case SqlParsingParser::VALUES: {
        enterOuterAlt(_localctx, 2);
        setState(1316);
        match(SqlParsingParser::VALUES);
        setState(1317);
        match(SqlParsingParser::OPEN_PAR);
        setState(1318);
        expr(0);
        setState(1323);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParsingParser::COMMA) {
          setState(1319);
          match(SqlParsingParser::COMMA);
          setState(1320);
          expr(0);
          setState(1325);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1326);
        match(SqlParsingParser::CLOSE_PAR);
        setState(1341);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParsingParser::COMMA) {
          setState(1327);
          match(SqlParsingParser::COMMA);
          setState(1328);
          match(SqlParsingParser::OPEN_PAR);
          setState(1329);
          expr(0);
          setState(1334);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SqlParsingParser::COMMA) {
            setState(1330);
            match(SqlParsingParser::COMMA);
            setState(1331);
            expr(0);
            setState(1336);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(1337);
          match(SqlParsingParser::CLOSE_PAR);
          setState(1343);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Factored_select_stmtContext ------------------------------------------------------------------

SqlParsingParser::Factored_select_stmtContext::Factored_select_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Select_stmtContext* SqlParsingParser::Factored_select_stmtContext::select_stmt() {
  return getRuleContext<SqlParsingParser::Select_stmtContext>(0);
}


size_t SqlParsingParser::Factored_select_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleFactored_select_stmt;
}

void SqlParsingParser::Factored_select_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactored_select_stmt(this);
}

void SqlParsingParser::Factored_select_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactored_select_stmt(this);
}


antlrcpp::Any SqlParsingParser::Factored_select_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitFactored_select_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Factored_select_stmtContext* SqlParsingParser::factored_select_stmt() {
  Factored_select_stmtContext *_localctx = _tracker.createInstance<Factored_select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 84, SqlParsingParser::RuleFactored_select_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1346);
    select_stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_select_stmtContext ------------------------------------------------------------------

SqlParsingParser::Simple_select_stmtContext::Simple_select_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Select_coreContext* SqlParsingParser::Simple_select_stmtContext::select_core() {
  return getRuleContext<SqlParsingParser::Select_coreContext>(0);
}

SqlParsingParser::Common_table_stmtContext* SqlParsingParser::Simple_select_stmtContext::common_table_stmt() {
  return getRuleContext<SqlParsingParser::Common_table_stmtContext>(0);
}

SqlParsingParser::Order_by_stmtContext* SqlParsingParser::Simple_select_stmtContext::order_by_stmt() {
  return getRuleContext<SqlParsingParser::Order_by_stmtContext>(0);
}

SqlParsingParser::Limit_stmtContext* SqlParsingParser::Simple_select_stmtContext::limit_stmt() {
  return getRuleContext<SqlParsingParser::Limit_stmtContext>(0);
}


size_t SqlParsingParser::Simple_select_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleSimple_select_stmt;
}

void SqlParsingParser::Simple_select_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_select_stmt(this);
}

void SqlParsingParser::Simple_select_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_select_stmt(this);
}


antlrcpp::Any SqlParsingParser::Simple_select_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitSimple_select_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Simple_select_stmtContext* SqlParsingParser::simple_select_stmt() {
  Simple_select_stmtContext *_localctx = _tracker.createInstance<Simple_select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 86, SqlParsingParser::RuleSimple_select_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1349);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::WITH) {
      setState(1348);
      common_table_stmt();
    }
    setState(1351);
    select_core();
    setState(1353);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::ORDER) {
      setState(1352);
      order_by_stmt();
    }
    setState(1356);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::LIMIT) {
      setState(1355);
      limit_stmt();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compound_select_stmtContext ------------------------------------------------------------------

SqlParsingParser::Compound_select_stmtContext::Compound_select_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SqlParsingParser::Select_coreContext *> SqlParsingParser::Compound_select_stmtContext::select_core() {
  return getRuleContexts<SqlParsingParser::Select_coreContext>();
}

SqlParsingParser::Select_coreContext* SqlParsingParser::Compound_select_stmtContext::select_core(size_t i) {
  return getRuleContext<SqlParsingParser::Select_coreContext>(i);
}

SqlParsingParser::Common_table_stmtContext* SqlParsingParser::Compound_select_stmtContext::common_table_stmt() {
  return getRuleContext<SqlParsingParser::Common_table_stmtContext>(0);
}

SqlParsingParser::Order_by_stmtContext* SqlParsingParser::Compound_select_stmtContext::order_by_stmt() {
  return getRuleContext<SqlParsingParser::Order_by_stmtContext>(0);
}

SqlParsingParser::Limit_stmtContext* SqlParsingParser::Compound_select_stmtContext::limit_stmt() {
  return getRuleContext<SqlParsingParser::Limit_stmtContext>(0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Compound_select_stmtContext::INTERSECT() {
  return getTokens(SqlParsingParser::INTERSECT);
}

tree::TerminalNode* SqlParsingParser::Compound_select_stmtContext::INTERSECT(size_t i) {
  return getToken(SqlParsingParser::INTERSECT, i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Compound_select_stmtContext::EXCEPT() {
  return getTokens(SqlParsingParser::EXCEPT);
}

tree::TerminalNode* SqlParsingParser::Compound_select_stmtContext::EXCEPT(size_t i) {
  return getToken(SqlParsingParser::EXCEPT, i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Compound_select_stmtContext::UNION() {
  return getTokens(SqlParsingParser::UNION);
}

tree::TerminalNode* SqlParsingParser::Compound_select_stmtContext::UNION(size_t i) {
  return getToken(SqlParsingParser::UNION, i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Compound_select_stmtContext::ALL() {
  return getTokens(SqlParsingParser::ALL);
}

tree::TerminalNode* SqlParsingParser::Compound_select_stmtContext::ALL(size_t i) {
  return getToken(SqlParsingParser::ALL, i);
}


size_t SqlParsingParser::Compound_select_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleCompound_select_stmt;
}

void SqlParsingParser::Compound_select_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_select_stmt(this);
}

void SqlParsingParser::Compound_select_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_select_stmt(this);
}


antlrcpp::Any SqlParsingParser::Compound_select_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitCompound_select_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Compound_select_stmtContext* SqlParsingParser::compound_select_stmt() {
  Compound_select_stmtContext *_localctx = _tracker.createInstance<Compound_select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 88, SqlParsingParser::RuleCompound_select_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1359);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::WITH) {
      setState(1358);
      common_table_stmt();
    }
    setState(1361);
    select_core();
    setState(1371); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1368);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SqlParsingParser::UNION: {
          setState(1362);
          match(SqlParsingParser::UNION);
          setState(1364);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == SqlParsingParser::ALL) {
            setState(1363);
            match(SqlParsingParser::ALL);
          }
          break;
        }

        case SqlParsingParser::INTERSECT: {
          setState(1366);
          match(SqlParsingParser::INTERSECT);
          break;
        }

        case SqlParsingParser::EXCEPT: {
          setState(1367);
          match(SqlParsingParser::EXCEPT);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(1370);
      select_core();
      setState(1373); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SqlParsingParser::EXCEPT

    || _la == SqlParsingParser::INTERSECT || _la == SqlParsingParser::UNION);
    setState(1376);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::ORDER) {
      setState(1375);
      order_by_stmt();
    }
    setState(1379);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::LIMIT) {
      setState(1378);
      limit_stmt();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_or_subqueryContext ------------------------------------------------------------------

SqlParsingParser::Table_or_subqueryContext::Table_or_subqueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Table_nameContext* SqlParsingParser::Table_or_subqueryContext::table_name() {
  return getRuleContext<SqlParsingParser::Table_nameContext>(0);
}

SqlParsingParser::Schema_nameContext* SqlParsingParser::Table_or_subqueryContext::schema_name() {
  return getRuleContext<SqlParsingParser::Schema_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Table_or_subqueryContext::DOT() {
  return getToken(SqlParsingParser::DOT, 0);
}

SqlParsingParser::Table_aliasContext* SqlParsingParser::Table_or_subqueryContext::table_alias() {
  return getRuleContext<SqlParsingParser::Table_aliasContext>(0);
}

tree::TerminalNode* SqlParsingParser::Table_or_subqueryContext::INDEXED() {
  return getToken(SqlParsingParser::INDEXED, 0);
}

tree::TerminalNode* SqlParsingParser::Table_or_subqueryContext::BY() {
  return getToken(SqlParsingParser::BY, 0);
}

SqlParsingParser::Index_nameContext* SqlParsingParser::Table_or_subqueryContext::index_name() {
  return getRuleContext<SqlParsingParser::Index_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Table_or_subqueryContext::NOT() {
  return getToken(SqlParsingParser::NOT, 0);
}

tree::TerminalNode* SqlParsingParser::Table_or_subqueryContext::AS() {
  return getToken(SqlParsingParser::AS, 0);
}

SqlParsingParser::Table_function_nameContext* SqlParsingParser::Table_or_subqueryContext::table_function_name() {
  return getRuleContext<SqlParsingParser::Table_function_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Table_or_subqueryContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

std::vector<SqlParsingParser::ExprContext *> SqlParsingParser::Table_or_subqueryContext::expr() {
  return getRuleContexts<SqlParsingParser::ExprContext>();
}

SqlParsingParser::ExprContext* SqlParsingParser::Table_or_subqueryContext::expr(size_t i) {
  return getRuleContext<SqlParsingParser::ExprContext>(i);
}

tree::TerminalNode* SqlParsingParser::Table_or_subqueryContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Table_or_subqueryContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Table_or_subqueryContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}

std::vector<SqlParsingParser::Table_or_subqueryContext *> SqlParsingParser::Table_or_subqueryContext::table_or_subquery() {
  return getRuleContexts<SqlParsingParser::Table_or_subqueryContext>();
}

SqlParsingParser::Table_or_subqueryContext* SqlParsingParser::Table_or_subqueryContext::table_or_subquery(size_t i) {
  return getRuleContext<SqlParsingParser::Table_or_subqueryContext>(i);
}

SqlParsingParser::Join_clauseContext* SqlParsingParser::Table_or_subqueryContext::join_clause() {
  return getRuleContext<SqlParsingParser::Join_clauseContext>(0);
}

SqlParsingParser::Select_stmtContext* SqlParsingParser::Table_or_subqueryContext::select_stmt() {
  return getRuleContext<SqlParsingParser::Select_stmtContext>(0);
}


size_t SqlParsingParser::Table_or_subqueryContext::getRuleIndex() const {
  return SqlParsingParser::RuleTable_or_subquery;
}

void SqlParsingParser::Table_or_subqueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_or_subquery(this);
}

void SqlParsingParser::Table_or_subqueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_or_subquery(this);
}


antlrcpp::Any SqlParsingParser::Table_or_subqueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitTable_or_subquery(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Table_or_subqueryContext* SqlParsingParser::table_or_subquery() {
  Table_or_subqueryContext *_localctx = _tracker.createInstance<Table_or_subqueryContext>(_ctx, getState());
  enterRule(_localctx, 90, SqlParsingParser::RuleTable_or_subquery);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1445);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 202, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1384);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 190, _ctx)) {
      case 1: {
        setState(1381);
        schema_name();
        setState(1382);
        match(SqlParsingParser::DOT);
        break;
      }

      }
      setState(1386);
      table_name();
      setState(1391);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 192, _ctx)) {
      case 1: {
        setState(1388);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 191, _ctx)) {
        case 1: {
          setState(1387);
          match(SqlParsingParser::AS);
          break;
        }

        }
        setState(1390);
        table_alias();
        break;
      }

      }
      setState(1398);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SqlParsingParser::INDEXED: {
          setState(1393);
          match(SqlParsingParser::INDEXED);
          setState(1394);
          match(SqlParsingParser::BY);
          setState(1395);
          index_name();
          break;
        }

        case SqlParsingParser::NOT: {
          setState(1396);
          match(SqlParsingParser::NOT);
          setState(1397);
          match(SqlParsingParser::INDEXED);
          break;
        }

        case SqlParsingParser::EOF:
        case SqlParsingParser::SCOL:
        case SqlParsingParser::CLOSE_PAR:
        case SqlParsingParser::COMMA:
        case SqlParsingParser::CROSS:
        case SqlParsingParser::EXCEPT:
        case SqlParsingParser::GROUP:
        case SqlParsingParser::INNER:
        case SqlParsingParser::INTERSECT:
        case SqlParsingParser::JOIN:
        case SqlParsingParser::LEFT:
        case SqlParsingParser::LIMIT:
        case SqlParsingParser::NATURAL:
        case SqlParsingParser::ON:
        case SqlParsingParser::ORDER:
        case SqlParsingParser::UNION:
        case SqlParsingParser::USING:
        case SqlParsingParser::WHERE:
        case SqlParsingParser::WINDOW: {
          break;
        }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1403);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 194, _ctx)) {
      case 1: {
        setState(1400);
        schema_name();
        setState(1401);
        match(SqlParsingParser::DOT);
        break;
      }

      }
      setState(1405);
      table_function_name();
      setState(1406);
      match(SqlParsingParser::OPEN_PAR);
      setState(1407);
      expr(0);
      setState(1412);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SqlParsingParser::COMMA) {
        setState(1408);
        match(SqlParsingParser::COMMA);
        setState(1409);
        expr(0);
        setState(1414);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1415);
      match(SqlParsingParser::CLOSE_PAR);
      setState(1420);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 197, _ctx)) {
      case 1: {
        setState(1417);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 196, _ctx)) {
        case 1: {
          setState(1416);
          match(SqlParsingParser::AS);
          break;
        }

        }
        setState(1419);
        table_alias();
        break;
      }

      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1422);
      match(SqlParsingParser::OPEN_PAR);
      setState(1432);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 199, _ctx)) {
      case 1: {
        setState(1423);
        table_or_subquery();
        setState(1428);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParsingParser::COMMA) {
          setState(1424);
          match(SqlParsingParser::COMMA);
          setState(1425);
          table_or_subquery();
          setState(1430);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case 2: {
        setState(1431);
        join_clause();
        break;
      }

      }
      setState(1434);
      match(SqlParsingParser::CLOSE_PAR);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1436);
      match(SqlParsingParser::OPEN_PAR);
      setState(1437);
      select_stmt();
      setState(1438);
      match(SqlParsingParser::CLOSE_PAR);
      setState(1443);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 201, _ctx)) {
      case 1: {
        setState(1440);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 200, _ctx)) {
        case 1: {
          setState(1439);
          match(SqlParsingParser::AS);
          break;
        }

        }
        setState(1442);
        table_alias();
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Result_columnContext ------------------------------------------------------------------

SqlParsingParser::Result_columnContext::Result_columnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Result_columnContext::STAR() {
  return getToken(SqlParsingParser::STAR, 0);
}

SqlParsingParser::Table_nameContext* SqlParsingParser::Result_columnContext::table_name() {
  return getRuleContext<SqlParsingParser::Table_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Result_columnContext::DOT() {
  return getToken(SqlParsingParser::DOT, 0);
}

SqlParsingParser::ExprContext* SqlParsingParser::Result_columnContext::expr() {
  return getRuleContext<SqlParsingParser::ExprContext>(0);
}

SqlParsingParser::Column_aliasContext* SqlParsingParser::Result_columnContext::column_alias() {
  return getRuleContext<SqlParsingParser::Column_aliasContext>(0);
}

tree::TerminalNode* SqlParsingParser::Result_columnContext::AS() {
  return getToken(SqlParsingParser::AS, 0);
}


size_t SqlParsingParser::Result_columnContext::getRuleIndex() const {
  return SqlParsingParser::RuleResult_column;
}

void SqlParsingParser::Result_columnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResult_column(this);
}

void SqlParsingParser::Result_columnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResult_column(this);
}


antlrcpp::Any SqlParsingParser::Result_columnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitResult_column(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Result_columnContext* SqlParsingParser::result_column() {
  Result_columnContext *_localctx = _tracker.createInstance<Result_columnContext>(_ctx, getState());
  enterRule(_localctx, 92, SqlParsingParser::RuleResult_column);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1459);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 205, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1447);
      match(SqlParsingParser::STAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1448);
      table_name();
      setState(1449);
      match(SqlParsingParser::DOT);
      setState(1450);
      match(SqlParsingParser::STAR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1452);
      expr(0);
      setState(1457);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SqlParsingParser::AS || _la == SqlParsingParser::IDENTIFIER

      || _la == SqlParsingParser::STRING_LITERAL) {
        setState(1454);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::AS) {
          setState(1453);
          match(SqlParsingParser::AS);
        }
        setState(1456);
        column_alias();
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Join_operatorContext ------------------------------------------------------------------

SqlParsingParser::Join_operatorContext::Join_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Join_operatorContext::COMMA() {
  return getToken(SqlParsingParser::COMMA, 0);
}

tree::TerminalNode* SqlParsingParser::Join_operatorContext::JOIN() {
  return getToken(SqlParsingParser::JOIN, 0);
}

tree::TerminalNode* SqlParsingParser::Join_operatorContext::NATURAL() {
  return getToken(SqlParsingParser::NATURAL, 0);
}

tree::TerminalNode* SqlParsingParser::Join_operatorContext::INNER() {
  return getToken(SqlParsingParser::INNER, 0);
}

tree::TerminalNode* SqlParsingParser::Join_operatorContext::CROSS() {
  return getToken(SqlParsingParser::CROSS, 0);
}

tree::TerminalNode* SqlParsingParser::Join_operatorContext::LEFT() {
  return getToken(SqlParsingParser::LEFT, 0);
}

tree::TerminalNode* SqlParsingParser::Join_operatorContext::OUTER() {
  return getToken(SqlParsingParser::OUTER, 0);
}


size_t SqlParsingParser::Join_operatorContext::getRuleIndex() const {
  return SqlParsingParser::RuleJoin_operator;
}

void SqlParsingParser::Join_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJoin_operator(this);
}

void SqlParsingParser::Join_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJoin_operator(this);
}


antlrcpp::Any SqlParsingParser::Join_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitJoin_operator(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Join_operatorContext* SqlParsingParser::join_operator() {
  Join_operatorContext *_localctx = _tracker.createInstance<Join_operatorContext>(_ctx, getState());
  enterRule(_localctx, 94, SqlParsingParser::RuleJoin_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1474);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(1461);
        match(SqlParsingParser::COMMA);
        break;
      }

      case SqlParsingParser::CROSS:
      case SqlParsingParser::INNER:
      case SqlParsingParser::JOIN:
      case SqlParsingParser::LEFT:
      case SqlParsingParser::NATURAL: {
        enterOuterAlt(_localctx, 2);
        setState(1463);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::NATURAL) {
          setState(1462);
          match(SqlParsingParser::NATURAL);
        }
        setState(1471);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case SqlParsingParser::LEFT: {
            setState(1465);
            match(SqlParsingParser::LEFT);
            setState(1467);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == SqlParsingParser::OUTER) {
              setState(1466);
              match(SqlParsingParser::OUTER);
            }
            break;
          }

          case SqlParsingParser::INNER: {
            setState(1469);
            match(SqlParsingParser::INNER);
            break;
          }

          case SqlParsingParser::CROSS: {
            setState(1470);
            match(SqlParsingParser::CROSS);
            break;
          }

          case SqlParsingParser::JOIN: {
            break;
          }

        default:
          break;
        }
        setState(1473);
        match(SqlParsingParser::JOIN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Join_constraintContext ------------------------------------------------------------------

SqlParsingParser::Join_constraintContext::Join_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Join_constraintContext::ON() {
  return getToken(SqlParsingParser::ON, 0);
}

SqlParsingParser::ExprContext* SqlParsingParser::Join_constraintContext::expr() {
  return getRuleContext<SqlParsingParser::ExprContext>(0);
}

tree::TerminalNode* SqlParsingParser::Join_constraintContext::USING() {
  return getToken(SqlParsingParser::USING, 0);
}

tree::TerminalNode* SqlParsingParser::Join_constraintContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

std::vector<SqlParsingParser::Column_nameContext *> SqlParsingParser::Join_constraintContext::column_name() {
  return getRuleContexts<SqlParsingParser::Column_nameContext>();
}

SqlParsingParser::Column_nameContext* SqlParsingParser::Join_constraintContext::column_name(size_t i) {
  return getRuleContext<SqlParsingParser::Column_nameContext>(i);
}

tree::TerminalNode* SqlParsingParser::Join_constraintContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Join_constraintContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Join_constraintContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}


size_t SqlParsingParser::Join_constraintContext::getRuleIndex() const {
  return SqlParsingParser::RuleJoin_constraint;
}

void SqlParsingParser::Join_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJoin_constraint(this);
}

void SqlParsingParser::Join_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJoin_constraint(this);
}


antlrcpp::Any SqlParsingParser::Join_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitJoin_constraint(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Join_constraintContext* SqlParsingParser::join_constraint() {
  Join_constraintContext *_localctx = _tracker.createInstance<Join_constraintContext>(_ctx, getState());
  enterRule(_localctx, 96, SqlParsingParser::RuleJoin_constraint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1490);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::ON: {
        enterOuterAlt(_localctx, 1);
        setState(1476);
        match(SqlParsingParser::ON);
        setState(1477);
        expr(0);
        break;
      }

      case SqlParsingParser::USING: {
        enterOuterAlt(_localctx, 2);
        setState(1478);
        match(SqlParsingParser::USING);
        setState(1479);
        match(SqlParsingParser::OPEN_PAR);
        setState(1480);
        column_name();
        setState(1485);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParsingParser::COMMA) {
          setState(1481);
          match(SqlParsingParser::COMMA);
          setState(1482);
          column_name();
          setState(1487);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1488);
        match(SqlParsingParser::CLOSE_PAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compound_operatorContext ------------------------------------------------------------------

SqlParsingParser::Compound_operatorContext::Compound_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Compound_operatorContext::UNION() {
  return getToken(SqlParsingParser::UNION, 0);
}

tree::TerminalNode* SqlParsingParser::Compound_operatorContext::ALL() {
  return getToken(SqlParsingParser::ALL, 0);
}

tree::TerminalNode* SqlParsingParser::Compound_operatorContext::INTERSECT() {
  return getToken(SqlParsingParser::INTERSECT, 0);
}

tree::TerminalNode* SqlParsingParser::Compound_operatorContext::EXCEPT() {
  return getToken(SqlParsingParser::EXCEPT, 0);
}


size_t SqlParsingParser::Compound_operatorContext::getRuleIndex() const {
  return SqlParsingParser::RuleCompound_operator;
}

void SqlParsingParser::Compound_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_operator(this);
}

void SqlParsingParser::Compound_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_operator(this);
}


antlrcpp::Any SqlParsingParser::Compound_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitCompound_operator(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Compound_operatorContext* SqlParsingParser::compound_operator() {
  Compound_operatorContext *_localctx = _tracker.createInstance<Compound_operatorContext>(_ctx, getState());
  enterRule(_localctx, 98, SqlParsingParser::RuleCompound_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1498);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::UNION: {
        enterOuterAlt(_localctx, 1);
        setState(1492);
        match(SqlParsingParser::UNION);
        setState(1494);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::ALL) {
          setState(1493);
          match(SqlParsingParser::ALL);
        }
        break;
      }

      case SqlParsingParser::INTERSECT: {
        enterOuterAlt(_localctx, 2);
        setState(1496);
        match(SqlParsingParser::INTERSECT);
        break;
      }

      case SqlParsingParser::EXCEPT: {
        enterOuterAlt(_localctx, 3);
        setState(1497);
        match(SqlParsingParser::EXCEPT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Update_stmtContext ------------------------------------------------------------------

SqlParsingParser::Update_stmtContext::Update_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Update_stmtContext::UPDATE() {
  return getToken(SqlParsingParser::UPDATE, 0);
}

SqlParsingParser::Qualified_table_nameContext* SqlParsingParser::Update_stmtContext::qualified_table_name() {
  return getRuleContext<SqlParsingParser::Qualified_table_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Update_stmtContext::SET() {
  return getToken(SqlParsingParser::SET, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Update_stmtContext::ASSIGN() {
  return getTokens(SqlParsingParser::ASSIGN);
}

tree::TerminalNode* SqlParsingParser::Update_stmtContext::ASSIGN(size_t i) {
  return getToken(SqlParsingParser::ASSIGN, i);
}

std::vector<SqlParsingParser::ExprContext *> SqlParsingParser::Update_stmtContext::expr() {
  return getRuleContexts<SqlParsingParser::ExprContext>();
}

SqlParsingParser::ExprContext* SqlParsingParser::Update_stmtContext::expr(size_t i) {
  return getRuleContext<SqlParsingParser::ExprContext>(i);
}

std::vector<SqlParsingParser::Column_nameContext *> SqlParsingParser::Update_stmtContext::column_name() {
  return getRuleContexts<SqlParsingParser::Column_nameContext>();
}

SqlParsingParser::Column_nameContext* SqlParsingParser::Update_stmtContext::column_name(size_t i) {
  return getRuleContext<SqlParsingParser::Column_nameContext>(i);
}

std::vector<SqlParsingParser::Column_name_listContext *> SqlParsingParser::Update_stmtContext::column_name_list() {
  return getRuleContexts<SqlParsingParser::Column_name_listContext>();
}

SqlParsingParser::Column_name_listContext* SqlParsingParser::Update_stmtContext::column_name_list(size_t i) {
  return getRuleContext<SqlParsingParser::Column_name_listContext>(i);
}

SqlParsingParser::With_clauseContext* SqlParsingParser::Update_stmtContext::with_clause() {
  return getRuleContext<SqlParsingParser::With_clauseContext>(0);
}

tree::TerminalNode* SqlParsingParser::Update_stmtContext::OR() {
  return getToken(SqlParsingParser::OR, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Update_stmtContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Update_stmtContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}

tree::TerminalNode* SqlParsingParser::Update_stmtContext::WHERE() {
  return getToken(SqlParsingParser::WHERE, 0);
}

tree::TerminalNode* SqlParsingParser::Update_stmtContext::ROLLBACK() {
  return getToken(SqlParsingParser::ROLLBACK, 0);
}

tree::TerminalNode* SqlParsingParser::Update_stmtContext::ABORT() {
  return getToken(SqlParsingParser::ABORT, 0);
}

tree::TerminalNode* SqlParsingParser::Update_stmtContext::REPLACE() {
  return getToken(SqlParsingParser::REPLACE, 0);
}

tree::TerminalNode* SqlParsingParser::Update_stmtContext::FAIL() {
  return getToken(SqlParsingParser::FAIL, 0);
}

tree::TerminalNode* SqlParsingParser::Update_stmtContext::IGNORE() {
  return getToken(SqlParsingParser::IGNORE, 0);
}


size_t SqlParsingParser::Update_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleUpdate_stmt;
}

void SqlParsingParser::Update_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUpdate_stmt(this);
}

void SqlParsingParser::Update_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUpdate_stmt(this);
}


antlrcpp::Any SqlParsingParser::Update_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitUpdate_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Update_stmtContext* SqlParsingParser::update_stmt() {
  Update_stmtContext *_localctx = _tracker.createInstance<Update_stmtContext>(_ctx, getState());
  enterRule(_localctx, 100, SqlParsingParser::RuleUpdate_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1501);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::WITH) {
      setState(1500);
      with_clause();
    }
    setState(1503);
    match(SqlParsingParser::UPDATE);
    setState(1506);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 215, _ctx)) {
    case 1: {
      setState(1504);
      match(SqlParsingParser::OR);
      setState(1505);
      _la = _input->LA(1);
      if (!(_la == SqlParsingParser::ABORT || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (SqlParsingParser::FAIL - 72))
        | (1ULL << (SqlParsingParser::IGNORE - 72))
        | (1ULL << (SqlParsingParser::REPLACE - 72))
        | (1ULL << (SqlParsingParser::ROLLBACK - 72)))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    }
    setState(1508);
    qualified_table_name();
    setState(1509);
    match(SqlParsingParser::SET);
    setState(1512);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 216, _ctx)) {
    case 1: {
      setState(1510);
      column_name();
      break;
    }

    case 2: {
      setState(1511);
      column_name_list();
      break;
    }

    }
    setState(1514);
    match(SqlParsingParser::ASSIGN);
    setState(1515);
    expr(0);
    setState(1526);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SqlParsingParser::COMMA) {
      setState(1516);
      match(SqlParsingParser::COMMA);
      setState(1519);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 217, _ctx)) {
      case 1: {
        setState(1517);
        column_name();
        break;
      }

      case 2: {
        setState(1518);
        column_name_list();
        break;
      }

      }
      setState(1521);
      match(SqlParsingParser::ASSIGN);
      setState(1522);
      expr(0);
      setState(1528);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1531);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::WHERE) {
      setState(1529);
      match(SqlParsingParser::WHERE);
      setState(1530);
      expr(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_name_listContext ------------------------------------------------------------------

SqlParsingParser::Column_name_listContext::Column_name_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Column_name_listContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

std::vector<SqlParsingParser::Column_nameContext *> SqlParsingParser::Column_name_listContext::column_name() {
  return getRuleContexts<SqlParsingParser::Column_nameContext>();
}

SqlParsingParser::Column_nameContext* SqlParsingParser::Column_name_listContext::column_name(size_t i) {
  return getRuleContext<SqlParsingParser::Column_nameContext>(i);
}

tree::TerminalNode* SqlParsingParser::Column_name_listContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Column_name_listContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Column_name_listContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}


size_t SqlParsingParser::Column_name_listContext::getRuleIndex() const {
  return SqlParsingParser::RuleColumn_name_list;
}

void SqlParsingParser::Column_name_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn_name_list(this);
}

void SqlParsingParser::Column_name_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn_name_list(this);
}


antlrcpp::Any SqlParsingParser::Column_name_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitColumn_name_list(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Column_name_listContext* SqlParsingParser::column_name_list() {
  Column_name_listContext *_localctx = _tracker.createInstance<Column_name_listContext>(_ctx, getState());
  enterRule(_localctx, 102, SqlParsingParser::RuleColumn_name_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1533);
    match(SqlParsingParser::OPEN_PAR);
    setState(1534);
    column_name();
    setState(1539);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SqlParsingParser::COMMA) {
      setState(1535);
      match(SqlParsingParser::COMMA);
      setState(1536);
      column_name();
      setState(1541);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1542);
    match(SqlParsingParser::CLOSE_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Update_stmt_limitedContext ------------------------------------------------------------------

SqlParsingParser::Update_stmt_limitedContext::Update_stmt_limitedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Update_stmt_limitedContext::UPDATE() {
  return getToken(SqlParsingParser::UPDATE, 0);
}

SqlParsingParser::Qualified_table_nameContext* SqlParsingParser::Update_stmt_limitedContext::qualified_table_name() {
  return getRuleContext<SqlParsingParser::Qualified_table_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Update_stmt_limitedContext::SET() {
  return getToken(SqlParsingParser::SET, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Update_stmt_limitedContext::ASSIGN() {
  return getTokens(SqlParsingParser::ASSIGN);
}

tree::TerminalNode* SqlParsingParser::Update_stmt_limitedContext::ASSIGN(size_t i) {
  return getToken(SqlParsingParser::ASSIGN, i);
}

std::vector<SqlParsingParser::ExprContext *> SqlParsingParser::Update_stmt_limitedContext::expr() {
  return getRuleContexts<SqlParsingParser::ExprContext>();
}

SqlParsingParser::ExprContext* SqlParsingParser::Update_stmt_limitedContext::expr(size_t i) {
  return getRuleContext<SqlParsingParser::ExprContext>(i);
}

std::vector<SqlParsingParser::Column_nameContext *> SqlParsingParser::Update_stmt_limitedContext::column_name() {
  return getRuleContexts<SqlParsingParser::Column_nameContext>();
}

SqlParsingParser::Column_nameContext* SqlParsingParser::Update_stmt_limitedContext::column_name(size_t i) {
  return getRuleContext<SqlParsingParser::Column_nameContext>(i);
}

std::vector<SqlParsingParser::Column_name_listContext *> SqlParsingParser::Update_stmt_limitedContext::column_name_list() {
  return getRuleContexts<SqlParsingParser::Column_name_listContext>();
}

SqlParsingParser::Column_name_listContext* SqlParsingParser::Update_stmt_limitedContext::column_name_list(size_t i) {
  return getRuleContext<SqlParsingParser::Column_name_listContext>(i);
}

SqlParsingParser::With_clauseContext* SqlParsingParser::Update_stmt_limitedContext::with_clause() {
  return getRuleContext<SqlParsingParser::With_clauseContext>(0);
}

tree::TerminalNode* SqlParsingParser::Update_stmt_limitedContext::OR() {
  return getToken(SqlParsingParser::OR, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Update_stmt_limitedContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Update_stmt_limitedContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}

tree::TerminalNode* SqlParsingParser::Update_stmt_limitedContext::WHERE() {
  return getToken(SqlParsingParser::WHERE, 0);
}

SqlParsingParser::Limit_stmtContext* SqlParsingParser::Update_stmt_limitedContext::limit_stmt() {
  return getRuleContext<SqlParsingParser::Limit_stmtContext>(0);
}

tree::TerminalNode* SqlParsingParser::Update_stmt_limitedContext::ROLLBACK() {
  return getToken(SqlParsingParser::ROLLBACK, 0);
}

tree::TerminalNode* SqlParsingParser::Update_stmt_limitedContext::ABORT() {
  return getToken(SqlParsingParser::ABORT, 0);
}

tree::TerminalNode* SqlParsingParser::Update_stmt_limitedContext::REPLACE() {
  return getToken(SqlParsingParser::REPLACE, 0);
}

tree::TerminalNode* SqlParsingParser::Update_stmt_limitedContext::FAIL() {
  return getToken(SqlParsingParser::FAIL, 0);
}

tree::TerminalNode* SqlParsingParser::Update_stmt_limitedContext::IGNORE() {
  return getToken(SqlParsingParser::IGNORE, 0);
}

SqlParsingParser::Order_by_stmtContext* SqlParsingParser::Update_stmt_limitedContext::order_by_stmt() {
  return getRuleContext<SqlParsingParser::Order_by_stmtContext>(0);
}


size_t SqlParsingParser::Update_stmt_limitedContext::getRuleIndex() const {
  return SqlParsingParser::RuleUpdate_stmt_limited;
}

void SqlParsingParser::Update_stmt_limitedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUpdate_stmt_limited(this);
}

void SqlParsingParser::Update_stmt_limitedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUpdate_stmt_limited(this);
}


antlrcpp::Any SqlParsingParser::Update_stmt_limitedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitUpdate_stmt_limited(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Update_stmt_limitedContext* SqlParsingParser::update_stmt_limited() {
  Update_stmt_limitedContext *_localctx = _tracker.createInstance<Update_stmt_limitedContext>(_ctx, getState());
  enterRule(_localctx, 104, SqlParsingParser::RuleUpdate_stmt_limited);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1545);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::WITH) {
      setState(1544);
      with_clause();
    }
    setState(1547);
    match(SqlParsingParser::UPDATE);
    setState(1550);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 222, _ctx)) {
    case 1: {
      setState(1548);
      match(SqlParsingParser::OR);
      setState(1549);
      _la = _input->LA(1);
      if (!(_la == SqlParsingParser::ABORT || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (SqlParsingParser::FAIL - 72))
        | (1ULL << (SqlParsingParser::IGNORE - 72))
        | (1ULL << (SqlParsingParser::REPLACE - 72))
        | (1ULL << (SqlParsingParser::ROLLBACK - 72)))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    }
    setState(1552);
    qualified_table_name();
    setState(1553);
    match(SqlParsingParser::SET);
    setState(1556);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 223, _ctx)) {
    case 1: {
      setState(1554);
      column_name();
      break;
    }

    case 2: {
      setState(1555);
      column_name_list();
      break;
    }

    }
    setState(1558);
    match(SqlParsingParser::ASSIGN);
    setState(1559);
    expr(0);
    setState(1570);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SqlParsingParser::COMMA) {
      setState(1560);
      match(SqlParsingParser::COMMA);
      setState(1563);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 224, _ctx)) {
      case 1: {
        setState(1561);
        column_name();
        break;
      }

      case 2: {
        setState(1562);
        column_name_list();
        break;
      }

      }
      setState(1565);
      match(SqlParsingParser::ASSIGN);
      setState(1566);
      expr(0);
      setState(1572);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1575);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::WHERE) {
      setState(1573);
      match(SqlParsingParser::WHERE);
      setState(1574);
      expr(0);
    }
    setState(1581);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::LIMIT

    || _la == SqlParsingParser::ORDER) {
      setState(1578);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SqlParsingParser::ORDER) {
        setState(1577);
        order_by_stmt();
      }
      setState(1580);
      limit_stmt();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Qualified_table_nameContext ------------------------------------------------------------------

SqlParsingParser::Qualified_table_nameContext::Qualified_table_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Table_nameContext* SqlParsingParser::Qualified_table_nameContext::table_name() {
  return getRuleContext<SqlParsingParser::Table_nameContext>(0);
}

SqlParsingParser::Schema_nameContext* SqlParsingParser::Qualified_table_nameContext::schema_name() {
  return getRuleContext<SqlParsingParser::Schema_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Qualified_table_nameContext::DOT() {
  return getToken(SqlParsingParser::DOT, 0);
}

tree::TerminalNode* SqlParsingParser::Qualified_table_nameContext::AS() {
  return getToken(SqlParsingParser::AS, 0);
}

SqlParsingParser::AliasContext* SqlParsingParser::Qualified_table_nameContext::alias() {
  return getRuleContext<SqlParsingParser::AliasContext>(0);
}

tree::TerminalNode* SqlParsingParser::Qualified_table_nameContext::INDEXED() {
  return getToken(SqlParsingParser::INDEXED, 0);
}

tree::TerminalNode* SqlParsingParser::Qualified_table_nameContext::BY() {
  return getToken(SqlParsingParser::BY, 0);
}

SqlParsingParser::Index_nameContext* SqlParsingParser::Qualified_table_nameContext::index_name() {
  return getRuleContext<SqlParsingParser::Index_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Qualified_table_nameContext::NOT() {
  return getToken(SqlParsingParser::NOT, 0);
}


size_t SqlParsingParser::Qualified_table_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleQualified_table_name;
}

void SqlParsingParser::Qualified_table_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualified_table_name(this);
}

void SqlParsingParser::Qualified_table_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualified_table_name(this);
}


antlrcpp::Any SqlParsingParser::Qualified_table_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitQualified_table_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Qualified_table_nameContext* SqlParsingParser::qualified_table_name() {
  Qualified_table_nameContext *_localctx = _tracker.createInstance<Qualified_table_nameContext>(_ctx, getState());
  enterRule(_localctx, 106, SqlParsingParser::RuleQualified_table_name);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1586);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 229, _ctx)) {
    case 1: {
      setState(1583);
      schema_name();
      setState(1584);
      match(SqlParsingParser::DOT);
      break;
    }

    }
    setState(1588);
    table_name();
    setState(1591);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::AS) {
      setState(1589);
      match(SqlParsingParser::AS);
      setState(1590);
      alias();
    }
    setState(1598);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::INDEXED: {
        setState(1593);
        match(SqlParsingParser::INDEXED);
        setState(1594);
        match(SqlParsingParser::BY);
        setState(1595);
        index_name();
        break;
      }

      case SqlParsingParser::NOT: {
        setState(1596);
        match(SqlParsingParser::NOT);
        setState(1597);
        match(SqlParsingParser::INDEXED);
        break;
      }

      case SqlParsingParser::EOF:
      case SqlParsingParser::SCOL:
      case SqlParsingParser::LIMIT:
      case SqlParsingParser::ORDER:
      case SqlParsingParser::SET:
      case SqlParsingParser::WHERE: {
        break;
      }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Vacuum_stmtContext ------------------------------------------------------------------

SqlParsingParser::Vacuum_stmtContext::Vacuum_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Vacuum_stmtContext::VACUUM() {
  return getToken(SqlParsingParser::VACUUM, 0);
}

SqlParsingParser::Schema_nameContext* SqlParsingParser::Vacuum_stmtContext::schema_name() {
  return getRuleContext<SqlParsingParser::Schema_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Vacuum_stmtContext::INTO() {
  return getToken(SqlParsingParser::INTO, 0);
}

SqlParsingParser::FilenameContext* SqlParsingParser::Vacuum_stmtContext::filename() {
  return getRuleContext<SqlParsingParser::FilenameContext>(0);
}


size_t SqlParsingParser::Vacuum_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleVacuum_stmt;
}

void SqlParsingParser::Vacuum_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVacuum_stmt(this);
}

void SqlParsingParser::Vacuum_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVacuum_stmt(this);
}


antlrcpp::Any SqlParsingParser::Vacuum_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitVacuum_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Vacuum_stmtContext* SqlParsingParser::vacuum_stmt() {
  Vacuum_stmtContext *_localctx = _tracker.createInstance<Vacuum_stmtContext>(_ctx, getState());
  enterRule(_localctx, 108, SqlParsingParser::RuleVacuum_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1600);
    match(SqlParsingParser::VACUUM);
    setState(1602);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 232, _ctx)) {
    case 1: {
      setState(1601);
      schema_name();
      break;
    }

    }
    setState(1606);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::INTO) {
      setState(1604);
      match(SqlParsingParser::INTO);
      setState(1605);
      filename();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Filter_clauseContext ------------------------------------------------------------------

SqlParsingParser::Filter_clauseContext::Filter_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Filter_clauseContext::FILTER() {
  return getToken(SqlParsingParser::FILTER, 0);
}

tree::TerminalNode* SqlParsingParser::Filter_clauseContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Filter_clauseContext::WHERE() {
  return getToken(SqlParsingParser::WHERE, 0);
}

SqlParsingParser::ExprContext* SqlParsingParser::Filter_clauseContext::expr() {
  return getRuleContext<SqlParsingParser::ExprContext>(0);
}

tree::TerminalNode* SqlParsingParser::Filter_clauseContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}


size_t SqlParsingParser::Filter_clauseContext::getRuleIndex() const {
  return SqlParsingParser::RuleFilter_clause;
}

void SqlParsingParser::Filter_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFilter_clause(this);
}

void SqlParsingParser::Filter_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFilter_clause(this);
}


antlrcpp::Any SqlParsingParser::Filter_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitFilter_clause(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Filter_clauseContext* SqlParsingParser::filter_clause() {
  Filter_clauseContext *_localctx = _tracker.createInstance<Filter_clauseContext>(_ctx, getState());
  enterRule(_localctx, 110, SqlParsingParser::RuleFilter_clause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1608);
    match(SqlParsingParser::FILTER);
    setState(1609);
    match(SqlParsingParser::OPEN_PAR);
    setState(1610);
    match(SqlParsingParser::WHERE);
    setState(1611);
    expr(0);
    setState(1612);
    match(SqlParsingParser::CLOSE_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Window_defnContext ------------------------------------------------------------------

SqlParsingParser::Window_defnContext::Window_defnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Window_defnContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Window_defnContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Window_defnContext::ORDER() {
  return getToken(SqlParsingParser::ORDER, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Window_defnContext::BY() {
  return getTokens(SqlParsingParser::BY);
}

tree::TerminalNode* SqlParsingParser::Window_defnContext::BY(size_t i) {
  return getToken(SqlParsingParser::BY, i);
}

std::vector<SqlParsingParser::Ordering_termContext *> SqlParsingParser::Window_defnContext::ordering_term() {
  return getRuleContexts<SqlParsingParser::Ordering_termContext>();
}

SqlParsingParser::Ordering_termContext* SqlParsingParser::Window_defnContext::ordering_term(size_t i) {
  return getRuleContext<SqlParsingParser::Ordering_termContext>(i);
}

SqlParsingParser::Base_window_nameContext* SqlParsingParser::Window_defnContext::base_window_name() {
  return getRuleContext<SqlParsingParser::Base_window_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Window_defnContext::PARTITION() {
  return getToken(SqlParsingParser::PARTITION, 0);
}

std::vector<SqlParsingParser::ExprContext *> SqlParsingParser::Window_defnContext::expr() {
  return getRuleContexts<SqlParsingParser::ExprContext>();
}

SqlParsingParser::ExprContext* SqlParsingParser::Window_defnContext::expr(size_t i) {
  return getRuleContext<SqlParsingParser::ExprContext>(i);
}

SqlParsingParser::Frame_specContext* SqlParsingParser::Window_defnContext::frame_spec() {
  return getRuleContext<SqlParsingParser::Frame_specContext>(0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Window_defnContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Window_defnContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}


size_t SqlParsingParser::Window_defnContext::getRuleIndex() const {
  return SqlParsingParser::RuleWindow_defn;
}

void SqlParsingParser::Window_defnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWindow_defn(this);
}

void SqlParsingParser::Window_defnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWindow_defn(this);
}


antlrcpp::Any SqlParsingParser::Window_defnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitWindow_defn(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Window_defnContext* SqlParsingParser::window_defn() {
  Window_defnContext *_localctx = _tracker.createInstance<Window_defnContext>(_ctx, getState());
  enterRule(_localctx, 112, SqlParsingParser::RuleWindow_defn);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1614);
    match(SqlParsingParser::OPEN_PAR);
    setState(1616);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 234, _ctx)) {
    case 1: {
      setState(1615);
      base_window_name();
      break;
    }

    }
    setState(1628);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::PARTITION) {
      setState(1618);
      match(SqlParsingParser::PARTITION);
      setState(1619);
      match(SqlParsingParser::BY);
      setState(1620);
      expr(0);
      setState(1625);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SqlParsingParser::COMMA) {
        setState(1621);
        match(SqlParsingParser::COMMA);
        setState(1622);
        expr(0);
        setState(1627);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }

    setState(1630);
    match(SqlParsingParser::ORDER);
    setState(1631);
    match(SqlParsingParser::BY);
    setState(1632);
    ordering_term();
    setState(1637);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SqlParsingParser::COMMA) {
      setState(1633);
      match(SqlParsingParser::COMMA);
      setState(1634);
      ordering_term();
      setState(1639);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1641);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 127) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 127)) & ((1ULL << (SqlParsingParser::ROWS - 127))
      | (1ULL << (SqlParsingParser::RANGE - 127))
      | (1ULL << (SqlParsingParser::GROUPS - 127)))) != 0)) {
      setState(1640);
      frame_spec();
    }
    setState(1643);
    match(SqlParsingParser::CLOSE_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Over_clauseContext ------------------------------------------------------------------

SqlParsingParser::Over_clauseContext::Over_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Over_clauseContext::OVER() {
  return getToken(SqlParsingParser::OVER, 0);
}

SqlParsingParser::Window_nameContext* SqlParsingParser::Over_clauseContext::window_name() {
  return getRuleContext<SqlParsingParser::Window_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Over_clauseContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Over_clauseContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

SqlParsingParser::Base_window_nameContext* SqlParsingParser::Over_clauseContext::base_window_name() {
  return getRuleContext<SqlParsingParser::Base_window_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Over_clauseContext::PARTITION() {
  return getToken(SqlParsingParser::PARTITION, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Over_clauseContext::BY() {
  return getTokens(SqlParsingParser::BY);
}

tree::TerminalNode* SqlParsingParser::Over_clauseContext::BY(size_t i) {
  return getToken(SqlParsingParser::BY, i);
}

std::vector<SqlParsingParser::ExprContext *> SqlParsingParser::Over_clauseContext::expr() {
  return getRuleContexts<SqlParsingParser::ExprContext>();
}

SqlParsingParser::ExprContext* SqlParsingParser::Over_clauseContext::expr(size_t i) {
  return getRuleContext<SqlParsingParser::ExprContext>(i);
}

tree::TerminalNode* SqlParsingParser::Over_clauseContext::ORDER() {
  return getToken(SqlParsingParser::ORDER, 0);
}

std::vector<SqlParsingParser::Ordering_termContext *> SqlParsingParser::Over_clauseContext::ordering_term() {
  return getRuleContexts<SqlParsingParser::Ordering_termContext>();
}

SqlParsingParser::Ordering_termContext* SqlParsingParser::Over_clauseContext::ordering_term(size_t i) {
  return getRuleContext<SqlParsingParser::Ordering_termContext>(i);
}

SqlParsingParser::Frame_specContext* SqlParsingParser::Over_clauseContext::frame_spec() {
  return getRuleContext<SqlParsingParser::Frame_specContext>(0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Over_clauseContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Over_clauseContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}


size_t SqlParsingParser::Over_clauseContext::getRuleIndex() const {
  return SqlParsingParser::RuleOver_clause;
}

void SqlParsingParser::Over_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOver_clause(this);
}

void SqlParsingParser::Over_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOver_clause(this);
}


antlrcpp::Any SqlParsingParser::Over_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitOver_clause(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Over_clauseContext* SqlParsingParser::over_clause() {
  Over_clauseContext *_localctx = _tracker.createInstance<Over_clauseContext>(_ctx, getState());
  enterRule(_localctx, 114, SqlParsingParser::RuleOver_clause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1645);
    match(SqlParsingParser::OVER);
    setState(1679);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 245, _ctx)) {
    case 1: {
      setState(1646);
      window_name();
      break;
    }

    case 2: {
      setState(1647);
      match(SqlParsingParser::OPEN_PAR);
      setState(1649);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 239, _ctx)) {
      case 1: {
        setState(1648);
        base_window_name();
        break;
      }

      }
      setState(1661);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SqlParsingParser::PARTITION) {
        setState(1651);
        match(SqlParsingParser::PARTITION);
        setState(1652);
        match(SqlParsingParser::BY);
        setState(1653);
        expr(0);
        setState(1658);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParsingParser::COMMA) {
          setState(1654);
          match(SqlParsingParser::COMMA);
          setState(1655);
          expr(0);
          setState(1660);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(1673);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SqlParsingParser::ORDER) {
        setState(1663);
        match(SqlParsingParser::ORDER);
        setState(1664);
        match(SqlParsingParser::BY);
        setState(1665);
        ordering_term();
        setState(1670);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParsingParser::COMMA) {
          setState(1666);
          match(SqlParsingParser::COMMA);
          setState(1667);
          ordering_term();
          setState(1672);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(1676);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 127) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 127)) & ((1ULL << (SqlParsingParser::ROWS - 127))
        | (1ULL << (SqlParsingParser::RANGE - 127))
        | (1ULL << (SqlParsingParser::GROUPS - 127)))) != 0)) {
        setState(1675);
        frame_spec();
      }
      setState(1678);
      match(SqlParsingParser::CLOSE_PAR);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Frame_specContext ------------------------------------------------------------------

SqlParsingParser::Frame_specContext::Frame_specContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Frame_clauseContext* SqlParsingParser::Frame_specContext::frame_clause() {
  return getRuleContext<SqlParsingParser::Frame_clauseContext>(0);
}

tree::TerminalNode* SqlParsingParser::Frame_specContext::EXCLUDE() {
  return getToken(SqlParsingParser::EXCLUDE, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_specContext::GROUP() {
  return getToken(SqlParsingParser::GROUP, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_specContext::TIES() {
  return getToken(SqlParsingParser::TIES, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_specContext::NO() {
  return getToken(SqlParsingParser::NO, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_specContext::OTHERS() {
  return getToken(SqlParsingParser::OTHERS, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_specContext::CURRENT() {
  return getToken(SqlParsingParser::CURRENT, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_specContext::ROW() {
  return getToken(SqlParsingParser::ROW, 0);
}


size_t SqlParsingParser::Frame_specContext::getRuleIndex() const {
  return SqlParsingParser::RuleFrame_spec;
}

void SqlParsingParser::Frame_specContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFrame_spec(this);
}

void SqlParsingParser::Frame_specContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFrame_spec(this);
}


antlrcpp::Any SqlParsingParser::Frame_specContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitFrame_spec(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Frame_specContext* SqlParsingParser::frame_spec() {
  Frame_specContext *_localctx = _tracker.createInstance<Frame_specContext>(_ctx, getState());
  enterRule(_localctx, 116, SqlParsingParser::RuleFrame_spec);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1681);
    frame_clause();
    setState(1689);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::EXCLUDE: {
        setState(1682);
        match(SqlParsingParser::EXCLUDE);

        setState(1683);
        match(SqlParsingParser::NO);
        setState(1684);
        match(SqlParsingParser::OTHERS);
        break;
      }

      case SqlParsingParser::CURRENT: {
        setState(1685);
        match(SqlParsingParser::CURRENT);
        setState(1686);
        match(SqlParsingParser::ROW);
        break;
      }

      case SqlParsingParser::GROUP: {
        setState(1687);
        match(SqlParsingParser::GROUP);
        break;
      }

      case SqlParsingParser::TIES: {
        setState(1688);
        match(SqlParsingParser::TIES);
        break;
      }

      case SqlParsingParser::CLOSE_PAR: {
        break;
      }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Frame_clauseContext ------------------------------------------------------------------

SqlParsingParser::Frame_clauseContext::Frame_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Frame_clauseContext::RANGE() {
  return getToken(SqlParsingParser::RANGE, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_clauseContext::ROWS() {
  return getToken(SqlParsingParser::ROWS, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_clauseContext::GROUPS() {
  return getToken(SqlParsingParser::GROUPS, 0);
}

SqlParsingParser::Frame_singleContext* SqlParsingParser::Frame_clauseContext::frame_single() {
  return getRuleContext<SqlParsingParser::Frame_singleContext>(0);
}

tree::TerminalNode* SqlParsingParser::Frame_clauseContext::BETWEEN() {
  return getToken(SqlParsingParser::BETWEEN, 0);
}

SqlParsingParser::Frame_leftContext* SqlParsingParser::Frame_clauseContext::frame_left() {
  return getRuleContext<SqlParsingParser::Frame_leftContext>(0);
}

tree::TerminalNode* SqlParsingParser::Frame_clauseContext::AND() {
  return getToken(SqlParsingParser::AND, 0);
}

SqlParsingParser::Frame_rightContext* SqlParsingParser::Frame_clauseContext::frame_right() {
  return getRuleContext<SqlParsingParser::Frame_rightContext>(0);
}


size_t SqlParsingParser::Frame_clauseContext::getRuleIndex() const {
  return SqlParsingParser::RuleFrame_clause;
}

void SqlParsingParser::Frame_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFrame_clause(this);
}

void SqlParsingParser::Frame_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFrame_clause(this);
}


antlrcpp::Any SqlParsingParser::Frame_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitFrame_clause(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Frame_clauseContext* SqlParsingParser::frame_clause() {
  Frame_clauseContext *_localctx = _tracker.createInstance<Frame_clauseContext>(_ctx, getState());
  enterRule(_localctx, 118, SqlParsingParser::RuleFrame_clause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1691);
    _la = _input->LA(1);
    if (!(((((_la - 127) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 127)) & ((1ULL << (SqlParsingParser::ROWS - 127))
      | (1ULL << (SqlParsingParser::RANGE - 127))
      | (1ULL << (SqlParsingParser::GROUPS - 127)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(1698);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 247, _ctx)) {
    case 1: {
      setState(1692);
      frame_single();
      break;
    }

    case 2: {
      setState(1693);
      match(SqlParsingParser::BETWEEN);
      setState(1694);
      frame_left();
      setState(1695);
      match(SqlParsingParser::AND);
      setState(1696);
      frame_right();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_function_invocationContext ------------------------------------------------------------------

SqlParsingParser::Simple_function_invocationContext::Simple_function_invocationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Simple_funcContext* SqlParsingParser::Simple_function_invocationContext::simple_func() {
  return getRuleContext<SqlParsingParser::Simple_funcContext>(0);
}

tree::TerminalNode* SqlParsingParser::Simple_function_invocationContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Simple_function_invocationContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Simple_function_invocationContext::STAR() {
  return getToken(SqlParsingParser::STAR, 0);
}

std::vector<SqlParsingParser::ExprContext *> SqlParsingParser::Simple_function_invocationContext::expr() {
  return getRuleContexts<SqlParsingParser::ExprContext>();
}

SqlParsingParser::ExprContext* SqlParsingParser::Simple_function_invocationContext::expr(size_t i) {
  return getRuleContext<SqlParsingParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Simple_function_invocationContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Simple_function_invocationContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}


size_t SqlParsingParser::Simple_function_invocationContext::getRuleIndex() const {
  return SqlParsingParser::RuleSimple_function_invocation;
}

void SqlParsingParser::Simple_function_invocationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_function_invocation(this);
}

void SqlParsingParser::Simple_function_invocationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_function_invocation(this);
}


antlrcpp::Any SqlParsingParser::Simple_function_invocationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitSimple_function_invocation(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Simple_function_invocationContext* SqlParsingParser::simple_function_invocation() {
  Simple_function_invocationContext *_localctx = _tracker.createInstance<Simple_function_invocationContext>(_ctx, getState());
  enterRule(_localctx, 120, SqlParsingParser::RuleSimple_function_invocation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1700);
    simple_func();
    setState(1701);
    match(SqlParsingParser::OPEN_PAR);
    setState(1711);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::OPEN_PAR:
      case SqlParsingParser::PLUS:
      case SqlParsingParser::MINUS:
      case SqlParsingParser::TILDE:
      case SqlParsingParser::ABORT:
      case SqlParsingParser::ACTION:
      case SqlParsingParser::ADD:
      case SqlParsingParser::AFTER:
      case SqlParsingParser::ALL:
      case SqlParsingParser::ALTER:
      case SqlParsingParser::ANALYZE:
      case SqlParsingParser::AND:
      case SqlParsingParser::AS:
      case SqlParsingParser::ASC:
      case SqlParsingParser::ATTACH:
      case SqlParsingParser::AUTOINCREMENT:
      case SqlParsingParser::BEFORE:
      case SqlParsingParser::BEGIN:
      case SqlParsingParser::BETWEEN:
      case SqlParsingParser::BY:
      case SqlParsingParser::CASCADE:
      case SqlParsingParser::CASE:
      case SqlParsingParser::CAST:
      case SqlParsingParser::CHECK:
      case SqlParsingParser::COLLATE:
      case SqlParsingParser::COLUMN:
      case SqlParsingParser::COMMIT:
      case SqlParsingParser::CONFLICT:
      case SqlParsingParser::CONSTRAINT:
      case SqlParsingParser::CREATE:
      case SqlParsingParser::CROSS:
      case SqlParsingParser::CURRENT_DATE:
      case SqlParsingParser::CURRENT_TIME:
      case SqlParsingParser::CURRENT_TIMESTAMP:
      case SqlParsingParser::DATABASE:
      case SqlParsingParser::DEFAULT:
      case SqlParsingParser::DEFERRABLE:
      case SqlParsingParser::DEFERRED:
      case SqlParsingParser::DELETE:
      case SqlParsingParser::DESC:
      case SqlParsingParser::DETACH:
      case SqlParsingParser::DISTINCT:
      case SqlParsingParser::DROP:
      case SqlParsingParser::EACH:
      case SqlParsingParser::ELSE:
      case SqlParsingParser::END:
      case SqlParsingParser::ESCAPE:
      case SqlParsingParser::EXCEPT:
      case SqlParsingParser::EXCLUSIVE:
      case SqlParsingParser::EXISTS:
      case SqlParsingParser::EXPLAIN:
      case SqlParsingParser::FAIL:
      case SqlParsingParser::FOR:
      case SqlParsingParser::FOREIGN:
      case SqlParsingParser::FROM:
      case SqlParsingParser::FULL:
      case SqlParsingParser::GLOB:
      case SqlParsingParser::GROUP:
      case SqlParsingParser::HAVING:
      case SqlParsingParser::IF:
      case SqlParsingParser::IGNORE:
      case SqlParsingParser::IMMEDIATE:
      case SqlParsingParser::IN:
      case SqlParsingParser::INDEX:
      case SqlParsingParser::INDEXED:
      case SqlParsingParser::INITIALLY:
      case SqlParsingParser::INNER:
      case SqlParsingParser::INSERT:
      case SqlParsingParser::INSTEAD:
      case SqlParsingParser::INTERSECT:
      case SqlParsingParser::INTO:
      case SqlParsingParser::IS:
      case SqlParsingParser::ISNULL:
      case SqlParsingParser::JOIN:
      case SqlParsingParser::KEY:
      case SqlParsingParser::LEFT:
      case SqlParsingParser::LIKE:
      case SqlParsingParser::LIMIT:
      case SqlParsingParser::MATCH:
      case SqlParsingParser::NATURAL:
      case SqlParsingParser::NO:
      case SqlParsingParser::NOT:
      case SqlParsingParser::NOTNULL:
      case SqlParsingParser::NULL_:
      case SqlParsingParser::OF:
      case SqlParsingParser::OFFSET:
      case SqlParsingParser::ON:
      case SqlParsingParser::OR:
      case SqlParsingParser::ORDER:
      case SqlParsingParser::OUTER:
      case SqlParsingParser::PLAN:
      case SqlParsingParser::PRAGMA:
      case SqlParsingParser::PRIMARY:
      case SqlParsingParser::QUERY:
      case SqlParsingParser::RAISE:
      case SqlParsingParser::RECURSIVE:
      case SqlParsingParser::REFERENCES:
      case SqlParsingParser::REGEXP:
      case SqlParsingParser::REINDEX:
      case SqlParsingParser::RELEASE:
      case SqlParsingParser::RENAME:
      case SqlParsingParser::REPLACE:
      case SqlParsingParser::RESTRICT:
      case SqlParsingParser::RIGHT:
      case SqlParsingParser::ROLLBACK:
      case SqlParsingParser::ROW:
      case SqlParsingParser::ROWS:
      case SqlParsingParser::SAVEPOINT:
      case SqlParsingParser::SELECT:
      case SqlParsingParser::SET:
      case SqlParsingParser::TABLE:
      case SqlParsingParser::TEMP:
      case SqlParsingParser::TEMPORARY:
      case SqlParsingParser::THEN:
      case SqlParsingParser::TO:
      case SqlParsingParser::TRANSACTION:
      case SqlParsingParser::TRIGGER:
      case SqlParsingParser::UNION:
      case SqlParsingParser::UNIQUE:
      case SqlParsingParser::UPDATE:
      case SqlParsingParser::USING:
      case SqlParsingParser::VACUUM:
      case SqlParsingParser::VALUES:
      case SqlParsingParser::VIEW:
      case SqlParsingParser::VIRTUAL:
      case SqlParsingParser::WHEN:
      case SqlParsingParser::WHERE:
      case SqlParsingParser::WITH:
      case SqlParsingParser::WITHOUT:
      case SqlParsingParser::FIRST_VALUE:
      case SqlParsingParser::OVER:
      case SqlParsingParser::PARTITION:
      case SqlParsingParser::RANGE:
      case SqlParsingParser::PRECEDING:
      case SqlParsingParser::UNBOUNDED:
      case SqlParsingParser::CURRENT:
      case SqlParsingParser::FOLLOWING:
      case SqlParsingParser::CUME_DIST:
      case SqlParsingParser::DENSE_RANK:
      case SqlParsingParser::LAG:
      case SqlParsingParser::LAST_VALUE:
      case SqlParsingParser::LEAD:
      case SqlParsingParser::NTH_VALUE:
      case SqlParsingParser::NTILE:
      case SqlParsingParser::PERCENT_RANK:
      case SqlParsingParser::RANK:
      case SqlParsingParser::ROW_NUMBER:
      case SqlParsingParser::GENERATED:
      case SqlParsingParser::ALWAYS:
      case SqlParsingParser::STORED:
      case SqlParsingParser::TRUE_:
      case SqlParsingParser::FALSE_:
      case SqlParsingParser::WINDOW:
      case SqlParsingParser::NULLS:
      case SqlParsingParser::FIRST:
      case SqlParsingParser::LAST:
      case SqlParsingParser::FILTER:
      case SqlParsingParser::GROUPS:
      case SqlParsingParser::EXCLUDE:
      case SqlParsingParser::IDENTIFIER:
      case SqlParsingParser::NUMERIC_LITERAL:
      case SqlParsingParser::BIND_PARAMETER:
      case SqlParsingParser::STRING_LITERAL:
      case SqlParsingParser::BLOB_LITERAL: {
        setState(1702);
        expr(0);
        setState(1707);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParsingParser::COMMA) {
          setState(1703);
          match(SqlParsingParser::COMMA);
          setState(1704);
          expr(0);
          setState(1709);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case SqlParsingParser::STAR: {
        setState(1710);
        match(SqlParsingParser::STAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(1713);
    match(SqlParsingParser::CLOSE_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Aggregate_function_invocationContext ------------------------------------------------------------------

SqlParsingParser::Aggregate_function_invocationContext::Aggregate_function_invocationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Aggregate_funcContext* SqlParsingParser::Aggregate_function_invocationContext::aggregate_func() {
  return getRuleContext<SqlParsingParser::Aggregate_funcContext>(0);
}

tree::TerminalNode* SqlParsingParser::Aggregate_function_invocationContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Aggregate_function_invocationContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Aggregate_function_invocationContext::STAR() {
  return getToken(SqlParsingParser::STAR, 0);
}

SqlParsingParser::Filter_clauseContext* SqlParsingParser::Aggregate_function_invocationContext::filter_clause() {
  return getRuleContext<SqlParsingParser::Filter_clauseContext>(0);
}

std::vector<SqlParsingParser::ExprContext *> SqlParsingParser::Aggregate_function_invocationContext::expr() {
  return getRuleContexts<SqlParsingParser::ExprContext>();
}

SqlParsingParser::ExprContext* SqlParsingParser::Aggregate_function_invocationContext::expr(size_t i) {
  return getRuleContext<SqlParsingParser::ExprContext>(i);
}

tree::TerminalNode* SqlParsingParser::Aggregate_function_invocationContext::DISTINCT() {
  return getToken(SqlParsingParser::DISTINCT, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Aggregate_function_invocationContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Aggregate_function_invocationContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}


size_t SqlParsingParser::Aggregate_function_invocationContext::getRuleIndex() const {
  return SqlParsingParser::RuleAggregate_function_invocation;
}

void SqlParsingParser::Aggregate_function_invocationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAggregate_function_invocation(this);
}

void SqlParsingParser::Aggregate_function_invocationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAggregate_function_invocation(this);
}


antlrcpp::Any SqlParsingParser::Aggregate_function_invocationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitAggregate_function_invocation(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Aggregate_function_invocationContext* SqlParsingParser::aggregate_function_invocation() {
  Aggregate_function_invocationContext *_localctx = _tracker.createInstance<Aggregate_function_invocationContext>(_ctx, getState());
  enterRule(_localctx, 122, SqlParsingParser::RuleAggregate_function_invocation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1715);
    aggregate_func();
    setState(1716);
    match(SqlParsingParser::OPEN_PAR);
    setState(1729);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::OPEN_PAR:
      case SqlParsingParser::PLUS:
      case SqlParsingParser::MINUS:
      case SqlParsingParser::TILDE:
      case SqlParsingParser::ABORT:
      case SqlParsingParser::ACTION:
      case SqlParsingParser::ADD:
      case SqlParsingParser::AFTER:
      case SqlParsingParser::ALL:
      case SqlParsingParser::ALTER:
      case SqlParsingParser::ANALYZE:
      case SqlParsingParser::AND:
      case SqlParsingParser::AS:
      case SqlParsingParser::ASC:
      case SqlParsingParser::ATTACH:
      case SqlParsingParser::AUTOINCREMENT:
      case SqlParsingParser::BEFORE:
      case SqlParsingParser::BEGIN:
      case SqlParsingParser::BETWEEN:
      case SqlParsingParser::BY:
      case SqlParsingParser::CASCADE:
      case SqlParsingParser::CASE:
      case SqlParsingParser::CAST:
      case SqlParsingParser::CHECK:
      case SqlParsingParser::COLLATE:
      case SqlParsingParser::COLUMN:
      case SqlParsingParser::COMMIT:
      case SqlParsingParser::CONFLICT:
      case SqlParsingParser::CONSTRAINT:
      case SqlParsingParser::CREATE:
      case SqlParsingParser::CROSS:
      case SqlParsingParser::CURRENT_DATE:
      case SqlParsingParser::CURRENT_TIME:
      case SqlParsingParser::CURRENT_TIMESTAMP:
      case SqlParsingParser::DATABASE:
      case SqlParsingParser::DEFAULT:
      case SqlParsingParser::DEFERRABLE:
      case SqlParsingParser::DEFERRED:
      case SqlParsingParser::DELETE:
      case SqlParsingParser::DESC:
      case SqlParsingParser::DETACH:
      case SqlParsingParser::DISTINCT:
      case SqlParsingParser::DROP:
      case SqlParsingParser::EACH:
      case SqlParsingParser::ELSE:
      case SqlParsingParser::END:
      case SqlParsingParser::ESCAPE:
      case SqlParsingParser::EXCEPT:
      case SqlParsingParser::EXCLUSIVE:
      case SqlParsingParser::EXISTS:
      case SqlParsingParser::EXPLAIN:
      case SqlParsingParser::FAIL:
      case SqlParsingParser::FOR:
      case SqlParsingParser::FOREIGN:
      case SqlParsingParser::FROM:
      case SqlParsingParser::FULL:
      case SqlParsingParser::GLOB:
      case SqlParsingParser::GROUP:
      case SqlParsingParser::HAVING:
      case SqlParsingParser::IF:
      case SqlParsingParser::IGNORE:
      case SqlParsingParser::IMMEDIATE:
      case SqlParsingParser::IN:
      case SqlParsingParser::INDEX:
      case SqlParsingParser::INDEXED:
      case SqlParsingParser::INITIALLY:
      case SqlParsingParser::INNER:
      case SqlParsingParser::INSERT:
      case SqlParsingParser::INSTEAD:
      case SqlParsingParser::INTERSECT:
      case SqlParsingParser::INTO:
      case SqlParsingParser::IS:
      case SqlParsingParser::ISNULL:
      case SqlParsingParser::JOIN:
      case SqlParsingParser::KEY:
      case SqlParsingParser::LEFT:
      case SqlParsingParser::LIKE:
      case SqlParsingParser::LIMIT:
      case SqlParsingParser::MATCH:
      case SqlParsingParser::NATURAL:
      case SqlParsingParser::NO:
      case SqlParsingParser::NOT:
      case SqlParsingParser::NOTNULL:
      case SqlParsingParser::NULL_:
      case SqlParsingParser::OF:
      case SqlParsingParser::OFFSET:
      case SqlParsingParser::ON:
      case SqlParsingParser::OR:
      case SqlParsingParser::ORDER:
      case SqlParsingParser::OUTER:
      case SqlParsingParser::PLAN:
      case SqlParsingParser::PRAGMA:
      case SqlParsingParser::PRIMARY:
      case SqlParsingParser::QUERY:
      case SqlParsingParser::RAISE:
      case SqlParsingParser::RECURSIVE:
      case SqlParsingParser::REFERENCES:
      case SqlParsingParser::REGEXP:
      case SqlParsingParser::REINDEX:
      case SqlParsingParser::RELEASE:
      case SqlParsingParser::RENAME:
      case SqlParsingParser::REPLACE:
      case SqlParsingParser::RESTRICT:
      case SqlParsingParser::RIGHT:
      case SqlParsingParser::ROLLBACK:
      case SqlParsingParser::ROW:
      case SqlParsingParser::ROWS:
      case SqlParsingParser::SAVEPOINT:
      case SqlParsingParser::SELECT:
      case SqlParsingParser::SET:
      case SqlParsingParser::TABLE:
      case SqlParsingParser::TEMP:
      case SqlParsingParser::TEMPORARY:
      case SqlParsingParser::THEN:
      case SqlParsingParser::TO:
      case SqlParsingParser::TRANSACTION:
      case SqlParsingParser::TRIGGER:
      case SqlParsingParser::UNION:
      case SqlParsingParser::UNIQUE:
      case SqlParsingParser::UPDATE:
      case SqlParsingParser::USING:
      case SqlParsingParser::VACUUM:
      case SqlParsingParser::VALUES:
      case SqlParsingParser::VIEW:
      case SqlParsingParser::VIRTUAL:
      case SqlParsingParser::WHEN:
      case SqlParsingParser::WHERE:
      case SqlParsingParser::WITH:
      case SqlParsingParser::WITHOUT:
      case SqlParsingParser::FIRST_VALUE:
      case SqlParsingParser::OVER:
      case SqlParsingParser::PARTITION:
      case SqlParsingParser::RANGE:
      case SqlParsingParser::PRECEDING:
      case SqlParsingParser::UNBOUNDED:
      case SqlParsingParser::CURRENT:
      case SqlParsingParser::FOLLOWING:
      case SqlParsingParser::CUME_DIST:
      case SqlParsingParser::DENSE_RANK:
      case SqlParsingParser::LAG:
      case SqlParsingParser::LAST_VALUE:
      case SqlParsingParser::LEAD:
      case SqlParsingParser::NTH_VALUE:
      case SqlParsingParser::NTILE:
      case SqlParsingParser::PERCENT_RANK:
      case SqlParsingParser::RANK:
      case SqlParsingParser::ROW_NUMBER:
      case SqlParsingParser::GENERATED:
      case SqlParsingParser::ALWAYS:
      case SqlParsingParser::STORED:
      case SqlParsingParser::TRUE_:
      case SqlParsingParser::FALSE_:
      case SqlParsingParser::WINDOW:
      case SqlParsingParser::NULLS:
      case SqlParsingParser::FIRST:
      case SqlParsingParser::LAST:
      case SqlParsingParser::FILTER:
      case SqlParsingParser::GROUPS:
      case SqlParsingParser::EXCLUDE:
      case SqlParsingParser::IDENTIFIER:
      case SqlParsingParser::NUMERIC_LITERAL:
      case SqlParsingParser::BIND_PARAMETER:
      case SqlParsingParser::STRING_LITERAL:
      case SqlParsingParser::BLOB_LITERAL: {
        setState(1718);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 250, _ctx)) {
        case 1: {
          setState(1717);
          match(SqlParsingParser::DISTINCT);
          break;
        }

        }
        setState(1720);
        expr(0);
        setState(1725);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParsingParser::COMMA) {
          setState(1721);
          match(SqlParsingParser::COMMA);
          setState(1722);
          expr(0);
          setState(1727);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case SqlParsingParser::STAR: {
        setState(1728);
        match(SqlParsingParser::STAR);
        break;
      }

      case SqlParsingParser::CLOSE_PAR: {
        break;
      }

    default:
      break;
    }
    setState(1731);
    match(SqlParsingParser::CLOSE_PAR);
    setState(1733);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::FILTER) {
      setState(1732);
      filter_clause();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Window_function_invocationContext ------------------------------------------------------------------

SqlParsingParser::Window_function_invocationContext::Window_function_invocationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Window_functionContext* SqlParsingParser::Window_function_invocationContext::window_function() {
  return getRuleContext<SqlParsingParser::Window_functionContext>(0);
}

tree::TerminalNode* SqlParsingParser::Window_function_invocationContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Window_function_invocationContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}

tree::TerminalNode* SqlParsingParser::Window_function_invocationContext::OVER() {
  return getToken(SqlParsingParser::OVER, 0);
}

SqlParsingParser::Window_defnContext* SqlParsingParser::Window_function_invocationContext::window_defn() {
  return getRuleContext<SqlParsingParser::Window_defnContext>(0);
}

SqlParsingParser::Window_nameContext* SqlParsingParser::Window_function_invocationContext::window_name() {
  return getRuleContext<SqlParsingParser::Window_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Window_function_invocationContext::STAR() {
  return getToken(SqlParsingParser::STAR, 0);
}

SqlParsingParser::Filter_clauseContext* SqlParsingParser::Window_function_invocationContext::filter_clause() {
  return getRuleContext<SqlParsingParser::Filter_clauseContext>(0);
}

std::vector<SqlParsingParser::ExprContext *> SqlParsingParser::Window_function_invocationContext::expr() {
  return getRuleContexts<SqlParsingParser::ExprContext>();
}

SqlParsingParser::ExprContext* SqlParsingParser::Window_function_invocationContext::expr(size_t i) {
  return getRuleContext<SqlParsingParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Window_function_invocationContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Window_function_invocationContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}


size_t SqlParsingParser::Window_function_invocationContext::getRuleIndex() const {
  return SqlParsingParser::RuleWindow_function_invocation;
}

void SqlParsingParser::Window_function_invocationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWindow_function_invocation(this);
}

void SqlParsingParser::Window_function_invocationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWindow_function_invocation(this);
}


antlrcpp::Any SqlParsingParser::Window_function_invocationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitWindow_function_invocation(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Window_function_invocationContext* SqlParsingParser::window_function_invocation() {
  Window_function_invocationContext *_localctx = _tracker.createInstance<Window_function_invocationContext>(_ctx, getState());
  enterRule(_localctx, 124, SqlParsingParser::RuleWindow_function_invocation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1735);
    window_function();
    setState(1736);
    match(SqlParsingParser::OPEN_PAR);
    setState(1746);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::OPEN_PAR:
      case SqlParsingParser::PLUS:
      case SqlParsingParser::MINUS:
      case SqlParsingParser::TILDE:
      case SqlParsingParser::ABORT:
      case SqlParsingParser::ACTION:
      case SqlParsingParser::ADD:
      case SqlParsingParser::AFTER:
      case SqlParsingParser::ALL:
      case SqlParsingParser::ALTER:
      case SqlParsingParser::ANALYZE:
      case SqlParsingParser::AND:
      case SqlParsingParser::AS:
      case SqlParsingParser::ASC:
      case SqlParsingParser::ATTACH:
      case SqlParsingParser::AUTOINCREMENT:
      case SqlParsingParser::BEFORE:
      case SqlParsingParser::BEGIN:
      case SqlParsingParser::BETWEEN:
      case SqlParsingParser::BY:
      case SqlParsingParser::CASCADE:
      case SqlParsingParser::CASE:
      case SqlParsingParser::CAST:
      case SqlParsingParser::CHECK:
      case SqlParsingParser::COLLATE:
      case SqlParsingParser::COLUMN:
      case SqlParsingParser::COMMIT:
      case SqlParsingParser::CONFLICT:
      case SqlParsingParser::CONSTRAINT:
      case SqlParsingParser::CREATE:
      case SqlParsingParser::CROSS:
      case SqlParsingParser::CURRENT_DATE:
      case SqlParsingParser::CURRENT_TIME:
      case SqlParsingParser::CURRENT_TIMESTAMP:
      case SqlParsingParser::DATABASE:
      case SqlParsingParser::DEFAULT:
      case SqlParsingParser::DEFERRABLE:
      case SqlParsingParser::DEFERRED:
      case SqlParsingParser::DELETE:
      case SqlParsingParser::DESC:
      case SqlParsingParser::DETACH:
      case SqlParsingParser::DISTINCT:
      case SqlParsingParser::DROP:
      case SqlParsingParser::EACH:
      case SqlParsingParser::ELSE:
      case SqlParsingParser::END:
      case SqlParsingParser::ESCAPE:
      case SqlParsingParser::EXCEPT:
      case SqlParsingParser::EXCLUSIVE:
      case SqlParsingParser::EXISTS:
      case SqlParsingParser::EXPLAIN:
      case SqlParsingParser::FAIL:
      case SqlParsingParser::FOR:
      case SqlParsingParser::FOREIGN:
      case SqlParsingParser::FROM:
      case SqlParsingParser::FULL:
      case SqlParsingParser::GLOB:
      case SqlParsingParser::GROUP:
      case SqlParsingParser::HAVING:
      case SqlParsingParser::IF:
      case SqlParsingParser::IGNORE:
      case SqlParsingParser::IMMEDIATE:
      case SqlParsingParser::IN:
      case SqlParsingParser::INDEX:
      case SqlParsingParser::INDEXED:
      case SqlParsingParser::INITIALLY:
      case SqlParsingParser::INNER:
      case SqlParsingParser::INSERT:
      case SqlParsingParser::INSTEAD:
      case SqlParsingParser::INTERSECT:
      case SqlParsingParser::INTO:
      case SqlParsingParser::IS:
      case SqlParsingParser::ISNULL:
      case SqlParsingParser::JOIN:
      case SqlParsingParser::KEY:
      case SqlParsingParser::LEFT:
      case SqlParsingParser::LIKE:
      case SqlParsingParser::LIMIT:
      case SqlParsingParser::MATCH:
      case SqlParsingParser::NATURAL:
      case SqlParsingParser::NO:
      case SqlParsingParser::NOT:
      case SqlParsingParser::NOTNULL:
      case SqlParsingParser::NULL_:
      case SqlParsingParser::OF:
      case SqlParsingParser::OFFSET:
      case SqlParsingParser::ON:
      case SqlParsingParser::OR:
      case SqlParsingParser::ORDER:
      case SqlParsingParser::OUTER:
      case SqlParsingParser::PLAN:
      case SqlParsingParser::PRAGMA:
      case SqlParsingParser::PRIMARY:
      case SqlParsingParser::QUERY:
      case SqlParsingParser::RAISE:
      case SqlParsingParser::RECURSIVE:
      case SqlParsingParser::REFERENCES:
      case SqlParsingParser::REGEXP:
      case SqlParsingParser::REINDEX:
      case SqlParsingParser::RELEASE:
      case SqlParsingParser::RENAME:
      case SqlParsingParser::REPLACE:
      case SqlParsingParser::RESTRICT:
      case SqlParsingParser::RIGHT:
      case SqlParsingParser::ROLLBACK:
      case SqlParsingParser::ROW:
      case SqlParsingParser::ROWS:
      case SqlParsingParser::SAVEPOINT:
      case SqlParsingParser::SELECT:
      case SqlParsingParser::SET:
      case SqlParsingParser::TABLE:
      case SqlParsingParser::TEMP:
      case SqlParsingParser::TEMPORARY:
      case SqlParsingParser::THEN:
      case SqlParsingParser::TO:
      case SqlParsingParser::TRANSACTION:
      case SqlParsingParser::TRIGGER:
      case SqlParsingParser::UNION:
      case SqlParsingParser::UNIQUE:
      case SqlParsingParser::UPDATE:
      case SqlParsingParser::USING:
      case SqlParsingParser::VACUUM:
      case SqlParsingParser::VALUES:
      case SqlParsingParser::VIEW:
      case SqlParsingParser::VIRTUAL:
      case SqlParsingParser::WHEN:
      case SqlParsingParser::WHERE:
      case SqlParsingParser::WITH:
      case SqlParsingParser::WITHOUT:
      case SqlParsingParser::FIRST_VALUE:
      case SqlParsingParser::OVER:
      case SqlParsingParser::PARTITION:
      case SqlParsingParser::RANGE:
      case SqlParsingParser::PRECEDING:
      case SqlParsingParser::UNBOUNDED:
      case SqlParsingParser::CURRENT:
      case SqlParsingParser::FOLLOWING:
      case SqlParsingParser::CUME_DIST:
      case SqlParsingParser::DENSE_RANK:
      case SqlParsingParser::LAG:
      case SqlParsingParser::LAST_VALUE:
      case SqlParsingParser::LEAD:
      case SqlParsingParser::NTH_VALUE:
      case SqlParsingParser::NTILE:
      case SqlParsingParser::PERCENT_RANK:
      case SqlParsingParser::RANK:
      case SqlParsingParser::ROW_NUMBER:
      case SqlParsingParser::GENERATED:
      case SqlParsingParser::ALWAYS:
      case SqlParsingParser::STORED:
      case SqlParsingParser::TRUE_:
      case SqlParsingParser::FALSE_:
      case SqlParsingParser::WINDOW:
      case SqlParsingParser::NULLS:
      case SqlParsingParser::FIRST:
      case SqlParsingParser::LAST:
      case SqlParsingParser::FILTER:
      case SqlParsingParser::GROUPS:
      case SqlParsingParser::EXCLUDE:
      case SqlParsingParser::IDENTIFIER:
      case SqlParsingParser::NUMERIC_LITERAL:
      case SqlParsingParser::BIND_PARAMETER:
      case SqlParsingParser::STRING_LITERAL:
      case SqlParsingParser::BLOB_LITERAL: {
        setState(1737);
        expr(0);
        setState(1742);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParsingParser::COMMA) {
          setState(1738);
          match(SqlParsingParser::COMMA);
          setState(1739);
          expr(0);
          setState(1744);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case SqlParsingParser::STAR: {
        setState(1745);
        match(SqlParsingParser::STAR);
        break;
      }

      case SqlParsingParser::CLOSE_PAR: {
        break;
      }

    default:
      break;
    }
    setState(1748);
    match(SqlParsingParser::CLOSE_PAR);
    setState(1750);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::FILTER) {
      setState(1749);
      filter_clause();
    }
    setState(1752);
    match(SqlParsingParser::OVER);
    setState(1755);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 257, _ctx)) {
    case 1: {
      setState(1753);
      window_defn();
      break;
    }

    case 2: {
      setState(1754);
      window_name();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Common_table_stmtContext ------------------------------------------------------------------

SqlParsingParser::Common_table_stmtContext::Common_table_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Common_table_stmtContext::WITH() {
  return getToken(SqlParsingParser::WITH, 0);
}

std::vector<SqlParsingParser::Common_table_expressionContext *> SqlParsingParser::Common_table_stmtContext::common_table_expression() {
  return getRuleContexts<SqlParsingParser::Common_table_expressionContext>();
}

SqlParsingParser::Common_table_expressionContext* SqlParsingParser::Common_table_stmtContext::common_table_expression(size_t i) {
  return getRuleContext<SqlParsingParser::Common_table_expressionContext>(i);
}

tree::TerminalNode* SqlParsingParser::Common_table_stmtContext::RECURSIVE() {
  return getToken(SqlParsingParser::RECURSIVE, 0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Common_table_stmtContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Common_table_stmtContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}


size_t SqlParsingParser::Common_table_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleCommon_table_stmt;
}

void SqlParsingParser::Common_table_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommon_table_stmt(this);
}

void SqlParsingParser::Common_table_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommon_table_stmt(this);
}


antlrcpp::Any SqlParsingParser::Common_table_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitCommon_table_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Common_table_stmtContext* SqlParsingParser::common_table_stmt() {
  Common_table_stmtContext *_localctx = _tracker.createInstance<Common_table_stmtContext>(_ctx, getState());
  enterRule(_localctx, 126, SqlParsingParser::RuleCommon_table_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1757);
    match(SqlParsingParser::WITH);
    setState(1759);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 258, _ctx)) {
    case 1: {
      setState(1758);
      match(SqlParsingParser::RECURSIVE);
      break;
    }

    }
    setState(1761);
    common_table_expression();
    setState(1766);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SqlParsingParser::COMMA) {
      setState(1762);
      match(SqlParsingParser::COMMA);
      setState(1763);
      common_table_expression();
      setState(1768);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Order_by_stmtContext ------------------------------------------------------------------

SqlParsingParser::Order_by_stmtContext::Order_by_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Order_by_stmtContext::ORDER() {
  return getToken(SqlParsingParser::ORDER, 0);
}

tree::TerminalNode* SqlParsingParser::Order_by_stmtContext::BY() {
  return getToken(SqlParsingParser::BY, 0);
}

std::vector<SqlParsingParser::Ordering_termContext *> SqlParsingParser::Order_by_stmtContext::ordering_term() {
  return getRuleContexts<SqlParsingParser::Ordering_termContext>();
}

SqlParsingParser::Ordering_termContext* SqlParsingParser::Order_by_stmtContext::ordering_term(size_t i) {
  return getRuleContext<SqlParsingParser::Ordering_termContext>(i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Order_by_stmtContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Order_by_stmtContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}


size_t SqlParsingParser::Order_by_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleOrder_by_stmt;
}

void SqlParsingParser::Order_by_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrder_by_stmt(this);
}

void SqlParsingParser::Order_by_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrder_by_stmt(this);
}


antlrcpp::Any SqlParsingParser::Order_by_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitOrder_by_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Order_by_stmtContext* SqlParsingParser::order_by_stmt() {
  Order_by_stmtContext *_localctx = _tracker.createInstance<Order_by_stmtContext>(_ctx, getState());
  enterRule(_localctx, 128, SqlParsingParser::RuleOrder_by_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1769);
    match(SqlParsingParser::ORDER);
    setState(1770);
    match(SqlParsingParser::BY);
    setState(1771);
    ordering_term();
    setState(1776);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SqlParsingParser::COMMA) {
      setState(1772);
      match(SqlParsingParser::COMMA);
      setState(1773);
      ordering_term();
      setState(1778);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Limit_stmtContext ------------------------------------------------------------------

SqlParsingParser::Limit_stmtContext::Limit_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Limit_stmtContext::LIMIT() {
  return getToken(SqlParsingParser::LIMIT, 0);
}

std::vector<SqlParsingParser::ExprContext *> SqlParsingParser::Limit_stmtContext::expr() {
  return getRuleContexts<SqlParsingParser::ExprContext>();
}

SqlParsingParser::ExprContext* SqlParsingParser::Limit_stmtContext::expr(size_t i) {
  return getRuleContext<SqlParsingParser::ExprContext>(i);
}

tree::TerminalNode* SqlParsingParser::Limit_stmtContext::OFFSET() {
  return getToken(SqlParsingParser::OFFSET, 0);
}

tree::TerminalNode* SqlParsingParser::Limit_stmtContext::COMMA() {
  return getToken(SqlParsingParser::COMMA, 0);
}


size_t SqlParsingParser::Limit_stmtContext::getRuleIndex() const {
  return SqlParsingParser::RuleLimit_stmt;
}

void SqlParsingParser::Limit_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLimit_stmt(this);
}

void SqlParsingParser::Limit_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLimit_stmt(this);
}


antlrcpp::Any SqlParsingParser::Limit_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitLimit_stmt(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Limit_stmtContext* SqlParsingParser::limit_stmt() {
  Limit_stmtContext *_localctx = _tracker.createInstance<Limit_stmtContext>(_ctx, getState());
  enterRule(_localctx, 130, SqlParsingParser::RuleLimit_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1779);
    match(SqlParsingParser::LIMIT);
    setState(1780);
    expr(0);
    setState(1783);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::COMMA || _la == SqlParsingParser::OFFSET) {
      setState(1781);
      _la = _input->LA(1);
      if (!(_la == SqlParsingParser::COMMA || _la == SqlParsingParser::OFFSET)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1782);
      expr(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ordering_termContext ------------------------------------------------------------------

SqlParsingParser::Ordering_termContext::Ordering_termContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::ExprContext* SqlParsingParser::Ordering_termContext::expr() {
  return getRuleContext<SqlParsingParser::ExprContext>(0);
}

tree::TerminalNode* SqlParsingParser::Ordering_termContext::COLLATE() {
  return getToken(SqlParsingParser::COLLATE, 0);
}

SqlParsingParser::Collation_nameContext* SqlParsingParser::Ordering_termContext::collation_name() {
  return getRuleContext<SqlParsingParser::Collation_nameContext>(0);
}

SqlParsingParser::Asc_descContext* SqlParsingParser::Ordering_termContext::asc_desc() {
  return getRuleContext<SqlParsingParser::Asc_descContext>(0);
}

tree::TerminalNode* SqlParsingParser::Ordering_termContext::NULLS() {
  return getToken(SqlParsingParser::NULLS, 0);
}

tree::TerminalNode* SqlParsingParser::Ordering_termContext::FIRST() {
  return getToken(SqlParsingParser::FIRST, 0);
}

tree::TerminalNode* SqlParsingParser::Ordering_termContext::LAST() {
  return getToken(SqlParsingParser::LAST, 0);
}


size_t SqlParsingParser::Ordering_termContext::getRuleIndex() const {
  return SqlParsingParser::RuleOrdering_term;
}

void SqlParsingParser::Ordering_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrdering_term(this);
}

void SqlParsingParser::Ordering_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrdering_term(this);
}


antlrcpp::Any SqlParsingParser::Ordering_termContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitOrdering_term(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Ordering_termContext* SqlParsingParser::ordering_term() {
  Ordering_termContext *_localctx = _tracker.createInstance<Ordering_termContext>(_ctx, getState());
  enterRule(_localctx, 132, SqlParsingParser::RuleOrdering_term);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1785);
    expr(0);
    setState(1788);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::COLLATE) {
      setState(1786);
      match(SqlParsingParser::COLLATE);
      setState(1787);
      collation_name();
    }
    setState(1791);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::ASC

    || _la == SqlParsingParser::DESC) {
      setState(1790);
      asc_desc();
    }
    setState(1795);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::NULLS) {
      setState(1793);
      match(SqlParsingParser::NULLS);
      setState(1794);
      _la = _input->LA(1);
      if (!(_la == SqlParsingParser::FIRST

      || _la == SqlParsingParser::LAST)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Asc_descContext ------------------------------------------------------------------

SqlParsingParser::Asc_descContext::Asc_descContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Asc_descContext::ASC() {
  return getToken(SqlParsingParser::ASC, 0);
}

tree::TerminalNode* SqlParsingParser::Asc_descContext::DESC() {
  return getToken(SqlParsingParser::DESC, 0);
}


size_t SqlParsingParser::Asc_descContext::getRuleIndex() const {
  return SqlParsingParser::RuleAsc_desc;
}

void SqlParsingParser::Asc_descContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsc_desc(this);
}

void SqlParsingParser::Asc_descContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsc_desc(this);
}


antlrcpp::Any SqlParsingParser::Asc_descContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitAsc_desc(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Asc_descContext* SqlParsingParser::asc_desc() {
  Asc_descContext *_localctx = _tracker.createInstance<Asc_descContext>(_ctx, getState());
  enterRule(_localctx, 134, SqlParsingParser::RuleAsc_desc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1797);
    _la = _input->LA(1);
    if (!(_la == SqlParsingParser::ASC

    || _la == SqlParsingParser::DESC)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Frame_leftContext ------------------------------------------------------------------

SqlParsingParser::Frame_leftContext::Frame_leftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::ExprContext* SqlParsingParser::Frame_leftContext::expr() {
  return getRuleContext<SqlParsingParser::ExprContext>(0);
}

tree::TerminalNode* SqlParsingParser::Frame_leftContext::PRECEDING() {
  return getToken(SqlParsingParser::PRECEDING, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_leftContext::FOLLOWING() {
  return getToken(SqlParsingParser::FOLLOWING, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_leftContext::CURRENT() {
  return getToken(SqlParsingParser::CURRENT, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_leftContext::ROW() {
  return getToken(SqlParsingParser::ROW, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_leftContext::UNBOUNDED() {
  return getToken(SqlParsingParser::UNBOUNDED, 0);
}


size_t SqlParsingParser::Frame_leftContext::getRuleIndex() const {
  return SqlParsingParser::RuleFrame_left;
}

void SqlParsingParser::Frame_leftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFrame_left(this);
}

void SqlParsingParser::Frame_leftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFrame_left(this);
}


antlrcpp::Any SqlParsingParser::Frame_leftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitFrame_left(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Frame_leftContext* SqlParsingParser::frame_left() {
  Frame_leftContext *_localctx = _tracker.createInstance<Frame_leftContext>(_ctx, getState());
  enterRule(_localctx, 136, SqlParsingParser::RuleFrame_left);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1809);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 265, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1799);
      expr(0);
      setState(1800);
      match(SqlParsingParser::PRECEDING);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1802);
      expr(0);
      setState(1803);
      match(SqlParsingParser::FOLLOWING);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1805);
      match(SqlParsingParser::CURRENT);
      setState(1806);
      match(SqlParsingParser::ROW);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1807);
      match(SqlParsingParser::UNBOUNDED);
      setState(1808);
      match(SqlParsingParser::PRECEDING);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Frame_rightContext ------------------------------------------------------------------

SqlParsingParser::Frame_rightContext::Frame_rightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::ExprContext* SqlParsingParser::Frame_rightContext::expr() {
  return getRuleContext<SqlParsingParser::ExprContext>(0);
}

tree::TerminalNode* SqlParsingParser::Frame_rightContext::PRECEDING() {
  return getToken(SqlParsingParser::PRECEDING, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_rightContext::FOLLOWING() {
  return getToken(SqlParsingParser::FOLLOWING, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_rightContext::CURRENT() {
  return getToken(SqlParsingParser::CURRENT, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_rightContext::ROW() {
  return getToken(SqlParsingParser::ROW, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_rightContext::UNBOUNDED() {
  return getToken(SqlParsingParser::UNBOUNDED, 0);
}


size_t SqlParsingParser::Frame_rightContext::getRuleIndex() const {
  return SqlParsingParser::RuleFrame_right;
}

void SqlParsingParser::Frame_rightContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFrame_right(this);
}

void SqlParsingParser::Frame_rightContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFrame_right(this);
}


antlrcpp::Any SqlParsingParser::Frame_rightContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitFrame_right(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Frame_rightContext* SqlParsingParser::frame_right() {
  Frame_rightContext *_localctx = _tracker.createInstance<Frame_rightContext>(_ctx, getState());
  enterRule(_localctx, 138, SqlParsingParser::RuleFrame_right);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1821);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 266, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1811);
      expr(0);
      setState(1812);
      match(SqlParsingParser::PRECEDING);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1814);
      expr(0);
      setState(1815);
      match(SqlParsingParser::FOLLOWING);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1817);
      match(SqlParsingParser::CURRENT);
      setState(1818);
      match(SqlParsingParser::ROW);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1819);
      match(SqlParsingParser::UNBOUNDED);
      setState(1820);
      match(SqlParsingParser::FOLLOWING);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Frame_singleContext ------------------------------------------------------------------

SqlParsingParser::Frame_singleContext::Frame_singleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::ExprContext* SqlParsingParser::Frame_singleContext::expr() {
  return getRuleContext<SqlParsingParser::ExprContext>(0);
}

tree::TerminalNode* SqlParsingParser::Frame_singleContext::PRECEDING() {
  return getToken(SqlParsingParser::PRECEDING, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_singleContext::UNBOUNDED() {
  return getToken(SqlParsingParser::UNBOUNDED, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_singleContext::CURRENT() {
  return getToken(SqlParsingParser::CURRENT, 0);
}

tree::TerminalNode* SqlParsingParser::Frame_singleContext::ROW() {
  return getToken(SqlParsingParser::ROW, 0);
}


size_t SqlParsingParser::Frame_singleContext::getRuleIndex() const {
  return SqlParsingParser::RuleFrame_single;
}

void SqlParsingParser::Frame_singleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFrame_single(this);
}

void SqlParsingParser::Frame_singleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFrame_single(this);
}


antlrcpp::Any SqlParsingParser::Frame_singleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitFrame_single(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Frame_singleContext* SqlParsingParser::frame_single() {
  Frame_singleContext *_localctx = _tracker.createInstance<Frame_singleContext>(_ctx, getState());
  enterRule(_localctx, 140, SqlParsingParser::RuleFrame_single);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1830);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 267, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1823);
      expr(0);
      setState(1824);
      match(SqlParsingParser::PRECEDING);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1826);
      match(SqlParsingParser::UNBOUNDED);
      setState(1827);
      match(SqlParsingParser::PRECEDING);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1828);
      match(SqlParsingParser::CURRENT);
      setState(1829);
      match(SqlParsingParser::ROW);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Window_functionContext ------------------------------------------------------------------

SqlParsingParser::Window_functionContext::Window_functionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> SqlParsingParser::Window_functionContext::OPEN_PAR() {
  return getTokens(SqlParsingParser::OPEN_PAR);
}

tree::TerminalNode* SqlParsingParser::Window_functionContext::OPEN_PAR(size_t i) {
  return getToken(SqlParsingParser::OPEN_PAR, i);
}

SqlParsingParser::ExprContext* SqlParsingParser::Window_functionContext::expr() {
  return getRuleContext<SqlParsingParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Window_functionContext::CLOSE_PAR() {
  return getTokens(SqlParsingParser::CLOSE_PAR);
}

tree::TerminalNode* SqlParsingParser::Window_functionContext::CLOSE_PAR(size_t i) {
  return getToken(SqlParsingParser::CLOSE_PAR, i);
}

tree::TerminalNode* SqlParsingParser::Window_functionContext::OVER() {
  return getToken(SqlParsingParser::OVER, 0);
}

SqlParsingParser::Order_by_expr_asc_descContext* SqlParsingParser::Window_functionContext::order_by_expr_asc_desc() {
  return getRuleContext<SqlParsingParser::Order_by_expr_asc_descContext>(0);
}

tree::TerminalNode* SqlParsingParser::Window_functionContext::FIRST_VALUE() {
  return getToken(SqlParsingParser::FIRST_VALUE, 0);
}

tree::TerminalNode* SqlParsingParser::Window_functionContext::LAST_VALUE() {
  return getToken(SqlParsingParser::LAST_VALUE, 0);
}

SqlParsingParser::Partition_byContext* SqlParsingParser::Window_functionContext::partition_by() {
  return getRuleContext<SqlParsingParser::Partition_byContext>(0);
}

SqlParsingParser::Frame_clauseContext* SqlParsingParser::Window_functionContext::frame_clause() {
  return getRuleContext<SqlParsingParser::Frame_clauseContext>(0);
}

tree::TerminalNode* SqlParsingParser::Window_functionContext::CUME_DIST() {
  return getToken(SqlParsingParser::CUME_DIST, 0);
}

tree::TerminalNode* SqlParsingParser::Window_functionContext::PERCENT_RANK() {
  return getToken(SqlParsingParser::PERCENT_RANK, 0);
}

SqlParsingParser::Order_by_exprContext* SqlParsingParser::Window_functionContext::order_by_expr() {
  return getRuleContext<SqlParsingParser::Order_by_exprContext>(0);
}

tree::TerminalNode* SqlParsingParser::Window_functionContext::DENSE_RANK() {
  return getToken(SqlParsingParser::DENSE_RANK, 0);
}

tree::TerminalNode* SqlParsingParser::Window_functionContext::RANK() {
  return getToken(SqlParsingParser::RANK, 0);
}

tree::TerminalNode* SqlParsingParser::Window_functionContext::ROW_NUMBER() {
  return getToken(SqlParsingParser::ROW_NUMBER, 0);
}

tree::TerminalNode* SqlParsingParser::Window_functionContext::LAG() {
  return getToken(SqlParsingParser::LAG, 0);
}

tree::TerminalNode* SqlParsingParser::Window_functionContext::LEAD() {
  return getToken(SqlParsingParser::LEAD, 0);
}

SqlParsingParser::OffsetContext* SqlParsingParser::Window_functionContext::offset() {
  return getRuleContext<SqlParsingParser::OffsetContext>(0);
}

SqlParsingParser::Default_valueContext* SqlParsingParser::Window_functionContext::default_value() {
  return getRuleContext<SqlParsingParser::Default_valueContext>(0);
}

tree::TerminalNode* SqlParsingParser::Window_functionContext::NTH_VALUE() {
  return getToken(SqlParsingParser::NTH_VALUE, 0);
}

tree::TerminalNode* SqlParsingParser::Window_functionContext::COMMA() {
  return getToken(SqlParsingParser::COMMA, 0);
}

SqlParsingParser::Signed_numberContext* SqlParsingParser::Window_functionContext::signed_number() {
  return getRuleContext<SqlParsingParser::Signed_numberContext>(0);
}

tree::TerminalNode* SqlParsingParser::Window_functionContext::NTILE() {
  return getToken(SqlParsingParser::NTILE, 0);
}


size_t SqlParsingParser::Window_functionContext::getRuleIndex() const {
  return SqlParsingParser::RuleWindow_function;
}

void SqlParsingParser::Window_functionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWindow_function(this);
}

void SqlParsingParser::Window_functionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWindow_function(this);
}


antlrcpp::Any SqlParsingParser::Window_functionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitWindow_function(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Window_functionContext* SqlParsingParser::window_function() {
  Window_functionContext *_localctx = _tracker.createInstance<Window_functionContext>(_ctx, getState());
  enterRule(_localctx, 142, SqlParsingParser::RuleWindow_function);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1917);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::FIRST_VALUE:
      case SqlParsingParser::LAST_VALUE: {
        enterOuterAlt(_localctx, 1);
        setState(1832);
        _la = _input->LA(1);
        if (!(_la == SqlParsingParser::FIRST_VALUE

        || _la == SqlParsingParser::LAST_VALUE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(1833);
        match(SqlParsingParser::OPEN_PAR);
        setState(1834);
        expr(0);
        setState(1835);
        match(SqlParsingParser::CLOSE_PAR);
        setState(1836);
        match(SqlParsingParser::OVER);
        setState(1837);
        match(SqlParsingParser::OPEN_PAR);
        setState(1839);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::PARTITION) {
          setState(1838);
          partition_by();
        }
        setState(1841);
        order_by_expr_asc_desc();
        setState(1843);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 127) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 127)) & ((1ULL << (SqlParsingParser::ROWS - 127))
          | (1ULL << (SqlParsingParser::RANGE - 127))
          | (1ULL << (SqlParsingParser::GROUPS - 127)))) != 0)) {
          setState(1842);
          frame_clause();
        }
        setState(1845);
        match(SqlParsingParser::CLOSE_PAR);
        break;
      }

      case SqlParsingParser::CUME_DIST:
      case SqlParsingParser::PERCENT_RANK: {
        enterOuterAlt(_localctx, 2);
        setState(1847);
        _la = _input->LA(1);
        if (!(_la == SqlParsingParser::CUME_DIST

        || _la == SqlParsingParser::PERCENT_RANK)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(1848);
        match(SqlParsingParser::OPEN_PAR);
        setState(1849);
        match(SqlParsingParser::CLOSE_PAR);
        setState(1850);
        match(SqlParsingParser::OVER);
        setState(1851);
        match(SqlParsingParser::OPEN_PAR);
        setState(1853);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::PARTITION) {
          setState(1852);
          partition_by();
        }
        setState(1856);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::ORDER) {
          setState(1855);
          order_by_expr();
        }
        setState(1858);
        match(SqlParsingParser::CLOSE_PAR);
        break;
      }

      case SqlParsingParser::DENSE_RANK:
      case SqlParsingParser::RANK:
      case SqlParsingParser::ROW_NUMBER: {
        enterOuterAlt(_localctx, 3);
        setState(1859);
        _la = _input->LA(1);
        if (!(((((_la - 159) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 159)) & ((1ULL << (SqlParsingParser::DENSE_RANK - 159))
          | (1ULL << (SqlParsingParser::RANK - 159))
          | (1ULL << (SqlParsingParser::ROW_NUMBER - 159)))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(1860);
        match(SqlParsingParser::OPEN_PAR);
        setState(1861);
        match(SqlParsingParser::CLOSE_PAR);
        setState(1862);
        match(SqlParsingParser::OVER);
        setState(1863);
        match(SqlParsingParser::OPEN_PAR);
        setState(1865);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::PARTITION) {
          setState(1864);
          partition_by();
        }
        setState(1867);
        order_by_expr_asc_desc();
        setState(1868);
        match(SqlParsingParser::CLOSE_PAR);
        break;
      }

      case SqlParsingParser::LAG:
      case SqlParsingParser::LEAD: {
        enterOuterAlt(_localctx, 4);
        setState(1870);
        _la = _input->LA(1);
        if (!(_la == SqlParsingParser::LAG

        || _la == SqlParsingParser::LEAD)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(1871);
        match(SqlParsingParser::OPEN_PAR);
        setState(1872);
        expr(0);
        setState(1874);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 273, _ctx)) {
        case 1: {
          setState(1873);
          offset();
          break;
        }

        }
        setState(1877);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::COMMA) {
          setState(1876);
          default_value();
        }
        setState(1879);
        match(SqlParsingParser::CLOSE_PAR);
        setState(1880);
        match(SqlParsingParser::OVER);
        setState(1881);
        match(SqlParsingParser::OPEN_PAR);
        setState(1883);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::PARTITION) {
          setState(1882);
          partition_by();
        }
        setState(1885);
        order_by_expr_asc_desc();
        setState(1886);
        match(SqlParsingParser::CLOSE_PAR);
        break;
      }

      case SqlParsingParser::NTH_VALUE: {
        enterOuterAlt(_localctx, 5);
        setState(1888);
        match(SqlParsingParser::NTH_VALUE);
        setState(1889);
        match(SqlParsingParser::OPEN_PAR);
        setState(1890);
        expr(0);
        setState(1891);
        match(SqlParsingParser::COMMA);
        setState(1892);
        signed_number();
        setState(1893);
        match(SqlParsingParser::CLOSE_PAR);
        setState(1894);
        match(SqlParsingParser::OVER);
        setState(1895);
        match(SqlParsingParser::OPEN_PAR);
        setState(1897);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::PARTITION) {
          setState(1896);
          partition_by();
        }
        setState(1899);
        order_by_expr_asc_desc();
        setState(1901);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 127) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 127)) & ((1ULL << (SqlParsingParser::ROWS - 127))
          | (1ULL << (SqlParsingParser::RANGE - 127))
          | (1ULL << (SqlParsingParser::GROUPS - 127)))) != 0)) {
          setState(1900);
          frame_clause();
        }
        setState(1903);
        match(SqlParsingParser::CLOSE_PAR);
        break;
      }

      case SqlParsingParser::NTILE: {
        enterOuterAlt(_localctx, 6);
        setState(1905);
        match(SqlParsingParser::NTILE);
        setState(1906);
        match(SqlParsingParser::OPEN_PAR);
        setState(1907);
        expr(0);
        setState(1908);
        match(SqlParsingParser::CLOSE_PAR);
        setState(1909);
        match(SqlParsingParser::OVER);
        setState(1910);
        match(SqlParsingParser::OPEN_PAR);
        setState(1912);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParsingParser::PARTITION) {
          setState(1911);
          partition_by();
        }
        setState(1914);
        order_by_expr_asc_desc();
        setState(1915);
        match(SqlParsingParser::CLOSE_PAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OffsetContext ------------------------------------------------------------------

SqlParsingParser::OffsetContext::OffsetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::OffsetContext::COMMA() {
  return getToken(SqlParsingParser::COMMA, 0);
}

SqlParsingParser::Signed_numberContext* SqlParsingParser::OffsetContext::signed_number() {
  return getRuleContext<SqlParsingParser::Signed_numberContext>(0);
}


size_t SqlParsingParser::OffsetContext::getRuleIndex() const {
  return SqlParsingParser::RuleOffset;
}

void SqlParsingParser::OffsetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOffset(this);
}

void SqlParsingParser::OffsetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOffset(this);
}


antlrcpp::Any SqlParsingParser::OffsetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitOffset(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::OffsetContext* SqlParsingParser::offset() {
  OffsetContext *_localctx = _tracker.createInstance<OffsetContext>(_ctx, getState());
  enterRule(_localctx, 144, SqlParsingParser::RuleOffset);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1919);
    match(SqlParsingParser::COMMA);
    setState(1920);
    signed_number();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Default_valueContext ------------------------------------------------------------------

SqlParsingParser::Default_valueContext::Default_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Default_valueContext::COMMA() {
  return getToken(SqlParsingParser::COMMA, 0);
}

SqlParsingParser::Signed_numberContext* SqlParsingParser::Default_valueContext::signed_number() {
  return getRuleContext<SqlParsingParser::Signed_numberContext>(0);
}


size_t SqlParsingParser::Default_valueContext::getRuleIndex() const {
  return SqlParsingParser::RuleDefault_value;
}

void SqlParsingParser::Default_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefault_value(this);
}

void SqlParsingParser::Default_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefault_value(this);
}


antlrcpp::Any SqlParsingParser::Default_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitDefault_value(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Default_valueContext* SqlParsingParser::default_value() {
  Default_valueContext *_localctx = _tracker.createInstance<Default_valueContext>(_ctx, getState());
  enterRule(_localctx, 146, SqlParsingParser::RuleDefault_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1922);
    match(SqlParsingParser::COMMA);
    setState(1923);
    signed_number();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Partition_byContext ------------------------------------------------------------------

SqlParsingParser::Partition_byContext::Partition_byContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Partition_byContext::PARTITION() {
  return getToken(SqlParsingParser::PARTITION, 0);
}

tree::TerminalNode* SqlParsingParser::Partition_byContext::BY() {
  return getToken(SqlParsingParser::BY, 0);
}

std::vector<SqlParsingParser::ExprContext *> SqlParsingParser::Partition_byContext::expr() {
  return getRuleContexts<SqlParsingParser::ExprContext>();
}

SqlParsingParser::ExprContext* SqlParsingParser::Partition_byContext::expr(size_t i) {
  return getRuleContext<SqlParsingParser::ExprContext>(i);
}


size_t SqlParsingParser::Partition_byContext::getRuleIndex() const {
  return SqlParsingParser::RulePartition_by;
}

void SqlParsingParser::Partition_byContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPartition_by(this);
}

void SqlParsingParser::Partition_byContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPartition_by(this);
}


antlrcpp::Any SqlParsingParser::Partition_byContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitPartition_by(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Partition_byContext* SqlParsingParser::partition_by() {
  Partition_byContext *_localctx = _tracker.createInstance<Partition_byContext>(_ctx, getState());
  enterRule(_localctx, 148, SqlParsingParser::RulePartition_by);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1925);
    match(SqlParsingParser::PARTITION);
    setState(1926);
    match(SqlParsingParser::BY);
    setState(1928); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(1927);
              expr(0);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(1930); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 280, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Order_by_exprContext ------------------------------------------------------------------

SqlParsingParser::Order_by_exprContext::Order_by_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Order_by_exprContext::ORDER() {
  return getToken(SqlParsingParser::ORDER, 0);
}

tree::TerminalNode* SqlParsingParser::Order_by_exprContext::BY() {
  return getToken(SqlParsingParser::BY, 0);
}

std::vector<SqlParsingParser::ExprContext *> SqlParsingParser::Order_by_exprContext::expr() {
  return getRuleContexts<SqlParsingParser::ExprContext>();
}

SqlParsingParser::ExprContext* SqlParsingParser::Order_by_exprContext::expr(size_t i) {
  return getRuleContext<SqlParsingParser::ExprContext>(i);
}


size_t SqlParsingParser::Order_by_exprContext::getRuleIndex() const {
  return SqlParsingParser::RuleOrder_by_expr;
}

void SqlParsingParser::Order_by_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrder_by_expr(this);
}

void SqlParsingParser::Order_by_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrder_by_expr(this);
}


antlrcpp::Any SqlParsingParser::Order_by_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitOrder_by_expr(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Order_by_exprContext* SqlParsingParser::order_by_expr() {
  Order_by_exprContext *_localctx = _tracker.createInstance<Order_by_exprContext>(_ctx, getState());
  enterRule(_localctx, 150, SqlParsingParser::RuleOrder_by_expr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1932);
    match(SqlParsingParser::ORDER);
    setState(1933);
    match(SqlParsingParser::BY);
    setState(1935); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1934);
      expr(0);
      setState(1937); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SqlParsingParser::OPEN_PAR)
      | (1ULL << SqlParsingParser::PLUS)
      | (1ULL << SqlParsingParser::MINUS)
      | (1ULL << SqlParsingParser::TILDE)
      | (1ULL << SqlParsingParser::ABORT)
      | (1ULL << SqlParsingParser::ACTION)
      | (1ULL << SqlParsingParser::ADD)
      | (1ULL << SqlParsingParser::AFTER)
      | (1ULL << SqlParsingParser::ALL)
      | (1ULL << SqlParsingParser::ALTER)
      | (1ULL << SqlParsingParser::ANALYZE)
      | (1ULL << SqlParsingParser::AND)
      | (1ULL << SqlParsingParser::AS)
      | (1ULL << SqlParsingParser::ASC)
      | (1ULL << SqlParsingParser::ATTACH)
      | (1ULL << SqlParsingParser::AUTOINCREMENT)
      | (1ULL << SqlParsingParser::BEFORE)
      | (1ULL << SqlParsingParser::BEGIN)
      | (1ULL << SqlParsingParser::BETWEEN)
      | (1ULL << SqlParsingParser::BY)
      | (1ULL << SqlParsingParser::CASCADE)
      | (1ULL << SqlParsingParser::CASE)
      | (1ULL << SqlParsingParser::CAST)
      | (1ULL << SqlParsingParser::CHECK)
      | (1ULL << SqlParsingParser::COLLATE)
      | (1ULL << SqlParsingParser::COLUMN)
      | (1ULL << SqlParsingParser::COMMIT)
      | (1ULL << SqlParsingParser::CONFLICT)
      | (1ULL << SqlParsingParser::CONSTRAINT)
      | (1ULL << SqlParsingParser::CREATE)
      | (1ULL << SqlParsingParser::CROSS)
      | (1ULL << SqlParsingParser::CURRENT_DATE)
      | (1ULL << SqlParsingParser::CURRENT_TIME)
      | (1ULL << SqlParsingParser::CURRENT_TIMESTAMP)
      | (1ULL << SqlParsingParser::DATABASE)
      | (1ULL << SqlParsingParser::DEFAULT)
      | (1ULL << SqlParsingParser::DEFERRABLE)
      | (1ULL << SqlParsingParser::DEFERRED)
      | (1ULL << SqlParsingParser::DELETE)
      | (1ULL << SqlParsingParser::DESC)
      | (1ULL << SqlParsingParser::DETACH)
      | (1ULL << SqlParsingParser::DISTINCT)
      | (1ULL << SqlParsingParser::DROP))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (SqlParsingParser::EACH - 64))
      | (1ULL << (SqlParsingParser::ELSE - 64))
      | (1ULL << (SqlParsingParser::END - 64))
      | (1ULL << (SqlParsingParser::ESCAPE - 64))
      | (1ULL << (SqlParsingParser::EXCEPT - 64))
      | (1ULL << (SqlParsingParser::EXCLUSIVE - 64))
      | (1ULL << (SqlParsingParser::EXISTS - 64))
      | (1ULL << (SqlParsingParser::EXPLAIN - 64))
      | (1ULL << (SqlParsingParser::FAIL - 64))
      | (1ULL << (SqlParsingParser::FOR - 64))
      | (1ULL << (SqlParsingParser::FOREIGN - 64))
      | (1ULL << (SqlParsingParser::FROM - 64))
      | (1ULL << (SqlParsingParser::FULL - 64))
      | (1ULL << (SqlParsingParser::GLOB - 64))
      | (1ULL << (SqlParsingParser::GROUP - 64))
      | (1ULL << (SqlParsingParser::HAVING - 64))
      | (1ULL << (SqlParsingParser::IF - 64))
      | (1ULL << (SqlParsingParser::IGNORE - 64))
      | (1ULL << (SqlParsingParser::IMMEDIATE - 64))
      | (1ULL << (SqlParsingParser::IN - 64))
      | (1ULL << (SqlParsingParser::INDEX - 64))
      | (1ULL << (SqlParsingParser::INDEXED - 64))
      | (1ULL << (SqlParsingParser::INITIALLY - 64))
      | (1ULL << (SqlParsingParser::INNER - 64))
      | (1ULL << (SqlParsingParser::INSERT - 64))
      | (1ULL << (SqlParsingParser::INSTEAD - 64))
      | (1ULL << (SqlParsingParser::INTERSECT - 64))
      | (1ULL << (SqlParsingParser::INTO - 64))
      | (1ULL << (SqlParsingParser::IS - 64))
      | (1ULL << (SqlParsingParser::ISNULL - 64))
      | (1ULL << (SqlParsingParser::JOIN - 64))
      | (1ULL << (SqlParsingParser::KEY - 64))
      | (1ULL << (SqlParsingParser::LEFT - 64))
      | (1ULL << (SqlParsingParser::LIKE - 64))
      | (1ULL << (SqlParsingParser::LIMIT - 64))
      | (1ULL << (SqlParsingParser::MATCH - 64))
      | (1ULL << (SqlParsingParser::NATURAL - 64))
      | (1ULL << (SqlParsingParser::NO - 64))
      | (1ULL << (SqlParsingParser::NOT - 64))
      | (1ULL << (SqlParsingParser::NOTNULL - 64))
      | (1ULL << (SqlParsingParser::NULL_ - 64))
      | (1ULL << (SqlParsingParser::OF - 64))
      | (1ULL << (SqlParsingParser::OFFSET - 64))
      | (1ULL << (SqlParsingParser::ON - 64))
      | (1ULL << (SqlParsingParser::OR - 64))
      | (1ULL << (SqlParsingParser::ORDER - 64))
      | (1ULL << (SqlParsingParser::OUTER - 64))
      | (1ULL << (SqlParsingParser::PLAN - 64))
      | (1ULL << (SqlParsingParser::PRAGMA - 64))
      | (1ULL << (SqlParsingParser::PRIMARY - 64))
      | (1ULL << (SqlParsingParser::QUERY - 64))
      | (1ULL << (SqlParsingParser::RAISE - 64))
      | (1ULL << (SqlParsingParser::RECURSIVE - 64))
      | (1ULL << (SqlParsingParser::REFERENCES - 64))
      | (1ULL << (SqlParsingParser::REGEXP - 64))
      | (1ULL << (SqlParsingParser::REINDEX - 64))
      | (1ULL << (SqlParsingParser::RELEASE - 64))
      | (1ULL << (SqlParsingParser::RENAME - 64))
      | (1ULL << (SqlParsingParser::REPLACE - 64))
      | (1ULL << (SqlParsingParser::RESTRICT - 64))
      | (1ULL << (SqlParsingParser::RIGHT - 64))
      | (1ULL << (SqlParsingParser::ROLLBACK - 64))
      | (1ULL << (SqlParsingParser::ROW - 64))
      | (1ULL << (SqlParsingParser::ROWS - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 128)) & ((1ULL << (SqlParsingParser::SAVEPOINT - 128))
      | (1ULL << (SqlParsingParser::SELECT - 128))
      | (1ULL << (SqlParsingParser::SET - 128))
      | (1ULL << (SqlParsingParser::TABLE - 128))
      | (1ULL << (SqlParsingParser::TEMP - 128))
      | (1ULL << (SqlParsingParser::TEMPORARY - 128))
      | (1ULL << (SqlParsingParser::THEN - 128))
      | (1ULL << (SqlParsingParser::TO - 128))
      | (1ULL << (SqlParsingParser::TRANSACTION - 128))
      | (1ULL << (SqlParsingParser::TRIGGER - 128))
      | (1ULL << (SqlParsingParser::UNION - 128))
      | (1ULL << (SqlParsingParser::UNIQUE - 128))
      | (1ULL << (SqlParsingParser::UPDATE - 128))
      | (1ULL << (SqlParsingParser::USING - 128))
      | (1ULL << (SqlParsingParser::VACUUM - 128))
      | (1ULL << (SqlParsingParser::VALUES - 128))
      | (1ULL << (SqlParsingParser::VIEW - 128))
      | (1ULL << (SqlParsingParser::VIRTUAL - 128))
      | (1ULL << (SqlParsingParser::WHEN - 128))
      | (1ULL << (SqlParsingParser::WHERE - 128))
      | (1ULL << (SqlParsingParser::WITH - 128))
      | (1ULL << (SqlParsingParser::WITHOUT - 128))
      | (1ULL << (SqlParsingParser::FIRST_VALUE - 128))
      | (1ULL << (SqlParsingParser::OVER - 128))
      | (1ULL << (SqlParsingParser::PARTITION - 128))
      | (1ULL << (SqlParsingParser::RANGE - 128))
      | (1ULL << (SqlParsingParser::PRECEDING - 128))
      | (1ULL << (SqlParsingParser::UNBOUNDED - 128))
      | (1ULL << (SqlParsingParser::CURRENT - 128))
      | (1ULL << (SqlParsingParser::FOLLOWING - 128))
      | (1ULL << (SqlParsingParser::CUME_DIST - 128))
      | (1ULL << (SqlParsingParser::DENSE_RANK - 128))
      | (1ULL << (SqlParsingParser::LAG - 128))
      | (1ULL << (SqlParsingParser::LAST_VALUE - 128))
      | (1ULL << (SqlParsingParser::LEAD - 128))
      | (1ULL << (SqlParsingParser::NTH_VALUE - 128))
      | (1ULL << (SqlParsingParser::NTILE - 128))
      | (1ULL << (SqlParsingParser::PERCENT_RANK - 128))
      | (1ULL << (SqlParsingParser::RANK - 128))
      | (1ULL << (SqlParsingParser::ROW_NUMBER - 128))
      | (1ULL << (SqlParsingParser::GENERATED - 128))
      | (1ULL << (SqlParsingParser::ALWAYS - 128))
      | (1ULL << (SqlParsingParser::STORED - 128))
      | (1ULL << (SqlParsingParser::TRUE_ - 128))
      | (1ULL << (SqlParsingParser::FALSE_ - 128))
      | (1ULL << (SqlParsingParser::WINDOW - 128))
      | (1ULL << (SqlParsingParser::NULLS - 128))
      | (1ULL << (SqlParsingParser::FIRST - 128))
      | (1ULL << (SqlParsingParser::LAST - 128))
      | (1ULL << (SqlParsingParser::FILTER - 128))
      | (1ULL << (SqlParsingParser::GROUPS - 128))
      | (1ULL << (SqlParsingParser::EXCLUDE - 128))
      | (1ULL << (SqlParsingParser::IDENTIFIER - 128))
      | (1ULL << (SqlParsingParser::NUMERIC_LITERAL - 128))
      | (1ULL << (SqlParsingParser::BIND_PARAMETER - 128))
      | (1ULL << (SqlParsingParser::STRING_LITERAL - 128))
      | (1ULL << (SqlParsingParser::BLOB_LITERAL - 128)))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Order_by_expr_asc_descContext ------------------------------------------------------------------

SqlParsingParser::Order_by_expr_asc_descContext::Order_by_expr_asc_descContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Order_by_expr_asc_descContext::ORDER() {
  return getToken(SqlParsingParser::ORDER, 0);
}

tree::TerminalNode* SqlParsingParser::Order_by_expr_asc_descContext::BY() {
  return getToken(SqlParsingParser::BY, 0);
}

SqlParsingParser::Order_by_expr_asc_descContext* SqlParsingParser::Order_by_expr_asc_descContext::order_by_expr_asc_desc() {
  return getRuleContext<SqlParsingParser::Order_by_expr_asc_descContext>(0);
}


size_t SqlParsingParser::Order_by_expr_asc_descContext::getRuleIndex() const {
  return SqlParsingParser::RuleOrder_by_expr_asc_desc;
}

void SqlParsingParser::Order_by_expr_asc_descContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrder_by_expr_asc_desc(this);
}

void SqlParsingParser::Order_by_expr_asc_descContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrder_by_expr_asc_desc(this);
}


antlrcpp::Any SqlParsingParser::Order_by_expr_asc_descContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitOrder_by_expr_asc_desc(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Order_by_expr_asc_descContext* SqlParsingParser::order_by_expr_asc_desc() {
  Order_by_expr_asc_descContext *_localctx = _tracker.createInstance<Order_by_expr_asc_descContext>(_ctx, getState());
  enterRule(_localctx, 152, SqlParsingParser::RuleOrder_by_expr_asc_desc);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1939);
    match(SqlParsingParser::ORDER);
    setState(1940);
    match(SqlParsingParser::BY);
    setState(1941);
    order_by_expr_asc_desc();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr_asc_descContext ------------------------------------------------------------------

SqlParsingParser::Expr_asc_descContext::Expr_asc_descContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SqlParsingParser::ExprContext *> SqlParsingParser::Expr_asc_descContext::expr() {
  return getRuleContexts<SqlParsingParser::ExprContext>();
}

SqlParsingParser::ExprContext* SqlParsingParser::Expr_asc_descContext::expr(size_t i) {
  return getRuleContext<SqlParsingParser::ExprContext>(i);
}

std::vector<SqlParsingParser::Asc_descContext *> SqlParsingParser::Expr_asc_descContext::asc_desc() {
  return getRuleContexts<SqlParsingParser::Asc_descContext>();
}

SqlParsingParser::Asc_descContext* SqlParsingParser::Expr_asc_descContext::asc_desc(size_t i) {
  return getRuleContext<SqlParsingParser::Asc_descContext>(i);
}

std::vector<tree::TerminalNode *> SqlParsingParser::Expr_asc_descContext::COMMA() {
  return getTokens(SqlParsingParser::COMMA);
}

tree::TerminalNode* SqlParsingParser::Expr_asc_descContext::COMMA(size_t i) {
  return getToken(SqlParsingParser::COMMA, i);
}


size_t SqlParsingParser::Expr_asc_descContext::getRuleIndex() const {
  return SqlParsingParser::RuleExpr_asc_desc;
}

void SqlParsingParser::Expr_asc_descContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_asc_desc(this);
}

void SqlParsingParser::Expr_asc_descContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_asc_desc(this);
}


antlrcpp::Any SqlParsingParser::Expr_asc_descContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitExpr_asc_desc(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Expr_asc_descContext* SqlParsingParser::expr_asc_desc() {
  Expr_asc_descContext *_localctx = _tracker.createInstance<Expr_asc_descContext>(_ctx, getState());
  enterRule(_localctx, 154, SqlParsingParser::RuleExpr_asc_desc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1943);
    expr(0);
    setState(1945);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParsingParser::ASC

    || _la == SqlParsingParser::DESC) {
      setState(1944);
      asc_desc();
    }
    setState(1954);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SqlParsingParser::COMMA) {
      setState(1947);
      match(SqlParsingParser::COMMA);
      setState(1948);
      expr(0);
      setState(1950);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SqlParsingParser::ASC

      || _la == SqlParsingParser::DESC) {
        setState(1949);
        asc_desc();
      }
      setState(1956);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Initial_selectContext ------------------------------------------------------------------

SqlParsingParser::Initial_selectContext::Initial_selectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Select_stmtContext* SqlParsingParser::Initial_selectContext::select_stmt() {
  return getRuleContext<SqlParsingParser::Select_stmtContext>(0);
}


size_t SqlParsingParser::Initial_selectContext::getRuleIndex() const {
  return SqlParsingParser::RuleInitial_select;
}

void SqlParsingParser::Initial_selectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitial_select(this);
}

void SqlParsingParser::Initial_selectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitial_select(this);
}


antlrcpp::Any SqlParsingParser::Initial_selectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitInitial_select(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Initial_selectContext* SqlParsingParser::initial_select() {
  Initial_selectContext *_localctx = _tracker.createInstance<Initial_selectContext>(_ctx, getState());
  enterRule(_localctx, 156, SqlParsingParser::RuleInitial_select);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1957);
    select_stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Recursive_selectContext ------------------------------------------------------------------

SqlParsingParser::Recursive_selectContext::Recursive_selectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Select_stmtContext* SqlParsingParser::Recursive_selectContext::select_stmt() {
  return getRuleContext<SqlParsingParser::Select_stmtContext>(0);
}


size_t SqlParsingParser::Recursive_selectContext::getRuleIndex() const {
  return SqlParsingParser::RuleRecursive_select;
}

void SqlParsingParser::Recursive_selectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRecursive_select(this);
}

void SqlParsingParser::Recursive_selectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRecursive_select(this);
}


antlrcpp::Any SqlParsingParser::Recursive_selectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitRecursive_select(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Recursive_selectContext* SqlParsingParser::recursive_select() {
  Recursive_selectContext *_localctx = _tracker.createInstance<Recursive_selectContext>(_ctx, getState());
  enterRule(_localctx, 158, SqlParsingParser::RuleRecursive_select);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1959);
    select_stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_operatorContext ------------------------------------------------------------------

SqlParsingParser::Unary_operatorContext::Unary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Unary_operatorContext::MINUS() {
  return getToken(SqlParsingParser::MINUS, 0);
}

tree::TerminalNode* SqlParsingParser::Unary_operatorContext::PLUS() {
  return getToken(SqlParsingParser::PLUS, 0);
}

tree::TerminalNode* SqlParsingParser::Unary_operatorContext::TILDE() {
  return getToken(SqlParsingParser::TILDE, 0);
}

tree::TerminalNode* SqlParsingParser::Unary_operatorContext::NOT() {
  return getToken(SqlParsingParser::NOT, 0);
}


size_t SqlParsingParser::Unary_operatorContext::getRuleIndex() const {
  return SqlParsingParser::RuleUnary_operator;
}

void SqlParsingParser::Unary_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_operator(this);
}

void SqlParsingParser::Unary_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_operator(this);
}


antlrcpp::Any SqlParsingParser::Unary_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitUnary_operator(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Unary_operatorContext* SqlParsingParser::unary_operator() {
  Unary_operatorContext *_localctx = _tracker.createInstance<Unary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 160, SqlParsingParser::RuleUnary_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1961);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SqlParsingParser::PLUS)
      | (1ULL << SqlParsingParser::MINUS)
      | (1ULL << SqlParsingParser::TILDE))) != 0) || _la == SqlParsingParser::NOT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Error_messageContext ------------------------------------------------------------------

SqlParsingParser::Error_messageContext::Error_messageContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Error_messageContext::STRING_LITERAL() {
  return getToken(SqlParsingParser::STRING_LITERAL, 0);
}


size_t SqlParsingParser::Error_messageContext::getRuleIndex() const {
  return SqlParsingParser::RuleError_message;
}

void SqlParsingParser::Error_messageContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterError_message(this);
}

void SqlParsingParser::Error_messageContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitError_message(this);
}


antlrcpp::Any SqlParsingParser::Error_messageContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitError_message(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Error_messageContext* SqlParsingParser::error_message() {
  Error_messageContext *_localctx = _tracker.createInstance<Error_messageContext>(_ctx, getState());
  enterRule(_localctx, 162, SqlParsingParser::RuleError_message);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1963);
    match(SqlParsingParser::STRING_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Module_argumentContext ------------------------------------------------------------------

SqlParsingParser::Module_argumentContext::Module_argumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::ExprContext* SqlParsingParser::Module_argumentContext::expr() {
  return getRuleContext<SqlParsingParser::ExprContext>(0);
}

SqlParsingParser::Column_defContext* SqlParsingParser::Module_argumentContext::column_def() {
  return getRuleContext<SqlParsingParser::Column_defContext>(0);
}


size_t SqlParsingParser::Module_argumentContext::getRuleIndex() const {
  return SqlParsingParser::RuleModule_argument;
}

void SqlParsingParser::Module_argumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModule_argument(this);
}

void SqlParsingParser::Module_argumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModule_argument(this);
}


antlrcpp::Any SqlParsingParser::Module_argumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitModule_argument(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Module_argumentContext* SqlParsingParser::module_argument() {
  Module_argumentContext *_localctx = _tracker.createInstance<Module_argumentContext>(_ctx, getState());
  enterRule(_localctx, 164, SqlParsingParser::RuleModule_argument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1967);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 285, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1965);
      expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1966);
      column_def();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_aliasContext ------------------------------------------------------------------

SqlParsingParser::Column_aliasContext::Column_aliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Column_aliasContext::IDENTIFIER() {
  return getToken(SqlParsingParser::IDENTIFIER, 0);
}

tree::TerminalNode* SqlParsingParser::Column_aliasContext::STRING_LITERAL() {
  return getToken(SqlParsingParser::STRING_LITERAL, 0);
}


size_t SqlParsingParser::Column_aliasContext::getRuleIndex() const {
  return SqlParsingParser::RuleColumn_alias;
}

void SqlParsingParser::Column_aliasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn_alias(this);
}

void SqlParsingParser::Column_aliasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn_alias(this);
}


antlrcpp::Any SqlParsingParser::Column_aliasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitColumn_alias(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Column_aliasContext* SqlParsingParser::column_alias() {
  Column_aliasContext *_localctx = _tracker.createInstance<Column_aliasContext>(_ctx, getState());
  enterRule(_localctx, 166, SqlParsingParser::RuleColumn_alias);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1969);
    _la = _input->LA(1);
    if (!(_la == SqlParsingParser::IDENTIFIER

    || _la == SqlParsingParser::STRING_LITERAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeywordContext ------------------------------------------------------------------

SqlParsingParser::KeywordContext::KeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::KeywordContext::ABORT() {
  return getToken(SqlParsingParser::ABORT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::ACTION() {
  return getToken(SqlParsingParser::ACTION, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::ADD() {
  return getToken(SqlParsingParser::ADD, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::AFTER() {
  return getToken(SqlParsingParser::AFTER, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::ALL() {
  return getToken(SqlParsingParser::ALL, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::ALTER() {
  return getToken(SqlParsingParser::ALTER, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::ANALYZE() {
  return getToken(SqlParsingParser::ANALYZE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::AND() {
  return getToken(SqlParsingParser::AND, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::AS() {
  return getToken(SqlParsingParser::AS, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::ASC() {
  return getToken(SqlParsingParser::ASC, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::ATTACH() {
  return getToken(SqlParsingParser::ATTACH, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::AUTOINCREMENT() {
  return getToken(SqlParsingParser::AUTOINCREMENT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::BEFORE() {
  return getToken(SqlParsingParser::BEFORE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::BEGIN() {
  return getToken(SqlParsingParser::BEGIN, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::BETWEEN() {
  return getToken(SqlParsingParser::BETWEEN, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::BY() {
  return getToken(SqlParsingParser::BY, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::CASCADE() {
  return getToken(SqlParsingParser::CASCADE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::CASE() {
  return getToken(SqlParsingParser::CASE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::CAST() {
  return getToken(SqlParsingParser::CAST, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::CHECK() {
  return getToken(SqlParsingParser::CHECK, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::COLLATE() {
  return getToken(SqlParsingParser::COLLATE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::COLUMN() {
  return getToken(SqlParsingParser::COLUMN, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::COMMIT() {
  return getToken(SqlParsingParser::COMMIT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::CONFLICT() {
  return getToken(SqlParsingParser::CONFLICT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::CONSTRAINT() {
  return getToken(SqlParsingParser::CONSTRAINT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::CREATE() {
  return getToken(SqlParsingParser::CREATE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::CROSS() {
  return getToken(SqlParsingParser::CROSS, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::CURRENT_DATE() {
  return getToken(SqlParsingParser::CURRENT_DATE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::CURRENT_TIME() {
  return getToken(SqlParsingParser::CURRENT_TIME, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::CURRENT_TIMESTAMP() {
  return getToken(SqlParsingParser::CURRENT_TIMESTAMP, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::DATABASE() {
  return getToken(SqlParsingParser::DATABASE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::DEFAULT() {
  return getToken(SqlParsingParser::DEFAULT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::DEFERRABLE() {
  return getToken(SqlParsingParser::DEFERRABLE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::DEFERRED() {
  return getToken(SqlParsingParser::DEFERRED, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::DELETE() {
  return getToken(SqlParsingParser::DELETE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::DESC() {
  return getToken(SqlParsingParser::DESC, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::DETACH() {
  return getToken(SqlParsingParser::DETACH, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::DISTINCT() {
  return getToken(SqlParsingParser::DISTINCT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::DROP() {
  return getToken(SqlParsingParser::DROP, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::EACH() {
  return getToken(SqlParsingParser::EACH, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::ELSE() {
  return getToken(SqlParsingParser::ELSE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::END() {
  return getToken(SqlParsingParser::END, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::ESCAPE() {
  return getToken(SqlParsingParser::ESCAPE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::EXCEPT() {
  return getToken(SqlParsingParser::EXCEPT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::EXCLUSIVE() {
  return getToken(SqlParsingParser::EXCLUSIVE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::EXISTS() {
  return getToken(SqlParsingParser::EXISTS, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::EXPLAIN() {
  return getToken(SqlParsingParser::EXPLAIN, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::FAIL() {
  return getToken(SqlParsingParser::FAIL, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::FOR() {
  return getToken(SqlParsingParser::FOR, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::FOREIGN() {
  return getToken(SqlParsingParser::FOREIGN, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::FROM() {
  return getToken(SqlParsingParser::FROM, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::FULL() {
  return getToken(SqlParsingParser::FULL, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::GLOB() {
  return getToken(SqlParsingParser::GLOB, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::GROUP() {
  return getToken(SqlParsingParser::GROUP, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::HAVING() {
  return getToken(SqlParsingParser::HAVING, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::IF() {
  return getToken(SqlParsingParser::IF, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::IGNORE() {
  return getToken(SqlParsingParser::IGNORE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::IMMEDIATE() {
  return getToken(SqlParsingParser::IMMEDIATE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::IN() {
  return getToken(SqlParsingParser::IN, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::INDEX() {
  return getToken(SqlParsingParser::INDEX, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::INDEXED() {
  return getToken(SqlParsingParser::INDEXED, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::INITIALLY() {
  return getToken(SqlParsingParser::INITIALLY, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::INNER() {
  return getToken(SqlParsingParser::INNER, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::INSERT() {
  return getToken(SqlParsingParser::INSERT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::INSTEAD() {
  return getToken(SqlParsingParser::INSTEAD, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::INTERSECT() {
  return getToken(SqlParsingParser::INTERSECT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::INTO() {
  return getToken(SqlParsingParser::INTO, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::IS() {
  return getToken(SqlParsingParser::IS, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::ISNULL() {
  return getToken(SqlParsingParser::ISNULL, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::JOIN() {
  return getToken(SqlParsingParser::JOIN, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::KEY() {
  return getToken(SqlParsingParser::KEY, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::LEFT() {
  return getToken(SqlParsingParser::LEFT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::LIKE() {
  return getToken(SqlParsingParser::LIKE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::LIMIT() {
  return getToken(SqlParsingParser::LIMIT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::MATCH() {
  return getToken(SqlParsingParser::MATCH, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::NATURAL() {
  return getToken(SqlParsingParser::NATURAL, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::NO() {
  return getToken(SqlParsingParser::NO, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::NOT() {
  return getToken(SqlParsingParser::NOT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::NOTNULL() {
  return getToken(SqlParsingParser::NOTNULL, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::NULL_() {
  return getToken(SqlParsingParser::NULL_, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::OF() {
  return getToken(SqlParsingParser::OF, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::OFFSET() {
  return getToken(SqlParsingParser::OFFSET, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::ON() {
  return getToken(SqlParsingParser::ON, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::OR() {
  return getToken(SqlParsingParser::OR, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::ORDER() {
  return getToken(SqlParsingParser::ORDER, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::OUTER() {
  return getToken(SqlParsingParser::OUTER, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::PLAN() {
  return getToken(SqlParsingParser::PLAN, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::PRAGMA() {
  return getToken(SqlParsingParser::PRAGMA, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::PRIMARY() {
  return getToken(SqlParsingParser::PRIMARY, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::QUERY() {
  return getToken(SqlParsingParser::QUERY, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::RAISE() {
  return getToken(SqlParsingParser::RAISE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::RECURSIVE() {
  return getToken(SqlParsingParser::RECURSIVE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::REFERENCES() {
  return getToken(SqlParsingParser::REFERENCES, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::REGEXP() {
  return getToken(SqlParsingParser::REGEXP, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::REINDEX() {
  return getToken(SqlParsingParser::REINDEX, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::RELEASE() {
  return getToken(SqlParsingParser::RELEASE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::RENAME() {
  return getToken(SqlParsingParser::RENAME, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::REPLACE() {
  return getToken(SqlParsingParser::REPLACE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::RESTRICT() {
  return getToken(SqlParsingParser::RESTRICT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::RIGHT() {
  return getToken(SqlParsingParser::RIGHT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::ROLLBACK() {
  return getToken(SqlParsingParser::ROLLBACK, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::ROW() {
  return getToken(SqlParsingParser::ROW, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::ROWS() {
  return getToken(SqlParsingParser::ROWS, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::SAVEPOINT() {
  return getToken(SqlParsingParser::SAVEPOINT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::SELECT() {
  return getToken(SqlParsingParser::SELECT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::SET() {
  return getToken(SqlParsingParser::SET, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::TABLE() {
  return getToken(SqlParsingParser::TABLE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::TEMP() {
  return getToken(SqlParsingParser::TEMP, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::TEMPORARY() {
  return getToken(SqlParsingParser::TEMPORARY, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::THEN() {
  return getToken(SqlParsingParser::THEN, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::TO() {
  return getToken(SqlParsingParser::TO, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::TRANSACTION() {
  return getToken(SqlParsingParser::TRANSACTION, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::TRIGGER() {
  return getToken(SqlParsingParser::TRIGGER, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::UNION() {
  return getToken(SqlParsingParser::UNION, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::UNIQUE() {
  return getToken(SqlParsingParser::UNIQUE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::UPDATE() {
  return getToken(SqlParsingParser::UPDATE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::USING() {
  return getToken(SqlParsingParser::USING, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::VACUUM() {
  return getToken(SqlParsingParser::VACUUM, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::VALUES() {
  return getToken(SqlParsingParser::VALUES, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::VIEW() {
  return getToken(SqlParsingParser::VIEW, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::VIRTUAL() {
  return getToken(SqlParsingParser::VIRTUAL, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::WHEN() {
  return getToken(SqlParsingParser::WHEN, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::WHERE() {
  return getToken(SqlParsingParser::WHERE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::WITH() {
  return getToken(SqlParsingParser::WITH, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::WITHOUT() {
  return getToken(SqlParsingParser::WITHOUT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::FIRST_VALUE() {
  return getToken(SqlParsingParser::FIRST_VALUE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::OVER() {
  return getToken(SqlParsingParser::OVER, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::PARTITION() {
  return getToken(SqlParsingParser::PARTITION, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::RANGE() {
  return getToken(SqlParsingParser::RANGE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::PRECEDING() {
  return getToken(SqlParsingParser::PRECEDING, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::UNBOUNDED() {
  return getToken(SqlParsingParser::UNBOUNDED, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::CURRENT() {
  return getToken(SqlParsingParser::CURRENT, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::FOLLOWING() {
  return getToken(SqlParsingParser::FOLLOWING, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::CUME_DIST() {
  return getToken(SqlParsingParser::CUME_DIST, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::DENSE_RANK() {
  return getToken(SqlParsingParser::DENSE_RANK, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::LAG() {
  return getToken(SqlParsingParser::LAG, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::LAST_VALUE() {
  return getToken(SqlParsingParser::LAST_VALUE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::LEAD() {
  return getToken(SqlParsingParser::LEAD, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::NTH_VALUE() {
  return getToken(SqlParsingParser::NTH_VALUE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::NTILE() {
  return getToken(SqlParsingParser::NTILE, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::PERCENT_RANK() {
  return getToken(SqlParsingParser::PERCENT_RANK, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::RANK() {
  return getToken(SqlParsingParser::RANK, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::ROW_NUMBER() {
  return getToken(SqlParsingParser::ROW_NUMBER, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::GENERATED() {
  return getToken(SqlParsingParser::GENERATED, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::ALWAYS() {
  return getToken(SqlParsingParser::ALWAYS, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::STORED() {
  return getToken(SqlParsingParser::STORED, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::TRUE_() {
  return getToken(SqlParsingParser::TRUE_, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::FALSE_() {
  return getToken(SqlParsingParser::FALSE_, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::WINDOW() {
  return getToken(SqlParsingParser::WINDOW, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::NULLS() {
  return getToken(SqlParsingParser::NULLS, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::FIRST() {
  return getToken(SqlParsingParser::FIRST, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::LAST() {
  return getToken(SqlParsingParser::LAST, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::FILTER() {
  return getToken(SqlParsingParser::FILTER, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::GROUPS() {
  return getToken(SqlParsingParser::GROUPS, 0);
}

tree::TerminalNode* SqlParsingParser::KeywordContext::EXCLUDE() {
  return getToken(SqlParsingParser::EXCLUDE, 0);
}


size_t SqlParsingParser::KeywordContext::getRuleIndex() const {
  return SqlParsingParser::RuleKeyword;
}

void SqlParsingParser::KeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword(this);
}

void SqlParsingParser::KeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword(this);
}


antlrcpp::Any SqlParsingParser::KeywordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitKeyword(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::KeywordContext* SqlParsingParser::keyword() {
  KeywordContext *_localctx = _tracker.createInstance<KeywordContext>(_ctx, getState());
  enterRule(_localctx, 168, SqlParsingParser::RuleKeyword);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1971);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SqlParsingParser::ABORT)
      | (1ULL << SqlParsingParser::ACTION)
      | (1ULL << SqlParsingParser::ADD)
      | (1ULL << SqlParsingParser::AFTER)
      | (1ULL << SqlParsingParser::ALL)
      | (1ULL << SqlParsingParser::ALTER)
      | (1ULL << SqlParsingParser::ANALYZE)
      | (1ULL << SqlParsingParser::AND)
      | (1ULL << SqlParsingParser::AS)
      | (1ULL << SqlParsingParser::ASC)
      | (1ULL << SqlParsingParser::ATTACH)
      | (1ULL << SqlParsingParser::AUTOINCREMENT)
      | (1ULL << SqlParsingParser::BEFORE)
      | (1ULL << SqlParsingParser::BEGIN)
      | (1ULL << SqlParsingParser::BETWEEN)
      | (1ULL << SqlParsingParser::BY)
      | (1ULL << SqlParsingParser::CASCADE)
      | (1ULL << SqlParsingParser::CASE)
      | (1ULL << SqlParsingParser::CAST)
      | (1ULL << SqlParsingParser::CHECK)
      | (1ULL << SqlParsingParser::COLLATE)
      | (1ULL << SqlParsingParser::COLUMN)
      | (1ULL << SqlParsingParser::COMMIT)
      | (1ULL << SqlParsingParser::CONFLICT)
      | (1ULL << SqlParsingParser::CONSTRAINT)
      | (1ULL << SqlParsingParser::CREATE)
      | (1ULL << SqlParsingParser::CROSS)
      | (1ULL << SqlParsingParser::CURRENT_DATE)
      | (1ULL << SqlParsingParser::CURRENT_TIME)
      | (1ULL << SqlParsingParser::CURRENT_TIMESTAMP)
      | (1ULL << SqlParsingParser::DATABASE)
      | (1ULL << SqlParsingParser::DEFAULT)
      | (1ULL << SqlParsingParser::DEFERRABLE)
      | (1ULL << SqlParsingParser::DEFERRED)
      | (1ULL << SqlParsingParser::DELETE)
      | (1ULL << SqlParsingParser::DESC)
      | (1ULL << SqlParsingParser::DETACH)
      | (1ULL << SqlParsingParser::DISTINCT)
      | (1ULL << SqlParsingParser::DROP))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (SqlParsingParser::EACH - 64))
      | (1ULL << (SqlParsingParser::ELSE - 64))
      | (1ULL << (SqlParsingParser::END - 64))
      | (1ULL << (SqlParsingParser::ESCAPE - 64))
      | (1ULL << (SqlParsingParser::EXCEPT - 64))
      | (1ULL << (SqlParsingParser::EXCLUSIVE - 64))
      | (1ULL << (SqlParsingParser::EXISTS - 64))
      | (1ULL << (SqlParsingParser::EXPLAIN - 64))
      | (1ULL << (SqlParsingParser::FAIL - 64))
      | (1ULL << (SqlParsingParser::FOR - 64))
      | (1ULL << (SqlParsingParser::FOREIGN - 64))
      | (1ULL << (SqlParsingParser::FROM - 64))
      | (1ULL << (SqlParsingParser::FULL - 64))
      | (1ULL << (SqlParsingParser::GLOB - 64))
      | (1ULL << (SqlParsingParser::GROUP - 64))
      | (1ULL << (SqlParsingParser::HAVING - 64))
      | (1ULL << (SqlParsingParser::IF - 64))
      | (1ULL << (SqlParsingParser::IGNORE - 64))
      | (1ULL << (SqlParsingParser::IMMEDIATE - 64))
      | (1ULL << (SqlParsingParser::IN - 64))
      | (1ULL << (SqlParsingParser::INDEX - 64))
      | (1ULL << (SqlParsingParser::INDEXED - 64))
      | (1ULL << (SqlParsingParser::INITIALLY - 64))
      | (1ULL << (SqlParsingParser::INNER - 64))
      | (1ULL << (SqlParsingParser::INSERT - 64))
      | (1ULL << (SqlParsingParser::INSTEAD - 64))
      | (1ULL << (SqlParsingParser::INTERSECT - 64))
      | (1ULL << (SqlParsingParser::INTO - 64))
      | (1ULL << (SqlParsingParser::IS - 64))
      | (1ULL << (SqlParsingParser::ISNULL - 64))
      | (1ULL << (SqlParsingParser::JOIN - 64))
      | (1ULL << (SqlParsingParser::KEY - 64))
      | (1ULL << (SqlParsingParser::LEFT - 64))
      | (1ULL << (SqlParsingParser::LIKE - 64))
      | (1ULL << (SqlParsingParser::LIMIT - 64))
      | (1ULL << (SqlParsingParser::MATCH - 64))
      | (1ULL << (SqlParsingParser::NATURAL - 64))
      | (1ULL << (SqlParsingParser::NO - 64))
      | (1ULL << (SqlParsingParser::NOT - 64))
      | (1ULL << (SqlParsingParser::NOTNULL - 64))
      | (1ULL << (SqlParsingParser::NULL_ - 64))
      | (1ULL << (SqlParsingParser::OF - 64))
      | (1ULL << (SqlParsingParser::OFFSET - 64))
      | (1ULL << (SqlParsingParser::ON - 64))
      | (1ULL << (SqlParsingParser::OR - 64))
      | (1ULL << (SqlParsingParser::ORDER - 64))
      | (1ULL << (SqlParsingParser::OUTER - 64))
      | (1ULL << (SqlParsingParser::PLAN - 64))
      | (1ULL << (SqlParsingParser::PRAGMA - 64))
      | (1ULL << (SqlParsingParser::PRIMARY - 64))
      | (1ULL << (SqlParsingParser::QUERY - 64))
      | (1ULL << (SqlParsingParser::RAISE - 64))
      | (1ULL << (SqlParsingParser::RECURSIVE - 64))
      | (1ULL << (SqlParsingParser::REFERENCES - 64))
      | (1ULL << (SqlParsingParser::REGEXP - 64))
      | (1ULL << (SqlParsingParser::REINDEX - 64))
      | (1ULL << (SqlParsingParser::RELEASE - 64))
      | (1ULL << (SqlParsingParser::RENAME - 64))
      | (1ULL << (SqlParsingParser::REPLACE - 64))
      | (1ULL << (SqlParsingParser::RESTRICT - 64))
      | (1ULL << (SqlParsingParser::RIGHT - 64))
      | (1ULL << (SqlParsingParser::ROLLBACK - 64))
      | (1ULL << (SqlParsingParser::ROW - 64))
      | (1ULL << (SqlParsingParser::ROWS - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 128)) & ((1ULL << (SqlParsingParser::SAVEPOINT - 128))
      | (1ULL << (SqlParsingParser::SELECT - 128))
      | (1ULL << (SqlParsingParser::SET - 128))
      | (1ULL << (SqlParsingParser::TABLE - 128))
      | (1ULL << (SqlParsingParser::TEMP - 128))
      | (1ULL << (SqlParsingParser::TEMPORARY - 128))
      | (1ULL << (SqlParsingParser::THEN - 128))
      | (1ULL << (SqlParsingParser::TO - 128))
      | (1ULL << (SqlParsingParser::TRANSACTION - 128))
      | (1ULL << (SqlParsingParser::TRIGGER - 128))
      | (1ULL << (SqlParsingParser::UNION - 128))
      | (1ULL << (SqlParsingParser::UNIQUE - 128))
      | (1ULL << (SqlParsingParser::UPDATE - 128))
      | (1ULL << (SqlParsingParser::USING - 128))
      | (1ULL << (SqlParsingParser::VACUUM - 128))
      | (1ULL << (SqlParsingParser::VALUES - 128))
      | (1ULL << (SqlParsingParser::VIEW - 128))
      | (1ULL << (SqlParsingParser::VIRTUAL - 128))
      | (1ULL << (SqlParsingParser::WHEN - 128))
      | (1ULL << (SqlParsingParser::WHERE - 128))
      | (1ULL << (SqlParsingParser::WITH - 128))
      | (1ULL << (SqlParsingParser::WITHOUT - 128))
      | (1ULL << (SqlParsingParser::FIRST_VALUE - 128))
      | (1ULL << (SqlParsingParser::OVER - 128))
      | (1ULL << (SqlParsingParser::PARTITION - 128))
      | (1ULL << (SqlParsingParser::RANGE - 128))
      | (1ULL << (SqlParsingParser::PRECEDING - 128))
      | (1ULL << (SqlParsingParser::UNBOUNDED - 128))
      | (1ULL << (SqlParsingParser::CURRENT - 128))
      | (1ULL << (SqlParsingParser::FOLLOWING - 128))
      | (1ULL << (SqlParsingParser::CUME_DIST - 128))
      | (1ULL << (SqlParsingParser::DENSE_RANK - 128))
      | (1ULL << (SqlParsingParser::LAG - 128))
      | (1ULL << (SqlParsingParser::LAST_VALUE - 128))
      | (1ULL << (SqlParsingParser::LEAD - 128))
      | (1ULL << (SqlParsingParser::NTH_VALUE - 128))
      | (1ULL << (SqlParsingParser::NTILE - 128))
      | (1ULL << (SqlParsingParser::PERCENT_RANK - 128))
      | (1ULL << (SqlParsingParser::RANK - 128))
      | (1ULL << (SqlParsingParser::ROW_NUMBER - 128))
      | (1ULL << (SqlParsingParser::GENERATED - 128))
      | (1ULL << (SqlParsingParser::ALWAYS - 128))
      | (1ULL << (SqlParsingParser::STORED - 128))
      | (1ULL << (SqlParsingParser::TRUE_ - 128))
      | (1ULL << (SqlParsingParser::FALSE_ - 128))
      | (1ULL << (SqlParsingParser::WINDOW - 128))
      | (1ULL << (SqlParsingParser::NULLS - 128))
      | (1ULL << (SqlParsingParser::FIRST - 128))
      | (1ULL << (SqlParsingParser::LAST - 128))
      | (1ULL << (SqlParsingParser::FILTER - 128))
      | (1ULL << (SqlParsingParser::GROUPS - 128))
      | (1ULL << (SqlParsingParser::EXCLUDE - 128)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameContext ------------------------------------------------------------------

SqlParsingParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::NameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::NameContext::getRuleIndex() const {
  return SqlParsingParser::RuleName;
}

void SqlParsingParser::NameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName(this);
}

void SqlParsingParser::NameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName(this);
}


antlrcpp::Any SqlParsingParser::NameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitName(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::NameContext* SqlParsingParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 170, SqlParsingParser::RuleName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1973);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_nameContext ------------------------------------------------------------------

SqlParsingParser::Function_nameContext::Function_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Function_nameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Function_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleFunction_name;
}

void SqlParsingParser::Function_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_name(this);
}

void SqlParsingParser::Function_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_name(this);
}


antlrcpp::Any SqlParsingParser::Function_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitFunction_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Function_nameContext* SqlParsingParser::function_name() {
  Function_nameContext *_localctx = _tracker.createInstance<Function_nameContext>(_ctx, getState());
  enterRule(_localctx, 172, SqlParsingParser::RuleFunction_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1975);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Schema_nameContext ------------------------------------------------------------------

SqlParsingParser::Schema_nameContext::Schema_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Schema_nameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Schema_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleSchema_name;
}

void SqlParsingParser::Schema_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSchema_name(this);
}

void SqlParsingParser::Schema_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSchema_name(this);
}


antlrcpp::Any SqlParsingParser::Schema_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitSchema_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Schema_nameContext* SqlParsingParser::schema_name() {
  Schema_nameContext *_localctx = _tracker.createInstance<Schema_nameContext>(_ctx, getState());
  enterRule(_localctx, 174, SqlParsingParser::RuleSchema_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1977);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_nameContext ------------------------------------------------------------------

SqlParsingParser::Table_nameContext::Table_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Table_nameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Table_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleTable_name;
}

void SqlParsingParser::Table_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_name(this);
}

void SqlParsingParser::Table_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_name(this);
}


antlrcpp::Any SqlParsingParser::Table_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitTable_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Table_nameContext* SqlParsingParser::table_name() {
  Table_nameContext *_localctx = _tracker.createInstance<Table_nameContext>(_ctx, getState());
  enterRule(_localctx, 176, SqlParsingParser::RuleTable_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1979);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_or_index_nameContext ------------------------------------------------------------------

SqlParsingParser::Table_or_index_nameContext::Table_or_index_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Table_or_index_nameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Table_or_index_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleTable_or_index_name;
}

void SqlParsingParser::Table_or_index_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_or_index_name(this);
}

void SqlParsingParser::Table_or_index_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_or_index_name(this);
}


antlrcpp::Any SqlParsingParser::Table_or_index_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitTable_or_index_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Table_or_index_nameContext* SqlParsingParser::table_or_index_name() {
  Table_or_index_nameContext *_localctx = _tracker.createInstance<Table_or_index_nameContext>(_ctx, getState());
  enterRule(_localctx, 178, SqlParsingParser::RuleTable_or_index_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1981);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- New_table_nameContext ------------------------------------------------------------------

SqlParsingParser::New_table_nameContext::New_table_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::New_table_nameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::New_table_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleNew_table_name;
}

void SqlParsingParser::New_table_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNew_table_name(this);
}

void SqlParsingParser::New_table_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNew_table_name(this);
}


antlrcpp::Any SqlParsingParser::New_table_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitNew_table_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::New_table_nameContext* SqlParsingParser::new_table_name() {
  New_table_nameContext *_localctx = _tracker.createInstance<New_table_nameContext>(_ctx, getState());
  enterRule(_localctx, 180, SqlParsingParser::RuleNew_table_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1983);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_nameContext ------------------------------------------------------------------

SqlParsingParser::Column_nameContext::Column_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Column_nameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Column_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleColumn_name;
}

void SqlParsingParser::Column_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn_name(this);
}

void SqlParsingParser::Column_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn_name(this);
}


antlrcpp::Any SqlParsingParser::Column_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitColumn_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Column_nameContext* SqlParsingParser::column_name() {
  Column_nameContext *_localctx = _tracker.createInstance<Column_nameContext>(_ctx, getState());
  enterRule(_localctx, 182, SqlParsingParser::RuleColumn_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1985);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Collation_nameContext ------------------------------------------------------------------

SqlParsingParser::Collation_nameContext::Collation_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Collation_nameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Collation_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleCollation_name;
}

void SqlParsingParser::Collation_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCollation_name(this);
}

void SqlParsingParser::Collation_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCollation_name(this);
}


antlrcpp::Any SqlParsingParser::Collation_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitCollation_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Collation_nameContext* SqlParsingParser::collation_name() {
  Collation_nameContext *_localctx = _tracker.createInstance<Collation_nameContext>(_ctx, getState());
  enterRule(_localctx, 184, SqlParsingParser::RuleCollation_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1987);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Foreign_tableContext ------------------------------------------------------------------

SqlParsingParser::Foreign_tableContext::Foreign_tableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Foreign_tableContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Foreign_tableContext::getRuleIndex() const {
  return SqlParsingParser::RuleForeign_table;
}

void SqlParsingParser::Foreign_tableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForeign_table(this);
}

void SqlParsingParser::Foreign_tableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForeign_table(this);
}


antlrcpp::Any SqlParsingParser::Foreign_tableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitForeign_table(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Foreign_tableContext* SqlParsingParser::foreign_table() {
  Foreign_tableContext *_localctx = _tracker.createInstance<Foreign_tableContext>(_ctx, getState());
  enterRule(_localctx, 186, SqlParsingParser::RuleForeign_table);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1989);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Index_nameContext ------------------------------------------------------------------

SqlParsingParser::Index_nameContext::Index_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Index_nameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Index_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleIndex_name;
}

void SqlParsingParser::Index_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndex_name(this);
}

void SqlParsingParser::Index_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndex_name(this);
}


antlrcpp::Any SqlParsingParser::Index_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitIndex_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Index_nameContext* SqlParsingParser::index_name() {
  Index_nameContext *_localctx = _tracker.createInstance<Index_nameContext>(_ctx, getState());
  enterRule(_localctx, 188, SqlParsingParser::RuleIndex_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1991);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Trigger_nameContext ------------------------------------------------------------------

SqlParsingParser::Trigger_nameContext::Trigger_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Trigger_nameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Trigger_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleTrigger_name;
}

void SqlParsingParser::Trigger_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrigger_name(this);
}

void SqlParsingParser::Trigger_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrigger_name(this);
}


antlrcpp::Any SqlParsingParser::Trigger_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitTrigger_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Trigger_nameContext* SqlParsingParser::trigger_name() {
  Trigger_nameContext *_localctx = _tracker.createInstance<Trigger_nameContext>(_ctx, getState());
  enterRule(_localctx, 190, SqlParsingParser::RuleTrigger_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1993);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- View_nameContext ------------------------------------------------------------------

SqlParsingParser::View_nameContext::View_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::View_nameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::View_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleView_name;
}

void SqlParsingParser::View_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterView_name(this);
}

void SqlParsingParser::View_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitView_name(this);
}


antlrcpp::Any SqlParsingParser::View_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitView_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::View_nameContext* SqlParsingParser::view_name() {
  View_nameContext *_localctx = _tracker.createInstance<View_nameContext>(_ctx, getState());
  enterRule(_localctx, 192, SqlParsingParser::RuleView_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1995);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Module_nameContext ------------------------------------------------------------------

SqlParsingParser::Module_nameContext::Module_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Module_nameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Module_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleModule_name;
}

void SqlParsingParser::Module_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModule_name(this);
}

void SqlParsingParser::Module_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModule_name(this);
}


antlrcpp::Any SqlParsingParser::Module_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitModule_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Module_nameContext* SqlParsingParser::module_name() {
  Module_nameContext *_localctx = _tracker.createInstance<Module_nameContext>(_ctx, getState());
  enterRule(_localctx, 194, SqlParsingParser::RuleModule_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1997);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pragma_nameContext ------------------------------------------------------------------

SqlParsingParser::Pragma_nameContext::Pragma_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Pragma_nameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Pragma_nameContext::getRuleIndex() const {
  return SqlParsingParser::RulePragma_name;
}

void SqlParsingParser::Pragma_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPragma_name(this);
}

void SqlParsingParser::Pragma_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPragma_name(this);
}


antlrcpp::Any SqlParsingParser::Pragma_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitPragma_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Pragma_nameContext* SqlParsingParser::pragma_name() {
  Pragma_nameContext *_localctx = _tracker.createInstance<Pragma_nameContext>(_ctx, getState());
  enterRule(_localctx, 196, SqlParsingParser::RulePragma_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1999);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Savepoint_nameContext ------------------------------------------------------------------

SqlParsingParser::Savepoint_nameContext::Savepoint_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Savepoint_nameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Savepoint_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleSavepoint_name;
}

void SqlParsingParser::Savepoint_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSavepoint_name(this);
}

void SqlParsingParser::Savepoint_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSavepoint_name(this);
}


antlrcpp::Any SqlParsingParser::Savepoint_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitSavepoint_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Savepoint_nameContext* SqlParsingParser::savepoint_name() {
  Savepoint_nameContext *_localctx = _tracker.createInstance<Savepoint_nameContext>(_ctx, getState());
  enterRule(_localctx, 198, SqlParsingParser::RuleSavepoint_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2001);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_aliasContext ------------------------------------------------------------------

SqlParsingParser::Table_aliasContext::Table_aliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Table_aliasContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Table_aliasContext::getRuleIndex() const {
  return SqlParsingParser::RuleTable_alias;
}

void SqlParsingParser::Table_aliasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_alias(this);
}

void SqlParsingParser::Table_aliasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_alias(this);
}


antlrcpp::Any SqlParsingParser::Table_aliasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitTable_alias(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Table_aliasContext* SqlParsingParser::table_alias() {
  Table_aliasContext *_localctx = _tracker.createInstance<Table_aliasContext>(_ctx, getState());
  enterRule(_localctx, 200, SqlParsingParser::RuleTable_alias);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2003);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Transaction_nameContext ------------------------------------------------------------------

SqlParsingParser::Transaction_nameContext::Transaction_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Transaction_nameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Transaction_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleTransaction_name;
}

void SqlParsingParser::Transaction_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTransaction_name(this);
}

void SqlParsingParser::Transaction_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTransaction_name(this);
}


antlrcpp::Any SqlParsingParser::Transaction_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitTransaction_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Transaction_nameContext* SqlParsingParser::transaction_name() {
  Transaction_nameContext *_localctx = _tracker.createInstance<Transaction_nameContext>(_ctx, getState());
  enterRule(_localctx, 202, SqlParsingParser::RuleTransaction_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2005);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Window_nameContext ------------------------------------------------------------------

SqlParsingParser::Window_nameContext::Window_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Window_nameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Window_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleWindow_name;
}

void SqlParsingParser::Window_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWindow_name(this);
}

void SqlParsingParser::Window_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWindow_name(this);
}


antlrcpp::Any SqlParsingParser::Window_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitWindow_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Window_nameContext* SqlParsingParser::window_name() {
  Window_nameContext *_localctx = _tracker.createInstance<Window_nameContext>(_ctx, getState());
  enterRule(_localctx, 204, SqlParsingParser::RuleWindow_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2007);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AliasContext ------------------------------------------------------------------

SqlParsingParser::AliasContext::AliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::AliasContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::AliasContext::getRuleIndex() const {
  return SqlParsingParser::RuleAlias;
}

void SqlParsingParser::AliasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlias(this);
}

void SqlParsingParser::AliasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlias(this);
}


antlrcpp::Any SqlParsingParser::AliasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitAlias(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::AliasContext* SqlParsingParser::alias() {
  AliasContext *_localctx = _tracker.createInstance<AliasContext>(_ctx, getState());
  enterRule(_localctx, 206, SqlParsingParser::RuleAlias);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2009);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FilenameContext ------------------------------------------------------------------

SqlParsingParser::FilenameContext::FilenameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::FilenameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::FilenameContext::getRuleIndex() const {
  return SqlParsingParser::RuleFilename;
}

void SqlParsingParser::FilenameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFilename(this);
}

void SqlParsingParser::FilenameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFilename(this);
}


antlrcpp::Any SqlParsingParser::FilenameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitFilename(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::FilenameContext* SqlParsingParser::filename() {
  FilenameContext *_localctx = _tracker.createInstance<FilenameContext>(_ctx, getState());
  enterRule(_localctx, 208, SqlParsingParser::RuleFilename);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2011);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Base_window_nameContext ------------------------------------------------------------------

SqlParsingParser::Base_window_nameContext::Base_window_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Base_window_nameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Base_window_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleBase_window_name;
}

void SqlParsingParser::Base_window_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBase_window_name(this);
}

void SqlParsingParser::Base_window_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBase_window_name(this);
}


antlrcpp::Any SqlParsingParser::Base_window_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitBase_window_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Base_window_nameContext* SqlParsingParser::base_window_name() {
  Base_window_nameContext *_localctx = _tracker.createInstance<Base_window_nameContext>(_ctx, getState());
  enterRule(_localctx, 210, SqlParsingParser::RuleBase_window_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2013);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_funcContext ------------------------------------------------------------------

SqlParsingParser::Simple_funcContext::Simple_funcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Simple_funcContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Simple_funcContext::getRuleIndex() const {
  return SqlParsingParser::RuleSimple_func;
}

void SqlParsingParser::Simple_funcContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_func(this);
}

void SqlParsingParser::Simple_funcContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_func(this);
}


antlrcpp::Any SqlParsingParser::Simple_funcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitSimple_func(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Simple_funcContext* SqlParsingParser::simple_func() {
  Simple_funcContext *_localctx = _tracker.createInstance<Simple_funcContext>(_ctx, getState());
  enterRule(_localctx, 212, SqlParsingParser::RuleSimple_func);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2015);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Aggregate_funcContext ------------------------------------------------------------------

SqlParsingParser::Aggregate_funcContext::Aggregate_funcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Aggregate_funcContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Aggregate_funcContext::getRuleIndex() const {
  return SqlParsingParser::RuleAggregate_func;
}

void SqlParsingParser::Aggregate_funcContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAggregate_func(this);
}

void SqlParsingParser::Aggregate_funcContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAggregate_func(this);
}


antlrcpp::Any SqlParsingParser::Aggregate_funcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitAggregate_func(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Aggregate_funcContext* SqlParsingParser::aggregate_func() {
  Aggregate_funcContext *_localctx = _tracker.createInstance<Aggregate_funcContext>(_ctx, getState());
  enterRule(_localctx, 214, SqlParsingParser::RuleAggregate_func);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2017);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_function_nameContext ------------------------------------------------------------------

SqlParsingParser::Table_function_nameContext::Table_function_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Table_function_nameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}


size_t SqlParsingParser::Table_function_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleTable_function_name;
}

void SqlParsingParser::Table_function_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_function_name(this);
}

void SqlParsingParser::Table_function_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_function_name(this);
}


antlrcpp::Any SqlParsingParser::Table_function_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitTable_function_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Table_function_nameContext* SqlParsingParser::table_function_name() {
  Table_function_nameContext *_localctx = _tracker.createInstance<Table_function_nameContext>(_ctx, getState());
  enterRule(_localctx, 216, SqlParsingParser::RuleTable_function_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2019);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Any_nameContext ------------------------------------------------------------------

SqlParsingParser::Any_nameContext::Any_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParsingParser::Any_nameContext::IDENTIFIER() {
  return getToken(SqlParsingParser::IDENTIFIER, 0);
}

SqlParsingParser::KeywordContext* SqlParsingParser::Any_nameContext::keyword() {
  return getRuleContext<SqlParsingParser::KeywordContext>(0);
}

tree::TerminalNode* SqlParsingParser::Any_nameContext::STRING_LITERAL() {
  return getToken(SqlParsingParser::STRING_LITERAL, 0);
}

tree::TerminalNode* SqlParsingParser::Any_nameContext::OPEN_PAR() {
  return getToken(SqlParsingParser::OPEN_PAR, 0);
}

SqlParsingParser::Any_nameContext* SqlParsingParser::Any_nameContext::any_name() {
  return getRuleContext<SqlParsingParser::Any_nameContext>(0);
}

tree::TerminalNode* SqlParsingParser::Any_nameContext::CLOSE_PAR() {
  return getToken(SqlParsingParser::CLOSE_PAR, 0);
}


size_t SqlParsingParser::Any_nameContext::getRuleIndex() const {
  return SqlParsingParser::RuleAny_name;
}

void SqlParsingParser::Any_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAny_name(this);
}

void SqlParsingParser::Any_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlParsingListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAny_name(this);
}


antlrcpp::Any SqlParsingParser::Any_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlParsingVisitor*>(visitor))
    return parserVisitor->visitAny_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParsingParser::Any_nameContext* SqlParsingParser::any_name() {
  Any_nameContext *_localctx = _tracker.createInstance<Any_nameContext>(_ctx, getState());
  enterRule(_localctx, 218, SqlParsingParser::RuleAny_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2028);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParsingParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(2021);
        match(SqlParsingParser::IDENTIFIER);
        break;
      }

      case SqlParsingParser::ABORT:
      case SqlParsingParser::ACTION:
      case SqlParsingParser::ADD:
      case SqlParsingParser::AFTER:
      case SqlParsingParser::ALL:
      case SqlParsingParser::ALTER:
      case SqlParsingParser::ANALYZE:
      case SqlParsingParser::AND:
      case SqlParsingParser::AS:
      case SqlParsingParser::ASC:
      case SqlParsingParser::ATTACH:
      case SqlParsingParser::AUTOINCREMENT:
      case SqlParsingParser::BEFORE:
      case SqlParsingParser::BEGIN:
      case SqlParsingParser::BETWEEN:
      case SqlParsingParser::BY:
      case SqlParsingParser::CASCADE:
      case SqlParsingParser::CASE:
      case SqlParsingParser::CAST:
      case SqlParsingParser::CHECK:
      case SqlParsingParser::COLLATE:
      case SqlParsingParser::COLUMN:
      case SqlParsingParser::COMMIT:
      case SqlParsingParser::CONFLICT:
      case SqlParsingParser::CONSTRAINT:
      case SqlParsingParser::CREATE:
      case SqlParsingParser::CROSS:
      case SqlParsingParser::CURRENT_DATE:
      case SqlParsingParser::CURRENT_TIME:
      case SqlParsingParser::CURRENT_TIMESTAMP:
      case SqlParsingParser::DATABASE:
      case SqlParsingParser::DEFAULT:
      case SqlParsingParser::DEFERRABLE:
      case SqlParsingParser::DEFERRED:
      case SqlParsingParser::DELETE:
      case SqlParsingParser::DESC:
      case SqlParsingParser::DETACH:
      case SqlParsingParser::DISTINCT:
      case SqlParsingParser::DROP:
      case SqlParsingParser::EACH:
      case SqlParsingParser::ELSE:
      case SqlParsingParser::END:
      case SqlParsingParser::ESCAPE:
      case SqlParsingParser::EXCEPT:
      case SqlParsingParser::EXCLUSIVE:
      case SqlParsingParser::EXISTS:
      case SqlParsingParser::EXPLAIN:
      case SqlParsingParser::FAIL:
      case SqlParsingParser::FOR:
      case SqlParsingParser::FOREIGN:
      case SqlParsingParser::FROM:
      case SqlParsingParser::FULL:
      case SqlParsingParser::GLOB:
      case SqlParsingParser::GROUP:
      case SqlParsingParser::HAVING:
      case SqlParsingParser::IF:
      case SqlParsingParser::IGNORE:
      case SqlParsingParser::IMMEDIATE:
      case SqlParsingParser::IN:
      case SqlParsingParser::INDEX:
      case SqlParsingParser::INDEXED:
      case SqlParsingParser::INITIALLY:
      case SqlParsingParser::INNER:
      case SqlParsingParser::INSERT:
      case SqlParsingParser::INSTEAD:
      case SqlParsingParser::INTERSECT:
      case SqlParsingParser::INTO:
      case SqlParsingParser::IS:
      case SqlParsingParser::ISNULL:
      case SqlParsingParser::JOIN:
      case SqlParsingParser::KEY:
      case SqlParsingParser::LEFT:
      case SqlParsingParser::LIKE:
      case SqlParsingParser::LIMIT:
      case SqlParsingParser::MATCH:
      case SqlParsingParser::NATURAL:
      case SqlParsingParser::NO:
      case SqlParsingParser::NOT:
      case SqlParsingParser::NOTNULL:
      case SqlParsingParser::NULL_:
      case SqlParsingParser::OF:
      case SqlParsingParser::OFFSET:
      case SqlParsingParser::ON:
      case SqlParsingParser::OR:
      case SqlParsingParser::ORDER:
      case SqlParsingParser::OUTER:
      case SqlParsingParser::PLAN:
      case SqlParsingParser::PRAGMA:
      case SqlParsingParser::PRIMARY:
      case SqlParsingParser::QUERY:
      case SqlParsingParser::RAISE:
      case SqlParsingParser::RECURSIVE:
      case SqlParsingParser::REFERENCES:
      case SqlParsingParser::REGEXP:
      case SqlParsingParser::REINDEX:
      case SqlParsingParser::RELEASE:
      case SqlParsingParser::RENAME:
      case SqlParsingParser::REPLACE:
      case SqlParsingParser::RESTRICT:
      case SqlParsingParser::RIGHT:
      case SqlParsingParser::ROLLBACK:
      case SqlParsingParser::ROW:
      case SqlParsingParser::ROWS:
      case SqlParsingParser::SAVEPOINT:
      case SqlParsingParser::SELECT:
      case SqlParsingParser::SET:
      case SqlParsingParser::TABLE:
      case SqlParsingParser::TEMP:
      case SqlParsingParser::TEMPORARY:
      case SqlParsingParser::THEN:
      case SqlParsingParser::TO:
      case SqlParsingParser::TRANSACTION:
      case SqlParsingParser::TRIGGER:
      case SqlParsingParser::UNION:
      case SqlParsingParser::UNIQUE:
      case SqlParsingParser::UPDATE:
      case SqlParsingParser::USING:
      case SqlParsingParser::VACUUM:
      case SqlParsingParser::VALUES:
      case SqlParsingParser::VIEW:
      case SqlParsingParser::VIRTUAL:
      case SqlParsingParser::WHEN:
      case SqlParsingParser::WHERE:
      case SqlParsingParser::WITH:
      case SqlParsingParser::WITHOUT:
      case SqlParsingParser::FIRST_VALUE:
      case SqlParsingParser::OVER:
      case SqlParsingParser::PARTITION:
      case SqlParsingParser::RANGE:
      case SqlParsingParser::PRECEDING:
      case SqlParsingParser::UNBOUNDED:
      case SqlParsingParser::CURRENT:
      case SqlParsingParser::FOLLOWING:
      case SqlParsingParser::CUME_DIST:
      case SqlParsingParser::DENSE_RANK:
      case SqlParsingParser::LAG:
      case SqlParsingParser::LAST_VALUE:
      case SqlParsingParser::LEAD:
      case SqlParsingParser::NTH_VALUE:
      case SqlParsingParser::NTILE:
      case SqlParsingParser::PERCENT_RANK:
      case SqlParsingParser::RANK:
      case SqlParsingParser::ROW_NUMBER:
      case SqlParsingParser::GENERATED:
      case SqlParsingParser::ALWAYS:
      case SqlParsingParser::STORED:
      case SqlParsingParser::TRUE_:
      case SqlParsingParser::FALSE_:
      case SqlParsingParser::WINDOW:
      case SqlParsingParser::NULLS:
      case SqlParsingParser::FIRST:
      case SqlParsingParser::LAST:
      case SqlParsingParser::FILTER:
      case SqlParsingParser::GROUPS:
      case SqlParsingParser::EXCLUDE: {
        enterOuterAlt(_localctx, 2);
        setState(2022);
        keyword();
        break;
      }

      case SqlParsingParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(2023);
        match(SqlParsingParser::STRING_LITERAL);
        break;
      }

      case SqlParsingParser::OPEN_PAR: {
        enterOuterAlt(_localctx, 4);
        setState(2024);
        match(SqlParsingParser::OPEN_PAR);
        setState(2025);
        any_name();
        setState(2026);
        match(SqlParsingParser::CLOSE_PAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool SqlParsingParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 31: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SqlParsingParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 20);
    case 1: return precpred(_ctx, 19);
    case 2: return precpred(_ctx, 18);
    case 3: return precpred(_ctx, 17);
    case 4: return precpred(_ctx, 16);
    case 5: return precpred(_ctx, 15);
    case 6: return precpred(_ctx, 14);
    case 7: return precpred(_ctx, 13);
    case 8: return precpred(_ctx, 6);
    case 9: return precpred(_ctx, 5);
    case 10: return precpred(_ctx, 9);
    case 11: return precpred(_ctx, 8);
    case 12: return precpred(_ctx, 7);
    case 13: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> SqlParsingParser::_decisionToDFA;
atn::PredictionContextCache SqlParsingParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SqlParsingParser::_atn;
std::vector<uint16_t> SqlParsingParser::_serializedATN;

std::vector<std::string> SqlParsingParser::_ruleNames = {
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

std::vector<std::string> SqlParsingParser::_literalNames = {
  "", "';'", "'.'", "'('", "')'", "','", "'='", "'*'", "'+'", "'-'", "'~'", 
  "'||'", "'/'", "'%'", "'<<'", "'>>'", "'&'", "'|'", "'<'", "'<='", "'>'", 
  "'>='", "'=='", "'!='", "'<>'"
};

std::vector<std::string> SqlParsingParser::_symbolicNames = {
  "", "SCOL", "DOT", "OPEN_PAR", "CLOSE_PAR", "COMMA", "ASSIGN", "STAR", 
  "PLUS", "MINUS", "TILDE", "PIPE2", "DIV", "MOD", "LT2", "GT2", "AMP", 
  "PIPE", "LT", "LT_EQ", "GT", "GT_EQ", "EQ", "NOT_EQ1", "NOT_EQ2", "ABORT", 
  "ACTION", "ADD", "AFTER", "ALL", "ALTER", "ANALYZE", "AND", "AS", "ASC", 
  "ATTACH", "AUTOINCREMENT", "BEFORE", "BEGIN", "BETWEEN", "BY", "CASCADE", 
  "CASE", "CAST", "CHECK", "COLLATE", "COLUMN", "COMMIT", "CONFLICT", "CONSTRAINT", 
  "CREATE", "CROSS", "CURRENT_DATE", "CURRENT_TIME", "CURRENT_TIMESTAMP", 
  "DATABASE", "DEFAULT", "DEFERRABLE", "DEFERRED", "DELETE", "DESC", "DETACH", 
  "DISTINCT", "DROP", "EACH", "ELSE", "END", "ESCAPE", "EXCEPT", "EXCLUSIVE", 
  "EXISTS", "EXPLAIN", "FAIL", "FOR", "FOREIGN", "FROM", "FULL", "GLOB", 
  "GROUP", "HAVING", "IF", "IGNORE", "IMMEDIATE", "IN", "INDEX", "INDEXED", 
  "INITIALLY", "INNER", "INSERT", "INSTEAD", "INTERSECT", "INTO", "IS", 
  "ISNULL", "JOIN", "KEY", "LEFT", "LIKE", "LIMIT", "MATCH", "NATURAL", 
  "NO", "NOT", "NOTNULL", "NULL_", "OF", "OFFSET", "ON", "OR", "ORDER", 
  "OUTER", "PLAN", "PRAGMA", "PRIMARY", "QUERY", "RAISE", "RECURSIVE", "REFERENCES", 
  "REGEXP", "REINDEX", "RELEASE", "RENAME", "REPLACE", "RESTRICT", "RIGHT", 
  "ROLLBACK", "ROW", "ROWS", "SAVEPOINT", "SELECT", "SET", "TABLE", "TEMP", 
  "TEMPORARY", "THEN", "TO", "TRANSACTION", "TRIGGER", "UNION", "UNIQUE", 
  "UPDATE", "USING", "VACUUM", "VALUES", "VIEW", "VIRTUAL", "WHEN", "WHERE", 
  "WITH", "WITHOUT", "FIRST_VALUE", "OVER", "PARTITION", "RANGE", "PRECEDING", 
  "UNBOUNDED", "CURRENT", "FOLLOWING", "CUME_DIST", "DENSE_RANK", "LAG", 
  "LAST_VALUE", "LEAD", "NTH_VALUE", "NTILE", "PERCENT_RANK", "RANK", "ROW_NUMBER", 
  "GENERATED", "ALWAYS", "STORED", "TRUE_", "FALSE_", "WINDOW", "NULLS", 
  "FIRST", "LAST", "FILTER", "GROUPS", "EXCLUDE", "TIES", "OTHERS", "DO", 
  "NOTHING", "IDENTIFIER", "NUMERIC_LITERAL", "BIND_PARAMETER", "STRING_LITERAL", 
  "BLOB_LITERAL", "SINGLE_LINE_COMMENT", "MULTILINE_COMMENT", "SPACES", 
  "UNEXPECTED_CHAR"
};

dfa::Vocabulary SqlParsingParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SqlParsingParser::_tokenNames;

SqlParsingParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xc2, 0x7f1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
    0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 0x9, 
    0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 0x9, 0x5c, 
    0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 0x9, 0x5f, 0x4, 
    0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 0x9, 0x62, 0x4, 0x63, 
    0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 0x9, 0x65, 0x4, 0x66, 0x9, 
    0x66, 0x4, 0x67, 0x9, 0x67, 0x4, 0x68, 0x9, 0x68, 0x4, 0x69, 0x9, 0x69, 
    0x4, 0x6a, 0x9, 0x6a, 0x4, 0x6b, 0x9, 0x6b, 0x4, 0x6c, 0x9, 0x6c, 0x4, 
    0x6d, 0x9, 0x6d, 0x4, 0x6e, 0x9, 0x6e, 0x4, 0x6f, 0x9, 0x6f, 0x3, 0x2, 
    0x7, 0x2, 0xe0, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xe3, 0xb, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x6, 0x2, 0xe7, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0xe8, 0x3, 0x2, 
    0x7, 0x2, 0xec, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xef, 0xb, 0x2, 0x3, 0x2, 
    0x7, 0x2, 0xf2, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xf5, 0xb, 0x2, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0xfa, 0xa, 0x3, 0x5, 0x3, 0xfc, 0xa, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x116, 0xa, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x11d, 0xa, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x124, 0xa, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x12a, 0xa, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0x12e, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 0x131, 0xa, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x138, 
    0xa, 0x5, 0x3, 0x5, 0x5, 0x5, 0x13b, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0x13f, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x5, 0x7, 0x147, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x14b, 
    0xa, 0x7, 0x5, 0x7, 0x14d, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x151, 
    0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x155, 0xa, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x5, 0x9, 0x159, 0xa, 0x9, 0x3, 0x9, 0x5, 0x9, 0x15c, 0xa, 0x9, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x163, 0xa, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x169, 0xa, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x16f, 0xa, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x174, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x17d, 0xa, 
    0xc, 0xc, 0xc, 0xe, 0xc, 0x180, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x5, 0xc, 0x185, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x189, 0xa, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x18d, 0xa, 0xd, 0x3, 0xd, 0x5, 0xd, 
    0x190, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x194, 0xa, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x19a, 0xa, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x19f, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x1a6, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 
    0x1a9, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x1ad, 0xa, 0xe, 0xc, 
    0xe, 0xe, 0xe, 0x1b0, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 
    0x1b5, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x1b9, 0xa, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x5, 0xf, 0x1bd, 0xa, 0xf, 0x3, 0xf, 0x7, 0xf, 0x1c0, 
    0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x1c3, 0xb, 0xf, 0x3, 0x10, 0x6, 0x10, 
    0x1c6, 0xa, 0x10, 0xd, 0x10, 0xe, 0x10, 0x1c7, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x5, 0x10, 0x1d4, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x5, 0x11, 0x1d8, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0x1dd, 0xa, 0x11, 0x3, 0x11, 0x5, 0x11, 0x1e0, 0xa, 0x11, 0x3, 0x11, 
    0x5, 0x11, 0x1e3, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0x1e8, 0xa, 0x11, 0x3, 0x11, 0x5, 0x11, 0x1eb, 0xa, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x1f9, 
    0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 
    0x11, 0x200, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x5, 0x11, 0x207, 0xa, 0x11, 0x5, 0x11, 0x209, 0xa, 0x11, 
    0x3, 0x12, 0x5, 0x12, 0x20c, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 
    0x3, 0x13, 0x5, 0x13, 0x212, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x5, 0x13, 0x217, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x7, 0x13, 0x21d, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x220, 0xb, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x224, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x231, 0xa, 0x13, 0xc, 0x13, 
    0xe, 0x13, 0x234, 0xb, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 
    0x239, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x7, 0x14, 0x241, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x244, 
    0xb, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x248, 0xa, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x5, 0x14, 0x252, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 
    0x256, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x259, 0xb, 0x14, 0x3, 0x14, 
    0x5, 0x14, 0x25c, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 
    0x261, 0xa, 0x14, 0x5, 0x14, 0x263, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x26b, 0xa, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x271, 0xa, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x276, 0xa, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x27d, 0xa, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x7, 0x16, 0x286, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0x289, 0xb, 
    0x16, 0x5, 0x16, 0x28b, 0xa, 0x16, 0x5, 0x16, 0x28d, 0xa, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x294, 
    0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x298, 0xa, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x29f, 0xa, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x6, 0x16, 0x2a3, 0xa, 0x16, 0xd, 0x16, 0xe, 0x16, 
    0x2a4, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x2ab, 
    0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x2b1, 
    0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x2b6, 0xa, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x2bd, 
    0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x2c0, 0xb, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x5, 0x17, 0x2c4, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x2cf, 
    0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x2d4, 0xa, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x7, 0x18, 0x2dd, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x2e0, 0xb, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x2e4, 0xa, 0x18, 0x3, 0x19, 
    0x3, 0x19, 0x5, 0x19, 0x2e8, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x2f6, 0xa, 0x19, 0xc, 0x19, 
    0xe, 0x19, 0x2f9, 0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x7, 0x1a, 0x300, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 0x303, 
    0xb, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x307, 0xa, 0x1a, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x30f, 
    0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x319, 0xa, 0x1c, 0xc, 0x1c, 
    0xe, 0x1c, 0x31c, 0xb, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x320, 
    0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1d, 0x5, 0x1d, 0x328, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x32f, 0xa, 0x1d, 0x3, 0x1e, 0x5, 0x1e, 
    0x332, 0xa, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x5, 0x1e, 0x339, 0xa, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x33c, 0xa, 0x1e, 
    0x3, 0x1e, 0x5, 0x1e, 0x33f, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 
    0x343, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x5, 0x20, 0x34b, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x5, 0x20, 0x350, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x35a, 0xa, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x35f, 0xa, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 
    0x21, 0x368, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 
    0x36d, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x370, 0xb, 0x21, 0x3, 0x21, 
    0x5, 0x21, 0x373, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x377, 
    0xa, 0x21, 0x3, 0x21, 0x5, 0x21, 0x37a, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x380, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 
    0x383, 0xb, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x38f, 
    0xa, 0x21, 0x3, 0x21, 0x5, 0x21, 0x392, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x39a, 0xa, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x6, 0x21, 0x3a1, 
    0xa, 0x21, 0xd, 0x21, 0xe, 0x21, 0x3a2, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 
    0x3a7, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x3ac, 
    0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x3ca, 0xa, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x3d6, 0xa, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x3db, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x21, 0x3, 0x21, 0x5, 0x21, 0x3e7, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x3ed, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x3f4, 0xa, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x5, 0x21, 0x3f8, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x400, 0xa, 0x21, 0xc, 0x21, 
    0xe, 0x21, 0x403, 0xb, 0x21, 0x5, 0x21, 0x405, 0xa, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x40b, 0xa, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x411, 0xa, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x418, 0xa, 0x21, 
    0xc, 0x21, 0xe, 0x21, 0x41b, 0xb, 0x21, 0x5, 0x21, 0x41d, 0xa, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x421, 0xa, 0x21, 0x7, 0x21, 0x423, 
    0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x426, 0xb, 0x21, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x42e, 0xa, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x5, 0x24, 0x435, 
    0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 
    0x24, 0x43c, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x5, 0x24, 0x442, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 
    0x447, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 
    0x44d, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x450, 0xb, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x5, 0x24, 0x454, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x45b, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 
    0x45e, 0xb, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x7, 0x24, 0x466, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x469, 
    0xb, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x46d, 0xa, 0x24, 0xc, 0x24, 
    0xe, 0x24, 0x470, 0xb, 0x24, 0x3, 0x24, 0x5, 0x24, 0x473, 0xa, 0x24, 
    0x3, 0x24, 0x5, 0x24, 0x476, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 
    0x47a, 0xa, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x7, 0x25, 0x482, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x485, 
    0xb, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x48a, 0xa, 0x25, 
    0x5, 0x25, 0x48c, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x494, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x49b, 0xa, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x4a0, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 
    0x4a3, 0xb, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x4a7, 0xa, 0x25, 
    0x5, 0x25, 0x4a9, 0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x5, 0x26, 0x4af, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x4b8, 0xa, 0x26, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x4bd, 0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x4c4, 0xa, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x5, 0x28, 0x4c8, 0xa, 0x28, 0x5, 0x28, 0x4ca, 0xa, 0x28, 
    0x3, 0x29, 0x5, 0x29, 0x4cd, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x7, 0x29, 0x4d3, 0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x4d6, 
    0xb, 0x29, 0x3, 0x29, 0x5, 0x29, 0x4d9, 0xa, 0x29, 0x3, 0x29, 0x5, 0x29, 
    0x4dc, 0xa, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 
    0x4e2, 0xa, 0x2a, 0x7, 0x2a, 0x4e4, 0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 
    0x4e7, 0xb, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x4eb, 0xa, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x4f0, 0xa, 0x2b, 0xc, 0x2b, 
    0xe, 0x2b, 0x4f3, 0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x7, 0x2b, 0x4f9, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x4fc, 0xb, 0x2b, 
    0x3, 0x2b, 0x5, 0x2b, 0x4ff, 0xa, 0x2b, 0x5, 0x2b, 0x501, 0xa, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x505, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x50c, 0xa, 0x2b, 0xc, 0x2b, 
    0xe, 0x2b, 0x50f, 0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x513, 
    0xa, 0x2b, 0x5, 0x2b, 0x515, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x7, 
    0x2b, 0x520, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x523, 0xb, 0x2b, 0x5, 
    0x2b, 0x525, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x7, 0x2b, 0x52c, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x52f, 
    0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
    0x2b, 0x7, 0x2b, 0x537, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x53a, 0xb, 
    0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x53e, 0xa, 0x2b, 0xc, 0x2b, 
    0xe, 0x2b, 0x541, 0xb, 0x2b, 0x5, 0x2b, 0x543, 0xa, 0x2b, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2d, 0x5, 0x2d, 0x548, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x5, 0x2d, 0x54c, 0xa, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x54f, 0xa, 0x2d, 
    0x3, 0x2e, 0x5, 0x2e, 0x552, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x5, 0x2e, 0x557, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x55b, 
    0xa, 0x2e, 0x3, 0x2e, 0x6, 0x2e, 0x55e, 0xa, 0x2e, 0xd, 0x2e, 0xe, 0x2e, 
    0x55f, 0x3, 0x2e, 0x5, 0x2e, 0x563, 0xa, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 
    0x566, 0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x56b, 
    0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x56f, 0xa, 0x2f, 0x3, 0x2f, 
    0x5, 0x2f, 0x572, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x5, 0x2f, 0x579, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x5, 0x2f, 0x57e, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x7, 0x2f, 0x585, 0xa, 0x2f, 0xc, 0x2f, 0xe, 0x2f, 0x588, 
    0xb, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x58c, 0xa, 0x2f, 0x3, 0x2f, 
    0x5, 0x2f, 0x58f, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x7, 0x2f, 0x595, 0xa, 0x2f, 0xc, 0x2f, 0xe, 0x2f, 0x598, 0xb, 0x2f, 
    0x3, 0x2f, 0x5, 0x2f, 0x59b, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x5a3, 0xa, 0x2f, 0x3, 0x2f, 
    0x5, 0x2f, 0x5a6, 0xa, 0x2f, 0x5, 0x2f, 0x5a8, 0xa, 0x2f, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 
    0x30, 0x5b1, 0xa, 0x30, 0x3, 0x30, 0x5, 0x30, 0x5b4, 0xa, 0x30, 0x5, 
    0x30, 0x5b6, 0xa, 0x30, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x5ba, 0xa, 
    0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x5be, 0xa, 0x31, 0x3, 0x31, 
    0x3, 0x31, 0x5, 0x31, 0x5c2, 0xa, 0x31, 0x3, 0x31, 0x5, 0x31, 0x5c5, 
    0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 
    0x32, 0x3, 0x32, 0x7, 0x32, 0x5ce, 0xa, 0x32, 0xc, 0x32, 0xe, 0x32, 
    0x5d1, 0xb, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x5d5, 0xa, 0x32, 
    0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x5d9, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x5, 0x33, 0x5dd, 0xa, 0x33, 0x3, 0x34, 0x5, 0x34, 0x5e0, 0xa, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x5e5, 0xa, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x5eb, 0xa, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x5f2, 0xa, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x7, 0x34, 0x5f7, 0xa, 0x34, 0xc, 0x34, 
    0xe, 0x34, 0x5fa, 0xb, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x5fe, 
    0xa, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 0x604, 
    0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x607, 0xb, 0x35, 0x3, 0x35, 0x3, 0x35, 
    0x3, 0x36, 0x5, 0x36, 0x60c, 0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
    0x5, 0x36, 0x611, 0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
    0x5, 0x36, 0x617, 0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
    0x3, 0x36, 0x5, 0x36, 0x61e, 0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
    0x7, 0x36, 0x623, 0xa, 0x36, 0xc, 0x36, 0xe, 0x36, 0x626, 0xb, 0x36, 
    0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x62a, 0xa, 0x36, 0x3, 0x36, 0x5, 0x36, 
    0x62d, 0xa, 0x36, 0x3, 0x36, 0x5, 0x36, 0x630, 0xa, 0x36, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x635, 0xa, 0x37, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x5, 0x37, 0x63a, 0xa, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x641, 0xa, 0x37, 0x3, 0x38, 0x3, 0x38, 
    0x5, 0x38, 0x645, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x649, 
    0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 
    0x39, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x653, 0xa, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x7, 0x3a, 0x65a, 0xa, 0x3a, 
    0xc, 0x3a, 0xe, 0x3a, 0x65d, 0xb, 0x3a, 0x5, 0x3a, 0x65f, 0xa, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x7, 0x3a, 0x666, 
    0xa, 0x3a, 0xc, 0x3a, 0xe, 0x3a, 0x669, 0xb, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 
    0x66c, 0xa, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 
    0x3, 0x3b, 0x5, 0x3b, 0x674, 0xa, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x67b, 0xa, 0x3b, 0xc, 0x3b, 0xe, 0x3b, 
    0x67e, 0xb, 0x3b, 0x5, 0x3b, 0x680, 0xa, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x687, 0xa, 0x3b, 0xc, 0x3b, 
    0xe, 0x3b, 0x68a, 0xb, 0x3b, 0x5, 0x3b, 0x68c, 0xa, 0x3b, 0x3, 0x3b, 
    0x5, 0x3b, 0x68f, 0xa, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x692, 0xa, 0x3b, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x69c, 0xa, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x6a5, 
    0xa, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x7, 
    0x3e, 0x6ac, 0xa, 0x3e, 0xc, 0x3e, 0xe, 0x3e, 0x6af, 0xb, 0x3e, 0x3, 
    0x3e, 0x5, 0x3e, 0x6b2, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x6b9, 0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
    0x3, 0x3f, 0x7, 0x3f, 0x6be, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 0x6c1, 
    0xb, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x6c4, 0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
    0x5, 0x3f, 0x6c8, 0xa, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x7, 0x40, 0x6cf, 0xa, 0x40, 0xc, 0x40, 0xe, 0x40, 0x6d2, 
    0xb, 0x40, 0x3, 0x40, 0x5, 0x40, 0x6d5, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x5, 0x40, 0x6d9, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 
    0x6de, 0xa, 0x40, 0x3, 0x41, 0x3, 0x41, 0x5, 0x41, 0x6e2, 0xa, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x7, 0x41, 0x6e7, 0xa, 0x41, 0xc, 0x41, 
    0xe, 0x41, 0x6ea, 0xb, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 
    0x3, 0x42, 0x7, 0x42, 0x6f1, 0xa, 0x42, 0xc, 0x42, 0xe, 0x42, 0x6f4, 
    0xb, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x6fa, 
    0xa, 0x43, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x5, 0x44, 0x6ff, 0xa, 0x44, 
    0x3, 0x44, 0x5, 0x44, 0x702, 0xa, 0x44, 0x3, 0x44, 0x3, 0x44, 0x5, 0x44, 
    0x706, 0xa, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 
    0x46, 0x5, 0x46, 0x714, 0xa, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 
    0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 
    0x47, 0x5, 0x47, 0x720, 0xa, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x5, 0x48, 0x729, 0xa, 0x48, 
    0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 
    0x49, 0x5, 0x49, 0x732, 0xa, 0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 
    0x736, 0xa, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 
    0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 0x740, 0xa, 0x49, 0x3, 0x49, 
    0x5, 0x49, 0x743, 0xa, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 
    0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 0x74c, 0xa, 0x49, 0x3, 0x49, 
    0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 
    0x49, 0x755, 0xa, 0x49, 0x3, 0x49, 0x5, 0x49, 0x758, 0xa, 0x49, 0x3, 
    0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 0x75e, 0xa, 0x49, 
    0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 
    0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 
    0x76c, 0xa, 0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 0x770, 0xa, 0x49, 
    0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 
    0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 0x77b, 0xa, 0x49, 0x3, 0x49, 
    0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 0x780, 0xa, 0x49, 0x3, 0x4a, 0x3, 0x4a, 
    0x3, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 
    0x4c, 0x6, 0x4c, 0x78b, 0xa, 0x4c, 0xd, 0x4c, 0xe, 0x4c, 0x78c, 0x3, 
    0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x6, 0x4d, 0x792, 0xa, 0x4d, 0xd, 0x4d, 
    0xe, 0x4d, 0x793, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4f, 
    0x3, 0x4f, 0x5, 0x4f, 0x79c, 0xa, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 
    0x5, 0x4f, 0x7a1, 0xa, 0x4f, 0x7, 0x4f, 0x7a3, 0xa, 0x4f, 0xc, 0x4f, 
    0xe, 0x4f, 0x7a6, 0xb, 0x4f, 0x3, 0x50, 0x3, 0x50, 0x3, 0x51, 0x3, 0x51, 
    0x3, 0x52, 0x3, 0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 0x54, 0x3, 0x54, 0x5, 
    0x54, 0x7b2, 0xa, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x56, 0x3, 0x56, 
    0x3, 0x57, 0x3, 0x57, 0x3, 0x58, 0x3, 0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 
    0x5a, 0x3, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5d, 
    0x3, 0x5d, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x60, 0x3, 
    0x60, 0x3, 0x61, 0x3, 0x61, 0x3, 0x62, 0x3, 0x62, 0x3, 0x63, 0x3, 0x63, 
    0x3, 0x64, 0x3, 0x64, 0x3, 0x65, 0x3, 0x65, 0x3, 0x66, 0x3, 0x66, 0x3, 
    0x67, 0x3, 0x67, 0x3, 0x68, 0x3, 0x68, 0x3, 0x69, 0x3, 0x69, 0x3, 0x6a, 
    0x3, 0x6a, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6d, 0x3, 
    0x6d, 0x3, 0x6e, 0x3, 0x6e, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 
    0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x5, 0x6f, 0x7ef, 0xa, 0x6f, 0x3, 0x6f, 
    0x2, 0x3, 0x40, 0x70, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 
    0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 
    0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 
    0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 
    0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 
    0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 
    0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 
    0xbc, 0xbe, 0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0xcc, 0xce, 0xd0, 0xd2, 
    0xd4, 0xd6, 0xd8, 0xda, 0xdc, 0x2, 0x1e, 0x5, 0x2, 0x3c, 0x3c, 0x47, 
    0x47, 0x54, 0x54, 0x4, 0x2, 0x31, 0x31, 0x44, 0x44, 0x3, 0x2, 0x86, 
    0x87, 0x4, 0x2, 0x93, 0x93, 0xac, 0xac, 0x3, 0x2, 0xa, 0xb, 0x4, 0x2, 
    0x3d, 0x3d, 0x8e, 0x8e, 0x4, 0x2, 0x3a, 0x3a, 0x6a, 0x6a, 0x4, 0x2, 
    0x3c, 0x3c, 0x54, 0x54, 0x7, 0x2, 0x1b, 0x1b, 0x4a, 0x4a, 0x53, 0x53, 
    0x7c, 0x7c, 0x7f, 0x7f, 0x6, 0x2, 0x56, 0x56, 0x85, 0x85, 0x8b, 0x8b, 
    0x92, 0x92, 0x4, 0x2, 0x9, 0x9, 0xe, 0xf, 0x3, 0x2, 0x10, 0x13, 0x3, 
    0x2, 0x14, 0x17, 0x6, 0x2, 0x4f, 0x4f, 0x63, 0x63, 0x65, 0x65, 0x78, 
    0x78, 0x5, 0x2, 0x1b, 0x1b, 0x4a, 0x4a, 0x7f, 0x7f, 0x7, 0x2, 0x36, 
    0x38, 0x6a, 0x6a, 0xad, 0xae, 0xbb, 0xbb, 0xbd, 0xbe, 0x4, 0x2, 0x1f, 
    0x1f, 0x40, 0x40, 0x5, 0x2, 0x81, 0x81, 0x9b, 0x9b, 0xb4, 0xb4, 0x4, 
    0x2, 0x7, 0x7, 0x6c, 0x6c, 0x3, 0x2, 0xb1, 0xb2, 0x4, 0x2, 0x24, 0x24, 
    0x3e, 0x3e, 0x4, 0x2, 0x98, 0x98, 0xa3, 0xa3, 0x4, 0x2, 0xa0, 0xa0, 
    0xa7, 0xa7, 0x4, 0x2, 0xa1, 0xa1, 0xa8, 0xa9, 0x4, 0x2, 0xa2, 0xa2, 
    0xa4, 0xa4, 0x4, 0x2, 0xa, 0xc, 0x68, 0x68, 0x4, 0x2, 0xba, 0xba, 0xbd, 
    0xbd, 0x3, 0x2, 0x1b, 0xb5, 0x2, 0x905, 0x2, 0xe1, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x6, 0x117, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x132, 0x3, 0x2, 0x2, 0x2, 0xa, 0x13c, 0x3, 0x2, 0x2, 0x2, 0xc, 0x144, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x10, 0x152, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x14, 0x160, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x166, 0x3, 0x2, 0x2, 0x2, 0x18, 0x188, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x191, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1ba, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x20, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x20b, 0x3, 0x2, 0x2, 0x2, 0x24, 0x211, 0x3, 0x2, 0x2, 0x2, 0x26, 0x23a, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x264, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x268, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2c8, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x2e5, 0x3, 0x2, 0x2, 0x2, 0x32, 0x2fa, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x308, 0x3, 0x2, 0x2, 0x2, 0x36, 0x313, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x327, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x331, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x340, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x346, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3ab, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x427, 0x3, 0x2, 0x2, 0x2, 0x44, 0x431, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x479, 0x3, 0x2, 0x2, 0x2, 0x48, 0x47b, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x4aa, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4bc, 0x3, 0x2, 0x2, 
    0x2, 0x4e, 0x4be, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4cc, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x4dd, 0x3, 0x2, 0x2, 0x2, 0x54, 0x542, 0x3, 0x2, 0x2, 0x2, 0x56, 
    0x544, 0x3, 0x2, 0x2, 0x2, 0x58, 0x547, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x551, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x5a7, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5b5, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x5c4, 0x3, 0x2, 0x2, 0x2, 0x62, 0x5d4, 0x3, 0x2, 
    0x2, 0x2, 0x64, 0x5dc, 0x3, 0x2, 0x2, 0x2, 0x66, 0x5df, 0x3, 0x2, 0x2, 
    0x2, 0x68, 0x5ff, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x60b, 0x3, 0x2, 0x2, 0x2, 
    0x6c, 0x634, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x642, 0x3, 0x2, 0x2, 0x2, 0x70, 
    0x64a, 0x3, 0x2, 0x2, 0x2, 0x72, 0x650, 0x3, 0x2, 0x2, 0x2, 0x74, 0x66f, 
    0x3, 0x2, 0x2, 0x2, 0x76, 0x693, 0x3, 0x2, 0x2, 0x2, 0x78, 0x69d, 0x3, 
    0x2, 0x2, 0x2, 0x7a, 0x6a6, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x6b5, 0x3, 0x2, 
    0x2, 0x2, 0x7e, 0x6c9, 0x3, 0x2, 0x2, 0x2, 0x80, 0x6df, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0x6eb, 0x3, 0x2, 0x2, 0x2, 0x84, 0x6f5, 0x3, 0x2, 0x2, 0x2, 
    0x86, 0x6fb, 0x3, 0x2, 0x2, 0x2, 0x88, 0x707, 0x3, 0x2, 0x2, 0x2, 0x8a, 
    0x713, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x71f, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x728, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x77f, 0x3, 0x2, 0x2, 0x2, 0x92, 0x781, 0x3, 
    0x2, 0x2, 0x2, 0x94, 0x784, 0x3, 0x2, 0x2, 0x2, 0x96, 0x787, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x78e, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x795, 0x3, 0x2, 0x2, 
    0x2, 0x9c, 0x799, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x7a7, 0x3, 0x2, 0x2, 0x2, 
    0xa0, 0x7a9, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x7ab, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0x7ad, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x7b1, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x7b3, 
    0x3, 0x2, 0x2, 0x2, 0xaa, 0x7b5, 0x3, 0x2, 0x2, 0x2, 0xac, 0x7b7, 0x3, 
    0x2, 0x2, 0x2, 0xae, 0x7b9, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x7bb, 0x3, 0x2, 
    0x2, 0x2, 0xb2, 0x7bd, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x7bf, 0x3, 0x2, 0x2, 
    0x2, 0xb6, 0x7c1, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x7c3, 0x3, 0x2, 0x2, 0x2, 
    0xba, 0x7c5, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x7c7, 0x3, 0x2, 0x2, 0x2, 0xbe, 
    0x7c9, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x7cb, 0x3, 0x2, 0x2, 0x2, 0xc2, 0x7cd, 
    0x3, 0x2, 0x2, 0x2, 0xc4, 0x7cf, 0x3, 0x2, 0x2, 0x2, 0xc6, 0x7d1, 0x3, 
    0x2, 0x2, 0x2, 0xc8, 0x7d3, 0x3, 0x2, 0x2, 0x2, 0xca, 0x7d5, 0x3, 0x2, 
    0x2, 0x2, 0xcc, 0x7d7, 0x3, 0x2, 0x2, 0x2, 0xce, 0x7d9, 0x3, 0x2, 0x2, 
    0x2, 0xd0, 0x7db, 0x3, 0x2, 0x2, 0x2, 0xd2, 0x7dd, 0x3, 0x2, 0x2, 0x2, 
    0xd4, 0x7df, 0x3, 0x2, 0x2, 0x2, 0xd6, 0x7e1, 0x3, 0x2, 0x2, 0x2, 0xd8, 
    0x7e3, 0x3, 0x2, 0x2, 0x2, 0xda, 0x7e5, 0x3, 0x2, 0x2, 0x2, 0xdc, 0x7ee, 
    0x3, 0x2, 0x2, 0x2, 0xde, 0xe0, 0x7, 0x3, 0x2, 0x2, 0xdf, 0xde, 0x3, 
    0x2, 0x2, 0x2, 0xe0, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xdf, 0x3, 0x2, 
    0x2, 0x2, 0xe1, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe4, 0x3, 0x2, 0x2, 
    0x2, 0xe3, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xed, 0x5, 0x4, 0x3, 0x2, 
    0xe5, 0xe7, 0x7, 0x3, 0x2, 0x2, 0xe6, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe7, 
    0xe8, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 
    0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x3, 0x2, 0x2, 0x2, 0xea, 0xec, 0x5, 
    0x4, 0x3, 0x2, 0xeb, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xec, 0xef, 0x3, 0x2, 
    0x2, 0x2, 0xed, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x3, 0x2, 0x2, 
    0x2, 0xee, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xef, 0xed, 0x3, 0x2, 0x2, 0x2, 
    0xf0, 0xf2, 0x7, 0x3, 0x2, 0x2, 0xf1, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf2, 
    0xf5, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 
    0x3, 0x2, 0x2, 0x2, 0xf4, 0x3, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf3, 0x3, 
    0x2, 0x2, 0x2, 0xf6, 0xf9, 0x7, 0x49, 0x2, 0x2, 0xf7, 0xf8, 0x7, 0x74, 
    0x2, 0x2, 0xf8, 0xfa, 0x7, 0x71, 0x2, 0x2, 0xf9, 0xf7, 0x3, 0x2, 0x2, 
    0x2, 0xf9, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfc, 0x3, 0x2, 0x2, 0x2, 
    0xfb, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 
    0x115, 0x3, 0x2, 0x2, 0x2, 0xfd, 0x116, 0x5, 0x6, 0x4, 0x2, 0xfe, 0x116, 
    0x5, 0x8, 0x5, 0x2, 0xff, 0x116, 0x5, 0xa, 0x6, 0x2, 0x100, 0x116, 0x5, 
    0xc, 0x7, 0x2, 0x101, 0x116, 0x5, 0xe, 0x8, 0x2, 0x102, 0x116, 0x5, 
    0x16, 0xc, 0x2, 0x103, 0x116, 0x5, 0x1a, 0xe, 0x2, 0x104, 0x116, 0x5, 
    0x2a, 0x16, 0x2, 0x105, 0x116, 0x5, 0x2c, 0x17, 0x2, 0x106, 0x116, 0x5, 
    0x2e, 0x18, 0x2, 0x107, 0x116, 0x5, 0x38, 0x1d, 0x2, 0x108, 0x116, 0x5, 
    0x3a, 0x1e, 0x2, 0x109, 0x116, 0x5, 0x3c, 0x1f, 0x2, 0x10a, 0x116, 0x5, 
    0x3e, 0x20, 0x2, 0x10b, 0x116, 0x5, 0x46, 0x24, 0x2, 0x10c, 0x116, 0x5, 
    0x4a, 0x26, 0x2, 0x10d, 0x116, 0x5, 0x4e, 0x28, 0x2, 0x10e, 0x116, 0x5, 
    0x14, 0xb, 0x2, 0x10f, 0x116, 0x5, 0x10, 0x9, 0x2, 0x110, 0x116, 0x5, 
    0x12, 0xa, 0x2, 0x111, 0x116, 0x5, 0x50, 0x29, 0x2, 0x112, 0x116, 0x5, 
    0x66, 0x34, 0x2, 0x113, 0x116, 0x5, 0x6a, 0x36, 0x2, 0x114, 0x116, 0x5, 
    0x6e, 0x38, 0x2, 0x115, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x115, 0xfe, 0x3, 
    0x2, 0x2, 0x2, 0x115, 0xff, 0x3, 0x2, 0x2, 0x2, 0x115, 0x100, 0x3, 0x2, 
    0x2, 0x2, 0x115, 0x101, 0x3, 0x2, 0x2, 0x2, 0x115, 0x102, 0x3, 0x2, 
    0x2, 0x2, 0x115, 0x103, 0x3, 0x2, 0x2, 0x2, 0x115, 0x104, 0x3, 0x2, 
    0x2, 0x2, 0x115, 0x105, 0x3, 0x2, 0x2, 0x2, 0x115, 0x106, 0x3, 0x2, 
    0x2, 0x2, 0x115, 0x107, 0x3, 0x2, 0x2, 0x2, 0x115, 0x108, 0x3, 0x2, 
    0x2, 0x2, 0x115, 0x109, 0x3, 0x2, 0x2, 0x2, 0x115, 0x10a, 0x3, 0x2, 
    0x2, 0x2, 0x115, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x115, 0x10c, 0x3, 0x2, 
    0x2, 0x2, 0x115, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x115, 0x10e, 0x3, 0x2, 
    0x2, 0x2, 0x115, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x115, 0x110, 0x3, 0x2, 
    0x2, 0x2, 0x115, 0x111, 0x3, 0x2, 0x2, 0x2, 0x115, 0x112, 0x3, 0x2, 
    0x2, 0x2, 0x115, 0x113, 0x3, 0x2, 0x2, 0x2, 0x115, 0x114, 0x3, 0x2, 
    0x2, 0x2, 0x116, 0x5, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x7, 0x20, 0x2, 
    0x2, 0x118, 0x11c, 0x7, 0x85, 0x2, 0x2, 0x119, 0x11a, 0x5, 0xb0, 0x59, 
    0x2, 0x11a, 0x11b, 0x7, 0x4, 0x2, 0x2, 0x11b, 0x11d, 0x3, 0x2, 0x2, 
    0x2, 0x11c, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x3, 0x2, 0x2, 
    0x2, 0x11d, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x130, 0x5, 0xb2, 0x5a, 
    0x2, 0x11f, 0x129, 0x7, 0x7b, 0x2, 0x2, 0x120, 0x121, 0x7, 0x89, 0x2, 
    0x2, 0x121, 0x12a, 0x5, 0xb6, 0x5c, 0x2, 0x122, 0x124, 0x7, 0x30, 0x2, 
    0x2, 0x123, 0x122, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x3, 0x2, 0x2, 
    0x2, 0x124, 0x125, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x5, 0xb8, 0x5d, 
    0x2, 0x126, 0x127, 0x7, 0x89, 0x2, 0x2, 0x127, 0x128, 0x5, 0xb8, 0x5d, 
    0x2, 0x128, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x129, 0x120, 0x3, 0x2, 0x2, 
    0x2, 0x129, 0x123, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x131, 0x3, 0x2, 0x2, 
    0x2, 0x12b, 0x12d, 0x7, 0x1d, 0x2, 0x2, 0x12c, 0x12e, 0x7, 0x30, 0x2, 
    0x2, 0x12d, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x3, 0x2, 0x2, 
    0x2, 0x12e, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x131, 0x5, 0x1c, 0xf, 
    0x2, 0x130, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x130, 0x12b, 0x3, 0x2, 0x2, 
    0x2, 0x131, 0x7, 0x3, 0x2, 0x2, 0x2, 0x132, 0x13a, 0x7, 0x21, 0x2, 0x2, 
    0x133, 0x13b, 0x5, 0xb0, 0x59, 0x2, 0x134, 0x135, 0x5, 0xb0, 0x59, 0x2, 
    0x135, 0x136, 0x7, 0x4, 0x2, 0x2, 0x136, 0x138, 0x3, 0x2, 0x2, 0x2, 
    0x137, 0x134, 0x3, 0x2, 0x2, 0x2, 0x137, 0x138, 0x3, 0x2, 0x2, 0x2, 
    0x138, 0x139, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13b, 0x5, 0xb4, 0x5b, 0x2, 
    0x13a, 0x133, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x137, 0x3, 0x2, 0x2, 0x2, 
    0x13a, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x9, 0x3, 0x2, 0x2, 0x2, 0x13c, 
    0x13e, 0x7, 0x25, 0x2, 0x2, 0x13d, 0x13f, 0x7, 0x39, 0x2, 0x2, 0x13e, 
    0x13d, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x13f, 
    0x140, 0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 0x5, 0x40, 0x21, 0x2, 0x141, 
    0x142, 0x7, 0x23, 0x2, 0x2, 0x142, 0x143, 0x5, 0xb0, 0x59, 0x2, 0x143, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0x144, 0x146, 0x7, 0x28, 0x2, 0x2, 0x145, 0x147, 
    0x9, 0x2, 0x2, 0x2, 0x146, 0x145, 0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 
    0x3, 0x2, 0x2, 0x2, 0x147, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x148, 0x14a, 
    0x7, 0x8a, 0x2, 0x2, 0x149, 0x14b, 0x5, 0xcc, 0x67, 0x2, 0x14a, 0x149, 
    0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14d, 
    0x3, 0x2, 0x2, 0x2, 0x14c, 0x148, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14d, 
    0x3, 0x2, 0x2, 0x2, 0x14d, 0xd, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x150, 0x9, 
    0x3, 0x2, 0x2, 0x14f, 0x151, 0x7, 0x8a, 0x2, 0x2, 0x150, 0x14f, 0x3, 
    0x2, 0x2, 0x2, 0x150, 0x151, 0x3, 0x2, 0x2, 0x2, 0x151, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x152, 0x154, 0x7, 0x7f, 0x2, 0x2, 0x153, 0x155, 0x7, 0x8a, 
    0x2, 0x2, 0x154, 0x153, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x3, 0x2, 
    0x2, 0x2, 0x155, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x156, 0x158, 0x7, 0x89, 
    0x2, 0x2, 0x157, 0x159, 0x7, 0x82, 0x2, 0x2, 0x158, 0x157, 0x3, 0x2, 
    0x2, 0x2, 0x158, 0x159, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x3, 0x2, 
    0x2, 0x2, 0x15a, 0x15c, 0x5, 0xc8, 0x65, 0x2, 0x15b, 0x156, 0x3, 0x2, 
    0x2, 0x2, 0x15b, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x15d, 0x15e, 0x7, 0x82, 0x2, 0x2, 0x15e, 0x15f, 0x5, 0xc8, 0x65, 
    0x2, 0x15f, 0x13, 0x3, 0x2, 0x2, 0x2, 0x160, 0x162, 0x7, 0x7a, 0x2, 
    0x2, 0x161, 0x163, 0x7, 0x82, 0x2, 0x2, 0x162, 0x161, 0x3, 0x2, 0x2, 
    0x2, 0x162, 0x163, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x3, 0x2, 0x2, 
    0x2, 0x164, 0x165, 0x5, 0xc8, 0x65, 0x2, 0x165, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x166, 0x168, 0x7, 0x34, 0x2, 0x2, 0x167, 0x169, 0x7, 0x8d, 0x2, 
    0x2, 0x168, 0x167, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x3, 0x2, 0x2, 
    0x2, 0x169, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16e, 0x7, 0x56, 0x2, 
    0x2, 0x16b, 0x16c, 0x7, 0x52, 0x2, 0x2, 0x16c, 0x16d, 0x7, 0x68, 0x2, 
    0x2, 0x16d, 0x16f, 0x7, 0x48, 0x2, 0x2, 0x16e, 0x16b, 0x3, 0x2, 0x2, 
    0x2, 0x16e, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x173, 0x3, 0x2, 0x2, 
    0x2, 0x170, 0x171, 0x5, 0xb0, 0x59, 0x2, 0x171, 0x172, 0x7, 0x4, 0x2, 
    0x2, 0x172, 0x174, 0x3, 0x2, 0x2, 0x2, 0x173, 0x170, 0x3, 0x2, 0x2, 
    0x2, 0x173, 0x174, 0x3, 0x2, 0x2, 0x2, 0x174, 0x175, 0x3, 0x2, 0x2, 
    0x2, 0x175, 0x176, 0x5, 0xbe, 0x60, 0x2, 0x176, 0x177, 0x7, 0x6d, 0x2, 
    0x2, 0x177, 0x178, 0x5, 0xb2, 0x5a, 0x2, 0x178, 0x179, 0x7, 0x5, 0x2, 
    0x2, 0x179, 0x17e, 0x5, 0x18, 0xd, 0x2, 0x17a, 0x17b, 0x7, 0x7, 0x2, 
    0x2, 0x17b, 0x17d, 0x5, 0x18, 0xd, 0x2, 0x17c, 0x17a, 0x3, 0x2, 0x2, 
    0x2, 0x17d, 0x180, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17c, 0x3, 0x2, 0x2, 
    0x2, 0x17e, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x181, 0x3, 0x2, 0x2, 
    0x2, 0x180, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x181, 0x184, 0x7, 0x6, 0x2, 
    0x2, 0x182, 0x183, 0x7, 0x95, 0x2, 0x2, 0x183, 0x185, 0x5, 0x40, 0x21, 
    0x2, 0x184, 0x182, 0x3, 0x2, 0x2, 0x2, 0x184, 0x185, 0x3, 0x2, 0x2, 
    0x2, 0x185, 0x17, 0x3, 0x2, 0x2, 0x2, 0x186, 0x189, 0x5, 0xb8, 0x5d, 
    0x2, 0x187, 0x189, 0x5, 0x40, 0x21, 0x2, 0x188, 0x186, 0x3, 0x2, 0x2, 
    0x2, 0x188, 0x187, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18c, 0x3, 0x2, 0x2, 
    0x2, 0x18a, 0x18b, 0x7, 0x2f, 0x2, 0x2, 0x18b, 0x18d, 0x5, 0xba, 0x5e, 
    0x2, 0x18c, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18d, 0x3, 0x2, 0x2, 
    0x2, 0x18d, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x190, 0x5, 0x88, 0x45, 
    0x2, 0x18f, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x3, 0x2, 0x2, 
    0x2, 0x190, 0x19, 0x3, 0x2, 0x2, 0x2, 0x191, 0x193, 0x7, 0x34, 0x2, 
    0x2, 0x192, 0x194, 0x9, 0x4, 0x2, 0x2, 0x193, 0x192, 0x3, 0x2, 0x2, 
    0x2, 0x193, 0x194, 0x3, 0x2, 0x2, 0x2, 0x194, 0x195, 0x3, 0x2, 0x2, 
    0x2, 0x195, 0x199, 0x7, 0x85, 0x2, 0x2, 0x196, 0x197, 0x7, 0x52, 0x2, 
    0x2, 0x197, 0x198, 0x7, 0x68, 0x2, 0x2, 0x198, 0x19a, 0x7, 0x48, 0x2, 
    0x2, 0x199, 0x196, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19a, 0x3, 0x2, 0x2, 
    0x2, 0x19a, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x5, 0xb0, 0x59, 
    0x2, 0x19c, 0x19d, 0x7, 0x4, 0x2, 0x2, 0x19d, 0x19f, 0x3, 0x2, 0x2, 
    0x2, 0x19e, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x3, 0x2, 0x2, 
    0x2, 0x19f, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1b8, 0x5, 0xb2, 0x5a, 
    0x2, 0x1a1, 0x1a2, 0x7, 0x5, 0x2, 0x2, 0x1a2, 0x1a7, 0x5, 0x1c, 0xf, 
    0x2, 0x1a3, 0x1a4, 0x7, 0x7, 0x2, 0x2, 0x1a4, 0x1a6, 0x5, 0x1c, 0xf, 
    0x2, 0x1a5, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a9, 0x3, 0x2, 0x2, 
    0x2, 0x1a7, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x3, 0x2, 0x2, 
    0x2, 0x1a8, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1a7, 0x3, 0x2, 0x2, 
    0x2, 0x1aa, 0x1ab, 0x7, 0x7, 0x2, 0x2, 0x1ab, 0x1ad, 0x5, 0x24, 0x13, 
    0x2, 0x1ac, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1b0, 0x3, 0x2, 0x2, 
    0x2, 0x1ae, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1af, 0x3, 0x2, 0x2, 
    0x2, 0x1af, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1ae, 0x3, 0x2, 0x2, 
    0x2, 0x1b1, 0x1b4, 0x7, 0x6, 0x2, 0x2, 0x1b2, 0x1b3, 0x7, 0x97, 0x2, 
    0x2, 0x1b3, 0x1b5, 0x7, 0xba, 0x2, 0x2, 0x1b4, 0x1b2, 0x3, 0x2, 0x2, 
    0x2, 0x1b4, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b9, 0x3, 0x2, 0x2, 
    0x2, 0x1b6, 0x1b7, 0x7, 0x23, 0x2, 0x2, 0x1b7, 0x1b9, 0x5, 0x50, 0x29, 
    0x2, 0x1b8, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b6, 0x3, 0x2, 0x2, 
    0x2, 0x1b9, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bc, 0x5, 0xb8, 0x5d, 
    0x2, 0x1bb, 0x1bd, 0x5, 0x1e, 0x10, 0x2, 0x1bc, 0x1bb, 0x3, 0x2, 0x2, 
    0x2, 0x1bc, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1c1, 0x3, 0x2, 0x2, 
    0x2, 0x1be, 0x1c0, 0x5, 0x20, 0x11, 0x2, 0x1bf, 0x1be, 0x3, 0x2, 0x2, 
    0x2, 0x1c0, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1bf, 0x3, 0x2, 0x2, 
    0x2, 0x1c1, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x1c3, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c6, 0x5, 0xac, 0x57, 0x2, 
    0x1c5, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c7, 0x3, 0x2, 0x2, 0x2, 
    0x1c7, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c8, 0x3, 0x2, 0x2, 0x2, 
    0x1c8, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1ca, 0x7, 0x5, 0x2, 0x2, 
    0x1ca, 0x1cb, 0x5, 0x22, 0x12, 0x2, 0x1cb, 0x1cc, 0x7, 0x6, 0x2, 0x2, 
    0x1cc, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1ce, 0x7, 0x5, 0x2, 0x2, 
    0x1ce, 0x1cf, 0x5, 0x22, 0x12, 0x2, 0x1cf, 0x1d0, 0x7, 0x7, 0x2, 0x2, 
    0x1d0, 0x1d1, 0x5, 0x22, 0x12, 0x2, 0x1d1, 0x1d2, 0x7, 0x6, 0x2, 0x2, 
    0x1d2, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1c9, 0x3, 0x2, 0x2, 0x2, 
    0x1d3, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d4, 0x3, 0x2, 0x2, 0x2, 
    0x1d4, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d6, 0x7, 0x33, 0x2, 0x2, 
    0x1d6, 0x1d8, 0x5, 0xac, 0x57, 0x2, 0x1d7, 0x1d5, 0x3, 0x2, 0x2, 0x2, 
    0x1d7, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x208, 0x3, 0x2, 0x2, 0x2, 
    0x1d9, 0x1da, 0x7, 0x73, 0x2, 0x2, 0x1da, 0x1dc, 0x7, 0x61, 0x2, 0x2, 
    0x1db, 0x1dd, 0x5, 0x88, 0x45, 0x2, 0x1dc, 0x1db, 0x3, 0x2, 0x2, 0x2, 
    0x1dc, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1df, 0x3, 0x2, 0x2, 0x2, 
    0x1de, 0x1e0, 0x5, 0x28, 0x15, 0x2, 0x1df, 0x1de, 0x3, 0x2, 0x2, 0x2, 
    0x1df, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e2, 0x3, 0x2, 0x2, 0x2, 
    0x1e1, 0x1e3, 0x7, 0x26, 0x2, 0x2, 0x1e2, 0x1e1, 0x3, 0x2, 0x2, 0x2, 
    0x1e2, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x209, 0x3, 0x2, 0x2, 0x2, 
    0x1e4, 0x1e5, 0x7, 0x68, 0x2, 0x2, 0x1e5, 0x1e8, 0x7, 0x6a, 0x2, 0x2, 
    0x1e6, 0x1e8, 0x7, 0x8d, 0x2, 0x2, 0x1e7, 0x1e4, 0x3, 0x2, 0x2, 0x2, 
    0x1e7, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1ea, 0x3, 0x2, 0x2, 0x2, 
    0x1e9, 0x1eb, 0x5, 0x28, 0x15, 0x2, 0x1ea, 0x1e9, 0x3, 0x2, 0x2, 0x2, 
    0x1ea, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x209, 0x3, 0x2, 0x2, 0x2, 
    0x1ec, 0x1ed, 0x7, 0x2e, 0x2, 0x2, 0x1ed, 0x1ee, 0x7, 0x5, 0x2, 0x2, 
    0x1ee, 0x1ef, 0x5, 0x40, 0x21, 0x2, 0x1ef, 0x1f0, 0x7, 0x6, 0x2, 0x2, 
    0x1f0, 0x209, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f8, 0x7, 0x3a, 0x2, 0x2, 
    0x1f2, 0x1f9, 0x5, 0x22, 0x12, 0x2, 0x1f3, 0x1f9, 0x5, 0x44, 0x23, 0x2, 
    0x1f4, 0x1f5, 0x7, 0x5, 0x2, 0x2, 0x1f5, 0x1f6, 0x5, 0x40, 0x21, 0x2, 
    0x1f6, 0x1f7, 0x7, 0x6, 0x2, 0x2, 0x1f7, 0x1f9, 0x3, 0x2, 0x2, 0x2, 
    0x1f8, 0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1f3, 0x3, 0x2, 0x2, 0x2, 
    0x1f8, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x209, 0x3, 0x2, 0x2, 0x2, 
    0x1fa, 0x1fb, 0x7, 0x2f, 0x2, 0x2, 0x1fb, 0x209, 0x5, 0xba, 0x5e, 0x2, 
    0x1fc, 0x209, 0x5, 0x26, 0x14, 0x2, 0x1fd, 0x1fe, 0x7, 0xaa, 0x2, 0x2, 
    0x1fe, 0x200, 0x7, 0xab, 0x2, 0x2, 0x1ff, 0x1fd, 0x3, 0x2, 0x2, 0x2, 
    0x1ff, 0x200, 0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 0x3, 0x2, 0x2, 0x2, 
    0x201, 0x202, 0x7, 0x23, 0x2, 0x2, 0x202, 0x203, 0x7, 0x5, 0x2, 0x2, 
    0x203, 0x204, 0x5, 0x40, 0x21, 0x2, 0x204, 0x206, 0x7, 0x6, 0x2, 0x2, 
    0x205, 0x207, 0x9, 0x5, 0x2, 0x2, 0x206, 0x205, 0x3, 0x2, 0x2, 0x2, 
    0x206, 0x207, 0x3, 0x2, 0x2, 0x2, 0x207, 0x209, 0x3, 0x2, 0x2, 0x2, 
    0x208, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x208, 0x1e7, 0x3, 0x2, 0x2, 0x2, 
    0x208, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x208, 0x1f1, 0x3, 0x2, 0x2, 0x2, 
    0x208, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x208, 0x1fc, 0x3, 0x2, 0x2, 0x2, 
    0x208, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x209, 0x21, 0x3, 0x2, 0x2, 0x2, 0x20a, 
    0x20c, 0x9, 0x6, 0x2, 0x2, 0x20b, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x20b, 
    0x20c, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x20d, 
    0x20e, 0x7, 0xbb, 0x2, 0x2, 0x20e, 0x23, 0x3, 0x2, 0x2, 0x2, 0x20f, 
    0x210, 0x7, 0x33, 0x2, 0x2, 0x210, 0x212, 0x5, 0xac, 0x57, 0x2, 0x211, 
    0x20f, 0x3, 0x2, 0x2, 0x2, 0x211, 0x212, 0x3, 0x2, 0x2, 0x2, 0x212, 
    0x238, 0x3, 0x2, 0x2, 0x2, 0x213, 0x214, 0x7, 0x73, 0x2, 0x2, 0x214, 
    0x217, 0x7, 0x61, 0x2, 0x2, 0x215, 0x217, 0x7, 0x8d, 0x2, 0x2, 0x216, 
    0x213, 0x3, 0x2, 0x2, 0x2, 0x216, 0x215, 0x3, 0x2, 0x2, 0x2, 0x217, 
    0x218, 0x3, 0x2, 0x2, 0x2, 0x218, 0x219, 0x7, 0x5, 0x2, 0x2, 0x219, 
    0x21e, 0x5, 0x18, 0xd, 0x2, 0x21a, 0x21b, 0x7, 0x7, 0x2, 0x2, 0x21b, 
    0x21d, 0x5, 0x18, 0xd, 0x2, 0x21c, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x21d, 
    0x220, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x21e, 
    0x21f, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x221, 0x3, 0x2, 0x2, 0x2, 0x220, 
    0x21e, 0x3, 0x2, 0x2, 0x2, 0x221, 0x223, 0x7, 0x6, 0x2, 0x2, 0x222, 
    0x224, 0x5, 0x28, 0x15, 0x2, 0x223, 0x222, 0x3, 0x2, 0x2, 0x2, 0x223, 
    0x224, 0x3, 0x2, 0x2, 0x2, 0x224, 0x239, 0x3, 0x2, 0x2, 0x2, 0x225, 
    0x226, 0x7, 0x2e, 0x2, 0x2, 0x226, 0x227, 0x7, 0x5, 0x2, 0x2, 0x227, 
    0x228, 0x5, 0x40, 0x21, 0x2, 0x228, 0x229, 0x7, 0x6, 0x2, 0x2, 0x229, 
    0x239, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x22b, 0x7, 0x4c, 0x2, 0x2, 0x22b, 
    0x22c, 0x7, 0x61, 0x2, 0x2, 0x22c, 0x22d, 0x7, 0x5, 0x2, 0x2, 0x22d, 
    0x232, 0x5, 0xb8, 0x5d, 0x2, 0x22e, 0x22f, 0x7, 0x7, 0x2, 0x2, 0x22f, 
    0x231, 0x5, 0xb8, 0x5d, 0x2, 0x230, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x231, 
    0x234, 0x3, 0x2, 0x2, 0x2, 0x232, 0x230, 0x3, 0x2, 0x2, 0x2, 0x232, 
    0x233, 0x3, 0x2, 0x2, 0x2, 0x233, 0x235, 0x3, 0x2, 0x2, 0x2, 0x234, 
    0x232, 0x3, 0x2, 0x2, 0x2, 0x235, 0x236, 0x7, 0x6, 0x2, 0x2, 0x236, 
    0x237, 0x5, 0x26, 0x14, 0x2, 0x237, 0x239, 0x3, 0x2, 0x2, 0x2, 0x238, 
    0x216, 0x3, 0x2, 0x2, 0x2, 0x238, 0x225, 0x3, 0x2, 0x2, 0x2, 0x238, 
    0x22a, 0x3, 0x2, 0x2, 0x2, 0x239, 0x25, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x23b, 
    0x7, 0x77, 0x2, 0x2, 0x23b, 0x247, 0x5, 0xbc, 0x5f, 0x2, 0x23c, 0x23d, 
    0x7, 0x5, 0x2, 0x2, 0x23d, 0x242, 0x5, 0xb8, 0x5d, 0x2, 0x23e, 0x23f, 
    0x7, 0x7, 0x2, 0x2, 0x23f, 0x241, 0x5, 0xb8, 0x5d, 0x2, 0x240, 0x23e, 
    0x3, 0x2, 0x2, 0x2, 0x241, 0x244, 0x3, 0x2, 0x2, 0x2, 0x242, 0x240, 
    0x3, 0x2, 0x2, 0x2, 0x242, 0x243, 0x3, 0x2, 0x2, 0x2, 0x243, 0x245, 
    0x3, 0x2, 0x2, 0x2, 0x244, 0x242, 0x3, 0x2, 0x2, 0x2, 0x245, 0x246, 
    0x7, 0x6, 0x2, 0x2, 0x246, 0x248, 0x3, 0x2, 0x2, 0x2, 0x247, 0x23c, 
    0x3, 0x2, 0x2, 0x2, 0x247, 0x248, 0x3, 0x2, 0x2, 0x2, 0x248, 0x257, 
    0x3, 0x2, 0x2, 0x2, 0x249, 0x24a, 0x7, 0x6d, 0x2, 0x2, 0x24a, 0x251, 
    0x9, 0x7, 0x2, 0x2, 0x24b, 0x24c, 0x7, 0x84, 0x2, 0x2, 0x24c, 0x252, 
    0x9, 0x8, 0x2, 0x2, 0x24d, 0x252, 0x7, 0x2b, 0x2, 0x2, 0x24e, 0x252, 
    0x7, 0x7d, 0x2, 0x2, 0x24f, 0x250, 0x7, 0x67, 0x2, 0x2, 0x250, 0x252, 
    0x7, 0x1c, 0x2, 0x2, 0x251, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x251, 0x24d, 
    0x3, 0x2, 0x2, 0x2, 0x251, 0x24e, 0x3, 0x2, 0x2, 0x2, 0x251, 0x24f, 
    0x3, 0x2, 0x2, 0x2, 0x252, 0x256, 0x3, 0x2, 0x2, 0x2, 0x253, 0x254, 
    0x7, 0x65, 0x2, 0x2, 0x254, 0x256, 0x5, 0xac, 0x57, 0x2, 0x255, 0x249, 
    0x3, 0x2, 0x2, 0x2, 0x255, 0x253, 0x3, 0x2, 0x2, 0x2, 0x256, 0x259, 
    0x3, 0x2, 0x2, 0x2, 0x257, 0x255, 0x3, 0x2, 0x2, 0x2, 0x257, 0x258, 
    0x3, 0x2, 0x2, 0x2, 0x258, 0x262, 0x3, 0x2, 0x2, 0x2, 0x259, 0x257, 
    0x3, 0x2, 0x2, 0x2, 0x25a, 0x25c, 0x7, 0x68, 0x2, 0x2, 0x25b, 0x25a, 
    0x3, 0x2, 0x2, 0x2, 0x25b, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x25d, 
    0x3, 0x2, 0x2, 0x2, 0x25d, 0x260, 0x7, 0x3b, 0x2, 0x2, 0x25e, 0x25f, 
    0x7, 0x58, 0x2, 0x2, 0x25f, 0x261, 0x9, 0x9, 0x2, 0x2, 0x260, 0x25e, 
    0x3, 0x2, 0x2, 0x2, 0x260, 0x261, 0x3, 0x2, 0x2, 0x2, 0x261, 0x263, 
    0x3, 0x2, 0x2, 0x2, 0x262, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x262, 0x263, 
    0x3, 0x2, 0x2, 0x2, 0x263, 0x27, 0x3, 0x2, 0x2, 0x2, 0x264, 0x265, 0x7, 
    0x6d, 0x2, 0x2, 0x265, 0x266, 0x7, 0x32, 0x2, 0x2, 0x266, 0x267, 0x9, 
    0xa, 0x2, 0x2, 0x267, 0x29, 0x3, 0x2, 0x2, 0x2, 0x268, 0x26a, 0x7, 0x34, 
    0x2, 0x2, 0x269, 0x26b, 0x9, 0x4, 0x2, 0x2, 0x26a, 0x269, 0x3, 0x2, 
    0x2, 0x2, 0x26a, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26c, 0x3, 0x2, 
    0x2, 0x2, 0x26c, 0x270, 0x7, 0x8b, 0x2, 0x2, 0x26d, 0x26e, 0x7, 0x52, 
    0x2, 0x2, 0x26e, 0x26f, 0x7, 0x68, 0x2, 0x2, 0x26f, 0x271, 0x7, 0x48, 
    0x2, 0x2, 0x270, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x270, 0x271, 0x3, 0x2, 
    0x2, 0x2, 0x271, 0x275, 0x3, 0x2, 0x2, 0x2, 0x272, 0x273, 0x5, 0xb0, 
    0x59, 0x2, 0x273, 0x274, 0x7, 0x4, 0x2, 0x2, 0x274, 0x276, 0x3, 0x2, 
    0x2, 0x2, 0x275, 0x272, 0x3, 0x2, 0x2, 0x2, 0x275, 0x276, 0x3, 0x2, 
    0x2, 0x2, 0x276, 0x277, 0x3, 0x2, 0x2, 0x2, 0x277, 0x27c, 0x5, 0xc0, 
    0x61, 0x2, 0x278, 0x27d, 0x7, 0x27, 0x2, 0x2, 0x279, 0x27d, 0x7, 0x1e, 
    0x2, 0x2, 0x27a, 0x27b, 0x7, 0x5b, 0x2, 0x2, 0x27b, 0x27d, 0x7, 0x6b, 
    0x2, 0x2, 0x27c, 0x278, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x279, 0x3, 0x2, 
    0x2, 0x2, 0x27c, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27d, 0x3, 0x2, 
    0x2, 0x2, 0x27d, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x28d, 0x7, 0x3d, 
    0x2, 0x2, 0x27f, 0x28d, 0x7, 0x5a, 0x2, 0x2, 0x280, 0x28a, 0x7, 0x8e, 
    0x2, 0x2, 0x281, 0x282, 0x7, 0x6b, 0x2, 0x2, 0x282, 0x287, 0x5, 0xb8, 
    0x5d, 0x2, 0x283, 0x284, 0x7, 0x7, 0x2, 0x2, 0x284, 0x286, 0x5, 0xb8, 
    0x5d, 0x2, 0x285, 0x283, 0x3, 0x2, 0x2, 0x2, 0x286, 0x289, 0x3, 0x2, 
    0x2, 0x2, 0x287, 0x285, 0x3, 0x2, 0x2, 0x2, 0x287, 0x288, 0x3, 0x2, 
    0x2, 0x2, 0x288, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x289, 0x287, 0x3, 0x2, 
    0x2, 0x2, 0x28a, 0x281, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x28b, 0x3, 0x2, 
    0x2, 0x2, 0x28b, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x27e, 0x3, 0x2, 
    0x2, 0x2, 0x28c, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x280, 0x3, 0x2, 
    0x2, 0x2, 0x28d, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x28e, 0x28f, 0x7, 0x6d, 
    0x2, 0x2, 0x28f, 0x293, 0x5, 0xb2, 0x5a, 0x2, 0x290, 0x291, 0x7, 0x4b, 
    0x2, 0x2, 0x291, 0x292, 0x7, 0x42, 0x2, 0x2, 0x292, 0x294, 0x7, 0x80, 
    0x2, 0x2, 0x293, 0x290, 0x3, 0x2, 0x2, 0x2, 0x293, 0x294, 0x3, 0x2, 
    0x2, 0x2, 0x294, 0x297, 0x3, 0x2, 0x2, 0x2, 0x295, 0x296, 0x7, 0x94, 
    0x2, 0x2, 0x296, 0x298, 0x5, 0x40, 0x21, 0x2, 0x297, 0x295, 0x3, 0x2, 
    0x2, 0x2, 0x297, 0x298, 0x3, 0x2, 0x2, 0x2, 0x298, 0x299, 0x3, 0x2, 
    0x2, 0x2, 0x299, 0x2a2, 0x7, 0x28, 0x2, 0x2, 0x29a, 0x29f, 0x5, 0x66, 
    0x34, 0x2, 0x29b, 0x29f, 0x5, 0x46, 0x24, 0x2, 0x29c, 0x29f, 0x5, 0x38, 
    0x1d, 0x2, 0x29d, 0x29f, 0x5, 0x50, 0x29, 0x2, 0x29e, 0x29a, 0x3, 0x2, 
    0x2, 0x2, 0x29e, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x29c, 0x3, 0x2, 
    0x2, 0x2, 0x29e, 0x29d, 0x3, 0x2, 0x2, 0x2, 0x29f, 0x2a0, 0x3, 0x2, 
    0x2, 0x2, 0x2a0, 0x2a1, 0x7, 0x3, 0x2, 0x2, 0x2a1, 0x2a3, 0x3, 0x2, 
    0x2, 0x2, 0x2a2, 0x29e, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x2a4, 0x3, 0x2, 
    0x2, 0x2, 0x2a4, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a5, 0x3, 0x2, 
    0x2, 0x2, 0x2a5, 0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a7, 0x7, 0x44, 
    0x2, 0x2, 0x2a7, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x2aa, 0x7, 0x34, 
    0x2, 0x2, 0x2a9, 0x2ab, 0x9, 0x4, 0x2, 0x2, 0x2aa, 0x2a9, 0x3, 0x2, 
    0x2, 0x2, 0x2aa, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2ac, 0x3, 0x2, 
    0x2, 0x2, 0x2ac, 0x2b0, 0x7, 0x92, 0x2, 0x2, 0x2ad, 0x2ae, 0x7, 0x52, 
    0x2, 0x2, 0x2ae, 0x2af, 0x7, 0x68, 0x2, 0x2, 0x2af, 0x2b1, 0x7, 0x48, 
    0x2, 0x2, 0x2b0, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2b1, 0x3, 0x2, 
    0x2, 0x2, 0x2b1, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b3, 0x5, 0xb0, 
    0x59, 0x2, 0x2b3, 0x2b4, 0x7, 0x4, 0x2, 0x2, 0x2b4, 0x2b6, 0x3, 0x2, 
    0x2, 0x2, 0x2b5, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2b5, 0x2b6, 0x3, 0x2, 
    0x2, 0x2, 0x2b6, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2c3, 0x5, 0xc2, 
    0x62, 0x2, 0x2b8, 0x2b9, 0x7, 0x5, 0x2, 0x2, 0x2b9, 0x2be, 0x5, 0xb8, 
    0x5d, 0x2, 0x2ba, 0x2bb, 0x7, 0x7, 0x2, 0x2, 0x2bb, 0x2bd, 0x5, 0xb8, 
    0x5d, 0x2, 0x2bc, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2c0, 0x3, 0x2, 
    0x2, 0x2, 0x2be, 0x2bc, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bf, 0x3, 0x2, 
    0x2, 0x2, 0x2bf, 0x2c1, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2be, 0x3, 0x2, 
    0x2, 0x2, 0x2c1, 0x2c2, 0x7, 0x6, 0x2, 0x2, 0x2c2, 0x2c4, 0x3, 0x2, 
    0x2, 0x2, 0x2c3, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c4, 0x3, 0x2, 
    0x2, 0x2, 0x2c4, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c6, 0x7, 0x23, 
    0x2, 0x2, 0x2c6, 0x2c7, 0x5, 0x50, 0x29, 0x2, 0x2c7, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0x2c8, 0x2c9, 0x7, 0x34, 0x2, 0x2, 0x2c9, 0x2ca, 0x7, 0x93, 
    0x2, 0x2, 0x2ca, 0x2ce, 0x7, 0x85, 0x2, 0x2, 0x2cb, 0x2cc, 0x7, 0x52, 
    0x2, 0x2, 0x2cc, 0x2cd, 0x7, 0x68, 0x2, 0x2, 0x2cd, 0x2cf, 0x7, 0x48, 
    0x2, 0x2, 0x2ce, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2cf, 0x3, 0x2, 
    0x2, 0x2, 0x2cf, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2d1, 0x5, 0xb0, 
    0x59, 0x2, 0x2d1, 0x2d2, 0x7, 0x4, 0x2, 0x2, 0x2d2, 0x2d4, 0x3, 0x2, 
    0x2, 0x2, 0x2d3, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2d3, 0x2d4, 0x3, 0x2, 
    0x2, 0x2, 0x2d4, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d6, 0x5, 0xb2, 
    0x5a, 0x2, 0x2d6, 0x2d7, 0x7, 0x8f, 0x2, 0x2, 0x2d7, 0x2e3, 0x5, 0xc4, 
    0x63, 0x2, 0x2d8, 0x2d9, 0x7, 0x5, 0x2, 0x2, 0x2d9, 0x2de, 0x5, 0xa6, 
    0x54, 0x2, 0x2da, 0x2db, 0x7, 0x7, 0x2, 0x2, 0x2db, 0x2dd, 0x5, 0xa6, 
    0x54, 0x2, 0x2dc, 0x2da, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2e0, 0x3, 0x2, 
    0x2, 0x2, 0x2de, 0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2df, 0x3, 0x2, 
    0x2, 0x2, 0x2df, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2de, 0x3, 0x2, 
    0x2, 0x2, 0x2e1, 0x2e2, 0x7, 0x6, 0x2, 0x2, 0x2e2, 0x2e4, 0x3, 0x2, 
    0x2, 0x2, 0x2e3, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2e3, 0x2e4, 0x3, 0x2, 
    0x2, 0x2, 0x2e4, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e7, 0x7, 0x96, 
    0x2, 0x2, 0x2e6, 0x2e8, 0x7, 0x76, 0x2, 0x2, 0x2e7, 0x2e6, 0x3, 0x2, 
    0x2, 0x2, 0x2e7, 0x2e8, 0x3, 0x2, 0x2, 0x2, 0x2e8, 0x2e9, 0x3, 0x2, 
    0x2, 0x2, 0x2e9, 0x2ea, 0x5, 0x32, 0x1a, 0x2, 0x2ea, 0x2eb, 0x7, 0x23, 
    0x2, 0x2, 0x2eb, 0x2ec, 0x7, 0x5, 0x2, 0x2, 0x2ec, 0x2ed, 0x5, 0x50, 
    0x29, 0x2, 0x2ed, 0x2f7, 0x7, 0x6, 0x2, 0x2, 0x2ee, 0x2ef, 0x7, 0x7, 
    0x2, 0x2, 0x2ef, 0x2f0, 0x5, 0x32, 0x1a, 0x2, 0x2f0, 0x2f1, 0x7, 0x23, 
    0x2, 0x2, 0x2f1, 0x2f2, 0x7, 0x5, 0x2, 0x2, 0x2f2, 0x2f3, 0x5, 0x50, 
    0x29, 0x2, 0x2f3, 0x2f4, 0x7, 0x6, 0x2, 0x2, 0x2f4, 0x2f6, 0x3, 0x2, 
    0x2, 0x2, 0x2f5, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f9, 0x3, 0x2, 
    0x2, 0x2, 0x2f7, 0x2f5, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f8, 0x3, 0x2, 
    0x2, 0x2, 0x2f8, 0x31, 0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2f7, 0x3, 0x2, 0x2, 
    0x2, 0x2fa, 0x306, 0x5, 0xb2, 0x5a, 0x2, 0x2fb, 0x2fc, 0x7, 0x5, 0x2, 
    0x2, 0x2fc, 0x301, 0x5, 0xb8, 0x5d, 0x2, 0x2fd, 0x2fe, 0x7, 0x7, 0x2, 
    0x2, 0x2fe, 0x300, 0x5, 0xb8, 0x5d, 0x2, 0x2ff, 0x2fd, 0x3, 0x2, 0x2, 
    0x2, 0x300, 0x303, 0x3, 0x2, 0x2, 0x2, 0x301, 0x2ff, 0x3, 0x2, 0x2, 
    0x2, 0x301, 0x302, 0x3, 0x2, 0x2, 0x2, 0x302, 0x304, 0x3, 0x2, 0x2, 
    0x2, 0x303, 0x301, 0x3, 0x2, 0x2, 0x2, 0x304, 0x305, 0x7, 0x6, 0x2, 
    0x2, 0x305, 0x307, 0x3, 0x2, 0x2, 0x2, 0x306, 0x2fb, 0x3, 0x2, 0x2, 
    0x2, 0x306, 0x307, 0x3, 0x2, 0x2, 0x2, 0x307, 0x33, 0x3, 0x2, 0x2, 0x2, 
    0x308, 0x309, 0x5, 0x32, 0x1a, 0x2, 0x309, 0x30a, 0x7, 0x23, 0x2, 0x2, 
    0x30a, 0x30b, 0x7, 0x5, 0x2, 0x2, 0x30b, 0x30c, 0x5, 0x9e, 0x50, 0x2, 
    0x30c, 0x30e, 0x7, 0x8c, 0x2, 0x2, 0x30d, 0x30f, 0x7, 0x1f, 0x2, 0x2, 
    0x30e, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x30e, 0x30f, 0x3, 0x2, 0x2, 0x2, 
    0x30f, 0x310, 0x3, 0x2, 0x2, 0x2, 0x310, 0x311, 0x5, 0xa0, 0x51, 0x2, 
    0x311, 0x312, 0x7, 0x6, 0x2, 0x2, 0x312, 0x35, 0x3, 0x2, 0x2, 0x2, 0x313, 
    0x31f, 0x5, 0xb2, 0x5a, 0x2, 0x314, 0x315, 0x7, 0x5, 0x2, 0x2, 0x315, 
    0x31a, 0x5, 0xb8, 0x5d, 0x2, 0x316, 0x317, 0x7, 0x7, 0x2, 0x2, 0x317, 
    0x319, 0x5, 0xb8, 0x5d, 0x2, 0x318, 0x316, 0x3, 0x2, 0x2, 0x2, 0x319, 
    0x31c, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x318, 0x3, 0x2, 0x2, 0x2, 0x31a, 
    0x31b, 0x3, 0x2, 0x2, 0x2, 0x31b, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x31c, 
    0x31a, 0x3, 0x2, 0x2, 0x2, 0x31d, 0x31e, 0x7, 0x6, 0x2, 0x2, 0x31e, 
    0x320, 0x3, 0x2, 0x2, 0x2, 0x31f, 0x314, 0x3, 0x2, 0x2, 0x2, 0x31f, 
    0x320, 0x3, 0x2, 0x2, 0x2, 0x320, 0x321, 0x3, 0x2, 0x2, 0x2, 0x321, 
    0x322, 0x7, 0x23, 0x2, 0x2, 0x322, 0x323, 0x7, 0x5, 0x2, 0x2, 0x323, 
    0x324, 0x5, 0x50, 0x29, 0x2, 0x324, 0x325, 0x7, 0x6, 0x2, 0x2, 0x325, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x326, 0x328, 0x5, 0x30, 0x19, 0x2, 0x327, 
    0x326, 0x3, 0x2, 0x2, 0x2, 0x327, 0x328, 0x3, 0x2, 0x2, 0x2, 0x328, 
    0x329, 0x3, 0x2, 0x2, 0x2, 0x329, 0x32a, 0x7, 0x3d, 0x2, 0x2, 0x32a, 
    0x32b, 0x7, 0x4d, 0x2, 0x2, 0x32b, 0x32e, 0x5, 0x6c, 0x37, 0x2, 0x32c, 
    0x32d, 0x7, 0x95, 0x2, 0x2, 0x32d, 0x32f, 0x5, 0x40, 0x21, 0x2, 0x32e, 
    0x32c, 0x3, 0x2, 0x2, 0x2, 0x32e, 0x32f, 0x3, 0x2, 0x2, 0x2, 0x32f, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x330, 0x332, 0x5, 0x30, 0x19, 0x2, 0x331, 
    0x330, 0x3, 0x2, 0x2, 0x2, 0x331, 0x332, 0x3, 0x2, 0x2, 0x2, 0x332, 
    0x333, 0x3, 0x2, 0x2, 0x2, 0x333, 0x334, 0x7, 0x3d, 0x2, 0x2, 0x334, 
    0x335, 0x7, 0x4d, 0x2, 0x2, 0x335, 0x338, 0x5, 0x6c, 0x37, 0x2, 0x336, 
    0x337, 0x7, 0x95, 0x2, 0x2, 0x337, 0x339, 0x5, 0x40, 0x21, 0x2, 0x338, 
    0x336, 0x3, 0x2, 0x2, 0x2, 0x338, 0x339, 0x3, 0x2, 0x2, 0x2, 0x339, 
    0x33e, 0x3, 0x2, 0x2, 0x2, 0x33a, 0x33c, 0x5, 0x82, 0x42, 0x2, 0x33b, 
    0x33a, 0x3, 0x2, 0x2, 0x2, 0x33b, 0x33c, 0x3, 0x2, 0x2, 0x2, 0x33c, 
    0x33d, 0x3, 0x2, 0x2, 0x2, 0x33d, 0x33f, 0x5, 0x84, 0x43, 0x2, 0x33e, 
    0x33b, 0x3, 0x2, 0x2, 0x2, 0x33e, 0x33f, 0x3, 0x2, 0x2, 0x2, 0x33f, 
    0x3b, 0x3, 0x2, 0x2, 0x2, 0x340, 0x342, 0x7, 0x3f, 0x2, 0x2, 0x341, 
    0x343, 0x7, 0x39, 0x2, 0x2, 0x342, 0x341, 0x3, 0x2, 0x2, 0x2, 0x342, 
    0x343, 0x3, 0x2, 0x2, 0x2, 0x343, 0x344, 0x3, 0x2, 0x2, 0x2, 0x344, 
    0x345, 0x5, 0xb0, 0x59, 0x2, 0x345, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x346, 
    0x347, 0x7, 0x41, 0x2, 0x2, 0x347, 0x34a, 0x9, 0xb, 0x2, 0x2, 0x348, 
    0x349, 0x7, 0x52, 0x2, 0x2, 0x349, 0x34b, 0x7, 0x48, 0x2, 0x2, 0x34a, 
    0x348, 0x3, 0x2, 0x2, 0x2, 0x34a, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x34b, 
    0x34f, 0x3, 0x2, 0x2, 0x2, 0x34c, 0x34d, 0x5, 0xb0, 0x59, 0x2, 0x34d, 
    0x34e, 0x7, 0x4, 0x2, 0x2, 0x34e, 0x350, 0x3, 0x2, 0x2, 0x2, 0x34f, 
    0x34c, 0x3, 0x2, 0x2, 0x2, 0x34f, 0x350, 0x3, 0x2, 0x2, 0x2, 0x350, 
    0x351, 0x3, 0x2, 0x2, 0x2, 0x351, 0x352, 0x5, 0xdc, 0x6f, 0x2, 0x352, 
    0x3f, 0x3, 0x2, 0x2, 0x2, 0x353, 0x354, 0x8, 0x21, 0x1, 0x2, 0x354, 
    0x3ac, 0x5, 0x44, 0x23, 0x2, 0x355, 0x3ac, 0x7, 0xbc, 0x2, 0x2, 0x356, 
    0x357, 0x5, 0xb0, 0x59, 0x2, 0x357, 0x358, 0x7, 0x4, 0x2, 0x2, 0x358, 
    0x35a, 0x3, 0x2, 0x2, 0x2, 0x359, 0x356, 0x3, 0x2, 0x2, 0x2, 0x359, 
    0x35a, 0x3, 0x2, 0x2, 0x2, 0x35a, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x35b, 
    0x35c, 0x5, 0xb2, 0x5a, 0x2, 0x35c, 0x35d, 0x7, 0x4, 0x2, 0x2, 0x35d, 
    0x35f, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x359, 0x3, 0x2, 0x2, 0x2, 0x35e, 
    0x35f, 0x3, 0x2, 0x2, 0x2, 0x35f, 0x360, 0x3, 0x2, 0x2, 0x2, 0x360, 
    0x3ac, 0x5, 0xb8, 0x5d, 0x2, 0x361, 0x362, 0x5, 0xa2, 0x52, 0x2, 0x362, 
    0x363, 0x5, 0x40, 0x21, 0x17, 0x363, 0x3ac, 0x3, 0x2, 0x2, 0x2, 0x364, 
    0x365, 0x5, 0xae, 0x58, 0x2, 0x365, 0x372, 0x7, 0x5, 0x2, 0x2, 0x366, 
    0x368, 0x7, 0x40, 0x2, 0x2, 0x367, 0x366, 0x3, 0x2, 0x2, 0x2, 0x367, 
    0x368, 0x3, 0x2, 0x2, 0x2, 0x368, 0x369, 0x3, 0x2, 0x2, 0x2, 0x369, 
    0x36e, 0x5, 0x40, 0x21, 0x2, 0x36a, 0x36b, 0x7, 0x7, 0x2, 0x2, 0x36b, 
    0x36d, 0x5, 0x40, 0x21, 0x2, 0x36c, 0x36a, 0x3, 0x2, 0x2, 0x2, 0x36d, 
    0x370, 0x3, 0x2, 0x2, 0x2, 0x36e, 0x36c, 0x3, 0x2, 0x2, 0x2, 0x36e, 
    0x36f, 0x3, 0x2, 0x2, 0x2, 0x36f, 0x373, 0x3, 0x2, 0x2, 0x2, 0x370, 
    0x36e, 0x3, 0x2, 0x2, 0x2, 0x371, 0x373, 0x7, 0x9, 0x2, 0x2, 0x372, 
    0x367, 0x3, 0x2, 0x2, 0x2, 0x372, 0x371, 0x3, 0x2, 0x2, 0x2, 0x372, 
    0x373, 0x3, 0x2, 0x2, 0x2, 0x373, 0x374, 0x3, 0x2, 0x2, 0x2, 0x374, 
    0x376, 0x7, 0x6, 0x2, 0x2, 0x375, 0x377, 0x5, 0x70, 0x39, 0x2, 0x376, 
    0x375, 0x3, 0x2, 0x2, 0x2, 0x376, 0x377, 0x3, 0x2, 0x2, 0x2, 0x377, 
    0x379, 0x3, 0x2, 0x2, 0x2, 0x378, 0x37a, 0x5, 0x74, 0x3b, 0x2, 0x379, 
    0x378, 0x3, 0x2, 0x2, 0x2, 0x379, 0x37a, 0x3, 0x2, 0x2, 0x2, 0x37a, 
    0x3ac, 0x3, 0x2, 0x2, 0x2, 0x37b, 0x37c, 0x7, 0x5, 0x2, 0x2, 0x37c, 
    0x381, 0x5, 0x40, 0x21, 0x2, 0x37d, 0x37e, 0x7, 0x7, 0x2, 0x2, 0x37e, 
    0x380, 0x5, 0x40, 0x21, 0x2, 0x37f, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x380, 
    0x383, 0x3, 0x2, 0x2, 0x2, 0x381, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x381, 
    0x382, 0x3, 0x2, 0x2, 0x2, 0x382, 0x384, 0x3, 0x2, 0x2, 0x2, 0x383, 
    0x381, 0x3, 0x2, 0x2, 0x2, 0x384, 0x385, 0x7, 0x6, 0x2, 0x2, 0x385, 
    0x3ac, 0x3, 0x2, 0x2, 0x2, 0x386, 0x387, 0x7, 0x2d, 0x2, 0x2, 0x387, 
    0x388, 0x7, 0x5, 0x2, 0x2, 0x388, 0x389, 0x5, 0x40, 0x21, 0x2, 0x389, 
    0x38a, 0x7, 0x23, 0x2, 0x2, 0x38a, 0x38b, 0x5, 0x1e, 0x10, 0x2, 0x38b, 
    0x38c, 0x7, 0x6, 0x2, 0x2, 0x38c, 0x3ac, 0x3, 0x2, 0x2, 0x2, 0x38d, 
    0x38f, 0x7, 0x68, 0x2, 0x2, 0x38e, 0x38d, 0x3, 0x2, 0x2, 0x2, 0x38e, 
    0x38f, 0x3, 0x2, 0x2, 0x2, 0x38f, 0x390, 0x3, 0x2, 0x2, 0x2, 0x390, 
    0x392, 0x7, 0x48, 0x2, 0x2, 0x391, 0x38e, 0x3, 0x2, 0x2, 0x2, 0x391, 
    0x392, 0x3, 0x2, 0x2, 0x2, 0x392, 0x393, 0x3, 0x2, 0x2, 0x2, 0x393, 
    0x394, 0x7, 0x5, 0x2, 0x2, 0x394, 0x395, 0x5, 0x50, 0x29, 0x2, 0x395, 
    0x396, 0x7, 0x6, 0x2, 0x2, 0x396, 0x3ac, 0x3, 0x2, 0x2, 0x2, 0x397, 
    0x399, 0x7, 0x2c, 0x2, 0x2, 0x398, 0x39a, 0x5, 0x40, 0x21, 0x2, 0x399, 
    0x398, 0x3, 0x2, 0x2, 0x2, 0x399, 0x39a, 0x3, 0x2, 0x2, 0x2, 0x39a, 
    0x3a0, 0x3, 0x2, 0x2, 0x2, 0x39b, 0x39c, 0x7, 0x94, 0x2, 0x2, 0x39c, 
    0x39d, 0x5, 0x40, 0x21, 0x2, 0x39d, 0x39e, 0x7, 0x88, 0x2, 0x2, 0x39e, 
    0x39f, 0x5, 0x40, 0x21, 0x2, 0x39f, 0x3a1, 0x3, 0x2, 0x2, 0x2, 0x3a0, 
    0x39b, 0x3, 0x2, 0x2, 0x2, 0x3a1, 0x3a2, 0x3, 0x2, 0x2, 0x2, 0x3a2, 
    0x3a0, 0x3, 0x2, 0x2, 0x2, 0x3a2, 0x3a3, 0x3, 0x2, 0x2, 0x2, 0x3a3, 
    0x3a6, 0x3, 0x2, 0x2, 0x2, 0x3a4, 0x3a5, 0x7, 0x43, 0x2, 0x2, 0x3a5, 
    0x3a7, 0x5, 0x40, 0x21, 0x2, 0x3a6, 0x3a4, 0x3, 0x2, 0x2, 0x2, 0x3a6, 
    0x3a7, 0x3, 0x2, 0x2, 0x2, 0x3a7, 0x3a8, 0x3, 0x2, 0x2, 0x2, 0x3a8, 
    0x3a9, 0x7, 0x44, 0x2, 0x2, 0x3a9, 0x3ac, 0x3, 0x2, 0x2, 0x2, 0x3aa, 
    0x3ac, 0x5, 0x42, 0x22, 0x2, 0x3ab, 0x353, 0x3, 0x2, 0x2, 0x2, 0x3ab, 
    0x355, 0x3, 0x2, 0x2, 0x2, 0x3ab, 0x35e, 0x3, 0x2, 0x2, 0x2, 0x3ab, 
    0x361, 0x3, 0x2, 0x2, 0x2, 0x3ab, 0x364, 0x3, 0x2, 0x2, 0x2, 0x3ab, 
    0x37b, 0x3, 0x2, 0x2, 0x2, 0x3ab, 0x386, 0x3, 0x2, 0x2, 0x2, 0x3ab, 
    0x391, 0x3, 0x2, 0x2, 0x2, 0x3ab, 0x397, 0x3, 0x2, 0x2, 0x2, 0x3ab, 
    0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3ac, 0x424, 0x3, 0x2, 0x2, 0x2, 0x3ad, 
    0x3ae, 0xc, 0x16, 0x2, 0x2, 0x3ae, 0x3af, 0x7, 0xd, 0x2, 0x2, 0x3af, 
    0x423, 0x5, 0x40, 0x21, 0x17, 0x3b0, 0x3b1, 0xc, 0x15, 0x2, 0x2, 0x3b1, 
    0x3b2, 0x9, 0xc, 0x2, 0x2, 0x3b2, 0x423, 0x5, 0x40, 0x21, 0x16, 0x3b3, 
    0x3b4, 0xc, 0x14, 0x2, 0x2, 0x3b4, 0x3b5, 0x9, 0x6, 0x2, 0x2, 0x3b5, 
    0x423, 0x5, 0x40, 0x21, 0x15, 0x3b6, 0x3b7, 0xc, 0x13, 0x2, 0x2, 0x3b7, 
    0x3b8, 0x9, 0xd, 0x2, 0x2, 0x3b8, 0x423, 0x5, 0x40, 0x21, 0x14, 0x3b9, 
    0x3ba, 0xc, 0x12, 0x2, 0x2, 0x3ba, 0x3bb, 0x9, 0xe, 0x2, 0x2, 0x3bb, 
    0x423, 0x5, 0x40, 0x21, 0x13, 0x3bc, 0x3c9, 0xc, 0x11, 0x2, 0x2, 0x3bd, 
    0x3ca, 0x7, 0x8, 0x2, 0x2, 0x3be, 0x3ca, 0x7, 0x18, 0x2, 0x2, 0x3bf, 
    0x3ca, 0x7, 0x19, 0x2, 0x2, 0x3c0, 0x3ca, 0x7, 0x1a, 0x2, 0x2, 0x3c1, 
    0x3ca, 0x7, 0x5e, 0x2, 0x2, 0x3c2, 0x3c3, 0x7, 0x5e, 0x2, 0x2, 0x3c3, 
    0x3ca, 0x7, 0x68, 0x2, 0x2, 0x3c4, 0x3ca, 0x7, 0x55, 0x2, 0x2, 0x3c5, 
    0x3ca, 0x7, 0x63, 0x2, 0x2, 0x3c6, 0x3ca, 0x7, 0x4f, 0x2, 0x2, 0x3c7, 
    0x3ca, 0x7, 0x65, 0x2, 0x2, 0x3c8, 0x3ca, 0x7, 0x78, 0x2, 0x2, 0x3c9, 
    0x3bd, 0x3, 0x2, 0x2, 0x2, 0x3c9, 0x3be, 0x3, 0x2, 0x2, 0x2, 0x3c9, 
    0x3bf, 0x3, 0x2, 0x2, 0x2, 0x3c9, 0x3c0, 0x3, 0x2, 0x2, 0x2, 0x3c9, 
    0x3c1, 0x3, 0x2, 0x2, 0x2, 0x3c9, 0x3c2, 0x3, 0x2, 0x2, 0x2, 0x3c9, 
    0x3c4, 0x3, 0x2, 0x2, 0x2, 0x3c9, 0x3c5, 0x3, 0x2, 0x2, 0x2, 0x3c9, 
    0x3c6, 0x3, 0x2, 0x2, 0x2, 0x3c9, 0x3c7, 0x3, 0x2, 0x2, 0x2, 0x3c9, 
    0x3c8, 0x3, 0x2, 0x2, 0x2, 0x3ca, 0x3cb, 0x3, 0x2, 0x2, 0x2, 0x3cb, 
    0x423, 0x5, 0x40, 0x21, 0x12, 0x3cc, 0x3cd, 0xc, 0x10, 0x2, 0x2, 0x3cd, 
    0x3ce, 0x7, 0x22, 0x2, 0x2, 0x3ce, 0x423, 0x5, 0x40, 0x21, 0x11, 0x3cf, 
    0x3d0, 0xc, 0xf, 0x2, 0x2, 0x3d0, 0x3d1, 0x7, 0x6e, 0x2, 0x2, 0x3d1, 
    0x423, 0x5, 0x40, 0x21, 0x10, 0x3d2, 0x3d3, 0xc, 0x8, 0x2, 0x2, 0x3d3, 
    0x3d5, 0x7, 0x5e, 0x2, 0x2, 0x3d4, 0x3d6, 0x7, 0x68, 0x2, 0x2, 0x3d5, 
    0x3d4, 0x3, 0x2, 0x2, 0x2, 0x3d5, 0x3d6, 0x3, 0x2, 0x2, 0x2, 0x3d6, 
    0x3d7, 0x3, 0x2, 0x2, 0x2, 0x3d7, 0x423, 0x5, 0x40, 0x21, 0x9, 0x3d8, 
    0x3da, 0xc, 0x7, 0x2, 0x2, 0x3d9, 0x3db, 0x7, 0x68, 0x2, 0x2, 0x3da, 
    0x3d9, 0x3, 0x2, 0x2, 0x2, 0x3da, 0x3db, 0x3, 0x2, 0x2, 0x2, 0x3db, 
    0x3dc, 0x3, 0x2, 0x2, 0x2, 0x3dc, 0x3dd, 0x7, 0x29, 0x2, 0x2, 0x3dd, 
    0x3de, 0x5, 0x40, 0x21, 0x2, 0x3de, 0x3df, 0x7, 0x22, 0x2, 0x2, 0x3df, 
    0x3e0, 0x5, 0x40, 0x21, 0x8, 0x3e0, 0x423, 0x3, 0x2, 0x2, 0x2, 0x3e1, 
    0x3e2, 0xc, 0xb, 0x2, 0x2, 0x3e2, 0x3e3, 0x7, 0x2f, 0x2, 0x2, 0x3e3, 
    0x423, 0x5, 0xba, 0x5e, 0x2, 0x3e4, 0x3e6, 0xc, 0xa, 0x2, 0x2, 0x3e5, 
    0x3e7, 0x7, 0x68, 0x2, 0x2, 0x3e6, 0x3e5, 0x3, 0x2, 0x2, 0x2, 0x3e6, 
    0x3e7, 0x3, 0x2, 0x2, 0x2, 0x3e7, 0x3e8, 0x3, 0x2, 0x2, 0x2, 0x3e8, 
    0x3e9, 0x9, 0xf, 0x2, 0x2, 0x3e9, 0x3ec, 0x5, 0x40, 0x21, 0x2, 0x3ea, 
    0x3eb, 0x7, 0x45, 0x2, 0x2, 0x3eb, 0x3ed, 0x5, 0x40, 0x21, 0x2, 0x3ec, 
    0x3ea, 0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3ed, 0x3, 0x2, 0x2, 0x2, 0x3ed, 
    0x423, 0x3, 0x2, 0x2, 0x2, 0x3ee, 0x3f3, 0xc, 0x9, 0x2, 0x2, 0x3ef, 
    0x3f4, 0x7, 0x5f, 0x2, 0x2, 0x3f0, 0x3f4, 0x7, 0x69, 0x2, 0x2, 0x3f1, 
    0x3f2, 0x7, 0x68, 0x2, 0x2, 0x3f2, 0x3f4, 0x7, 0x6a, 0x2, 0x2, 0x3f3, 
    0x3ef, 0x3, 0x2, 0x2, 0x2, 0x3f3, 0x3f0, 0x3, 0x2, 0x2, 0x2, 0x3f3, 
    0x3f1, 0x3, 0x2, 0x2, 0x2, 0x3f4, 0x423, 0x3, 0x2, 0x2, 0x2, 0x3f5, 
    0x3f7, 0xc, 0x6, 0x2, 0x2, 0x3f6, 0x3f8, 0x7, 0x68, 0x2, 0x2, 0x3f7, 
    0x3f6, 0x3, 0x2, 0x2, 0x2, 0x3f7, 0x3f8, 0x3, 0x2, 0x2, 0x2, 0x3f8, 
    0x3f9, 0x3, 0x2, 0x2, 0x2, 0x3f9, 0x420, 0x7, 0x55, 0x2, 0x2, 0x3fa, 
    0x404, 0x7, 0x5, 0x2, 0x2, 0x3fb, 0x405, 0x5, 0x50, 0x29, 0x2, 0x3fc, 
    0x401, 0x5, 0x40, 0x21, 0x2, 0x3fd, 0x3fe, 0x7, 0x7, 0x2, 0x2, 0x3fe, 
    0x400, 0x5, 0x40, 0x21, 0x2, 0x3ff, 0x3fd, 0x3, 0x2, 0x2, 0x2, 0x400, 
    0x403, 0x3, 0x2, 0x2, 0x2, 0x401, 0x3ff, 0x3, 0x2, 0x2, 0x2, 0x401, 
    0x402, 0x3, 0x2, 0x2, 0x2, 0x402, 0x405, 0x3, 0x2, 0x2, 0x2, 0x403, 
    0x401, 0x3, 0x2, 0x2, 0x2, 0x404, 0x3fb, 0x3, 0x2, 0x2, 0x2, 0x404, 
    0x3fc, 0x3, 0x2, 0x2, 0x2, 0x404, 0x405, 0x3, 0x2, 0x2, 0x2, 0x405, 
    0x406, 0x3, 0x2, 0x2, 0x2, 0x406, 0x421, 0x7, 0x6, 0x2, 0x2, 0x407, 
    0x408, 0x5, 0xb0, 0x59, 0x2, 0x408, 0x409, 0x7, 0x4, 0x2, 0x2, 0x409, 
    0x40b, 0x3, 0x2, 0x2, 0x2, 0x40a, 0x407, 0x3, 0x2, 0x2, 0x2, 0x40a, 
    0x40b, 0x3, 0x2, 0x2, 0x2, 0x40b, 0x40c, 0x3, 0x2, 0x2, 0x2, 0x40c, 
    0x421, 0x5, 0xb2, 0x5a, 0x2, 0x40d, 0x40e, 0x5, 0xb0, 0x59, 0x2, 0x40e, 
    0x40f, 0x7, 0x4, 0x2, 0x2, 0x40f, 0x411, 0x3, 0x2, 0x2, 0x2, 0x410, 
    0x40d, 0x3, 0x2, 0x2, 0x2, 0x410, 0x411, 0x3, 0x2, 0x2, 0x2, 0x411, 
    0x412, 0x3, 0x2, 0x2, 0x2, 0x412, 0x413, 0x5, 0xda, 0x6e, 0x2, 0x413, 
    0x41c, 0x7, 0x5, 0x2, 0x2, 0x414, 0x419, 0x5, 0x40, 0x21, 0x2, 0x415, 
    0x416, 0x7, 0x7, 0x2, 0x2, 0x416, 0x418, 0x5, 0x40, 0x21, 0x2, 0x417, 
    0x415, 0x3, 0x2, 0x2, 0x2, 0x418, 0x41b, 0x3, 0x2, 0x2, 0x2, 0x419, 
    0x417, 0x3, 0x2, 0x2, 0x2, 0x419, 0x41a, 0x3, 0x2, 0x2, 0x2, 0x41a, 
    0x41d, 0x3, 0x2, 0x2, 0x2, 0x41b, 0x419, 0x3, 0x2, 0x2, 0x2, 0x41c, 
    0x414, 0x3, 0x2, 0x2, 0x2, 0x41c, 0x41d, 0x3, 0x2, 0x2, 0x2, 0x41d, 
    0x41e, 0x3, 0x2, 0x2, 0x2, 0x41e, 0x41f, 0x7, 0x6, 0x2, 0x2, 0x41f, 
    0x421, 0x3, 0x2, 0x2, 0x2, 0x420, 0x3fa, 0x3, 0x2, 0x2, 0x2, 0x420, 
    0x40a, 0x3, 0x2, 0x2, 0x2, 0x420, 0x410, 0x3, 0x2, 0x2, 0x2, 0x421, 
    0x423, 0x3, 0x2, 0x2, 0x2, 0x422, 0x3ad, 0x3, 0x2, 0x2, 0x2, 0x422, 
    0x3b0, 0x3, 0x2, 0x2, 0x2, 0x422, 0x3b3, 0x3, 0x2, 0x2, 0x2, 0x422, 
    0x3b6, 0x3, 0x2, 0x2, 0x2, 0x422, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0x422, 
    0x3bc, 0x3, 0x2, 0x2, 0x2, 0x422, 0x3cc, 0x3, 0x2, 0x2, 0x2, 0x422, 
    0x3cf, 0x3, 0x2, 0x2, 0x2, 0x422, 0x3d2, 0x3, 0x2, 0x2, 0x2, 0x422, 
    0x3d8, 0x3, 0x2, 0x2, 0x2, 0x422, 0x3e1, 0x3, 0x2, 0x2, 0x2, 0x422, 
    0x3e4, 0x3, 0x2, 0x2, 0x2, 0x422, 0x3ee, 0x3, 0x2, 0x2, 0x2, 0x422, 
    0x3f5, 0x3, 0x2, 0x2, 0x2, 0x423, 0x426, 0x3, 0x2, 0x2, 0x2, 0x424, 
    0x422, 0x3, 0x2, 0x2, 0x2, 0x424, 0x425, 0x3, 0x2, 0x2, 0x2, 0x425, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x426, 0x424, 0x3, 0x2, 0x2, 0x2, 0x427, 0x428, 
    0x7, 0x75, 0x2, 0x2, 0x428, 0x42d, 0x7, 0x5, 0x2, 0x2, 0x429, 0x42e, 
    0x7, 0x53, 0x2, 0x2, 0x42a, 0x42b, 0x9, 0x10, 0x2, 0x2, 0x42b, 0x42c, 
    0x7, 0x7, 0x2, 0x2, 0x42c, 0x42e, 0x5, 0xa4, 0x53, 0x2, 0x42d, 0x429, 
    0x3, 0x2, 0x2, 0x2, 0x42d, 0x42a, 0x3, 0x2, 0x2, 0x2, 0x42e, 0x42f, 
    0x3, 0x2, 0x2, 0x2, 0x42f, 0x430, 0x7, 0x6, 0x2, 0x2, 0x430, 0x43, 0x3, 
    0x2, 0x2, 0x2, 0x431, 0x432, 0x9, 0x11, 0x2, 0x2, 0x432, 0x45, 0x3, 
    0x2, 0x2, 0x2, 0x433, 0x435, 0x5, 0x30, 0x19, 0x2, 0x434, 0x433, 0x3, 
    0x2, 0x2, 0x2, 0x434, 0x435, 0x3, 0x2, 0x2, 0x2, 0x435, 0x43b, 0x3, 
    0x2, 0x2, 0x2, 0x436, 0x43c, 0x7, 0x5a, 0x2, 0x2, 0x437, 0x43c, 0x7, 
    0x7c, 0x2, 0x2, 0x438, 0x439, 0x7, 0x5a, 0x2, 0x2, 0x439, 0x43a, 0x7, 
    0x6e, 0x2, 0x2, 0x43a, 0x43c, 0x9, 0xa, 0x2, 0x2, 0x43b, 0x436, 0x3, 
    0x2, 0x2, 0x2, 0x43b, 0x437, 0x3, 0x2, 0x2, 0x2, 0x43b, 0x438, 0x3, 
    0x2, 0x2, 0x2, 0x43c, 0x43d, 0x3, 0x2, 0x2, 0x2, 0x43d, 0x441, 0x7, 
    0x5d, 0x2, 0x2, 0x43e, 0x43f, 0x5, 0xb0, 0x59, 0x2, 0x43f, 0x440, 0x7, 
    0x4, 0x2, 0x2, 0x440, 0x442, 0x3, 0x2, 0x2, 0x2, 0x441, 0x43e, 0x3, 
    0x2, 0x2, 0x2, 0x441, 0x442, 0x3, 0x2, 0x2, 0x2, 0x442, 0x443, 0x3, 
    0x2, 0x2, 0x2, 0x443, 0x446, 0x5, 0xb2, 0x5a, 0x2, 0x444, 0x445, 0x7, 
    0x23, 0x2, 0x2, 0x445, 0x447, 0x5, 0xca, 0x66, 0x2, 0x446, 0x444, 0x3, 
    0x2, 0x2, 0x2, 0x446, 0x447, 0x3, 0x2, 0x2, 0x2, 0x447, 0x453, 0x3, 
    0x2, 0x2, 0x2, 0x448, 0x449, 0x7, 0x5, 0x2, 0x2, 0x449, 0x44e, 0x5, 
    0xb8, 0x5d, 0x2, 0x44a, 0x44b, 0x7, 0x7, 0x2, 0x2, 0x44b, 0x44d, 0x5, 
    0xb8, 0x5d, 0x2, 0x44c, 0x44a, 0x3, 0x2, 0x2, 0x2, 0x44d, 0x450, 0x3, 
    0x2, 0x2, 0x2, 0x44e, 0x44c, 0x3, 0x2, 0x2, 0x2, 0x44e, 0x44f, 0x3, 
    0x2, 0x2, 0x2, 0x44f, 0x451, 0x3, 0x2, 0x2, 0x2, 0x450, 0x44e, 0x3, 
    0x2, 0x2, 0x2, 0x451, 0x452, 0x7, 0x6, 0x2, 0x2, 0x452, 0x454, 0x3, 
    0x2, 0x2, 0x2, 0x453, 0x448, 0x3, 0x2, 0x2, 0x2, 0x453, 0x454, 0x3, 
    0x2, 0x2, 0x2, 0x454, 0x472, 0x3, 0x2, 0x2, 0x2, 0x455, 0x456, 0x7, 
    0x91, 0x2, 0x2, 0x456, 0x457, 0x7, 0x5, 0x2, 0x2, 0x457, 0x45c, 0x5, 
    0x40, 0x21, 0x2, 0x458, 0x459, 0x7, 0x7, 0x2, 0x2, 0x459, 0x45b, 0x5, 
    0x40, 0x21, 0x2, 0x45a, 0x458, 0x3, 0x2, 0x2, 0x2, 0x45b, 0x45e, 0x3, 
    0x2, 0x2, 0x2, 0x45c, 0x45a, 0x3, 0x2, 0x2, 0x2, 0x45c, 0x45d, 0x3, 
    0x2, 0x2, 0x2, 0x45d, 0x45f, 0x3, 0x2, 0x2, 0x2, 0x45e, 0x45c, 0x3, 
    0x2, 0x2, 0x2, 0x45f, 0x46e, 0x7, 0x6, 0x2, 0x2, 0x460, 0x461, 0x7, 
    0x7, 0x2, 0x2, 0x461, 0x462, 0x7, 0x5, 0x2, 0x2, 0x462, 0x467, 0x5, 
    0x40, 0x21, 0x2, 0x463, 0x464, 0x7, 0x7, 0x2, 0x2, 0x464, 0x466, 0x5, 
    0x40, 0x21, 0x2, 0x465, 0x463, 0x3, 0x2, 0x2, 0x2, 0x466, 0x469, 0x3, 
    0x2, 0x2, 0x2, 0x467, 0x465, 0x3, 0x2, 0x2, 0x2, 0x467, 0x468, 0x3, 
    0x2, 0x2, 0x2, 0x468, 0x46a, 0x3, 0x2, 0x2, 0x2, 0x469, 0x467, 0x3, 
    0x2, 0x2, 0x2, 0x46a, 0x46b, 0x7, 0x6, 0x2, 0x2, 0x46b, 0x46d, 0x3, 
    0x2, 0x2, 0x2, 0x46c, 0x460, 0x3, 0x2, 0x2, 0x2, 0x46d, 0x470, 0x3, 
    0x2, 0x2, 0x2, 0x46e, 0x46c, 0x3, 0x2, 0x2, 0x2, 0x46e, 0x46f, 0x3, 
    0x2, 0x2, 0x2, 0x46f, 0x473, 0x3, 0x2, 0x2, 0x2, 0x470, 0x46e, 0x3, 
    0x2, 0x2, 0x2, 0x471, 0x473, 0x5, 0x50, 0x29, 0x2, 0x472, 0x455, 0x3, 
    0x2, 0x2, 0x2, 0x472, 0x471, 0x3, 0x2, 0x2, 0x2, 0x473, 0x475, 0x3, 
    0x2, 0x2, 0x2, 0x474, 0x476, 0x5, 0x48, 0x25, 0x2, 0x475, 0x474, 0x3, 
    0x2, 0x2, 0x2, 0x475, 0x476, 0x3, 0x2, 0x2, 0x2, 0x476, 0x47a, 0x3, 
    0x2, 0x2, 0x2, 0x477, 0x478, 0x7, 0x3a, 0x2, 0x2, 0x478, 0x47a, 0x7, 
    0x91, 0x2, 0x2, 0x479, 0x434, 0x3, 0x2, 0x2, 0x2, 0x479, 0x477, 0x3, 
    0x2, 0x2, 0x2, 0x47a, 0x47, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x47c, 0x7, 0x6d, 
    0x2, 0x2, 0x47c, 0x48b, 0x7, 0x32, 0x2, 0x2, 0x47d, 0x47e, 0x7, 0x5, 
    0x2, 0x2, 0x47e, 0x483, 0x5, 0x18, 0xd, 0x2, 0x47f, 0x480, 0x7, 0x7, 
    0x2, 0x2, 0x480, 0x482, 0x5, 0x18, 0xd, 0x2, 0x481, 0x47f, 0x3, 0x2, 
    0x2, 0x2, 0x482, 0x485, 0x3, 0x2, 0x2, 0x2, 0x483, 0x481, 0x3, 0x2, 
    0x2, 0x2, 0x483, 0x484, 0x3, 0x2, 0x2, 0x2, 0x484, 0x486, 0x3, 0x2, 
    0x2, 0x2, 0x485, 0x483, 0x3, 0x2, 0x2, 0x2, 0x486, 0x489, 0x7, 0x6, 
    0x2, 0x2, 0x487, 0x488, 0x7, 0x95, 0x2, 0x2, 0x488, 0x48a, 0x5, 0x40, 
    0x21, 0x2, 0x489, 0x487, 0x3, 0x2, 0x2, 0x2, 0x489, 0x48a, 0x3, 0x2, 
    0x2, 0x2, 0x48a, 0x48c, 0x3, 0x2, 0x2, 0x2, 0x48b, 0x47d, 0x3, 0x2, 
    0x2, 0x2, 0x48b, 0x48c, 0x3, 0x2, 0x2, 0x2, 0x48c, 0x48d, 0x3, 0x2, 
    0x2, 0x2, 0x48d, 0x4a8, 0x7, 0xb8, 0x2, 0x2, 0x48e, 0x4a9, 0x7, 0xb9, 
    0x2, 0x2, 0x48f, 0x490, 0x7, 0x8e, 0x2, 0x2, 0x490, 0x493, 0x7, 0x84, 
    0x2, 0x2, 0x491, 0x494, 0x5, 0xb8, 0x5d, 0x2, 0x492, 0x494, 0x5, 0x68, 
    0x35, 0x2, 0x493, 0x491, 0x3, 0x2, 0x2, 0x2, 0x493, 0x492, 0x3, 0x2, 
    0x2, 0x2, 0x494, 0x495, 0x3, 0x2, 0x2, 0x2, 0x495, 0x496, 0x7, 0x18, 
    0x2, 0x2, 0x496, 0x4a1, 0x5, 0x40, 0x21, 0x2, 0x497, 0x49a, 0x7, 0x7, 
    0x2, 0x2, 0x498, 0x49b, 0x5, 0xb8, 0x5d, 0x2, 0x499, 0x49b, 0x5, 0x68, 
    0x35, 0x2, 0x49a, 0x498, 0x3, 0x2, 0x2, 0x2, 0x49a, 0x499, 0x3, 0x2, 
    0x2, 0x2, 0x49b, 0x49c, 0x3, 0x2, 0x2, 0x2, 0x49c, 0x49d, 0x7, 0x18, 
    0x2, 0x2, 0x49d, 0x49e, 0x5, 0x40, 0x21, 0x2, 0x49e, 0x4a0, 0x3, 0x2, 
    0x2, 0x2, 0x49f, 0x497, 0x3, 0x2, 0x2, 0x2, 0x4a0, 0x4a3, 0x3, 0x2, 
    0x2, 0x2, 0x4a1, 0x49f, 0x3, 0x2, 0x2, 0x2, 0x4a1, 0x4a2, 0x3, 0x2, 
    0x2, 0x2, 0x4a2, 0x4a6, 0x3, 0x2, 0x2, 0x2, 0x4a3, 0x4a1, 0x3, 0x2, 
    0x2, 0x2, 0x4a4, 0x4a5, 0x7, 0x95, 0x2, 0x2, 0x4a5, 0x4a7, 0x5, 0x40, 
    0x21, 0x2, 0x4a6, 0x4a4, 0x3, 0x2, 0x2, 0x2, 0x4a6, 0x4a7, 0x3, 0x2, 
    0x2, 0x2, 0x4a7, 0x4a9, 0x3, 0x2, 0x2, 0x2, 0x4a8, 0x48e, 0x3, 0x2, 
    0x2, 0x2, 0x4a8, 0x48f, 0x3, 0x2, 0x2, 0x2, 0x4a9, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x4aa, 0x4ae, 0x7, 0x72, 0x2, 0x2, 0x4ab, 0x4ac, 0x5, 0xb0, 0x59, 
    0x2, 0x4ac, 0x4ad, 0x7, 0x4, 0x2, 0x2, 0x4ad, 0x4af, 0x3, 0x2, 0x2, 
    0x2, 0x4ae, 0x4ab, 0x3, 0x2, 0x2, 0x2, 0x4ae, 0x4af, 0x3, 0x2, 0x2, 
    0x2, 0x4af, 0x4b0, 0x3, 0x2, 0x2, 0x2, 0x4b0, 0x4b7, 0x5, 0xc6, 0x64, 
    0x2, 0x4b1, 0x4b2, 0x7, 0x8, 0x2, 0x2, 0x4b2, 0x4b8, 0x5, 0x4c, 0x27, 
    0x2, 0x4b3, 0x4b4, 0x7, 0x5, 0x2, 0x2, 0x4b4, 0x4b5, 0x5, 0x4c, 0x27, 
    0x2, 0x4b5, 0x4b6, 0x7, 0x6, 0x2, 0x2, 0x4b6, 0x4b8, 0x3, 0x2, 0x2, 
    0x2, 0x4b7, 0x4b1, 0x3, 0x2, 0x2, 0x2, 0x4b7, 0x4b3, 0x3, 0x2, 0x2, 
    0x2, 0x4b7, 0x4b8, 0x3, 0x2, 0x2, 0x2, 0x4b8, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x4b9, 0x4bd, 0x5, 0x22, 0x12, 0x2, 0x4ba, 0x4bd, 0x5, 0xac, 0x57, 0x2, 
    0x4bb, 0x4bd, 0x7, 0xbd, 0x2, 0x2, 0x4bc, 0x4b9, 0x3, 0x2, 0x2, 0x2, 
    0x4bc, 0x4ba, 0x3, 0x2, 0x2, 0x2, 0x4bc, 0x4bb, 0x3, 0x2, 0x2, 0x2, 
    0x4bd, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4be, 0x4c9, 0x7, 0x79, 0x2, 0x2, 
    0x4bf, 0x4ca, 0x5, 0xba, 0x5e, 0x2, 0x4c0, 0x4c1, 0x5, 0xb0, 0x59, 0x2, 
    0x4c1, 0x4c2, 0x7, 0x4, 0x2, 0x2, 0x4c2, 0x4c4, 0x3, 0x2, 0x2, 0x2, 
    0x4c3, 0x4c0, 0x3, 0x2, 0x2, 0x2, 0x4c3, 0x4c4, 0x3, 0x2, 0x2, 0x2, 
    0x4c4, 0x4c7, 0x3, 0x2, 0x2, 0x2, 0x4c5, 0x4c8, 0x5, 0xb2, 0x5a, 0x2, 
    0x4c6, 0x4c8, 0x5, 0xbe, 0x60, 0x2, 0x4c7, 0x4c5, 0x3, 0x2, 0x2, 0x2, 
    0x4c7, 0x4c6, 0x3, 0x2, 0x2, 0x2, 0x4c8, 0x4ca, 0x3, 0x2, 0x2, 0x2, 
    0x4c9, 0x4bf, 0x3, 0x2, 0x2, 0x2, 0x4c9, 0x4c3, 0x3, 0x2, 0x2, 0x2, 
    0x4c9, 0x4ca, 0x3, 0x2, 0x2, 0x2, 0x4ca, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4cb, 
    0x4cd, 0x5, 0x80, 0x41, 0x2, 0x4cc, 0x4cb, 0x3, 0x2, 0x2, 0x2, 0x4cc, 
    0x4cd, 0x3, 0x2, 0x2, 0x2, 0x4cd, 0x4ce, 0x3, 0x2, 0x2, 0x2, 0x4ce, 
    0x4d4, 0x5, 0x54, 0x2b, 0x2, 0x4cf, 0x4d0, 0x5, 0x64, 0x33, 0x2, 0x4d0, 
    0x4d1, 0x5, 0x54, 0x2b, 0x2, 0x4d1, 0x4d3, 0x3, 0x2, 0x2, 0x2, 0x4d2, 
    0x4cf, 0x3, 0x2, 0x2, 0x2, 0x4d3, 0x4d6, 0x3, 0x2, 0x2, 0x2, 0x4d4, 
    0x4d2, 0x3, 0x2, 0x2, 0x2, 0x4d4, 0x4d5, 0x3, 0x2, 0x2, 0x2, 0x4d5, 
    0x4d8, 0x3, 0x2, 0x2, 0x2, 0x4d6, 0x4d4, 0x3, 0x2, 0x2, 0x2, 0x4d7, 
    0x4d9, 0x5, 0x82, 0x42, 0x2, 0x4d8, 0x4d7, 0x3, 0x2, 0x2, 0x2, 0x4d8, 
    0x4d9, 0x3, 0x2, 0x2, 0x2, 0x4d9, 0x4db, 0x3, 0x2, 0x2, 0x2, 0x4da, 
    0x4dc, 0x5, 0x84, 0x43, 0x2, 0x4db, 0x4da, 0x3, 0x2, 0x2, 0x2, 0x4db, 
    0x4dc, 0x3, 0x2, 0x2, 0x2, 0x4dc, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4dd, 0x4e5, 
    0x5, 0x5c, 0x2f, 0x2, 0x4de, 0x4df, 0x5, 0x60, 0x31, 0x2, 0x4df, 0x4e1, 
    0x5, 0x5c, 0x2f, 0x2, 0x4e0, 0x4e2, 0x5, 0x62, 0x32, 0x2, 0x4e1, 0x4e0, 
    0x3, 0x2, 0x2, 0x2, 0x4e1, 0x4e2, 0x3, 0x2, 0x2, 0x2, 0x4e2, 0x4e4, 
    0x3, 0x2, 0x2, 0x2, 0x4e3, 0x4de, 0x3, 0x2, 0x2, 0x2, 0x4e4, 0x4e7, 
    0x3, 0x2, 0x2, 0x2, 0x4e5, 0x4e3, 0x3, 0x2, 0x2, 0x2, 0x4e5, 0x4e6, 
    0x3, 0x2, 0x2, 0x2, 0x4e6, 0x53, 0x3, 0x2, 0x2, 0x2, 0x4e7, 0x4e5, 0x3, 
    0x2, 0x2, 0x2, 0x4e8, 0x4ea, 0x7, 0x83, 0x2, 0x2, 0x4e9, 0x4eb, 0x9, 
    0x12, 0x2, 0x2, 0x4ea, 0x4e9, 0x3, 0x2, 0x2, 0x2, 0x4ea, 0x4eb, 0x3, 
    0x2, 0x2, 0x2, 0x4eb, 0x4ec, 0x3, 0x2, 0x2, 0x2, 0x4ec, 0x4f1, 0x5, 
    0x5e, 0x30, 0x2, 0x4ed, 0x4ee, 0x7, 0x7, 0x2, 0x2, 0x4ee, 0x4f0, 0x5, 
    0x5e, 0x30, 0x2, 0x4ef, 0x4ed, 0x3, 0x2, 0x2, 0x2, 0x4f0, 0x4f3, 0x3, 
    0x2, 0x2, 0x2, 0x4f1, 0x4ef, 0x3, 0x2, 0x2, 0x2, 0x4f1, 0x4f2, 0x3, 
    0x2, 0x2, 0x2, 0x4f2, 0x500, 0x3, 0x2, 0x2, 0x2, 0x4f3, 0x4f1, 0x3, 
    0x2, 0x2, 0x2, 0x4f4, 0x4fe, 0x7, 0x4d, 0x2, 0x2, 0x4f5, 0x4fa, 0x5, 
    0x5c, 0x2f, 0x2, 0x4f6, 0x4f7, 0x7, 0x7, 0x2, 0x2, 0x4f7, 0x4f9, 0x5, 
    0x5c, 0x2f, 0x2, 0x4f8, 0x4f6, 0x3, 0x2, 0x2, 0x2, 0x4f9, 0x4fc, 0x3, 
    0x2, 0x2, 0x2, 0x4fa, 0x4f8, 0x3, 0x2, 0x2, 0x2, 0x4fa, 0x4fb, 0x3, 
    0x2, 0x2, 0x2, 0x4fb, 0x4ff, 0x3, 0x2, 0x2, 0x2, 0x4fc, 0x4fa, 0x3, 
    0x2, 0x2, 0x2, 0x4fd, 0x4ff, 0x5, 0x52, 0x2a, 0x2, 0x4fe, 0x4f5, 0x3, 
    0x2, 0x2, 0x2, 0x4fe, 0x4fd, 0x3, 0x2, 0x2, 0x2, 0x4ff, 0x501, 0x3, 
    0x2, 0x2, 0x2, 0x500, 0x4f4, 0x3, 0x2, 0x2, 0x2, 0x500, 0x501, 0x3, 
    0x2, 0x2, 0x2, 0x501, 0x504, 0x3, 0x2, 0x2, 0x2, 0x502, 0x503, 0x7, 
    0x95, 0x2, 0x2, 0x503, 0x505, 0x5, 0x40, 0x21, 0x2, 0x504, 0x502, 0x3, 
    0x2, 0x2, 0x2, 0x504, 0x505, 0x3, 0x2, 0x2, 0x2, 0x505, 0x514, 0x3, 
    0x2, 0x2, 0x2, 0x506, 0x507, 0x7, 0x50, 0x2, 0x2, 0x507, 0x508, 0x7, 
    0x2a, 0x2, 0x2, 0x508, 0x50d, 0x5, 0x40, 0x21, 0x2, 0x509, 0x50a, 0x7, 
    0x7, 0x2, 0x2, 0x50a, 0x50c, 0x5, 0x40, 0x21, 0x2, 0x50b, 0x509, 0x3, 
    0x2, 0x2, 0x2, 0x50c, 0x50f, 0x3, 0x2, 0x2, 0x2, 0x50d, 0x50b, 0x3, 
    0x2, 0x2, 0x2, 0x50d, 0x50e, 0x3, 0x2, 0x2, 0x2, 0x50e, 0x512, 0x3, 
    0x2, 0x2, 0x2, 0x50f, 0x50d, 0x3, 0x2, 0x2, 0x2, 0x510, 0x511, 0x7, 
    0x51, 0x2, 0x2, 0x511, 0x513, 0x5, 0x40, 0x21, 0x2, 0x512, 0x510, 0x3, 
    0x2, 0x2, 0x2, 0x512, 0x513, 0x3, 0x2, 0x2, 0x2, 0x513, 0x515, 0x3, 
    0x2, 0x2, 0x2, 0x514, 0x506, 0x3, 0x2, 0x2, 0x2, 0x514, 0x515, 0x3, 
    0x2, 0x2, 0x2, 0x515, 0x524, 0x3, 0x2, 0x2, 0x2, 0x516, 0x517, 0x7, 
    0xaf, 0x2, 0x2, 0x517, 0x518, 0x5, 0xce, 0x68, 0x2, 0x518, 0x519, 0x7, 
    0x23, 0x2, 0x2, 0x519, 0x521, 0x5, 0x72, 0x3a, 0x2, 0x51a, 0x51b, 0x7, 
    0x7, 0x2, 0x2, 0x51b, 0x51c, 0x5, 0xce, 0x68, 0x2, 0x51c, 0x51d, 0x7, 
    0x23, 0x2, 0x2, 0x51d, 0x51e, 0x5, 0x72, 0x3a, 0x2, 0x51e, 0x520, 0x3, 
    0x2, 0x2, 0x2, 0x51f, 0x51a, 0x3, 0x2, 0x2, 0x2, 0x520, 0x523, 0x3, 
    0x2, 0x2, 0x2, 0x521, 0x51f, 0x3, 0x2, 0x2, 0x2, 0x521, 0x522, 0x3, 
    0x2, 0x2, 0x2, 0x522, 0x525, 0x3, 0x2, 0x2, 0x2, 0x523, 0x521, 0x3, 
    0x2, 0x2, 0x2, 0x524, 0x516, 0x3, 0x2, 0x2, 0x2, 0x524, 0x525, 0x3, 
    0x2, 0x2, 0x2, 0x525, 0x543, 0x3, 0x2, 0x2, 0x2, 0x526, 0x527, 0x7, 
    0x91, 0x2, 0x2, 0x527, 0x528, 0x7, 0x5, 0x2, 0x2, 0x528, 0x52d, 0x5, 
    0x40, 0x21, 0x2, 0x529, 0x52a, 0x7, 0x7, 0x2, 0x2, 0x52a, 0x52c, 0x5, 
    0x40, 0x21, 0x2, 0x52b, 0x529, 0x3, 0x2, 0x2, 0x2, 0x52c, 0x52f, 0x3, 
    0x2, 0x2, 0x2, 0x52d, 0x52b, 0x3, 0x2, 0x2, 0x2, 0x52d, 0x52e, 0x3, 
    0x2, 0x2, 0x2, 0x52e, 0x530, 0x3, 0x2, 0x2, 0x2, 0x52f, 0x52d, 0x3, 
    0x2, 0x2, 0x2, 0x530, 0x53f, 0x7, 0x6, 0x2, 0x2, 0x531, 0x532, 0x7, 
    0x7, 0x2, 0x2, 0x532, 0x533, 0x7, 0x5, 0x2, 0x2, 0x533, 0x538, 0x5, 
    0x40, 0x21, 0x2, 0x534, 0x535, 0x7, 0x7, 0x2, 0x2, 0x535, 0x537, 0x5, 
    0x40, 0x21, 0x2, 0x536, 0x534, 0x3, 0x2, 0x2, 0x2, 0x537, 0x53a, 0x3, 
    0x2, 0x2, 0x2, 0x538, 0x536, 0x3, 0x2, 0x2, 0x2, 0x538, 0x539, 0x3, 
    0x2, 0x2, 0x2, 0x539, 0x53b, 0x3, 0x2, 0x2, 0x2, 0x53a, 0x538, 0x3, 
    0x2, 0x2, 0x2, 0x53b, 0x53c, 0x7, 0x6, 0x2, 0x2, 0x53c, 0x53e, 0x3, 
    0x2, 0x2, 0x2, 0x53d, 0x531, 0x3, 0x2, 0x2, 0x2, 0x53e, 0x541, 0x3, 
    0x2, 0x2, 0x2, 0x53f, 0x53d, 0x3, 0x2, 0x2, 0x2, 0x53f, 0x540, 0x3, 
    0x2, 0x2, 0x2, 0x540, 0x543, 0x3, 0x2, 0x2, 0x2, 0x541, 0x53f, 0x3, 
    0x2, 0x2, 0x2, 0x542, 0x4e8, 0x3, 0x2, 0x2, 0x2, 0x542, 0x526, 0x3, 
    0x2, 0x2, 0x2, 0x543, 0x55, 0x3, 0x2, 0x2, 0x2, 0x544, 0x545, 0x5, 0x50, 
    0x29, 0x2, 0x545, 0x57, 0x3, 0x2, 0x2, 0x2, 0x546, 0x548, 0x5, 0x80, 
    0x41, 0x2, 0x547, 0x546, 0x3, 0x2, 0x2, 0x2, 0x547, 0x548, 0x3, 0x2, 
    0x2, 0x2, 0x548, 0x549, 0x3, 0x2, 0x2, 0x2, 0x549, 0x54b, 0x5, 0x54, 
    0x2b, 0x2, 0x54a, 0x54c, 0x5, 0x82, 0x42, 0x2, 0x54b, 0x54a, 0x3, 0x2, 
    0x2, 0x2, 0x54b, 0x54c, 0x3, 0x2, 0x2, 0x2, 0x54c, 0x54e, 0x3, 0x2, 
    0x2, 0x2, 0x54d, 0x54f, 0x5, 0x84, 0x43, 0x2, 0x54e, 0x54d, 0x3, 0x2, 
    0x2, 0x2, 0x54e, 0x54f, 0x3, 0x2, 0x2, 0x2, 0x54f, 0x59, 0x3, 0x2, 0x2, 
    0x2, 0x550, 0x552, 0x5, 0x80, 0x41, 0x2, 0x551, 0x550, 0x3, 0x2, 0x2, 
    0x2, 0x551, 0x552, 0x3, 0x2, 0x2, 0x2, 0x552, 0x553, 0x3, 0x2, 0x2, 
    0x2, 0x553, 0x55d, 0x5, 0x54, 0x2b, 0x2, 0x554, 0x556, 0x7, 0x8c, 0x2, 
    0x2, 0x555, 0x557, 0x7, 0x1f, 0x2, 0x2, 0x556, 0x555, 0x3, 0x2, 0x2, 
    0x2, 0x556, 0x557, 0x3, 0x2, 0x2, 0x2, 0x557, 0x55b, 0x3, 0x2, 0x2, 
    0x2, 0x558, 0x55b, 0x7, 0x5c, 0x2, 0x2, 0x559, 0x55b, 0x7, 0x46, 0x2, 
    0x2, 0x55a, 0x554, 0x3, 0x2, 0x2, 0x2, 0x55a, 0x558, 0x3, 0x2, 0x2, 
    0x2, 0x55a, 0x559, 0x3, 0x2, 0x2, 0x2, 0x55b, 0x55c, 0x3, 0x2, 0x2, 
    0x2, 0x55c, 0x55e, 0x5, 0x54, 0x2b, 0x2, 0x55d, 0x55a, 0x3, 0x2, 0x2, 
    0x2, 0x55e, 0x55f, 0x3, 0x2, 0x2, 0x2, 0x55f, 0x55d, 0x3, 0x2, 0x2, 
    0x2, 0x55f, 0x560, 0x3, 0x2, 0x2, 0x2, 0x560, 0x562, 0x3, 0x2, 0x2, 
    0x2, 0x561, 0x563, 0x5, 0x82, 0x42, 0x2, 0x562, 0x561, 0x3, 0x2, 0x2, 
    0x2, 0x562, 0x563, 0x3, 0x2, 0x2, 0x2, 0x563, 0x565, 0x3, 0x2, 0x2, 
    0x2, 0x564, 0x566, 0x5, 0x84, 0x43, 0x2, 0x565, 0x564, 0x3, 0x2, 0x2, 
    0x2, 0x565, 0x566, 0x3, 0x2, 0x2, 0x2, 0x566, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x567, 0x568, 0x5, 0xb0, 0x59, 0x2, 0x568, 0x569, 0x7, 0x4, 0x2, 0x2, 
    0x569, 0x56b, 0x3, 0x2, 0x2, 0x2, 0x56a, 0x567, 0x3, 0x2, 0x2, 0x2, 
    0x56a, 0x56b, 0x3, 0x2, 0x2, 0x2, 0x56b, 0x56c, 0x3, 0x2, 0x2, 0x2, 
    0x56c, 0x571, 0x5, 0xb2, 0x5a, 0x2, 0x56d, 0x56f, 0x7, 0x23, 0x2, 0x2, 
    0x56e, 0x56d, 0x3, 0x2, 0x2, 0x2, 0x56e, 0x56f, 0x3, 0x2, 0x2, 0x2, 
    0x56f, 0x570, 0x3, 0x2, 0x2, 0x2, 0x570, 0x572, 0x5, 0xca, 0x66, 0x2, 
    0x571, 0x56e, 0x3, 0x2, 0x2, 0x2, 0x571, 0x572, 0x3, 0x2, 0x2, 0x2, 
    0x572, 0x578, 0x3, 0x2, 0x2, 0x2, 0x573, 0x574, 0x7, 0x57, 0x2, 0x2, 
    0x574, 0x575, 0x7, 0x2a, 0x2, 0x2, 0x575, 0x579, 0x5, 0xbe, 0x60, 0x2, 
    0x576, 0x577, 0x7, 0x68, 0x2, 0x2, 0x577, 0x579, 0x7, 0x57, 0x2, 0x2, 
    0x578, 0x573, 0x3, 0x2, 0x2, 0x2, 0x578, 0x576, 0x3, 0x2, 0x2, 0x2, 
    0x578, 0x579, 0x3, 0x2, 0x2, 0x2, 0x579, 0x5a8, 0x3, 0x2, 0x2, 0x2, 
    0x57a, 0x57b, 0x5, 0xb0, 0x59, 0x2, 0x57b, 0x57c, 0x7, 0x4, 0x2, 0x2, 
    0x57c, 0x57e, 0x3, 0x2, 0x2, 0x2, 0x57d, 0x57a, 0x3, 0x2, 0x2, 0x2, 
    0x57d, 0x57e, 0x3, 0x2, 0x2, 0x2, 0x57e, 0x57f, 0x3, 0x2, 0x2, 0x2, 
    0x57f, 0x580, 0x5, 0xda, 0x6e, 0x2, 0x580, 0x581, 0x7, 0x5, 0x2, 0x2, 
    0x581, 0x586, 0x5, 0x40, 0x21, 0x2, 0x582, 0x583, 0x7, 0x7, 0x2, 0x2, 
    0x583, 0x585, 0x5, 0x40, 0x21, 0x2, 0x584, 0x582, 0x3, 0x2, 0x2, 0x2, 
    0x585, 0x588, 0x3, 0x2, 0x2, 0x2, 0x586, 0x584, 0x3, 0x2, 0x2, 0x2, 
    0x586, 0x587, 0x3, 0x2, 0x2, 0x2, 0x587, 0x589, 0x3, 0x2, 0x2, 0x2, 
    0x588, 0x586, 0x3, 0x2, 0x2, 0x2, 0x589, 0x58e, 0x7, 0x6, 0x2, 0x2, 
    0x58a, 0x58c, 0x7, 0x23, 0x2, 0x2, 0x58b, 0x58a, 0x3, 0x2, 0x2, 0x2, 
    0x58b, 0x58c, 0x3, 0x2, 0x2, 0x2, 0x58c, 0x58d, 0x3, 0x2, 0x2, 0x2, 
    0x58d, 0x58f, 0x5, 0xca, 0x66, 0x2, 0x58e, 0x58b, 0x3, 0x2, 0x2, 0x2, 
    0x58e, 0x58f, 0x3, 0x2, 0x2, 0x2, 0x58f, 0x5a8, 0x3, 0x2, 0x2, 0x2, 
    0x590, 0x59a, 0x7, 0x5, 0x2, 0x2, 0x591, 0x596, 0x5, 0x5c, 0x2f, 0x2, 
    0x592, 0x593, 0x7, 0x7, 0x2, 0x2, 0x593, 0x595, 0x5, 0x5c, 0x2f, 0x2, 
    0x594, 0x592, 0x3, 0x2, 0x2, 0x2, 0x595, 0x598, 0x3, 0x2, 0x2, 0x2, 
    0x596, 0x594, 0x3, 0x2, 0x2, 0x2, 0x596, 0x597, 0x3, 0x2, 0x2, 0x2, 
    0x597, 0x59b, 0x3, 0x2, 0x2, 0x2, 0x598, 0x596, 0x3, 0x2, 0x2, 0x2, 
    0x599, 0x59b, 0x5, 0x52, 0x2a, 0x2, 0x59a, 0x591, 0x3, 0x2, 0x2, 0x2, 
    0x59a, 0x599, 0x3, 0x2, 0x2, 0x2, 0x59b, 0x59c, 0x3, 0x2, 0x2, 0x2, 
    0x59c, 0x59d, 0x7, 0x6, 0x2, 0x2, 0x59d, 0x5a8, 0x3, 0x2, 0x2, 0x2, 
    0x59e, 0x59f, 0x7, 0x5, 0x2, 0x2, 0x59f, 0x5a0, 0x5, 0x50, 0x29, 0x2, 
    0x5a0, 0x5a5, 0x7, 0x6, 0x2, 0x2, 0x5a1, 0x5a3, 0x7, 0x23, 0x2, 0x2, 
    0x5a2, 0x5a1, 0x3, 0x2, 0x2, 0x2, 0x5a2, 0x5a3, 0x3, 0x2, 0x2, 0x2, 
    0x5a3, 0x5a4, 0x3, 0x2, 0x2, 0x2, 0x5a4, 0x5a6, 0x5, 0xca, 0x66, 0x2, 
    0x5a5, 0x5a2, 0x3, 0x2, 0x2, 0x2, 0x5a5, 0x5a6, 0x3, 0x2, 0x2, 0x2, 
    0x5a6, 0x5a8, 0x3, 0x2, 0x2, 0x2, 0x5a7, 0x56a, 0x3, 0x2, 0x2, 0x2, 
    0x5a7, 0x57d, 0x3, 0x2, 0x2, 0x2, 0x5a7, 0x590, 0x3, 0x2, 0x2, 0x2, 
    0x5a7, 0x59e, 0x3, 0x2, 0x2, 0x2, 0x5a8, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5a9, 
    0x5b6, 0x7, 0x9, 0x2, 0x2, 0x5aa, 0x5ab, 0x5, 0xb2, 0x5a, 0x2, 0x5ab, 
    0x5ac, 0x7, 0x4, 0x2, 0x2, 0x5ac, 0x5ad, 0x7, 0x9, 0x2, 0x2, 0x5ad, 
    0x5b6, 0x3, 0x2, 0x2, 0x2, 0x5ae, 0x5b3, 0x5, 0x40, 0x21, 0x2, 0x5af, 
    0x5b1, 0x7, 0x23, 0x2, 0x2, 0x5b0, 0x5af, 0x3, 0x2, 0x2, 0x2, 0x5b0, 
    0x5b1, 0x3, 0x2, 0x2, 0x2, 0x5b1, 0x5b2, 0x3, 0x2, 0x2, 0x2, 0x5b2, 
    0x5b4, 0x5, 0xa8, 0x55, 0x2, 0x5b3, 0x5b0, 0x3, 0x2, 0x2, 0x2, 0x5b3, 
    0x5b4, 0x3, 0x2, 0x2, 0x2, 0x5b4, 0x5b6, 0x3, 0x2, 0x2, 0x2, 0x5b5, 
    0x5a9, 0x3, 0x2, 0x2, 0x2, 0x5b5, 0x5aa, 0x3, 0x2, 0x2, 0x2, 0x5b5, 
    0x5ae, 0x3, 0x2, 0x2, 0x2, 0x5b6, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5b7, 0x5c5, 
    0x7, 0x7, 0x2, 0x2, 0x5b8, 0x5ba, 0x7, 0x66, 0x2, 0x2, 0x5b9, 0x5b8, 
    0x3, 0x2, 0x2, 0x2, 0x5b9, 0x5ba, 0x3, 0x2, 0x2, 0x2, 0x5ba, 0x5c1, 
    0x3, 0x2, 0x2, 0x2, 0x5bb, 0x5bd, 0x7, 0x62, 0x2, 0x2, 0x5bc, 0x5be, 
    0x7, 0x70, 0x2, 0x2, 0x5bd, 0x5bc, 0x3, 0x2, 0x2, 0x2, 0x5bd, 0x5be, 
    0x3, 0x2, 0x2, 0x2, 0x5be, 0x5c2, 0x3, 0x2, 0x2, 0x2, 0x5bf, 0x5c2, 
    0x7, 0x59, 0x2, 0x2, 0x5c0, 0x5c2, 0x7, 0x35, 0x2, 0x2, 0x5c1, 0x5bb, 
    0x3, 0x2, 0x2, 0x2, 0x5c1, 0x5bf, 0x3, 0x2, 0x2, 0x2, 0x5c1, 0x5c0, 
    0x3, 0x2, 0x2, 0x2, 0x5c1, 0x5c2, 0x3, 0x2, 0x2, 0x2, 0x5c2, 0x5c3, 
    0x3, 0x2, 0x2, 0x2, 0x5c3, 0x5c5, 0x7, 0x60, 0x2, 0x2, 0x5c4, 0x5b7, 
    0x3, 0x2, 0x2, 0x2, 0x5c4, 0x5b9, 0x3, 0x2, 0x2, 0x2, 0x5c5, 0x61, 0x3, 
    0x2, 0x2, 0x2, 0x5c6, 0x5c7, 0x7, 0x6d, 0x2, 0x2, 0x5c7, 0x5d5, 0x5, 
    0x40, 0x21, 0x2, 0x5c8, 0x5c9, 0x7, 0x8f, 0x2, 0x2, 0x5c9, 0x5ca, 0x7, 
    0x5, 0x2, 0x2, 0x5ca, 0x5cf, 0x5, 0xb8, 0x5d, 0x2, 0x5cb, 0x5cc, 0x7, 
    0x7, 0x2, 0x2, 0x5cc, 0x5ce, 0x5, 0xb8, 0x5d, 0x2, 0x5cd, 0x5cb, 0x3, 
    0x2, 0x2, 0x2, 0x5ce, 0x5d1, 0x3, 0x2, 0x2, 0x2, 0x5cf, 0x5cd, 0x3, 
    0x2, 0x2, 0x2, 0x5cf, 0x5d0, 0x3, 0x2, 0x2, 0x2, 0x5d0, 0x5d2, 0x3, 
    0x2, 0x2, 0x2, 0x5d1, 0x5cf, 0x3, 0x2, 0x2, 0x2, 0x5d2, 0x5d3, 0x7, 
    0x6, 0x2, 0x2, 0x5d3, 0x5d5, 0x3, 0x2, 0x2, 0x2, 0x5d4, 0x5c6, 0x3, 
    0x2, 0x2, 0x2, 0x5d4, 0x5c8, 0x3, 0x2, 0x2, 0x2, 0x5d5, 0x63, 0x3, 0x2, 
    0x2, 0x2, 0x5d6, 0x5d8, 0x7, 0x8c, 0x2, 0x2, 0x5d7, 0x5d9, 0x7, 0x1f, 
    0x2, 0x2, 0x5d8, 0x5d7, 0x3, 0x2, 0x2, 0x2, 0x5d8, 0x5d9, 0x3, 0x2, 
    0x2, 0x2, 0x5d9, 0x5dd, 0x3, 0x2, 0x2, 0x2, 0x5da, 0x5dd, 0x7, 0x5c, 
    0x2, 0x2, 0x5db, 0x5dd, 0x7, 0x46, 0x2, 0x2, 0x5dc, 0x5d6, 0x3, 0x2, 
    0x2, 0x2, 0x5dc, 0x5da, 0x3, 0x2, 0x2, 0x2, 0x5dc, 0x5db, 0x3, 0x2, 
    0x2, 0x2, 0x5dd, 0x65, 0x3, 0x2, 0x2, 0x2, 0x5de, 0x5e0, 0x5, 0x30, 
    0x19, 0x2, 0x5df, 0x5de, 0x3, 0x2, 0x2, 0x2, 0x5df, 0x5e0, 0x3, 0x2, 
    0x2, 0x2, 0x5e0, 0x5e1, 0x3, 0x2, 0x2, 0x2, 0x5e1, 0x5e4, 0x7, 0x8e, 
    0x2, 0x2, 0x5e2, 0x5e3, 0x7, 0x6e, 0x2, 0x2, 0x5e3, 0x5e5, 0x9, 0xa, 
    0x2, 0x2, 0x5e4, 0x5e2, 0x3, 0x2, 0x2, 0x2, 0x5e4, 0x5e5, 0x3, 0x2, 
    0x2, 0x2, 0x5e5, 0x5e6, 0x3, 0x2, 0x2, 0x2, 0x5e6, 0x5e7, 0x5, 0x6c, 
    0x37, 0x2, 0x5e7, 0x5ea, 0x7, 0x84, 0x2, 0x2, 0x5e8, 0x5eb, 0x5, 0xb8, 
    0x5d, 0x2, 0x5e9, 0x5eb, 0x5, 0x68, 0x35, 0x2, 0x5ea, 0x5e8, 0x3, 0x2, 
    0x2, 0x2, 0x5ea, 0x5e9, 0x3, 0x2, 0x2, 0x2, 0x5eb, 0x5ec, 0x3, 0x2, 
    0x2, 0x2, 0x5ec, 0x5ed, 0x7, 0x8, 0x2, 0x2, 0x5ed, 0x5f8, 0x5, 0x40, 
    0x21, 0x2, 0x5ee, 0x5f1, 0x7, 0x7, 0x2, 0x2, 0x5ef, 0x5f2, 0x5, 0xb8, 
    0x5d, 0x2, 0x5f0, 0x5f2, 0x5, 0x68, 0x35, 0x2, 0x5f1, 0x5ef, 0x3, 0x2, 
    0x2, 0x2, 0x5f1, 0x5f0, 0x3, 0x2, 0x2, 0x2, 0x5f2, 0x5f3, 0x3, 0x2, 
    0x2, 0x2, 0x5f3, 0x5f4, 0x7, 0x8, 0x2, 0x2, 0x5f4, 0x5f5, 0x5, 0x40, 
    0x21, 0x2, 0x5f5, 0x5f7, 0x3, 0x2, 0x2, 0x2, 0x5f6, 0x5ee, 0x3, 0x2, 
    0x2, 0x2, 0x5f7, 0x5fa, 0x3, 0x2, 0x2, 0x2, 0x5f8, 0x5f6, 0x3, 0x2, 
    0x2, 0x2, 0x5f8, 0x5f9, 0x3, 0x2, 0x2, 0x2, 0x5f9, 0x5fd, 0x3, 0x2, 
    0x2, 0x2, 0x5fa, 0x5f8, 0x3, 0x2, 0x2, 0x2, 0x5fb, 0x5fc, 0x7, 0x95, 
    0x2, 0x2, 0x5fc, 0x5fe, 0x5, 0x40, 0x21, 0x2, 0x5fd, 0x5fb, 0x3, 0x2, 
    0x2, 0x2, 0x5fd, 0x5fe, 0x3, 0x2, 0x2, 0x2, 0x5fe, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x5ff, 0x600, 0x7, 0x5, 0x2, 0x2, 0x600, 0x605, 0x5, 0xb8, 0x5d, 
    0x2, 0x601, 0x602, 0x7, 0x7, 0x2, 0x2, 0x602, 0x604, 0x5, 0xb8, 0x5d, 
    0x2, 0x603, 0x601, 0x3, 0x2, 0x2, 0x2, 0x604, 0x607, 0x3, 0x2, 0x2, 
    0x2, 0x605, 0x603, 0x3, 0x2, 0x2, 0x2, 0x605, 0x606, 0x3, 0x2, 0x2, 
    0x2, 0x606, 0x608, 0x3, 0x2, 0x2, 0x2, 0x607, 0x605, 0x3, 0x2, 0x2, 
    0x2, 0x608, 0x609, 0x7, 0x6, 0x2, 0x2, 0x609, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0x60a, 0x60c, 0x5, 0x30, 0x19, 0x2, 0x60b, 0x60a, 0x3, 0x2, 0x2, 0x2, 
    0x60b, 0x60c, 0x3, 0x2, 0x2, 0x2, 0x60c, 0x60d, 0x3, 0x2, 0x2, 0x2, 
    0x60d, 0x610, 0x7, 0x8e, 0x2, 0x2, 0x60e, 0x60f, 0x7, 0x6e, 0x2, 0x2, 
    0x60f, 0x611, 0x9, 0xa, 0x2, 0x2, 0x610, 0x60e, 0x3, 0x2, 0x2, 0x2, 
    0x610, 0x611, 0x3, 0x2, 0x2, 0x2, 0x611, 0x612, 0x3, 0x2, 0x2, 0x2, 
    0x612, 0x613, 0x5, 0x6c, 0x37, 0x2, 0x613, 0x616, 0x7, 0x84, 0x2, 0x2, 
    0x614, 0x617, 0x5, 0xb8, 0x5d, 0x2, 0x615, 0x617, 0x5, 0x68, 0x35, 0x2, 
    0x616, 0x614, 0x3, 0x2, 0x2, 0x2, 0x616, 0x615, 0x3, 0x2, 0x2, 0x2, 
    0x617, 0x618, 0x3, 0x2, 0x2, 0x2, 0x618, 0x619, 0x7, 0x8, 0x2, 0x2, 
    0x619, 0x624, 0x5, 0x40, 0x21, 0x2, 0x61a, 0x61d, 0x7, 0x7, 0x2, 0x2, 
    0x61b, 0x61e, 0x5, 0xb8, 0x5d, 0x2, 0x61c, 0x61e, 0x5, 0x68, 0x35, 0x2, 
    0x61d, 0x61b, 0x3, 0x2, 0x2, 0x2, 0x61d, 0x61c, 0x3, 0x2, 0x2, 0x2, 
    0x61e, 0x61f, 0x3, 0x2, 0x2, 0x2, 0x61f, 0x620, 0x7, 0x8, 0x2, 0x2, 
    0x620, 0x621, 0x5, 0x40, 0x21, 0x2, 0x621, 0x623, 0x3, 0x2, 0x2, 0x2, 
    0x622, 0x61a, 0x3, 0x2, 0x2, 0x2, 0x623, 0x626, 0x3, 0x2, 0x2, 0x2, 
    0x624, 0x622, 0x3, 0x2, 0x2, 0x2, 0x624, 0x625, 0x3, 0x2, 0x2, 0x2, 
    0x625, 0x629, 0x3, 0x2, 0x2, 0x2, 0x626, 0x624, 0x3, 0x2, 0x2, 0x2, 
    0x627, 0x628, 0x7, 0x95, 0x2, 0x2, 0x628, 0x62a, 0x5, 0x40, 0x21, 0x2, 
    0x629, 0x627, 0x3, 0x2, 0x2, 0x2, 0x629, 0x62a, 0x3, 0x2, 0x2, 0x2, 
    0x62a, 0x62f, 0x3, 0x2, 0x2, 0x2, 0x62b, 0x62d, 0x5, 0x82, 0x42, 0x2, 
    0x62c, 0x62b, 0x3, 0x2, 0x2, 0x2, 0x62c, 0x62d, 0x3, 0x2, 0x2, 0x2, 
    0x62d, 0x62e, 0x3, 0x2, 0x2, 0x2, 0x62e, 0x630, 0x5, 0x84, 0x43, 0x2, 
    0x62f, 0x62c, 0x3, 0x2, 0x2, 0x2, 0x62f, 0x630, 0x3, 0x2, 0x2, 0x2, 
    0x630, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x631, 0x632, 0x5, 0xb0, 0x59, 0x2, 
    0x632, 0x633, 0x7, 0x4, 0x2, 0x2, 0x633, 0x635, 0x3, 0x2, 0x2, 0x2, 
    0x634, 0x631, 0x3, 0x2, 0x2, 0x2, 0x634, 0x635, 0x3, 0x2, 0x2, 0x2, 
    0x635, 0x636, 0x3, 0x2, 0x2, 0x2, 0x636, 0x639, 0x5, 0xb2, 0x5a, 0x2, 
    0x637, 0x638, 0x7, 0x23, 0x2, 0x2, 0x638, 0x63a, 0x5, 0xd0, 0x69, 0x2, 
    0x639, 0x637, 0x3, 0x2, 0x2, 0x2, 0x639, 0x63a, 0x3, 0x2, 0x2, 0x2, 
    0x63a, 0x640, 0x3, 0x2, 0x2, 0x2, 0x63b, 0x63c, 0x7, 0x57, 0x2, 0x2, 
    0x63c, 0x63d, 0x7, 0x2a, 0x2, 0x2, 0x63d, 0x641, 0x5, 0xbe, 0x60, 0x2, 
    0x63e, 0x63f, 0x7, 0x68, 0x2, 0x2, 0x63f, 0x641, 0x7, 0x57, 0x2, 0x2, 
    0x640, 0x63b, 0x3, 0x2, 0x2, 0x2, 0x640, 0x63e, 0x3, 0x2, 0x2, 0x2, 
    0x640, 0x641, 0x3, 0x2, 0x2, 0x2, 0x641, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x642, 
    0x644, 0x7, 0x90, 0x2, 0x2, 0x643, 0x645, 0x5, 0xb0, 0x59, 0x2, 0x644, 
    0x643, 0x3, 0x2, 0x2, 0x2, 0x644, 0x645, 0x3, 0x2, 0x2, 0x2, 0x645, 
    0x648, 0x3, 0x2, 0x2, 0x2, 0x646, 0x647, 0x7, 0x5d, 0x2, 0x2, 0x647, 
    0x649, 0x5, 0xd2, 0x6a, 0x2, 0x648, 0x646, 0x3, 0x2, 0x2, 0x2, 0x648, 
    0x649, 0x3, 0x2, 0x2, 0x2, 0x649, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x64a, 0x64b, 
    0x7, 0xb3, 0x2, 0x2, 0x64b, 0x64c, 0x7, 0x5, 0x2, 0x2, 0x64c, 0x64d, 
    0x7, 0x95, 0x2, 0x2, 0x64d, 0x64e, 0x5, 0x40, 0x21, 0x2, 0x64e, 0x64f, 
    0x7, 0x6, 0x2, 0x2, 0x64f, 0x71, 0x3, 0x2, 0x2, 0x2, 0x650, 0x652, 0x7, 
    0x5, 0x2, 0x2, 0x651, 0x653, 0x5, 0xd4, 0x6b, 0x2, 0x652, 0x651, 0x3, 
    0x2, 0x2, 0x2, 0x652, 0x653, 0x3, 0x2, 0x2, 0x2, 0x653, 0x65e, 0x3, 
    0x2, 0x2, 0x2, 0x654, 0x655, 0x7, 0x9a, 0x2, 0x2, 0x655, 0x656, 0x7, 
    0x2a, 0x2, 0x2, 0x656, 0x65b, 0x5, 0x40, 0x21, 0x2, 0x657, 0x658, 0x7, 
    0x7, 0x2, 0x2, 0x658, 0x65a, 0x5, 0x40, 0x21, 0x2, 0x659, 0x657, 0x3, 
    0x2, 0x2, 0x2, 0x65a, 0x65d, 0x3, 0x2, 0x2, 0x2, 0x65b, 0x659, 0x3, 
    0x2, 0x2, 0x2, 0x65b, 0x65c, 0x3, 0x2, 0x2, 0x2, 0x65c, 0x65f, 0x3, 
    0x2, 0x2, 0x2, 0x65d, 0x65b, 0x3, 0x2, 0x2, 0x2, 0x65e, 0x654, 0x3, 
    0x2, 0x2, 0x2, 0x65e, 0x65f, 0x3, 0x2, 0x2, 0x2, 0x65f, 0x660, 0x3, 
    0x2, 0x2, 0x2, 0x660, 0x661, 0x7, 0x6f, 0x2, 0x2, 0x661, 0x662, 0x7, 
    0x2a, 0x2, 0x2, 0x662, 0x667, 0x5, 0x86, 0x44, 0x2, 0x663, 0x664, 0x7, 
    0x7, 0x2, 0x2, 0x664, 0x666, 0x5, 0x86, 0x44, 0x2, 0x665, 0x663, 0x3, 
    0x2, 0x2, 0x2, 0x666, 0x669, 0x3, 0x2, 0x2, 0x2, 0x667, 0x665, 0x3, 
    0x2, 0x2, 0x2, 0x667, 0x668, 0x3, 0x2, 0x2, 0x2, 0x668, 0x66b, 0x3, 
    0x2, 0x2, 0x2, 0x669, 0x667, 0x3, 0x2, 0x2, 0x2, 0x66a, 0x66c, 0x5, 
    0x76, 0x3c, 0x2, 0x66b, 0x66a, 0x3, 0x2, 0x2, 0x2, 0x66b, 0x66c, 0x3, 
    0x2, 0x2, 0x2, 0x66c, 0x66d, 0x3, 0x2, 0x2, 0x2, 0x66d, 0x66e, 0x7, 
    0x6, 0x2, 0x2, 0x66e, 0x73, 0x3, 0x2, 0x2, 0x2, 0x66f, 0x691, 0x7, 0x99, 
    0x2, 0x2, 0x670, 0x692, 0x5, 0xce, 0x68, 0x2, 0x671, 0x673, 0x7, 0x5, 
    0x2, 0x2, 0x672, 0x674, 0x5, 0xd4, 0x6b, 0x2, 0x673, 0x672, 0x3, 0x2, 
    0x2, 0x2, 0x673, 0x674, 0x3, 0x2, 0x2, 0x2, 0x674, 0x67f, 0x3, 0x2, 
    0x2, 0x2, 0x675, 0x676, 0x7, 0x9a, 0x2, 0x2, 0x676, 0x677, 0x7, 0x2a, 
    0x2, 0x2, 0x677, 0x67c, 0x5, 0x40, 0x21, 0x2, 0x678, 0x679, 0x7, 0x7, 
    0x2, 0x2, 0x679, 0x67b, 0x5, 0x40, 0x21, 0x2, 0x67a, 0x678, 0x3, 0x2, 
    0x2, 0x2, 0x67b, 0x67e, 0x3, 0x2, 0x2, 0x2, 0x67c, 0x67a, 0x3, 0x2, 
    0x2, 0x2, 0x67c, 0x67d, 0x3, 0x2, 0x2, 0x2, 0x67d, 0x680, 0x3, 0x2, 
    0x2, 0x2, 0x67e, 0x67c, 0x3, 0x2, 0x2, 0x2, 0x67f, 0x675, 0x3, 0x2, 
    0x2, 0x2, 0x67f, 0x680, 0x3, 0x2, 0x2, 0x2, 0x680, 0x68b, 0x3, 0x2, 
    0x2, 0x2, 0x681, 0x682, 0x7, 0x6f, 0x2, 0x2, 0x682, 0x683, 0x7, 0x2a, 
    0x2, 0x2, 0x683, 0x688, 0x5, 0x86, 0x44, 0x2, 0x684, 0x685, 0x7, 0x7, 
    0x2, 0x2, 0x685, 0x687, 0x5, 0x86, 0x44, 0x2, 0x686, 0x684, 0x3, 0x2, 
    0x2, 0x2, 0x687, 0x68a, 0x3, 0x2, 0x2, 0x2, 0x688, 0x686, 0x3, 0x2, 
    0x2, 0x2, 0x688, 0x689, 0x3, 0x2, 0x2, 0x2, 0x689, 0x68c, 0x3, 0x2, 
    0x2, 0x2, 0x68a, 0x688, 0x3, 0x2, 0x2, 0x2, 0x68b, 0x681, 0x3, 0x2, 
    0x2, 0x2, 0x68b, 0x68c, 0x3, 0x2, 0x2, 0x2, 0x68c, 0x68e, 0x3, 0x2, 
    0x2, 0x2, 0x68d, 0x68f, 0x5, 0x76, 0x3c, 0x2, 0x68e, 0x68d, 0x3, 0x2, 
    0x2, 0x2, 0x68e, 0x68f, 0x3, 0x2, 0x2, 0x2, 0x68f, 0x690, 0x3, 0x2, 
    0x2, 0x2, 0x690, 0x692, 0x7, 0x6, 0x2, 0x2, 0x691, 0x670, 0x3, 0x2, 
    0x2, 0x2, 0x691, 0x671, 0x3, 0x2, 0x2, 0x2, 0x692, 0x75, 0x3, 0x2, 0x2, 
    0x2, 0x693, 0x69b, 0x5, 0x78, 0x3d, 0x2, 0x694, 0x695, 0x7, 0xb5, 0x2, 
    0x2, 0x695, 0x696, 0x7, 0x67, 0x2, 0x2, 0x696, 0x69c, 0x7, 0xb7, 0x2, 
    0x2, 0x697, 0x698, 0x7, 0x9e, 0x2, 0x2, 0x698, 0x69c, 0x7, 0x80, 0x2, 
    0x2, 0x699, 0x69c, 0x7, 0x50, 0x2, 0x2, 0x69a, 0x69c, 0x7, 0xb6, 0x2, 
    0x2, 0x69b, 0x694, 0x3, 0x2, 0x2, 0x2, 0x69b, 0x697, 0x3, 0x2, 0x2, 
    0x2, 0x69b, 0x699, 0x3, 0x2, 0x2, 0x2, 0x69b, 0x69a, 0x3, 0x2, 0x2, 
    0x2, 0x69b, 0x69c, 0x3, 0x2, 0x2, 0x2, 0x69c, 0x77, 0x3, 0x2, 0x2, 0x2, 
    0x69d, 0x6a4, 0x9, 0x13, 0x2, 0x2, 0x69e, 0x6a5, 0x5, 0x8e, 0x48, 0x2, 
    0x69f, 0x6a0, 0x7, 0x29, 0x2, 0x2, 0x6a0, 0x6a1, 0x5, 0x8a, 0x46, 0x2, 
    0x6a1, 0x6a2, 0x7, 0x22, 0x2, 0x2, 0x6a2, 0x6a3, 0x5, 0x8c, 0x47, 0x2, 
    0x6a3, 0x6a5, 0x3, 0x2, 0x2, 0x2, 0x6a4, 0x69e, 0x3, 0x2, 0x2, 0x2, 
    0x6a4, 0x69f, 0x3, 0x2, 0x2, 0x2, 0x6a5, 0x79, 0x3, 0x2, 0x2, 0x2, 0x6a6, 
    0x6a7, 0x5, 0xd6, 0x6c, 0x2, 0x6a7, 0x6b1, 0x7, 0x5, 0x2, 0x2, 0x6a8, 
    0x6ad, 0x5, 0x40, 0x21, 0x2, 0x6a9, 0x6aa, 0x7, 0x7, 0x2, 0x2, 0x6aa, 
    0x6ac, 0x5, 0x40, 0x21, 0x2, 0x6ab, 0x6a9, 0x3, 0x2, 0x2, 0x2, 0x6ac, 
    0x6af, 0x3, 0x2, 0x2, 0x2, 0x6ad, 0x6ab, 0x3, 0x2, 0x2, 0x2, 0x6ad, 
    0x6ae, 0x3, 0x2, 0x2, 0x2, 0x6ae, 0x6b2, 0x3, 0x2, 0x2, 0x2, 0x6af, 
    0x6ad, 0x3, 0x2, 0x2, 0x2, 0x6b0, 0x6b2, 0x7, 0x9, 0x2, 0x2, 0x6b1, 
    0x6a8, 0x3, 0x2, 0x2, 0x2, 0x6b1, 0x6b0, 0x3, 0x2, 0x2, 0x2, 0x6b2, 
    0x6b3, 0x3, 0x2, 0x2, 0x2, 0x6b3, 0x6b4, 0x7, 0x6, 0x2, 0x2, 0x6b4, 
    0x7b, 0x3, 0x2, 0x2, 0x2, 0x6b5, 0x6b6, 0x5, 0xd8, 0x6d, 0x2, 0x6b6, 
    0x6c3, 0x7, 0x5, 0x2, 0x2, 0x6b7, 0x6b9, 0x7, 0x40, 0x2, 0x2, 0x6b8, 
    0x6b7, 0x3, 0x2, 0x2, 0x2, 0x6b8, 0x6b9, 0x3, 0x2, 0x2, 0x2, 0x6b9, 
    0x6ba, 0x3, 0x2, 0x2, 0x2, 0x6ba, 0x6bf, 0x5, 0x40, 0x21, 0x2, 0x6bb, 
    0x6bc, 0x7, 0x7, 0x2, 0x2, 0x6bc, 0x6be, 0x5, 0x40, 0x21, 0x2, 0x6bd, 
    0x6bb, 0x3, 0x2, 0x2, 0x2, 0x6be, 0x6c1, 0x3, 0x2, 0x2, 0x2, 0x6bf, 
    0x6bd, 0x3, 0x2, 0x2, 0x2, 0x6bf, 0x6c0, 0x3, 0x2, 0x2, 0x2, 0x6c0, 
    0x6c4, 0x3, 0x2, 0x2, 0x2, 0x6c1, 0x6bf, 0x3, 0x2, 0x2, 0x2, 0x6c2, 
    0x6c4, 0x7, 0x9, 0x2, 0x2, 0x6c3, 0x6b8, 0x3, 0x2, 0x2, 0x2, 0x6c3, 
    0x6c2, 0x3, 0x2, 0x2, 0x2, 0x6c3, 0x6c4, 0x3, 0x2, 0x2, 0x2, 0x6c4, 
    0x6c5, 0x3, 0x2, 0x2, 0x2, 0x6c5, 0x6c7, 0x7, 0x6, 0x2, 0x2, 0x6c6, 
    0x6c8, 0x5, 0x70, 0x39, 0x2, 0x6c7, 0x6c6, 0x3, 0x2, 0x2, 0x2, 0x6c7, 
    0x6c8, 0x3, 0x2, 0x2, 0x2, 0x6c8, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x6c9, 0x6ca, 
    0x5, 0x90, 0x49, 0x2, 0x6ca, 0x6d4, 0x7, 0x5, 0x2, 0x2, 0x6cb, 0x6d0, 
    0x5, 0x40, 0x21, 0x2, 0x6cc, 0x6cd, 0x7, 0x7, 0x2, 0x2, 0x6cd, 0x6cf, 
    0x5, 0x40, 0x21, 0x2, 0x6ce, 0x6cc, 0x3, 0x2, 0x2, 0x2, 0x6cf, 0x6d2, 
    0x3, 0x2, 0x2, 0x2, 0x6d0, 0x6ce, 0x3, 0x2, 0x2, 0x2, 0x6d0, 0x6d1, 
    0x3, 0x2, 0x2, 0x2, 0x6d1, 0x6d5, 0x3, 0x2, 0x2, 0x2, 0x6d2, 0x6d0, 
    0x3, 0x2, 0x2, 0x2, 0x6d3, 0x6d5, 0x7, 0x9, 0x2, 0x2, 0x6d4, 0x6cb, 
    0x3, 0x2, 0x2, 0x2, 0x6d4, 0x6d3, 0x3, 0x2, 0x2, 0x2, 0x6d4, 0x6d5, 
    0x3, 0x2, 0x2, 0x2, 0x6d5, 0x6d6, 0x3, 0x2, 0x2, 0x2, 0x6d6, 0x6d8, 
    0x7, 0x6, 0x2, 0x2, 0x6d7, 0x6d9, 0x5, 0x70, 0x39, 0x2, 0x6d8, 0x6d7, 
    0x3, 0x2, 0x2, 0x2, 0x6d8, 0x6d9, 0x3, 0x2, 0x2, 0x2, 0x6d9, 0x6da, 
    0x3, 0x2, 0x2, 0x2, 0x6da, 0x6dd, 0x7, 0x99, 0x2, 0x2, 0x6db, 0x6de, 
    0x5, 0x72, 0x3a, 0x2, 0x6dc, 0x6de, 0x5, 0xce, 0x68, 0x2, 0x6dd, 0x6db, 
    0x3, 0x2, 0x2, 0x2, 0x6dd, 0x6dc, 0x3, 0x2, 0x2, 0x2, 0x6de, 0x7f, 0x3, 
    0x2, 0x2, 0x2, 0x6df, 0x6e1, 0x7, 0x96, 0x2, 0x2, 0x6e0, 0x6e2, 0x7, 
    0x76, 0x2, 0x2, 0x6e1, 0x6e0, 0x3, 0x2, 0x2, 0x2, 0x6e1, 0x6e2, 0x3, 
    0x2, 0x2, 0x2, 0x6e2, 0x6e3, 0x3, 0x2, 0x2, 0x2, 0x6e3, 0x6e8, 0x5, 
    0x36, 0x1c, 0x2, 0x6e4, 0x6e5, 0x7, 0x7, 0x2, 0x2, 0x6e5, 0x6e7, 0x5, 
    0x36, 0x1c, 0x2, 0x6e6, 0x6e4, 0x3, 0x2, 0x2, 0x2, 0x6e7, 0x6ea, 0x3, 
    0x2, 0x2, 0x2, 0x6e8, 0x6e6, 0x3, 0x2, 0x2, 0x2, 0x6e8, 0x6e9, 0x3, 
    0x2, 0x2, 0x2, 0x6e9, 0x81, 0x3, 0x2, 0x2, 0x2, 0x6ea, 0x6e8, 0x3, 0x2, 
    0x2, 0x2, 0x6eb, 0x6ec, 0x7, 0x6f, 0x2, 0x2, 0x6ec, 0x6ed, 0x7, 0x2a, 
    0x2, 0x2, 0x6ed, 0x6f2, 0x5, 0x86, 0x44, 0x2, 0x6ee, 0x6ef, 0x7, 0x7, 
    0x2, 0x2, 0x6ef, 0x6f1, 0x5, 0x86, 0x44, 0x2, 0x6f0, 0x6ee, 0x3, 0x2, 
    0x2, 0x2, 0x6f1, 0x6f4, 0x3, 0x2, 0x2, 0x2, 0x6f2, 0x6f0, 0x3, 0x2, 
    0x2, 0x2, 0x6f2, 0x6f3, 0x3, 0x2, 0x2, 0x2, 0x6f3, 0x83, 0x3, 0x2, 0x2, 
    0x2, 0x6f4, 0x6f2, 0x3, 0x2, 0x2, 0x2, 0x6f5, 0x6f6, 0x7, 0x64, 0x2, 
    0x2, 0x6f6, 0x6f9, 0x5, 0x40, 0x21, 0x2, 0x6f7, 0x6f8, 0x9, 0x14, 0x2, 
    0x2, 0x6f8, 0x6fa, 0x5, 0x40, 0x21, 0x2, 0x6f9, 0x6f7, 0x3, 0x2, 0x2, 
    0x2, 0x6f9, 0x6fa, 0x3, 0x2, 0x2, 0x2, 0x6fa, 0x85, 0x3, 0x2, 0x2, 0x2, 
    0x6fb, 0x6fe, 0x5, 0x40, 0x21, 0x2, 0x6fc, 0x6fd, 0x7, 0x2f, 0x2, 0x2, 
    0x6fd, 0x6ff, 0x5, 0xba, 0x5e, 0x2, 0x6fe, 0x6fc, 0x3, 0x2, 0x2, 0x2, 
    0x6fe, 0x6ff, 0x3, 0x2, 0x2, 0x2, 0x6ff, 0x701, 0x3, 0x2, 0x2, 0x2, 
    0x700, 0x702, 0x5, 0x88, 0x45, 0x2, 0x701, 0x700, 0x3, 0x2, 0x2, 0x2, 
    0x701, 0x702, 0x3, 0x2, 0x2, 0x2, 0x702, 0x705, 0x3, 0x2, 0x2, 0x2, 
    0x703, 0x704, 0x7, 0xb0, 0x2, 0x2, 0x704, 0x706, 0x9, 0x15, 0x2, 0x2, 
    0x705, 0x703, 0x3, 0x2, 0x2, 0x2, 0x705, 0x706, 0x3, 0x2, 0x2, 0x2, 
    0x706, 0x87, 0x3, 0x2, 0x2, 0x2, 0x707, 0x708, 0x9, 0x16, 0x2, 0x2, 
    0x708, 0x89, 0x3, 0x2, 0x2, 0x2, 0x709, 0x70a, 0x5, 0x40, 0x21, 0x2, 
    0x70a, 0x70b, 0x7, 0x9c, 0x2, 0x2, 0x70b, 0x714, 0x3, 0x2, 0x2, 0x2, 
    0x70c, 0x70d, 0x5, 0x40, 0x21, 0x2, 0x70d, 0x70e, 0x7, 0x9f, 0x2, 0x2, 
    0x70e, 0x714, 0x3, 0x2, 0x2, 0x2, 0x70f, 0x710, 0x7, 0x9e, 0x2, 0x2, 
    0x710, 0x714, 0x7, 0x80, 0x2, 0x2, 0x711, 0x712, 0x7, 0x9d, 0x2, 0x2, 
    0x712, 0x714, 0x7, 0x9c, 0x2, 0x2, 0x713, 0x709, 0x3, 0x2, 0x2, 0x2, 
    0x713, 0x70c, 0x3, 0x2, 0x2, 0x2, 0x713, 0x70f, 0x3, 0x2, 0x2, 0x2, 
    0x713, 0x711, 0x3, 0x2, 0x2, 0x2, 0x714, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x715, 
    0x716, 0x5, 0x40, 0x21, 0x2, 0x716, 0x717, 0x7, 0x9c, 0x2, 0x2, 0x717, 
    0x720, 0x3, 0x2, 0x2, 0x2, 0x718, 0x719, 0x5, 0x40, 0x21, 0x2, 0x719, 
    0x71a, 0x7, 0x9f, 0x2, 0x2, 0x71a, 0x720, 0x3, 0x2, 0x2, 0x2, 0x71b, 
    0x71c, 0x7, 0x9e, 0x2, 0x2, 0x71c, 0x720, 0x7, 0x80, 0x2, 0x2, 0x71d, 
    0x71e, 0x7, 0x9d, 0x2, 0x2, 0x71e, 0x720, 0x7, 0x9f, 0x2, 0x2, 0x71f, 
    0x715, 0x3, 0x2, 0x2, 0x2, 0x71f, 0x718, 0x3, 0x2, 0x2, 0x2, 0x71f, 
    0x71b, 0x3, 0x2, 0x2, 0x2, 0x71f, 0x71d, 0x3, 0x2, 0x2, 0x2, 0x720, 
    0x8d, 0x3, 0x2, 0x2, 0x2, 0x721, 0x722, 0x5, 0x40, 0x21, 0x2, 0x722, 
    0x723, 0x7, 0x9c, 0x2, 0x2, 0x723, 0x729, 0x3, 0x2, 0x2, 0x2, 0x724, 
    0x725, 0x7, 0x9d, 0x2, 0x2, 0x725, 0x729, 0x7, 0x9c, 0x2, 0x2, 0x726, 
    0x727, 0x7, 0x9e, 0x2, 0x2, 0x727, 0x729, 0x7, 0x80, 0x2, 0x2, 0x728, 
    0x721, 0x3, 0x2, 0x2, 0x2, 0x728, 0x724, 0x3, 0x2, 0x2, 0x2, 0x728, 
    0x726, 0x3, 0x2, 0x2, 0x2, 0x729, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x72a, 0x72b, 
    0x9, 0x17, 0x2, 0x2, 0x72b, 0x72c, 0x7, 0x5, 0x2, 0x2, 0x72c, 0x72d, 
    0x5, 0x40, 0x21, 0x2, 0x72d, 0x72e, 0x7, 0x6, 0x2, 0x2, 0x72e, 0x72f, 
    0x7, 0x99, 0x2, 0x2, 0x72f, 0x731, 0x7, 0x5, 0x2, 0x2, 0x730, 0x732, 
    0x5, 0x96, 0x4c, 0x2, 0x731, 0x730, 0x3, 0x2, 0x2, 0x2, 0x731, 0x732, 
    0x3, 0x2, 0x2, 0x2, 0x732, 0x733, 0x3, 0x2, 0x2, 0x2, 0x733, 0x735, 
    0x5, 0x9a, 0x4e, 0x2, 0x734, 0x736, 0x5, 0x78, 0x3d, 0x2, 0x735, 0x734, 
    0x3, 0x2, 0x2, 0x2, 0x735, 0x736, 0x3, 0x2, 0x2, 0x2, 0x736, 0x737, 
    0x3, 0x2, 0x2, 0x2, 0x737, 0x738, 0x7, 0x6, 0x2, 0x2, 0x738, 0x780, 
    0x3, 0x2, 0x2, 0x2, 0x739, 0x73a, 0x9, 0x18, 0x2, 0x2, 0x73a, 0x73b, 
    0x7, 0x5, 0x2, 0x2, 0x73b, 0x73c, 0x7, 0x6, 0x2, 0x2, 0x73c, 0x73d, 
    0x7, 0x99, 0x2, 0x2, 0x73d, 0x73f, 0x7, 0x5, 0x2, 0x2, 0x73e, 0x740, 
    0x5, 0x96, 0x4c, 0x2, 0x73f, 0x73e, 0x3, 0x2, 0x2, 0x2, 0x73f, 0x740, 
    0x3, 0x2, 0x2, 0x2, 0x740, 0x742, 0x3, 0x2, 0x2, 0x2, 0x741, 0x743, 
    0x5, 0x98, 0x4d, 0x2, 0x742, 0x741, 0x3, 0x2, 0x2, 0x2, 0x742, 0x743, 
    0x3, 0x2, 0x2, 0x2, 0x743, 0x744, 0x3, 0x2, 0x2, 0x2, 0x744, 0x780, 
    0x7, 0x6, 0x2, 0x2, 0x745, 0x746, 0x9, 0x19, 0x2, 0x2, 0x746, 0x747, 
    0x7, 0x5, 0x2, 0x2, 0x747, 0x748, 0x7, 0x6, 0x2, 0x2, 0x748, 0x749, 
    0x7, 0x99, 0x2, 0x2, 0x749, 0x74b, 0x7, 0x5, 0x2, 0x2, 0x74a, 0x74c, 
    0x5, 0x96, 0x4c, 0x2, 0x74b, 0x74a, 0x3, 0x2, 0x2, 0x2, 0x74b, 0x74c, 
    0x3, 0x2, 0x2, 0x2, 0x74c, 0x74d, 0x3, 0x2, 0x2, 0x2, 0x74d, 0x74e, 
    0x5, 0x9a, 0x4e, 0x2, 0x74e, 0x74f, 0x7, 0x6, 0x2, 0x2, 0x74f, 0x780, 
    0x3, 0x2, 0x2, 0x2, 0x750, 0x751, 0x9, 0x1a, 0x2, 0x2, 0x751, 0x752, 
    0x7, 0x5, 0x2, 0x2, 0x752, 0x754, 0x5, 0x40, 0x21, 0x2, 0x753, 0x755, 
    0x5, 0x92, 0x4a, 0x2, 0x754, 0x753, 0x3, 0x2, 0x2, 0x2, 0x754, 0x755, 
    0x3, 0x2, 0x2, 0x2, 0x755, 0x757, 0x3, 0x2, 0x2, 0x2, 0x756, 0x758, 
    0x5, 0x94, 0x4b, 0x2, 0x757, 0x756, 0x3, 0x2, 0x2, 0x2, 0x757, 0x758, 
    0x3, 0x2, 0x2, 0x2, 0x758, 0x759, 0x3, 0x2, 0x2, 0x2, 0x759, 0x75a, 
    0x7, 0x6, 0x2, 0x2, 0x75a, 0x75b, 0x7, 0x99, 0x2, 0x2, 0x75b, 0x75d, 
    0x7, 0x5, 0x2, 0x2, 0x75c, 0x75e, 0x5, 0x96, 0x4c, 0x2, 0x75d, 0x75c, 
    0x3, 0x2, 0x2, 0x2, 0x75d, 0x75e, 0x3, 0x2, 0x2, 0x2, 0x75e, 0x75f, 
    0x3, 0x2, 0x2, 0x2, 0x75f, 0x760, 0x5, 0x9a, 0x4e, 0x2, 0x760, 0x761, 
    0x7, 0x6, 0x2, 0x2, 0x761, 0x780, 0x3, 0x2, 0x2, 0x2, 0x762, 0x763, 
    0x7, 0xa5, 0x2, 0x2, 0x763, 0x764, 0x7, 0x5, 0x2, 0x2, 0x764, 0x765, 
    0x5, 0x40, 0x21, 0x2, 0x765, 0x766, 0x7, 0x7, 0x2, 0x2, 0x766, 0x767, 
    0x5, 0x22, 0x12, 0x2, 0x767, 0x768, 0x7, 0x6, 0x2, 0x2, 0x768, 0x769, 
    0x7, 0x99, 0x2, 0x2, 0x769, 0x76b, 0x7, 0x5, 0x2, 0x2, 0x76a, 0x76c, 
    0x5, 0x96, 0x4c, 0x2, 0x76b, 0x76a, 0x3, 0x2, 0x2, 0x2, 0x76b, 0x76c, 
    0x3, 0x2, 0x2, 0x2, 0x76c, 0x76d, 0x3, 0x2, 0x2, 0x2, 0x76d, 0x76f, 
    0x5, 0x9a, 0x4e, 0x2, 0x76e, 0x770, 0x5, 0x78, 0x3d, 0x2, 0x76f, 0x76e, 
    0x3, 0x2, 0x2, 0x2, 0x76f, 0x770, 0x3, 0x2, 0x2, 0x2, 0x770, 0x771, 
    0x3, 0x2, 0x2, 0x2, 0x771, 0x772, 0x7, 0x6, 0x2, 0x2, 0x772, 0x780, 
    0x3, 0x2, 0x2, 0x2, 0x773, 0x774, 0x7, 0xa6, 0x2, 0x2, 0x774, 0x775, 
    0x7, 0x5, 0x2, 0x2, 0x775, 0x776, 0x5, 0x40, 0x21, 0x2, 0x776, 0x777, 
    0x7, 0x6, 0x2, 0x2, 0x777, 0x778, 0x7, 0x99, 0x2, 0x2, 0x778, 0x77a, 
    0x7, 0x5, 0x2, 0x2, 0x779, 0x77b, 0x5, 0x96, 0x4c, 0x2, 0x77a, 0x779, 
    0x3, 0x2, 0x2, 0x2, 0x77a, 0x77b, 0x3, 0x2, 0x2, 0x2, 0x77b, 0x77c, 
    0x3, 0x2, 0x2, 0x2, 0x77c, 0x77d, 0x5, 0x9a, 0x4e, 0x2, 0x77d, 0x77e, 
    0x7, 0x6, 0x2, 0x2, 0x77e, 0x780, 0x3, 0x2, 0x2, 0x2, 0x77f, 0x72a, 
    0x3, 0x2, 0x2, 0x2, 0x77f, 0x739, 0x3, 0x2, 0x2, 0x2, 0x77f, 0x745, 
    0x3, 0x2, 0x2, 0x2, 0x77f, 0x750, 0x3, 0x2, 0x2, 0x2, 0x77f, 0x762, 
    0x3, 0x2, 0x2, 0x2, 0x77f, 0x773, 0x3, 0x2, 0x2, 0x2, 0x780, 0x91, 0x3, 
    0x2, 0x2, 0x2, 0x781, 0x782, 0x7, 0x7, 0x2, 0x2, 0x782, 0x783, 0x5, 
    0x22, 0x12, 0x2, 0x783, 0x93, 0x3, 0x2, 0x2, 0x2, 0x784, 0x785, 0x7, 
    0x7, 0x2, 0x2, 0x785, 0x786, 0x5, 0x22, 0x12, 0x2, 0x786, 0x95, 0x3, 
    0x2, 0x2, 0x2, 0x787, 0x788, 0x7, 0x9a, 0x2, 0x2, 0x788, 0x78a, 0x7, 
    0x2a, 0x2, 0x2, 0x789, 0x78b, 0x5, 0x40, 0x21, 0x2, 0x78a, 0x789, 0x3, 
    0x2, 0x2, 0x2, 0x78b, 0x78c, 0x3, 0x2, 0x2, 0x2, 0x78c, 0x78a, 0x3, 
    0x2, 0x2, 0x2, 0x78c, 0x78d, 0x3, 0x2, 0x2, 0x2, 0x78d, 0x97, 0x3, 0x2, 
    0x2, 0x2, 0x78e, 0x78f, 0x7, 0x6f, 0x2, 0x2, 0x78f, 0x791, 0x7, 0x2a, 
    0x2, 0x2, 0x790, 0x792, 0x5, 0x40, 0x21, 0x2, 0x791, 0x790, 0x3, 0x2, 
    0x2, 0x2, 0x792, 0x793, 0x3, 0x2, 0x2, 0x2, 0x793, 0x791, 0x3, 0x2, 
    0x2, 0x2, 0x793, 0x794, 0x3, 0x2, 0x2, 0x2, 0x794, 0x99, 0x3, 0x2, 0x2, 
    0x2, 0x795, 0x796, 0x7, 0x6f, 0x2, 0x2, 0x796, 0x797, 0x7, 0x2a, 0x2, 
    0x2, 0x797, 0x798, 0x5, 0x9a, 0x4e, 0x2, 0x798, 0x9b, 0x3, 0x2, 0x2, 
    0x2, 0x799, 0x79b, 0x5, 0x40, 0x21, 0x2, 0x79a, 0x79c, 0x5, 0x88, 0x45, 
    0x2, 0x79b, 0x79a, 0x3, 0x2, 0x2, 0x2, 0x79b, 0x79c, 0x3, 0x2, 0x2, 
    0x2, 0x79c, 0x7a4, 0x3, 0x2, 0x2, 0x2, 0x79d, 0x79e, 0x7, 0x7, 0x2, 
    0x2, 0x79e, 0x7a0, 0x5, 0x40, 0x21, 0x2, 0x79f, 0x7a1, 0x5, 0x88, 0x45, 
    0x2, 0x7a0, 0x79f, 0x3, 0x2, 0x2, 0x2, 0x7a0, 0x7a1, 0x3, 0x2, 0x2, 
    0x2, 0x7a1, 0x7a3, 0x3, 0x2, 0x2, 0x2, 0x7a2, 0x79d, 0x3, 0x2, 0x2, 
    0x2, 0x7a3, 0x7a6, 0x3, 0x2, 0x2, 0x2, 0x7a4, 0x7a2, 0x3, 0x2, 0x2, 
    0x2, 0x7a4, 0x7a5, 0x3, 0x2, 0x2, 0x2, 0x7a5, 0x9d, 0x3, 0x2, 0x2, 0x2, 
    0x7a6, 0x7a4, 0x3, 0x2, 0x2, 0x2, 0x7a7, 0x7a8, 0x5, 0x50, 0x29, 0x2, 
    0x7a8, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x7a9, 0x7aa, 0x5, 0x50, 0x29, 0x2, 
    0x7aa, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x7ab, 0x7ac, 0x9, 0x1b, 0x2, 0x2, 
    0x7ac, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x7ad, 0x7ae, 0x7, 0xbd, 0x2, 0x2, 
    0x7ae, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x7af, 0x7b2, 0x5, 0x40, 0x21, 0x2, 
    0x7b0, 0x7b2, 0x5, 0x1c, 0xf, 0x2, 0x7b1, 0x7af, 0x3, 0x2, 0x2, 0x2, 
    0x7b1, 0x7b0, 0x3, 0x2, 0x2, 0x2, 0x7b2, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x7b3, 
    0x7b4, 0x9, 0x1c, 0x2, 0x2, 0x7b4, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x7b5, 
    0x7b6, 0x9, 0x1d, 0x2, 0x2, 0x7b6, 0xab, 0x3, 0x2, 0x2, 0x2, 0x7b7, 
    0x7b8, 0x5, 0xdc, 0x6f, 0x2, 0x7b8, 0xad, 0x3, 0x2, 0x2, 0x2, 0x7b9, 
    0x7ba, 0x5, 0xdc, 0x6f, 0x2, 0x7ba, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x7bb, 
    0x7bc, 0x5, 0xdc, 0x6f, 0x2, 0x7bc, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x7bd, 
    0x7be, 0x5, 0xdc, 0x6f, 0x2, 0x7be, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x7bf, 
    0x7c0, 0x5, 0xdc, 0x6f, 0x2, 0x7c0, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x7c1, 
    0x7c2, 0x5, 0xdc, 0x6f, 0x2, 0x7c2, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x7c3, 
    0x7c4, 0x5, 0xdc, 0x6f, 0x2, 0x7c4, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x7c5, 
    0x7c6, 0x5, 0xdc, 0x6f, 0x2, 0x7c6, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x7c7, 
    0x7c8, 0x5, 0xdc, 0x6f, 0x2, 0x7c8, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x7c9, 
    0x7ca, 0x5, 0xdc, 0x6f, 0x2, 0x7ca, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x7cb, 
    0x7cc, 0x5, 0xdc, 0x6f, 0x2, 0x7cc, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x7cd, 
    0x7ce, 0x5, 0xdc, 0x6f, 0x2, 0x7ce, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x7cf, 
    0x7d0, 0x5, 0xdc, 0x6f, 0x2, 0x7d0, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x7d1, 
    0x7d2, 0x5, 0xdc, 0x6f, 0x2, 0x7d2, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x7d3, 
    0x7d4, 0x5, 0xdc, 0x6f, 0x2, 0x7d4, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x7d5, 
    0x7d6, 0x5, 0xdc, 0x6f, 0x2, 0x7d6, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x7d7, 
    0x7d8, 0x5, 0xdc, 0x6f, 0x2, 0x7d8, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x7d9, 
    0x7da, 0x5, 0xdc, 0x6f, 0x2, 0x7da, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x7db, 
    0x7dc, 0x5, 0xdc, 0x6f, 0x2, 0x7dc, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x7dd, 
    0x7de, 0x5, 0xdc, 0x6f, 0x2, 0x7de, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x7df, 
    0x7e0, 0x5, 0xdc, 0x6f, 0x2, 0x7e0, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x7e1, 
    0x7e2, 0x5, 0xdc, 0x6f, 0x2, 0x7e2, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x7e3, 
    0x7e4, 0x5, 0xdc, 0x6f, 0x2, 0x7e4, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x7e5, 
    0x7e6, 0x5, 0xdc, 0x6f, 0x2, 0x7e6, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x7e7, 
    0x7ef, 0x7, 0xba, 0x2, 0x2, 0x7e8, 0x7ef, 0x5, 0xaa, 0x56, 0x2, 0x7e9, 
    0x7ef, 0x7, 0xbd, 0x2, 0x2, 0x7ea, 0x7eb, 0x7, 0x5, 0x2, 0x2, 0x7eb, 
    0x7ec, 0x5, 0xdc, 0x6f, 0x2, 0x7ec, 0x7ed, 0x7, 0x6, 0x2, 0x2, 0x7ed, 
    0x7ef, 0x3, 0x2, 0x2, 0x2, 0x7ee, 0x7e7, 0x3, 0x2, 0x2, 0x2, 0x7ee, 
    0x7e8, 0x3, 0x2, 0x2, 0x2, 0x7ee, 0x7e9, 0x3, 0x2, 0x2, 0x2, 0x7ee, 
    0x7ea, 0x3, 0x2, 0x2, 0x2, 0x7ef, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x121, 0xe1, 
    0xe8, 0xed, 0xf3, 0xf9, 0xfb, 0x115, 0x11c, 0x123, 0x129, 0x12d, 0x130, 
    0x137, 0x13a, 0x13e, 0x146, 0x14a, 0x14c, 0x150, 0x154, 0x158, 0x15b, 
    0x162, 0x168, 0x16e, 0x173, 0x17e, 0x184, 0x188, 0x18c, 0x18f, 0x193, 
    0x199, 0x19e, 0x1a7, 0x1ae, 0x1b4, 0x1b8, 0x1bc, 0x1c1, 0x1c7, 0x1d3, 
    0x1d7, 0x1dc, 0x1df, 0x1e2, 0x1e7, 0x1ea, 0x1f8, 0x1ff, 0x206, 0x208, 
    0x20b, 0x211, 0x216, 0x21e, 0x223, 0x232, 0x238, 0x242, 0x247, 0x251, 
    0x255, 0x257, 0x25b, 0x260, 0x262, 0x26a, 0x270, 0x275, 0x27c, 0x287, 
    0x28a, 0x28c, 0x293, 0x297, 0x29e, 0x2a4, 0x2aa, 0x2b0, 0x2b5, 0x2be, 
    0x2c3, 0x2ce, 0x2d3, 0x2de, 0x2e3, 0x2e7, 0x2f7, 0x301, 0x306, 0x30e, 
    0x31a, 0x31f, 0x327, 0x32e, 0x331, 0x338, 0x33b, 0x33e, 0x342, 0x34a, 
    0x34f, 0x359, 0x35e, 0x367, 0x36e, 0x372, 0x376, 0x379, 0x381, 0x38e, 
    0x391, 0x399, 0x3a2, 0x3a6, 0x3ab, 0x3c9, 0x3d5, 0x3da, 0x3e6, 0x3ec, 
    0x3f3, 0x3f7, 0x401, 0x404, 0x40a, 0x410, 0x419, 0x41c, 0x420, 0x422, 
    0x424, 0x42d, 0x434, 0x43b, 0x441, 0x446, 0x44e, 0x453, 0x45c, 0x467, 
    0x46e, 0x472, 0x475, 0x479, 0x483, 0x489, 0x48b, 0x493, 0x49a, 0x4a1, 
    0x4a6, 0x4a8, 0x4ae, 0x4b7, 0x4bc, 0x4c3, 0x4c7, 0x4c9, 0x4cc, 0x4d4, 
    0x4d8, 0x4db, 0x4e1, 0x4e5, 0x4ea, 0x4f1, 0x4fa, 0x4fe, 0x500, 0x504, 
    0x50d, 0x512, 0x514, 0x521, 0x524, 0x52d, 0x538, 0x53f, 0x542, 0x547, 
    0x54b, 0x54e, 0x551, 0x556, 0x55a, 0x55f, 0x562, 0x565, 0x56a, 0x56e, 
    0x571, 0x578, 0x57d, 0x586, 0x58b, 0x58e, 0x596, 0x59a, 0x5a2, 0x5a5, 
    0x5a7, 0x5b0, 0x5b3, 0x5b5, 0x5b9, 0x5bd, 0x5c1, 0x5c4, 0x5cf, 0x5d4, 
    0x5d8, 0x5dc, 0x5df, 0x5e4, 0x5ea, 0x5f1, 0x5f8, 0x5fd, 0x605, 0x60b, 
    0x610, 0x616, 0x61d, 0x624, 0x629, 0x62c, 0x62f, 0x634, 0x639, 0x640, 
    0x644, 0x648, 0x652, 0x65b, 0x65e, 0x667, 0x66b, 0x673, 0x67c, 0x67f, 
    0x688, 0x68b, 0x68e, 0x691, 0x69b, 0x6a4, 0x6ad, 0x6b1, 0x6b8, 0x6bf, 
    0x6c3, 0x6c7, 0x6d0, 0x6d4, 0x6d8, 0x6dd, 0x6e1, 0x6e8, 0x6f2, 0x6f9, 
    0x6fe, 0x701, 0x705, 0x713, 0x71f, 0x728, 0x731, 0x735, 0x73f, 0x742, 
    0x74b, 0x754, 0x757, 0x75d, 0x76b, 0x76f, 0x77a, 0x77f, 0x78c, 0x793, 
    0x79b, 0x7a0, 0x7a4, 0x7b1, 0x7ee, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SqlParsingParser::Initializer SqlParsingParser::_init;
