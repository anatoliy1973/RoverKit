/* 
* Extender74HC595.cpp
*
* Created: 5/4/2015 22:04:59
* Author: Tolik
*/

#include "Extender74HC595.h"

#define PINS_PER_CHIP 8

namespace ExtIO
{

    // default constructor
    Extender74HC595::Extender74HC595(uint8_t chipsCount, uint8_t ssPin)
    {
        this->m_chipsCount = chipsCount;
        this->m_buffer = new uint8_t[chipsCount];
        this->m_ssPin = ssPin;
        pinMode(this->m_ssPin, OUTPUT);
        digitalWrite(this->m_ssPin, HIGH);
    } //Extender74HC595

    uint8_t Extender74HC595::get_PinsCount()
    {
        return this->m_chipsCount * PINS_PER_CHIP;
    }

    void Extender74HC595::PinMode(uint8_t pin, uint8_t mode)
    {
        // Does nothing
    }

    PinFlags Extender74HC595::get_PinFlags(uint8_t pin)
    {
        return OutputPin;
    }

    void Extender74HC595::Flash()
    {
        digitalWrite(this->m_ssPin, LOW);
        for (uint8_t i = 0; i < this->m_chipsCount; i++)
        {
            SPI.transfer(this->m_buffer[i]);
        }

        digitalWrite(this->m_ssPin, HIGH);
    }

    uint8_t Extender74HC595::DigitalReadInternal(uint8_t pin)
    {
        return 0;
    }

    void Extender74HC595::DigitalWriteInternal(uint8_t pin, uint8_t val)
    {
        if (pin <= this->get_PinsCount())
        {
            pin--;
            bitWrite(this->m_buffer[pin >> 3], pin & B111, val);
        }
    }

}
