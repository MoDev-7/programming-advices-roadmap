#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct stDate {
    short day, month, year;
};
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
short readDay() {
    short day;
    cout << "\nPlease enter a day to check? ";
    cin >> day;
    return day;
}

bool isLeapYear(short year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
short numberOfDaysInAMonth(short month, short year) {
    if (month < 1 || month > 12) return 0;
    int numberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : numberOfDays[month - 1];
}
short numberOfDaysFromBeginningOfYear(short year, short month, short day) {
    short numberOfDays = day;
    for (short i = 1; i <= month - 1; i++)
    {
        numberOfDays += numberOfDaysInAMonth(i, year);
    }
    return numberOfDays;
}
short numberOfMonths(short dayOrder, short year) {
    short i = 0;
    while (dayOrder > 0) {
        dayOrder -= numberOfDaysInAMonth(i + 1, year);
        i++;
    }
    return i;
}
short numberTheDay(short dayOrder, short year, short months) {
    for (short i = 1; i <= months - 1; i++)
    {
        dayOrder -= numberOfDaysInAMonth(i, year);
    }
    return dayOrder;
}
stDate getDateFromDayOrder(short dayOrder, short year) {
    stDate date;
    date.year = year;
    date.month = numberOfMonths(dayOrder, year);
    date.day = numberTheDay(dayOrder, year, date.month);
    return date;
}
int main() {
    short day = readDay();
    short month = readMonth();
    short year = readYear();
    short dayOrder = numberOfDaysFromBeginningOfYear(year, month, day);
    stDate date = getDateFromDayOrder(dayOrder, year);
    cout << "Number of days from beginning of year is " << dayOrder << endl;
    cout << "Date is " << date.day << "/" << date.month << "/" << date.year << endl;
    system("pause>0");
    return 0;
}
