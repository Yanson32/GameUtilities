#ifndef PHYSICS_OBJECT_H
#define PHYSICS_OBJECT_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       13/09/22
*   Purpose:    This class represents a rectangle 
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

#include "data_export.h"
#include <Math/Vector2.h>
#include "GameUtilities/Data/AABB.h"
namespace GU
{
    namespace Data
    {
        class DATA_EXPORT PhysicsObject 
        {
            public:
                /****************************************************************************************
                *   @brief      This method returns a axis aligned bounding box for the object. 
                *   @param      A axis aligned bounding box. 
                ****************************************************************************************/
                virtual AABB getBounds() const = 0; 
        };
    }
}
#endif