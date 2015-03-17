/*
 * TimeTypes.h
 *
 * Created: 3/15/2015 23:24:51
 *  Author: Tolik
 */ 

#include <inttypes.h>

#ifndef TIMETYPES_H_
#define TIMETYPES_H_

typedef struct {
    uint8_t Second;
	uint8_t Minute;
	uint8_t Hour;
	uint8_t Dow; // Day of week, Sunday is day 1
	uint8_t Day;
	uint8_t Month;
	uint8_t Year; // Offset from 1970
} TElements;

typedef uint32_t  LongTime;

typedef union {
	TElements Elements;
	LongTime Time;
} TTime;

#endif /* TIMETYPES_H_ */