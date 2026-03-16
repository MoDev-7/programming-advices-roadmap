#include <iostream>
using namespace std;
int readNum() {
    int num;
    cout << "enter a num\n";
    cin >> num;
    return num;
}
bool checkRemainder0(int num, int div) {
    return num % div == 0;
}
bool checkPerfectNum(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++)
    {
        if (checkRemainder0(num, i))
            sum = sum + i;
    }
    return sum == num;
}
void printResult(bool value) {
    if (value)
        cout << "perfect\n";
    else
        cout << "not perfect\n";
}
int main()
{
    printResult(checkPerfectNum(readNum()));
}