#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "Scope.h"
#include "Type.h"
#include "This.h"
#include "Super.h"
#include "PlayScriptBaseVisitor.h"
#include "DefaultConstructor.h"


class Class: public Scope, public Type
{
    private:
        Class *parentClass;

        This *thisRef;

        Super *superRef;

        DefaultConstructor *defaultConstructor;

    
    protected:
        // 最顶层的基类
        static Class *rootClass;

        Class (std::string, PlayScriptParser::ExpressionContext *ctx)
        {
            this->name = name;
            this->ctx = ctx;

            thisRef = new This(this, ctx);
            thisRef->type = this;

            rootClass = new Class("Object", NULL);
        }

        Class* getParentClass()
        {
            return parentClass;
        }

        void setParentClass(Class* theClass)
        {
            parentClass = theClass;

            // 其实superRef引用的也是自己
            superRef = new Super(parentClass, ctx);
            superRef->type = parentClass;
        }

        This* getThis()
        {
            return thisRef;
        }

        Super* getSuper()
        {
            return superRef;
        }

        // 是否包含某个Variable， 包括自身及父类
        Variable* getVariable(std::string name)
        {
            Variable *rtn = Scope::getVariable(name);

            if (rtn == NULL && parentClass != NULL) {
                rtn = parentClass->getVariable(name);   // TODO 是否要检查visibility
            }

            return rtn;
        }

        // 是否包含某个Class
        Class* getClass(std::string name)
        {
            Class *rtn = Scope::getClass(name);

            if (rtn == NULL && parentClass != NULL) {
                rtn = parentClass->getClass(name);
            }

            return rtn;
        }

        // 找到某个构造函数。不需要往父类去找，在本级找就行类
        Function* findConstructos(std::vector<Type*> paramTypes)
        {
            Function *rtn = Scope::getFunction(name, paramTypes);   // TODO是否要检查 visibility
            return rtn;
        }

        /**
         * 在自身及父类中找到某个方法
         * @param name
         * @param paramTypes 参数类型列表。该参数不允许为空，如果没有参数，需要传入一个0长度的列表
         */
        Function* getFunction(std::string name, std::vector<Type*> paramTypes)
        {
            // 在本级查找这个方法
            Function *rtn = Scope::getFunction(name, paramTypes);   // TODO是否要检查 visibility

            // 如果在本级找不到，那么递归的从父类中查找
            if (rtn == NULL && parentClass != NULL) {
                rtn = parentClass->getFunction(name, paramTypes);
            }

            return rtn;
        }

        Variable* getFunctionVariable(std::string name, std::vector<Type*> paramTypes)
        {
           Variable *rtn = Scope::getFunctionVariable(name, paramTypes);

            if (rtn == NULL && parentClass != NULL) {
               rtn = parentClass->getFunctionVariable(name, paramTypes);
            }

            return rtn;
        }

        // 是否包含某个Symbol.这时候要把父类的成员考虑进来
        bool containsSymbol(Symbol *symbol)
        {
            // this 关键字
            if (symbol == thisRef || symbol == superRef) {
                return true;
            }

            bool rtn = false;
            rtn = std::find(symbols.begin(), symbols.end(), symbol);
            if (!rtn && parentClass != NULL) {
                rtn = parentClass->containsSymbol(symbol);
            }
            return rtn;
        }

        DefaultConstructor* defaultConstructor()
        {
            if (defaultConstructor == NULL) {
                defaultConstructor = new DefaultConstructor(this->name, this);
            }
            return defaultConstructor;
        } 

    public:
        /**
         * 当自身是目标类型的子类型的时候，返回true
         * @param type 目标类型
         * @return
         */
        bool isType(Type *type)
        {
            if (this == type) {
                return true;
            }

            Class *tmp = dynamic_cast<Class*>(type);
            if (tmp != NULL) {
                return ((Class *)type)->isAncestor(this);
            }
            return false;
        }

        /**
         * 本类型是不是另一个类型的祖先类型
         * @param theClass
         * @return
         */
        bool isAncestor(Class *theClass)
        {
            if (theClass->getParentClass() != NULL) {
                if (theClass->getParentClass() == this) {
                    return true;
                } else {
                    return isAncestor(theClass->getParentClass());
                }
            }
            return false;
        }
};