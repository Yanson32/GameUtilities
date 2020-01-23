#include "GameUtilities/Engin/Engin.h"

#include <cassert>
#include <stack>

namespace GU
{

    namespace Engin
    {


        /*************************************************************************
        *   @author Wayne J Larson Jr.
        *   @brief  Implimentation of the Engin class.
        *   @date   3/20/18
        *************************************************************************/
		class Engin::Impl
		{
			public:
				typedef GU::Engin::Engin::StatePtr StatePtr; //pointer to gamestate

                /********************************************************************
                *   @brief  Constructor
                *   @param  engin is a reference to the parent GU::Engin::Engin
                *           class.
                ********************************************************************/
                Impl(GU::Engin::Engin &engin);


                Impl(Impl&& param):
                engin(param.engin),
                _running(param._running)
                {
                    states = std::move(param.states);
                    _running = param._running;
                }

                Impl& operator=(Impl&& param)
                {
                    if (this != &param)
                    {
                        states = std::move(param.states);
                        _running = param._running;
                    }
                    return *this;
                }

                /********************************************************************
                *   @brief  Implimentation for adding another state to the stack of
                *           states. See Engin::Push(StatePtr state);
                *   @param  state is a pointer to a GameState.
                ********************************************************************/
                void Push(StatePtr state);


                /********************************************************************
                *   @brief  Implimentation for removing a state from the stack of
                *           states.
                *           See Engin::Pop();
                ********************************************************************/
                bool Pop();


                /********************************************************************
                *   @brief  Implimentation for Engin::ChangeState. Any states on the
                *           stack will be removed. The only state on the stack after
                *           this call will be the state passed as a parameter.
                *           See Engin::ChangeState
                *   @param  state is a pointer to a GameState.
                ********************************************************************/
                void ChangeState(StatePtr state);


                /********************************************************************
                *   @brief  Implimentation for Engin::IsRunning which returns a
                *           boolean true value when the game is still running. See
                *           Engin::IsRunning
                ********************************************************************/
                bool IsRunning() const;


                /********************************************************************
                *   @brief  Implimentation for Engin::Quit. Once this methos runs
                *           Engin::IsRunning will return false.
                *           See Engin::Quit
                *           See Engin::IsRunning
                ********************************************************************/
                void Quit();

                bool empty() const
                {
                    return states.empty();
                }
                /********************************************************************
                *   @brief  This method handles all types of input.
                *   @param  deltaTime is the time the previous frame took
                *           See Engin::HendleEvents
                ********************************************************************/
                void HandleEvents(const float &deltaTime);


                /********************************************************************
                *   @brief  This method executes per frame logic.
                *   @param  deltaTime is the time the previous frame took
                *           See Engin::Update
                ********************************************************************/
                void Update(const float &deltaTime);


                /********************************************************************
                *   @brief  This method draws the current frame.
                *   @param  deltaTime is the time the previous frame took
                *           See Engin::Draw
                ********************************************************************/
                void Draw(const float &deltaTime);

                int Size() const
                {
                    return states.size();
                }
                /********************************************************************
                *   @brief  Destructor
                ********************************************************************/
                virtual ~Impl();
			private:
				//stack of states the state on the top of the stack is the current state
				std::stack<StatePtr> states;

                //Referece to an Engin object
				GU::Engin::Engin &engin;

				//true while the game is running and false otherwise
				bool _running = true;
		};


        /********************************************************************
        *   @brief  Constructor
        *   @param  engin is a reference to the parent GU::Engin::Engin
        *           class.
        ********************************************************************/
        Engin::Impl::Impl(GU::Engin::Engin &engin):
        engin(engin),
        _running(true)
        {
        }


        /********************************************************************
        *   @brief  Implimentation for adding another state to the stack of
        *           states. See Engin::Push(StatePtr state);
        *   @param  state is a pointer to a GameState.
        ********************************************************************/
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


        /********************************************************************
        *   @brief  Implimentation for removing a state from the stack of
        *           states.
        *           See Engin::Pop();
        *   @return boolean true when the state is successfully removed
        *           from the stack.
        ********************************************************************/
		bool Engin::Impl::Pop()
		{
			if(states.empty())
			{
				return false;
			}


			states.top()->Clean();
			states.pop();

			if (!states.empty())
			{
				states.top()->Init();
				states.top()->Pause(false);
			}

			return true;
		}


        /********************************************************************
        *   @brief  Implimentation for Engin::ChangeState. Any states on the
        *           stack will be removed. The only state on the stack after
        *           this call will be the state passed as a parameter.
        *           See Engin::ChangeState
        *   @param  state is a pointer to a GameState.
        ********************************************************************/
		void Engin::Impl::ChangeState(StatePtr state)
		{
			assert(state != nullptr);


			///Remove any existing states
			while (!states.empty())
				this->Pop();

			///Push the state onto the now empty stack
			this->Push(std::move(state));
		}


        /********************************************************************
        *   @brief  Implimentation for Engin::IsRunning which returns a
        *           boolean true value when the game is still running. See
        *           Engin::IsRunning
        ********************************************************************/
		bool Engin::Impl::IsRunning() const
		{
			return _running;
		}


        /********************************************************************
        *   @brief  Implimentation for Engin::Quit. Once this methos runs
        *           Engin::IsRunning will return false.
        *           See Engin::Quit
        *           See Engin::IsRunning
        ********************************************************************/
		void Engin::Impl::Quit()
		{
			_running = false;
		}


        /********************************************************************
        *   @brief  This method handles all types of input.
        *   @param  deltaTime is the time the previous frame took
        *           See Engin::HendleEvents
        ********************************************************************/
		void Engin::Impl::HandleEvents(const float &deltaTime)
		{
			assert(!states.empty());

			///Call the current states HandleEvents method.
			states.top()->HandleEvents(engin, deltaTime);
		}


        /********************************************************************
        *   @brief  This method executes per frame logic.
        *   @param  deltaTime is the time the previous frame took
        *           See Engin::Update
        ********************************************************************/
		void Engin::Impl::Update(const float &deltaTime)
		{
			assert(!states.empty());

			///Call the current states Update method.
			states.top()->Update(engin, deltaTime);
		}


        /********************************************************************
        *   @brief  This method draws the current frame.
        *   @param  deltaTime is the time the previous frame took
        *           See Engin::Draw
        ********************************************************************/
		void Engin::Impl::Draw(const float &deltaTime)
		{
			assert(!states.empty());

			///Call the current states Draw method.
			states.top()->Draw(engin, deltaTime);
		}


        /********************************************************************
        *   @brief  Destructor
        ********************************************************************/
        Engin::Impl::~Impl()
		{

		}


        /*********************************************************************************//**
        *   @brief	Default constructor
        *************************************************************************************/
        Engin::Engin(): pimpl(new Engin::Impl(*this))
        {
            //ctor

        }



        Engin::Engin(Engin&& param)
        {
            if(pimpl)
                delete pimpl;

            pimpl = param.pimpl;
            param.pimpl = nullptr;
        }


        Engin& Engin::operator=(Engin&& param)
        {
            assert(pimpl != nullptr);
            assert(param.pimpl != nullptr);
            pimpl = param.pimpl;

			return *this;
        }

        /*********************************************************************************//**
        *	@brief	Push a new state onto the stack.
        *   @param	state a pointer to a GameState object.
        *************************************************************************************/
        void Engin::Push(StatePtr state)
        {
            assert(pimpl != nullptr);
			pimpl->Push(std::move(state));
        }


        /*********************************************************************************//**
        *   @brief Remove a state from the stack
        *   @return boolean true when the state is successfully removed
        *           from the stack.
        *************************************************************************************/
        bool Engin::Pop()
        {
            assert(pimpl != nullptr);
			return pimpl->Pop();
        }


        /*********************************************************************************//**
        *   @brief 	Remove any existing GameState objects from the stack, and push
        *           A new GameState object onto the stack.
        *   @param	state a pointer to a GameState object.
        *************************************************************************************/
        void Engin::ChangeState(StatePtr state)
        {
            assert(pimpl != nullptr);
			pimpl->ChangeState(std::move(state));
        }


        /*********************************************************************************//**
        *   @brief	This method is used to determine if the game is still running.
        *	@return boolean true when the game is running and false otherwise
        *************************************************************************************/
        bool Engin::IsRunning() const
        {
            assert(pimpl != nullptr);
			return pimpl->IsRunning();
        }


        /*********************************************************************************//**
        *   @brief	This method is used to end the game.
        *
        *	@return	After calling this method IsRunning() returns false.
        *************************************************************************************/
        void Engin::Quit()
        {
            assert(pimpl != nullptr);
			return pimpl->Quit();
        }

        bool Engin::empty() const
        {
            assert(pimpl != nullptr);
            return pimpl->empty();
        }
        /*********************************************************************************//**
        *   @brief	This method is used to call an equivalent method in a GameState
        *           class. Which will have code for handling all kinds of input
        *           include events and user input.
        *   @param  deltaTime is the time the previous frame took
        *************************************************************************************/
        void Engin::HandleEvents(const float &deltaTime)
        {
            assert(pimpl != nullptr);
			pimpl->HandleEvents(deltaTime);
        }


        /*********************************************************************************//**
        *   @brief	 This method is used to call an equivalent method in a GameState
        *            class. Which will have code for handling game logic.
        *   @param  deltaTime is the time the previous frame took
        *************************************************************************************/
        void Engin::Update(const float &deltaTime)
        {
            assert(pimpl != nullptr);
			pimpl->Update(deltaTime);
        }


        /*********************************************************************************//**
        *   @brief	Remove any existing GameState objects from the stack, and push
        *           A new GameState object onto the stack. The new state will be
        *           created internally the user specifies the type of state, and
        *           passes any arguments needed by the states constructor.
        *   @param  StatePtr a pointer to a GameState object.
        *   @param  deltaTime is the time the previous frame took
        *************************************************************************************/
        void Engin::Draw(const float &deltaTime)
        {
            assert(pimpl != nullptr);
			pimpl->Draw(deltaTime);
        }

        int Engin::Size() const
        {
            assert(pimpl != nullptr);
            return pimpl->Size();
        }

        /*********************************************************************************//**
        *   @brief	Destructor:
        *************************************************************************************/
        Engin::~Engin()
        {
            //dtor
            if(pimpl)
                delete pimpl;
        }
    }

}
