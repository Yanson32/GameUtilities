/*********************************************************************************//**
*	@author	        Wayne J Larson Jr.
*	@date 	        02/08/17
*	@class          EventQueue creates a queue for pushing and popping events. 
*	@file           EventQueue.cpp 
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
                /***********************************************************************//**
                *   @breif Constructor 
                ***************************************************************************/
				impl();
                

                /***********************************************************************//**
                *   @brief  This method adds an event to the event queue.
                *   @param  EventPtr a pointer to an event to be added.
                ***************************************************************************/
				void post(EventPtr event);
                

                /***********************************************************************//**
                *   @breif  This method returns a boolean value indicating whether
                *           there is an event in the queue or not.
                *   @return bool true if there is an event in the queue.
                ***************************************************************************/
				bool empty() const;
                

                /***********************************************************************//**
                *   @brief  This method is used to remove an event from the queue.
                *   @param  EventPtr a pointer to the event taken from the queue.
                *           This will be a = to nullptr if there are no events to be
                *           removed.
                *   @return bool true if an event has been taken from the queue, and
                *           false otherwise.
                ***************************************************************************/
				bool poll(EventPtr &event);
			

                /***********************************************************************//**
                *   @brief Destructor.
                ***************************************************************************/
				virtual ~impl();
			private:
				std::queue<EventPtr> m_eventQueue;        /*!< Queue data structure for the events */ 

				#ifdef MULTITHREAD
					mutable std::mutex m_eventQueueLock;  /*!< Mutex for the queue */ 
				#endif
		};

        
        /***********************************************************************//**
        *   @breif Constructor 
        ***************************************************************************/
		EventQueue::impl::impl()
		{

		}

        
        /***********************************************************************//**
        *   @brief  This method adds an event to the event queue.
        *   @param  EventPtr a pointer to an event to be added.
        ***************************************************************************/
		void EventQueue::impl::post(EventPtr event)
		{
			assert(event != nullptr);
			#ifdef MULTITHREAD
				std::lock_guard<std::mutex> lock(m_eventQueueLock);
			#endif

			m_eventQueue.push(event);
		}

        
        /***********************************************************************//**
        *   @breif  This method returns a boolean value indicating whether
        *           there is an event in the queue or not.
        *   @return bool true if there is an event in the queue.
        ***************************************************************************/
		bool EventQueue::impl::empty() const
		{
			return m_eventQueue.empty();
		}

        
        /***********************************************************************//**
        *   @brief  This method is used to remove an event from the queue.
        *   @param  EventPtr a pointer to the event taken from the queue.
        *           This will be a = to nullptr if there are no events to be
        *           removed.
        *   @return bool true if an event has been taken from the queue, and
        *           false otherwise.
        ***************************************************************************/
		bool EventQueue::impl::poll(EventPtr &event)
		{
			#ifdef MULTITHREAD
				std::lock_guard<std::mutex> lock(m_eventQueueLock);
			#endif

			if (!m_eventQueue.empty())
			{
				event = m_eventQueue.front();
				assert(event != nullptr);
				m_eventQueue.pop();
				return true;
			}
			return false;
		}

        
        /***********************************************************************//**
        *   @brief Destructor.
        ***************************************************************************/
		EventQueue::impl::~impl()
		{

		}
		

        /***********************************************************************//**
		*   @breif Constructor 
		***************************************************************************/
        EventQueue::EventQueue(): pimpl(new EventQueue::impl)
        {
            //ctor
        }

        
        /***********************************************************************//**
        *   @brief Copy constructor 
        *   @param queue the EventQueue to be copied
        ***************************************************************************/
		EventQueue::EventQueue(const EventQueue &queue)
		{
            assert(pimpl != nullptr);
			pimpl = queue.pimpl;
		}

        
        /***********************************************************************//**
        *   @brief Move constructor.
        *   @param param the EventQueue to be moved. 
        ***************************************************************************/
		EventQueue::EventQueue(EventQueue&& param)
		{
            assert(pimpl != nullptr);
			pimpl = param.pimpl;
		}

        
        /***********************************************************************//**
        *   @brief  Assignment operator.
        *   @param  param is the EventQueue to be copied.
        *   @return A reference to the updated EventQueue. 
        ***************************************************************************/
		EventQueue& EventQueue::operator=(EventQueue&& param)
		{
            assert(pimpl != nullptr);
			pimpl = param.pimpl;

			return *this;
		}

        
        /***********************************************************************//**
        *   @brief  This method adds an event to the event queue.
        *   @param  EventPtr a pointer to an event to be added.
        ***************************************************************************/
        void EventQueue::post(EventPtr event)
        {
            assert(pimpl != nullptr);
			pimpl->post(event);
        }


        /***********************************************************************//**
        *   @breif  This method returns a boolean value indicating whether
        *           there is an event in the queue or not.
        *   @return bool true if there is an event in the queue.
        ***************************************************************************/
        bool EventQueue::empty() const
        {
            assert(pimpl != nullptr);
			return pimpl->empty();
        }


        /***********************************************************************//**
        *   @brief  This method is used to remove an event from the queue.
        *   @param  EventPtr a pointer to the event taken from the queue.
        *           This will be a = to nullptr if there are no events to be
        *           removed.
        *   @return bool true if an event has been taken from the queue, and
        *           false otherwise.
        ***************************************************************************/
        bool EventQueue::poll(EventPtr &event)
        {
            assert(pimpl != nullptr);
			return pimpl->poll(event);
        }


        /***********************************************************************//**
        *   @brief Destructor.
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
