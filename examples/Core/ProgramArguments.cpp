#include "GameUtilities/Core/ProgramArguments.h"
#include "GameUtilities/Core/Macros.h"
#include <iostream>

struct Data
{
    std::string item_1 = "This is a cool item";
    bool cool = true;
    
};

void cool(GU::Core::ArgumentData params)
{

    if(params.data == nullptr)
        throw std::runtime_error("Parameter cannot be null"); 
    
    std::shared_ptr<Data> data = std::static_pointer_cast<Data>(params.data);
   
    if(data == nullptr)
        throw std::runtime_error("Could not cast void pointer");
    
    std::cout << data->item_1 << std::endl;
    
    if(data->cool)
        std::cout << "Do cool thing" << std::endl;
    else
        std::cout << "Dont do cool thing" << std::endl;
    
}

void help(GU::Core::ArgumentData params)
{
    UNUSED(params);
    std::cout << "--help            Display help text" << std::endl;
    std::cout << "--version, -v     Display program version" << std::endl;
    std::cout << "--cool, -c        Do somthing cool" << std::endl;
    std::cout << "--log_file=, -l   Sets the log file path" << std::endl;
}

void log(GU::Core::ArgumentData params)
{
    std::cout << "Log file is " << params.value << std::endl;
}

int main(int argc, char **argv)
{
    GU::Core::ProgramArguments arguments;
    
    //Add help option 
    if(!arguments.add("--help", '\0', help))
        throw std::runtime_error("Error: unable to add key");

    
    //Add version option
    if(!arguments.add("--version", 'v', [](GU::Core::ArgumentData params){ 
        UNUSED(params);
        std::cout << "version = 0.0.0.1" << std::endl;
    }))
        throw std::runtime_error("Error: Unable to add key");
   
    std::shared_ptr<Data> data(new Data());
   
    std::pair<GU::Core::ProgramArguments::Callback, GU::Core::ArgumentData> dataPair;
    dataPair.first = cool;
    dataPair.second.data = data; 
    
    //Add cool option
    if(!arguments.add("--cool", 'c', dataPair))
        throw std::runtime_error("Error: Unable to add key");
    
    //Add log file 
    if(!arguments.add("--log_file=", 'l', log))
        throw std::runtime_error("Error: Unable to add key");
    
    arguments.parse(argc, argv);
    
    //Positional Argumnets
    for(std::size_t i = 0; i < arguments.positionalSize(); ++i)
        std::cout << "Positional Arguments [" << i << "] " << arguments[i] << std::endl;

    //Execute callback functions
    arguments.run();
    
    return 0;
}
