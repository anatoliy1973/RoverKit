/* 
* AnalogGyro.h
*
* Created: 5/9/2015 15:47:36
* Author: Tolik
*/


#ifndef __ANALOGGYRO_H__
#define __ANALOGGYRO_H__

#include <inttypes.h>
#include "Platform/MultiPlatform.h"
#include "ThreeAxisGyro.h"
#include "Sensor.h"
#include "ThreeAxisAnalogSensor.h"

namespace Navigation
{

    class AnalogGyro : public ThreeAxisGyro
    {
        //variables
        private:
            ThreeAxisAnalogSensor* m_sensor;
            float m_scale;
            uint32_t m_lastUpdateMicros;

        //functions
        public:
            // Initializes a new instance of the AnalogGyro class
            //  pinX: indicates a pin the X sensor is connected to
            //  pinY: indicates a pin the Y sensor is connected to
            //  pinZ: indicates a pin the Z sensor is connected to
            //  threashold: indicates a # of microseconds between measurements
            //  scale: indicates a ratio of sensor value to radiant
            AnalogGyro(uint8_t pinX, uint8_t pinY, uint8_t pinZ, uint16_t threashold, float scale);

            // Updates the gyro's data
            virtual void Update();

        private:

    }; //AnalogGyro

}

#endif //__ANALOGGYRO_H__
