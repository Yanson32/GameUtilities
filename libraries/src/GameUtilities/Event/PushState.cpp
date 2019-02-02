#include "GameUtilities/Event/PushState.h"
#include "GameUtilities/Event/Id.h"

namespace GU
{
    namespace Evt
    {

		PushState::PushState(const int newStateId, const int newLine, const char* newFile):
		Event(GU::Evt::Id::PUSH_STATE, newLine, newFile),
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
