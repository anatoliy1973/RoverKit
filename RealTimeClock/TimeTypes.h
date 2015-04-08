/*
 * TimeTypes.h
 *
 * Created: 3/15/2015 23:24:51
 *  Author: Tolik
 */ 

#ifndef TIMETYPES_H_
#define TIMETYPES_H_

#include <inttypes.h>
#include <stdio.h>

#define START_YEAR 1970
#define ISO_DATE_FORMAT "%04d-%02d-%02dT%02d:%02d:%02d"
#define ISO_DATE_PARTS 6

namespace RealTimeClock
{

    // Tomohiko Sakamoto algorithm
    // From: http://c-faq.com/misc/zeller.html
    int TSDayOfWeek(int y, int m, int d)	/* 0 = Sunday */;

    struct TElements {
        uint8_t Second;
	    uint8_t Minute;
	    uint8_t Hour;
	    uint8_t Dow; // Day of week, Sunday is day 1
	    uint8_t Day;
	    uint8_t Month;
	    uint8_t Year; // Offset from 1970

        // Gets a calendar year from the logical one in the structure
        int CalendarYear();
        // Set a logical year from the calendar one to the structure
        void CalendarYear(int year);

        bool FromIsoDate(const char* isoDate);

        void ToIsoDate(char* isoDate);
    };
    
    extern TElements EmptyTElements;

    typedef uint32_t LongTime;

    union TTime {
	    TElements Elements;
	    LongTime Time;
    };

};
#endif /* TIMETYPES_H_ */