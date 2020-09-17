#ifndef PLAYOBJECT_H
#define PLAYOBJECT_H

#pragma once
#include <unordered_map>
#include "antlr4-runtime.h"

namespace play
{
    class Variable;
    class NullObject;

    // PlayScript的对象
    class PlayObject
    {
        protected:
            std::unordered_map<Variable*, antlrcpp::Any> fields;

        public:
            virtual antlrcpp::Any getValue(Variable *variable);

            virtual void setValue(Variable *variable, antlrcpp::Any value);

            std::unordered_map<Variable*, antlrcpp::Any> getFields();

            bool isset(Variable *variable);
    };
};

#endif