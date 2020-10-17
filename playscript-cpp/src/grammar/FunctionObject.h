#ifndef FUNCTIONOBJECT_H
#define FUNCTIONOBJECT_H

#pragma once
#include "PlayObject.h"


namespace play 
{
    class Function;
    class Variable;

    // 存放一个函数运行时的本地变量的值，包括参数的值
    class FunctionObject: public PlayObject
    {
        public:
            // 类型
            Function *function_;

            /**
             * 接收者所在的scope。缺省是function的enclosingScope，也就是词法的Scope。
             * 当赋值给一个函数型变量的时候，要修改receiverEnclosingScope等于这个变量的enclosingScope。
             */
            Variable *receiver_ = nullptr;

            FunctionObject(Function *function);

            void setFunction(Function *function);

            Variable* getReceiver();
    };
};

#endif