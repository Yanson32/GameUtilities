#include <iostream>
#include "GameUtilities/Log/LogManager.h"
#include "GameUtilities/Log/LogFileTarget.h"

int main()
{
	//Create log manager
	GU::Log::LogManager manager;
	
	//Set log target
	GU::Log::LogFileTarget target;
	manager.add(target);
	std::cout << "Target count " << manager.getTargetCount() << std::endl;
	
    return 0;
}