/*
 * Arithmetic.h
 *
 * Created: 3/15/2015 14:02:46
 *  Author: Tolik
 */ 


#ifndef ARITHMETIC_H_
#define ARITHMETIC_H_

#include <inttypes.h>

long Multiply(long x, long y)
{
	return ((x >> 16) * y) + (((x & 0x0000FFFF) * y) >> 16);
}

// Convert Decimal to Binary Coded Decimal (BCD)
uint8_t Dec2Bcd(uint8_t num)
{
	return (((num / 10) << 4) + (num % 10));
}

// Convert Binary Coded Decimal (BCD) to Decimal
uint8_t Bcd2Dec(uint8_t num)
{
	return (((num >> 4) * 10) + (num & 0xF));
}

#endif /* ARITHMETIC_H_ */