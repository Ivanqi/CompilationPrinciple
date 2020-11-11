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
        DyArray<antlrcpp::Any> tmp = rtn.as<DyArray<antlrcpp::Any>>();
        rtn = tmp.getIdx(rowIndex);
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

    DyArray<antlrcpp::Any> col1(DEFAULT_CAP);

    col1.insert("电话销售部");
    col1.insert("现场销售部");
    col1.insert("电子商务部");
    col1.insert("渠道销售部");
    col1.insert("微商销售部");
    data->fieldValues["dept"] = col1;

    DyArray<antlrcpp::Any> col2(DEFAULT_CAP);
    col2.insert(10);
    col2.insert(20);
    col2.insert(15);
    col2.insert(20);
    col2.insert(12);
    data->fieldValues["num_person"] = col2;

    DyArray<antlrcpp::Any> col3(DEFAULT_CAP);
    col3.insert(2345.0);
    col3.insert(5860.0);
    col3.insert(3045.0);
    col3.insert(5500.0);
    col3.insert(3624.0);
    data->fieldValues["sales_amount"] = col3;

    return data;
}