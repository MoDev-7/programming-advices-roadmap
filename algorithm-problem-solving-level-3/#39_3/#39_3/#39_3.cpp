#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
string joinStringFromVector(vector <string> vWords, string delim) {
	string words = "";
	for (string& word : vWords) {
		words = words + word + delim;
	}
	return words.substr(0, words.length() - delim.length());
}
int main() {
	vector <string> vWords = { "Mohammad","ALi","Anas" };
	cout << joinStringFromVector(vWords, " ");
}