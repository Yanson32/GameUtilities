#ifndef MATH_C_VECTOR_H
#define MATH_C_VECTOR_H
/************************************************************//**
*	@author	Wayne J Larson Jr.
*	@date	5/7/2018
****************************************************************/
namespace Math
{
	class cVector
	{
	public:
		/************************************************************//**
		*	@brief	Default constructor
		****************************************************************/
		cVector();


		/************************************************************//**
		*	@brief	Constructor with two arguments.
		*	@param	newX movement on the x axis.
		*	@param	newY movement on the y axis.
		****************************************************************/
		cVector(const float newX, const float newY);


		/************************************************************//**
		*	@brief	Get the vectors magnitude.
		*	@return	The magnitude of the vector
		****************************************************************/
		float magnitude() const;


		/************************************************************//**
		*	@brief	Set the vectors magnitude to one, with the same
		*			direction.
		****************************************************************/
		void normalize();


		/************************************************************//**
		*	@brief	Scale the vector according to the input param.
		*	@param	scalar the amout of scaling to occur.
		*	@return	A vector that has been scaled in comparison to
		*		    this vector object.
		****************************************************************/
		cVector operator * (const float scalar);


		/************************************************************//**
		*	@brief	Get the difference between two vectors
		*	@param	param a vector to subtract from this vector object.
		*	@return	A vector representing the difference between this
		*			vector and the input vector (param)
		****************************************************************/
		cVector operator - (const cVector param);


		/************************************************************//**
		*	@brief	Get the sum of two vectors
		*	@param	param a vector to be added to this vector object.
		*	@return	A vector representing the sum of this
		*			vector and the input vector (param)
		****************************************************************/
		cVector operator + (const cVector param);


		/************************************************************//**
		*	@brief	Set the magnitude of the vector
		*	@param	magnitude the new magnitude of the vector.
		****************************************************************/
		void setMagnitude(const float magnitude);


		/************************************************************//**
		*	@brief	Calculate the dot product of two vectors.
		*	@param	param a vector that will be used to calculate the
		*			dot product against.
		*	@return	The dot product of this vector and the input vector.
		****************************************************************/
		float dot(const cVector param);


		/************************************************************//**
		*	@brief	Destructor
		****************************************************************/
		~cVector();


		float x = 0;
		float y = 0;
	};
}

#endif
