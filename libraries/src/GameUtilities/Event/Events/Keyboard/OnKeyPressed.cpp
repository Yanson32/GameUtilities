#include "GameUtilities/Event/Events/Keyboard/OnKeyPressed.h"
#include "GameUtilities/Event/EventId.h"


namespace GU
{
    namespace Evt
    {

        OnKeyPressed::OnKeyPressed(const int &key, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_KEY_PRESSED), line, file),
        m_keyId(key)
        {

        }


        OnKeyPressed::~OnKeyPressed()
        {

        }
    }
}
