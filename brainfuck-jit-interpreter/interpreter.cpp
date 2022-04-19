#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <exception>
#include <sys/mman.h>
#include <unistd.h>
#include <cmath>

#define ENABLE_DEBUG

constexpr size_t TAPE_SIZE = 30000;
constexpr size_t MAX_NESTING = 100;

#ifdef ENABLE_DEBUG
template<typename T>
void debugVec(std::vector<T> &vp) {
    for (auto i = vp.cbegin(); i != vp.cend(); ++i) {
        std::count << std::hex << static_cast<size_t>(*i) << std::endl;
    }
}

void debugTape(unsigned char *arr, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        std::cout << static_cast<int> (arr[i]);
    }
}

#endif

uint8_t* allocateExecMem(size_t size) {
    return static_cast<uint8_t*>(
        mmap(NULL, size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)
    );
}

class VM {
    public:
        uint8_t *mem = nullptr;
        std::vector<uint8_t> *machineCode = nullptr;
        void *stdoutBuf = nullptr;
        size_t allocatedSize = 0;
        size_t prependStaticSize = 0;
    
    public:
        VM (std::vector<uint8_t> *machineCode, size_t prependStaticSize)
            : machineCode(machineCode), prependStaticSize(prependStaticSize)
        {
            // getpagesize 取得内存分页大小
            auto pageSize = getpagesize();
            allocatedSize = static_cast<size_t>(std::ceil(machineCode->size() / static_cast<double>(pageSize)) * pageSize)
            mem = allocateExecMem(allocatedSize);
            if (mem == MAP_FAILED) {
                throw std::runtime_error("[error] can't allocate memory.")
            }

            std::memcpy(mem, machineCode->data(), machineCode->size());

            // 设置存储标准输出缓冲区的内存范围
            stdoutBuf = std::calloc(2048, sizeof(uint8_t))
        }

        void exec()
        {
            asm(R"(
                pushq %%rax
                pushq %%rbx
                pushq %%r10
                pushq %%r11
                pushq %%r12
                movq %1, %%r10
                xorq %%r11, %%r11
                lea 0x9(%%rip), %%rax
                pushq %%rax
                movq %0, %%rax
                addq %2, %%rax
                jmpq *%%q
            )":: "S" (mem), "m" (stdoutBuf), "D" (prependStaticSize));

            // 清空栈
            asm(R"(
                addq $8, %rsp
                popq %r12
                popq %r11
                popq %r10
                popq %rbx
                popq %rax
            )");
        }

        ~VM()
        {
            std::free(stdoutBuf);
            munmap(mem, allocatedSize)
        }
};

// 机器模型接口
struct BFState {
    unsigned char tape[TAPE_SIZE] = {0};
    unsigned char *ptr = nullptr;

    BFState()
    {
        ptr = tape;
    }
};

