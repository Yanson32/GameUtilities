#include "GameUtilities/Event/Click.h"
#include "GameUtilities/Event/EventId.h"
namespace GU
{
    namespace Evt
    {
        Click::Click(const int newId):
        Event(static_cast<int>(GU::Evt::EventId::CLICK)),
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
