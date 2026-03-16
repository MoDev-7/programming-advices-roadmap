#include <iostream>
#include <iomanip>
using namespace std;

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

void printDate(short year, short month, short day) {
    cout << setw(11) << left << "Date" << left << ": " << day << "/" << month << "/" << year << endl;
}

short dayOrderByGregorianCalendar(short year, short month, short day) {
    short a, m, y;
    a = (14 - month) / 12;
    m = month + (12 * a) - 2;
    y = year - a;
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string dayName(short dayOrder) {
    string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    return days[dayOrder];
}


int main() {
    short year = readYear();
    short month = readMonth();
    short day = readDay();
    short dayOrder = dayOrderByGregorianCalendar(year, month, day);
    printDate(year, month, day);
    cout << setw(11) << left << "Day order" << left << ": " << dayOrder << endl;
    cout << setw(11) << left << "Day name:" << left << ": " << dayName(dayOrder) << endl;
    system("pause>0");
    return 0;
}
