#include "TabularData.h"

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
    return fieldValues[fieldName];
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

    col1.push_back("电话销售部");
    col1.push_back("现场销售部");
    col1.push_back("电子商务部");
    col1.push_back("渠道销售部");
    col1.push_back("微商销售部");
    data->fieldValues["dept"] = col1;

    std::vector<antlrcpp::Any> col2;
    col2.push_back(10);
    col2.push_back(20);
    col2.push_back(15);
    col2.push_back(20);
    col2.push_back(12);
    data->fieldValues["num_person"] = col2;

    std::vector<antlrcpp::Any> col3;
    col3.push_back(2345.0);
    col3.push_back(5860.0);
    col3.push_back(3045.0);
    col3.push_back(5500.0);
    col3.push_back(3624.0);
    data->fieldValues["sales_amount"] = col3;

    return data;
}