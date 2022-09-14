#ifndef QUADTREE_H
#define QUADTREE_H
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
#include <memory>
#include "GameUtilities/Data/PhysicsObject.h"
#include "GameUtilities/Data/Rectangle.h"
#include "GameUtilities/Data/AABB.h"
#include <vector>

namespace GU
{
    namespace Data 
    {
        class DATA_EXPORT QuadTree
        {
            public:
                /****************************************************************************************
                *   @brief      Constructor 
                *   @param      origin is the starting point of the QuadTree. 
                *   @param      width is the width of the QuadTree.
                *   @param      height is the height of the QuadTree.
                *   @param      currentLevel assignes an integer to each level of the QuadTree to limit
                *               how deep the QuadTree can go and avoid infinite QuadTrees.
                *   @param      maxObjects is the maximum number of objects any QuadTree can store 
                *               before splitting.
                *   @param      maxLevel is the maximum number of levels a QuadTree can have. A level
                *               being the number of nested QuadTrees.
                ****************************************************************************************/
                QuadTree(const Math::Vector2<float> &origin, 
                const float &width, 
                const float &height, 
                const int currentLevel, 
                const int &maxObjects = 5, 
                const int maxLevel = 5);
                

                /****************************************************************************************
                *   @brief      This method inserts a shared pointer to an object into the QuadTree. 
                *   @param      object is a pointer to a PhysicsObject. The QuadTree will store the object
                *               for collision detection later.  
                ****************************************************************************************/
                void insert(const std::shared_ptr<PhysicsObject> object);


                /****************************************************************************************
                *   @brief      This method determines if the AABB intersects the QuadTree. 
                *   @param      aabb will be checked for collision against the QuadTree.
                *   @return     True if collision is detected and false otherwise. 
                ****************************************************************************************/
                bool intersects(const AABB &aabb) const;
                

                /****************************************************************************************
                *   @brief      This method gathers any objects in the QuadTree that are colliding with
                *               the input AABB. 
                *   @param      aabb will be checked for collision against all objects in the QuadTree. 
                *   @return     A vector of objects that were determined to be colliding against the
                *               input AABB. 
                ****************************************************************************************/
                std::vector<std::shared_ptr<PhysicsObject>> query(const AABB &aabb) const;
                

                /****************************************************************************************
                *   @brief      This method gathers any objects in the QuadTree that are colliding with
                *               the input AABB. 
                *   @param      aabb will be checked for collision against all objects in the QuadTree. 
                *   @return     A vector of objects that were determined to be colliding against the
                *               input AABB. 
                ****************************************************************************************/
                std::vector<GU::Data::AABB> getAllBounds() const;
                
    
                /****************************************************************************************
                *   @brief      Destructor 
                ****************************************************************************************/
                virtual ~QuadTree();
            private:
                /****************************************************************************************
                *   @brief      This method will split the current QuadTree into 4 QuadTrees. 
                ****************************************************************************************/
                void split();
                
                
                /****************************************************************************************
                *   @brief      This method creates QuadTree from the current QuadTree but the bounds of 
                *               new QuadTree will be equivalent to the top left quadrant of the current
                *               QuadTree.
                *   @return     A shared pointer to the new QuadTree. 
                ****************************************************************************************/
                std::shared_ptr<QuadTree> getTopLeftQuadrant() const;
                

                /****************************************************************************************
                *   @brief      This method creates QuadTree from the current QuadTree but the bounds of 
                *               new QuadTree will be equivalent to the top right quadrant of the current
                *               QuadTree.
                *   @return     A shared pointer to the new QuadTree. 
                ****************************************************************************************/
                std::shared_ptr<QuadTree> getTopRightQuadrant() const;
                

                /****************************************************************************************
                *   @brief      This method creates QuadTree from the current QuadTree but the bounds of 
                *               new QuadTree will be equivalent to the bottom left quadrant of the current
                *               QuadTree.
                *   @return     A shared pointer to the new QuadTree. 
                ****************************************************************************************/
                std::shared_ptr<QuadTree> getBottomLeftQuadrant() const;
                

                /****************************************************************************************
                *   @brief      This method creates QuadTree from the current QuadTree but the bounds of 
                *               new QuadTree will be equivalent to the bottom right quadrant of the current
                *               QuadTree.
                *   @return     A shared pointer to the new QuadTree. 
                ****************************************************************************************/
                std::shared_ptr<QuadTree> getBottomRightQuadrant() const;
            protected: 
                std::vector<std::shared_ptr<QuadTree>> m_quadrants;
                std::vector<std::shared_ptr<PhysicsObject>> m_data;
                GU::Data::AABB m_bounds;
                const int m_max;
                const int m_maxLevel;
                const int m_currentLevel;
        };
    }
}
#endif
