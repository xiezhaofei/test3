#ifndef _FAST_MATH_OPERATIONS_H_
#define _FAST_MATH_OPERATIONS_H_

#define MAGIC 0x5f3759df
#define THREEHALFS 1.5f
 
#include "inc/macro.h"

static inline float _RecipSqrt(float number)
{
	int i,j;
	float x2, y, y2,tmp;

	x2 = number * 0.5F;
	y   = number;
	i   = * ( int * ) &y;   
	j   = MAGIC - ( i >> 1 ); 
	y   = * ( float * ) &j;
	y2  = y * y;
	tmp = THREEHALFS - x2 * y2;
	//y   *=  tmp;
	//y   = y * ( THREEHALFS - ( x2 * y * y ) ); // 1st iteration
	//y   = y * ( THREEHALFS - ( x2 * y * y ) ); // 2nd iteration, this can be removed

	return y*tmp;
}

static inline float _Recip(float number)
{
	int i,j;
	float x2, y, y2,tmp;

	x2  = number * 0.5F;
	y   = number;
	i   = * ( int * ) &y;   
	j   = MAGIC - ( i >> 1 ); 
	y   = * ( float * ) &j;
	y2  = y * y;
	tmp = THREEHALFS - x2 * y2;
	y   *=  tmp;
//	y   = y * ( THREEHALFS - ( x2 * y * y ) ); // 1st iteration
//	y   = y * ( THREEHALFS - ( x2 * y * y ) ); // 2nd iteration, this can be removed

	return y*y;
}

static inline float _Log10(const float val, register float* const pTable, register const unsigned precision)
{
	/* get access to float bits */
	register const int* const pVal = (const int*)(&val);

	/* extract exponent and mantissa (quantized) */
	register const int exp = ((*pVal >> 23) & 255) - 127;
	register const int man = (*pVal & 0x7FFFFF) >> (23 - precision);

	/* exponent plus lookup refinement */
	return ((float)(exp) + pTable[man]) * 0.301029995663981f;
}
#endif
