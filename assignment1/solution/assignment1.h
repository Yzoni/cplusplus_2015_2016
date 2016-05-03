#ifndef ASSIGNMENT1_H_INCLUDED
#define ASSIGNMENT1_H_INCLUDED

#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <stdio.h>

int daysInMonth(int year, int month);

int yearsOld(int currentYear, int currentMonth, int currentDay,
             int birthYear, int birthMonth, int birthDay);

int monthsOld(int currentYear, int currentMonth, int currentDay,
              int birthYear, int birthMonth, int birthDay);

int dayOfTheWeek(int birthYear, int birthMonth, int birthDay);

double randomGuessing(int n = 1000);

#endif
