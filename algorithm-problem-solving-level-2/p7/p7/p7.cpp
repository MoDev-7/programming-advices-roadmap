#include <iostream>
using namespace std;
int readNum() {
	int num;
	cout << "enter a num" << endl;
	cin >> num;
	return num;
}
float getHalf(int num) {
	float halfNum = num / 2;
	return halfNum;
}
void printHalfNum(float halfNum) {
	cout << halfNum;
}
int main() {
	printHalfNum(getHalf(readNum()));
}