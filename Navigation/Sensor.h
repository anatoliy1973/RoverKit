/* 
* Sensor.h
*
* Created: 5/9/2015 13:42:46
* Author: Tolik
*/


#ifndef __SENSOR_H__
#define __SENSOR_H__

#include "Platform/MultiPlatform.h"

namespace Navigation
{

    class Sensor
    {
        //variables
        private:
            uint8_t m_pin;
            int m_value;
            int m_baseline;
            uint32_t m_micros;

        //functions
        public:
            // Initializes a new instance of the Sensor class
            //  pin: indicates a pin the sensor is connected to
            Sensor(uint8_t pin);

            // Gets the last sensor value
            int get_Value();
            // Gets the last read micros
            uint32_t get_Micros();
            // Sets the baseline
            void set_Baseline(int value);

            // Reads a value from sensor
            void Read();
            // Sets the value to 0
            void Reset();

    }; //Sensor

}
#endif //__SENSOR_H__
