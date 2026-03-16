#include <iostream>
using namespace std;
int readNum(string massege) {
    cout << massege << endl;
    int num;
    cin >> num;
    return num;
}

int randomNumber(int from, int to) {
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}
void readArray(int array[100], int& arrayLength) {
    arrayLength = readNum("enter array length");
    for (int i = 0; i < arrayLength; i++)
    {
        array[i] = randomNumber(10,99);
    }
}
void printArray(int array[100], int arrayLength) {
    for (int i = 0; i < arrayLength; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));
    int array[100], arrayLength;
    readArray(array, arrayLength);
    printArray(array, arrayLength);
}