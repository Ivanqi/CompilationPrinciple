#include "runtime/interpreter.hpp"
#include "runtime/frameObject.hpp"
#include "runtime/universe.hpp"
#include "runtime/functionObject.hpp"
#include "runtime/stringTable.hpp"
#include "runtime/module.hpp"
#include "runtime/traceback.hpp"
#include "runtime/generator.hpp"
#include "runtime/cellObject.hpp"
#include "util/arrayList.hpp"
#include "util/map.hpp"
#include "util/handles.hpp"
#include "object/hiString.hpp"
#include "object/hiInteger.hpp"
#include "object/hiList.hpp"
#include "object/hiDict.hpp"
#include "memory/oopClosure.hpp"

#include <string.h>

#define PUSH(x) _frame->stack()->append((x))
#define POP() _frame->stack()->pop()
#define TOP() _frame->stack()->top()
#define STACK_LEVEL() _frame->stack()->size()
#define PEEK(x) _frame->stack()->get((x))
#define EMPTY() (_frame->stack()->size() == 0)

#define HI_TRUE Universe::HiTrue
#define HI_FALSE Universe::HiFalse

#define ST(x) StringTable::get_instance()->STR(x)
#define STR(x) x##_str

Interpreter* Interpreter::_instance = NULL;

Interpreter* Interpreter::get_instance()
{
    if (_instance == NULL) {
        _instance = new Interpreter();
    }

    return _instance;
}

Interpreter::Interpreter()
{
    _frame = NULL;
    _exception_class = NULL;
    _pending_exception = NULL;
    _trace_back = NULL;
    _int_status = IS_OK;

    // prepare for import builtin, this should be created first
    _builtins = new ModuleObject(new HiDict());
    _builtins->put(new HiString("object"), ObjectKlass::get_instance()->type_object());
    _builtins->put(new HiString("True"), Universe::HiTrue);
    _builtins->put(new HiString("False"), Universe::HiFalse);
    _builtins->put(new HiString("None"), Universe::HiNone);

    _builtins->put(new HiString("len"), new FunctionObject(len));
    _builtins->put(new HiString("iter"), new FunctionObject(iter));
    _builtins->put(new HiString("type"), new FunctionObject(type_of));
    _builtins->put(new HiString("isinstance"), new FunctionObject(isinstance));
    _builtins->put(new HiString("super"), new FunctionObject(builtin_super));
    _builtins->put(new HiString("sysgc"), new FunctionObject(sysgc));

    _builtins->put(new HiString("int"), IntegerKlass::get_instance()->type_object());
    _builtins->put(new HiString("object"), ObjectKlass::get_instance()->type_object());
    _builtins->put(new HiString("str"), StringKlass::get_instance()->type_object());
    _builtins->put(new HiString("list"), ListKlass::get_instance()->type_object());
    _builtins->put(new HiString("dict"), DictKlass::get_instance()->type_object());
}

void Interpreter::initialize()
{
    _builtins->extend(ModuleObject::import_module(new HiString("builtin")));
    Universe::stop_iteration = _builtins->get(new HiString("StopIteration"));

    _modules = new HiDict();
    _modules->put(new HiString("__builtins__"), _builtins);
}

/**
 * @brief 栈帧创建
 * 
 * @param callable 
 * @param args 
 * @param op_arg 
 */
void Interpreter::build_frame(HiObject* callable, ObjList args, int op_arg)
{
    if (callable->klass() == NativeFunctionKlass::get_instance()) { // 内建函数
        PUSH(((FunctionObject*)callable)->call(args));
    } else if (callable->klass() == MethodKlass::get_instance()) { // 方法创建
        MethodObject* method = (MethodObject*) callable;
        // return value is ignored here, because they are handled
        // by other pathes.
        if (!args) {
            args = new ArrayList<HiObject*>(1);
        }

        args->insert(0, method->owner());
        build_frame(method->func(), args, op_arg + 1);
    } else if (MethodObject::is_yield_function(callable)) {
        Generator* gtor = new Generator((FunctionObject*) callable, args, op_arg);
        PUSH(gtor);
        return;
    } else if (callable->klass() == FunctionKlass::get_instance()) { // 函数创建
        // 函数的创建，新增活动记录。当活动记录执行完成后，然后返回保存的栈帧
        FrameObject* frame = new FrameObject((FunctionObject*) callable, args, op_arg);
        frame->set_sender(_frame);
        _frame = frame; 
    } else if (callable->klass() == TypeKlass::get_instance()) {
        HiObject* inst = ((HiTypeObject*)callable)->own_klass()->allocate_instance(callable, args); 
        PUSH(inst);
    } else {
        HiObject* m = callable->get_klass_attr(ST(call));
        if (m != Universe::HiNone) {
            build_frame(m, args, op_arg);
        } else {
            callable->print();
            printf("\nError : can not call a normal object.\n");
        }
    }
}

/**
 * @brief 将调用者的frameObject销毁
 * 
 */
void Interpreter::leave_frame()
{
    destroy_frame();
    // 把返回结果push到栈中
    PUSH(_ret_value);
}

/**
 * @brief 销毁FrameObject
 *  1. 把栈帧设置成之前存储的
 *  2. 并删除FrameObject
 */
void Interpreter::destroy_frame()
{
    FrameObject* temp = _frame;
    _frame = _frame->sender();

    delete temp;
}

HiObject* Interpreter::call_virtual(HiObject* func, ObjList args)
{
    if (func->klass() == NativeFunctionKlass::get_instance()) {
        // we do not create a virtual frame, but native frame.
        return ((FunctionObject*)func)->call(args);
    } else if (func->klass() == MethodKlass::get_instance()) {
        MethodObject* method = (MethodObject*) func;
        if (!args) {
            args = new ArrayList<HiObject*>(1);
        }
        args->insert(0, method->owner());
        return call_virtual(method->func(), args);
    } else if (MethodObject::is_function(func)) {
        int size = args ? args->size() : 0;
        FrameObject* frame = new FrameObject((FunctionObject*) func, args, size);
        frame->set_entry_frame(true);
        enter_frame(frame);
        eval_frame();
        destroy_frame();
        return _ret_value;
    }

    return Universe::HiNone;
}

void Interpreter::enter_frame(FrameObject* frame)
{
    frame->set_sender(_frame);
    _frame         = frame;
}

/**
 * @brief 栈执行
 *  1. 让逐个字节地取出字节码并且执行
 * 
 * @param codes 
 */
void Interpreter::run(CodeObject* codes)
{
    _frame = new FrameObject(codes);
    _frame->locals()->put(ST(name), new HiString("__main__"));
    eval_frame();

    if (_int_status == IS_EXCEPTION) {
        _int_status = IS_OK;

        _trace_back->print();
        _pending_exception->print();
        printf("\n");

        _trace_back = NULL;
        _pending_exception = NULL;
        _exception_class = NULL;
    }

    destroy_frame();
}

HiDict* Interpreter::run_mod(CodeObject* codes, HiString* mod_name)
{
    FrameObject* frame = new FrameObject(codes);
    frame->set_entry_frame(true);
    frame->locals()->put(ST(name), mod_name);

    enter_frame(frame);
    eval_frame();
    HiDict* result = frame->locals();
    destroy_frame();
    return result;
}

void Interpreter::eval_frame()
{
    Block* b;
    FunctionObject* fo;
    ArrayList<HiObject*>* args = NULL;
    HiObject *v, *w, *u;
    unsigned char op_code;
    bool has_argument;
    int op_arg;

    while (_frame->has_more_codes()) {
        if (_int_status != IS_OK) {
            goto fast_handle_exception;
        }

        op_code = _frame->get_op_code();
        has_argument = (op_code & 0xFF) >= ByteCode::HAVE_ARGUMENT;

        op_arg = -1;
        // 检测是否有参数
        if (has_argument) {
            op_arg = _frame->get_op_arg();
        }

        // 大循环。不断取出字节码，并且通过一个巨大的switch case语句
        switch (op_code) {
            case ByteCode::POP_TOP: // 弹出一个
                POP();
                break;

            case ByteCode::ROT_TWO:
                v = POP();
                w = POP();
                PUSH(v);
                PUSH(w);
                break;

            case ByteCode::ROT_THREE:
                v = POP();
                w = POP();
                u = POP();
                PUSH(v);
                PUSH(u);
                PUSH(w);
                break;

            case ByteCode::DUP_TOP:
                PUSH(TOP());
                break;

            case ByteCode::LOAD_CONST: // 读取常量
                PUSH(_frame->consts()->get(op_arg));
                break;

            case ByteCode::LOAD_NAME:
                // 变量的查询，先查找局部变量表
                v = _frame->names()->get(op_arg);
                w = _frame->locals()->get(v);
                if (w != Universe::HiNone) {
                    PUSH(w);
                    break;
                }

                // 如果发现局部变量表里找不到，则从全局变量表中查
                w = _frame->globals()->get(v);
                if (w != Universe::HiNone) {
                    PUSH(w);
                    break;
                }

                // 如果全部变量表找不到，从内建表中查找
                w = _builtins->get(v);
                if (w != Universe::HiNone) {
                    PUSH(w);
                    break;
                }

                PUSH(Universe::HiNone);
                break;

            case ByteCode::LOAD_FAST:
                PUSH(_frame->fast_locals()->get(op_arg));
                break;

            case ByteCode::LOAD_GLOBAL:
                v = _frame->names()->get(op_arg);
                w = _frame->globals()->get(v);
                if (w != Universe::HiNone) {
                    PUSH(w);
                    break;
                }

                w = _builtins->get(v);
                if (w != Universe::HiNone) {
                    PUSH(w);
                    break;
                }

                PUSH(Universe::HiNone);
                break;

            case ByteCode::LOAD_ATTR:
                v = POP();
                w = _frame->_names->get(op_arg);
                PUSH(v->getattr(w));
                break;

            case ByteCode::LOAD_LOCALS:
                PUSH(_frame->_locals);
                break;

            case ByteCode::LOAD_CLOSURE:
                v = _frame->closure()->get(op_arg);
                if (v == NULL) {
                    _frame->closure()->set(op_arg, (_frame->get_cell_from_parameter(op_arg)));
                }

                v = _frame->closure()->get(op_arg);
                if (v->klass() == CellKlass::get_instance()) {
                    PUSH(v);
                } else {
                    PUSH(new CellObject(_frame->closure(), op_arg));
                }

                break;

            case ByteCode::LOAD_DEREF:
                v = _frame->closure()->get(op_arg);
                if (v->klass() == CellKlass::get_instance()) {
                    v = ((CellObject*)v)->value();
                }
                PUSH(v);
                break;

            case ByteCode::STORE_NAME:
                v = _frame->names()->get(op_arg);
                _frame->locals()->put(v, POP());
                break;

            case ByteCode::STORE_FAST:
                _frame->_fast_locals->set(op_arg, POP());
                break;

            case ByteCode::STORE_GLOBAL:
                v = _frame->names()->get(op_arg);
                _frame->globals()->put(v, POP());
                break;

            case ByteCode::STORE_SUBSCR:
                u = POP();
                v = POP();
                w = POP();
                v->store_subscr(u, w);
                break;

            case ByteCode::STORE_MAP:
                w = POP();
                u = POP();
                v = TOP();
                ((HiDict*)v)->put(w, u);
                break;

            case ByteCode::STORE_ATTR:
                u = POP();
                v = _frame->_names->get(op_arg);
                w = POP();
                u->setattr(v, w);
                break;

            case ByteCode::STORE_DEREF:
                _frame->closure()->set(op_arg, POP());
                break;

            case ByteCode::BINARY_SUBSCR:
                v = POP();
                w = POP();
                PUSH(w->subscr(v));
                break;

            case ByteCode::PRINT_ITEM:
                v = POP();
                v->print();
                break;

            case ByteCode::PRINT_NEWLINE:
                printf("\n");
                break;

            case ByteCode::INPLACE_DIVIDE:
            case ByteCode::BINARY_DIVIDE:
                v = POP();
                w = POP();
                PUSH(w->div(v));
                break;

            case ByteCode::INPLACE_ADD:
            case ByteCode::BINARY_ADD:
                v = POP();
                w = POP();
                PUSH(w->add(v));
                break;

            case ByteCode::BINARY_SUBTRACT:
                v = POP();
                w = POP();
                PUSH(w->sub(v));
                break;

            case ByteCode::BINARY_MULTIPLY:
                v = POP();
                w = POP();
                PUSH(w->mul(v));
                break;

            case ByteCode::INPLACE_MODULO: // drop down
            case ByteCode::BINARY_MODULO:
                v = POP();
                w = POP();
                PUSH(w->mod(v));
                break;

            case ByteCode::MAKE_CLOSURE:
                v = POP();
                fo = new FunctionObject(v);
                fo->set_closure((HiList*)(POP()));
                fo->set_globals(_frame->globals());
                if (op_arg > 0) {
                    args = new ArrayList<HiObject*>(op_arg);
                    while (op_arg--) {
                        args->set(op_arg, POP());
                    }
                }

                fo->set_default(args);

                if (args != NULL) {
                    args = NULL;
                }

                PUSH(fo);
                break;

            case ByteCode::MAKE_FUNCTION:
                v = POP();
                fo = new FunctionObject(v);
                fo->set_globals(_frame->globals());
                if (op_arg > 0) {
                    args = new ArrayList<HiObject*>(op_arg);
                    while (op_arg--) {
                        args->set(op_arg, POP());
                    }
                }

                fo->set_default(args);

                if (args != NULL) {
                    args = NULL;
                }

                PUSH(fo);
                break;

            case ByteCode::CALL_FUNCTION:
                if (op_arg > 0) {
                    int na = op_arg & 0xff;
                    int nk = op_arg >> 8;
                    int arg_cnt = na + 2 * nk;
                    args = new ArrayList<HiObject*>(arg_cnt);
                    while (arg_cnt--) {
                        args->set(arg_cnt, POP());
                    }
                }

                build_frame(POP(), args, op_arg);

                if (args != NULL) {
                    args = NULL;
                }
                break;

            case ByteCode::RETURN_VALUE:
                _ret_value = POP();
                _int_status = IS_RETURN;
                break;

            // 用于比较
            case ByteCode::COMPARE_OP:
                w = POP();
                v = POP();

                switch(op_arg) {
                    case ByteCode::GREATER:
                        PUSH(v->greater(w));
                        break;

                    case ByteCode::LESS:
                        PUSH(v->less(w));
                        break;

                    case ByteCode::EQUAL:
                        PUSH(v->equal(w));
                        break;

                    case ByteCode::NOT_EQUAL:
                        PUSH(v->not_equal(w));
                        break;

                    case ByteCode::GREATER_EQUAL:
                        PUSH(v->ge(w));
                        break;
                
                    case ByteCode::LESS_EQUAL: 
                        PUSH(v->le(w));
                        break;

                    case ByteCode::IN:
                        PUSH(w->contains(v));
                        break;

                    case ByteCode::IS:
                        if (v == w)
                            PUSH(HI_TRUE);
                        else
                            PUSH(HI_FALSE);
                        break;

                    case ByteCode::IS_NOT:
                        if (v == w)
                            PUSH(HI_TRUE);
                        else
                            PUSH(HI_FALSE);
                        break;

                    case ByteCode::EXC_MATCH:
                    {
                        bool found = false;
                        Klass* k = ((HiTypeObject*)v)->own_klass();

                        if (v == w) {
                            found = true;
                        } else {
                            for (int i = 0; i < k->mro()->size(); i++) {
                                if (v->klass()->mro()->get(i) == w) {
                                    found = true;
                                    break;
                                }
                            }
                        }

                        if (found) {
                            PUSH(Universe::HiTrue);
                        } else {
                            PUSH(Universe::HiFalse);
                        }

                        break;
                    }

                    default:
                        printf("Error: Unrecognized compare op %d\n", op_arg);

                }
                break;

            case ByteCode::DELETE_SUBSCR:
                w = POP();
                v = POP();
                v->del_subscr(w);
                break;

            case ByteCode::POP_JUMP_IF_FALSE:
                v = POP();
                if (v == Universe::HiFalse)
                    _frame->set_pc(op_arg);
                break;

            case ByteCode::JUMP_FORWARD:
                _frame->set_pc(op_arg + _frame->get_pc());
                break;

            case ByteCode::JUMP_ABSOLUTE:
                _frame->set_pc(op_arg);
                break;

            case ByteCode::SETUP_FINALLY:
            case ByteCode::SETUP_EXCEPT:
            case ByteCode::SETUP_LOOP:
                // 设置一个loopblock。
                _frame->loop_stack()->add(new Block(op_code, _frame->get_pc() + op_arg, STACK_LEVEL()));
                break;

            case ByteCode::POP_BLOCK:
                b = _frame->loop_stack()->pop();
                // 通过当前栈和之前栈的深度比较，并弹出栈
                while (STACK_LEVEL() > b->_level) {
                    POP();
                }
                break;

            case ByteCode::BREAK_LOOP:
                _int_status = IS_BREAK;
                break;

            case ByteCode::CONTINUE_LOOP:
                _int_status = IS_CONTINUE;
                _ret_value = (HiObject*)((long)op_arg);
                break;

            case ByteCode::END_FINALLY:
                // TODO: restore exceptions
                v = POP();
                if (((long)v) & 0x1) {
                    _int_status = (Status)(((long)v) >> 1);
                    if (_int_status == IS_RETURN) {
                        _ret_value = POP();
                    } else if (_int_status == IS_CONTINUE) {
                        _frame->_pc = (int)((long)(POP()));
                    }
                } else if (v != Universe::HiNone) {
                    _exception_class = v;
                    _pending_exception = POP();
                    _trace_back = POP();
                    _int_status = IS_EXCEPTION;
                }
                break;

            case ByteCode::BUILD_TUPLE: // drop down, we need this
            case ByteCode::BUILD_LIST:
                v = new HiList();
                while (op_arg--) {
                    ((HiList*)v)->set(op_arg, POP());
                }
                PUSH(v);
                break;

            case ByteCode::BUILD_MAP:
                v = new HiDict();
                PUSH(v);
                break;

            case ByteCode::BUILD_CLASS:
                v = POP();
                u = POP();
                w = POP();
                v = Klass::create_klass(v, u, w);
                PUSH(v);
                break;

            case ByteCode::GET_ITER:
                v = POP();
                PUSH(v->iter());
                break;

            case ByteCode::FOR_ITER:
                v = TOP();
                w = v->next();

                if (w == NULL) {
                    // we may encounter a StopIteration, ignore it.
                    //assert(_int_status == IS_EXCEPTION && _pending_exception != NULL);
                    _frame->_pc += op_arg;
                    _int_status = IS_OK;
                    _pending_exception = NULL;
                } else {
                    PUSH(w);
                }
                break;

            case ByteCode::UNPACK_SEQUENCE:
                v = POP();

                while (op_arg--) {
                    PUSH(v->subscr(new HiInteger(op_arg)));
                }

                break;

            case ByteCode::IMPORT_NAME:
                POP();
                POP();
                v = _frame->names()->get(op_arg);
                w = _modules->get(v);
                if (w != Universe::HiNone) {
                    PUSH(w);
                    break;
                }
                w = ModuleObject::import_module(v);
                _modules->put(v, w);
                PUSH(w);
                break;

            case ByteCode::IMPORT_FROM:
                v = _frame->names()->get(op_arg);
                w = TOP();
                u = ((ModuleObject*)w)->get(v);
                PUSH(u);
                break;

            case ByteCode::DUP_TOPX:
                for (int i = 0; i < op_arg; i++) {
                    int index = STACK_LEVEL() - op_arg;
                    PUSH(PEEK(index));
                }
                break;

            case ByteCode::CALL_FUNCTION_VAR:
                v = POP();
                if (op_arg > 0 || (v && ((HiList*)v)->size() > 0)) {
                    int na = op_arg & 0xff;
                    int nk = op_arg >> 8;
                    int arg_cnt = na + 2 * nk;
                    args = new ArrayList<HiObject*>();
                    while (arg_cnt--) {
                        args->set(arg_cnt, POP());
                    }

                    int s = ((HiList*)v)->size();
                    for (int i = 0; i < s; i++) {
                        args->add(((HiList*)v)->get(i));
                    }
                    na += s;
                    op_arg = (nk << 8) | na;
                }

                build_frame(POP(), args, op_arg);

                if (args != NULL) {
                    args = NULL;
                }
                break;

            case ByteCode::RAISE_VARARGS:
                w = v = u = NULL;
                switch (op_arg) {
                case 3:
                    u = POP();
                case 2:
                    v = POP();
                case 1:
                    w = POP();
                    break;
                }
                do_raise(w, v, u);

                break;

            case ByteCode::YIELD_VALUE:
                // we are assured that we're in the progress
                // of evalating generator.
                _int_status = IS_YIELD;
                _ret_value = TOP();
                return;

            default:
                printf("Error: Unrecognized byte code %d\n", op_code);
        }

fast_handle_exception:
        while (_int_status != IS_OK && _frame->_loop_stack->size() != 0) {
            b = _frame->_loop_stack->get(_frame->_loop_stack->size()-1);
            if (_int_status == IS_CONTINUE && b->_type == ByteCode::SETUP_LOOP) {
                _frame->_pc = (int)((long)_ret_value);
                _int_status = IS_OK;
                break;
            }

            b = _frame->_loop_stack->pop();
            while (STACK_LEVEL() > b->_level) {
                POP();
            }

            if (_int_status == IS_BREAK && b->_type == ByteCode::SETUP_LOOP) {
                _frame->_pc = b->_target;;
                _int_status = IS_OK;
            } else if (b->_type == ByteCode::SETUP_FINALLY ||  (_int_status == IS_EXCEPTION && b->_type == ByteCode::SETUP_EXCEPT)) {
                if (_int_status == IS_EXCEPTION) {
                    // traceback, value, exception class
                    PUSH(_trace_back);
                    PUSH(_pending_exception);
                    PUSH(_exception_class);

                    _trace_back = NULL;
                    _pending_exception = NULL;
                    _exception_class = NULL;
                } else {
                    if (_int_status == IS_RETURN || _int_status == IS_CONTINUE) {
                        PUSH(_ret_value);
                    }

                    PUSH((HiObject*)(((long)_int_status << 1) | 0x1));
                }
                _frame->_pc = b->_target;;
                _int_status = IS_OK;
            }
        }

        // has pending exception and no handler found, unwind stack.
        if (_int_status != IS_OK && _frame->_loop_stack->size() == 0) {
            if (_int_status == IS_EXCEPTION) {
                _ret_value = NULL;
                ((Traceback*)_trace_back)->record_frame(_frame);
            }

            if (_int_status == IS_RETURN) {
                _int_status = IS_OK;
            }

            if (_frame->is_first_frame() || _frame->is_entry_frame()) {
                return;
            }

            leave_frame();
        }
    }
}

void Interpreter::oops_do(OopClosure* f)
{
    f->do_oop((HiObject**)&_builtins);
    f->do_oop((HiObject**)&_modules);
    f->do_oop((HiObject**)&_ret_value);
    f->do_oop((HiObject**)&_exception_class);
    f->do_oop((HiObject**)&_pending_exception);
    f->do_oop((HiObject**)&_trace_back);

    if (_frame) {
        _frame->oops_do(f);
    }
}

Interpreter::Status Interpreter::do_raise(HiObject* exc, HiObject* val, HiObject* tb)
{
    assert(exc != NULL);

    _int_status = IS_EXCEPTION;

    if (tb == NULL) {
        tb = new Traceback();
    }

    if (val != NULL) {
        _exception_class = exc;
        _pending_exception = val;
        _trace_back = tb;
        return IS_EXCEPTION;
    }

    if (exc->klass() == TypeKlass::get_instance()) {
        _pending_exception = call_virtual(exc, NULL);
        _exception_class = exc;
    } else {
        _pending_exception = exc;
        _exception_class = _pending_exception->klass()->type_object();
    }

    _trace_back = tb;
    return IS_EXCEPTION;
}

HiObject* Interpreter::eval_generator(Generator* g)
{
    Handle handle(g);
    enter_frame(g->frame());
    g->frame()->set_entry_frame(true);
    eval_frame();

    if (_int_status != IS_YIELD) {
        _int_status = IS_OK;
        leave_frame();
        ((Generator*)handle())->set_frame(NULL);
        return NULL;
    }

    _int_status = IS_OK;
    _frame = _frame->sender();

    return _ret_value;
}