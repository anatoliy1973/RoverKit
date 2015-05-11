/* 
* IntVector.cpp
*
* Created: 2/24/2015 21:20:15
* Author: Tolik
*/


#include "LongVector.h"
#include <math.h>

LongVector::LongVector() : m_x(0), m_y(0), m_z(0)
{
}

LongVector::LongVector(long x, long y, long z)
{
    this->m_x = x;
    this->m_y = y;
    this->m_z = z;
} //IntVector

LongVector::LongVector(long val)
{
    this->m_x = this->m_y = this->m_z = val;
}

LongVector::LongVector(LongVector &v)
{
    this->m_x = v.m_x;
    this->m_y = v.m_x;
    this->m_z = v.m_z;
}

long LongVector::get_X()
{
    return this->m_x;
}

void LongVector::set_X(long x)
{
    this->m_x = x;
}

long LongVector::get_Y()
{
    return this->m_y;
}

void LongVector::set_Y(long y)
{
    this->m_y = y;
}

long LongVector::get_Z()
{
    return this->m_z;
}

void LongVector::set_Z(long z)
{
    this->m_z = z;
}

LongVector* LongVector::operator - () const
{
    return new LongVector(-this->m_x, -this->m_y, -this->m_z);
}

LongVector& LongVector::operator += (const LongVector& v)
{
    this->m_x += v.m_x;
    this->m_y += v.m_y;
    this->m_z += v.m_z;

    return *this;
}

LongVector& LongVector::operator -= (const LongVector& v)
{
    this->m_x -= v.m_x;
    this->m_y -= v.m_y;
    this->m_z -= v.m_z;

    return *this;
}

LongVector& LongVector::operator *= (const LongVector& v)
{
    this->m_x = this->m_x * v.m_x;
    this->m_y = this->m_y * v.m_y;
    this->m_z = this->m_z * v.m_z;

    return *this;
}

LongVector& LongVector::operator *= (long val)
{
    this->m_x = this->m_x * val;
    this->m_y = this->m_y * val;
    this->m_z = this->m_z * val;

    return *this;
}

LongVector& LongVector::operator /= (int y)
{
    int halfY = y >> 1;
    this->m_x = (this->m_x + halfY) / y;
    this->m_y = (this->m_y + halfY) / y;
    this->m_z = (this->m_z + halfY) / y;

    return *this;
}

long LongVector::operator!()
{
    return long(sqrt((this->m_x * this->m_x) + (this->m_y * this->m_y) + (this->m_z * this->m_z)));
}
