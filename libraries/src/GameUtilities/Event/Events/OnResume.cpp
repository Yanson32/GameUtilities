/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       10/01/22
*   Purpose:    This event is generated when something resumes. 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Events/OnResume.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{

    namespace Evt
    {

        /**************************************************************************
        *   Constructor
        **************************************************************************/
        OnResume::OnResume(const int &resumehId, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_RESUME), line, file),
        m_resumeId(resumeId)
        {

        }

        
        /**************************************************************************
        *   Destructor
        **************************************************************************/
        OnResume::~OnResume()
        {

        }
    }

}
