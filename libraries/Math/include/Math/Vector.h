#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H
#include "Math/Point.h"
#include "Math/Radian.h"

/*******************************************************************//**
*   @author Wayne J Larson Jr
*   @brief  The Vector class is designed to mimic the mathmatical
*           concept of a vector.
***********************************************************************/
namespace Math
{

    class Vector final
    {
        public:
            Vector() = default;
            explicit Vector(const Radian &direction, unsigned magnitude);
            explicit Vector(const Degree &direction, unsigned magnitude);


            /****************************************************************//**
            *   @brief  Get the x axis movemet in cartesian coordinates
            *   @return the movement on the x axis in cartesian coordinates
            ********************************************************************/
            float GetX() const;


            /****************************************************************//**
            *   @brief  Get the y axis movemet in cartesian coordinates
            *   @return the movement on the y axis in cartesian coordinates
            ********************************************************************/
            float GetY() const;
            unsigned magnitude;
            Radian direction;
    };

}
#endif // MATH_VECTOR_H
