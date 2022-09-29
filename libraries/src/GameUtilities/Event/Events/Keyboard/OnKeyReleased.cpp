#include "GameUtilities/Event/Events/Keyboard/OnKeyReleased.h"
#include "GameUtilities/Event/EventId.h"


namespace GU
{
    namespace Evt
    {

        OnKeyReleased::OnKeyReleased(const int &key, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_KEY_RELEASED), line, file),
        m_keyId(key)
        {

        }


        OnKeyReleased::~OnKeyReleased()
        {

        }

    }
}
