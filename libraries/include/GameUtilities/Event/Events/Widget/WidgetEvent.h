#ifndef GAMEUTILITIES_EVENT_WIDGET_H
#define GAMEUTILITIES_EVENT_WIDGET_H
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {
        class EVENT_EXPORT WidgetEvent: public GU::Evt::Event
        {
            public:
                WidgetEvent(void *parent, const int &id, const int &line = 0, const char* file = nullptr);
                virtual ~WidgetEvent();
            public:
                void *m_parent = nullptr;
        };
    }

}
#endif

