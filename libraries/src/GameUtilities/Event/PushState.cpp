#include "GameUtilities/Event/PushState.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {

		PushState::PushState(const int newStateId, const int newLine, const char* newFile):
		Event(static_cast<int>(GU::Evt::EventId::PUSH_STATE), newLine, newFile),
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
