#pragma warning (disable: 4996)
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
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
stDate GetSystemDate()
{
    stDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.year = now->tm_year + 1900;
    Date.month = now->tm_mon + 1;
    Date.day = now->tm_mday;
    return Date;
}
//
bool isDayLastDayInMonth(stDate date) {
    return date.day == numberOfDaysInAMonth(date.month, date.year);
}
bool isMonthLastMonthInYear(stDate date) {
    return date.month == 12;
}
short daysToMonth(short& dayOrder, short year) {
    short i = 0;
    while (dayOrder > 0) {
        dayOrder -= numberOfDaysInAMonth(i + 1, year);
        i++;
    }
    dayOrder += numberOfDaysInAMonth(i, year);
    return i;
}
short daysToYears(short& days, short year) {
    year--;
    while (days > 0) {
        days -= (isLeapYear(year + 1) ? 366 : 365);
        year++;
    }
    days += (isLeapYear(year) ? 366 : 365);
    return year;
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
stDate increasDateByXDays(stDate date, short daysToAdd) {
    short dayOrder = numberOfDaysFromBeginningOfYear(date.year, date.month, date.day) + daysToAdd;
    date.year = daysToYears(dayOrder, date.year);
    date.month = daysToMonth(dayOrder, date.year);
    date.day = dayOrder;
    return date;
}
//
stDate increasDateByOneWeek(stDate date) {
    date = increasDateByXDays(date, 7);
    return date;
}
stDate increasDateByXWeeks(stDate date, short x) {
    date = increasDateByXDays(date, 7 * x);
    return date;
}
//
stDate increasDateByOneMonth(stDate date) {
    if (isMonthLastMonthInYear(date)) {
        date.month = 1;
        date.year++;
    }
    else
        date.month++;
    (date.day > numberOfDaysInAMonth(date.month, date.year)) ? date.day = numberOfDaysInAMonth(date.month, date.year) : date.day = date.day;
    return date;
}
stDate increasDateByXMonthes(stDate date, short x) {
    for (short i = 0; i < x; i++)
    {
        date = increasDateByOneMonth(date);
    }
    return date;
}
//
stDate increasDateByOneYear(stDate date) {
    date.year++;
    return date;
}
stDate increasDateByXYears(stDate date, short x) {
    date.year += x;
    return date;
}
//
stDate increasDateByOneDecade(stDate date) {
    date.year += 10;
    return date;
}
stDate increasDateByXDeacads(stDate date, short x) {
    date.year += (x * 10);
    return date;
}
//
stDate increasDateByOneCentury(stDate date) {
    date.year += 100;
    return date;
}
stDate increasDateByOneMillennium(stDate date) {
    date.year += 1000;
    return date;
}
//
int main() {
    stDate date1, date2;
    cout << "date 1:" << endl;
    date1.year = readYear();
    date1.month = readMonth();
    date1.day = readDay();
    cout << "current date: " << date1.day << "/" << date1.month << "/" << date1.year << endl;
    date1 = increasDateByOneDay(date1);
    cout << "1) Adding one day: " << date1.day << "/" << date1.month << "/" << date1.year <<  endl;
    date1 = increasDateByXDays(date1, 10);
    cout << "2) Adding 10 days: " << date1.day << "/" << date1.month << "/" << date1.year << endl;
    date1 = increasDateByOneWeek(date1);
    cout << "3) Adding one week: " << date1.day << "/" << date1.month << "/" << date1.year << endl;
    date1 = increasDateByXWeeks(date1, 10);
    cout << "4) Adding 10 weeks: " << date1.day << "/" << date1.month << "/" << date1.year << endl;
    date1 = increasDateByOneMonth(date1);
    cout << "5) Adding one month: " << date1.day << "/" << date1.month << "/" << date1.year << endl;
    date1 = increasDateByXMonthes(date1, 5);
    cout << "6) Adding 5 monthes: " << date1.day << "/" << date1.month << "/" << date1.year << endl;
    date1 = increasDateByOneYear(date1);
    cout << "7) Adding one year: " << date1.day << "/" << date1.month << "/" << date1.year << endl;
    date1 = increasDateByXYears(date1, 10);
    cout << "8) Adding 10 years: " << date1.day << "/" << date1.month << "/" << date1.year << endl;
    date1 = increasDateByOneDecade(date1);
    cout << "9) Adding one decade: " << date1.day << "/" << date1.month << "/" << date1.year << endl;
    date1 = increasDateByXDeacads(date1, 10);
    cout << "10) Adding 10 decades: " << date1.day << "/" << date1.month << "/" << date1.year << endl;
    date1 = increasDateByOneCentury(date1);
    cout << "11) Adding one century: " << date1.day << "/" << date1.month << "/" << date1.year << endl;
    date1 = increasDateByOneMillennium(date1);
    cout << "12) Adding one millennium: " << date1.day << "/" << date1.month << "/" << date1.year << endl;
}
