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
                OnTextChanged(void *parent, const int id, const GU::Core::String &text);
                virtual ~OnTextChanged();
                const int m_id = -1;
                const GU::Core::String m_text = "";
        };
    }
}

#endif

