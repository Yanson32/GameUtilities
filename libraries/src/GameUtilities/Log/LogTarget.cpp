#include "GameUtilities/Log/LogTarget.h"

namespace GU
{
    namespace Log
    { 
		LogTarget::LogTarget()
		{
			
		}
		
		bool LogTarget::operator == (const LogTarget &logTarget) const
		{
			return true;
		}
		
		
		LogTarget::~LogTarget()
		{
			
		}
	}
}