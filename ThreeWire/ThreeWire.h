/*
 * ThreeWire.h
 *
 * Created: 3/15/2015 21:16:17
 *  Author: Tolik
 */ 


#ifndef THREEWIRE_H_
#define THREEWIRE_H_

#include "MultiPlatform.h"
#include <inttypes.h>

//////////////////////////////////////////////////////////////////////////
// Provides communication with devices those use 3 wire interface
//////////////////////////////////////////////////////////////////////////
class ThreeWire
{
private:
	uint8_t m_dataPin;
	uint8_t m_cePin;
	uint8_t m_clkPin;
	int m_delay;
	
public:
	// Initializes a new instance of the ThreeWire class
	ThreeWire(uint8_t dataPin, uint8_t cePin, uint8_t m_clkPin, int del);
	
	// A helper function to setup the start condition.
    void BeginReading();
    // A helper function to finish the communication.
	void EndReading();
    // A helper function for writing a byte with bit toggle
	void Write(uint8_t data);
	// A helper function for reading a byte with bit toggle
    uint8_t Read();
	
private:
    void SerialClock();
	
};


#endif /* THREEWIRE_H_ */