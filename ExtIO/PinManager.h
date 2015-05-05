/* 
* PinManager.h
*
* Created: 5/4/2015 16:23:12
* Author: Tolik
*/


#ifndef __PINMANAGER_H__
#define __PINMANAGER_H__

#include <inttypes.h>
#include "Platform/MultiPlatform.h"
#include "Extender.h"

namespace ExtIO
{

    //////////////////////////////////////////////////////////////////////////
    // Provides the way to increase a number IN/OUT pins
    //////////////////////////////////////////////////////////////////////////
    class PinManagerClass
    {
        //functions
        public:
            // Initializes PinManager
            //  startExtPin: indicates a number of first extension pin
            //  extenders: an array of hardware extenders
            //  extendersCount: indicates a number of hardware extenders (up to 8)
            static void Init(uint8_t startExtPin, Extender** extenders, uint8_t extendersCount);
            // Sets a mode of the indicated pin (1-based) if possible
            static void PinMode(uint8_t pin, uint8_t mode);
            // Returns an electric level on the indicated pin
            static uint8_t DigitalRead(uint8_t pin);
            // Sets an electric level on the indicated pin
            static void DigitalWrite(uint8_t pin, uint8_t val);

        private:
            static bool FindExtender(uint8_t* pin, Extender* extender);

    }; //PinManagerClass

    extern PinManagerClass PinManager;
}

#endif //__PINMANAGER_H__
