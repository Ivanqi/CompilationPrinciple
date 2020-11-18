#ifndef TRANSITION_H
#define TRANSITION_H
// 状态迁移

class Any;

class Transition
{
    public:
        /**
         * 对于重复的情况，最终可以重复几次
         * 这是把GrammarNode中的maxTimes属性转义到这里来了
         * 对于 ? maxTimes = 1, 对于 + 和 * ，maxTimes = -1;
         */
        int maxTimes = 1;

    public:
        /**
         * 是否满足迁移条件
         */
        virtual bool match(Any obj) = 0;

        // 是否是一个Epsilon转换
        virtual bool isEpsilon() = 0;

        int getMaxtTime()
        {
            return maxTimes;
        }
};

#endif