#include "GameUtilities/Core/ProgramArguments.h"
#include "GameUtilities/Core/Macros.h"
#include <iostream>

struct Data
{
    std::string item_1 = "This is a cool item";
    bool cool = true;
    
};

void cool(std::shared_ptr<void> params)
{

    if(params == nullptr)
        throw std::runtime_error("Parameter cannot be null"); 
    
    std::shared_ptr<Data> data = std::static_pointer_cast<Data>(params);
   
    if(data == nullptr)
        throw std::runtime_error("Could not cast void pointer");
    
    std::cout << data->item_1 << std::endl;
    
    if(data->cool)
        std::cout << "Do cool thing" << std::endl;
    else
        std::cout << "Dont do cool thing" << std::endl;
    
}

void help(std::shared_ptr<void> params)
{
    UNUSED(params);
    std::cout << "--help            Display help text" << std::endl;
    std::cout << "--version, -v     Display program version" << std::endl;
    std::cout << "--cool, -c        Do somthing cool" << std::endl;
}


int main(int argc, char **argv)
{
    GU::Core::ProgramArguments arguments(argc, argv);
    
    //Add help option 
    if(!arguments.add("--help", '\0', help))
        throw std::runtime_error("Error: unable to add key");

    
    //Add version option
    if(!arguments.add("--version", 'v', [](std::shared_ptr<void> data = nullptr){ 
        UNUSED(data);
        std::cout << "version = 0.0.0.1" << std::endl;
    }))
        throw std::runtime_error("Error: Unable to add key");

    //Positional Argumnets
    for(std::size_t i = 0; i < arguments.positionalSize(); ++i)
        std::cout << "Positional Arguments [" << i << "] " << arguments[i] << std::endl;

   
    std::shared_ptr<Data> data(new Data());
   
    std::pair<GU::Core::ProgramArguments::Callback, std::shared_ptr<void>> dataPair;
    dataPair.first = cool;
    dataPair.second = data; 
    
    //Add version option
    if(!arguments.add("--cool", 'c', dataPair))
        throw std::runtime_error("Error: Unable to add key");

    //Execute callback functions
    arguments.run();
    
    return 0;
}
