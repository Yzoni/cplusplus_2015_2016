#include "assignment1.h"

using namespace std;

int main() {
    srand(time(NULL));
    // get birth time
    int birthYear, birthMonth, birthDay;
    do {
        cout << "Enter birth-year (1900 -- 2100): ";
        cin >> birthYear;
        cin.clear();
        cin.ignore(10000, '\n');
    } while (birthYear < 1900 || birthYear > 2100);
    do {
        cout << "Enter birth-month (1 -- 12): ";
        cin >> birthMonth;
        cin.clear();
        cin.ignore(10000, '\n');
    } while (birthMonth < 1 || birthMonth > 12);
    do {
        cout << "Enter birth-day  (1 -- " << daysInMonth(birthYear, birthMonth) << "): ";
        cin >> birthDay;
        cin.clear();
        cin.ignore(10000, '\n');
    } while (birthDay < 1 || birthDay > daysInMonth(birthYear, birthMonth));
    cout << "entered: " << birthYear << "-" << birthMonth << "-" << birthDay << endl;

    // get current time
    time_t curtime;
    time(&curtime);
    //cout<<"curtime:"<<ctime(&curtime)<<endl;
    tm *timePtr = localtime(&curtime);
    int curYear = timePtr->tm_year + 1900;
    int curMonth = timePtr->tm_mon + 1;
    int curDay = timePtr->tm_mday;
    cout << "current: " << curYear << "-" << curMonth << "-" << curDay << endl;

    int oldYear = yearsOld(curYear, curMonth, curDay, birthYear, birthMonth, birthDay);
    int oldMonth = monthsOld(curYear, curMonth, curDay, birthYear, birthMonth, birthDay);
    cout << "you are " << oldYear << " years or " << oldMonth << " months old" << endl;

    int dayNr;
    do {
        cout << "What is the name of your birthday?" << endl;
        cout << "1: Monday" << endl;
        cout << "2: Tuesday" << endl;
        cout << "3: Wednesday" << endl;
        cout << "4: Thursday" << endl;
        cout << "5: Friday" << endl;
        cout << "6: Saturday" << endl;
        cout << "7: Sunday" << endl;
        char day;
        cout << "give the number of the day:";
        cin >> day;
        dayNr = (int) day - 48;
    } while (dayNr < 1 || dayNr > 7);
    //cout<<"you entered: "<<dayNr<<endl;

    int bday = dayOfTheWeek(birthYear, birthMonth, birthDay);
    //cout<<"bday:"<<bday<<endl;
    if (dayNr == bday)
        cout << "Correct day" << endl;
    else
        cout << "Incorrect day (it was " << bday << ")" << endl;

    cout << "random guess ratio:" << randomGuessing(1000) << endl;

    return 0;
}
