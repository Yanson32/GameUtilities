#include <iostream>
#include "GameUtilities/Log/LogManager.h"
#include "GameUtilities/Log/LogFileTarget.h"
#include <memory>

int main()
{
	//Create log manager
	GU::Log::LogManager manager;
	
	//Set log target
	std::unique_ptr<GU::Log::LogFileTarget> target(new GU::Log::LogFileTarget("C:/"));
	manager.add(std::move(target));
	std::cout << "Target count " << manager.getTargetCount() << std::endl;
	
    return 0;
}