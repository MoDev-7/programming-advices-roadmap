#include <iostream>
using namespace std;
int readNum(string massege) {
    cout << massege << endl;
    int num;
    cin >> num;
    return num;
}
void readArray(int array[100], int& arrayLength) {
    arrayLength = readNum("enter array length");
    for (int i = 0; i < arrayLength; i++)
    {
        cout << "enter element[" << i + 1 << "]" << endl;
        cin >> array[i];
    }
}
void printArray(int array[100], int arrayLength) {
    for (int i = 0; i < arrayLength; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
int timesRepeated(int array[100], int arrayLength, int numberToChek) {
    int count = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        if (array[i] == numberToChek)
            count++;
    }
    return count;
}
int main()
{
    int array[100];
    int arrayLength;
    readArray(array, arrayLength);
    printArray(array, arrayLength);
    int numberToChek = readNum("enter number you want to chek");
    cout << timesRepeated(array, arrayLength, numberToChek) << endl;
}