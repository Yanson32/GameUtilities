#ifndef GAMEUTILITIES_LOG_ENTRY_H
#define GAMEUTILITIES_LOG_ENTRY_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*	@date 	5/18/22
*   @file   LogEntry.h
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
#include "log_export.h"
#include "GameUtilities/Log/Component/LogComponent.h"
#include <memory>
namespace GU
{
    namespace Log
    {
        /*********************************************************************************//**
        *   @class  LogEntry
        *	@brief  The LogEntry class contains all data for a single log entry.  
        *************************************************************************************/
        class LOG_EXPORT LogEntry
        {
            public:
                /*********************************************************************************//**
                *	@brief  Constructor 
                *   @param  id is the unique identifier for the LogEntry.
                *   @param  type is the 
                *************************************************************************************/
                LogEntry(const int &id = -1, const int &type = -1);
                

                /*********************************************************************************//**
                *	@brief  This method is used to add a LogComponent to the LogEvent. 
                *   @param  component is a pointer to the LogComponent to be added.
                *************************************************************************************/
                void add(std::shared_ptr<GU::Log::LogComponent> component);
                

                /*********************************************************************************//**
                *	@brief  This method is for convinience it uses perfect forwarding to add a 
                *           LogComponet to the entry.
                *   @tparam Type is a subclass of the LogComponent class.
                *   @param  args is the arguments required by the LogComponent subclass. 
                *************************************************************************************/
                template<typename Type, typename... Args>
                void add(Args&&... args);
                

                /*********************************************************************************//**
                *	@brief  This method returns the number of log components.
                *   @return The number of log components. 
                *************************************************************************************/
                std::size_t size() const;
                
                /*********************************************************************************//**
                *	@brief  This method returns a unique identifier for the LogEntry. 
                *   @return The unique identifier for the LogEntry.
                *************************************************************************************/
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
                Impl* m_pimpl = nullptr;    /**< Pointer to class implimentation */
        };

        
        /*********************************************************************************//**
        *	brief   This method is for convinience it uses perfect forwarding to add a 
        *           LogComponet to the entry.
        *   tparam  Type is a subclass of the LogComponent class.
        *   param   args is the arguments required by the LogComponent subclass. 
        *************************************************************************************/
        template<typename Type, typename... Args>
        void LogEntry::add(Args&&... args)
        {
            this->add(std::shared_ptr<GU::Log::LogComponent>(new Type(std::forward<Args>(args)...)));
        }
    }
}

#endif
