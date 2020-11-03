#ifndef SELECTSTMT_H
#define SELECTSTMT_H
#include <string>
#include <list>

// 保存select查询语句概括信息
class WhereExpr;
class SelectStmt
{
    public:
        std::string tableName_;
        std::list<WhereExpr*> whereExprs_;

        SelectStmt(std::string tableName, std::list<WhereExpr*> whereExprs);
};

#endif