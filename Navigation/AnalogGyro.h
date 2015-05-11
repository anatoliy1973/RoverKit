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

namespace Navigation
{

    class AnalogGyro : public ThreeAxisGyro
    {
        //variables
        private:
            Sensor* m_sensorX;
            Sensor* m_sensorY;
            Sensor* m_sensorZ;
            float m_scale;
            int m_baseLevel;
            int m_noiseLevel;

        //functions
        public:
            AnalogGyro(uint8_t pinX, uint8_t pinY, uint8_t pinZ, float scale);

            virtual void Update();

        private:
            static void GetSensorStats(Sensor* sensor, int* values);
            static void AnalyzeStats(int* values, int* base1, int* noise1);
            void SetBaseline(int base1, int base2, int noise1, int noise2);
            void Calibrate();
    }; //AnalogGyro

}

#endif //__ANALOGGYRO_H__
