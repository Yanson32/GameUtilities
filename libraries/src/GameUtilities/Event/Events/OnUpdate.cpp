/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   10/01/22
*   @file   OnUpdate.cpp
**************************************************************************/
#include "GameUtilities/Event/Events/OnUpdate.h"
#include "event_export.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{

    namespace Evt
    {

        /**********************************************************************//**
        *   @brief  Constructor.
        *   @param  updateId is a unique id of the entity to be updated.
        *   @param  line is the source code line number that generated the event.
        *   @param  file is the source code file that generated the event
        **************************************************************************/
        OnUpdate::OnUpdate(const int &updateId, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_UPDATE), line, file),
        m_updateId(updateId)
        {

        }

        
        /**********************************************************************//**
        *   Destructor
        **************************************************************************/
        OnUpdate::~OnUpdate()
        {

        }

    }

}
