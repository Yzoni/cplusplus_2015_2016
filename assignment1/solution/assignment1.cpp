#include "assignment1.h"

using namespace std;

// returns days in a month of a specific year taking leap years into account
int daysInMonth(int year, int month) {
    int days = -1;
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: // 31 day months
            days = 31;
            break;
        case 2: // Februari
            if (year > 1900 && year < 2099 && year % 4 == 0) // check for leap year
                days = 29;
            else
                days = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11: // 30 day months
            days = 30;
            break;
        default:
            cout << "error, unkown month" << endl;
            exit(1);
    }
    return days;
}

// helper function to avoid code duplication in monthsOld() and yearsOld()
// returns age in years or months (depending on 'years' argument) given current and birth date
int helperOld(int currentYear, int currentMonth, int currentDay,
              int birthYear, int birthMonth, int birthDay, bool years = true) {
    int diffYear = currentYear - birthYear; // start by subtracting the dates, then correct
    int diffMonth = currentMonth - birthMonth;
    int diffDay = currentDay - birthDay;
    if (diffDay <= 0) diffMonth -= 1; // if diffDay is negative then diffMonth should be 1 less
    if (diffMonth < 0) // if diffMonth is negative then diffYear should be 1 less and diffMonth 12 more
    {
        diffYear -= 1;
        diffMonth += 12;
    }
    if (years) // return years or months depending on 'years'
        return diffYear;
    else
        return diffYear * 12 + diffMonth;
}

// returns age in year given current and birth date
int yearsOld(int currentYear, int currentMonth, int currentDay,
             int birthYear, int birthMonth, int birthDay) {
    return helperOld(currentYear, currentMonth, currentDay,
                     birthYear, birthMonth, birthDay, true);
}

// returns age in months given current and birth date
int monthsOld(int currentYear, int currentMonth, int currentDay,
              int birthYear, int birthMonth, int birthDay) {
    return helperOld(currentYear, currentMonth, currentDay,
                     birthYear, birthMonth, birthDay, false);
}

// returns difference in days between ref date and birth date
int diffDays(int refYear, int refMonth, int refDay,
             int birthYear, int birthMonth, int birthDay) {
    // we will move birth date to ref date counting all days in between
    int days = birthDay - refDay; // first correct by the difference in days
    while (birthYear < refYear || (birthYear == refYear && birthMonth < refMonth)) // birth smaller than ref
    {
        days -= daysInMonth(birthYear, birthMonth); // count the days in the month
        birthMonth += 1; // move one month up
        if (birthMonth > 12) // move to next year
        {
            birthMonth = 1;
            birthYear += 1;
        }
    }
    while (birthYear > refYear || (birthYear == refYear && birthMonth > refMonth)) // birth larger than ref
    {
        birthMonth -= 1; // move one month down
        if (birthMonth == 0) // move to previous year
        {
            birthMonth = 12;
            birthYear -= 1;
        }
        days += daysInMonth(birthYear, birthMonth); // count the days in the month
    }
    return days;
}

// returns which day of the week it was on the date
int dayOfTheWeek(int birthYear, int birthMonth, int birthDay) {
    // this reference day was a monday
    int refYear = 2015;
    int refMonth = 1;
    int refDay = 5;

    int days = diffDays(refYear, refMonth, refDay, // get difference in days
                        birthYear, birthMonth, birthDay);
    //cout<<"diffDays: "<<days<<endl;
    int bday = days % 7; // we only care about remainder after division by 7 days because of the week cycle
    if (bday < 0) bday += 7; // can be negative so correct for that
    return bday + 1; // 1 is a Monday
}

// returns ration of correct guesses of the day of the week for a random date
double randomGuessing(int n) {
    int correctCount = 0;
    for (int i = 0; i < n; i++) {
        int birthYear = 1900 + rand() % 201; // get random date
        int birthMonth = 1 + rand() % 12;
        int birthDay = 1 + rand() % daysInMonth(birthYear, birthMonth);
        int dayOfWeek = 1 + rand() % 7; // get random day of the week
        bool correct = (dayOfWeek == dayOfTheWeek(birthYear, birthMonth, birthDay));
        if (correct) ++correctCount;
        //cout<<birthYear<<"-"<<birthMonth<<"-"<<birthDay<<" dayOfWeek:"<<dayOfWeek<<" correct:"<<correct<<endl;
    }
    return correctCount / (double) n;
}

