#ifndef GU_LOG_COMPONENT_H
#define GU_LOG_COMPONENT_H

#include "log_export.h"
#include "GameUtilities/Core/String.h"
#include "GameUtilities/Log/Component/ComponentId.h"
namespace GU
{
    namespace Log
    {
      struct LOG_EXPORT LogComponent
      {
        LogComponent(const componentId &id);
        bool operator == (const LogComponent &comp);
        bool operator == (const componentId &comp);
        virtual GU::Core::String format() = 0;
        const componentId m_id;
      };
    }
}
#endif
