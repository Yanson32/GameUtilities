#include "GameUtilities/Log/LogManager.h"
namespace GU
{
    namespace Log
    { 		
		LogManager::LogManager()
		{
			
		}

		LogManager::~LogManager()
		{
			
		}
		
		LogManager& inst()
		{
			static LogManager manager;
			return manager;
		}
	}
}
