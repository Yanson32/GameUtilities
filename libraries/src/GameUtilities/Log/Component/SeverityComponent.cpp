#include "GameUtilities/Log/Component/SeverityComponent.h"

namespace GU
{
    namespace Log
    {

        SeverityComponent::SeverityComponent(const LogType &severity):
        LogComponent(componentId::SEVERITY),
        m_severity(m_severity)
        {

        }


        SeverityComponent::SeverityComponent():
        LogComponent(componentId::SEVERITY)
        {

        }


        SeverityComponent& SeverityComponent::operator = (const SeverityComponent &comp)
        {
          m_severity = comp.m_severity;
          return *this;
        }


        GU::Core::String SeverityComponent::format()
        {

          switch(m_severity)
          {
            case GU::Log::LogType::FATAL_ERROR:
              return "Fatal Error";
            case GU::Log::LogType::ERROR:
              return "Error";
            case GU::Log::LogType::WARNING:
              return "Warning";
            case GU::Log::LogType::MESSAGE:
              return "Message";
            case GU::Log::LogType::VERBOSE:
              return "Verbose";
            case GU::Log::LogType::STATUS:
              return "Status";
            case GU::Log::LogType::SYSTEM_ERROR:
              return "System Error";
            case GU::Log::LogType::DEBUG:
              return "Debug";
            case GU::Log::LogType::TRACE:
              return "Trace";
            default:
              return "";

           }
         }
    }
}
