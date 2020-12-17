#include "FirstFollowSet.h"
#include "GrammarNode.h"

#include <algorithm>
#include <iostream>
#include <cassert>
/**
 * First, 顾名思义就是关于该符号的所有产生式右部第一个遇到的终结符
 * 
 * 计算First集合
 * 采用了不动点法
 * 
 * 不动点法介绍
 *  1. 多次遍历图中的节点，看看每次有没有计算出新的集合成员
 *  2. 比如，第一遍计算的时候，当求First(pri)的时候，它所依赖的First(expression)中的成员可能不全
 *  3. 等下一轮继续计算时，发现有新的集合成员，再加进来就好了，直到所有集合的成员都没有变动为止
 */
map<GrammarNode*, set<string>*> FirstFollowSet::caclFirstSets(GrammarNode* grammar)
{
    map<GrammarNode*, set<string>*> firstSets;
    firstSets.clear();

    set<GrammarNode*> calculated;
    calculated.clear();
    bool stable = caclFirstSets(grammar, firstSets, calculated);

    int i = 1;

    std::cout << "fcaclFirstSets round: " << i++ << std::endl;

    set<GrammarNode*> calculated1;
    while (!stable) {
        std::cout << "caclFirstSets round: " << i++ << std::endl;
        stable = caclFirstSets(grammar, firstSets, calculated1);
    }
    return firstSets;
}

/**
 * 对First集合做一次计算
 * @param grammar
 * @param firstSets
 * @return 如果这次计算，First集合的成员都没有变动，则返回true
 */
bool FirstFollowSet::caclFirstSets(GrammarNode* grammar, map<GrammarNode*, set<string>*>& firstSets, set<GrammarNode*>& calculated)
{
    // 标记正在计算该节点，避免重复调用
    calculated.insert(grammar);

    // 获取或创建First集合
    set<string> *firstSet = new set<string>();
    if (firstSets.find(grammar) != firstSets.end()) {
        firstSet = firstSets[grammar];
    } else {
        firstSets[grammar] = firstSet;
    }

    bool stable = true;

    if (!grammar->isLeaf()) {
        // 先把所有的子节点都计算一遍
        for (size_t i = 0; i < grammar->getChildren().size(); i++) {
            GrammarNode *child = grammar->getChildren()[i].get();
            // 重复的节点或叶子节点，不递归
            if (!child->isLeaf() && calculated.find(child) == calculated.end()) {
                caclFirstSets(child, firstSets, calculated);    // todo 是否需要记录Stable
            }
        }

        vector<GrammarNode*> childToAdd;

        if (grammar->getType() == GrammarNodeType::And) {
            childToAdd.emplace_back(grammar->getChild(0));

            // 要一直找到一个不产生Epsilong的符号. todo: 这步的作用？找到不是空集的集合？
            for (size_t i = 0; i < grammar->getChildren().size(); i++) {
                GrammarNode *child = grammar->getChildren()[i].get();
                childToAdd.emplace_back(child);
                // And 一个不为空，全部不为空
                if (!child->isNullable()) {
                    break;
                }
            }
        } else if (grammar->getType() == GrammarNodeType::Or) {
            for (size_t i = 0; i < grammar->getChildren().size(); i++) {
                GrammarNode *child = grammar->getChildren()[i].get();
                childToAdd.emplace_back(child);
            }
        }

        set<string> *v_intersection = new set<string>();
        // 生成First集合
        for (GrammarNode *child : childToAdd) {
            if (!child->isLeaf()) {
                /**
                 * 如果x的开头是非终结符a，那么First(x)要包含First(a)的所有成员
                 * 比如expressionStatement是以expression开头，因此它的First集合要包含First(expression)的全体成员
                 * 
                 * 最后，如果x是一个非终结符，它有多个产生式可供选择，那么First(x)应包含所有产生式的First()集合的成语
                 * 比如 statement 的First集合要包含if, while 等所有产生式的First集合的成员
                 * 并且，如果这些产生式只要有一个可能产生ε, 那么x就可能产生ε，因此, First(x)就应该包含ε
                 */
                set<string> *childSet = firstSets[child];
                v_intersection->clear();   
                // 求交集
                std::set_intersection(firstSet->begin(), firstSet->end(),
                                      childSet->begin(), childSet->end(),
                                      std::inserter((*v_intersection), std::begin((*v_intersection))));

                // 检查两个集合是否包含相同的元素
                if (v_intersection->size() != childSet->size()) {
                    firstSet->insert(childSet->begin(), childSet->end());
                    stable = false;
                }
            } else if (child->isToken()) {
                /**
                 * 如果x以Token开头，那么First(x)包含的元素就是这个Token，比如if语句的First集合就是{IF}
                 */
                if (firstSet->find(child->getToken()->getType()) == firstSet->end()) {
                    stable = false;
                    firstSet->insert(child->getToken()->getType());
                }
            }

            /**
             * 这些产生式，只要有一个可能产生ε,那么x就可能产生ε，因此First(x)就应该包含ε
             */
            if (child->isNullable()) {
                // 插入空集
                if (firstSet->find("EPSILON") == firstSet->end()) {
                    firstSet->insert("EPSILON");
                }
            }
        }
    }

    return stable;
}

/**
 * Follow，顾名思义，就是该符号后面跟着的第一个终结符
 * 求 follow 集合，都是从开始符号S开始推导
 * 
 * 计算Follow集合
 * 对所有节点计算
 * @param grammar 入口语法节点
 * @return
 */
map<GrammarNode*, set<string>*> FirstFollowSet::caclFollowSets(GrammarNode *grammar, map<GrammarNode*, set<string>*> firstSets)
{
    map<GrammarNode*, set<string>*> followSets;
    map<GrammarNode*, set<GrammarNode*>*> rightChildrenSets;

    // 不动点法计算Follow集合
    int i = 1;
    std::cout << "follow set round: " << i++ << endl;

    set<GrammarNode*> calculated;
    bool stable = caclFollowSets(grammar, followSets, rightChildrenSets, firstSets, calculated);

    set<GrammarNode*> calculated1;
    while (!stable) {
        std::cout << "follow set round:" << i++ << std::endl;
        stable = caclFollowSets(grammar, followSets, rightChildrenSets, firstSets, calculated1);
    }

    //  为根节点最右边的边，也就是所有可能出现在程序末尾的非终结符，加上$,也就是整个Token串结束符号
    set<string> *tempFollowSet = new set<string>();
    tempFollowSet->insert("$");
    set<GrammarNode*> add1;
    addToRightChild(grammar, tempFollowSet, followSets, rightChildrenSets, add1);

    // 给根节点加上$。根节点如果没有递归引用，不会出现在followSets中
    set<string> *rootFollowSet = followSets[grammar];
    if (rootFollowSet == nullptr) {
        rootFollowSet = new set<string>();
        followSets[grammar] = rootFollowSet;
    }
    rootFollowSet->insert("$");

    return followSets;
}

/**
 * 计算一遍Follow节点
 */
bool FirstFollowSet::caclFollowSets(GrammarNode *grammar, map<GrammarNode*, set<string>*> &followSets,
                                    map<GrammarNode*, set<GrammarNode*>*>& rightChildrenSets, 
                                    map<GrammarNode*, set<string>*>& firstSets, 
                                    set<GrammarNode*>& calculated)
{
    calculated.insert(grammar);
    bool stable = true;

    if (!grammar->isLeaf()) {
        set<GrammarNode*> *rightChildren = rightChildrenSets[grammar];
        if (rightChildren == nullptr) {
            rightChildren = new set<GrammarNode*>();
            rightChildrenSets[grammar] = rightChildren;
        }
        
        if (grammar->getType() == GrammarNodeType::And) {
            set<string> *v_intersection = new set<string>();
            set<GrammarNode*> added;

            // 对子节点遍历
            for (int i = 0; i < grammar->getChildCount(); i++) {
                GrammarNode *left = grammar->getChild(i);
                // 重复的节点或叶子节点，不递归
                if (!left->isLeaf() && calculated.find(left) == calculated.end()) {
                    bool state = caclFollowSets(left, followSets, rightChildrenSets, firstSets, calculated);
                    if (!state) {
                        stable = false;
                    }
                }

                set<string> *followSet = followSets[left];
                if (followSet == nullptr) {
                    followSet = new set<string>();
                    followSets[left] = followSet;
                }

                if (i == grammar->getChildCount()) {    // 当 i 等于 grammar 子节点的数量
                    rightChildren->insert(left);
                } else {
                    bool foundNotNull = false;
                    // 遍历grammar i + 1 的后子节点
                    for (int j = i + 1; j < grammar->getChildCount(); j++) {
                        GrammarNode *right = grammar->getChild(j);
                        set<string> *tempFollowSet = new set<string>();
                        // 不是叶子节点
                        if (!right->isLeaf()) {
                            if (firstSets[right] == nullptr) {
                                cout << "" << endl;
                            }
                            // 如果后面是非终结符，就把它的First集合加到自己的Follow集合中去
                            tempFollowSet->insert(firstSets[right]->begin(), firstSets[right]->end());
                        } else if (right->isToken()) {
                            // 后面跟着的终结符，都加到Follow(x)集合中去
                            tempFollowSet->insert(right->getToken()->getType());
                        }

                        assert(tempFollowSet->size() > 0);
                        v_intersection->clear();
                        // 求交集
                        std::set_intersection(followSet->begin(), followSet->end(),
                                      tempFollowSet->begin(), tempFollowSet->end(),
                                      std::inserter((*v_intersection), std::begin((*v_intersection))));
                        // 检查两个集合是否包含相同的元素
                        if (v_intersection->size() != tempFollowSet->size()) {
                            followSet->insert(tempFollowSet->begin(), tempFollowSet->end());
                            stable = false;
                        }

                        /**
                         * 把left的子节点的follow集合和 tempFollowSet 关联起来
                         */
                        if (!addToRightChild(left, tempFollowSet, followSets, rightChildrenSets, added)) {
                            stable = false;
                        }

                        if (!right->isNullable()) { // 必须找到一个非空的
                            foundNotNull = true;
                            break;
                        }
                    }

                    // 本节点也是最右节点
                    if (!foundNotNull) {
                        rightChildren->insert(left);
                    }
                }
            }
        } else if (grammar->getType() == GrammarNodeType::Or) {
            for (int i = 0; i < grammar->getChildCount(); i++) {
                GrammarNode *child = grammar->getChild(i);
                if (!child->isLeaf())  {
                    rightChildren->insert(child);
                    if (calculated.find(child) == calculated.end()) {
                        bool state = caclFollowSets(child, followSets, rightChildrenSets, firstSets, calculated);
                        if (state) {
                            stable = false;
                        }
                    }
                }
            }
        }
    } 

    return stable;
}

/**
 * 把某个节点的Follow集合，也给它所有右边分支的后代节点?
 * 
 * 因为这些孩子节点是父节点最右边的。那么父节点后面会跟什么终结符，这些子节点也会跟这些终结符
 * 
 * 如果一个非终结符位于上一级产生式的最右边，比如: A -> abcdB中的B, (我们用大小写区分终结符和非终结符)，那么找到可能出现在它右边的终结符，实际上也不好找
 * 要看看A后面都可能跟啥，比如: C -> abcAb, 那么A的Follow集合中有b，B的Follow集合中也要b
 */
bool FirstFollowSet::addToRightChild(GrammarNode *grammar, set<string>* followSet, 
                                    map<GrammarNode*, set<string>*>& followSets, 
                                    map<GrammarNode*, set<GrammarNode*>*>& rightChildrenSets,
                                    set<GrammarNode*>& added)
{
    added.insert(grammar);

    bool stable = true;
    set<GrammarNode*> *rightChildren = rightChildrenSets[grammar];
    if (rightChildren == nullptr) {
        return stable;
    }

    set<string> *v_intersection = new set<string>();
    for (auto setIt = rightChildren->begin(); setIt != rightChildren->end(); setIt++) {
        GrammarNode *rightChild = *setIt;
        
        // 重复的节点或叶子节点，不进行操作
        if (!rightChild->isLeaf() && added.find(rightChild) != added.end()) {
            set<string> *childFollowSet = followSets[rightChild];
            if (childFollowSet == nullptr) {
                childFollowSet = new set<string>();
                followSets[rightChild] = childFollowSet;
            }

            v_intersection->clear();

            // 求交集
            std::set_intersection(followSet->begin(), followSet->end(),
                            childFollowSet->begin(), childFollowSet->end(),
                            std::inserter((*v_intersection), std::begin((*v_intersection))));
            // 检查两个集合是否包含相同的元素
            if (v_intersection->size() != childFollowSet->size()) {
                childFollowSet->insert(followSet->begin(), followSet->end());
                stable = false;
            }

            // 递归向下
            if (!addToRightChild(rightChild, followSet, followSets, rightChildrenSets, added)) {
                stable = false;
            }
        }
    }

    return stable;
}

// 打印输出First或Follow集合
void FirstFollowSet::dumpFirstFollowSets(map<GrammarNode*, set<string>*> sets)
{
    string str;

    // O(n ^ 2)
    for (auto it = sets.begin(); it != sets.end(); it++) {
        str.clear();
        GrammarNode *node = it->first;
        set<string> *aggr = it->second;

        str = node->toString() + ":";
        for (auto setIt = aggr->begin(); setIt != aggr->end(); ++setIt) {
            str += " " + *setIt;
        }
        std::cout << str << std::endl;
    }
}