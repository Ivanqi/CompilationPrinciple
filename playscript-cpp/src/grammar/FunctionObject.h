#pragma once
#include "PlayObject.h"
#include "Function.h"
#include "Variable.h"

// 存放一个函数运行时的本地变量的值，包括参数的值
class FunctionObject: public PlayObject
{
    protected:
        // 类型
        Function *function;

        /**
         * 接收者所在的scope。缺省是function的enclosingScope，也就是词法的Scope。
         * 当赋值给一个函数型变量的时候，要修改receiverEnclosingScope等于这个变量的enclosingScope。
         */
        Variable *receiver;

    public:
        FunctionObject(Function *function)
        {
            this->function = function;
        }

        void setFunction(Function *function)
        {
            this->function = function;
        }

        Variable* getReceiver()
        {
            return receiver;
        }

};