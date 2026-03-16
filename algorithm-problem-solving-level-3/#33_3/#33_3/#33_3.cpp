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
short countVowels(string text) {
	short count = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (isCharacterVowel(text[i]))
			count++;
	}
	return count;
}
int main() {
	string text = readText("Enter text..");
	cout << "Count of vowel letters : " << countVowels(text);
}