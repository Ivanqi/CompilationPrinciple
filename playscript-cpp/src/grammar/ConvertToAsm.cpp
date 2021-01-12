#include "ConvertToAsm.h"
#include <fstream>
#include <iostream>
using std::ofstream;

using namespace play;


bool ConvertToAsm::output(string text)
{
    ofstream out(outPutFile_, std::ios::out | std::ios::binary);

    if (out.is_open()) {
        out << text;
        return true;
    } else {
        return false;
    }
}