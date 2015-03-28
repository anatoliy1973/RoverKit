/* 
* DS1302Rtc.cpp
*
* Created: 3/28/2015 12:55:24
* Author: Tolik
*/


#include "DS1302Rtc.h"

#define DS1302_DATA_ACCESS_DELAY 4

DS1302Rtc::DS1302Rtc(uint8_t dataPin, uint8_t cePin, uint8_t clkPin) : Rtc(DS1302_THREASHOLD)
{
	this->m_channel = new ThreeWire(dataPin, cePin, clkPin, DS1302_DATA_ACCESS_DELAY);
}

// default destructor
DS1302Rtc::~DS1302Rtc()
{
	delete this->m_channel;
} //~DS1302Rtc

void DS1302Rtc::Update(TTime& time)
{
	//TODO:
}

// This function reads a byte from the DS1302
// (clock or ram).
//
// The address could be like "0x80" or "0x81",
// the lowest bit is set anyway.
//
// This function may be called as the first function,
// also the pinMode is set.
//
uint8_t DS1302Rtc::readRTC(uint8_t address)
{
    uint8_t result;

    // set lowest bit (read bit) in address
    bitSet(address, DS1302_READ);

    this->m_channel->BeginReading();
    // the I/O-line is released for the value
    this->m_channel->Write(address);
    result = this->m_channel->Read();
    this->m_channel->EndReading();

    return result;
}

// This function writes a byte to the DS1302 (clock or ram).
//
// The address could be like "0x80" or "0x81",
// the lowest bit is cleared anyway.
//
// This function may be called as the first function,
// also the pinMode is set.
//
void DS1302Rtc::writeRTC(uint8_t address, uint8_t value)
{
    // clear lowest bit (read bit) in address
    bitClear(address, DS1302_READ);

    this->m_channel->BeginReading();

    this->m_channel->Write(address);
    this->m_channel->Write(value);

    this->m_channel->EndReading();
}
