// **************************************************************
// **************************************************************
//
// **********  DO NOT MODIFY ANYTHING IN THIS SECTION
//
// solution cpp file for project 11
// all helper function definitions go in this file

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "P11.h"

using namespace std;

// **************************************************************
// **************************************************************
//
// **************************************************************
// **********   PUT ALL FUNCTION DEFINITIONS BELOW THIS COMMENT
//
// Function definitions start here. 

// ************** CONTRUCTORS **************

Date::Date() // default 
{
    month = 1;
    day = 1;
    year = 1900;
}

Date::Date(int initMonths, int initDays, int initYears) // parameterized
{
    day = initDays;
    month = initMonths;
    year = initYears;
}

// ************** TRANSFORMERS **************

void Date::SetDate(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}

// ************** OBSERVERS *******************

void Date:: WriteNumberFormat() const
{
    cout << setw(2) << setfill('0') << month << "/" << setw(2)
    << setfill('0') << day << "/" <<
    year << endl;
}

void Date::WriteNameFormat() const
{
    string monthName;
    switch(month)
    {
        case 1: monthName = "January";
            break;

        case 2: monthName = "February";
            break;
            
        case 3: monthName = "March";
            break;
            
        case 4: monthName = "April";
            break;
            
        case 5: monthName = "May";
            break;

        case 6: monthName = "June";
            break;
            
        case 7: monthName = "July";
            break;

        case 8: monthName = "August";
            break;

        case 9: monthName = "September";
            break;

        case 10: monthName = "October";
            break;

        case 11: monthName = "November";
            break;

        case 12: monthName = "December";
            break;
                                        
    }
    cout << monthName << " " << day << ", " << year << endl;
}

bool Date::SameDate(Date otherDate) const
{
    return (month == otherDate.month && day == otherDate.day &&
    year == otherDate.year);
}
