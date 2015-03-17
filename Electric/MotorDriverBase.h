/* 
* MotorDriverBase.h
*
* Created: 01/22/2015 11:12:59
* Author: Default
*/


#ifndef __MOTORDRIVERBASE_H__
#define __MOTORDRIVERBASE_H__

#include "MultiPlatform.h"

// Provides an interface handling a motor
class MotorDriverBase
{
//variables
private:
    char m_currentSpeed;
	int m_voltageLowMapping;
	int m_voltageHighMapping;

//functions
public:
	// Creates a new instance of the MotorDriverBase class
    MotorDriverBase();
    
    // Gets a currently set motor power
    char get_CurrentSpeed();
    
    // Sets the motor power in percents
    void Throttle(char speed);
    // Sets the motor to break mode
    void Break();
	// Sets the voltage mappings - relative values indicating min and max voltage available motor
	void SetVoltageMapping(int low, int high);

protected:
    // Returns the value of m_voltageLowMapping field
	int get_VoltageLowMapping();
	// Returns the value of m_voltageHighMapping field
	int get_VoltageHighMapping();

private:
	MotorDriverBase( const MotorDriverBase &c );
	MotorDriverBase& operator=( const MotorDriverBase &c );
    
    // Sets the motor power in percents
    virtual void SetThrottle(char speed)=0;
    // Sets the motor to break mode
    virtual void SetBreak()=0;

}; //MotorDriverBase

#endif //__MOTORDRIVERBASE_H__
