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
				Impl();

				void RegisterListener(ListenerPtr listener, const int id = ALL);
				void RegisterListener(ListenerPtr listener, EventPtr event);
				void RegisterListener(Evt::Listener &listener, const int id = ALL);
				void RegisterListener(Evt::Listener &listener, EventPtr event);
				void UnRegisterListener(ListenerPtr listener, const int id = ALL);
				void UnRegisterListener(ListenerPtr listener, EventPtr event);
				void UnRegisterListener(Evt::Listener &listener, const int id = ALL);
				void UnRegisterListener(Evt::Listener &listener, EventPtr event);
				bool IsRegistered(ListenerPtr listener, const int id = ALL);
				bool IsRegistered(ListenerPtr listener, EventPtr event);
				bool IsRegistered(Evt::Listener &listener, const int id = ALL);
				bool IsRegistered(Evt::Listener &listener, EventPtr event);
				void Dispatch(EventPtr event);
				virtual ~Impl();
			private:
				std::map<int, listenerVecPtr> listenerMap;
				std::mutex listenerMapGuard;

		};

		Dispatcher::Impl::Impl()
		{

		}
		void Dispatcher::Impl::RegisterListener(ListenerPtr listener, const int id)
		{
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
		void Dispatcher::Impl::RegisterListener(ListenerPtr listener, EventPtr event)
		{
			assert(event != nullptr);
			RegisterListener(listener, event->id);
		}
		void Dispatcher::Impl::RegisterListener(Evt::Listener &listener, const int id)
		{
			RegisterListener(&listener, id);
		}
		void Dispatcher::Impl::RegisterListener(Evt::Listener &listener, EventPtr event)
		{
			RegisterListener(&listener, event);
		}
		void Dispatcher::Impl::UnRegisterListener(ListenerPtr listener, const int id)
		{
			#ifdef MULTITHREAD
				std::lock_guard<std::mutex> listenersMapLock(listenerMapGuard);
			#endif

			assert(IsRegistered(listener, id));
			listenerVecPtr &vec = listenerMap.find(id)->second;
			vec.erase(std::find(vec.begin(), vec.end(), listener));
		}
		void Dispatcher::Impl::UnRegisterListener(ListenerPtr listener, EventPtr event)
		{
			assert(event != nullptr);
			UnRegisterListener(listener, event->id);
		}
		void Dispatcher::Impl::UnRegisterListener(Evt::Listener &listener, const int id)
		{
			UnRegisterListener(&listener, id);
		}
		void Dispatcher::Impl::UnRegisterListener(Evt::Listener &listener, EventPtr event)
		{
			UnRegisterListener(&listener, event);
		}
		bool Dispatcher::Impl::IsRegistered(ListenerPtr listener, const int id)
		{
			auto iter = listenerMap.find(id);
			if (iter == listenerMap.end())
				return false;

			return std::find(iter->second.begin(), iter->second.end(), listener) != iter->second.end();
		}
		bool Dispatcher::Impl::IsRegistered(ListenerPtr listener, EventPtr event)
		{
			return IsRegistered(listener, event->id);
		}
		bool Dispatcher::Impl::IsRegistered(Evt::Listener &listener, const int id)
		{
			return IsRegistered(&listener, id);
		}
		bool Dispatcher::Impl::IsRegistered(Evt::Listener &listener, EventPtr event)
		{
			return IsRegistered(&listener, event);
		}
		void Dispatcher::Impl::Dispatch(EventPtr event)
		{
			assert(event != nullptr);
			if (listenerMap.find(ALL) != listenerMap.end())
			{
				listenerVecPtr &vec = listenerMap.find(ALL)->second;
				for (auto element : vec)
					element->OnEvent(event);
			}


			if (listenerMap.find(event->id) != listenerMap.end())
			{
				listenerVecPtr &vec2 = listenerMap.find(event->id)->second;
				for (auto element : vec2)
					element->OnEvent(event);
			}
		}
		Dispatcher::Impl::~Impl()
		{

		}

        /********************************************************************************************
        *   Constructor
        ********************************************************************************************/
        Dispatcher::Dispatcher(): pimpl(new Dispatcher::Impl())
        {
            //ctor
        }

        /*******************************************************************************************
        *   Purpose:    This method registers an event listener with an event.
        *   Input:      ListenerPtr a pointer to the listener to be registered.
        *               const int the id of the event listener should listen for.
        *               if id = ALL (-1) then the listener will receive all events
        *******************************************************************************************/
        void Dispatcher::RegisterListener(ListenerPtr listener, const int id)
        {
			pimpl->RegisterListener(listener, id);
        }


        /*******************************************************************************************
        *   Purpose:    This method registers an event listener with an event.
        *   Input:      ListenerPtr a pointer to the listener to be registered.
        *               EventPtr the event that the listener will listen for.
        *               if event = EventPtr(new Event); then the listener will receive all events.
        *******************************************************************************************/
        void Dispatcher::RegisterListener(ListenerPtr listener, EventPtr event)
        {
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
			pimpl->RegisterListener(listener, event);
        }


        /*******************************************************************************************
        *   Purpose:    This method unregisters an event listener.
        *   Input:      ListenerPtr a pointer to the listener to be unregistered.
        *               const int the id of the event the listener should be unregistered from.
        *               if id = Evt::ALL then the listener will be unregistered from all events.
        *******************************************************************************************/
        void Dispatcher::UnRegisterListener(ListenerPtr listener, const int id)
        {
			pimpl->UnRegisterListener(listener, id);
        }


        /*******************************************************************************************
        *   Purpose:    This method unregisters an event listener.
        *   Input:      ListenerPtr a pointer to the listener to be unregistered.
        *               EventPtr a pointer to the event listener should be unregistered from.
        *               if event = EventPtr(new Event); then the listener will be unregistered from
        *               all events.
        *******************************************************************************************/
        void Dispatcher::UnRegisterListener(ListenerPtr listener, EventPtr event)
        {
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
			pimpl->UnRegisterListener(listener, event);
        }


        /*******************************************************************************************
        *   @brief          This method returns true if a listener has already been registered with an
        *                   event.
        *   @param [in]     ListenerPtr a pointer to a listener in question of being registered with
        *                   the given event.
        *   @param [in]     id of the event in question of being registered with the
        *                   given listener.
        *   @return         bool true if the listener has already been registered.
        *   @retval         True when a Listener is successfully registered.
        *   @retval         False when a Listener is not successfully registered.
        *******************************************************************************************/
        bool Dispatcher::IsRegistered(ListenerPtr listener, const int id)
        {
			return pimpl->IsRegistered(listener, id);
        }


        /*******************************************************************************************
        *   Purpose:    This method returns true if a listener has already been registered with an
        *               event.
        *   Input:      ListenerPtr a pointer to a listener in question of being registered with
        *               the given event.
        *               EventPtr a pointer of the event in question of being registered with the
        *               given listener.
        *   Return:     bool true if the listener has already been registered.
        *******************************************************************************************/
        bool Dispatcher::IsRegistered(ListenerPtr listener, EventPtr event)
        {
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
			return pimpl->IsRegistered(listener, event);
        }


        /*******************************************************************************************
        *   Purpose:    This method is used to send an event to any listeners that are registered
        *               to listen for the event.
        *   Input:      EventPtr a pointer to the event.
        *******************************************************************************************/
        void Dispatcher::Dispatch(EventPtr event)
        {
			pimpl->Dispatch(event);
        }


        /*******************************************************************************************
        *   Destructor
        *******************************************************************************************/
        Dispatcher::~Dispatcher()
        {
            //dtor
            if(pimpl)
                delete pimpl;
        }
    }
}
