#include <iostream>
#include <iostream>
#include <iomanip>
using namespace std;
struct stDate {
    short day, month, year;
};
struct stPeriod {
    stDate start, end;
};
enum enDateCompare {
    befor = -1,
    equal = 0,
    after = 1
};

short readMonth() {
    short month;
    cout << "Please enter a month ? ";
    cin >> month;
    cout << endl;
    return month;
}
short readYear() {
    short year;
    cout << "Please enter a year ? ";
    cin >> year;
    cout << endl;
    return year;
}
short readDay() {
    short day;
    cout << "Please enter a day ? ";
    cin >> day;
    cout << endl;
    return day;
}
stDate readFullDate() {
    stDate date;
    cout << "date:" << endl;
    date.day = readDay();
    date.month = readMonth();
    date.year = readYear();
    return date;
}
stPeriod readFullPeriod() {
    stPeriod period;
    cout << "start:\n";
    period.start = readFullDate();
    cout << "end:\n";
    period.end = readFullDate();
    return period;
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
enDateCompare compareDates(stDate date1, stDate date2) {
    if (IsDate1AfterDate2(date1, date2))
        return enDateCompare::after;
    if (IsDate1EqualseDate2(date1, date2))
        return enDateCompare::equal;
    return enDateCompare::befor;
}
bool isTwoPeriodsAreOverlape(stPeriod period1, stPeriod period2) {
    return IsDate1BeforeDate2(period1.end, period2.start) || IsDate1AfterDate2(period1.start, period2.end);
}
int main()
{
    stPeriod p1 = readFullPeriod(), p2 = readFullPeriod();
    cout << (isTwoPeriodsAreOverlape(p1, p2) ? "yeah" : "nah") << endl;
}