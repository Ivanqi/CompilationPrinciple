// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>

// Unix
#include <unistd.h>
#include <fcntl.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/termios.h>
#include <sys/mman.h>

/**
 * LC-3 总共有 10 个寄存器，每个都是 16 比特。其中大部分都是通用目的寄存器，少数几 个用于特定目的
 *  8 个通用目的寄存器（R0-R7）
 *  1 个程序计数器（program counter, PC）寄存器
 *  1 个条件标志位（condition flags，COND）寄存器
 * 
 * 一个寄存器就是CPU上一个能够存储单个数据的槽(slot)。寄存器就像是CPU的“工作台”(workbench)，CPU要对一段数据进行处理，必须先将数据放到某个寄存器中
 * 但因为寄存器的数量很少，所以解决方法：首先将数据从内存加载到寄存器，然后将计算结果放到其他寄存器，最后将最终结果，再写回内存
 */
enum {
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC,
    R_COND,
    R_COUNT
};

/**
 * 条件标志位
 *  1. R_COND 寄存器存储条件标记，其中记录了最近一次计算的执行结果
 *  2. 这使得程序可以完成诸如 `if (x > 0) { ... }` 之类的逻辑条件
 * 
 * 每个CPU都有很多条件标志位表示不同的情形。LC-3只使用3个条件标记位，用来表示前一次计算结果的符号 
 */
enum {
    FL_POS = 1 << 0, /* P */
    FL_ZRO = 1 << 1, /* Z */
    FL_NEG = 1 << 2, /* N */
};

/**
 * 指令集
 *  一条指令就是一条CPU命令，它告诉CPU执行什么任务，例如将两个数相加。一条指令包含两部分:
 *      1. 操作码(opcode)：表示任务的类型
 *      2. 执行任务所需的参数
 */

// Opcodes, 操作码
enum {
    OP_BR = 0,  // branch
    OP_ADD,     // add
    OP_LD,      // load
    OP_ST,      // store
    OP_JSR,     // jump register
    OP_AND,     // bitwise and
    OP_LDR,     // load register
    OP_STR,     // store register
    OP_RTI,     // unused
    OP_NOT,     // bitwise not
    OP_LDI,     // load indirect
    OP_STI,     // store indirect
    OP_JMP,     // jump
    OP_RES,     // reserved (unused)
    OP_LEA,     // load efffective address. 加载有效地址
    OP_TRAP     // execute trap
};

// Memory Mapped Registers, 内存映射寄存器
enum {
    MR_KBSR = 0xFE00,   // keyboard status
    MR_KBDR = 0xFE02,   // keyboard data
};

// TRAR Codes
enum {
    TRAP_GETC = 0x20,   // 从键盘获取字符，而不是回显到终端上
    TRAP_OUT = 0x21,    // 输出一个字符
    TRAP_PUTS = 0x22,   // 输出一个字串
    TRAP_IN = 0x23,     // 从键盘获取字符，回显到终端
    TRAP_PUTSP = 0x24,  // 输出一个字节串
    TRAP_HALT = 0x25    // 停止程序
};

// Memory Storage

// 65536 locations
/**
 * LC-3 有65536个内存位置(16 bit 无符号整形能寻址的最大值)，每个位置可以存储一个16bit的值
 * 这意味它总共可以存储128KB数据(64K * 2Byte)
 */
uint16_t memory[UINT16_MAX];

// 寄存器存储
uint16_t reg[R_COUNT];

// Sign Extend， 符号扩展
uint16_t sign_extend(uint16_t x, int bit_count) {
    if ((x >> (bit_count - 1)) & 1) {
        x |= (0xFFFF << bit_count);
    }
    return x;
}

// Swap
uint16_t swap16(uint16_t x) {
    return (x << 8) | (x >> 8);
}

// Update Flags
void update_flags(uint16_t r) {
    if (reg[r] == 0) {
        reg[R_COND] = FL_ZRO;
    } else if (reg[r] >> 15) {  // a 1 in the left-most bit indicates negative, 最左边位的 1 表示负数
        reg[R_COND] = FL_NEG;
    } else {
        reg[R_COND] = FL_POS;
    }
}

/**
 * Read Image File
 *  1. size_t  fread(void *buffer, size_t size, size_t count, FILE * stream);
 *      1. buffer为接收数据的地址，size为一个单元的大小，count为单元个数，stream为文件流
 *      2. fread()函数每次从stream中最多读取count个单元，每个单元大小为size个字节，将读取的数据放到buffer
 *      3. 文件流的位置指针后移 size * count 字节
 *  2. 【返回值】返回实际读取的单元个数。如果小于count，则可能文件结束或读取出错
*/
void read_image_file(FILE *file) {
    // origin 告诉我们内存中放置Image的位置
    uint16_t origin;
    fread(&origin, sizeof(origin), 1, file);
    origin = swap16(origin);

    // 我们知道最大文件大小，所以我们只需要fread
    uint16_t max_read = UINT16_MAX - origin;
    uint16_t *p = memory + origin;
    size_t read = fread(p, sizeof(uint16_t), max_read, file);

    // swap to little endian
    while (read-- > 0) {
        *p = swap16(*p);
        ++p;
    }
}

// Read Image
int read_image(const char *image_path) {
    FILE *file = fopen(image_path, "rb");
    if (!file) {
        return 0;
    }

    read_image_file(file);
    fclose(file);
    return 1;
}

/**
 * CHeck Key
 *  STDIN_FILENO就是标准输入设备（一般是键盘）的文件描述符
*/
uint16_t check_key() {
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;
    return select(1, &readfds, NULL, NULL, &timeout) != 0;
}

// Memory Access
void mem_write(uint16_t address, uint16_t val) {
    memory[address] = val;
}

uint16_t mem_read(uint16_t address) {
    if (address == MR_KBSR) {
        if (check_key()) {
            memory[MR_KBSR] = (1 << 15);
            // getchar()函数的作用是从标准的输入stdin中读取字符
            memory[MR_KBDR] = getchar();
        } else {
            memory[MR_KBSR] = 0;
        }
    }
    return memory[address];
}

// Input Buffering
struct termios original_tio;

void disable_input_buffering() {
    tcgetattr(STDIN_FILENO, &original_tio);
    struct termios new_tio = original_tio;
    new_tio.c_lflag &= ~ICANON & ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
}

// 获取键盘事件
void restore_input_buffering() {
    // tcsetattr 用于获取与终端相关的参数，提供异步通讯接口
    // TCSANOW：更改立即发生
    tcsetattr(STDIN_FILENO, TCSANOW, &original_tio);
}

/* Handle Interrupt */
void handle_interrupt(int signal) {
    restore_input_buffering();
    printf("\n");
    exit(-2);
}

int running = 1;
/* Instruction C++ */
template <unsigned op>
void ins(uint16_t instr) {
    uint16_t r0, r1, r2, imm5, imm_flag;
    uint16_t pc_plus_off, base_plus_off;

    constexpr uint16_t opbit = (1 << op);
    if (0x4EEE & opbit) { r0 = (instr >> 9) & 0x7; }

    if (0x12F3 & opbit) { r1 = (instr >> 6) & 0x7; }

    if (0x0022 & opbit) {
        imm_flag = (instr >> 5) & 0x1;

        if (imm_flag) {
            imm5 = sign_extend(instr & 0x1F, 5);
        } else {
            r2 = instr & 0x7;
        }
    }

    if (0x00C0 & opbit) {   // Base + offset
        base_plus_off = reg[r1] + sign_extend(instr & 0x3F, 6);
    }

    if (0x4C0D & opbit) {
        // Indirect address
        pc_plus_off = reg[R_PC] + sign_extend(instr & 0x1FF, 9);
    }

    if (0x0001 & opbit) {
        // BR
        uint16_t cond = (instr >> 9) & 0x7;
        if (cond & reg[R_COND]) { reg[R_PC] = pc_plus_off; }
    }

    if (0x0002 & opbit) {  // ADD
        if (imm_flag) {
            reg[r0] = reg[r1] + imm5;
        } else {
            reg[r0] = reg[r1] + reg[r2];
        }
    }

    if (0x0020 & opbit) {  // AND
        if (imm_flag) {
            reg[r0] = reg[r1] & imm5;
        } else {
            reg[r0] = reg[r1] & reg[r2];
        }
    }

    if (0x0200 & opbit) { reg[r0] = ~reg[r1]; } // NOT

    if (0x1000 & opbit) { reg[R_PC] = reg[r1]; } // JMP

    if (0x0010 & opbit) {  // JSR
        uint16_t long_flag = (instr >> 11) & 1;
        reg[R_R7] = reg[R_PC];
        if (long_flag) {
            pc_plus_off = reg[R_PC] + sign_extend(instr & 0x7FF, 11);
            reg[R_PC] = pc_plus_off;
        } else {
            reg[R_PC] = reg[r1];
        }
    }

    if (0x0004 & opbit) { reg[r0] = mem_read(pc_plus_off); }            // LD

    if (0x0400 & opbit) { reg[r0] = mem_read(mem_read(pc_plus_off)); }   // LDI

    if (0x0040 & opbit) { reg[r0] = mem_read(base_plus_off); }           // LDR

    if (0x4000 & opbit) { reg[r0] = pc_plus_off; }                       // LEA

    if (0x0008 & opbit) { mem_write(pc_plus_off, reg[r0]); }             // ST

    if (0x0800 & opbit) { mem_write(mem_read(pc_plus_off), reg[r0]); }   // STI

    if (0x0080 & opbit) { mem_write(base_plus_off, reg[r0]); }           // STR

    if (0x8000 & opbit) {  // TRAP
        /* TRAP */
        switch (instr & 0xFF) {
            case TRAP_GETC:
                /* TRAP GETC */
                /* read a single ASCII char */
                reg[R_R0] = (uint16_t)getchar();
                update_flags(R_R0);

                break;

            case TRAP_OUT:
                /* TRAP OUT */
                putc((char)reg[R_R0], stdout);
                fflush(stdout);

                break;

            case TRAP_PUTS:
                /* TRAP PUTS */
                {
                    /* one char per word */
                    uint16_t* c = memory + reg[R_R0];
                    while (*c) {
                        putc((char)*c, stdout);
                        ++c;
                    }
                    fflush(stdout);
                }

                break;

            case TRAP_IN:
                /* TRAP IN */
                {
                    printf("Enter a character: ");
                    char c = getchar();
                    putc(c, stdout);
                    fflush(stdout);
                    reg[R_R0] = (uint16_t)c;
                    update_flags(R_R0);
                }

                break;

            case TRAP_PUTSP:
                /* TRAP PUTSP */
                {
                    /* one char per byte (two bytes per word)
                    here we need to swap back to
                    big endian format */
                    uint16_t* c = memory + reg[R_R0];
                    while (*c) {
                        char char1 = (*c) & 0xFF;
                        putc(char1, stdout);
                        char char2 = (*c) >> 8;
                        if (char2) putc(char2, stdout);
                        ++c;
                    }
                    fflush(stdout);
                }

                break;

             case TRAP_HALT:
                /* TRAP HALT */
                puts("HALT");
                fflush(stdout);
                running = 0;

                break;
        }
    }

    //if (0x0100 & opbit) { } // RTI
    if (0x4666 & opbit) { update_flags(r0); }

}

/* Op Table */
static void (*op_table[16])(uint16_t) = {
    ins<0>, ins<1>, ins<2>, ins<3>,
    ins<4>, ins<5>, ins<6>, ins<7>,
    NULL, ins<9>, ins<10>, ins<11>,
    ins<12>, NULL, ins<14>, ins<15>
};

int main(int argc, const char *argv[]) {

    // Load Arguments
    if (argc < 2) {
        // show usage string
        printf("lc3 [image-file1] ...\n");
        exit(2);
    }

    for (int j = 1; j < argc; ++j) {
        if (!read_image(argv[j])) {
            printf("failed to load image: %s\n", argv[j]);
            exit(1);
        }
    }

    // SetUp
    signal(SIGINT, handle_interrupt);
    disable_input_buffering();

    reg[R_COND] = FL_ZRO;

    // 设置PC的起始地址
    enum {PC_START = 0x3000};
    reg[R_PC] = PC_START;

    /**
     * @brief 执行过程
     * 1. 从 PC 寄存器指向的内存地址中加载一条指令
     * 2. 递增 PC 寄存器
     * 3. 查看指令中的 opcode 字段，判断指令类型
     * 4. 根据指令类型和指令中所带的参数执行该指令
     * 5. 跳转到步骤 1
     */
    while (running) {
        uint16_t instr = mem_read(reg[R_PC]++);
        uint16_t op = instr >> 12;
        op_table[op](instr);
    }

    // Shutdown
    restore_input_buffering();

    return 0;
}