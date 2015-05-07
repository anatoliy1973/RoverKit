/* 
* SimpleMotorDriver.cpp
*
* Created: 01/22/2015 11:21:15
* Author: Default
*/

#include "SimpleMotorDriver.h"

#define MAX_PERCENT 100

SimpleMotorDriver::SimpleMotorDriver(uint8_t pin1, uint8_t pin2, uint8_t pwmPin)
{
    this->m_pin1 = pin1;
    this->m_pin2 = pin2;
    this->m_pwmPin = pwmPin;
    
    PinManager.PinMode(this->m_pin1, OUTPUT);
    PinManager.PinMode(this->m_pin2, OUTPUT);
    PinManager.PinMode(this->m_pwmPin, OUTPUT);
} //SimpleMotorDriver

void SimpleMotorDriver::SetThrottle(char speed)
{
    uint8_t pin1Value = speed > 0 ? HIGH : LOW;
    uint8_t pin2Value = speed < 0 ? HIGH : LOW;

    this->WritePins(pin1Value, pin2Value, abs(speed));
}

void SimpleMotorDriver::SetBreak()
{
    this->WritePins(HIGH, HIGH, 0);
}

void SimpleMotorDriver::WritePins(uint8_t pin1Value, uint8_t pin2Value, uint8_t pwmPinValue)
{
    if (pwmPinValue > MAX_PERCENT)
    {
        pwmPinValue = MAX_PERCENT;
    }

    PinManager.DigitalWrite(this->m_pin1, pin1Value);
    PinManager.DigitalWrite(this->m_pin2, pin2Value);
    analogWrite(this->m_pwmPin, map(pwmPinValue, CHAR_MIN, MAX_PERCENT, this->get_VoltageLowMapping(), this->get_VoltageHighMapping()));
}
