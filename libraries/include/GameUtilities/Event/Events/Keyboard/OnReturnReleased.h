#ifndef EVENT_ON_RETURN_RELEASED_H_
#define EVENT_ON_RETURN_RELEASED_H
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

        class OnReturnReleased: public GU::Evt::Event
        {
            public:
                OnReturnReleased(const int id);
                virtual ~OnReturnReleased();
                const int m_id = -1;
        };
    }
}

#endif


