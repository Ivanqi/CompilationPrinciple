#ifndef VOIDTYPE_H
#define VOIDTYPE_H

#pragma once

#include "Type.h"
#include <string>

namespace play
{  
    class Scope;
    class VoidType final: public Type
    {
        protected:
            static VoidType* singleton_; 

        public:
            std::string getName()
            {
                return "void";
            }

            Scope* getEnclosingScope()
            {
                return NULL;
            }
        
            VoidType()
            {
            }

            static VoidType* GetInstance();


            bool isType(Type *type)
            {
                return this == type;
            }

            std::string toString()
            {
                return "void";
            }
    };
};
#endif