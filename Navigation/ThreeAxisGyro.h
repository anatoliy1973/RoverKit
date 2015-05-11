/* 
* ThreeAxisGyro.h
*
* Created: 5/9/2015 15:32:16
* Author: Tolik
*/


#ifndef __THREEAXISGYRO_H__
#define __THREEAXISGYRO_H__

namespace Navigation
{

    class ThreeAxisGyro
    {
    //variables
    private:
        float m_x;
        float m_y;
        float m_z;

    //functions
    public:
        ThreeAxisGyro();

        // Gets a rotation around X axis in radians
        float get_X();
        // Gets a rotation around Y axis in radians
        float get_Y();
        // Gets a rotation around Z axis in radians
        float get_Z();

        virtual void Update()=0;

    }; //ThreeAxisGyro

}

#endif //__THREEAXISGYRO_H__
