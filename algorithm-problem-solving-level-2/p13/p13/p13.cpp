#include <iostream>
using namespace std;
int readNum1() {
	int n1;
	cout << "enter n1\n";
	cin >> n1;
	return n1;
}
int readNum2() {
	int n2;
	cout << "enter n2\n";
	cin >> n2;
	return n2;
}
int readNum3() {
	int n3;
	cout << "enter n3\n";
	cin >> n3;
	return n3;
}
int max(int n1, int n2,int n3) {
	if (n1 > n2) {
		if (n2 > n3)
			return n1;
		else
			return n3;
	}
	else
		return n2;
}
void printMax(int max) {
	cout << max;
}
int main() {
	printMax(max(readNum3(), readNum2(),readNum1()));
}