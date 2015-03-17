/* 
* SimpleMotorDriver.cpp
*
* Created: 01/22/2015 11:21:15
* Author: Default
*/

#include "SimpleMotorDriver.h"

const unsigned char MaxPercent = 100;

SimpleMotorDriver::SimpleMotorDriver(unsigned char pin1, unsigned char pin2, unsigned char pwmPin)
{
    this->m_pin1 = pin1;
    this->m_pin2 = pin2;
    this->m_pwmPin = pwmPin;
    
    pinMode(this->m_pin1, OUTPUT);
    pinMode(this->m_pin2, OUTPUT);
    pinMode(this->m_pwmPin, OUTPUT);
} //SimpleMotorDriver

void SimpleMotorDriver::SetThrottle(char speed)
{
	unsigned char pin1Value = speed > 0 ? HIGH : LOW;
	unsigned char pin2Value = speed < 0 ? HIGH : LOW;
	
	this->WritePins(pin1Value, pin2Value, abs(speed));
}

void SimpleMotorDriver::SetBreak()
{
	this->WritePins(HIGH, HIGH, 0);
}

void SimpleMotorDriver::WritePins(unsigned char pin1Value, unsigned char pin2Value, unsigned char pwmPinValue)
{
	if (pwmPinValue > MaxPercent)
	{
	    pwmPinValue = MaxPercent;	
	}
	
	digitalWrite(this->m_pin1, pin1Value);
	digitalWrite(this->m_pin2, pin2Value);
	analogWrite(this->m_pwmPin, map(pwmPinValue, CHAR_MIN, MaxPercent, this->get_VoltageLowMapping(), this->get_VoltageHighMapping()));
}
