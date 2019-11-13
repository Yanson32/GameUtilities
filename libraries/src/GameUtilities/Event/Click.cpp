#include "GameUtilities/Event/Click.h"
#include "GameUtilities/Event/Id.h"
namespace GU
{
    namespace Evt
    {
        Click::Click(const int newId):
        Event(GU::Evt::Id::CLICK),
        buttonId(newId)
        {
            //ctor
        }

        Click::~Click()
        {
            //dtor
        }
    }
}
