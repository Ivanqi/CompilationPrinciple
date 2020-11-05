#ifndef PLAYREPORT_H
#define PLAYREPORT_H

#include <string>
#include <vector>
#include "antlr4-runtime.h"
#include "PlayReportParser.h"
#include "PlayReportLexer.h"

class ReportTemplate;
class TabularData;

class PlayReport
{   
    public:
        PlayReport()
        {

        }

        std::string renderReport(ReportTemplate *temp, TabularData *data);

        PlayReportParser::BracedExpressionContext* parse(std::string exp);
};

#endif