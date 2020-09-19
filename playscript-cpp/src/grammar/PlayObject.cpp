#include "PlayObject.h"
#include "Variable.h"
#include "NullObject.h"

using namespace play;

antlrcpp::Any PlayObject::getValue(Variable *variable)
{
    antlrcpp::Any rtn = fields[variable];

    //TODO 父类的属性如何返回？还是说都在这里了？

    // 替换成自己的NullObject
    if (rtn.isNull()) {
        rtn = NullObject::GetInstance();
    }
    return rtn;
}

void PlayObject::setValue(Variable *variable, antlrcpp::Any value)
{
    fields[variable] = value;
}

std::unordered_map<Variable*, antlrcpp::Any> PlayObject::getFields()
{
    return fields;
}

bool PlayObject::isset(Variable *variable)
{
    return (fields.find(variable) != fields.end()) ? true : false;
}