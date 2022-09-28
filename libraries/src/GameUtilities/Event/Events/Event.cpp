#include "GameUtilities/Event/Events/Event.h"

namespace GU
{
    namespace Evt
    {

        /**************************************************************************
        *	@brief	Event class constructor is not public to prevent it from
        *         	being instantiated accidentally.
        *   @param 	id the id of the event.
        *   @param  line is the line in source code where the event originated from.
        *   @param  file is the source file where the event originated from
        **************************************************************************/
        Event::Event(const int id, const int line, const GU::Core::String &file):
		m_id(id),
		m_line(line),
		m_file(file)
        {

        }

        
        /**************************************************************************
        *   @brief	This method returns the id of the event.
        *   @return A unique identifier for the event.  
        **************************************************************************/
        int Event::getId() const
        {
          return m_id;
        }


        /**************************************************************************
        *   @brief  This method returns the line in source code where the event
        *           originated from.	
        *   @return The line where the event originated from 
        **************************************************************************/
        int Event::getLine() const
        {
          return m_line;
        }


        /**************************************************************************
        *   @brief  This method returns the source file where the event originated from.
        *   @return The source file where the event originated from.
        **************************************************************************/
        GU::Core::String Event::getFile() const
        {
          return m_file;
        }


        /**************************************************************************
        *   \brief	Destructor
        **************************************************************************/
        Event::~Event()
        {

        }
    }
}
