#include "GameUtilities/Event/EventManager.h"
#include "GameUtilities/Event/Pop.h"
#include "GameUtilities/Event/EventId.h"
#include <iostream>

int main()
{
    GU::Evt::EventManager::inst().Post<GU::Evt::Pop>();
	GU::Evt::EventPtr evt;
    while(GU::Evt::EventManager::inst().Poll(evt))
    {
        switch(evt->getId())
        {
            case GU::Evt::EventId::POP_STATE:
               std::cout << "Pop Event" << std::endl; 
            break;
        }
    }    
    return 0;
}
