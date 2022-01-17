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
		
		
		LogManager& LogManager::inst()
		{
			static LogManager manager;
			return manager;
		}
		
		
		void LogManager::add(LogTarget &logTarget)
		{
			
		}
		
		
		LogTarget& LogManager::getTarget()
		{
			
		}
		
		
		void LogManager::add(LogFormatter &logFormatter)
		{
			
		}
		
		
		LogFormatter& LogManager::getFormatter()
		{
			
		}
	}
}
