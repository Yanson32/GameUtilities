#ifndef LOG_FILTER_H
#define LOG_FILTER_H
/*********************************************************************************//**
*	@author	        Wayne J Larson Jr.
*	@date 	        5/26/22
*	@description    This class is the base class for all Log Filters. 
*************************************************************************************/
#include "log_export.h"
#include "GameUtilities/Log/LogEntry.h"
#include "GameUtilities/Core/String.h"

namespace GU
{
    namespace Log
    {
        claSS LOG_EXPORT LogFilter
        {
            public:
                /*********************************************************************************//**
                *	@brief  Constructor 
                *************************************************************************************/
                LogFilter();
                

                /*********************************************************************************//**
                *	@brief  This method filters out unwanted log entries.
                *   @param  entry a pointer to a log entry to be filtered.
                *   @return True if the log entry should be filtered and false otherwise.
                *************************************************************************************/
                virtual bool filter(std::shared_ptr<GU::Log::LogEntry> entry) = 0;
                

                /*********************************************************************************//**
                *	@brief  Destructor 
                *************************************************************************************/
                virtual ~LogFilter();

        };
    }
}
#endif
