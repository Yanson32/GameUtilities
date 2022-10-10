#include "GameUtilities/Event/Events/OnPop.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {
        /**************************************************************************
        *   @brief  Constructor
        *   @param  id is the unique identifier for the pop event.
        *   @param  line is the line number where the event originated from
        *   @param  file is the file where the event originated from
        **************************************************************************/
		OnPop::OnPop(const int &popId, const int &line, const char* file):
		Event(static_cast<int>(GU::Evt::EventId::POP_STATE), line, file),
        m_popId(popId)
		{
			//ctor
		}

        
        /**************************************************************************
        *   @brief  Deconstructor 
        **************************************************************************/
		OnPop::~OnPop()
		{
			//dtor
		}
	}
}
