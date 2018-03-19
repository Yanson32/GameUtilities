#include "GameUtilities/Event/ChangeState.h"

namespace GU
{
    namespace Evt
    {
		ChangeState::ChangeState(const int newStateId, const int newLine, const char* newFile):
		Event(0, newLine, newFile),
		stateId(newStateId)
		{
			//ctor
		}

		ChangeState::~ChangeState()
		{
			//dtor
		}
	}
}
