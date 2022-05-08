#ifndef GAMEUTILITIES_EVENT_EVENT_H
#define GAMEUTILITIES_EVENT_EVENT_H
/*********************************************************************************//**
*	\author	Wayne J Larson Jr.
*	\date 	12/10/17
*************************************************************************************/

#include "event_export.h"
#include <memory>
#include "GameUtilities/Core/String.h"

namespace GU
{
    namespace Evt
    {
        const int ALL = -1;

        /*********************************************************************************//**
        *	\brief	This class is a base class for all events and should not be instantiated.
        *	\class 	Event
        *************************************************************************************/
        struct EVENT_EXPORT Event
        {
                int getId() const;
                int getLine() const;
                GU::Core::String getFile() const;
                /**************************************************************************
                *   \brief	Destructor
                **************************************************************************/
                virtual ~Event();
            protected:
                const int m_id = 0;
                int m_line = 0;
                const GU::Core::String m_file;
                Event(const Event&) = delete;
                Event& operator = (const Event& ) = delete;
                /**************************************************************************
                *	\brief	Event class constructor is not public to prevent it from
                *         	being instantiated accidentally.
                *   \param 	newId the id of the event.
                **************************************************************************/
                Event(const int id = ALL, const int line = 0, const GU::Core::String &file = "");

        };

        typedef std::shared_ptr<Event> EventPtr;
    }
}
#endif // EVENT_H
