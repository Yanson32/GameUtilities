#ifndef GAMEUTILITIES_EVENT_ON_END_MOUSE_DRAG_H
#define GAMEUTILITIES_EVENT_ON_END_MOUSE_DRAG_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       09/30/22
*   Purpose:    The OnEndDrag event will be generated when the user stops
*               using the mouse to drag. 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Event.h"
#include <Math/Vector2.h>

namespace GU
{
    namespace Evt
    {
        class EVENT_EXPORT OnEndMouseDrag: public Event
        {
            public: 
                OnEndMouseDrag(Math::Vector2<float> &position, const int &line, const char* file = "");
                virtual ~OnEndMouseDrag(); 
            public:
                Math::Vector2<float> m_position;
        };
    }
}
#endif

