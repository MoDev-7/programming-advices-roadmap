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
int max(int n1, int n2) {
	if (n1 > n2)
		return n1;
	else if (n2 > n1)
		return n2;
	else {
		cout << "drow\n";
		return 0;
	}
}
void printMax(int max) {
	cout << max;
}
int main() {
	printMax(max(readNum1(), readNum2()));
}