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
                virtual void Init() = 0;
                virtual void Clean() = 0;
                virtual void HandleEvents(Engin& engin, const float &deltaTime) = 0;
                virtual void Update(Engin& engin, const float &deltaTime) = 0;
                virtual void Draw(Engin& engin, const float &deltaTime) = 0;
        };

    }

}

#endif
