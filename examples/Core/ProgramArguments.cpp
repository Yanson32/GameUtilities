#include "GameUtilities/Core/ProgramArguments.h"
#include "GameUtilities/Core/Macros.h"
#include <iostream>
#include <iomanip>

struct Data
{
    std::string item_1 = "This is user defined data item 1";
    bool userbool = true;
    
};

void userData(GU::Core::ArgumentData params)
{

    if(params.data == nullptr)
        throw std::runtime_error("Parameter cannot be null"); 
    
    std::shared_ptr<Data> data = std::static_pointer_cast<Data>(params.data);
   
    if(data == nullptr)
        throw std::runtime_error("Could not cast void pointer");
    
    std::cout << data->item_1 << std::endl;
    
    if(data->userbool)
        std::cout << "Do user defined thing" << std::endl;
    else
        std::cout << "Dont do user defined thing" << std::endl;
    
}

void help(GU::Core::ArgumentData params)
{
    UNUSED(params);
    std::cout << "--help            Display help text" << std::endl;
    std::cout << "--version, -v     Display program version" << std::endl;
    std::cout << "--user, -u        Do some user defined thing" << std::endl;
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
  

    //User data 
    std::shared_ptr<Data> data(new Data());
   
    std::pair<GU::Core::ProgramArguments::Callback, GU::Core::ArgumentData> dataPair;
    dataPair.first = userData;
    dataPair.second.data = data; 
    
    //Add user defined option
    if(!arguments.add("--user", 'u', dataPair))
        throw std::runtime_error("Error: Unable to add key");
    
    //Add log file 
    if(!arguments.add("--log_file=", log))
        throw std::runtime_error("Error: Unable to add key");
    
    arguments.parse(argc, argv);
    
    //Execute callback functions
    arguments.run();


    //Loop over all keys
    if(arguments.keyCount() > 0 )
    {
        std::cout << "\nLoop over all the keys" << std::endl;    

        for(std::size_t i = 0; i < arguments.keyCount(); ++i)
        {
            std::pair<std::string, GU::Core::ArgumentData> data = arguments.getKey(i);
            std::cout << "Key = " << std::setw(20) << std::left << data.first;
            if(!data.second.value.empty())
                std::cout << " value = " << data.second.value << std::endl;
            else
                std::cout << std::endl;
        }
    
    }


    //Positional Argumnets
    if(arguments.positionalSize() > 0)
    {
        std::cout << "\nLoop over all positional arguments" << std::endl;    

        for(std::size_t i = 0; i < arguments.positionalSize(); ++i)
            std::cout << "Positional Arguments [" << i << "] " << arguments[i] << std::endl;
    }
    return 0;
}
