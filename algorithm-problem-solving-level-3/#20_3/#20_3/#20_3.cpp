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
bool isPalindromeMatrix(int array[3][3], short rows, short cols) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols / 2; j++)
        {
            if (array[i][j] != array[i][cols - j - 1])
                return false;
        }
    }
    return true;
}
int main() {
    srand((unsigned)time(NULL));
    int array[3][3];
    /*int array1[3][3] = {
        {1,0,1},
        {2,0,2},
        {3,0,3}
    };*/
    fillMatrixWithRandomNumber(array, 3, 3);
    printMatrix(array, 3, 3);
    if (isPalindromeMatrix(array, 3, 3))
        cout << "Yes\n";
    else
        cout << "No\n";
}