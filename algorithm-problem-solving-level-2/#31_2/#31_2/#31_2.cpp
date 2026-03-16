#include <iostream>
using namespace std;
int readNum(string massege) {
    cout << massege << endl;
    int num;
    cin >> num;
    return num;
}
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
int randomNumber(int from, int to) {
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

void getArray(int array[100], int lengthOfArray) {
    for (int i = 0; i < lengthOfArray; i++)
    {
        array[i] = i + 1;
    }
}
void editArray(int array[100], int lengthOfArray) {
    for (int i = 0; i < lengthOfArray; i++)
    {
        swap(array[randomNumber(1, lengthOfArray) - 1], array[randomNumber(1, lengthOfArray) - 1]);
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
    int array[100], lengthOfArray = readNum("enter length");
    getArray(array, lengthOfArray);
    printArray(array, lengthOfArray);
    editArray(array, lengthOfArray);
    printArray(array, lengthOfArray);

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
