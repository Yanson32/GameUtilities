#ifndef EVENT_ON_RETURN_PRESSED_H
#define EVENT_ON_RETURN_PRESSED_H
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

        class OnReturnPressed: public GU::Evt::Event
        {
            public:
                OnReturnPressed(const int id);
                virtual ~OnReturnPressed();
                const int m_id = -1;
        };
    }
}

#endif

