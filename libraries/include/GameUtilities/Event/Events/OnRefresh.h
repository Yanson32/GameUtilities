#ifndef GAMEUTILITIES_EVENT_ONREFRESH_H
#define GAMEUTILITIES_EVENT_ONREFRESH_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       10/01/22
*   Purpose:    This event is generates when something is refreshed. 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{

    namespace Evt
    {

        class EVENT_EXPORT OnRefresh : public Event
        {
            public:
                /**************************************************************************
                *   Constructor
                **************************************************************************/
                OnRefresh(const int &refreshId, const int &line, const char* file = "");

                
                /**************************************************************************
                *   Destructor
                **************************************************************************/
                virtual ~OnRefresh(); 
            private:
                const int m_refreshId = -1;
        };

    }

}
#endif




