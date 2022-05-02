#ifndef SAT_OBJECT_H
#define SAT_OBJECT_H
#include "algorithm_export.h"
#include <Math/Vector2.h>

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
                SatObject(const unsigned &vertexCount);
                

                /********************************************************************//**
                *   @brief  This method returns a reference to the point at index.
                *   @param  index is the position of the element in the std::vector
                *   @return This method retruns a reference to the point at the index
                *           specified in the parameter list.
                ************************************************************************/
                Math::Vector2<float>& operator [] (const unsigned index); 
               
 
                Math::Vector2<float> operator [] (const unsigned index) const;
                

                /********************************************************************//**
                *   @brief  This method returns the number of  vertices that make up the
                *           SAT object. 
                *   @return The number of vertices that make up the SAT object. 
                ************************************************************************/
                std::size_t getVertexCount() const;


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
