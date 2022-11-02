#include "GameUtilities/Event/Dispatcher.h"
#include "GameUtilities/Event/Listener.h"
#include <cassert>
#include <algorithm>
#include <map>
#include <mutex>
#include <vector>

namespace GU
{
    namespace Evt
    {
		class Dispatcher::Impl
		{
			public:
				typedef std::vector<ListenerPtr> listenerVecPtr;


				/***********************************************************
				*   @brief Constructor
				***********************************************************/
                Impl()
                {

                }


                /***********************************************************
				*   @brief  Register a listner for an event with the given
				*           id.
				*   @param  listener the object to be called when an event
				*           with the given id occures.
				*   @param  id is the events numerical identifier
				*           See Dispatcher::RegisterListener
				***********************************************************/
                void RegisterListener(ListenerPtr listener, const int id)
                {
                    assert(listener != nullptr);

                    #ifdef MULTITHREAD
                        std::lock_guard<std::mutex> listenersMapLock(listenerMapGuard);
                    #endif

                    //Add a vector to the map with the correct key if one does not exist
                    if (listenerMap.find(id) == listenerMap.end())
                        listenerMap.emplace(id, listenerVecPtr());

                    auto iter = listenerMap.find(id);

                    //Make sure the listener has not already been added to the map
                    assert(!IsRegistered(listener, ALL));
                    assert(!IsRegistered(listener, id));

                    //Add element to vector at key id
                    iter->second.push_back(listener);
                }



                /***********************************************************
				*   @brief  Register a listener for the given event
				*   @param  listener a poinyrt to the object to be called
				*           when the given event is called
				*   @param  event is the Event that triggers the given
				*           listener.
				*           See Engin::RegisterListener
				***********************************************************/
                void RegisterListener(ListenerPtr listener, EventPtr event)
                {
                    assert(event != nullptr);
                    assert(listener != nullptr);
                    RegisterListener(listener, event->getId());
                }



                /***********************************************************
				*   @brief  Register a Listener for the event identified
				*           by the given id.
				*   @param  listener reference to a Listener object
				*   @param  id the numerical identifier for the event
				*           the Listener is being registered for
				*           Dispatcher::RegisterListener
				***********************************************************/
                void RegisterListener(Listener &listener, const int id)
                {
                    RegisterListener(&listener, id);
                }


                /***********************************************************
				*   @brief  Register a listener for the given event
				*   @param  listener a Listener object to be registered
				*           with the given event.
				*   @param  event is a pointer to an Event which will
				*           be registered with the given Listener
				*           See Dispatcher::RegisterListener
				***********************************************************/
                void RegisterListener(Listener &listener, EventPtr event)
                {
                    assert(event != nullptr);
                    RegisterListener(&listener, event);
                }


                /***********************************************************
				*   @brief  Unregister a listener which was previously
				*           registered with RegisterListener.
				*   @param  listener is a ponter to a Listener object
				*           that was previously registered with
				*           RegisterListener.
				*   @param  id the numerical identifier for an Event
				*           See Dispatcher::RegisterListener
				*           See Dispatcher::UnRegisterListener
				***********************************************************/
                void UnRegisterListener(ListenerPtr listener, const int id)
                {
                    assert(listener != nullptr);

                    #ifdef MULTITHREAD
                        std::lock_guard<std::mutex> listenersMapLock(listenerMapGuard);
                    #endif

                    assert(IsRegistered(listener, id));
                    listenerVecPtr &vec = listenerMap.find(id)->second;
                    vec.erase(std::find(vec.begin(), vec.end(), listener));
                }


                /***********************************************************
				*   @brief  Unregister a Listener that was previously
				*           registered with RegisterListener.
				*   @param  listener a pointer to a Listener object to
				*           be unregistered.
				*   @param  event a pointer to an event object that will
				*           no loger be registered with the given Listener.
				*           See Displatcher::UnRegisterListener
				***********************************************************/
                void UnRegisterListener(ListenerPtr listener, EventPtr event)
                {
                    assert(listener != nullptr);
                    assert(event != nullptr);
                    UnRegisterListener(listener, event->getId());
                }


                /***********************************************************
				*   @brief  Unregister a Listener that was previously
				*           registered with RegisterListener.
				*   @param  listener a pointer to a Listener object to
				*           be unregistered.
				*   @param  id the numerical identifier of an event.
				*           See Dispatcher::UnRegisterListener
				***********************************************************/
                void UnRegisterListener(Listener &listener, const int id)
                {
                    UnRegisterListener(&listener, id);
                }


                /***********************************************************
				*   @brief  Unregister a Listener that was previously
				*           registered with RegisterListener.
				*   @param  listener a pointer to a Listener object to
				*           be unregistered.
				*   @param  event a pointer to an event object that will
				*           no loger be registered with the given Listener.
				*           See Displatcher::UnRegisterListener
				***********************************************************/
                void UnRegisterListener(Listener &listener, EventPtr event)
                {
                    assert(event != nullptr);

                    UnRegisterListener(&listener, event);
                }


                /***********************************************************
				*   @brief  Determine if a Listener has already been registered
				*           for an event.
				*   @param  listener a pointer to a Listener object.
				*   @param  id the numerical identifier of an event.
				*           Dispacher::IsRegistered
				***********************************************************/
                bool IsRegistered(ListenerPtr listener, const int id)
                {
                    assert(listener != nullptr);

                    auto iter = listenerMap.find(id);
                    if (iter == listenerMap.end())
                        return false;

                    return std::find(iter->second.begin(), iter->second.end(), listener) != iter->second.end();
                }


                /***********************************************************
				*   @brief  Determine if a Listener has already been registered
				*           for an event.
				*   @param  listener a pointer to a Listener object.
				*   @param  event is a pointer to an Event object wich
				*           may be registered with a Listener
				*           Dispacher::IsRegistered
				***********************************************************/
                bool IsRegistered(ListenerPtr listener, EventPtr event)
                {
                    assert(listener != nullptr);
                    assert(event != nullptr);

                    return IsRegistered(listener, event->getId());
                }

                /***********************************************************
				*   @brief  Determine if a Listener has already been registered
				*           for an event.
				*   @param  listener a reference to a Listener object.
				*   @param  id the numerical identifier of an event.
				*           Dispacher::IsRegistered
				***********************************************************/
                bool IsRegistered(Listener &listener, const int id)
                {
                    return IsRegistered(&listener, id);
                }


                /***********************************************************
				*   @brief  Determine if a Listener has already been registered
				*           for an event.
				*   @param  listener a reference to a Listener object.
				*   @param  event is a pointer to an Event object wich
				*           may be registered with a Listener
				*           Dispacher::IsRegistered
				***********************************************************/
                bool IsRegistered(Listener &listener, EventPtr event)
                {
                    assert(event != nullptr);

                    return IsRegistered(&listener, event);
                }


                /***********************************************************
				*   @brief  Dispatch an event to any registered listeners
				*   @param  event a pointer to an event to be dispatched
				*           See Dispatch::Dispatch
				***********************************************************/
                void Dispatch(EventPtr event)
                {
                    assert(event != nullptr);

                    if (listenerMap.find(ALL) != listenerMap.end())
                    {
                        listenerVecPtr &vec = listenerMap.find(ALL)->second;
                        for (auto element : vec)
                            element->OnEvent(event);
                    }


                    if (listenerMap.find(event->getId()) != listenerMap.end())
                    {
                        listenerVecPtr &vec2 = listenerMap.find(event->getId())->second;
                        for (auto element : vec2)
                            element->OnEvent(event);
                    }
                }


                /***********************************************************
				*   @brief Destructor
				***********************************************************/
                virtual ~Impl()
                {

                }
			private:
				std::map<int, listenerVecPtr> listenerMap;
				std::mutex listenerMapGuard;

		};



        /********************************************************************************************
        *   Constructor
        ********************************************************************************************/
        Dispatcher::Dispatcher(): pimpl(new Dispatcher::Impl())
        {
            //ctor
        }

        /*******************************************************************************************
        *   Purpose:    This method registers an event listener with an event.
        *   Input:      listener a pointer to the listener to be registered.
        *               const int the id of the event listener should listen for.
        *               if id = ALL (-1) then the listener will receive all events
        *******************************************************************************************/
        void Dispatcher::RegisterListener(ListenerPtr listener, const int id)
        {
            assert(pimpl != nullptr);
			pimpl->RegisterListener(listener, id);
        }


        /*******************************************************************************************
        *   Purpose:    This method registers an event listener with an event.
        *   Input:      listener a pointer to the listener to be registered.
        *               EventPtr the event that the listener will listen for.
        *               if event = EventPtr(new Event); then the listener will receive all events.
        *******************************************************************************************/
        void Dispatcher::RegisterListener(ListenerPtr listener, EventPtr event)
        {
            assert(pimpl != nullptr);
			pimpl->RegisterListener(listener, event);
        }


        /*******************************************************************************************
        *   Purpose:    This method registers an event listener with an event.
        *   Input:      Evt::Listener& a reference to the listener to be registered.
        *               const int the id of the event listener should listen for.
        *               if id = ALL (-1) then the listener will receive all events
        *******************************************************************************************/
        void Dispatcher::RegisterListener(Evt::Listener &listener, const int id)
        {
            assert(pimpl != nullptr);
			pimpl->RegisterListener(listener, id);
        }


        /*******************************************************************************************
        *   Purpose:    This method registers an event listener with an event.
        *   Input:      Evt::Listener& a reference to the listener to be registered.
        *               EventPtr the event that the listener will listen for.
        *               if event = EventPtr(new Event); then the listener will receive all events.
        *******************************************************************************************/
        void Dispatcher::RegisterListener(Evt::Listener &listener, EventPtr event)
        {
            assert(pimpl != nullptr);
			pimpl->RegisterListener(listener, event);
        }


        /*******************************************************************************************
        *   Purpose:    This method unregisters an event listener.
        *   Input:      listener a pointer to the listener to be unregistered.
        *               const int the id of the event the listener should be unregistered from.
        *               if id = Evt::ALL then the listener will be unregistered from all events.
        *******************************************************************************************/
        void Dispatcher::UnRegisterListener(ListenerPtr listener, const int id)
        {
            assert(pimpl != nullptr);
			pimpl->UnRegisterListener(listener, id);
        }


        /*******************************************************************************************
        *   Purpose:    This method unregisters an event listener.
        *   Input:      listener a pointer to the listener to be unregistered.
        *               EventPtr a pointer to the event listener should be unregistered from.
        *               if event = EventPtr(new Event); then the listener will be unregistered from
        *               all events.
        *******************************************************************************************/
        void Dispatcher::UnRegisterListener(ListenerPtr listener, EventPtr event)
        {
            assert(pimpl != nullptr);
			pimpl->UnRegisterListener(listener, event);
        }


        /*******************************************************************************************
        *   Purpose:    This method unregisters an event listener.
        *   Input:      Evt::Listener& a reference to the listener to be unregistered.
        *               const int the id of the event the listener should be unregistered from.
        *               if id = Evt::ALL then the listener will be unregistered from all events.
        *******************************************************************************************/
        void Dispatcher::UnRegisterListener(Evt::Listener &listener, const int id)
        {
            assert(pimpl != nullptr);
			pimpl->UnRegisterListener(listener, id);
        }


        /*******************************************************************************************
        *   Purpose:    This method unregisters an event listener.
        *   Input:      Evt::Listener& a reference to the listener to be unregistered.
        *               EventPtr a pointer to the event listener should be unregistered from.
        *               if event = EventPtr(new Event); then the listener will be unregistered from
        *               all events.
        *******************************************************************************************/
        void Dispatcher::UnRegisterListener(Evt::Listener &listener, EventPtr event)
        {
            assert(pimpl != nullptr);
			pimpl->UnRegisterListener(listener, event);
        }


        /*******************************************************************************************
        *   @brief          This method returns true if a listener has already been registered with an
        *                   event.
        *   @param [in]     listener a pointer to a listener in question of being registered with
        *                   the given event.
        *   @param [in]     id of the event in question of being registered with the
        *                   given listener.
        *   @return         bool true if the listener has already been registered.
        *   @retval         True when a Listener is successfully registered.
        *   @retval         False when a Listener is not successfully registered.
        *******************************************************************************************/
        bool Dispatcher::IsRegistered(ListenerPtr listener, const int id)
        {
            assert(pimpl != nullptr);
			return pimpl->IsRegistered(listener, id);
        }


        /*******************************************************************************************
        *   Purpose:    This method returns true if a listener has already been registered with an
        *               event.
        *   Input:      listener a pointer to a listener in question of being registered with
        *               the given event.
        *               EventPtr a pointer of the event in question of being registered with the
        *               given listener.
        *   Return:     bool true if the listener has already been registered.
        *******************************************************************************************/
        bool Dispatcher::IsRegistered(ListenerPtr listener, EventPtr event)
        {
            assert(pimpl != nullptr);
			return pimpl->IsRegistered(listener, event);
        }


        /*******************************************************************************************
        *   Purpose:    This method returns true if a listener has already been registered with an
        *               event.
        *   Input:      Evt::Listener& a reference to a listener in question of being registered with
        *               the given event.
        *               const int the id of the event in question of being registered with the
        *               given listener.
        *   Return:     bool true if the listener has already been registered.
        *******************************************************************************************/
        bool Dispatcher::IsRegistered(Evt::Listener &listener, const int id)
        {
            assert(pimpl != nullptr);
			return pimpl->IsRegistered(listener, id);
        }


        /*******************************************************************************************
        *   Purpose:    This method returns true if a listener has already been registered with an
        *               event.
        *   Input:      Evt::Listener& a reference to a listener in question of being registered with
        *               the given event.
        *               EventPtr a pointer of the event in question of being registered with the
        *               given listener.
        *   Return:     bool true if the listener has already been registered.
        *******************************************************************************************/
        bool Dispatcher::IsRegistered(Evt::Listener &listener, EventPtr event)
        {
            assert(pimpl != nullptr);
			return pimpl->IsRegistered(listener, event);
        }


        /*******************************************************************************************
        *   Purpose:    This method is used to send an event to any listeners that are registered
        *               to listen for the event.
        *   Input:      event a pointer to the event.
        *******************************************************************************************/
        void Dispatcher::Dispatch(EventPtr event)
        {
            assert(pimpl != nullptr);
			pimpl->Dispatch(event);
        }


        /*******************************************************************************************
        *   Destructor
        *******************************************************************************************/
        Dispatcher::~Dispatcher()
        {
            //dtor
            if(pimpl != nullptr)
            {
                delete pimpl;
                pimpl = nullptr; 
            }
        }
    }
}
