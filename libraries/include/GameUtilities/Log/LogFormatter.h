#ifndef GU_LOG_FORMATTER_H
#define GU_LOG_FORMATTER_H
/*********************************************************************************//**
*	@author	        Wayne J Larson Jr.
*	@date 	        5/19/22
*	@description    This class is used to format log entries.
*************************************************************************************/

#include "log_export.h"
#include "GameUtilities/Core/String.h"
#include "GameUtilities/Log/Component/ComponentId.h"
#include "GameUtilities/Log/LogEntry.h"
#include <memory>

namespace GU
{
    namespace Log
    {   

        class LogComponent;
  		class LOG_EXPORT LogFormatter
  		{
  	        public:
                /*********************************************************************************//**
                *	@brief  Constructor 
                *************************************************************************************/
  				LogFormatter();
                

                /*********************************************************************************//**
                *	@brief  This method adds a log component to the log formatter. The log component
                *           is used by the formatter to determine the order that the components will 
                *           be written to the log file. Components will be written to the log file
                *           in the same order they were added to the formatter.
                *   @param  component is the log component to be added to the log file. 
                *************************************************************************************/
                void add(std::shared_ptr<GU::Log::LogComponent> component);
                

                /*********************************************************************************//**
                *	@brief  This method adds a log component to the log formatter. The log component
                *           is used by the formatter to determine the order that the components will 
                *           be written to the log file. Components will be written to the log file
                *           in the same order they were added to the formatter.
                *   @param  component is the log component to be added to the log file. 
                *************************************************************************************/
                template<typename Type, typename... Args>
                void add(Args&&... args);
                

                /*********************************************************************************//**
                *	@brief  This method is used to initialize a log component. The log component should
                *           have been added previously with the add method. 
                *   @pre    A log component should be added with the add method.
                *   @param  component will be used to initialize the previously added log component. 
                *************************************************************************************/
                void init(std::shared_ptr<GU::Log::LogComponent> component);
                

                /*********************************************************************************//**
                *	@brief  This method return a component with the given id.
                *   @return A pointer to the log component with the given id. 
                *************************************************************************************/
                std::shared_ptr<LogComponent> getComponent(const componentId &component) const;
                

                /*********************************************************************************//**
                *	@brief  This method will return a string formatted correctly for the log file. 
                *   @return A string formatted correctly for the log file. 
                *************************************************************************************/
                virtual GU::Core::String format();
                

                /*********************************************************************************//**
                *	@brief  Destructor 
                *************************************************************************************/
  				virtual ~LogFormatter();
            private:
                class Impl;
                Impl* m_pimpl = nullptr;
  		};


        /*********************************************************************************//**
        *	@brief  This method adds a log component to the log formatter. The log component
        *           is used by the formatter to determine the order that the components will 
        *           be written to the log file. Components will be written to the log file
        *           in the same order they were added to the formatter.
        *   @param  component is the log component to be added to the log file. 
        *************************************************************************************/
        template<typename Type, typename... Args>
        void LogFormatter::add(Args&&... args)
        {
            this->add(std::shared_ptr<LogComponent>(new Type(std::forward<Args>(args)...)));
        }
	}
}

#endif
