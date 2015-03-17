/* 
* SimpleMotorDriver.h
*
* Created: 01/22/2015 11:21:15
* Author: Default
*/

#include <limits.h>
#include "MotorDriverBase.h"

#ifndef __SIMPLEMOTORDRIVER_H__
#define __SIMPLEMOTORDRIVER_H__

// Provides a simple motor controller driver like Toshiba TB6612FNG
class SimpleMotorDriver : public MotorDriverBase
{
//variables
private:
    unsigned char m_pin1;
    unsigned char m_pin2;
    unsigned char m_pwmPin;

//functions
public:
	// Creates a new instance of the SimpleMotorDriver class.
    SimpleMotorDriver(unsigned char pin1, unsigned char pin2, unsigned char pwmPin);

private:
	SimpleMotorDriver( const SimpleMotorDriver &c );
	SimpleMotorDriver& operator=( const SimpleMotorDriver &c );

    
    // Sets the motor power in percents
    virtual void SetThrottle(char speed);
    // Sets the motor to break mode
    virtual void SetBreak();

    void WritePins(unsigned char pin1Value, unsigned char pin2Value, unsigned char pwmPinValue);
}; //SimpleMotorDriver

#endif //__SIMPLEMOTORDRIVER_H__
