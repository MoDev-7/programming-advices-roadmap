#include <iostream>
#include <iomanip>
#include <string>
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
short dayOrderByGregorianCalendar(short year, short month, short day) {
    short a, m, y;
    a = (14 - month) / 12;
    m = month + (12 * a) - 2;
    y = year - a;
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string monthName(short month) {
    string months[12] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    return months[month - 1];
}
bool isLeapYear(short year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
short numberOfDaysInAMonth(short month, short year) {
    if (month < 1 || month > 12) return 0;
    int numberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : numberOfDays[month - 1];
}

void printHeader(short month) {
    cout << "  _______________" << monthName(month) << "_______________" << endl << endl;
    cout << setw(5) << "Sun" << setw(5) << "Mon" << setw(5) << "Tue" << setw(5) << "Wed" << setw(5) << "Thu" << setw(5) << "Fri" << setw(5) << "Sut" << endl;
}
void printLow() {
    cout << "  _________________________________";
}
void printCalendar(short year, short month) {
    printHeader(month);
    short dayOrder = dayOrderByGregorianCalendar(year, month, 1);
    short counter = 0;
    for (short i = 0; i < dayOrder; i++)
    {
        cout << setw(5) << "";
        counter++;
    }
    for (short i = 1; i <= numberOfDaysInAMonth(month, year); i++)
    {
        cout << setw(5) << i;
        counter++;
        if (counter == 7) {
            cout << endl;
            counter = 0;
        }
    }
    cout << endl;
    printLow();
}

int main() {
    short year = readYear();
    short month = readMonth();
    printCalendar(year, month);
    system("pause>0");
    return 0;
}
