#ifndef GAMEUTILITIES_LOG_LOGMANAGER_H
#define GAMEUTILITIES_LOG_LOGMANAGER_H
/*********************************************************************************//**
*	@author	        Wayne J Larson Jr.
*	@date 	        5/20/22
*	@description    The purpose of this class is to write log entries to a log file. 
*************************************************************************************/

#include "GameUtilities/Log/Target/LogTarget.h"
#include "GameUtilities/Log/LogFormatter.h"
#include "GameUtilities/Log/LogEntry.h"
#include "log_export.h"
#include <cstddef>
#include <memory>

namespace GU
{
    namespace Log
    {
        class LOG_EXPORT LogManager
  	    {
  	        public:
                /*********************************************************************************//**
                *	@brief  Constructor 
                *************************************************************************************/
                LogManager();
                

                /*********************************************************************************//**
                *	@brief  This  method adds a log target to the log manager. 
                *   @param  logTarget is the log target to be added to the log manager.
                *************************************************************************************/
                void add(std::shared_ptr<LogTarget> logTarget);
                

                /*********************************************************************************//**
                *	@brief  This method returns the log target at the given index. 
                *   @param  index is the current position of the log target to be returned. 
                *************************************************************************************/
                LogTarget& getTarget(const std::size_t &index);
                

                /*********************************************************************************//**
                *	@brief  This method removes the log target. 
                *   @param  logTarget The log target to be removed. 
                *************************************************************************************/
                bool remove(const LogTarget &logTarget);
                

                /*********************************************************************************//**
                *	@brief  This method returns the number of log targets currently stored in the 
                *           log manager. 
                *   @return The number of log targets currently stored in the log manager. 
                *************************************************************************************/
                std::size_t getTargetCount() const;
                

                /*********************************************************************************//**
                *	@brief  This method writes a string to the log file.
                *   @param  msg is the string to be written to the log file. 
                *************************************************************************************/
                void write(const GU::Core::String &msg);
                

                /*********************************************************************************//**
                *	@brief  This method writes a log entry to the log file. 
                *   @param  entry is the log entry to be written to the log file. 
                *************************************************************************************/
                void write(std::shared_ptr<LogEntry> entry);
                

                /*********************************************************************************//**
                *	@brief  This method sets the log formatter for the log manager.  
                *   @param  logFormatter is the log formatter to be used by the log manager. 
                *************************************************************************************/
                void set(LogFormatter &logFormatter);
                

                /*********************************************************************************//**
                *	@brief  This method returns the log formatter currently being used by the log 
                *           manager. 
                *************************************************************************************/
                LogFormatter& getFormatter();
                

                /*********************************************************************************//**
                *	@brief  Destructor 
                *************************************************************************************/
                virtual ~LogManager();
  	        private:
                class Impl;
                Impl* m_pimpl = nullptr;
        };
    }
}
#endif
