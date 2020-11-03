
// Generated from PlayReport.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "PlayReportParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PlayReportParser.
 */
class  PlayReportVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PlayReportParser.
   */
    virtual antlrcpp::Any visitBracedExpression(PlayReportParser::BracedExpressionContext *context) = 0;

    virtual antlrcpp::Any visitExpression(PlayReportParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPrimary(PlayReportParser::PrimaryContext *context) = 0;

    virtual antlrcpp::Any visitExpressionList(PlayReportParser::ExpressionListContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCall(PlayReportParser::FunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(PlayReportParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitIntegerLiteral(PlayReportParser::IntegerLiteralContext *context) = 0;

    virtual antlrcpp::Any visitFloatLiteral(PlayReportParser::FloatLiteralContext *context) = 0;


};

