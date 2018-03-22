#include "GameUtilities/Event/ChangeState.h"
#include "GameUtilities/Event/Id.h"
namespace GU
{
    namespace Evt
    {
		ChangeState::ChangeState(const int newStateId, const int newLine, const char* newFile):
		Event(GU::Evt::Id::CHANGE_STATE, newLine, newFile),
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
