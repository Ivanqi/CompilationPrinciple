#ifndef BYTE_CODE_HPP
#define BYTE_CODE_HPP

/**
 * @brief 字节码内存说明
 *  1. 不带参数的字节码只有操作码，所有它的大小就是1个字节
 *  2. 带参数的字节码，最大也只能带一个参数，而每个参数占2个字节，整体3个字节
 * 
 */

class ByteCode
{
    public:
        // Define org.railgun.vm.Bytecode Operator Code
        static const unsigned char POP_TOP = 1;
        static const unsigned char ROT_TWO = 2;
        static const unsigned char ROT_THREE = 3;
        static const unsigned char DUP_TOP = 4;
        static const unsigned char UNARY_NEGATIVE = 11;
        static const unsigned char BINARY_MULTIPLY = 20;
        static const unsigned char BINARY_MODULO = 22;
        static const unsigned char BINARY_SUBSCR = 25;
        static const unsigned char BINARY_DIVIDE = 21;
        static const unsigned char BINARY_ADD = 23; // 把操作数栈上的前两项出栈，求出它们的和并且再放入栈中
        static const unsigned char BINARY_SUBTRACT = 24;

        static const unsigned char INPLACE_ADD = 55;
        static const unsigned char STORE_MAP = 54;
        static const unsigned char INPLACE_SUBSTRACT = 56;
        static const unsigned char INPLACE_MULTIPLY = 57;
        static const unsigned char INPLACE_DIVIDE = 58;
        static const unsigned char INPLACE_MODULO = 59;
        static const unsigned char STORE_SUBSCR = 60;
        static const unsigned char DELETE_SUBSCR = 61;

        static const unsigned char GET_ITER = 68;

        // 用于打印栈顶元素和换行符
        static const unsigned char PRINT_ITEM = 71; // 栈顶元素出栈，并将其输出
        static const unsigned char PRINT_NEWLINE = 72; // 输出换行符

        static const unsigned char BREAK_LOOP = 80; //  从循环中退出
        static const unsigned char LOAD_LOCALS = 82; // 将局部变量表作为一个对象加载到栈顶
        static const unsigned char RETURN_VALUE = 83; // 将栈顶元素作为返回值返回给函数的调用者
        static const unsigned char YIELD_VALUE = 86;
        static const unsigned char POP_BLOCK = 87; // 将BlockStack的栈顶元素出栈
        static const unsigned char END_FINALLY = 88;
        static const unsigned char BUILD_CLASS = 89;

        // TODO: This is a separator
        static const unsigned char HAVE_ARGUMENT = 90; /* 有参数。Opcodes from here have an argument: */

        static const unsigned char STORE_NAME = 90; // 将栈顶元素出栈，并赋值给参数所代表的变量
        static const unsigned char UNPACK_SEQUENCE = 92;
        static const unsigned char FOR_ITER = 93;
        static const unsigned char STORE_ATTR = 95; // 为对象设置属性，参数代表属性在names表中序号，而对象和值则从栈上获取
        static const unsigned char STORE_GLOBAL = 97; // 将栈顶元素出栈，并赋值给参数所代表的全局变量
        static const unsigned char DUP_TOPX = 99;   /* number of items to duplicate */
        static const unsigned char LOAD_CONST = 100; // 将参数所代表的变量加载到栈顶
        static const unsigned char LOAD_NAME = 101; // 将参数所代表的变量加载到栈顶
        static const unsigned char BUILD_TUPLE = 102;
        static const unsigned char BUILD_LIST = 103;
        static const unsigned char BUILD_MAP = 105;
        static const unsigned char LOAD_ATTR = 106; // 为对象设置属性，参数代表属性在names表中序号，而对象和值则从栈上获取
        static const unsigned char COMPARE_OP = 107; /* 条件判断，带参数(>|<).Comparison operator */
        static const unsigned char IMPORT_NAME = 108; /*  */
        static const unsigned char IMPORT_FROM = 109; /* Index in name list */
        static const unsigned char JUMP_FORWARD = 110; // 向前跳转，参数代表目标相对于当前位置的偏移
        static const unsigned char JUMP_IF_FALSE_OR_POP = 111; /* Target byte offset from beginning of code */

        static const unsigned char JUMP_ABSOLUTE = 113; // 绝对跳转，参数代表跳转目标的绝对地址
        static const unsigned char POP_JUMP_IF_FALSE = 114; // 将栈顶元素出栈，并判断是否为False，如果是则跳转
        static const unsigned char POP_JUMP_IF_TRUE = 115;
        static const unsigned char LOAD_GLOBAL = 116; /* Index in name list */

        static const unsigned char CONTINUE_LOOP = 119; /* Start of loop (absolute) */
        static const unsigned char SETUP_LOOP = 120; // 新建一个loopblock
        static const unsigned char SETUP_EXCEPT = 121;  /* "" */
        static const unsigned char SETUP_FINALLY = 122; /* "" */

        static const unsigned char LOAD_FAST  = 124; /* Local variable number */
        static const unsigned char STORE_FAST = 125; /* Local variable number */

        static const unsigned char RAISE_VARARGS = 130;
        static const unsigned char CALL_FUNCTION = 131; // 调用一个函数，函数调用的参数使用栈传递。字节码参数代表函数参数的个数
        static const unsigned char MAKE_FUNCTION = 132; // 创建一个函数对象，函数调用的参数使用栈传递。字节码参数代表函数参数的个数

        static const unsigned char MAKE_CLOSURE = 134; /* #free vars */
        static const unsigned char LOAD_CLOSURE = 135; /* Load free variable from closure */
        static const unsigned char LOAD_DEREF = 136; /* Load and dereference from closure cell */
        static const unsigned char STORE_DEREF = 137; /* Store into cell */

        static const unsigned char CALL_FUNCTION_VAR = 140;
        
        enum COMPARE {
            LESS = 0,       // 小于
            LESS_EQUAL,     // 小于等于
            EQUAL,          // 等于
            NOT_EQUAL,      // 不等于
            GREATER,        // 大于
            GREATER_EQUAL,  // 大于等于
            IN,
            NOT_IN,
            IS,
            IS_NOT,
            EXC_MATCH
        };

};

#endif