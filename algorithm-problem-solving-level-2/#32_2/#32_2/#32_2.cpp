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
void newArray(int array1[100], int arrayLength) {
    for (int i = 0; i < arrayLength; i++)
    {
        array1[i] = randomNumber(1, 99);
    }
}
void copyArray(int array2[100], int array1[100], int arrayLength) {
    for (int i = 0; i < arrayLength; i++)
    {
        array2[i] = array1[arrayLength - 1 - i];
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
    int array1[100], array2[100], arrayLength = readNum("enter length");
    newArray(array1, arrayLength);
    printArray(array1, arrayLength);
    copyArray(array2, array1, arrayLength);
    printArray(array2, arrayLength);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
