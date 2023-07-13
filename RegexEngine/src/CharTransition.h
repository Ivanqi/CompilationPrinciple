#ifndef CHAETEANSITION_H
#define CHAETEANSITION_H
#include "Transition.h"
#include "CharSet.h"

#include <string>
#include <type_traits>

class Any;
// 状态转移
class CharTransition: public Transition
{
    public:
        // 状态迁移条件
        CharSet *condition = new CharSet();

        CharTransition()
        {

        }

        CharTransition(CharSet *charSet)
        {
            condition = charSet;
        }

        CharTransition(int maxTimes)
        {
            Transition::maxTimes = maxTimes;
        }

        /**
         * 是否满足迁移条件
         * 算法
         *  1. 如果没有任何conditions，那么就代表epsilon，就是可以迁移的
         *  2. 否则就要检测字符是否落在CharRange中
         */
        bool match(char ch);

        bool match(Any obj);

        bool isEpsilon();

        std::string toString();
};

#endif