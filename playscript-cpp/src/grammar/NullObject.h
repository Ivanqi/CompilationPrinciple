#ifndef NULLOBJECT_H
#define NULLOBJECT_H

#pragma once
#include "ClassObject.h"

namespace play
{
    /**
     * 用来代表NULL值的对象
     * 采用单例模式。用instance()方法来获得一个对象实例
     */
    class NullObject: public ClassObject
    {
        private:
            static NullObject *instance;

            NullObject();

        public:
            // 获取唯一实例
            static NullObject* GetInstance();

            // 在打印时输出Null
            std::string toString()
            {
                return "Null";
            }
    };
};

#endif