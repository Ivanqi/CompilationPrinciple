#ifndef FUNCTION_H
#pragma once
#include <vector>
#include <set>
#include <string>
#include "FunctionType.h"
#include "Scope.h"
// #include "ParserRuleContext.h"
using namespace antlr4;

namespace play
{
    class Variable;
    class DefaultFunctionType;
    
    class Function: public Scope, public FunctionType
    {
        private:
            std::vector<Type*> paramTypes;

        public:
            // 参数
            std::vector<Variable*> parameters;

            // 返回值
            Type *returnType;

            // 闭包变量，即它所引用的外部环境变量
            std::set<Variable*> closureVariables;

        public:
            Function(std::string name, Scope *enclosingScope, ParserRuleContext *ctx);

            std::string getName();

            Type* getReturnType();

            std::vector<Type*> getParamTypes();

            Scope* getEnclosingScope();

            std::string toString();

            bool isType(Type *type);

            /**
             * 检查改函数是否匹配所需的参数
             */
            bool matchParameterTypes(std::vector<Type*> paramTypes);

            /**
             * 该函数是不是类的方法
             */
            bool isMethod();

            /**
             * 该函数是不是类的构建函数
             */
            bool isConstructor();
    };
};
#endif