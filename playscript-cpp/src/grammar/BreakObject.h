#ifndef BREAKOBJECT_H
#define BREAKOBJECT_H

#pragma once

#include <string>

// 用于代表一个break语句的对象
class BreakObject final
{
    private:
        static BreakObject *instance;

    public:
        BreakObject()
        {
        }

        // 获取唯一的实例
        static BreakObject* GetInstance()
        {
            return instance;
        }

        // 在打印时输出Break
        std::string toString()
        {
            return "Break";
        }
};

BreakObject* BreakObject::instance = new BreakObject();

#endif