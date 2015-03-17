/* 
* CriticalSection.h
*
* Created: 09/21/2014 13:11:33
* Author: Default
*/


#ifndef __CRITICALSECTION_H__
#define __CRITICALSECTION_H__

#include "Platform.h"

class CriticalSection
{
//variables
private:
    unsigned char m_oldSREG;

//functions
public:
	CriticalSection();
    
    void Enter();
    void Exit();

}; //CriticalSection

#endif //__CRITICALSECTION_H__
