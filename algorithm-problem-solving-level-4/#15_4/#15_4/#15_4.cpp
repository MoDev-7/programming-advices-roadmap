#include <iostream>
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

bool isDayLastDayInMonth(stDate date) {
    return date.day == numberOfDaysInAMonth(date.month, date.year);
}
bool isMonthLastMonthInYear(stDate date) {
    return date.month == 12;
}
int main()
{
    stDate date1, date2;
    cout << "date 1:" << endl;
    date1.year = readYear();
    date1.month = readMonth();
    date1.day = readDay();
    cout << "date 2:" << endl;
    date2.year = readYear();
    date2.month = readMonth();
    date2.day = readDay();
    cout << (isDayLastDayInMonth(date1) ? "yeah" : "naah");
    cout << (isMonthLastMonthInYear(date1) ? "yeah" : "naah");
}
