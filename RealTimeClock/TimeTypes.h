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

// Tomohiko Sakamoto algorithm
// From: http://c-faq.com/misc/zeller.html
int TSDayOfWeek(int y, int m, int d)	/* 0 = Sunday */
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
};

struct TElements {
    uint8_t Second;
	uint8_t Minute;
	uint8_t Hour;
	uint8_t Dow; // Day of week, Sunday is day 1
	uint8_t Day;
	uint8_t Month;
	uint8_t Year; // Offset from 1970

    // Gets a calendar year from the logical one in the structure
    int CalendarYear() { return START_YEAR + this->Year; };
    // Set a logical year from the calendar one to the structure
    void CalendarYear(int year) { this->Year = year - START_YEAR; };

    bool FromIsoDate(const char* isoDate)
    {
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;

        bool result = sscanf(isoDate, ISO_DATE_FORMAT, &year, &month, &day, &hour, &minute, &second) == ISO_DATE_PARTS;

        if (result)
        {
            this->CalendarYear(year);
            this->Month = month;
            this->Day = day;
            this->Hour = hour;
            this->Minute = minute;
            this->Second = second;
            this->Dow = TSDayOfWeek(year, month, day);
        }

        return result;
    }

    void ToIsoDate(char* isoDate)
    {
        int year = this->CalendarYear();
        int month = this->Month;
        int day = this->Day;
        int hour = this->Hour;
        int minute = this->Minute;
        int second = this->Second;

        sprintf(isoDate, ISO_DATE_FORMAT, year, month, day, hour, minute, second);
    }

} EmptyTElements = {0, 0, 0, 0, 0, 0, 0};

typedef uint32_t LongTime;

typedef union {
	TElements Elements;
	LongTime Time;
} TTime;

#endif /* TIMETYPES_H_ */