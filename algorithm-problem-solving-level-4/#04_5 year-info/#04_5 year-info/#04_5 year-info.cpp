#include <iostream>
using namespace std;
bool leapYear(short year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
short days(short year) {
    if (leapYear(year))
        return 364;
    else
        return 365;
}
short hours(short year) {
    return days(year) * 24;
}
short minutes(short year) {
    return hours(year) * 60;
}
short seconds(short year) {
    return minutes(year) * 60;
}
short readYear() {
    cout << "Enter year" << endl;
    short year;
    cin >> year;
    return year;
}
int main()
{
    short year = readYear();
    cout << "Days = " << days(year) << endl;
    cout << "Hours = " << hours(year) << endl;
    cout << "Minutes = " << minutes(year) << endl;
    cout << "Seconds = " << seconds(year) << endl;
}