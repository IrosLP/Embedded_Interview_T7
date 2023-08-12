/*
* File: date_to_day_of_week.h
* Author: Phạm Văn Lộc
* Date: 12/08/2023
* Description: date_to_day_of_week.h for declare list of function in date_to_day_of_week library
*/
#include <stdio.h>

#ifndef DATE_TO_DAY_OF_WEEK_H
#define DATE_TO_DAY_OF_WEEK_H

extern int day0, month0, year0;
extern int dayOfWeek0;

extern int day1, month1, year1;
extern int dayOfWeek1;

extern int dayLow, monthLow, yearLow;
extern int dayHigh, monthHigh, yearHigh;

void inputDate(int *day1, int *month1, int *year1);
int comparisonDates();
int gapOfYears();
int gapOfMonths();
int gapOfDays();

#endif 