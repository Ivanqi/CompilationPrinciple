// #pragma once

// #include <string>
// #include "Type.h"
// #include "Symbol.h"
// #include "PlayScriptBaseVisitor.h"

// class Variable: public Symbol
// {
//     protected:
//         // 变量类型
//         Type *type;

//         // 是否允许多次重复，这是一个创新的参数机制
//         int multiplicity;

//         // 作为parameter的变量的属性，缺省值
//         void* defaultValue = NULL;

//         Variable(std::string name, Scope *enclosingScope, PlayScriptParser::ExpressionContext *ctx)
//         {
//             this->name = name;
//             this->enclosingScope = enclosingScope;
//             this->ctx = ctx;
//         }
    
//     public:
//         // 是不是类的属性
//         bool isClassMember()
//         {
//             Scope *sc = dynamic_cast<Scope*>(enclosingScope);
//             return (sc != NULL) ? true: false;
//         }

//         std::string toString()
//         {
//             return "Variable " + name + " -> ";
//         }

//         Type* getType()
//         {
//             return type;
//         }
// };
