/*
 * ThreeWire.cpp
 *
 * Created: 3/15/2015 21:02:45
 *  Author: Tolik
 */ 

#include "ThreeWire.h"

ThreeWire::ThreeWire(uint8_t dataPin, uint8_t cePin, uint8_t clkPin, int del)
{
	this->m_dataPin = dataPin;
	this->m_cePin = cePin;
	this->m_clkPin = clkPin;
	this->m_delay = del;
	
	pinMode(this->m_cePin, OUTPUT);
	pinMode(this->m_clkPin, OUTPUT);
	
	digitalWrite(this->m_cePin, LOW);
}

// A helper function to setup the start condition.
//
// An 'init' function is not used.
// But now the pinMode is set every time.
// That's not a big deal, and it's valid.
// At startup, the pins of the Arduino are high impedance.
// Since the DS1302 has pull-down resistors,
// the signals are low (inactive) until the DS1302 is used.
void ThreeWire::BeginReading()
{
    digitalWrite(this->m_cePin, LOW); // default, not enabled
    pinMode(this->m_cePin, OUTPUT);

    digitalWrite(this->m_clkPin, LOW); // default, clock low
    pinMode(this->m_clkPin, OUTPUT);

    pinMode(this->m_dataPin, OUTPUT);

    digitalWrite(this->m_cePin, HIGH); // start the session
    delayMicroseconds(this->m_delay);	
}

void ThreeWire::EndReading()
{
    // Set CE low
    digitalWrite(this->m_cePin, LOW);

    delayMicroseconds(this->m_delay);
}

void ThreeWire::Write(uint8_t data)
{
    for (int i = 0; i < 8; i++)
    {
		digitalWrite(this->m_dataPin, bitRead(data, i));
		delayMicroseconds(this->m_delay);
		
		this->SerialClock();
    }
}

// A helper function for reading a byte with bit toggle
//
// This function assumes that the SCLK is still low.
//
uint8_t ThreeWire::Read()
{
	uint8_t result = 0;
	
	pinMode(this->m_dataPin, INPUT);
	
	for (int i = 0; i < 8; i++)
	{
		bitWrite(result, i, digitalRead(this->m_dataPin));
		
		this->SerialClock();
	}
	
	return result;
}

void ThreeWire::SerialClock()
{
	digitalWrite(this->m_clkPin, HIGH);
	delayMicroseconds(this->m_delay);
	
	digitalWrite(this->m_clkPin, LOW);
	delayMicroseconds(this->m_delay);
}
