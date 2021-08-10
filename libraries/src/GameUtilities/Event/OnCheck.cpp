#include "GameUtilities/Event/OnCheck.h"
#include "GameUtilities/Event/EventId.h"
namespace GU
{
    namespace Evt
    {
        OnCheck::OnCheck(const int newCheckBoxId, const bool newChecked):
        Event(static_cast<int>(GU::Evt::EventId::ON_CHECK)),
        checkboxId(newCheckBoxId),
        checked(newChecked)
        {
            //ctor
        }

        OnCheck::~OnCheck()
        {
            //dtor
        }
    }
}
