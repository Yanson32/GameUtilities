#include "GameUtilities/Algorithm/SAT/SatObject.h"
#include <vector>
#include <cassert>
#include <Math/Vector2.h>
#include <Math/Line.h>
#include <Math/Line.h>

namespace GU
{
    namespace Al
    {

        class SatObject::Impl
        {
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
            assert(index <= getVertexCount());
            if(index < getVertexCount())
            {
                Math::Vector2 start(getGlobalCoordinate(index));
                Math::Vector2 end(getGlobalCoordinate(index + 1));
                return Math::Line<float>(start, end);
            }
            else
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
            assert(index < getVertexCount());
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
            assert(index < getVertexCount());
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
            assert(index < getVertexCount());
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
            assert(index < getVertexCount());
            return m_pimpl->m_vertices[index];
        }


        /********************************************************************//**
        *   @brief  This method determines if tow SatObjects are colliding.
        *   @return True if the SatObjects are colliding. 
        ************************************************************************/
        bool SatObject::intersects(const SatObject &object) const
        {
            //Get the object with the least vetices.
            const SatObject * less = &object;
            const SatObject * more = this;
            if(this->getVertexCount() < object.getVertexCount())
            {
                less = this; 
                more = &object;           
            } 

            //Loop through all the vertecies of less 
            for(std::size_t i = 0; i < less->getEdgeCount(); ++i)
            {
                Math::Line<float> edge = less->getEdge(i);
                Math::Vector2<float> leftNormal = edge.LeftNormal();  
                
                //Find the least and greatest projections of less onto edge
                float lLess = 0;
                float mLess = 0;
                for(std::size_t i = 0; i < less->getVertexCount(); ++i)
                {
                    float dotProduct = leftNormal.dot(less->getGlobalCoordinate(i));
                    if(dotProduct < lLess)
                        lLess = dotProduct; 

                    if(dotProduct > mLess)
                        mLess = dotProduct;
                }
                

                //Find the least and greatest projections of more onto edge
                float lMore= 0;
                float mMore = 0;
                for(std::size_t i = 0; i < more->getVertexCount(); ++i)
                {
                    float dotProduct = leftNormal.dot(less->getGlobalCoordinate(i));
                    if(dotProduct < lMore)
                        lMore= dotProduct; 

                    if(dotProduct > mMore)
                        mMore = dotProduct;
                }

                
                //Return true if either polygon is overlapping the other
                if(lMore > mLess)
                    return true;
                else if(mMore > mLess)
                    return true; 
            } 
            

            //Loop through all the vertecies of more 
            for(std::size_t i = 0; i < more->getEdgeCount(); ++i)
            {
                Math::Line<float> edge = more->getEdge(i);
                Math::Vector2<float> leftNormal = edge.LeftNormal();  
                
                //Find the least and greatest projections of less onto edge
                float lLess = 0;
                float mLess = 0;
                for(std::size_t i = 0; i < less->getVertexCount(); ++i)
                {
                    float dotProduct = leftNormal.dot(less->getGlobalCoordinate(i));
                    if(dotProduct < lLess)
                        lLess = dotProduct; 

                    if(dotProduct > mLess)
                        mLess = dotProduct;
                }
                

                //Find the least and greatest projections of more onto edge
                float lMore= 0;
                float mMore = 0;
                for(std::size_t i = 0; i < more->getVertexCount(); ++i)
                {
                    float dotProduct = leftNormal.dot(less->getGlobalCoordinate(i));
                    if(dotProduct < lMore)
                        lMore= dotProduct; 

                    if(dotProduct > mMore)
                        mMore = dotProduct;
                }

                
                //Return true if either polygon is overlapping the other
                if(lMore > mLess)
                    return true;
                else if(mMore > mLess)
                    return true; 
            } 
            return false;
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
