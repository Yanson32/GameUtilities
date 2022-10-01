#ifndef GAMEUTILITIES_EVNT_MOUSE_ON_CONTEXTMENU_H
#define GAMEUTILITIES_EVNT_MOUSE_ON_CONTEXTMENU_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       09/30/22
*   Purpose:    This event should be generated when the user clicks the
*               right mouse button. 
**************************************************************************/

#include "event_export.h"
#include "GameUtilities/Event/Event.h"
namespace GU
{
    namespace Evt
    {
        class EVENT_EXPORT OnContextMenu: public GU::Evt::Event
        {
            public:
                OnContextMenu(const int &menuId, const int &line, const char* file = "");
                virtual ~OnContextMenu();
            public:
                const int m_menuId = -1;
        };
    }
}
#endif
