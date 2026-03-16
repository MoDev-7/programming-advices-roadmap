#include <iostream>
using namespace std;
void printArray(int array[100], int arrayLength) {
    for (int i = 0; i < arrayLength; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int readNum(string massege) {
    cout << massege << endl;
    int num;
    cin >> num;
    return num;
}
bool checkValue() {
    int num = readNum("do you want to add more numbers?\n[0] No\n[1] Yes");
    if (num == 0)
        return false;
    else if (num == 1)
        return true;
}
void addArrayEliment(int array[100], int& length, int eliment) {
    length++;
    array[length - 1] = eliment;
}
int addEliment(int array[100]) {
    int length = 0;
    bool value = true;
    while (value) {
        addArrayEliment(array, length, readNum("enter number to add"));
        value = checkValue();
    }
    printArray(array, length);
    return length;
}
int main()
{
    int array[100];
    cout << endl << addEliment(array);
}