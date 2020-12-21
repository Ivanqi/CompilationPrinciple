#include "Production.h"
#include <algorithm>

int Production::hashCode()
{
    return hashCode(toString());
}

int Production::hashCode(std::string value)
{
    int hash = 0;
    int h = hash;
    if (h == 0 && value.length() > 0) {
        std::string tmp;
        for (int i = 0; i < value.length(); i++) {
            tmp = value[i];
            h = 31 * h + tmp.c_str()[0];
        }
        hash = h;
    }

    return h;
}

bool Production::equals(Any obj)
{
    if (!obj.is<Production*>()) {
       return false;
    }

    Production *production = obj.as<Production*>();

    if (this == production) {
        return true;
    }

    if (production->lhs != lhs) {
       return false;
    }

    if (production->rhs.size() != rhs.size()) {
        return false;
    }
    
    std::vector<std::string> v_intersection;
    // 求交集
    std::set_intersection(production->rhs.begin(), production->rhs.end(), rhs.begin(), rhs.end(),
                            std::inserter(v_intersection, std::begin(v_intersection)));

    if (v_intersection.size() != rhs.size()) {
        return false;
    }

    return true;
}

std::string Production::toString()
{
    std::string sb;
    sb.append(lhs).append("->");
    std::string tmp;
    for (int i = 0; i < rhs.size(); i++) {
        tmp = rhs[i];
        sb.append(tmp).append(" ");
    }

    return sb;
}