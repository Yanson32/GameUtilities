/*********************************************************************************//**
*	@author  Wayne J Larson Jr.
*   @date    09/16/2022
*   @file    Resource.cpp
*************************************************************************************/

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
#include "GameUtilities/Core/Resource.h"

namespace GU
{

    namespace Core
    {

        /*********************************************************************************//**
        *	@brief  Constructor
        *   @param  id is a unique identifier for the resource. 
        *************************************************************************************/
        Resource::Resource(const int &type):
        m_type(type)
        {

        }

        
        /*********************************************************************************//**
        *	@brief  Destructor 
        *************************************************************************************/
        Resource::~Resource()
        {

        }
    }
}
