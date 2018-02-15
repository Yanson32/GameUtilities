#ifndef GAMEUTILITIES_EVENT_DISPATCHER_H
#define GAMEUTILITIES_EVENT_DISPATCHER_H
/***************************************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   2/8/17
*   @file
*******************************************************************************************/

#include <vector>
#include <map>
#include <memory>
#include "GameUtilities/Event/Event.h"
#include <mutex>
#include "gameutilities_export.h"

namespace Evt
{
    class Listener;


    /***************************************************************************************//**
    *   @author Wayne J Larson Jr.
    *   @date   2/8/17
    *   @class  Dispatcher
    *   @brief  This class distributes events to the appropriate listeners.
    *******************************************************************************************/
    class GAMEUTILITIES_EXPORT Dispatcher
    {
        public:
            typedef Evt::Listener* ListenerPtr;
            typedef std::vector<ListenerPtr> listenerVecPtr;

            /***************************************************************************************//**
            *   @param Constructor
            ********************************************************************************************/
            Dispatcher();


            /***************************************************************************************//**
            *   @brief      This method registers an event listener with an event.
            *   @param [in] a pointer to the listener to be registered.
            *   @param [in] id of the event listener should listen for.
            *               if id = ALL (-1) then the listener will receive all events
            *******************************************************************************************/
            void RegisterListener(ListenerPtr listener, const int id = ALL);


            /***************************************************************************************//**
            *   @brief      This method registers an event listener with an event.
            *   @param [in] listener a pointer to the listener to be registered.
            *   @param [in] event the event that the listener will listen for.
            *               if event = EventPtr(new Event); then the listener will receive all events.
            *******************************************************************************************/
            void RegisterListener(ListenerPtr listener, EventPtr event);


            /***************************************************************************************//**
            *   @brief      This method registers an event listener with an event.
            *   @param [in] listener a reference to the listener to be registered.
            *   @param [in] id of the event listener should listen for.
            *               if id = ALL (-1) then the listener will receive all events
            *******************************************************************************************/
            void RegisterListener(Evt::Listener &listener, const int id = ALL);


            /***************************************************************************************//**
            *   @brief      This method registers an event listener with an event.
            *   @param [in] listener a reference to the listener to be registered.
            *   @param [in] event the event that the listener will listen for.
            *               if event = EventPtr(new Event); then the listener will receive all events.
            *******************************************************************************************/
            void RegisterListener(Evt::Listener &listener, EventPtr event);


            /***************************************************************************************//**
            *   @brief      This method registers an event listener with an event.
            *   @param [in] listener a reference to the listener to be registered.
            *   @param [in] args will be used to construct the Evt::Event subclass
            *   @tparam     Type is the type of event the listener should listen for
            *   @tparam     Args is an arbitrary number of arguments passed to the Events
            *               constructor. An event is created internally an registered with the listener.
            *******************************************************************************************/
            template<typename Type, typename... Args>
            void RegisterListener(Evt::Listener &listener, Args&&... args);


            /***************************************************************************************//**
            *   @brief      This method unregisters an event listener.
            *   @param [in] listener a pointer to the listener to be unregistered.
            *   @param [in] id of the event the listener should be unregistered from.
            *               if id = Evt::ALL then the listener will be unregistered from all events.
            *******************************************************************************************/
            void UnRegisterListener(ListenerPtr listener, const int id = ALL);


            /***************************************************************************************//**
            *   @brief      This method unregisters an event listener.
            *   @param [in] listener a pointer to the listener to be unregistered.
            *   @param [in] event a pointer to the event listener should be unregistered from.
            *               if event = EventPtr(new Event); then the listener will be unregistered from
            *               all events.
            *******************************************************************************************/
            void UnRegisterListener(ListenerPtr listener, EventPtr event);


            /***************************************************************************************//**
            *   @brief          This method unregisters an event listener.
            *   @param  [in]    listener a reference to the listener to be unregistered.
            *   @param [in]     id of the event the listener should be unregistered from.
            *                   if id = Evt::ALL then the listener will be unregistered from all events.
            *******************************************************************************************/
            void UnRegisterListener(Evt::Listener &listener, const int id = ALL);


            /***************************************************************************************//**
            *   @brief      This method unregisters an event listener.
            *   @param [in] listener a reference to the listener to be unregistered.
            *   @param [in] event a pointer to the event listener should be unregistered from.
            *               if event = EventPtr(new Event); then the listener will be unregistered from
            *               all events.
            *******************************************************************************************/
            void UnRegisterListener(Evt::Listener &listener, EventPtr event);


            /***************************************************************************************//**
            *   @brief  This method unregisters an event listener.
            *   @tparam Type is a subclass of the Evt::Event base class.
            *   @tparam Args list of arguments used to construct the Evt::Event subclass.
            *   @param  [in] listener a reference to the listener to be unregistered.
            *   @param [in] args a variable number of arguments.
            *******************************************************************************************/
            template<typename Type, typename... Args>
            void UnRegisterListener(Evt::Listener &listener, Args&&... args);


            /***************************************************************************************//**
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
            bool IsRegistered(ListenerPtr listener, const int id = ALL);


            /***************************************************************************************//**
            *   @brief      This method returns true if a listener has already been registered with an
            *               event.
            *   @param [in] listener a pointer to a listener in question of being registered with
            *               the given event.
            *   @param [in] event a pointer of the event in question of being registered with the
            *               given listener.
            *   @return     boolean true / false
            *   @retval     True if the Listener has already been registered.
            *   @retval     False if the Listener has not olready been registered.
            *******************************************************************************************/
            bool IsRegistered(ListenerPtr listener, EventPtr event);


            /***************************************************************************************//**
            *   @brief  This method returns true if a listener has already been registered with an
            *               event.
            *   @param [in] listener a reference to a listener in question of being registered with
            *               the given event.
            *   @param [in] id of the event in question of being registered with the
            *               given listener.
            *   @return     boolean true / false
            *   @retval     True if the Listener has already been registered.
            *   @retval     False if the Listener has not olready been registered.
            *******************************************************************************************/
            bool IsRegistered(Evt::Listener &listener, const int id = ALL);


            /***************************************************************************************//**
            *   @brief  This method returns true if a listener has already been registered with an
            *               event.
            *   @param [in] listener a reference to a listener in question of being registered with
            *               the given event.
            *   @param [in] event a pointer of the event in question of being registered with the
            *               given listener.
            *   @return     boolean true / false
            *   @retval     True if the Listener has already been registered.
            *   @retval     False if the Listener has not olready been registered.
            *******************************************************************************************/
            bool IsRegistered(Evt::Listener &listener, EventPtr event);


            /***************************************************************************************//**
            *   @brief      This method is used to send an event to any listeners that are registered
            *               to listen for the event.
            *   @param [in] a pointer to the event.
            *******************************************************************************************/
            void Dispatch(EventPtr event);


            /***************************************************************************************//**
            *   @brief  Destructor
            *******************************************************************************************/
            virtual ~Dispatcher();
        private:
            std::map<int, listenerVecPtr> listenerMap;
            std::mutex listenerMapGuard;
    };


    /***************************************************************************************//**
    *   @brief		This method registers an event listener with an event.
    *   @param [in]	listener a reference to the listener to be registered.
	*	@param [in]	args A list of arguments used to construct the listener
    *   @tparam		Type is the type of event the listener should listen for
    *   @tparam		Args is an arbitrary number of arguments passed to the Events
    *               constructor. An event is created internally an registered with the listener.
    *******************************************************************************************/
    template<typename Type, typename... Args>
    void Dispatcher::RegisterListener(Evt::Listener &listener, Args&&... args)
    {
        this->RegisterListener(listener, EventPtr(new Type(std::forward<Args>(args)...)));
    }


    /***************************************************************************************//**
    *   @brief		This method unregisters an event listener.
    *   @param [in]	listener a reference to the listener to be unregistered.
	*	@param [in]	args a list of arguments used to construct the listener.
    *   @tparam		Type the type of event the listener will listen for.
    *   @tparam		Args an arbitrary number of arguments to pass to the events
    *               constructor. An event is created internally when registering the listener
    *               and the events constructor must be called.
    *******************************************************************************************/
    template<typename Type, typename... Args>
    void Dispatcher::UnRegisterListener(Evt::Listener &listener, Args&&... args)
    {
        this->UnRegisterListener(listener, EventPtr(new Type(std::forward<Args>(args)...)));
    }
}
#endif // DISPATCHER_H
