#include "code/codeObject.hpp"
#include "object/hiString.hpp"
#include "memory/heap.hpp"
#include "memory/oopClosure.hpp"

CodeKlass* CodeKlass::instance = NULL;

CodeKlass* CodeKlass::get_instance()
{
    if (instance == NULL) {
        instance = new CodeKlass();
    }

    return instance;
}

CodeKlass::CodeKlass()
{
    set_name(new HiString("code"));
    add_super(ObjectKlass::get_instance());
    HiTypeObject* dict_type_obj = new HiTypeObject();
    set_type_object(dict_type_obj);
}

void CodeKlass::oops_do(OopClosure* f, HiObject* obj)
{
    CodeObject* co = (CodeObject*) obj;
    assert(co && co->klass() == (Klass*)this);

    f->do_oop((HiObject**)&co->_bytecodes);
    f->do_array_list(&co->_names);
    f->do_array_list(&co->_consts);
    f->do_array_list(&co->_var_names);
    f->do_array_list(&co->_free_vars);
    f->do_array_list(&co->_cell_vars);
    f->do_oop((HiObject**)&co->_co_name);
    f->do_oop((HiObject**)&co->_file_name);
    f->do_oop((HiObject**)&co->_notable);
}

size_t CodeKlass::size()
{
    return sizeof(CodeObject);
}

/**
 * @brief Code Object object
 * 
 * @param argcount  参数个数
 * @param nlocals 局部变量个数
 * @param stacksize 操作数栈
 * @param flag code属性值
 * @param bytecodes 字节码
 * @param consts 常量表
 * @param names 变量表
 * @param varnames 
 * @param freevars 用于构建闭包
 * @param cellvars 用于构建闭包
 * @param file_name 文件名称
 * @param co_name 模块名
 * @param lineno 行号
 * @param notable 
 */
CodeObject::CodeObject(int argcount, int nlocals, int stacksize, int flag, HiString* bytecodes,
    ArrayList<HiObject*>* consts, ArrayList<HiObject*>* names, ArrayList<HiObject*>* varnames, 
    ArrayList<HiObject*>* freevars, ArrayList<HiObject*>* cellvars,
    HiString* file_name, HiString* co_name, int lineno, HiString* notable):
        _argcount(argcount), 
        _nlocals(nlocals), 
        _stack_size(stacksize),
        _flag(flag), 
        _bytecodes(bytecodes), 
        _names(names),
        _consts(consts), 
        _var_names(varnames),
        _free_vars(freevars),
        _cell_vars(cellvars), 
        _co_name(co_name), 
        _file_name(file_name),
        _lineno(lineno), 
        _notable(notable)
{
    set_klass(CodeKlass::get_instance());
}