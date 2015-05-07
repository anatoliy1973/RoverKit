/*
 * Arithmetic.h
 *
 * Created: 3/15/2015 14:02:46
 *  Author: Tolik
 */ 


#ifndef ARITHMETIC_H_
#define ARITHMETIC_H_

#include <inttypes.h>

// Convert Decimal to Binary Coded Decimal (BCD)
uint8_t Dec2Bcd(uint8_t num);

// Convert Binary Coded Decimal (BCD) to Decimal
uint8_t Bcd2Dec(uint8_t num);

#endif /* ARITHMETIC_H_ */