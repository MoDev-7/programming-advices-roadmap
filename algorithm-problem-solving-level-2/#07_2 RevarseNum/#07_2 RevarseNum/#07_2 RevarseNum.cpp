#include <iostream>
using namespace std;
int readNum() {
	int num;
	cout << "enter a num\n";
	cin >> num;
	return num;
}
int reversNum(int num) {
	int remainder = 0, sum = 0, i = 0;
	while (num > 0)
	{
		remainder = num % 10;
		num = num / 10;
		sum = sum * 10 + remainder;
		i++;
	}
	return sum;
}
int main()
{
	cout << reversNum(readNum());
}