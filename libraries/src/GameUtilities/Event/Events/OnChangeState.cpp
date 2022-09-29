#include "GameUtilities/Event/Events/OnChangeState.h"
#include "GameUtilities/Event/EventId.h"
namespace GU
{
    namespace Evt
    {

        /*******************************************************//**
        *   @brief  Constructor
        *   @param  newStateId a unique identifier of the new state
        *   @param  newLine the line where the event originates from
        *   @param  newFile the file where the event originates from
        ***********************************************************/
		OnChangeState::OnChangeState(const int newStateId, const int newLine, const char* newFile):
		Event(static_cast<int>(GU::Evt::EventId::CHANGE_STATE), newLine, newFile),
		stateId(newStateId)
		{
			//ctor
		}


        /*******************************************************//**
        *   @brief  Destructor
        ***********************************************************/
		OnChangeState::~OnChangeState()
		{
			//dtor
		}
	}
}
