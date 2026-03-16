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
            array[i][j] = getRandomNumber(1, 9);
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
void multiplyMatrix(int array1[3][3], int array2[3][3], int array3[3][3], short rows, short cols) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array3[i][j] = array1[i][j] * array2[i][j];
        }
    }
}
int main() {
    srand((unsigned)time(NULL));
    int array1[3][3], array2[3][3], array3[3][3];
    fillMatrixWithRandomNumber(array1, 3, 3);
    fillMatrixWithRandomNumber(array2, 3, 3);
    printMatrix(array1, 3, 3);
    cout << "______________________\n";
    printMatrix(array2, 3, 3);
    cout << "______________________\n";
    multiplyMatrix(array1, array2, array3, 3, 3);
    printMatrix(array3, 3, 3);
}