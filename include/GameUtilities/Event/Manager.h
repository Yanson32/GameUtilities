/*********************************************************************************//**
*	\author	Wayne J Larson Jr.
*	\date 	12/10/17
*************************************************************************************/

#ifndef GAMEUTILITIES_EVENT_MANAGER_H
#define GAMEUTILITIES_EVENT_MANAGER_H
#include "gameutilities_export.h"
#include "GameUtilities/Event/EventQueue.h"
#include "GameUtilities/Event/Dispatcher.h"
namespace Evt
{

	/*********************************************************************************//**
	*	\brief	This class is usded as the central location where the games events
	*			are managed.
	*	\class 	Manager
	*************************************************************************************/
    class GAMEUTILITIES_EXPORT Manager: public Evt::EventQueue, public Evt::Dispatcher
    {
        public:

            /**************************************************************************
            *	\brief	Constructor
            **************************************************************************/
            Manager();


            /**************************************************************************
            *	\brief	Destructor
            **************************************************************************/
            virtual ~Manager();
    };

}
#endif // Event_MANAGER_H
