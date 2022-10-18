#include "GameUtilities/Event/Events/Widget/OnTextChanged.h"
#include "GameUtilities/Event/EventId.h"


namespace GU
{
    namespace Evt
    {

        OnTextChanged::OnTextChanged(std::shared_ptr<void> parent, const int &widgetId, const GU::Core::String &text, const int &line, const char* file):
        WidgetEvent(parent, widgetId, static_cast<int>(GU::Evt::EventId::ON_TEXT_CHANGED), line, file),
        m_text(text)
        {

        }


        OnTextChanged::~OnTextChanged()
        {

        }

    }
}

