/* 
* DS1302Rtc.h
*
* Created: 3/28/2015 12:55:25
* Author: Tolik
*/


#ifndef __DS1302RTC_H__
#define __DS1302RTC_H__

#include "Platform\Arithmetic.h"
#include "ThreeWire\ThreeWire.h"
#include "Rtc.h"

// Defines for the bits, to be able to change
// between bit number and binary definition.
// By using the bit number, using the DS1302
// is like programming an AVR microcontroller.
// But instead of using "(1<<X)", or "_BV(X)",
// the Arduino "bit(X)" is used.
#define DS1302_D0 0
#define DS1302_D7 7

// Bit for reading (bit in address)
#define DS1302_READ DS1302_D0 // READ=1, WRITE=0

#define DS1302_THREASHOLD 1000

// Enable Write Protect Register
#define DS1302_WP       DS1302_D7 // 1 = Write Protect, 0 = enabled

// Register names.
// Since the highest bit is always '1',
// the registers start at 0x80
// If the register is read, the lowest bit should be '1'.
#define DS1302_ENABLE            0x8E
#define DS1302_CLOCK_BURST_WRITE 0xBE
#define DS1302_CLOCK_BURST_READ  0xBF

class DS1302Rtc : public Rtc
{
//variables
private:
    ThreeWire* m_channel;

//functions
public:
	DS1302Rtc(uint8_t dataPin, uint8_t cePin, uint8_t clkPin);

protected:
    // Read the current time from the RTC and return it in a TTime structure.
    virtual bool ReadTime(TTime& time);
    // Set the RTC's time from a TTime structure.
    virtual bool WriteTime(TTime& time);
	
private:
	DS1302Rtc( const DS1302Rtc &c );
	DS1302Rtc& operator=( const DS1302Rtc &c );

    // Check Write-protect bit
    bool get_WriteEnabled();
    // Set or clear Write-protect bit
    void set_WriteEnabled(bool value);

    uint8_t ReadRTC(uint8_t address);
    void WriteRTC(uint8_t address, uint8_t value);
    void ReadRTC(uint8_t *p);
    void WriteRTC(uint8_t *p);

}; //DS1302Rtc

#endif //__DS1302RTC_H__
