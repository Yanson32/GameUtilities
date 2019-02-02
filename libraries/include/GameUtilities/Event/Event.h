/*********************************************************************************//**
*	\author	Wayne J Larson Jr.
*	\date 	12/10/17
*************************************************************************************/

#ifndef GAMEUTILITIES_EVENT_EVENT_H
#define GAMEUTILITIES_EVENT_EVENT_H
#include "gameutilities_export.h"
#include <memory>

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

				const char* file;
				int line = 0;
            protected:

                /**************************************************************************
                *	\brief	Event class constructor is not public to prevent it from
                *         	being instantiated accidentally.
                *   \param 	newId the id of the event.
                **************************************************************************/
                Event(const int newId = ALL, const int newLine = 0, const char* newFile = "");

        };

        typedef std::shared_ptr<Event> EventPtr;
    }
}
#endif // EVENT_H
