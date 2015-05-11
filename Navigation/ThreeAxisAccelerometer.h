/* 
* ThreeAxisAccelerometer.h
*
* Created: 2/24/2015 22:22:30
* Author: Tolik
*/


#ifndef __THREEAXISACCELEROMETER_H__
#define __THREEAXISACCELEROMETER_H__

#include "Platform/MultiPlatform.h"
#include "LongVector.h"

namespace Navigation
{

    class ThreeAxisAccelerometer
    {
        //variables
        private:
            LongVector* m_value;

        //functions
        public:
            ThreeAxisAccelerometer();

            LongVector& get_Value();
        protected:
        private:

    }; //ThreeAxisAccelerometer

}
#endif //__THREEAXISACCELEROMETER_H__
