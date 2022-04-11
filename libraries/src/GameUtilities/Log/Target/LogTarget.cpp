#include "GameUtilities/Log/Target/LogTarget.h"
#include <iostream>
#include "GameUtilities/Core/Macros.h"
namespace GU
{
    namespace Log
    {
  		LogTarget::LogTarget()
  		{

  		}

  		bool LogTarget::operator == (const LogTarget &logTarget) const
  		{
        UNUSED(logTarget);
  			return true;
  		}


  		LogTarget::~LogTarget()
  		{

  		}
	 }
}
