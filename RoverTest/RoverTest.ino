/*
 * RoverTest.ino
 *
 * Created: 2/21/2015 22:54:23
 * Author: Tolik
 */ 

#include "Platform\MultiPlatform.h"
#include "ExtIO\PinManager.h"
#include "ExtIO\Extender.h"
#include "ExtIO\Extender74HC595.h"
#include "Electric\SimpleMotorDriver.h"

#include <SPI\SPI.h>
#include <DS1302RTC.h>
#include <Time.h>                         //http://playground.arduino.cc/Code/Time

using namespace ExtIO;

#define STARTING_EXT_PIN 36
#define SS_EXTENDER 9
// Optional connection for RTC module
#define DS1302_GND_PIN 37
#define DS1302_VCC_PIN 36

// Set pins: CE, IO, CLK
DS1302RTC RTC(38, 8, 39);
Extender *outputExtender = new Extender74HC595(1, SS_EXTENDER);

/*SimpleMotorDriver *leftMotor = new SimpleMotorDriver(2, 4, 6);
SimpleMotorDriver *rigthMotor = new SimpleMotorDriver(7, 8, 9);*/

void setup()
{
    Serial.begin(115200);
    SPI.begin();

    Extender** extenders = new Extender*[1];
    extenders[0] = (Extender*)outputExtender;

    PinManager.Init(STARTING_EXT_PIN, extenders, 1);

    // Activate RTC module
    PinManager.PinMode(DS1302_GND_PIN, OUTPUT);
    PinManager.DigitalWrite(DS1302_GND_PIN, LOW);

    PinManager.PinMode(DS1302_VCC_PIN, OUTPUT);
    PinManager.DigitalWrite(DS1302_VCC_PIN, HIGH);

    delay(500);

    RTC.haltRTC();
    delay(5000);

    //setSyncProvider() causes the Time library to synchronize with the
    //external RTC by calling RTC.get() every five minutes by default.
    setSyncProvider(RTC.get);

    Serial.print("RTC Sync");
    if (timeStatus() == timeSet)
    {
        Serial.println(" Ok!");
    }
    else
    {
        Serial.println(" FAIL!");
    }

    /*leftMotor->Break();
    rigthMotor->Break();*/
}

void loop()
{
    static time_t tLast;
    time_t t;

    t = now();
    if (t != tLast) {
        tLast = t;
        printDateTime(t);
        Serial.println();
    }

    Serial.flush();

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
}

//print date and time to Serial
void printDateTime(time_t t)
{
    printDate(t);
    Serial.print(' ');
    printTime(t);
}

//print time to Serial
void printTime(time_t t)
{
    printI00(hour(t), ':');
    printI00(minute(t), ':');
    printI00(second(t), ' ');
}

//print date to Serial
void printDate(time_t t)
{
    Serial.print(year(t));
    Serial.print('-');
    printI00(month(t), '-');
    printI00(day(t), ' ');
}

//Print an integer in "00" format (with leading zero),
//followed by a delimiter character to Serial.
//Input value assumed to be between 0 and 99.
void printI00(int val, char delim)
{
    if (val < 10)
    {
        Serial.print('0');
    }

    Serial.print(val);
    if (delim > 0)
    {
        Serial.print(delim);
    }
}
