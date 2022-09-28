#include "GameUtilities/Event/Events/Keyboard/OnReturnReleased.h"
#include "GameUtilities/Event/EventId.h"


namespace GU
{
    namespace Evt
    {

        OnReturnReleased::OnReturnReleased(const int id):
        Event(static_cast<int>(GU::Evt::EventId::ON_RETURN_RELEASED)),
        m_id(id)
        {

        }


        OnReturnReleased::~OnReturnReleased()
        {

        }

    }
}
