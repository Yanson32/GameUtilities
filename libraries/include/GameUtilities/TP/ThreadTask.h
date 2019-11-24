#ifndef THREAD_POOL_TASK_H
#define THREAD_POOL_TASK_H
#include "threadpool_export.h"

namespace GU
{
    namespace Thread
    {

        /************************************************************************//**
        *   @brief  This class is the base class for all tasks in the queue.
        *   @author Wayne J Larson Jr.
        *   @date
        ****************************************************************************/
        class THREADPOOL_EXPORT ThreadPoolTask
        {
            public:
                /********************************************************************//**
                *   @brief  Constructor
                ************************************************************************/
                ThreadPoolTask();


                /********************************************************************//**
                *   @brief  This method contains the code to be executed.
                ************************************************************************/
                virtual void run() = 0;

                /********************************************************************//**
                *   @brief  Destructor
                ************************************************************************/
                virtual ~ThreadPoolTask();
            private:
        };
    }
}
#endif
