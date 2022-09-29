#include "GameUtilities/Event/Events/Widget/WidgetEvent.h"

namespace GU
{
    namespace Evt
    {
        WidgetEvent::WidgetEvent(void *parent, const int &id, const int &line, const char* file):
        Event(id, line, file),
        m_parent(parent)
        {

        }


        WidgetEvent::~WidgetEvent()
        {

        }
    }
}
