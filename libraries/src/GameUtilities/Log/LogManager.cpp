/*********************************************************************************//**
*	@author	 Wayne J Larson Jr.
*	@date 	 5/20/22
*   @class   LogManager
*   @file    LogManager.cpp
*	@brief   The purpose of this class is to write log entries to a log file. 
*************************************************************************************/

/*************************************************************************
*                           COPYRIGHT NOTICE
* GameUtilities is a toolkit for making 2d video games.
* Copyright (C) 2018 Wayne J Larson Jr. 
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 3 as 
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
***************************************************************************/
#include "GameUtilities/Log/LogManager.h"
#include "GameUtilities/Log/LogFormatter.h"
#include "GameUtilities/Core/Macros.h"
#include <vector>
#include <stdexcept>
#include <cassert>
#include <iostream>

namespace GU
{
    namespace Log
    {
        
		class LogManager::Impl
		{
			public:
                /*********************************************************************************//**
                *	@brief  Impl Constructor 
                *************************************************************************************/
				Impl();
                

                /*********************************************************************************//**
                *	@brief  This  method adds a log target to the Impl log manager. 
                *   @param  logTarget is the log target to be added to the Impl log manager.
                *************************************************************************************/
				void add(std::shared_ptr<GU::Log::LogTarget> logTarget);
                

                /*********************************************************************************//**
                *	@brief  This method returns the log target at the given index. 
                *   @param  index is the current position of the log target to be returned. 
                *************************************************************************************/
				LogTarget& getTarget(const std::size_t &index);
                

                /*********************************************************************************//**
                *	@brief  This method removes the log target. 
                *   @param  logTarget The log target to be removed. 
                *************************************************************************************/
				bool remove(const GU::Log::LogTarget &logTarget);
                

                /*********************************************************************************//**
                *	@brief  This method returns the number of log targets currently stored in the 
                *           Impl log manager. 
                *   @return The number of log targets currently stored in the Impl log manager. 
                *************************************************************************************/
				std::size_t getTargetCount() const;
                

                /*********************************************************************************//**
                *	@brief  This method sets the log formatter for the Impl log manager.  
                *   @param  logFormatter is the log formatter to be used by the Impl log manager. 
                *************************************************************************************/
				void set(std::shared_ptr<LogFormatter> logFormatter);
                

                /*********************************************************************************//**
                *	@brief  This method writes a string to the log file.
                *   @param  msg is the string to be written to the log file. 
                *************************************************************************************/
                void write(const GU::Core::String &msg);
                

                /*********************************************************************************//**
                *	@brief  This method writes a log entry to the log file. 
                *   @param  entry is the log entry to be written to the log file. 
                *************************************************************************************/
                void write(std::shared_ptr<GU::Log::LogEntry> entry);
                

                /*********************************************************************************//**
                *	@brief  This method returns the log formatter currently being used by the Impl log 
                *           manager. 
                *   @return A pointer to the LogFormatter
                *************************************************************************************/
				std::shared_ptr<LogFormatter> getFormatter();
                

                /*********************************************************************************//**
                *	@brief  Impl Destructor 
                *************************************************************************************/
				virtual ~Impl();
			private:
				std::vector<std::shared_ptr<GU::Log::LogTarget>> m_targets;
				std::shared_ptr<LogFormatter> m_logFormatter;
		};

        
        /*********************************************************************************//**
        *	@brief  Impl Constructor 
        *************************************************************************************/
		LogManager::Impl::Impl()
		{
		}


        /*********************************************************************************//**
        *	@brief  This  method adds a log target to the Impl log manager. 
        *   @param  logTarget is the log target to be added to the Impl log manager.
        *************************************************************************************/
		void LogManager::Impl::add(std::shared_ptr<GU::Log::LogTarget> logTarget)
		{
            assert(logTarget != nullptr);
			m_targets.push_back(logTarget);

		}


        /*********************************************************************************//**
        *	@brief  This method returns the log target at the given index. 
        *   @param  index is the current position of the log target to be returned. 
        *************************************************************************************/
		LogTarget& LogManager::Impl::getTarget(const std::size_t &index)
		{
			if(index < m_targets.size())
			{
				assert((m_targets[index]) != nullptr);
				return *(m_targets[index]);
			}
			else
			{
				throw
					std::runtime_error("Invalid index");
			}
		}


        /*********************************************************************************//**
        *	@brief  This method removes the log target. 
        *   @param  logTarget The log target to be removed. 
        *************************************************************************************/
		bool LogManager::Impl::remove(const GU::Log::LogTarget &logTarget)
		{
			for(std::size_t i = 0; i < m_targets.size(); ++i)
			{
				assert(m_targets[i] != nullptr);

				if((*m_targets[i]) == logTarget)
				{
					m_targets.erase(m_targets.begin() + i);
					return true;
				}
			}

			return false;
		}


        /*********************************************************************************//**
        *	@brief  This method returns the number of log targets currently stored in the 
        *           Impl log manager. 
        *   @return The number of log targets currently stored in the Impl log manager. 
        *************************************************************************************/
		std::size_t LogManager::Impl::getTargetCount() const
		{
			return m_targets.size();
		}


        /*********************************************************************************//**
        *	@brief  This method sets the log formatter for the Impl log manager.  
        *   @param  logFormatter is the log formatter to be used by the Impl log manager. 
        *************************************************************************************/
		void LogManager::Impl::set(std::shared_ptr<LogFormatter> logFormatter)
		{
			m_logFormatter = logFormatter;
		}

        
        /*********************************************************************************//**
        *	@brief  This method writes a string to the log file.
        *   @param  msg is the string to be written to the log file. 
        *************************************************************************************/
        void LogManager::Impl::write(const GU::Core::String &msg)
        {
            UNUSED(msg);
        }


        /*********************************************************************************//**
        *	@brief  This method writes a log entry to the log file. 
        *   @param  entry is the log entry to be written to the log file. 
        *************************************************************************************/
        void LogManager::Impl::write(std::shared_ptr<GU::Log::LogEntry> entry)
        {
            assert(entry != nullptr);

            for(std::size_t i = 0; i < entry->size(); ++i)
            {
                m_logFormatter->init(entry->operator[](i));
            }

            for(std::size_t i = 0; i < m_targets.size(); ++i)
            {
                m_targets[i]->write(m_logFormatter->format());
            }

        }


        /*********************************************************************************//**
        *	@brief  This method returns the log formatter currently being used by the Impl log 
        *           manager. 
        *   @return A pointer to the LogFormatter
        *************************************************************************************/
		std::shared_ptr<LogFormatter> LogManager::Impl::getFormatter()
		{
			return m_logFormatter;
		}


		LogManager::Impl::~Impl()
		{

		}


        /*********************************************************************************//**
        *	@brief  Constructor 
        *************************************************************************************/
        LogManager::LogManager():m_pimpl(new LogManager::Impl())
        {
            assert(m_pimpl != nullptr);
        }


        /*********************************************************************************//**
        *	@brief  This  method adds a log target to the log manager. 
        *   @param  logTarget is the log target to be added to the log manager.
        *************************************************************************************/
		void LogManager::add(std::shared_ptr<GU::Log::LogTarget> logTarget)
		{
			assert(m_pimpl != nullptr);
            assert(logTarget != nullptr);
			m_pimpl->add(std::move(logTarget));
		}
		

        /*********************************************************************************//**
        *	@brief  This method returns the log target at the given index. 
        *   @param  index is the current position of the log target to be returned. 
        *************************************************************************************/
		LogTarget& LogManager::getTarget(const std::size_t &index)
		{
			assert(m_pimpl != nullptr);
			return m_pimpl->getTarget(index);
		}
        

        /*********************************************************************************//**
        *	@brief  This method removes the log target. 
        *   @param  logTarget The log target to be removed. 
        *************************************************************************************/
		bool LogManager::remove(const GU::Log::LogTarget &logTarget)
		{
            assert(m_pimpl != nullptr);
			return m_pimpl->remove(logTarget);
		}
        

        /*********************************************************************************//**
        *	@brief  This method returns the number of log targets currently stored in the 
        *           log manager. 
        *   @return The number of log targets currently stored in the log manager. 
        *************************************************************************************/
		std::size_t LogManager::getTargetCount() const
		{
			return m_pimpl->getTargetCount();
		}
        

        /*********************************************************************************//**
        *	@brief  This method writes a string to the log file.
        *   @param  msg is the string to be written to the log file. 
        *************************************************************************************/
        void LogManager::write(const GU::Core::String &msg)
        {
            assert(m_pimpl != nullptr);
            m_pimpl->write(msg);
        }
		

        /*********************************************************************************//**
        *	@brief  This method writes a log entry to the log file. 
        *   @param  entry is the log entry to be written to the log file. 
        *************************************************************************************/
        void LogManager::write(std::shared_ptr<GU::Log::LogEntry> entry)
        {
            assert(m_pimpl != nullptr);
            assert(entry != nullptr);
            m_pimpl->write(entry);
        }
        

        /*********************************************************************************//**
        *	@brief  This method sets the log formatter for the log manager.  
        *   @param  logFormatter is the log formatter to be used by the log manager. 
        *************************************************************************************/
        void LogManager::set(std::shared_ptr<LogFormatter> logFormatter)
		{
            assert(m_pimpl != nullptr);
			m_pimpl->set(logFormatter);
		}
        

        /*********************************************************************************//**
        *	@brief  This method returns the log formatter currently being used by the log 
        *           manager. 
        *   @return A pointer to the LogFormatter
        *************************************************************************************/
        std::shared_ptr<LogFormatter> LogManager::getFormatter()
        {
            assert(m_pimpl != nullptr);
            return m_pimpl->getFormatter();
        }
        

        /*********************************************************************************//**
        *	@brief  Destructor 
        *************************************************************************************/
        LogManager::~LogManager()
		{
			assert(m_pimpl != nullptr);
            if(m_pimpl != nullptr)
            {
  			    delete m_pimpl;
                m_pimpl = nullptr;
            }
		}

	}
}
