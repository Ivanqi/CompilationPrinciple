#ifndef FUNCTION_H
#pragma once
#include <vector>
#include <unordered_set>
#include <string>
#include "FunctionType.h"
#include "Scope.h"
#include "ParserRuleContext.h"
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
            // 参数. 设置该function的参数
            std::vector<Variable*> parameters;

            // 返回值
            Type *returnType;

            // 闭包变量，即它所引用的外部环境变量
            std::unordered_set<Variable*> closureVariables;

        public:
            Function(std::string name, Scope *enclosingScope, ParserRuleContext *ctx);

            virtual std::string getName();

            virtual Type* getReturnType();

            virtual std::vector<Type*> getParamTypes();

            virtual Scope* getEnclosingScope();

            virtual std::string toString();

            bool isType(Type *type);

            void setParameters(Variable *var)
            {
                parameters.push_back(var);
            }

            /**
             * 检查改函数是否匹配所需的参数
             */
            virtual bool matchParameterTypes(std::vector<Type*> paramTypes);

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