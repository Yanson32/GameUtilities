#ifndef RECTANGLE_H
#define RECTANGLE_H
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

namespace GU
{
    namespace Data
    {
        class AABB;
        class DATA_EXPORT Rectangle
        {
            public:
                /****************************************************************************************
                *   @purpose    Constructor.
                *   @param      origin the starting point of the rectangle.
                *   @param      width the width of the rectangle.
                *   @param      height the height of the rectangle.
                *   @param      angle is the angle of the rectangle. 
                ****************************************************************************************/
                Rectangle(const Math::Vector2<float> &origin, const float &width, const float &height, const float &angle = 0);
                

                /****************************************************************************************
                *   @purpose    This method checks if the two rectangles are overlapping. 
                *   @param      rectangle is checked to determine if the two rectangles are intersecting.
                *   @return     True if the two rectangles are intersecting and false otherwise. 
                ****************************************************************************************/
                bool intersects(const Rectangle &rectangle) const;
                

                /****************************************************************************************
                *   @purpose    This method checks if the rectangle overlaps a bounding box. 
                *   @param      aabb is checked to determine if it is overlapping the rectangle.  
                *   @return     True if the rectangle and AABB  are intersecting and false otherwise. 
                ****************************************************************************************/
                bool intersects(const AABB &aabb) const;
                

                /****************************************************************************************
                *   @purpose    Destructor 
                ****************************************************************************************/
                virtual ~Rectangle();
            public:
                Math::Vector2<float> m_origin;
                float m_width = 0;
                float m_height = 0;
                float m_angle = 0;
        };
    }
}
#endif
