#include <iostream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
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
enum enForamateDate {
    dmy = 0,
    ymd = 1,
    ydm = 2,
    mdy = 3,
    slash = 4,
    dash = 5
};
enum enStyleDate {
    
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
bool isLeapYear(short year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
short numberOfDaysInAMonth(short month, short year) {
    if (month < 1 || month > 12) return 0;
    int numberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : numberOfDays[month - 1];
}
bool isDateVslid(stDate d) {
    return !(d.month < 1 || d.month > 12 || d.day < 1 || d.day > numberOfDaysInAMonth(d.month, d.year));
}
stDate readFullDate() {
    stDate date;
    bool value = true;
    while (value) {
        cout << "date:" << endl;
        date.day = readDay();
        date.month = readMonth();
        date.year = readYear();
        value = !isDateVslid(date);
        cout << "Invalid date!... Please enter a valid date.\n";
    }

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
vector <string> splitTextToWords(string text, string delim) {
    vector <string> vWords;
    string word = "";
    short pos = 0;
    while ((pos = text.find(delim)) != std::string::npos) {
        word = text.substr(0, pos);
        if (word != "")
            vWords.push_back(word);
        text.erase(0, pos + delim.length());
    }
    if (text != "")
        vWords.push_back(text);
    return vWords;
}
stDate convertStringToDate(string s) {
    vector <string> vS = splitTextToWords(s, "/");
    stDate d;
    d.day = short(stoi(vS[0]));
    d.month = short(stoi(vS[1]));
    d.year = short(stoi(vS[2]));
    return d;
}
stDate readDateString() {
    stDate d;
    string s;
    cout << "Pleas enter date ? ";
    cin >> s;
    return convertStringToDate(s);
}
string dateFormating(stDate d, enForamateDate form) {
    switch (form) {
    case enForamateDate::ymd:
    case enForamateDate::dmy:
    case enForamateDate::mdy:
    case enForamateDate::ydm:
    }
}


int main()
{
    stDate date = readFullDate();
    stPeriod p1 = readFullPeriod(), p2 = readFullPeriod();
}