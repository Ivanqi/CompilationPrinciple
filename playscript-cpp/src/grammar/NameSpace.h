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
            std::string name;
        
        private:
            std::vector<NameSpace*> subNameSpaces;

        public:
            NameSpace(std::string name, Scope *enclosingScope, ParserRuleContext *ctx)
            {
                this->name = name;
                this->enclosingScope = enclosingScope;
                this->ctx = ctx;
            }

            std::string getName()
            {
                return name;
            }

            std::vector<NameSpace*> getSubNameSpaces()
            {
                return subNameSpaces;
            }

            void addSubNameSpace(NameSpace *child)
            {
                child->setParent(this);
                subNameSpaces.push_back(child);
            }

            void removeSubNameSpace(NameSpace *child)
            {
                child->setParent(NULL);
                std::vector<NameSpace*>::iterator itor;
                // O(n)
                for (itor = subNameSpaces.begin(); itor != subNameSpaces.end(); itor++) {
                    if (*itor == child) {
                        itor = subNameSpaces.erase(itor);
                    }
                }
            }

            void setParent(NameSpace *pa)
            {
                parent = pa;
            }
    };
};
#endif