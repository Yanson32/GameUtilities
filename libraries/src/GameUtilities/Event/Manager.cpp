#include "GameUtilities/Event/Manager.h"
#include <cassert>

namespace GU
{
    namespace Evt
    {


        /**************************************************************************
        *	\brief	Constructor
        **************************************************************************/
        Manager::Manager()
        {
            //ctor
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
        *	\brief	Destructor
        **************************************************************************/
        Manager::~Manager()
        {
            //dtor
        }

    }
}
