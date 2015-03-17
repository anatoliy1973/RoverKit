/* 
* CriticalSection.cpp
*
* Created: 09/21/2014 13:11:33
* Author: Default
*/


#include "CriticalSection.h"

// default constructor
CriticalSection::CriticalSection()
{
    this->m_oldSREG = 0;
} //CriticalSection

void CriticalSection::Enter()
{
	this->m_oldSREG = SREG;
    noInterrupts();
}

void CriticalSection::Exit()
{
	SREG = this->m_oldSREG;
}

