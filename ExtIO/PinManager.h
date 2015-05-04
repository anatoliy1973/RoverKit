/* 
* PinManager.h
*
* Created: 5/4/2015 16:23:12
* Author: Tolik
*/


#ifndef __PINMANAGER_H__
#define __PINMANAGER_H__

#include <inttypes.h>
#include "MultiPlatform.h"
#include "Extender.h"

namespace ExtIO
{

    class PinManagerClass
    {
        //variables
        private:
            uint8_t m_startExtPin;
            Extender** m_extenders;
            uint8_t m_extendersCount;

        //functions
        public:
            PinManagerClass();

            // Initializes an instance of PinManager
            void Init(uint8_t startExtPin, Extender** extenders, uint8_t extendersCount);
            // Sets a mode of the indicated pin (1-based) if possible
            void PinMode(uint8_t pin, uint8_t mode);
            // Returns an electric level on the indicated pin
            uint8_t DigitalRead(uint8_t pin);
            // Sets an electric level on the indicated pin
            void DigitalWrite(uint8_t pin, uint8_t val);

        private:
            PinManagerClass(const PinManagerClass &c);
            PinManagerClass& operator=(const PinManagerClass &c);

            bool FindExtender(uint8_t* pin, Extender* extender);

    }; //PinManagerClass

    extern PinManagerClass PinManager;
}

#endif //__PINMANAGER_H__
