#ifndef GU_DATA_RGBA_H
#define GU_DATA_RGBA_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*	@date 	4/1/2022
*   @file   RGBA.h
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

#include "data_export.h"

namespace GU
{
    namespace Data
    {
        /*********************************************************************************//**
        *	@class RGBA
        *	@brief This class represents a color with a red, green, blue, and alpha channel.  
        *************************************************************************************/
        class DATA_EXPORT RGBA
        {
            unsigned red;       /**< The amount of red in the color */
            unsigned blue;      /**< The amount of blue in the color */
            unsigned green;     /**< The amount of green in the color */
            unsigned alpha;     /**< The amount of alpha in the color */
        };
    }
}

#endif // GU_RGBA_H
