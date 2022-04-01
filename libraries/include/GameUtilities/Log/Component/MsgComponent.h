#ifndef GU_LOG_MSGCOMPONENT_H
#define GU_LOG_MSGCOMPONENT_H

#include "log_export.h"
#include "GameUtilities/Core/String.h"
#include "GameUtilities/Log/Component/LogComponent.h"
#include "GameUtilities/Log/Component/ComponentId.h"


namespace GU
{
    namespace Log
    {
      struct LOG_EXPORT MsgComponent: public LogComponent
      {
        MsgComponent();
        MsgComponent(const GU::Core::String &msg);
        MsgComponent& operator = (const MsgComponent &comp);
        GU::Core::String format();
        GU::Core::String m_msg;
      };
    }
}
#endif
