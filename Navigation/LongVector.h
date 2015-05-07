/* 
* IntVector.h
*
* Created: 2/24/2015 21:20:15
* Author: Tolik
*/

#include "Platform\MultiPlatform.h"
#include "Platform\Arithmetic.h"

#ifndef __LONGVECTOR_H__
#define __LONGVECTOR_H__


class LongVector
{
    //variables
    private:
        long m_x;
        long m_y;
        long m_z;

    //functions
    public:
        // Creates a vector with indicated coordinates
        LongVector(long x, long y, long z);

        // Creates a vector with equal coordinates
        LongVector(long val);

        // Copies a a copy of indicated vector
        LongVector(LongVector &c);

        inline long get_X() { return this->m_x; };
        inline long get_Y() { return this->m_y; };
        inline long get_Z() { return this->m_z; };

        LongVector& operator = (LongVector &c) { this->m_x = c.m_x; this->m_y = c.m_y; this->m_z = c.m_z; return *this; };
        LongVector& operator = (long l) { this->m_x = this->m_y = this->m_z = l; return *this; };
        LongVector* operator - () const;
        LongVector& operator += (const LongVector&);
        LongVector& operator -= (const LongVector&);
        LongVector& operator *= (const LongVector&);
        LongVector& operator *= (long);
        LongVector& operator /= (int);

        friend LongVector* operator + (const LongVector& x, const LongVector& y)
        {
            return new LongVector(x.m_x + y.m_x, x.m_y + y.m_y, x.m_z + y.m_z);
        }

        friend LongVector* operator - (const LongVector& x, const LongVector& y)
        {
            return new LongVector(x.m_x - y.m_x, x.m_y - y.m_y, x.m_z - y.m_z);
        }

        friend LongVector* operator * (const LongVector& x, const LongVector& y)
        {
            return new LongVector(Multiply(x.m_x, y.m_x), Multiply(x.m_y, y.m_y), Multiply(x.m_z, y.m_z));
        }

        friend LongVector* operator * (const LongVector& x, long y)
        {
            return new LongVector(x.m_x * y, x.m_y * y, x.m_z * y);
        }

        friend LongVector* operator / (const LongVector& x, int y)
        {
            return new LongVector(x.m_x / y, x.m_y / y, x.m_z / y);
        }

        friend long operator & (const LongVector& x, const LongVector& y)
        {
            return (x.m_x * y.m_y) + (x.m_y * y.m_y) + (x.m_z * y.m_z);
        }

        friend LongVector* operator ^ (const LongVector& u, const LongVector& v)
        {
            return new LongVector(
                (u.m_y * v.m_z) - (u.m_z * v.m_y),
                (u.m_z * v.m_x) - (u.m_x * v.m_z),
                (u.m_x * v.m_y) - (u.m_y * v.m_x));
        }

        long operator ! ();

}; //LongVector

#endif //__LONGVECTOR_H__
