#include <iostream>
#include <string>
using namespace std;
char readCharacter(string massege) {
	cout << massege << endl;
	char character;
	cin >> character;
	return character;
}
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
int main() {
	invertCharacterCase(readCharacter("Enter character you want to invert.."));
}