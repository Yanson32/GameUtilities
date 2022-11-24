/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       10/01/22
*   Purpose:    This event is generates when something is paused. 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Events/OnPause.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{

    namespace Evt
    {

        /**********************************************************************//**
        *   @brief  Constructor.
        *   @param  pauseId is a unique id for the entity to be paused. 
        *   @param  line is the line in code where the event was generated.
        *   @param  file is the file were the event was generated.
        **************************************************************************/
        OnPause::OnPause(const int &pauseId, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_PAUSE), line, file),
        m_pauseId(pauseId)
        {

        }

        
        /**********************************************************************//**
        *   @brief  Destructor
        **************************************************************************/
        OnPause::~OnPause()
        {

        }

    }

}
