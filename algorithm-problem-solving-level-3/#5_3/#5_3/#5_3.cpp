#include <iostream>
using namespace std;
int getRandomNumber(int from, int to) {
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}
void fillMatrixWithRandomNumber(int array[3][3], short rows, short cols) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] = getRandomNumber(1, 99);
        }
    }
}
void printMatrix(int array[3][3], short rows, short cols) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%0*d ", 2, array[i][j]);
        }
        cout << endl;
    }
}
int colSum(int array[3][3], short rows, short colNumber) {
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        sum = sum + array[i][colNumber];
    }
    return sum;
}
void sumMatrixColsInArray(int array[3][3], short rows, short cols, int arrayOfSum[3]) {
    for (int i = 0; i < cols; i++)
    {
        arrayOfSum[i] = colSum(array, rows, i);
    }
}
void printArray(int array[3], short length) {
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
int main() {
    srand((unsigned)time(NULL));
    int array[3][3];
    int arrayOfSum[3];
    fillMatrixWithRandomNumber(array, 3, 3);
    printMatrix(array, 3, 3);
    sumMatrixColsInArray(array, 3, 3, arrayOfSum);
    printArray(arrayOfSum, 3);
}