#include <iostream>
using namespace std;
int readNum(string st) {
	int num;
	cout << st << endl;
	cin >> num;
	return num;
}
int numberOfDigits(int n) {
	n = abs(n);
	int x = 0, y = 10;
	for (int i = 1; i < 9; i++)
	{
		if (n >= x && n < y)
			return i;
		if (x == 0) {
			x = 10;
			y = 100;
		}
		else {
			x = x * 10;
			y = y * 10;
		}
	}
}
void printNum(int num, int digit) {
	int remainder = 0;
	int i = 0;
	while (num > 0)
	{
		remainder = num % 10;
		num = num / 10;
		if (remainder == digit)
			i++;
	}
	cout << i;
}
int main()
{
	printNum(readNum("enter a num"), readNum("enter a digit"));
}