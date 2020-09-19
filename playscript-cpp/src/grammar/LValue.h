#ifndef LVALUE_H
#define LVALUE_H

#pragma once

#include "Variable.h"
// #include "PlayObject.h"

namespace play
{
    class PlayObject;
    class LValue
    {
        public:
            virtual antlrcpp::Any getValue() = 0;

            virtual void setValue(antlrcpp::Any value) = 0;

            virtual Variable* getVariable() = 0;
            
            virtual PlayObject* getValueContainer() = 0;
    };
};

#endif