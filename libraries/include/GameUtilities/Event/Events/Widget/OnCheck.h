#ifndef GAMEUTILITIES_ON_CHECK_H 
#define GAMEUTILITIES_ON_CHECK_H 
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       5/16/22
*   Purpose:    This event is generated when the user clicks on something. 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Events/Widget/WidgetEvent.h"

namespace GU
{
    namespace Evt
    {
        class EVENT_EXPORT OnCheck: public WidgetEvent
        {
            public:
                /**************************************************************************
                *   @breif  Constructor
                *   @param  checkBoxId is a unique identifier for the checkbox.
                *   @param  checked is true if the checkbox was checked and false otherwise.
                **************************************************************************/
                OnCheck(void *parent, const int &widgetId, const bool &checked, const int &line, const char* file);
                

                /**************************************************************************
                *   @breif  Destructor 
                **************************************************************************/
                virtual ~OnCheck();
            public: 
                const bool m_checked;

        };
    }
}
#endif 
