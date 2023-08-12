/*
* File: BaiTap3.c
* Author: Phạm Văn Lộc
* Date: 12/08/2023
* Description: This is a BaiTap3 file for change date (dd/mm/yyyy) to a day of week
*/
#include "date_to_day_of_week.h"

//date1: the date need to find day of week
//date0: the date have day of week already
int day0 = 29, month0 = 1, year0 = 2000;
int dayOfWeek0 = 7;

int day1, month1, year1;
int dayOfWeek1;

int dayLow, monthLow, yearLow;
int dayHigh, monthHigh, yearHigh;

int main()
{
    int dayOfDates;
    inputDate(&day1, &month1, &year1);
    //get value for dayHigh, monthHigh, yearHigh, dayLow, monthLow, yearLow
    comparisonDates(); 
    //count days between dates
    dayOfDates = gapOfDays() + gapOfMonths() + gapOfYears();
    //count distance between 2 dates
    dayOfDates %= 7;

    //find day of week of date1
    dayOfWeek1 = dayOfWeek0;
    if(comparisonDates() > 0)
    {
        for(int i=0; i<dayOfDates; i++)
        {
            if(dayOfWeek1 == 8) dayOfWeek1 = 2;
            else dayOfWeek1++;
        }
    }
    if(comparisonDates() < 0)
    {
        for(int i=0; i<dayOfDates; i++)
        {
            if(dayOfWeek1 == 2) dayOfWeek1 = 8;
            else dayOfWeek1--;
        }
    }
        
    //print day of week of date1
    switch (dayOfWeek1)
    {
        case 2:
            printf("MONDAY");
            break;
        case 3:
            printf("TUESDAY");
            break;
        case 4:
            printf("WEDNESDAY");
            break;
        case 5:
            printf("THURSDAY");
            break;
        case 6:
            printf("FRIDAY");
            break;
        case 7:
            printf("SATURDAY");
            break;
        case 8:
            printf("SUNDAY");
            break;
        default:
            printf("ERROR!!!");
    }
    return 0;
}