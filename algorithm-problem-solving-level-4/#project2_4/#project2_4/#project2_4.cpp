#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
string clinetFileName = "Clinets.txt";
//Structures:
struct stClient {
	string accountNumber = "";
	string pinCode = "";
	string name = "";
	string phone = "";
	int accountBalance = 0;
	bool markForDelet = false;
};

//Enums:
enum enMainMenueOptions {
	eQuickWhithdraw = 1,
	eWhithdraw = 2,
	eDeposit = 3,
	eCheckBalance = 4,
	eLogout = 0
};

//==============================
//Functions:
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
void saveClientsDataToFile(vector <stClient>vClients)
{
	fstream myFile;
	myFile.open(clinetFileName, ios::out); //overwrite 

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
}

//==============================

// Check Balance:
void showBalanceTitle() {
	cout << "==================================" << endl;
	cout << right << setw(24) << "Balance Screen" << endl;
	cout << "==================================" << endl;
}
void showBalance(stClient client) {
	cout << "Your balance is : " << client.accountBalance << endl;
}

// Whithdraw:
short readMultipleOf5Amount() {
	cout << "Enter the amount you want to whithdraw (positiv & multiple of 5) ? " << endl;
	short amount;
	cin >> amount;
	while ((amount % 5 != 0) || amount < 1) {
		cout << "Invalid amount, please enter a (positiv & multiple of 5) ? " << endl;
		cin >> amount;
	}
	return amount;
}
short showeWhithdrawMenue() {
	cout << "==================================" << endl;
	cout << right << setw(25) << "Whithdraw Screen" << endl;
	cout << "==================================" << endl;
	cout << "Enter the amount you want to whithdraw (multiple of 5) ? " << endl;
	short amount = readMultipleOf5Amount();
	return amount;
}
void performWhithdraw(stClient& client, short amount) {
	client.accountBalance -= amount;
}
bool tryWhithdraw(stClient& client, short amount) {
	if (amount > client.accountBalance) {
		cout << "You don't have enough balance to whithdraw this amount" << endl;
		return false;
	}
	else {
		cout << "Are you sure ?" << endl;
		char answer;
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			performWhithdraw(client, amount);
			cout << "Whithdraw successfully" << endl;
			return true;
		}
		else {
			cout << "Whithdraw cancelled" << endl;
			return false;
		}
	}
}
void whithdraw(stClient& client) {
	tryWhithdraw(client, showeWhithdrawMenue());
	showBalance(client);
}

//Quick Whithdraw:
short showQuickWhithdrawMenue() {
	cout << "==================================" << endl;
	cout << right << setw(28) << "Quick Whithdraw Screen" << endl;
	cout << "==================================" << endl;
	cout << "[1] 200" << endl;
	cout << "[2] 400" << endl;
	cout << "[3] 600" << endl;
	cout << "[4] 800" << endl;
	cout << "[5] 1000" << endl;
	cout << "[0] Exit" << endl;
	cout << "==================================" << endl;
	short option;
	do {
		cout << "Please choose an option ? ";
		cin >> option;
	} while (option < 0 || option > 5);
	return option * 200;
}
void quickWhithdraw(stClient& client) {
	short amount = showQuickWhithdrawMenue();
	if (amount == 0)
		return ;
	tryWhithdraw(client, amount);
	showBalance(client);
}

//Deposit:
short showDepositMenue() {
	cout << "==================================" << endl;
	cout << right << setw(24) << "Deposit Screen" << endl;
	cout << "==================================" << endl;
	return readMultipleOf5Amount();
}
void deposit(stClient& client) {
	short amount = showDepositMenue();
	client.accountBalance += amount;
	cout << "Deposit successfully" << endl;
	showBalance(client);
}

//Main Menue:
enMainMenueOptions showMainMenue() {
	cout << "===================================" << endl;
	cout << right << setw(28) << "ATM Main Menue Screen" << endl;
	cout << "===================================" << endl;
	cout << "[1] Quick Whithdraw" << endl;
	cout << "[2] Whithdraw" << endl;
	cout << "[3] Deposit" << endl;
	cout << "[4] Check Balance" << endl;
	cout << "[0] Logout" << endl;
	cout << "===================================" << endl;
	short option;
	do {
		cout << "Please choose an option ? ";
		cin >> option;
	} while (option < 0 || option > 4);
	system("cls");
	return (enMainMenueOptions)option;
}
bool performMainMenueOption(stClient& client, enMainMenueOptions option) {
	switch (option) {
		case enMainMenueOptions::eQuickWhithdraw: {
			quickWhithdraw(client);
			system("pause");
			return true;
		}
		case enMainMenueOptions::eWhithdraw: {
			whithdraw(client);
			system("pause");
			return true;
		}
		case enMainMenueOptions::eDeposit: {
			deposit(client);
			system("pause");
			return true;
		}
		case enMainMenueOptions::eCheckBalance: {
			showBalanceTitle();
			showBalance(client);
			system("pause");
			return true;
		}
		case enMainMenueOptions::eLogout: {
			return false;
		}
	}
}
void mainMenue(stClient& client, vector<stClient>& clients) {
	bool logout = false;
	while (!logout) {
		enMainMenueOptions option = showMainMenue();
		logout = !performMainMenueOption(client, option);
		system("pause");
		system("cls");
	}
	saveClientsDataToFile(clients);
}

//Login Screen:
void showLoginScreen(string& accountNumber, string& pinCode) {
	cout << "==================================" << endl;
	cout << right << setw(22) << "Login Screen" << endl;
	cout << "==================================" << endl;
	cout << "Please enter your account number ? " << endl;
	getline(cin >> ws, accountNumber);
	cout << "Please enter your pin code ? " << endl;
	cin >> pinCode;
}
bool checkLogin(vector<stClient>& clients, string accountNumber, string pinCode) {
	for (stClient client : clients) {
		if(client.accountNumber == accountNumber && client.pinCode == pinCode) {
			return true;
		}
	}
	return false;
}
stClient& getCurrentClient(vector<stClient>& clients, string accountNumber) {
	for (stClient& client : clients) {
		if (client.accountNumber == accountNumber) {
			return client;
		}
	}
}
bool login(vector<stClient>& clients) {
	string accountNumber, pinCode;
	showLoginScreen(accountNumber, pinCode);
	if (checkLogin(clients, accountNumber, pinCode)) {
		cout << "Login successfully" << endl;
		system("pause");
		system("cls");
		mainMenue(getCurrentClient(clients, accountNumber), clients);
		return false;
	}
	else {
		cout << "Login failed" << endl;
		system("pause");
		system("cls");
		return false;
	}
}

int main() {
	vector<stClient> clients = loadDataFromFile();
	bool loginBool = false;
	while (!loginBool) {
		loginBool = login(clients);
	}
}