#include "TabularData.h"
#include <memory>

int TabularData::getNumRows()
{
    return numRows;
}

antlrcpp::Any TabularData::getFieldValue(std::string fieldName, int rowIndex)
{
    antlrcpp::Any rtn = nullptr;

    rtn = fieldValues[fieldName];

    if (rtn.is<std::vector<antlrcpp::Any>>()) {
        std::vector<antlrcpp::Any> tmp = rtn.as<std::vector<antlrcpp::Any>>();
        rtn = tmp[rowIndex];
    }

    return rtn;
}

antlrcpp::Any TabularData::getField(std::string fieldName)
{
    antlrcpp::Any ret = fieldValues[fieldName];
    return ret;
}

bool TabularData::hasField(std::string fieldName)
{
    return (fieldValues.find(fieldName) == fieldValues.end()) ? false : true;
}

/**
 * 添加新列
 * @param fieldName 字段名称，有可能是公式 
 * @param col 这一列的数据
 */
void TabularData::setField(std::string fieldName, antlrcpp::Any value)
{
    fieldValues[fieldName] = value;
}

// 创建一个例子报表
TabularData* TabularData::sampleData()
{
    TabularData *data = new TabularData();

    data->numRows = 5;

    std::vector<antlrcpp::Any> col1;

    col1.emplace_back(new std::string("电话销售部"));
    col1.emplace_back(new std::string("现场销售部"));
    col1.emplace_back(new std::string("电子商务部"));
    col1.emplace_back(new std::string("渠道销售部"));
    col1.emplace_back(new std::string("微商销售部"));
    data->fieldValues["dept"] = col1;

    std::vector<antlrcpp::Any> col2;
    col2.emplace_back(new int(10));
    col2.emplace_back(new int(20));
    col2.emplace_back(new int (15));
    col2.emplace_back(new int (20));
    col2.emplace_back(new int (12));
    data->fieldValues["num_person"] = col2;

    std::vector<antlrcpp::Any> col3;
    col3.emplace_back(new double(2345.0));
    col3.emplace_back(new double (5860.0));
    col3.emplace_back(new double (3045.0));
    col3.emplace_back(new double (5500.0));
    col3.emplace_back(new double (3624.0));
    data->fieldValues["sales_amount"] = col3;

    return data;
}