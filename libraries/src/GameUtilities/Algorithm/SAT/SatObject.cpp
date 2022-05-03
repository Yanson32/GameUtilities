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
        };

        
        /********************************************************************//**
        *   @brief  Constructor 
        ************************************************************************/
        SatObject::SatObject(const unsigned &vertexCount):
        m_pimpl(new SatObject::Impl())
        {
            assert(m_pimpl != nullptr);
            m_pimpl->m_vertices.resize(vertexCount);            
        }

    
        /********************************************************************//**
        *   @brief  This method returns a reference to the point at index.
        *   @param  index is the position of the element in the std::vector
        *   @return This method retruns a reference to the point at the index
        *           specified in the parameter list.
        ************************************************************************/
        Math::Vector2<float>& SatObject::operator [] (const unsigned index)
        {
            assert(m_pimpl != nullptr);
            assert(m_pimpl->m_vertices.size() > index); 
            return m_pimpl->m_vertices[index]; 
        }
        

        /********************************************************************//**
        *   @brief  This method returns a reference to the point at index.
        *   @param  index is the position of the element in the std::vector
        *   @return This method retruns a reference to the point at the index
        *           specified in the parameter list.
        ************************************************************************/
        Math::Vector2<float> SatObject::operator [] (const unsigned index) const
        {
            assert(m_pimpl != nullptr);
            assert(m_pimpl->m_vertices.size() > index); 
            return m_pimpl->m_vertices[index]; 
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
            assert(index <= m_pimpl->m_vertices.size());
            if(index < m_pimpl->m_vertices.size())
            {
                Math::Vector2 start(m_pimpl->m_vertices[index].x, m_pimpl->m_vertices[index].y);
                Math::Vector2 end(m_pimpl->m_vertices[index + 1].x, m_pimpl->m_vertices[index +1].y);
                return Math::Line<float>(start, end);
            }
            else
            {
                Math::Vector2 start(m_pimpl->m_vertices[index].x, m_pimpl->m_vertices[index].y);
                Math::Vector2 end(m_pimpl->m_vertices[0].x, m_pimpl->m_vertices[0].y);
                return Math::Line<float>(start, end);
            }
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
                    float dotProduct = leftNormal.dot((*less)[i]);
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
                    float dotProduct = leftNormal.dot((*less)[i]);
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
                    float dotProduct = leftNormal.dot((*less)[i]);
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
                    float dotProduct = leftNormal.dot((*less)[i]);
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
