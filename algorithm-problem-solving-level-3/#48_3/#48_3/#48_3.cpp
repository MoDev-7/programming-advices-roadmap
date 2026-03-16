#include <iostream>
#include <fstream>
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
void printHeader() {
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(42) << "" << setw(42) << left << "Clinet list (3) clinet (s)" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(20) << left << "| Account Number" << setw(20) << left << "| Pin Code" << setw(30) << left << "| Name" << setw(20) << left << "| Phone" << setw(20) << left << "| Account Balance" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
}
void printLowLine() {
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
}
void printClientRecord(stClient Client)
{
	cout << setw(2) << left << "|" << setw(18) << left << Client.AccountNumber << setw(2) << left << "|" << setw(18) << left << Client.PinCode << setw(2) << left << "|" << setw(28) << left << Client.Name << setw(2) << left << "|" << setw(18) << left << Client.Phone << setw(2) << left << "|" << setw(18) << left << Client.AccountBalance << endl;
}
void printClinetsFromFile(vector <stClient> vClinets) {
	printHeader();
	for (stClient& clinet : vClinets) {
		printClientRecord(clinet);
	}
	printLowLine();
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
int main() {
	vector <stClient> vClinets = loadDataFromFile();
	printClinetsFromFile(vClinets);
}