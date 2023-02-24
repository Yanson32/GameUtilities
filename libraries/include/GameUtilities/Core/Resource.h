#ifndef GAMEUTILITIES_RESOURCE_H
#define GAMEUTILITIES_RESOURCE_H
/*********************************************************************************//**
*	@author  Wayne J Larson Jr.
*   @date    09/16/2022
*   @file    Resource.h
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
#include "core_export.h"
#include <cstring>
#include "GameUtilities/Core/String.h"
#include <memory>

namespace GU
{

    namespace Core
    {

        /*********************************************************************************//**
        *   @class   Resource
        *   @brief   This class is the base class for all resources 
        *************************************************************************************/
        class CORE_EXPORT Resource
        {
            public:
                /*********************************************************************************//**
                *   @brief  Constructor
                *   @param  type is a unique identifier for the resource. 
                *************************************************************************************/
                Resource(const int &type);
                
                
                /*********************************************************************************//**
                *   @brief  This method loads a resource from memory. 
                *   @param  data is a pointer to the resource data.
                *   @param  size is the amount of data.
                *************************************************************************************/
                virtual void load(const std::shared_ptr<void> data, const std::size_t &size) = 0;
                

                /*********************************************************************************//**
                *   @brief  This method loads a resource from disk. 
                *   @param  file is the full path to the resource on disk.
                *************************************************************************************/
                virtual void load(const GU::Core::String &file) = 0;


                /*********************************************************************************//**
                *   @brief  Destructor 
                *************************************************************************************/
                virtual ~Resource();
            private:
                const int m_type;
        };
    }
} 

#endif
