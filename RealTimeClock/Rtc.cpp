/* 
* Rtc.cpp
*
* Created: 3/15/2015 23:11:36
* Author: Tolik
*/


#include "Rtc.h"

// functions

Rtc::Rtc(uint32_t threashold)
{
	this->m_threashold = threashold;
	this->m_lastMicros = 0;
}


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
}

void Rtc::UpdateTime(uint32_t currentMicros)
{
	this->m_lastMicros = currentMicros;
	this->ReadTime(this->m_time);
}

