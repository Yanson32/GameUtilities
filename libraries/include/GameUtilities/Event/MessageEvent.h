#ifndef GAMEUTILITIES_EVENT_MESSAGE_H 
#define GAMEUTILITIES_EVENT_MESSAGE_H
#include "event_export.h"
#include <memory>
#include "GameUtilities/Event/Event.h"

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

        class EVENT_EXPORT MessageEvent 
        {
            public:
                /**************************************************************************
                *   Constructor
                **************************************************************************/
                MessageEvent(const std::string &msg, const int  newSeverity = -1);


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
                virtual ~MessageEvent();

            private:
                const int m_messageType = -1;
        };

    }

}
#endif // LISTENER_H


