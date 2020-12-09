#ifndef CHARSET_H
#define CHARSET_H
#include <vector>
#include <string>
#include <memory>

#include "Any.h"

using std::vector;
using std::string;
using std::unique_ptr;
using std::shared_ptr;

/**
 * 字符的集合
 * 用于在词法分析时，定义满足条件的字符。它有这几种使用方式
 *  1. 代表一个字符
 *  2. 用起止字符定义一个集合
 *  3. 对集合取补集
 *  4. 通过包含多个子集合来定义该集合
 */

class CharSet
{
    public:
        // 起始字符
        char fromChar_{' '};

        // 终止字符
        char toChar_{' '};

        // 是否是取补集,比如[^a]
        bool exclude{false};

        // 子集
        vector<shared_ptr<CharSet>> subSets;
        // vector<CharSet*> subSets;

        // ascii表，也就是0到127
        static vector<char> ascii;
        static vector<char> letterAndDigits;

        // 整个字母表
        static vector<char> Alphabet;

        // 一些常量
        static shared_ptr<CharSet> digit;
        static shared_ptr<CharSet> smallLetter;
        static shared_ptr<CharSet> capitalLeter;
        static shared_ptr<CharSet> letter;
        static shared_ptr<CharSet> letterOrDigit;
        static shared_ptr<CharSet> whiteSpace;

        CharSet()
        {
            
        }


        CharSet(char fromChar)
            :fromChar_{fromChar}, toChar_{fromChar}
        {
        }

        CharSet(char fromChar, char toChar)
            :fromChar_{fromChar}, toChar_{toChar}
        {
        }

        CharSet(char fromChar, char toChar, bool exclude)
            :fromChar_{fromChar}, toChar_{toChar}, exclude{exclude}
        {
            
        }

        void addSubSet(shared_ptr<CharSet>& charSet);


        /**
         * 某个字符是否属于本集合
         */
        bool match(char ch);

        string toString();

        /**
         * 返回一个等价的集合，但是显示的时候更简短
         * 比如, a|b|....z就显示成[a - z]就行了
         */
        CharSet* getShorterForm();


        // 计算补集
        CharSet* getSupplementarySet();

        /**
         * 初始化字母表。目前支持整个ASCII表，128个值
         */
        static vector<char> asciiDeclare();

        /**
         * 包含字母和数字的字母表
         */
        static vector<char> letterAndDigitsDeclare();

        static CharSet* initLetterOrDigitDeclare();

        static CharSet* initLetterDeclare();

        static CharSet* initWhiteSpaceDeclare();

        bool equals(Any obj);

        // 是不是空集
        bool isEmpty();
};

#endif