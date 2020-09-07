// #pragma once
// #include <string>
// #include "Scope.h"
// #include "PlayObject.h"
// #include "BlockScope.h"
// #include "ClassObject.h"
// #include "FunctionObject.h"

// class StackFrame
// {
//     public:
//         // 该frame所对应的scope
//         Scope *scope;

//         /**
//          * 放parent scope所对应的frame的指针，就叫parentFrame吧，便于提高查找效率。
//          * 规则：如果是同一级函数调用，跟上一级的parentFrame相同；
//          * 如果是下一级的函数调用或For、If等block，parentFrame是自己；
//          * 如果是一个闭包（如何判断？），那么要带一个存放在堆里的环境。
//          */
//         StackFrame *parentFrame;

//         // 实际存放变量的地方
//         PlayObject *object;

//         StackFrame(BlockScope *scope)
//         {
//             this->scope = scope;
//             this->object = new PlayObject();
//         }

//         StackFrame(ClassObject *object)
//         {
//             this->scope = object->getType();
//             this->object = object;
//         }

//         // todo,检查这个类下的这个函数
//         std::string toString()
//         {
//             std::string rtn = "";
//             if (parentFrame != NULL) {
//                 rtn += " -> ";
//             }
//             return rtn;
//         }

//     protected:
//         // 本栈帧里有没有包含某个变量的数据
//         bool contains(Variable *variable)
//         {
//             if (object != NULL && object->getFields() != NULL) {
//                 return object->isset(variable);
//             }
//             return false;
//         }
    
// };