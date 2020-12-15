#ifndef GRAMMARNFAStATE_H
#define GRAMMARNFAStATE_H
#include "State.h"
#include "Item.h"

class GrammarNFAState: public State
{
    public:
        Item *item{nullptr};

        GrammarNFAState(Item *item);

        string toString();
};

#endif