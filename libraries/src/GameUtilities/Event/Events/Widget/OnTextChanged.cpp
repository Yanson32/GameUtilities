#include "GameUtilities/Event/Events/Widget/OnTextChanged.h"
#include "GameUtilities/Event/EventId.h"


namespace GU
{
    namespace Evt
    {

        OnTextChanged::OnTextChanged(void *parent, const int id, const GU::Core::String &text):
        WidgetEvent(parent, static_cast<int>(GU::Evt::EventId::ON_TEXT_CHANGED)),
        m_id(id),
        m_text(text)
        {

        }


        OnTextChanged::~OnTextChanged()
        {

        }

    }
}

