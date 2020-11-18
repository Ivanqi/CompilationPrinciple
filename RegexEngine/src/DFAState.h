#ifndef DFASTATE_H
#define DFASTATE_H
#include "State.h"
#include <set>
#include <string>

class Any;

/**
 * DFA状态
 * 每个DFA包含多个NFA
 */
class DFAState: public State
{
    private:
        // 组成这个DFAState的NFAState的集合
        std::set<State*> states = nullptr

    public:
        DFAState(std::set<State*> states)
            :states(states)
        {

        }

        std::set<State*> getStates();

        /**
         * 提供一个对象作为迁移条件，看能否迁移到下一个状态
         * @param obj， 做词法分析
         * @return
         */
        DFAState* getNextState(Any obj);

        std::string toString();

        /**
         * 只要它所包含的NFA有一个是接受状态，该DFAState就是接受状态
         */
        bool isAcceptable();
};

#endif