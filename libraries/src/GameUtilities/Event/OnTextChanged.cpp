#include "GameUtilities/Event/OnTextChanged.h"
#include "GameUtilities/Event/EventId.h"


namespace GU
{
    namespace Evt
    {

        OnTextChanged::OnTextChanged(const int id, const GU::Core::String &text):
        Event(static_cast<int>(GU::Evt::EventId::ON_RETURN_RELEASED)),
        m_id(id)
        {

        }


        OnTextChanged::~OnTextChanged()
        {

        }

    }
}

