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
            Impl();
            virtual ~Impl();
            std::vector<std::shared_ptr<GU::Log::LogComponent>> m_data;
        };


        LogEntry::Impl::Impl()
        {
        }


        LogEntry::Impl::~Impl()
        {

        }


        LogEntry::LogEntry():
        pimpl(new LogEntry::Impl())
        {
          assert(pimpl != nullptr);
        }

        std::size_t LogEntry::size() const
        {
          return pimpl->m_data.size();
        }


        std::shared_ptr<LogComponent> LogEntry::operator [] (const std::size_t &index)
        {
          return pimpl->m_data[index];
        }


        void LogEntry::add(std::shared_ptr<GU::Log::LogComponent> component)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.push_back(component);
        }


        LogEntry::~LogEntry()
        {
          if(pimpl)
            delete pimpl;
        }
    }
}
