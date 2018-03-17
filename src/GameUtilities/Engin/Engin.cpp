#include "GameUtilities/Engin/Engin.h"
#include <cassert>

namespace GU
{

    namespace Engin
    {

        /*********************************************************************************//**
        *   \brief	Default constructor
        *************************************************************************************/
        Engin::Engin()
        {
            //ctor

        }


        /*********************************************************************************//**
        *   \brief		Copy constructor
        *	\warning 	The copy constructor is not complete
        *	\param		newStates an Engin object to be copied
        *************************************************************************************/
        Engin::Engin(const Engin& newStates)
        {
            assert(true && "Copy constructor not complete");
            _running = newStates._running;
        }


        /*********************************************************************************//**
        *   \brief		Assignment operator
        *	\warning 	assignment operator is not complete
        *	\param		newStates an Engin object to be copied
        *************************************************************************************/
        Engin& Engin::operator=(const Engin& newStates)
        {
            assert(true && "Assignment operator not complete");
            _running = newStates._running;
            return *this;
        }


        /*********************************************************************************//**
        *	\brief	Push a new state onto the stack.
        *   \param	state a pointer to a GameState object.
        *************************************************************************************/
        void Engin::Push(StatePtr state)
        {
            assert(state != nullptr);

            if(!states.empty())
            {
                states.top()->Pause();
                states.top()->Clean();
            }

            states.push(std::move(state));
            states.top()->Init();
        }


        /*********************************************************************************//**
        *   \brief Remove a state from the stack
        *************************************************************************************/
        void Engin::Pop()
        {
            assert(!states.empty());

            states.top()->Clean();
            states.pop();

            if(!states.empty())
            {
                states.top()->Init();
                states.top()->Pause(false);
            }
        }


        /*********************************************************************************//**
        *   \brief 	Remove any existing GameState objects from the stack, and push
        *           A new GameState object onto the stack.
        *   \param	state a pointer to a GameState object.
        *************************************************************************************/
        void Engin::ChangeState(StatePtr state)
        {
            assert(state != nullptr);

            ///Remove any existing states
            while(!states.empty())
                this->Pop();

            ///Push the state onto the now empty stack
            this->Push(std::move(state));
        }


        /*********************************************************************************//**
        *   \brief	This method is used to determine if the game is still running.
        *	\return boolean true when the game is running and false otherwise
        *************************************************************************************/
        bool Engin::IsRunning() const
        {
            return _running;
        }


        /*********************************************************************************//**
        *   \brief	This method is used to end the game.
        *
        *	\return	After calling this method IsRunning() returns false.
        *************************************************************************************/
        void Engin::Quit()
        {
            _running = false;
        }


        /*********************************************************************************//**
        *   \brief	This method is used to call an equivalent method in a GameState
        *           class. Which will have code for handling all kinds of input
        *           include events and user input.
        *   @param  deltaTime is the time the previous frame took
        *************************************************************************************/
        void Engin::HandleEvents(const int &deltaTime)
        {
            assert(!states.empty());

            ///Call the current states HandleEvents method.
            states.top()->HandleEvents(*this, deltaTime);
        }


        /*********************************************************************************//**
        *   \brief	 This method is used to call an equivalent method in a GameState
        *            class. Which will have code for handling game logic.
        *   @param  deltaTime is the time the previous frame took
        *************************************************************************************/
        void Engin::Update(const int &deltaTime)
        {
            assert(!states.empty());

            ///Call the current states Update method.
            states.top()->Update(*this, deltaTime);
        }


        /*********************************************************************************//**
        *   \brief	Remove any existing GameState objects from the stack, and push
        *           A new GameState object onto the stack. The new state will be
        *           created internally the user specifies the type of state, and
        *           passes any arguments needed by the states constructor.
        *   \param  StatePtr a pointer to a GameState object.
        *   @param  deltaTime is the time the previous frame took
        *************************************************************************************/
        void Engin::Draw(const int &deltaTime)
        {
            assert(!states.empty());

            ///Call the current states Draw method.
            states.top()->Draw(*this, deltaTime);
        }


        /*********************************************************************************//**
        *   \brief	Destructor:
        *************************************************************************************/
        Engin::~Engin()
        {
            //dtor
        }
    }

}
