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
void printMiddleRowInMatrix(int array[3][3], short rowNumber, short cols) {
    rowNumber = 1;
    for (int i = 0; i < cols; i++)
    {
        printf("%02d ", array[2][i]);
    }
    cout << endl;
}
void printMiddleColInMatrix(int array[3][3], short rows, short colNumber) {
    colNumber = 1;
    for (int i = 0; i < rows; i++)
    {
        printf("%02d ", array[i][2]);
    }
    cout << endl;
}
int main() {
    srand((unsigned)time(NULL));
    int array[3][3];
    fillMatrixWithRandomNumber(array, 3, 3);
    printMatrix(array, 3, 3);
    printMiddleRowInMatrix(array, 3, 3);
    printMiddleColInMatrix(array, 3, 3);

}