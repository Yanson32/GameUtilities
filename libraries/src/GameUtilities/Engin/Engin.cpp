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

                Impl();

                virtual ~Impl();

				//stack of states the state on the top of the stack is the current state
				std::stack<StatePtr> m_states;

				//true while the game is running and false otherwise
				bool m_running = true;
		};


        Engin::Impl::Impl()
        {

        }

        Engin::Impl::~Impl()
        {

        }


        /*********************************************************************************//**
        *   @brief	Default constructor
        *************************************************************************************/
        Engin::Engin(): m_pimpl(new Engin::Impl())
        {
            //ctor
            assert(m_pimpl != nullptr);
        }



        Engin::Engin(Engin&& param)
        {
            if(m_pimpl)
                delete m_pimpl;

            m_pimpl = param.m_pimpl;
            param.m_pimpl = nullptr;
        }


        Engin& Engin::operator=(Engin&& param)
        {
            assert(m_pimpl != nullptr);
            assert(param.m_pimpl != nullptr);
            m_pimpl = param.m_pimpl;

			return *this;
        }

        
        /*********************************************************************************//**
        *	@brief	Push a new state onto the stack.
        *   @param	state a pointer to a GameState object.
        *************************************************************************************/
        void Engin::push(StatePtr state, std::shared_ptr<Frame> frame)
        {
            assert(m_pimpl != nullptr);

			if (!m_pimpl->m_states.empty())
			{
				m_pimpl->m_states.top()->pause();
				m_pimpl->m_states.top()->clean(frame);
			}

			m_pimpl->m_states.push(std::move(state));
			m_pimpl->m_states.top()->init(frame);
        }


        /*********************************************************************************//**
        *   @brief Remove a state from the stack
        *   @return boolean true when the state is successfully removed
        *           from the stack.
        *************************************************************************************/
        bool Engin::pop(std::shared_ptr<Frame> frame)
        {
            assert(m_pimpl != nullptr);
			
            if(m_pimpl->m_states.empty())
			{
				return false;
			}


			m_pimpl->m_states.top()->clean(frame);
			m_pimpl->m_states.pop();

			if (!m_pimpl->m_states.empty())
			{
				m_pimpl->m_states.top()->init(frame);
				m_pimpl->m_states.top()->pause(false);
			}

			return true;
        }


        /*********************************************************************************//**
        *   @brief 	Remove any existing GameState objects from the stack, and push
        *           A new GameState object onto the stack.
        *   @param	state a pointer to a GameState object.
        *************************************************************************************/
        void Engin::changeState(StatePtr state, std::shared_ptr<Frame> frame)
        {
			assert(state != nullptr);

			///Remove any existing states
			while (!m_pimpl->m_states.empty())
				this->pop(frame);

			///Push the state onto the now empty stack
			this->push(std::move(state), frame);
        }


        /*********************************************************************************//**
        *   @brief	This method is used to determine if the game is still running.
        *	@return boolean true when the game is running and false otherwise
        *************************************************************************************/
        bool Engin::isRunning() const
        {
            assert(m_pimpl != nullptr);
			return m_pimpl->m_running;
        }


        /*********************************************************************************//**
        *   @brief	This method is used to end the game.
        *
        *	@return	After calling this method IsRunning() returns false.
        *************************************************************************************/
        void Engin::quit()
        {
            assert(m_pimpl != nullptr);
			m_pimpl->m_running = false;
        }

        bool Engin::empty() const
        {
            assert(m_pimpl != nullptr);
            return m_pimpl->m_states.empty();
        }


        /*********************************************************************************//**
        *   @brief	This method is used to call an equivalent method in a GameState
        *           class. Which will have code for handling all kinds of input
        *           include events and user input.
        *   @param  deltaTime is the time the previous frame took
        *************************************************************************************/
        void Engin::handleEvents(const float &deltaTime, std::shared_ptr<Frame> frame)
        {
            assert(m_pimpl != nullptr);
			assert(!m_pimpl->m_states.empty());

			///Call the current states HandleEvents method.
			m_pimpl->m_states.top()->handleEvents(*this, deltaTime, frame);
        }


        /*********************************************************************************//**
        *   @brief	 This method is used to call an equivalent method in a GameState
        *            class. Which will have code for handling game logic.
        *   @param  deltaTime is the time the previous frame took
        *************************************************************************************/
        void Engin::update(const float &deltaTime, std::shared_ptr<Frame> frame)
        {
            assert(m_pimpl != nullptr);
			assert(!m_pimpl->m_states.empty());

			///Call the current states Update method.
			m_pimpl->m_states.top()->update(*this, deltaTime, frame);
        }


        /*********************************************************************************//**
        *   @brief	Remove any existing GameState objects from the stack, and push
        *           A new GameState object onto the stack. The new state will be
        *           created internally the user specifies the type of state, and
        *           passes any arguments needed by the states constructor.
        *   @param  StatePtr a pointer to a GameState object.
        *   @param  deltaTime is the time the previous frame took
        *************************************************************************************/
        void Engin::draw(const float &deltaTime, std::shared_ptr<Frame> frame)
        {
            assert(m_pimpl != nullptr);
			assert(!m_pimpl->m_states.empty());

			///Call the current states Draw method.
			m_pimpl->m_states.top()->draw(*this, deltaTime, frame);
        }


        int Engin::size() const
        {
            assert(m_pimpl != nullptr);
            return m_pimpl->m_states.size();
        }


        /*********************************************************************************//**
        *   @brief	Destructor:
        *************************************************************************************/
        Engin::~Engin()
        {
            //dtor
            if(m_pimpl != nullptr)
            {
                delete m_pimpl;
                m_pimpl = nullptr;
            }
        }
    }

}
