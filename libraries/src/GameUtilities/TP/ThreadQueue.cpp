#include "GameUtilities/TP/ThreadQueue.h"
#include <cassert>
#include <iostream>

namespace GU
{
    namespace Thread
    {
        /********************************************************************//**
        *   @brief  Constructor
        ************************************************************************/
        ThreadPoolQueue::ThreadPoolQueue()
        {

        }


        /********************************************************************//**
        *   @brief  Add a task to the queue
        *   @param  A unique pointer to a task to be completed.
        ************************************************************************/
        void ThreadPoolQueue::add(std::unique_ptr<ThreadPoolTask> newTask)
        {

            std::lock_guard<std::mutex> lock(mutex);
            assert(newTask != nullptr);
            taskQueue.push(std::move(newTask));
        }


        /********************************************************************//**
        *   @brief  Remove a task from the queue.
        *   @return A pointer to the removed task.
        ************************************************************************/
        std::unique_ptr<ThreadPoolTask> ThreadPoolQueue::pop()
        {
            std::lock_guard<std::mutex> lock(mutex);
            assert(!taskQueue.empty());
            std::unique_ptr<ThreadPoolTask> task = std::move(taskQueue.front());
            assert(task != nullptr);
            taskQueue.pop();
            return std::move(task);
        }


        /********************************************************************//**
        *   @brief  Determine if the queue is empty.
        *   @return True is returned if the queue is empty and false otherwise.
        ************************************************************************/
        bool ThreadPoolQueue::empty()
        {
            std::lock_guard<std::mutex> lock(mutex);
            return taskQueue.empty();
        }


        /********************************************************************//**
        *   @brief  Get the number of tasks currently in the queue.
        *   @return The number of tasks in the queue
        ************************************************************************/
        std::size_t ThreadPoolQueue::size()
        {
            std::lock_guard<std::mutex> lock(mutex);
            return taskQueue.size();
        }


        /********************************************************************//**
        *   @brief  Destructor
        ************************************************************************/
        ThreadPoolQueue::~ThreadPoolQueue()
        {

        }
    }
}
