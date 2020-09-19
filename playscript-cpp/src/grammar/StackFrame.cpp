#include "StackFrame.h"
#include "Scope.h"
#include "PlayObject.h"
#include "BlockScope.h"
#include "ClassObject.h"
#include "FunctionObject.h"
#include "Function.h"

using namespace play;

StackFrame::StackFrame()
{
}

StackFrame::StackFrame(BlockScope *scope): scope_(scope), object_(new PlayObject)
{
}

StackFrame::StackFrame(ClassObject *object): scope_((Scope*)object->getType()), object_(object)
{
    
}

StackFrame::StackFrame(FunctionObject *object):scope_(object->function_), object_(object)
{
}

// todo,检查这个类下的这个函数
std::string StackFrame::toString()
{
    std::string rtn = "";
    if (parentFrame_ != NULL) {
        rtn += " -> ";
    }
    return rtn;
}

// 本栈帧里有没有包含某个变量的数据
bool StackFrame::contains(Variable *variable)
{
    if (object_ != NULL && object_->getFields().size () > 0) {
        return object_->isset(variable);
    }
    return false;
}