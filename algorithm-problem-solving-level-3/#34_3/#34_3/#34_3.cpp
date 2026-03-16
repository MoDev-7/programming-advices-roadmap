#include <iostream>
#include <string>
using namespace std;
string readText(string massege) {
	cout << massege << endl;
	string text;
	getline(cin, text);
	return text;
}
bool isCharacterVowel(char character) {
	character = tolower(character);
	return (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u');
}
void printVowels(string text) {
	for (int i = 0; i < text.length(); i++)
	{
		if (isCharacterVowel(text[i]))
			cout << text[i] << "  ";
	}
}
int main() {
	string text = readText("Enter text..");
	cout << "Vowel letters : ";
	printVowels(text);
}