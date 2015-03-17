/* 
* MotorDriverBase.cpp
*
* Created: 01/22/2015 11:12:59
* Author: Default
*/


#include "MotorDriverBase.h"

#define VOLTAGE_LOW_GRADE PWM_GRADE *20 / 100

// default constructor
MotorDriverBase::MotorDriverBase()
{
    this->m_currentSpeed = 0;
	this->SetVoltageMapping(VOLTAGE_LOW_GRADE, PWM_GRADE);
} //MotorDriverBase

char MotorDriverBase::get_CurrentSpeed()
{
	return this->m_currentSpeed;
}

void MotorDriverBase::Throttle(char speed)
{
	this->SetThrottle(speed);
    this->m_currentSpeed = speed;
}

void MotorDriverBase::Break()
{
	this->Throttle(0);
    this->SetBreak();
}

void MotorDriverBase::SetVoltageMapping(int low, int high)
{
	this->m_voltageLowMapping = low;
	this->m_voltageHighMapping = high;
}

int MotorDriverBase::get_VoltageLowMapping()
{
	return this->m_voltageLowMapping;
}

int MotorDriverBase::get_VoltageHighMapping()
{
	return this->m_voltageHighMapping;
}
