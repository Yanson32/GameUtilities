#ifndef GAMEUTILITIES_EVENT_LISTENER_H
#define GAMEUTILITIES_EVENT_LISTENER_H
#include "gameutilities_export.h"
#include <memory>
#include "GameUtilities/Event/Event.h"
namespace Evt
{
    /**************************************************************************
    *   Author:     Wayne J Larson Jr.
    *   Date:       2/8/17
    *   Purpose:    This is an abstract base class used to define a listener
    *               object. Which can then be registered to receive events.
    **************************************************************************/
    class GAMEUTILITIES_EXPORT Listener
    {
        public:
            /**************************************************************************
            *   Constructor
            **************************************************************************/
            Listener();


            /**************************************************************************
            *   Purpose:    Method called when an event is sent
            *   Input:      EventPtr a pointer to an event this can be a nullptr.
            *               the pointer will be overwritten so the event should not
            *               still be useful
            **************************************************************************/
            virtual void OnEvent(EventPtr event) = 0;


            /**************************************************************************
            *   Destructor
            **************************************************************************/
            virtual ~Listener();
    };

}
#endif // LISTENER_H
