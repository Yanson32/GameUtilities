#ifndef GAMEUTILITIES_EVENT_ONSTOP_H
#define GAMEUTILITIES_EVENT_ONSTOP_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       10/01/22
*   Purpose:    This event is generates when something is stopped. 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{

    namespace Evt
    {

        class EVENT_EXPORT OnStop : public Event
        {
            public:
                /**************************************************************************
                *   Constructor
                **************************************************************************/
                OnStop(const int &stopId, const int &line, const char* file = "");

                
                /**************************************************************************
                *   Destructor
                **************************************************************************/
                virtual ~OnStop(); 
            private:
                const int m_stopId = -1;
        };

    }

}
#endif


