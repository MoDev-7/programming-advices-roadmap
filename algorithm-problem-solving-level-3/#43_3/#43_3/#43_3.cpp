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
string uppperAllString(string text) {
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = toupper(text[i]);
	}
	return text;
}
string replaceWord(string word, string replaceTo, string wordToReplace, bool matchCase = true) {
	if (matchCase) {
		if (word == wordToReplace)
			word = replaceTo;
	}
	else {
		if (uppperAllString(word) == uppperAllString(wordToReplace))
			word = replaceTo;
	}
	return word;
}
string joinStringFromVector(vector <string> vWords, string delim) {
	string words = "";
	for (string& word : vWords) {
		words = words + word + delim;
	}
	return words.substr(0, words.length() - delim.length());
}
string replaceWordInStringUsingCustomFunction(string text, string replaceTo, string wordToReplace, bool matchCase = true) {
	vector <string> vWords = splitTextToWords(text, " ");
	for (string& word : vWords) {
		word = replaceWord(word, replaceTo, wordToReplace, matchCase);
	}
	text = joinStringFromVector(vWords, " ");
}
int main() {
	string text = readText("Enter text..");
	cout << replaceWordInStringUsingCustomFunction(text, "iii", "jjj", 0);
}