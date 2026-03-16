#include <iostream>
#include <string>
using namespace std;
string readText(string massege) {
	cout << massege << endl;
	string text;
	getline(cin, text);
	return text;
}
void printFirstLetterOfEachWord(string text) {
	if (text[0] != ' ')
		cout << text[0] << endl;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == ' ' && text[i + 1] != ' ')
			cout << text[i + 1] << endl;
	}
}

int main() {
	printFirstLetterOfEachWord(readText("Enter the text.."));
}