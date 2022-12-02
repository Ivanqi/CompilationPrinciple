#ifndef BUFFERED_INPUT_STREAM_HPP
#define BUFFERED_INPUT_STREAM_HPP

#include <stdio.h>

#define BUFFER_LEN 256

class BufferedInputStream {
    private:
        FILE *fp;
        char szBuffer[BUFFER_LEN];
        unsigned short index;
    
    public:
        BufferedInputStream(char const *filename)
        {
            fp = fopen(filename, "rb");
            fread(szBuffer, BUFFER_LEN * sizeof(char), 1, fp);
            index = 0;
        }

        ~BufferedInputStream()
        {
            close();
        }

        /**
         * @brief 读取内容
         *  1. 当 index < 256时，单字节读取
         *  2. 当 index > 256时, 从套接字读人256个字节到内存中
         * 
         * @return char 
         */
        char read()
        {
            if (index < BUFFER_LEN) {
                return szBuffer[index++];
            } else {
                index = 0;
                fread(szBuffer, BUFFER_LEN * sizeof(char), 1, fp);
                return szBuffer[index++];
            }
        }

        /**
         * @brief 读取四个字节
         * 
         * @return int 
         */
        int read_int()
        {
            int b1 = read() & 0xff;
            int b2 = read() & 0xff;
            int b3 = read() & 0xff;
            int b4 = read() & 0xff;

            return b4 << 24 | b3 << 16 | b2 << 8 | b1;
        }

        /**
         * @brief 读取8个字节
         * 
         * @return double 
         */
        double read_double()
        {
            char t[8];
            for (int i = 0; i < 8; i++) {
                t[i] = read();
            }

            return *(double *) t;
        }

        void unread()
        {
            index--;
        }

        void close()
        {
            if (fp != NULL) {
                fclose(fp);
                fp = NULL;
            }
        }
};

#endif