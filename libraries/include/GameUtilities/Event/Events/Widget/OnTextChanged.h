#ifndef EVENT_ON_TEXT_CHANGED_H
#define EVENT_ON_TEXT_CHANGED_H
#include "GameUtilities/Event/Events/Widget/WidgetEvent.h"
#include "GameUtilities/Core/String.h"

namespace GU
{
    namespace Evt
    {

        class OnTextChanged: public GU::Evt::WidgetEvent
        {
            public:
                OnTextChanged(void *parent, const int &widgetId, const GU::Core::String &text, const int &line, const char* file);
                virtual ~OnTextChanged();
                const GU::Core::String m_text = "";
        };
    }
}

#endif

