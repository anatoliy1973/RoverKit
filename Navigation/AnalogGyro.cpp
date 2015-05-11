/* 
* AnalogGyro.cpp
*
* Created: 5/9/2015 15:47:35
* Author: Tolik
*/


#include "AnalogGyro.h"

#define TEST_NUM 10
#define TEST_DELAY 8

namespace Navigation
{

    AnalogGyro::AnalogGyro(uint8_t pinX, uint8_t pinY, uint8_t pinZ, float scale)
    {
        this->m_sensorX = new Sensor(pinX);
        this->m_sensorY = new Sensor(pinY);
        this->m_sensorZ = new Sensor(pinZ);
        this->m_scale = scale;

        this->Calibrate();

        Serial.println(m_baseLevel);
        Serial.println(m_noiseLevel);
    } //AnalogGyro

    void AnalogGyro::Update()
    {
        //TODO:
    }

    void AnalogGyro::GetSensorStats(Sensor* sensor, int* values)
    {
        for (uint8_t i = 0; i < TEST_NUM; i++)
        {
            sensor->Read();
            values[i] = sensor->get_Value();
            delay(TEST_DELAY);
        }
    }

    void AnalogGyro::AnalyzeStats(int* values, int* base, int* noise)
    {
        int sum = 0;
        for (uint8_t i = 0; i < TEST_NUM; i++)
        {
            sum += values[i];
        }

        int avg = sum / TEST_NUM;
        int dispersion = 0;

        for (uint8_t i = 0; i < TEST_NUM; i++)
        {
            dispersion = max(dispersion, abs(avg - values[i]));
        }

        *base = avg;
        *noise = dispersion;
    }

    void AnalogGyro::SetBaseline(int base1, int base2, int noise1, int noise2)
    {
        this->m_baseLevel = (base1 + base2 + 1) >> 1;
        this->m_noiseLevel = max(noise1, noise2);
    }

    void AnalogGyro::Calibrate()
    {
        int* values = new int[TEST_NUM];

        GetSensorStats(this->m_sensorX, values);
        int base1 = 0;
        int noise1 = 0;
        AnalyzeStats(values, &base1, &noise1);

        GetSensorStats(this->m_sensorY, values);
        int base2 = 0;
        int noise2 = 0;
        AnalyzeStats(values, &base2, &noise2);

        GetSensorStats(this->m_sensorZ, values);
        int base3 = 0;
        int noise3 = 0;
        AnalyzeStats(values, &base3, &noise3);

        int diff_1_2 = abs(base1 - base2);
        int diff_1_3 = abs(base1 - base3);
        int diff_2_3 = abs(base2 - base3);

        if (diff_1_2 <= diff_1_3 && diff_1_2 <= diff_2_3)
        {
            this->SetBaseline(base1, base2, noise1, noise2);
        }
        else if (diff_1_3 <= diff_1_2 && diff_1_3 <= diff_2_3)
        {
            this->SetBaseline(base1, base3, noise1, noise3);
        }
        else //if (diff_2_3 <= diff_1_2 && diff_2_3 <= diff_1_3)
        {
            this->SetBaseline(base2, base3, noise2, noise3);
        }
    }

}
