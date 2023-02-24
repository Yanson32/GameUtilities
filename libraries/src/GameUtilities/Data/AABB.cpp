/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   13/09/22
*   @file   AABB.cpp
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
#include "GameUtilities/Data/AABB.h"
#include "GameUtilities/Data/Rectangle.h"

namespace GU
{
    namespace Data
    {

        /************************************************************************************//**
        *   @brief Constructor.
        *   @param origin the starting point of the AABB.
        *   @param width the width of the AABB.
        *   @param height the height of the AABB.
        ****************************************************************************************/
        AABB::AABB(const Math::Vector2<float> &origin, const int &width, const int &height):
        m_origin(origin),
        m_width(width),
        m_height(height)
        {

        }


        /************************************************************************************//**
        *   @brief  This method checks to see if the current bounding box and the input 
        *           bounding box are overlapping. 
        *   @param  aabb is a bounding box to check for collision against.
        *   @return True if the two bounding boxes are overlapping and false otherwise. 
        ****************************************************************************************/
        bool AABB::intersects(const AABB &aabb) const
        {
            int halfWidth = m_width / 2.0;
            int halfHeight = m_height / 2.0;

            //If this aabb is to the left of the input aabb
            if((m_origin.x + halfWidth) < (aabb.m_origin.x - (aabb.m_width / 2.0)))
                return false;

            //If this aabb is to the right of the input aabb
            if((m_origin.x - halfWidth) > (aabb.m_origin.x + (aabb.m_width / 2.0)))
                return false;

            //If this aabb is above the input aabb
            if((m_origin.y + halfHeight) < (aabb.m_origin.y - (aabb.m_height / 2.0)))
                return false;

            //If this aabb is below the input aabb
            if((m_origin.y - halfHeight) > (aabb.m_origin.y + (aabb.m_height / 2.0)))
                return false;

            return true;
        }


        /************************************************************************************//**
        *   @brief  This method converts the bounding box to a Rectangle. 
        *   @return A Rectangle object equivalent to the  current bounding box. 
        ****************************************************************************************/
        GU::Data::Rectangle AABB::asRectangle() const
        {
            float halfWidth = m_width / 2.0;
            float halfHeight = m_height / 2.0; 
            Math::Vector2<float> origin(m_origin.x - halfWidth, m_origin.y - halfHeight);
            return GU::Data::Rectangle(origin, m_width, m_height);
        }
        
    
        /************************************************************************************//**
        *   @brief  Destructor. 
        ****************************************************************************************/
        AABB::~AABB()
        {

        }
    }
}
