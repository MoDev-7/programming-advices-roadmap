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
struct stClinet
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	int AccountBalance = 0;
	bool markForDelet = false;

};
stClinet ReadNewClient(stClinet Client)
{

	cout << "Enter PinCode ? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name ? ";
	getline(cin, Client.Name);

	cout << "Enter Phone ? ";
	getline(cin, Client.Phone);

	cout << "Enter Account Balance ? ";
	cin >> Client.AccountBalance;

	return Client;

}
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
stClinet convertLineToRecord(string line) {
	stClinet newClinet;
	vector <string> vRecord = splitTextToWords(line, "#//#");
	newClinet.AccountNumber = vRecord[0];
	newClinet.PinCode = vRecord[1];
	newClinet.Name = vRecord[2];
	newClinet.Phone = vRecord[3];
	newClinet.AccountBalance = stod(vRecord[4]);
	return newClinet;
}
void printClientRecord(stClinet Client)
{
	cout << "\n\nThe following is the extracted client record : \n\n";

	cout << "Account Number  : " << Client.AccountNumber << endl;
	cout << "PinCode         : " << Client.PinCode << endl;
	cout << "Name            : " << Client.Name << endl;
	cout << "Phone           : " << Client.Phone << endl;
	cout << "Account Balance : " << Client.AccountBalance << endl;
}
vector <stClinet> loadDataFromFile() {
	vector <stClinet> vClinets;
	stClinet clinet;
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
bool searchClinetByAccountNumber(vector <stClinet>& vClinets, stClinet& clinet, string accountNumber) {
	for (stClinet& vclinet : vClinets) {
		if (vclinet.AccountNumber == accountNumber) {
			clinet = vclinet;
			return true;
		}
	}
	return false;
}
bool updateClinetInVector(vector <stClinet>& vClinets, string accountNumber) {
	for (stClinet& clinet : vClinets) {
		if (clinet.AccountNumber == accountNumber) {
			clinet = ReadNewClient(clinet);
			return true;
		}
	}
	return false;
}
string CounvertRecordToLine(stClinet Client, string Separator = "#//#")
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
vector <stClinet> SaveClientsDataToFile(string FileName, vector <stClinet>vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out); //overwrite 

	string DataLine;
	if (MyFile.is_open())
	{
		for (stClinet C : vClients)
		{
			if (C.markForDelet == false)
			{
				// we only write record that are not marked for delete 
				DataLine = CounvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return vClients;
}
bool UpdateClientByAccountNumber(string accountNumber, vector <stClinet>& vClients)
{
	stClinet client;
	char Answer = 'n';

	if (searchClinetByAccountNumber(vClients, client, accountNumber))
	{
		printClientRecord(client);

		cout << "\n\nAre you sure you want update client ? n/y ?";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			updateClinetInVector(vClients, accountNumber);
			SaveClientsDataToFile(clinetFileName, vClients);

			cout << "\n\n Client updated Successfully. \n";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << accountNumber << ") is NOT Found!\n";
		return false;
	}
}
int main() {
	string accountNumber = readText("Enter account number to search? ");
	vector <stClinet> vClinets = loadDataFromFile();
	UpdateClientByAccountNumber(accountNumber, vClinets);
}