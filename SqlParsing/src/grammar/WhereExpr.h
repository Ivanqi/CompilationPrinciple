#ifndef WHEREEXPR_H
#define WHEREEXPR_H
#include <string>

// 保存where条件的概要信息
class WhereExpr
{
    public:
        std::string columnName_;
        std::string op_ = "=";
        std::string value_;

        WhereExpr(std::string columnName, std::string op, std::string value);
};

#endif