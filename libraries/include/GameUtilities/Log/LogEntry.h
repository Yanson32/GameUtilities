#ifndef GAMEUTILITIES_LOG_ENTRY_H
#define GAMEUTILITIES_LOG_ENTRY_H
/*********************************************************************************//**
*	@author	        Wayne J Larson Jr.
*	@date 	        5/18/22
*	@description    The LogEntry class represents a log entry. It contains all data
*   `               needed to generate a log entry.
*************************************************************************************/
#include "log_export.h"
#include "GameUtilities/Log/Component/LogComponent.h"
#include <memory>
namespace GU
{
    namespace Log
    {
        class LOG_EXPORT LogEntry
        {
            public:
                /*********************************************************************************//**
                *	@brief  Constructor 
                *************************************************************************************/
                LogEntry(const int &id = -1, const int &type = -1);
                

                /*********************************************************************************//**
                *	@brief  This method is used to add a LogComponent to the LogEvent. 
                *************************************************************************************/
                void add(std::shared_ptr<GU::Log::LogComponent> component);
                

                /*********************************************************************************//**
                *	@brief  This method is for convinience it uses perfect forwarding to add a 
                *           LogComponet to the entry.
                *************************************************************************************/
                template<typename Type, typename... Args>
                void add(Args&&... args);
                

                /*********************************************************************************//**
                *	@brief  This method returns the number of log components.
                *   @return The number of log components. 
                *************************************************************************************/
                std::size_t size() const;
                
                int getId() const;
                int getType() const;
                /*********************************************************************************//**
                *	@brief  This method returns a pointer to a LogComponent at the given index. 
                *   @param  index is the index of the LogComponent to be returned. 
                *   @return A LogComponent pointer. 
                *************************************************************************************/
                std::shared_ptr<LogComponent> operator [] (const std::size_t &index);
                

                /*********************************************************************************//**
                *	@brief  Destructor 
                *************************************************************************************/
                virtual ~LogEntry();
            private:
                class Impl;
                Impl* m_pimpl = nullptr;
        };

        
        /*********************************************************************************//**
        *	@brief  This method is for convinience it uses perfect forwarding to add a 
        *           LogComponet to the entry.
        *************************************************************************************/
        template<typename Type, typename... Args>
        void LogEntry::add(Args&&... args)
        {
            this->add(std::shared_ptr<GU::Log::LogComponent>(new Type(std::forward<Args>(args)...)));
        }
    }
}

#endif
