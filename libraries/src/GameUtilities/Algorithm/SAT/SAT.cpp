#include "GameUtilities/Algorithm/SAT/SAT.h"
#include "GameUtilities/Algorithm/SAT/SatObject.h"
#include "GameUtilities/Algorithm/SAT/CollisionInfo.h"

namespace GU
{
    namespace Al
    {
        /****************************************************************************//**
        *   @brief  This method projects a SatObject onto a direction vector. 
        *   @param  first is the object to be projected.
        *   @param  normal is the direction vector the object will be projected on.
        *   @return A std::pair where the first data member is the lowest projection
        *           and the second data member is the highest projection. 
        ********************************************************************************/
        Projection project(const GU::Al::SatObject &first, const Direction &normal)
        {
            std::pair<float, float> result(std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity());
            //Find the least and greatest projections of first onto edge
            for(std::size_t i = 0; i < first.getVertexCount(); ++i)
            {
                float dotProduct = normal.dot(first.getGlobalCoordinate(i));
                
                if(dotProduct < result.first)
                    result.first = dotProduct; 

                if(dotProduct > result.second)
                    result.second = dotProduct;
            }
            return result; 
        }
        

        /****************************************************************************//**
        *   @brief  This method projects a vector of points onto a direction vector. 
        *           The points will be on global coordinates
        *   @param  first is a vector of points to be projected onto the direction vector.
        *   @param  normal is the direction vector the points will be projected onto.
        *   @return A std::pair where the first data member is the lowest projection
        *           and the second data member is the highest projection. 
        ********************************************************************************/
        Projection project(const PointsVec &first, const Direction &normal)
        {
            std::pair<float, float> result(std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity());
            //Find the least and greatest projections of first onto edge
            for(std::size_t i = 0; i < first.size(); ++i)
            {
                float dotProduct = normal.dot(first[i]);
                
                if(dotProduct < result.first)
                    result.first = dotProduct; 

                if(dotProduct > result.second)
                    result.second = dotProduct;
            }
            return result; 
        }
        
        
        /****************************************************************************//**
        *   @brief  This method projects a vector of points onto a direction vector. 
        *           The points vector will be in local coordinates so an object position
        *           will be needed.
        *   @param  first is a vector of points to be projected onto the direction vector.
        *   @param  firstPosition is the current position of the object represented by
        *           the first PointsVec.
        *   @param  normal is the direction vector the points will be projected onto.
        *   @return A std::pair where the first data member is the lowest projection
        *           and the second data member is the highest projection. 
        ********************************************************************************/
        Projection project(const PointsVec &first, const Position &firstPosition, const Direction &normal)
        {
            std::pair<float, float> result(std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity());
            //Find the least and greatest projections of first onto edge
            for(std::size_t i = 0; i < first.size(); ++i)
            {
                float dotProduct = normal.dot(first[i] + firstPosition);
                
                if(dotProduct < result.first)
                    result.first = dotProduct; 

                if(dotProduct > result.second)
                    result.second = dotProduct;
            }
            return result; 
        }
        

        /****************************************************************************//**
        *   @brief  This method determines if one object is overlapping the other.
        *   @param  first is the first object to be compared.
        *   @param  second is the second object to be compared.
        *   @return True if the objects are overlapping and false otherwise. 
        ********************************************************************************/
        bool satIntersects(const SatObject &first, const SatObject &second)
        {
            
            //Loop through all the edges of the current object 
            for(std::size_t i = 0; i < first.getVertexCount(); ++i)
            {
                Math::Line<float> edge = first.getEdge(i);
                Math::Vector2<float> leftNormal = edge.LeftNormal();  
        
                std::pair<float, float> firstResult = project(first, leftNormal);
                std::pair<float, float> secondResult = project(second, leftNormal);
                if(firstResult.first < secondResult.first && firstResult.first<  secondResult.second &&
                    firstResult.second < secondResult.first && firstResult.second < secondResult.second)
                {
                    return false;
                }
                else if(firstResult.first > secondResult.first && firstResult.first > secondResult.second &&
                    firstResult.second > secondResult.first && firstResult.second > secondResult.second)
                {
                    return false;
                }
            
 
            }    

            //Loop through all the edges of the parameter object 
            for(std::size_t i = 0; i < second.getVertexCount(); ++i)
            {
                Math::Line<float> edge = second.getEdge(i);
                Math::Vector2<float> leftNormal = edge.LeftNormal();  
                
                std::pair<float, float> firstResult = project(first, leftNormal);
                std::pair<float, float> secondResult = project(second, leftNormal);
                if(firstResult.first < secondResult.first && firstResult.first<  secondResult.second &&
                    firstResult.second < secondResult.first && firstResult.second < secondResult.second)
                {
                    return false;
                }
                else if(firstResult.first > secondResult.first && firstResult.first > secondResult.second &&
                    firstResult.second > secondResult.first && firstResult.second > secondResult.second)
                {
                    return false;
                }
            } 
            return true;
              
        }
        

        /****************************************************************************//**
        *   @brief  This method determines if one vector of points (which represents
        *           a shape) is overlapping a second vector of points.
        *   @param  first is a vector of points in global coordinates 
        *   @param  second is a vector of points in global coordinates 
        *   @return True if the vectors are overlapping and false otherwise. 
        ********************************************************************************/
        bool satIntersects(const PointsVec &first, const PointsVec &second)
        {
            //Loop through all the edges of the current object 
            for(std::size_t i = 0; i < first.size(); ++i)
            {
                Math::Vector2<float> start(first[i]);
                Math::Vector2<float> end;

                if(i == first.size() - 1)
                    end = first[0];
                else
                    end = first[i + 1];
                

                Math::Line<float> edge(start, end);
                Math::Vector2<float> leftNormal = edge.LeftNormal();  
    
                std::pair<float, float> firstResult = project(first, leftNormal);
                std::pair<float, float> secondResult = project(second, leftNormal);
                if(firstResult.first < secondResult.first && firstResult.first<  secondResult.second &&
                    firstResult.second < secondResult.first && firstResult.second < secondResult.second)
                {
                    return false;
                }
                else if(firstResult.first > secondResult.first && firstResult.first > secondResult.second &&
                    firstResult.second > secondResult.first && firstResult.second > secondResult.second)
                {
                    return false;
                }
            }  
            
            //Loop through all the edges of the parameter object 
            for(std::size_t i = 0; i < second.size(); ++i)
            {
                Math::Vector2<float> start(second[i]);
                Math::Vector2<float> end;

                if(i == second.size() - 1)
                    end = second[0];
                else
                    end = second[i + 1];
                Math::Line<float> edge(start, end);
                Math::Vector2<float> leftNormal = edge.LeftNormal();  
                
                std::pair<float, float> firstResult = project(first, leftNormal);
                std::pair<float, float> secondResult = project(second, leftNormal);
                if(firstResult.first < secondResult.first && firstResult.first<  secondResult.second &&
                    firstResult.second < secondResult.first && firstResult.second < secondResult.second)
                {
                    return false;
                }
                else if(firstResult.first > secondResult.first && firstResult.first > secondResult.second &&
                    firstResult.second > secondResult.first && firstResult.second > secondResult.second)
                {
                    return false;
                }
            } 
            return true;

        }
        

        /****************************************************************************//**
        *   @brief  This method determines if one vector of points (which represents
        *           a shape) is overlapping a second vector of points.
        *   @param  first is a vector of points in local coordinates. 
        *   @param  The position of the first shape in global coordinates.
        *   @param  second is a vector of points in local coordinates.
        *   @param  The position of the second shape in global coordinates.
        *   @return True if the vectors are overlapping and false otherwise. 
        ********************************************************************************/
        bool satIntersects(const PointsVec &first, const Position &fPos, const PointsVec &second, const Position &sPos)
        {
            //Loop through all the edges of the current object 
            for(std::size_t i = 0; i < first.size(); ++i)
            {
                Math::Vector2<float> start(first[i] + fPos);
                Math::Vector2<float> end;

                if(i == first.size() - 1)
                    end = first[0] + fPos;
                else
                    end = first[i + 1] + fPos;
                

                Math::Line<float> edge(start, end);
                Math::Vector2<float> leftNormal = edge.LeftNormal();  
    
                std::pair<float, float> firstResult = project(first, fPos, leftNormal);
                std::pair<float, float> secondResult = project(second, sPos, leftNormal);
                if(firstResult.first < secondResult.first && firstResult.first<  secondResult.second &&
                    firstResult.second < secondResult.first && firstResult.second < secondResult.second)
                {
                    return false;
                }
                else if(firstResult.first > secondResult.first && firstResult.first > secondResult.second &&
                    firstResult.second > secondResult.first && firstResult.second > secondResult.second)
                {
                    return false;
                }
            }  
            
            //Loop through all the edges of the parameter object 
            for(std::size_t i = 0; i < second.size(); ++i)
            {
                Math::Vector2<float> start(second[i] + sPos);
                Math::Vector2<float> end;

                if(i == second.size() - 1)
                    end = second[0] + sPos;
                else
                    end = second[i + 1] + sPos;
                Math::Line<float> edge(start, end);
                Math::Vector2<float> leftNormal = edge.LeftNormal();  
                
                std::pair<float, float> firstResult = project(first, fPos, leftNormal);
                std::pair<float, float> secondResult = project(second, sPos, leftNormal);
                if(firstResult.first < secondResult.first && firstResult.first<  secondResult.second &&
                    firstResult.second < secondResult.first && firstResult.second < secondResult.second)
                {
                    return false;
                }
                else if(firstResult.first > secondResult.first && firstResult.first > secondResult.second &&
                    firstResult.second > secondResult.first && firstResult.second > secondResult.second)
                {
                    return false;
                }
            } 
            return true;

        }
    }
}
