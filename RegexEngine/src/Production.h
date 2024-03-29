#ifndef PRODUCTION_H
#define PRODUCTION_H
#include <string>
#include <vector>

#include "Any.h"

class Production
{
    public:
        // 产生式左侧，非终结符名称
        std::string lhs{""};

        // 产生式右侧
        std::vector<std::string> rhs;

        Production()
        {

        }

        int hashCode();

        bool equals(Any obj);

        std::string toString();

    private:
        int hashCode(std::string value);
};
#endif 