#include <iostream>
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
bool isDateWeekend(stDate date) {
    return dayOrderByGregorianCalendar(date) == 6 || dayOrderByGregorianCalendar(date) == 5;
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
short weekendDaysInAPeriod(stDate date1, stDate date2) {
    short vDays = 0;
    short temp = diffBetwenTwoDates(date1, date2);
    for (short i = 0; i < 6; i++)
    {
        if (dayOrderByGregorianCalendar(date1) == 0)
            break;
        if (isDateWeekend(date1))
            vDays++;
        date1 = increasDateByOneDay(date1);
        temp--;
    }
    vDays += (temp / 7) * 2 + ((temp % 7 > 5) ? (temp % 7) - 5 : 0);
    return vDays;
}
short vocationDaysInAPeriod(stDate date1, stDate date2) {
    return diffBetwenTwoDates(date1, date2) - weekendDaysInAPeriod(date1, date2);
}
//short vocationDaysInAPeriod(stDate date1, stDate date2) {
//    short vDays = 0;
//    if (!IsDate1BeforeDate2(date1, date2)) {
//        stDate temp = date1;
//        date1 = date2;
//        date2 = temp;
//    }
//    short diff = diffBetwenTwoDates(date1, date2);
//    for (short i = 0; i < diff; i++)
//    {
//        if (isDateWeekend(date1))
//            vDays++;
//        date1 = increasDateByOneDay(date1);
//    }
//    return vDays;
//}
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
stDate getDateFromDayOrder(short dayOrder, short year) {
    stDate date;
    date.year = daysToYears(dayOrder, year);
    date.month = daysToMonth(dayOrder, year);
    date.day = dayOrder;
    return date;
}

stDate calculateEndDateOfVocation(stDate date, short vocationDays) {
    stDate temp = date;
    short days = 0;
    for (short i = 0; i < 6; i++)
    {
        if (dayOrderByGregorianCalendar(date) == 0)
            break;
        if (!isDateWeekend(date))
            vocationDays--;
        days++;
        date = increasDateByOneDay(date);
    }
    days += (vocationDays / 5) * 7 + (vocationDays % 5);
    return getDateFromDayOrder(numberOfDaysFromBeginningOfYear(temp.year, temp.month, temp.day) + days, date.year);
}
string dayName(short dayOrder) {
    string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    return days[dayOrder];
}
void printDate(stDate date) {
    cout << setw(11) << left << "Date" << left << ": " << dayName(dayOrderByGregorianCalendar(date)) << " " << date.day << "/" << date.month << "/" << date.year << endl;
}

int main() {
    stDate date, date2;
    date.year = readYear();
    date.month = readMonth();
    date.day = readDay();
    short num;
    cout << "enter vocation..? ";
    cin >> num;
    cout << endl;
    cout << "date is : ";
    printDate(calculateEndDateOfVocation(date, num));
}