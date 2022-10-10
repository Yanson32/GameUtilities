/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       10/01/22
*   Purpose:    This event is generates when something is stopped. 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Events/OnStop.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{

    namespace Evt
    {

        /**************************************************************************
        *   Constructor
        **************************************************************************/
        OnStop::OnStop(const int &stopId, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_STOP), line, file),
        m_stopId(stopId)
        {

        }

        
        /**************************************************************************
        *   Destructor
        **************************************************************************/
        OnStop::~OnStop()
        {

        }
    }

}
