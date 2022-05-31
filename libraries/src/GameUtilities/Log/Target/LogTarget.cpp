#include "GameUtilities/Log/Target/LogTarget.h"
#include <iostream>
#include "GameUtilities/Core/Macros.h"
namespace GU
{
    namespace Log
    {
        /*********************************************************************************//**
        *	@brief  Constructor 
        *************************************************************************************/
  		LogTarget::LogTarget()
  		{

  		}

        
        /*********************************************************************************//**
        *	@brief  This method retruns true if the current log target and the passed log
        *           target are equal.
        *   @param  logTarget is the log target the current log target will be checked against
        *           for equality.
        *   @return True if the current log target and passed log target are equal and false
        *           otherwise. 
        *************************************************************************************/
  		bool LogTarget::operator == (const LogTarget &logTarget) const
  		{
  			return (*this)==logTarget;
  		}


        /*********************************************************************************//**
        *	@brief  Destructor 
        *************************************************************************************/
  		LogTarget::~LogTarget()
  		{

        }
    }
}
