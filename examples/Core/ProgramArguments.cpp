#include "GameUtilities/Core/ProgramArguments.h"
#include <iostream>

struct Data
{
    std::string item_1 = "This is item 1";
    bool badass = true;
    
};

void badass(void* params)
{

    if(params == nullptr)
        throw std::runtime_error("Parameter cannot be null"); 
    
    Data *data = static_cast<Data*>(params);
   
    if(data == nullptr)
        throw std::runtime_error("Could not cast void pointer");
    
    std::cout << "Inside badass" << std::endl;
    
    std::cout << data->item_1 << std::endl;
    
    if(data->badass)
        std::cout << "I'm a badass" << std::endl;
    else
        std::cout << "I'm a pussy" << std::endl;
    
}

void help(void* params)
{
    std::cout << "--help            Display help text" << std::endl;
    std::cout << "--version, -v     Display program version" << std::endl;
}


int main(int argc, char **argv)
{
    GU::Core::ProgramArguments arguments(argc, argv);
    
    //Add help option 
    if(!arguments.add("--help", '\0', help))
        throw std::runtime_error("Error: unable to add key");

    
    //Add version option
    if(!arguments.add("--version", 'v', [](void*){ std::cout << "version = 0.0.0.1" << std::endl;}))
        throw std::runtime_error("Error: Unable to add key");

    //Positional Argumnets
    for(std::size_t i = 0; i < arguments.positionalSize(); ++i)
        std::cout << "Positional Arguments [" << i << "] " << arguments[i] << std::endl;

    Data *data = new Data();
   
    std::pair<GU::Core::ProgramArguments::Callback, void*> dataPair;
    dataPair.first = badass;
    dataPair.second = data; 
    //Add version option
    if(!arguments.add("--badass", 'b', dataPair))
        throw std::runtime_error("Error: Unable to add key");

    //Execute callback functions
    arguments.run();
         
    delete data;
    data = nullptr;


    return 0;
}
