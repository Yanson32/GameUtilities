#ifndef GAMEUTILITIES_LOG_ENTRY_H
#define GAMEUTILITIES_LOG_ENTRY_H
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
          LogEntry();
          void add(std::shared_ptr<GU::Log::LogComponent> component);
          std::size_t size() const;
          std::shared_ptr<LogComponent> operator [] (const std::size_t &index);
          template<typename Type, typename... Args>
          void add(Args&&... args);
          virtual ~LogEntry();
        private:
          class Impl;
          Impl* pimpl = nullptr;
      };

      template<typename Type, typename... Args>
      void LogEntry::add(Args&&... args)
      {
        this->add(std::shared_ptr<GU::Log::LogComponent>(new Type(std::forward<Args>(args)...)));
      }
    }
}

#endif
