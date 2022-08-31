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
                Impl();
            

                /*********************************************************************************//**
                *	@brief  Inplimentation destructor 
                *************************************************************************************/
                virtual ~Impl();
            
            public:
                std::vector<std::shared_ptr<GU::Log::LogComponent>> m_data;
        };


        /*********************************************************************************//**
        *	@brief  Inplimentation constructor 
        *************************************************************************************/
        LogEntry::Impl::Impl()
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
        LogEntry::LogEntry():
        pimpl(new LogEntry::Impl())
        {
          assert(pimpl != nullptr);
        }

        
        /*********************************************************************************//**
        *	@brief  This method is used to add a LogComponent to the LogEvent. 
        *************************************************************************************/
        void LogEntry::add(std::shared_ptr<GU::Log::LogComponent> component)
        {
            assert(pimpl != nullptr);
            assert(component != nullptr);
            pimpl->m_data.push_back(component);
        }
        

        /*********************************************************************************//**
        *	@brief  This method returns the number of log components.
        *   @return The number of log components. 
        *************************************************************************************/
        std::size_t LogEntry::size() const
        {
            assert(pimpl != nullptr);
            return pimpl->m_data.size();
        }


        /*********************************************************************************//**
        *	@brief  This method returns a pointer to a LogComponent at the given index. 
        *   @param  index is the index of the LogComponent to be returned. 
        *   @return A LogComponent pointer. 
        *************************************************************************************/
        std::shared_ptr<LogComponent> LogEntry::operator [] (const std::size_t &index)
        {
            assert(pimpl != nullptr);
            assert(index >= 0);
            assert(index < pimpl->m_data.size());
            return pimpl->m_data[index];
        }


        /*********************************************************************************//**
        *	@brief  Destructor 
        *************************************************************************************/
        LogEntry::~LogEntry()
        {
            assert(pimpl != nullptr);
            if(pimpl)
                delete pimpl;
        }
    }
}
