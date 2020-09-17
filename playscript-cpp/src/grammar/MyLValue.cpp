#include "MyLValue.h"
#include "Variable.h"
#include "PlayObject.h"
#include "This.h"
#include "Super.h"
#include "FunctionObject.h"

using namespace play;

MyLValue::MyLValue(PlayObject *valueContainer, Variable *variable):valueContainer_(valueContainer), variable_(variable)
{
    
}

antlrcpp::Any MyLValue::getValue()
{
    // 对于this 或 super 关键字，直接返回这个对象，应该是ClassObject
    This *thisTmp = dynamic_cast<This*>(variable_);
    Super *superTmp = dynamic_cast<Super*>(variable_);

    if (thisTmp != NULL || superTmp != NULL) {
        return valueContainer_;
    }

    return valueContainer_->getValue(variable_);
}

void MyLValue::setValue(antlrcpp::Any value)
{
    valueContainer_->setValue(variable_, value);

    // 如果variable是函数型变量，那改变functionObject->receiver
    FunctionObject *tmp = dynamic_cast<FunctionObject*>(value);

    if (tmp != NULL) {
        tmp->receiver = (Variable *) variable_;
    }
}

Variable* MyLValue::getVariable()
{
    return variable_;
}

// TODO: 代码确实一部分
std::string MyLValue::toString()
{
    return "LValue of " + variable_->name + " : " ;
}

PlayObject* MyLValue::getValueContainer()
{
    return valueContainer_;
}