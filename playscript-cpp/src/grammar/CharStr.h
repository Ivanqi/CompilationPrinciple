#ifndef CHARSTR_H
#define CHARSTR_H
#include <string>
class CharStr
{
    private:
        std::string charS;

    public:
        CharStr() 
        {

        }

        ~CharStr()
        {
        }

        CharStr(std::string str)
        {
            charS = str;
        }

        std::string& getCharStr()
        {
            return charS;
        }

        void splicing(std::string str)
        {
            charS += str;
        }
};

#endif