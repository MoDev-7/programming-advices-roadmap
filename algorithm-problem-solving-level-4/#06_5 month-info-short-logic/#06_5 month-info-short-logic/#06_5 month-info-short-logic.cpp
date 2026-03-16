#include <iostream>
using namespace std;

bool isLeapYear(short year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short numberOfDaysInAMonth(short month, short year) {
    if (month < 1 || month > 12) return 0;
    int numberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : numberOfDays[month - 1];
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
