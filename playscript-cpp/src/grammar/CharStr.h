#ifndef CHARSTR_H
#define CHARSTR_H
#include <string.h>
class CharStr
{
    private:
        char *charS = nullptr;

    public:
        CharStr() {

        }

        ~CharStr()
        {
            if (charS != nullptr) {
                delete [] charS;
                charS = nullptr;
            }
        }

        CharStr(const char* str)
        {
            int num = strlen(str) + 1;
            charS = new char[num];
            
            strcpy(charS, str);
        }



        char* getCharStr()
        {
            return charS;
        }

        void splicing(char *str)
        {
            strcat(charS, str);
        }
};

#endif