#include <iostream>
#include <string>
using namespace std;
string readText(string massege) {
	cout << massege << endl;
	string text;
	getline(cin, text);
	return text;
}
short getSmallLettersCount(string text) {
	short smallLettersCount = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (islower(text[i]))
			smallLettersCount++;
	}
	return smallLettersCount;
}
short getCapitalLettersCount(string text) {
	short capitalLettersCount = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (isupper(text[i]))
			capitalLettersCount++;
	}
	return capitalLettersCount;
}
int main() {
	string text = readText("Enter text..");
	cout << "Cappital letter count :" << getCapitalLettersCount(text) << endl;
	cout << "Small letter count :" << getSmallLettersCount(text) << endl;
}