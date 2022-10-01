#ifndef GAMEUTILITIES_EVNT_MOUSE_ON_DOUBLECLICK_H
#define GAMEUTILITIES_EVNT_MOUSE_ON_DOUBLECLICK_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       09/30/22
*   Purpose:    The OnDoubleClick event should be generated when the 
*               user clicks twice quickly.
**************************************************************************/

#include "event_export.h"
#include "GameUtilities/Event/Event.h"
namespace GU
{
    namespace Evt
    {
        class EVENT_EXPORT OnDoubleClick: public GU::Evt::Event
        {
            public:
                OnDoubleClick(const int &widgetId, const int &line, const char* file = "");
                virtual ~OnDoubleClick();
            public:
                const int m_widgetId = -1;
        };
    }
}
#endif

