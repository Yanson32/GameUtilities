/*!
*	\author Wayne J Larson Jr.
*	\version 1.0
*	\date 12/10/17
*/

#include "GameUtilities/FrameRate/FrameRate.h"
#include <iomanip>
#include <ctime>

namespace GU
{
    namespace FR
    {

    FrameRate::FrameRate(const std::size_t newMaxQueueSize): maxQueueSize(newMaxQueueSize)
    {
        //ctor
        prevTime = clock();
    }


    void FrameRate::update()
    {
        //get the current time in milliseconds
        unsigned int currentTime = clock();

        //add the current time to the dequeue
        timeQue.push_front(currentTime - prevTime);

        //remove any time that is over maxQueueSize
        if(timeQue.size() >= maxQueueSize)
            timeQue.pop_back();

        //set previous time to current time
        prevTime = currentTime;
    }


    //calculate the number of frames per seconds
    double FrameRate::getFrameRate()
    {
        //add all the time in the deque
        unsigned int totalTime = 0;
        for(auto element: timeQue)
            totalTime += element;

        //calculate the average time
        double averageTime = static_cast<double>(totalTime) / timeQue.size();

        //averageTime needs to be converted to milliseconds
        //then we divide 1 by the result witch gives the number of frames per second
        return 1 / (averageTime / 1000);
    }


    FrameRate::~FrameRate()
    {
        //dtor
    }

    }

}
