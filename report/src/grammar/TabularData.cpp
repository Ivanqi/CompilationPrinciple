#include "TabularData.h"
#include "DyArray.h"

#include <memory>

using namespace std;

int TabularData::getNumRows()
{
    return numRows;
}

antlrcpp::Any TabularData::getFieldValue(string fieldName, int rowIndex)
{
    antlrcpp::Any rtn = nullptr;

    rtn = fieldValues[fieldName];

    if (rtn.is<DyArray<antlrcpp::Any>>()) {
        DyArray<antlrcpp::Any> *tmp = rtn.as<DyArray<antlrcpp::Any>*>();
        rtn = tmp->get(rowIndex);   
    }

    return rtn;
}

antlrcpp::Any TabularData::getField(string fieldName)
{
    antlrcpp::Any tmp =  fieldValues[fieldName];
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
void TabularData::setField(string fieldName, antlrcpp::Any value)
{
    fieldValues[fieldName] = value;
}

// 创建一个例子报表
TabularData* TabularData::sampleData()
{
    TabularData *data = new TabularData();

    data->numRows = 5;

    DyArray<antlrcpp::Any> *col1 = new DyArray<antlrcpp::Any>();

    col1->push_back("电话销售部");
    col1->push_back("现场销售部");
    col1->push_back("电子商务部");
    col1->push_back("渠道销售部");
    col1->push_back("微商销售部");
    data->fieldValues["dept"] = col1;

    DyArray<antlrcpp::Any> *col2 = new DyArray<antlrcpp::Any>();
    col2->push_back(10);
    col2->push_back(20);
    col2->push_back(15);
    col2->push_back(20);
    col2->push_back(12);
    data->fieldValues["num_person"] = col2;

    DyArray<antlrcpp::Any> *col3 = new DyArray<antlrcpp::Any>();
    col3->push_back(2345.0);
    col3->push_back(5860.0);
    col3->push_back(3045.0);
    col3->push_back(5500.0);
    col3->push_back(3624.0);
    data->fieldValues["sales_amount"] = col3;

    return data;
}