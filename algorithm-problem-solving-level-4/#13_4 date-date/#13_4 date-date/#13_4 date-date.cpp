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
bool IsDate1BeforeDate2(stDate date2, stDate date1) {
    return (date1.year > date2.year) ? true : ((date1.year == date2.year) ? ((date1.month > date2.month) ? true : ((date1.month == date2.month) ? (date1.day > date2.day) : false)) : false);
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
    cout << (IsDate1BeforeDate2(date1, date2) ? "yeah" : "naah");
}
