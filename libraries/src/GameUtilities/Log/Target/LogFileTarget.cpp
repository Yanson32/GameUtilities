#include "log_export.h"
#include "GameUtilities/Log/Target/LogFileTarget.h"
#include <iostream>

namespace GU
{
    namespace Log
    {
		LogFileTarget::LogFileTarget(const GU::Core::String path):
		m_path(path)
		{
      m_file.open(m_path);
      if(!m_file.good())
      {
        std::cout << "Unable to open file " << m_path.toStdString() << std::endl;
      }

		}


		void LogFileTarget::write(const GU::Core::String &msg)
    {
      m_file << msg.toStdString() << std::endl;
		}


		LogFileTarget::~LogFileTarget()
		{
      m_file.close();
		}
	}
}
