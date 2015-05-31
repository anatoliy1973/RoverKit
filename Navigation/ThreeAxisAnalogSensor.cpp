/*
* ThreeAxisAnalogSensor.cpp
*
* Created: 5/24/2015 15:34:59
* Author: Tolik
*/


#include "ThreeAxisAnalogSensor.h"

#define TEST_NUM 20

namespace Navigation
{

    // Initializes a new instance of the ThreeAxisAnalogSensor class
    //  pinX: indicates a pin the X sensor is connected to
    //  pinY: indicates a pin the Y sensor is connected to
    //  pinZ: indicates a pin the Z sensor is connected to
    //  threashold: indicates a # of microseconds between measurements
    ThreeAxisAnalogSensor::ThreeAxisAnalogSensor(uint8_t pinX, uint8_t pinY, uint8_t pinZ, uint16_t threashold)
    {
        this->m_sensorX = new Sensor(pinX);
        this->m_sensorY = new Sensor(pinY);
        this->m_sensorZ = new Sensor(pinZ);
        this->m_threashold = threashold;
    } //ThreeAxisAnalogSensor

    int ThreeAxisAnalogSensor::get_ValueX()
    {
        return this->m_sensorX->get_Value();
    }

    int ThreeAxisAnalogSensor::get_ValueY()
    {
        return this->m_sensorY->get_Value();
    }

    int ThreeAxisAnalogSensor::get_ValueZ()
    {
        return this->m_sensorZ->get_Value();
    }

    void ThreeAxisAnalogSensor::Calibrate()
    {
        uint8_t noiseX = this->CalibrateSensor(this->m_sensorX);
        uint8_t noiseY = this->CalibrateSensor(this->m_sensorY);
        uint8_t noiseZ = this->CalibrateSensor(this->m_sensorZ);
        this->m_noiseLevel = max(noiseX, max(noiseY, noiseZ));
    }

    void ThreeAxisAnalogSensor::Read()
    {
        this->TryReadSensor(this->m_sensorX);
        this->TryReadSensor(this->m_sensorY);
        this->TryReadSensor(this->m_sensorZ);
    }

    uint8_t ThreeAxisAnalogSensor::CalibrateSensor(Sensor* sensor)
    {
        uint8_t result = 0;
        int data[TEST_NUM];

        sensor->set_Baseline(0);
        long test = 0;

        for (uint8_t i = 0; i < TEST_NUM; i++)
        {
            delayMicroseconds(this->m_threashold);
            sensor->Read();
            data[i] = sensor->get_Value();
            test += data[i];
        }

        int baseline = (int)(test + (TEST_NUM >> 1)) / TEST_NUM;
        sensor->set_Baseline(baseline);

        for (uint8_t i = 0; i < TEST_NUM; i++)
        {
            result = max(result, abs(data[i] - baseline));
        }

        return result;
    }

    void ThreeAxisAnalogSensor::TryReadSensor(Sensor* sensor)
    {
        uint32_t currentMicros = micros();
        if (ULONG_DIFF(currentMicros, sensor->get_Micros()) >= this->m_threashold)
        {
            sensor->Read();
            if (abs(sensor->get_Value()) <= this->m_noiseLevel)
            {
                sensor->Reset();
            }
        }
    }

}
