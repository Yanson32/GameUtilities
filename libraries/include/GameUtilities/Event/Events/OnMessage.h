#ifndef GAMEUTILITIES_EVENT_ONMESSAGE_H 
#define GAMEUTILITIES_EVENT_ONMESSAGE_H
#include "event_export.h"
#include <memory>
#include "GameUtilities/Event/Event.h"
#include "GameUtilities/Core/String.h"

namespace GU
{

    namespace Evt
    {
        /**************************************************************************
        *   Author:     Wayne J Larson Jr.
        *   Date:       11/14/20
        *   Purpose:    This is an abstract base class used to define a listener
        *               object. Which can then be registered to receive events.
        **************************************************************************/

        class EVENT_EXPORT OnMessage: public Event 
        {
            public:
                /**************************************************************************
                *   Constructor
                **************************************************************************/
                OnMessage(const GU::Core::String &msg, const int  &messageType  = -1, const int &line = -1, const char* file = "");


                /**************************************************************************
                *   Purpose:    Method called when an event is sent
                *   Input:      EventPtr a pointer to an event this can be a nullptr.
                *               the pointer will be overwritten so the event should not
                *               still be useful
                **************************************************************************/
                virtual void OnEvent(EventPtr event) = 0;

                
                int getMessageType() const;

                /**************************************************************************
                *   Destructor
                **************************************************************************/
                virtual ~OnMessage();

            private:
                const int m_messageType = -1;
                const GU::Core::String m_msg;
        };

    }

}
#endif // LISTENER_H


