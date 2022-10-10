/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       09/30/22
*   Purpose:    The OnEndDrag event will be generated when the user stops
*               using the mouse to drag. 
**************************************************************************/
#include "GameUtilities/Event/Events/Mouse/OnEndMouseDrag.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {  
        OnEndMouseDrag::OnEndMouseDrag(Math::Vector2<float> &position, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_END_DRAG), line, file),
        m_position(position) 
        {

        }
        

        OnEndMouseDrag::~OnEndMouseDrag()
        {

        } 
    }
}

