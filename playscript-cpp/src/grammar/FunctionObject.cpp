#include "FunctionObject.h"
#include "Function.h"
#include "Variable.h"

using namespace play;

FunctionObject::FunctionObject(Function *function): function_(function)
{
}

void FunctionObject::setFunction(Function *function)
{
    function_ = function;
}

Variable* getReceiver()
{
    return receiver_;
}