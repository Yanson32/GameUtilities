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
                *   @brief  Constructor 
                ************************************************************************/
                SatObject(const Math::Vector2<float> &position, const unsigned &vertexCount);
                

                /********************************************************************//**
                *   @brief  This method returns the number of  vertices that make up the
                *           SAT object. 
                *   @return The number of vertices that make up the SAT object. 
                ************************************************************************/
                std::size_t getVertexCount() const;

                
                /********************************************************************//**
                *   @brief  This method returns the number of edges that make up the
                *           SAT object.
                *   @return The number of edges that make up the SAT object.
                ************************************************************************/
                std::size_t getEdgeCount() const;

                
                /********************************************************************//**
                *   @brief  This method returns the edge at the given index.
                *   @param  index The index of the edge to be returned. 
                *   @return A Line object representing the edge at index. 
                ************************************************************************/
                Math::Line<float> getEdge(const std::size_t &index) const;
               
 
                /********************************************************************//**
                *   @brief  This method sets a coordiante at the index specified in
                *           global coordinates. The coordinate will be translated to 
                *           local coordinates. 
                *   @param  coordinate is the new coordinate value in global coordinates 
                *   @param  index is the current index of the coordinate to be updated. 
                ************************************************************************/
                void  setGlobalCoordinate(const Math::Vector2<float> &coordinate, const std::size_t &index) const;
                
                
                /********************************************************************//**
                *   @brief  This method returns a coordinate at the index specified. In
                *           global coordinates.  
                *   @param  index The current index of the coordinated stored internally 
                *           to the SatObject.  
                *   @return A coordinate at the index specified in global coordinates.
                ************************************************************************/
                Math::Vector2<float> getGlobalCoordinate(const std::size_t &index) const;

                
                /********************************************************************//**
                *   @brief  This method sets a coordinate in local coordinates. The
                *           coordinate will not be translated to local coordinates.
                *   @param  coordinate The new value of coordinate at the index specified
                *           in local coordinates 
                *   @param  index is the index of the coordinate to be replaced.
                ************************************************************************/
                void  setLocalCoordinate(const Math::Vector2<float> &coordinate, const std::size_t &index) const;
                

                /********************************************************************//**
                *   @brief  This method returns the coordinate at the specified index
                *           In local coordinates.  
                *   @param  index is the current index of the coordinate. 
                *   @return The coordinate at the specified index in local coordinates.
                ************************************************************************/
                Math::Vector2<float> getLocalCoordinate(const std::size_t &index) const;
                

                /********************************************************************//**
                *   @brief  This method determines if tow SatObjects are colliding.
                *   @return True if the SatObjects are colliding. 
                ************************************************************************/
                bool intersects(const SatObject &object) const;
                

                /********************************************************************//**
                *   @brief  Destructor 
                ************************************************************************/
                virtual ~SatObject();
            private:
                class Impl;
                Impl *m_pimpl = nullptr;  
        };
    }
}

#endif
