/*
 * ArduinoPlatform.h
 *
 * Created: 09/20/2014 11:36:03
 *  Author: Default
 */ 


#ifndef ARDUINOPLATFORM_H_
#define ARDUINOPLATFORM_H_

#include "Arduino.h"
#include "C:\Program Files\Arduino\hardware\tools\avr\avr\include\avr\common.h"
#include "pins_arduino.h"

#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328p__)

#define SUPPLY_VOLTAGE 5000
#define ADC_GRADE 1024
#define PWM_GRADE 255

#endif

#endif /* ARDUINOPLATFORM_H_ */