/* 
* ThreeAxisGyro.cpp
*
* Created: 5/9/2015 15:32:15
* Author: Tolik
*/


#include "ThreeAxisGyro.h"

namespace Navigation
{

    // default constructor
    ThreeAxisGyro::ThreeAxisGyro() : m_x(0), m_y(0), m_z(0)
    {
    } //ThreeAxisGyro

    // Gets a rotation around X axis in radians
    float ThreeAxisGyro::get_X()
    {
        return this->m_x;
    }

    // Gets a rotation around Y axis in radians
    float ThreeAxisGyro::get_Y()
    {
        return this->m_y;
    }

    // Gets a rotation around Z axis in radians
    float ThreeAxisGyro::get_Z()
    {
        return this->m_z;
    }

}
