/* 
* Rtc.cpp
*
* Created: 3/15/2015 23:11:36
* Author: Tolik
*/


#include "Rtc.h"

namespace RealTimeClock
{
// functions

    Rtc::Rtc(uint32_t threashold)
    {
	    this->m_threashold = threashold;
	    this->m_lastMicros = 0;
        this->m_correction = (uint16_t)(1000UL - (millis() % 1000UL));
    };


    TTime Rtc::get_Time()
    {
	    uint32_t currentMicros = micros();
	
	
	    if (this->m_lastMicros == 0)
	    {
		    this->UpdateTime(currentMicros);
	    }
	    else if (currentMicros < this->m_lastMicros)
	    {
		    if (((this->m_lastMicros - currentMicros + 1) ^ 0xFFFFFFFF) >= this->m_threashold)
		    {
			    this->UpdateTime(currentMicros);
		    }
	    }
	    else if (currentMicros - this->m_lastMicros >= this->m_threashold)
	    {
		    this->UpdateTime(currentMicros);
	    }
	
	    return this->m_time;
    };

    void Rtc::set_Time(TTime& time)
    {
	    if (this->WriteTime(time))
        {
            this->UpdateTime(micros());
        }
    };

    uint32_t Rtc::get_Millis()
    {
	    return (millis() + this->m_correction) % 1000UL;
    };

    void Rtc::UpdateTime(uint32_t currentMicros)
    {
	    this->m_lastMicros = currentMicros;
	    this->ReadTime(this->m_time);
    };

}