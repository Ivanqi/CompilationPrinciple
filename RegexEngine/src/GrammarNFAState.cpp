#include "GrammarNFAState.h"

string GrammarNFAState::toString()
{
    string sb;
    sb.append(item->toString()).append("\n");
    sb.append(this->toString());
    return sb;
}