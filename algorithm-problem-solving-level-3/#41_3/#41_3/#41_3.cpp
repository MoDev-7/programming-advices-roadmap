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
vector <string> splitTextToWords(string text, string delim) {
	vector <string> vWords;
	string word = "";
	short pos = 0;
	while ((pos = text.find(delim)) != std::string::npos) {
		word = text.substr(0, pos);
		if (word != "")
			vWords.push_back(word);
		text.erase(0, pos + delim.length());
	}
	if (text != "")
		vWords.push_back(text);
	return vWords;
}
string reversStringsWords(string text) {
	string newText = "";
	vector <string> vWords = splitTextToWords(text, " ");
	vector <string>::iterator it = vWords.end();
	while (it != vWords.begin()) {
		--it;
		newText += *it + " ";

	}
	newText = newText.substr(0, newText.length() - 1);
	return newText;
}
int main() {
	string text = readText("Enter text..");
	cout << reversStringsWords(text);
}