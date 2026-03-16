#include <iostream>
#include <string>
using namespace std;
char readCharacter(string massege) {
	cout << massege << endl;
	char character;
	cin >> character;
	return character;
}
bool isCharacterVowel(char character) {
	character = tolower(character);
	return (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u');
}
int main() {
	char character = readCharacter("Enter character..");
	if (isCharacterVowel(character))
		cout << "Yes\n";
	else
		cout << "No\n";
}