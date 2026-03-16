#include <iostream>
using namespace std;
int readNum(string massege) {
    cout << massege << endl;
    int num;
    cin >> num;
    return num;
}
bool checkPrimeNumber(int num) {
    for (int i = 2; i <= num/2; i++)
    {
        if (num % i == 0 || num == 2 || num == 1)
            return false;
    }
    return true;
}
int randomNumber(int from, int to) {
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}
void fillArray(int array1[100], int arrayLength) {
    for (int i = 0; i < arrayLength; i++)
    {
        array1[i] = randomNumber(1, 99);
    }
}
void addArrayEliment(int array[100], int& length, int eliment) {
    length++;
    array[length - 1] = eliment;
}

void copyPrimeNumbers(int array1[100], int array2[100], int arrayLength, int& length) {
    for (int i = 0; i < arrayLength; i++)
    {
        if (checkPrimeNumber(array1[i]))
            addArrayEliment(array2, length, array1[i]);
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
    int array1[100], array2[100], arrayLength = readNum("enter array length"), length = 0;
    fillArray(array1, arrayLength);
    cout << "array1:" << endl;
    printArray(array1, arrayLength);
    copyPrimeNumbers(array1, array2, arrayLength, length);
    cout << "array2:" << endl;
    printArray(array2, length);

}