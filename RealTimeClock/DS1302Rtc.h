/* 
* DS1302Rtc.h
*
* Created: 3/28/2015 12:55:25
* Author: Tolik
*/


#ifndef __DS1302RTC_H__
#define __DS1302RTC_H__

#include "Rtc.h"
#include "ThreeWire\ThreeWire.h"

// Defines for the bits, to be able to change
// between bit number and binary definition.
// By using the bit number, using the DS1302
// is like programming an AVR microcontroller.
// But instead of using "(1<<X)", or "_BV(X)",
// the Arduino "bit(X)" is used.
#define DS1302_D0 0

// Bit for reading (bit in address)
#define DS1302_READ DS1302_D0 // READ=1, WRITE=0

#define DS1302_THREASHOLD 1000


class DS1302Rtc : public Rtc
{
//variables
private:
    ThreeWire* m_channel;

//functions
public:
	DS1302Rtc(uint8_t dataPin, uint8_t cePin, uint8_t clkPin);
	~DS1302Rtc();
protected:
    virtual void Update(TTime& time);
	
private:
	DS1302Rtc( const DS1302Rtc &c );
	DS1302Rtc& operator=( const DS1302Rtc &c );

    uint8_t readRTC(uint8_t address);
    void writeRTC(uint8_t address, uint8_t value);

}; //DS1302Rtc

#endif //__DS1302RTC_H__
