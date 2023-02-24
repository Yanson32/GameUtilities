#include "GameUtilities/TP/ThreadQueue.h"
#include <cassert>
#include <iostream>

namespace GU
{
    namespace Thread
    {
        class ThreadPoolQueue::Impl
        {
            public:
                std::queue<std::unique_ptr<ThreadPoolTask>> taskQueue;
                std::mutex mutex;
        };

        /********************************************************************//**
        *   @brief  Constructor
        ************************************************************************/
        ThreadPoolQueue::ThreadPoolQueue():
        m_pimpl(new ThreadPoolQueue::Impl())
        {
            assert(m_pimpl != nullptr);
        }


        /********************************************************************//**
        *   @brief  Add a task to the queue
        *   @param  task A unique pointer to a task to be completed.
        ************************************************************************/
        void ThreadPoolQueue::add(std::unique_ptr<ThreadPoolTask> task)
        {
            assert(m_pimpl != nullptr);
            std::lock_guard<std::mutex> lock(m_pimpl->mutex);
            assert(task != nullptr);
            m_pimpl->taskQueue.push(std::move(task));
        }


        /********************************************************************//**
        *   @brief  Remove a task from the queue.
        *   @return A pointer to the removed task.
        ************************************************************************/
        std::unique_ptr<ThreadPoolTask> ThreadPoolQueue::pop()
        {
            assert(m_pimpl != nullptr);
            assert(!m_pimpl->taskQueue.empty());
            std::lock_guard<std::mutex> lock(m_pimpl->mutex);
            std::unique_ptr<ThreadPoolTask> task = std::move(m_pimpl->taskQueue.front());
            assert(task != nullptr);
            m_pimpl->taskQueue.pop();
            return task;
        }


        /********************************************************************//**
        *   @brief  Determine if the queue is empty.
        *   @return True is returned if the queue is empty and false otherwise.
        ************************************************************************/
        bool ThreadPoolQueue::empty()
        {
            assert(m_pimpl != nullptr);
            std::lock_guard<std::mutex> lock(m_pimpl->mutex);
            return m_pimpl->taskQueue.empty();
        }


        /********************************************************************//**
        *   @brief  Get the number of tasks currently in the queue.
        *   @return The number of tasks in the queue
        ************************************************************************/
        std::size_t ThreadPoolQueue::size()
        {
            assert(m_pimpl != nullptr);
            std::lock_guard<std::mutex> lock(m_pimpl->mutex);
            return m_pimpl->taskQueue.size();
        }


        /********************************************************************//**
        *   @brief  Destructor
        ************************************************************************/
        ThreadPoolQueue::~ThreadPoolQueue()
        {
            assert(m_pimpl != nullptr);
            if(m_pimpl != nullptr)
            {
                delete m_pimpl;
                m_pimpl = nullptr;
            }
        }
    }
}
