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
		OnChangeState::OnChangeState(const int &stateId, const int &line, const char* file):
		Event(static_cast<int>(GU::Evt::EventId::CHANGE_STATE), line, file),
		m_stateId(stateId)
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
