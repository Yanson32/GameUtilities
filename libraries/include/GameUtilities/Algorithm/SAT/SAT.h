#ifndef SAT_H
#define SAT_H

#include <utility>
#include <Math/Vector2.h>
#include <vector>
#include "algorithm_export.h"

namespace GU
{
    namespace Al
    {
        class SatObject;
        typedef std::vector<Math::Vector2<float>> PointsVec;
        typedef Math::Vector2<float> Position;
        typedef Math::Vector2<float> Direction;
        typedef std::pair<float, float> Projection;
        /****************************************************************************//**
        *   @brief  This method projects a SatObject onto a direction vector. 
        *   @param  first is the object to be projected.
        *   @param  normal is the direction vector the object will be projected on.
        *   @return A std::pair where the first data member is the lowest projection
        *           and the second data member is the highest projection. 
        ********************************************************************************/
        Projection ALGORITHM_EXPORT project(const GU::Al::SatObject &first, const Direction &normal);        
        

        /****************************************************************************//**
        *   @brief  This method projects a vector of points onto a direction vector. 
        *           The points will be on global coordinates
        *   @param  first is a vector of points to be projected onto the direction vector.
        *   @param  normal is the direction vector the points will be projected onto.
        *   @return A std::pair where the first data member is the lowest projection
        *           and the second data member is the highest projection. 
        ********************************************************************************/
        Projection ALGORITHM_EXPORT project(const PointsVec &first, const Direction &normal);
        

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
        Projection ALGORITHM_EXPORT project(const PointsVec &first, const Position &firstPosition, const Direction &normal);
    }
}

#endif
