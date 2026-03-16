#include <iostream>
using namespace std;
struct personInfo {
	string name, lastName;
};
void readInfo(personInfo& mohammad) {
	cout << "enter name\n";
	cin >> mohammad.name;
	cout << "enter last name\n";
	cin >> mohammad.lastName;
}
void printInfo(personInfo mohammad) {
	cout << mohammad.name << " " << mohammad.lastName << endl;
}
int main() {
	personInfo mohammad;
	readInfo(mohammad);
	printInfo(mohammad);
}