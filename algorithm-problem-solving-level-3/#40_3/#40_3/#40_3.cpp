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
string joinStringFromVector(string arrWords[], int length, string delim) {
	string words = "";
	for (int i = 0; i < length; i++)
	{
		words = words + arrWords[i] + delim;
	}
	return words.substr(0, words.length() - delim.length());
}
int main() {
	vector <string> vWords = { "Mohammad","ALi","Anas" };
	string arrWords[] = { "Mohammad","ALi","Anas" };
	cout << "Join string from vector" << endl;
	cout << joinStringFromVector(vWords, " ") << endl;
	cout << "Join string from array" << endl;
	cout << joinStringFromVector(arrWords, 3, " ") << endl;
}