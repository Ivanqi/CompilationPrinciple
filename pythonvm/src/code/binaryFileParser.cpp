#include <stdio.h>
#include <assert.h>

#include "code/binaryFileParser.hpp"
#include "runtime/universe.hpp"
#include "object/hiList.hpp"
#include "object/hiDouble.hpp"

BinaryFileParser::BinaryFileParser(BufferedInputStream* buf_file_stream)
{
    file_stream = buf_file_stream;
}

/**
 * @brief pyc格式解析
 * 
 * @return CodeObject* 
 */
CodeObject* BinaryFileParser::parse()
{
    int magic_number = file_stream->read_int(); // 魔数
    printf("magic number is 0x%x\n", magic_number);
    int moddate = file_stream->read_int();  // 文件创建时间
    printf("moddate is 0x%x\n", moddate);

    char object_type = file_stream->read();

    // 固定字符串c，16进制0x63
    if (object_type == 'c') {
        CodeObject* result = get_code_object();
        printf("parse OK!\n");
        return result;
    }

    return NULL;
}

/**
 * @brief 获取CodeObject
 * 
 * @return CodeObject* 
 */
CodeObject* BinaryFileParser::get_code_object()
{
    int argcount = file_stream->read_int(); // 参数个数
    int nlocals = file_stream->read_int();  // 局部变量的个数
    int stacksize = file_stream->read_int(); // 操作数栈
    int flags = file_stream->read_int(); // code的属性值
    printf("flags is 0x%x\n", flags);

    HiString* byte_codes = get_byte_codes(); // 字节码
    ArrayList<HiObject*>* consts = get_consts(); // 常量表
    ArrayList<HiObject*>* names = get_names();  // 变量表
    ArrayList<HiObject*>* var_names = get_var_names();
    ArrayList<HiObject*>* free_vars = get_free_vars(); // 用于闭包
    ArrayList<HiObject*>* cell_vars = get_cell_vars(); // 用于闭包

    HiString* file_name  = get_file_name(); // 文件名称
    HiString* module_name = get_name(); // 模块名
    int begin_line_no = file_stream->read_int(); // 开始的行号
    HiString* lnotab = get_no_table();

    return new CodeObject(argcount, nlocals, stacksize, flags, byte_codes,
        consts, names, var_names, free_vars, cell_vars, file_name, module_name,
        begin_line_no, lnotab);
}

/**
 * @brief 获取字符串
 * 
 * @return HiString* 
 */
HiString* BinaryFileParser::get_string()
{
    int length = file_stream->read_int();   // 字符串长度
    char* str_value = new char[length];

    for (int i = 0; i < length; i++) {
        str_value[i] = file_stream->read();
    }

    HiString* s = new HiString(str_value, length);
    delete[] str_value;

    return s;
}

/**
 * @brief 获取后续的字符串
 *  1. 一个字符's',代表的是一个字符串
 *  2. 一个字符't',也是一个字符串，格式与's'是完全相同的，代表当前code所属的模块
 * 
 * @return HiString* 
 */
HiString* BinaryFileParser::get_name()
{
    char ch = file_stream->read();

    if (ch == 's') {
        return get_string();
    } else if (ch == 't') {
        HiString* str = get_string();
        _string_table.add(str);
        return str;
    } else if (ch == 'R') {
        return _string_table.get(file_stream->read_int());
    }
    
    return NULL;
}

/**
 * @brief 获取文件名称
 * 
 * @return HiString* 
 */
HiString* BinaryFileParser::get_file_name()
{
    return get_name();
}

/**
 * @brief 获取字节码
 *  它是以字符s开头，接下来是一个整数，代表了这段code的字节码的长度
 * 
 * @return HiString* 
 */
HiString* BinaryFileParser::get_byte_codes()
{
    assert(file_stream->read() == 's');

    return get_string();
}

HiString* BinaryFileParser::get_no_table()
{
    char ch = file_stream->read();
    
    if (ch != 's' && ch != 't') {
        file_stream->unread();
        return NULL;
    }

    return get_string();
}

/**
 * @brief 获取常量表
 *  1. 常量表中存着程序所使用的所有常量
 *  2. 它是一个元祖，可以理解为一个列表或数组
 *  3. 这个元祖以字符'('作为开头，紧接着的是一个整数，代表元祖中的元素个数
 * 
 * @return ArrayList<HiObject*>* 
 */
ArrayList<HiObject*>* BinaryFileParser::get_consts()
{
    if (file_stream->read() == '(') {
        return get_tuple();
    }

    file_stream->unread();
    return NULL;
}

/**
 * @brief 获取变量表
 *  1. 在一个'(' 字符之后，然后就是变量表的长度
 * 
 * @return ArrayList<HiObject*>* 
 */
ArrayList<HiObject*>* BinaryFileParser::get_names()
{
    if (file_stream->read() == '(') {
        return get_tuple();
    }

    file_stream->unread();
    return NULL;
}

ArrayList<HiObject*>* BinaryFileParser::get_var_names()
{
    if (file_stream->read() == '(') {
        return get_tuple();
    }

    file_stream->unread();
    return NULL;
}

ArrayList<HiObject*>* BinaryFileParser::get_free_vars()
{
    if (file_stream->read() == '(') {
        return get_tuple();
    }

    file_stream->unread();
    return NULL;
}

ArrayList<HiObject*>* BinaryFileParser::get_cell_vars()
{
    if (file_stream->read() == '(') {
        return get_tuple();
    }

    file_stream->unread();
    return NULL;
}

/**
 * @brief 获取一个元祖(列表or数组)
 * 
 * @return ArrayList<HiObject*>* 
 */
ArrayList<HiObject*>* BinaryFileParser::get_tuple()
{
    int length = file_stream->read_int(); // 元祖个数
    HiString * str;

    ArrayList<HiObject*>* list = new ArrayList<HiObject*>(length);
    for (int i = 0; i < length; i++) {
        char obj_type = file_stream->read();

        switch (obj_type) {
            case 'c': // 得到一个codeObject，意味着codeObject可以嵌套
                printf("got a code object\n");
                list->add(get_code_object());
                break;
            case 'i': // 一个int数值
                list->add(new HiInteger(file_stream->read_int()));
                break;
            case 'g': // 一个double数值
                list->add(new HiDouble(file_stream->read_double()));
                break;
            case 'N': // 一个None
                list->add(Universe::HiNone);
                break;
            case 't': // 一个字符串
                str = get_string();
                list->add(str);
                _string_table.add(str);
                break;
            case 's': // 一个字符串
                list->add(get_string());
                break;
            case 'R':
                list->add(_string_table.get(file_stream->read_int()));
                break;
            case '(': // 一个元祖
                list->add(new HiList(get_tuple()));
                break;
            default:
                printf("parser, unrecognized type : %c\n", obj_type);
        }
    }

    return list;
}