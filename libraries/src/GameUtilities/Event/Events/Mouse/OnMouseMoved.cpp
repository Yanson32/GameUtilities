/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       09/30/22
*   Purpose:    This event is generated when the mouse moves
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/EventId.h"
#include "GameUtilities/Event/Events/Mouse/OnMouseMoved.h"

namespace GU
{
    namespace Evt
    {
        OnMouseMoved::OnMouseMoved(const Math::Vector2<float> &pos, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_MOUSE_MOVED), line, file),
        m_pos(pos)
        {

        
        }

          
        OnMouseMoved::~OnMouseMoved()
        {

        }
    }
}





