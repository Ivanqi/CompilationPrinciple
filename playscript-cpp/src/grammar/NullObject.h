// #pragma once
// #include "ClassObject.h"

// /**
//  * 用来代表NULL值的对象
//  * 采用单例模式。用instance()方法来获得一个对象实例
//  */
// class NullObject: public ClassObject
// {
//     private:
//         static NullObject *instance;

//         NullObject()
//         {
//             instance = new NullObject();
//         }

//     public:
//         // 获取唯一实例
//         static NullObject* instance()
//         {
//             return instance;
//         }

//         // 在打印时输出Null
//         std::string toString()
//         {
//             return "Null";
//         }
// };