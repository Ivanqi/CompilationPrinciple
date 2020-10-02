#ifndef CLASS_H
#define CLASS_H
#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "Scope.h"
#include "Type.h"

#include "ParserRuleContext.h"
using namespace antlr4;

namespace play
{
    class This;
    class Super;
    class DefaultConstructor;

    class Class: public Scope, public Type
    {
        private:
            Class *parentClass;

            This *thisRef;

            Super *superRef;

            DefaultConstructor *defaultConstructor_;
        
        protected:
            // 最顶层的基类
            Class *rootClass;

        public:
            Class* getParentClass();

            void setParentClass(Class* theClass);

            This* getThis();

            Super* getSuper();

            // 是否包含某个Variable， 包括自身及父类
            Variable* getVariable(std::string name);

            // 是否包含某个Class
            Class* getClass(std::string name);

            // 找到某个构造函数。不需要往父类去找，在本级找就行类
            Function* findConstructor(std::vector<Type*> paramTypes);

            /**
             * 在自身及父类中找到某个方法
             * @param name
             * @param paramTypes 参数类型列表。该参数不允许为空，如果没有参数，需要传入一个0长度的列表
             */
            Function* getFunction(std::string name, std::vector<Type*> paramTypes);

            Variable* getFunctionVariable(std::string name, std::vector<Type*> paramTypes);

            // 是否包含某个Symbol.这时候要把父类的成员考虑进来
            bool containsSymbol(Symbol *symbol);

            DefaultConstructor* defaultConstructor();

            Class(std::string, ParserRuleContext *ctx);

            std::string getName();

            Scope* getEnclosingScope();

            /**
             * 当自身是目标类型的子类型的时候，返回true
             * @param type 目标类型
             * @return
             */
            bool isType(Type *type);

            /**
             * 本类型是不是另一个类型的祖先类型
             * @param theClass
             * @return
             */
            bool isAncestor(Class *theClass);
    };
};

#endif