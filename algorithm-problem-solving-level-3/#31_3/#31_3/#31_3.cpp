#include <iostream>
#include <string>
using namespace std;
char invertCharacterCase(char character) {
	if (isupper(character))
		character = tolower(character);
	else
		character = toupper(character);
	return character;
}
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
short countLetterWhithMatchCase(string text, char character, bool matchCase = true) {
	short count = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (matchCase) {
			if (text[i] == character)
				count++;
		}
		else {
			if (toupper(text[i]) == toupper(character))
				count++;
		}
	}
	return count;
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
	char character = readCharacter("Enter character..");
	cout << "Letter count of " << character << " : " << countLetterWhithMatchCase(text, character) << endl;
	cout << "Letter count of " << character << " or " << invertCharacterCase(character) << " : " << countLetterWhithMatchCase(text, character, false) << endl;
}