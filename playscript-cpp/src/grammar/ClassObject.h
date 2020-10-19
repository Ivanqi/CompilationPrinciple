#ifndef CLASSOBJECT_H
#define CLASSOBJECT_H

#pragma once
#include "PlayObject.h"

namespace play
{
    class Class;
    
    class ClassObject: public PlayObject
    {        
        public:
            // 类型
            Class *type;

            ClassObject(Class *theClass)
            {

            }
            Class* getType();
    };
};

#endif