#include "DFAState.h"
#include "Any.h"
#include "Transition.h"
#include "GrammarNode.h"

#include <iostream>

std::vector<State*> DFAState::getStates()
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
    for (size_t i = 0; i < transitions.size(); i++) {
        Transition *transition = transitions[i].get();
        if (transition->match(obj)) {
            return (DFAState*) getState(transition);
        }
    }

    return nullptr;
}

std::string DFAState::toString()
{
    string rtn = State::toString();
    rtn += "\tNFA states: ";
    int i = 0;

    for (State *state: states) {
        if (i++ > 0) {
            rtn += ", ";
        }
        rtn += state->getName();
        if (state->getGrammarNode() != nullptr && state->getGrammarNode()->isNamedNode()) {
            rtn += "(" + state->getGrammarNode()->getName() + ")";
        }
    }

    rtn += "\n";
    return rtn;
}

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

void DFAState::showDFAState(vector<shared_ptr<DFAState>> dfaStates)
{
    for (size_t i = 0; i < dfaStates.size(); i++) {
        DFAState *dstate = dfaStates[i].get();
        cout << dstate->getName() << endl;
        for (State *state: dstate->getStates()) {
            cout << "\t" << state->toString() << endl;
        }
    }
}