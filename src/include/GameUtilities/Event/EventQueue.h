#ifndef GAMEUTILITIES_EVENT_EVENTQUEUE_H
#define GAMEUTILITIES_EVENT_EVENTQUEUE_H
#include "GameUtilities/Event/Event.h"
#include "gameutilities_export.h"

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
		class GAMEUTILITIES_EXPORT EventQueue
		{
		public:
			/***************************************************************************
			*   Constructor:
			***************************************************************************/
			EventQueue();

			EventQueue(const EventQueue &queue);

			EventQueue(EventQueue&& param);

			EventQueue& operator=(EventQueue&& param);

			
			/***************************************************************************
			*   Purpose:    This method adds an event to the event queue.
			*   Input:      EventPtr a pointer to an event to be added.
			***************************************************************************/
			void Post(EventPtr event);


			/***************************************************************************
			*   Purpose:    This method adds an event to the event queue. The event
			*               will be constructed internally based on the input parameters
			*   Input:      typename Type the type of event to be constructed.
			*               typename.. Args an arbitrary type, and number of arguments
			*               passed to the constructor of the event.
			***************************************************************************/
			template<typename Type, typename... Args>
			void Post(Args&&... args);


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
			bool Poll(EventPtr &event);


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
		void EventQueue::Post(Args&&... args)
		{
			this->Post(EventPtr(new T(std::forward<Args>(args)...)));
		}

	}

}
#endif // EVENTQUEUE_H
