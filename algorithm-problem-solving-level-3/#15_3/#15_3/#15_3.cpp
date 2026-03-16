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
short countNumberInMatrix(int array[3][3], short rows, short cols, int number) {
    short count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (array[i][j] == number)
                count++;
        }
    }
    return count;
}
int main() {
    srand((unsigned)time(NULL));
    int array[3][3];
    fillMatrixWithRandomNumber(array, 3, 3);
    printMatrix(array, 3, 3);
    cout << endl << "Count number is : " << countNumberInMatrix(array, 3, 3, 1);
}