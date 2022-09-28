#include "GameUtilities/Event/Events/Keyboard/OnReturnPressed.h"
#include "GameUtilities/Event/EventId.h"


namespace GU
{
    namespace Evt
    {

        OnReturnPressed::OnReturnPressed(const int id):
        Event(static_cast<int>(GU::Evt::EventId::ON_RETURN_PRESSED)),
        m_id(id)
        {

        }


        OnReturnPressed::~OnReturnPressed()
        {

        }
    }
}
