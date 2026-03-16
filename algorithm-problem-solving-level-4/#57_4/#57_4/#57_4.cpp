#include <iostream>
#include <iostream>
#include <iomanip>
using namespace std;
struct stDate {
    short day, month, year;
};
enum enDateCompare {
    befor = -1,
    equal = 0,
    after = 1
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
bool IsDate1BeforeDate2(stDate date2, stDate date1) {
    return (date1.year > date2.year) ? true : ((date1.year == date2.year) ? ((date1.month > date2.month) ? true : ((date1.month == date2.month) ? (date1.day > date2.day) : false)) : false);
}
bool IsDate1AfterDate2(stDate date1, stDate date2) {
    return (date1.year > date2.year) ? true : ((date1.year == date2.year) ? ((date1.month > date2.month) ? true : ((date1.month == date2.month) ? (date1.day > date2.day) : false)) : false);
}
bool IsDate1EqualseDate2(stDate date2, stDate date1) {
    return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
}
enDateCompare compareDates(stDate date1, stDate date2){
    if (IsDate1AfterDate2(date1, date2))
        return enDateCompare::after;
    if (IsDate1EqualseDate2(date1, date2))
        return enDateCompare::equal;
    return enDateCompare::befor;
}
int main()
{
    stDate date, date2;
    date.year = readYear();
    date.month = readMonth();
    date.day = readDay();
    date2.year = readYear();
    date2.month = readMonth();
    date2.day = readDay();
}