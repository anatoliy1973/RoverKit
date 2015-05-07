/* 
* SimpleMotorDriver.h
*
* Created: 01/22/2015 11:21:15
* Author: Default
*/

#include <inttypes.h>
#include <limits.h>
#include "MotorDriverBase.h"
#include "ExtIO/PinManager.h"

using namespace ExtIO;

#ifndef __SIMPLEMOTORDRIVER_H__
#define __SIMPLEMOTORDRIVER_H__

// Provides a simple motor controller driver like Toshiba TB6612FNG
class SimpleMotorDriver : public MotorDriverBase
{
    //variables
    private:
        uint8_t m_pin1;
        uint8_t m_pin2;
        uint8_t m_pwmPin;

    //functions
    public:
        // Creates a new instance of the SimpleMotorDriver class.
        SimpleMotorDriver(uint8_t pin1, uint8_t pin2, uint8_t pwmPin);

    private:
        // Sets the motor power in percents
        virtual void SetThrottle(char speed);
        // Sets the motor to break mode
        virtual void SetBreak();

        void WritePins(uint8_t pin1Value, uint8_t pin2Value, uint8_t pwmPinValue);
}; //SimpleMotorDriver

#endif //__SIMPLEMOTORDRIVER_H__
