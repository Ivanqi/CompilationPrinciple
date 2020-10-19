#include "ClassObject.h"
#include "Class.h"

using namespace play;

ClassObject::ClassObject(Class *theClass): type(theClass)
{
    
}

Class* ClassObject::getType()
{
    return type;
}