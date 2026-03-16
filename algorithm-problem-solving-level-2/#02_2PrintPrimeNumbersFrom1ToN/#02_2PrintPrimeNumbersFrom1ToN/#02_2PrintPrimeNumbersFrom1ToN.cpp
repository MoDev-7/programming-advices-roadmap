#include <iostream>
using namespace std;
void printNum(int num) {
	cout << num << endl;
}
int readNum() {
	int num;
	cout << "enter a num\n";
	cin >> num;
	return num;
}
bool chekPrimeNum(int num) {
	for (int i = 2; i <= num/2; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
void getPrimNumbers(int num) {
	for (int i = 1; i <= num; i++)
	{
		if (chekPrimeNum(i))
			printNum(i);
	}
}
int main()
{
	getPrimNumbers(readNum());
}
