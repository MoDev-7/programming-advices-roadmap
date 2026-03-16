#include <iostream>
#include <fstream>
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
struct stClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	int AccountBalance = 0;

};
string clinetFileName = "Clinets.txt";
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
vector <stClient> loadDataFromFile() {
	vector <stClient> vClinets;
	stClient clinet;
	string clinetLineRecord;
	fstream file;
	file.open(clinetFileName, ios::in);
	if (file.is_open()) {
		while (getline(file, clinetLineRecord)) {
			clinet = convertLineToRecord(clinetLineRecord);
			vClinets.push_back(clinet);
		}
		file.close();
	}
	return vClinets;
}
bool searchClinetByAccountNumber(stClient& clinet, string accountNumber) {
	vector <stClient> vClinets = loadDataFromFile();
	for (stClient& vclinet : vClinets) {
		if (vclinet.AccountNumber == accountNumber) {
			clinet = vclinet;
			return true;
		}
	}
	return false;
}
int main() {
	string accountNumber = readText("Enter account number to search? ");
	stClient clinet;
	if (searchClinetByAccountNumber(clinet, accountNumber))
		printClientRecord(clinet);
	else
		cout << "Clinet whith account number (" << accountNumber << ") is not found\n";
}