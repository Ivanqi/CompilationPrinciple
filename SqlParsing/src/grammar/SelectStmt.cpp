#include "SelectStmt.h"
#include "WhereExpr.h"

SelectStmt::SelectStmt(std::string tableName, std::list<WhereExpr*> whereExprs)
    :tableName_(tableName), whereExprs_(whereExprs)
{

}