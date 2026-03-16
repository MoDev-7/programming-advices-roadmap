#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
string readText(string massege) {
	cout << massege << endl;
	string text;
	getline(cin, text);
	return text;
}
string trimLeft(string text) {
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] != ' ')
			return text.substr(i, text.length() - i);
	}
	return "";
}
string trimRight(string text) {
	for (int i = text.length() - 1; i >= 0; i--)
	{
		if (text[i] != ' ')
			return text.substr(0, i + 1);
	}
	return "";
}
string trim(string text) {
	return trimRight(trimLeft(text));
}
int main() {
	string text = readText("Enter text..");
	cout << trim(text);
}