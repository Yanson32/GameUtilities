/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       10/01/22
*   Purpose:    This event is generates when something is started. 
**************************************************************************/
#include "GameUtilities/Event/Events/OnStart.h"
#include "event_export.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{

    namespace Evt
    {

        /**************************************************************************
        *   Constructor
        **************************************************************************/
        OnStart::OnStart(const int &startId, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_START), line, file),
        m_startId(startId)
        {

        }

        
        /**************************************************************************
        *   Destructor
        **************************************************************************/
        OnStart::~OnStart()
        {

        }

    }

}


