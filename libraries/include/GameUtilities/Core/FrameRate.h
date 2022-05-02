#ifndef GAMEUTILITIES_FRAMERATE_H
#define GAMEUTILITIES_FRAMERATE_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*   @date 12/10/2017
*   @description This class allows us to track the frame rate of a game.
*************************************************************************************/
#include "core_export.h"
#include <cstddef> //std::size_t

namespace GU
{

    namespace Core
    {

        class CORE_EXPORT FrameRate final
        {
            public:
                /******************************************************************//**
                *   @brief  Constructor
                *   @param  maxQueueSize the maximum size of the queue. The queue stores
                *           a time for each frame, which is then used to get the average
                *           time. 
                **********************************************************************/ 
                FrameRate(const std::size_t maxQueueSize = 60);
                

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
                ~FrameRate();
            private:
                
                /******************************************************************//**
                *   @brief  Deleted copy constructor 
                *   @param  The FrameRate class to be copied  
                **********************************************************************/ 
                FrameRate(const FrameRate&) = delete;
                

                /******************************************************************//**
                *   @brief  Deleted assignment operator 
                *   @param  The FrameRate class to be assigned 
                **********************************************************************/ 
                FrameRate& operator = (const FrameRate&) = delete;
			
            	class Impl;
				Impl* pimpl = nullptr;
        };
    }
}
#endif // FRAMERATE_H
