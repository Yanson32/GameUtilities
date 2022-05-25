#include "GameUtilities/Algorithm/SAT/SAT.h"
#include "GameUtilities/Algorithm/SAT/SatObject.h"

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
    }
}
