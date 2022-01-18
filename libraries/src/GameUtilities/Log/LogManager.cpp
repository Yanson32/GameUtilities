#include "GameUtilities/Log/LogManager.h"
#include <vector>
#include <stdexcept>
namespace GU
{
    namespace Log
    { 		
	
		class LogManager::Impl
		{
			public:
				Impl();
				void add(LogTarget &logTarget);
				LogTarget& getTarget(const std::size_t &index);
				bool remove(const LogTarget &logTarget);
				void add(LogFormatter &logFormatter);
				LogFormatter& getFormatter();
				virtual ~Impl();
			private:
				std::vector<LogTarget> m_targets;
				LogFormatter m_logFormatter;
		};
		
		LogManager::Impl::Impl()
		{
			
		}
		
		
		void LogManager::Impl::add(LogTarget &logTarget)
		{
			m_targets.push_back(logTarget);
		}
		
		
		LogTarget& LogManager::Impl::getTarget(const std::size_t &index)
		{
			if(index < m_targets.size())
			{
				return m_targets[index];
			}
			else
			{
				throw
					std::runtime_error("Invalid index");
			}
		}
		
		
		bool LogManager::Impl::remove(const LogTarget &logTarget)
		{
			for(std::size_t i = 0; i < m_targets.size(); ++i)
			{
				if(m_targets[i] == logTarget)
				{
					m_targets.erase(m_targets.begin() + i);
					return true;
				}
			}
			
			return false;
		}
		
		
		void LogManager::Impl::add(LogFormatter &logFormatter)
		{
			m_logFormatter = logFormatter;
		}
		
		
		LogFormatter& LogManager::Impl::getFormatter()
		{
			return m_logFormatter;
		}
		
		
		LogManager::Impl::~Impl()
		{
			
		}
				
				
		LogManager::LogManager():pimpl(new LogManager::Impl())
		{
			
		}


		LogManager::~LogManager()
		{
			if(pimpl)
				delete pimpl;
		}
		
		
		void LogManager::add(LogTarget &logTarget)
		{
			if(pimpl)
				pimpl->add(logTarget);
		}
		
		
		LogTarget& LogManager::getTarget(const std::size_t &index)
		{
			if(pimpl)
				return pimpl->getTarget(index);
			
			throw
				std::runtime_error("Cannot dereference nullptr");
		}
		
		
		bool LogManager::remove(const LogTarget &logTarget)
		{
			if(pimpl)
				return pimpl->remove(logTarget);
			throw
				std::runtime_error("Cannot dereference nullptr");
		}
		
		void LogManager::add(LogFormatter &logFormatter)
		{
			if(pimpl)
				pimpl->add(logFormatter);
		}
		
		
		LogFormatter& LogManager::getFormatter()
		{
			if(pimpl)
				return pimpl->getFormatter();
			
			throw
				std::runtime_error("Cannot dereference nullptr");
		}
	}
}
