#ifndef CONVERTTOASM_H
#define CONVERTTOASM_H
#pragma once
#include <string>
using std::string;

namespace play
{
    class ConvertToAsm
    {
        private:
            string outPutFile_{"asm"};
            string suffix{".s"};

        public:
            ConvertToAsm(): outPutFile_("")
            {

            }

            ConvertToAsm(const char *p):outPutFile_(p)
            {

            }

            ConvertToAsm(string filepath): outPutFile_(filepath)
            {

            }

            bool output(string text);
    };
};

#endif