#include "VoidType.h"
#include "Scope.h"

using namespace play;

VoidType* VoidType::singleton_ = NULL;


VoidType* VoidType::GetInstance()
{
    if (singleton_ == NULL) {
        singleton_ = new VoidType();
    }
    return singleton_;
}

