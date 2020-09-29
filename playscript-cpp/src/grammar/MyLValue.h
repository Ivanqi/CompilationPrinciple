#ifndef MYLVALUE_H
#define MYLVALUE_H
#pragma once

#include "LValue.h"

namespace play
{
    class Variable;

    // 自己实现的左值对象
    class MyLValue final : public LValue
    {
        private:
            Variable *variable_;
            PlayObject *valueContainer_;

        public:
            MyLValue(PlayObject *valueContainer, Variable *variable);

            virtual antlrcpp::Any getValue();

            virtual void setValue(antlrcpp::Any value);

            virtual Variable* getVariable();

            std::string toString();

            virtual PlayObject* getValueContainer();
    };
};

#endif