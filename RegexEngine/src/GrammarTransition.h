#ifndef GRAMMARTRANSITION_H
#define GRAMMARTRANSITION_H

#include "Transition.h"
#include "Any.h"
#include <string>
using std::string;

/**
 * 状态迁移
 */
class GrammarTransition: public Transition
{
    private:
        // 状态迁移条件
        string condition_{""};

    public:
        GrammarTransition()
        {

        }

        GrammarTransition(string condition): condition_(condition)
        {

        }

        GrammarTransition(int maxTimes)
        {
            this->maxTimes = maxTimes;
        }

        /**
         * 是否满足迁移条件
         * 算法：输入的GrammarNode和迁移条件相等
         */
        bool match(string grammarName);

        bool match(Any obj);

        bool isEpsilon();

        string toString();
};

#endif