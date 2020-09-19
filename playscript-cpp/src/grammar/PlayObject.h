#ifndef PLAYOBJECT_H
#define PLAYOBJECT_H

#pragma once
#include <unordered_map>
#include "antlr4-runtime.h"

namespace play
{
    class Variable;

    // PlayScript的对象
    class PlayObject
    {
        public:
            std::unordered_map<Variable*, antlrcpp::Any> fields;

            virtual antlrcpp::Any getValue(Variable *variable);

            virtual void setValue(Variable *variable, antlrcpp::Any value);

            std::unordered_map<Variable*, antlrcpp::Any> getFields();

            bool isset(Variable *variable);
    };
};

#endif