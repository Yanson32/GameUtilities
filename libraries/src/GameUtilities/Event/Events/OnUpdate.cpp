/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       10/01/22
*   Purpose:    This event is generated when somthing is updated.
**************************************************************************/
#include "GameUtilities/Event/Events/OnUpdate.h"
#include "event_export.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{

    namespace Evt
    {

        /**************************************************************************
        *   Constructor
        **************************************************************************/
        OnUpdate::OnUpdate(const int &updateId, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_UPDATE), line, file),
        m_updateId(updateId)
        {

        }

        
        /**************************************************************************
        *   Destructor
        **************************************************************************/
        OnUpdate::~OnUpdate()
        {

        }

    }

}
