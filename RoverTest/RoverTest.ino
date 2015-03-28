/*
 * RoverTest.ino
 *
 * Created: 2/21/2015 22:54:23
 * Author: Tolik
 */ 

#include "MultiPlatform.h"
#include "Electric\SimpleMotorDriver.h"

SimpleMotorDriver *leftMotor = new SimpleMotorDriver(2, 4, 6);
SimpleMotorDriver *rigthMotor = new SimpleMotorDriver(7, 8, 9);

void setup()
{
    leftMotor->Break();
	rigthMotor->Break();
}

void loop()
{
    leftMotor->Throttle(100);
	rigthMotor->Throttle(100);
	delay(1500);

    leftMotor->Break();
    rigthMotor->Break();
	delay(1000);
		
	leftMotor->Throttle(-100);
	rigthMotor->Throttle(-100);
	delay(1500);

	leftMotor->Break();
	rigthMotor->Break();
	delay(1000);
}
