#include "GameUtilities/Log/LogManager.h"
#include "GameUtilities/Log/LogFormatter.h"
#include "GameUtilities/Core/Macros.h"
#include <vector>
#include <stdexcept>
#include <cassert>
#include <iostream>

namespace GU
{
    namespace Log
    {

		class LogManager::Impl
		{
			public:
				Impl();
				void add(std::shared_ptr<GU::Log::LogTarget> logTarget);
				LogTarget& getTarget(const std::size_t &index);
				bool remove(const GU::Log::LogTarget &logTarget);
				std::size_t getTargetCount() const;
				void set(LogFormatter &logFormatter);
        void write(const GU::Core::String &msg);
        void write(std::shared_ptr<GU::Log::LogEntry> entry);
				LogFormatter& getFormatter();
				virtual ~Impl();
			private:
				std::vector<std::shared_ptr<GU::Log::LogTarget>> m_targets;
				LogFormatter m_logFormatter;
		};

		LogManager::Impl::Impl()
		{

		}


		void LogManager::Impl::add(std::shared_ptr<GU::Log::LogTarget> logTarget)
		{
			m_targets.push_back(logTarget);

		}


		LogTarget& LogManager::Impl::getTarget(const std::size_t &index)
		{
			if(index < m_targets.size())
			{
				assert((m_targets[index]) != nullptr);
				return *(m_targets[index]);
			}
			else
			{
				throw
					std::runtime_error("Invalid index");
			}
		}


		bool LogManager::Impl::remove(const GU::Log::LogTarget &logTarget)
		{
			for(std::size_t i = 0; i < m_targets.size(); ++i)
			{
				assert(m_targets[i] != nullptr);

				if((*m_targets[i]) == logTarget)
				{
					m_targets.erase(m_targets.begin() + i);
					return true;
				}
			}

			return false;
		}


		std::size_t LogManager::Impl::getTargetCount() const
		{
			return m_targets.size();
		}


		void LogManager::Impl::set(LogFormatter &logFormatter)
		{
			m_logFormatter = logFormatter;
		}

    void LogManager::Impl::write(const GU::Core::String &msg)
    {
      UNUSED(msg);
      std::cout << "Impl write" << std::endl;
    }


    void LogManager::Impl::write(std::shared_ptr<GU::Log::LogEntry> entry)
    {
      for(std::size_t i = 0; i < entry->size(); ++i)
      {
        m_logFormatter.init(entry->operator[](i));
      }

      for(std::size_t i = 0; i < m_targets.size(); ++i)
      {
        m_targets[i]->write(m_logFormatter.format());
      }

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
      assert(pimpl != nullptr);
		}


		LogManager::~LogManager()
		{
			assert(pimpl != nullptr);
			delete pimpl;
		}


		void LogManager::add(std::shared_ptr<GU::Log::LogTarget> logTarget)
		{
			assert(pimpl != nullptr);
			pimpl->add(std::move(logTarget));
		}


		LogTarget& LogManager::getTarget(const std::size_t &index)
		{
			assert(pimpl != nullptr);
			return pimpl->getTarget(index);
		}


		bool LogManager::remove(const GU::Log::LogTarget &logTarget)
		{
      assert(pimpl != nullptr);
			return pimpl->remove(logTarget);
		}


		std::size_t LogManager::getTargetCount() const
		{
			return pimpl->getTargetCount();
		}


		void LogManager::set(LogFormatter &logFormatter)
		{
      assert(pimpl != nullptr);
			pimpl->set(logFormatter);
		}


    void LogManager::write(const GU::Core::String &msg)
    {
      assert(pimpl != nullptr);
      pimpl->write(msg);
    }


    void LogManager::write(std::shared_ptr<GU::Log::LogEntry> entry)
    {
      assert(pimpl != nullptr);
      pimpl->write(entry);
    }


		LogFormatter& LogManager::getFormatter()
		{
      assert(pimpl != nullptr);
			return pimpl->getFormatter();
		}

	}
}
