#include "NullObject.h"
using namespace play;

NullObject* NullObject::instance = NULL;

NullObject::NullObject()
{
    instance = new NullObject();
}

// 获取唯一实例
NullObject* NullObject::GetInstance()
{
    return instance;
}