/* 
* Rtc.h
*
* Created: 3/15/2015 23:11:37
* Author: Tolik
*/


#ifndef __RTC_H__
#define __RTC_H__

#include "Platform\MultiPlatform.h"
#include "TimeTypes.h"

namespace RealTimeClock
{

    class Rtc
    {
    private:
        uint32_t m_lastMicros;
	    uint32_t m_threashold;
	    TTime m_time;
        uint16_t m_correction;

    //functions
    public:
	    Rtc(uint32_t threashold);

	    TTime get_Time();
        void set_Time(TTime& time);
        uint32_t get_Millis();
	
    protected:
        // Read the current time from the RTC and return it in a TTime structure.
	    virtual bool ReadTime(TTime& time)=0;
        // Set the RTC's time from a TTime structure.
        virtual bool WriteTime(TTime&)=0;

    private:
        void UpdateTime(uint32_t currentMicros);

    }; //Rtc

}
#endif //__RTC_H__
