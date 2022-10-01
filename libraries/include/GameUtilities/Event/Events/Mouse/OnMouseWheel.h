#ifndef GAMEUTILITIES_EVNT_MOUSE_ON_MOUSEBUTTONWHEEL_H
#define GAMEUTILITIES_EVNT_MOUSE_ON_MOUSEBUTTONWHEEL_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       09/30/22
*   Purpose:    This event is generated when the user moves the mouse wheel 
**************************************************************************/

#include "event_export.h"
#include "GameUtilities/Event/Event.h"
#include <Math/Vector2.h>

namespace GU
{
    namespace Evt
    {
        class EVENT_EXPORT OnMouseWheel: public GU::Evt::Event
        {
            public:
                OnMouseWheel(const int &pos, const int &line, const char* file = "");
                virtual ~OnMouseWheel();
            public:
                const int m_pos;
        };
    }
}
#endif





