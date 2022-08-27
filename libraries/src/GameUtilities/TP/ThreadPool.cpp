#include "GameUtilities/TP/ThreadPool.h"
#include <cassert>
#include <memory>
#include <iostream>
#include <vector>
#include <thread>
#include <condition_variable>
#include <cassert>

namespace GU
{
    namespace Thread
    {



        class ThreadPool::Impl
        {
            public:
                std::vector<std::thread> m_threads;
                std::condition_variable m_cv;
                Thread::ThreadPoolQueue m_queue;
                bool m_wait = true;
        };


        /************************************************************************//**
        *   @brief  Constructor
        *   @param  The number of threads to be alloted. This must be less than
        *           std::thread::hardware_cuncurrency
        ****************************************************************************/
        ThreadPool::ThreadPool(const unsigned &newNumThreads):
        m_pimpl(new ThreadPool::Impl())
        {
            assert(m_pimpl != nullptr);
            assert(newNumThreads < std::thread::hardware_concurrency());
            assert(newNumThreads > 0);
            for(std::size_t i = 0; i < newNumThreads; ++i)
            {
                m_pimpl->m_threads.emplace_back(&ThreadPool::waitForTask, this);
            }

        }


        /************************************************************************//**
        *   @brief  Queue a new task.
        *   @param  An object that contains a task to be completed.
        ****************************************************************************/
        void ThreadPool::add(std::unique_ptr<ThreadPoolTask> newTask)
        {
            assert(newTask != nullptr);
            m_pimpl->m_queue.add(std::move(newTask));
        }


        /************************************************************************//**
        *   @brief  Returns the total number of threads available in the pool
        *   @return The total number of threads available in the pool
        ****************************************************************************/
        std::size_t ThreadPool::size() const
        {
            assert(m_pimpl != nullptr);
            return m_pimpl->m_threads.size();
        }


        /************************************************************************//**
        *   @brief  Run all previously added tasks
        ****************************************************************************/
        void ThreadPool::execute()
        {
            assert(m_pimpl != nullptr);
            while(!m_pimpl->m_queue.empty())
            {
                m_pimpl->m_cv.notify_one();
            }

            m_pimpl->m_wait = false;
            m_pimpl->m_cv.notify_all();
        }


        /************************************************************************//**
        *   @brief  Each thread executes this method. The method causes the thread
        *           to wait for a task to execute.
        ****************************************************************************/
        void ThreadPool::waitForTask()
        {
            assert(m_pimpl != nullptr);
            std::mutex mute;
            std::unique_lock<std::mutex> lock(mute);

            while(m_pimpl->m_wait)
            {
                m_pimpl->m_cv.wait(lock);
                if(!m_pimpl->m_queue.empty())
                {
                    std::unique_ptr<Thread::ThreadPoolTask> task(m_pimpl->m_queue.pop());
                    assert(task != nullptr);
                    task->run();
                }
            }

        }


        /************************************************************************//**
        *   @brief  Destructor.
        ****************************************************************************/
        ThreadPool::~ThreadPool()
        {
            assert(m_pimpl != nullptr);
            for(auto it = m_pimpl->m_threads.begin(); it != m_pimpl->m_threads.end(); ++it)
            {
                it->join();
            }
            if(m_pimpl != nullptr)
                delete m_pimpl;
        }
    }
}
