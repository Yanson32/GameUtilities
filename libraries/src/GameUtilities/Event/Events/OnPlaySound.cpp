/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   5/08/22
*   @file   OnPlaySound.cpp
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
#include "GameUtilities/Event/Events/OnPlaySound.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {
        /**********************************************************************//**
        *   @brief  Constructor
        *   @param  soundId is the unique identifier for the sound.
        *   @param  line is the line number where the event originated from
        *   @param  file is the file where the event originated from
        **************************************************************************/
		OnPlaySound::OnPlaySound(const int &soundId, const int &line, const char* file):
		Event(static_cast<int>(GU::Evt::EventId::PLAY_SOUND), line, file), m_soundId(soundId)
		{
			//ctor
		}

        
        /**********************************************************************//**
        *   @brief  Destructor 
        **************************************************************************/
		OnPlaySound::~OnPlaySound()
		{
			//dtor
		}
	}
}
