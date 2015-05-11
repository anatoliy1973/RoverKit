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
        // Default constructor
        LongVector();
        
        // Creates a vector with indicated coordinates
        LongVector(long x, long y, long z);

        // Creates a vector with equal coordinates
        LongVector(long val);

        // Copies a a copy of indicated vector
        LongVector(LongVector &c);

        long get_X();
        void set_X(long x);
        long get_Y();
        void set_Y(long y);
        long get_Z();
        void set_Z(long z);

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
            return new LongVector(x.m_x * y.m_x, x.m_y * y.m_y, x.m_z * y.m_z);
        }

        friend LongVector* operator * (const LongVector& x, long y)
        {
            return new LongVector(x.m_x * y, x.m_y * y, x.m_z * y);
        }

        friend LongVector* operator / (const LongVector& x, int y)
        {
            int halfY = y >> 1;
            return new LongVector((x.m_x + halfY) / y, (x.m_y + halfY)/ y, (x.m_z + halfY)/ y);
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

        // Returns a normalized vector
        long operator ! ();

}; //LongVector

#endif //__LONGVECTOR_H__
