/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   13/09/22
*   @file   QuadTree.cpp
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
#include "GameUtilities/Data/QuadTree.h"
#include <cassert>

namespace GU
{
    namespace Data
    {
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
        QuadTree::QuadTree(const Math::Vector2<float> &origin, 
        const float &width, 
        const float &height, 
        const int currentSplit,
        const int maxSplit, 
        const int &maxObjects):
        m_bounds(origin, width, height),
        m_currentSplit(currentSplit),
        m_maxSplit(maxSplit),
        m_maxObjects(maxObjects)
        {

        }


        /************************************************************************************//**
        *   @brief      This method inserts a shared pointer to an object into the QuadTree. 
        *   @param      object is a pointer to a PhysicsObject. The QuadTree will store the object
        *               for collision detection later.  
        ****************************************************************************************/
        void QuadTree::insert(const std::shared_ptr<PhysicsObject> object)
        {
            assert(object != nullptr);
            if(m_bounds.intersects(object->getBounds()))
            {
                if(m_quadrants.empty())
                {
                    m_data.push_back(object);
                    split();
                }
                else
                {
                    for(auto &element: m_quadrants)
                    {
                        assert(element != nullptr);
                        element->insert(object); 
                    }
                }
            }
        }

        
        /************************************************************************************//**
        *   @brief      This method determines if the AABB intersects the QuadTree. 
        *   @param      aabb will be checked for collision against the QuadTree.
        *   @return     True if collision is detected and false otherwise. 
        ****************************************************************************************/
        bool QuadTree::intersects(const AABB &aabb) const
        {
            
            return m_bounds.intersects(aabb);
        }
        

        /************************************************************************************//**
        *   @brief      This method gathers any objects in the QuadTree that are colliding with
        *               the input AABB. 
        *   @param      aabb will be checked for collision against all objects in the QuadTree. 
        *   @return     A vector of objects that were determined to be colliding against the
        *               input AABB. 
        ****************************************************************************************/
        std::vector<std::shared_ptr<PhysicsObject>> QuadTree::query(const GU::Data::AABB &aabb) const
        {
            std::vector<std::shared_ptr<PhysicsObject>> data;
            if(m_bounds.intersects(aabb))
            {
                if(m_quadrants.empty())
                {
                    for(std::size_t i = 0; i < m_data.size(); ++i)
                    {
                        if(m_data[i]->getBounds().intersects(aabb))    
                            data.insert(data.end(), m_data[i]);
                    }
                } 
                else 
                {
                    for(auto &element: m_quadrants)
                    {
                        std::vector<std::shared_ptr<PhysicsObject>> results = element->query(aabb);
                        data.insert(data.end(), results.begin(), results.end());
                    }
                }
            }
            
            return data; 
        }

        
        /************************************************************************************//**
        *   @brief      This method gathers any objects in the QuadTree that are colliding with
        *               the input AABB. 
        *   @param      aabb will be checked for collision against all objects in the QuadTree. 
        *   @return     A vector of objects that were determined to be colliding against the
        *               input AABB. 
        ****************************************************************************************/
        std::vector<GU::Data::AABB> QuadTree::getAllBounds() const
        {
            std::vector<AABB> bounds;
            bounds.push_back(m_bounds);

            for(auto &element : m_quadrants)
            {
                std::vector<AABB> temp = element->getAllBounds(); 
                bounds.insert(bounds.end(), temp.begin(), temp.end());
                
            }
            return bounds;
        }

        
        /************************************************************************************//**
        *   @brief      This method will split the current QuadTree into 4 QuadTrees. 
        ****************************************************************************************/
        void QuadTree::split()
        {
            if(m_data.size() >= m_maxObjects) 
            {
                if(m_currentSplit < m_maxSplit)
                {
                    m_quadrants.push_back(getTopLeftQuadrant());
                    m_quadrants.push_back(getTopRightQuadrant());
                    m_quadrants.push_back(getBottomLeftQuadrant());
                    m_quadrants.push_back(getBottomRightQuadrant());
                   
                    while(!m_data.empty()) 
                    {
                        for(std::size_t i = 0; i < m_quadrants.size(); ++i)
                        {
                           if(m_quadrants[i]->intersects(m_data.back()->getBounds()))
                                m_quadrants[i]->insert(m_data.back());
                            
                        }              
                        
                        m_data.pop_back(); 
                    }
                }
            }
        }

    
        /************************************************************************************//**
        *   @brief      This method creates QuadTree from the current QuadTree but the bounds of 
        *               new QuadTree will be equivalent to the top left quadrant of the current
        *               QuadTree.
        *   @return     A shared pointer to the new QuadTree. 
        ****************************************************************************************/
        std::shared_ptr<QuadTree> QuadTree::getTopLeftQuadrant() const
        {
            float width = m_bounds.m_width / 2.0;
            float height = m_bounds.m_height / 2.0;
            float halfWidth = width / 2.0;
            float halfHeight = height / 2.0;
            Math::Vector2<float> origin({m_bounds.m_origin.x - halfWidth, m_bounds.m_origin.y - halfHeight});
            return std::shared_ptr<QuadTree>(new QuadTree(origin, width, height, m_currentSplit + 1, m_maxObjects, m_maxSplit));
        }


        /************************************************************************************//**
        *   @brief      This method creates QuadTree from the current QuadTree but the bounds of 
        *               new QuadTree will be equivalent to the top right quadrant of the current
        *               QuadTree.
        *   @return     A shared pointer to the new QuadTree. 
        ****************************************************************************************/
        std::shared_ptr<QuadTree> QuadTree::getTopRightQuadrant() const
        {
            float width = m_bounds.m_width / 2.0;
            float height = m_bounds.m_height / 2.0;
            float halfWidth = width / 2.0;
            float halfHeight = height / 2.0;
            Math::Vector2<float> origin(m_bounds.m_origin.x + halfWidth, m_bounds.m_origin.y - halfHeight);
            return std::unique_ptr<QuadTree>(new QuadTree(origin, width, height, m_currentSplit + 1, m_maxObjects, m_maxSplit));
        }


        /************************************************************************************//**
        *   @brief      This method creates QuadTree from the current QuadTree but the bounds of 
        *               new QuadTree will be equivalent to the bottom left quadrant of the current
        *               QuadTree.
        *   @return     A shared pointer to the new QuadTree. 
        ****************************************************************************************/
        std::shared_ptr<QuadTree> QuadTree::getBottomLeftQuadrant() const
        {
            float width = m_bounds.m_width / 2.0;
            float height = m_bounds.m_height / 2.0;
            float halfWidth = width / 2.0;
            float halfHeight = height / 2.0;
            Math::Vector2<float> origin(m_bounds.m_origin.x - halfWidth, m_bounds.m_origin.y + halfHeight);
            return std::unique_ptr<QuadTree>(new QuadTree(origin, width, height, m_currentSplit + 1, m_maxObjects, m_maxSplit));
        }


        /************************************************************************************//**
        *   @brief      This method creates QuadTree from the current QuadTree but the bounds of 
        *               new QuadTree will be equivalent to the bottom right quadrant of the current
        *               QuadTree.
        *   @return     A shared pointer to the new QuadTree. 
        ****************************************************************************************/
        std::shared_ptr<QuadTree> QuadTree::getBottomRightQuadrant() const
        {
            float width = m_bounds.m_width / 2.0;
            float height = m_bounds.m_height / 2.0;
            float halfWidth = width / 2.0;
            float halfHeight = height / 2.0;
            Math::Vector2<float> origin(m_bounds.m_origin.x + halfWidth, m_bounds.m_origin.y + halfHeight);
            return std::unique_ptr<QuadTree>(new QuadTree(origin, width, height, m_currentSplit + 1, m_maxObjects, m_maxSplit));
        }

        
        /************************************************************************************//**
        *   @brief      Destructor 
        ****************************************************************************************/
        QuadTree::~QuadTree()
        {

        }
    }
}
