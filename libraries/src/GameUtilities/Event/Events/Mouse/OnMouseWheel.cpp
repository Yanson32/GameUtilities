/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       09/30/22
*   Purpose:    This event is generated when the user moves the mouse wheel 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/EventId.h"
#include "GameUtilities/Event/Events/Mouse/OnMouseWheel.h"

namespace GU
{
    namespace Evt
    {
        OnMouseWheel::OnMouseWheel(const int &pos, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_MOUSE_WHEEL), line, file),
        m_pos(pos)
        {

        }


        OnMouseWheel::~OnMouseWheel()
        {

        }
    }
}






