#include <iostream>
using namespace std;
string readWord(string massege) {
	string word;
	cout << massege << endl;
	cin >> word;
	return word;
}
bool checkPassword(string password, string trial) {
	return password == trial;
}
bool trials(string password) {
	string word = "";
	int count = 1;
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				word = word + char(i);
				word = word + char(j);
				word = word + char(k);
				cout << "trial [" << count << "] is " << word << endl;
				if (checkPassword(password, word)) {
					cout << "password found : " << word << endl << "after " << count << endl;
					return true;
				}
				word = "";
				count++;
			}
		}
	}
}
int main()
{
	trials(readWord("enter a password"));
}