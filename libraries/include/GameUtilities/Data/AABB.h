#ifndef AABB_H
#define AABB_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       13/09/22
*   Purpose:    This class represents a axis aligned bounding box. 
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
#include "Math/Vector2.h"

namespace GU
{
    namespace Data
    {
        class Rectangle;
        class DATA_EXPORT AABB 
        {
            public:
                /****************************************************************************************
                *   @brief      Constructor.
                *   @param      origin the starting point of the AABB.
                *   @param      width the width of the AABB.
                *   @param      height the height of the AABB.
                ****************************************************************************************/
                AABB(const Math::Vector2<float> &origin, const int &width, const int &height);
                

                /****************************************************************************************
                *   @brief      This method checks to see if the current bounding box and the input 
                *               bounding box are overlapping. 
                *   @return     True if the two bounding boxes are overlapping and false otherwise. 
                ****************************************************************************************/
                bool intersects(const AABB &aabb) const;
                

                /****************************************************************************************
                *   @breif      This method converts the bounding box to a Rectangle. 
                *   @return     A Rectangle object equivalent to the  current bounding box. 
                ****************************************************************************************/
                GU::Data::Rectangle asRectangle() const;
                

                /****************************************************************************************
                *   @brief  Destructor. 
                ****************************************************************************************/
                virtual ~AABB();
            public:
                Math::Vector2<float> m_origin;
                int m_width;
                int m_height;
        };
    }
}
#endif
