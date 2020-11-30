#include "State.h"
#include "Transition.h"
#include "GrammarNode.h"
#include "CharTransition.h"

int State::count = 0;
map<State*, string> State::checkState;


void State::addTransition(Transition *transition, State *toState)
{
    transitions.emplace_back(transition);
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
        State *tmp = transition2State[transition];
        if (tmp == toState) {
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
            sb.append("\t").append(transition->toString()).append(" -> ").append(state->name).append("\n");
        }
    } else {
        sb.append("\t(end)").append("\n");
    }

    if (isAcceptable()) {
        sb.append("\t acceptable \n");
    }

    return sb;
}

void State::showState(State *state)
{
    if (State::checkState.find(state) != State::checkState.end()) {
        return;
    }

    State::checkState[state] = state->name;

    string sb;
    sb.append(state->name);

    vector<Transition*> transitions = state->getTransitions();
    map<Transition*, State*> transition2State = state->transition2State;
    vector<State*> nextState;

    if (transitions.size() > 0) {
        for (Transition *transition : transitions) {
            State *state = transition2State[transition];
            sb.append("\t").append(transition->toString()).append(" -> ").append(state->name).append("\n");
            nextState.emplace_back(state);
        }
        cout << sb;
        for (State *s : nextState) {
            showState(s);
        }
        return;
    } else {
        sb.append("\t(end)").append("\n");
        State::checkState.clear();
    }

    if (state->isAcceptable()) {
        sb.append("\t acceptable \n");
    }

    cout << sb << endl;
    return;
}

/**
 * 打印FSA中的所有状态
 */
void State::dump(State *state, map<State*, string>& dumpedStates)
{
    string name = state->getName();
    cout << name << endl;
    dumpedStates[state] = name;

    // O(n)
    for (Transition *transition: state->getTransitions()) {
        State *state2 = state->getState(transition);
        auto it = dumpedStates.find(state2);
        if (it == dumpedStates.end()) {
            dump(state2, dumpedStates);
        }
    }
}

void State::deleteState(State *state)
{
    if (State::checkState.find(state) != State::checkState.end()) {
        return;
    }

    State::checkState[state] = state->name;

    vector<Transition*> transitions = state->getTransitions();
    map<Transition*, State*> transition2State = state->transition2State;

    if (transitions.size() > 0) {
        for (Transition *transition : transitions) {
            State *state = transition2State[transition];
            deleteState(state);
        }
        delete state;
    } else {
        delete state;
    }
}