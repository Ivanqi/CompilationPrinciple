#ifndef COMPILATIONLOG_H
#define COMPILATIONLOG_H

#include <string>
#include "ParserRuleContext.h"
using namespace antlr4;

namespace play
{
    // 记录编译过程中产生的信息
    class CompilationLog
    {
        public:
            const static int INFO = 0;
            const static int WARNING = 1;
            const static int ERROR = 2;

            std::string message;

            int line;

            int positionInLine;

            // 相关的AST节点
            ParserRuleContext *ctx;

            // log的类型，包括信息、警告、错误。
            int type = INFO;
        
        public:
            std::string toString()
            {
                return message + " @" + std::to_string(line) + ":" + std::to_string(positionInLine);
            }
    };
}
#endif