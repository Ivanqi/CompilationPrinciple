#ifndef FIRSTFOLLOWSET_H
#define FIRSTFOLLOWSET_H

#include <map>
#include <set>
#include <string>
using std::map;
using std::set;
using std::string;

class GrammarNode;
class FirstFollowSet
{
    public:
        /**
         * 计算First集合
         * 采用了不动点法
         */
        static map<GrammarNode*, set<string>*> caclFirstSets(GrammarNode* grammar);

        /**
         * 对First集合做一次计算
         * @param grammar
         * @param firstSets
         * @return 如果这次计算，First集合的成员都没有变动，则返回true
         */
        static bool caclFirstSets(GrammarNode* grammar, map<GrammarNode*, set<string>*>& firstSets, set<GrammarNode*>& calculated);

        /**
         * 计算Follow集合
         * 对所有节点计算
         * @param grammar 入口语法节点
         * @return
         */
        static map<GrammarNode*, set<string>*> caclFollowSets(GrammarNode *grammar, map<GrammarNode*, set<string>*> firstSets);

        /**
         * 计算一遍Follow节点
         */
        static bool caclFollowSets(GrammarNode *grammar, map<GrammarNode*, set<string>*>& followSets, 
                                    map<GrammarNode*, set<GrammarNode*>>& rightChildrenSets, 
                                    map<GrammarNode*, set<string>*>& firstSets, 
                                    set<GrammarNode*>& calculated);
        
        // 打印输出First或Follow集合
        static void dumpFirstFollowSets(map<GrammarNode*, set<string>*> sets);
    
    private:
        /**
         * 把某个节点的Follow集合，也给它所有右边分支的后代节点
         */
        static bool addToRightChild(GrammarNode *grammar, set<string>* followSet, 
                                    map<GrammarNode*, set<string>*>& followSets, 
                                    map<GrammarNode*, set<GrammarNode*>> rightChildrenSets,
                                    set<GrammarNode*>& added);
};

#endif