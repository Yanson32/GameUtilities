#ifndef GAMEUTILITIES_EVENT_ONSTART_H
#define GAMEUTILITIES_EVENT_ONSTART_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       10/01/22
*   Purpose:    This event is generates when something is started. 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{

    namespace Evt
    {

        class EVENT_EXPORT OnStart : public Event
        {
            public:
                /**************************************************************************
                *   Constructor
                **************************************************************************/
                OnStart(const int &startId, const int &line, const char* file = "");

                
                /**************************************************************************
                *   Destructor
                **************************************************************************/
                virtual ~OnStart(); 
            private:
                const int m_startId = -1;
        };

    }

}
#endif

