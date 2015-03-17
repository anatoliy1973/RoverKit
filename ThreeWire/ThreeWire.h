/*
 * ThreeWire.h
 *
 * Created: 3/15/2015 21:16:17
 *  Author: Tolik
 */ 


#ifndef THREEWIRE_H_
#define THREEWIRE_H_

#include "MultiPlatform.h"

//////////////////////////////////////////////////////////////////////////
// Provides communication with devices those use 3 wire interface
//////////////////////////////////////////////////////////////////////////
class ThreeWire
{
private:
	unsigned char m_dataPin;
	unsigned char m_cePin;
	unsigned char m_clkPin;
	int m_delay;
	
public:
	// Initializes a new instance of the ThreeWire class
	ThreeWire(unsigned char dataPin, unsigned char cePin, unsigned char m_clkPin, int del);
	
	void Write(unsigned char data);
	unsigned char Read();
	
private:
    void SerialClock();
	
};


#endif /* THREEWIRE_H_ */