#include "GameUtilities/Event/OnComboChanged.h"
#include "GameUtilities/Event/EventId.h"
namespace GU
{
    namespace Evt
    {
        OnComboChanged::OnComboChanged(const int newComboId, const int newIndex):
        Event(static_cast<int>(GU::Evt::EventId::ON_CHECK)),
        comboId(newComboId),
        index(newIndex)
        {
            //ctor
        }

        OnComboChanged::~OnComboChanged()
        {
            //dtor
        }
    }
}
