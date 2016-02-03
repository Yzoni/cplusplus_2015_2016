#include <iostream>

using namespace std;

int yearsOld(int currentYear, int currentMonth, int currentDay, int birthYear, int birthMonth, int birthDay) {
    int deltaYear = currentYear - birthYear;
    if ((currentMonth >= birthMonth) && (currentDay >= birthDay)) {
        return deltaYear;
    }
    return deltaYear - 1;
}

int monthsOld(int currentYear, int currentMonth, int currentDay, int birthYear, int birthMonth, int birthDay) {
    int partD;
    int dMonths;
    if ((currentMonth >= birthMonth) && currentDay >= birthDay) {
        partD = (12 - birthMonth) + currentMonth;
        dMonths = ((currentYear - birthYear - 1) * 12) + partD;
    } else {
        partD = currentMonth - birthMonth - 1;
        dMonths = ((currentYear - birthYear) * 12) + partD;
    }
    return dMonths;
}

int dayOfTheWeek(int birthYear,int birthMonth,int birthDay) {
    int daynr;

    cout << "Select the weekday by day number\n";
    cout << "1: monday \n";
    cout << "2: tuesday \n";
    cout << "3: wednesday \n";
    cout << "4: thursday \n";
    cout << "5: friday \n";
    cout << "6: saturday \n";
    cout << "7: sunday \n";
    cout << "Day (1-7): ";
    cin >> daynr;


    return 0;
}

int main() {
    time_t currentTime;
    time(&currentTime);
    tm* timePtr = localtime(&currentTime);
    cout << " year:" << timePtr->tm_year+1900
         << " month:" << timePtr->tm_mon+1
         << " day:" << timePtr->tm_mday << endl;

    int z = dayOfTheWeek(2060,10,26);
    cout << z;
}



