#ifndef GU_LOG_DATECOMPONENT_H
#define GU_LOG_DATECOMPONENT_H

#include "log_export.h"
#include "GameUtilities/Core/String.h"
#include "GameUtilities/Log/Component/LogComponent.h"
#include "GameUtilities/Log/Component/ComponentId.h"
#include <chrono>

namespace GU
{
    namespace Log
    {
      struct LOG_EXPORT DateComponent: public LogComponent
      {
        DateComponent();
        DateComponent& operator = (const DateComponent &comp);
        GU::Core::String format();
      };
    }
}
#endif
