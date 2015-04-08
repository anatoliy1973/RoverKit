/*
 * TimeTypes.cpp
 *
 * Created: 4/8/2015 22:45:12
 *  Author: Tolik
 */ 

#include "TimeTypes.h"

namespace RealTimeClock
{

    int TSDayOfWeek(int y, int m, int d) /* 0 = Sunday */
    {
        static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        y -= m < 3;
        return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
    }

    TElements EmptyTElements = {0, 0, 0, 0, 0, 0, 0};

    // TElements methods
    int TElements::CalendarYear()
    {
        return START_YEAR + this->Year;
    }

    void TElements::CalendarYear(int year)
    {
        this->Year = year - START_YEAR;
    }

    bool TElements::FromIsoDate(const char* isoDate)
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

    void TElements::ToIsoDate(char* isoDate)
    {
        int year = this->CalendarYear();
        int month = this->Month;
        int day = this->Day;
        int hour = this->Hour;
        int minute = this->Minute;
        int second = this->Second;

        sprintf(isoDate, ISO_DATE_FORMAT, year, month, day, hour, minute, second);
    }

}