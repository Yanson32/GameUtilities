/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       09/30/22
*   Purpose:    This event is generated when the user initiates a drag 
*               operation with the mouse 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/EventId.h"
#include "GameUtilities/Event/Events/Mouse/OnStartMouseDrag.h"

namespace GU
{
    namespace Evt
    {
        OnStartMouseDrag::OnStartMouseDrag(Math::Vector2<float> &pos, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_START_MOUSE_DRAG), line, file),
        m_pos(pos)
        {

        }


        OnStartMouseDrag::~OnStartMouseDrag()
        {

        }
    }
}
