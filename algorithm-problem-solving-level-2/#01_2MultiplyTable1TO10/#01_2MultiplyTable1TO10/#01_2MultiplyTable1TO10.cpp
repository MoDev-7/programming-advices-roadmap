#include <iostream>
using namespace std;
void tabelHeader() {
	for (int i = 1; i <= 10; i++)
	{
		cout << "\t" << i;
	}
	cout << "\n__________________________________________________________________________________________ \n";
}
void multipleTible() {
	tabelHeader();
	for (int i = 1; i <= 10; i++)
	{
		cout << i ;
		for (int j = 1; j <= 10; j++)
		{
			cout << "\t" << "|" << i * j;
		}
		cout << endl;
	}
}
int main()
{
	multipleTible();
}