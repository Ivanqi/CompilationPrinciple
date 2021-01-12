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
            string outPutFile_{"asm.s"};

        public:
            ConvertToAsm()
            {

            }

            ConvertToAsm(string filepath): outPutFile_(filepath)
            {

            }

            bool output(string text);
    };
};

#endif