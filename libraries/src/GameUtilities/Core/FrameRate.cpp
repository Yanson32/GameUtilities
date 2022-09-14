#include "GameUtilities/Core/FrameRate.h"
#include <iomanip>
#include <ctime>
#include <deque>

namespace GU
{
    namespace Core
    {
		class FrameRate::Impl
		{
			public:
                /******************************************************************//**
                *   @brief  Constructor
                *   @param  maxQueueSize the maximum size of the queue. The queue stores
                *           a time for each frame, which is then used to get the average
                *           time. 
                **********************************************************************/ 
				Impl(const std::size_t maxQueueSize = 0);
                

                /******************************************************************//**
                *   @brief  This method must be called once per frame. It adds the 
                *           execution time of the previous frame to the queue, and 
                *           also removes an entry if the number of entries is over 
                *           maxQueueSize.
                **********************************************************************/ 
				void update();
                

                /******************************************************************//**
                *   @brief  This method returns the average frame rate.
                *   @param  The average frame rate in seconds 
                **********************************************************************/ 
				double getFrameRate();
                

                /******************************************************************//**
                *   @brief  Destructor 
                **********************************************************************/ 
				~Impl();
			private:
				const std::size_t m_maxQueueSize;
				std::deque<unsigned int> m_timeQue;
				unsigned int m_prevTime = 0;
		};

        /******************************************************************//**
        *   @brief  Constructor
        *   @param  maxQueueSize the maximum size of the queue. The queue stores
        *           a time for each frame, which is then used to get the average
        *           time. 
        **********************************************************************/ 
		FrameRate::Impl::Impl(const std::size_t maxQueueSize): m_maxQueueSize(maxQueueSize)
		{
			m_prevTime = clock();
		}
        

        /******************************************************************//**
        *   @brief  This method must be called once per frame. It adds the 
        *           execution time of the previous frame to the queue, and 
        *           also removes an entry if the number of entries is over 
        *           maxQueueSize.
        **********************************************************************/ 
		void FrameRate::Impl::update()
		{
			//get the current time in milliseconds
			unsigned int currentTime = clock();

			//add the current time to the dequeue
			m_timeQue.push_front(currentTime - m_prevTime);

			//remove any time that is over maxQueueSize
			if (m_timeQue.size() >= m_maxQueueSize)
				m_timeQue.pop_back();

			//set previous time to current time
			m_prevTime = currentTime;
		}

        
        /******************************************************************//**
        *   @brief  This method returns the average frame rate.
        *   @param  The average frame rate in seconds 
        **********************************************************************/ 
		double FrameRate::Impl::getFrameRate()
		{
			//add all the time in the deque
			unsigned int totalTime = 0;
			for (auto element : m_timeQue)
				totalTime += element;

			//calculate the average time
			double averageTime = static_cast<double>(totalTime) / m_timeQue.size();

			//averageTime needs to be converted to milliseconds
			//then we divide 1 by the result witch gives the number of frames per second
			return 1 / (averageTime / 1000);
		}

        
        /******************************************************************//**
        *   @brief  Destructor 
        **********************************************************************/ 
		FrameRate::Impl::~Impl()
		{

		}
        

        /******************************************************************//**
        *   @brief  Constructor
        *   @param  maxQueueSize the maximum size of the queue. The queue stores
        *           a time for each frame, which is then used to get the average
        *           time. 
        **********************************************************************/ 
		FrameRate::FrameRate(const std::size_t maxQueueSize):
		pimpl(new FrameRate::Impl(maxQueueSize))
		{
			//ctor

		}


        /******************************************************************//**
        *   @brief  This method must be called once per frame. It adds the 
        *           execution time of the previous frame to the queue, and 
        *           also removes an entry if the number of entries is over 
        *           maxQueueSize.
        **********************************************************************/ 
		void FrameRate::update()
		{
			pimpl->update();
		}


        /******************************************************************//**
        *   @brief  This method returns the average frame rate.
        *   @param  The average frame rate in seconds 
        **********************************************************************/ 
		double FrameRate::getFrameRate()
		{
			return pimpl->getFrameRate();
		}


        /******************************************************************//**
        *   @brief  Destructor 
        **********************************************************************/ 
		FrameRate::~FrameRate()
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
