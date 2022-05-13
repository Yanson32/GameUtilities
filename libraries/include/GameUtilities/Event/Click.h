#ifndef GAMEUTILITIES_CLICK_H
#define GAMEUTILITIES_CLICK_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       05/13/22
*   Purpose:    This class is a subclass of the event class. This event
*               is generated when the user clicks on something. 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Event.h"
namespace GU
{
    namespace Evt
    {
        class EVENT_EXPORT Click: public Event
        {
            public:
                /**************************************************************************
                *   @brief  Constructor
                *   @param  id is the unique id of the button that was clicked 
                **************************************************************************/
                Click(const int id);
                

                /**************************************************************************
                *   @brief  Destructor 
                **************************************************************************/
                virtual ~Click();
            public:
                const int m_buttonId;
        };
    }
}
#endif // CLICK_H
