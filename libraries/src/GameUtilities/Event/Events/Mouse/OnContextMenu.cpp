/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       09/30/22
*   Purpose:    This event should be generated when the user clicks the
*               right mouse button. 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Events/Mouse/OnContextMenu.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {
        OnContextMenu::OnContextMenu(const int &menuId, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_CONTEXT_MENU), line, file),
        m_menuId(menuId)
        {

        }
        
    
        OnContextMenu::~OnContextMenu()
        {

        }
    }
}

