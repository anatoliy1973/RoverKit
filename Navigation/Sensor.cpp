/* 
* Sensor.cpp
*
* Created: 5/9/2015 13:42:44
* Author: Tolik
*/


#include "Sensor.h"

namespace Navigation
{

    // Initializes a new instance of the Sensor class
    //  pin: indicates a pin the sensor is connected to
    Sensor::Sensor(uint8_t pin)
    {
        this->m_pin = pin;
    } //Sensor

    // Gets the last sensor value
    int Sensor::get_Value()
    {
        return this->m_value;
    }

    // Gets the last read micros
    uint32_t Sensor::get_Micros()
    {
        return this->m_micros;
    }

    void Sensor::set_Baseline(int value)
    {
        this->m_baseline = value;
    }

    // Reads a value from sensor
    void Sensor::Read()
    {
        this->m_value = digitalRead(this->m_pin) - this->m_baseline;
        this->m_micros = micros();
    }

    void Sensor::Reset()
    {
        this->m_value = 0;
    }

}