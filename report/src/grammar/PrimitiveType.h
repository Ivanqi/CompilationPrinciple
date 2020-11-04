#ifndef PRIMITIVETYPE_H
#define PRIMITIVETYPE_H

#include <string>

class PrimitiveType
{
    private:
        std::string name_;

    public:
        // 把常见的基础数据类型都定义出来
        static PrimitiveType* Integer;
        static PrimitiveType* Long;
        static PrimitiveType* Float;
        static PrimitiveType* Double;
        static PrimitiveType* Boolean;
        static PrimitiveType* Byte;
        static PrimitiveType* Char;
        static PrimitiveType* Short;
        

        //增加String为基础类型
        static PrimitiveType* String;

        static PrimitiveType* Null;


    public:
        std::string getName()
        {
            return name_;
        }



        PrimitiveType(std::string name):name_(name)
        {
        }
};
#endif