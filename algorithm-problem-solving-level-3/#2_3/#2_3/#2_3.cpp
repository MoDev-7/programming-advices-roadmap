#include <iostream>
using namespace std;
int getRandomNumber(int from, int to) {
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}
void fillMatrixWithRandomNumber(int array[3][3]) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            array[i][j] = getRandomNumber(1, 99);
        }
    }
}
void printMatrix(int array[3][3]) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%0*d ", 2, array[i][j]);
        }
        cout << endl;
    }
}
void printEachRowSum(int array[3][3]) {
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum = sum + array[i][j];
        }
        cout << "Sum of row [" << i << "] is : " << sum << endl;
        sum = 0;
    }
}
int main() {
    srand((unsigned)time(NULL));
    int array[3][3];
    fillMatrixWithRandomNumber(array);
    printMatrix(array);
    printEachRowSum(array);
}