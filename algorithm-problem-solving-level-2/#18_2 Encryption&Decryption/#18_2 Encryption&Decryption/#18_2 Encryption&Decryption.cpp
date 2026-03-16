#include <iostream>
#include <string>
using namespace std;
string readWord(string massege) {
	string word;
	cout << massege << endl;
	getline(cin,word);
	return word;
}
string encrypt(string& word, short key) {
	for (int i = 0; i < word.length(); i++)
	{
		word[i] = char((int)word[i] + key);
	}
	return word;
}
string decrypt(string& word, short key) {
	for (int i = 0; i < word.length(); i++)
	{
		word[i] = char((int)word[i] - key);
	}
	return word;
}
void printWord(string word) {
	cout << word << endl;
}
int main()
{
	int key = 1;
	string word = readWord("enter a name");
	printWord(encrypt(word, key));
	printWord(decrypt(word, key));
}
