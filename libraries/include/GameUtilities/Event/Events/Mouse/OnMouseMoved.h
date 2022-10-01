#ifndef GAMEUTILITIES_EVNT_MOUSE_ON_MOUSEMOVED_H
#define GAMEUTILITIES_EVNT_MOUSE_ON_MOUSEMOVED_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       09/30/22
*   Purpose:    
**************************************************************************/

#include "event_export.h"
#include "GameUtilities/Event/Event.h"
#include <Math/Vector2.h>

namespace GU
{
    namespace Evt
    {
        class EVENT_EXPORT OnMouseMoved: public GU::Evt::Event
        {
            public:
                OnMouseMoved(const Math::Vector2<float> &pos, const int &line, const char* file = "");
                virtual ~OnMouseMoved();
            public:
                const Math::Vector2<float> m_pos;
        };
    }
}
#endif




