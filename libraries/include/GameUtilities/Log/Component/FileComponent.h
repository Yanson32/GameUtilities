#ifndef GU_LOG_FILECOMPONENT_H
#define GU_LOGFILECOMPONENT_H

#include "log_export.h"
#include "GameUtilities/Core/String.h"
#include "GameUtilities/Log/Component/LogComponent.h"
#include "GameUtilities/Log/Component/ComponentId.h"

namespace GU
{
    namespace Log
    {
      struct LOG_EXPORT FileComponent: public LogComponent
      {
        FileComponent();
        FileComponent(GU::Core::String &file);
        FileComponent& operator = (const FileComponent &comp);
        GU::Core::String format();
        GU::Core::String m_file;
        int lineNumber = 0;
      };
    }
}
#endif
