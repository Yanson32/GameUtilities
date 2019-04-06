#include "Math\cVector.h"
#include <cmath>
#include <stdexcept>


namespace Math
{
	/************************************************************//**
	*	@brief	Default constructor
	****************************************************************/
	cVector::cVector()
	{

	}


	/************************************************************//**
	*	@brief	Constructor with two arguments.
	*	@param	newX movement on the x axis.
	*	@param	newY movement on the y axis.
	****************************************************************/
	cVector::cVector(const float newX, const float newY) :
		x(newX),
		y(newY)
	{

	}


	/************************************************************//**
	*	@brief	Get the vectors magnitude.
	*	@return	The magnitude of the vector
	****************************************************************/
	float cVector::magnitude() const
	{
		//Use pythagorean theorem to calculate magnitude
		return std::sqrt(x * x + y * y);
	}


	/************************************************************//**
	*	@brief	Set the vectors magnitude to one, with the same
	*			direction.
	****************************************************************/
	void cVector::normalize()
	{
		float mag = magnitude();
		if (!mag)
			throw std::runtime_error("cannot divide by zero [cVector::normalize]");

		x = x / mag;
		y = y / mag;
	}


	/************************************************************//**
	*	@brief	Scale the vector according to the input param.
	*	@param	scalar the amout of scaling to occur.
	*	@return	A vector that has been scaled in comparison to
	*		    this vector object.
	****************************************************************/
	cVector cVector::operator * (const float scalar)
	{
		float mag = (magnitude() * scalar);
		cVector vec;
		vec.setMagnitude(mag);
		return vec;
	}


	/************************************************************//**
	*	@brief	Get the difference between two vectors
	*	@param	param a vector to subtract from this vector object.
	*	@return	A vector representing the difference between this
	*			vector and the input vector (param)
	****************************************************************/
	cVector cVector::operator - (const cVector param)
	{
		float xAxis = x - param.x;
		float yAxis = y - param.y;
		return cVector(x, y);
	}


	/************************************************************//**
	*	@brief	Get the sum of two vectors
	*	@param	param a vector to be added to this vector object.
	*	@return	A vector representing the sum of this
	*			vector and the input vector (param)
	****************************************************************/
	cVector cVector::operator + (const cVector param)
	{
		float xAxis = x + param.x;
		float yAxis = y + param.y;
		return cVector(xAxis, yAxis);
	}


	/************************************************************//**
	*	@brief	Set the magnitude of the vector
	*	@param	magnitude the new magnitude of the vector.
	****************************************************************/
	void cVector::setMagnitude(const float magnitude)
	{
		normalize();
		cVector vec = *this * magnitude;
		x = vec.x;
		y = vec.y;
	}


	/************************************************************//**
	*	@brief	Calculate the dot product of two vectors.
	*	@param	param a vector that will be used to calculate the
	*			dot product against.
	*	@return	The dot product of this vector and the input vector.
	****************************************************************/
	float cVector::dot(const cVector param)
	{
		return x  * param.x + y * param.y;
	}


	/************************************************************//**
	*	@brief	Destructor
	****************************************************************/
	cVector::~cVector()
	{

	}
}