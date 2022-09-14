#ifndef GAMEUTILITIES_FRAME_H
#define GAMEUTILITIES_FRAME_H
#include "engin_export.h"

namespace GU
{
    namespace Engin
    {
        class Engin;
        class ENGIN_EXPORT Frame 
        {
            public:
                virtual void init() = 0;
                virtual void clean() = 0;
                virtual void handleEvents(GU::Engin::Engin& engin, const float &deltaTime) = 0;
                virtual void update(GU::Engin::Engin& engin, const float &deltaTime) = 0;
                virtual void draw(GU::Engin::Engin& engin, const float &deltaTime) = 0;
        };

    }

}

#endif
