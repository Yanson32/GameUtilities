#include "GameUtilities/Event/EventManager.h"
#include <cassert>

namespace GU
{
    namespace Evt
    {

        /**************************************************************************
        *	@brief	Constructor
        **************************************************************************/
        EventManager::EventManager()
        {
            //ctor
        }


        /**************************************************************************
        *	@brief  This method returns a static instance of the EventManager class.	
        **************************************************************************/
        EventManager& EventManager::inst()
        {
	        static EventManager eventManager;
	        return eventManager;
        }

    //    bool Manager::RegisterListener(Evt::Listener *listener)
    //    {
    //        assert(listener != nullptr);
    //        _listeners.push_back(listener);
    //        return true;
    //    }


    //    void Manager::ProcessEvent(const Evt::Event &event)
    //    {
    //        for(auto element: _listeners)
    //        {
    //            assert(element != nullptr);
    //            element->ProcessEvent(event);
    //        }
    //
    //    }
    //    void Manager::Post( std::unique_ptr<Evt::Event> event)
    //    {
    //        _eventQueue.push(std::move(event));
    //    }


        /**************************************************************************
        *	@brief	Destructor
        **************************************************************************/
        EventManager::~EventManager()
        {
            //dtor
        }

    }
}
