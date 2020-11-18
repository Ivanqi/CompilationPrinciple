#include "DFAState.h"
#include "Any.h"
#include "Transition.h"

std::set<State*> DFAState::getStates()
{
    return states;
}

/**
 * 提供一个对象作为迁移条件，看能否迁移到下一个状态
 * @param obj， 做词法分析
 * @return
 */
DFAState* DFAState::getNextState(Any obj)
{
    for (Transition *transition : getTransitions()) {
        if (transition->match(obj)) {
            return (DFAState*) getState(transition);
        }
    }

    return nullptr;
}

std::string DFAState::toString();

/**
 * 只要它所包含的NFA有一个是接受状态，该DFAState就是接受状态
 */
bool DFAState::isAcceptable()
{
    for (State *state: states) {
        if (state->isAcceptable()) {
            return true;
        }
    }
    return false;
}