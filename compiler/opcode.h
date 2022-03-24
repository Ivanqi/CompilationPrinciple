#ifndef OP_CODE_H
#define OP_CODE_H

#define BINARY_ADD          1   // +
#define BINARY_SUB          2   // -
#define BINARY_MUL          3   // *
#define BINARY_DIV          4   // /
#define PRINT               5   // 打印

#define OP_CODE_PARAMETER   90  // 变量
#define LOAD_CONST          90  // 读取常量
#define LOAD_NAME           91  // 读取 Name
#define STORE_NAME          92  // 存储 Name

#define JUMP                100
#define JUMP_IF_FALSE       101

#define COMPARE             105 // 比较

#define COMPARE_LT          0   // 比较 小于号

#endif