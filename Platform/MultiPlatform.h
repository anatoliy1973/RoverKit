/*
 * MultiPlatform.h
 *
 * Created: 09/20/2014 11:31:45
 *  Author: Default
 */ 


#ifndef MULTI_PLATFORM_H_
#define MULTI_PLATFORM_H_

#if defined(ARDUINO)

#include "ArduinoPlatform.h"

#else

#ifdef __AVR__
#endif

#endif

#endif /* PLATFORM_H_ */