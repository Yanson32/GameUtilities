#include "GameUtilities/Event/Events/OnChangeState.h"
#include "GameUtilities/Event/EventId.h"
namespace GU
{
    namespace Evt
    {

        /*******************************************************//**
        *   @brief  Constructor
        *   @param  stateId a unique identifier of the new state
        *   @param  line the line where the event originates from
        *   @param  file the file where the event originates from
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
