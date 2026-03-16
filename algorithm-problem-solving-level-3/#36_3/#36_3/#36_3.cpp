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
short countWords(string text) {
	short count = 0;
	string word = "";
	string delim = " ";
	short pos = 0;
	while ((pos = text.find(delim)) != std::string::npos) {
		word = text.substr(0, pos);
		if (word != "")
			count++;
		text.erase(0, pos + delim.length());
	}
	if (text != "")
		count++;
	return count;
}
int main() {
	string text = readText("Enter text..");
	cout << "Number of words in your text is : " << countWords(text);
}