/* 
* Extender74HC595.h
*
* Created: 5/4/2015 22:04:59
* Author: Tolik
*/


#ifndef __EXTENDER74HC595_H__
#define __EXTENDER74HC595_H__

#include "Extender.h"
#include <SPI/SPI.h>

namespace ExtIO
{

    class Extender74HC595 : public Extender
    {
        //variables
        private:
            uint8_t m_chipsCount;
            uint8_t* m_buffer;
            uint8_t m_ssPin;

        //functions
        public:
            // Initializes a new instance of Extender74HC595 class
            //  chipsCount: indicates a number of 74HC595 chips connected
            //  ssPin: indicates a Slave Select pin
            Extender74HC595(uint8_t chipsCount, uint8_t ssPin);

            // Gets a number of pins provided by the extender
            virtual uint8_t get_PinsCount();
            // Actually does nothing in this class
            virtual void PinMode(uint8_t pin, uint8_t mode);

        private:
            // Always returns OutputPin
            virtual PinFlags get_PinFlags(uint8_t pin);
            // Flashes internal buffer into the physical device
            virtual void Flash();
            // Returns an electric level on the indicated pin
            virtual uint8_t DigitalReadInternal(uint8_t pin);
            // Sets an electric level on the indicated pin
            virtual void DigitalWriteInternal(uint8_t pin, uint8_t val);

    }; //Extender74HC595

}

#endif //__EXTENDER74HC595_H__
