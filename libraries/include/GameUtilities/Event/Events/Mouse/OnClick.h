#ifndef GAMEUTILITIES_ONCLICK_H
#define GAMEUTILITIES_ONCLICK_H
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
        class EVENT_EXPORT OnClick: public Event
        {
            public:
                /**************************************************************************
                *   @brief  Constructor
                *   @param  id is the unique id of the button that was clicked 
                **************************************************************************/
                OnClick(const int &buttonId, const int &line, const char* file = "");
                

                /**************************************************************************
                *   @brief  Destructor 
                **************************************************************************/
                virtual ~OnClick();
            public:
                const int m_buttonId;
        };
    }
}
#endif // CLICK_H
