/*********************************************************************************//**
*	\author	Wayne J Larson Jr.
*	\date 	12/10/17
*************************************************************************************/

#ifndef GAMEUTILITIES_EVENT_MANAGER_H
#define GAMEUTILITIES_EVENT_MANAGER_H
#include "event_export.h"
#include "GameUtilities/Event/EventQueue.h"
#include "GameUtilities/Event/Dispatcher.h"

namespace GU
{
    namespace Evt
    {

        /*********************************************************************************//**
        *	\brief	This class is usded as the central location where the games events
        *			are managed.
        *	\class 	Manager
        *************************************************************************************/
        class EVENT_EXPORT EventManager: public Evt::EventQueue, public Evt::Dispatcher
        {
            public:

                /**************************************************************************
                *	\brief	Constructor
                **************************************************************************/
                EventManager();


                /**************************************************************************
                *	\brief	Destructor
                **************************************************************************/
                virtual ~EventManager();

                static EventManager& inst();

                EventManager operator = (const EventManager eventManager) = delete;
                EventManager(const EventManager &EventManager) = delete;
        };

    }
}
#endif // Event_MANAGER_H
