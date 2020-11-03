#include "WhereExpr.h"

WhereExpr::WhereExpr(std::string columnName, std::string op, std::string value)
    :columnName_(columnName), op_(op), value_(value)
{

}