#ifndef GAMEUTILITIES_FRAMERATE_H
#define GAMEUTILITIES_FRAMERATE_H
#include "gameutilities_export.h"
#include <cstddef> //std::size_t

namespace GU
{

    namespace FR
    {

        class GAMEUTILITIES_EXPORT FrameRate final
        {
            public:
                FrameRate(const std::size_t newMaxQueueSize = 60);
                void update();
                double getFrameRate();
                ~FrameRate();
            private:
				class Impl;
				Impl* pimpl = nullptr;
        };
    }
}
#endif // FRAMERATE_H
