/*
 * Arithmetic.h
 *
 * Created: 3/15/2015 14:02:46
 *  Author: Tolik
 */ 


#ifndef ARITHMETIC_H_
#define ARITHMETIC_H_


long Multiply(long x, long y)
{
	return ((x >> 16) * y) + (((x & 0x0000FFFF) * y) >> 16);
}


#endif /* ARITHMETIC_H_ */