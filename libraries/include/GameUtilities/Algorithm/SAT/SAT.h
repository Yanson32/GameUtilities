#ifndef SAT_H
#define SAT_H

#include <utility>
#include <Math/Vector2.h>
#include <vector>
#include "GameUtilities/Algorithm/SAT/CollisionTypes.h"
#include "algorithm_export.h"

namespace GU
{
    namespace Al
    {
        class SatObject;
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
        

        /****************************************************************************//**
        *   @brief  This method determines if one object is overlapping the other.
        *   @param  first is the first object to be compared.
        *   @param  second is the second object to be compared.
        *   @return True if the objects are overlapping and false otherwise. 
        ********************************************************************************/
        bool ALGORITHM_EXPORT satIntersects(const SatObject &first, const SatObject &second);
        

        /****************************************************************************//**
        *   @brief  This method determines if one vector of points (which represents
        *           a shape) is overlapping a second vector of points.
        *   @param  first is a vector of points in global coordinates 
        *   @param  second is a vector of points in global coordinates 
        *   @return True if the vectors are overlapping and false otherwise. 
        ********************************************************************************/
        bool ALGORITHM_EXPORT satIntersects(const PointsVec &first, const PointsVec &second);
        

        /****************************************************************************//**
        *   @brief  This method determines if one vector of points (which represents
        *           a shape) is overlapping a second vector of points.
        *   @param  first is a vector of points in local coordinates. 
        *   @param  The position of the first shape in global coordinates.
        *   @param  second is a vector of points in local coordinates.
        *   @param  The position of the second shape in global coordinates.
        *   @return True if the vectors are overlapping and false otherwise. 
        ********************************************************************************/
        bool ALGORITHM_EXPORT satIntersects(const PointsVec &first, const Position &fPos, const PointsVec &second, const Position &sPos);
    }
}

#endif
