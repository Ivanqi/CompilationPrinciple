// #pragma once
// #include <string>
// #include "Class.h"
// #include "Function.h"

// /**
//  * 代表一个缺省的构造函数
//  * 这不是在程序里声明的。因此没有对应的FunctionDeclarationContext
//  */
// class DefaultConstructor: public Function
// {
//     protected:
//         DefaultConstructor(std::string name, Class *theClass): Function(name, theClass, NULL)
//         {

//         }

//     public:
//         Class* Class()
//         {
//             return (Class*) enclosingScope;
//         }
// };