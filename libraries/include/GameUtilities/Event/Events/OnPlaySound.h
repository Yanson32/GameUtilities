#ifndef GAMEUTILITIES_ONPLAYSOUND_H
#define GAMEUTILITIES_ONPLAYSOUND_H
/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   5/08/22
*   @file   OnPlaySound.h
**************************************************************************/

/*************************************************************************
*                           COPYRIGHT NOTICE
* GameUtilities is a toolkit for making 2d video games.
* Copyright (C) 2018 Wayne J Larson Jr. 
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 3 as 
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
***************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

        /**********************************************************************//**
        *   @class  OnPlaySound
        *   @brief  This class is a subclass of the event class. This event
        *           is generated to indicate that a sound should be played. 
        **************************************************************************/
		class EVENT_EXPORT OnPlaySound: public Event
		{
			public:
                /**********************************************************************//**
                *   @brief  Constructor
                *   @param  soundId is the unique identifier for the sound.
                *   @param  line is the line number where the event originated from
                *   @param  file is the file where the event originated from
                **************************************************************************/
				OnPlaySound(const int &soundId, const int &line = 0, const char* file= "");
                
                
                /**********************************************************************//**
                *   @brief  Destructor 
                **************************************************************************/
				virtual ~OnPlaySound();
            public:
				int m_soundId;      /**< Is a unique identifier for the sound. */
		};
	}
}

#endif // PLAYSOUND_H
