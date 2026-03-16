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
void fillArray(int array[100], int arrayLength) {
    for (int i = 0; i < arrayLength; i++)
    {
        array[i] = randomNumber(1, 99);
    }
}
void printArray(int array[100], int arrayLength) {
    for (int i = 0; i < arrayLength; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
void search(int array[100], int arrayLength) {
    int num = readNum("enter a num to search");
    for (int i = 0; i < arrayLength; i++)
    {
        if (array[i] == num) {
            cout << "numberr is " << num << endl << "position is " << i << endl << "order is " << i + 1 << endl;
            break;
        }
        else if (i == arrayLength - 1)
            cout << "not found" << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int array[100], arrayLength = readNum("enter array length");
    fillArray(array, arrayLength);
    printArray(array, arrayLength);
    search(array, arrayLength);

}