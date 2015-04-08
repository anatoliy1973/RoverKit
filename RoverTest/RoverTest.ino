/*
 * RoverTest.ino
 *
 * Created: 2/21/2015 22:54:23
 * Author: Tolik
 */ 

#include "Platform\MultiPlatform.h"
#include "Electric\SimpleMotorDriver.h"
#include "RealTimeClock\TimeTypes.h"
//#include "RealTimeClock\DS1302Rtc.h"

using namespace RealTimeClock;

SimpleMotorDriver *leftMotor = new SimpleMotorDriver(2, 4, 6);
SimpleMotorDriver *rigthMotor = new SimpleMotorDriver(7, 8, 9);
//DS1302Rtc *rtc = new DS1302Rtc(A6, A5, A7);
char isoDate[20] = "0123456789012345678";

void setup()
{
    delay(1000);
    Serial.begin(115200);

    TElements time = EmptyTElements;

    while (!Serial.available())
    {
        delay(1);
    }

    String date = Serial.readString();

    time.FromIsoDate(date.c_str());

    time.ToIsoDate(isoDate);

    Serial.println();
    Serial.println(isoDate);

    //leftMotor->Break();
	//rigthMotor->Break();
}

void loop()
{
    //leftMotor->Throttle(100);
	//rigthMotor->Throttle(100);
	//delay(1500);
//
    //leftMotor->Break();
    //rigthMotor->Break();
	//delay(1000);
		//
	//leftMotor->Throttle(-100);
	//rigthMotor->Throttle(-100);
	//delay(1500);
//
	//leftMotor->Break();
	//rigthMotor->Break();
	delay(1000);
}
