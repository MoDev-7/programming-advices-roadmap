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
stDate increasDateByOneDay(stDate date) {
    if (isDayLastDayInMonth(date)) {
        if (isMonthLastMonthInYear(date)) {
            date.day = 1;
            date.month = 1;
            date.year++;
        }
        else {
            date.day = 1;
            date.month++;
        }
    }
    else
        date.day++;
    return date;
}
int main()
{
    stDate date1, date2;
    cout << "date 1:" << endl;
    date1.year = readYear();
    date1.month = readMonth();
    date1.day = readDay();
    date1 = increasDateByOneDay(date1);
    cout << date1.year << "/" << date1.month << "/" << date1.day;
}
