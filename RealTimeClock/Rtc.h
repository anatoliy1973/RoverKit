/* 
* Rtc.h
*
* Created: 3/15/2015 23:11:37
* Author: Tolik
*/


#ifndef __RTC_H__
#define __RTC_H__

#include "MultiPlatform.h"
#include "TimeTypes.h"
#include <stdint-gcc.h>

class Rtc
{
private:
    uint32_t m_lastMicros;
	uint32_t m_threashold;
	TTime m_time;

//functions
public:
	Rtc(uint32_t threashold);
	TTime get_Time();
	
protected:
	virtual bool ReadTime(TTime& time)=0;
    // Set the RTC's time from a tmElements_t structure.
    virtual bool WriteTime(TTime&)=0;

private:
    void UpdateTime(uint32_t currentMicros);

}; //Rtc

#endif //__RTC_H__
