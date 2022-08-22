#ifndef SAT_OBJECT_H
#define SAT_OBJECT_H
#include "algorithm_export.h"
#include <Math/Vector2.h>
#include <Math/Line.h>


namespace GU
{
    namespace Al
    {
        class ALGORITHM_EXPORT SatObject
        {
            public:
                /********************************************************************//**
                *   @brief  This method returns the number of  vertices that make up the
                *           SAT object. 
                *   @return The number of vertices that make up the SAT object. 
                ************************************************************************/
                virtual std::size_t getVertexCount() const = 0;

                
                /********************************************************************//**
                *   @brief  This method returns the edge at the given index.
                *   @param  index The index of the edge to be returned. 
                *   @return A Line object representing the edge at index. 
                ************************************************************************/
                virtual Math::Line<float> getEdge(const std::size_t &index) const = 0;
                

                /********************************************************************//**
                *   @brief  This method returns a position of a vertex in global coordinates. 
                *   @param  index The index of the vertex to be returned. 
                *   @return The vertex in global coordinate.  
                ************************************************************************/
                virtual Math::Vector2<float> getGlobalCoordinate(const std::size_t &index) const = 0;
                
        };
    }
}

#endif
