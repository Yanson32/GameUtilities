/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       09/30/22
*   Purpose:    This event should be generated when the user presses a 
*               mouse button. 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/EventId.h"
#include "GameUtilities/Event/Events/Mouse/OnMouseButtonPressed.h"

namespace GU
{
    namespace Evt
    {
        OnMouseButtonPressed::OnMouseButtonPressed(const Math::Vector2<float> &pos, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_MOUSE_BUTTON_PRESSED), line, file),
        m_pos(pos) 
        {

        }


        OnMouseButtonPressed::~OnMouseButtonPressed()
        {

        }
    }
}
