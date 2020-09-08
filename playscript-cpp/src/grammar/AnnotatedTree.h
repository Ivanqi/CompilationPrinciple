#ifndef ANNOTATEDTREE_H
#define ANNOTATEDTREE_H

#pragma once
#include "ParserRuleContext.h"
#include "RuleContext.h"
#include "tree/ParseTree.h"
#include "Type.h"
#include "Symbol.h"
#include "NameSpace.h"
#include "CompilationLog.h"
#include "Function.h"

#include <vector>
#include <map>
#include <string>

using namespace antlr4;
using namespace antlr4::tree;
using namespace std;

/**
 * 注释树
 *  语义分析的结果都放在这里。跟AST的节点建立关联。包括
 *      1. 类型信息，包括基本类型和用户自定义类型
 *      2. 变量和函数调用的消解
 *      3. 作用域Scope。在Scope中包含了该作用域的所有符号。Variable、Function、Class等都是符号
 */
class AnnotatedTree
{
    public:
        // AST
        ParseTree *ast;

        // 解析出来的所有类型，包括类和函数，以后还可以包括数组和枚举。类的方法也作为单独的要素放进去
        vector<Type*> types;

        // AST节点对应的Symbol
        map<ParserRuleContext, Symbol> symbolOfNode;

        // AST 节点对应的Scope。 如for, 函数调用会启动新的Scope
        map<ParserRuleContext*, Scope*> node2Scope;

        // 用于做类型推断，每个节点推断出来的类型
        map<ParserRuleContext, Type> typeOfNode;

        // 命名空间
        NameSpace *namespaces;

        // 语义分析过程中生成的信息，包括普通信息，警告和错误
        vector<CompilationLog*> logs;

        // 在构造函数里，引用的this(). 第二个函数是被调用的构造函数
        map<Function, Function> thisConstructorRef;

        // 在构造函数里，引用的super(), 第二个函数是被调用的构造函数
        map<Function, Function> superConstructorRef;

        /**
         * 
         */

        // AnnotatedTree()
        // {
        // }

        
};

#endif