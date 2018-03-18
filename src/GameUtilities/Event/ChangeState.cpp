#include "GameUtilities/Event/ChangeState.h"

namespace GU
{
    namespace Evt
    {
		ChangeState::ChangeState(const int newStateId, const int newLine, const std::string newFile):
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
