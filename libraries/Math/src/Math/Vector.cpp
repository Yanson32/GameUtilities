#include "Math/Vector.h"
#include "Math/Functions.h"
namespace Math
{
    Vector::Vector(const Radian &direction, unsigned magnitude):
    magnitude(magnitude),
    direction(direction)
    {

    }

    Vector::Vector(const Degree &direction, unsigned magnitude):
    magnitude(magnitude),
    direction(direction)
    {

    }

    /****************************************************************//**
    *   @brief  Get the x axis movemet in cartesian coordinates
    *   @return the movement on the x axis in cartesian coordinates
    ********************************************************************/
    float Vector::GetX() const
    {
        return Math::cos(direction);
    }

    /****************************************************************//**
    *   @brief  Get the y axis movemet in cartesian coordinates
    *   @return the movement on the y axis in cartesian coordinates
    ********************************************************************/
    float Vector::GetY() const
    {
        return Math::sin(direction);
    }
}
