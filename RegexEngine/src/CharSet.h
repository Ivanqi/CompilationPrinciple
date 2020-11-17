#ifndef CHARSET_H
#define CHARSET_H
#include <vector>
#include <string>

#include "Any.h"

using namespace std;

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
        char fromChar;

        // 终止字符
        char toChar;

        // 是否是取补集,比如[^a]
        bool exclude = false;

        // 子集
        vector<charSet*> subSets;

        // ascii表，也就是0到127
        static vector<char> ascii;
        static vector<char> letterAndDigits;

        // 整个字母表
        static vector<char> Alphabet;

        // 一些常量
        static CharSet digit;
        static CharSet smallLetter;
        static CharSet capitalLeter;
        static CharSet letter;
        static CharSet letterOrDigit;
        static CharSet whiteSpace;

        CharSet()
        {
            
        }

        CharSet(char fromChar)
        {
            CharSet(fromChar, fromChar, false);
        }

        CharSet(char fromChar, cha toChar)
        {
            CharSet(fromChar, toChar, false);
        }

        CharSet(char fromChar, cha toChar, bool exclude)
            :fromChar(fromChar), toChar(fromChar), exclude(exclude)
        {
            
        }

        void addSubSet(char charSet);


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
        static vector<char> ascii();

        /**
         * 包含字母和数字的字母表
         */
        static vector<char> letterAndDigits();

        static CharSet* initLetterOrDigit();

        static CharSet* initLetter();

        static CharSet* initWhiteSpace();

        bool equals(Any obj);

        // 是不是空集
        bool isEmpty();
};

#endif