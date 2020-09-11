#ifndef CLOSUREANALYZER_H
#define CLOSUREANALYZER_H
#pragma once

#include <unordered_set>
#include "RuleContext.h"
using namespace antlr4;
using namespace std;

namespace play
{

    class AnnotatedTree;
    class Variable;
    class Function;
    class Scope;

    class ClosureAnalyzer
    {
        public:
            AnnotatedTree *at_;
        
        public:
            ClosureAnalyzer(AnnotatedTree *at): at_(at)
            {
            }

            /**
             * 对所有的函数做闭包分析
             * 只做标准函数的分析，不做类的方法的分析
             */
            void analyzeClosures();

            /**
             * 为某个函数计算闭包变量，也就是它所引用的外部环境变量
             * 算法：计算所有的变量引用，去掉内部声明的变量，剩下的就是外部的
             */
            unordered_set<Variable*> calcClosureVariables(Function *function);

            /**
             * 被一个Scope（包括下级Scope）内部的代码所引用的所有变量的集合
             */
            unordered_set<Variable*> variablesReferedByScope(Scope *scope);

            // 在一个Scope（及）下级Scope中声明的所有变量的集合
            unordered_set<Variable*> variablesDeclaredUnderScope(Scope *scope);

        private:
            // 看看node1是不是node2的祖先
            bool isAncestor(RuleContext *node1, RuleContext *node2);

    };
};

#endif