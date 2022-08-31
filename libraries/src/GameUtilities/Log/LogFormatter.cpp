#include "GameUtilities/Log/LogFormatter.h"
#include "GameUtilities/Log/Component/LogComponent.h"
#include "GameUtilities/Log/Component/Components.h"
#include "GameUtilities/Core/Macros.h"
#include <vector>
#include <cassert>

namespace GU
{
    namespace Log
    {
        class LogFormatter::Impl
        {
            public:
                /*********************************************************************************//**
                *	@brief  Constructor 
                *************************************************************************************/
                Impl();
                
    
                /*********************************************************************************//**
                *	@brief  Destructor 
                *************************************************************************************/
                virtual ~Impl();
            public:
                std::vector<std::shared_ptr<LogComponent>> m_data;
        };

    
        /*********************************************************************************//**
        *	@brief  Constructor 
        *************************************************************************************/
        LogFormatter::Impl::Impl()
        {

        }
        

        /*********************************************************************************//**
        *	@brief  Destructor 
        *************************************************************************************/
        LogFormatter::Impl::~Impl()
        {

        }
        


        /*********************************************************************************//**
        *	@brief  Constructor 
        *************************************************************************************/
        LogFormatter::LogFormatter(): m_pimpl(new LogFormatter::Impl())
        {
            assert(m_pimpl != nullptr);
        }

        
        /*********************************************************************************//**
        *	@brief  This method adds a log component to the log formatter. The log component
        *           is used by the formatter to determine the order that the components will 
        *           be written to the log file. Components will be written to the log file
        *           in the same order they were added to the formatter.
        *   @param  component is the log component to be added to the log file. 
        *************************************************************************************/
        void LogFormatter::add(std::shared_ptr<GU::Log::LogComponent> component)
        {
            assert(m_pimpl != nullptr);
            //assert(std::find(pimpl->m_data.begin(), pimpl->m_data.end(), component) != pimpl->m_data.end());
            m_pimpl->m_data.push_back(component);
        }


        /*********************************************************************************//**
        *	@brief  This method is used to initialize a log component. The log component should
        *           have been added previously with the add method. 
        *   @pre    A log component should be added with the add method.
        *   @param  component will be used to initialize the previously added log component. 
        *************************************************************************************/
        void LogFormatter::init(std::shared_ptr<GU::Log::LogComponent> component)
        {
            
            assert(component != nullptr);
            assert(m_pimpl != nullptr);
            for(std::size_t i = 0; i < m_pimpl->m_data.size(); ++i)
            {
                assert(m_pimpl->m_data[i] != nullptr);
                
                std::shared_ptr<LogComponent> data = m_pimpl->m_data[i];

                if((*data) == (*component))
                {
                    switch((*data).m_id)
                    {
                        case GU::Log::componentId::DATE:
                        {
                            std::shared_ptr<GU::Log::DateComponent> temp = std::dynamic_pointer_cast<DateComponent>(data);
                            std::shared_ptr<GU::Log::DateComponent> temp2 = std::dynamic_pointer_cast<DateComponent>(component);
                            (*temp) = (*temp2);
                        }
                        break;
                        case GU::Log::componentId::FILE:
                        {
                            std::shared_ptr<GU::Log::FileComponent> temp = std::dynamic_pointer_cast<FileComponent>(data);
                            std::shared_ptr<GU::Log::FileComponent> temp2 = std::dynamic_pointer_cast<FileComponent>(component);
                            (*temp) = (*temp2);
                        }
                        break;
                        case GU::Log::componentId::MSG:
                        {
                          std::shared_ptr<GU::Log::MsgComponent> temp = std::dynamic_pointer_cast<MsgComponent>(data);
                          std::shared_ptr<GU::Log::MsgComponent> temp2 = std::dynamic_pointer_cast<MsgComponent>(component);
                          (*temp) = (*temp2);
                        }
                        break;
                        case GU::Log::componentId::SEVERITY:
                        {
                            std::shared_ptr<GU::Log::SeverityComponent> temp = std::dynamic_pointer_cast<SeverityComponent>(data);
                            std::shared_ptr<GU::Log::SeverityComponent> temp2 = std::dynamic_pointer_cast<SeverityComponent>(component);
                            (*temp) = (*temp2);
                        }
                        break;
                        case GU::Log::componentId::TIME:
                        {
                            std::shared_ptr<GU::Log::TimeComponent> temp = std::dynamic_pointer_cast<TimeComponent>(data);
                            std::shared_ptr<GU::Log::TimeComponent> temp2 = std::dynamic_pointer_cast<TimeComponent>(component);
                            (*temp) = (*temp2);
                        }
                        break;
                        case GU::Log::componentId::LINE:
                            std::shared_ptr<GU::Log::LineComponent> temp = std::dynamic_pointer_cast<LineComponent>(data);
                            std::shared_ptr<GU::Log::LineComponent> temp2 = std::dynamic_pointer_cast<LineComponent>(component);
                            (*temp) = (*temp2);
                        break;

                    }
                }

            }
            
        }


        /*********************************************************************************//**
        *	@brief  This method return a component with the given id.
        *   @return A pointer to the log component with the given id. 
        *************************************************************************************/
        std::shared_ptr<LogComponent> LogFormatter::getComponent(const componentId &component) const
        {
            assert(m_pimpl != nullptr);
            for(auto &element : m_pimpl->m_data)
              if(element->m_id == component)
                return element;

            return nullptr;
        }


        /*********************************************************************************//**
        *	@brief  This method will return a string formatted correctly for the log file. 
        *   @return A string formatted correctly for the log file. 
        *************************************************************************************/
        GU::Core::String LogFormatter::format()
        {
          assert(m_pimpl != nullptr);
          GU::Core::String temp;

          for(auto &element: m_pimpl->m_data)
          {
            temp += "[";
            temp = temp + element->format();
            temp += "]";
          }
          return temp;
        }

        
        /*********************************************************************************//**
        *	@brief  Destructor 
        *************************************************************************************/
        LogFormatter::~LogFormatter()
        {
            assert(m_pimpl != nullptr);
            if(m_pimpl != nullptr)
                delete m_pimpl;
        } 
    }

}
