/* 
* DS1302Rtc.cpp
*
* Created: 3/28/2015 12:55:24
* Author: Tolik
*/

#include "DS1302Rtc.h"

namespace RealTimeClock
{

    #define DS1302_DATA_ACCESS_DELAY 4

    DS1302Rtc::DS1302Rtc(uint8_t dataPin, uint8_t cePin, uint8_t clkPin) : Rtc(DS1302_THREASHOLD)
    {
	    this->m_channel = new ThreeWire(dataPin, cePin, clkPin, DS1302_DATA_ACCESS_DELAY);
    }

    // Read the current time from the RTC and return it in a TTime structure.
    // Returns the bus status (true if successful).
    bool DS1302Rtc::ReadTime(TTime& time)
    {
        uint8_t buff[8];

        this->ReadRTC(buff);

        time.Elements.Second = Bcd2Dec(buff[0] & B01111111); // 7 bit (4L - sec, 3H - 10 sec), ignore CH bit
        time.Elements.Minute = Bcd2Dec(buff[1] & B01111111); // 7 bit (4L - min, 3H - 10 min), ignore NULL bit
        time.Elements.Hour = Bcd2Dec(buff[2] & B00111111);   // 6 bit (4L - hrs, 2H - 10 hrs), ignore NULL & 12/24 bits
        time.Elements.Day = Bcd2Dec(buff[3] & B00111111);    // 6 bit (4L - dat, 2H - 10 dat), ignore 2 NULLs
        time.Elements.Month = Bcd2Dec(buff[4] & B00011111);  // 5 bit (4L - mth, 1H - 10 mth), ignore 3 NULLs
        time.Elements.Dow = buff[5] & B00000111 ;            // 3 bit, ignore 5 NULLs
        time.Elements.Year = Bcd2Dec(buff[6]);               // 8 bit
	  
        // Validation
        if(time.Elements.Second >= 0 && time.Elements.Second <= 59)
        {
            if(time.Elements.Minute >= 0 && time.Elements.Minute <= 59)
            {
                if(time.Elements.Hour >= 0 && time.Elements.Hour <= 23)
                {
                    if(time.Elements.Day >= 1 && time.Elements.Day <= 31)
                    {
                        if(time.Elements.Month >= 1 && time.Elements.Month <= 12)
                        {
                            if(time.Elements.Dow >= 1 && time.Elements.Dow <= 7)
                            {
                                if(time.Elements.Year >= 0 && time.Elements.Year <= 99)
                                {
                                    return true;                   // Success
                                }
                            }
                        }
                    }
                }
            }
        }

        return false; // Error
    }

    // Set the RTC's time from a TTime structure.
    // Returns the bus status (true if successful).
    bool DS1302Rtc::WriteTime(TTime& time)
    {
        uint8_t buff[8];

        this->set_WriteEnabled(true);
  
        if(!this->get_WriteEnabled())
        {
            return false;                         // Error! Write-protect not disabled
        }

        buff[0] = Dec2Bcd(time.Elements.Second);
        buff[1] = Dec2Bcd(time.Elements.Minute);
        buff[2] = Dec2Bcd(time.Elements.Hour);    // 24-hour mode
        buff[3] = Dec2Bcd(time.Elements.Day);
        buff[4] = Dec2Bcd(time.Elements.Month);
        buff[5] = time.Elements.Dow;
        buff[6] = Dec2Bcd(time.Elements.Year);
        buff[7] = B10000000;                      // Write protect enable

        this->WriteRTC(buff);

        return this->get_WriteEnabled();
    }

    // Check Write-protect bit
    bool DS1302Rtc::get_WriteEnabled()
    {
        return !bitRead(this->ReadRTC(DS1302_ENABLE), DS1302_WP);
    }

    // Set or clear Write-protect bit
    // Before any write operation to the clock or RAM, must be 0.
    // When 1, the write-protect bit prevents a write operation
    // to any other register.
    void DS1302Rtc::set_WriteEnabled(bool value)
    {
        uint8_t wp = this->ReadRTC(DS1302_ENABLE);
        bitWrite(wp, DS1302_WP, !value);
        this->WriteRTC(DS1302_ENABLE, wp);
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
    uint8_t DS1302Rtc::ReadRTC(uint8_t address)
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
    void DS1302Rtc::WriteRTC(uint8_t address, uint8_t value)
    {
        // clear lowest bit (read bit) in address
        bitClear(address, DS1302_READ);

        this->m_channel->BeginReading();

        this->m_channel->Write(address);
        this->m_channel->Write(value);

        this->m_channel->EndReading();
    }

    // This function reads 8 bytes clock data in burst mode
    // from the DS1302.
    //
    // This function may be called as the first function,
    // also the pinMode is set.
    //
    void DS1302Rtc::ReadRTC(uint8_t *p)
    {
        this->m_channel->BeginReading();

        // Instead of the address,
        // the CLOCK_BURST_READ command is issued
        // the I/O-line is released for the data
        this->m_channel->Write(DS1302_CLOCK_BURST_READ);

        for (uint8_t i = 0; i < 8; i++)
        {
            *p++ = this->m_channel->Read();
        }

        this->m_channel->EndReading();
    }

    // This function writes 8 bytes clock data in burst mode
    // to the DS1302.
    //
    // This function may be called as the first function,
    // also the pinMode is set.
    //
    void DS1302Rtc::WriteRTC(uint8_t *p)
    {
        this->m_channel->BeginReading();

        // Instead of the address,
        // the CLOCK_BURST_WRITE command is issued.
        // the I/O-line is not released
        this->m_channel->Write(DS1302_CLOCK_BURST_WRITE);

        for (uint8_t i = 0; i < 8; i++)
        {
            this->m_channel->Write(*p++);
        }
  
        this->m_channel->EndReading();
    }

}