#include "Arithmetic.h"

long Multiply(long x, long y)
{
	return ((x >> 16) * y) + (((x & 0x0000FFFF) * y) >> 16);
}

uint8_t Dec2Bcd(uint8_t num)
{
	return (((num / 10) << 4) + (num % 10));
}

uint8_t Bcd2Dec(uint8_t num)
{
	return (((num >> 4) * 10) + (num & 0xF));
}
