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
                void push(StatePtr state);


                /********************************************************************
                *   @brief  Implimentation for removing a state from the stack of
                *           states.
                *           See Engin::Pop();
                ********************************************************************/
                bool pop();


                /********************************************************************
                *   @brief  Implimentation for Engin::ChangeState. Any states on the
                *           stack will be removed. The only state on the stack after
                *           this call will be the state passed as a parameter.
                *           See Engin::ChangeState
                *   @param  state is a pointer to a GameState.
                ********************************************************************/
                void changeState(StatePtr state);


                /********************************************************************
                *   @brief  Implimentation for Engin::IsRunning which returns a
                *           boolean true value when the game is still running. See
                *           Engin::IsRunning
                ********************************************************************/
                bool isRunning() const;


                /********************************************************************
                *   @brief  Implimentation for Engin::Quit. Once this methos runs
                *           Engin::IsRunning will return false.
                *           See Engin::Quit
                *           See Engin::IsRunning
                ********************************************************************/
                void quit();

                bool empty() const
                {
                    return states.empty();
                }
                /********************************************************************
                *   @brief  This method handles all types of input.
                *   @param  deltaTime is the time the previous frame took
                *           See Engin::HendleEvents
                ********************************************************************/
                void handleEvents(const float &deltaTime);


                /********************************************************************
                *   @brief  This method executes per frame logic.
                *   @param  deltaTime is the time the previous frame took
                *           See Engin::Update
                ********************************************************************/
                void update(const float &deltaTime);


                /********************************************************************
                *   @brief  This method draws the current frame.
                *   @param  deltaTime is the time the previous frame took
                *           See Engin::Draw
                ********************************************************************/
                void draw(const float &deltaTime);

                int size() const
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
        void Engin::Impl::push(StatePtr state)
		{
			assert(state != nullptr);

			if (!states.empty())
			{
				states.top()->pause();
				states.top()->clean();
			}

			states.push(std::move(state));
			states.top()->init();
		}


        /********************************************************************
        *   @brief  Implimentation for removing a state from the stack of
        *           states.
        *           See Engin::Pop();
        *   @return boolean true when the state is successfully removed
        *           from the stack.
        ********************************************************************/
		bool Engin::Impl::pop()
		{
			if(states.empty())
			{
				return false;
			}


			states.top()->clean();
			states.pop();

			if (!states.empty())
			{
				states.top()->init();
				states.top()->pause(false);
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
		void Engin::Impl::changeState(StatePtr state)
		{
			assert(state != nullptr);


			///Remove any existing states
			while (!states.empty())
				this->pop();

			///Push the state onto the now empty stack
			this->push(std::move(state));
		}


        /********************************************************************
        *   @brief  Implimentation for Engin::IsRunning which returns a
        *           boolean true value when the game is still running. See
        *           Engin::IsRunning
        ********************************************************************/
		bool Engin::Impl::isRunning() const
		{
			return _running;
		}


        /********************************************************************
        *   @brief  Implimentation for Engin::Quit. Once this methos runs
        *           Engin::IsRunning will return false.
        *           See Engin::Quit
        *           See Engin::IsRunning
        ********************************************************************/
		void Engin::Impl::quit()
		{
			_running = false;
		}


        /********************************************************************
        *   @brief  This method handles all types of input.
        *   @param  deltaTime is the time the previous frame took
        *           See Engin::HendleEvents
        ********************************************************************/
		void Engin::Impl::handleEvents(const float &deltaTime)
		{
			assert(!states.empty());

			///Call the current states HandleEvents method.
			states.top()->handleEvents(engin, deltaTime);
		}


        /********************************************************************
        *   @brief  This method executes per frame logic.
        *   @param  deltaTime is the time the previous frame took
        *           See Engin::Update
        ********************************************************************/
		void Engin::Impl::update(const float &deltaTime)
		{
			assert(!states.empty());

			///Call the current states Update method.
			states.top()->update(engin, deltaTime);
		}


        /********************************************************************
        *   @brief  This method draws the current frame.
        *   @param  deltaTime is the time the previous frame took
        *           See Engin::Draw
        ********************************************************************/
		void Engin::Impl::draw(const float &deltaTime)
		{
			assert(!states.empty());

			///Call the current states Draw method.
			states.top()->draw(engin, deltaTime);
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
        void Engin::push(StatePtr state)
        {
            assert(pimpl != nullptr);
			pimpl->push(std::move(state));
        }


        /*********************************************************************************//**
        *   @brief Remove a state from the stack
        *   @return boolean true when the state is successfully removed
        *           from the stack.
        *************************************************************************************/
        bool Engin::pop()
        {
            assert(pimpl != nullptr);
			return pimpl->pop();
        }


        /*********************************************************************************//**
        *   @brief 	Remove any existing GameState objects from the stack, and push
        *           A new GameState object onto the stack.
        *   @param	state a pointer to a GameState object.
        *************************************************************************************/
        void Engin::changeState(StatePtr state)
        {
            assert(pimpl != nullptr);
			pimpl->changeState(std::move(state));
        }


        /*********************************************************************************//**
        *   @brief	This method is used to determine if the game is still running.
        *	@return boolean true when the game is running and false otherwise
        *************************************************************************************/
        bool Engin::isRunning() const
        {
            assert(pimpl != nullptr);
			return pimpl->isRunning();
        }


        /*********************************************************************************//**
        *   @brief	This method is used to end the game.
        *
        *	@return	After calling this method IsRunning() returns false.
        *************************************************************************************/
        void Engin::quit()
        {
            assert(pimpl != nullptr);
			return pimpl->quit();
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
        void Engin::handleEvents(const float &deltaTime)
        {
            assert(pimpl != nullptr);
			pimpl->handleEvents(deltaTime);
        }


        /*********************************************************************************//**
        *   @brief	 This method is used to call an equivalent method in a GameState
        *            class. Which will have code for handling game logic.
        *   @param  deltaTime is the time the previous frame took
        *************************************************************************************/
        void Engin::update(const float &deltaTime)
        {
            assert(pimpl != nullptr);
			pimpl->update(deltaTime);
        }


        /*********************************************************************************//**
        *   @brief	Remove any existing GameState objects from the stack, and push
        *           A new GameState object onto the stack. The new state will be
        *           created internally the user specifies the type of state, and
        *           passes any arguments needed by the states constructor.
        *   @param  StatePtr a pointer to a GameState object.
        *   @param  deltaTime is the time the previous frame took
        *************************************************************************************/
        void Engin::draw(const float &deltaTime)
        {
            assert(pimpl != nullptr);
			pimpl->draw(deltaTime);
        }

        int Engin::size() const
        {
            assert(pimpl != nullptr);
            return pimpl->size();
        }

        /*********************************************************************************//**
        *   @brief	Destructor:
        *************************************************************************************/
        Engin::~Engin()
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
