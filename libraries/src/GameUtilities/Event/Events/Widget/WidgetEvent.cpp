#include "GameUtilities/Event/Events/Widget/WidgetEvent.h"

namespace GU
{
    namespace Evt
    {
        WidgetEvent::WidgetEvent(void *parent, const int &widgetId, const int &eventId, const int &line, const char* file):
        Event(eventId, line, file),
        m_parent(parent),
        m_widgetId(widgetId)
        {

        }


        WidgetEvent::~WidgetEvent()
        {

        }
    }
}
