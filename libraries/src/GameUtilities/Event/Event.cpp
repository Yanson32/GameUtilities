/*!
*	\author Wayne J Larson Jr.
*	\version 1.0
*	\date 12/10/17
*/

#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

        /**************************************************************************
        *	\brief	Event class constructor is not public to prevent it from
        *         	being instantiated accidentally.
        *   \brief 	param: const int the id of the event.
        **************************************************************************/
        Event::Event(const int newId, const int newLine, const GU::Core::String &newFile):
		m_id(newId),
		m_line(newLine),
		m_file(newFile)
        {

        }

        
        int Event::getId() const
        {
          return m_id;
        }


        int Event::getLine() const
        {
          return m_line;
        }


        GU::Core::String Event::getFile() const
        {
          return m_file;
        }


        /**************************************************************************
        *   \brief	Virtual Destructor
        **************************************************************************/
        Event::~Event()
        {

        }
    }
}
