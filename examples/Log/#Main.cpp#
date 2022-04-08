#include <iostream>
#include "GameUtilities/Log/LogManager.h"
#include "GameUtilities/Log/Target/LogTarget.h"
#include "GameUtilities/Log/Target/LogFileTarget.h"
#include "GameUtilities/Log/LogFormatter.h"
#include "GameUtilities/Log/Component/Components.h"
#include "GameUtilities/Log/LogEntry.h"
#include <memory>

int main()
{

	//Create log manager
	GU::Log::LogManager manager;

	//Set log target
	std::shared_ptr<GU::Log::LogTarget> target(new GU::Log::LogFileTarget("log.txt"));
	manager.add(target);

	//Set log formatter
	GU::Log::LogFormatter logFormatter;
	logFormatter.add<GU::Log::DateComponent>();
	logFormatter.add<GU::Log::SeverityComponent>();
	logFormatter.add<GU::Log::MsgComponent>();
	manager.set(logFormatter);

	//Create log entry
	std::shared_ptr<GU::Log::LogEntry> entry(new GU::Log::LogEntry());
	entry->add<GU::Log::MsgComponent>("This is a sample log message");
	entry->add<GU::Log::SeverityComponent>(GU::Log::LogType::WARNING);
	entry->add<GU::Log::DateComponent>();

	//Write log
	manager.write(entry);
	manager.write(entry);

    return 0;
}
