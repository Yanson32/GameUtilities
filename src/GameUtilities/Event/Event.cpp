/*!
*	\author Wayne J Larson Jr.
*	\version 1.0
*	\date 12/10/17
*/

#include "GameUtilities/Event/Event.h"


namespace Evt
{

    /**************************************************************************
    *	\brief	Event class constructor is not public to prevent it from
    *         	being instantiated accidentally.
    *   \brief 	param: const int the id of the event.
    **************************************************************************/
    Event::Event(const int newId): id(newId)
    {

    }


    /**************************************************************************
    *   \brief	Virtual Destructor
    **************************************************************************/
    Event::~Event()
    {

    }
}
