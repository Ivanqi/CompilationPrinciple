#pragma once
#include <unordered_map>
#include "Variable.h"
#include "NullObject.h"

class PlayObject
{
    protected:
        unordered_map<Variable*, void*> fields;

    public:
        void* getValue(Variable *variable)
        {
            void *rtn = fields[variable];

            // 替换成自己的NullObject
            if (rtn == NULL) {
                rtn = NullObject::instance();
            }
            return rtn;
        }

        void setValue(Variable *variable, void *value)
        {
            fields[variable] = value;
        }

        unordered_map<Variable*, void*> getFields()
        {
            return fields;
        }

        bool isset(Variable *variable)
        {
            return (fields.find(variable) != fields.end()) ? true : false;
        }
};