#include <iostream>
using namespace std;
bool leapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
int main()
{
	for (short i = 1900; i <= 2050; i++)
	{
		cout << i << " : " << ((leapYear(i)) ? "leap\n" : "not leap\n");
	}
}