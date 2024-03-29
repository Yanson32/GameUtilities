/********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   10/18/22
*   @file   WindowBase.cpp
************************************************************************/

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
#include "GameUtilities/Window/WindowBase.h"
#include "GameUtilities/Core/Macros.h"
#include <iostream>

namespace GU
{
    namespace Win
    {
        
        /********************************************************************//**
        *   @brief  Constructor. 
        *   @param  size is the size of the window. 
        ************************************************************************/
        WindowBase::WindowBase(const Math::Vector2<float> &size)
        {
            UNUSED(size);
        }
        

        /********************************************************************//**
        *   @brief  Destructor. 
        ************************************************************************/
        WindowBase::~WindowBase()
        {

        }
    }
}
