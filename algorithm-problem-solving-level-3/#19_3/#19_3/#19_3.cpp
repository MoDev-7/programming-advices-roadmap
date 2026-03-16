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
bool isNumberInMatrix(int array[3][3], short rows, short cols, int number) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (array[i][j] == number)
                return true;
        }
    }
    return false;
}
void printMaxNumberInMatrix(int array[3][3], short rows, short cols) {
    int maxNumber = array[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (array[i][j] > maxNumber)
                maxNumber = array[i][j];
        }
    }
    cout << maxNumber << endl;
}
void printMinNumberInMatrix(int array[3][3], short rows, short cols) {
    int minNumber = array[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (array[i][j] < minNumber)
                minNumber = array[i][j];
        }
    }
    cout << minNumber << endl;
}
int main() {
    srand((unsigned)time(NULL));
    int array[3][3];
    fillMatrixWithRandomNumber(array, 3, 3);
    printMatrix(array, 3, 3);
    printMaxNumberInMatrix(array, 3, 3);
    printMinNumberInMatrix(array, 3, 3);
}