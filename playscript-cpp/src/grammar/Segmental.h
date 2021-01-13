#ifndef SEGMENTAL_H
#define SEGMENTAL_H
#include <string>

namespace play
{
    class Segmental
    {
        private:
            int counter_{0};
            std::string prefix_{"LBBO_"};
        
        public:
            std::string newSegment()
            {
                ++counter_;
                std::string segm = prefix_ + std::to_string(counter_);
                return segm;
            }

            std::string nowSegment()
            {
                std::string segm = prefix_ + std::to_string(counter_);
                return segm;
            }

            std::string incrSegment()
            {
                std::string segm = prefix_ + std::to_string(counter_ + 1);
                return segm;
            }

            void clearCounter()
            {
                counter_ = 1;
            }
    };
};


#endif