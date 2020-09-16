#ifndef NAMESPACE_H
#define NAMESPACE_H
#pragma once

#include "ParserRuleContext.h"
#include "Scope.h"
#include <vector>
using namespace antlr4;

namespace play
{
    class NameSpace: public Scope
    {
        private:
            NameSpace *parent;
            // std::string name;
        
        private:
            std::vector<NameSpace*> subNameSpaces;

        public:
            NameSpace(std::string name, Scope *enclosingScope, ParserRuleContext *ctx);

            std::string getName();

            std::vector<NameSpace*> getSubNameSpaces();

            void addSubNameSpace(NameSpace *child);

            void removeSubNameSpace(NameSpace *child);

            void setParent(NameSpace *pa);
    };
};
#endif