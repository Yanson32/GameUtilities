#ifndef GAMEUTILITIES_EVNT_MOUSE_ON_MOUSEBUTTONPRESSED_H
#define GAMEUTILITIES_EVNT_MOUSE_ON_MOUSEBUTTONPRESSED_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       09/30/22
*   Purpose:    This event should be generated when the user presses a 
*               mouse button. 
**************************************************************************/

#include "event_export.h"
#include "GameUtilities/Event/Event.h"
#include <Math/Vector2.h>

namespace GU
{
    namespace Evt
    {
        class EVENT_EXPORT OnMouseButtonPressed: public GU::Evt::Event
        {
            public:
                OnMouseButtonPressed(const Math::Vector2<float> &pos, const int &line, const char* file = "");
                virtual ~OnMouseButtonPressed();
            public:
                const Math::Vector2<float> m_pos;
        };
    }
}
#endif


