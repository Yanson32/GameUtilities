#ifndef GAMEUTILITIES_EVENT_ONUPDATE_H
#define GAMEUTILITIES_EVENT_ONUPDATE_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       10/01/22
*   Purpose:    This event is generated when somthing is updated.
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{

    namespace Evt
    {

        class EVENT_EXPORT OnUpdate : public Event
        {
            public:
                /**************************************************************************
                *   Constructor
                **************************************************************************/
                OnUpdate(const int &updateId, const int &line, const char* file = "");

                
                /**************************************************************************
                *   Destructor
                **************************************************************************/
                virtual ~OnUpdate(); 
            private:
                const int m_updateId = -1;
        };

    }

}
#endif




