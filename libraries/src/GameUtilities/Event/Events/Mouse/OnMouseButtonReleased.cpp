/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       09/30/22
*   Purpose:    The OnMouseButtonReleased event should be generated
*               when the user releases a mouse button.
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/EventId.h"
#include "GameUtilities/Event/Events/Mouse/OnMouseButtonReleased.h"

namespace GU
{
    namespace Evt
    {
        OnMouseButtonReleased::OnMouseButtonReleased(const Math::Vector2<float> &pos, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_MOUSE_BUTTON_RELEASED), line, file),
        m_pos(pos)
        {

        }


        OnMouseButtonReleased::~OnMouseButtonReleased()
        {

        }
    }
}




