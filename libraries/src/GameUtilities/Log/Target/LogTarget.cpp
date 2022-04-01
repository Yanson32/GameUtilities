#include "GameUtilities/Log/Target/LogTarget.h"
#include <iostream>

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
