/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*	@date 	5/18/22
*   @file   LogEntry.cpp
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
#include "GameUtilities/Log/LogEntry.h"
#include "GameUtilities/Log/Component/LogComponent.h"
#include <vector>
#include <memory>
#include <cassert>
#include <iostream>

namespace GU
{
    namespace Log
    {
        class LogEntry::Impl
        {
            public:
                /*********************************************************************************//**
                *	@brief  Inplimentation constructor 
                *************************************************************************************/
                Impl(const int &id, const int &type);
            

                /*********************************************************************************//**
                *	@brief  Inplimentation destructor 
                *************************************************************************************/
                virtual ~Impl();
            
            public:
                std::vector<std::shared_ptr<GU::Log::LogComponent>> m_data;
                int m_id = -1;
                int m_type = -1;
        };


        /*********************************************************************************//**
        *	@brief  Inplimentation constructor 
        *************************************************************************************/
        LogEntry::Impl::Impl(const int &id, const int &type):
        m_id(id),
        m_type(type)
        {
        }


        /*********************************************************************************//**
        *	@brief  Inplimentation destructor 
        *************************************************************************************/
        LogEntry::Impl::~Impl()
        {

        }


        /*********************************************************************************//**
        *	@brief  Constructor 
        *************************************************************************************/
        LogEntry::LogEntry(const int &id, const int &type):
        m_pimpl(new LogEntry::Impl(id, type))
        {
          assert(m_pimpl != nullptr);
        }

        
        /*********************************************************************************//**
        *	@brief  This method is used to add a LogComponent to the LogEvent. 
        *   @param  component is a pointer to the LogComponent to be added.
        *************************************************************************************/
        void LogEntry::add(std::shared_ptr<GU::Log::LogComponent> component)
        {
            assert(m_pimpl != nullptr);
            assert(component != nullptr);
            m_pimpl->m_data.push_back(component);
        }
        

        /*********************************************************************************//**
        *	@brief  This method returns the number of log components.
        *   @return The number of log components. 
        *************************************************************************************/
        std::size_t LogEntry::size() const
        {
            assert(m_pimpl != nullptr);
            return m_pimpl->m_data.size();
        }


        /*********************************************************************************//**
        *	@brief  This method returns a unique identifier for the LogEntry. 
        *   @return The unique identifier for the LogEntry.
        *************************************************************************************/
        int LogEntry::getId() const
        {
            assert(m_pimpl != nullptr);
            return m_pimpl->m_id; 
        }


        int LogEntry::getType() const
        {
            assert(m_pimpl != nullptr);
            return m_pimpl->m_type;
        }
        

        /*********************************************************************************//**
        *	@brief  This method returns a pointer to a LogComponent at the given index. 
        *   @param  index is the index of the LogComponent to be returned. 
        *   @return A LogComponent pointer. 
        *************************************************************************************/
        std::shared_ptr<LogComponent> LogEntry::operator [] (const std::size_t &index)
        {
            assert(m_pimpl != nullptr);
            assert(index < m_pimpl->m_data.size());
            return m_pimpl->m_data[index];
        }


        /*********************************************************************************//**
        *	@brief  Destructor 
        *************************************************************************************/
        LogEntry::~LogEntry()
        {
            assert(m_pimpl != nullptr);
            if(m_pimpl)
            {
                delete m_pimpl;
                m_pimpl = nullptr;
            }
        }
    }
}
