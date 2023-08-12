/*
* File: date_to_day_of_week.c
* Author: Phạm Văn Lộc
* Date: 12/08/2023
* Description: date_to_day_of_week.c for writting detail all function in list of date_to_day_of_week.h 
*/
#include "date_to_day_of_week.h"

/*
* Function: inputDate
* Description: This function to scan the value to variable
* Input:
*   *day1   -   an interger pointer
*   *month1 -   an interger pointer
*   *year1  -   an interger pointer
* Output:
*   none
*/
void inputDate(int *day1, int *month1, int *year1)
{
    printf("Nhap ngay thang nam: ");
    scanf("%d %d %d", day1, month1, year1);
}

/*
* Function: comparisonDates
* Description: This function to compare 2 date 
* Input:
*   none
* Output:
*    1 if date1 > date0
*    0 if date1 = date0
*   -1 if date1 < date0
*/
int comparisonDates()
{
    if(year1 > year0) 
    {
        dayHigh = day1;
        monthHigh = month1;
        yearHigh = year1;
        dayLow = day0;
        monthLow = month0;
        yearLow = year0;
        return 1;
    }
    else if(year1 < year0) 
    {
        dayHigh = day0;
        monthHigh = month0;
        yearHigh = year0;
        dayLow = day1;
        monthLow = month1;
        yearLow = year1;
        return -1;
    }
    else
    {
        if(month1 > month0)
        {
            dayHigh = day1;
            monthHigh = month1;
            yearHigh = year1;
            dayLow = day0;
            monthLow = month0;
            yearLow = year0;
            return 1;
        }
        else if(month1 < month0) 
        {
            dayHigh = day0;
            monthHigh = month0;
            yearHigh = year0;
            dayLow = day1;
            monthLow = month1;
            yearLow = year1;
            return -1;
        }
        else
        {
            if (day1 > day0) 
            {
                dayHigh = day1;
                monthHigh = month1;
                yearHigh = year1;
                dayLow = day0;
                monthLow = month0;
                yearLow = year0;
                return 1;
            }
            else if (day1 < day0) 
            {
                dayHigh = day0;
                monthHigh = month0;
                yearHigh = year0;
                dayLow = day1;
                monthLow = month1;
                yearLow = year1;
                return -1;
            }
            else
            {
                return 0;
            }
        }
    }
}

/*
* Function: gapOfYears
* Description: This function to count days between yearLow & yearHigh (do not count yearLow & yearHigh)
* Input:
*   none
* Output:
*    days between yearLow & yearHigh (do not count yearLow & yearHigh)
*/
int gapOfYears()
{
    int numOfYears, dayBetweenYears, count=0;
    //comparisonDates();
    //number between 2 years
    if((yearLow == yearHigh) || (yearLow+1 == yearHigh))  
    {
        dayBetweenYears = 0;
        printf("dayBetweenYears = %d\n", dayBetweenYears);
        return dayBetweenYears;
    }
    else numOfYears = yearHigh - yearLow - 1;
    //Day of years
    for(int i=yearLow+1; i<yearHigh; i++)
    {
        if(i%4 == 0) count++;
    }
    dayBetweenYears = numOfYears*365 + count;
    printf("dayBetweenYears = %d\n", dayBetweenYears);
    return dayBetweenYears;
}

/*
* Function: gapOfMonths
* Description: This function to count days between monthLow & monthHigh (do not count monthLow & monthHigh)
* Input:
*   none
* Output:
*    days between monthLow & monthHigh (do not count monthLow & monthHigh)
*/
int gapOfMonths()
{
    int numOfMonths, dayBetweenMonths, count=0, year = yearLow;
    //number between 2 months
    if(yearLow == yearHigh)
    {
        if((monthLow == monthHigh) || (monthLow+1 == monthHigh))  
        {
            dayBetweenMonths = 0;
            printf("dayBetweenMonths = %d\n", dayBetweenMonths);
            return dayBetweenMonths;
        }
        else 
        {
            numOfMonths = monthHigh - monthLow - 1;
            for(int i= monthLow + 1; i < monthHigh; i++)
            {
                if(i == 2)
                {
                    if(year%4 == 0) 
                        count += 2;
                    else
                        count +=3;
                }
                if((i == 4) || (i == 6) || (i == 9) || (i == 11))
                    count++;
            }
        }
    }   
    else 
    {
        numOfMonths = monthHigh - monthLow - 1 + 12;
        //Day of months
        for(int i=monthLow + 1; i<=12; i++)
        {
            if(i == 2)
            {
                if(year%4 == 0) 
                    count += 2;
                else
                    count +=3;
            }
            if((i == 4) || (i == 6) || (i == 9) || (i == 11))
                count++;
            if(i == 12) 
            {
                year = yearHigh;
            }
        }
        for(int i=1; i<monthHigh; i++)
        {
            if(i == 2)
            {
                if(year%4 == 0) 
                    count += 2;
                else
                    count +=3;
            }
            if((i == 4) || (i == 6) || (i == 9) || (i == 11))
                count++;
        }
    }
    dayBetweenMonths = numOfMonths*31 - count;
    printf("dayBetweenMonths = %d\n", dayBetweenMonths);
    return dayBetweenMonths;
}

/*
* Function: gapOfDays
* Description: This function to count days between days (from dayLow+1 to dayHigh)
* Input:
*   none
* Output:
*    days between dayLow & dayHigh (from dayLow+1 to dayHigh)
*/
int gapOfDays()
{
    int dayBetweenDays;
    if(comparisonDates() == 0)
    {
        dayBetweenDays = 0;
        printf("dayBetweenDays = %d\n", dayBetweenDays);
        return dayBetweenDays;
    }
    else
    {
        if((yearLow == yearHigh) && (monthLow == monthHigh))
                dayBetweenDays = dayHigh - dayLow;
        else
        {
            if((monthLow == 4) || (monthLow == 6) || (monthLow == 9) || (monthLow == 11))
                dayBetweenDays = dayHigh - dayLow + 30;
            else if(monthLow ==2)
            {
                if(yearLow%4 == 0)
                    dayBetweenDays = dayHigh - dayLow + 29;
                else
                    dayBetweenDays = dayHigh - dayLow + 28;
            }
            else
                dayBetweenDays = dayHigh - dayLow + 31;
        }        
    }
    printf("dayBetweenDays = %d\n", dayBetweenDays);
    return dayBetweenDays;
}