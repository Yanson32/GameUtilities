#include "GameUtilities/Engin/Engin.h"

#include <cassert>
#include <stack>

namespace GU
{

    namespace Engin
    {

		class Engin::Impl
		{
			public:
				typedef GU::Engin::Engin::StatePtr StatePtr;
				void Push(StatePtr state);
				void Pop();
				void ChangeState(StatePtr state);
				bool IsRunning() const;
				void Quit();
				void HandleEvents(const int &deltaTime);
				void Update(const int &deltaTime);
				void Draw(const int &deltaTime);
				virtual ~Impl();
			private:
				///stack of states the state on the top of the stack is the current state
				std::stack<StatePtr> states;

				///true while the game is running and false otherwise
				bool _running = true;

				GU::Engin::Engin &engin;
		};



		void Engin::Impl::Push(StatePtr state)
		{
			assert(state != nullptr);

			if (!states.empty())
			{
				states.top()->Pause();
				states.top()->Clean();
			}

			states.push(std::move(state));
			states.top()->Init();
		}
		void Engin::Impl::Pop()
		{
			assert(!states.empty());

			states.top()->Clean();
			states.pop();

			if (!states.empty())
			{
				states.top()->Init();
				states.top()->Pause(false);
			}
		}
		void Engin::Impl::ChangeState(StatePtr state)
		{
			assert(state != nullptr);

			///Remove any existing states
			while (!states.empty())
				this->Pop();

			///Push the state onto the now empty stack
			this->Push(std::move(state));
		}
		bool Engin::Impl::IsRunning() const
		{
			return _running;
		}
		void Engin::Impl::Quit()
		{
			_running = false;
		}
		void Engin::Impl::HandleEvents(const int &deltaTime)
		{
			assert(!states.empty());

			///Call the current states HandleEvents method.
			states.top()->HandleEvents(engin, deltaTime);
		}
		void Engin::Impl::Update(const int &deltaTime)
		{
			assert(!states.empty());

			///Call the current states Update method.
			states.top()->Update(engin, deltaTime);
		}
		void Engin::Impl::Draw(const int &deltaTime)
		{
			assert(!states.empty());

			///Call the current states Draw method.
			states.top()->Draw(engin, deltaTime);
		}
		Engin::Impl::~Impl()
		{

		}
        /*********************************************************************************//**
        *   \brief	Default constructor
        *************************************************************************************/
        Engin::Engin()
        {
            //ctor

        }





        /*********************************************************************************//**
        *	\brief	Push a new state onto the stack.
        *   \param	state a pointer to a GameState object.
        *************************************************************************************/
        void Engin::Push(StatePtr state)
        {
			pimpl->Push(std::move(state));
        }


        /*********************************************************************************//**
        *   \brief Remove a state from the stack
        *************************************************************************************/
        void Engin::Pop()
        {
			pimpl->Pop();
        }


        /*********************************************************************************//**
        *   \brief 	Remove any existing GameState objects from the stack, and push
        *           A new GameState object onto the stack.
        *   \param	state a pointer to a GameState object.
        *************************************************************************************/
        void Engin::ChangeState(StatePtr state)
        {
			pimpl->ChangeState(std::move(state));
        }


        /*********************************************************************************//**
        *   \brief	This method is used to determine if the game is still running.
        *	\return boolean true when the game is running and false otherwise
        *************************************************************************************/
        bool Engin::IsRunning() const
        {
			return pimpl->IsRunning();
        }


        /*********************************************************************************//**
        *   \brief	This method is used to end the game.
        *
        *	\return	After calling this method IsRunning() returns false.
        *************************************************************************************/
        void Engin::Quit()
        {
			return pimpl->Quit();
        }


        /*********************************************************************************//**
        *   \brief	This method is used to call an equivalent method in a GameState
        *           class. Which will have code for handling all kinds of input
        *           include events and user input.
        *   @param  deltaTime is the time the previous frame took
        *************************************************************************************/
        void Engin::HandleEvents(const int &deltaTime)
        {
			pimpl->HandleEvents(deltaTime);
        }


        /*********************************************************************************//**
        *   \brief	 This method is used to call an equivalent method in a GameState
        *            class. Which will have code for handling game logic.
        *   @param  deltaTime is the time the previous frame took
        *************************************************************************************/
        void Engin::Update(const int &deltaTime)
        {
			pimpl->Update(deltaTime);
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
			pimpl->Draw(deltaTime);
        }


        /*********************************************************************************//**
        *   \brief	Destructor:
        *************************************************************************************/
        Engin::~Engin()
        {
            //dtor
            if(pimpl)
                delete pimpl;
        }
    }

}
