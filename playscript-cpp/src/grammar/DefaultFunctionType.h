#ifndef DEFAULTFUNCTIONTYPE_H
#define DEFAULTFUNCTIONTYPE_H

#pragma once
#include <vector>
#include <string>
#include "FunctionType.h"


namespace play
{
    class Scope;
    class Type;

    class DefaultFunctionType: public FunctionType
    {
        public:
            std::string name;

            // 所属于作用域
            Scope *enclosingScope;

            Type *returnType;

            // 参数类型
            std::vector<Type*> paramTypes_;

            // 对于未命名的类型，自动赋予名字
            static int nameIndex;

        public:
            DefaultFunctionType();

            std::string getName()
            {
                return name;
            }

            Scope* getEnclosingScope()
            {
                return enclosingScope;
            }

            Type* getReturnType()
            {
                return returnType;
            }

            std::vector<Type*> getParamTypes()
            {
                return paramTypes_;
            }

            std::string toString()
            {
                return "FunctionType";
            }

            bool isType(Type *type);

            /**
             * 工具性方法：比较type1 是否是 type2
             * 规则
             *  1. type1的返回值跟 type2 相等， 或者是它的子类
             */
            static bool isType(FunctionType *type1, FunctionType *type2);

            /**
             * 检查改函数是否匹配所需的参数
             */
            bool matchParameterTypes(std::vector<Type*> paramTypes);
    };
};
#endif