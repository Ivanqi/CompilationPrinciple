#pragma once
#include <vector>
#include <string>
#include "FunctionType.h"
#include "Scope.h"
#include "Type.h"

class DefaultFunctionType: public FunctionType
{
    protected:
        std::string name;

        // 所属于作用域
        Scope *enclosingScope;

        Type *returnType;

        std::vector<Type*> paramTypes;

        // 对于未命名的类型，自动赋予名字
        int nameIndex = 1;

    public:
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
            return paramTypes;
        }

        std::string toString()
        {
            return "FunctionType";
        }

        bool isType(Type *type)
        {
            FunctionType *type = dynamic_cast<FunctionType*>(type);
            if (type) {
                return isType(this, (FunctionType*)type);
            }
        }

        /**
         * 工具性方法：比较type1 是否是 type2
         * 规则
         *  1. type1的返回值跟 type2 相等， 或者是它的子类
         */
        static bool isType(FunctionType *type1, FunctionType *type2)
        {
            if (type1 == type2) return true;    // shortcut

            if (!type1->getReturnType()->isType(type2->getReturnType())) {
                return false;
            }

            std::vector<Type*> paramTypes1 = type1->getParamTypes();
            std::vector<Type*> paramTypes2 = type2->getParamTypes();

            if (paramTypes1.size() != paramTypes2.size()) {
                return false;
            }

            for (int i = 0; i < paramTypes1.size(); i++) {
                if (!paramTypes1[i]->isType(paramTypes2[i])) {
                    return false;
                }
            }

            return true;
        }

        /**
         * 检查改函数是否匹配所需的参数
         */
        bool matchParameterTypes(std::vector<Type*> paramTypes)
        {
            // 比较每个参数
            if (paramTypes.size() != paramTypes.size()) {
                return false;
            }

            bool match = true;
            
            for (int i = 0; i < paramTypes.size(); i++) {
                Type *type1 = this->getParamTypes[i];
                Type *type = paramTypes[i];
                if (!type1->isType(type)) {
                    match = false;
                    break;
                }
            }

            return match;
        }
};