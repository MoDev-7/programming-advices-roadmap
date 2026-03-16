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
string removePunctuationCharacters(string text) {
	string newText = "";
	for (int i = 0; i < text.length(); i++)
	{
		if (!ispunct(text[i]))
			newText += text[i];
	}
	return newText;
}
int main() {
	string text = "(ab(*&(*&?>?<NMdskljlfjcd?)&*%^*^##";
	cout << removePunctuationCharacters(text);
}