#pragma once


#include "Date.h"

class Period
{
    Date StartDate;
    Date EndDate;

    Period(Date StartDate, Date DateTo)
    {
        this->StartDate = StartDate;
        this->EndDate = EndDate;

    }

    static bool IsOverlapPeriods(Period Period1, Period Period2)
    {

        if (
            Date::CompareDates(Period2.EndDate, Period1.StartDate) == Date::enDateCompare::Before
            ||
            Date::CompareDates(Period2.StartDate, Period1.EndDate) == Date::enDateCompare::After
            )
            return false;
        else
            return true;

    }

    bool IsOverLapWith(Period Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }

    void Print()
    {
        cout << "Period Start: ";
        StartDate.Print();


        cout << "Period End: ";
        EndDate.Print();


    }

};

