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
string replaceWordInStringUsingBultInFunction(string text, string wordToReplace, string replaceTo) {
	short pos = text.find(wordToReplace);
	while (pos != std::string::npos) {
		text = text.replace(pos, wordToReplace.length(), replaceTo);
		pos = text.find(wordToReplace);
	}
	return text;
}
int main() {
	string text = readText("Enter text..");
	cout << replaceWordInStringUsingBultInFunction(text, "iii ", " jjj ");
}