#include "GameUtilities/Event/Pop.h"
#include "GameUtilities/Event/Id.h"

namespace GU
{
    namespace Evt
    {
		Pop::Pop(const int newLine, const char* newFile):
		Event(GU::Evt::Id::POP_STATE, newLine, newFile)
		{
			//ctor
		}

		Pop::~Pop()
		{
			//dtor
		}
	}
}
