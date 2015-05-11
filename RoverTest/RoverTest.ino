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
#include "Navigation\ThreeAxisGyro.h"
#include "Navigation\Sensor.h"
#include "Navigation\AnalogGyro.h"

#include <SPI\SPI.h>
#include <DS1302RTC.h>
#include <Time.h>                         //http://playground.arduino.cc/Code/Time

using namespace ExtIO;
using namespace Navigation;

#define STARTING_EXT_PIN 36
#define SS_EXTENDER 7
// Optional connection for RTC module
#define DS1302_GND_PIN 37
#define DS1302_VCC_PIN 36

// Set pins: CE, IO, CLK
DS1302RTC RTC(38, 8, 39);
Extender *outputExtender = new Extender74HC595(1, SS_EXTENDER);

SimpleMotorDriver *leftMotor = NULL;
SimpleMotorDriver *rigthMotor = NULL;
AnalogGyro* gyro = NULL;

int analogValue = 0;

void setup()
{
    Serial.begin(115200);
    SPI.begin();

    int v = 277;
    int nv = -277;

    Serial.print(v >> 2);
    Serial.println();

    Serial.print(nv >> 2);
    Serial.println();

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

    leftMotor = new SimpleMotorDriver(42, 43, 9);
    rigthMotor = new SimpleMotorDriver(41, 40, 10);

    leftMotor->Break();
    rigthMotor->Break();

    gyro = new AnalogGyro(A2, A3, A1, 1);
    gyro->Update();
}

void loop()
{
    static time_t tLast;
    time_t t;
    tmElements_t tm;

    uint32_t startMillis = millis();

    //check for input to set the RTC, minimum length is 12, i.e. yy,m,d,h,m,s
    if (Serial.available() >= 12)
    {
        //note that the tmElements_t Year member is an offset from 1970,
        //but the RTC wants the last two digits of the calendar year.
        //use the convenience macros from Time.h to do the conversions.
        int y = Serial.parseInt();
        if (y >= 100 && y < 1000)
            Serial.println("Error: Year must be two digits or four digits!");
        else
        {
            if (y >= 1000)
            tm.Year = CalendarYrToTm(y);
            else    //(y < 100)
            tm.Year = y2kYearToTm(y);
            tm.Month = Serial.parseInt();
            tm.Day = Serial.parseInt();
            tm.Hour = Serial.parseInt();
            tm.Minute = Serial.parseInt();
            tm.Second = Serial.parseInt();
            t = makeTime(tm);
            //use the time_t value to ensure correct weekday is set
            if(RTC.set(t) == 0)
            { // Success
                setTime(t);
                Serial.print("RTC set to: ");
                printDateTime(t);
                Serial.println();
            }
            else
                Serial.println("RTC set failed!");
            //dump any extraneous input
            while (Serial.available() > 0) Serial.read();
        }
    }

    t = now();
    if (t != tLast)
    {
        tLast = t;
        //printDateTime(t);
        //Serial.println();
    }

    int iv = analogRead(A0);
    if (abs(iv - analogValue) > 1)
    {
        Serial.println(iv);
        analogValue = iv;
    }

    uint32_t totalMillis = millis() - startMillis;

    if (totalMillis < 10)
    {
        delay(10 - totalMillis);
    }

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
