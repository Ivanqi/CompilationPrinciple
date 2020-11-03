
// Generated from PlayReport.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "PlayReportParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by PlayReportParser.
 */
class  PlayReportListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterBracedExpression(PlayReportParser::BracedExpressionContext *ctx) = 0;
  virtual void exitBracedExpression(PlayReportParser::BracedExpressionContext *ctx) = 0;

  virtual void enterExpression(PlayReportParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(PlayReportParser::ExpressionContext *ctx) = 0;

  virtual void enterPrimary(PlayReportParser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(PlayReportParser::PrimaryContext *ctx) = 0;

  virtual void enterExpressionList(PlayReportParser::ExpressionListContext *ctx) = 0;
  virtual void exitExpressionList(PlayReportParser::ExpressionListContext *ctx) = 0;

  virtual void enterFunctionCall(PlayReportParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(PlayReportParser::FunctionCallContext *ctx) = 0;

  virtual void enterLiteral(PlayReportParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(PlayReportParser::LiteralContext *ctx) = 0;

  virtual void enterIntegerLiteral(PlayReportParser::IntegerLiteralContext *ctx) = 0;
  virtual void exitIntegerLiteral(PlayReportParser::IntegerLiteralContext *ctx) = 0;

  virtual void enterFloatLiteral(PlayReportParser::FloatLiteralContext *ctx) = 0;
  virtual void exitFloatLiteral(PlayReportParser::FloatLiteralContext *ctx) = 0;


};

