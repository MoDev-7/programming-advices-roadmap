#include <iostream>
using namespace std;
enum character {multiplied = '*',plus = '+', minus = '-', divided = '/' };
float readNum(string massege) {
    float num;
    cout << massege;
    cin >> num;
    return num;
}
char readChar() {
    char operation;
    cout << "choose an operation \n";
    cin >> operation;
    return operation;
}
float doo(char c, float n1, float n2) {
    switch (c) {
    case character::plus:
        return n1 + n2;
        break;
    case character::minus:
        return n1 - n2;
        break;
    case character::multiplied :
        return n1 * n2;
        break;
    case character::divided :
        return n1 / n2;
        break;
    default :
        cout << "wrong option\n";
        doo(readChar(), n1, n2);
    }
}
void printResult(float result) {
    cout << result;
}

int main()
{
    float n1 = readNum("enter first num");
    float n2 = readNum("enter second num");
    printResult(doo(readChar(), n1, n2));
}