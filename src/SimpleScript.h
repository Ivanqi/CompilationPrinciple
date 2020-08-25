#include <cstring>
#include <unordered_map>

#include "SimpleLexer.h"
#include "SimpleCalculator.h"

using std::unordered_map;
using std::string;

class SimpleScript
{
    public:
        unordered_map<string, int> variables;
        bool verbose = false;
        

        /**
         * 遍历AST, 计算值
         * @param node
         * @param indent
         */
        int evaluate(ASTNode *node, string indent);

        void REPL(int argc, char* argv[]);
    
    private:
        string& trim(string &s)
        {
            if (s.empty()) {
                return s;
            }

            s.erase(0, s.find_last_not_of(" "));
            s.erase(s.find_last_not_of(" ") + 1);
            return s;
        }

        // 此方法测试字符串是否以指定的后缀 suffix 结束
        bool endsWith(string str, string suffix)
        {
            if (str.empty() || suffix.empty()) {
                return false;
            }
            int strLen = str.size();
            int suffixLen = suffix.size();
            string search = str.substr(strLen - suffix.size(), suffixLen);
            return (search == suffix) ? true : false;
        }
};