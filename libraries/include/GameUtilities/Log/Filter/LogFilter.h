#ifndef LOG_FILTER_H
#define LOG_FILTER_H
#include "log_export.h"
#include "GameUtilities/Log/LogEntry.h"
#include "GameUtilities/Core/String.h"

namespace GU
{
    namespace Log
    {
      claSS LOG_EXPORT LogFilter
      {
      public:
        LogFilter();
        virtual GU::Core::String filter(std::shared_ptr<GU::Log::LogEntry> entry) = 0;
        virtual ~LogFilter();

      };
    }
}
#endif
