/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       09/30/22
*   Purpose:    The OnDoubleClick event should be generated when the 
*               user clicks twice quickly.
**************************************************************************/
#include "GameUtilities/Event/EventId.h"
#include "GameUtilities/Event/Events/Mouse/OnDoubleClick.h"

namespace GU
{
    namespace Evt
    {
        OnDoubleClick::OnDoubleClick(const int &widgetId, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_DOUBLE_CLICK), line, file),
        m_widgetId(widgetId)
        {

        }

        
        OnDoubleClick::~OnDoubleClick()
        {

        }
    }
}


