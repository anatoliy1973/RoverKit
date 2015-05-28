/* 
* ThreeAxisAnalogSensor.h
*
* Created: 5/24/2015 15:34:59
* Author: Tolik
*/


#ifndef __THREEAXISANALOGSENSOR_H__
#define __THREEAXISANALOGSENSOR_H__

#include "Platform/MultiPlatform.h"
#include "Platform/Arithmetic.h"
#include "Sensor.h"

namespace Navigation
{

    class ThreeAxisAnalogSensor
    {
        //variables
        private:
            Sensor* m_sensorX;
            Sensor* m_sensorY;
            Sensor* m_sensorZ;
            uint16_t m_threashold;
            uint8_t m_noiseLevel;

        //functions
        public:
            // Initializes a new instance of the ThreeAxisAnalogSensor class
            //  pinX: indicates a pin the X sensor is connected to
            //  pinY: indicates a pin the Y sensor is connected to
            //  pinZ: indicates a pin the Z sensor is connected to
            //  threashold: indicates a # of microseconds between measurements
            ThreeAxisAnalogSensor(uint8_t pinX, uint8_t pinY, uint8_t pinZ, uint16_t threashold);

            // Gets the X axis sensor last value
            int get_ValueX();
            // Gets the Y axis sensor last value
            int get_ValueY();
            // Gets the Z axis sensor last value
            int get_ValueZ();

            // Performs sensors auto-calibration
            void Calibrate();
            // Reads sensors
            void Read();
        private:
            // Performs sensor calibration
            //  returns: sensor's noise level
            uint8_t CalibrateSensor(Sensor* sensor);
            // Checks if the sensor can be read and if the sensor's value is greater than the detected noise level
            void TryReadSensor(Sensor* sensor);

    }; //ThreeAxisAnalogSensor

}
#endif //__THREEAXISANALOGSENSOR_H__
