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

void copyOddNumbers(int array1[100], int array2[100], int arrayLength, int& length) {
    for (int i = 0; i < arrayLength; i++)
    {
        if (array1[i] % 2 != 0)
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
    int array1[100],array2[100], arrayLength = readNum("enter array length"), length = 0;
    fillArray(array1, arrayLength);
    cout << "array1:" << endl;
    printArray(array1, arrayLength);
    copyOddNumbers(array1, array2, arrayLength, length);
    cout << "array2:" << endl;
    printArray(array2, length);
}