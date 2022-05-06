#ifndef GU_LOG_FORMATTER_H
#define GU_LOG_FORMATTER_H

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
  				LogFormatter();
          void add(std::shared_ptr<GU::Log::LogComponent> component);
          template<typename Type, typename... Args>
          void add(Args&&... args);
          void init(std::shared_ptr<GU::Log::LogComponent> component);
          std::shared_ptr<LogComponent> getComponent(const componentId &component) const;
          virtual GU::Core::String format();
          virtual GU::Core::String format(std::shared_ptr<GU::Log::LogEntry> entry);
  				virtual ~LogFormatter();
        private:
          class Impl;
          Impl* m_pimpl = nullptr;
  		};


      template<typename Type, typename... Args>
      void LogFormatter::add(Args&&... args)
      {
        this->add(std::shared_ptr<LogComponent>(new Type(std::forward<Args>(args)...)));
      }
	}
}

#endif
