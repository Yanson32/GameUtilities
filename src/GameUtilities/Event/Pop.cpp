#include "GameUtilities/Event/Pop.h"

namespace GU
{
    namespace Evt
    {
		Pop::Pop(const int newLine, const char* newFile):
		Event(2, newLine, newFile)
		{
			//ctor
		}

		Pop::~Pop()
		{
			//dtor
		}
	}
}
