/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   10/01/22
*   @file   OnResume.cpp
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Events/OnResume.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{

    namespace Evt
    {

        /**********************************************************************//**
        *   @brief  Constructor.
        *   @param  resumeId is a unique identifier for the entity to be resumed. 
        *   @param  line is the source code line number that generated the event.
        *   @param  file is the source code file that generated the event
        **************************************************************************/
        OnResume::OnResume(const int &resumeId, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_RESUME), line, file),
        m_resumeId(resumeId)
        {

        }

        
        /**********************************************************************//**
        *   @brief  Destructor
        **************************************************************************/
        OnResume::~OnResume()
        {

        }
    }

}
