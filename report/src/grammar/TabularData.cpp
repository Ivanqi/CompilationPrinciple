#include "TabularData.h"
#include <memory>

int TabularData::getNumRows()
{
    return numRows;
}

antlrcpp::Any TabularData::getFieldValue(string fieldName, int rowIndex)
{
    antlrcpp::Any rtn = nullptr;

    rtn = fieldValues[fieldName];

    if (rtn.is<vector<antlrcpp::Any>>()) {
        vector<antlrcpp::Any> tmp = rtn.as<vector<antlrcpp::Any>>();
        rtn = tmp[rowIndex];
    }

    return rtn;
}

vector<antlrcpp::Any>& TabularData::getField(string& fieldName)
{
    vector<antlrcpp::Any>& tmp =  fieldValues[fieldName];
    return tmp;
}

bool TabularData::hasField(string fieldName)
{
    return (fieldValues.find(fieldName) == fieldValues.end()) ? false : true;
}

/**
 * 添加新列
 * @param fieldName 字段名称，有可能是公式 
 * @param col 这一列的数据
 */
void TabularData::setField(string fieldName,vector<antlrcpp::Any> value)
{
    fieldValues[fieldName] = value;
}

// 创建一个例子报表
TabularData* TabularData::sampleData()
{
    TabularData *data = new TabularData();

    data->numRows = 5;

    vector<antlrcpp::Any> col1;

    col1.emplace_back("电话销售部");
    col1.emplace_back("现场销售部");
    col1.emplace_back("电子商务部");
    col1.emplace_back("渠道销售部");
    col1.emplace_back("微商销售部");
    data->fieldValues["dept"] = col1;

    vector<antlrcpp::Any> col2;
    col2.emplace_back(10);
    col2.emplace_back(20);
    col2.emplace_back(15);
    col2.emplace_back(20);
    col2.emplace_back(12);
    data->fieldValues["num_person"] = col2;

    vector<antlrcpp::Any> col3;
    col3.emplace_back(2345.0);
    col3.emplace_back(5860.0);
    col3.emplace_back(3045.0);
    col3.emplace_back(5500.0);
    col3.emplace_back(3624.0);
    data->fieldValues["sales_amount"] = col3;

    return data;
}