#include <iostream>
using namespace std;

bool leapYear(short year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short numberOfDaysInAMonth(short month, short year) {
    if (month < 1 || month > 12) return 0;
    if (month == 2) {
        return leapYear(year) ? 29 : 28;
    }
    short arr31Days[7] = { 1, 3, 5, 7, 8, 10, 12 };
    for (short i = 0; i < 7; i++) {
        if (arr31Days[i] == month) return 31;
    }
    return 30;
}

short numberOfHoursInAMonth(short month, short year) {
    return numberOfDaysInAMonth(month, year) * 24;
}

int numberOfMinutesInAMonth(short month, short year) {
    return numberOfHoursInAMonth(month, year) * 60;
}

int numberOfSecondsInAMonth(short month, short year) {
    return numberOfMinutesInAMonth(month, year) * 60;
}

short readMonth() {
    short month;
    cout << "\nPlease enter a month to check? ";
    cin >> month;
    return month;
}

short readYear() {
    short year;
    cout << "\nPlease enter a year to check? ";
    cin >> year;
    return year;
}

int main() {
    short year = readYear();
    short month = readMonth();

    cout << "\nNumber of Days    in Month [" << month << "] is " << numberOfDaysInAMonth(month, year);
    cout << "\nNumber of Hours   in Month [" << month << "] is " << numberOfHoursInAMonth(month, year);
    cout << "\nNumber of Minutes in Month [" << month << "] is " << numberOfMinutesInAMonth(month, year);
    cout << "\nNumber of Seconds in Month [" << month << "] is " << numberOfSecondsInAMonth(month, year);

    system("pause>0");
    return 0;
}
