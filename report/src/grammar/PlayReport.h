#ifndef PLAYREPORT_H
#define PLAYREPORT_H

#include <string>
#include <vector>
#include "antlr4-runtime.h"
#include "PlayReportParser.h"
#include "PlayReportLexer.h"
using namespace antlr4;

class PlayReport
{
    class ReportTemplate;
    class TabularData;
    public:
        PlayReport()
        {

        }

        std::string renderReport(ReportTemplate *template, TabularData *data);

        PlayReportParser::BracedExpressionContext* parse(std::string exp);
};

#endif