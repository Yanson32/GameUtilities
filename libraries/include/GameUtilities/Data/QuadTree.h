#ifndef QUADTREE_H
#define QUADTREE_H
/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   13/09/22
*   @file   QuadTree.h
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
#include <memory>
#include "GameUtilities/Data/PhysicsObject.h"
#include "GameUtilities/Data/Rectangle.h"
#include "GameUtilities/Data/AABB.h"
#include <vector>
#include <cstddef>
namespace GU
{
    namespace Data 
    {
        /**********************************************************************//**
        *   @class  QuadTree
        *   @brief  This class represents a axis aligned bounding box. 
        **************************************************************************/
        class DATA_EXPORT QuadTree
        {
            public:
                /************************************************************************************//**
                *   @brief      Constructor 
                *   @param      origin is the starting point of the QuadTree. 
                *   @param      width is the width of the QuadTree.
                *   @param      height is the height of the QuadTree.
                *   @param      currentSplit this number should be incremented every time the QuadTree 
                *               splits. 
                *   @param      maxSplit is the maximum number of times the QuadTree can split. 
                *   @param      maxObjects is the maximum number of objects any QuadTree can store 
                *               before splitting.
                ****************************************************************************************/
                QuadTree(const Math::Vector2<float> &origin, 
                const float &width, 
                const float &height, 
                const int currentLevel, 
                const int maxLevel = 5,
                const int &maxObjects = 5);
                

                /************************************************************************************//**
                *   @brief      This method inserts a shared pointer to an object into the QuadTree. 
                *   @param      object is a pointer to a PhysicsObject. The QuadTree will store the object
                *               for collision detection later.  
                ****************************************************************************************/
                void insert(const std::shared_ptr<PhysicsObject> object);


                /*************************************************************************************//**
                *   @brief      This method determines if the AABB intersects the QuadTree. 
                *   @param      aabb will be checked for collision against the QuadTree.
                *   @return     True if collision is detected and false otherwise. 
                ****************************************************************************************/
                bool intersects(const AABB &aabb) const;
                

                /************************************************************************************//**
                *   @brief      This method gathers any objects in the QuadTree that are colliding with
                *               the input AABB. 
                *   @param      aabb will be checked for collision against all objects in the QuadTree. 
                *   @return     A vector of objects that were determined to be colliding against the
                *               input AABB. 
                ****************************************************************************************/
                std::vector<std::shared_ptr<PhysicsObject>> query(const AABB &aabb) const;
                

                /************************************************************************************//**
                *   @brief      This method gathers any objects in the QuadTree that are colliding with
                *               the input AABB. 
                *   @param      aabb will be checked for collision against all objects in the QuadTree. 
                *   @return     A vector of objects that were determined to be colliding against the
                *               input AABB. 
                ****************************************************************************************/
                std::vector<GU::Data::AABB> getAllBounds() const;
                
    
                /************************************************************************************//**
                *   @brief      Destructor 
                ****************************************************************************************/
                virtual ~QuadTree();
            private:
                /************************************************************************************//**
                *   @brief      This method will split the current QuadTree into 4 QuadTrees. 
                ****************************************************************************************/
                void split();
                
                
                /************************************************************************************//**
                *   @brief      This method creates QuadTree from the current QuadTree but the bounds of 
                *               new QuadTree will be equivalent to the top left quadrant of the current
                *               QuadTree.
                *   @return     A shared pointer to the new QuadTree. 
                ****************************************************************************************/
                std::shared_ptr<QuadTree> getTopLeftQuadrant() const;
                

                /************************************************************************************//**
                *   @brief      This method creates QuadTree from the current QuadTree but the bounds of 
                *               new QuadTree will be equivalent to the top right quadrant of the current
                *               QuadTree.
                *   @return     A shared pointer to the new QuadTree. 
                ****************************************************************************************/
                std::shared_ptr<QuadTree> getTopRightQuadrant() const;
                

                /************************************************************************************//**
                *   @brief      This method creates QuadTree from the current QuadTree but the bounds of 
                *               new QuadTree will be equivalent to the bottom left quadrant of the current
                *               QuadTree.
                *   @return     A shared pointer to the new QuadTree. 
                ****************************************************************************************/
                std::shared_ptr<QuadTree> getBottomLeftQuadrant() const;
                

                /************************************************************************************//**
                *   @brief      This method creates QuadTree from the current QuadTree but the bounds of 
                *               new QuadTree will be equivalent to the bottom right quadrant of the current
                *               QuadTree.
                *   @return     A shared pointer to the new QuadTree. 
                ****************************************************************************************/
                std::shared_ptr<QuadTree> getBottomRightQuadrant() const;
            protected: 
                /// Vector of QuadTree objects one for each quadrant (top, left, right, bottom)
                std::vector<std::shared_ptr<QuadTree>> m_quadrants;

                /// Vector of pointers to PhysicsObject these objects will be used to check for collision.
                std::vector<std::shared_ptr<PhysicsObject>> m_data;

                /// The bounding box for the current QuadTree object
                GU::Data::AABB m_bounds;

                /// The number of times the QuadTree has split into quadtrants. 
                const int m_currentSplit;
               
                /// The maximum number of times the QuadTree can split into quadrants.
                const int m_maxSplit;
                
                /// The maximum number of objects a QuadTree can hold before splitting into quadrants.
                const std::size_t m_maxObjects;
        };
    }
}
#endif
