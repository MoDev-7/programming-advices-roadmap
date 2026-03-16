#include <iostream>
#include <string>
using namespace std;
string readText(string massege) {
	cout << massege << endl;
	string text;
	getline(cin, text);
	return text;
}
char invertCharacterCase(char character) {
	if (isupper(character))
		character = tolower(character);
	else
		character = toupper(character);
	return character;
}
void invertAllStringLettersCase(string text) {
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = invertCharacterCase(text[i]);
	}
	cout << text << endl;
}
int main() {
	invertAllStringLettersCase(readText("Enter the text you want to invert.."));
}