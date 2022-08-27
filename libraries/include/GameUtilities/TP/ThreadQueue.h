#ifndef THREAD_POOL_QUEUE_H
#define THREAD_POOL_QUEUE_H

#include "threadpool_export.h"
#include "GameUtilities/TP/ThreadTask.h"
#include <queue>
#include <vector>
#include <memory>
#include <mutex>
namespace GU
{
    namespace Thread
    {
        /************************************************************************//**
        *   @brief  This class is used to create a queue of tasks to be completed
        *   `   `   by threads.
        *   @author Wayne J Larson Jr.
        *   @date
        ****************************************************************************/
        class THREADPOOL_EXPORT ThreadPoolQueue
        {
            public:

                /********************************************************************//**
                *   @brief  Constructor
                ************************************************************************/
                ThreadPoolQueue();


                /********************************************************************//**
                *   @brief  Add a task to the queue
                *   @param  A unique pointer to a task to be completed.
                ************************************************************************/
                void add(std::unique_ptr<ThreadPoolTask> newTask);


                /********************************************************************//**
                *   @brief  Remove a task from the queue.
                *   @return A pointer to the removed task.
                ************************************************************************/
                std::unique_ptr<ThreadPoolTask> pop();


                /********************************************************************//**
                *   @brief  Determine if the queue is empty.
                *   @return True is returned if the queue is empty and false otherwise.
                ************************************************************************/
                bool empty();


                /********************************************************************//**
                *   @brief  Get the number of tasks currently in the queue.
                *   @return The number of tasks in the queue
                ************************************************************************/
                std::size_t size();


                /********************************************************************//**
                *   @brief
                ************************************************************************/
                virtual ~ThreadPoolQueue();
            private:
                class Impl;
                Impl *m_pimpl = nullptr;
        };
    }
}
#endif
