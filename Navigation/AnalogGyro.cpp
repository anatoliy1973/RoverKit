/*
* AnalogGyro.cpp
*
* Created: 5/9/2015 15:47:35
* Author: Tolik
*/


#include "AnalogGyro.h"

namespace Navigation
{

    // Initializes a new instance of the AnalogGyro class
    //  pinX: indicates a pin the X sensor is connected to
    //  pinY: indicates a pin the Y sensor is connected to
    //  pinZ: indicates a pin the Z sensor is connected to
    //  threashold: indicates a # of microseconds between measurements
    //  scale: indicates a ratio of sensor value to radiant
    AnalogGyro::AnalogGyro(uint8_t pinX, uint8_t pinY, uint8_t pinZ, uint16_t threashold, float scale)
    {
        this->m_scale = scale;

        this->m_sensor = new ThreeAxisAnalogSensor(pinX, pinY, pinZ, threashold);
        this->m_sensor->Calibrate();

        this->m_lastUpdateMicros = micros();
    } //AnalogGyro

    // Updates the gyro's data
    void AnalogGyro::Update()
    {
        this->m_sensor->Read();
        uint32_t currentMicros = micros();
        uint32_t diff = ULONG_DIFF(currentMicros, this->m_lastUpdateMicros);

        if (diff > 0)
        {
            float fDiff = (float)diff;
            this->m_x += this->m_scale * (float)(this->m_sensor->get_ValueX()) * fDiff;
            this->m_y += this->m_scale * (float)(this->m_sensor->get_ValueY()) * fDiff;
            this->m_z += this->m_scale * (float)(this->m_sensor->get_ValueZ()) * fDiff;

            if (this->m_sensor->get_ValueZ() != 0)
            {
                Serial.println(this->m_sensor->get_ValueZ());
            }

            this->m_lastUpdateMicros = currentMicros;
        }
    }

}
