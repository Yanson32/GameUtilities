#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include <vector>
#include <thread>
#include <condition_variable>
#include "GameUtilities/TP/ThreadQueue.h"
#include "threadpool_export.h"
namespace GU
{
    namespace Thread
    {
        /************************************************************************//**
        *   @brief  This class manages available threads
        *   @author Wayne J Larson Jr.
        *   @date   11/23/19
        ****************************************************************************/
        class THREADPOOL_EXPORT ThreadPool
        {
            public:

                /************************************************************************//**
                *   @brief  Constructor
                *   @param  The number of threads to be alloted. This must be less than
                *           std::thread::hardware_cuncurrency
                ****************************************************************************/
                ThreadPool(const unsigned &newNumThreads);


                /************************************************************************//**
                *   @brief  Queue a new task.
                *   @param  An object that contains a task to be completed.
                ****************************************************************************/
                void add(std::unique_ptr<ThreadPoolTask> newTask);


                /************************************************************************//**
                *   @brief  Run all previously added tasks
                ****************************************************************************/
                void execute();


                /************************************************************************//**
                *   @brief  Destructor.
                ****************************************************************************/
                virtual ~ThreadPool();
            private:

                /************************************************************************//**
                *   @brief  Each thread executes this method. The method causes the thread
                *           to wait for a task to execute.
                ****************************************************************************/
                void waitForTask();
                std::vector<std::thread> threads;
                std::condition_variable cv;
                const unsigned numThreads = 0;
                Thread::ThreadPoolQueue queue;
                bool wait = true;
        };
    }
}
#endif
