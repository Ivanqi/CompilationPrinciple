#include "ReportTemplate.h"

ReportTemplate* ReportTemplate::sampleReport1()
{
    ReportTemplate *temp = new ReportTemplate();

    temp->columnHeaders.emplace_back("部门         ");
    temp->columnHeaders.emplace_back("人数");
    temp->columnHeaders.emplace_back("销售额");
    temp->columnHeaders.emplace_back("人均销售额");

    temp->fields.emplace_back("{=dept}");
    temp->fields.emplace_back("{=num_person}");
    temp->fields.emplace_back("{=sales_amount}");
    temp->fields.emplace_back("{=sales_amount/num_person}");

    return temp;
}

ReportTemplate* ReportTemplate::sampleReport2()
{
    ReportTemplate *temp = new ReportTemplate();

    temp->columnHeaders.emplace_back("部门         ");
    temp->columnHeaders.emplace_back("人数");
    temp->columnHeaders.emplace_back("销售额");
    temp->columnHeaders.emplace_back("最高额");
    // temp->columnHeaders.emplace_back("差距");
    // temp->columnHeaders.emplace_back("排序");
    // temp->columnHeaders.emplace_back("人均");
    // temp->columnHeaders.emplace_back("人均排序");
    // temp->columnHeaders.emplace_back("累计汇总");
    // temp->columnHeaders.emplace_back("占比%");

    temp->fields.emplace_back("{=dept}");
    temp->fields.emplace_back("{=num_person}");
    temp->fields.emplace_back("{=sales_amount}");
    temp->fields.emplace_back("{=max(sales_amount)}");
    // temp->fields.emplace_back("{=max(sales_amount)-sales_amount}");
    // temp->fields.emplace_back("{=rank(sales_amount)}");
    // temp->fields.emplace_back("{=sales_amount/num_person}");
    // temp->fields.emplace_back("{=rank(sales_amount/num_person)}");
    // temp->fields.emplace_back("{=runningsum(sales_amount)}");
    // temp->fields.emplace_back("{=sales_amount/sum(sales_amount)*100}");

    return temp;
}