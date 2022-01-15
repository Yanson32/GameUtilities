#include "GameUtilities/Event/Pop.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {
		Pop::Pop(const int newLine, const char* newFile):
		Event(static_cast<int>(GU::Evt::EventId::POP_STATE), newLine, newFile)
		{
			//ctor
		}

		Pop::~Pop()
		{
			//dtor
		}
	}
}
