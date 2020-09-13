#ifndef ANNOTATEDTREE_H
#define ANNOTATEDTREE_H

#pragma once
#include "ParserRuleContext.h"
#include "RuleContext.h"
#include "tree/ParseTree.h"
#include "Type.h"
#include "Symbol.h"
#include "CompilationLog.h"

#include <vector>
#include <map>
#include <string>

using namespace antlr4;
using namespace antlr4::tree;

using namespace std;

namespace play 
{
    class NameSpace;
    class Function;
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
            map<ParserRuleContext*, Symbol*> symbolOfNode;

            // AST 节点对应的Scope。 如for, 函数调用会启动新的Scope
            map<ParserRuleContext*, Scope*> node2Scope;

            // 用于做类型推断，每个节点推断出来的类型
            map<ParserRuleContext*, Type*> typeOfNode;

            // 命名空间
            NameSpace *namespaces;

            // 语义分析过程中生成的信息，包括普通信息，警告和错误
            vector<CompilationLog> logs;

            // 在构造函数里，引用的this(). 第二个函数是被调用的构造函数
            map<Function*, Function*> thisConstructorRef;

            // 在构造函数里，引用的super(), 第二个函数是被调用的构造函数
            map<Function*, Function*> superConstructorRef;

            // AnnotatedTree()
            // {
            // }

            void log(std::string message, int type, ParserRuleContext *ctx);

            void log(std::string message, ParserRuleContext *ctx);

            /**
             * 是否有编译错误
             */
            bool hasCompilationError();

            // 通过名称查找Variable.逐级Scope查找
            Variable* lookupVariable(Scope *scope, std::string idName);

            // 通过名称查找Class。逐级Scope查找。
            Class* lookupClass(Scope *scope, std::string idName);

            Type* lookupType(std::string idName);

            // 通过方法的名称和方法签名查找Function。逐级Scope查找。
            Function* lookupFunction(Scope *scope, std::string idName, std::vector<Type*> paramTypes);

            // 查找函数型变量，逐级查找
            Variable* lookupFunctionVariable(Scope *scope, std::string idName, std::vector<Type*> paramTypes);

            // 逐级查找函数（或方法）。仅通过名字查找。如果有重名的，返回第一个就算了。//TODO 未来应该报警。
            Function* lookupFunction(Scope *scope, std::string name);

            /**
             * 查找某节点所在的Scope
             * 算法：逐级查找父节点，找到一个对应着Scope的上级节点
             */
            Scope* enclosingScopeOfNode(ParserRuleContext *node);

            /**
             * 包含某节点的函数
             */
            Function* enclosingFunctionOfNode(RuleContext *ctx);

            /**
             * 包含某节点的类
             */
            Class* enclosingClassOfNode(RuleContext *ctx);

            /**
             * 输出本Scope中的内容，包括每个变量的名称、类型。
             * @return 树状显示的字符串
             */
            std::string getScopeTreeString();
        
        private:
            // 对于类，需要连父类也查找
            Function* getMethodOnlyByName(Class *theClass, std::string name);

            Function* getFunctionOnlyByName(Scope *scope, std::string name);

            void scopeToString(std::string& sb, Scope *scope, std::string indent);
    };
};

#endif