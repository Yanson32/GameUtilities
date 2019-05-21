#include "GameUtilities/Event/ChangeState.h"
#include "GameUtilities/Event/Id.h"
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
		ChangeState::ChangeState(const int newStateId, const int newLine, const char* newFile):
		Event(GU::Evt::Id::CHANGE_STATE, newLine, newFile),
		stateId(newStateId)
		{
			//ctor
		}


        /*******************************************************//**
        *   @brief  Destructor
        ***********************************************************/
		ChangeState::~ChangeState()
		{
			//dtor
		}
	}
}
