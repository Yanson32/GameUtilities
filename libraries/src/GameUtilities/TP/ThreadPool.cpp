#include "GameUtilities/TP/ThreadPool.h"
#include <cassert>
#include <memory>
#include <iostream>

namespace GU
{
    namespace Thread
    {
        /************************************************************************//**
        *   @brief  Constructor
        *   @param  The number of threads to be alloted. This must be less than
        *           std::thread::hardware_cuncurrency
        ****************************************************************************/
        ThreadPool::ThreadPool(const unsigned &newNumThreads):
        numThreads(newNumThreads)
        {
            assert(numThreads < std::thread::hardware_concurrency());
            assert(numThreads > 0);
            for(std::size_t i = 0; i < numThreads; ++i)
            {
                threads.emplace_back(&ThreadPool::waitForTask, this);
            }

        }


        /************************************************************************//**
        *   @brief  Queue a new task.
        *   @param  An object that contains a task to be completed.
        ****************************************************************************/
        void ThreadPool::add(std::unique_ptr<ThreadPoolTask> newTask)
        {
            assert(newTask != nullptr);
            queue.add(std::move(newTask));
        }


        /************************************************************************//**
        *   @brief  Run all previously added tasks
        ****************************************************************************/
        void ThreadPool::execute()
        {
            while(!queue.empty())
            {
                cv.notify_one();
            }

            wait = false;
            cv.notify_all();
        }


        /************************************************************************//**
        *   @brief  Each thread executes this method. The method causes the thread
        *           to wait for a task to execute.
        ****************************************************************************/
        void ThreadPool::waitForTask()
        {
            std::mutex mute;
            std::unique_lock<std::mutex> lock(mute);

            while(wait)
            {
                cv.wait(lock);
                if(!queue.empty())
                {
                    std::unique_ptr<Thread::ThreadPoolTask> task(queue.pop());
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
            for(auto it = threads.begin(); it != threads.end(); ++it)
            {
                it->join();
            }
        }
    }
}
