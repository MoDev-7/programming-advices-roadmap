#include <iostream>
using namespace std;
int readNum() {
	int num;
	cout << "enter a num\n";
	cin >> num;
	return num;
}
int sumOfDigits(int num) {
	int remainder = 0, sum = 0;
	while (num > 0)
	{
		remainder = num % 10;
		num = num / 10;
		sum = sum + remainder;
	}
	cout << sum;
}
int main()
{
	cout << sumOfDigits(readNum());
}