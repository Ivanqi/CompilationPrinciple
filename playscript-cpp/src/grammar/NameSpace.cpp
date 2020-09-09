#include "NameSpace.h"
using namespace play;

NameSpace::NameSpace(std::string name, Scope *enclosingScope, ParserRuleContext *ctx):name(name)
{
    this->enclosingScope = enclosingScope;
    this->ctx = ctx;
}

std::string NameSpace::getName()
{
    return name;
}

std::vector<NameSpace*> NameSpace::getSubNameSpaces()
{
    return subNameSpaces;
}

void NameSpace::addSubNameSpace(NameSpace *child)
{
    child->setParent(this);
    subNameSpaces.push_back(child);
}

void NameSpace::removeSubNameSpace(NameSpace *child)
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

void NameSpace::setParent(NameSpace *pa)
{
    parent = pa;
}