#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
string clinetFileName = "Clinets.txt";
struct stClient {
	string accountNumber = "";
	string pinCode = "";
	string name = "";
	string phone = "";
	int accountBalance = 0;
	bool markForDelet = false;
};
enum chooseAnOption {
	showClientList = 1,
	addNewClient = 2,
	deleteClient = 3,
	updateClientInfo = 4,
	findClient = 5,
	exitMenue = 0
};
enum typeOfPrint {
	tableType = 0,
};
vector <stClient> loadDataFromFile();
string readText(string massege) {
	cout << massege << endl;
	string text;
	getline(cin, text);
	return text;
}


//--------------------------------------------------------------
// Show clients list :
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
void printClientRecord(stClient Client, typeOfPrint type) {
	cout << setw(2) << left << "|" << setw(18) << left << Client.accountNumber << setw(2) << left << "|" << setw(18) << left << Client.pinCode << setw(2) << left << "|" << setw(28) << left << Client.name << setw(2) << left << "|" << setw(18) << left << Client.phone << setw(2) << left << "|" << setw(18) << left << Client.accountBalance << endl;
}
void printClinetsFromFile(vector <stClient> vClinets) {
	printHeader();
	for (stClient& clinet : vClinets) {
		printClientRecord(clinet, typeOfPrint::tableType);
	}
	printLowLine();
}
//--------------------------------------------------------------


//--------------------------------------------------------------
// Add client to file :
bool searchClinetByAccountNumber(vector <stClient>& vClinets, stClient& clinet, string accountNumber) {
	for (stClient& vclinet : vClinets) {
		if (vclinet.accountNumber == accountNumber) {
			clinet = vclinet;
			return true;
		}
	}
	return false;
}
stClient readNewClient(vector <stClient> vClients) {
	stClient client;
	cout << "Enter Account Number ? ";
	getline(cin >> ws, client.accountNumber);
	while (searchClinetByAccountNumber(vClients, client, client.accountNumber)) {
		cout << "This client is already exist.. Enter another account number ? ";
		getline(cin >> ws, client.accountNumber);
	}

	cout << "Enter PinCode ? ";
	getline(cin, client.pinCode);

	cout << "Enter Name ? ";
	getline(cin, client.name);

	cout << "Enter Phone ? ";
	getline(cin, client.phone);

	cout << "Enter Account Balance ? ";
	cin >> client.accountBalance;

	return client;
}
string counvertRecordToLine(stClient client, string separator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += client.accountNumber + separator;
	stClientRecord += client.pinCode + separator;
	stClientRecord += client.name + separator;
	stClientRecord += client.phone + separator;
	stClientRecord += to_string(client.accountBalance);

	return stClientRecord;
}
vector <string> splitTextToWords(string text, string delim = "#//#") {
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
	stClient newClient;
	vector <string> vRecord = splitTextToWords(line, "#//#");
	newClient.accountNumber = vRecord[0];
	newClient.pinCode = vRecord[1];
	newClient.name = vRecord[2];
	newClient.phone = vRecord[3];
	newClient.accountBalance = stod(vRecord[4]);
	return newClient;
}
void addClinetToFileAndVector(string fileName, vector <stClient>& vClinets) {
	fstream file;
	stClient client = readNewClient(vClinets);
	string clinetRecordLine = counvertRecordToLine(client);
	file.open(fileName, ios::out | ios::app);
	if (file.is_open()) {
		file << clinetRecordLine << endl;
		file.close();
	}
	vClinets.push_back(client);
	cout << "Client added sucssesfuly" << endl;
}
//--------------------------------------------------------------


//--------------------------------------------------------------
// Delete Client :
void printClientRecord(stClient client)
{
	cout << "The following is the extracted client record :" << endl;;

	cout << "Account Number  : " << client.accountNumber << endl;
	cout << "PinCode         : " << client.pinCode << endl;
	cout << "Name            : " << client.name << endl;
	cout << "Phone           : " << client.phone << endl;
	cout << "Account Balance : " << client.accountBalance << endl;
}
bool makeMarkToDelet(vector <stClient>& vClients, string accountNumber) {
	for (stClient& clinet : vClients) {
		if (clinet.accountNumber == accountNumber) {
			clinet.markForDelet = true;
			return true;
		}
	}
	return false;
}
vector <stClient> saveClientsDataToFile(string FileName, vector <stClient>vClients)
{
	fstream myFile;
	myFile.open(FileName, ios::out); //overwrite 

	string dataLine;
	if (myFile.is_open())
	{
		for (stClient c : vClients)
		{
			if (c.markForDelet == false)
			{
				// we only write record that are not marked for delete 
				dataLine = counvertRecordToLine(c);
				myFile << dataLine << endl;
			}
		}
		myFile.close();
	}
	return vClients;
}
void deleteClientByAccountNumber(vector <stClient>& vClients)
{
	stClient client;
	char answer = 'n';
	string accountNumber;
	cout << "Enter account number you want to delete ? ";
	cin >> accountNumber;
	cout << "\n";

	if (searchClinetByAccountNumber(vClients, client, accountNumber))
	{
		printClientRecord(client);

		cout << "\n\nAre you sure you want delete client ? n/y ? ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			makeMarkToDelet(vClients, accountNumber);
			saveClientsDataToFile(clinetFileName, vClients);

			vClients = loadDataFromFile();

			cout << "\n\nClient Deleted Successfully. \n";
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << accountNumber << ") is NOT Found!\n";
	}
}
//--------------------------------------------------------------


//--------------------------------------------------------------
// Update Client :
void updateClient(stClient& client) {

	cout << "Enter New PinCode ? ";
	getline(cin >> ws, client.pinCode);

	cout << "Enter New Name ? ";
	getline(cin, client.name);

	cout << "Enter New Phone ? ";
	getline(cin, client.phone);

	cout << "Enter Account New Balance ? ";
	cin >> client.accountBalance;

}
void updateClinetInVector(vector <stClient>& vClinets, string accountNumber) {
	for (stClient& client : vClinets) {
		if (client.accountNumber == accountNumber) {
			updateClient(client);
			break;
		}
	}
}
void UpdateClientByAccountNumber(vector <stClient>& vClients)
{
	stClient client;
	char answer = 'n';
	string accountNumber;
	cout << "Enter account number you want to update ? ";
	cin >> accountNumber;
	cout << "\n";
	if (searchClinetByAccountNumber(vClients, client, accountNumber))
	{
		printClientRecord(client);

		cout << "\n\nAre you sure you want update client ? n/y ?";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			updateClinetInVector(vClients, accountNumber);
			saveClientsDataToFile(clinetFileName, vClients);

			cout << "\n\nClient updated Successfully. \n";
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << accountNumber << ") is NOT Found!\n";
	}
}
//--------------------------------------------------------------


chooseAnOption showMainMenue() {
	system("cls");
	cout << "===============================================" << endl;
	cout << setw(15) << "" << setw(17) << "Main Menue Screen" << endl;
	cout << "===============================================" << endl;
	cout << setw(12) << "" << setw(23) << left << "[1] Show Client List." << endl;
	cout << setw(12) << "" << setw(23) << left << "[2] Add New Client." << endl;
	cout << setw(12) << "" << setw(23) << left << "[3] Delete Client." << endl;
	cout << setw(12) << "" << setw(23) << left << "[4] Update Client Info." << endl;
	cout << setw(12) << "" << setw(23) << left << "[5] Find Client." << endl;
	cout << setw(12) << "" << setw(23) << left << "[0] Exit." << endl;
	cout << "===============================================" << endl;
	cout << "Choose an option ? ";
	int choice;
	cin >> ws >> choice;
	cout << endl;
	return (chooseAnOption)choice;
}
void mainMenue(vector <stClient>& vClients, chooseAnOption choic);
void backTOMainMenue(vector <stClient>& vClients) {
	system("pause");
	mainMenue(vClients, showMainMenue());
}
void  mainMenue(vector <stClient>& vClients, chooseAnOption choic) {
	switch (choic) {
	case chooseAnOption::showClientList: {
		printClinetsFromFile(vClients);
		backTOMainMenue(vClients);
		break;
	}
	case chooseAnOption::addNewClient: {
		addClinetToFileAndVector(clinetFileName, vClients);
		backTOMainMenue(vClients);
		break;
	}
	case chooseAnOption::deleteClient: {
		deleteClientByAccountNumber(vClients);
		backTOMainMenue(vClients);
		break;
	}
	case chooseAnOption::updateClientInfo: {
		UpdateClientByAccountNumber(vClients);
		backTOMainMenue(vClients);
		break;
	}
	case chooseAnOption::findClient: {
		stClient client;
		string accountNumber;
		cout << "Enter account number  ? ";
		cin >> accountNumber;
		if (searchClinetByAccountNumber(vClients, client, accountNumber))
			printClientRecord(client);
		else
			cout << "Not found!\n";
		backTOMainMenue(vClients);
		break;
	}
	case chooseAnOption::exitMenue: {
		system("cls");
		cout << "Thank you for using our program\nMohammad Sukary." << endl;
		break;
	}
	default: {
		cout << "Wrong option, Please choose a number from [0] to [5]" << endl;
		backTOMainMenue(vClients);
		break;
	}
	}
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
	vector <stClient> vClients = loadDataFromFile();
	mainMenue(vClients, showMainMenue());
}