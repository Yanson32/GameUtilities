#include "GameUtilities/Event/PushState.h"

namespace GU
{
    namespace Evt
    {

		PushState::PushState(const int newStateId, const int newLine, const std::string newFile):
		Event(1, newLine, newFile),
		id(newStateId)
		{
			//ctor
		}

		PushState::~PushState()
		{
			//dtor
		}
	}
}
