/* 
* Extender.h
*
* Created: 5/4/2015 15:30:22
* Author: Tolik
*/


#ifndef __EXTENDER_H__
#define __EXTENDER_H__

namespace ExtIO
{

    class Extender
    {
    //functions
    public:
	    virtual ~Extender();
	    virtual void Method1()=0;//make Extender not instantiable
	    virtual void Method2();
	    void Method3();

    }; //Extender

}
#endif //__EXTENDER_H__
