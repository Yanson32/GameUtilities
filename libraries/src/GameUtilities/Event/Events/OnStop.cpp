/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   10/01/22
*   @file   OnStop.h
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Events/OnStop.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{

    namespace Evt
    {

        /**********************************************************************//**
        *   @brief  Constructor.
        *   @param  stopId is a unique id for the entity to be stopped. 
        *   @param  line is the source code line number that generated the event.
        *   @param  file is the source code file that generated the event
        **************************************************************************/
        OnStop::OnStop(const int &stopId, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_STOP), line, file),
        m_stopId(stopId)
        {

        }

        
        /**********************************************************************//**
        *   Destructor
        **************************************************************************/
        OnStop::~OnStop()
        {

        }
    }

}
