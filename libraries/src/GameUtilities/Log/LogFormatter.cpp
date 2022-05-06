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
          Impl(){};
          virtual ~Impl(){};
          std::vector<std::shared_ptr<LogComponent>> m_data;
          #ifdef MULTITHREAD
            mutable std::mutex eventQueueLock;
          #endif
      };

  		LogFormatter::LogFormatter(): m_pimpl(new LogFormatter::Impl())
  		{
            assert(m_pimpl != nullptr);
  		}

      void LogFormatter::add(std::shared_ptr<GU::Log::LogComponent> component)
      {
        assert(m_pimpl != nullptr);
        //assert(std::find(pimpl->m_data.begin(), pimpl->m_data.end(), component) != pimpl->m_data.end());
        m_pimpl->m_data.push_back(component);
      }

      std::shared_ptr<LogComponent> LogFormatter::getComponent(const componentId &component) const
      {
        assert(m_pimpl != nullptr);
        for(auto &element : m_pimpl->m_data)
          if(element->m_id == component)
            return element;

        return nullptr;
      }


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

      GU::Core::String LogFormatter::format(std::shared_ptr<GU::Log::LogEntry> entry)
      {
        UNUSED(entry);
        assert(m_pimpl != nullptr);
        return GU::Core::String("");
      }


      void LogFormatter::init(std::shared_ptr<GU::Log::LogComponent> component)
      {
        assert(m_pimpl != nullptr);
        for(std::size_t i = 0; i < m_pimpl->m_data.size(); ++i)
        {
          if((*m_pimpl->m_data[i]) == (*component))
          {
            switch((*m_pimpl->m_data[i]).m_id)
            {
              case GU::Log::componentId::DATE:
              {
                std::shared_ptr<GU::Log::DateComponent> temp = std::dynamic_pointer_cast<DateComponent>(m_pimpl->m_data[i]);
                std::shared_ptr<GU::Log::DateComponent> temp2 = std::dynamic_pointer_cast<DateComponent>(component);
                (*temp) = (*temp2);
              }
              break;
              case GU::Log::componentId::FILE:
              {
                std::shared_ptr<GU::Log::FileComponent> temp = std::dynamic_pointer_cast<FileComponent>(m_pimpl->m_data[i]);
                std::shared_ptr<GU::Log::FileComponent> temp2 = std::dynamic_pointer_cast<FileComponent>(component);
                (*temp) = (*temp2);
              }
              break;
              case GU::Log::componentId::MSG:
              {
                std::shared_ptr<GU::Log::MsgComponent> temp = std::dynamic_pointer_cast<MsgComponent>(m_pimpl->m_data[i]);
                std::shared_ptr<GU::Log::MsgComponent> temp2 = std::dynamic_pointer_cast<MsgComponent>(component);
                (*temp) = (*temp2);
              }
              break;
              case GU::Log::componentId::SEVERITY:
              {
                std::shared_ptr<GU::Log::SeverityComponent> temp = std::dynamic_pointer_cast<SeverityComponent>(m_pimpl->m_data[i]);
                std::shared_ptr<GU::Log::SeverityComponent> temp2 = std::dynamic_pointer_cast<SeverityComponent>(component);
                (*temp) = (*temp2);
              }
              break;
              case GU::Log::componentId::TIME:
              {
                std::shared_ptr<GU::Log::TimeComponent> temp = std::dynamic_pointer_cast<TimeComponent>(m_pimpl->m_data[i]);
                std::shared_ptr<GU::Log::TimeComponent> temp2 = std::dynamic_pointer_cast<TimeComponent>(component);
                (*temp) = (*temp2);
              }
              break;
              case GU::Log::componentId::LINE:
                std::shared_ptr<GU::Log::LineComponent> temp = std::dynamic_pointer_cast<LineComponent>(m_pimpl->m_data[i]);
                std::shared_ptr<GU::Log::LineComponent> temp2 = std::dynamic_pointer_cast<LineComponent>(component);
                (*temp) = (*temp2);
              break;

            }
          }

        }
      }


  		LogFormatter::~LogFormatter()
  		{
            assert(m_pimpl != nullptr);
            if(m_pimpl != nullptr)
                delete m_pimpl;
  		}
	  }
}
