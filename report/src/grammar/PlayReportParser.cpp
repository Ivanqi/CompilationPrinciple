
// Generated from PlayReport.g4 by ANTLR 4.8


#include "PlayReportListener.h"
#include "PlayReportVisitor.h"

#include "PlayReportParser.h"


using namespace antlrcpp;
using namespace antlr4;

PlayReportParser::PlayReportParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

PlayReportParser::~PlayReportParser() {
  delete _interpreter;
}

std::string PlayReportParser::getGrammarFileName() const {
  return "PlayReport.g4";
}

const std::vector<std::string>& PlayReportParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& PlayReportParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- BracedExpressionContext ------------------------------------------------------------------

PlayReportParser::BracedExpressionContext::BracedExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PlayReportParser::BracedExpressionContext::LBRACE() {
  return getToken(PlayReportParser::LBRACE, 0);
}

tree::TerminalNode* PlayReportParser::BracedExpressionContext::ASSIGN() {
  return getToken(PlayReportParser::ASSIGN, 0);
}

PlayReportParser::ExpressionContext* PlayReportParser::BracedExpressionContext::expression() {
  return getRuleContext<PlayReportParser::ExpressionContext>(0);
}

tree::TerminalNode* PlayReportParser::BracedExpressionContext::RBRACE() {
  return getToken(PlayReportParser::RBRACE, 0);
}


size_t PlayReportParser::BracedExpressionContext::getRuleIndex() const {
  return PlayReportParser::RuleBracedExpression;
}

void PlayReportParser::BracedExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PlayReportListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBracedExpression(this);
}

void PlayReportParser::BracedExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PlayReportListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBracedExpression(this);
}


antlrcpp::Any PlayReportParser::BracedExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlayReportVisitor*>(visitor))
    return parserVisitor->visitBracedExpression(this);
  else
    return visitor->visitChildren(this);
}

PlayReportParser::BracedExpressionContext* PlayReportParser::bracedExpression() {
  BracedExpressionContext *_localctx = _tracker.createInstance<BracedExpressionContext>(_ctx, getState());
  enterRule(_localctx, 0, PlayReportParser::RuleBracedExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(16);
    match(PlayReportParser::LBRACE);
    setState(17);
    match(PlayReportParser::ASSIGN);
    setState(18);
    expression(0);
    setState(19);
    match(PlayReportParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

PlayReportParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PlayReportParser::PrimaryContext* PlayReportParser::ExpressionContext::primary() {
  return getRuleContext<PlayReportParser::PrimaryContext>(0);
}

PlayReportParser::FunctionCallContext* PlayReportParser::ExpressionContext::functionCall() {
  return getRuleContext<PlayReportParser::FunctionCallContext>(0);
}

std::vector<PlayReportParser::ExpressionContext *> PlayReportParser::ExpressionContext::expression() {
  return getRuleContexts<PlayReportParser::ExpressionContext>();
}

PlayReportParser::ExpressionContext* PlayReportParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<PlayReportParser::ExpressionContext>(i);
}

tree::TerminalNode* PlayReportParser::ExpressionContext::MUL() {
  return getToken(PlayReportParser::MUL, 0);
}

tree::TerminalNode* PlayReportParser::ExpressionContext::DIV() {
  return getToken(PlayReportParser::DIV, 0);
}

tree::TerminalNode* PlayReportParser::ExpressionContext::MOD() {
  return getToken(PlayReportParser::MOD, 0);
}

tree::TerminalNode* PlayReportParser::ExpressionContext::ADD() {
  return getToken(PlayReportParser::ADD, 0);
}

tree::TerminalNode* PlayReportParser::ExpressionContext::SUB() {
  return getToken(PlayReportParser::SUB, 0);
}

tree::TerminalNode* PlayReportParser::ExpressionContext::LE() {
  return getToken(PlayReportParser::LE, 0);
}

tree::TerminalNode* PlayReportParser::ExpressionContext::GE() {
  return getToken(PlayReportParser::GE, 0);
}

tree::TerminalNode* PlayReportParser::ExpressionContext::GT() {
  return getToken(PlayReportParser::GT, 0);
}

tree::TerminalNode* PlayReportParser::ExpressionContext::LT() {
  return getToken(PlayReportParser::LT, 0);
}

tree::TerminalNode* PlayReportParser::ExpressionContext::EQUAL() {
  return getToken(PlayReportParser::EQUAL, 0);
}

tree::TerminalNode* PlayReportParser::ExpressionContext::NOTEQUAL() {
  return getToken(PlayReportParser::NOTEQUAL, 0);
}

tree::TerminalNode* PlayReportParser::ExpressionContext::AND() {
  return getToken(PlayReportParser::AND, 0);
}

tree::TerminalNode* PlayReportParser::ExpressionContext::OR() {
  return getToken(PlayReportParser::OR, 0);
}


size_t PlayReportParser::ExpressionContext::getRuleIndex() const {
  return PlayReportParser::RuleExpression;
}

void PlayReportParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PlayReportListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void PlayReportParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PlayReportListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any PlayReportParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlayReportVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


PlayReportParser::ExpressionContext* PlayReportParser::expression() {
   return expression(0);
}

PlayReportParser::ExpressionContext* PlayReportParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PlayReportParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  PlayReportParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, PlayReportParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(24);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      setState(22);
      primary();
      break;
    }

    case 2: {
      setState(23);
      functionCall();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(46);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(44);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(26);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(27);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 88) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 88)) & ((1ULL << (PlayReportParser::MUL - 88))
            | (1ULL << (PlayReportParser::DIV - 88))
            | (1ULL << (PlayReportParser::MOD - 88)))) != 0))) {
            dynamic_cast<ExpressionContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(28);
          expression(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(29);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(30);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == PlayReportParser::ADD

          || _la == PlayReportParser::SUB)) {
            dynamic_cast<ExpressionContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(31);
          expression(6);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(32);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(33);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 72) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 72)) & ((1ULL << (PlayReportParser::GT - 72))
            | (1ULL << (PlayReportParser::LT - 72))
            | (1ULL << (PlayReportParser::LE - 72))
            | (1ULL << (PlayReportParser::GE - 72)))) != 0))) {
            dynamic_cast<ExpressionContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(34);
          expression(5);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(35);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(36);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == PlayReportParser::EQUAL

          || _la == PlayReportParser::NOTEQUAL)) {
            dynamic_cast<ExpressionContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(37);
          expression(4);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(38);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(39);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = match(PlayReportParser::AND);
          setState(40);
          expression(3);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(41);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(42);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = match(PlayReportParser::OR);
          setState(43);
          expression(2);
          break;
        }

        } 
      }
      setState(48);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

PlayReportParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PlayReportParser::PrimaryContext::LPAREN() {
  return getToken(PlayReportParser::LPAREN, 0);
}

PlayReportParser::ExpressionContext* PlayReportParser::PrimaryContext::expression() {
  return getRuleContext<PlayReportParser::ExpressionContext>(0);
}

tree::TerminalNode* PlayReportParser::PrimaryContext::RPAREN() {
  return getToken(PlayReportParser::RPAREN, 0);
}

PlayReportParser::LiteralContext* PlayReportParser::PrimaryContext::literal() {
  return getRuleContext<PlayReportParser::LiteralContext>(0);
}

tree::TerminalNode* PlayReportParser::PrimaryContext::IDENTIFIER() {
  return getToken(PlayReportParser::IDENTIFIER, 0);
}


size_t PlayReportParser::PrimaryContext::getRuleIndex() const {
  return PlayReportParser::RulePrimary;
}

void PlayReportParser::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PlayReportListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}

void PlayReportParser::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PlayReportListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}


antlrcpp::Any PlayReportParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlayReportVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

PlayReportParser::PrimaryContext* PlayReportParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 4, PlayReportParser::RulePrimary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(55);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PlayReportParser::LPAREN: {
        enterOuterAlt(_localctx, 1);
        setState(49);
        match(PlayReportParser::LPAREN);
        setState(50);
        expression(0);
        setState(51);
        match(PlayReportParser::RPAREN);
        break;
      }

      case PlayReportParser::DECIMAL_LITERAL:
      case PlayReportParser::HEX_LITERAL:
      case PlayReportParser::OCT_LITERAL:
      case PlayReportParser::BINARY_LITERAL:
      case PlayReportParser::FLOAT_LITERAL:
      case PlayReportParser::HEX_FLOAT_LITERAL:
      case PlayReportParser::BOOL_LITERAL:
      case PlayReportParser::CHAR_LITERAL:
      case PlayReportParser::STRING_LITERAL:
      case PlayReportParser::NULL_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(53);
        literal();
        break;
      }

      case PlayReportParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(54);
        match(PlayReportParser::IDENTIFIER);
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

//----------------- ExpressionListContext ------------------------------------------------------------------

PlayReportParser::ExpressionListContext::ExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PlayReportParser::ExpressionContext *> PlayReportParser::ExpressionListContext::expression() {
  return getRuleContexts<PlayReportParser::ExpressionContext>();
}

PlayReportParser::ExpressionContext* PlayReportParser::ExpressionListContext::expression(size_t i) {
  return getRuleContext<PlayReportParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> PlayReportParser::ExpressionListContext::COMMA() {
  return getTokens(PlayReportParser::COMMA);
}

tree::TerminalNode* PlayReportParser::ExpressionListContext::COMMA(size_t i) {
  return getToken(PlayReportParser::COMMA, i);
}


size_t PlayReportParser::ExpressionListContext::getRuleIndex() const {
  return PlayReportParser::RuleExpressionList;
}

void PlayReportParser::ExpressionListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PlayReportListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionList(this);
}

void PlayReportParser::ExpressionListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PlayReportListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionList(this);
}


antlrcpp::Any PlayReportParser::ExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlayReportVisitor*>(visitor))
    return parserVisitor->visitExpressionList(this);
  else
    return visitor->visitChildren(this);
}

PlayReportParser::ExpressionListContext* PlayReportParser::expressionList() {
  ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 6, PlayReportParser::RuleExpressionList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    expression(0);
    setState(62);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PlayReportParser::COMMA) {
      setState(58);
      match(PlayReportParser::COMMA);
      setState(59);
      expression(0);
      setState(64);
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

//----------------- FunctionCallContext ------------------------------------------------------------------

PlayReportParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PlayReportParser::FunctionCallContext::IDENTIFIER() {
  return getToken(PlayReportParser::IDENTIFIER, 0);
}

tree::TerminalNode* PlayReportParser::FunctionCallContext::LPAREN() {
  return getToken(PlayReportParser::LPAREN, 0);
}

tree::TerminalNode* PlayReportParser::FunctionCallContext::RPAREN() {
  return getToken(PlayReportParser::RPAREN, 0);
}

PlayReportParser::ExpressionListContext* PlayReportParser::FunctionCallContext::expressionList() {
  return getRuleContext<PlayReportParser::ExpressionListContext>(0);
}


size_t PlayReportParser::FunctionCallContext::getRuleIndex() const {
  return PlayReportParser::RuleFunctionCall;
}

void PlayReportParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PlayReportListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void PlayReportParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PlayReportListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}


antlrcpp::Any PlayReportParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlayReportVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

PlayReportParser::FunctionCallContext* PlayReportParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 8, PlayReportParser::RuleFunctionCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65);
    match(PlayReportParser::IDENTIFIER);
    setState(66);
    match(PlayReportParser::LPAREN);
    setState(68);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 52) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 52)) & ((1ULL << (PlayReportParser::DECIMAL_LITERAL - 52))
      | (1ULL << (PlayReportParser::HEX_LITERAL - 52))
      | (1ULL << (PlayReportParser::OCT_LITERAL - 52))
      | (1ULL << (PlayReportParser::BINARY_LITERAL - 52))
      | (1ULL << (PlayReportParser::FLOAT_LITERAL - 52))
      | (1ULL << (PlayReportParser::HEX_FLOAT_LITERAL - 52))
      | (1ULL << (PlayReportParser::BOOL_LITERAL - 52))
      | (1ULL << (PlayReportParser::CHAR_LITERAL - 52))
      | (1ULL << (PlayReportParser::STRING_LITERAL - 52))
      | (1ULL << (PlayReportParser::NULL_LITERAL - 52))
      | (1ULL << (PlayReportParser::LPAREN - 52))
      | (1ULL << (PlayReportParser::IDENTIFIER - 52)))) != 0)) {
      setState(67);
      expressionList();
    }
    setState(70);
    match(PlayReportParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

PlayReportParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PlayReportParser::IntegerLiteralContext* PlayReportParser::LiteralContext::integerLiteral() {
  return getRuleContext<PlayReportParser::IntegerLiteralContext>(0);
}

PlayReportParser::FloatLiteralContext* PlayReportParser::LiteralContext::floatLiteral() {
  return getRuleContext<PlayReportParser::FloatLiteralContext>(0);
}

tree::TerminalNode* PlayReportParser::LiteralContext::CHAR_LITERAL() {
  return getToken(PlayReportParser::CHAR_LITERAL, 0);
}

tree::TerminalNode* PlayReportParser::LiteralContext::STRING_LITERAL() {
  return getToken(PlayReportParser::STRING_LITERAL, 0);
}

tree::TerminalNode* PlayReportParser::LiteralContext::BOOL_LITERAL() {
  return getToken(PlayReportParser::BOOL_LITERAL, 0);
}

tree::TerminalNode* PlayReportParser::LiteralContext::NULL_LITERAL() {
  return getToken(PlayReportParser::NULL_LITERAL, 0);
}


size_t PlayReportParser::LiteralContext::getRuleIndex() const {
  return PlayReportParser::RuleLiteral;
}

void PlayReportParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PlayReportListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void PlayReportParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PlayReportListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


antlrcpp::Any PlayReportParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlayReportVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

PlayReportParser::LiteralContext* PlayReportParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 10, PlayReportParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(78);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PlayReportParser::DECIMAL_LITERAL:
      case PlayReportParser::HEX_LITERAL:
      case PlayReportParser::OCT_LITERAL:
      case PlayReportParser::BINARY_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(72);
        integerLiteral();
        break;
      }

      case PlayReportParser::FLOAT_LITERAL:
      case PlayReportParser::HEX_FLOAT_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(73);
        floatLiteral();
        break;
      }

      case PlayReportParser::CHAR_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(74);
        match(PlayReportParser::CHAR_LITERAL);
        break;
      }

      case PlayReportParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 4);
        setState(75);
        match(PlayReportParser::STRING_LITERAL);
        break;
      }

      case PlayReportParser::BOOL_LITERAL: {
        enterOuterAlt(_localctx, 5);
        setState(76);
        match(PlayReportParser::BOOL_LITERAL);
        break;
      }

      case PlayReportParser::NULL_LITERAL: {
        enterOuterAlt(_localctx, 6);
        setState(77);
        match(PlayReportParser::NULL_LITERAL);
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

//----------------- IntegerLiteralContext ------------------------------------------------------------------

PlayReportParser::IntegerLiteralContext::IntegerLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PlayReportParser::IntegerLiteralContext::DECIMAL_LITERAL() {
  return getToken(PlayReportParser::DECIMAL_LITERAL, 0);
}

tree::TerminalNode* PlayReportParser::IntegerLiteralContext::HEX_LITERAL() {
  return getToken(PlayReportParser::HEX_LITERAL, 0);
}

tree::TerminalNode* PlayReportParser::IntegerLiteralContext::OCT_LITERAL() {
  return getToken(PlayReportParser::OCT_LITERAL, 0);
}

tree::TerminalNode* PlayReportParser::IntegerLiteralContext::BINARY_LITERAL() {
  return getToken(PlayReportParser::BINARY_LITERAL, 0);
}


size_t PlayReportParser::IntegerLiteralContext::getRuleIndex() const {
  return PlayReportParser::RuleIntegerLiteral;
}

void PlayReportParser::IntegerLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PlayReportListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntegerLiteral(this);
}

void PlayReportParser::IntegerLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PlayReportListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntegerLiteral(this);
}


antlrcpp::Any PlayReportParser::IntegerLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlayReportVisitor*>(visitor))
    return parserVisitor->visitIntegerLiteral(this);
  else
    return visitor->visitChildren(this);
}

PlayReportParser::IntegerLiteralContext* PlayReportParser::integerLiteral() {
  IntegerLiteralContext *_localctx = _tracker.createInstance<IntegerLiteralContext>(_ctx, getState());
  enterRule(_localctx, 12, PlayReportParser::RuleIntegerLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PlayReportParser::DECIMAL_LITERAL)
      | (1ULL << PlayReportParser::HEX_LITERAL)
      | (1ULL << PlayReportParser::OCT_LITERAL)
      | (1ULL << PlayReportParser::BINARY_LITERAL))) != 0))) {
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

//----------------- FloatLiteralContext ------------------------------------------------------------------

PlayReportParser::FloatLiteralContext::FloatLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PlayReportParser::FloatLiteralContext::FLOAT_LITERAL() {
  return getToken(PlayReportParser::FLOAT_LITERAL, 0);
}

tree::TerminalNode* PlayReportParser::FloatLiteralContext::HEX_FLOAT_LITERAL() {
  return getToken(PlayReportParser::HEX_FLOAT_LITERAL, 0);
}


size_t PlayReportParser::FloatLiteralContext::getRuleIndex() const {
  return PlayReportParser::RuleFloatLiteral;
}

void PlayReportParser::FloatLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PlayReportListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloatLiteral(this);
}

void PlayReportParser::FloatLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PlayReportListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloatLiteral(this);
}


antlrcpp::Any PlayReportParser::FloatLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PlayReportVisitor*>(visitor))
    return parserVisitor->visitFloatLiteral(this);
  else
    return visitor->visitChildren(this);
}

PlayReportParser::FloatLiteralContext* PlayReportParser::floatLiteral() {
  FloatLiteralContext *_localctx = _tracker.createInstance<FloatLiteralContext>(_ctx, getState());
  enterRule(_localctx, 14, PlayReportParser::RuleFloatLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    _la = _input->LA(1);
    if (!(_la == PlayReportParser::FLOAT_LITERAL

    || _la == PlayReportParser::HEX_FLOAT_LITERAL)) {
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

bool PlayReportParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool PlayReportParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);
    case 3: return precpred(_ctx, 3);
    case 4: return precpred(_ctx, 2);
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> PlayReportParser::_decisionToDFA;
atn::PredictionContextCache PlayReportParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN PlayReportParser::_atn;
std::vector<uint16_t> PlayReportParser::_serializedATN;

std::vector<std::string> PlayReportParser::_ruleNames = {
  "bracedExpression", "expression", "primary", "expressionList", "functionCall", 
  "literal", "integerLiteral", "floatLiteral"
};

std::vector<std::string> PlayReportParser::_literalNames = {
  "", "'abstract'", "'assert'", "'boolean'", "'break'", "'byte'", "'case'", 
  "'catch'", "'char'", "'class'", "'const'", "'continue'", "'default'", 
  "'do'", "'double'", "'else'", "'enum'", "'extends'", "'final'", "'finally'", 
  "'float'", "'for'", "'if'", "'goto'", "'implements'", "'import'", "'instanceof'", 
  "'int'", "'interface'", "'long'", "'native'", "'new'", "'package'", "'private'", 
  "'protected'", "'public'", "'return'", "'short'", "'static'", "'strictfp'", 
  "'super'", "'switch'", "'synchronized'", "'this'", "'throw'", "'throws'", 
  "'transient'", "'try'", "'void'", "'volatile'", "'while'", "'function'", 
  "", "", "", "", "", "", "", "", "", "'null'", "'('", "')'", "'{'", "'}'", 
  "'['", "']'", "';'", "','", "'.'", "'='", "'>'", "'<'", "'!'", "'~'", 
  "'?'", "':'", "'=='", "'<='", "'>='", "'!='", "'&&'", "'||'", "'++'", 
  "'--'", "'+'", "'-'", "'*'", "'/'", "'&'", "'|'", "'^'", "'%'", "'+='", 
  "'-='", "'*='", "'/='", "'&='", "'|='", "'^='", "'%='", "'<<='", "'>>='", 
  "'>>>='", "'->'", "'::'", "'@'", "'...'"
};

std::vector<std::string> PlayReportParser::_symbolicNames = {
  "", "ABSTRACT", "ASSERT", "BOOLEAN", "BREAK", "BYTE", "CASE", "CATCH", 
  "CHAR", "CLASS", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", 
  "ENUM", "EXTENDS", "FINAL", "FINALLY", "FLOAT", "FOR", "IF", "GOTO", "IMPLEMENTS", 
  "IMPORT", "INSTANCEOF", "INT", "INTERFACE", "LONG", "NATIVE", "NEW", "PACKAGE", 
  "PRIVATE", "PROTECTED", "PUBLIC", "RETURN", "SHORT", "STATIC", "STRICTFP", 
  "SUPER", "SWITCH", "SYNCHRONIZED", "THIS", "THROW", "THROWS", "TRANSIENT", 
  "TRY", "VOID", "VOLATILE", "WHILE", "FUNCTION", "DECIMAL_LITERAL", "HEX_LITERAL", 
  "OCT_LITERAL", "BINARY_LITERAL", "FLOAT_LITERAL", "HEX_FLOAT_LITERAL", 
  "BOOL_LITERAL", "CHAR_LITERAL", "STRING_LITERAL", "NULL_LITERAL", "LPAREN", 
  "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "SEMI", "COMMA", "DOT", 
  "ASSIGN", "GT", "LT", "BANG", "TILDE", "QUESTION", "COLON", "EQUAL", "LE", 
  "GE", "NOTEQUAL", "AND", "OR", "INC", "DEC", "ADD", "SUB", "MUL", "DIV", 
  "BITAND", "BITOR", "CARET", "MOD", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", 
  "DIV_ASSIGN", "AND_ASSIGN", "OR_ASSIGN", "XOR_ASSIGN", "MOD_ASSIGN", "LSHIFT_ASSIGN", 
  "RSHIFT_ASSIGN", "URSHIFT_ASSIGN", "ARROW", "COLONCOLON", "AT", "ELLIPSIS", 
  "WS", "COMMENT", "LINE_COMMENT", "IDENTIFIER"
};

dfa::Vocabulary PlayReportParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> PlayReportParser::_tokenNames;

PlayReportParser::Initializer::Initializer() {
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
    0x3, 0x72, 0x57, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x1b, 0xa, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x2f, 0xa, 0x3, 0xc, 
    0x3, 0xe, 0x3, 0x32, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x3a, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x7, 0x5, 0x3f, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x42, 0xb, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x47, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 
    0x51, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x2, 
    0x3, 0x4, 0xa, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x2, 0x8, 0x4, 
    0x2, 0x5a, 0x5b, 0x5f, 0x5f, 0x3, 0x2, 0x58, 0x59, 0x4, 0x2, 0x4a, 0x4b, 
    0x51, 0x52, 0x4, 0x2, 0x50, 0x50, 0x53, 0x53, 0x3, 0x2, 0x36, 0x39, 
    0x3, 0x2, 0x3a, 0x3b, 0x2, 0x5e, 0x2, 0x12, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x1a, 0x3, 0x2, 0x2, 0x2, 0x6, 0x39, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x43, 0x3, 0x2, 0x2, 0x2, 0xc, 0x50, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x52, 0x3, 0x2, 0x2, 0x2, 0x10, 0x54, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x13, 0x7, 0x42, 0x2, 0x2, 0x13, 0x14, 0x7, 0x49, 0x2, 0x2, 
    0x14, 0x15, 0x5, 0x4, 0x3, 0x2, 0x15, 0x16, 0x7, 0x43, 0x2, 0x2, 0x16, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x17, 0x18, 0x8, 0x3, 0x1, 0x2, 0x18, 0x1b, 
    0x5, 0x6, 0x4, 0x2, 0x19, 0x1b, 0x5, 0xa, 0x6, 0x2, 0x1a, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x30, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0x1d, 0xc, 0x8, 0x2, 0x2, 0x1d, 0x1e, 0x9, 0x2, 0x2, 
    0x2, 0x1e, 0x2f, 0x5, 0x4, 0x3, 0x9, 0x1f, 0x20, 0xc, 0x7, 0x2, 0x2, 
    0x20, 0x21, 0x9, 0x3, 0x2, 0x2, 0x21, 0x2f, 0x5, 0x4, 0x3, 0x8, 0x22, 
    0x23, 0xc, 0x6, 0x2, 0x2, 0x23, 0x24, 0x9, 0x4, 0x2, 0x2, 0x24, 0x2f, 
    0x5, 0x4, 0x3, 0x7, 0x25, 0x26, 0xc, 0x5, 0x2, 0x2, 0x26, 0x27, 0x9, 
    0x5, 0x2, 0x2, 0x27, 0x2f, 0x5, 0x4, 0x3, 0x6, 0x28, 0x29, 0xc, 0x4, 
    0x2, 0x2, 0x29, 0x2a, 0x7, 0x54, 0x2, 0x2, 0x2a, 0x2f, 0x5, 0x4, 0x3, 
    0x5, 0x2b, 0x2c, 0xc, 0x3, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x55, 0x2, 0x2, 
    0x2d, 0x2f, 0x5, 0x4, 0x3, 0x4, 0x2e, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x22, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0x2f, 0x32, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2e, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x31, 0x3, 0x2, 0x2, 0x2, 0x31, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x32, 0x30, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x7, 0x40, 0x2, 0x2, 
    0x34, 0x35, 0x5, 0x4, 0x3, 0x2, 0x35, 0x36, 0x7, 0x41, 0x2, 0x2, 0x36, 
    0x3a, 0x3, 0x2, 0x2, 0x2, 0x37, 0x3a, 0x5, 0xc, 0x7, 0x2, 0x38, 0x3a, 
    0x7, 0x72, 0x2, 0x2, 0x39, 0x33, 0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x39, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x3b, 0x40, 0x5, 0x4, 0x3, 0x2, 0x3c, 0x3d, 0x7, 0x47, 0x2, 
    0x2, 0x3d, 0x3f, 0x5, 0x4, 0x3, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 
    0x3f, 0x42, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 0x9, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 
    0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x7, 0x72, 0x2, 0x2, 0x44, 0x46, 0x7, 
    0x40, 0x2, 0x2, 0x45, 0x47, 0x5, 0x8, 0x5, 0x2, 0x46, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x46, 0x47, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x3, 0x2, 0x2, 
    0x2, 0x48, 0x49, 0x7, 0x41, 0x2, 0x2, 0x49, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x51, 0x5, 0xe, 0x8, 0x2, 0x4b, 0x51, 0x5, 0x10, 0x9, 0x2, 0x4c, 
    0x51, 0x7, 0x3d, 0x2, 0x2, 0x4d, 0x51, 0x7, 0x3e, 0x2, 0x2, 0x4e, 0x51, 
    0x7, 0x3c, 0x2, 0x2, 0x4f, 0x51, 0x7, 0x3f, 0x2, 0x2, 0x50, 0x4a, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0x50, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4e, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x53, 0x9, 0x6, 0x2, 0x2, 0x53, 0xf, 0x3, 0x2, 0x2, 0x2, 0x54, 
    0x55, 0x9, 0x7, 0x2, 0x2, 0x55, 0x11, 0x3, 0x2, 0x2, 0x2, 0x9, 0x1a, 
    0x2e, 0x30, 0x39, 0x40, 0x46, 0x50, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

PlayReportParser::Initializer PlayReportParser::_init;
