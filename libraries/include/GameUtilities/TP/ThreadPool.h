#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include "GameUtilities/TP/ThreadQueue.h"
#include "threadpool_export.h"
namespace GU
{
    namespace Thread
    {
        /************************************************************************//**
        *   @brief  This class manages available threads.
        *   @author Wayne J Larson Jr.
        *   @date   11/23/19
        ****************************************************************************/
        class THREADPOOL_EXPORT ThreadPool
        {
            public:

                /************************************************************************//**
                *   @brief  Constructor.
                *   @param  numThreads The number of threads to be alloted. This must be less 
                *           than std::thread::hardware_cuncurrency.
                ****************************************************************************/
                ThreadPool(const unsigned &numThreads);


                /************************************************************************//**
                *   @brief  Queue a new task.
                *   @param  task An object that contains a task to be completed.
                ****************************************************************************/
                void add(std::unique_ptr<ThreadPoolTask> task);


                /************************************************************************//**
                *   @brief  Run all previously added tasks
                ****************************************************************************/
                void execute();


                /************************************************************************//**
                *   @brief  Returns the total number of threads available in the pool
                *   @return The total number of threads available in the pool
                ****************************************************************************/
                std::size_t size() const;

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

                class Impl;
                Impl *m_pimpl = nullptr;       /*!< pointer to the class implimentation */ 
        };
    }
}
#endif
