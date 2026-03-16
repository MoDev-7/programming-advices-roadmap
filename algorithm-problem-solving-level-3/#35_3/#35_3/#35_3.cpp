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
void printWords(string text) {
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] != ' ')
			cout << text[i];
		else if (i != text.length() - 1 && (text[i + 1] != ' ' && i != 0))
			cout << endl;
	}
}
void splitTextToWords(string text) {
	string word = "";
	string delim = " ";
	short pos = 0;
	while ((pos = text.find(delim)) != std::string::npos) {
		word = text.substr(0, pos);
		if (word != "")
			cout << word << endl;
		text.erase(0, pos + delim.length());
	}
	if (text != "")
		cout << text << endl;
}
int main() {
	string text = readText("Enter text..");
	splitTextToWords(text);
}