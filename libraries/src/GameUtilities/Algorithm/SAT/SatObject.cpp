#include "GameUtilities/Algorithm/SAT/SatObject.h"
#include <vector>
#include <cassert>
#include <Math/Vector2.h>

namespace GU
{
    namespace Al
    {

        class SatObject::Impl
        {
            public:
                Impl(){};
                ~Impl(){};
            std::vector<Math::Vector2<float>> m_points;
        };

        
        /********************************************************************//**
        *   @brief  Constructor 
        ************************************************************************/
        SatObject::SatObject(const unsigned &points):
        m_pimpl(new SatObject::Impl())
        {
            assert(m_pimpl != nullptr);
            m_pimpl->m_points.resize(points);            
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
            assert(m_pimpl->m_points.size() > index); 
            return m_pimpl->m_points[index]; 
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
