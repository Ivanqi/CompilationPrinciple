#ifndef FUNCTION_H
#pragma once
// #include <vector>
// #include <set>
// #include <string>
#include "FunctionType.h"
#include "Scope.h"
// #include "Variable.h"
// #include "PlayScriptBaseVisitor.h"
// #include "DefaultFunctionType.h"

class Function: public Scope, public FunctionType
{
//     private:
//         std::vector<Type*> paramTypes;

//     protected:
//         // 参数
//         std::vector<Variable*> parameters;

//         // 返回值
//         Type returnType;

//         // 闭包变量，即它所引用的外部环境变量
//         std::set<Variable*> closureVariables;

//     public:
//         Function(std::string name, Scope *enclosingScope, PlayScriptParser::ExpressionContext *ctx)
//         {
//             this->name = name;
//             this->enclosingScope = enclosingScope;
//             this->ctx = ctx;
//         }

//         Type getReturnType()
//         {
//             return returnType;
//         }

//         std::vector<Type*> getParamTypes()
//         {
//             for (Variable *param: parameters) {
//                 paramTypes.push_back(param->getType());
//             }

//             return paramTypes;
//         }

//         std::string toString()
//         {
//             return "Function " + name;
//         }

//         bool isType(Type *type)
//         {
//             FunctionType *ft = dynamic_cast<FunctionType*>(type);
//             if (ft != NULL) {
//                 return DefaultFunctionType::isType(this, (FunctionType*)type);
//             }
//             return false;
//         }

//         /**
//          * 检查改函数是否匹配所需的参数
//          */
//         bool matchParameterTypes(std::vector<Type*> paramTypes)
//         {
//             // 比较每个参数
//             if (parameters.size() != paramTypes.size()) {
//                 return false;
//             }

//             bool match = true;

//             for (int i = 0; i < paramTypes.size(); i++) {
//                 Variable *var = parameters[i];
//                 Type *type = paramTypes[i];
//                 if (!var->getType()->isType(type)) {
//                     match = false;
//                     break;
//                 }
//             }

//             return match;
//         }

//         /**
//          * 该函数是不是类的方法
//          */
//         bool isMethod()
//         {
//             Scope *tmp = dynamic_cast<Scope*>(enclosingScope);
//             return (tmp != NULL ? true : false);
//         }

//         /**
//          * 该函数是不是类的构建函数
//          */
//         bool isConstructor()
//         {
//             Scope *tmp = dynamic_cast<Scope*>(enclosingScope);
//             if (tmp != NULL) {
//                 return (enclosingScope->name == name);
//             }
//             return false;
//         }
};
#endif