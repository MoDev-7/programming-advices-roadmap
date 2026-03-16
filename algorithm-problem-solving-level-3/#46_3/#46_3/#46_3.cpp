#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
struct stClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	int AccountBalance = 0;

};
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
stClient convertLineToRecord(string line) {
	stClient newClinet;
	vector <string> vRecord = splitTextToWords(line, "#//#");
	newClinet.AccountNumber = vRecord[0];
	newClinet.PinCode = vRecord[1];
	newClinet.Name = vRecord[2];
	newClinet.Phone = vRecord[3];
	newClinet.AccountBalance = stod(vRecord[4]);
	return newClinet;
}
void printClientRecord(stClient Client)
{
	cout << "\n\nThe following is the extracted client record : \n\n";

	cout << "Account Number  : " << Client.AccountNumber << endl;
	cout << "PinCode         : " << Client.PinCode << endl;
	cout << "Name            : " << Client.Name << endl;
	cout << "Phone           : " << Client.Phone << endl;
	cout << "Account Balance : " << Client.AccountBalance << endl;
}
int main() {
	string line = "A150#//#1234#//#Mohammed Sukary#//#079999#//#5270.00000";
	stClient newClinet = convertLineToRecord(line);
	printClientRecord(newClinet);
}