#include "State.h"
#include "Transition.h"
#include "GrammarNode.h"

int State::count = 0;

void State::addTransition(Transition *transition, State *toState)
{
    transitions.push_back(transition);
    transition2State[transition] = toState;
}

/**
 * 把另一个状态的连线全部拷贝成自己的
 * 这相当于把State这个节点替换成自己
 */
void State::copyTransitions(State *state)
{
    transitions = state->transitions;
    transition2State = state->transition2State;
}

State* State::getState(Transition *transition)
{
    return transition2State[transition];
}

/**
 * 获取某个状态的Transition // TODO 这里假设每两个状态之间只可能有一个Transition
 */
Transition* State::getTransitionTo(State *toState)
{
    for (Transition *transition: transitions) {
        if (transition2State[transition] == toState) {
            return transition;
        }
    }
    return nullptr;
}

void State::setAcceptable(bool acceptable)
{
    acceptable = acceptable;
}

string State::toString()
{
    string sb;
    sb.append(name);

    if (transitions.size() > 0) {
        for (Transition *transition : transitions) {
            State *state = transition2State[transition];
            int maxTime = transition->getMaxtTime();
            sb.append("\t").append(to_string(maxTime)).append(" -> ").append(state->name).append("\n");
        }
    } else {
        sb.append("\t(end)").append("\n");
    }

    if (isAcceptable()) {
        sb.append("\t acceptable \n");
    }

    return sb;
}

/**
 * 打印FSA中的所有状态
 */
void State::dump(State *state, set<State*> dumpedStates)
{
    cout << state->name << endl;
    dumpedStates.insert(state);

    for (Transition *transition: state->getTransitions()) {
        State *state2 = state->getState(transition);
        if (dumpedStates.find(state2) != dumpedStates.end()) {
            dump(state2, dumpedStates);
        }
    }
}