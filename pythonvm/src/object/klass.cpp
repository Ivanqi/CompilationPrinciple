#include "object/klass.hpp"
#include "runtime/universe.hpp"
#include "runtime/stringTable.hpp"
#include "runtime/functionObject.hpp"
#include "runtime/interpreter.hpp"
#include "object/hiObject.hpp"
#include "object/hiInteger.hpp"
#include "object/hiDict.hpp"
#include "object/hiList.hpp"
#include "object/hiString.hpp"
#include "memory/heap.hpp"
#include "memory/oopClosure.hpp"

#define ST(x) StringTable::get_instance()->STR(x)
#define STR(x) x##_str

int Klass::compare_klass(Klass* x, Klass* y)
{
    if (x == y) {
        return 0;
    }

    if (x == IntegerKlass::get_instance()) {
        return -1;
    } else if (y == IntegerKlass::get_instance()) {
        return 1;
    }

    if (x->name()->less(y->name()) == (HiObject*)Universe::HiTrue) {
        return -1;
    } else {
        return 1;
    }
}

void Klass::print(HiObject* x)
{
    HiObject* meth_repr = get_klass_attr(x, ST(repr));
    if (meth_repr != Universe::HiNone) {
        Interpreter::get_instance()->call_virtual(meth_repr, NULL)->print();

        return;
    }

    printf("<object of ");
    x->klass()->name()->print();
    printf(", at %p>", x);
}

HiObject* Klass::create_klass(HiObject* x, HiObject* supers, HiObject* name)
{
    assert(x->klass() == (Klass*)DictKlass::get_instance());
    assert(supers->klass() == (Klass*)ListKlass::get_instance());
    assert(name->klass() == (Klass*)StringKlass::get_instance());

    Klass* new_klass = new Klass();
    HiDict* klass_dict = (HiDict*) x;
    HiList* supers_list = (HiList*) supers;

    new_klass->set_klass_dict(klass_dict);
    new_klass->set_name((HiString*)name);
    new_klass->set_super_list(supers_list);

    HiTypeObject* type_obj = new HiTypeObject();
    type_obj->set_own_klass(new_klass);

    return type_obj;
}

HiObject* Klass::allocate_instance(HiObject* callable, ArrayList<HiObject*>* args)
{
    HiObject* inst = NULL;
    if (_mro->index(IntegerKlass::get_instance()->type_object()) >= 0) {
        inst = new HiInteger(0);
    } else if (_mro->index(StringKlass::get_instance()->type_object()) >= 0) {
        inst = new HiString("");
    } else if (_mro->index(ListKlass::get_instance()->type_object()) >= 0) {
        inst = new HiList();
    } else if (_mro->index(DictKlass::get_instance()->type_object()) >= 0) {
        inst = new HiDict();
    } else {
        inst = new HiObject();
    }

    inst->set_klass(((HiTypeObject*)callable)->own_klass);
    HiObject* constructor = inst->get_klass_attr(ST(init));
    if (constructor != Universe::HiNone) {
        Interpreter::get_instance()->call_virtual(constructor, args);
    }

    return inst;
}

HiObject* Klass::add(HiObject* lhs, HiObject* rhs)
{
    ObjList args = new ArrayList<HiObject*>();
    args->add(rhs);
    return find_and_call(lhs, args, ST(add));
}

HiObject* Klass::find_and_call(HiObject* lhs, ObjList args, HiObject* func_name)
{
    HiObject* func = lhs->get_klass_attr(func_name);
    if (func != Universe::HiNone) {
        return Interpreter::get_instance()->call_virtual(func, args);
    }

    printf("class ");
    lhs->klass()->name()->print();
    printf(" Error : unsupport operation for class ");
    assert(false);
    return Universe::HiNone;
}

HiObject* Klass::len(HiObject* x)
{
    return find_and_call(x, args, ST(len));
}

HiObject* Klass::subscr(HiObject* x, HiObject* y)
{
    ObjList = new ArrayList<HiObject*>();
    args->add(y);
    return find_and_call(x, args, ST(getitem));
}

void Klass::store_subscr(HiObject* x, HiObject* y, HiObject* z)
{
    ObjList args = new ArrayList<HiObject*>();
    args->add(y);
    args->add(z);

    find_and_call(x, args, ST(setitem));
}

HiObject* Klass::get_klass_attr(HiObject* x, HiObject* y)
{
    HiObject* result = Universe::HiNone;

    result = find_in_parents(x, y);
    if (MethodObject::is_function(result)) {
        result = new MethodObject((FunctionObject*)result, x);
    }

    return result;
}

// This method should only be called in LOAD_ATTR
HiObject* Klass::getattr(HiObject* x, HiObject* y)
{
    HiObject* func = find_in_parents(x, ST(getattr));
    if (func->klass() == FunctionKlass::get_instance()) {
        func = new MethodObject((FunctionObject*)func, x);
        ObjList args = new ArrayList<HiObject*>();
        args->add(y);
        return Interpreter::get_instance()->call_virtual(func, args);
    }

    HiObject* result = Universe::HiNone;

    if (x->obj_dict() != NULL) {
        result = x->obj_dict()->get(y);

        if (result != Universe::HiNone) {
            return result;
        }
    }

    return get_klass_attr(x, y);
}

HiObject* Klass::setattr(HiObject* x, HiObject* y, HiObject* z)
{
    HiObject* func = x->klass()->klass_dict()->get(ST(setattr));

    if (func->klass() == FunctionKlass::get_instance()) {
        func = new MethodObject((FunctionObject*)func, x);
        ObjList args = new ArrayList<HiObject*>();
        args->add(y);
        args->add(z);
        return Interpreter::get_instance()->call_virtual(func, args);
    }

    if (x->obj_dict() == NULL) {
        x->init_dict();
    }

    x->obj_dict()->put(y, z);
    return Universe::HiNone;
}

void Klass::add_super(Klass* klass)
{
    if (_super == NULL) {
        _super = new HiList();
    }

    _super->append(klass->type_object());
}

HiTypeObject* Klass::super()
{
    if (_super == NULL) {
        return NULL;
    }

    if (_super->size() <= 0) {
        return NULL;
    }

    return (HiTypeObject*)_super->get(0);
}

Klass::Klass() 
{
    Universe::klasses->add(this);
    _klass_dict = NULL;
    _name = NULL;
    _super = NULL;
    _mro   = NULL;
}

void Klass::order_supers()
{
    if (_super == NULL) {
        return;
    }

    if (_mro == NULL) {
        _mro = new HiList();
    }

    int cur = -1;
    for (int i = 0; i < _super->size(); i++) {
        HiTypeObject* tp_obj = (HiTypeObject*)(_super->get(i));
        Klass* k = tp_obj->own_klass();
        _mro->append(tp_obj);
        if (k->mro() == NULL) {
            continue;
        }

        for (int j = 0; j < k->mro()->size(); j++) {
            HiTypeObject* tp_obj = (HiTypeObject*)(k->mro()->get(j));
            int index = _mro->index(tp_obj);
            if (index < cur) {
                printf("Error: method resolution order conflicts.\n");
                assert(false);
            }
            cur = index;

            if (index >= 0) {
                _mro->delete_index(index);
            }

            _mro->append(tp_obj);
        }
    }

    if (_mro == NULL) {
        return;
    }

    printf("%s's mro is ", _name->value());
    for (int i = 0; i < _mro->size(); i++) {
        HiTypeObject* tp_obj = (HiTypeObject*)(_mro->get(i));
        Klass* k = tp_obj->own_klass();
        printf("%s, ", k->name()->value());
    }
    printf("\n");
}

HiObject* Klass::find_in_parents(HiObject* x, HiObject* y)
{
    HiObject* result = Universe::HiNone;
    result = x->klass()->klass_dict()->get(y);

    if (result != Universe::HiNone) {
        return result;
    }

    // find attribute in all parents.
    if (x->klass()->mro() == NULL) {
        return result;
    }

    for (int i = 0; i < x->klass()->mro()->size(); i++) {
        result = ((HiTypeObject*)(x->klass()->mro()->get(i)))->own_klass()->klass_dict()->get(y);

        if (result != Universe::HiNone) {
            break;
        }
    }

    return result;
}

void* Klass::operator new(size_t size)
{
    return Universe::heap->allocate_meta(size);
}

// this function will visit all children
void Klass::oops_do(OopClosure* closure, HiObject* obj)
{
    printf("warning: klass oops_do for ");
    _name->print();
    printf("\n");
}

void Klass::oops_do(OopClosure* f) 
{
    f->do_oop((HiObject**)&_super);
    f->do_oop((HiObject**)&_mro);
    f->do_oop((HiObject**)&_name);
    f->do_oop((HiObject**)&_klass_dict);
    f->do_oop((HiObject**)&_type_object);
}

size_t Klass::size()
{
    return sizeof(HiObject);
}

HiObject* Klass::iter(HiObject* x)
{
    return find_and_call(x, NULL, ST(iter));
}

HiObject* Klass::next(HiObject* x)
{
    return find_and_call(x, NULL, ST(next));
}