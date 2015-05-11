/* 
* ThreeAxisAccelerometer.cpp
*
* Created: 2/24/2015 22:22:30
* Author: Tolik
*/


#include "ThreeAxisAccelerometer.h"

namespace Navigation
{

    // default constructor
    ThreeAxisAccelerometer::ThreeAxisAccelerometer()
    {
        this->m_value = new LongVector();
    } //ThreeAxisAccelerometer

    LongVector& ThreeAxisAccelerometer::get_Value()
    {
        return *this->m_value;
    }

}
