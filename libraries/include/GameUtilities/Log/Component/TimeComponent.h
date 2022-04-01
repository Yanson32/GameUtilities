#ifndef GU_LOG_TIMECOMPONENT_H
#define GU_LOG_TIMECOMPONENT_H

#include "log_export.h"
#include "GameUtilities/Core/String.h"
#include "GameUtilities/Log/Component/LogComponent.h"
#include "GameUtilities/Log/Component/ComponentId.h"
#include <chrono>
#include <ctime>

namespace GU
{
    namespace Log
    {
      struct LOG_EXPORT TimeComponent: public LogComponent
      {
        TimeComponent();
        TimeComponent& operator = (const TimeComponent &comp);
        GU::Core::String format();
      };
    }
}

#endif
