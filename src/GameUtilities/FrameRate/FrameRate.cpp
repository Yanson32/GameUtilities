/*!
*	\author Wayne J Larson Jr.
*	\version 1.0
*	\date 12/10/17
*/

#include "GameUtilities/FrameRate/FrameRate.h"
#include <iomanip>
#include <ctime>
#include <deque>

namespace GU
{
    namespace FR
    {
		class FrameRate::Impl
		{
			public:
				Impl(const std::size_t newMaxQueueSize = 0);
				void update();
				double getFrameRate();
				~Impl();
			private:
				const std::size_t maxQueueSize;
				std::deque<unsigned int> timeQue;
				unsigned int prevTime = 0;
		};

		FrameRate::Impl::Impl(const std::size_t newMaxQueueSize): maxQueueSize(newMaxQueueSize)
		{
			prevTime = clock();
		}
		void FrameRate::Impl::update()
		{
			//get the current time in milliseconds
			unsigned int currentTime = clock();

			//add the current time to the dequeue
			timeQue.push_front(currentTime - prevTime);

			//remove any time that is over maxQueueSize
			if (timeQue.size() >= maxQueueSize)
				timeQue.pop_back();

			//set previous time to current time
			prevTime = currentTime;
		}

		double FrameRate::Impl::getFrameRate()
		{
			//add all the time in the deque
			unsigned int totalTime = 0;
			for (auto element : timeQue)
				totalTime += element;

			//calculate the average time
			double averageTime = static_cast<double>(totalTime) / timeQue.size();

			//averageTime needs to be converted to milliseconds
			//then we divide 1 by the result witch gives the number of frames per second
			return 1 / (averageTime / 1000);
		}

		FrameRate::Impl::~Impl()
		{

		}
    FrameRate::FrameRate(const std::size_t newMaxQueueSize): 
	pimpl(new FrameRate::Impl(newMaxQueueSize))
    {
        //ctor
        
    }


    void FrameRate::update()
    {
		pimpl->update();
    }


    //calculate the number of frames per seconds
    double FrameRate::getFrameRate()
    {
		return pimpl->getFrameRate();
    }


    FrameRate::~FrameRate()
    {
        //dtor
    }

    }

}
