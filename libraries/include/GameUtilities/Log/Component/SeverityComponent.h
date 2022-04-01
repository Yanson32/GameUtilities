#ifndef GU_LOG_SECURITYCOMPONENT_H
#define GU_LOG_SECURITYCOMPONENT_H

#include "log_export.h"
#include "GameUtilities/Core/String.h"
#include "GameUtilities/Log/Component/LogComponent.h"
#include "GameUtilities/Log/Component/ComponentId.h"
#include "GameUtilities/Log/LogType.h"

namespace GU
{
    namespace Log
    {
      struct LOG_EXPORT SeverityComponent: public LogComponent
      {
        SeverityComponent(const LogType &severity);
        SeverityComponent();
        SeverityComponent& operator = (const SeverityComponent &comp);
        GU::Core::String format();
        LogType m_severity = LogType::MESSAGE;
      };
    }
}
#endif
