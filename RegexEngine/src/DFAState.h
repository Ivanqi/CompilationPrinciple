#ifndef DFASTATE_H
#define DFASTATE_H
#include "State.h"
#include <vector>
#include <string>
#include <set>

class Any;

/**
 * DFA状态
 * 每个DFA包含多个NFA
 */
class DFAState: public State
{
    private:
        // 组成这个DFAState的NFAState的集合
        std::vector<State*> states;

        std::set<State*> statesSet_;

    public:
        DFAState(std::vector<State*> states)
            :states(states)
        {

        }

        DFAState(std::set<State*> states)
            :statesSet_(states)
        {

        }

        std::vector<State*> getStates();

        std::set<State*> getStatesSet();

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

        static void showDFAState(vector<shared_ptr<DFAState>> dfaStates);
};

#endif