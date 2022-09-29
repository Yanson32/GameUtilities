#include "GameUtilities/Event/Events/Keyboard/OnKeyReleased.h"
#include "GameUtilities/Event/EventId.h"


namespace GU
{
    namespace Evt
    {

        OnKeyReleased::OnKeyReleased(const int &key):
        Event(static_cast<int>(GU::Evt::EventId::ON_KEY_RELEASED)),
        m_keyId(key)
        {

        }


        OnKeyReleased::~OnKeyReleased()
        {

        }

    }
}
