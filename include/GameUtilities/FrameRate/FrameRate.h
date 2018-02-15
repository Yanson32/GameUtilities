#ifndef FRAMERATE_H
#define FRAMERATE_H
#include <deque>
#include <cstddef> //std::size_t
#include "gameutilities_export.h"
class GAMEUTILITIES_EXPORT FrameRate final
{
    public:
        FrameRate(const std::size_t newMaxQueueSize = 60);
        void update();
        double getFrameRate();
        ~FrameRate();
    private:
        const std::size_t maxQueueSize;
        std::deque<unsigned int> timeQue;
        unsigned int prevTime = 0;
};

#endif // FRAMERATE_H
