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
stClient ReadNewClient()
{
	stClient Client;

	cout << "Enter Account Number ? ";
	getline(cin, Client.AccountNumber);

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
int main() {
	stClient newClinet = ReadNewClient();
	cout << endl << CounvertRecordToLine(newClinet);
}