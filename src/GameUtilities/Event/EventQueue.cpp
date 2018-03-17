/*!
*	\author Wayne J Larson Jr.
*	\version 1.0
*	\date 12/10/17
*/

#include "GameUtilities/Event/EventQueue.h"
#include <cassert>

namespace GU
{
    namespace Evt
    {
        /***************************************************************************
        *   \brief	Constructor:
        ***************************************************************************/
        EventQueue::EventQueue()
        {
            //ctor
        }


        /***************************************************************************
        *   \brief	This method adds an event to the event queue.
        *   \brief 	param: EventPtr a pointer to an event to be added.
        ***************************************************************************/
        void EventQueue::Post(EventPtr event)
        {
            assert(event != nullptr);
            std::lock_guard<std::mutex> lock(eventQueueLock);
            eventQueue.push(event);
        }


        /***************************************************************************
        *   \brief	This method returns a boolean value indicating whether
        *         	there is an event in the queue or not.
        *   \brief 	bool true if there is an event in the queue.
        ***************************************************************************/
        bool EventQueue::empty() const
        {
            return eventQueue.empty();
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
            std::lock_guard<std::mutex> lock(eventQueueLock);
            if(!eventQueue.empty())
            {
                event = eventQueue.front();
                assert(event != nullptr);
                eventQueue.pop();
                return true;
            }
            return false;
        }


        /***************************************************************************
        *   brief	Virtual destructor
        ***************************************************************************/
        EventQueue::~EventQueue()
        {
            //dtor
        }
    }
}
