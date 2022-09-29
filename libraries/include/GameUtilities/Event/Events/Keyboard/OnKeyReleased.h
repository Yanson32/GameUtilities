#ifndef EVENT_ON_RETURN_RELEASED_H_
#define EVENT_ON_RETURN_RELEASED_H
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

        class OnKeyReleased: public GU::Evt::Event
        {
            public:
                OnKeyReleased(const int &key);
                virtual ~OnKeyReleased();
                const int m_keyId = -1;
        };
    }
}

#endif


