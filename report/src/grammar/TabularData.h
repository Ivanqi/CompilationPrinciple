#ifndef TABULARDATA_H
#define TABULARDATA_H

#include <map>
#include <string>
#include <vector>

#include "antlr4-runtime.h"

class TabularData
{
    public:
        // 数据，字段和值，值可以是向量(list<antlrcpp::Any>) 或标量
        std::map<std::string, antlrcpp::Any> fieldValues;

        // 行数
        int numRows = 0;

    
    public:
        int getNumRows();

        antlrcpp::Any getFieldValue(std::string fieldName, int rowIndex);

        antlrcpp::Any getField(std::string fieldName);

        bool hasField(std::string fieldName);

        /**
         * 添加新列
         * @param fieldName 字段名称，有可能是公式 
         * @param col 这一列的数据
         */
        void setField(std::string fieldName, antlrcpp::Any value);

        // 创建一个例子报表
        static TabularData* sampleData();
};

#endif