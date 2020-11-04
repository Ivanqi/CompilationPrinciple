#ifndef REPORTTEMPLATE_H
#define REPORTTEMPLATE_H

#include <vector>
#include <string>

class ReportTemplate
{
    public:
        // 列标题
        std::vector<std::string> columnHeaders;

        // 字段的公式
        std::vector<std::string> fields;

        static ReportTemplate* sampleReport1();

        static ReportTemplate* sampleReport2();
};

#endif