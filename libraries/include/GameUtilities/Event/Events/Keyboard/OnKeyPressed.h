#ifndef EVENT_ON_RETURN_PRESSED_H
#define EVENT_ON_RETURN_PRESSED_H
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

        class OnKeyPressed: public GU::Evt::Event
        {
            public:
                OnKeyPressed(const int &key, const int &line, const char* file = "");
                virtual ~OnKeyPressed();
                const int m_keyId = -1;
        };
    }
}

#endif

