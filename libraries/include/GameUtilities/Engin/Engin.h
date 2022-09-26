/*********************************************************************************//**
*	\author	Wayne J Larson Jr.
*	\date 12/10/17
*************************************************************************************/

#ifndef GAMEUTILITIES_ENGIN_ENGIN_H
#define GAMEUTILITIES_ENGIN_ENGIN_H

#include <memory>
#include "GameUtilities/Engin/GameState.h"
#include "GameUtilities/Engin/Frame.h"
#include "engin_export.h"
#include <memory>

namespace GU
{
    namespace Engin
    {
        /*********************************************************************************//**
        *	\brief	This is the main game engin class
        *	\class Engin
        *************************************************************************************/
        class ENGIN_EXPORT Engin
        {
            public:
                typedef std::unique_ptr<GU::Engin::GameState> StatePtr;

                /*********************************************************************************//**
                *   @brief	Default constructor
                *************************************************************************************/
                Engin();

                Engin(const Engin& other) = delete;
                Engin(Engin&& param);

                Engin& operator=(const Engin& param) = delete;
                Engin& operator=(Engin&& param);
                /*********************************************************************************//**
                *	@brief	Push a new state onto the stack
                *   @param	state a pointer to a GameState object.
                *************************************************************************************/
                void push(StatePtr param, std::shared_ptr<GU::Engin::Frame> frame);


                /**************************************************************************//**
                *   @brief	Push a new state onto the stack. The state will be created
                *           Internally. The user specifies the type of state and passes
                *           any arguments needed by the states constructor.
                *   @param  Type the type of gamestate to be created
                *	@param	args these arguments will be passed to the GameState subclass to
                *			construct a GameState object.
                ******************************************************************************/
                template<typename Type, typename... Args>
                void push(std::shared_ptr<GU::Engin::Frame> frame, Args&&... args);


                /*********************************************************************************//**
                *   @brief Remove a state from the stack
                *   @return boolean true when the state is successfully removed
                *           from the stack.
                *************************************************************************************/
                bool pop(std::shared_ptr<GU::Engin::Frame> frame);


                /*********************************************************************************//**
                *   @brief 	Remove any existing GameState objects from the stack, and push
                *           A new GameState object onto the stack.
                *   @param	state a pointer to a GameState object.
                *************************************************************************************/
                void changeState(StatePtr param, std::shared_ptr<GU::Engin::Frame> frame);


                /**************************************************************************//**
                *   @brief	Remove any existing GameState objects from the stack, and push
                *           A new GameState object onto the stack. The new state will be
                *           created internally the user specifies the type of state, and
                *           passes any arguments needed by the states constructor.
                *	@param	args these arguments will be passed to the GameState subclass to
                *			construct a GameState object.
                *   @param  Type this is the type of GameState.
                ******************************************************************************/
                template<typename Type, typename... Args>
                void changeState(std::shared_ptr<GU::Engin::Frame> frame, Args&&... args);


                /*********************************************************************************//**
                *   @brief	This method is used to determine if the game is still running.
                *	@return boolean true when the game is running and false otherwise
                *************************************************************************************/
                bool isRunning() const;


                /*********************************************************************************//**
                *   @brief	This method is used to end the game.
                *
                *	@return	After calling this method IsRunning() returns false.
                *************************************************************************************/
                void quit();


                bool empty() const;


                /*********************************************************************************//**
                *   @brief	This method is used to call an equivalent method in a GameState
                *           class. Which will have code for handling all kinds of input
                *           include events and user input.
                *   @param  deltaTime is the time the previous frame took
                *************************************************************************************/
                void handleEvents(const float &deltaTime, std::shared_ptr<GU::Engin::Frame> frame);


                /*********************************************************************************//**
                *   @brief	 This method is used to call an equivalent method in a GameState
                *            class. Which will have code for handling game logic.
                *   @param  deltaTime is the time the previous frame took
                *************************************************************************************/
                void update(const float &deltaTime, std::shared_ptr<GU::Engin::Frame> frame);


                /*********************************************************************************//**
                *   @brief	Remove any existing GameState objects from the stack, and push
                *           A new GameState object onto the stack. The new state will be
                *           created internally the user specifies the type of state, and
                *           passes any arguments needed by the states constructor.
                *   @param  StatePtr a pointer to a GameState object.
                *   @param  deltaTime is the time the previous frame took
                *************************************************************************************/
                void draw(const float &deltaTime, std::shared_ptr<GU::Engin::Frame> frame);


                int size() const;
                /*********************************************************************************//**
                *   @brief	Destructor:
                *************************************************************************************/
                virtual ~Engin();
            private:
				class Impl;
				Impl* m_pimpl = nullptr;
        };


        /**************************************************************************//**
        *   \brief	Push a new state onto the stack. The state will be created
        *           Internally. The user specifies the type of state and passes
        *           any arguments needed by the states constructor.
        *   \param  Type the type of gamestate to be created
        *	\param	args these arguments will be passed to the GameState subclass to
        *			construct a GameState object.
        ******************************************************************************/
        template<typename Type, typename... Args>
        void Engin::push(std::shared_ptr<GU::Engin::Frame> frame, Args&&... args)
        {
            this->push(StatePtr(new Type(std::forward<Args>(args)...)), frame);
        }


        /**************************************************************************//**
        *   \brief	Remove any existing GameState objects from the stack, and push
        *           A new GameState object onto the stack. The new state will be
        *           created internally the user specifies the type of state, and
        *           passes any arguments needed by the states constructor.
        *	\param	args these arguments will be passed to the GameState subclass to
        *			construct a GameState object.
        *   \param  Type this is the type of GameState.
        ******************************************************************************/
        template<typename Type, typename... Args>
        void Engin::changeState(std::shared_ptr<GU::Engin::Frame> frame, Args&&... args)
        {
            this->changeState(StatePtr(new Type(std::forward<Args>(args)...)), frame);
        }
    }
}
#endif // ENGIN_H
