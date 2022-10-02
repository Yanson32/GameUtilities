#ifndef GAMEUTILITIES_EVENT_ONPAUSE_H
#define GAMEUTILITIES_EVENT_ONPAUSE_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       10/01/22
*   Purpose:    This event is generates when something is paused. 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{

    namespace Evt
    {

        class EVENT_EXPORT OnPause : public Event
        {
            public:
                /**************************************************************************
                *   Constructor
                **************************************************************************/
                OnPause(const int &pauseId, const int &line, const char* file = "");

                
                /**************************************************************************
                *   Destructor
                **************************************************************************/
                virtual ~OnPause(); 
            private:
                const int m_pauseId = -1;
        };

    }

}
#endif



