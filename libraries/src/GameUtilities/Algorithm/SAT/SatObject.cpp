#include "GameUtilities/Algorithm/SAT/SatObject.h"
#include "GameUtilities/Algorithm/SAT/SAT.h"
#include <vector>
#include <cassert>
#include <Math/Vector2.h>
#include <Math/Line.h>
#include <Math/Line.h>
#include <limits>
#include <iostream>
#include <utility>

namespace GU
{
    namespace Al
    {

        class SatObject::Impl {
            public:
                Impl(){};
                ~Impl(){};
                std::vector<Math::Vector2<float>> m_vertices;
                Math::Vector2<float> m_position;
                float m_angle = 0;
                
        };

        /********************************************************************//**
        *   @brief  Constructor 
        ************************************************************************/
        SatObject::SatObject(const Math::Vector2<float> &position, const unsigned &vertexCount):
        m_pimpl(new SatObject::Impl())
        {
            assert(m_pimpl != nullptr);
            m_pimpl->m_position = position;
            m_pimpl->m_vertices.resize(vertexCount);            
        }
        
        void SatObject::setPosition(const Math::Vector2<float> &position)
        {
            assert(m_pimpl != nullptr);
            m_pimpl->m_position = position;
        }
        

        Math::Vector2<float> SatObject::getPosition() const
        {
            return m_pimpl->m_position;
        }

        /********************************************************************//**
        *   @brief  This method returns the number of  vertices that make up the
        *           SAT object. 
        *   @return The number of vertices that make up the SAT object. 
        ************************************************************************/
        std::size_t SatObject::getVertexCount() const
        {
            assert(m_pimpl != nullptr);
            return m_pimpl->m_vertices.size();
        }
      
         
        /********************************************************************//**
        *   @brief  This method returns the number of edges that make up the
        *           SAT object.
        *   @return The number of edges that make up the SAT object.
        ************************************************************************/
        std::size_t SatObject::getEdgeCount() const
        {
            assert(m_pimpl != nullptr);
            return m_pimpl->m_vertices.size(); 
        }


        /********************************************************************//**
        *   @brief  This method returns the edge at the given index.
        *   @param  index The index of the edge to be returned. 
        *   @return A Line object representing the edge at index. 
        ************************************************************************/
        Math::Line<float> SatObject::getEdge(const std::size_t &index) const
        {
            assert(m_pimpl != nullptr);
            if(index >= getEdgeCount())
                throw std::runtime_error("SatObject::getEdge index out of range");
            
            if(index < getVertexCount() - 1)
            {
                Math::Vector2 start(getGlobalCoordinate(index));
                Math::Vector2 end(getGlobalCoordinate(index + 1));
                return Math::Line<float>(start, end);
            }
            else if(index == getVertexCount() - 1)
            {
                Math::Vector2 start(getGlobalCoordinate(index));
                Math::Vector2 end(getGlobalCoordinate(0));
                return Math::Line<float>(start, end);
            }
        }


        /********************************************************************//**
        *   @brief  This method sets a coordiante at the index specified in
        *           global coordinates. The coordinate will be translated to 
        *           local coordinates. 
        *   @param  coordinate is the new coordinate value in global coordinates 
        *   @param  index is the current index of the coordinate to be updated. 
        ************************************************************************/
        void  SatObject::setGlobalCoordinate(const Math::Vector2<float> &coordinate, const std::size_t &index) const
        {
            assert(m_pimpl != nullptr);
            if(index >= getVertexCount())
                throw std::runtime_error("SatObject::setGlobalCoordinate index out of range");
            Math::Vector2<float> temp = m_pimpl->m_position - coordinate;
            temp.x = -temp.x;
            temp.y = -temp.y; 
            m_pimpl->m_vertices[index] = temp;
        }


        /********************************************************************//**
        *   @brief  This method returns a coordinate at the index specified. In
        *           global coordinates.  
        *   @param  index The current index of the coordinated stored internally 
        *           to the SatObject.  
        *   @return A coordinate at the index specified in global coordinates.
        ************************************************************************/
        Math::Vector2<float> SatObject::getGlobalCoordinate(const std::size_t &index) const
        {
            assert(m_pimpl != nullptr);
            if(index >= getVertexCount())
                throw std::runtime_error("SatObject::getGlobalCoordinate index out of range");
    
            return getLocalCoordinate(index) + m_pimpl->m_position; 
        }


        /********************************************************************//**
        *   @brief  This method sets a coordinate in local coordinates. The
        *           coordinate will not be translated to local coordinates.
        *   @param  coordinate The new value of coordinate at the index specified
        *           in local coordinates 
        *   @param  index is the index of the coordinate to be replaced.
        ************************************************************************/
        void  SatObject::setLocalCoordinate(const Math::Vector2<float> &coordinate, const std::size_t &index) const
        {
            assert(m_pimpl != nullptr);
            if(index >= getVertexCount());
                std::runtime_error("Index out of range"); 
            m_pimpl->m_vertices[index] = coordinate;
        }


        /********************************************************************//**
        *   @brief  This method returns the coordinate at the specified index
        *           In local coordinates.  
        *   @param  index is the current index of the coordinate. 
        *   @return The coordinate at the specified index in local coordinates.
        ************************************************************************/
        Math::Vector2<float>  SatObject::getLocalCoordinate(const std::size_t &index) const
        {
            assert(m_pimpl != nullptr);
            if(index < 0 || index >= getVertexCount());
                std::runtime_error("Index out of range"); 
            return m_pimpl->m_vertices[index];
        }

        
        /********************************************************************//**
        *   @brief  This method determines if tow SatObjects are colliding.
        *   @return True if the SatObjects are colliding. 
        ************************************************************************/
        bool SatObject::intersects(const SatObject &object) const
        {
            Math::Vector2<float> direction; //This vector represents the direction needed for collision resolution            
            float magnitude = std::numeric_limits<float>::infinity(); //This is the distance the objects need to move for collision resolution
            

            //Loop through all the edges of the current object 
            for(std::size_t i = 0; i < getEdgeCount(); ++i)
            {
                Math::Line<float> edge = getEdge(i);
                Math::Vector2<float> leftNormal = edge.LeftNormal();  
        
                std::pair<float, float> thisResult = project(*this, leftNormal);
                std::pair<float, float> objectResult = project(object, leftNormal);
                if(thisResult.first < objectResult.first && thisResult.first<  objectResult.second &&
                    thisResult.second < objectResult.first && thisResult.second < objectResult.second)
                {
                    return false;
                }
                else if(thisResult.first > objectResult.first && thisResult.first > objectResult.second &&
                    thisResult.second > objectResult.first && thisResult.second > objectResult.second)
                {
                    return false;
                }
            } 
            

            //Loop through all the edges of the parameter object 
            for(std::size_t i = 0; i < object.getEdgeCount(); ++i)
            {
                Math::Line<float> edge = object.getEdge(i);
                Math::Vector2<float> leftNormal = edge.LeftNormal();  
                
                std::pair<float, float> thisResult = project(*this, leftNormal);
                std::pair<float, float> objectResult = project(object, leftNormal);
                if(thisResult.first < objectResult.first && thisResult.first<  objectResult.second &&
                    thisResult.second < objectResult.first && thisResult.second < objectResult.second)
                {
                    return false;
                }
                else if(thisResult.first > objectResult.first && thisResult.first > objectResult.second &&
                    thisResult.second > objectResult.first && thisResult.second > objectResult.second)
                {
                    return false;
                }
            } 
            return true;
        }

        
        /********************************************************************//**
        *   @brief  Destructor 
        ************************************************************************/
        SatObject::~SatObject()
        {
            if(m_pimpl)
                delete m_pimpl;
        }
        
    }
}
