// #pragma once
// #include "PlayScriptBaseVisitor.h"
// #include "Variable.h"
// #include "Class.h"

// // 用来表示this 关键字的符号
// class This: public Variable
// {
//     public:
//         This(Class *theClass, PlayScriptParser::ExpressionContext *ctx): Variable(typeid(this).name(), theClass, ctx)
//         {

//         }

//         Class* Class()
//         {
//             return (Class*) enclosingScope;
//         }
// };