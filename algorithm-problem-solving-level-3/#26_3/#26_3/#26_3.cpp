#include <iostream>
#include <string>
using namespace std;
string readText(string massege) {
	cout << massege << endl;
	string text;
	getline(cin, text);
	return text;
}
void uppperAllString(string text) {
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = toupper(text[i]);
	}
	cout << text << endl;
}
void lowerAllString(string text) {
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = tolower(text[i]);
	}
	cout << text << endl;
}
int main() {
	uppperAllString(readText("Enter the text you want to upper.."));
	lowerAllString(readText("Enter the text you want to lower.."));
}