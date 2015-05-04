/* 
* Extender.h
*
* Created: 5/4/2015 15:30:22
* Author: Tolik
*/


#ifndef __EXTENDER_H__
#define __EXTENDER_H__

#include <inttypes.h>

namespace ExtIO
{

    enum PinFLlags
    {
        Input = 1,
        Output = 2,
        Analog = 4,
        Pwm = 8
    };

    class Extender
    {
        //functions
        public:
            // Gets a number of pins provided by the extender
            virtual uint8_t get_PinsCount()=0;
            // Gets a flags indicating the pin possibilities
            virtual PinFLlags get_PinFlags(uint8_t pin)=0;

            // Sets a mode of the indicated pin (1-based) if possible
            virtual void PinMode(uint8_t pin, uint8_t mode)=0;
            // Returns an electric level on the indicated pin
            uint8_t DigitalRead(uint8_t pin);
            // Sets an electric level on the indicated pin
            void DigitalWrite(uint8_t pin, uint8_t val);

        protected:
            // Returns an electric level on the indicated pin
            virtual uint8_t DigitalReadInternal(uint8_t pin)=0;
            // Sets an electric level on the indicated pin
            virtual void DigitalWriteInternal(uint8_t pin, uint8_t val)=0;

    }; //Extender

}
#endif //__EXTENDER_H__
