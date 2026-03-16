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
stClient ReadNewClient()
{
	stClient Client;

	cout << "Enter Account Number ? ";
	getline(cin >> ws, Client.AccountNumber);

	cout << "Enter PinCode ? ";
	getline(cin, Client.PinCode);

	cout << "Enter Name ? ";
	getline(cin, Client.Name);

	cout << "Enter Phone ? ";
	getline(cin, Client.Phone);

	cout << "Enter Account Balance ? ";
	cin >> Client.AccountBalance;

	return Client;

}
string CounvertRecordToLine(stClient Client, string Separator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.AccountNumber + Separator;
	stClientRecord += Client.PinCode + Separator;
	stClientRecord += Client.Name + Separator;
	stClientRecord += Client.Phone + Separator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}
void addClinetToFile(string fileName, string clinetRecordLine) {
	fstream file;
	file.open(fileName, ios::out | ios::app);
	if (file.is_open()) {
		file << clinetRecordLine << endl;
		file.close();
	}
}
void addClinet() {
	stClient newClinet = ReadNewClient();
	addClinetToFile(clinetFileName, CounvertRecordToLine(newClinet, "#//#"));
}
void addClinets() {
	char yes = 'Y';
	do {
		system("cls");
		addClinet();
		cout << "Added sucsussfully, Do you want to add more clinets ? [Y/y] ";
		cin >> yes;
	} while (yes == 'Y' || yes == 'y');
}
int main() {
	addClinets();
}