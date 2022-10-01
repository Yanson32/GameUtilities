#ifndef GAMEUTILITIES_START_MOUSE_DRAG_H
#define GAMEUTILITIES_START_MOUSE_DRAG_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       09/30/22
*   Purpose:    This event is generated when the user initiates a drag 
*               operation with the mouse 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Event.h"
#include <Math/Vector2.h>

namespace GU
{
    namespace Evt
    {
        class EVENT_EXPORT OnStartMouseDrag: public Event
        {
            public: 
                OnStartMouseDrag(Math::Vector2<float> &position, const int &line, const char* file = "");
                virtual ~OnStartMouseDrag(); 
            public:
                Math::Vector2<float> m_pos;
        };
    }
}
#endif
