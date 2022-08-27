#include "GameUtilities/Event/PushState.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {

        /*******************************************************//**
        *   @brief  Constructor
        *   @param  stateId is the unique identifier for the state.
        *   @param  line is the line in source code where the 
        *           event was generated.
        *   @param  file is the source file where the event was
        *           generated.
        ***********************************************************/
		PushState::PushState(const int stateId, const int line, const char* file):
		Event(static_cast<int>(GU::Evt::EventId::PUSH_STATE), line, file),
		m_id(stateId)
		{
			//ctor
		}

        
        /*******************************************************//**
        *   @brief  Destructor 
        ***********************************************************/
		PushState::~PushState()
		{
			//dtor
		}
	}
}
