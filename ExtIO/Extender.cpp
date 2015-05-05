/* 
* Extender.cpp
*
* Created: 5/4/2015 15:30:21
* Author: Tolik
*/


#include "Extender.h"

namespace ExtIO
{

    uint8_t Extender::DigitalRead(uint8_t pin)
    {
        if ((this->get_PinFlags(pin) & InputPin) == InputPin)
        {
            this->Flash();
            return this->DigitalReadInternal(pin);
        }

        return 0;
    }

    void Extender::DigitalWrite(uint8_t pin, uint8_t val)
    {
        if ((this->get_PinFlags(pin) & OutputPin) == OutputPin)
        {
            this->DigitalWriteInternal(pin, val);
            this->Flash();
        }
    }

}