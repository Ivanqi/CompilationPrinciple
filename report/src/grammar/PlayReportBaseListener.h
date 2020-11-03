
// Generated from PlayReport.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "PlayReportListener.h"


/**
 * This class provides an empty implementation of PlayReportListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  PlayReportBaseListener : public PlayReportListener {
public:

  virtual void enterBracedExpression(PlayReportParser::BracedExpressionContext * /*ctx*/) override { }
  virtual void exitBracedExpression(PlayReportParser::BracedExpressionContext * /*ctx*/) override { }

  virtual void enterExpression(PlayReportParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(PlayReportParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterPrimary(PlayReportParser::PrimaryContext * /*ctx*/) override { }
  virtual void exitPrimary(PlayReportParser::PrimaryContext * /*ctx*/) override { }

  virtual void enterExpressionList(PlayReportParser::ExpressionListContext * /*ctx*/) override { }
  virtual void exitExpressionList(PlayReportParser::ExpressionListContext * /*ctx*/) override { }

  virtual void enterFunctionCall(PlayReportParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(PlayReportParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterLiteral(PlayReportParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(PlayReportParser::LiteralContext * /*ctx*/) override { }

  virtual void enterIntegerLiteral(PlayReportParser::IntegerLiteralContext * /*ctx*/) override { }
  virtual void exitIntegerLiteral(PlayReportParser::IntegerLiteralContext * /*ctx*/) override { }

  virtual void enterFloatLiteral(PlayReportParser::FloatLiteralContext * /*ctx*/) override { }
  virtual void exitFloatLiteral(PlayReportParser::FloatLiteralContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

