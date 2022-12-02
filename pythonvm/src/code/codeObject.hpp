#ifndef CODE_OBJECT_HPP
#define CODE_OBJECT_HPP

#include "object/hiObject.hpp"

class HiString;

template<typename T>
class ArrayList;

class CodeKlass: public Klass
{
    private:
        CodeKlass();
        static CodeKlass* instance;

    public:
        static CodeKlass* get_instance();

        virtual void oops_do(OopClosure* closure, HiObject* obj);
        virtual size_t size();
};

/**
 * @brief 静态代码片段
 * 
 */
class CodeObject: public HiObject
{
    public:
        int _argcount; // 参数个数
        int _nlocals; // 局部变量个数
        int _stack_size; // 操作数栈
        int _flag; // 字节码

        HiString* _bytecodes; // 字节码
        ArrayList<HiObject*>* _names; // 变量表
        ArrayList<HiObject*>* _consts; // 常量表
        ArrayList<HiObject*>* _var_names;

        ArrayList<HiObject*>* _free_vars; // 用于构建闭包
        ArrayList<HiObject*>* _cell_vars; // 用于构建闭包

        HiString* _co_name; // 模块名
        HiString* _file_name; // 文件名称

        int _lineno; // 行号
        HiString* _notable;

        CodeObject(int argcount, int nlocals, int stacksize, int flag, HiString* bytecodes,
            ArrayList<HiObject*>* consts, ArrayList<HiObject*>* names, 
            ArrayList<HiObject*>* varnames, 
            ArrayList<HiObject*>* freevars, ArrayList<HiObject*>* cellvars,
            HiString* file_name, HiString* co_name, int lineno, HiString* notable);
};

#endif