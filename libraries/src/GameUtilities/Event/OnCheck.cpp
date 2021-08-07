#include "GameUtilities/Event/OnCheck.h"
#include "GameUtilities/Event/Id.h"
namespace GU
{
    namespace Evt
    {
        OnCheck::OnCheck(const int newCheckBoxId, const bool newChecked):
        Event(GU::Evt::Id::ON_CHECK),
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
