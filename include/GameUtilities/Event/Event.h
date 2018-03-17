/*********************************************************************************//**
*	\author	Wayne J Larson Jr.
*	\date 	12/10/17
*************************************************************************************/

#ifndef GAMEUTILITIES_EVENT_EVENT_H
#define GAMEUTILITIES_EVENT_EVENT_H
#include "gameutilities_export.h"
#include <memory>
#include <string>

namespace GU
{
    namespace Evt
    {
        const int ALL = -1;

        /*********************************************************************************//**
        *	\brief	This class is a base class for all events and should not be instantiated.
        *	\class 	Event
        *************************************************************************************/
        struct GAMEUTILITIES_EXPORT Event
        {
                const int id = 0;

                /**************************************************************************
                *   \brief	Destructor
                **************************************************************************/
                virtual ~Event();


            protected:

                /**************************************************************************
                *	\brief	Event class constructor is not public to prevent it from
                *         	being instantiated accidentally.
                *   \param 	newId the id of the event.
                **************************************************************************/
                Event(const int newLine = 0, const std::string newFile = "", const int newId = ALL);
				std::string file;
				int line = 0;

				
        };

        typedef std::shared_ptr<Event> EventPtr;
    }
}
#endif // EVENT_H
