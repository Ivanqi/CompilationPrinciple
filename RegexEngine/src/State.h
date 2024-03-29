#ifndef STATE_H
#define STATE_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <memory>

class Transition;
class GrammarNode;

using std::string;
using std::vector;
using std::map;
using std::set;
using std::cout;
using std::endl;
using std::shared_ptr;
// 代表有限自动机的一个状态
class State
{
    private:
        static map<State*, string> checkState;

    public:
        // 计数器
        static int count;

        // 状态名称，是自动增长的数字, 0, 1...
        string name{""};

        // 是不是最终状态(接受状态)
        bool acceptable;

        // 状态间的连线
        vector<shared_ptr<Transition>> transitions;

        // 连线与下一个状态的对照表
        map<Transition*, State*> transition2State;

        /**
         * 跟这个节点关联的语法
         * 用于语法分析时，分辨哪个词法的结束状态
         */
        GrammarNode *grammarNode_{nullptr};

    public:
        State(): name(std::to_string(count++))
        {
        }

        State(bool acceptable):acceptable(acceptable), name(std::to_string(count++))
        {
        }

        void addTransition(Transition *transition, State *toState);

        /**
         * 把另一个状态的连线全部拷贝成自己的
         * 这相当于把State这个节点替换成自己
         */
        void copyTransitions(State *state);

        State* getState(Transition *transition);

        /**
         * 获取某个状态的Transition // TODO 这里假设每两个状态之间只可能有一个Transition
         */
        Transition* getTransitionTo(State *toState);

        vector<shared_ptr<Transition>> getTransitions()
        {
            return transitions;
        }

        string toString();

        void static showState(State *state, bool repeat = true);

        bool isAcceptable()
        {
            return acceptable;
        }

        void setAcceptable(bool acceptable);

        void static dump(State *state)
        {
            map<State*, string> dumpedStates;
            dump(state, dumpedStates);
        }

        /**
         * 打印FSA中的所有状态
         */
        static void dump(State *state, map<State*, string>& dumpedStates);

        string getName()
        {
            return name;
        }

        GrammarNode* getGrammarNode()
        {
            return grammarNode_;
        }

        void setGrammarNode(GrammarNode* grammarNode)
        {
            grammarNode_ = grammarNode;
        }

        void static deleteState(State *state);
};

#endif