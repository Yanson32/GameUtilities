#ifndef GAMEUTILITIES_EVENT_EVENTQUEUE_H
#define GAMEUTILITIES_EVENT_EVENTQUEUE_H
/*********************************************************************************//**
*	@author	        Wayne J Larson Jr.
*	@date 	        12/10/18
*	@description    This class creates a queue for pushing and popping events. 
*************************************************************************************/

/*************************************************************************
*                           COPYRIGHT NOTICE
* GameUtilities is a toolkit for making 2d video games.
* Copyright (C) 2018 Wayne J Larson Jr. 
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 3 as 
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
***************************************************************************/
#include "GameUtilities/Event/Event.h"
#include "event_export.h"

namespace GU
{
	namespace Evt
	{
		typedef std::shared_ptr<Event> EventPtr;

		/***************************************************************************
		*   Author:     Wayne J Larson Jr.
		*   Date:       2/8/17
		*   Purpose:    This class provides a queue for events.
		***************************************************************************/
		class EVENT_EXPORT EventQueue
		{
		public:
			/***************************************************************************
			*   @breif: Constructor 
			***************************************************************************/
			EventQueue();

		
        	/***************************************************************************
			*   @brief: Copy constructor 
            *   @param: queue the EventQueue to be copied
			***************************************************************************/
			EventQueue(const EventQueue &queue);

			
        	/***************************************************************************
			*   @brief: Move constructor.
            *   @param: param the EventQueue to be moved. 
			***************************************************************************/
			EventQueue(EventQueue&& param);

            
            /***************************************************************************
			*   @brief:     Assignment operator.
            *   @param:     param is the EventQueue to be copied.
            *   @return:    A reference to the updated EventQueue. 
			***************************************************************************/
			EventQueue& operator=(EventQueue&& param);

			
			/***************************************************************************
			*   Purpose:    This method adds an event to the event queue.
			*   Input:      EventPtr a pointer to an event to be added.
			***************************************************************************/
			void post(EventPtr event);


			/***************************************************************************
			*   Purpose:    This method adds an event to the event queue. The event
			*               will be constructed internally based on the input parameters
			*   Input:      typename Type the type of event to be constructed.
			*               typename.. Args an arbitrary type, and number of arguments
			*               passed to the constructor of the event.
			***************************************************************************/
			template<typename Type, typename... Args>
			void post(Args&&... args);


			/***************************************************************************
			*   Purpose:    This method returns a boolean value indicating whether
			*               there is an event in the queue or not.
			*   Return:     bool true if there is an event in the queue.
			***************************************************************************/
			bool empty() const;


			/***************************************************************************
			*   Purpose:    This method is used to remove an event from the queue.
			*   Input:      EventPtr a pointer to the event taken from the queue.
			*               This will be a = to nullptr if there are no events to be
			*               removed.
			*   Return:     bool true if an event has been taken from the queue, and
			*               false otherwise.
			***************************************************************************/
			bool poll(EventPtr &event);


			/***************************************************************************
			*   Virtual destructor:
			***************************************************************************/
			virtual ~EventQueue();
		private:

			class impl;
			impl* pimpl = nullptr;
		};


		/***************************************************************************
		*   Purpose:    This method adds an event to the event queue. The event
		*               will be constructed internally based on the input parameters
		*   Input:      typename Type the type of event to be constructed.
		*               typename.. Args an arbitrary type, and number of arguments
		*               passed to the constructor of the event.
		***************************************************************************/
		template<typename T, typename... Args>
		void EventQueue::post(Args&&... args)
		{
			this->post(EventPtr(new T(std::forward<Args>(args)...)));
		}

	}

}
#endif // EVENTQUEUE_H