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
void printNum(int num) {
    cout << num << endl;
}
void getPerfectNums(int num) {
    for (int i = 1; i <= num; i++)
    {
        if (checkPerfectNum(i))
            printNum(i);
    }
}
int main()
{
    getPerfectNums(readNum());
}
