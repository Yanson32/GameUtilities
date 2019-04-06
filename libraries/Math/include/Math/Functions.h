#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace Math
{
    class Radian;
    class Degree;

    /*********************************************************//**
    *   @brief  Get the cosign of a Math::Radian object.
    *   @param  rad a Math::Radian object which will be used to
    *           calculate the cosign.
    *   @return a float representing the cosign of the input
    *           Math::Radian object.
    *************************************************************/
    float cos(const Radian &rad);


    /***********************************************************//**
    *   @brief  Get the cosign of the Math::Degree object.
    *   @param  deg a Math::Degree object which will be used to
    *           calculate the cosign.
    *   @return a float representing the cosign of the input
    *           Math::Degree object.
    ***************************************************************/
    float cos(const Degree &deg);


    /***********************************************************//**
    *   @brief  Get the sin of the Math::Radian object.
    *   @param  deg a Math::Radian object which will be used to
    *           calculate the sign.
    *   @return a float representing the sin of the input
    *           Math::Radian object.
    ***************************************************************/
    float sin(const Radian &rad);


    /***********************************************************//**
    *   @brief  Get the sin of the Math::Degree object.
    *   @param  deg a Math::Degree object which will be used to
    *           calculate the sign.
    *   @return a float representing the sin of the input
    *           Math::Degree object.
    ***************************************************************/
    float sin(const Degree &deg);
}

#endif // FUNCTIONS_H
