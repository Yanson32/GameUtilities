#ifndef GAMEUTILITIES_FRAMERATE_H
#define GAMEUTILITIES_FRAMERATE_H
#include "core_export.h"
#include <cstddef> //std::size_t

namespace GU
{

    namespace Core
    {

        class CORE_EXPORT FrameRate final
        {
            public:
                FrameRate(const std::size_t newMaxQueueSize = 60);
                void update();
                double getFrameRate();
                ~FrameRate();
            private:
                FrameRate(const FrameRate&) = delete;
                FrameRate& operator = (const FrameRate&) = delete;
				class Impl;
				Impl* pimpl = nullptr;
        };
    }
}
#endif // FRAMERATE_H
