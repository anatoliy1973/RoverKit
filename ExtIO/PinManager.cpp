/* 
* PinManager.cpp
*
* Created: 5/4/2015 16:23:11
* Author: Tolik
*/


#include "PinManager.h"
#include "binary.h"

namespace ExtIO
{

    // default constructor
    PinManagerClass::PinManagerClass()
    {
    } //PinManager

    void PinManagerClass::Init(uint8_t startExtPin, Extender** extenders, uint8_t extendersCount)
    {
        this->m_startExtPin = startExtPin;
        this->m_extenders = extenders;
        this->m_extendersCount = extendersCount;
    }

    void PinManagerClass::PinMode(uint8_t pin, uint8_t mode)
    {
        Extender* extender = NULL;
        if (this->FindExtender(&pin, extender))
        {
            if (pin > B00)
            {
                extender->PinMode(pin, mode);
            }
        }
        else
        {
            pinMode(pin, mode);
        }
    }

    uint8_t PinManagerClass::DigitalRead(uint8_t pin)
    {
        Extender* extender = NULL;
        if (this->FindExtender(&pin, extender))
        {
            if (pin > B00)
            {
                return extender->DigitalRead(pin);
            }
        }
        else
        {
            return digitalRead(pin);
        }

        return LOW;
    }

    void PinManagerClass::DigitalWrite(uint8_t pin, uint8_t val)
    {
        Extender* extender = NULL;
        if (this->FindExtender(&pin, extender))
        {
            if (pin > B00)
            {
                extender->DigitalWrite(pin, val);
            }
        }
        else
        {
            digitalWrite(pin, val);
        }
    }

    bool PinManagerClass::FindExtender(uint8_t* pin, Extender* extender)
    {
        if (*pin < this->m_startExtPin)
        {
            return false;
        }

        *pin -= this->m_startExtPin - 1;
        for (uint8_t i = 0; i < this->m_extendersCount; i++)
        {
            uint8_t extenderPins = this->m_extenders[i]->get_PinsCount();
            *pin -= extenderPins;
            if (*pin <= extenderPins)
            {
                extender = this->m_extenders[i];
                break;
            }
        }

        return true;
    }

}
