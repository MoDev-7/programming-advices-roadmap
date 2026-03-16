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
short readNumber() {
    short number;
    cout << "\nEnter number to add ? ";
    cin >> number;
    return number;
}
bool IsDate1BeforeDate2(stDate date2, stDate date1) {
    return (date1.year > date2.year) ? true : ((date1.year == date2.year) ? ((date1.month > date2.month) ? true : ((date1.month == date2.month) ? (date1.day > date2.day) : false)) : false);
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
short diffBetwenTwoDates(stDate date1, stDate date2) {
    if (!IsDate1BeforeDate2(date1, date2)) {
        stDate temp = date1;
        date1 = date2;
        date2 = temp;
    }
    short diff = numberOfDaysFromBeginningOfYear(date2.year, date2.month, date2.day) - numberOfDaysFromBeginningOfYear(date1.year, date1.month, date1.day);
    while (date2.year - date1.year != 0) {
        diff += (isLeapYear(date1.year) ? 366 : 365);
        date1.year++;
    }
    return diff;
}
int main() {
    stDate date1, date2;
    cout << "date 1:" << endl;
    date1.year = readYear();
    date1.month = readMonth();
    date1.day = readDay();
    cout << "date 2:" << endl;
    date2.year = readYear();
    date2.month = readMonth();
    date2.day = readDay();
    cout << "diff is : " << diffBetwenTwoDates(date1, date2);
}
