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
            array[i][j] = getRandomNumber(1, 10);
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
int sumOfMatrix(int array[3][3], short rows, short cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += array[i][j];
        }
    }
    return sum;
}
int main() {
    srand((unsigned)time(NULL));
    int array1[3][3], array2[3][3];
    fillMatrixWithRandomNumber(array1, 3, 3);
    printMatrix(array1, 3, 3);
    cout << endl;
    fillMatrixWithRandomNumber(array2, 3, 3);
    printMatrix(array2, 3, 3);
    cout << endl;
    if (sumOfMatrix(array1, 3, 3) == sumOfMatrix(array2, 3, 3))
        cout << "Yes\n";
    else
        cout << "No\n";
}