#include <iostream>
#include <iomanip>
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
short dayOrderByGregorianCalendar(stDate date) {
    short a, m, y;
    a = (14 - date.month) / 12;
    m = date.month + (12 * a) - 2;
    y = date.year - a;
    return (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
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
string dayName(short dayOrder) {
    string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    return days[dayOrder];
}
void printDate(stDate date) {
    cout << setw(11) << left << "Date" << left << ": " << dayName(dayOrderByGregorianCalendar(date)) << " " << date.day << "/" << date.month << "/" << date.year << endl;
}

bool isDateEndOfWeek(stDate date) {
    return dayOrderByGregorianCalendar(date) == 6;
}
bool isDateWeekend(stDate date) {
    return dayOrderByGregorianCalendar(date) == 6 || dayOrderByGregorianCalendar(date) == 5;
}
bool isDateBusinessDay(stDate date) {
    return !isDateWeekend(date);
}
short daysUntilEndOfWeek(stDate date) {
    return 6 - dayOrderByGregorianCalendar(date);
}
short daysUntilEndOfMonth(stDate date) {
    return numberOfDaysInAMonth(date.month, date.year) - date.day;
}
short daysUntilEndOfYear(stDate date) {
    return (isLeapYear(date.year) ? 366 : 365) - numberOfDaysFromBeginningOfYear(date.year, date.month, date.day);
}

int main() {
    stDate date;
    date.year = readYear();
    date.month = readMonth();
    date.day = readDay();
    cout << dayOrderByGregorianCalendar(date) << endl;
    printDate(date);
    cout << "is date end of week? " << (isDateEndOfWeek(date) ? "yes" : "no") << endl;
    cout << "is date weekend? " << (isDateWeekend(date) ? "yes" : "no") << endl;
    cout << "is date business day? " << (isDateBusinessDay(date) ? "yes" : "no") << endl;
    cout << "days until end of week : " << daysUntilEndOfWeek(date) << endl;
    cout << "days until end of month : " << daysUntilEndOfMonth(date) << endl;
    cout << "days until end of year : " << daysUntilEndOfYear(date) << endl;
    return 0;
}
