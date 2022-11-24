/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   5/11/22
*   @file   OnPlayMusic.cpp
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
#include "GameUtilities/Event/Events/OnPlayMusic.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {
        /**********************************************************************//**
        *   @brief  Constructor.
        *   @param  musicFile is the music to be played.   
        *   @param  line is the line in code where the event was generated.
        *   @param  file is the file were the event was generated.
        **************************************************************************/
		OnPlayMusic::OnPlayMusic(const char* musicFile, const int &line, const char* file):
		Event(static_cast<int>(GU::Evt::EventId::PLAY_MUSIC), line, file),
		m_musicFile(musicFile)
		{
			//ctor
		}

        

        /**********************************************************************//**
        *   @brief  Destructor.
        **************************************************************************/
		OnPlayMusic::~OnPlayMusic()
		{
			//dtor
		}
	}
}
