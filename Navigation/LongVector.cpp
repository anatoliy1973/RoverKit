/* 
* IntVector.cpp
*
* Created: 2/24/2015 21:20:15
* Author: Tolik
*/


#include "LongVector.h"
#include <math.h>

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

LongVector& LongVector::operator /= (int val)
{
    this->m_x /= val;
    this->m_y /= val;
    this->m_z /= val;

    return *this;
}

long LongVector::operator!()
{
    return long(sqrt((this->m_x * this->m_x) + (this->m_y * this->m_y) + (this->m_z * this->m_z)));
}
