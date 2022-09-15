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
				void post(EventPtr event);
				bool empty() const;
				bool poll(EventPtr &event);
				virtual ~impl();
			private:
				std::queue<EventPtr> eventQueue;

				#ifdef MULTITHREAD
					mutable std::mutex eventQueueLock;
				#endif
		};

		//EventQueue constructor
		EventQueue::impl::impl()
		{

		}

		//Post implimentation
		void EventQueue::impl::post(EventPtr event)
		{
			assert(event != nullptr);
			#ifdef MULTITHREAD
				std::lock_guard<std::mutex> lock(eventQueueLock);
			#endif

			eventQueue.push(event);
		}

		//empty implimentation
		bool EventQueue::impl::empty() const
		{
			return eventQueue.empty();
		}

		//Poll Implimentation
		bool EventQueue::impl::poll(EventPtr &event)
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

		//Destructor
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

		EventQueue::EventQueue(const EventQueue &queue)
		{
            assert(pimpl != nullptr);
			pimpl = queue.pimpl;
		}

		EventQueue::EventQueue(EventQueue&& param)
		{
            assert(pimpl != nullptr);
			pimpl = param.pimpl;
		}

		EventQueue& EventQueue::operator=(EventQueue&& param)
		{
            assert(pimpl != nullptr);
			pimpl = param.pimpl;

			return *this;
		}

        /***************************************************************************
        *   \brief	This method adds an event to the event queue.
        *   \brief 	param: EventPtr a pointer to an event to be added.
        ***************************************************************************/
        void EventQueue::post(EventPtr event)
        {
            assert(pimpl != nullptr);
			pimpl->post(event);
        }


        /***************************************************************************
        *   \brief	This method returns a boolean value indicating whether
        *         	there is an event in the queue or not.
        *   \brief 	bool true if there is an event in the queue.
        ***************************************************************************/
        bool EventQueue::empty() const
        {
            assert(pimpl != nullptr);
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
        bool EventQueue::poll(EventPtr &event)
        {
            assert(pimpl != nullptr);
			return pimpl->poll(event);
        }


        /***************************************************************************
        *   brief	Virtual destructor
        ***************************************************************************/
        EventQueue::~EventQueue()
        {
            //dtor
			if (pimpl != nullptr)
            {
				delete pimpl;
                pimpl = nullptr;
            }
        }

    }
}
