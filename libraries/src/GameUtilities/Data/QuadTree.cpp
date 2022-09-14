#include "GameUtilities/Data/QuadTree.h"
#include <cassert>

namespace GU
{
    namespace Data
    {
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
        QuadTree::QuadTree(const Math::Vector2<float> &origin, 
        const float &width, 
        const float &height, 
        const int currentLevel,
        const int &max, 
        const int maxLevel):
        m_bounds(origin, width, height),
        m_currentLevel(currentLevel),
        m_max(max),
        m_maxLevel(maxLevel)
        {

        }


        /****************************************************************************************
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

        
        /****************************************************************************************
        *   @brief      This method determines if the AABB intersects the QuadTree. 
        *   @param      aabb will be checked for collision against the QuadTree.
        *   @return     True if collision is detected and false otherwise. 
        ****************************************************************************************/
        bool QuadTree::intersects(const AABB &aabb) const
        {
            
            return m_bounds.intersects(aabb);
        }
        

        /****************************************************************************************
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

        
        /****************************************************************************************
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

        
        /****************************************************************************************
        *   @brief      This method will split the current QuadTree into 4 QuadTrees. 
        ****************************************************************************************/
        void QuadTree::split()
        {
            if(m_data.size() >= m_max) 
            {
                if(m_currentLevel < m_maxLevel)
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

    
        /****************************************************************************************
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
            return std::shared_ptr<QuadTree>(new QuadTree(origin, width, height, m_currentLevel + 1, m_max, m_maxLevel));
        }


        /****************************************************************************************
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
            return std::unique_ptr<QuadTree>(new QuadTree(origin, width, height, m_currentLevel + 1, m_max, m_maxLevel));
        }


        /****************************************************************************************
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
            return std::unique_ptr<QuadTree>(new QuadTree(origin, width, height, m_currentLevel + 1, m_max, m_maxLevel));
        }


        /****************************************************************************************
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
            return std::unique_ptr<QuadTree>(new QuadTree(origin, width, height, m_currentLevel + 1, m_max, m_maxLevel));
        }

        
        /****************************************************************************************
        *   @brief      Destructor 
        ****************************************************************************************/
        QuadTree::~QuadTree()
        {

        }
    }
}
