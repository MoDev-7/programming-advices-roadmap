#include <iostream>
#include <string>
using namespace std;
string readText(string massege) {
	cout << massege << endl;
	string text;
	getline(cin, text);
	return text;
}
char readCharacter(string massege) {
	cout << massege << endl;
	char character;
	cin >> character;
	return character;
}
short countLetter(string text, char character) {
	short count = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == character)
			count++;
	}
	return count;
}
int main() {
	string text = readText("Enter text..");
	char character = readCharacter("Enter character..");
	cout << "Letter count of " << character << " : " << countLetter(text, character) << endl;
}