#include <iostream>
using namespace std;
void readNum(int& n1, int& n2) {
    cout << "enter n1\n";
    cin >> n1;
    cout << "enter n2\n";
    cin >> n2;
}
void swapnums(int& n1, int& n2) {
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
    }
void printNums(int n1, int n2) {
    cout << "n1: " << n1 << endl << "n2: " << n2 << endl;
}
int main()
{
    int n1, n2;
    readNum(n1, n2);
    swapnums(n1, n2);
    printNums(n1, n2);
}