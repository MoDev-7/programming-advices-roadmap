#include <iostream>
#include <string>
using namespace std;
string readText(string massege) {
	cout << massege << endl;
	string text;
	getline(cin, text);
	return text;
}
void printLowerFirstLetterOfEachWord(string text) {
	if (text[0] != ' ')
		text[0] = tolower(text[0]);
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == ' ' && text[i + 1] != ' ')
			text[i + 1] = tolower(text[i + 1]);
	}
	cout << text << endl;
}

int main() {
	printLowerFirstLetterOfEachWord(readText("Enter the text.."));
}