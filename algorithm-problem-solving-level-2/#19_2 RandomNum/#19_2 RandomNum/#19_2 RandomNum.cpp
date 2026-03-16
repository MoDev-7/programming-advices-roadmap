#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int randomNumber(int from, int to) {
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}
int main()
{
    srand((unsigned)time(NULL));
    cout << randomNumber(1, 10) << endl;
    cout << randomNumber(1, 13) << endl;
    cout << randomNumber(5, 10) << endl;
}