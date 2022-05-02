#include "GameUtilities/Algorithm/SAT/SatObject.h"
#include <vector>
#include <cassert>
#include <Math/Vector2.h>
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

            
            for(std::size_t i = 0; i < less->getVertexCount() - 1; ++i)
            {
                Math::Line<float> edge((*less)[i], (*more)[i]);
                Math::Vector2<float> leftNormal = edge.LeftNormal();  
                
                //Project all points onto the normal
                std::vector<Math::Vector2<float>> lessPoints;
                for(std::size_t i = 0; i < less->getVertexCount(); ++i)
                {
                    lessPoints.push_back(leftNormal.dot((*less)[i]));
                        
                }
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
