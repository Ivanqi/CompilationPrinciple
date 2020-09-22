#include "ClosureAnalyzer.h"
#include "AnnotatedTree.h"
#include "Type.h"
#include "Variable.h"
#include "Scope.h"
#include "Symbol.h"
#include "Function.h"

using namespace play;

 /**
 * 对所有的函数做闭包分析
 * 只做标准函数的分析，不做类的方法的分析
 */
void ClosureAnalyzer::analyzeClosures()
{
    for (Type *type : at_->types) {
        Function *tmp = dynamic_cast<Function*>(type);
        if (tmp != nullptr && tmp->isMethod()) {
            unordered_set<Variable*> set_ = move(calcClosureVariables((Function *)type));
            
            if (set_.size() > 0) {
                tmp->closureVariables = move(set_);
            }
        }
    }
}

/**
 * 为某个函数计算闭包变量，也就是它所引用的外部环境变量
 * 算法：计算所有的变量引用，去掉内部声明的变量，剩下的就是外部的
 */
unordered_set<Variable*> ClosureAnalyzer::calcClosureVariables(Function *function)
{
    unordered_set<Variable*> refered = move(variablesReferedByScope(function));
    unordered_set<Variable*> declared = move(variablesDeclaredUnderScope(function));

    // refered.erase(declared);

    return refered;
}

/**
 * 被一个Scope（包括下级Scope）内部的代码所引用的所有变量的集合
 */
unordered_set<Variable*> ClosureAnalyzer::variablesReferedByScope(Scope *scope)
{
    unordered_set<Variable*> rtn;
    ParserRuleContext *scopeNode = scope->ctx;

    // 扫描所有的符号引用。这对于大的程序性能不够优化，因为符号表太大
    map<ParserRuleContext*, Symbol*>::iterator iter;
    for (iter = at_->symbolOfNode.begin(); iter != at_->symbolOfNode.end(); iter++) {
        Symbol *tmp = dynamic_cast<Symbol*>(iter->second);
        if (tmp != nullptr && isAncestor(scopeNode, iter->first)) {
            rtn.insert((Variable*)iter->second);
        }
    }
    return rtn;
}

bool ClosureAnalyzer::isAncestor(RuleContext *node1, RuleContext *node2)
{
    if (node2->parent == nullptr) {
        return false;
    } else if (node2->parent == node1) {
        return true;
    } else {
        return isAncestor(node1, (RuleContext*)node2->parent);
    }
}

// 在一个Scope（及）下级Scope中声明的所有变量的集合
unordered_set<Variable*> ClosureAnalyzer::variablesDeclaredUnderScope(Scope *scope)
{
    unordered_set<Variable*> rtn;
    for (Symbol *symbol: scope->symbols) {
        //TODO 这里的派生类转换有问题
        Variable *tmp = static_cast<Variable*>(symbol);
        Scope *tmp2 = static_cast<Scope*> (symbol);
        
        if (tmp != nullptr) {
            rtn.insert(tmp);
        } else if (tmp2 != nullptr) {
            unordered_set<Variable*> hVariable = variablesDeclaredUnderScope(tmp2);

            for (auto iter = hVariable.begin(); iter != hVariable.end(); ++iter) {
                rtn.insert(*iter);
            }
        }
    }
    return rtn;
}