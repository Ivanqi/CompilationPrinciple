#ifndef MYLVALUE_H
#define MYLVALUE_H
#pragma once

#include "LValue.h"

namespace play
{
    class Variable;
    class PlayObject;

    // 自己实现的左值对象
    class MyLValue final : public LValue
    {
        private:
            Variable *variable_;
            PlayObject* valueContainer_;

            MyLValue(PlayObject *valueContainer, Variable *variable);

        public:
            antlrcpp::Any getValue();

            void setValue(antlrcpp::Any value);

            Variable* getVariable();

            std::string toString();

            PlayObject* getValueContainer();
    };
};

#endif