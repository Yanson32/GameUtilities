/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       10/01/22
*   Purpose:    This event is generates when something is refreshed. 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Events/OnRefresh.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{

    namespace Evt
    {

        /**************************************************************************
        *   Constructor
        **************************************************************************/
        OnRefresh::OnRefresh(const int &refreshId, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_REFRESH),line,file),
        m_refreshId(refreshId)
        {

        }

        
        /**************************************************************************
        *   Destructor
        **************************************************************************/
        OnRefresh::~OnRefresh()
        {

        }

    }

}
