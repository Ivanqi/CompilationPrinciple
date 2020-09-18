#ifndef CLASSOBJECT_H
#define CLASSOBJECT_H

#pragma once
#include "PlayObject.h"
#include "Class.h"

namespace play
{
    class ClassObject: public PlayObject
    {        
        public:
            // 类型
            Class *type;

            Class* getType()
            {
                return type;
            }
    };
};

#endif