/* 
* PinManager.cpp
*
* Created: 5/4/2015 16:23:11
* Author: Tolik
*/


#include "PinManager.h"
#include <binary.h>

namespace ExtIO
{

    //variables
    uint8_t PinManagerClass::m_startExtPin;
    Extender** PinManagerClass::m_extenders;
    uint8_t PinManagerClass::m_extendersCount;

    void PinManagerClass::Init(uint8_t startExtPin, Extender** extenders, uint8_t extendersCount)
    {
        m_startExtPin = startExtPin;
        m_extenders = extenders;
        m_extendersCount = extendersCount;
    }

    void PinManagerClass::PinMode(uint8_t pin, uint8_t mode)
    {
        Extender* extender = NULL;
        int ipin  = pin;
        if (FindExtender(&ipin, &extender))
        {
            if (ipin > B00)
            {
                extender->PinMode(ipin, mode);
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
        int ipin  = pin;
        if (FindExtender(&ipin, &extender))
        {
            if (ipin > B00)
            {
                return extender->DigitalRead(ipin);
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
        int ipin  = pin;
        if (FindExtender(&ipin, &extender))
        {
            if (ipin > B00)
            {
                extender->DigitalWrite(ipin, val);
            }
        }
        else
        {
            digitalWrite(pin, val);
        }
    }

    bool PinManagerClass::FindExtender(int* pin, Extender** extender)
    {
        if (*pin < m_startExtPin)
        {
            return false;
        }

        *pin -= m_startExtPin - 1;
        for (uint8_t i = 0; i < m_extendersCount; i++)
        {
            uint8_t extenderPins = m_extenders[i]->get_PinsCount();
            if (*pin <= extenderPins)
            {
                *extender = m_extenders[i];
                break;
            }

            *pin -= extenderPins;
        }

        return true;
    }

}
