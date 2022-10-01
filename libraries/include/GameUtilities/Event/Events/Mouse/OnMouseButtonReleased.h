#ifndef GAMEUTILITIES_EVNT_MOUSE_ON_MOUSEBUTTONRELEASED_H
#define GAMEUTILITIES_EVNT_MOUSE_ON_MOUSEBUTTONRELEASD_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       09/30/22
*   Purpose:    The OnMouseButtonReleased event should be generated
*               when the user releases a mouse button.
**************************************************************************/

#include "event_export.h"
#include "GameUtilities/Event/Event.h"
#include <Math/Vector2.h>

namespace GU
{
    namespace Evt
    {
        class EVENT_EXPORT OnMouseButtonReleased: public GU::Evt::Event
        {
            public:
                OnMouseButtonReleased(const Math::Vector2<float> &pos, const int &line, const char* file = "");
                virtual ~OnMouseButtonReleased();
            public:
                const Math::Vector2<float> m_pos;
        };
    }
}
#endif



