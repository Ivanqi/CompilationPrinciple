#ifndef FRAME_OBJECT_HPP
#define FRAME_OBJECT_HPP

#include "code/codeObject.hpp"
#include "util/map.hpp"
#include "util/arrayList.hpp"

class FunctionObject;
class HiList;

class Block
{
    public:
        unsigned char _type;
        unsigned int _target;
        int _level;

        Block()
        {
            _type = 0;
            _target = 0;
            _level = 0;
        }

        /**
         * @brief Construct a new Block object
         * 
         * @param b_type 字节码
         * @param b_target pc指针
         * @param b_level 操作栈深度
         */
        Block(unsigned char b_type, unsigned int b_target, int b_level)
            : _type(b_type), 
            _target(b_target), 
            _level(b_level)
        {

        }

        Block(const Block& b)
        {
            _type = b._type;
            _target = b._target;
            _level = b._level;
        }
};

/**
 * @brief 活动记录
 *  1. 每一次调用一个函数，便有一个这次调用的活动记录(FrameObject)被创建，每次函数执行结束，它所对应的活动记录也会被销毁
 * 
 */
class FrameObject
{
    public:
        FrameObject(CodeObject* codes);
        FrameObject(FunctionObject* func, ObjList args, int op_arg);
        ~FrameObject();

        HiList* _stack; // 栈帧
        ArrayList<Block*>* _loop_stack; // loopblock

        ArrayList<HiObject*>* _consts;  // 常量表
        ArrayList<HiObject*>* _names; // 变量表

        HiDict* _locals; // 局部变量
        HiDict* _globals; // 全局变量
        HiList* _fast_locals; // 参数列表
        HiList* _closure; // 闭包

        CodeObject* _codes; // codeObject 对象
        FrameObject* _sender; // 这个域里会记录调用中的栈帧，当函数执行结束时，就会通过这个域返回到调用者的栈帧里
        int _pc; // 字节码计算器(程序计数器)
        bool _entry_frame;
    
    public:
        void set_sender(FrameObject* x)
        {
            _sender = x;
        }

        FrameObject* sender()
        {
            return _sender;
        }

        void set_pc(int x)
        {
            _pc = x;
        }

        int get_pc()
        {
            return _pc;
        }

        void set_entry_frame(bool x)
        {
            _entry_frame = x;
        }

        bool is_entry_frame()
        {
            return _entry_frame;
        }

        bool is_first_frame()
        {
            return _sender == NULL;
        }

        HiList* stack()
        {
            return _stack;
        }

        ArrayList<Block*>* loop_stack()
        {
            return _loop_stack;
        }

        ArrayList<HiObject*>* consts()
        {
            return _consts;
        }

        ArrayList<HiObject*>* names()
        {
            return _names;
        }

        HiDict* locals()
        {
            return _locals;
        }

        HiDict* globals()
        {
            return _globals;
        }

        HiList* fast_locals()
        {
            return _fast_locals;
        }

        HiList* closure()
        {
            return _closure;
        }

        HiObject* get_cell_from_paramter(int i);

        HiString* file_name();
        HiString* func_name();

        bool has_more_codes();
        unsigned char get_op_code();
        int get_op_arg();

        void oops_do(OopClosure* f);
};

#endif