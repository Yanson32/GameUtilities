#ifndef GAMEUTILITIES_EVENT_ONRESUME_H
#define GAMEUTILITIES_EVENT_ONRESUME_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       10/01/22
*   Purpose:    This event is generated when something resumes. 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{

    namespace Evt
    {

        class EVENT_EXPORT OnResume : public Event
        {
            public:
                /**************************************************************************
                *   Constructor
                **************************************************************************/
                OnResume(const int &resumehId, const int &line, const char* file = "");

                
                /**************************************************************************
                *   Destructor
                **************************************************************************/
                virtual ~OnResume(); 
            private:
                const int m_refreshId = -1;
        };

    }

}
#endif





