
// Generated from PlayReport.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "PlayReportVisitor.h"


/**
 * This class provides an empty implementation of PlayReportVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  PlayReportBaseVisitor : public PlayReportVisitor {
public:

  virtual antlrcpp::Any visitBracedExpression(PlayReportParser::BracedExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(PlayReportParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimary(PlayReportParser::PrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionList(PlayReportParser::ExpressionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionCall(PlayReportParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(PlayReportParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntegerLiteral(PlayReportParser::IntegerLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFloatLiteral(PlayReportParser::FloatLiteralContext *ctx) override {
    return visitChildren(ctx);
  }


};

