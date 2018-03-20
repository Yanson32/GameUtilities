/*!
*	\author Wayne J Larson Jr.
*	\version 1.0
*	\date 12/10/17
*/

#include "GameUtilities/Event/EventQueue.h"
#include <cassert>
#include <queue>
#include <mutex>

namespace GU
{
    namespace Evt
    {

		class EventQueue::impl
		{
			public:
				impl();
				void Post(EventPtr event);
				bool empty() const;
				bool Poll(EventPtr &event);
				virtual ~impl();
			private:
				std::queue<EventPtr> eventQueue;

				#ifdef MULTITHREAD
					mutable std::mutex eventQueueLock;
				#endif
		};

		EventQueue::impl::impl()
		{

		}

		void EventQueue::impl::Post(EventPtr event)
		{
			assert(event != nullptr);
			#ifdef MULTITHREAD
				std::lock_guard<std::mutex> lock(eventQueueLock);
			#endif

			eventQueue.push(event);
		}

		bool EventQueue::impl::empty() const
		{
			return eventQueue.empty();
		}

		bool EventQueue::impl::Poll(EventPtr &event)
		{
			#ifdef MULTITHREAD
				std::lock_guard<std::mutex> lock(eventQueueLock);
			#endif

			if (!eventQueue.empty())
			{
				event = eventQueue.front();
				assert(event != nullptr);
				eventQueue.pop();
				return true;
			}
			return false;
		}

		EventQueue::impl::~impl()
		{

		}
        /***************************************************************************
        *   \brief	Constructor:
        ***************************************************************************/
        EventQueue::EventQueue(): pimpl(new EventQueue::impl)
        {
            //ctor
        }


        /***************************************************************************
        *   \brief	This method adds an event to the event queue.
        *   \brief 	param: EventPtr a pointer to an event to be added.
        ***************************************************************************/
        void EventQueue::Post(EventPtr event)
        {
			pimpl->Post(event);
        }


        /***************************************************************************
        *   \brief	This method returns a boolean value indicating whether
        *         	there is an event in the queue or not.
        *   \brief 	bool true if there is an event in the queue.
        ***************************************************************************/
        bool EventQueue::empty() const
        {
			return pimpl->empty();
        }


        /***************************************************************************
        *   \brief	This method is used to remove an event from the queue.
        *   \brief 	param: EventPtr a pointer to the event taken from the queue.
        *           This will be a = to nullptr if there are no events to be
        *           removed.
        *   \brief  Return: bool true if an event has been taken from the queue, and
        *           false otherwise.
        ***************************************************************************/
        bool EventQueue::Poll(EventPtr &event)
        {
			return pimpl->Poll(event);
        }


        /***************************************************************************
        *   brief	Virtual destructor
        ***************************************************************************/
        EventQueue::~EventQueue()
        {
            //dtor
			if (pimpl)
				delete pimpl;
        }

    }
}
