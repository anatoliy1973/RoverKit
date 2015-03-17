/*
 * ThreeWire.cpp
 *
 * Created: 3/15/2015 21:02:45
 *  Author: Tolik
 */ 

#include "ThreeWire.h"

ThreeWire::ThreeWire(unsigned char dataPin, unsigned char cePin, unsigned char clkPin, int del)
{
	this->m_dataPin = dataPin;
	this->m_cePin = cePin;
	this->m_clkPin = clkPin;
	this->m_delay = del;
	
	pinMode(this->m_cePin, OUTPUT);
	pinMode(this->m_clkPin, OUTPUT);
	
	digitalWrite(this->m_cePin, LOW);
}

void ThreeWire::Write(unsigned char data)
{
    for (int i = 0; i < 8; i++)
    {
		digitalWrite(this->m_dataPin, bitRead(data, i));
		delayMicroseconds(this->m_delay);
		
		this->SerialClock();
    }
}

unsigned char ThreeWire::Read()
{
	unsigned char value = 0;
	
	pinMode(this->m_dataPin, INPUT);
	
	for (int i = 0; i < 8; i++)
	{
		bitWrite(value, i, digitalRead(this->m_dataPin));
		
		this->SerialClock();
	}
	
	return value;
}

void ThreeWire::SerialClock()
{
	digitalWrite(this->m_clkPin, HIGH);
	delayMicroseconds(this->m_delay);
	
	digitalWrite(this->m_clkPin, LOW);
	delayMicroseconds(this->m_delay);
}
