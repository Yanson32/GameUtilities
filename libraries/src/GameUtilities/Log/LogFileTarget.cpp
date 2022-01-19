#include "log_export.h"
#include "GameUtilities/Log/LogFileTarget.h"

namespace GU
{
    namespace Log
    { 
		LogFileTarget::LogFileTarget(const GU::Core::String path):
		m_path(path)
		{

		}

		LogFileTarget::~LogFileTarget()
		{
			
		}
	}
}